 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDICountReportV.h"
#include "MetaClasses.h"
#include "World.h"
#include <utilcls.h>
#include "AUIV.h"
#include "MDI3DV.h"
#include "Main.h"
#include "CounterBaseV.h"
#include "MyGL.h"
#include "ProgBarV.h"
#include "ArchitectureSupportV.h"
#include "NomenclatureV.h"
#include "LuaAttributeV.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MyMDIChildV"
#pragma resource "*.dfm"
TMDICountReport *MDICountReport=NULL;
//---------------------------------------------------------------------------
__fastcall TMDICountReport::TMDICountReport(TComponent* Owner)
    : TMyMDIChild(Owner)
{
//    CountMode = _CountMode;
    QNParent = NULL;
    UpdateReport();
}
//---------------------------------------------------------------------------
int TakeMode = 0;

void __fastcall TMDICountReport::FormDestroy(TObject *Sender)
{
    SG->ColCount=0;
    SG->RowCount=0;
    delete HQ;
    delete CB;
    MDICountReport=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TMDICountReport::FormShow(TObject *Sender)
{
    MDICountReport=this;
    if (!World)
    {
        Close();
        return;
    }
}
//---------------------------------------------------------------------------
void TMDICountReport::SetQNParent(TQuerryNode* newQNParent)
{
    FQNParent = newQNParent;
    if (!FQNParent)
        FQNParent = HQ->Head;
    QNS.Clear();
    FQNParent->Select(QNS,TreeView,AllDirectory);
}

void TMDICountReport::UpdateReport()
{
    AnsiString Str;
    if (!World->TechCheck(Str))
    {
        if (!Str.IsEmpty())
            ShowMessage(Str);
        ShowMessage("Technology matching check has not been finished.");
        Close();
        return;
    }

    CB->ForceCount();
    HQ->FullProcess();
    QNParent = NULL;
    DrawCounterBase();
}

/*void TMDICountReport::SetNParent(TMyRegObject* newParent)
{
     NFParent = newParent;
     if (!NFParent)
         for (int i=0;i<MetaNodeCollection->Head->ChildList->Count;i++)
             if ( ((TMetaNode*)MetaNodeCollection->Head->ChildList->Items[i])->ChildType == cNomenclature)
                 NFParent = MetaNodeCollection->Head->ChildList->Items[i];
     NomList.Clear();
     BMPList.Clear();
     for (int i=0;i<NFParent->ChildList->Count;i++)
     {
        NomList.Add(NFParent->ChildList->Items[i]);
        BMPList.Add(new Graphics::TBitmap());
            BMPList.Last()->HandleType = bmDIB;

        if (MY_IS(NomList.Last(),typeid(TNomenclature)) || ((TMetaNode*)NomList.Last())->Img1->Valid() )
            ((TMetaNode*)NomList.Last())->Img1->GetBitmap(BMPList.Last());
        else
            ((TMetaNode*)NomList.Last())->Img1->GetStandartBitmap(siFOLDER,BMPList.Last());
     }
}*/

void TMDICountReport::DrawCounterBase()
{
    for (int i = 0;i<SG->ColCount;i++)
        SG->ColWidths[i]=5;
    for (int i = 0;i<SG->RowCount;i++)
        SG->RowHeights[i]=5;
    for (int i = 0;i<SG->ColCount;i++)
        for (int j = 0;j<SG->RowCount;j++)
        {
            SG->Objects[i][j]=NULL;
            SG->Cells[i][j] = AnsiString("");
        }
    DrawCounterBaseAdvanced();
    tbTree->Down = TreeView;
    tbFull->Down = AllDirectory;
    tbUp->Enabled = QNParent!=HQ->Head;
}

void TMDICountReport::UpdateAllCelsSize()
{
    for (int i = 0;i<SG->ColCount;i++)
        for (int j = 0;j<SG->RowCount;j++)
            UpdateCellSize(i,j);
}


void TMDICountReport::DrawCounterBaseAdvanced()
{
    //Parent is not NULL here
    //выводим  шапку
    int ShowImages = CB->ShowImages;
    SG->ColCount = CB->GetVisibleFieldCount() + ShowImages + ShowName;
    int CapCount = 1;
    SG->RowCount = QNS.Count+CapCount;
    SG->FixedRows = MIN(1,SG->RowCount-1);
    SG->FixedCols = MIN(SG->ColCount-1,ShowImages);
    if (ShowName)
        SG->Cells[ShowImages][0] = "Name";
    for (int i = 0;i<CB->GetVisibleFieldCount();i++)
        SG->Cells[i+ShowImages + ShowName][0] = CB->Fields->Items[i]->Name;
    for (int i=0;i<CB->GetVisibleFieldCount();i++)
    {
        if ( !ShowName && (CB->Fields->Items[i]->Name.AnsiCompareIC(AnsiString("Name")) == 0) )
        {
            for (int j=0;j<QNS.Count;j++)
                SG->Cells[i+ShowImages+ShowName][j+CapCount] = (QNS[j].Nom->Description + AnsiString("\n") + QNS[j].GetValue(i)).Trim();
        }
        else
            for (int j=0;j<QNS.Count;j++)
                SG->Cells[i+ShowImages+ShowName][j+CapCount] = QNS[j].GetValue(i);
    }

    if (ShowName)
        for (int j=0;j<QNS.Count;j++)
            SG->Cells[ShowImages][j+CapCount] = QNS[j].Nom->Description;
    if (ShowImages)
    {
        int MAXWidth = 0;
        for (int i=0;i<QNS.Count;i++)
        {
            SG->Objects[0][i+CapCount] = QNS[i].BMP;
            MAXWidth = MAX(QNS[i].BMP->Width,MAXWidth);
            SG->RowHeights[i+CapCount] = MAX(QNS[i].BMP->Height,SG->RowHeights[i+1]);
        }
        SG->ColWidths[0]=MAXWidth;
    }
    bool total = false;
    for (int i=0;i<CB->GetVisibleFieldCount();i++)
        if (CB->FieldExs->Items[i]->Total)
            total = true;
    if (total)
    {
        SG->RowCount++;
        if (QNParent == HQ->Head)
            SG->Cells[1][SG->RowCount-1] = AnsiString("Total");
        else
            SG->Cells[1][SG->RowCount-1] = AnsiString("Total by group") + QNParent->Nom->Description;
        for (int i=1;i<CB->GetVisibleFieldCount();i++)
            if (CB->FieldExs->Items[i]->Total)
                SG->Cells[ShowImages+ShowName+i][SG->RowCount-1] = QNParent->GetValue(i);
        SG->RowCount++;
        SG->Cells[ShowImages][SG->RowCount-1] = AnsiString("Total area (sq.m.)");
        float _total = GetTotalArea(World,-1);
        SG->Cells[ShowImages+1][SG->RowCount-1] = FLOATTOSTR(RoundTo(_total,-2));
        if (_total>0.05)
        {
            SG->RowCount++;
            SG->Cells[ShowImages][SG->RowCount-1] = AnsiString("Total for 1 sq.m.");
            for (int i=1;i<CB->GetVisibleFieldCount();i++)
                if (CB->FieldExs->Items[i]->Total && (CB->Fields->Items[i]->Type == mtInt || CB->Fields->Items[i]->Type == mtDouble))
                {
                    AnsiString Val = QNParent->GetValueNotRounded(i);
                    if (EmptyVariant(Val))
                        SG->Cells[ShowImages+ShowName+i][SG->RowCount-1] = AnsiString();
                    else
                    {
                        AnsiString Meter = CB->FieldExs->Items[i]->Meter;
                        AnsiString NewVal = FLOATTOSTR(RoundTo(TO_DOUBLE(Val)/_total,CB->FieldExs->Items[i]->Digits));
                        if (!Meter.Trim().IsEmpty())
                            NewVal = NewVal + AnsiString(" ") + Meter + AnsiString("/sq.m.");
                        SG->Cells[ShowImages+ShowName+i][SG->RowCount-1] = (NewVal).Trim();
                    }
                }
        }
    }
    UpdateAllCelsSize();
}

void TMDICountReport::DrawCounterBaseStandart()
{
    int ShowImages = CB->ShowImages;
    SG->ColCount = CB->Fields->Count+ShowImages;
    SG->RowCount = CB->Nomenclature->Count+1;
    SG->FixedRows = MIN(1,SG->RowCount-1);
    SG->FixedCols = MIN(SG->ColCount-1,ShowImages);
    for (int i = 0;i<CB->Fields->Count;i++)
        SG->Cells[i+ShowImages][0] = CB->Fields->Items[i]->Name;
    for (int i = 0;i<CB->Fields->Count;i++)
        for (int j = 0;j<CB->Nomenclature->Count;j++)
        {
            SG->Cells[i+ShowImages][j+1] = (CB->GetSum(-1,j,i,true)+AnsiString(" ")+CB->FieldExs->Items[i]->Meter).Trim();
        }
    if (CB->ShowImages)
    {
        int MAXWidth = 0;
        for (int i=0;i<CB->Nomenclature->Count;i++)
        {
//return            SG->Objects[0][i+1] = CB->BMPS->Items[i];
//            MAXWidth = MAX(CB->BMPS->Items[i]->Width,MAXWidth);
  //          SG->RowHeights[i+1] = MAX(CB->BMPS->Items[i]->Height,SG->RowHeights[i+1]);
        }
        SG->ColWidths[0]=MAXWidth;
    }
    bool total = false;
    for (int i=0;i<CB->FieldExs->Count;i++)
        if (CB->FieldExs->Items[i]->Total)
            total = true;
    if (total)
    {
        SG->RowCount++;
        SG->Cells[1][SG->RowCount-1] = AnsiString("Total");
        for (int i=1;i<CB->FieldExs->Count;i++)
            if (CB->FieldExs->Items[i]->Total)
                SG->Cells[ShowImages+i][SG->RowCount-1] = (CB->GetSum(-1,-1,i,true)+AnsiString(" ")+CB->FieldExs->Items[i]->Meter).Trim();
        SG->RowCount++;
        SG->Cells[1][SG->RowCount-1] = AnsiString("Total area (sq.m.)");
        float _total = GetTotalArea(World,-1);
        SG->Cells[2][SG->RowCount-1] = FLOATTOSTR(RoundTo(_total,-2));
        if (_total>0.05)
        {
            SG->RowCount++;
            SG->Cells[1][SG->RowCount-1] = AnsiString("Total for 1 sq.m.");
            for (int i=1;i<CB->FieldExs->Count;i++)
                if (CB->FieldExs->Items[i]->Total && (CB->Fields->Items[i]->Type == mtInt || CB->Fields->Items[i]->Type == mtDouble))
                {
                    AnsiString Val = CB->GetSum(-1,-1,i,false);
                    AnsiString Meter = CB->FieldExs->Items[i]->Meter;
                    AnsiString NewVal = FLOATTOSTR(RoundTo(TO_DOUBLE(Val)/_total,CB->FieldExs->Items[i]->Digits));
                    if (!Meter.Trim().IsEmpty())
                        NewVal = NewVal + AnsiString(" ") + Meter + AnsiString("/sq.m.");
                    SG->Cells[ShowImages+i][SG->RowCount-1] = (NewVal).Trim();
                }
        }
    }
}

void __fastcall TMDICountReport::FormCreate(TObject *Sender)
{
    CB = new TCounterBase();
    HQ = new THierarchyQuerry(CB) ;
    CB->CountMode = TakeMode;
//    ViewMode = vmTree;
    ShowName = false;
    TreeView = true;
    AllDirectory = false;
}
//---------------------------------------------------------------------------



void TMDICountReport::UpdateCellSize(int ACol, int ARow)
{
    if (CB->ShowImages && ACol == 0 && ARow>0 && SG->Objects[0][ARow])
    {
        return;
    }
    else
    {
        if ( SG->Cells[ACol][ARow].IsEmpty() )
            return;
        int Mode = DT_CENTER | DT_WORDBREAK;
        int Length = SG->Cells[ACol][ARow].Length();
        TRect R = TRect(0, 0, MAX(SG->ColWidths[ACol]-10,10), 1);

        //--------------------------------------------------
        DrawText(SG->Canvas->Handle, SG->Cells[ACol][ARow].c_str(), Length, &R, (Mode | DT_CALCRECT) );
        int tHeight = (R.Bottom - R.Top);
        int tWidth = (R.Right - R.Left);

        if (tWidth && tWidth > (SG->ColWidths[ACol]-10) && (double(tHeight)/double(tWidth))>1.8 )
        {
            R = TRect(0, 0, MAX(double(tWidth*1.5),10.0), 1);
            DrawText(SG->Canvas->Handle, SG->Cells[ACol][ARow].c_str(), Length, &R, (Mode | DT_CALCRECT) );
            tHeight = (R.Bottom - R.Top);
            tWidth = (R.Right - R.Left);
        }

        if (tWidth > (SG->ColWidths[ACol]-10))
            SG->ColWidths[ACol] = tWidth + 10;

        if (tHeight > (SG->RowHeights[ARow]-10))
            SG->RowHeights[ARow] = tHeight + 10;
    }
}

void __fastcall TMDICountReport::SGDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if (ProgBar->Visible)
        return;
    if (CB->ShowImages && ACol == 0 && ARow>0 && SG->Objects[0][ARow])
    {
        SG->Canvas->Brush->Color = SG->Color;
        SG->Canvas->FillRect(Rect);
        TRect Res ;
        RectForBMP(Rect,(Graphics::TBitmap*)SG->Objects[0][ARow],Res);
        SG->Canvas->StretchDraw(Res,(Graphics::TBitmap*)SG->Objects[0][ARow]);
        if (State.Contains(gdFocused))
            SG->Canvas->DrawFocusRect(Rect);
    }else 
    {
        if (ACol<SG->FixedCols || ARow<SG->FixedRows)
            SG->Canvas->Brush->Color = SG->FixedColor;
        else if ( (ARow-1)>=0 && (ARow-1)<QNS.Count && QNS[ARow-1].Childs.Count>0 )
            SG->Canvas->Brush->Color = TColor(0x00EFFAFA);
        else
            SG->Canvas->Brush->Color = SG->Color;
        SG->Canvas->FillRect(Rect);
        if ( SG->Cells[ACol][ARow].IsEmpty() )
            return;
        UpdateCellSize( ACol,  ARow);
        int Mode = DT_CENTER | DT_WORDBREAK;
        int Length = SG->Cells[ACol][ARow].Length();
        TRect R = Rect;
        InflateRectEx(R, 5, 5, -5, -5);
        DrawText(SG->Canvas->Handle, SG->Cells[ACol][ARow].c_str(), Length, &R, Mode);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDICountReport::FormActivate(TObject *Sender)
{
    SG->Invalidate();
    ::SetFocus(SG->Handle);        
}
//---------------------------------------------------------------------------


void __fastcall TMDICountReport::SGMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if (!Active)
        Activate();
    if (!SG->Focused())
        ::SetFocus(SG->Handle);
    SG->Cursor = crDefault;
    int Col,Row;
    TPoint P = SG->ScreenToClient(Mouse->CursorPos);
    SG->MouseToCell( P.x,  P.y, Col, Row);
    int index = Row-1;
    if (index>=0 && index<QNS.Count && Col == 0)
        if ( (QNS[index].Childs.Count && TreeView) ||
            (QNS[index].Childs.Count==0&&QNS[index].Nom->TB->Exists(trView)&&
                QNS[index].Nom->Is(TNomenclature::StaticType) ) )
            SG->Cursor = crHandPoint;
}
//---------------------------------------------------------------------------


void __fastcall TMDICountReport::SGMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    int Col,Row;
    TPoint P = SG->ScreenToClient(Mouse->CursorPos);
    SG->MouseToCell( P.x,  P.y, Col, Row);
    int index = Row-1;
    if (index>=0 && index < QNS.Count && Col == 0)
        if ( QNS[index].Childs.Count && TreeView)
        {
                QNParent = QNS.Items[index];
                DrawCounterBase();
        }
        else if (QNS[index].Childs.Count==0 && QNS[index].Nom->TB->Exists(trView) && QNS[index].Nom->Is(TNomenclature::StaticType ))
        {
            TNomenclature* backNom = CurNomenclature;
            CurNomenclature = (TNomenclature*)QNS[index].Nom;
            CurNomenclature->TB->Run(trView);
            CurNomenclature = backNom;
        }
}
//---------------------------------------------------------------------------

