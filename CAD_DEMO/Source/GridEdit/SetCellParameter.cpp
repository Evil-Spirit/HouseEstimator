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
void __fastcall TCellGrid::SetVisibleSectionLeft(bool Visible)
{
    if (Visible)
        SetColWidths(0,60);
    else
        SetColWidths(0,0);

    InvalidateU2();
}

void __fastcall TCellGrid::SetVisibleSectionTop(bool Visible)
{
    if (Visible)
        SetRowHeights(0,20);
    else
        SetRowHeights(0,0);

    InvalidateU2();
}

bool __fastcall TCellGrid::GetVisibleOfficialMargin()
{
    bool bol;
    if (GetColWidths(1) == 0)
        bol = false;
    else
        bol = true;
    return bol;
}

void __fastcall TCellGrid::SetVisibleOfficialMargin(bool Visible)
{
    if (Visible)
    {
        bool NotSection=true;
        int x=0;
        for (int i=2;(i<RowCount && NotSection); i++)
        {
            if (GetCellSimple(x,i) !=NULL) NotSection=false;
        }
        if (NotSection)
            VisibleSectionLeft =false;
        else
            VisibleSectionLeft =true;

        int y=0;
        NotSection =true;
        for (int i=2;(i<ColCount && NotSection); i++)
        {
            if (GetCellSimple(i,y) !=NULL) NotSection=false;
        }
        if (NotSection)
            VisibleSectionTop =false;
        else
            VisibleSectionTop =true;

        SetColWidths(1,40);
        SetRowHeights(1,20);
    } else
    {
        SetColWidths(0,0);
        SetColWidths(1,0);
        SetRowHeights(0,0);
        SetRowHeights(1,0);
    }
    InvalidateU2();
}

bool __fastcall TCellGrid::GetVisibleSectionLeft()
{
    bool bol;
    if (GetColWidths(0) == 0) bol = false; else bol = true;
    return bol;
}

bool __fastcall TCellGrid::GetVisibleSectionTop()
{
    return (GetRowHeights(0) != 0);
}

bool __fastcall TCellGrid::ParamCellCompare(TCell* Cell, TCellFlag* CellFlag)
{// Праверка нужных параметров
    bool IsEqual = true;
    if (IsEqual && CellFlag->f_UnionCell)
        IsEqual = false;
    if (IsEqual && CellFlag->f_Text)
        IsEqual = IsEqual && Cell->Text == CellFlag->Text;
    if (IsEqual && CellFlag->f_bgColor)
        IsEqual = IsEqual && Cell->bgColor == CellFlag->bgColor;
    if (IsEqual && CellFlag->f_FontColor)
        IsEqual = IsEqual && Cell->FontColor == CellFlag->FontColor;
    if (IsEqual && CellFlag->f_FontName)
        IsEqual = IsEqual && Cell->FontName == CellFlag->FontName;
    if (IsEqual && CellFlag->f_FontSize)
        IsEqual = IsEqual && Cell->CellFlags.FontSize == CellFlag->CellFlags.FontSize;
    if (IsEqual && CellFlag->f_FontStrikeOut)
        IsEqual = IsEqual && Cell->CellFlags.FontStrikeOut == CellFlag->CellFlags.FontStrikeOut;
    if (IsEqual && CellFlag->f_FontStyle)
        IsEqual = IsEqual && Cell->CellFlags.FontStyle == CellFlag->CellFlags.FontStyle;
    if (IsEqual && CellFlag->f_FontUnderline)
        IsEqual = IsEqual && Cell->CellFlags.FontUnderline ==CellFlag->CellFlags.FontUnderline;
    if (IsEqual && CellFlag->f_LineColorNot)
        IsEqual = IsEqual && Cell->LineColorNot ==CellFlag->LineColorNot;
    if (IsEqual && CellFlag->f_TextHAlign)
        IsEqual = IsEqual && Cell->CellFlags.TextHAlign ==CellFlag->CellFlags.TextHAlign;
    if (IsEqual && CellFlag->f_TextHeightAuto)
        IsEqual = IsEqual && Cell->CellFlags.TextHeightAuto ==CellFlag->CellFlags.TextHeightAuto;
    if (IsEqual && CellFlag->f_TextVAlign)
        IsEqual = IsEqual && Cell->CellFlags.TextVAlign ==CellFlag->CellFlags.TextVAlign;
    if (IsEqual && CellFlag->f_TextWordBreak)
        IsEqual = IsEqual && Cell->CellFlags.TextWordBreak ==CellFlag->CellFlags.TextWordBreak;
    if (IsEqual && CellFlag->f_TypeAutoSize)
        IsEqual =IsEqual && Cell->CellFlags.TypeAutoSize ==CellFlag->CellFlags.TypeAutoSize;
    if (IsEqual && CellFlag->f_ValueType)
        IsEqual = IsEqual && Cell->CellFlags.ValueType ==CellFlag->CellFlags.ValueType;
    if (IsEqual && CellFlag->f_WidthBottom)
        IsEqual = IsEqual && Cell->Line.WidthBottom ==CellFlag->Line.WidthBottom;
    if (IsEqual && CellFlag->f_WidthLeft)
        IsEqual = IsEqual && Cell->Line.WidthLeft ==CellFlag->Line.WidthLeft;
    if (IsEqual && CellFlag->f_WidthRight)
        IsEqual = IsEqual && Cell->Line.WidthRight ==CellFlag->Line.WidthRight;
    if (IsEqual && CellFlag->f_WidthTop)
        IsEqual = IsEqual && Cell->Line.WidthTop ==CellFlag->Line.WidthTop;

    return IsEqual;
}

