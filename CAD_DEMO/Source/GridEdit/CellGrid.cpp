// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "compat/vcl_qt.h"

#include "CellGrid.h"
#include "GridFormV.h"
#include "SectionDialogU.h"
#include "CellParameterU.h"
#include "SelectColorU.h"
#include "ColorComboBoxU.h"
#include "TextEditU.h"
#include "ToolBarCellGrid.h"
#include "OffsetCellU.h"

//---------------------------------------------------------------------------
TClassNode* TCell::StaticType       =NULL;
TClassNode* TCellColRow::StaticType =NULL;
TClassNode* TCellTab::StaticType    =NULL;
TClassNode* TMGrid::StaticType      =NULL;

TMGrid MClipBoard;

void RegisterCellGrid()
{
    TCell();
    TCellTab();
    TCellColRow();
    TMGrid();
}
#pragma startup RegisterCellGrid
// ----------- TCellTab ------------------
TMyObject* TCellTab::CreateFunction()
{
    return new TCellTab();
}

const AnsiString aColWidth = AnsiString("ColWidth");
const AnsiString aRowHeight = AnsiString("RowHeight");

TCellTab::TCellTab()
{
    RegisterNewClass<TMyObject,TCellTab>(this,false,&CreateFunction);
    RegisterField(&ColWidth,&aColWidth,mtInt);
    RegisterField(&RowHeight,&aRowHeight,mtInt);

    ColWidth    =2;
    RowHeight   =2;
}

TCellTab::~TCellTab()
{
}

//==================================================
// ----------- TCellFlag ------------------
TMyObject* TCellFlag::CreateFunction()
{
    return new TCellFlag();
}

TCellFlag::TCellFlag()
{

    UnionCell.Left    =0;
    UnionCell.Top     =0;
    UnionCell.Right   =0;
    UnionCell.Bottom  =0;

    Col               =0;
    Row               =0;
    ColWidth          =0;
    RowHeight         =0;
    bool Set          =false;
    f_ColWidth        =Set;
    f_Text            =Set;
    f_FontStyle       =Set;
    f_FontStrikeOut   =Set;
    f_FontSize        =Set;
    f_FontName        =Set;
    f_WidthTop        =Set;
    f_WidthRight      =Set;
    f_WidthLeft       =Set;
    f_WidthBottom     =Set;
    f_ValueType       =Set;
    f_TypeAutoSize    =Set;
    f_TextWordBreak   =Set;
    f_TextVAlign      =Set;
    f_TextHeightAuto  =Set;
    f_TextHAlign      =Set;
    f_LineColorNot    =Set;
    f_FontUnderline   =Set;
    f_FontColor       =Set;
    f_bgColor         =Set;
    f_Flood           =Set;
    f_UnionCell       =Set;
    f_SetUnion        =Set;
}
// ----------- TCellColRow ------------------
TMyObject* TCellColRow::CreateFunction()
{
    return new TCellColRow();
}

const AnsiString aColRowWidth = AnsiString("ColRowWidth");

TCellColRow::TCellColRow()
{
    RegisterNewClass<TMyObject,TCellColRow>(this,false,&CreateFunction);
    RegisterField(&ColRowWidth,&aColRowWidth,mtInt);

    ColRowWidth =2;
}

TCellColRow::~TCellColRow()
{
}

//==================================================
// ----------- TCell ------------------
void TCell::Assign(TMyObject* MO)
{
    TMyObject::Assign(MO);
    if (UnionRect)
    {
        delete UnionRect;
        UnionRect = NULL;
    }
    if (((TCell*)MO)->UnionRect !=NULL)
    {
        UnionRect =new TRect();
        *UnionRect = *((TCell*)MO)->UnionRect;
    }
}

TMyObject* TCell::CreateFunction()
{
    return new TCell();
}


/*
int,double,float,MBTi,AnsiString,bool,TMyObject
*/

const AnsiString aText          =AnsiString("Text");
const AnsiString aFontName      =AnsiString("FontName");
const AnsiString aCellFlags     =AnsiString("CellFlags");
const AnsiString aFontColor     =AnsiString("FontColor");
const AnsiString abgColor       =AnsiString("bgColor");
const AnsiString aLine          =AnsiString("Line");
const AnsiString aLineColorNot  =AnsiString("LineColorNot");

void TCell::InitFont()
{
    Font->Name = FontName;
    Font->Size = CellFlags.FontSize;
    Font->Color = FontColor;

    TFontStyles Style;
    switch (CellFlags.FontStyle)
    {
        case 0:
        {// Îáû÷íûé
            Style.Clear();
        }break;
        case 1:
        {// Êóðñèâ
            Style <<fsItalic;
        }break;
        case 2:
        {// Æèðíûé
            Style <<fsBold;
        }break;
        case 3:
        {// Æèðíûé êóðñèâ
            Style <<fsBold <<fsItalic;
        }break;
    }
    if (CellFlags.FontStrikeOut ==1)
    {// Çà÷åðêíóòûé øðèôò
        Style <<fsStrikeOut;
    }
    if (CellFlags.FontUnderline ==1)
    {// Ïîä÷åðêíóòûé øðèôò
        Style <<fsUnderline;
    }
    Font->Style =Style;
}

TCell::TCell()
{
    RegisterNewClass<TMyObject,TCell>(this,false,&CreateFunction);
    RegisterField(&Text,&aText,mtString);
    RegisterField(&FontName,&aFontName,mtString);
    RegisterField(&CellFlags,&aCellFlags,mtInt);
    RegisterField(&FontColor,&aFontColor,mtInt);
    RegisterField(&bgColor,&abgColor,mtInt);
    RegisterField(&LineColorNot,&aLineColorNot,mtBool);
    RegisterField(&Line,&aLine,mtInt);
    Font = new TFont();
    UndoRegistered  =false;

    bgColor         =clWhite;
    FontColor       =clBlack;
    UnionRect       =NULL;
    LineColorNot    =false;
    FontName        ="Arial Cyr";

    CellFlags.FontSize          =10;
    CellFlags.FontStyle         =0;
    CellFlags.ValueType         =0;
    CellFlags.TypeAutoSize      =0;
    CellFlags.TextWordBreak     =0;
    CellFlags.TextHAlign        =0;
    CellFlags.TextVAlign        =1;
    CellFlags.FontStrikeOut     =0;
    CellFlags.FontUnderline     =0;
    CellFlags.TextHeightAuto    =1;

    Line.WidthTop       =0;
    Line.WidthLeft      =0;
    Line.WidthRight     =0;
    Line.WidthBottom    =0;

    InitFont();
}

TCell::~TCell()
{
    delete Font;
}

void TCell::WriteData(TMemoryStream *MS) const
{
    TMyObject::WriteData(MS);
    bool OK = (UnionRect!=NULL);
    WriteOne( &OK, mtBool, MS);
    if (OK)
    {
        WriteOne(&(UnionRect->Left), mtInt,  MS);
        WriteOne(&(UnionRect->Top), mtInt,  MS);
        WriteOne(&(UnionRect->Right), mtInt,  MS);
        WriteOne(&(UnionRect->Bottom), mtInt,  MS);
    }
}

void MYFILEPUTS(const TMyObject* Obj,const AnsiString& String,FILE* F)
{
    fputs( ( AnsiString::StringOfChar('\t',Obj->GetDepth()+1)+String ).c_str(), F);
}

void TCell::SaveData(FILE *F) const
{
    AnsiString flag;
    bool OK = (UnionRect!=NULL);
    flag = TYPETOSTR(&OK,mtBool);
    MYFILEPUTS(this,flag.c_str(), F);
    fputs("\n", F);
    if (OK)
    {
        MYFILEPUTS(this,TYPETOSTR(&(UnionRect->Left),mtInt).c_str(), F);
        fputs("\n", F);
        MYFILEPUTS(this,TYPETOSTR(&(UnionRect->Top),mtInt).c_str(), F);
        fputs("\n", F);
        MYFILEPUTS(this,TYPETOSTR(&(UnionRect->Right),mtInt).c_str(), F);
        fputs("\n", F);
        MYFILEPUTS(this,TYPETOSTR(&(UnionRect->Bottom),mtInt).c_str(), F);
        fputs("\n", F);
    }
    TMyObject::SaveData(F);
}

void TCell::LoadData(FILE *F)
{
    AnsiString flag;
    char ch[512];
    fgets(ch,512,F);
    flag = AnsiString(ch).Trim();
    bool OK;
    CopyType(mtBool,&OK,STRTOTYPE(flag,mtBool));
    if (UnionRect)
    {
        delete UnionRect;
        UnionRect = NULL;
    }
    if (OK)
    {
        UnionRect = new TRect();

        fgets(ch,512,F);
        flag =AnsiString(ch).Trim();
        CopyType(mtInt,&(UnionRect->Left),STRTOTYPE(flag,mtInt));
        fgets(ch,512,F);
        flag =AnsiString(ch).Trim();
        CopyType(mtInt,&(UnionRect->Top),STRTOTYPE(flag,mtInt));
        fgets(ch,512,F);
        flag =AnsiString(ch).Trim();
        CopyType(mtInt,&(UnionRect->Right),STRTOTYPE(flag,mtInt));
        fgets(ch,512,F);
        flag =AnsiString(ch).Trim();
        CopyType(mtInt,&(UnionRect->Bottom),STRTOTYPE(flag,mtInt));
    }
    TMyObject::LoadData(F);
}

void TCell::ReadData(TMemoryStream *MS)
{
    TMyObject::ReadData(MS);
    bool OK;
    ReadOne( &OK, mtBool, MS);
    if (UnionRect)
    {
        delete UnionRect;
        UnionRect = NULL;
    }
    if (OK)
    {
        UnionRect = new TRect();

        ReadOne(&(UnionRect->Left), mtInt,  MS);
        ReadOne(&(UnionRect->Top), mtInt,  MS);
        ReadOne(&(UnionRect->Right), mtInt,  MS);
        ReadOne(&(UnionRect->Bottom), mtInt,  MS);
    }
}

// ----------- TCellList ------------------
void  TCellList::Put(int index, TCell * item)
{
    TSparseList::Put(index, item);
}

TCell*  TCellList::Get(int index)
{
    return (TCell*)TSparseList::Get(index);
}

// ----------- TCellGrid ------------------

 TCellGrid::TCellGrid(Classes::TComponent* AOwner, TGridForm* _Form, TToolBarCellGrid* _ToolBarCellGrid)
    :TMyDrawGrid(AOwner)
{

    FData = NULL;
    GridForm =_Form;
    Initialize();
    Timer = new TTimer(this);
    Timer->Interval = 100;
    Timer->Enabled = false;
    Timer->OnTimer = OnTimer;

    EndColRowCell.x=0;
    EndColRowCell.y=0;

    bResizeColRow =false; //Èçìåíèëñÿ ðàçìåð (ñòðîê, ñòîëáöîâ)

    TStart = new TTimer(this);
    TStart->Interval = 2;
    TStart->Enabled = true;
    TStart->OnTimer = StartTime;

    ToolBarCellGrid =_ToolBarCellGrid;
    
// Ïåðåìåííûå ÍÀØÅÃÎ Paint
    InvalidateRectOK = false;
    StartVisible = false;

    ScrollParam=0;

    PopupMenuNotMouseUp =false;

    oldFCurrent.X = 1;
    oldFCurrent.Y = 1;
    oldFAnchor.X = 1;
    oldFAnchor.Y = 1;
    OnMouseMove = CellGridMouseMove;
    OnMouseDown = CellGridMouseDown;
    OnMouseUp = CellGridMouseUp;

    iMouseDown = 0;
    iMouseMove = 0;

//    MouseDownAndMoveCursor = false;

    MouseUP =false;

    OldRectDown.Left = -1;
    OldRectDown.Top = -1;
    OldRectDown.Right = -1;
    OldRectDown.Bottom = -1;

    MoveCellBorder =false;

    CurrentRectDrawUnionFixed = OldRectDown;

    CurrentAnchorMouseUp.Left = 0;
    CurrentAnchorMouseUp.Top = 0;
    CurrentAnchorMouseUp.Right = 0;
    CurrentAnchorMouseUp.Bottom = 0;

    OldRectMouseDown = OldRectDown;
    OldRectDownCurrentAnchor =OldRectDown;

    iTest1=0;
    iTest2=0;
    OldRectDrawCellFixedT =-1;
    OldRectDrawCellFixedL =-1;
//    iCountCalculation=0;
// Ïåðåìåííûå ÍÀØÅÃÎ Paint - END

    NullRect(OldCurrentAnchorSort);

// Ïåðåìåííûå ÍÀØÅÃÎ Paint V2
//    OldRectCurrentAnchorMouseDown=OldRectDown;
    OldRectCurrentAnchorMouseMove=OldRectDown;
    OldCellMouseMove.X = -1;
    OldCellMouseMove.Y = -1;

// Ïåðåìåííûå ÍÀØÅÃÎ Paint - END

    CellGridResizeRow.x =0;
    CellGridResizeRow.y =0;

    CellGridResizeCol.x =0;
    CellGridResizeCol.y =0;

    NewSizeColRow =0;

// Ïåðåìåííûå ×àñòíûé ñëó÷àé
    PrivatEvent_1 = false;
// Ïåðåìåííûå ×àñòíûé ñëó÷àé END

// Ïåðåìåííûå ÍÀØÅÃÎ Paint V4
    CurrentUnionRectMouseMove = OldRectDown;
    iCountYes = 0;

    MousePosCellMove.X = -1;
    MousePosCellMove.Y = -1;

//    MouseWhellUp = 0;
//    MouseWhellDown = 0;

//    MouseWhellRight = 0;
//    MouseWhellLeft = 0;


    PointMouseDownOld.X = 0;
    PointMouseDownOld.Y = 0;

    MouseUpCoord=PointMouseDownOld;

    Vert = false;
    Horz = false;

    VertFixed = true;
    HorzFixed = true;

    VertFixedLast = true;
    HorzFixedLast =true;

    MouseX =10;
    MouseY =10;
// Ïåðåìåííûå ÍÀØÅÃÎ Paint - END

//*********************  Color **********
    ColorCursor =clWhite; // Ñòàíäàðòíûé ôîí
//*********************  Color ********** END

//********************* Function System
    SelectTable = false; // Âûäåëåíà òàáëèöà
    SelectColumn = false;// Âûäåëåí ñòîëáåö
    SelectString = false;// Âûäåëåíà ñòðîêà
    SelectCell = false;// Âûäåëåíà ÿ÷åéêà

    XM=1;
    YM=1;

    MousePosCellMoveSelect = PointMouseDownOld;
//********************* Function System END

    EditText        =new TEditText(AOwner, this);
    gCellFlag       =new TCellFlag();
    ProgressCopy =false;
    // Matrix
    Matrix =new TCellMatrix(this,this);
    // Matrix
}

inline  TCellGrid::~TCellGrid(void)
{
    delete Timer;
    delete TStart;
    delete gCellFlag;
    gCellFlag =NULL;

    for (int y=0; y<= EndColRowCell.y; y++)
        for (int x=0; x<= EndColRowCell.x; x++)
            DelCell(x,y);
    int i=0;
    TSparseList* SL = ((TSparseList*)FData);
    for ( int i=0; i<RowCount; i++ )
        if ( SL->Items[i] )
        {
            delete ((TSparseList*)SL->Items[i]);
            SL->Items[i] = NULL;
        }
    delete SL;

}

void  TCellGrid::ClearSelectRect()
{// Î÷èñòêà âûäåëåííîé îáëàñòè
    TRect rect =GetSelectGridRect();
    if (rect.Left ==1 && rect.Top ==1)
    {
        for (int y=1; y<rect.Bottom; y++)
            for (int x=1; x<=rect.Right; x++)
                if (GetCellSimple(x,y) !=NULL)
                {
                    DelCell(x,y);
                    RecalculationEndCell(x,y);
                }
    }
    else
    {
        GetSelectCells(true);
        int iEnd =ListFilling.Count;
        for (int i=0; i<iEnd; i++)
            if (GetCellSimple(ListFilling[i].x,ListFilling[i].y))
            {
                DelCell(ListFilling[i].x,ListFilling[i].y);
                RecalculationEndCell(ListFilling[i].x,ListFilling[i].y);
            }

        ClearListFilling();
    }
    if (GetCellSimple(1,1) ==NULL)
    {
        EndColRowCell.x=0;
        EndColRowCell.y=0;
        NewCell(1,1);
        GetCellSimple(1,1)->Assign(GetCellSimple(0,0));

    }

}

void  TCellGrid::ClearSelectRect(const TRect& rect)
{// Î÷èñòêà âûäåëåííîé îáëàñòè
    TRect rect2 =rect;

    if (rect2.Bottom == RowCount-1)
        rect2.Bottom =EndColRowCell.y;
    if (rect2.Right == ColCount-1)
        rect2.Right =EndColRowCell.x;

    if (rect2.Left <1)
        rect2.Left =1;
    if (rect2.Top <1)
        rect2.Top =1;

    for (int y=rect2.Top; y<=rect2.Bottom; y++)
        for (int x=rect2.Left; x<=rect2.Right; x++)
            if (GetCellSimple(x,y))
            {
                DelCell(x,y);
                RecalculationEndCell(x,y);
            }
    if (GetCellSimple(1,1) ==NULL)
    {
        EndColRowCell.x=0;
        EndColRowCell.y=0;
        NewCell(1,1);
        GetCellSimple(1,1)->Assign(GetCellSimple(0,0));
    }
}

void  TCellGrid::RecalculationEndCell(int Col, int Row)
{
    bool bOK =false;
    if (Col >=EndColRowCell.x)
        for (int x=Col; x >0  && !bOK; x--)
            for (int y=0; y <=EndColRowCell.y && !bOK; y++)
                if (GetCellSimple(x,y) !=NULL)
                {
                    EndColRowCell.x =x;
                    bOK =true;
                }

    bOK =false;
    if (Row >=EndColRowCell.y)
        for (int y=Row; y >0  && !bOK; y--)
            for (int x=0; x <=EndColRowCell.x && !bOK; x++)
                if (GetCellSimple(x,y) !=NULL)
                {
                    EndColRowCell.y =y;
                    bOK =true;
                }

}

void  TCellGrid::ClearCell(int Col, int Row)
{// Î÷èñòêà âûäåëåííîé îáëàñòè

    if (GetCellSimple(Col,Row))
    {
        if (GetCellSimple(Col,Row)->UnionRect != NULL)
        {
            TCell* CellR =GetCellSimple(Col,Row);
            TRect rect;
            rect.Left   =CellR->UnionRect->Left;
            rect.Top    =CellR->UnionRect->Top;
            rect.Right  =CellR->UnionRect->Right;
            rect.Bottom =CellR->UnionRect->Bottom;
            for (int y=rect.Top; y<=rect.Bottom; y++)
                for (int x=rect.Left; x<=rect.Right; x++)
                    if (GetCellSimple(x,y) !=NULL)
                        DelCell(x,y);
        }
        if (GetCellSimple(Col,Row) !=NULL)
            DelCell(Col,Row);
    }
    if (GetCellSimple(1,1) ==NULL)
    {
        NewCell(1,1);
        GetCellSimple(1,1)->Assign(GetCellSimple(0,0));
    }
    RecalculationEndCell(Col, Row);
}

void  TCellGrid::DelCell(int Col, int Row)
{
    if (GetCellSimple(Col,Row) !=NULL)
    {
        if (GetCellSimple(Col,Row)->UnionRect != NULL)
        {
            delete ((TRect*)GetCellSimple(Col,Row)->UnionRect);
            GetCellSimple(Col,Row)->UnionRect = NULL;
        }
        TCell* _Cell = GetCellSimple(Col,Row);
        delete _Cell;
        SetNewCell(Col,Row,NULL);
    }
}

int  TCellGrid::DelCellF(int Col, int Row, void * TheItem)
{
    TCell* Cell =  (TCell*)TheItem;
    if (Cell !=NULL && !(Cell->UnionRect !=NULL && !Rect1InRect2(*Cell->UnionRect,Matrix->DelRect)))
            DelAndSetDefaultCell(Col,Row);

    return 0;
}

void  TCellGrid::DelAndSetDefaultCellF(const TRect& Rect)
{
    Matrix->DelRect =Rect;
    FForAll((TRect)Rect,DelCellF);
}

void  TCellGrid::DelAndSetDefaultCell(const TRect& Rect)
{// Î÷èñòêà âûäåëåííîé îáëàñòè
    TRect rect2 =Rect;
    if (rect2.Bottom == RowCount-1)
        rect2.Bottom =EndColRowCell.y;
    if (rect2.Right == ColCount-1)
        rect2.Right =EndColRowCell.x;

    if (rect2.Left <1)
        rect2.Left =1;
    if (rect2.Top <1)
        rect2.Top =1;

    for (int y=rect2.Top; y<=rect2.Bottom; y++)
        for (int x=rect2.Left; x<=rect2.Right; x++)
            if (
              !(GetCellSimple(x,y) !=NULL &&
              GetCellSimple(x,y)->UnionRect !=NULL &&
              !Rect1InRect2(*GetCellSimple(x,y)->UnionRect,rect2)
              )
            )
                DelAndSetDefaultCell(x,y);

}

void  TCellGrid::DelAndSetDefaultCell(int Col, int Row)
{// Î÷èñòêà âûäåëåííîé îáëàñòè

    DelCell(Col,Row);
    if (!(Col ==1 && Row ==1))
    {
        NewCell(Col,Row);
        CopyCell1ToCell2(0,0,Col,Row);
        SetCircumferentialBorder(Col,Row);
    }
    if (GetCellSimple(1,1) ==NULL)
    {
        NewCell(1,1);
        GetCellSimple(1,1)->Assign(GetCellSimple(0,0));
    }
    RecalculationEndCell(Col, Row);
}

void TCellGrid::Initialize()
{
    if (!FData)
        FData = new TSparseList( (RowCount > 256) ? SPALarge : SPASmall );
}

void*  TCellGrid::EnsureDataRow(int aRow)
{
    if ( !((TSparseList*)FData)->Items[aRow] )
        ((TSparseList*)FData)->Items[aRow] = new TCellList( (RowCount > 256) ? SPALarge : SPASmall ) ;
    return ((TSparseList*)FData)->Items[aRow];
}

void  TCellGrid::SetCell(int aCol, int aRow, TCell* data)
{
    ((TSparseList*)EnsureDataRow(aRow))->Items[aCol] = data;
}

void  TCellGrid::SetNewCell(int aCol, int aRow, TCell* data)
{
    SetCell(aCol,aRow,data);
}

TCell*  TCellGrid::GetCell(int Col, int Row)
{
    TCell* Cell =GetCellSimple(Col, Row);
    if (Cell != NULL && Cell->UnionRect != NULL)
        Cell = GetCellSimple(Cell->UnionRect->Left, Cell->UnionRect->Top);
    return Cell;
}

TCell*  TCellGrid::GetCellSimple(int Col, int Row)
{

    if ( !((TSparseList*)FData)->Items[Row] )
        return NULL;
    else
        return (TCell*)((TSparseList*)EnsureDataRow(Row))->Items[Col];
}

// -----------   ------------------
namespace Gridcomponent
{
    void   Register()
    {
        TComponentClass classes[1] = {__classid(TCellGrid)};
        RegisterComponents("Samples", classes, 0);
    }
}
// -----------   END ------------------
void  TCellGrid::DoModalFormCellParameter()
{
    TCellParameter* CP = new TCellParameter(Application,this);
    CP->ShowModal();
    delete CP;
    InvalidateU2();
}

int  TCellGrid::GetAlignText(int Col, int Row)
{
    TCell* Cell =GetCellParam(Col,Row);
    int iAlign=0;
    if (Cell->CellFlags.TextWordBreak ==1)
    {
        iAlign =DT_WORDBREAK | DT_CALCRECT;
    } else
    {
        iAlign=DT_SINGLELINE | DT_CALCRECT;
    }

    if (Cell->CellFlags.TextHAlign ==0)
        iAlign =iAlign |DT_LEFT;
    if (Cell->CellFlags.TextHAlign ==1)
        iAlign =iAlign |DT_CENTER;
    if (Cell->CellFlags.TextHAlign ==2)
        iAlign =iAlign |DT_RIGHT;

    if (Cell->CellFlags.TextVAlign ==0)
    {
        iAlign =iAlign |DT_TOP;
    }
    if (Cell->CellFlags.TextVAlign ==1)
    {
        iAlign =iAlign |DT_VCENTER;
    }
    if (Cell->CellFlags.TextVAlign ==2)
    {
        iAlign =iAlign |DT_BOTTOM;
    }
    return iAlign;
}

