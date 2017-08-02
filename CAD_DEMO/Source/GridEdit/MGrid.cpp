//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include <Math.hpp>
#include "CellGrid.h"
#include "OffsetCellU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ----------- TMGrid ------------------
TMyObject* TMGrid::CreateFunction()
{
    return new TMGrid();
}

const AnsiString aCols = AnsiString("Cols");
const AnsiString aRows = AnsiString("Rows");
const AnsiString aCells = AnsiString("Cells");

TMGrid::TMGrid()
{
    RegisterNewClass<TMyObject,TMGrid>(this,false,&CreateFunction);
    RegisterField(&Cols,&aCols,mtMyObject);
    RegisterField(&Rows,&aRows,mtMyObject);
    RegisterField(&Cells,&aCells,mtMyObject);
    CutCells =false;
    CopyWidth =0;
    CopyHeight =0;
    iOffsetCell =0;
}

TMGrid::~TMGrid()
{
}

void __fastcall TMGrid::FromCellGrid(TCellGrid* CellGrid)
{
    for (int y=0; y<=CellGrid->EndColRowCell.y; y++)
        for (int x=0; x<=CellGrid->EndColRowCell.x; x++)
            if ( CellGrid->GetCellSimple(x,y) )
            {
                Cols.Add( new int(x) );
                Rows.Add( new int(y) );
                Cells.Add( (TCell*)CellGrid->GetCellSimple(x,y)->DynamicType->CreateFunction() );
                Cells.Last()->Assign( CellGrid->GetCellSimple(x,y) );
            }
}

void __fastcall TMGrid::ToCellGrid(TCellGrid* CellGrid)
{// чтение
    for (int i=0;i<Cols.Count;i++)
    {
        if ((Cols[i] ==0 && Rows[i] ==0)||
            (Cols[i] ==1 && Rows[i] ==1)
        )
        {// - Таблица
            CellGrid->DelCell(Cols[i],Rows[i]);
            CellGrid->NewCell(Cols[i],Rows[i],(TCellTab*)Cells.Items[i]);

            if (Cols[i] ==1 && Rows[i] ==1)
            {
                CellGrid->DefaultColWidth =((TCellTab*)Cells.Items[i])->ColWidth;
                CellGrid->DefaultRowHeight =((TCellTab*)Cells.Items[i])->RowHeight;
                CellGrid->VisibleOfficialMargin =true;
            }
        }
        else if (Cols[i] >1 && Rows[i] ==1)
        { // - Столбцы
            CellGrid->DelCell(Cols[i],Rows[i]);
            CellGrid->NewCell(Cols[i],Rows[i],(TCellColRow*)Cells.Items[i]);
            CellGrid->SetColWidths(Cols[i], ((TCellColRow*)Cells.Items[i])->ColRowWidth);
        }
        else if (Cols[i] ==1 && Rows[i] >1)
        {// - Строки
            CellGrid->DelCell(Cols[i],Rows[i]);
            CellGrid->NewCell(Cols[i],Rows[i],(TCellColRow*)Cells.Items[i]);
            CellGrid->SetRowHeights(Rows[i], ((TCellColRow*)Cells.Items[i])->ColRowWidth);
        }
        else
        { // - Ячейки и секции
            if (Cols[i] ==0 && Rows[i] >1)// - Секция горизонтал на показ
                CellGrid->VisibleSectionLeft =true;

            if (Cols[i] >1 && Rows[i] ==0)// - Секция вертикал на показ
                CellGrid->VisibleSectionTop =true;

            CellGrid->DelCell(Cols[i],Rows[i]);
            CellGrid->NewCell(Cols[i],Rows[i],(TCell*)Cells.Items[i]);
        }
    }
    CellGrid->Invalidate();
}

void __fastcall TMGrid::CorrectionRect(TCellGrid* CellGrid, TRect& rect)
{
    if (rect.Left ==2 && rect.Right ==CellGrid->ColCount-1)
        rect.Left =1;
    if (rect.Top ==2 && rect.Bottom ==CellGrid->RowCount-1)
        rect.Top =1;
}