void __fastcall TCellGrid::SetAllFlag(TCellFlag* CellFlag, bool Set)
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

void __fastcall TCellGrid::AssignParamCell(TCellFlag* CellFlag, int Col, int Row)
{// Копирование параметров

    TCell* Cell =GetCellSimple(Col,Row);
//    Cell->Is( TCellTab::StaticType )
    if (((Col ==1 && Row >1)||(Col >1 && Row ==1))&&CellFlag->ColWidth >0)
          ((TCellColRow*)Cell)->ColRowWidth =CellFlag->ColWidth;

    if (Cell->UnionRect !=NULL && !CellFlag->f_SetUnion)
    {
    }
    else
    {
        if (CellFlag->f_Text)
            Cell->Text =CellFlag->Text;
        if (CellFlag->f_bgColor)
            Cell->bgColor =CellFlag->bgColor;
        if (CellFlag->f_FontColor)
            Cell->FontColor =CellFlag->FontColor;
        if (CellFlag->f_FontName)
            Cell->FontName =CellFlag->FontName;
        if (CellFlag->f_FontSize)
            Cell->CellFlags.FontSize =CellFlag->CellFlags.FontSize;
        if (CellFlag->f_FontStrikeOut)
            Cell->CellFlags.FontStrikeOut =CellFlag->CellFlags.FontStrikeOut;
        if (CellFlag->f_FontStyle)
            Cell->CellFlags.FontStyle =CellFlag->CellFlags.FontStyle;
        if (CellFlag->f_FontUnderline)
            Cell->CellFlags.FontUnderline =CellFlag->CellFlags.FontUnderline;
        if (CellFlag->f_LineColorNot)
            Cell->LineColorNot =CellFlag->LineColorNot;
        if (CellFlag->f_TextHAlign)
            Cell->CellFlags.TextHAlign =CellFlag->CellFlags.TextHAlign;
        if (CellFlag->f_TextHeightAuto)
            Cell->CellFlags.TextHeightAuto =CellFlag->CellFlags.TextHeightAuto;
        if (CellFlag->f_TextVAlign)
            Cell->CellFlags.TextVAlign =CellFlag->CellFlags.TextVAlign;
        if (CellFlag->f_TextWordBreak)
            Cell->CellFlags.TextWordBreak =CellFlag->CellFlags.TextWordBreak;
        if (CellFlag->f_TypeAutoSize)
            Cell->CellFlags.TypeAutoSize =CellFlag->CellFlags.TypeAutoSize;
        if (CellFlag->f_ValueType)
            Cell->CellFlags.ValueType =CellFlag->CellFlags.ValueType;
        if (CellFlag->f_WidthBottom &&
            !(Cell->UnionRect !=NULL &&
            Cell->UnionRect->Top <=Row &&
            Cell->UnionRect->Bottom >Row
            )
        )
        {
            Cell->Line.WidthBottom =CellFlag->Line.WidthBottom;
            if (Row+1 >1 && GetCellSimple(Col,Row+1) !=NULL)
                GetCellSimple(Col,Row+1)->Line.WidthTop =CellFlag->Line.WidthBottom;
        }
        if (CellFlag->f_WidthLeft &&
            !(Cell->UnionRect !=NULL &&
            Cell->UnionRect->Left <Col &&
            Cell->UnionRect->Right >=Col
            )
        )
        {
            Cell->Line.WidthLeft =CellFlag->Line.WidthLeft;
            if (Col-1 >1 && GetCellSimple(Col-1,Row) !=NULL)
                GetCellSimple(Col-1,Row)->Line.WidthRight =CellFlag->Line.WidthLeft;

        }
        if (CellFlag->f_WidthRight &&
            !(Cell->UnionRect !=NULL &&
            Cell->UnionRect->Left <=Col &&
            Cell->UnionRect->Right >Col
            )
        )
        {
            Cell->Line.WidthRight =CellFlag->Line.WidthRight;
            if (Col+1 >1 && GetCellSimple(Col+1,Row) !=NULL)
                GetCellSimple(Col+1,Row)->Line.WidthLeft =CellFlag->Line.WidthRight;
        }
        if (CellFlag->f_WidthTop &&
            !(Cell->UnionRect !=NULL &&
            Cell->UnionRect->Top <Row &&
            Cell->UnionRect->Bottom >=Row
            )
        )
        {
            Cell->Line.WidthTop =CellFlag->Line.WidthTop;
            if (Row-1 >1 && GetCellSimple(Col,Row-1) !=NULL)
                GetCellSimple(Col,Row-1)->Line.WidthBottom =CellFlag->Line.WidthTop;
        }
        if (CellFlag->f_UnionCell)
        {
            if (CellFlag->UnionCell.Right == Col && CellFlag->UnionCell.Bottom == Row)
            {
                DelUnionCell(Cell);
                SetUnionCell(CellFlag->UnionCell,true);
            }
        }
    }
}