void  TCellGrid::GetRectDrawText(int Col, int Row, const AnsiString& Text, TRect& calcrect)
{
    int iAlign=0;
    TCell* Cell =GetCellParam(Col,Row);
    SetCanvasParameterCell(Col,Row);
    iAlign =GetAlignText(Col,Row);
    TRect newcalcrect =calcrect;
    ::DrawText(Canvas->Handle, Text.c_str(), Text.Length(), &newcalcrect, iAlign);

    if (Cell->CellFlags.TextWordBreak ==1)
    {
        int iLen =Text.Length();
        int iCount =2;
        for (int i=1; i<=iLen; i++)
        {
            if (Text[i] =='\n')
                iCount++;
        }
        if (iCount >2)
            newcalcrect.Bottom =iCount*3 +newcalcrect.Top +iCount*-1*Canvas->Font->Height;
    } else
    {
        newcalcrect.Right +=6;
    }
    calcrect =newcalcrect;
}

TCellFlag*  TCellGrid::GetParamCell(int Col, int Row)
{ // Ïîëó÷èòü ÿ÷åéêó ñî âñåìè ïàðàìåòðàìè
    SetAllFlag(gCellFlag,true);
    if (Col >1 && Row ==1) // ÑòîëáåÖ
        gCellFlag->ColWidth =GetColWidths(Col);
    else if (Col ==1 && Row >1) // ÑòðîêåÖ
        gCellFlag->ColWidth =GetRowHeights(Row);
    else
        gCellFlag->ColWidth =0;

    if (GetCellSimple(Col,Row) !=NULL)// ß÷åéêà Ñóù
        CopyCell1ToCell2(Col,Row,gCellFlag);
    else
    {// // ß÷åéêà ÍÅ Ñóù

        CopyCell1ToCell2(Col,Row,gCellFlag);

        TCell* Cell11 =GetCellSimple(1,1);
        // Òàáëèöà
        gCellFlag->Line.WidthLeft    =Cell11->Line.WidthLeft;
        gCellFlag->Line.WidthTop     =Cell11->Line.WidthTop;
        gCellFlag->Line.WidthRight   =Cell11->Line.WidthRight;
        gCellFlag->Line.WidthBottom  =Cell11->Line.WidthBottom;

        //Ñîñåäíèå Ñòðîêè, Ñòîëáöû
        if (GetCellSimple(Col+1,1) !=NULL)// Left
            gCellFlag->Line.WidthRight =GetCellSimple(Col+1,1)->Line.WidthLeft;

        if (GetCellSimple(Col-1,1) !=NULL)// Right
            gCellFlag->Line.WidthLeft =GetCellSimple(Col-1,1)->Line.WidthRight;

        if (GetCellSimple(1,Row+1) !=NULL)// Left
            gCellFlag->Line.WidthBottom =GetCellSimple(1,Row+1)->Line.WidthTop;

        if (GetCellSimple(1,Row-1) !=NULL)// Right
            gCellFlag->Line.WidthTop =GetCellSimple(1,Row-1)->Line.WidthBottom;

        if (GetCellSimple(Col,1) !=NULL)
        {// Òåêóùèå Ñòîëáöû
            TCell* CellCol               =GetCellSimple(Col,1);
            gCellFlag->Line.WidthRight   =CellCol->Line.WidthRight;
            gCellFlag->Line.WidthLeft    =CellCol->Line.WidthLeft;
            gCellFlag->Line.WidthBottom  =CellCol->Line.WidthBottom;
            gCellFlag->Line.WidthTop     =CellCol->Line.WidthTop;
        }
        else if (GetCellSimple(1,Row) !=NULL)
        {// Òåêóùèå Ñòðîêè
            TCell* CellRow               =GetCellSimple(1,Row);
            gCellFlag->Line.WidthRight   =CellRow->Line.WidthRight;
            gCellFlag->Line.WidthLeft    =CellRow->Line.WidthLeft;
            gCellFlag->Line.WidthBottom  =CellRow->Line.WidthBottom;
            gCellFlag->Line.WidthTop     =CellRow->Line.WidthTop;
        }

        // Ñîñåäíèå ÿ÷åéêè
        if (GetCellSimple(Col+1,Row) !=NULL)// Left
            gCellFlag->Line.WidthRight =GetCellSimple(Col+1,Row)->Line.WidthLeft;

        if (GetCellSimple(Col-1,Row) !=NULL)// Right
            gCellFlag->Line.WidthLeft =GetCellSimple(Col-1,Row)->Line.WidthRight;

        if (GetCellSimple(Col,Row+1) !=NULL)// Bottom
            gCellFlag->Line.WidthBottom =GetCellSimple(Col,Row+1)->Line.WidthTop;

        if (GetCellSimple(Col,Row-1) !=NULL)// Top
            gCellFlag->Line.WidthTop =GetCellSimple(Col,Row-1)->Line.WidthBottom;

        // Òåêóùàÿ ÿ÷åéêà
        if (GetCellSimple(Col,Row) !=NULL)
        {
            TCell* Cell =GetCellSimple(Col,Row);
            gCellFlag->Line.WidthRight   =Cell->Line.WidthRight;
            gCellFlag->Line.WidthLeft    =Cell->Line.WidthLeft;
            gCellFlag->Line.WidthBottom  =Cell->Line.WidthBottom;
            gCellFlag->Line.WidthTop     =Cell->Line.WidthTop;
        }
    }
    if (gCellFlag->UnionRect ==NULL)
    {
        NullRect(gCellFlag->UnionCell);
        gCellFlag->f_UnionCell =false;
    }
    else
    {
        gCellFlag->UnionCell.Left   =gCellFlag->UnionRect->Left;
        gCellFlag->UnionCell.Top    =gCellFlag->UnionRect->Top;
        gCellFlag->UnionCell.Right  =gCellFlag->UnionRect->Right;
        gCellFlag->UnionCell.Bottom =gCellFlag->UnionRect->Bottom;
    }

    return gCellFlag;
}

void  TCellGrid::SetCanvasParameterCell(int Col, int Row)
{// Óñòàíîâèòü â Canvas ïàðàìåòðû ÿ÷åéêè
    TCell* Cell =GetCellParam(Col,Row);
    Canvas->Font->Name =Cell->FontName;
    Canvas->Font->Size =Cell->CellFlags.FontSize;
    
    // Ñòèëü øðèôòà (Îáû÷íû=0, Êóðñèâ=1, Æèðíûé=2, Æèðíûé êóðñèâ=3,
    TFontStyles Style;
    switch (Cell->CellFlags.FontStyle)
    {
        case 0:
        {// Îáû÷íûé
            Style.Clear();
            break;
        }
        case 1:
        {// Êóðñèâ
            Style <<fsItalic;
            break;
        }
        case 2:
        {// Æèðíûé
            Style <<fsBold;
            break;
        }
        case 3:
        {// Æèðíûé êóðñèâ
            Style <<fsBold <<fsItalic;
            break;
        }
    }
    if (Cell->CellFlags.FontStrikeOut ==1)
    {// Çà÷åðêíóòûé øðèôò
        Style <<fsStrikeOut;
    }
    if (Cell->CellFlags.FontUnderline ==1)
    {// Ïîä÷åðêíóòûé øðèôò
        Style <<fsUnderline;
    }
    Canvas->Font->Style =Style;
}

void     TCellGrid::UseTextWordBreak(int Col, int Row)
{// Ïðèìåíèòü ïåðåíîñ ïî ñëîâàì
    if (GetCellParam(Col, Row)->CellFlags.TextWordBreak ==1)
    {
        TRect rectMax =GetGridRectToRectPixelNotUnionAndScroll(Col, Row);
        SetCanvasParameterCell(Col, Row);

        AnsiString Text =GetCellSimple(Col, Row)->Text;
        AnsiString str =EditText->FormatMultiLine(Text,rectMax);

        ::DrawText(Canvas->Handle, str.c_str(),
        str.Length(), &rectMax, DT_WORDBREAK | DT_CALCRECT);
        if (GetRowHeights(Row) < rectMax.Bottom -rectMax.Top &&
            GetCellParam(1,Row)->CellFlags.TextHeightAuto ==1
        )
        {
            if (Height-100 >rectMax.Bottom -rectMax.Top)
                SetRowHeights(Row,rectMax.Bottom -rectMax.Top);
            else
                SetRowHeights(Row,Height-100);
        }
    }
}

void  TCellGrid::ShowEditText(int Col, int Row, bool clear)
{
    TRect rect=GetGridRectToRectPixelNotUnionAndScroll(Col,Row);

    CurrentEditCell =rect;
    CurrentEditCol =Col;
    CurrentEditRow =Row;

    EditText->Visible = false;
    SetCanvasParameterCell(Col,Row);

    if (GetCellParam(Col, Row)->CellFlags.TextHAlign ==1) //Center
    {
        EditText->Alignment =taCenter;
    }
    else if (GetCellParam(Col, Row)->CellFlags.TextHAlign ==2) //Right
    {
        EditText->Alignment =taRightJustify;
    }
    else
    { // Left
        EditText->Alignment =taLeftJustify;
    }

    if (GetCellParam(Col, Row)->CellFlags.TextWordBreak ==0)
        EditText->WordWrap =false;
    else
        EditText->WordWrap =true;



    EditText->Font = Canvas->Font;

    EditText->Left =rect.Left;
    EditText->Top =rect.Top;
    EditText->Height =rect.Bottom -rect.Top;
    EditText->Width =rect.Right -rect.Left;
    EditText->Color =GetCellParam(Col, Row)->bgColor;
    EditText->Visible =true;
    EditText->Text ="Set";
    ::SetFocus(EditText->Handle);
    if (GetCell(Col, Row) !=NULL && !clear)
        EditText->Text =GetCell(Col, Row)->Text;
    else
        EditText->Text ="";
    if (clear && TempStringCell.Length()>0)
    {
        EditText->Text =TempStringCell;
    }
    EditText->SelStart = EditText->Text.Length();
}

void  TCellGrid::DoModalFormSection()
{
    TRect AncrCurr = GetAnchorCurrentSort();

// --------- Êîððåêòèðîâêà åñëè âûäåëåíû ïîëíîñòüþ (Ñòðîêà, Ñòîëáåö, Òàáëèöà)
    if (AncrCurr.Left ==2 && AncrCurr.Right == ColCount)
        SelectString=true;
    if (AncrCurr.Top ==2 && AncrCurr.Bottom == RowCount)
        SelectColumn=true;

    if (SelectColumn)
        AncrCurr.Top =1;
    if (SelectString)
        AncrCurr.Left =1;
    if (SelectTable)
    {
        AncrCurr.Top =1;
        AncrCurr.Left =1;
    }
// --------- Êîððåêòèðîâêà åñëè âûäåëåíû ïîëíîñòüþ (Ñòðîêà, Ñòîëáåö, Òàáëèöà) End

    if (AncrCurr.Left ==1 && AncrCurr.Top ==1)// íåëüçÿ
        ShowMessage(MSG_ERR_9);
    else if (AncrCurr.Left ==1)
    {// Ãîðèçîíòàëüíàÿ ñåêöèÿ
        bool OK=true;
        for (int y=AncrCurr.Top; y<=AncrCurr.Bottom; y++)
            for (int x=AncrCurr.Left; x<=AncrCurr.Right; x++)
                if (GetCell(x,y) !=NULL && GetCell(x,y)->UnionRect !=NULL)
                    if (!Rect1InRect2(*GetCell(x,y)->UnionRect, AncrCurr))
                        OK=false;
        if (OK)
        {
            TSectionDialog* SC = new TSectionDialog(Application,this);
            SC->ShowModal();
            delete SC;
        }
        else
            ShowMessage("Ñóùåñòâóåò îáúåäåíåííàÿ ÿ÷åéêà \n êîòîðîÿ âûõîäèò çà ãðàíèöó ñåêöèè!");

    }
    else if (AncrCurr.Top ==1)
    {// Âåðòèêàëüíàÿ ñåêöèÿ
        bool OK=true;
        for (int y=AncrCurr.Top; y<=AncrCurr.Bottom; y++)
            for (int x=AncrCurr.Left; x<=AncrCurr.Right; x++)
                if (GetCell(x,y) !=NULL && GetCell(x,y)->UnionRect !=NULL)
                    if (!Rect1InRect2(*GetCell(x,y)->UnionRect, AncrCurr))
                        OK=false;
        if (OK)
        {
            TSectionDialog* SC = new TSectionDialog(Application,this);
            SC->ShowModal();
            delete SC;
        }
        else
            ShowMessage("Ñóùåñòâóåò îáúåäåíåííàÿ ÿ÷åéêà \n êîòîðîÿ âûõîäèò çà ãðàíèöó ñåêöèè!");
    }
    else// íåëüçÿ
        ShowMessage(MSG_ERR_9);

    InvalidateU2();
}

void  TCellGrid::DoModalSelectColor(int Left, int Top)
{
}

void  TCellGrid::SetScrollStartCol()
{
    TGridCoord oldCurren = FCurrent;
    TGridCoord oldAnchor = FAnchor;

    if(HorzFixedLast)
    {
        TMyCustomGrid::LeftCol =FixedCols;
        FCurrent.X =StartMouseDown.X;
        FCurrent.Y =StartMouseDown.Y;
        FAnchor.X = FixedCols;
        InvalidateU2();
        HorzFixedLast = false;
        FCurrent = oldCurren;
        FAnchor = oldAnchor;

    }
    else
    {
        FCurrent.Y =StartMouseDown.Y;
        FCurrent.X =StartMouseDown.X;
    }
}

void  TCellGrid::NewCell(int Col, int Row)
{
    // - Äëÿ îïðåäåëåíèÿ ðàáî÷åãî ðåêòà ãäå ïðîâîäèëèñü èçìåíåíèÿ
    if (EndColRowCell.x <Col)
        EndColRowCell.x =Col;

    if (EndColRowCell.y <Row)
        EndColRowCell.y =Row;
    // - Äëÿ îïðåäåëåíèÿ ðàáî÷åãî ðåêòà ãäå ïðîâîäèëèñü èçìåíåíèÿ END


    if ((Col ==1 && Row ==1) ||
        (Col ==0 && Row ==0)
    )
    { // - Òàáëèöà ÿ÷åéêà 1:1
        SetNewCell(Col,Row, new TCellTab());
        TMyObject* MO =GetCell(Col,Row);
        ((TCellTab*)MO)->ColWidth =DefaultColWidth;
        ((TCellTab*)MO)->RowHeight =DefaultRowHeight;
    }
    else if (Col >1 && Row ==1)
    { // - Ñòîëáåö
        SetNewCell(Col,Row, new TCellColRow());
        TMyObject* MO =GetCell(Col,Row);
        ((TCellColRow*)MO)->ColRowWidth =GetColWidths(Col);
    }
    else if (Col ==1 && Row >1)
    { // - Ñòðîêà
        SetNewCell(Col,Row, new TCellColRow());
        TMyObject* MO =GetCell(Col,Row);
        ((TCellColRow*)MO)->ColRowWidth =GetRowHeights(Row);
    }
    else if (GetCellSimple(Col,Row) !=NULL)
    {
        throw EMyException("<TCellGrid::NewCell>: ß÷åéêà óæå ñóùåñòâóåò.");
    }
    else
        SetNewCell(Col,Row, new TCell());
}

void  TCellGrid::NewCell(int Col, int Row, TCell* data)
{
    // - Äëÿ îïðåäåëåíèÿ ðàáî÷åãî ðåêòà ãäå ïðîâîäèëèñü èçìåíåíèÿ
    if (EndColRowCell.x <Col)
        EndColRowCell.x =Col;

    if (EndColRowCell.y <Row)
        EndColRowCell.y =Row;
    // - Äëÿ îïðåäåëåíèÿ ðàáî÷åãî ðåêòà ãäå ïðîâîäèëèñü èçìåíåíèÿ END

    if (GetCellSimple(Col,Row) !=NULL)
        throw EMyException("<TCellGrid::NewCell>: ß÷åéêà óæå ñóùåñòâóåò.");
    else
    {
        SetNewCell(Col,Row, (TCell*)data->DynamicType->CreateFunction());
        GetCellSimple(Col,Row)->Assign(data);
    }
}

void  TCellGrid::CopyCell1ToCell2(int Col1, int Row1, int Col2, int Row2)
{// Êîïèðîâàòüü èç Cell1 â Cell2

    GetCellSimple(Col2, Row2)->bgColor      =GetCellSimple(Col1, Row1)->bgColor;
    GetCellSimple(Col2, Row2)->LineColorNot =GetCellSimple(Col1, Row1)->LineColorNot;
    GetCellSimple(Col2, Row2)->Text         =GetCellSimple(Col1, Row1)->Text;
    GetCellSimple(Col2, Row2)->FontName     =GetCellSimple(Col1, Row1)->FontName;
    GetCellSimple(Col2, Row2)->FontColor    =GetCellSimple(Col1, Row1)->FontColor;
    GetCellSimple(Col2, Row2)->CellFlags    =GetCellSimple(Col1, Row1)->CellFlags;
    GetCellSimple(Col2, Row2)->Line         =GetCellSimple(Col1, Row1)->Line;

    if (Col ==1 && Row ==1)
    {
        ((TCellTab*)GetCellSimple(Col1,Row1))->ColWidth    =((TCellTab*)GetCellSimple(Col2,Row2))->ColWidth;
        ((TCellTab*)GetCellSimple(Col1,Row1))->RowHeight   =((TCellTab*)GetCellSimple(Col2,Row2))->RowHeight;
    }
    if ((Col >1 && Row ==1)||(Col ==1 && Row >1))
        ((TCellColRow*)GetCellSimple(Col1,Row1))->ColRowWidth =((TCellColRow*)GetCellSimple(Col1,Row1))->ColRowWidth;

    if (GetCellSimple(Col1, Row1)->UnionRect !=NULL)
    {
        if (GetCellSimple(Col2, Row2)->UnionRect ==NULL)
            GetCellSimple(Col2, Row2)->UnionRect = new TRect();
        GetCellSimple(Col2, Row2)->UnionRect->Left      =GetCellSimple(Col1, Row1)->UnionRect->Left;
        GetCellSimple(Col2, Row2)->UnionRect->Top       =GetCellSimple(Col1, Row1)->UnionRect->Top;
        GetCellSimple(Col2, Row2)->UnionRect->Right     =GetCellSimple(Col1, Row1)->UnionRect->Right;
        GetCellSimple(Col2, Row2)->UnionRect->Bottom    =GetCellSimple(Col1, Row1)->UnionRect->Bottom;
    }
}

void  TCellGrid::CopyCell1ToCell2(int Col,int Row, TCell* Cell2)
{// Êîïèðîâàòüü èç Cell1 â Cell2

    TCell* Cell1=GetCellSimple(Col,Row);
    if (Cell1 ==NULL)
        Cell1 =GetCellParam(Col,Row);

    Cell2->UnionRect    =NULL;
    Cell2->bgColor      =Cell1->bgColor;
    Cell2->LineColorNot =Cell1->LineColorNot;
    Cell2->Text         =Cell1->Text;
    Cell2->FontName     =Cell1->FontName;
    Cell2->FontColor    =Cell1->FontColor;
    Cell2->Line         =Cell1->Line;
    Cell2->CellFlags    =Cell1->CellFlags;

    if (Col ==1 && Row ==1)
    {
        ((TCellFlag*)Cell2)->ColWidth    =((TCellTab*)GetCellSimple(Col,Row))->ColWidth;
        ((TCellFlag*)Cell2)->RowHeight   =((TCellTab*)GetCellSimple(Col,Row))->RowHeight;
    }
    if (((Col >1 && Row ==1)||(Col ==1 && Row >1))&& GetCellSimple(Col,Row) !=NULL)
        ((TCellFlag*)Cell2)->ColWidth =((TCellColRow*)GetCellSimple(Col,Row))->ColRowWidth;

    if (Cell1->UnionRect !=NULL)
    {
        if (Cell2->UnionRect ==NULL)
            Cell2->UnionRect = new TRect();
        Cell2->UnionRect->Left      =Cell1->UnionRect->Left;
        Cell2->UnionRect->Top       =Cell1->UnionRect->Top;
        Cell2->UnionRect->Right     =Cell1->UnionRect->Right;
        Cell2->UnionRect->Bottom    =Cell1->UnionRect->Bottom;
    }
}

void  TCellGrid::CopyCell1ToCell2(TCell* Cell1, int Col,int Row)
{// Êîïèðîâàòüü èç Cell1 â Cell2
    TCell* Cell2;
    if (GetCellSimple(Col,Row) ==NULL)
        Cell2 =GetCellParam(Col,Row);
    else
        Cell2 =GetCellSimple(Col,Row);

    Cell2->UnionRect    =NULL;
    Cell2->bgColor      =Cell1->bgColor;
    Cell2->LineColorNot =Cell1->LineColorNot;
    Cell2->Text         =Cell1->Text;
    Cell2->FontName     =Cell1->FontName;
    Cell2->FontColor    =Cell1->FontColor;
    Cell2->Line         =Cell1->Line;
    Cell2->CellFlags    =Cell1->CellFlags;

    if (Col ==1 && Row ==1)
    {
        ((TCellTab*)Cell2)->ColWidth    =((TCellTab*)GetCellSimple(Col,Row))->ColWidth;
        ((TCellTab*)Cell2)->RowHeight   =((TCellTab*)GetCellSimple(Col,Row))->RowHeight;
    }
    if ((Col >1 && Row ==1)||(Col ==1 && Row >1))
        ((TCellColRow*)Cell2)->ColRowWidth =((TCellColRow*)GetCellSimple(Col,Row))->ColRowWidth;

    if (Cell1->UnionRect !=NULL)
    {
        if (Cell2->UnionRect ==NULL)
            Cell2->UnionRect = new TRect();
        Cell2->UnionRect->Left      =Cell1->UnionRect->Left;
        Cell2->UnionRect->Top       =Cell1->UnionRect->Top;
        Cell2->UnionRect->Right     =Cell1->UnionRect->Right;
        Cell2->UnionRect->Bottom    =Cell1->UnionRect->Bottom;
    }
}

void  TCellGrid::NewCellAndSetDefault(int Col, int Row, byte ColRow/*0=Auto, 1=Col, 2=Row*/)
{
    if (GetCell(Col,Row))
        throw EMyException("<TCellGrid::NewCellAndSetDefault>: ß÷åéêà óæå ñóùåñòâóåò.");

    if ((Col != 1)||(Row !=1))
    {
        if ((Col > 1)&&(Row >1))
        {
            if (ColRow ==0)
            {
                if (GetCell(1, Row) != NULL)
                {
                    NewCell(Col,Row);
                    CopyCell1ToCell2(1, Row, Col, Row);
                } else
                if (GetCell(Col, 1) != NULL)
                {
                    NewCell(Col,Row);
                    CopyCell1ToCell2(Col, 1, Col, Row);
                } else
                {
                    NewCell(Col,Row);
                    CopyCell1ToCell2(1, 1, Col, Row);
                }
            }
            else if (ColRow ==1)
            {// Âçÿòü èç ñòîëáöà
                if (GetCell(Col, 1) != NULL)
                {
                    if (GetCell(Col, Row) != NULL)
                        CopyCell1ToCell2(Col, 1, Col, Row);
                    else
                    {
                        NewCell(Col,Row);
                        CopyCell1ToCell2(Col, 1, Col, Row);
                    }
                }
            }
            else if (ColRow ==2)
            {// Âçÿòü èç Ñòðîêè
                if (GetCell(1, Row) != NULL)
                {
                    if (GetCell(Col, Row) != NULL)
                        CopyCell1ToCell2(1, Row, Col, Row);
                    else
                    {
                        NewCell(Col,Row);
                        CopyCell1ToCell2(1, Row, Col, Row);
                    }
                }
            }

        }
        else if ((Col == 1)&&(Row >1))
        { // Ñòðîêà
            NewCell(Col,Row);
            CopyCell1ToCell2(1, 1, Col, Row);
        }
        else if ((Col > 1)&&(Row == 1))
        { // Ñòîëáåö
            NewCell(Col,Row);
            CopyCell1ToCell2(1, 1, Col, Row);
        }
    }
    else
        throw EMyException("<TCellGrid::NewCellAndSetDefault>: íå ïðåäíàçíà÷åíà äëÿ \n ñîçäàíèÿ ÿ÷åéêè 1:1");
}