void __fastcall TMDICountReport::SGDblClick(TObject *Sender)
{
/*        int Col,Row;
        TPoint P = SG->ScreenToClient(Mouse->CursorPos);
        SG->MouseToCell( P.x,  P.y, Col, Row);
        int index = Row-1;
        if (index>=0 && index<NomList.Count && Col != 0)
        {
            NParent = NomList.Items[index];
            DrawCounterBase();
        }   */
}

AnsiString adr(int row,int col){
    //numeration from zero
    AnsiString First="";
    if(col>=26)
        First=AnsiString(char(65+(col/26-1)));
    AnsiString Second=AnsiString(char(65+(col%26)));
    return(First+Second+IntToStr(row+1));
}

double PTS(Variant* XL,int PTS,int PixelPerInch)
{
    double inch = double(PTS)/double(PixelPerInch);
    return ((double)XL->OleFunction("InchesToPoints",inch));
};

void RectForBMPExcel(   Variant* XL,
                        const TMBTRect& Where,
                        Graphics::TBitmap* _BMP,
                        TMBTRect& Res ,
                        int PixelPerInch)
{
    double _BMPW = PTS(XL,_BMP->Width,PixelPerInch);
    double _BMPH = PTS(XL,_BMP->Height,PixelPerInch);
    TIntVec Center;
    Center.x = (Where.left+Where.right)/2;
    Center.y = (Where.top+Where.bottom)/2;
    Res.left = Center.x - _BMPW/2;
    Res.right = Res.left + _BMPW;
    Res.top = Center.y - _BMPH/2;
    Res.bottom = Res.top + _BMPH;

    double RX = MAX(_BMPW- Where.Width(),0.0);
    double RY = MAX(_BMPH - Where.Height(),0.0);

    double RaznostY;
    double RaznostX;

    if (RX>RY)
    {
        RaznostX = RX;
        RaznostY = (RX*_BMPH)/_BMPW;
    }
    else
    {
        RaznostY = RY;
        RaznostX = (RY*_BMPW)/_BMPH;
    }
    Res.left = Res.left + RaznostX/2;
    Res.top = Res.top + RaznostY/2;
    Res.right = Res.right -RaznostX/2;
    Res.bottom = Res.bottom -RaznostY/2;
}                 