void __fastcall TCellGrid::CopyFlag1ToFlag2(TCellFlag* CellFlag1, TCellFlag* CellFlag2)
{// Праверка нужных параметров

    CellFlag2->ColWidth =CellFlag1->ColWidth;

    if (CellFlag1->f_SetUnion)
        CellFlag2->f_SetUnion =CellFlag1->f_SetUnion;

    if (CellFlag1->f_UnionCell)
    {
        CellFlag2->UnionCell =CellFlag1->UnionCell;
        CellFlag2->f_UnionCell =CellFlag1->f_UnionCell;
    }
    if (CellFlag1->f_Text)
    {
        CellFlag2->Text =CellFlag1->Text;
        CellFlag2->f_Text =CellFlag1->f_Text;
    }
    if (CellFlag1->f_bgColor)
    {
        CellFlag2->bgColor =CellFlag1->bgColor;
        CellFlag2->f_bgColor =CellFlag1->f_bgColor;
    }
    if (CellFlag1->f_FontColor)
    {
        CellFlag2->FontColor =CellFlag1->FontColor;
        CellFlag2->f_FontColor =CellFlag1->f_FontColor;
    }
    if (CellFlag1->f_FontName)
    {
        CellFlag2->FontName =CellFlag1->FontName;
        CellFlag2->f_FontName =CellFlag1->f_FontName;
    }
    if (CellFlag1->f_FontSize)
    {
        CellFlag2->CellFlags.FontSize =CellFlag1->CellFlags.FontSize;
        CellFlag2->f_FontSize =CellFlag1->f_FontSize;
    }
    if (CellFlag1->f_FontStrikeOut)
    {
        CellFlag2->CellFlags.FontStrikeOut =CellFlag1->CellFlags.FontStrikeOut;
        CellFlag2->f_FontStrikeOut =CellFlag1->f_FontStrikeOut;
    }
    if (CellFlag1->f_FontStyle)
    {
        CellFlag2->CellFlags.FontStyle =CellFlag1->CellFlags.FontStyle;
        CellFlag2->f_FontStyle =CellFlag1->f_FontStyle;
    }
    if (CellFlag1->f_FontUnderline)
    {
        CellFlag2->CellFlags.FontUnderline =CellFlag1->CellFlags.FontUnderline;
        CellFlag2->f_FontUnderline =CellFlag1->f_FontUnderline;
    }
    if (CellFlag1->f_LineColorNot)
    {
        CellFlag2->LineColorNot =CellFlag1->LineColorNot;
        CellFlag2->f_LineColorNot =CellFlag1->f_LineColorNot;
    }
    if (CellFlag1->f_TextHAlign)
    {
        CellFlag2->CellFlags.TextHAlign =CellFlag1->CellFlags.TextHAlign;
        CellFlag2->f_TextHAlign =CellFlag1->f_TextHAlign;
    }
    if (CellFlag1->f_TextHeightAuto)
    {
        CellFlag2->CellFlags.TextHeightAuto =CellFlag1->CellFlags.TextHeightAuto;
        CellFlag2->f_TextHeightAuto =CellFlag1->f_TextHeightAuto;
    }
    if (CellFlag1->f_TextVAlign)
    {
        CellFlag2->CellFlags.TextVAlign =CellFlag1->CellFlags.TextVAlign;
        CellFlag2->f_TextVAlign =CellFlag1->f_TextVAlign;
    }
    if (CellFlag1->f_TextWordBreak)
    {
        CellFlag2->CellFlags.TextWordBreak =CellFlag1->CellFlags.TextWordBreak;
        CellFlag2->f_TextWordBreak =CellFlag1->f_TextWordBreak;
    }
    if (CellFlag1->f_TypeAutoSize)
    {
        CellFlag2->CellFlags.TypeAutoSize =CellFlag1->CellFlags.TypeAutoSize;
        CellFlag2->f_TypeAutoSize =CellFlag1->f_TypeAutoSize;
    }
    if (CellFlag1->f_ValueType)
    {
        CellFlag2->CellFlags.ValueType =CellFlag1->CellFlags.ValueType;
        CellFlag2->f_ValueType =CellFlag1->f_ValueType;
    }
    if (CellFlag1->f_WidthBottom)
    {
        CellFlag2->Line.WidthBottom =CellFlag1->Line.WidthBottom;
        CellFlag2->f_WidthBottom =CellFlag1->f_WidthBottom;
    }
    if (CellFlag1->f_WidthLeft)
    {
        CellFlag2->Line.WidthLeft =CellFlag1->Line.WidthLeft;
        CellFlag2->f_WidthLeft =CellFlag1->f_WidthLeft;
    }
    if (CellFlag1->f_WidthRight)
    {
        CellFlag2->Line.WidthRight =CellFlag1->Line.WidthRight;
        CellFlag2->f_WidthRight =CellFlag1->f_WidthRight;
    }
    if (CellFlag1->f_WidthTop)
    {
        CellFlag2->Line.WidthTop =CellFlag1->Line.WidthTop;
        CellFlag2->f_WidthTop =CellFlag1->f_WidthTop;
    }
}