void  TCellGrid::NewCellAndSetDefault2(int Col, int Row, byte ColRow/*0=Auto, 1=Col, 2=Row*/)
{
    if (GetCellSimple(Col,Row))
        throw EMyException("<TCellGrid::NewCellAndSetDefault>: ß÷åéêà óæå ñóùåñòâóåò.");

    if (Col != 1 || Row !=1)
    {
        if (Col > 1 && Row >1)
        {
            if (GetCellSimple(1, Row) != NULL && ColRow==2)
            {// Ñòðîêè
                NewCell(Col,Row);
                CopyCell1ToCell2(1, Row, Col, Row);
            }
            if (GetCellSimple(Col, 1) != NULL && ColRow==1)
            {// Ñòîëáöû
                NewCell(Col,Row);
                CopyCell1ToCell2(Col, 1, Col, Row);
            }
            if (ColRow ==0)
            {// ÿ÷åéêè
                NewCell(Col,Row);
                if (GetCellSimple(1, Row) != NULL)
                {// Ñòðîêè
                    CopyCell1ToCell2(1, Row, Col, Row);
                }
                else if (GetCellSimple(Col, 1) != NULL)
                {// Ñòîëáöû
                    CopyCell1ToCell2(Col, 1, Col, Row);
                }
                else
                {// 1:1
                    CopyCell1ToCell2(1, 1, Col, Row);
                }
            }

            // Áîðäþð
            // Îáëàäàåò îñîáûìè ïàðàìåòðàìè
            if ((ColRow==1 || ColRow==0) && GetCellSimple(Col-1, 1) !=NULL)
                GetCellSimple(Col, Row)->Line.WidthLeft =GetCellSimple(Col-1, 1)->Line.WidthRight;

            if ((ColRow==2 || ColRow==0) && GetCellSimple(1, Row-1) !=NULL)
                GetCellSimple(Col, Row)->Line.WidthTop =GetCellSimple(1, Row-1)->Line.WidthBottom;

            if ((ColRow==1 || ColRow==0) && GetCellSimple(Col+1, 1) !=NULL)
                GetCellSimple(Col, Row)->Line.WidthRight =GetCellSimple(Col+1, 1)->Line.WidthLeft;

            if ((ColRow==2 || ColRow==0) && GetCellSimple(1, Row+1) !=NULL)
                GetCellSimple(Col, Row)->Line.WidthBottom =GetCellSimple(1, Row+1)->Line.WidthTop;

            // Ñóùåñòâóþò
            if (GetCellSimple(Col-1, Row) !=NULL)
                GetCellSimple(Col, Row)->Line.WidthLeft =GetCellSimple(Col-1, Row)->Line.WidthRight;

            if (GetCellSimple(Col, Row-1) !=NULL)
                GetCellSimple(Col, Row)->Line.WidthTop =GetCellSimple(Col, Row-1)->Line.WidthBottom;

            if (GetCellSimple(Col+1, Row) !=NULL)
                GetCellSimple(Col, Row)->Line.WidthRight =GetCellSimple(Col+1, Row)->Line.WidthLeft;

            if (GetCellSimple(Col, Row+1) !=NULL)
                GetCellSimple(Col, Row)->Line.WidthBottom =GetCellSimple(Col, Row+1)->Line.WidthTop;
        }
        else
        {
            NewCell(Col,Row);
            CopyCell1ToCell2(1, 1, Col, Row);
            if (Col ==1)
            {
                if (GetCellSimple(Col, Row-1) !=NULL)
                    GetCellSimple(Col, Row)->Line.WidthTop =GetCellSimple(Col, Row-1)->Line.WidthBottom;
                if (GetCellSimple(Col, Row+1) !=NULL)
                    GetCellSimple(Col, Row)->Line.WidthBottom =GetCellSimple(Col, Row+1)->Line.WidthTop;
            }
            if (Row ==1)
            {
                if (GetCellSimple(Col-1, Row) !=NULL)
                    GetCellSimple(Col, Row)->Line.WidthLeft =GetCellSimple(Col-1, Row)->Line.WidthRight;
                if (GetCellSimple(Col+1, Row) !=NULL)
                    GetCellSimple(Col, Row)->Line.WidthRight =GetCellSimple(Col+1, Row)->Line.WidthLeft;
            }
        }
    }
    else
        throw EMyException("<TCellGrid::NewCellAndSetDefault>: íå ïðåäíàçíà÷åíà äëÿ \n ñîçäàíèÿ ÿ÷åéêè 1:1");

}

void  TCellGrid::NewCellAndSetParam(int Col, int Row)
{
    if (GetCellSimple(Col,Row))
        throw EMyException("<TCellGrid::NewCellAndSetDefault>: ß÷åéêà óæå ñóùåñòâóåò.");

    if (Col == 1 && Row >1)
    {// Ñòðîêà
        NewCellAndSetDefault2(Col,Row,0);
        for (int i=2; i<=EndColRowCell.x; i++)
            if (GetCell(i,1) !=NULL && GetCell(i,Row) ==NULL)
                NewCellAndSetDefault2(i,Row,1);
    }
    else if (Col > 1 && Row ==1)
    {// Ñòîëáåö
        NewCellAndSetDefault2(Col,Row,0);
        for (int i=2; i<=EndColRowCell.y; i++)
            if (GetCell(1,i) !=NULL && GetCell(Col,i) ==NULL)
                NewCellAndSetDefault2(Col,i,2);
    }
    else if (Col > 1 && Row >1)
    {// ß÷åéêà
        NewCellAndSetDefault2(Col,Row,0);
    }
}

int  TCellGrid::ProcessCell(int Col, int Row, void * TheItem)
{
    TCell* Cell =  (TCell*)TheItem;
    if (Cell !=NULL )
    {
        TCellFlag* getcell =GetParamCell(Col,Row);
        if (!(getcell->f_UnionCell && !Rect1InRect2(getcell->UnionCell,Matrix->RectCopy)))
        {
            Matrix->NewCell(Col,Row);
            TCellFlag* setcell =Matrix->GetCellSimple(Col,Row);
            SetAllFlag(setcell,false);
            getcell->f_SetUnion =false;
            CopyFlag1ToFlag2(getcell,setcell);
        }
    }
    return 0;
}

void   TCellGrid::CopyInBuff(const TRect& rect)
{
    Matrix->ClearAll();
    Matrix->RectCopy =rect;
    if (rect.Left >1 && rect.Top >1)
    { // ß÷åéêè
        FForAll((TRect)rect,ProcessCell);
        FForAll(TRect(1,rect.Top,1,rect.Bottom),ProcessCell);
        FForAll(TRect(rect.Left,1,rect.Right,1),ProcessCell);
        FForAll(TRect(1,1,1,1),ProcessCell);
    }
    else if (rect.Left ==1 && rect.Top >1)
    { // Ñòðîêà
        FForAll(TRect(1,rect.Top,ColCount,rect.Bottom),ProcessCell);
        FForAll(TRect(1,1,ColCount,1),ProcessCell);
    }
    else if (rect.Left >1 && rect.Top ==1)
    { // Ñòîëáåö
        FForAll(TRect(rect.Left,1,rect.Right,RowCount),ProcessCell);
        FForAll(TRect(1,1,1,RowCount),ProcessCell);
    }
    else if (rect.Left ==1 && rect.Top ==1)// Òàáëèöà
        FForAll(TRect(1,1,ColCount,RowCount),ProcessCell);
}

void   TCellGrid::SetListFillingToCopy(const TRect& rect)
{
    if (ListFilling.Count >0)
        ListFilling.Clear();
    if (ListFilling2.Count >0)
        ListFilling2.Clear();

    if (rect.Left >1 && rect.Top >1) // ß÷åéêè
    {
        for (int y=rect.Top; y<=rect.Bottom; y++)
            for (int x=rect.Left; x<=rect.Right; x++)
                ListFilling.Add(new TPoint(x,y));
    }
    else if (rect.Left ==1 && rect.Top >1) // Ñòðîêà
    {
        FForAll(TRect(2,1, ColCount,1),ProcessCellTest);
        for (int y=rect.Top; y<=rect.Bottom; y++)
            for (int i=0; i<ListFilling2.Count; i++)
                if (GetCellSimple(ListFilling2[i].x,y)==NULL)
                    ListFilling.Add(new TPoint(ListFilling2[i].x,y));

        FForAll(TRect(1,rect.Top, ColCount,rect.Bottom),CellYes);
    }
    else if (rect.Left >1 && rect.Top ==1)// Ñòîëáåö
    {
        FForAll(TRect(1,2, 1,RowCount),ProcessCellTest);
        for (int x=rect.Left; x<=rect.Right; x++)
            for (int i=0; i<ListFilling2.Count; i++)
                if (GetCellSimple(x,ListFilling2[i].y)==NULL)
                    ListFilling.Add(new TPoint(x,ListFilling2[i].y));
        FForAll(TRect(rect.Left,1, rect.Right,RowCount),CellYes);

    }
    else if (rect.Left ==1 && rect.Top ==1) // Òàáëèöà
        FForAll(TRect(1,1, ColCount,RowCount),ProcessCellTest);
/*
    AnsiString str;
    for (int i=0; i<ListFilling.Count; i++)
    {
        str +="x: ";
        str +=IntToStr(ListFilling[i].x);
        str +="  y: ";
        str +=IntToStr(ListFilling[i].y);
    }
    int i=0;
*/
}

int  TCellGrid::ProcessCellTest(int Col, int Row, void * TheItem)
{
    TCell* Cell =  (TCell*)TheItem;
    if (Cell !=NULL )
        ListFilling2.Add(new TPoint(Col,Row));
    return 0;
}

int  TCellGrid::CellYes(int Col, int Row, void * TheItem)
{
    TCell* Cell =  (TCell*)TheItem;
    if (Cell !=NULL )
        ListFilling.Add(new TPoint(Col,Row));
    return 0;
}

int  TCellGrid::ProcessCellTest2(int Col, int Row, void * TheItem)
{
    //òîëüêî äëÿ ñòðî÷êè èëè äëÿ ñòîëáöà, ïîñëå âûïîëíåíèÿ <ProcessCellTest>
    //ListFilling2 óæå çàïîëíåí äëÿ ñòîëáöà ñòðî÷êàìè, äëÿ ñòðî÷åê ñòîëáöàìè
    TCell* Cell =  (TCell*)TheItem;
    if (Cell != NULL )
    {
        if (Col!=1 && Row!=1)
            throw EMyException("<TCellGrid::ProcessCellTest2>: äîëæåí âûçûâàòüñÿ òîëüêî äëÿ ñòðî÷êè èëè äëÿ ñòîëáöà.");
        else if (Col == 1)
            for (int i=0; i<ListFilling2.Count; i++)
                ListFilling.Add( new TPoint(ListFilling2[i].x,Row) );
        else
            for (int i=0;i<ListFilling2.Count;i++)
                ListFilling.Add( new TPoint(Col,ListFilling2[i].y) );
    }

    return 0;
}

void   TCellGrid::GetCellToTest(const TRect& rect)
{
    if (ListFilling.Count >0)
        ListFilling.Clear();
    if (ListFilling2.Count >0)
        ListFilling2.Clear();

    if (rect.Left >1 && rect.Top >1) // ß÷åéêè
    {
        for (int y=rect.Top; y<=rect.Bottom; y++)
            for (int x=rect.Left; x<=rect.Right; x++)
                ListFilling.Add(new TPoint(x,y));
    }
    else if (rect.Left ==1 && rect.Top >1) // Ñòðîêà
    {
        for (int y=rect.Top; y<=rect.Bottom; y++)
            ListFilling2.Add(new TPoint(1,y));//âñïîìîãàòåëüíûå
        for (int i=0; i<ListFilling2.Count; i++)
            ListFilling.Add(new TPoint(ListFilling2[i].x,ListFilling2[i].y));

        FForAll(TRect(2,1, ColCount,1),ProcessCellTest2);//ïîäîçðèòåëüíûå â ListFilling
        ListFilling2.Clear();
        FForAll(TRect(2,rect.Top, ColCount,rect.Bottom),ProcessCellTest);//ñóùåñòâóþùèå â ListFilling2
        //ñîáèðàåì âñå â ListFilling
        for (int i=0; i<ListFilling2.Count; i++)
            ListFilling.Add(new TPoint(ListFilling2[i].x,ListFilling2[i].y));
    }
    else if (rect.Left >1 && rect.Top ==1)// Ñòîëáåö
    {
        for (int x=rect.Left; x<=rect.Right; x++)
            ListFilling2.Add(new TPoint(x,1));//2 âñïîìîãàòåëüíûå

        for (int i=0; i<ListFilling2.Count; i++)
            ListFilling.Add(new TPoint(ListFilling2[i].x,ListFilling2[i].y));

        FForAll(TRect(1,2,1,RowCount),ProcessCellTest2);//ïîäîçðèòåëüíûå â ListFilling
        ListFilling2.Clear();
        FForAll(TRect(rect.Left,2, rect.Right,RowCount),ProcessCellTest); //ñóùåñòâóþùèå â ListFilling2
        //ñîáèðàåì âñå â ListFilling
        for (int i=0; i<ListFilling2.Count; i++)
            ListFilling.Add(new TPoint(ListFilling2[i].x,ListFilling2[i].y));
    }
    else if (rect.Left ==1 && rect.Top ==1) // Òàáëèöà
        FForAll(TRect(1,1, ColCount,RowCount),CellYes);
}

void   TCellGrid::PasteBuffInGrid(int Col, int Row)
{
    int x,y;
    if (Matrix->RectCopy.Left !=0)
    {
        TCell* CellSimpl =GetCellSimple(Col,Row);
        if (CellSimpl !=NULL && CellSimpl->UnionRect !=NULL)
        {
            Col =CellSimpl->UnionRect->Left;
            Row =CellSimpl->UnionRect->Top;
        }
        if (Matrix->CopyCell)
        {
            SetListFillingToCopy(Matrix->RectCopy);
            TCellFlag* CellFlag;

            if (Matrix->FieldCut)
                DelAndSetDefaultCellF(Matrix->RectCopy);
            Matrix->FieldCut =false;

            for (int i=0; i<ListFilling.Count; i++)
            {
                x                  =Col +ListFilling[i].x -Matrix->RectCopy.Left;
                y                  =Row +ListFilling[i].y -Matrix->RectCopy.Top;
                TCell* Cell         =GetCellParam(x,y);
                TCellFlag* CellFlag =Matrix->GetParamCell(ListFilling[i].x,ListFilling[i].y);

                ClearCell(x,y);
                if (CellFlag->f_UnionCell)
                {
                    TRect oldRect =CellFlag->UnionCell;
                    CellFlag->UnionCell.Left    +=Col -Matrix->RectCopy.Left;
                    CellFlag->UnionCell.Top     +=Row -Matrix->RectCopy.Top;
                    CellFlag->UnionCell.Right   +=Col -Matrix->RectCopy.Left;
                    CellFlag->UnionCell.Bottom  +=Row -Matrix->RectCopy.Top;
                    CellFlag->f_SetUnion        =true;

                    if ( !ParamCellCompare(Cell, CellFlag) )
                        SetFlagCell(x,y,CellFlag);
                    CellFlag->UnionCell =oldRect;
                }
                else if ( !ParamCellCompare(Cell, CellFlag) )
                        SetFlagCell(x,y,CellFlag);
            }
        }
        else
        {
            TCellFlag* CellFlag;
            GetCellToTest(Matrix->RectCopy);
            UndoStack.OpenSession("rmChanged");
            for (int i=0; i<ListFilling.Count; i++)
            {
                TCellFlag* Cell         =GetParamCell(ListFilling[i].x,ListFilling[i].y);

                UndoRegister(ListFilling[i].x,ListFilling[i].y,rmChanged);
                
                SetAllFlag(Cell,false);
                CellFlag =Matrix->GetParamCellAndFlag(ListFilling[i].x,ListFilling[i].y);
                if (Cell->UnionRect !=NULL && Rect1InRect2(*Cell->UnionRect,Matrix->RectCopy))
                    CellFlag->f_SetUnion =true;

                CellFlag->f_UnionCell =false;

                if ( !ParamCellCompare(Cell, CellFlag) )
                    SetFlagCell(ListFilling[i].x,ListFilling[i].y,CellFlag);
            }
            UndoStack.CloseSession();
        }
    }
    Matrix->CopyCell =false;
}

void  TCellGrid::FForAll(TRect& rect, TMyFunc Func)
{
    ((TSparseList*)FData)->SForAll(rect,Func);
}

void  TCellGrid::SetScrollStartRow()
{
    TGridCoord oldCurren = FCurrent;
    TGridCoord oldAnchor = FAnchor;

    if(VertFixedLast)
    {
        TMyCustomGrid::TopRow =FixedRows;
        FCurrent.Y =StartMouseDown.Y;
        FCurrent.X =StartMouseDown.X;
        FAnchor.Y = FixedRows;

        InvalidateU2();
        VertFixedLast = false;
        FCurrent = oldCurren;
        FAnchor = oldAnchor;
    }
    else
    {
        FCurrent.Y =StartMouseDown.Y;
        FCurrent.X =StartMouseDown.X;
    }
}

void  TCellGrid::StartTime(TObject *Sender)
{
    Matrix->ColCount =ColCount;
    Matrix->RowCount =RowCount;

    TStart->Enabled = false;
    TShiftState ss;
    TRect rect = GetGridRectToRectPixelUnionReal(2,2);
    ss.Clear();
    ss << ssLeft;
    CellGridMouseDown(this ,mbLeft,ss,rect.Left,rect.Top);
    CellGridMouseUp(this,mbLeft,ss,rect.Left,rect.Top);
    InvalidateU2();

}

void  TCellGrid::OnTimer(TObject *Sender)
{// Äëÿ îáðàáîòêè ñêðîëèðîâàíèÿ
    TGridCoord CellHit1 =MousePosCellMove;
    TGridCoord CellHit2;
    bool InvalidateOk   =false;

    ScrollParam=0;
    if (CellHit1.Y ==-1 && FAnchor.Y == DrawInfo.Vert.GridCellCount-1)
        CellHit1 = FAnchor;
    if (CellHit1.X ==-1 && FAnchor.X == DrawInfo.Horz.GridCellCount-1)
        CellHit1 = FAnchor;

    if (CellHit1.Y <2)
        CellHit1.Y=2;
    if (CellHit1.X <2)
        CellHit1.X=2;

    Timer->Interval -=5;
    if (Timer->Interval <20)
        Timer->Interval = 20;

    TPoint Pos =CalcCursorPos();
    TGridCoord PosCell =MouseCoord(Pos.x,Pos.y);

    if (MoveCellBorder)
    {
        if (PosCell.X <DrawInfo.Horz.FirstGridCell -DrawInfo.Horz.FixedCellCount+2)
            PosCell.X =DrawInfo.Horz.FirstGridCell -DrawInfo.Horz.FixedCellCount+2;
        if (PosCell.Y <DrawInfo.Vert.FirstGridCell -DrawInfo.Vert.FixedCellCount+2)
            PosCell.Y =DrawInfo.Vert.FirstGridCell -DrawInfo.Vert.FixedCellCount+2;

        if (PosCell.X >DrawInfo.Horz.LastFullVisibleCell)
            PosCell.X =DrawInfo.Horz.LastFullVisibleCell;
        if (PosCell.Y >DrawInfo.Vert.LastFullVisibleCell)
            PosCell.Y =DrawInfo.Vert.LastFullVisibleCell;

        DrawCursorMove2(PosCell.X,PosCell.Y);
        if (!((PosCell.Y <=DrawInfo.Vert.FirstGridCell &&
            DrawInfo.Vert.FirstGridCell == DrawInfo.Vert.FixedCellCount) ||
            (PosCell.X <=DrawInfo.Horz.FirstGridCell &&
            DrawInfo.Horz.FirstGridCell == DrawInfo.Horz.FixedCellCount)
        ))
        {
            if (CurrentMouseCoordTimer.X <=DrawInfo.Horz.FirstGridCell)
                ModifyScrollBar(0,0,0,true);
            else if (CurrentMouseCoordTimer.Y <=DrawInfo.Vert.FirstGridCell)
                ModifyScrollBar(1,0,0,true);
            else if (CurrentMouseCoordTimer.X >=DrawInfo.Horz.LastFullVisibleCell)
                ModifyScrollBar(0,1,0,true);
            else if (CurrentMouseCoordTimer.Y >=DrawInfo.Vert.LastFullVisibleCell)
                ModifyScrollBar(1,1,0,true);
            }
    }
    else
    {

        if (CellHit1.Y <=FixedRows &&
            StartMouseDown.Y < FixedRows &&
            DrawInfo.Vert.FirstGridCell >FixedRows)
        {// (1, 9)
            if (DrawInfo.Vert.FirstGridCell != FixedRows &&
                CellHit1.Y <= FixedRows &&
                !VertFixedLast)
            {
                ModifyScrollBar(1,0,0,true);
                FCurrent.Y =StartMouseDown.Y;
                InvalidateOk = true;

                if (DrawInfo.Vert.FirstGridCell != FixedRows+1)
                {
                    CellHit2 =CellHit1;
                    CellHit2.Y =FixedRows;
                    TRect rect= CalculationRect(StartMouseDown, CellHit2);
                    FCurrent.X = rect.Left;
                    FCurrent.Y = rect.Top;
                    FAnchor.Y =FixedRows;
                    ScrollParam=17;
                }
                else
                {
                    TRect rect= CalculationRect(StartMouseDown, CellHit1);
                    FCurrent.X = rect.Left;
                    FCurrent.Y = rect.Top;
                    FAnchor.X = rect.Right;
                    FAnchor.Y = rect.Bottom;
                }
            }
        }
        if (CellHit1.X <=FixedCols &&
            StartMouseDown.X < FixedCols &&
            DrawInfo.Horz.FirstGridCell >FixedCols)
        {// (5, 10)

            if (DrawInfo.Horz.FirstGridCell != FixedCols &&
                CellHit1.X <= FixedCols &&
                !HorzFixedLast)
            {
                ModifyScrollBar(0,0,0,true);
                FCurrent.X =StartMouseDown.X;
                InvalidateOk = true;
                if (DrawInfo.Horz.FirstGridCell != FixedCols+1)
                {
                    CellHit2 =CellHit1;
                    CellHit2.X =FixedCols;
                    TRect rect= CalculationRect(StartMouseDown, CellHit2);
                    FCurrent.X = rect.Left;
                    FCurrent.Y = rect.Top;
                    FAnchor.X =FixedCols;
                    ScrollParam=18;
                }
                else
                {
                    TRect rect= CalculationRect(StartMouseDown, CellHit1);
                    FCurrent.X = rect.Left;
                    FCurrent.Y = rect.Top;
                    FAnchor.X = rect.Right;
                    FAnchor.Y = rect.Bottom;
                }
            }
        }
        if (StartMouseDown.X > FixedCols &&
            DrawInfo.Horz.FirstGridCell >FixedCols &&
            StartMouseDown.Y < FixedRows)
        {// (16)

            if (DrawInfo.Horz.FirstGridCell != FixedCols &&
                CellHit1.X <= FixedCols)
            {
                ModifyScrollBar(0,0,0,true);
                FCurrent.X =StartMouseDown.X;
                FAnchor.X =FixedCols;
                InvalidateOk = true;
                if (CellHit1.X>1)
                {
                    TRect rect =CalculationRect(CellHit1, StartMouseDown);
                    FCurrent.X =rect.Right;
                    if (DrawInfo.Horz.FirstGridCell ==FixedCols+1)
                        FAnchor.X =rect.Left;
                    else
                        FAnchor.X =DrawInfo.Horz.FirstGridCell-1;
                }
                else
                {
                    FCurrent.X =StartMouseDown.X;
                    FAnchor.X =2;
                }
            }
        }
        if (StartMouseDown.Y > FixedRows &&
            DrawInfo.Vert.FirstGridCell >FixedRows &&
            StartMouseDown.X < FixedCols)
        {// (15)

            if (DrawInfo.Vert.FirstGridCell != FixedRows &&
                CellHit1.Y <= FixedRows)
            {
                ModifyScrollBar(1,0,0,true);
                FCurrent.Y =StartMouseDown.Y;
                FAnchor.Y =FixedRows;
                InvalidateOk = true;
                if (CellHit1.Y>1)
                {
                    TRect rect =CalculationRect(CellHit1, StartMouseDown);
                    FCurrent.Y =rect.Bottom;
                    if (DrawInfo.Vert.FirstGridCell ==FixedRows+1)
                        FAnchor.Y =rect.Top;
                    else
                        FAnchor.Y =DrawInfo.Vert.FirstGridCell-1;
                }
                else
                {
                    FCurrent.Y =StartMouseDown.Y;
                    FAnchor.Y =2;
                }
            }
        }
        if (StartMouseDown.X >0 &&
            StartMouseDown.Y >0 &&
            (StartMouseDown.Y < FixedRows ||
            StartMouseDown.X < FixedCols))
        {
            if (MouseX >Width-24 && CellHit1.X > FixedCols)
            {// (3, 6)
                ModifyScrollBar(0,1,0,true);
                FAnchor.X =DrawInfo.Horz.LastFullVisibleCell;
                InvalidateOk = true;
            }
            if (MouseY >Height && CellHit1.Y > FixedRows)
            {// (8, 2)
                ModifyScrollBar(1,1,0,true);
                FAnchor.Y =DrawInfo.Vert.LastFullVisibleCell;
                InvalidateOk = true;
            }
        }
        if (PosCell.X >DrawInfo.Horz.LastFullVisibleCell ||
            PosCell.Y >DrawInfo.Vert.LastFullVisibleCell
        )
        {
            if (PosCell.X >DrawInfo.Horz.LastFullVisibleCell)
            {// Right
                ModifyScrollBar(0,1,0,true);
                FAnchor.X =DrawInfo.Horz.LastFullVisibleCell;
                InvalidateOk = true;
            }
            if (PosCell.Y >DrawInfo.Vert.LastFullVisibleCell)
            {// Bottom
                ModifyScrollBar(1,1,0,true);
                FAnchor.Y =DrawInfo.Vert.LastFullVisibleCell;
                InvalidateOk = true;
            }
        }
        else if (StartMouseDown.X >=FixedCols &&
            StartMouseDown.Y >=FixedRows)
        {
            if (DrawInfo.Vert.FirstGridCell != FixedRows && CellHit1.Y <= FixedRows)
            {
                ModifyScrollBar(1,0,0,true);
                FCurrent.Y =StartMouseDown.Y;
                FAnchor.Y =FixedRows;
                Vert=true;
                InvalidateOk = true;
                ScrollParam=14;
            }
            else
            {
                if (DrawInfo.Horz.FirstGridCell != FixedCols && CellHit1.X <= FixedCols)
                {
                    ModifyScrollBar(0,0,0,true);
                    FCurrent.X =StartMouseDown.X;
                    FAnchor.X =FixedCols;
                    Horz=true;
                    InvalidateOk = true;
                    ScrollParam=13;
                }
                else
                {
                    if (Vert)
                    {
                        if (CellHit1.Y>0)
                        {
                            TRect rect =CalculationRect(CellHit1, StartMouseDown);
                            FCurrent.Y =rect.Bottom;
                            if (rect.Top <2) rect.Top=2;
                            FAnchor.Y =rect.Top;
                            PrivatEvent_1 = true;
                        }
                        else
                        {
                            FCurrent.Y =StartMouseDown.Y;
                            if (FCurrent.Y <2) FCurrent.Y=2;
                            FAnchor.Y =2;
                        }
                        Vert = false;
                    }
                    if (Horz)
                    {
                        if (CellHit1.X>0)
                        {
                            TRect rect =CalculationRect(CellHit1, StartMouseDown);
                            FCurrent.X =rect.Right;
                            if (rect.Left <2) rect.Left=2;
                            FAnchor.X =rect.Left;
                            PrivatEvent_1 = true;
                        }
                        else
                        {
                            FCurrent.X =StartMouseDown.X;
                            if (FCurrent.X <2) FCurrent.X=2;
                            FAnchor.X =2;
                        }
                        Horz = false;
                    }
                    if (!MoveCellBorder)
                        Timer->Enabled = false;
                    InvalidateOk = true;
                }
            }
        }
        if (InvalidateOk && !MoveCellBorder)
            InvalidateU2();
    }
}