double CPTS(Variant* XL,int PTS,int PixelPerInch,double SymbolWidth)
{
    double inch = double(PTS)/double(PixelPerInch);
//    double symb_inch = SymbolWidth/double(PixelPerInch);
    double XL_P_All = double(XL->OleFunction("InchesToPoints",inch));
//    double XL_P_Sym = double(XL->OleFunction("InchesToPoints",symb_inch));
    return (XL_P_All/SymbolWidth) ;
};


//return new Row
int ProcessAddBitmap(Variant* XL,Graphics::TBitmap* _BMP,const AnsiString& Caption, int Row,double symbWidth)
{
    Variant v1,v2,v3;
    v1 = XL->OlePropertyGet("ActiveWorkBook").OlePropertyGet("WorkSheets").OlePropertyGet("Item",2);

    v1.OlePropertyGet("Rows",Row).OlePropertySet("RowHeight", PTS(XL,30,96) );
    v1.OlePropertyGet("Rows",Row+1).OlePropertySet("RowHeight", PTS(XL,450,96) );
    v1.OlePropertyGet("Columns",1).OlePropertySet("ColumnWidth", CPTS(XL,600,96,symbWidth) );

    v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Row,1);
    v2.OlePropertySet("Value", Caption.c_str() );
    v2.OlePropertySet("VerticalAlignment", ((int)0xFFFFEFF4) );
    v2.OlePropertySet("HorizontalAlignment", ((int)0xFFFFEFF4) );
    v2.OlePropertyGet("Font").OlePropertySet("Name","Times New Roman");
    v2.OlePropertyGet("Font").OlePropertySet("Size",16);
    v2.OlePropertySet("WrapText", true );

    v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",Row+1,1);

    AnsiString FileName = MainDir + SL + AnsiString("tmp") + IntToStr(Row) + BMP;
    CHECK_FILE_SAVE(FileName);
    _BMP->SaveToFile(FileName);
    int pLeft  = v2.OlePropertyGet("Left")+1;
    int pTop = v2.OlePropertyGet("Top")+1;
    int pWidth = v2.OlePropertyGet("Width")-2;
    int pHeight = v2.OlePropertyGet("Height")-2;
    v3 = v1.OlePropertyGet("Shapes").OleFunction("AddPicture",FileName.c_str(),0,-1,pLeft,pTop,pWidth,pHeight);
    v3.OlePropertySet("Placement",1);
    DeleteFile(FileName);
    return (Row+2);
}

