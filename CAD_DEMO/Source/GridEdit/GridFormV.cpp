//---------------------------------------------------------------------------
#include<vcl.h>

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#pragma hdrstop

#include "GridFormV.h"
#include "CellGrid.h"
#include "TextEditU.h"
#include "SelectColorU.h"
#include "ImagesU.h"
#include "SelectBorderU.h"
#include "ToolBarCellGrid.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CellGrid"
#pragma resource "*.dfm"
TGridForm *GridForm;


//---------------------------------------------------------------------------
int CALLBACK GetFontToMashine(LOGFONT* lplf, TEXTMETRIC* lptm, DWORD dwType, LPARAM lpData);

__fastcall TGridForm::TGridForm(TComponent* Owner)
    : TForm(Owner)
{

    TMyRegObject OBJ;
    ToolBarCellGrid =new TToolBarCellGrid(this,this);

   CellGrid1 =NULL;

    CellGrid1 = new TCellGrid(this, GridForm,ToolBarCellGrid);
//    CellGrid1->DoubleBuffered = true;
    CellGrid1->Parent           =this;
    CellGrid1->Align            =alNone;
    CellGrid1->Top              =25;
    CellGrid1->Left             =0;
    CellGrid1->Width            =Screen->Width;
    CellGrid1->Height           =600;
    CellGrid1->ColCount         =256;
    CellGrid1->RowCount         =65000;
    CellGrid1->DefaultRowHeight =16;
    CellGrid1->DefaultColWidth  =64;
    CellGrid1->FixedCols        =2;
    CellGrid1->FixedRows        =2;
    CellGrid1->Visible          =true;

    CellGrid1->VisibleOfficialMargin    =true;
    CellGrid1->VisibleSectionLeft       =false;
    CellGrid1->VisibleSectionTop        =false;
    CellGrid1->PopupMenu                =PopupMenuCellGrid;
    CellGrid1->Options << goRowSizing;
    CellGrid1->Options << goColSizing;

    CellGrid1->SetDefaultCell11();

    CellGrid1->Invalidate();
    CellGrid1->StartVisible =true;
}
//---------------------------------------------------------------------------
void __fastcall TGridForm::CellGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
}
//---------------------------------------------------------------------------
void __fastcall TGridForm::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if ((ACol>0)&&(ARow>0))
    {
//        CellGrid1->SetNumerColRow(ACol,ARow,1, clWhite);
    }
}
//---------------------------------------------------------------------------

void __fastcall TGridForm::Button5Click(TObject *Sender)
{
    int Start = GetTickCount();
    for (int i=0; i<100; i++)
    {
        CellGrid1->Paint();
    }

    int End = GetTickCount()-Start;
    ShowMessage(IntToStr(End));
    CellGrid1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TGridForm::FormActivate(TObject *Sender)
{

    if (CellGrid1 !=NULL && !CellGrid1->Focused )
        ::SetFocus(CellGrid1->Handle);
}
//---------------------------------------------------------------------------
void __fastcall TGridForm::Button8Click(TObject *Sender)
{
    CellGrid1->DoModalFormSection();
}
//---------------------------------------------------------------------------
void __fastcall TGridForm::Button1Click(TObject *Sender)
{
    if (CellGrid1 !=NULL)
    {
        delete CellGrid1;
        CellGrid1 =NULL;
    }
    else
    {

        CellGrid1 = new TCellGrid(this, GridForm,ToolBarCellGrid);
        CellGrid1->Parent = this;
        CellGrid1->Align = alNone;
        CellGrid1->Top =25;
        CellGrid1->Left =0;
        CellGrid1->Width=Screen->Width;
        CellGrid1->Height = 600;
        CellGrid1->ColCount =256;
        CellGrid1->RowCount =65000;
        CellGrid1->DefaultRowHeight = 16;
        CellGrid1->DefaultColWidth = 64;
        CellGrid1->FixedCols =2;
        CellGrid1->FixedRows =2;
        CellGrid1->Visible = true;
        CellGrid1->Options << goRowSizing;
        CellGrid1->Options << goColSizing;
        CellGrid1->VisibleOfficialMargin = true;
        CellGrid1->VisibleSectionLeft = false;
        CellGrid1->VisibleSectionTop = false;
        CellGrid1->SetDefaultCell11();
        CellGrid1->PopupMenu =PopupMenuCellGrid;
        CellGrid1->Invalidate();
        CellGrid1->StartVisible =true;

    }
}
//---------------------------------------------------------------------------
TCellGrid* FindGrid()
{
    if (!Application->MainForm)
        return NULL;
    else
        return (TCellGrid*)ComponentExists(__classid(TCellGrid),Application->MainForm);
}

void __fastcall TGridForm::ApplicationEvents1Idle(TObject *Sender,
      bool &Done)
{

    TCellGrid* CG = FindGrid();
    if (CG)
    {
        ToolBarCellGrid->Visible = true;
        ToolBarCellGrid->SetDownToolBar(CG);
    }
    else
        ToolBarCellGrid->Visible = false;
    Done = true;

}
//---------------------------------------------------------------------------

void __fastcall TGridForm::Button2Click(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        TMGrid MGrid;
        MGrid.FromCellGrid(CellGrid1);
        MGrid.Write("Check.txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TGridForm::Button3Click(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        TMGrid MGrid;
        MGrid.Read("Check.txt");
        MGrid.ToCellGrid( CellGrid1 );
    }
}
//---------------------------------------------------------------------------


void __fastcall TGridForm::Button4Click(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        TMGrid MGrid;
        MGrid.FromCellGrid(CellGrid1);
        MGrid.Save("CheckText.txt");
    }
}
//---------------------------------------------------------------------------