void   TCellGrid::InvalidateU2()
{
    Invalidate();
}

void   TCellGrid::SelectAllCells()
{
    TShiftState ss;
    TRect rect = GetGridRectToRectPixelUnionReal(1,1);
    ss.Clear();
    ss << ssLeft;
    CellGridMouseDown(this ,mbLeft,ss,rect.Left,rect.Top);
    CellGridMouseUp(this,mbLeft,ss,rect.Left,rect.Top);
    InvalidateU2();
}

TRect  TCellGrid::GetSelectGridRect()
{ // Ïîëó÷èòü âûäåëåííûé ðåãèîí â ÿ÷åéêàõ

    TRect RectCellUnionSort =GetAnchorCurrentSort();
    bool SelectColumString =false;
    // Êîððåêòèðîâêà åñëè âûäåëåíû ïîëíîñòüþ (Ñòðîêà, Ñòîëáåö, Òàáëèöà)
    if (SelectColumn)
    {
        RectCellUnionSort.Top   =1;
        SelectColumString =true;
        RectCellUnionSort.Bottom =EndColRowCell.y;

    }
    else if (SelectString)
    {
        RectCellUnionSort.Left  =1;
        SelectColumString =true;
        RectCellUnionSort.Right =EndColRowCell.x;
    }
    else if (SelectTable)
    {
        RectCellUnionSort.Top       =1;
        RectCellUnionSort.Left      =1;
        RectCellUnionSort.Bottom    =EndColRowCell.y;
        RectCellUnionSort.Right     =EndColRowCell.x;
    }
    else
    {
        // Êîððåêòèðîâêà åñëè âûäåëåíû ïîëíîñòüþ (Ñòðîêà, Ñòîëáåö, Òàáëèöà) End

        if ((StartMouseDown.X ==1 && StartMouseDown.Y ==1))
        {
            if (StartMouseDown.Y ==1)
            {
                if (EndColRowCell.y <RectCellUnionSort.Bottom)
                    RectCellUnionSort.Bottom =EndColRowCell.y;

                if (RectCellUnionSort.Bottom <RectCellUnionSort.Top)
                    RectCellUnionSort.Bottom =RectCellUnionSort.Top;
            }
            if (StartMouseDown.X ==1)
            {
                if (EndColRowCell.x <RectCellUnionSort.Right)
                    RectCellUnionSort.Right =EndColRowCell.x;

                if (RectCellUnionSort.Right <RectCellUnionSort.Left)
                    RectCellUnionSort.Right =RectCellUnionSort.Left;
            }
        }
        if (!SelectColumString)
        {
            TRect Rect      =RectCellUnionSort;
            TRect AllCell1  =CalculationRect(RectCellUnionSort.Left,
                                            RectCellUnionSort.Top,
                                            RectCellUnionSort.Right,
                                            RectCellUnionSort.Bottom);

            RectCellUnionSort       =Rect;
            RectCellUnionSort.Left  =StartMouseDown.X;
            RectCellUnionSort.Top   =StartMouseDown.Y;

            TRect AllCell2 =CalculationRect(RectCellUnionSort.Left,
                                            RectCellUnionSort.Top,
                                            RectCellUnionSort.Right,
                                            RectCellUnionSort.Bottom);

            TRect AllCell = GetUnionRect(AllCell1, AllCell2);

            RectCellUnionSort.Top       =AllCell.Top;
            RectCellUnionSort.Bottom    =AllCell.Bottom;
            RectCellUnionSort.Left      =AllCell.Left;
            RectCellUnionSort.Right     =AllCell.Right;
        }
    }
    return RectCellUnionSort;
}

void TCellGrid::UndoRegister(int Col, int Row, TGridRegisterMode RM)
{
    if ( (!GetCellSimple(Col,Row)->UndoRegistered || RM == rmDeleted)/* && !GUID.IsEmpty() */)
        GetCellSimple(Col,Row)->UndoRegistered = UndoStack.Register(Col,Row,GetCellSimple(Col,Row),RM);
}

void  TCellGrid::GetSelectCells(bool AllUnion)
{
    TRect RectCellUnionSort = GetAnchorCurrentSort();
    if (RectCellUnionSort.Left ==1 && RectCellUnionSort.Top ==1)
        AllUnion =false;
    if (!BeEqualRect(OldCurrentAnchorSort,RectCellUnionSort) || ListFilling.Count ==0 || AllUnion)
    {
        if (ListFilling.Count >0)
            ListFilling.Clear();

        OldCurrentAnchorSort =RectCellUnionSort;
        int StartX  =RectCellUnionSort.Left;
        int StartY  =RectCellUnionSort.Top;
        int EndX    =RectCellUnionSort.Right;
        int EndY    =RectCellUnionSort.Bottom;

        if (!(StartMouseDown.X >1 && StartMouseDown.Y >1))
        {
            if (EndColRowCell.y <EndY)
                EndY =EndColRowCell.y;

            if (EndY <StartY)
                EndY =StartY;

            if (EndColRowCell.x <EndX)
                EndX =EndColRowCell.x;

            if (EndX <StartX)
                EndX =StartX;
        }
/**/
        TRect AllCell1 = CalculationRect(StartX, StartY, EndX, EndY);

        StartX  =StartMouseDown.X;
        StartY  =StartMouseDown.Y;
        EndX    =RectCellUnionSort.Right;
        EndY    =RectCellUnionSort.Bottom;

        if (!(StartMouseDown.X >1 && StartMouseDown.Y >1))
        {
            if (EndColRowCell.y <EndY)
                EndY =EndColRowCell.y;

            if (EndY <StartY)
                EndY =StartY;

            if (EndColRowCell.x <EndX)
                EndX =EndColRowCell.x;

            if (EndX <StartX)
                EndX =StartX;
        }
/**/
        TRect AllCell2 = CalculationRect(StartX, StartY, EndX, EndY);

        TRect AllCell = GetUnionRect(AllCell1, AllCell2);

        StartY  =AllCell.Top;
        EndY    =AllCell.Bottom;
        StartX  =AllCell.Left;
        EndX    =AllCell.Right;

    // --------- Êîððåêòèðîâêà åñëè âûäåëåíû ïîëíîñòüþ (Ñòðîêà, Ñòîëáåö, Òàáëèöà)
        if (SelectColumn)
            StartY=1;
        if (SelectString)
            StartX=1;
        if (SelectTable)
        {
            StartY=1;
            StartX=1;
        }
    // --------- Êîððåêòèðîâêà åñëè âûäåëåíû ïîëíîñòüþ (Ñòðîêà, Ñòîëáåö, Òàáëèöà) End

        if (StartY == 1 && StartX ==1)
        {// Ïðèìåíèòü ê Òàáëèöå

            for (int y=StartY; y<=EndY; y++)
                for (int x=StartX; x<=EndX; x++)
                    if (GetCell(x, y) != NULL)
                        ListFilling.Add(new TPoint(x,y));
        }
        else if (StartY == 1 && StartX >1)
        {// Ïðèìåíèòü ê Ñòîëáöó
            StartX  =RectCellUnionSort.Left;
            EndX    =RectCellUnionSort.Right;
            for (int y=StartY; y<=EndY; y++)
                for (int x=StartX; x<=EndX; x++)
                {
                    if (y ==1)
                        ListFilling.Add(new TPoint(x,y));
                    else
                    {
                        if (AllUnion)
                        {
                            if ((GetCell(x, y) != NULL)||(GetCell(1, y) != NULL))
                            {
                                if ((GetCell(x, y) != NULL)&&(GetCell(x, y)->UnionRect  != NULL))
                                {
                                    if (Rect1InRect2(*GetCell(x, y)->UnionRect, TRect(StartX,StartY,EndX,EndY)))
                                        ListFilling.Add(new TPoint(x,y));
                                }
                                else
                                    ListFilling.Add(new TPoint(x,y));
                            }
                        }
                        else if (GetCell(x, y) != NULL|| GetCell(1, y) != NULL)
                            ListFilling.Add(new TPoint(x,y));
                    }
                }
        }
        else if (StartY > 1 && StartX ==1)
        {// Ïðèìåíèòü ê Ñòðîêå
            StartY  =RectCellUnionSort.Top;
            EndY    =RectCellUnionSort.Bottom;

            for (int y=StartY; y<=EndY; y++)
                for (int x=StartX; x<=EndX; x++)
                {
                    if (x ==1)
                        ListFilling.Add(new TPoint(x,y));
                    else
                    {
                        if (AllUnion)
                        {
                            if ((GetCell(x, y) != NULL)||(GetCell(x, 1) != NULL))
                            {
                                if ((GetCell(x, y) != NULL)&&(GetCell(x, y)->UnionRect != NULL))
                                {
                                    if (Rect1InRect2(*GetCell(x, y)->UnionRect, TRect(StartX,StartY,EndX,EndY)))
                                        ListFilling.Add(new TPoint(x,y));
                                }
                                else
                                    ListFilling.Add(new TPoint(x,y));
                            }
                        }
                        else if (GetCell(x, y) != NULL || GetCell(x, 1) != NULL)
                                ListFilling.Add(new TPoint(x,y));
                    }
                }
        }
        else// Ê ÿ÷åéêå
            for (int y=StartY; y<=EndY; y++)
                for (int x=StartX; x<=EndX; x++)
                    ListFilling.Add(new TPoint(x,y));
    }
}
/*
void  TCellGrid::GetSelectCellsColRow()
{
    if (ListFilling.Count >0)
    {
        ListFilling.Clear();
        throw EMyException("<TCellGrid::GetSelectCellsColRow>: ListFilling íå ïóñò");
    }

    TRect RectCellUnionSort = GetAnchorCurrentSort();
    int StartX = RectCellUnionSort.Left;
    int StartY = RectCellUnionSort.Top;
    int EndX = RectCellUnionSort.Right;
    int EndY = RectCellUnionSort.Bottom;
    TRect AllCell1 = CalculationRect(StartX, StartY, EndX, EndY);

    StartX = StartMouseDown.X;
    StartY = StartMouseDown.Y;
    EndX = RectCellUnionSort.Right;
    EndY = RectCellUnionSort.Bottom;
    TRect AllCell2 = CalculationRect(StartX, StartY, EndX, EndY);

    TRect AllCell = GetUnionRect(AllCell1, AllCell2);


    StartY =AllCell.Top;
    EndY = AllCell.Bottom;
    StartX = AllCell.Left;
    EndX = AllCell.Right;

// --------- Êîððåêòèðîâêà åñëè âûäåëåíû ïîëíîñòüþ (Ñòðîêà, Ñòîëáåö, Òàáëèöà)
    if (SelectColumn) StartY=1;
    if (SelectString) StartX=1;
    if (SelectTable)
    {
        StartY=1;
        StartX=1;
    }
// --------- Êîððåêòèðîâêà åñëè âûäåëåíû ïîëíîñòüþ (Ñòðîêà, Ñòîëáåö, Òàáëèöà) End


    if ((StartY == 1)&&(StartX >1))
    {// Ïðèìåíèòü ê Ñòîëáöó
        StartX =RectCellUnionSort.Left;
        EndX =RectCellUnionSort.Right;
        ListFilling.Add(new TPoint(StartX-1, EndX+1));
        for (int y=StartY; y<=EndY; y++)
        for (int x=StartX-1; x<=EndX+1; x++)
        {
            if (y ==1)
            {
                ListFilling.Add(new TPoint(x,y));
            } else
            {
                if ((GetCell(x, y) != NULL)||(GetCell(1, y) != NULL))
                {
                    ListFilling.Add(new TPoint(x,y));
                }
            }
        }
    } else
    if ((StartY > 1)&&(StartX ==1))
    {// Ïðèìåíèòü ê Ñòðîêå
        StartY =RectCellUnionSort.Top;
        EndY =RectCellUnionSort.Bottom;
        ListFilling.Add(new TPoint(StartY-1, EndY+1));
        for (int y=StartY-1; y<=EndY+1; y++)
        for (int x=StartX; x<=EndX; x++)
        {
            if (x ==1)
            {
                ListFilling.Add(new TPoint(x,y));
            } else
            {
                if ((GetCell(x, y) != NULL)||(GetCell(x, 1) != NULL))
                {
                    ListFilling.Add(new TPoint(x,y));
                }
            }
        }
    }
}
*/

void  TCellGrid::ClearListFilling()
{// Î÷èñòêà ListFilling
    ListFilling.Clear();
}

void  TCellGrid::ClipByEndCell(TRect& rect)
{// Îáçåçàòü Rect ïî ïîñëåäíåé ñóù ÿ÷åéêå è ñêîððåêòèðîâàòü ïî ñòîëáöàì
    if (rect.Right == ColCount-1)
    {
        rect.Right  =EndColRowCell.x;
        rect.Left   =1;
    }
    if (rect.Bottom == RowCount-1)
    {
        rect.Bottom =EndColRowCell.y;
        rect.Top    =1;
    }
}

void  TCellGrid::DeleteUnionRect(TCell* Cell)
{// Óäàëèòü âñþ îáúåäåíåííóþ ÿ÷åéêó
    if (Cell !=NULL && Cell->UnionRect !=NULL)
    {
        TRect rect =*Cell->UnionRect;
        for (int y=rect.Top; y<=rect.Bottom; y++)
            for (int x=rect.Left; x<=rect.Right; x++)
                ClearCell(x,y);
        Cell =NULL;
    }
}

void  TCellGrid::DelUnionCell(TCell* Cell)
{// Óäàëèòü âñþ îáúåäåíåííóþ ÿ÷åéêó
    if (Cell !=NULL && Cell->UnionRect !=NULL)
    {
        TRect rect =*Cell->UnionRect;
        for (int y=rect.Top; y<=rect.Bottom; y++)
            for (int x=rect.Left; x<=rect.Right; x++)
            {
                delete (TRect*)GetCellSimple(x,y)->UnionRect;
                GetCellSimple(x,y)->UnionRect =NULL;
            }
    }
}

void  TCellGrid::SetUnionCell(const TRect& rect,bool Test)
{
    TGridCoord oldF =FCurrent;
    TGridCoord oldA =FAnchor;

    FCurrent.X  =rect.Left;
    FCurrent.Y  =rect.Top;
    FAnchor.X   =rect.Right;
    FAnchor.Y   =rect.Bottom;

    SetUnionCell(Test);

    FCurrent    =oldF;
    FAnchor     =oldA;
}

void  TCellGrid::SetUnionCell(bool Test)
{ // Óñòàíîâèòü îáúåäåíåííóþ ÿ÷åéêó
    TRect RectCellUnionSort;
    RectCellUnionSort   =GetAnchorCurrentSort();
    RectCellUnionSort   =CalculationRect(RectCellUnionSort);
    bool bYesUnionRect  =false;
    bool FixedOK        =true;
    int StartX          =RectCellUnionSort.Left;
    int StartY          =RectCellUnionSort.Top;
    int EndX            =RectCellUnionSort.Right;
    int EndY            =RectCellUnionSort.Bottom;


    for (int y=StartY+1; y<=EndY; y++)
        if (FixedRows == y)
            FixedOK = false;
    for (int x=StartX+1; x<=EndX; x++)
        if (FixedCols == x)
            FixedOK = false;

    bool OK=true;

    if (Test)
    {
        int x=0;
        for (int y=RectCellUnionSort.Top; y<=RectCellUnionSort.Bottom; y++)
            if (GetCell(x,y) !=NULL && GetCell(x,y)->UnionRect !=NULL)
            {
                TRect rect=*GetCell(x,y)->UnionRect;
                rect.Left=1;
                rect.Right=ColCount;
                if (!Rect1InRect2(RectCellUnionSort, rect))
                    OK=false;
            }

        int y=0;
        for (int x=RectCellUnionSort.Left; x<=RectCellUnionSort.Right; x++)
            if (GetCell(x,y) !=NULL && GetCell(x,y)->UnionRect !=NULL)
            {
                TRect rect=*GetCell(x,y)->UnionRect;
                rect.Top=1;
                rect.Bottom=RowCount;
                if (!Rect1InRect2(RectCellUnionSort, rect))
                    OK=false;
            }
        if (!OK)
        {
            ShowMessage("Íåîáõîäèìî ÷òîáû ñîçäàâàåìàÿ ÿ÷åéêà \n íàõîäèëàñü â íóòðè ñåêöèé èëè çà åå ãðàíèöåé");
            FixedOK=false;
        }
    }
    if (FixedOK)
    {
        for (int y=StartY; y<=EndY; y++)
            for (int x=StartX; x<=EndX; x++)
                if (GetCellSimple(x,y)!=NULL &&
                    GetCellSimple(x,y)->UnionRect != NULL)
                {
                    bYesUnionRect   =true;
                    delete (TRect*)GetCellSimple(x,y)->UnionRect;
                    GetCellSimple(x,y)->UnionRect =NULL;
                    if (x !=StartX || y !=StartY)
                    {
                        TCellFlag* Cellf        =GetParamCell(0,0);
                        Cellf->f_WidthLeft      =false;
                        Cellf->f_WidthTop       =false;
                        Cellf->f_WidthRight     =false;
                        Cellf->f_WidthBottom    =false;
                        AssignParamCell(Cellf,x,y);
                    }
                }

        if (!bYesUnionRect &&
            (
              StartY !=EndY ||
              StartX !=EndX
            )
        )
        {
            TCellFlag* Cellf        =GetParamCell(StartX,StartY);
            Cellf->f_SetUnion       =true;
            Cellf->f_UnionCell      =false;
            Cellf->f_WidthBottom    =false;
            Cellf->f_WidthRight     =false;
            Cellf->f_WidthLeft      =false;
            Cellf->f_WidthTop       =false;
            bool set=true;
            for (int y=StartY; y<=EndY; y++)
                for (int x=StartX; x<=EndX; x++)
                {
                    if (GetCellSimple(x,y) == NULL)
                    {
                        NewCellAndSetDefault(x,y,0);
                        set =false;
                        if (x ==StartX)
                            GetCellSimple(x,y)->Line.WidthLeft =GetLeftBorderEliminateCurrent(x,y);
                        if (y ==StartY)
                            GetCellSimple(x,y)->Line.WidthTop =GetTopBorderEliminateCurrent(x,y);
                        if (x ==EndX)
                            GetCellSimple(x,y)->Line.WidthRight =GetRightBorderEliminateCurrent(x,y);
                        if (y ==EndY)
                            GetCellSimple(x,y)->Line.WidthBottom =GetBottomBorderEliminateCurrent(x,y);
                    }


                    if (GetCellSimple(x,y)->UnionRect == NULL)
                        GetCellSimple(x,y)->UnionRect = new TRect();

                    GetCellSimple(x,y)->UnionRect->Top      =StartY;
                    GetCellSimple(x,y)->UnionRect->Left     =StartX;
                    GetCellSimple(x,y)->UnionRect->Right    =EndX;
                    GetCellSimple(x,y)->UnionRect->Bottom   =EndY;

                    Cellf->f_WidthLeft      =false;
                    Cellf->f_WidthTop       =false;
                    Cellf->f_WidthRight     =false;
                    Cellf->f_WidthBottom    =false;
                    AssignParamCell(Cellf,x,y);

                    if (x !=StartX)
                        GetCellSimple(x,y)->Line.WidthLeft      =0;
                    if (y !=StartY)
                        GetCellSimple(x,y)->Line.WidthTop       =0;
                    if (x !=EndX)
                        GetCellSimple(x,y)->Line.WidthRight     =0;
                    if (y !=EndY)
                        GetCellSimple(x,y)->Line.WidthBottom    =0;
                    if (set)
                    {
                        if (x ==StartX)
                            GetCellSimple(x,y)->Line.WidthLeft =GetLeftBorder(x,y);
                        if (y ==StartY)
                            GetCellSimple(x,y)->Line.WidthTop =GetTopBorder(x,y);
                        if (x ==EndX)
                            GetCellSimple(x,y)->Line.WidthRight =GetRightBorder(x,y);
                        if (y ==EndY)
                            GetCellSimple(x,y)->Line.WidthBottom =GetBottomBorder(x,y);
                    }
                    set =true;
                }
        }
        else
        {
            FCurrent.X  =StartX;
            FCurrent.Y  =StartY;
            FAnchor.X   =StartX;
            FAnchor.Y   =StartY;
        }
    }
    InvalidateU2();
}

bool  TCellGrid::PointInRect(int Col, int Row,const TRect& Rect)
{// Íàõîäèòüñÿ ÿ÷åéêà âíóòðè rect
    return (Col >=Rect.Left && Col <=Rect.Right && Row >=Rect.Top && Row <=Rect.Bottom);
}

TRect  TCellGrid::Zoom(const TRect& rect, int zoom)
{// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom
    TRect ret = rect;
    ZoomAndClipRectToJobRect(ret,zoom);
    return ret;
}

TGridRect  TCellGrid::ZoomGrid(const TRect& rect, int zoom)
{// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom
    return RectToGridRectType(Zoom(rect, zoom));
}