void __fastcall TMGrid::DelCells(TCellGrid* CellGrid, const TRect& rect)
{
    TRect rect2 =rect;
    CorrectionRect(CellGrid, rect2);
    bool bOK =true;

    TRect rectcopy =rect2;
    TRect rectclear =rect2;

    int iPasteX =0;
    int iPasteY =0;

    if (rect2.Left ==1 && rect2.Top ==1)
    {// - Таблица
        CellGrid->ClearSelectRect(TRect(1,1,CellGrid->EndColRowCell.x, CellGrid->EndColRowCell.y));
        bOK =false;
        CellGrid->Invalidate();
    }
    else if (rect2.Left >1 && rect2.Top ==1)
    { // - Столбец
        rectcopy.Left   =rect2.Right +1;
        rectcopy.Right  =CellGrid->EndColRowCell.x;
        rectcopy.Bottom =CellGrid->EndColRowCell.y;

        if (rectcopy.Left >rectcopy.Right)
            rectcopy.Right =rectcopy.Left;

        rectclear.Right =CellGrid->EndColRowCell.x;

        if (rectclear.Left >rectclear.Right)
        {
            bOK =false;
            rectclear.Left =rectclear.Right;
        }

        iPasteX =rect.Right -rect.Left+1;
        iPasteY =0;
    }
    else if (rect2.Left ==1 && rect2.Top >1)
    { // - Строка
        rectcopy.Top    =rect2.Bottom +1;
        rectcopy.Bottom =CellGrid->EndColRowCell.y;
        rectcopy.Right  =CellGrid->EndColRowCell.x;

        if (rectcopy.Top >rectcopy.Bottom)
            rectcopy.Bottom =rectcopy.Top;

        rectclear.Bottom =CellGrid->EndColRowCell.y;

        if (rectclear.Top >rectclear.Bottom)
        {
            bOK =false;
            rectclear.Top =rectclear.Bottom;
        }

        iPasteX =0;
        iPasteY =rect.Bottom -rect.Top+1;
    }
    else if (rect2.Left >1 && rect2.Top >1)
    { // - Ячейка
        OffsetCell =new TOffsetCell(NULL, this);
        OffsetCell->ShowModal();
        delete OffsetCell;
        OffsetCell =NULL;

        if (iOffsetCell ==0)
        {// Сдвиг вверх
            rectcopy.Top    =rect2.Bottom +1;
            rectcopy.Bottom =CellGrid->EndColRowCell.y;

            rectclear.Bottom =CellGrid->EndColRowCell.y;

            iPasteX =0;
            iPasteY =rect.Bottom -rect.Top+1;
        }
        else if (iOffsetCell ==1)
        {// Сдвиг влево
            rectcopy.Left   =rect2.Right +1;
            rectcopy.Right  =CellGrid->EndColRowCell.x;

            rectclear.Right =CellGrid->EndColRowCell.x;

            iPasteX =rect.Right -rect.Left+1;
            iPasteY =0;
        }

        if (rectcopy.Top >rectcopy.Bottom)
            rectcopy.Bottom =rectcopy.Top;

        if (rectcopy.Left >rectcopy.Right)
            rectcopy.Right =rectcopy.Left;

        if (rectclear.Top >rectclear.Bottom)
            rectclear.Bottom =rectclear.Top;

        if (rectclear.Left >rectclear.Right)
            rectclear.Left =rectclear.Right;
    }
    if (bOK && iOffsetCell !=-1)
    {
        // Copy
        dCopyCellGrid(CellGrid, rectcopy);

        // Clear
        CellGrid->ClearSelectRect(rectclear);

        // Paste
        dPasteToCellGrid(CellGrid, iPasteX, iPasteY);
    }
    iOffsetCell =0;
}

