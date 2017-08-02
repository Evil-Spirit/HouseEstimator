//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "CellGrid.h"
#include "SectionDialogU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSectionDialog *SectionDialog;
//---------------------------------------------------------------------------
__fastcall TSectionDialog::TSectionDialog(TComponent* Owner,TCellGrid* _CellGrid)
    : TForm(Owner)
{
    CellGrid = _CellGrid;
    TRect AncrCurr = CellGrid->GetAnchorCurrentSort();

// --------- Корректировка если выделены полностью (Строка, Столбец, Таблица)
    if (CellGrid->SelectColumn)
        AncrCurr.Top =1;
    if (CellGrid->SelectString)
        AncrCurr.Left =1;
    if (CellGrid->SelectTable)
    {
        AncrCurr.Top =1;
        AncrCurr.Left =1;
    }
// --------- Корректировка если выделены полностью (Строка, Столбец, Таблица) End

    if (AncrCurr.Left ==1)
    {// Горизонтальная секция
        Edit1->Text = "Line " + IntToStr(AncrCurr.Top);
    } else
    if (AncrCurr.Top ==1)
    {// Вертикальная секция
        Edit1->Text = "Column " + IntToStr(AncrCurr.Left);
    }

}
//---------------------------------------------------------------------------
void __fastcall TSectionDialog::Button2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TSectionDialog::Button1Click(TObject *Sender)
{
    TRect AncrCurr = CellGrid->GetAnchorCurrentSort();
    int StartX =AncrCurr.Left;
    int StartY =AncrCurr.Top;
    int EndX =AncrCurr.Right;
    int EndY =AncrCurr.Bottom;

// --------- Корректировка если выделены полностью (Строка, Столбец, Таблица)
    if (CellGrid->SelectColumn)
        AncrCurr.Top =1;
    if (CellGrid->SelectString)
        AncrCurr.Left =1;
    if (CellGrid->SelectTable)
    {
        AncrCurr.Top =1;
        AncrCurr.Left =1;
    }
// --------- Корректировка если выделены полностью (Строка, Столбец, Таблица) End
    StartX =AncrCurr.Left;
    StartY =AncrCurr.Top;

    if (Edit1->Text.Length() >0)
    if (AncrCurr.Left ==1)
    {// Горизонтальная секция
        int x=0;
        bool BeSection = false;
        bool BeSection2 = false;

        for (int y=StartY; y<=EndY; y++)
        {
            if (CellGrid->GetCellSimple(x,y) != NULL)
                BeSection2 = true;

            if (BeSection2)
            {// Секция существует и её надо удалить
                BeSection2  = false;
                int Start   =CellGrid->GetCell(x,y)->UnionRect->Top;
                int End     =CellGrid->GetCell(x,y)->UnionRect->Bottom;
                for (int i=Start; i<=End; i++)
                {
                    if (i == End)
                    {
                        CellGrid->DelCell(x,i);
                        BeSection = true;
                    }
                    else if (CellGrid->GetCellSimple(x,i) != NULL)
                        CellGrid->SetNewCell(x,i,NULL);

                }
                bool NotSection=true;
                for (int i=2;(i<CellGrid->RowCount && NotSection); i++)
                {
                    if (CellGrid->GetCellSimple(x,i) !=NULL) NotSection=false;
                }
                if (NotSection) CellGrid->VisibleSectionLeft =false;
            }
        }
        if (!BeSection)
        {
            for (int y=StartY; y<=EndY; y++)
            {// Создать секцию

                if (CellGrid->GetCellSimple(x,y) == NULL)
                    CellGrid->NewCell(x,y);
                if (CellGrid->GetCellSimple(x,y)->UnionRect == NULL)
                    CellGrid->GetCellSimple(x,y)->UnionRect = new TRect();

                CellGrid->GetCellSimple(x,y)->UnionRect->Top = StartY;
                CellGrid->GetCellSimple(x,y)->UnionRect->Bottom = EndY;
                CellGrid->GetCellSimple(x,y)->UnionRect->Left = x;
                CellGrid->GetCellSimple(x,y)->UnionRect->Right = x;

                CellGrid->GetCellSimple(x,y)->Text = Edit1->Text;
            }
            CellGrid->VisibleSectionLeft =true;
        }
    }
    else
    if (AncrCurr.Top ==1)
    {// Вертикальная секция
        int y=0;
        bool BeSection = false;
        bool BeSection2 = false;

        for (int x=StartX; x<=EndX; x++)
        {
            if (CellGrid->GetCellSimple(x,y) != NULL) BeSection2 = true;

            if (BeSection2)
            {// Секция существует и её надо удалить
                BeSection2 = false;
                int Start =CellGrid->GetCell(x,y)->UnionRect->Left;
                int End =CellGrid->GetCell(x,y)->UnionRect->Right;
                for (int i=Start; i<=End; i++)
                {
                    if (i == End)
                    {
                        CellGrid->DelCell(i,y);
                        BeSection = true;
                    }
                    else if (CellGrid->GetCellSimple(i,y) != NULL)
                        CellGrid->SetNewCell(i,y,NULL);
                }
                bool NotSection=true;
                for (int i=2;(i<CellGrid->ColCount && NotSection); i++)
                {
                    if (CellGrid->GetCellSimple(i,y) !=NULL) NotSection=false;
                }
                if (NotSection) CellGrid->VisibleSectionTop =false;
            }
        }
        if (!BeSection)
        {
            for (int x=StartX; x<=EndX; x++)
            {
                if (CellGrid->GetCellSimple(x,y) == NULL) CellGrid->NewCell(x,y);
                if (CellGrid->GetCellSimple(x,y)->UnionRect == NULL) CellGrid->GetCellSimple(x,y)->UnionRect = new TRect();

                CellGrid->GetCellSimple(x,y)->UnionRect->Top = y;
                CellGrid->GetCellSimple(x,y)->UnionRect->Bottom = y;
                CellGrid->GetCellSimple(x,y)->UnionRect->Left = StartX;
                CellGrid->GetCellSimple(x,y)->UnionRect->Right = EndX;

                CellGrid->GetCellSimple(x,y)->Text = Edit1->Text;
            }
            CellGrid->VisibleSectionTop =true;
        }
    }

    Button2Click(Sender);
}
//---------------------------------------------------------------------------