TGridRect  TCellGrid::ZoomGrid(TGridRect& rect, int zoom)
{// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom
    return ZoomGrid(GridRectToRectType(rect), zoom);
}

void  TCellGrid::ResizeRow(int Index, int OldSize, int NewSize)
{
    if (NewSize <2)
        NewSize =2;
    if (StartVisible && (StartMouseDown.X ==1 || StartMouseDown.Y ==1))
    {
        CellGridResizeRow.x =FCurrent.Y;
        CellGridResizeRow.y =FAnchor.Y;
        NewSizeColRow =NewSize;
    }
    if (StartVisible)
    {
        TMyObject* MO =GetCell(1,Index);
        if (Index>1)
        {
            if (MO ==NULL )
            {
                NewCellAndSetDefault2(1,Index,0);
                MO =GetCell(1,Index);
            }
            if (GetCellSimple(1,Index) !=NULL && MouseUP)
                GetCellSimple(1,Index)->CellFlags.TextHeightAuto =0;

            ((TCellColRow*)MO)->ColRowWidth =NewSize;
        }
    }
    MouseUP =false;
    TMyCustomGrid::ResizeRow(Index, OldSize, NewSize);
}

void  TCellGrid::ResizeCol(int Index, int OldSize, int NewSize)
{
    if (NewSize <2)
        NewSize =2;
    if (StartVisible && (StartMouseDown.X ==1 || StartMouseDown.Y ==1))
    {
        CellGridResizeCol.x =FCurrent.X;
        CellGridResizeCol.y =FAnchor.X;
        NewSizeColRow =NewSize;
    }
    if (StartVisible)
    {
        TMyObject* MO =GetCell(Index,1);
        if (Index>1)
        {
            if (MO ==NULL )
            {
                NewCellAndSetDefault2(Index,1,0);
                MO =GetCell(Index,1);
            }
            ((TCellColRow*)MO)->ColRowWidth =NewSize;
        }

    }
    TMyCustomGrid::ResizeCol(Index, OldSize, NewSize);
}

void  TCellGrid::ZoomAndClipRectToJobRect(TRect& rect,int zoom)
{// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom è Îãðàíè÷åíèå ðåêòà ïî ðàáî÷åé çîíå
    rect.Left -= zoom;
    rect.Top -= zoom;
    rect.Right += zoom;
    rect.Bottom += zoom;
    ClipRectToJobRect(rect);
}

void  TCellGrid::ZoomAndClipRectToJobRect(TGridRect& rect,int zoom)
{// Èçìåíèòü ðàçìåð rect íà âåëè÷åíó zoom è Îãðàíè÷åíèå ðåêòà ïî ðàáî÷åé çîíå
    rect.Left -= zoom;
    rect.Top -= zoom;
    rect.Right += zoom;
    rect.Bottom += zoom;

    ClipRectToJobRect(rect);
}

void  TCellGrid::ClipRectToJobRect(TRect& rect)
{// Îãðàíè÷åíèå ðåêòà ïî ðàáî÷åé çîíå
    if (rect.Left <2) rect.Left=2;
    if (rect.Top <2) rect.Top=2;
    if (rect.Right >ColCount-1) rect.Right=ColCount-1;
    if (rect.Bottom >RowCount-1) rect.Bottom=RowCount-1;
}

void  TCellGrid::ClipRectToJobRect(TGridRect& rect)
{// Îãðàíè÷åíèå ðåêòà ïî ðàáî÷åé çîíå
    if (rect.Left <2) rect.Left=2;
    if (rect.Top <2) rect.Top=2;
    if (rect.Right >ColCount-1) rect.Right=ColCount-1;
    if (rect.Bottom >RowCount-1) rect.Bottom=RowCount-1;
}

TCell*  TCellGrid::GetCellParam(int Col, int Row)
{ // Ïîëó÷èòü ïàðàìåòðû ÿ÷åéêè
    TCell* Cell;
    if (GetCell(Col,Row) !=NULL)
        Cell=GetCell(Col,Row);
    else if (GetCell(1,Row) !=NULL)
        Cell=GetCell(1,Row);
    else if (GetCell(Col,1) !=NULL)
        Cell=GetCell(Col,1);
    else
        Cell=GetCell(1,1);
    return Cell;
}

TCell*  TCellGrid::GetCellParamSimple(int Col, int Row)
{ // Ïîëó÷èòü ïàðàìåòðû ÿ÷åéêè
    TCell* Cell;
    if (GetCellSimple(Col,Row) !=NULL)
        Cell=GetCellSimple(Col,Row);
    else if (GetCellSimple(1,Row) !=NULL)
        Cell=GetCellSimple(1,Row);
    else if (GetCellSimple(Col,1) !=NULL)
        Cell=GetCellSimple(Col,1);
    else
        Cell=GetCellSimple(1,1);
    return Cell;
}

int  TCellGrid::CalcColumnWidthAutoText(int Col, int Row)
{// Ðàñ÷åò Max øèðèíû ñòîëáöà ïî òåêñòó
    int imaxwidth =GetColWidths(Col);
    AnsiString str;
    TRect rectcalc =TRect(0,0, imaxwidth,500);
    TCell* Cell;
    for (int i=2; i<=EndColRowCell.y; i++)
    {
        Cell =GetCellSimple(Col,i);
        if (Cell !=NULL)
        {
            str =Cell->Text;
            Canvas->Font->Name =Cell->FontName;
            Canvas->Font->Size =Cell->CellFlags.FontSize;
            ::DrawText(Canvas->Handle, str.c_str(), str.Length(), &rectcalc, DT_SINGLELINE |DT_CALCRECT);
            if (imaxwidth <rectcalc.Right -rectcalc.Left)
                imaxwidth =rectcalc.Right -rectcalc.Left;

        }
    }
    return imaxwidth;
}

int  TCellGrid::CalcStringHeightAutoText(int Col, int Row)
{// Ðàñ÷åò Max âûñîòû ñòðîêè ïî òåêñòó
    int imaxwidth =GetRowHeights(Row);
    AnsiString str;
    TRect rectcalc;
    TCell* Cell;
    for (int i=2; i<=EndColRowCell.x; i++)
    {
        Cell =GetCellSimple(i,Row);
        if (Cell !=NULL && Cell->CellFlags.TextWordBreak ==1)
        {
            str =Cell->Text;
            rectcalc =TRect(0,0, GetColWidths(i),imaxwidth);
            GetRectDrawText(i,Row,str,rectcalc);
            if (imaxwidth <rectcalc.Bottom -rectcalc.Top)
                imaxwidth =rectcalc.Bottom -rectcalc.Top;
        }
    }
    return imaxwidth;
}

void  TCellGrid::CellGridMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    // Íàæàòèå êíîïêè ìûøè (Îáðàáîòêà ëåâîé êíîïêè íàæàòèå îäèí ðàç)
    if (Shift.Contains(ssRight))
    {
    }
    else
    {
        if (X >= DrawInfo.Horz.GridBoundary)
            X=DrawInfo.Horz.GridBoundary-1;
        if (Y >= DrawInfo.Vert.GridBoundary)
            Y=DrawInfo.Vert.GridBoundary-1;

        TGridCoord CellHit1 = MouseCoord(X,Y);
        iMouseDown=1;

        VertFixedLast   =true;
        HorzFixedLast   =true;
        VertFixed       =true;
        HorzFixed       =true;


        int iDeltaBorder =4;
        // - Íà ãðàíèöå ÿ÷ååê
        TRect sortdownup =GetRectCellSort(TRect(StartMouseDown.X,StartMouseDown.Y,MouseUpCoord.X ,MouseUpCoord.Y));
        TRect rectborder =GetUnionRect(
            GetGridRectToRectPixelNotUnionAndScroll(sortdownup.Left,sortdownup.Top),
            GetGridRectToRectPixelNotUnionAndScroll(sortdownup.Right,sortdownup.Bottom));
        if (Screen->Cursor ==crSizeAll && !PointInRect(X,Y,
            TRect(rectborder.Left+iDeltaBorder,rectborder.Top+iDeltaBorder,
                  rectborder.Right -iDeltaBorder,rectborder.Bottom -iDeltaBorder
            )) &&
            (
              (
                X <rectborder.Left+iDeltaBorder &&
                Y >rectborder.Top &&
                Y <rectborder.Bottom
              ) ||
              (
                X >rectborder.Right -iDeltaBorder &&
                Y >rectborder.Top &&
                Y <rectborder.Bottom
              ) ||
              (
                Y <rectborder.Top+iDeltaBorder &&
                X >rectborder.Left &&
                X <rectborder.Right
              ) ||
              (
                Y >rectborder.Bottom -iDeltaBorder &&
                X >rectborder.Left &&
                X <rectborder.Right
              )
            )
        )
        {
            SetRectCellSort(TRect(StartMouseDown.X,StartMouseDown.Y,MouseUpCoord.X ,MouseUpCoord.Y));

            MoveCellBorder              =true;
            OldFAnchorBorder            =FAnchor;

            TRect calcrect              =CalculationRect(StartMouseDown,MouseUpCoord);
            StartMouseDown.X            =calcrect.Left;
            StartMouseDown.Y            =calcrect.Top;
            MouseUpCoord.X              =calcrect.Right;
            MouseUpCoord.Y              =calcrect.Bottom;
            if (MouseUpCoord.X ==1) // Ñòîëáåö
                MouseUpCoord.X =ColCount-1;
            if (MouseUpCoord.Y ==1) // Ñòðîêà
                MouseUpCoord.Y =RowCount-1;

            FCurrent.X                  =StartMouseDown.X;
            FCurrent.Y                  =StartMouseDown.Y;
            FAnchor.X                   =MouseUpCoord.X;
            FAnchor.Y                   =MouseUpCoord.Y;

            CurrentMouseCoordTimer.X    =0;
            CurrentMouseCoordTimer.Y    =0;
            TRect Rect =
                GetUnionRect(
                GetGridRectToRectPixelNotUnionAndScroll(
                StartMouseDown.X, StartMouseDown.Y),
                GetGridRectToRectPixelNotUnionAndScroll(
                MouseUpCoord.X, MouseUpCoord.Y)
                );
            DrawCursor(Rect);
            DrawCursor(Rect);
            DrawCursorMove2(CellHit1.X,CellHit1.Y);
            Screen->Cursor =crDefault;
        }
        else
        {
            Screen->Cursor          =crDefault;
            StartMouseDown          =CellHit1;
            MousePosCellMove        =CellHit1;
            MousePosCellMoveSelect  =CellHit1;

            if (Shift.Contains(ssDouble) && CellHit1.X >1 && CellHit1.Y>1)
                ShowEditText(CellHit1.X, CellHit1.Y, false);
            else
            {
                if (CellHit1.X >1 && CellHit1.Y>1)
                {// Ïðè íàõîæäåíèè êóðñîðà â îáëàñòè ôèêñèðîâàííûõ ÿ÷ååê

                    if ( CellHit1.Y <FixedRows || CellHit1.X <FixedCols )
                    {
                        FCurrent =CellHit1;
                        FAnchor =FCurrent;
                    }

//                    OldRectCurrentAnchorMouseDown = GetAnchorCurrentSort();
                    if (GetCell(CellHit1.X, CellHit1.Y) && GetCell(CellHit1.X,CellHit1.Y)->UnionRect != NULL)
                    {
                        CurrentRectMouseDown = *GetCell(CellHit1.X,CellHit1.Y)->UnionRect;
                        OldRectDown = *GetCell(CellHit1.X,CellHit1.Y)->UnionRect;
                        OldRectMouseDown =CurrentRectMouseDown;
                    }
                    else
                    {
                        OldRectMouseDown = GetAnchorCurrentSort();
                        CurrentRectMouseDown.Left = -1;
                    }

                    if (!(OldRectMouseDown2 == OldRectMouseDown &&
                        OldRectMouseDown2.Right == CurrentAnchorMouseUp.Right &&
                        OldRectMouseDown2.Bottom == CurrentAnchorMouseUp.Bottom)
                    )
                    {

                        TGridRect GridRect;

                        GridRect.Left = OldRectMouseDown.Left-2;
                        GridRect.Top = OldRectMouseDown.Top-2;

                        GridRect.Right = OldRectMouseDown.Right+2;
                        GridRect.Bottom = OldRectMouseDown.Bottom +2;
                        ClipRectToJobRect(GridRect);

                        TGridRect oldrec = ZoomGrid(CalculationRect(PointMouseDownOld,MouseUpCoord),2);

                        InvalidateRect(oldrec);
                        InvalidateRect(GridRect);

                        OldRectMouseDown2 =OldRectMouseDown;
                    }
                    if (PointMouseDownOld.X <2 || PointMouseDownOld.Y <2 || PrivatEvent_2)
                        InvalidateU2();
                }
            }
            PrivatEvent_2 =false;
            PointMouseDownOld = CellHit1;
            if (SelectTable || SelectColumn || SelectString)
                InvalidateU2();
            SelectTable=false;
            SelectColumn=false;
            SelectString=false;

            if (CellHit1.Y == 1 && CellHit1.X == 1)
            {
                FCurrent.X = 1;
                FCurrent.Y = 1;

                FAnchor.X = ColCount-1;
                FAnchor.Y = RowCount-1;
                SelectTable=true;
                InvalidateU2();
            }
            else if (CellHit1.Y == 1)
            {
                FCurrent.X = CellHit1.X;
                FCurrent.Y = 1;
                FAnchor.X = CellHit1.X;
                FAnchor.Y = RowCount-1;
                SelectColumn=true;
                InvalidateU2();
            }
            else if (CellHit1.X == 1)
            {
                FCurrent.X = 1;
                FCurrent.Y = CellHit1.Y;
                FAnchor.X = ColCount-1;
                FAnchor.Y = CellHit1.Y;;
                SelectString=true;
                InvalidateU2();
            }

            CellHit1 = MouseCoord(X,Y);
            if (CellHit1.X == 0 || CellHit1.Y == 0)
            {
                if (GetCell(CellHit1.X, CellHit1.Y) &&
                    GetCell(CellHit1.X,CellHit1.Y)->UnionRect != NULL)
                {
                    TRect CurAnc;
                    CurAnc = *GetCell(CellHit1.X,CellHit1.Y)->UnionRect;
                    if (CurAnc.Left ==0)
                    {// Ñòðîêè
                        FCurrent.X = 2;
                        FCurrent.Y = CurAnc.Top;
                        FAnchor.X = ColCount;
                        FAnchor.Y = CurAnc.Bottom;
                    }
                    if (CurAnc.Top ==0)
                    {// Ñòîëáöû
                        FCurrent.X = CurAnc.Left;
                        FCurrent.Y = 2;
                        FAnchor.X = CurAnc.Right;
                        FAnchor.Y = RowCount;
                    }
                }
                InvalidateU2();
            }
            if (Shift.Contains(ssCtrl))
                Test_CellInfo(CellHit1);
        }
    }
    CellGridResizeCol.x =0;
    CellGridResizeCol.y =0;
    CellGridResizeRow.x =0;
    CellGridResizeRow.y =0;
    PopupMenuNotMouseUp =false;
}

void  TCellGrid::CellGridMouseUp(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y)
{
    // Êíîïêà ìûøè îòæàòà (îáðàáîòêà ëåâîé)
    if (!PopupMenuNotMouseUp)
    {
        if (X >= DrawInfo.Horz.GridBoundary)
            X=DrawInfo.Horz.GridBoundary-1;
        if (Y >= DrawInfo.Vert.GridBoundary)
            Y=DrawInfo.Vert.GridBoundary-1;

        TGridCoord CellHit1 =MouseCoord(X,Y);
        Timer->Enabled      =false;
        Timer->Interval     =100;

        if (MoveCellBorder)
        {
            SetRectCellSort(TRect(StartMouseDown.X,StartMouseDown.Y,MouseUpCoord.X ,MouseUpCoord.Y));
            if (CellHit1.X <2)
                CellHit1.X =2;
            if (CellHit1.Y <2)
                CellHit1.Y =2;

            int iXS =StartMouseDown.X +CurrentMouseCoordTimer.X -OldFAnchorBorder.X;
            int iYS =StartMouseDown.Y +CurrentMouseCoordTimer.Y -OldFAnchorBorder.Y;
            int iXE =iXS +MouseUpCoord.X -StartMouseDown.X;
            int iYE =iYS +MouseUpCoord.Y -StartMouseDown.Y;

            if (StartMouseDown.Y ==1)
            {
                iYS =1;
                iYE =RowCount-1;
            }
            if (StartMouseDown.X ==1)
            {
                iXS =1;
                iXE =ColCount-1;
            }

            FCurrent.X =iXS;
            FCurrent.Y =iYS;
            FAnchor.X  =iXE;
            FAnchor.Y  =iYE;

            CopyInBuff(TRect(StartMouseDown.X,StartMouseDown.Y, MouseUpCoord.X, MouseUpCoord.Y));

            if (!Shift.Contains(ssCtrl))
                DelAndSetDefaultCell(TRect(StartMouseDown.X,StartMouseDown.Y, MouseUpCoord.X, MouseUpCoord.Y));

            StartMouseDown =FCurrent;
            if (iXS <1)
                iXS =1;
            if (iYS <1)
                iYS =1;

            Matrix->CopyCell =true;
            PasteBuffInGrid(iXS,iYS);

            MouseUpCoord.X          =FAnchor.X;
            MouseUpCoord.Y          =FAnchor.Y;
            MousePosCellMoveSelect  =MouseUpCoord;
            Invalidate();
        }
        else
            MouseUpCoord  =CellHit1;

        MoveCellBorder  =false;
        if (!(VertFixedLast || HorzFixedLast))
        {
            VertFixed =true;
            HorzFixed =true;
        }
        VertFixedLast =false;
        HorzFixedLast =false;

        TRect rectAC =GetAnchorCurrentSort();
        CurrentAnchorMouseUp =RectToGridRectType(rectAC);

        iMouseDown          =0;
        OldRectDown.Left    =-1;
        OldRectDown.Top     =-1;
        OldRectDown.Right   =-1;
        OldRectDown.Bottom  =-1;

        if (CellGridResizeRow.x !=0 || CellGridResizeCol.x !=0)
            bResizeColRow =true;

        if (CellGridResizeRow.x !=0
            && (
                    (StartMouseDown.X ==1 && StartMouseDown.Y !=1)
                ||
                    (StartMouseDown.X ==1 && StartMouseDown.Y ==1 && MouseUpCoord.Y !=1)
                )
        )
        {
            if (CellGridResizeRow.x ==1)
            {
                DefaultRowHeight = NewSizeColRow;
                TMyObject* MO =GetCell(1,1);
                ((TCellTab*)MO)->RowHeight =DefaultRowHeight;

                for ( int i=2; i<=EndColRowCell.y; i++)
                {
                    TMyObject* MO2 =GetCell(1,i);
                    if (MO2 !=NULL)
                        ((TCellColRow*)MO2)->ColRowWidth =DefaultRowHeight;
                }

                VisibleOfficialMargin =true;
            }
            else if (PointInCut(CellGridResizeCol,MouseUpCoord.Y))
                for (int i=CellGridResizeRow.x; i<=CellGridResizeRow.y; i++)
                    SetRowHeights(i,NewSizeColRow);
        }
        if (CellGridResizeCol.x !=0
            &&  (
                    (StartMouseDown.X !=1 && StartMouseDown.Y ==1)
                ||
                    (StartMouseDown.X ==1 && StartMouseDown.Y ==1  && MouseUpCoord.X !=1)
                )
            )
        {
            if (CellGridResizeCol.x == 1)
            {
                DefaultColWidth = NewSizeColRow;
                TMyObject* MO =GetCell(1,1);
                ((TCellTab*)MO)->ColWidth =DefaultColWidth;

                for ( int i=2; i<=EndColRowCell.x; i++)
                {
                    TMyObject* MO2 =GetCell(i,1);
                    if (MO2 !=NULL)
                        ((TCellColRow*)MO2)->ColRowWidth =DefaultColWidth;
                }
                VisibleOfficialMargin =true;
            }
            else if (PointInCut(CellGridResizeCol,MouseUpCoord.X))
                for (int i=CellGridResizeCol.x; i<=CellGridResizeCol.y; i++)
                    SetColWidths(i,NewSizeColRow);

        }
        CellGridResizeCol.x =0;
        CellGridResizeCol.y =0;

        CellGridResizeRow.x =0;
        CellGridResizeRow.y =0;
        MouseUP =false;
        PrivatEvent_2 =false;
        if (Shift.Contains(ssCtrl))
            PrivatEvent_2 =true;
    }
}

bool  TCellGrid::PointInCut(const TPoint& cut, int point)
{ // òî÷êà íàõîäèòüñÿ â ïðîìåæóòêå cut
    return (point >=cut.x && point <=cut.y);
}

bool   TCellGrid::TestingRectToSelection(TCell* Cell, const TRect RectSelection)
{// Íàõîäèòüñÿ ëè îáúåäåíåííàÿ ÿ÷åéêà  â çàäàííîì Recte
    bool ret =true;
    if (Cell->UnionRect !=NULL)
    {
        ret =Rect1InRect2(*Cell->UnionRect, RectSelection);
    }
    return ret;
}

TRect  TCellGrid::GetAnchorCurrentSort()
{
    // Ïîëó÷èòü â Rect Current è Fnchor â îòñîðòèðîâàííîì âèäå
    TRect rectCell;
    rectCell.Left = FCurrent.X;
    rectCell.Top = FCurrent.Y;
    rectCell.Right = FAnchor.X;
    rectCell.Bottom = FAnchor.Y;

    if (FAnchor.X < FCurrent.X)
    {
        rectCell.Left =FAnchor.X;;
        rectCell.Right =FCurrent.X;;
    }
    if (FAnchor.Y < FCurrent.Y)
    {
        rectCell.Top =FAnchor.Y;
        rectCell.Bottom =FCurrent.Y;
    }
    return rectCell;
}

void  TCellGrid::SetAnchorCurrentSort()
{// îòñîðòèðîâàòü FCurrent è FAnchor
    int t;
    if (FAnchor.X < FCurrent.X)
    {
        t =FCurrent.X;
        FCurrent.X =FAnchor.X;
        FAnchor.X =t;
    }
    if (FAnchor.Y < FCurrent.Y)
    {
        t =FCurrent.Y;
        FCurrent.Y =FAnchor.Y;
        FAnchor.Y =t;
    }
}

TGridRect  TCellGrid::GetAnchorCurrentSortGrid()
{// îòñîðòèðîâàòü FCurrent è FAnchor
    return RectToGridRectType(GetAnchorCurrentSort());
}

TRect  TCellGrid::GetAnchorCurrentSortPlus()
{
    // îòñîðòèðîâàòü FCurrent è FAnchor è zoom íà +1 ÿ÷åéêó
    TRect ret;
    ret = GetAnchorCurrentSort();

    if (GetCell(ret.Left, ret.Top) !=NULL && GetCell(ret.Left, ret.Top)->UnionRect !=NULL)
    {
        ret =*GetCell(ret.Left, ret.Top)->UnionRect;
    }

    if (ret.Left >2) ret.Left -=1;
    if (ret.Top >2) ret.Top -=1;
    if (ret.Bottom <RowCount-1) ret.Bottom +=1;
    if (ret.Right <ColCount-1) ret.Right +=1;
    return ret;
}

TRect  TCellGrid::GetJobAnchorCurrentSort()
{

    TRect rectCell;
    rectCell.Left = JobFCurrent.X;
    rectCell.Top = JobFCurrent.Y;
    rectCell.Right = JobFAnchor.X;
    rectCell.Bottom = JobFAnchor.Y;

    if (JobFAnchor.X < JobFCurrent.X)
    {
        rectCell.Left =JobFAnchor.X;;
        rectCell.Right =JobFCurrent.X;;
    }
    if (JobFAnchor.Y < JobFCurrent.Y)
    {
        rectCell.Top =JobFAnchor.Y;
        rectCell.Bottom =JobFCurrent.Y;
    }
    return rectCell;
}

TColor  TCellGrid::SetColorCursor(TColor& Color)// Óñòàíîâèòü öâåò êóðñîðà
{
    return (TColor)RGB((GetRValue(ColorSelect)+GetRValue(Color))/2,(GetGValue(ColorSelect)+GetGValue(Color))/2,(GetBValue(ColorSelect)+GetBValue(Color))/2);
}