void __fastcall TGridForm::Button6Click(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        TMGrid MGrid;
        MGrid.Load("CheckText.txt");
        MGrid.ToCellGrid(CellGrid1);
    }
}
//---------------------------------------------------------------------------

bool focus=false;
int iIndex=0;
void __fastcall TGridForm::Button9Click(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
//        TRect rect =CellGrid1->GetGridRectToRectPixelNotUnionAndScroll(6,178);
//        Label1->Caption ="Col: " + IntToStr(rect.Left) + " - Row: " + IntToStr(rect.Top);
        CellGrid1->Test_Speed();
    }
}
//---------------------------------------------------------------------------
void __fastcall TGridForm::EditCutExecute(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        CellGrid1->Matrix->FieldCut =true;
        CellGrid1->CopyInBuff(CellGrid1->GetSelectGridRect());
    }
}
//---------------------------------------------------------------------------

void __fastcall TGridForm::EditCopyExecute(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        CellGrid1->CopyInBuff(CellGrid1->GetSelectGridRect());
    }
}
//---------------------------------------------------------------------------

void __fastcall TGridForm::EditPasteExecute(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        int startx =CellGrid1->FCurrent.X;
        int starty =CellGrid1->FCurrent.Y;
        if (CellGrid1->FCurrent.Y ==2 && CellGrid1->FAnchor.Y == CellGrid1->RowCount)
            starty =1;
        if (CellGrid1->FCurrent.X ==2 && CellGrid1->FAnchor.X == CellGrid1->ColCount)
            startx =1;

        CellGrid1->Matrix->CopyCell =true;
        CellGrid1->PasteBuffInGrid(startx,starty);
        CellGrid1->Invalidate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TGridForm::EditSelectAllExecute(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        CellGrid1->SelectAllCells();
    }
}
//---------------------------------------------------------------------------

void __fastcall TGridForm::EditDeleteExecute(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        MClipBoard.DelCells(CellGrid1,
        TRect(CellGrid1->FCurrent.X,CellGrid1->FCurrent.Y, CellGrid1->FAnchor.X, CellGrid1->FAnchor.Y));
    }
}
//---------------------------------------------------------------------------
void __fastcall TGridForm::EditClearExecute(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        CellGrid1->ClearSelectRect();
        CellGrid1->Invalidate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TGridForm::EditFormatCellExecute(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        CellGrid1->DoModalFormCellParameter();
    }
}
//---------------------------------------------------------------------------


void __fastcall TGridForm::Button7Click(TObject *Sender)
{
    if (CellGrid1->FixedCols ==2)
    {
        CellGrid1->FixedCols =4;
        CellGrid1->FixedRows =5;
    }
    else
    {
        CellGrid1->FixedCols =2;
        CellGrid1->FixedRows =2;
    }
}
//---------------------------------------------------------------------------
void __fastcall TGridForm::Button10Click(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    int Start;
    int End;
    if (CellGrid1 !=NULL)
    {
        CellGrid1->InvalidateRect2(TRect(5,65000-1,7,65000));
//        CellGrid1->Invalidate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TGridForm::PopupMenuCellGridPopup(TObject *Sender)
{
    TCellGrid* CellGrid1 =FindGrid();
    if (CellGrid1 !=NULL)
    {
        CellGrid1->PopupMenuNotMouseUp =true;
    }
}
//---------------------------------------------------------------------------