void __fastcall TCellGrid::SetFlagCell(int Col, int Row, TCellFlag* CellFlag)
{
    //рекурсия
    TCell* Cell =GetCellParamSimple(Col,Row);
    if ( !ParamCellCompare(Cell, CellFlag) )
    {
        if (GetCellSimple(Col,Row) ==NULL)
            NewCellAndSetParam(Col,Row);
        AssignParamCell(CellFlag,Col,Row);
    }
    /*
    else
        if (GetCellSimple(Col,Row) ==NULL)
        {
            if (CellFlag->f_WidthLeft && GetCellSimple(Col-1,Row) !=NULL)
                GetCellSimple(Col-1,Row)->Line.WidthRight =CellFlag->Line.WidthLeft;
            if (CellFlag->f_WidthTop && GetCellSimple(Col,Row-1) !=NULL)
                GetCellSimple(Col,Row-1)->Line.WidthBottom =CellFlag->Line.WidthTop;
            if (CellFlag->f_WidthRight && GetCellSimple(Col+1,Row) !=NULL)
                GetCellSimple(Col+1,Row)->Line.WidthLeft =CellFlag->Line.WidthRight;
            if (CellFlag->f_WidthBottom && GetCellSimple(Col,Row+1) !=NULL)
                GetCellSimple(Col,Row+1)->Line.WidthTop =CellFlag->Line.WidthBottom;
        }
    */    

    if (Col ==1 && Row ==1)// Установка к таблице
    {
        SetFlagRect(TRect(2,1,EndColRowCell.x,1), CellFlag);
        SetFlagRect(TRect(1,2,1,EndColRowCell.y), CellFlag);
    }
    else if (Col >1 && Row ==1)// Столбцу
        SetFlagRect(TRect(Col,2,Col,EndColRowCell.y), CellFlag);
    else if (Col ==1 && Row >1)// Строке
        SetFlagRect(TRect(2,Row,EndColRowCell.x,Row), CellFlag);
}

void __fastcall TCellGrid::SetFlagRect(const TRect& SetRectCell, TCellFlag* CellFlag)
{// Установить Цвет Шрифта выделенной области
    for (int Col=SetRectCell.Left; Col<=SetRectCell.Right; Col++)
        for (int Row=SetRectCell.Top; Row<=SetRectCell.Bottom; Row++)
            SetFlagCell(Col,Row,CellFlag);
}

void __fastcall TCellGrid::UseTextWordBreakRegion()
{ // Применить перенос по словам к выделенной области
    GetSelectCells(true);
    int End=ListFilling.Count;

    if ((ListFilling[0].x > 1 && ListFilling[0].y ==1) ||
        (ListFilling[0].x == 1 && ListFilling[0].y >1)||
        (ListFilling[0].x > 1 && ListFilling[0].y >1)
    )
    { // Применить (ячейке, строке, столбцу)
        for (int i=0; i<End; i++)
            if (GetCell(ListFilling[i].x,ListFilling[i].y) != NULL)
                UseTextWordBreak(ListFilling[i].x,ListFilling[i].y);
    }
}