TRect  TCellGrid::GetUnionRect(const TRect& rect1,const TRect& rect2)
{

    // Òîæå ÷òî è UnionRect òîëüêî êîððåêòíî    è â ñëó÷àÿõ òèïà (x=1,y=1,x2=1,y2=5)
    TRect rectCellUnion;
    TRect rectsort1;
    TRect rectsort2;

    TRect rectsorttemp1;
    TRect rectsorttemp2;

    TRect rectsorttemp11;
    TRect rectsorttemp22;

    rectsort1 = GetRectCellSort(rect1);
    rectsort2 = GetRectCellSort(rect2);

    rectsorttemp1.Left = rectsort1.Left;
    rectsorttemp1.Top = rectsort1.Top;
    rectsorttemp1.Right = rectsort2.Left;
    rectsorttemp1.Bottom = rectsort2.Top;
    rectsorttemp11 = GetRectCellSort(rectsorttemp1);

    rectsorttemp2.Left = rectsort1.Right;
    rectsorttemp2.Top = rectsort1.Bottom;
    rectsorttemp2.Right = rectsort2.Right;
    rectsorttemp2.Bottom = rectsort2.Bottom;
    rectsorttemp22 = GetRectCellSort(rectsorttemp2);

    rectCellUnion.Left = rectsorttemp11.Left;
    rectCellUnion.Top = rectsorttemp11.Top;
    rectCellUnion.Right = rectsorttemp22.Right;
    rectCellUnion.Bottom = rectsorttemp22.Bottom;

    return rectCellUnion;
}

TRect  TCellGrid::GetUnionRect(const TGridRect& rect1,const TGridRect& rect2)
{
    return GetUnionRect(GridRectToRectType(rect1), GridRectToRectType(rect2));
}

TGridRect  TCellGrid::GetUnionGridRect(const TGridRect& rect1,const TGridRect& rect2)
{
    return RectToGridRectType(GetUnionRect(rect1, rect2));
}

TRect  TCellGrid::GridRectToRectType(const TGridRect& rect)
{
    TRect rec;
    rec.Left = rect.Left;
    rec.Top = rect.Top;
    rec.Right = rect.Right;
    rec.Bottom = rect.Bottom;
    return rec;
}

TRect  TCellGrid::GetRectCellSort(const TRect& rect)
{
    TRect rectCell =rect;
    if (rect.Right < rect.Left)
    {
        rectCell.Right =rect.Left;
        rectCell.Left =rect.Right;
    }
    if (rect.Bottom < rect.Top)
    {
        rectCell.Top =rect.Bottom;
        rectCell.Bottom =rect.Top;
    }
    return rectCell;
}

void  TCellGrid::SetRectCellSort(TRect& rect)
{
    int t;
    if (rect.Right < rect.Left)
    {
        t           =rect.Right;
        rect.Right  =rect.Left;
        rect.Left   =t;
    }
    if (rect.Bottom < rect.Top)
    {
        t           =rect.Bottom;
        rect.Bottom =rect.Top;
        rect.Top    =t;
    }
}

TRect  TCellGrid::GetRectCellSort(const TGridRect& rect)
{

    TRect rectCell;
    rectCell.Left = rect.Left;
    rectCell.Top = rect.Top;
    rectCell.Right = rect.Right;
    rectCell.Bottom = rect.Bottom;

    if (rect.Right < rect.Left)
    {
        rectCell.Right =rect.Left;
        rectCell.Left =rect.Right;
    }
    if (rect.Bottom < rect.Top)
    {
        rectCell.Top =rect.Bottom;
        rectCell.Bottom =rect.Top;
    }
    return rectCell;
}

TGridRect  TCellGrid::GetGridRectCellSort(const TGridRect& rect)
{
    TGridRect rectGirdCell =rect;
    if (rect.Right < rect.Left)
    {
        rectGirdCell.Right =rect.Left;
        rectGirdCell.Left =rect.Right;
    }
    if (rect.Bottom < rect.Top)
    {
        rectGirdCell.Top =rect.Bottom;
        rectGirdCell.Bottom =rect.Top;
    }
    return rectGirdCell;
}
/*
TGridRect  TCellGrid::RectToGridRectType(TRect* rect)
{

    TGridRect ret;
    ret.Left = rect->Left;
    ret.Top = rect->Top;
    ret.Right = rect->Right;
    ret.Bottom = rect->Bottom;
    return ret;
}
*/
TGridRect  TCellGrid::RectToGridRectType(const TRect& rect)
{
    TGridRect ret;
    ret.Left = rect.Left;
    ret.Top = rect.Top;
    ret.Right = rect.Right;
    ret.Bottom = rect.Bottom;
    return ret;
}


TRect  TCellGrid::CalculationRect(const TRect& rect)
{// Ïîëó÷èòü ðåêò ïî êîîðäèíàòàì
    return CalculationRect(rect.Left, rect.Top,rect.Right,rect.Bottom);
}

TRect  TCellGrid::CalculationRect(int StartX, int StartY, int EndX, int EndY)
{
    TGridCoord start,end;
    start.X =StartX;
    start.Y =StartY;

    end.X =EndX;
    end.Y =EndY;
    return CalculationRect(start,end);
}

TRect& TCellGrid::GetValidSelection()
{
    RecalculateSelection();
    return FValidSelection;
}

TRect& TCellGrid::GetValidSelectionPlus()
{
    RecalculateSelection();
    return FValidSelectionPlus;
}

TRect& TCellGrid::GetValidSelectionMinus()
{
    RecalculateSelection();
    return FValidSelectionMinus;
}

void TCellGrid::RecalculateSelection()
{
    if (    FCurrent_Mem.X != FCurrent.X ||
            FCurrent_Mem.Y != FCurrent.Y ||
            FAnchor_Mem.X != FAnchor.X  ||
            FAnchor_Mem.Y != FAnchor.Y ||
            bResizeColRow
        )
    {
        bResizeColRow =false;
        FValidCurAnchor = GetAnchorCurrentSortGrid();
        if (StartMouseDown.X ==1 || StartMouseDown.Y ==1)
        {
/*
            if (FValidCurAnchor.Left < DrawInfo.Horz.FirstGridCell)
                FValidCurAnchor.Left = DrawInfo.Horz.FirstGridCell;

            if (FValidCurAnchor.Top < DrawInfo.Vert.FirstGridCell)
                FValidCurAnchor.Top = DrawInfo.Vert.FirstGridCell;
*/
            if (FValidCurAnchor.Left < 2)
                FValidCurAnchor.Left = 2;

            if (FValidCurAnchor.Top < 2)
                FValidCurAnchor.Top = 2;

            if (FValidCurAnchor.Right > DrawInfo.Horz.LastFullVisibleCell)
                FValidCurAnchor.Right = DrawInfo.Horz.LastFullVisibleCell+1;

            if (FValidCurAnchor.Bottom > DrawInfo.Vert.LastFullVisibleCell)
                FValidCurAnchor.Bottom = DrawInfo.Vert.LastFullVisibleCell+1;

            FValidSelection = GridRectToRectType(FValidCurAnchor);
        }
        else
        {
            FValidSelection = CalculationRect( FValidCurAnchor.TopLeft,FValidCurAnchor.BottomRight );
        }
        FValidSelectionPlus = Zoom(FValidSelection,1 );
        FValidSelectionMinus = Zoom(FValidSelection,-1 );
        //çàïîìèíàåì
        FCurrent_Mem.X =FCurrent.X;
        FCurrent_Mem.Y =FCurrent.Y;
        FAnchor_Mem.X =FAnchor.X;
        FAnchor_Mem.Y =FAnchor.Y;
    }
}

TRect  TCellGrid::CalculationRect(TGridCoord mousestart, TGridCoord mousemove)
{
    TRect ForUnionRect1;

    if (mousestart.X ==1 && mousestart.Y ==1)
    {
        ForUnionRect1.Left      =1;
        ForUnionRect1.Top       =1;
        ForUnionRect1.Right     =ColCount-1;
        ForUnionRect1.Bottom    =RowCount-1;
    }
    else
    {
        TRect ForUnionRect2;
        TRect RectAnchorCurrent;
        TRect PosMouseToRect;
        TRect oldForUnionRect1;
        TRect TempRect;

        NullRect(oldForUnionRect1);

        if (mousemove.X <0)
            mousemove.X = 0;
        if (mousemove.Y <0)
            mousemove.Y = 0;

        if (mousestart.Y ==0)
            mousemove.Y = 0;
        if (mousestart.X ==0)
            mousemove.X = 0;

        RectAnchorCurrent.Left      =mousestart.X;
        RectAnchorCurrent.Top       =mousestart.Y;
        RectAnchorCurrent.Right     =mousestart.X;
        RectAnchorCurrent.Bottom    =mousestart.Y;

        PosMouseToRect.Left     =mousemove.X;
        PosMouseToRect.Top      =mousemove.Y;
        PosMouseToRect.Right    =mousemove.X;
        PosMouseToRect.Bottom   =mousemove.Y;

        ForUnionRect1 = GetUnionRect(RectAnchorCurrent,PosMouseToRect); // Ïåðâîíà÷àëüíûé Rect îò Anchor & Current & MousePos
        ForUnionRect2 = ForUnionRect1;
        TempRect = ForUnionRect1;
        for (int i=0; i<15; i++)
        {
            for (int y=ForUnionRect1.Top; y<=ForUnionRect1.Bottom; y++)
            for (int x=ForUnionRect1.Left; x<=ForUnionRect1.Right; x++)
            {
                if (GetCell(x,y) && GetCell(x,y)->UnionRect !=NULL)
                {
                    ForUnionRect2   =GetUnionRect(TempRect,*GetCell(x,y)->UnionRect);
                    TempRect        =GetUnionRect(ForUnionRect1,ForUnionRect2);
                }
            }
            TempRect        =GetUnionRect(ForUnionRect1,ForUnionRect2);
            ForUnionRect1   =TempRect;
            if (BeEqualRect(ForUnionRect1,oldForUnionRect1))
                i=16;

            oldForUnionRect1 =ForUnionRect1;
        }
    }
    return ForUnionRect1;
}

void  TCellGrid::WndProc(Messages::TMessage &Message)
{
    switch ( Message.Msg )
    {
        case WM_CHAR:
        {
            if (EditText->IsPrintSymbol(char(Message.WParam)))
            {
                TempStringCell =char(Message.WParam);
                ShowEditText(FCurrent.X, FCurrent.Y, true);
                TempStringCell="";
            }
        } break;
        case WM_LBUTTONDBLCLK:
        {
            TPoint point,pointclient;
            GetCursorPos(&point);
            pointclient =ScreenToClient(point);

            TGridCoord CellHit1 = MouseCoord(pointclient.x-4,pointclient.y-4);
            if (CellHit1.X >1 && CellHit1.Y ==1)
            {
                if (PointInRect(CellHit1.X,CellHit1.Y,TRect(FCurrent.X,1,FAnchor.X,FAnchor.Y)))
                    for (int i=FCurrent.X; i<=FAnchor.X; i++)
                        SetColWidths(i, CalcColumnWidthAutoText(i,CellHit1.Y));
                else
                    SetColWidths(CellHit1.X, CalcColumnWidthAutoText(CellHit1.X,CellHit1.Y));
            }

            if (CellHit1.X ==1 && CellHit1.Y >1)
            {
                if (PointInRect(CellHit1.X,CellHit1.Y,TRect(1,FCurrent.Y,FAnchor.X,FAnchor.Y)))
                    for (int i=FCurrent.Y; i<=FAnchor.Y; i++)
                        SetRowHeights(i, CalcStringHeightAutoText(CellHit1.X,i));
                else
                    SetRowHeights(CellHit1.Y, CalcStringHeightAutoText(CellHit1.X,CellHit1.Y));

            }

            TMyDrawGrid::WndProc(Message);
        } break;
        case WM_LBUTTONUP:
        {
            MouseUP =true;
            TMyDrawGrid::WndProc(Message);
        } break;
        case WM_KEYDOWN:
        { //
            if ( Message.WParam == VK_CONTROL)
            {
                if (MoveCellBorder)
                    Screen->Cursor =crDrag;
                TMyDrawGrid::WndProc(Message);
            }
            else if ( Message.WParam == VK_F2)
                ShowEditText(FCurrent.X, FCurrent.Y, false);
            else if ( Message.WParam == VK_DELETE)
                MClipBoard.DelTextToCellGrid(this);
            else
                TMyDrawGrid::WndProc(Message);
        }break;
        default:
            TMyDrawGrid::WndProc(Message);

    }
}

void  TCellGrid::KeyDown(Word &Key, Classes::TShiftState Shift)
{

    TShiftState Emptily;
    TPoint MousePos;
    Emptily.Clear();
    EditText->Visible =false;    
    if (Key == VK_RETURN)
    {
        ShowEditText(FCurrent.X, FCurrent.Y, true);
    } else
    if (Shift.Contains(ssShift))
    {
        switch (Key)
        {
            case VK_UP:
            {
                DoMouseWheelUp(Emptily,MousePos);
                break;
            }
            case VK_DOWN:{
                DoMouseWheelDown(Emptily,MousePos);
                break;
            }
            case VK_LEFT:{
                DoMouseWheelLeft(Emptily,MousePos);
                break;
            }
            case VK_RIGHT:{
                DoMouseWheelRight(Emptily,MousePos);
                break;
            }
        }
    }
    if (Shift == Emptily)
    {
        switch (Key)
        {
            case VK_UP:
            {
                DoMouseWheelUp(Emptily,MousePos);
                break;
            }
            case VK_DOWN:{
                DoMouseWheelDown(Emptily,MousePos);
                break;
            }
            case VK_LEFT:{
                DoMouseWheelLeft(Emptily,MousePos);
                break;
            }
            case VK_RIGHT:{
                DoMouseWheelRight(Emptily,MousePos);
                break;
            }
        }
    }
}

bool  TCellGrid::DoMouseWheelLeft(Classes::TShiftState Shift, const Types::TPoint &MousePos)
{

//    MouseWhellRight=0;
//    MouseWhellLeft = 1;

    int iRow;
    int iCol;
    TRect rect;
    int oldRow;
    TShiftState Mnoj;
    Mnoj.Clear();
    if (FCurrent.X >DrawInfo.Horz.GridCellCount-1)
    {
        FCurrent.X =DrawInfo.Horz.GridCellCount-1;
        FAnchor =FCurrent;
    }
    if (Shift == Mnoj)
    {
        if ((Row>1)&&(Col>2))
        {
            FCurrent.X --;
            FAnchor =FCurrent;
            iRow=CellRect(Col,Row).Top+2;
            iCol=CellRect(Col,Row).Left+2;

            if ((GetCell(Col, Row) && GetCell(Col, Row)->UnionRect != NULL))
            if ((GetCell(Col, Row)->UnionRect->Left <DrawInfo.Horz.FirstGridCell)&&(FCurrent.X >FixedCols))
            {
                oldRow =FCurrent.Y;
                while (GetCell(Col, Row)->UnionRect->Left < DrawInfo.Horz.FirstGridCell)
                {
                    DrawInfo.Horz.FirstGridCell--;
                    TMyCustomGrid::LeftCol =DrawInfo.Horz.FirstGridCell;
                }
                FCurrent.X =DrawInfo.Horz.FirstGridCell;
                FAnchor =FCurrent;
                FCurrent.Y = oldRow;
                FAnchor.Y = oldRow;
                iRow=GetGridRectToRectPixelNotUnionReal(FCurrent.X, FCurrent.Y).Top+2;
                iCol=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X, FCurrent.Y).Left+2;
            }

            if ((DrawInfo.Horz.FirstGridCell > FCurrent.X)&&(DrawInfo.Horz.FirstGridCell !=FixedCols))
            {
                ModifyScrollBar(0,0,0,true);
                DrawInfo.Horz.FirstGridCell = FCurrent.X;

                iRow=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X,FCurrent.Y).Top+2;
                iCol=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X,FCurrent.Y).Left+2;
            }

            CellGridMouseDown(this ,mbLeft,Shift,iCol,iRow);
            CellGridMouseUp(this,mbLeft,Shift,iCol,iRow);
            FAnchor =FCurrent;
            if (((FixedCols >=Col)&&(FCurrent.X>1))||((FixedRows >Row)&&(Col>2)))
            {
                FCurrent.X = GetGridRectCell(Col,Row).Left;
                FAnchor =FCurrent;
            } else
            {
                Col = GetGridRectCell(Col,Row).Left;
            }
            TGridRect GridRect;
            GridRect.Top = 2;
            GridRect.Left = DrawInfo.Horz.FirstGridCell;
            GridRect.Bottom = DrawInfo.Vert.LastFullVisibleCell;
            GridRect.Right = DrawInfo.Horz.FirstGridCell;

            InvalidateRect(GridRect);
        }
    }
    return true;
}

bool  TCellGrid::DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos)
{
    TShiftState Rasshiren;
    Rasshiren.Clear();
    if (StartMouseDown.X !=0 && StartMouseDown.Y !=0)
    {
        if (Shift.Contains(ssCtrl))
            DoMouseWheelLeft(Rasshiren,MousePos);

        if (Shift == Rasshiren)
        {
//            MouseWhellDown=0;
//            MouseWhellUp = 1;

            int iRow;
            int iCol;
            TRect rect;
            int oldCol;
            TShiftState Mnoj;
            Mnoj.Clear();
            if (FCurrent.Y >DrawInfo.Vert.GridCellCount-1)
            {
                FCurrent.Y =DrawInfo.Vert.GridCellCount-1;
                FAnchor =FCurrent;
            }
            if (Shift == Mnoj)
            {
                if ((Row>2)&&(Col>1))
                {
                    FCurrent.Y --;
                    FAnchor =FCurrent;
                    iRow=CellRect(Col,Row).Top+2;
                    iCol=CellRect(Col,Row).Left+2;

                    if ((GetCell(Col, Row) && GetCell(Col, Row)->UnionRect != NULL))
                    if ((GetCell(Col, Row)->UnionRect->Top <DrawInfo.Vert.FirstGridCell)&&(FCurrent.Y >FixedRows))
                    {
                        oldCol =FCurrent.X;
                        while (GetCell(Col, Row)->UnionRect->Top < DrawInfo.Vert.FirstGridCell)
                        {
                            DrawInfo.Vert.FirstGridCell--;
                            TMyCustomGrid::TopRow =DrawInfo.Vert.FirstGridCell;
                        }
                        FCurrent.Y =DrawInfo.Vert.FirstGridCell;
                        FAnchor =FCurrent;
                        FCurrent.X = oldCol;
                        FAnchor.X = oldCol;
                        iRow=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X,FCurrent.Y).Top+2;
                        iCol=GetGridRectToRectPixelNotUnionReal(FCurrent.X,FCurrent.Y).Left+2;
                    }

                    if ((DrawInfo.Vert.FirstGridCell > FCurrent.Y)&&(DrawInfo.Vert.FirstGridCell !=FixedRows))
                    {

                        ModifyScrollBar(1,0,0,true);
                        DrawInfo.Vert;
                        DrawInfo.Vert.FirstGridCell = FCurrent.Y;

                        iRow=GetGridRectToRectPixelNotUnionAndScroll(Col,FCurrent.Y).Top+2;
                        iCol=GetGridRectToRectPixelNotUnionAndScroll(Col,FCurrent.Y).Left+2;
                    }

                    CellGridMouseDown(this ,mbLeft,Shift,iCol,iRow);
                    CellGridMouseUp(this,mbLeft,Shift,iCol,iRow);
                    FAnchor =FCurrent;
                    if (((FixedRows >=Row)&&(FCurrent.Y>1))||((FixedCols >Col)&&(Row>2)))
                    {
                        FCurrent.Y = GetGridRectCell(Col,Row).Top;
                        FAnchor =FCurrent;
                    }
                    else
                        Row = GetGridRectCell(Col,Row).Top;

                    InvalidateRect2(TRect(
                        2,
                        DrawInfo.Vert.FirstGridCell,
                        DrawInfo.Horz.LastFullVisibleCell,
                        DrawInfo.Vert.FirstGridCell+1
                        ));
                }
            }
        }
    }
    return true;
}

bool  TCellGrid::DoMouseWheelRight(Classes::TShiftState Shift, const Types::TPoint &MousePos)
{

//    MouseWhellRight=1;
//    MouseWhellLeft = 0;
    VertFixed = true;
    HorzFixed = true;
    TShiftState Mnoj;
    Mnoj.Clear();

    int iRow;
    int iCol;
    int iCol2;
    int oldRow;

    if (Shift == Mnoj)
    {
        if (DrawInfo.Horz.GridCellCount-2 <Col)
        {
            FCurrent.X = DrawInfo.Horz.GridCellCount-1;
            FAnchor =FCurrent;
            PointMouseDownOld=FCurrent;
            MouseUpCoord=FCurrent;

            iRow=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X, FCurrent.Y).Top+2;
            iCol=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X, FCurrent.Y).Left+2;

            CellGridMouseDown(this ,mbLeft,Shift,iCol,iRow);
            CellGridMouseUp(this,mbLeft,Shift,iCol,iRow);
        } else
        if ((Col>1)&&(Row>1))
        {
            FCurrent.X ++;
            FAnchor =FCurrent;

            iRow=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X, FCurrent.Y).Top+2;
            iCol=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X, FCurrent.Y).Left+2;

            if ((GetCell(Col, Row) && GetCell(Col, Row)->UnionRect != NULL))
            {
                if ((GetCell(Col, Row)->UnionRect->Left >DrawInfo.Horz.LastFullVisibleCell))
                {
                    oldRow =FCurrent.Y;
                    while (GetCell(Col, Row)->UnionRect->Right >= DrawInfo.Horz.LastFullVisibleCell)
                    {
                        DrawInfo.Horz.LastFullVisibleCell++;
                        TMyCustomGrid::LeftCol++;
                    }
                    FCurrent.X =GetCell(Col, Row)->UnionRect->Right;
                    FAnchor =FCurrent;
                    FCurrent.Y = oldRow;
                    FAnchor.Y = oldRow;
                    iRow=GetGridRectToRectPixelNotUnionReal(FCurrent.X,FCurrent.Y).Top+2;
                    iCol=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X,FCurrent.Y).Left+2;
                }
                if (GetCell(Col, Row)->UnionRect->Left < FixedCols)
                {
                    FCurrent.X =GetCell(Col, Row)->UnionRect->Right;
                    FAnchor =FCurrent;
                    iRow=GetGridRectToRectPixelNotUnionReal(FCurrent.X,FCurrent.Y).Top+2;
                    iCol=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X,FCurrent.Y).Left+2;
                }
            }
            if ((DrawInfo.Horz.LastFullVisibleCell <= FCurrent.X)&&(DrawInfo.Horz.LastFullVisibleCell+1 <DrawInfo.Horz.GridCellCount))
            {
                ModifyScrollBar(0,1,0,true);
                FCurrent.X =DrawInfo.Horz.LastFullVisibleCell;
                FAnchor =FCurrent;

                iRow=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X, FCurrent.Y).Top+2;
                iCol=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X, FCurrent.Y).Left+2;
            }

            if (FCurrent.X == FixedCols)
            {
                HorzFixedLast = true;
                SetScrollStartCol();
                HorzFixedLast = false;
                FCurrent.X =FixedCols;

                iRow=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X, FCurrent.Y).Top+2;
                iCol=GetGridRectToRectPixelNotUnionReal(FCurrent.X, FCurrent.Y).Left+2;
            }
            oldRow = Row;

            if (FCurrent.X <DrawInfo.Horz.GridCellCount)
            {
                CellGridMouseDown(this ,mbLeft,Shift,iCol,iRow);
                CellGridMouseUp(this,mbLeft,Shift,iCol,iRow);
                FAnchor =FCurrent;

                if ((FixedCols >=Col)&&(FCurrent.X>1)||(FCurrent.Y <FixedRows))
                {
                    FCurrent.X = GetGridRectCell(Col,Row).Right;
                    Row = oldRow;
                    FCurrent.Y = Row;
                    FAnchor.Y = Row;
                    FAnchor =FCurrent;

                } else
                {
                    if (FixedRows >Row)
                    {
                    } else
                    {
                        Col = GetGridRectCell(Col,Row).Right;
                    }
                }
                TGridRect GridRect;
                GridRect.Top = 2;
                GridRect.Left = DrawInfo.Horz.FirstGridCell;
                GridRect.Bottom = DrawInfo.Vert.LastFullVisibleCell;
                GridRect.Right = DrawInfo.Horz.FirstGridCell;

                InvalidateRect(GridRect);
            }
        }
    }
    return true;
}

