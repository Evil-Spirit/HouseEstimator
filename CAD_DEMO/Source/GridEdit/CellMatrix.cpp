//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include <Math.hpp>
#include "CellGrid.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TCellMatrix::TCellMatrix(Classes::TComponent* AOwner, TCellGrid* _CellGrid)
    :TMyDrawGrid(AOwner)
{
    FData =NULL;
    Initialize();
    CellGrid    =_CellGrid;
    gCellFlag   =new TCellFlag();
    EndCell.X   =0;
    EndCell.Y   =0;
    FieldCut    =false;
    CopyCell    =false;
    CellGrid->NullRect(RectCopy);
}

inline __fastcall TCellMatrix::~TCellMatrix(void)
{
    delete gCellFlag;
    gCellFlag =NULL;
    ClearAll();
    delete ((TSparseList*)FData);
}


void __fastcall TCellMatrix::ClearAll()
{
    MatrixForAllTest();
    TSparseList* SL = ((TSparseList*)FData);
    for ( int i=0; i<RowCount; i++ )
        if ( SL->Items[i] )
        {
            delete ((TSparseList*)SL->Items[i]);
            SL->Items[i] = NULL;
        }

    EndCell.X =0;
    EndCell.Y =0;
}

void TCellMatrix::Initialize()
{
    if (!FData)
        FData = new TSparseList( (RowCount > 256) ? SPALarge : SPASmall );
}

void* __fastcall TCellMatrix::EnsureDataRow(int aRow)
{
    if ( !((TSparseList*)FData)->Items[aRow] )
        ((TSparseList*)FData)->Items[aRow] = new TCellList( (RowCount > 256) ? SPALarge : SPASmall ) ;
    return ((TSparseList*)FData)->Items[aRow];
}

int __fastcall TCellMatrix::ProcessMx(int Col, int Row, void * TheItem)
{
    TCellFlag* Cell =(TCellFlag*)TheItem;
    if (Cell !=NULL)
        DelCell(Col,Row);

    return 0;
}

void  __fastcall TCellMatrix::MatrixForAllTest()
{
    FForAll(TRect(0,0,ColCount,RowCount),ProcessMx);
}

void __fastcall TCellMatrix::FForAll(TRect& rect, TMyFunc Func)
{
    ((TSparseList*)FData)->SForAll(rect,Func);
}

void __fastcall TCellMatrix::SetCell(int aCol, int aRow, TCellFlag* data)
{
    ((TSparseList*)EnsureDataRow(aRow))->Items[aCol] = data;
}

void __fastcall TCellMatrix::NewCell(int Col, int Row, TCellFlag* data)
{
    SetCell(Col, Row, data);
    if (EndCell.X <Col)
        EndCell.X =Col;
    if (EndCell.Y <Row)
        EndCell.Y =Row;
}

void __fastcall TCellMatrix::NewCell(int Col, int Row)
{
    NewCell(Col, Row, new TCellFlag);
}

void __fastcall TCellMatrix::DelCell(int Col, int Row)
{
    if (GetCellSimple(Col,Row) !=NULL)
    {
        if (GetCellSimple(Col,Row)->UnionRect != NULL)
        {
            delete ((TRect*)GetCellSimple(Col,Row)->UnionRect);
            GetCellSimple(Col,Row)->UnionRect = NULL;
        }
        TCellFlag* _Cell = GetCellSimple(Col,Row);
        delete _Cell;
        NewCell(Col,Row,NULL);
    }
}

TCellFlag* __fastcall TCellMatrix::GetCell(int Col, int Row)
{
    TCellFlag* Cell =GetCellSimple(Col, Row);
    if (Cell != NULL && Cell->UnionRect != NULL)
        Cell = GetCellSimple(Cell->UnionRect->Left, Cell->UnionRect->Top);
    return Cell;
}

TCellFlag* __fastcall TCellMatrix::GetCellSimple(int Col, int Row)
{
    if ( !((TSparseList*)FData)->Items[Row] )
        return NULL;
    else
        return (TCellFlag*)((TSparseList*)EnsureDataRow(Row))->Items[Col];
}

void __fastcall TCellMatrix::SetAllFlag(TCellFlag* CellFlag, bool Set)
{
    CellFlag->UnionCell.Left    =0;
    CellFlag->UnionCell.Top     =0;
    CellFlag->UnionCell.Right   =0;
    CellFlag->UnionCell.Bottom  =0;

    CellFlag->Col               =0;
    CellFlag->Row               =0;
    CellFlag->ColWidth          =0;
    CellFlag->RowHeight         =0;

    CellFlag->f_ColWidth        =Set;
    CellFlag->f_Text            =Set;
    CellFlag->f_FontStyle       =Set;
    CellFlag->f_FontStrikeOut   =Set;
    CellFlag->f_FontSize        =Set;
    CellFlag->f_FontName        =Set;
    CellFlag->f_WidthTop        =Set;
    CellFlag->f_WidthRight      =Set;
    CellFlag->f_WidthLeft       =Set;
    CellFlag->f_WidthBottom     =Set;
    CellFlag->f_ValueType       =Set;
    CellFlag->f_TypeAutoSize    =Set;
    CellFlag->f_TextWordBreak   =Set;
    CellFlag->f_TextVAlign      =Set;
    CellFlag->f_TextHeightAuto  =Set;
    CellFlag->f_TextHAlign      =Set;
    CellFlag->f_LineColorNot    =Set;
    CellFlag->f_FontUnderline   =Set;
    CellFlag->f_FontColor       =Set;
    CellFlag->f_bgColor         =Set;
    CellFlag->f_Flood           =Set;
    CellFlag->f_UnionCell       =Set;
    CellFlag->f_SetUnion        =Set;
}