void __fastcall TCellGrid::SetFontColorRegion(TColor FontColor)
{ // Установить Цвет Шрифта выделенной области
    SetAllFlag(gCellFlag, false);
    gCellFlag->FontColor    =FontColor;
    gCellFlag->f_FontColor  =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetFontSizeRegion(int FontSize)
{ // Установить размер Шрифта выделенной области
    SetAllFlag(gCellFlag, false);
    gCellFlag->CellFlags.FontSize   =FontSize;
    gCellFlag->f_FontSize           =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetNotChangeParamRegion(const TRect& rectcopy)
{ // Создать ячейку и заполнить
    SetAllFlag(gCellFlag, false);
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetFontNameRegion(AnsiString FontName)
{ // Установить Шрифт выделенной области
    SetAllFlag(gCellFlag, false);
    gCellFlag->FontName     =FontName;
    gCellFlag->f_FontName   =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetFontUnderlineRegion(int FontUnderline)
{
    SetAllFlag(gCellFlag, false);
    gCellFlag->CellFlags.FontUnderline  =FontUnderline;
    gCellFlag->f_FontUnderline          =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetFontStrikeOutRegion(int FontStrikeOut)
{
    SetAllFlag(gCellFlag, false);
    gCellFlag->CellFlags.FontStrikeOut  =FontStrikeOut;
    gCellFlag->f_FontStrikeOut          =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetFontStyleRegion(int FontStyle)
{
    SetAllFlag(gCellFlag, false);
    gCellFlag->CellFlags.FontStyle  =FontStyle;
    gCellFlag->f_FontStyle          =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetTextWordBreakRegion(int TextWordBreak)
{// Установить авто размер строки по тексту (Not=0, Auto=1)
    SetAllFlag(gCellFlag, false);
    gCellFlag->CellFlags.TextWordBreak  =TextWordBreak;
    gCellFlag->f_TextWordBreak          =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetTypeAutoSizeRegion(int TypeAutoSize)
{// Установить авто размер строки по тексту (Not=0, Auto=1)
    SetAllFlag(gCellFlag, false);
    gCellFlag->CellFlags.TypeAutoSize   =TypeAutoSize;
    gCellFlag->f_TypeAutoSize           =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetTextHAlignRegion(int TextHAlign)
{// Установить Выравнивание текста по горизонтали (Left=0, Center=1, Right=2)
    SetAllFlag(gCellFlag, false);
    gCellFlag->CellFlags.TextHAlign     =TextHAlign;
    gCellFlag->f_TextHAlign             =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetTextVAlignRegion(int TextVAlign)
{// Установить Выравнивание текста по вертикали (Left=0, Center=1, Right=2)
    SetAllFlag(gCellFlag, false);
    gCellFlag->CellFlags.TextVAlign     =TextVAlign;
    gCellFlag->f_TextVAlign             =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetValueTypeRegion(int ValueType)
{ // Установить Тип Значения (текст =0, выражение =1, шаблон =2)
    SetAllFlag(gCellFlag, false);
    gCellFlag->CellFlags.ValueType  =ValueType;
    gCellFlag->f_ValueType          =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetColorRegion(TColor Color, bool FlagLineColor)
{ // Установить цвет
    SetAllFlag(gCellFlag, false);
    gCellFlag->bgColor          =Color;
    gCellFlag->f_bgColor        =true;
    gCellFlag->LineColorNot     =FlagLineColor;
    gCellFlag->f_LineColorNot   =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetCellLineOne(/*1=Left, 2=Top, 3=Right, 4=Bottom*/int Border, int WidthLine)
{
    SetAllFlag(gCellFlag, false);
    switch (Border)
    {
        case 1:
        {
            gCellFlag->Line.WidthLeft   =WidthLine;
            gCellFlag->f_WidthLeft      =true;
        } break;
        case 2:
        {
            gCellFlag->Line.WidthTop   =WidthLine;
            gCellFlag->f_WidthTop      =true;
        } break;
        case 3:
        {
            gCellFlag->Line.WidthRight   =WidthLine;
            gCellFlag->f_WidthRight      =true;
        } break;
        case 4:
        {
            gCellFlag->Line.WidthBottom   =WidthLine;
            gCellFlag->f_WidthBottom      =true;
        } break;
    }
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetCellLine(int WidthLeft, int WidthTop, int WidthRight, int WidthBottom)
{
    SetAllFlag(gCellFlag, false);
    gCellFlag->Line.WidthLeft   =WidthLeft;
    gCellFlag->f_WidthLeft      =true;
    gCellFlag->Line.WidthTop    =WidthTop;
    gCellFlag->f_WidthTop       =true;
    gCellFlag->Line.WidthRight  =WidthRight;
    gCellFlag->f_WidthRight     =true;
    gCellFlag->Line.WidthBottom =WidthBottom;
    gCellFlag->f_WidthBottom    =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetCellLineFlood(int WidthLeft, int WidthTop, int WidthRight, int WidthBottom)
{
    SetAllFlag(gCellFlag, false);
    gCellFlag->Line.WidthLeft   =WidthLeft;
    gCellFlag->f_WidthLeft      =true;
    gCellFlag->Line.WidthTop    =WidthTop;
    gCellFlag->f_WidthTop       =true;
    gCellFlag->Line.WidthRight  =WidthRight;
    gCellFlag->f_WidthRight     =true;
    gCellFlag->Line.WidthBottom =WidthBottom;
    gCellFlag->f_WidthBottom    =true;
    gCellFlag->f_Flood          =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetCellLineFloodVert(int WidthLine)
{ // Заполнить вертикальными линиями
    SetAllFlag(gCellFlag, false);
    gCellFlag->Line.WidthRight  =WidthLine;
    gCellFlag->f_WidthRight     =true;
    gCellFlag->f_Flood          =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetCellLineFloodHorz(int WidthLine)
{
    SetAllFlag(gCellFlag, false);
    gCellFlag->Line.WidthBottom  =WidthLine;
    gCellFlag->f_WidthBottom     =true;
    gCellFlag->f_Flood           =true;
    SetParam(GetSelectGridRect(),gCellFlag);
}

void __fastcall TCellGrid::SetParam(const TRect& rect,TCellFlag* CellFlag)
{ // Заполнить матрицу и применяет ее для ректа

    if (!CellFlag->f_Flood &&
            CellFlag->f_WidthLeft &&
            CellFlag->f_WidthTop &&
            CellFlag->f_WidthRight &&
            CellFlag->f_WidthBottom &&
            rect.Top >1 &&
            rect.Left >1
    )
    {// Обвести
        SetCellBorder(rect,
            CellFlag->Line.WidthLeft,
            CellFlag->Line.WidthTop,
            CellFlag->Line.WidthRight,
            CellFlag->Line.WidthBottom);
    }
    else if (CellFlag->f_Flood &&
            !CellFlag->f_WidthLeft &&
            !CellFlag->f_WidthTop &&
            CellFlag->f_WidthRight &&
            !CellFlag->f_WidthBottom &&
            rect.Top >1 &&
            rect.Left >1
    )
    {// Вертикальная заливка
        SetCellBorderFloodVert(rect, CellFlag->Line.WidthRight);
    }
    else if (CellFlag->f_Flood &&
            !CellFlag->f_WidthLeft &&
            !CellFlag->f_WidthTop &&
            !CellFlag->f_WidthRight &&
            CellFlag->f_WidthBottom &&
            rect.Top >1 &&
            rect.Left >1
    )
    {// Горизонтальная заливка
        SetCellBorderFloodHorz(rect, CellFlag->Line.WidthBottom);
    }
    else if (!CellFlag->f_Flood &&
        (
            CellFlag->f_WidthLeft ||
            CellFlag->f_WidthTop ||
            CellFlag->f_WidthRight ||
            CellFlag->f_WidthBottom
        ) &&
        (
            !CellFlag->f_WidthLeft ||
            !CellFlag->f_WidthTop ||
            !CellFlag->f_WidthRight ||
            !CellFlag->f_WidthBottom
        )
    )
    {// Одинарные линии
        if (CellFlag->f_WidthLeft && rect.Left >1)
            SetCellBorderOne(rect,1, CellFlag->Line.WidthLeft);
        if (CellFlag->f_WidthTop && rect.Top >1)
            SetCellBorderOne(rect,2, CellFlag->Line.WidthTop);
        if (CellFlag->f_WidthRight && rect.Left >1)
            SetCellBorderOne(rect,3, CellFlag->Line.WidthRight);
        if (CellFlag->f_WidthBottom && rect.Top >1)
            SetCellBorderOne(rect,4, CellFlag->Line.WidthBottom);
    }
    else if ((CellFlag->f_Flood &&
             CellFlag->f_WidthLeft &&
             CellFlag->f_WidthTop &&
             CellFlag->f_WidthRight &&
             CellFlag->f_WidthBottom) ||
             (!CellFlag->f_Flood &&
             !CellFlag->f_WidthLeft &&
             !CellFlag->f_WidthTop &&
             !CellFlag->f_WidthRight &&
             !CellFlag->f_WidthBottom)
    )
    {
        Matrix->ClearAll();
        Matrix->NewCell(1,1);
        CopyCell1ToCell2(1,1,Matrix->GetCellSimple(1,1));
        SetAllFlag(Matrix->GetCellSimple(1,1), false);
        TCellFlag* setcell;
        TRect temp =rect;
        if (rect.Top ==1 && rect.Left ==1)
        {
            temp.Left   =1;
            temp.Top    =1;
            temp.Right  =1;
            temp.Bottom =1;
            Matrix->DelCell(1,1);
        }
        else if (rect.Top ==1 && rect.Left >1)
        {
            temp.Top    =1;
            temp.Bottom =1;
        }
        else if (rect.Top >1 && rect.Left ==1)
        {
            temp.Left   =1;
            temp.Right  =1;
        }

        for (int y=temp.Top; y<=temp.Bottom; y++)
            for (int x=temp.Left; x<=temp.Right; x++)
            {
                Matrix->NewCell(x,y);
                setcell =Matrix->GetCellSimple(x,y);
                SetAllFlag(setcell,false);
                CopyFlag1ToFlag2(CellFlag,setcell);
            }
        setcell =NULL;
        Matrix->RectCopy =rect;
        PasteBuffInGrid(rect.Left,rect.Top);

    }
    SetAllFlag(gCellFlag, false);
}

//---------------------------------------------------------------------------
void __fastcall TCellGrid::SetCellBorder(const TRect& Rect, int WidthLeft, int WidthTop, int WidthRight, int WidthBottom)
{// Нижний уровень для SetCellLine
    Matrix->ClearAll();
    Matrix->NewCell(1,1);
    CopyCell1ToCell2(1,1,Matrix->GetCellSimple(1,1));
    SetAllFlag(Matrix->GetCellSimple(1,1), false);
    TCellFlag* setcell;

    TRect temp =Rect;
    if (Rect.Top ==1 && Rect.Left ==1)
    {
        temp.Left   =1;
        temp.Top    =1;
        temp.Right  =1;
        temp.Bottom =1;
    }
    else if (Rect.Top ==1 && Rect.Left >1)
    {
        temp.Top    =1;
        temp.Bottom =1;
    }
    else if (Rect.Top >1 && Rect.Left ==1)
    {
        temp.Left   =1;
        temp.Right  =1;
    }

    for (int y=temp.Top; y<=temp.Bottom; y++)
        for (int x=temp.Left; x<=temp.Right; x++)
        {
            if (Matrix->GetCellSimple(x,y) ==NULL)
                Matrix->NewCell(x,y);
            setcell =Matrix->GetCellSimple(x,y);
            SetAllFlag(setcell,false);

            if (x ==Rect.Left)
            {
                setcell->Line.WidthLeft  =WidthLeft;
                setcell->f_WidthLeft     =true;
            }
            if (y ==Rect.Top)
            {
                setcell->Line.WidthTop  =WidthTop;
                setcell->f_WidthTop     =true;
            }
            if (x ==Rect.Right)
            {
                setcell->Line.WidthRight  =WidthRight;
                setcell->f_WidthRight     =true;
            }
            if (y ==Rect.Bottom)
            {
                setcell->Line.WidthBottom  =WidthBottom;
                setcell->f_WidthBottom     =true;
            }
        }
    setcell =NULL;
    Matrix->RectCopy =Rect;
    PasteBuffInGrid(Rect.Left,Rect.Top);
    SetAllFlag(gCellFlag, false);
}

void __fastcall TCellGrid::SetCellBorderFloodVert(const TRect& Rect, int WidthLine)
{ // Заполнить вертикальными линиями
    Matrix->ClearAll();
    Matrix->NewCell(1,1);
    CopyCell1ToCell2(1,1,Matrix->GetCellSimple(1,1));

    SetAllFlag(Matrix->GetCellSimple(1,1), false);
    TCellFlag* setcell;

    TRect temp =Rect;
    if (Rect.Top ==1 && Rect.Left ==1)
    {
        temp.Left   =1;
        temp.Top    =1;
        temp.Right  =1;
        temp.Bottom =1;
    }
    else if (Rect.Top ==1 && Rect.Left >1)
    {
        temp.Top    =1;
        temp.Bottom =1;
    }
    else if (Rect.Top >1 && Rect.Left ==1)
    {
        temp.Left   =1;
        temp.Right  =1;
    }

    for (int y=temp.Top; y<=temp.Bottom; y++)
        for (int x=temp.Left; x<=temp.Right; x++)
        {
            Matrix->NewCell(x,y);
            setcell =Matrix->GetCellSimple(x,y);
            SetAllFlag(setcell,false);
            setcell->Line.WidthRight   =WidthLine;
            setcell->f_WidthRight      =true;
        }
    setcell =NULL;
    Matrix->RectCopy =Rect;
    PasteBuffInGrid(Rect.Left,Rect.Top);
    SetAllFlag(gCellFlag, false);
}

void __fastcall TCellGrid::SetCellBorderFloodHorz(const TRect& Rect, int WidthLine)
{ // Установить объедененную ячейку
    Matrix->ClearAll();
    Matrix->NewCell(1,1);
    CopyCell1ToCell2(1,1,Matrix->GetCellSimple(1,1));

    SetAllFlag(Matrix->GetCellSimple(1,1), false);
    TCellFlag* setcell;

    TRect temp =Rect;
    if (Rect.Top ==1 && Rect.Left ==1)
    {
        temp.Left   =1;
        temp.Top    =1;
        temp.Right  =1;
        temp.Bottom =1;
    }
    else if (Rect.Top ==1 && Rect.Left >1)
    {
        temp.Top    =1;
        temp.Bottom =1;
    }
    else if (Rect.Top >1 && Rect.Left ==1)
    {
        temp.Left   =1;
        temp.Right  =1;
    }

    for (int y=temp.Top; y<=temp.Bottom; y++)
        for (int x=temp.Left; x<=temp.Right; x++)
        {
            Matrix->NewCell(x,y);
            setcell =Matrix->GetCellSimple(x,y);
            SetAllFlag(setcell,false);
            setcell->Line.WidthBottom  =WidthLine;
            setcell->f_WidthBottom     =true;
        }
    setcell =NULL;
    Matrix->RectCopy =Rect;
    PasteBuffInGrid(Rect.Left,Rect.Top);
    SetAllFlag(gCellFlag, false);
}

void __fastcall TCellGrid::SetCellBorderOne(const TRect& Rect ,int Border, int WidthLine)
{// Нижний уровень для SetCellLineOne
    Matrix->ClearAll();
    Matrix->NewCell(1,1);
    CopyCell1ToCell2(1,1,Matrix->GetCellSimple(1,1));

    SetAllFlag(Matrix->GetCellSimple(1,1), false);
    TCellFlag* setcell;

    TRect temp =Rect;
    if (Rect.Top ==1 && Rect.Left ==1)
    {
        temp.Left   =1;
        temp.Top    =1;
        temp.Right  =1;
        temp.Bottom =1;
    }
    else if (Rect.Top ==1 && Rect.Left >1)
    {
        temp.Top    =1;
        temp.Bottom =1;
    }
    else if (Rect.Top >1 && Rect.Left ==1)
    {
        temp.Left   =1;
        temp.Right  =1;
    }
    for (int y=temp.Top; y<=temp.Bottom; y++)
        for (int x=temp.Left; x<=temp.Right; x++)
        {
            if (Border ==1)
            {
                if (x ==Rect.Left)
                {
                    Matrix->NewCell(x,y);
                    setcell =Matrix->GetCellSimple(x,y);
                    SetAllFlag(setcell,false);
                    setcell->Line.WidthLeft  =WidthLine;
                    setcell->f_WidthLeft     =true;
                }
            }
            else if (Border ==2)
            {
                if (y ==Rect.Top)
                {
                    Matrix->NewCell(x,y);
                    setcell =Matrix->GetCellSimple(x,y);
                    SetAllFlag(setcell,false);
                    setcell->Line.WidthTop  =WidthLine;
                    setcell->f_WidthTop     =true;
                }
            }
            else if (Border ==3)
            {
                if (x ==Rect.Right)
                {
                    Matrix->NewCell(x,y);
                    setcell =Matrix->GetCellSimple(x,y);
                    SetAllFlag(setcell,false);
                    setcell->Line.WidthRight  =WidthLine;
                    setcell->f_WidthRight     =true;
                }
            }
            else if (Border ==4)
            {
                if (y ==Rect.Bottom)
                {
                    Matrix->NewCell(x,y);
                    setcell =Matrix->GetCellSimple(x,y);
                    SetAllFlag(setcell,false);
                    setcell->Line.WidthBottom  =WidthLine;
                    setcell->f_WidthBottom     =true;
                }
            }
        }
    setcell =NULL;
    Matrix->RectCopy =Rect;
    PasteBuffInGrid(Rect.Left,Rect.Top);
    SetAllFlag(gCellFlag, false);
}