bool  TCellGrid::DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos)
{

    TShiftState Rasshiren;
    Rasshiren.Clear();
    if (StartMouseDown.Y ==0 || StartMouseDown.X ==0)
    {
    } else
    {
        if (Shift.Contains(ssCtrl))
        {
            DoMouseWheelRight(Rasshiren,MousePos);
        }
        if (Shift == Rasshiren)
        {
//            MouseWhellDown=1;
//            MouseWhellUp=0;
            VertFixed = true;
            HorzFixed = true;
            TShiftState Mnoj;
            Mnoj.Clear();

            int iRow;
            int iCol;
            int iCol2;
            int oldCol;

            if (Shift == Mnoj)
            {
                if (DrawInfo.Vert.GridCellCount-2 <Row)
                {
                    FCurrent.Y = DrawInfo.Vert.GridCellCount-1;
                    FAnchor =FCurrent;
                    PointMouseDownOld=FCurrent;
                    MouseUpCoord=FCurrent;

                    iRow=GetGridRectToRectPixelNotUnionAndScroll(Col,FCurrent.Y).Top+2;
                    iCol=GetGridRectToRectPixelNotUnionAndScroll(Col,FCurrent.Y).Left+2;

                    CellGridMouseDown(this ,mbLeft,Shift,iCol,iRow);
                    CellGridMouseUp(this,mbLeft,Shift,iCol,iRow);
                } else
                if ((Col>1)&&(Row>1))
                {
                    FCurrent.Y ++;
                    FAnchor =FCurrent;

                    iRow=GetGridRectToRectPixelNotUnionAndScroll(Col,FCurrent.Y).Top+2;
                    iCol=GetGridRectToRectPixelNotUnionAndScroll(Col,FCurrent.Y).Left+2;

                    if ((GetCell(Col, Row) && GetCell(Col, Row)->UnionRect != NULL))
                    {
                        if ((GetCell(Col, Row)->UnionRect->Top >DrawInfo.Vert.LastFullVisibleCell))
                        {
                            oldCol =FCurrent.X;
                            while (GetCell(Col, Row)->UnionRect->Bottom >= DrawInfo.Vert.LastFullVisibleCell)
                            {
                                DrawInfo.Vert.LastFullVisibleCell++;
                                TMyCustomGrid::TopRow++;
                            }
                            FCurrent.Y =GetCell(Col, Row)->UnionRect->Bottom;
                            FAnchor =FCurrent;
                            FCurrent.X = oldCol;
                            FAnchor.X = oldCol;
                            iRow=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X,FCurrent.Y).Top+2;
                            iCol=GetGridRectToRectPixelNotUnionReal(FCurrent.X,FCurrent.Y).Left+2;
                        }
                        if (GetCell(Col, Row)->UnionRect->Top < FixedRows)
                        {
                            FCurrent.Y =GetCell(Col, Row)->UnionRect->Bottom;
                            FAnchor =FCurrent;
                            iRow=GetGridRectToRectPixelNotUnionAndScroll(FCurrent.X,FCurrent.Y).Top+2;
                            iCol=GetGridRectToRectPixelNotUnionReal(FCurrent.X,FCurrent.Y).Left+2;
                        }
                    }

                    if ((DrawInfo.Vert.LastFullVisibleCell <= FCurrent.Y)&&(DrawInfo.Vert.LastFullVisibleCell+1 <DrawInfo.Vert.GridCellCount))
                    {
                        ModifyScrollBar(1,1,0,true);
                        DrawInfo.Vert;
                        FCurrent.Y =DrawInfo.Vert.LastFullVisibleCell;
                        FAnchor =FCurrent;

                        iRow=GetGridRectToRectPixelNotUnionAndScroll(Col,FCurrent.Y).Top+2;
                        iCol=GetGridRectToRectPixelNotUnionAndScroll(Col,FCurrent.Y).Left+2;
                    }

                    if (FCurrent.Y == FixedRows)
                    {
                        VertFixedLast = true;
                        SetScrollStartRow();
                        VertFixedLast = false;
                        FCurrent.Y =FixedRows;
                        iRow=GetGridRectToRectPixelNotUnionReal(Col,FCurrent.Y).Top+2;
                        iCol=GetGridRectToRectPixelNotUnionAndScroll(Col,FCurrent.Y).Left+2;
                    }
                    oldCol = Col;

                    if (FCurrent.Y <DrawInfo.Vert.GridCellCount)
                    {
                        CellGridMouseDown(this ,mbLeft,Shift,iCol,iRow);
                        CellGridMouseUp(this,mbLeft,Shift,iCol,iRow);
                        FAnchor =FCurrent;

                        if ((FixedRows >=Row)&&(FCurrent.Y>1)||(FCurrent.X <FixedCols))
                        {
                            FCurrent.Y = GetGridRectCell(Col,Row).Bottom;
                            Col = oldCol;
                            FCurrent.X = Col;
                            FAnchor.X = Col;
                            FAnchor =FCurrent;

                        } else
                        {
                            if (FixedCols >Col)
                            {
                            } else
                            {
                                Row = GetGridRectCell(Col,Row).Bottom;
                            }
                        }
                        TGridRect GridRect;
                        GridRect.Left = 2;
                        GridRect.Top = DrawInfo.Vert.FirstGridCell-1;
                        GridRect.Right = DrawInfo.Horz.LastFullVisibleCell;
                        GridRect.Bottom = DrawInfo.Vert.FirstGridCell;

                        InvalidateRect(GridRect);
                    }
                }
            }
        }
    }
    return true;
}

void  TCellGrid::ModifyScrollBar(unsigned ScrollBar, unsigned ScrollCode, unsigned Pos, bool UseRightToLeft)
{

    if (CursorMoveStarted())
        DrawCursorMove(CurrentMouseCoordTimer.X,CurrentMouseCoordTimer.Y);

    TMyCustomGrid::ModifyScrollBar(ScrollBar, ScrollCode, Pos, UseRightToLeft);
    CalcDrawInfo(DrawInfo);

    if (CursorMoveStarted())
        DrawCursorMove(CurrentMouseCoordTimer.X,CurrentMouseCoordTimer.Y);

    if (ScrollBar ==1)
    {
        InvalidateRect2(TRect(
            0,
            DrawInfo.Vert.FirstGridCell,
            DrawInfo.Horz.LastFullVisibleCell,
            DrawInfo.Vert.FirstGridCell
        ));
        InvalidateRect2(TRect(
            0,
            DrawInfo.Vert.LastFullVisibleCell,
            DrawInfo.Horz.LastFullVisibleCell,
            DrawInfo.Vert.LastFullVisibleCell
        ));
    }
    else
    {
        if (ScrollBar ==0)
        {
            InvalidateRect2(TRect(
                DrawInfo.Horz.FirstGridCell,
                0,
                DrawInfo.Horz.FirstGridCell,
                DrawInfo.Vert.LastFullVisibleCell
            ));
            InvalidateRect2(TRect(
                DrawInfo.Horz.LastFullVisibleCell,
                0,
                DrawInfo.Horz.LastFullVisibleCell,
                DrawInfo.Vert.LastFullVisibleCell
            ));
        }
        else
            InvalidateU2();
    }
}

TRect  TCellGrid::GetGridRectCell(int iCol,int iRow)
{
    TRect ret;
    ret.Left = iCol;
    ret.Right = iCol;
    ret.Top = iRow;
    ret.Bottom = iRow;
    TCell* Cell =GetCell(iCol, iRow);
    if (Cell && Cell->UnionRect != NULL)
    {// îáúåäåíåííàÿ
        ret.Left = Cell->UnionRect->Left;
        ret.Top = Cell->UnionRect->Top;
        ret.Right = Cell->UnionRect->Right;
        ret.Bottom = Cell->UnionRect->Bottom;
    }
    return ret;
}

void  TCellGrid::InvalidateRect2(const TRect& rect)
{
    InvalidateRect(RectToGridRectType(rect));
}

void     TCellGrid::StartScrollingTimer1(TGridCoord& CellHit1)
{
    if ((DrawInfo.Vert.FirstGridCell != FixedRows)||(DrawInfo.Horz.FirstGridCell != FixedCols))
    if ((StartMouseDown.X >0)&&(StartMouseDown.Y >0)&&
    ((StartMouseDown.Y < FixedRows)||(StartMouseDown.X < FixedCols))&&
    ((CellHit1.Y <FixedRows)&&(CellHit1.X <FixedCols))
    )
    {
        Timer->Enabled = true;
    }

    if ((StartMouseDown.X >0)&&(StartMouseDown.Y >0)&&
    ((StartMouseDown.Y < FixedRows)||(StartMouseDown.X < FixedCols))&&
    ((CellHit1.Y >=FixedRows)||(CellHit1.X >=FixedCols))
    )
    {
        Timer->Enabled = true;
        if ((DrawInfo.Vert.LastFullVisibleCell-1 >CellHit1.Y)&&
            (CellHit1.Y >=FixedRows)&&(StartMouseDown.Y < FixedRows)&&
            DrawInfo.Vert.FirstGridCell ==CellHit1.Y &&
            DrawInfo.Vert.FirstGridCell != FixedRows
        )
        {// (1, 9)
            SetScrollStartRow();
            Timer->Enabled = false;
        }
        if ((DrawInfo.Horz.LastFullVisibleCell-1 >CellHit1.X)&&
            (CellHit1.X >=FixedCols)&&(StartMouseDown.X < FixedCols)&&
            DrawInfo.Horz.FirstGridCell ==CellHit1.X &&
            DrawInfo.Horz.FirstGridCell != FixedCols
        )
        {// (5, 10)
            SetScrollStartCol();
            Timer->Enabled = false;
        }
    }
}

void     TCellGrid::StartScrollingTimer2(TGridCoord& CellHit1)
{

    if (!(DrawInfo.Vert.FirstGridCell ==FixedRows && DrawInfo.Horz.FirstGridCell ==FixedCols))
        if ((StartMouseDown.X > FixedCols-1)&&
            (StartMouseDown.Y > FixedRows-1)&&
            ((CellHit1.X <= FixedCols-1)||(CellHit1.Y <= FixedRows-1)))
            Timer->Enabled = true;

    if ((DrawInfo.Horz.FirstGridCell == FixedCols)&&(DrawInfo.Vert.FirstGridCell == FixedRows)&&(StartMouseDown.X > FixedCols-1)&&(StartMouseDown.Y > FixedRows-1)&&((CellHit1.X <= FixedCols-1)||(CellHit1.Y <= FixedRows-1)))
        Timer->Enabled = false;
}

void  TCellGrid::CellGridMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    TRect       Rect4;
    TGridRect   Rect4SortOld;
    TGridRect   Rect4SortNew;
    TGridRect   Rect4Draw;
    TRect       Rect4Union;

    ScrollParam     =0;
//    MouseWhellUp    =0;
//    MouseWhellDown  =0;
//    MouseWhellLeft  =0;
//    MouseWhellRight =0;

    TGridCoord CellHit1 = MouseCoord(X,Y);

    Rect4Union.Left  =-4;
    int iDeltaBorder =4;
    // - Íà ãðàíèöå ÿ÷ååê
    TRect AncCur =GetAnchorCurrentSort();
    if (iMouseDown ==0 && StartMouseDown.Y !=1 && StartMouseDown.X !=1)
        AncCur      =CalculationRect(AncCur);

    TRect rectborder =GetUnionRect(
        GetGridRectToRectPixelNotUnionAndScroll(AncCur.Left,AncCur.Top),
        GetGridRectToRectPixelNotUnionAndScroll(AncCur.Right,AncCur.Bottom));
    if (MoveCellBorder)
    {
        if (Shift.Contains(ssCtrl))
            Screen->Cursor =crDrag;
        else
            Screen->Cursor =crDefault;

        SetAnchorCurrentSort();
        if (CellHit1.X <DrawInfo.Horz.FirstGridCell -DrawInfo.Horz.FixedCellCount+2)
            CellHit1.X =DrawInfo.Horz.FirstGridCell -DrawInfo.Horz.FixedCellCount+2;
        if (CellHit1.Y <DrawInfo.Vert.FirstGridCell -DrawInfo.Vert.FixedCellCount+2)
            CellHit1.Y =DrawInfo.Vert.FirstGridCell -DrawInfo.Vert.FixedCellCount+2;

        if (CellHit1.X >DrawInfo.Horz.LastFullVisibleCell)
            CellHit1.X =DrawInfo.Horz.LastFullVisibleCell;
        if (CellHit1.Y >DrawInfo.Vert.LastFullVisibleCell)
            CellHit1.Y =DrawInfo.Vert.LastFullVisibleCell;

        DrawCursorMove2(CellHit1.X,CellHit1.Y);

        if (X <DrawInfo.Horz.FixedBoundary ||
            Y <DrawInfo.Vert.FixedBoundary ||
            DrawInfo.Horz.GridBoundary <X ||
            DrawInfo.Vert.GridBoundary <Y
        )
            Timer->Enabled =true;
        else
            Timer->Enabled =false;
    }
    else if (CellHit1.X >1 && CellHit1.Y >1 &&
            iMouseDown ==0 && (FCurrent.X !=1 || FCurrent.Y !=1) &&
            PointInRect(CellHit1.X,CellHit1.Y,AncCur) &&
            !PointInRect(X,Y,
            TRect(rectborder.Left+iDeltaBorder,rectborder.Top+iDeltaBorder,
              rectborder.Right -iDeltaBorder,rectborder.Bottom -iDeltaBorder
        )) &&
        (
          (
            X <rectborder.Left+iDeltaBorder &&
            Y >rectborder.Top &&
            Y <rectborder.Bottom
          ) ||
          (
            X >rectborder.Right -iDeltaBorder &&
            Y >rectborder.Top &&
            Y <rectborder.Bottom
          ) ||
          (
            Y <rectborder.Top+iDeltaBorder &&
            X >rectborder.Left &&
            X <rectborder.Right
          ) ||
          (
            Y >rectborder.Bottom -iDeltaBorder &&
            X >rectborder.Left &&
            X <rectborder.Right
          )
        )
    )
        Screen->Cursor =crSizeAll;
    else
    {
        Screen->Cursor =crDefault;
        if (iMouseDown == 0)
        {
            if (CellHit1.X >1 || CellHit1.X ==0)
                Options >> goRowSizing;
            else
                Options << goRowSizing;

            if (CellHit1.Y >1 || CellHit1.Y ==0)
                Options >> goColSizing;
            else
                Options << goColSizing;
        }

        if (iMouseDown == 1)
        { // Ìûøü áûëà íàæåòà è ïðîèñõîäèò äâèæåíèå
            // - Ïðîâåðêà êîððåêòíîñòè çîíû íàõîæäåíèÿ ìûøè
            if (X<3)
                X=3;
            if (Y<3)
                Y=3;
            // - Ïðîâåðêà êîððåêòíîñòè çîíû íàõîæäåíèÿ ìûøè END
            MouseX =X;
            MouseY =Y;
            StartScrollingTimer1(CellHit1);
            // - Åñëè ñòàðòîâàëè íà Fixed
            CellHit1 = MouseCoord(X,Y);

            if (StartMouseDown.X == 1)
                CellHit1.X = 1;
            if (StartMouseDown.Y == 1)
                CellHit1.Y = 1;
            // - END -

            // - Îáðàáîòêà âûäåëåíèÿ ïðè ñêðîëèðîâàíèè 1
            StartScrollingTimer2(CellHit1);
                if (CellHit1.X <=DrawInfo.Horz.FirstGridCell ||
                    CellHit1.Y <=DrawInfo.Vert.FirstGridCell ||
                    DrawInfo.Horz.GridBoundary <X ||
                    DrawInfo.Vert.GridBoundary <Y
                )
                    Timer->Enabled =true;
                else
                    Timer->Enabled =false;

            // - END -

            // - Âûäåëåíèå ñòðîêè, ñòîëáöà, òàáëèöû
            XM =X;
            YM =Y;

            if (DrawInfo.Horz.GridBoundary <= XM)
                XM=DrawInfo.Horz.GridBoundary-1;
            if (DrawInfo.Vert.GridBoundary <= YM)
                YM=DrawInfo.Vert.GridBoundary-1;

            MousePosCellMoveSelect = MouseCoord(XM,YM);
            // - Âûäåëåíèå ñòðîêè, ñòîëáöà, òàáëèöû END
            CellHit1 =MousePosCellMoveSelect;

            MousePosCellMove =CellHit1;
            if (MousePosCellMoveSelect.X >0 && MousePosCellMoveSelect.Y >0)
            {
                if ((OldCellMouseMove.X != MousePosCellMoveSelect.X)||(OldCellMouseMove.Y != MousePosCellMoveSelect.Y))
                {//Åñëè ïîçèöèÿ ìûøè èçìåíèëàñü íà çàí÷åíèå Cell

                    Rect4 = CalculationRect(StartMouseDown,MousePosCellMoveSelect);
                    if (StartMouseDown.X ==1 || StartMouseDown.Y ==1)
                    {
                        if (StartMouseDown.X ==1)
                        {
                            Rect4.Left      =2;
                            Rect4.Right     =ColCount-1;
                            Rect4.Top       =FCurrent.Y;
                            Rect4.Bottom    =MousePosCellMoveSelect.Y;
                        }
                        if (StartMouseDown.Y ==1)
                        {
                            Rect4.Top       =2;
                            Rect4.Bottom    =RowCount-1;
                            Rect4.Left      =FCurrent.X;
                            Rect4.Right     =MousePosCellMoveSelect.X;
                        }
                        if (StartMouseDown.Y ==1 && StartMouseDown.X ==1)
                        {
                            Rect4.Left      =2;
                            Rect4.Right     =ColCount-1;
                            Rect4.Top       =2;
                            Rect4.Bottom    =RowCount-1;
                        }
                    }
                    FCurrent.X  =Rect4.Left;
                    FCurrent.Y  =Rect4.Top;
                    FAnchor.X   =Rect4.Right;
                    FAnchor.Y   =Rect4.Bottom;

                    // Íèæå äëÿ ïåðåðèñîâêè îïðåäåëåííîãî ðåêòàíãëà
                    OldRectCurrentAnchorMouseMoveCell.Left      =JobFCurrent.X;
                    OldRectCurrentAnchorMouseMoveCell.Top       =JobFCurrent.Y;
                    OldRectCurrentAnchorMouseMoveCell.Right     =JobFAnchor.X;
                    OldRectCurrentAnchorMouseMoveCell.Bottom    =JobFAnchor.Y;

                    Rect4SortOld = GetGridRectCellSort(OldRectCurrentAnchorMouseMoveCell);
                    // - Îáðàáîòêà âûäåëåíèÿ ïðè ñêðîëèðîâàíèè  2

                    if (StartMouseDown.Y > FixedRows && StartMouseDown.X > FixedCols)
                        if ((Timer->Enabled == true)&&
                            (FixedRows!= DrawInfo.Vert.FirstGridCell)&&
                            (CellHit1.Y <=DrawInfo.Vert.FirstGridCell)
                        )
                            FCurrent.Y = FixedRows;
                        else if ((Timer->Enabled == true)&&
                                (FixedCols!= DrawInfo.Horz.FirstGridCell)&&
                                (CellHit1.X <=DrawInfo.Horz.FirstGridCell))
                                FCurrent.X = FixedCols;

                    // - Îáðàáîòêà âûäåëåíèÿ ïðè ñêðîëèðîâàíèè END  2

                    JobFCurrent =FCurrent;
                    JobFAnchor  =FAnchor;

                    OldRectCurrentAnchorMouseMoveCell.Left      =JobFCurrent.X;
                    OldRectCurrentAnchorMouseMoveCell.Top       =JobFCurrent.Y;
                    OldRectCurrentAnchorMouseMoveCell.Right     =JobFAnchor.X;
                    OldRectCurrentAnchorMouseMoveCell.Bottom    =JobFAnchor.Y;
                    Rect4SortNew = GetGridRectCellSort(OldRectCurrentAnchorMouseMoveCell);

                    Rect4Draw = GetUnionGridRect(Rect4SortOld, Rect4SortNew);
                    if (Rect4Draw.Bottom >DrawInfo.Vert.LastFullVisibleCell+1)
                        Rect4Draw.Bottom = DrawInfo.Vert.LastFullVisibleCell+1;
                    if (Rect4Draw.Right >DrawInfo.Horz.LastFullVisibleCell+1)
                        Rect4Draw.Right = DrawInfo.Horz.LastFullVisibleCell+1;

                    // - Âûäåëåíèå ñòðîêè, ñòîëáöà, òàáëèöû
                    Rect4 =CalculationRect(StartMouseDown,MousePosCellMoveSelect);

                    SelectTable             =false;
                    SelectColumn            =false;
                    SelectString            =false;
                    bool NotSelectString    =false;
                    bool NotSelectColumn    =false;

                    if ((Rect4.Left ==2)&&(Rect4.Right ==ColCount-1)&&(StartMouseDown.X >1))
                        SelectString = true;// Âûäåëåíà ñòðîêà

                    if (((Rect4.Left ==3)&&(Rect4.Right ==ColCount-1)&&(StartMouseDown.X >1)) ||
                        ((Rect4.Left ==2)&&(Rect4.Right ==ColCount-2)&&(StartMouseDown.X >1))
                    )
                        NotSelectString = true;// ÍÅ Âûäåëåíà ñòðîêà

                    if ((Rect4.Top ==2)&&(Rect4.Bottom ==RowCount-1)&&(StartMouseDown.Y >1))
                        SelectColumn = true;// Âûäåëåí ñòîëáåö

                    if (((Rect4.Top ==3)&&(Rect4.Bottom ==RowCount-1)&&(StartMouseDown.Y >1)) ||
                        ((Rect4.Top ==2)&&(Rect4.Bottom ==RowCount-2)&&(StartMouseDown.Y >1))
                    )
                        NotSelectColumn = true;// Âûäåëåí ñòîëáåö

                    if ((Rect4.Left ==1)&&((Rect4.Right ==ColCount-1)||(StartMouseDown.X ==1)))
                        SelectString = true;// Âûäåëåíà ñòðîêà

                    if ((Rect4.Top ==1)&&((Rect4.Bottom ==RowCount-1)||(StartMouseDown.Y ==1)))
                        SelectColumn = true;// Âûäåëåí ñòîëáåö

                    if (SelectColumn &&
                        SelectString &&
                        SelectAllJobField()
                    )
                        SelectTable=true;

                    // - Âûäåëåíèå ñòðîêè, ñòîëáöà, òàáëèöû END
                    if (GetCell(MousePosCellMoveSelect.X, MousePosCellMoveSelect.Y) && GetCell(MousePosCellMoveSelect.X,MousePosCellMoveSelect.Y)->UnionRect !=NULL)
                    {
                        Rect4Union =*GetCell(MousePosCellMoveSelect.X,MousePosCellMoveSelect.Y)->UnionRect;
                        if (CurrentUnionRectMouseMove == Rect4Union)
                        {
                            ZoomAndClipRectToJobRect(Rect4Draw,1);
                            if (SelectColumn || NotSelectColumn)
                                Rect4Draw.Top =1;

                            if (SelectString || NotSelectString)
                                Rect4Draw.Left =1;

                            InvalidateRect(Rect4Draw);
                        }
                        else
                        {
                            ZoomAndClipRectToJobRect(Rect4Draw,1);
                            if (SelectColumn || NotSelectColumn)
                                Rect4Draw.Top =1;

                            if (SelectString || NotSelectString)
                                Rect4Draw.Left =1;

                            InvalidateRect(Rect4Draw);
                            CurrentUnionRectMouseMove = Rect4Union;
                        }
                        iCountYes++;
                    }
                    else
                    {
                        ZoomAndClipRectToJobRect(Rect4Draw,1);

                        if (SelectColumn || NotSelectColumn)
                            Rect4Draw.Top =1;
                        if (SelectString || NotSelectString)
                            Rect4Draw.Left =1;

                        InvalidateRect(Rect4Draw);
                        if (Rect4Draw.Bottom == RowCount-1 || Rect4Draw.Right ==ColCount-1)
                            PrivatEvent_1 =true;
                        iCountYes = 0;
                    }

                    if (PrivatEvent_1)
                    {
                        PrivatEvent_1 = false;
                        InvalidateU2();
                    }
                    OldCellMouseMove = MousePosCellMoveSelect;
                }
            }
        }
    }

}