void __fastcall TMGrid::dCopyCellGrid(TCellGrid* CellGrid, const TRect& RectCopy)
{
    Cols.Clear();
    Rows.Clear();
    Cells.Clear();
    TRect rect =RectCopy;

    TCell* Cell;
    for (int y=rect.Top; y<=rect.Bottom; y++)
        for (int x=rect.Left; x<=rect.Right; x++)
        {
            Cell =CellGrid->GetCellSimple(x,y);
            if (Cell !=NULL)
            {
                if (rect.Left ==1)
                {// Строка
                    if (Cell->UnionRect !=NULL)
                    {
                        if (Cell->UnionRect->Top <rect.Top)
                            if (Cell->UnionRect->Top ==Cell->UnionRect->Bottom)
                            {
                                delete Cell->UnionRect;
                                Cell->UnionRect =NULL;
                            }
                            else
                                Cell->UnionRect->Top =rect.Top;
                    }
                }
                else if (rect.Top ==1)
                {// Столбец
                    if (Cell->UnionRect !=NULL)
                    {
                        if (Cell->UnionRect->Left <rect.Left)
                            if (Cell->UnionRect->Left ==Cell->UnionRect->Right)
                            {
                                delete Cell->UnionRect;
                                Cell->UnionRect =NULL;
                            }
                            else
                                Cell->UnionRect->Left =rect.Left;
                    }
                }
                else if (rect.Top >1 && rect.Left >1)
                {// Ячейка
                    if (Cell->UnionRect !=NULL)
                    {
                        if (iOffsetCell ==0)
                        {// Сдвиг в верх
                            if (!CellGrid->Rect1InRect2(*Cell->UnionRect, TRect(RectCopy.Left,RectCopy.Top-1,RectCopy.Right,RectCopy.Bottom)))
                            {
                                CellGrid->DeleteUnionRect(Cell);
                                Cell =CellGrid->GetCellSimple(x,y);
                            }
                            else if (Cell->UnionRect->Top <rect.Top)
                                if (Cell->UnionRect->Top ==Cell->UnionRect->Bottom)
                                {
                                    delete Cell->UnionRect;
                                    Cell->UnionRect =NULL;
                                }
                                else
                                    Cell->UnionRect->Top =rect.Top;
                        }
                        if (iOffsetCell ==1)
                        {// Сдвиг в влево
                            if (!CellGrid->Rect1InRect2(*Cell->UnionRect, TRect(RectCopy.Left-1,RectCopy.Top,RectCopy.Right,RectCopy.Bottom)))
                            {
                                CellGrid->DeleteUnionRect(Cell);
                                Cell =CellGrid->GetCellSimple(x,y);
                            }
                            else if (Cell->UnionRect->Left <rect.Left)
                            {
                                if (Cell->UnionRect->Left ==Cell->UnionRect->Right)
                                {
                                    delete Cell->UnionRect;
                                    Cell->UnionRect =NULL;
                                }
                                else
                                    Cell->UnionRect->Left =rect.Left;
                            }
                        }
                    }
                }
                if (Cell !=NULL)
                {
                    Cols.Add( new int(x) );
                    Rows.Add( new int(y) );

                    Cells.Add( (TCell*)Cell->DynamicType->CreateFunction());
                    Cells.Last()->Assign(Cell );
                }
            }
        }
    Cell =NULL;
}