TCellFlag* __fastcall TCellMatrix::GetCellParam(int Col, int Row)
{ // Получить параметры ячейки
    TCellFlag* Cell;
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

void __fastcall TCellMatrix::CopyCell1ToCell2(int Col,int Row, TCellFlag* Cell2)
{// Копироватьь из Cell1 в Cell2
    TCellFlag* Cell1;
    if (GetCellSimple(Col,Row) ==NULL)
        Cell1 =GetCellParam(Col,Row);
    else
        Cell1 =GetCellSimple(Col,Row);

    Cell2->UnionRect    =NULL;
    Cell2->bgColor      =Cell1->bgColor;
    Cell2->LineColorNot =Cell1->LineColorNot;
    Cell2->Text         =Cell1->Text;
    Cell2->FontName     =Cell1->FontName;
    Cell2->FontColor    =Cell1->FontColor;
    Cell2->Line         =Cell1->Line;
    Cell2->CellFlags    =Cell1->CellFlags;
    Cell2->UnionCell    =Cell1->UnionCell;
}

TCellFlag* __fastcall TCellMatrix::GetParamCell(int Col, int Row)
{ // Получить ячейку со всеми параметрами
    SetAllFlag(gCellFlag,true);

    if (GetCellSimple(Col,Row) !=NULL)
        CopyCell1ToCell2(Col,Row,gCellFlag);
    else
    {
        if (GetCellSimple(1,Row) !=NULL)
            CopyCell1ToCell2(1,Row,gCellFlag);
        else if (GetCellSimple(Col,1) !=NULL)
            CopyCell1ToCell2(Col,1,gCellFlag);
        else if (GetCellSimple(1,1) !=NULL)
            CopyCell1ToCell2(1,1,gCellFlag);


        CopyCell1ToCell2(Col,Row,gCellFlag);

        TCell* Cell11 =GetCellSimple(1,1);
        // Таблица
        gCellFlag->Line.WidthLeft    =Cell11->Line.WidthLeft;
        gCellFlag->Line.WidthTop     =Cell11->Line.WidthTop;
        gCellFlag->Line.WidthRight   =Cell11->Line.WidthRight;
        gCellFlag->Line.WidthBottom  =Cell11->Line.WidthBottom;

        //Соседние Строки, Столбцы
        if (GetCellSimple(Col+1,1) !=NULL)// Left
            gCellFlag->Line.WidthRight =GetCellSimple(Col+1,1)->Line.WidthLeft;

        if (GetCellSimple(Col-1,1) !=NULL)// Right
            gCellFlag->Line.WidthLeft =GetCellSimple(Col-1,1)->Line.WidthRight;

        if (GetCellSimple(1,Row+1) !=NULL)// Left
            gCellFlag->Line.WidthBottom =GetCellSimple(1,Row+1)->Line.WidthTop;

        if (GetCellSimple(1,Row-1) !=NULL)// Right
            gCellFlag->Line.WidthTop =GetCellSimple(1,Row-1)->Line.WidthBottom;

        if (GetCellSimple(Col,1) !=NULL)
        {// Текущие Столбцы
            TCell* CellCol               =GetCellSimple(Col,1);
            gCellFlag->Line.WidthRight   =CellCol->Line.WidthRight;
            gCellFlag->Line.WidthLeft    =CellCol->Line.WidthLeft;
            gCellFlag->Line.WidthBottom  =CellCol->Line.WidthBottom;
            gCellFlag->Line.WidthTop     =CellCol->Line.WidthTop;
        }
        else if (GetCellSimple(1,Row) !=NULL)
        {// Текущие Строки
            TCell* CellRow               =GetCellSimple(1,Row);
            gCellFlag->Line.WidthRight   =CellRow->Line.WidthRight;
            gCellFlag->Line.WidthLeft    =CellRow->Line.WidthLeft;
            gCellFlag->Line.WidthBottom  =CellRow->Line.WidthBottom;
            gCellFlag->Line.WidthTop     =CellRow->Line.WidthTop;
        }

        // Соседние ячейки
        if (GetCellSimple(Col+1,Row) !=NULL)// Left
            gCellFlag->Line.WidthRight =GetCellSimple(Col+1,Row)->Line.WidthLeft;

        if (GetCellSimple(Col-1,Row) !=NULL)// Right
            gCellFlag->Line.WidthLeft =GetCellSimple(Col-1,Row)->Line.WidthRight;

        if (GetCellSimple(Col,Row+1) !=NULL)// Bottom
            gCellFlag->Line.WidthBottom =GetCellSimple(Col,Row+1)->Line.WidthTop;

        if (GetCellSimple(Col,Row-1) !=NULL)// Top
            gCellFlag->Line.WidthTop =GetCellSimple(Col,Row-1)->Line.WidthBottom;

        // Текущая ячейка
        if (GetCellSimple(Col,Row) !=NULL)
        {
            TCell* Cell =GetCellSimple(Col,Row);
            gCellFlag->Line.WidthRight   =Cell->Line.WidthRight;
            gCellFlag->Line.WidthLeft    =Cell->Line.WidthLeft;
            gCellFlag->Line.WidthBottom  =Cell->Line.WidthBottom;
            gCellFlag->Line.WidthTop     =Cell->Line.WidthTop;
        }
    }
    return gCellFlag;
}

TCellFlag* __fastcall TCellMatrix::GetParamCellAndFlag(int Col, int Row)
{ // Получить ячейку со всеми параметрами

    SetAllFlag(gCellFlag,false);
    if (GetCellSimple(Col,Row) !=NULL)
        CellGrid->CopyFlag1ToFlag2(GetCellSimple(Col,Row),gCellFlag);
    else
    {
        if (GetCellSimple(1,Row) !=NULL)
            CellGrid->CopyFlag1ToFlag2(GetCellSimple(1,Row),gCellFlag);
        else if (GetCellSimple(Col,1) !=NULL)
            CellGrid->CopyFlag1ToFlag2(GetCellSimple(Col,1),gCellFlag);
        else if (GetCellSimple(1,1) !=NULL)
            CellGrid->CopyFlag1ToFlag2(GetCellSimple(1,1),gCellFlag);

        TCell* Cell11 =GetCellSimple(1,1);
        // Таблица
        gCellFlag->Line.WidthLeft    =Cell11->Line.WidthLeft;
        gCellFlag->Line.WidthTop     =Cell11->Line.WidthTop;
        gCellFlag->Line.WidthRight   =Cell11->Line.WidthRight;
        gCellFlag->Line.WidthBottom  =Cell11->Line.WidthBottom;

        //Соседние Строки, Столбцы
        if (GetCellSimple(Col+1,1) !=NULL)// Left
            gCellFlag->Line.WidthRight =GetCellSimple(Col+1,1)->Line.WidthLeft;

        if (GetCellSimple(Col-1,1) !=NULL)// Right
            gCellFlag->Line.WidthLeft =GetCellSimple(Col-1,1)->Line.WidthRight;

        if (GetCellSimple(1,Row+1) !=NULL)// Left
            gCellFlag->Line.WidthBottom =GetCellSimple(1,Row+1)->Line.WidthTop;

        if (GetCellSimple(1,Row-1) !=NULL)// Right
            gCellFlag->Line.WidthTop =GetCellSimple(1,Row-1)->Line.WidthBottom;

        if (GetCellSimple(Col,1) !=NULL)
        {// Текущие Столбцы
            TCell* CellCol               =GetCellSimple(Col,1);
            gCellFlag->Line.WidthRight   =CellCol->Line.WidthRight;
            gCellFlag->Line.WidthLeft    =CellCol->Line.WidthLeft;
            gCellFlag->Line.WidthBottom  =CellCol->Line.WidthBottom;
            gCellFlag->Line.WidthTop     =CellCol->Line.WidthTop;
        }
        else if (GetCellSimple(1,Row) !=NULL)
        {// Текущие Строки
            TCell* CellRow               =GetCellSimple(1,Row);
            gCellFlag->Line.WidthRight   =CellRow->Line.WidthRight;
            gCellFlag->Line.WidthLeft    =CellRow->Line.WidthLeft;
            gCellFlag->Line.WidthBottom  =CellRow->Line.WidthBottom;
            gCellFlag->Line.WidthTop     =CellRow->Line.WidthTop;
        }

        // Соседние ячейки
        if (GetCellSimple(Col+1,Row) !=NULL)// Left
            gCellFlag->Line.WidthRight =GetCellSimple(Col+1,Row)->Line.WidthLeft;

        if (GetCellSimple(Col-1,Row) !=NULL)// Right
            gCellFlag->Line.WidthLeft =GetCellSimple(Col-1,Row)->Line.WidthRight;

        if (GetCellSimple(Col,Row+1) !=NULL)// Bottom
            gCellFlag->Line.WidthBottom =GetCellSimple(Col,Row+1)->Line.WidthTop;

        if (GetCellSimple(Col,Row-1) !=NULL)// Top
            gCellFlag->Line.WidthTop =GetCellSimple(Col,Row-1)->Line.WidthBottom;

    }
    return gCellFlag;
}