bool  TCellGrid::SelectAllJobField()
{
    // Âûäåëåííî âñå ðàáî÷åå ïîëå
    bool ret=false;
    if ((FCurrent.X ==2)||(FCurrent.X ==ColCount-1)) ret=true; else ret =false;
    if ((FCurrent.Y ==2)||(FCurrent.Y ==RowCount-1)) ret=true; else ret =false;

    if ((FAnchor.X ==2)||(FAnchor.X ==ColCount-1)) ret=true; else ret =false;
    if ((FAnchor.Y ==2)||(FAnchor.Y ==RowCount-1)) ret=true; else ret =false;

    return ret;
}

TRect  TCellGrid::GetGridRectToRectPixelNotUnion(int iCol,int iRow)// Âîçâðàùàåò Rect â ïèêñåëÿõ
{
    TRect ret;
    int top=0;
    int left=0;
    //-(FixedCols-2)
    for (int i=DrawInfo.Horz.FirstGridCell-2; i<iCol; i++)
        left +=GetColWidths(i)+1;
    ret.Left = left;
    ret.Right = ret.Left+GetColWidths(iCol);

    //-(FixedRows-2)
    for (int i=DrawInfo.Vert.FirstGridCell-2; i<iRow; i++)
        top +=GetRowHeights(i)+1;
    ret.Top = top;
    ret.Bottom =ret.Top+GetRowHeights(iRow);

    return ret;
}

void  TCellGrid::DrawCursorU2(int CurCol, int CurRow, int iLeft,int iTop,int iRight,int iBottom)
{
    if (!MoveCellBorder)
    {
        TRect& ValideSel = GetValidSelection();
        ClipRectToJobRect(ValideSel);
        TRect& ValideSelPlus = GetValidSelectionPlus();
        TRect ColRow(CurCol,CurRow,CurCol,CurRow);

        if (Rect1InRect2(ColRow, ValideSelPlus))
        {
            TRect& ValideSelMinus=GetValidSelectionMinus();
            if (ValideSel.Left ==2 && ValideSel.Top ==2)
            {
                ValideSelMinus.Left=3;
                ValideSelMinus.Top=3;
            }
            if ( !Rect1InRect2(ColRow, ValideSelMinus) )
            {
                int xLeft = ValideSel.Left;
                int xRight =ValideSel.Right;

                int yTop = ValideSel.Top;
                int yBottom =ValideSel.Bottom;

                if (ScrollParam ==18)
                {
                    xLeft =FixedCols-1;
                    xRight =FixedCols-1;
                }
                if (ScrollParam ==17)
                {
                    yTop =FixedRows-1;
                    yBottom =FixedRows-1;
                }
                if (ScrollParam ==13)
                {
                    xLeft =DrawInfo.Horz.FirstGridCell;
                }
                if (ScrollParam ==14)
                {
                    yTop =DrawInfo.Vert.FirstGridCell;
                }

                HRGN MyRgn5;
                MyRgn5 = ::CreateRectRgn(iLeft,iTop,iRight,iBottom);
                ::SelectClipRgn(Canvas->Handle,MyRgn5);

                DrawCursor( GetUnionRect(   GetGridRectToRectPixelForBorder(xLeft, yTop),
                                            GetGridRectToRectPixelForBorder(xRight, yBottom))   );

                ::SelectClipRgn(Canvas->Handle,NULL);
                ::DeleteObject(MyRgn5);

            }
        }
    }
}

void  TCellGrid::DrawCursor(const TRect& Rect)
{
    if (Canvas->Pen->Color != clWhite)
        Canvas->Pen->Color = clWhite;

    TPenStyle oldStyle =Canvas->Pen->Style;
    TPenMode oldMode =Canvas->Pen->Mode;

    if (Canvas->Pen->Width !=1)
        Canvas->Pen->Width =1;

    if ( Canvas->Pen->Style != psSolid )
        Canvas->Pen->Style = psSolid;

    if ( Canvas->Pen->Mode != pmXor )
        Canvas->Pen->Mode = pmXor;

    Canvas->MoveTo(Rect.Left+1, Rect.Top);
    Canvas->LineTo(Rect.Right-1, Rect.Top);
    Canvas->LineTo(Rect.Right-1, Rect.Bottom-1);
    Canvas->LineTo(Rect.Left, Rect.Bottom-1);
    Canvas->LineTo(Rect.Left, Rect.Top-1);

    Canvas->MoveTo(Rect.Left, Rect.Top-1);
    Canvas->LineTo(Rect.Right, Rect.Top-1);
    Canvas->LineTo(Rect.Right, Rect.Bottom);
    Canvas->LineTo(Rect.Left-1, Rect.Bottom);
    Canvas->LineTo(Rect.Left-1, Rect.Top-2);

    Canvas->MoveTo(Rect.Left-1, Rect.Top-2);
    Canvas->LineTo(Rect.Right+1, Rect.Top-2);
    Canvas->LineTo(Rect.Right+1, Rect.Bottom+1);
    Canvas->LineTo(Rect.Left-2, Rect.Bottom+1);
    Canvas->LineTo(Rect.Left-2, Rect.Top-3);

    if ( Canvas->Pen->Style != oldStyle )
        Canvas->Pen->Style = oldStyle;

    if ( Canvas->Pen->Mode != oldMode )
        Canvas->Pen->Mode = oldMode;
}

void  TCellGrid::DrawCursorMove2(int Col, int Row)
{
    if (CurrentMouseCoordTimer.X != Col || CurrentMouseCoordTimer.Y != Row)
    {
        if ((CurrentMouseCoordTimer.X != 0 || CurrentMouseCoordTimer.Y != 0))
            DrawCursorMove(CurrentMouseCoordTimer.X,CurrentMouseCoordTimer.Y);

        CurrentMouseCoordTimer.X =Col;
        CurrentMouseCoordTimer.Y =Row;
        DrawCursorMove(CurrentMouseCoordTimer.X,CurrentMouseCoordTimer.Y);
    }
}

void  TCellGrid::DrawCursorMove(int Col, int Row)
{
    int iXS =StartMouseDown.X +Col -OldFAnchorBorder.X;
    int iYS =StartMouseDown.Y +Row -OldFAnchorBorder.Y;

    if (iXS <=DrawInfo.Horz.FirstGridCell-DrawInfo.Horz.FixedCellCount+2)
        iXS =DrawInfo.Horz.FirstGridCell-DrawInfo.Horz.FixedCellCount+2;
    if (iYS <=DrawInfo.Vert.FirstGridCell -DrawInfo.Vert.FixedCellCount+2)
        iYS =DrawInfo.Vert.FirstGridCell -DrawInfo.Vert.FixedCellCount+2;

    if (iXS +MouseUpCoord.X -StartMouseDown.X >=DrawInfo.Horz.LastFullVisibleCell)
        iXS =DrawInfo.Horz.LastFullVisibleCell -(MouseUpCoord.X -StartMouseDown.X);

    if (iYS +MouseUpCoord.Y -StartMouseDown.Y >=DrawInfo.Vert.LastFullVisibleCell)
        iYS =DrawInfo.Vert.LastFullVisibleCell -(MouseUpCoord.Y -StartMouseDown.Y);

    if (iXS <2)
        iXS =2;
    if (iYS <2)
        iYS =2;

    TRect Rect =
        GetUnionRect(
        GetGridRectToRectPixelForBorder(
        iXS,
        iYS),
        GetGridRectToRectPixelForBorder(
        iXS +MouseUpCoord.X -StartMouseDown.X,
        iYS +MouseUpCoord.Y -StartMouseDown.Y)
        );

    if (Rect.Bottom >DrawInfo.Vert.GridBoundary)
        Rect.Bottom =DrawInfo.Vert.GridBoundary;
    if (Rect.Right >DrawInfo.Horz.GridBoundary)
        Rect.Right =DrawInfo.Horz.GridBoundary;

    TColor Color;
    int Spoc =0;
    int Cross=0;
    int Width=3;

    for (int y=Rect.Top-1; y <=Rect.Bottom; y+=2)
    {
        for (int i=1; i<=Width; i++)
        {
            Color =Canvas->Pixels[Rect.Left -i+1-Spoc][y+Cross];
            Canvas->Pixels[Rect.Left-i+1-Spoc][y+Cross] = clWhite -Color;
            Color =Canvas->Pixels[Rect.Right -i+2-Spoc][y+Cross];
            Canvas->Pixels[Rect.Right -i+2-Spoc][y+Cross] = clWhite -Color;
            if (Cross ==1)
                Cross =-1;
            Cross++;
        }
        Cross=0;
    }
    Cross=0;
    for (int x=Rect.Left; x <Rect.Right; x+=2)
    {
        for (int i=1; i<=Width; i++)
        {
            Color =Canvas->Pixels[x+Cross][Rect.Top+1-i-Spoc];
            Canvas->Pixels[x+Cross][Rect.Top+1-i-Spoc] = clWhite -Color;
            Color =Canvas->Pixels[x+Cross][Rect.Bottom-i+2-Spoc];
            Canvas->Pixels[x+Cross][Rect.Bottom-i+2-Spoc] = clWhite -Color;
            if (Cross ==1)
                Cross =-1;
            Cross++;
        }
        Cross=0;
    }
}

void  TCellGrid::DrawCursorMove(const TRect& Rect, int Width)
{
    TColor Color;
    int Spoc =0;
    int Cross=0;
    for (int y=Rect.Top-1; y <=Rect.Bottom; y+=2)
    {
        for (int i=1; i<=Width; i++)
        {
            Color =Canvas->Pixels[Rect.Left -i+1-Spoc][y+Cross];
            Canvas->Pixels[Rect.Left-i+1-Spoc][y+Cross] = clWhite -Color;

            Color =Canvas->Pixels[Rect.Right -i+2-Spoc][y+Cross];
            Canvas->Pixels[Rect.Right -i+2-Spoc][y+Cross] = clWhite -Color;
            if (Cross ==1)
                Cross =-1;
            Cross++;
        }
        Cross=0;
    }
    Cross=0;
    for (int x=Rect.Left; x <Rect.Right; x+=2)
    {
        for (int i=1; i<=Width; i++)
        {
            Color =Canvas->Pixels[x+Cross][Rect.Top+1-i-Spoc];
            Canvas->Pixels[x+Cross][Rect.Top+1-i-Spoc] = clWhite -Color;

            Color =Canvas->Pixels[x+Cross][Rect.Bottom-i+2-Spoc];
            Canvas->Pixels[x+Cross][Rect.Bottom-i+2-Spoc] = clWhite -Color;
            if (Cross ==1)
                Cross =-1;
            Cross++;
        }
        Cross=0;
    }

}

TRect  TCellGrid::GetGridRectToRectPixelNotUnionReal(int iCol,int iRow)// Âîçâðàùàåò Rect â ïèêñåëÿõ
{
    TRect ret;
    int i;
    ret.Left =0;
    ret.Top =0;

    for (i=0; i<iCol; i++)
        ret.Left +=GetColWidths(i)+1;

    ret.Right = ret.Left+GetColWidths(iCol);

    for (i=0; i<iRow; i++)
        ret.Top +=GetRowHeights(i)+1;

    ret.Bottom =ret.Top+GetRowHeights(iRow);
    return ret;
}

int  TCellGrid::SumRow(int Start, int End)
{
    int ret=0;
    for (int i=Start; i<= End; i++)
        ret +=GetRowHeights(i)+1;

    return ret;
}

int  TCellGrid::SumCol(int Start, int End)
{
    int ret=0;
    for (int i=Start; i<= End; i++)
        ret +=GetColWidths(i)+1;

    return ret;
}

TRect  TCellGrid::GetGridRectToRectPixelForBorder(int Col,int Row)
{
    TRect recttemp;
    if (Row >1 && Col >1)
    {
        TRect StartRectF,EndRectF, StartRect,EndRect;
        int iColW, iRowH;
        if (Row <FixedRows || Col <FixedCols)
        {
            StartRectF = GetGridRectToRectPixelNotUnionReal(Col,Row);
            EndRectF = StartRectF;
        }

        StartRect = GetGridRectToRectPixelNotUnion(Col,Row);
        EndRect = StartRect;
        if (FixedRows>2)
        {
            int iFixedRow =SumRow(2,FixedRows-1);

            StartRect.Top +=iFixedRow;
            StartRect.Bottom +=iFixedRow;

            EndRect.Top +=iFixedRow;
            EndRect.Bottom +=iFixedRow;
        }
        if (FixedCols>2)
        {
            int iFixedCol =SumCol(2,FixedCols-1);

            StartRect.Left +=iFixedCol;
            StartRect.Right +=iFixedCol;

            EndRect.Left +=iFixedCol;
            EndRect.Right +=iFixedCol;
        }

        if (DrawInfo.Horz.FirstGridCell >2)
        {
            iColW=GetGridRectToRectPixelNotUnion(DrawInfo.Horz.FirstGridCell,2).Left - GetGridRectToRectPixelNotUnionReal(2,2).Left;

            StartRect.Left -=iColW;
            StartRect.Right -=iColW;
            EndRect.Left -=iColW;
            EndRect.Right -=iColW;
        }
        if (DrawInfo.Vert.FirstGridCell >2)
        {
            iRowH=GetGridRectToRectPixelNotUnion(2,DrawInfo.Vert.FirstGridCell).Top -GetGridRectToRectPixelNotUnionReal(2,2).Top;;

            StartRect.Top -=iRowH;
            StartRect.Bottom -=iRowH;
            EndRect.Top -=iRowH;
            EndRect.Bottom -=iRowH;
        }

        if (Row <FixedRows)
        {
            StartRect.Top = StartRectF.Top;
            StartRect.Bottom = StartRectF.Bottom;
            EndRect.Top = EndRectF.Top;
            EndRect.Bottom = EndRectF.Bottom;
        }
        if (Col <FixedCols)
        {
            StartRect.Left = StartRectF.Left;
            StartRect.Right = StartRectF.Right;
            EndRect.Left = EndRectF.Left;
            EndRect.Right = EndRectF.Right;
        }
        ::UnionRect(&recttemp, &StartRect, &EndRect);
    }
    return recttemp;
}

TRect  TCellGrid::GetGridRectToRectPixelNotUnionAndScroll(int Col,int Row)
{
    TRect StartRect,EndRect,recttemp;
    TRect StartRectF,EndRectF;
    int iColW, iRowH;
    TCell* Cell =GetCell(Col,Row);
    if (Row <FixedRows && Row >1)
    {
        if (Cell && Cell->UnionRect != NULL)
        {
            int NewColStart,NewRowStart,NewColEnd,NewRowEnd;
            // ïîëó÷àåì ðåãèîí â ÿ÷åéêàõ óêàçûâàþùèé íà îáúåäåíåííóþ ÿ÷åêó

            NewColStart =Cell->UnionRect->Left;
            NewRowStart =Cell->UnionRect->Top;
            NewColEnd   =Cell->UnionRect->Right;
            NewRowEnd   =Cell->UnionRect->Bottom;

            StartRectF = GetGridRectToRectPixelNotUnionReal(NewColStart,NewRowStart);
            EndRectF = GetGridRectToRectPixelNotUnionReal(NewColEnd,NewRowEnd);
        }
        else
        {
            StartRectF = GetGridRectToRectPixelNotUnionReal(Col,Row);
            EndRectF = StartRectF;
        }
    }

    if ((Col <FixedCols)&&(Col >1))
    {
        if (Cell && Cell->UnionRect != NULL)
        {
            int NewColStart,NewRowStart,NewColEnd,NewRowEnd;
            // ïîëó÷àåì ðåãèîí â ÿ÷åéêàõ óêàçûâàþùèé íà îáúåäåíåííóþ ÿ÷åêó
            NewColStart =Cell->UnionRect->Left;
            NewRowStart =Cell->UnionRect->Top;
            NewColEnd   =Cell->UnionRect->Right;
            NewRowEnd   =Cell->UnionRect->Bottom;

            StartRectF = GetGridRectToRectPixelNotUnionReal(NewColStart,NewRowStart);
            EndRectF = GetGridRectToRectPixelNotUnionReal(NewColEnd,NewRowEnd);
        } else
        {
            StartRectF = GetGridRectToRectPixelNotUnionReal(Col,Row);
            EndRectF = StartRectF;
        }
    }

    if (Cell && Cell->UnionRect != NULL)
    {
        int NewColStart,NewRowStart,NewColEnd,NewRowEnd;
        // ïîëó÷àåì ðåãèîí â ÿ÷åéêàõ óêàçûâàþùèé íà îáúåäåíåííóþ ÿ÷åêó
        NewColStart =Cell->UnionRect->Left;
        NewRowStart =Cell->UnionRect->Top;
        NewColEnd   =Cell->UnionRect->Right;
        NewRowEnd   =Cell->UnionRect->Bottom;

        StartRect = GetGridRectToRectPixelNotUnion(NewColStart,NewRowStart);
        EndRect = GetGridRectToRectPixelNotUnion(NewColEnd,NewRowEnd);
        if (FixedRows>2)
        {
            int iFixedRow =SumRow(2,FixedRows-1);

            StartRect.Top +=iFixedRow;
            StartRect.Bottom +=iFixedRow;

            EndRect.Top +=iFixedRow;
            EndRect.Bottom +=iFixedRow;
        }
        if (FixedCols>2)
        {
            int iFixedCol =SumCol(2,FixedCols-1);

            StartRect.Left +=iFixedCol;
            StartRect.Right +=iFixedCol;

            EndRect.Left +=iFixedCol;
            EndRect.Right +=iFixedCol;
        }
    } else
    {
        StartRect = GetGridRectToRectPixelNotUnion(Col,Row);
        EndRect = StartRect;
        if (FixedRows>2)
        {
            int iFixedRow       =SumRow(2,FixedRows-1);
            StartRect.Top       +=iFixedRow;
            StartRect.Bottom    +=iFixedRow;
            EndRect.Top         +=iFixedRow;
            EndRect.Bottom      +=iFixedRow;
        }
        if (FixedCols>2)
        {
            int iFixedCol   =SumCol(2,FixedCols-1);
            StartRect.Left  +=iFixedCol;
            StartRect.Right +=iFixedCol;
            EndRect.Left    +=iFixedCol;
            EndRect.Right   +=iFixedCol;
        }
    }
    if (DrawInfo.Horz.FirstGridCell >2)
    {
        iColW=GetGridRectToRectPixelNotUnion(DrawInfo.Horz.FirstGridCell,2).Left - GetGridRectToRectPixelNotUnionReal(2,2).Left;

        StartRect.Left  -=iColW;
        StartRect.Right -=iColW;
        EndRect.Left    -=iColW;
        EndRect.Right   -=iColW;
    }
    if (DrawInfo.Vert.FirstGridCell >2)
    {
        iRowH=GetGridRectToRectPixelNotUnion(2,DrawInfo.Vert.FirstGridCell).Top -GetGridRectToRectPixelNotUnionReal(2,2).Top;;

        StartRect.Top       -=iRowH;
        StartRect.Bottom    -=iRowH;
        EndRect.Top         -=iRowH;
        EndRect.Bottom      -=iRowH;
    }

    if (Row <FixedRows && Row >1)
    {
        StartRect.Top       =StartRectF.Top;
        StartRect.Bottom    =StartRectF.Bottom;
        EndRect.Top         =EndRectF.Top;
        EndRect.Bottom      =EndRectF.Bottom;
    }
    if (Col <FixedCols && Col >1)
    {
        StartRect.Left  =StartRectF.Left;
        StartRect.Right =StartRectF.Right;
        EndRect.Left    =EndRectF.Left;
        EndRect.Right   =EndRectF.Right;
    }

    ::UnionRect(&recttemp, &StartRect, &EndRect);
    return recttemp;
}

TRect  TCellGrid::GetGridRectToRectPixelUnionReal(int iCol,int iRow)
{// Âîçâðàùàåò Rect â ïèêñåëÿõ â Real è ñ ó÷åòîì Union
    TRect  rect1,rect2,ret,temp;

    if (GetCell(iCol,iRow) && (GetCell(iCol,iRow)->UnionRect != NULL))
    {
        int NewColStart,NewRowStart,NewColEnd,NewRowEnd;
        // ïîëó÷àåì ðåãèîí â ÿ÷åéêàõ óêàçûâàþùèé íà îáúåäåíåííóþ ÿ÷åêó
        temp =*GetCell(iCol,iRow)->UnionRect;
        NewColStart = temp.Left;
        NewRowStart = temp.Top;
        NewColEnd = temp.Right;
        NewRowEnd = temp.Bottom;

        rect1 = GetGridRectToRectPixelNotUnionReal(NewColStart,NewRowStart);
        rect2 = GetGridRectToRectPixelNotUnionReal(NewColEnd,NewRowEnd);
        ret = GetUnionRect(rect1,rect2);
    } else
    {
        ret = GetGridRectToRectPixelNotUnionReal(iCol, iRow);
    }
    return ret;
}

bool  TCellGrid::BeEqualRect(const TRect& rect1, const TRect& rect2)
{// Ðàâíÿåòñÿ ëè rect1 rect2 òîãäà OK
    bool ret=false;
    if ((rect1.Left ==rect2.Left)&&
        (rect1.Top ==rect2.Top)&&
        (rect1.Right ==rect2.Right)&&
        (rect1.Bottom ==rect2.Bottom)) ret = true;
    return ret;
}

bool  TCellGrid::EqualSizeRect(const TRect& rect1, const TRect& rect2)
{// Ðàâíÿåòñÿ ëè ðàçìåðû rect1 rect2
    return (
            (rect1.Right -rect1.Left ==
             rect2.Right -rect2.Left) &&
            (rect1.Bottom -rect1.Top ==
             rect2.Bottom -rect2.Top));
}

bool  TCellGrid::Rect1CrossRect2(const TRect& rect1, const TRect& rect2)
{// Ïåðåñåêàþòüñÿ ëè rect1 è rect2 òîãäà OK
    bool ret=false;
    if ((rect2.Left >=rect1.Left &&
        rect2.Left <=rect1.Right &&
        rect2.Top >=rect1.Top &&
        rect2.Top <=rect1.Bottom) ||
        (rect1.Left >=rect2.Left &&
        rect1.Left <=rect2.Right &&
        rect1.Top >=rect2.Top &&
        rect1.Top <=rect2.Bottom)
    )
        ret = true;
    return ret;
}

bool  TCellGrid::Rect1InRect2(const TRect& rect1, const TRect& rect2)
{// Âíóòðè ëè rect1 rect2 òîãäà OK
    bool ret=false;
    if ((rect1.Left >=rect2.Left)&&
        (rect1.Top >=rect2.Top)&&
        (rect1.Right <=rect2.Right)&&
        (rect1.Bottom <=rect2.Bottom)) ret = true;
    return ret;
}

void  TCellGrid::NullRect(TRect& rect1)
{
// Óñòàíîâèòü çíà÷åíèå 0 â rect
    rect1.Left = 0;
    rect1.Top = 0;
    rect1.Right = 0;
    rect1.Bottom = 0;
}

void  TCellGrid::NullLine(TCell& Cell)
{// Óñòàíîâèòü çíà÷åíèå 0 â Line
    Cell.Line.WidthLeft =0;
    Cell.Line.WidthTop =0;
    Cell.Line.WidthRight =0;
    Cell.Line.WidthBottom =0;
}

bool  TCellGrid::CellBeUnionCell(const TGridCoord& cell)
{// ßâëÿåòüñÿ ëè ýòà ÿ÷åéêà îáúåäåíåííîé
    bool ret=false;
    if ((GetCell(cell.X, cell.Y) != NULL)&&(GetCell(cell.X, cell.Y)->UnionRect != NULL)) ret =true;
    return ret;
}

bool  TCellGrid::CellBeUnionCell(int Col, int Row)
{// ßâëÿåòüñÿ ëè ýòà ÿ÷åéêà îáúåäåíåííîé
    bool ret=false;
    if ((GetCell(Col, Row) != NULL)&&(GetCell(Col, Row)->UnionRect != NULL)) ret =true;
    return ret;
}

bool  TCellGrid::CellInRect(const TRect& rect, const TGridCoord& cell)
{
    bool ret=false;
    if (
    (cell.X>=rect.Left)&&
    (cell.X<=rect.Right)&&

    (cell.Y>=rect.Top)&&
    (cell.Y<=rect.Bottom)
    ) ret=true;
    return ret;
}

void  TCellGrid::SetDefaultCell11()
{
    NewCell(0,0);
    GetCell(0,0)->bgColor = clWhite;
    GetCell(0,0)->Text = "";
    NullLine(*GetCell(0,0));
    GetCell(0,0)->FontName ="Arial Cyr";
    GetCell(0,0)->CellFlags.FontSize = 10;
    GetCell(0,0)->FontColor =clBlack;

    NewCell(1,1);
    GetCell(1,1)->Assign(GetCell(0, 0));
}