void __fastcall TMGrid::dPasteToCellGrid(TCellGrid* CellGrid, int DeltaX, int DeltaY)
{
    int Col,Row;
    bool bError =false;
    int iEnd    =Cols.Count;

    TMDelTList <TPoint> delpoint;
    for (int i=0; i<iEnd && !bError; i++)
    {
        Col =Cols[i] -DeltaX;
        Row =Rows[i] -DeltaY;

        CellGrid->NewCell(Col,Row,(TCell*)Cells.Items[i]);
        TCell* Cell =CellGrid->GetCellSimple(Col, Row);
        if (Cell->UnionRect !=NULL )
        {
            Cell->UnionRect->Left      -=DeltaX;
            Cell->UnionRect->Right     -=DeltaX;
            Cell->UnionRect->Top       -=DeltaY;
            Cell->UnionRect->Bottom    -=DeltaY;

            for (int i=Cell->UnionRect->Top; i<=Cell->UnionRect->Bottom; i++)
            {
                TCell* SectH =CellGrid->GetCellSimple(0, Row);
                if (SectH !=NULL && SectH->UnionRect !=NULL)
                {
                    TRect rects =TRect(0, SectH->UnionRect->Top, CellGrid->ColCount, SectH->UnionRect->Bottom);
                    if (!CellGrid->Rect1InRect2(*Cell->UnionRect,rects) &&
                        CellGrid->Rect1CrossRect2(*Cell->UnionRect,rects)
                    )
                        delpoint.Add(new TPoint(Cell->UnionRect->Left,Cell->UnionRect->Top));

                }
            }
            for (int i=Cell->UnionRect->Left; i<=Cell->UnionRect->Right; i++)
            {
                TCell* SectW =CellGrid->GetCellSimple(Col, 0);
                if (SectW !=NULL && SectW->UnionRect !=NULL)
                {
                    TRect rects =TRect(SectW->UnionRect->Left,0, SectW->UnionRect->Right,CellGrid->RowCount);
                    if (!CellGrid->Rect1InRect2(*Cell->UnionRect,rects) &&
                        CellGrid->Rect1CrossRect2(*Cell->UnionRect,rects)
                    )
                        delpoint.Add(new TPoint(Cell->UnionRect->Left,Cell->UnionRect->Top));

                }
            }
        }

        if (Cols[i] ==Cols[0] &&
            Cells.Items[i]->Line.WidthLeft >0 &&
            Col-1 >1 &&
            CellGrid->GetCellSimple(Col-1,Row) !=NULL
        )// - Left
            CellGrid->GetCellSimple(Col-1,Row)->Line.WidthRight =Cells.Items[i]->Line.WidthLeft;

        if (Rows[i] ==Rows[0] &&
            Cells.Items[i]->Line.WidthTop >0 &&
            Row-1 >1 &&
            CellGrid->GetCellSimple(Col,Row-1) !=NULL
        )// - Top
            CellGrid->GetCellSimple(Col,Row-1)->Line.WidthBottom =Cells.Items[i]->Line.WidthTop;

        if (Cols[i] ==Cols[iEnd-1] &&
            Cells.Items[i]->Line.WidthRight >0 &&
            CellGrid->GetCellSimple(Col+1,Row) !=NULL
        )// - Right
            CellGrid->GetCellSimple(Col+1,Row)->Line.WidthLeft =Cells.Items[i]->Line.WidthRight;

        if (Rows[i] ==Rows[iEnd-1] &&
            Cells.Items[i]->Line.WidthBottom >0 &&
            CellGrid->GetCellSimple(Col,Row+1) !=NULL
        )// - Right
            CellGrid->GetCellSimple(Col,Row+1)->Line.WidthTop =Cells.Items[i]->Line.WidthBottom;

    }
    if (delpoint.Count >0)
    {
        for (int i=0; i<delpoint.Count; i++)
        {
            TCell* Celld =CellGrid->GetCellSimple(delpoint[i].x,delpoint[i].y);
            if (Celld !=NULL && Celld->UnionRect !=NULL)
                    CellGrid->SetUnionCell(*Celld->UnionRect,false);
        }
        delpoint.Clear();
    }

    CellGrid->Invalidate();
}

void __fastcall TMGrid::DelTextToCellGrid(TCellGrid* CellGrid)
{
    CellGrid->GetSelectCells(true);
    int iEnd =CellGrid->ListFilling.Count;
    for (int i=0; i<iEnd; i++)
        if (CellGrid->GetCellSimple(CellGrid->ListFilling[i].x,CellGrid->ListFilling[i].y) !=NULL)
            CellGrid->GetCellSimple(CellGrid->ListFilling[i].x,CellGrid->ListFilling[i].y)->Text ="";

    CellGrid->Invalidate();
}
//======================================