void TMDICountReport::ToExcel(const AnsiString& FileName)
{
    StartProcess("Передача данных в Excel...",SG->RowCount);
    Variant XL,v0,v1,v2,v3;
    XL=CreateOleObject("Excel.Application");

//    XL.OlePropertySet("Visible",true);
    v0=XL.OlePropertyGet("Workbooks");
    v0.OleProcedure("Add");
    v1=v0.OlePropertyGet("Item",1);
    v0=v1.OlePropertyGet("Worksheets") ;
    v0.OlePropertyGet("Item",1).OlePropertySet("Name","Cost of house");
    v1=v0.OlePropertyGet("Item",1);
    double cw = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,1).OlePropertyGet("Width");
    double cwsym = v1.OlePropertyGet("Columns",1).OlePropertyGet("ColumnWidth");
    double pWidth = cw/cwsym;
    //Шапка
    int rowshift=1;
    float _total = GetTotalArea(World,-1);
    AnsiString Str = AnsiString("Cost of materials for building with total area of ");
    Str = Str + FLOATTOSTR(RoundTo(_total,-2)) + AnsiString(" sq.m., using technology """".");
    v1.OlePropertyGet("Rows",1).OlePropertySet("RowHeight", 96 );
    v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,1);
    v2.OlePropertySet("Value",Str.c_str());

    //строковая часть
    for (int i=1;i<=SG->RowCount;i++)
    {
        CountProcess(SG->Cells[CB->ShowImages][i-1],1);
        for (int j=1;j<=SG->ColCount;j++)
        {
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+rowshift,j);
            v2.OlePropertySet("Value",SG->Cells[j-1][i-1].c_str());

            v2.OlePropertyGet("Borders",9).OlePropertySet("LineStyle",1);
            v2.OlePropertyGet("Borders",9).OlePropertySet("Weight",2);
            v2.OlePropertyGet("Borders",7).OlePropertySet("LineStyle",1);
            v2.OlePropertyGet("Borders",7).OlePropertySet("Weight",2);
            v2.OlePropertyGet("Borders",10).OlePropertySet("LineStyle",1);
            v2.OlePropertyGet("Borders",10).OlePropertySet("Weight",2);
            v2.OlePropertyGet("Borders",8).OlePropertySet("LineStyle",1);
            v2.OlePropertyGet("Borders",8).OlePropertySet("Weight",2);
            if (i == SG->RowCount)
            {
                v1.OlePropertyGet("Columns",j).OlePropertySet("VerticalAlignment", ((int)0xFFFFEFF4) );
                v1.OlePropertyGet("Columns",j).OlePropertySet("HorizontalAlignment", ((int)0xFFFFEFF4) );
                v1.OlePropertyGet("Columns",j).OlePropertyGet("Font").OlePropertySet("Name",SG->Font->Name.c_str());
                v1.OlePropertyGet("Columns",j).OlePropertyGet("Font").OlePropertySet("Size",SG->Font->Size);
                v1.OlePropertyGet("Columns",j).OlePropertySet("WrapText", true );
            }
        }
    }
    SG->Canvas->Font->Assign(SG->Font);

    for (int i=1;i<=SG->RowCount;i++)
        v1.OlePropertyGet("Rows",i+rowshift).OlePropertySet("RowHeight", PTS(&XL,SG->RowHeights[i-1],96) );

    for (int j=1;j<=SG->ColCount;j++)
        v1.OlePropertyGet("Columns",j).OlePropertySet("ColumnWidth", CPTS(&XL,SG->ColWidths[j-1],96,pWidth));

    v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,1);
    v2.OlePropertySet("VerticalAlignment", ((int)0xFFFFEFF4) );
    v2.OlePropertySet("HorizontalAlignment", ((int)0xFFFFEFF4) );
    v2.OlePropertyGet("Font").OlePropertySet("Name","Times New Roman");
    v2.OlePropertyGet("Font").OlePropertySet("Size",16);
    v2.OlePropertySet("WrapText", true );
    v3 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",1,SG->ColCount);
    v1.OlePropertyGet("Range",v2,v3).OleFunction("Merge",false);

    TMDelTList<AnsiString> FileNames;

    StartProcess("Transfer graphics to Excel...",SG->RowCount+5);
    for (int i=1;i<=SG->RowCount;i++)
    {
        CountProcess(SG->Cells[CB->ShowImages][i-1],1);
        for (int j=1;j<=SG->ColCount;j++)
        {
            v2 = v1.OlePropertyGet("Cells").OlePropertyGet("Item",i+rowshift,j);
            if (SG->Objects[j-1][i-1])
            {
                Graphics::TBitmap* _BMP = (Graphics::TBitmap*)SG->Objects[j-1][i-1];
                _BMP->HandleType = bmDIB;
                AnsiString FileName = MainDir + SL + AnsiString("tmp") + IntToStr(j) + BMP;
                CHECK_FILE_SAVE(FileName);
                _BMP->SaveToFile(FileName);
                TMBTRect ExcelRect;
                ExcelRect.left  = v2.OlePropertyGet("Left")+1;
                ExcelRect.top = v2.OlePropertyGet("Top")+1;
                ExcelRect.right  = v2.OlePropertyGet("Left")+v2.OlePropertyGet("Width")-1;
                ExcelRect.bottom = v2.OlePropertyGet("Top")+v2.OlePropertyGet("Height")-1;

                TMBTRect EBMPR;

                RectForBMPExcel(&XL,ExcelRect,_BMP,EBMPR ,PixelsPerInch);

                /*ExcelRect.Width = v2.OlePropertyGet("Width")-2;
                ExcelRect.Height = v2.OlePropertyGet("Height")-2;*/
                
                v3 = v1.OlePropertyGet("Shapes").OleFunction("AddPicture",FileName.c_str(),0,-1,EBMPR.left,EBMPR.top,EBMPR.Width(),EBMPR.Height());
                v3.OlePropertySet("Placement",1);
                FileNames.Add(new AnsiString(FileName));
            }
        }
    }
    //эскизы и 3d-вид
    v1=v0.OlePropertyGet("Item",2);
    v1.OlePropertySet("Name","Perspective views and sketches");
    int Row = 1;
    for (int i=0;i<World->Clients.Count;i++)
    {
        Graphics::TBitmap* _BMP = new Graphics::TBitmap;
        _BMP->HandleType = bmDIB;
        _BMP->Width = 600;
        _BMP->Height = 450;
        AnsiString _Str = AnsiString();
        if ( IS(World->Clients[i].MDI3D,__classid(TMDI3D)) )
        {
            if ( World->Clients[i].MDI3D == AUI.ActiveView )
            {
                AUI.ActiveView->View->GetImage2(_BMP);
                _Str = "Perspective view";
            }
            CountProcess(_Str,1);
        }
/*        else if (IS(World->Clients[i].MDI,__classid(TMDI2D)))
        {
            if (World->Clients[i].ActiveIndex>=0 && World->Clients[i].ActiveIndex<World->Floors.Count)
            {
                _Str = "План Этажа №" + IntToStr(World->Clients[i].ActiveIndex+1);
                ((TMDI2D*)World->Clients[i].MDI)->DrawView->GetImage(_BMP);
            }
            CountProcess(_Str,1);
        } */
        if (!_Str.IsEmpty())
            Row = ProcessAddBitmap( &(XL),_BMP,_Str.c_str(), Row,pWidth);
        delete _BMP;
    }
    XL.OlePropertySet("DisplayAlerts",false); //отключить диагностику при закрытии сервера
    StartProcess("Saving workbook...",10);
    XL.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",FileName.c_str());
    StartProcess("Done",10);
    XL.OleProcedure("Quit");
    XL = Unassigned;
    v0 = Unassigned;
    v1 = Unassigned;
    v2 = Unassigned;
    v3 = Unassigned;
    XL=CreateOleObject("Excel.Application");
    v0=XL.OlePropertyGet("Workbooks");
    v0.OleProcedure("Add",FileName.c_str());
    XL.OlePropertySet("Visible",true);
    XL = Unassigned;
    v0 = Unassigned;
    for (int i=0;i<FileNames.Count;i++)
        DeleteFile(FileNames[i]);
}

//---------------------------------------------------------------------------


void __fastcall TMDICountReport::tbTreeClick(TObject *Sender)
{
    TreeView = tbTree->Down;
    AllDirectory = tbFull->Down;
    QNParent = NULL;
    DrawCounterBase();
    Invalidate();   
}
//---------------------------------------------------------------------------


void __fastcall TMDICountReport::tbUpClick(TObject *Sender)
{
    if (QNParent!=HQ->Head)
        QNParent = QNParent->Parent;
    DrawCounterBase();
    Invalidate();   
}
//---------------------------------------------------------------------------

void __fastcall TMDICountReport::ToolButton1Click(TObject *Sender)
{
    if (World)
        UpdateReport();
}
//---------------------------------------------------------------------------

