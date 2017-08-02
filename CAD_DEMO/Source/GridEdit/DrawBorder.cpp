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

void __fastcall TCellGrid::SetCircumferentialBorder(int Col, int Row)
{// «аполнить окружающие €чейки бордюрам из текущей
    // —уществуют
    if (GetCellSimple(Col, Row) !=NULL)
    {
        if (GetCellSimple(Col-1, Row) !=NULL)
        {
            if (GetCellSimple(Col-1, Row)->UnionRect !=NULL)
                GetCellSimple(Col, Row)->Line.WidthLeft =GetCellSimple(Col-1, Row)->Line.WidthRight;
            else
                GetCellSimple(Col-1, Row)->Line.WidthRight =GetCellSimple(Col, Row)->Line.WidthLeft;
        }

        if (GetCellSimple(Col, Row-1) !=NULL)
        {
            if (GetCellSimple(Col, Row-1)->UnionRect !=NULL)
                GetCellSimple(Col, Row)->Line.WidthTop =GetCellSimple(Col, Row-1)->Line.WidthBottom;
            else
                GetCellSimple(Col, Row-1)->Line.WidthBottom =GetCellSimple(Col, Row)->Line.WidthTop;
        }

        if (GetCellSimple(Col+1, Row) !=NULL)
        {
            if (GetCellSimple(Col+1, Row)->UnionRect !=NULL)
                GetCellSimple(Col, Row)->Line.WidthRight =GetCellSimple(Col+1, Row)->Line.WidthLeft;
            else
                GetCellSimple(Col+1, Row)->Line.WidthLeft =GetCellSimple(Col, Row)->Line.WidthRight;
        }

        if (GetCellSimple(Col, Row+1) !=NULL)
        {
            if (GetCellSimple(Col, Row+1)->UnionRect !=NULL)
                GetCellSimple(Col, Row)->Line.WidthBottom =GetCellSimple(Col, Row+1)->Line.WidthTop;
            else
                GetCellSimple(Col, Row+1)->Line.WidthTop =GetCellSimple(Col, Row)->Line.WidthBottom;
        }
    }
    else
        throw EMyException("<TCellGrid::Set—ircumferentialBorder>: не допустимое применение данной функции");

}

void __fastcall TCellGrid::SetToCellBorder(int Col, int Row)
{// «аполнить окружающие €чейки бордюрам из текущей
    // —уществуют
    if (GetCellSimple(Col, Row) !=NULL)
    {
        GetCellSimple(Col, Row)->Line.WidthLeft     =GetCellParam(Col-1, Row)->Line.WidthRight;
        GetCellSimple(Col, Row)->Line.WidthTop      =GetCellParam(Col, Row-1)->Line.WidthBottom;
        GetCellSimple(Col, Row)->Line.WidthRight    =GetCellParam(Col+1, Row)->Line.WidthLeft;
        GetCellSimple(Col, Row)->Line.WidthBottom   =GetCellParam(Col, Row+1)->Line.WidthTop;
    }
    else
        throw EMyException("<TCellGrid::SetToCellBorder>: Cell not cteating");

}

void __fastcall TCellGrid::SetCircumferentialBorderCol(int Col, int Row)
{// «аполнить окружающие €чейки бордюрам по текущим параметрам
    // —уществуют
    int aCol;
    int aRow;
    bool bError =false;

    if (GetCellSimple(Col, Row) !=NULL)
    {
        aCol =Col;
        aRow =Row;
    }
    else if (GetCellSimple(Col, 1) !=NULL)
    {
        aCol =Col;
        aRow =1;
    }
    else if (GetCellSimple(1, 1) !=NULL)
    {
        aCol =1;
        aRow =1;
    }
    else
    {
        bError =true;
        throw EMyException("<TCellGrid::SetCircumferentialBorderCol>: Ќе допустимое положение");
    }

    if (!bError)
    {
        if (GetCellSimple(Col-1, Row) !=NULL)
            GetCellSimple(Col-1, Row)->Line.WidthRight =GetCellSimple(aCol, aRow)->Line.WidthLeft;

        if (GetCellSimple(Col+1, Row) !=NULL)
            GetCellSimple(Col+1, Row)->Line.WidthLeft =GetCellSimple(aCol, aRow)->Line.WidthRight;
    }
}

void __fastcall TCellGrid::SetCircumferentialBorderRow(int Col, int Row)
{// «аполнить окружающие €чейки бордюрам по текущим параметрам
    // —уществуют
    int aCol;
    int aRow;
    bool bError =false;

    if (GetCellSimple(Col, Row) !=NULL)
    {
        aCol =Col;
        aRow =Row;
    }
    else if (GetCellSimple(1, Row) !=NULL)
    {
        aCol =1;
        aRow =Row;
    }
    else if (GetCellSimple(1, 1) !=NULL)
    {
        aCol =1;
        aRow =1;
    }
    else
    {
        bError =true;
        throw EMyException("<TCellGrid::SetCircumferentialBorderRow>: Ќе допустимое положение");
    }

    if (!bError)
    {
        if (GetCellSimple(Col, Row-1) !=NULL)
            GetCellSimple(Col, Row-1)->Line.WidthBottom =GetCellSimple(aCol, aRow)->Line.WidthTop;

        if (GetCellSimple(Col, Row+1) !=NULL)
            GetCellSimple(Col, Row+1)->Line.WidthTop =GetCellSimple(aCol, aRow)->Line.WidthBottom;
    }
}

void __fastcall TCellGrid::CellLineBottomSection(const TRect& RectStart)
{

    TPenStyle oldStyle = Canvas->Pen->Style;
    TColor oldColor =Canvas->Pen->Color;
    TColor oldBkColor =Canvas->Brush->Color;

    Canvas->Brush->Color =oldColor;
    Canvas->Pen->Style = psDashDot;
    Canvas->Pen->Color = clRed;

    CellLineBottom(RectStart);

    Canvas->Pen->Style = oldStyle;
    Canvas->Pen->Color = oldColor;
    Canvas->Brush->Color = oldBkColor;
}

void __fastcall TCellGrid::CellLineRightSection(const TRect& RectStart)
{

    TPenStyle oldStyle = Canvas->Pen->Style;
    TColor oldColor =Canvas->Pen->Color;
    TColor oldBkColor =Canvas->Brush->Color;

    Canvas->Brush->Color =oldColor;
    Canvas->Pen->Style = psDashDot;
    Canvas->Pen->Color = clRed;

    CellLineRight(RectStart);

    Canvas->Pen->Style = oldStyle;
    Canvas->Pen->Color = oldColor;
    Canvas->Brush->Color = oldBkColor;
}


//*************** Line Width =1 Pixel
void __fastcall TCellGrid::CellLineTop(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Left-1, RectStart.Top-1);
    Canvas->LineTo(RectStart.Right+1, RectStart.Top-1);
}

void __fastcall TCellGrid::CellRightBottomPixel(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Right, RectStart.Bottom);
    Canvas->LineTo(RectStart.Right+1, RectStart.Bottom+1);
}

void __fastcall TCellGrid::CellRightBottomPixel2(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Left, RectStart.Top);
    Canvas->LineTo(RectStart.Right, RectStart.Bottom);
}

void __fastcall TCellGrid::CellLineLeft(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Left-1,RectStart.Bottom);
    Canvas->LineTo(RectStart.Left-1, RectStart.Top-1);
}

void __fastcall TCellGrid::CellLineRight(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Right, RectStart.Top);
    Canvas->LineTo(RectStart.Right,RectStart.Bottom+1);
}

void __fastcall TCellGrid::CellLineRightColorBk(int Col, int Row)
{
    if (Canvas->Pen->Color !=Canvas->Brush->Color)
        Canvas->Pen->Color =Canvas->Brush->Color;

    TRect RectStart =GetGridRectToRectPixelForBorder(Col, Row);

    if (GetCellSimple(Col, Row-1) != NULL &&
        GetCellSimple(Col, Row-1)->UnionRect !=NULL &&
        GetCellSimple(Col, Row) !=NULL &&
        GetCellSimple(Col, Row)->UnionRect !=NULL &&
        BeEqualRect(*GetCell(Col, Row)->UnionRect, *GetCell(Col, Row-1)->UnionRect)&&
        (GetCellSimple(Col, Row-1)->Line.WidthRight <2))
    {
        RectStart.Top -=1;
    }
    Canvas->MoveTo(RectStart.Right-1, RectStart.Top+1);
    Canvas->LineTo(RectStart.Right-1,RectStart.Bottom+1);
}

void __fastcall TCellGrid::CellLineLeftColorBk(int Col, int Row)
{
    if (Canvas->Pen->Color !=Canvas->Brush->Color)
        Canvas->Pen->Color =Canvas->Brush->Color;
    if (Canvas->Pen->Width != 1)
        Canvas->Pen->Width = 1;

    TRect RectStart =GetGridRectToRectPixelForBorder(Col, Row);

    Canvas->MoveTo(RectStart.Left, RectStart.Top);
    Canvas->LineTo(RectStart.Left,RectStart.Bottom+1);
}

void __fastcall TCellGrid::CellLineBottomColorBk(int Col, int Row)
{
    if (Col >1 && Row>1)
    {
        if (Canvas->Pen->Color !=Canvas->Brush->Color)
            Canvas->Pen->Color =Canvas->Brush->Color;
        if (Canvas->Pen->Width != 1)
            Canvas->Pen->Width = 1;

        TRect RectStart =GetGridRectToRectPixelForBorder(Col, Row);

        TCell* CellLeft =GetCellSimple(Col-1, Row);
        TCell* Cell =GetCellSimple(Col, Row);

        if (CellLeft != NULL &&
            CellLeft->UnionRect !=NULL &&
            Cell != NULL &&
            Cell->UnionRect !=NULL &&
            BeEqualRect(*Cell->UnionRect, *CellLeft->UnionRect)&&
            (CellLeft->Line.WidthBottom <2))
        {
            RectStart.Left -=1;
        }

        Canvas->MoveTo(RectStart.Left+1,RectStart.Bottom-1);
        Canvas->LineTo(RectStart.Right+1,RectStart.Bottom-1);
    }
}

void __fastcall TCellGrid::CellLineTopColorBk(int Col, int Row)
{
    if (Col >1 && Row>1)
    {
        if (Canvas->Pen->Color !=Canvas->Brush->Color)
            Canvas->Pen->Color =Canvas->Brush->Color;
        if (Canvas->Pen->Width != 1)
            Canvas->Pen->Width = 1;

        TRect RectStart =GetGridRectToRectPixelForBorder(Col, Row);

        Canvas->MoveTo(RectStart.Left,RectStart.Top);
        Canvas->LineTo(RectStart.Right+1,RectStart.Top);
    }
}

void __fastcall TCellGrid::CellLineBottom(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Left,RectStart.Bottom);
    Canvas->LineTo(RectStart.Right+1,RectStart.Bottom);
}
//*************** Line Width =1 Pixel END


//*************** Line Width =2 Pixel
void __fastcall TCellGrid::CellLineTop2(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Right, RectStart.Top-1);
    Canvas->LineTo(RectStart.Left-2, RectStart.Top-1);
    Canvas->MoveTo(RectStart.Right, RectStart.Top-2);
    Canvas->LineTo(RectStart.Left-2, RectStart.Top-2);
}

void __fastcall TCellGrid::CellLineBottom2(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Left-1,RectStart.Bottom);
    Canvas->LineTo(RectStart.Right+1,RectStart.Bottom);
}
void __fastcall TCellGrid::CellLineBottom2b(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Left-1,RectStart.Bottom-1);
    Canvas->LineTo(RectStart.Right+1,RectStart.Bottom-1);
}

void __fastcall TCellGrid::CellLineLeft2(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Left-1,RectStart.Top-1);
    Canvas->LineTo(RectStart.Left-1,RectStart.Bottom+1);
    Canvas->MoveTo(RectStart.Left-2,RectStart.Top-1);
    Canvas->LineTo(RectStart.Left-2,RectStart.Bottom+1);
}

void __fastcall TCellGrid::CellLineRight2(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Right, RectStart.Top);
    Canvas->LineTo(RectStart.Right,RectStart.Bottom);
}

void __fastcall TCellGrid::CellLineRight2b(const TRect& RectStart)
{
    Canvas->MoveTo(RectStart.Right-1, RectStart.Top);
    Canvas->LineTo(RectStart.Right-1,RectStart.Bottom+1);
}

void __fastcall TCellGrid::Line(int Col, int Row, TColor Color)
{
    if (Col>1 && Row>1)
    {
        if (Canvas->Pen->Width !=1)
            Canvas->Pen->Width =1;

        SetBorder(Col,Row,3,GetRightBorder(Col,Row), Color);
        SetBorder(Col,Row,4,GetBottomBorder(Col,Row), Color);

        TCell* CellRightBottom =GetCellSimple(Col+1,Row+1);
        if (CellRightBottom !=NULL)
        {
            if (CellRightBottom->Line.WidthLeft ==
                CellRightBottom->Line.WidthTop &&
                (
                    GetCellSimple(Col,Row) ==NULL ||
                    (GetCellSimple(Col,Row) !=NULL && GetCellSimple(Col,Row)->UnionRect ==NULL)
                )
            )
            {
                SetBorder(Col,Row,9+CellRightBottom->Line.WidthLeft,CellRightBottom->Line.WidthLeft, Color);
            }
            if (CellRightBottom->Line.WidthLeft ==1 &&
                CellRightBottom->Line.WidthTop ==2
            )
            {
                SetBorder(Col,Row,12,1, Color);
            }
            if (CellRightBottom->Line.WidthLeft ==2 &&
                CellRightBottom->Line.WidthTop ==1
            )
            {
                SetBorder(Col,Row,13,1, Color);
            }
        }
    }
}

bool PointInRect(int Col,int Row,const TRect& Rect)
{
    return (Row>=Rect.Top &&
            Row<=Rect.Bottom &&
            Col>=Rect.Left &&
            Col<=Rect.Right);
}

void __fastcall TCellGrid::DrawBorder_0(int Col, int Row, int Border, const TRect& rect, TColor Color)
{
    TRect rect2;
    bool OK=false;

    TRect CurrentAnchorSelect =GetAnchorCurrentSort();
    TCell* Cell =GetCell(Col,Row);
    TCell* CellColumn =GetCellSimple(Col,1);
    TCell* CellString =GetCellSimple(1,Row);
    TCell* Cell11 =GetCellSimple(1,1);

    if (Cell !=NULL && Cell->LineColorNot)
    {
        if (Canvas->Pen->Color !=Color)
            Canvas->Pen->Color= Color;
    }
    else
    {
        if (Cell ==NULL && CellColumn !=NULL && CellColumn->LineColorNot)
        {// —толбец
            if ( PointInRect(Col,Row,CurrentAnchorSelect) )
            {
                if (Canvas->Pen->Color !=Color)
                    Canvas->Pen->Color =SetColorCursor(CellColumn->bgColor);
            }
            else if (Canvas->Pen->Color !=Color)
                Canvas->Pen->Color =CellColumn->bgColor;
        }
        else if (Cell ==NULL && CellString !=NULL && CellString->LineColorNot)
        {//—трока
            if ( PointInRect(Col,Row,CurrentAnchorSelect) )
            {
                if (Canvas->Pen->Color !=Color)
                    Canvas->Pen->Color =SetColorCursor(CellString->bgColor);
            }
            else if (Canvas->Pen->Color !=Color)
                Canvas->Pen->Color =CellString->bgColor;
        }
        else if (Cell ==NULL && Cell11->LineColorNot)
        {//“аблица
            if ( PointInRect(Col,Row,CurrentAnchorSelect) )
            {
                if (Canvas->Pen->Color !=Color)
                    Canvas->Pen->Color =SetColorCursor(Cell11->bgColor);
            }
            else if (Canvas->Pen->Color !=Color)
                Canvas->Pen->Color =Cell11->bgColor;
        }
        else
        {// ячейка
            if (Canvas->Pen->Color !=clSilver)
                Canvas->Pen->Color= clSilver;
        }
    }
    if (Cell !=NULL)
    {
        switch (Border)
        {
            case 3: // Right
            {
                if (Cell->Line.WidthRight ==0)
                {
                    if (!(Col+1 == FixedCols && FixedCols>2))
                    {
                        OK=false;
                        TCell* CellSectTop =GetCellSimple(Col+1,0);
                        if (CellSectTop !=NULL)
                        {
                            if (CellSectTop->UnionRect->Top ==0)
                            {
                                if (CellSectTop->UnionRect->Left-1 ==Col)
                                {
                                    if (RightLineUnion(Col, Row))
                                        CellLineRightSection(rect);
                                }
                                else OK=true;
                            }
                            else OK=true;
                        }
                        else
                        {
                            OK=true;
                            TCell* CellSectTop =GetCellSimple(Col,0);
                            if (CellSectTop !=NULL)
                            {
                                if (CellSectTop->UnionRect->Top ==0)
                                {
                                    if (CellSectTop->UnionRect->Right ==Col)
                                    {
                                        if (RightLineUnion(Col, Row))
                                            CellLineRightSection(rect);
                                        OK=false;
                                    }
                                    else OK=true;
                                }
                                else OK=true;
                            }
                            else OK=true;
                        }
                        if (OK)
                        {
                            if (RightLineUnion(Col, Row))
                            {
                                TCell* CellRight =GetCellParam(Col+1,Row);
                                if (!GetCell(Col,Row)->LineColorNot &&
                                    CellRight->LineColorNot
                                )
                                {
                                    if (CellRight->bgColor !=clWhite  || CellRight->LineColorNot)
                                    {
                                        if ( Rect1InRect2(TRect(Col+1,Row,Col+1,Row),CurrentAnchorSelect) )
                                            Canvas->Pen->Color=SetColorCursor(CellRight->bgColor);
                                        else
                                            Canvas->Pen->Color=CellRight->bgColor;
                                    }
                                }
                                if (GetCellParam(Col,Row+1)->bgColor !=clWhite)
                                    rect2.Bottom -=1;
                                CellLineRight(rect);
                            }
                        }
                    }
                }
            } break;
            case 4: // Bottom
            {
                TCell* CellS =GetCellSimple(Col,Row);
                if (CellS->Line.WidthBottom ==0)
                {
                    if (!(Row+1  == FixedRows && FixedRows>2))
                    {
                        rect2 = rect;
                        if (GetCellSimple(0,Row+1) !=NULL)
                        {
                            if (GetCellSimple(0,Row+1)->UnionRect->Left ==0)
                            {
                                if (GetCellSimple(0,Row+1)->UnionRect->Top-1 ==Row)
                                {
                                    if (BottomLineUnion(Col, Row))
                                        CellLineBottomSection(rect2);
                                }
                                else OK=true;
                            }
                            else OK=true;
                        }
                        else
                        {
                            OK=true;
                            TCell* CellString =GetCellSimple(0,Row);
                            if (CellString !=NULL)
                            {
                                if (CellString->UnionRect->Left ==0)
                                {
                                    if (CellString->UnionRect->Bottom ==Row)
                                    {
                                        if (BottomLineUnion(Col, Row))
                                            CellLineBottomSection(rect2);
                                        OK=false;
                                    }
                                    else OK=true;
                                }
                                else OK=true;
                            }
                            else OK=true;
                        }
                        if (OK)
                        {
                            if (BottomLineUnion(Col, Row))
                            {
                                TCell* CellBottom =GetCellParam(Col,Row+1);
                                if (!Cell->LineColorNot &&
                                    CellBottom->LineColorNot
                                )
                                {
                                    if (CellBottom->bgColor !=clWhite || CellBottom->LineColorNot)
                                    {
                                        if (Rect1InRect2(TRect(Col,Row+1,Col,Row+1),CurrentAnchorSelect))
                                            Canvas->Pen->Color=SetColorCursor(CellBottom->bgColor);
                                        else
                                            Canvas->Pen->Color=CellBottom->bgColor;
                                    }
                                }
                                rect2.Right -=GetRightBorder(Col,Row);
/*
                                if ((GetCellParam(Col+1,Row)->bgColor !=clWhite &&
                                    GetCell(Col,Row)->UnionRect ==NULL)
                                )
                                    rect2.Right -=GetRightBorder(Col,Row);
                                else
                                    rect2.Right -=GetRightBorder(Col,Row);
*/

                                CellLineBottom(rect2);
                            }
                        }
                    }
                }
            } break;
        }
    }
    else
    {// ѕуста€ €чейка
        switch (Border)
        {
            case 3: // Right
            {
                if (!(Col+1 == FixedCols && FixedCols>2))
                {
                    OK=false;
                    if (GetCellSimple(Col+1,0) !=NULL)
                    {
                        if (GetCellSimple(Col+1,0)->UnionRect->Top ==0)
                        {
                            if (GetCellSimple(Col+1,0)->UnionRect->Left-1 ==Col)
                            {
                                if (RightLineUnion(Col, Row))
                                    CellLineRightSection(rect);
                            }
                            else OK=true;
                        }
                        else OK=true;
                    }
                    else
                    {
                        if (GetCellSimple(Col,0) !=NULL)
                        {
                            if (GetCellSimple(Col,0)->UnionRect->Top ==0)
                            {
                                if (GetCellSimple(Col,0)->UnionRect->Right ==Col)
                                {
                                    if (RightLineUnion(Col, Row))
                                        CellLineRightSection(rect);
                                    OK=false;
                                }
                                else OK=true;
                            }
                            else OK=true;
                        }
                        else OK=true;
                    }
                    if (OK)
                    {
                        TCell* CellColumn =GetCell(Col,1);
                        TCell* CellString =GetCell(1,Row);
                        if (CellColumn ==NULL ||
                            (CellColumn !=NULL && !CellColumn->LineColorNot)
                        )
                        if (
                            (CellString ==NULL ||
                            (CellString !=NULL/* && CellString->LineColorNot*/)) &&
                            ((GetCell(Col+1,Row) !=NULL &&
                            GetCell(Col+1,Row)->LineColorNot) ||
                            (GetCell(Col+1,1) !=NULL && GetCell(Col+1,1)->LineColorNot))
                        )
                        {
                            TCell* CellLeft =GetCellParam(Col+1,Row);
                            if (CellLeft->bgColor !=clWhite || CellLeft->LineColorNot)
                            {
                                if ( Rect1InRect2( TRect(Col+1,Row,Col+1,Row), CurrentAnchorSelect ) )
                                    Canvas->Pen->Color=SetColorCursor(CellLeft->bgColor);
                                else
                                    Canvas->Pen->Color=CellLeft->bgColor;
                            }
                        }
                        if (GetCellParam(Col,Row+1)->bgColor !=clWhite)
                            rect2.Bottom -=1;

                        CellLineRight(rect);
                    }
                }
            } break;
            case 4: // Bottom
            {
                OK=false;
                if (!(Row+1 == FixedRows && FixedRows>2))
                {
                    TCell* CellLeft =GetCellSimple(Col+1,Row);
                    rect2 = rect;
                    if (CellLeft !=NULL &&
                        CellLeft->Line.WidthLeft ==2
                    )
                        rect2.Right -=1;

                    if (CellLeft !=NULL &&
                        CellLeft->Line.WidthLeft
                    )
                        rect2.Right -=1;

                    if (GetCellSimple(0,Row+1) !=NULL)
                    {
                        if (GetCellSimple(0,Row+1)->UnionRect->Left ==0)
                        {
                            if (GetCellSimple(0,Row+1)->UnionRect->Top-1 ==Row)
                            {
                                CellLineBottomSection(rect2);
                            }else OK=true;
                        }else OK=true;
                    }
                    else
                    {
                        OK=true;
                        if (GetCellSimple(0,Row) !=NULL)
                        {
                            if (GetCellSimple(0,Row)->UnionRect->Left ==0)
                            {
                                if (GetCellSimple(0,Row)->UnionRect->Bottom ==Row)
                                {
                                    CellLineBottomSection(rect2);
                                    OK=false;
                                }else OK=true;
                            }else OK=true;
                        } else OK=true;
                    }
                    if (OK)
                    {
                        TCell* CellColumn =GetCell(Col, 1);
                        if (CellColumn !=NULL &&
                            GetCellSimple(Col, 1)->Line.WidthRight >0
                        )
                        {
                            rect2.Right -=GetCellSimple(Col, 1)->Line.WidthRight;
                        }
                        else if (GetCellSimple(Col+1, 1) !=NULL &&
                            GetCellSimple(Col+1, 1)->Line.WidthLeft >0
                        )
                        {
                            rect2.Right -=GetCellSimple(Col+1, 1)->Line.WidthLeft;
                        }
                        else if (GetCellParam(Col+1,Row)->bgColor !=clWhite &&
                            GetRightBorder(Col,Row) ==0
                        )
                            rect2.Right -=1;

                        if (GetCell(1,Row) ==NULL ||
                            (GetCell(1,Row) !=NULL && !GetCell(1,Row)->LineColorNot)
                        )
                        if ((CellColumn ==NULL ||
                            (CellColumn !=NULL &&
                            !CellColumn->LineColorNot)) &&
                            ((GetCell(Col,Row+1) !=NULL &&
                            GetCell(Col,Row+1)->LineColorNot) ||
                            (GetCell(1,Row+1) !=NULL &&
                            GetCell(1,Row+1)->LineColorNot))
                        )
                        {
                            TCell* CellBottom =GetCellParam(Col,Row+1);
                            if (CellBottom->bgColor !=clWhite || CellBottom->LineColorNot)
                            {
                                if (Rect1InRect2(TRect(Col,Row+1,Col,Row+1),CurrentAnchorSelect))
                                {
                                    Canvas->Pen->Color=SetColorCursor(CellBottom->bgColor);
                                } else
                                    Canvas->Pen->Color=CellBottom->bgColor;
                            }
                        }

                        CellLineBottom(rect2);
                    }
                }
            } break;
        }
    }
}

void __fastcall TCellGrid::DrawBorder_1(int Col, int Row, int Border, const TRect& rect, TColor Color)
{
    TRect rect2;
    bool OK=false;
    if (Canvas->Pen->Color !=clBlack)
        Canvas->Pen->Color= clBlack;

    switch (Border)
    {
        case 3: // Right
        {
            rect2 = rect;
            OK=false;
            if (GetCellSimple(Col+1,0) !=NULL)
            {
                if (GetCellSimple(Col+1,0)->UnionRect->Top ==0)
                {
                    if (GetCellSimple(Col+1,0)->UnionRect->Left-1 ==Col)
                    {
                        if (RightLineUnion(Col, Row))
                            CellLineRightSection(rect);
                    }else OK=true;
                }else OK=true;
            } else
            {
                OK=true;
                if (GetCellSimple(Col,0) !=NULL)
                {
                    if (GetCellSimple(Col,0)->UnionRect->Top ==0)
                    {
                        if (GetCellSimple(Col,0)->UnionRect->Right ==Col)
                        {
                            if (RightLineUnion(Col, Row))
                                CellLineRightSection(rect);
                            OK=false;
                        }else OK=true;
                    }else OK=true;
                } else OK=true;
            }
            if (OK && RightLineUnion(Col, Row))
                CellLineRight(rect2);

        } break;
        case 4: // Bottom
        {
            rect2 = rect;
            OK=false;
            if (GetCellSimple(0,Row+1) !=NULL)
            {
                if (GetCellSimple(0,Row+1)->UnionRect->Left ==0)
                {
                    if (GetCellSimple(0,Row+1)->UnionRect->Top-1 ==Row)
                    {
                        if (BottomLineUnion(Col, Row))
                            CellLineBottomSection(rect);
                    }else OK=true;
                }else OK=true;
            } else
            {
                OK=true;
                if (GetCellSimple(0,Row) !=NULL)
                {
                    if (GetCellSimple(0,Row)->UnionRect->Left ==0)
                    {
                        if (GetCellSimple(0,Row)->UnionRect->Bottom ==Row)
                        {
                            if (BottomLineUnion(Col, Row))
                                CellLineBottomSection(rect);
                            OK=false;
                        }else OK=true;
                    }else OK=true;
                } else OK=true;
            }
            if (OK && BottomLineUnion(Col, Row))
                CellLineBottom(rect2);

        } break;
    }
}

void __fastcall TCellGrid::DrawBorder_2(int Col, int Row, int Border, const TRect& rect, TColor Color)
{
    TRect rect2;
    bool OK=false;

    if (Canvas->Pen->Color !=clBlack)
        Canvas->Pen->Color= clBlack;
    switch (Border)
    {
        case 3: // Right2
        {
            rect2 = rect;
            rect2.Bottom +=1;
            OK=false;
            if (GetCellSimple(Col+1,0) !=NULL)
            {
                if (GetCellSimple(Col+1,0)->UnionRect->Top ==0)
                {
                    if (GetCellSimple(Col+1,0)->UnionRect->Left-1 ==Col)
                    {
                        if (RightLineUnion(Col, Row))
                            CellLineRightSection(rect2);
                    }else OK=true;
                }else OK=true;
            } else
            {
                OK=true;
                if (GetCellSimple(Col,0) !=NULL)
                {
                    if (GetCellSimple(Col,0)->UnionRect->Top ==0)
                    {
                        if (GetCellSimple(Col,0)->UnionRect->Right ==Col)
                        {
                            if (RightLineUnion(Col, Row))
                                CellLineRightSection(rect2);
                            OK=false;
                        }else OK=true;
                    }else OK=true;
                } else OK=true;
            }
            if (RightLineUnion(Col, Row))
            {
                if (OK)
                    CellLineRight(rect2);

                CellLineRight2b(rect2);
            }
        }break;
        case 4: // Bottom2
        {
            OK=false;
            rect2 = rect;
            rect2.Left +=1;
            if (GetCellSimple(0,Row+1) !=NULL)
            {
                if (GetCellSimple(0,Row+1)->UnionRect->Left ==0)
                {
                    if (GetCellSimple(0,Row+1)->UnionRect->Top-1 ==Row)
                    {
                        if (BottomLineUnion(Col, Row))
                            CellLineBottomSection(rect2);
                    }else OK=true;
                }else OK=true;
            } else
            {
                OK=true;
                if (GetCellSimple(0,Row) !=NULL)
                {
                    if (GetCellSimple(0,Row)->UnionRect->Left ==0)
                    {
                        if (GetCellSimple(0,Row)->UnionRect->Bottom ==Row)
                        {
                            if (BottomLineUnion(Col, Row))
                                CellLineBottomSection(rect2);
                            OK=false;
                        }else OK=true;
                    }else OK=true;
                } else OK=true;
            }
            if (BottomLineUnion(Col, Row))
            {
                if (OK && BottomLineUnion(Col, Row))
                    CellLineBottom2(rect2);

                CellLineBottom2b(rect2);
            }
        } break;
    }
}

void __fastcall TCellGrid::SetBorder(int Col, int Row, /*1=Left, 2=Top, 3=Right, 4=Bottom*/int Border, int WidthLine, TColor Color)
{
    TRect rect = GetGridRectToRectPixelForBorder(Col,Row);

    if (WidthLine ==2)
        DrawBorder_2(Col, Row, Border, rect, Color);
    else
        if (WidthLine ==1)
            DrawBorder_1(Col, Row, Border, rect, Color);
        else
            DrawBorder_0(Col, Row, Border, rect, Color);


    if (WidthLine ==1)
    {
        switch (Border)
        {
            case 10: // RightBottomPixel
            {
                if (Canvas->Pen->Color !=clBlack)
                    Canvas->Pen->Color= clBlack;

                TRect rect2;
                rect2 = rect;
                CellRightBottomPixel(rect2);
                break;
            }
            case 12: //
            {
                if (Canvas->Pen->Color !=clBlack)
                    Canvas->Pen->Color= clBlack;

                TRect rect2;
                rect2 = rect;
                rect2.Left =rect2.Right;
                rect2.Top =rect2.Bottom-1;
                rect2.Bottom +=1;

                CellRightBottomPixel2(rect2);
                break;
            }
            case 13: //
            {
                if (Canvas->Pen->Color !=clBlack)
                    Canvas->Pen->Color= clBlack;

                TRect rect2;
                rect2 = rect;
                rect2.Left =rect2.Right-1;
                rect2.Top =rect2.Bottom;
                rect2.Right +=1;
                CellRightBottomPixel2(rect2);
                break;
            }

        }
    }
    if (WidthLine ==2)
    {
        switch (Border)
        {
            case 11: // RightBottomPixel2
            {
                if (Canvas->Pen->Color !=clBlack)
                    Canvas->Pen->Color= clBlack;

                Canvas->Pen->Width =2;
                TRect rect2;
                rect2 = rect;
                rect2.Right -=1;
                rect2.Bottom -=1;

                CellRightBottomPixel(rect2);
                break;
            }
        }
    }

    //- –исуем Fixed -
    if (Col+1 == FixedCols && FixedCols>2)
    {
        if (Canvas->Pen->Width != 1)
            Canvas->Pen->Width = 1;

        if (Canvas->Pen->Color !=clSkyBlue)
            Canvas->Pen->Color= clSkyBlue;

        CellLineRight(rect);
    }
    if (Row+1 == FixedRows && FixedRows>2)
    {
        if (Canvas->Pen->Width != 1)
            Canvas->Pen->Width = 1;

        if (Canvas->Pen->Color !=clSkyBlue)
            Canvas->Pen->Color= clSkyBlue;

        CellLineBottom(rect);
    }
}

void __fastcall TCellGrid::SectionLine(const TRect& Rect,int Param/*1=Left, 2=Top*/)
{
TRect localrect =Rect;
    if (Canvas->Pen->Color !=clBlack) Canvas->Pen->Color = clBlack;
    if (Param ==1)
    {
        localrect.Left +=2;
        localrect.Top +=2;

        CellLineLeft(localrect);
        CellLineTop(localrect);
        CellLineBottom(localrect);
        Canvas->Pen->Color = clWhite;
        localrect =Rect;
        localrect.Top +=2;
        localrect.Bottom -=2;

        CellLineRight(localrect);
    } else
    if (Param ==2)
    {
        localrect.Left +=2;
        localrect.Top +=2;

        CellLineLeft(localrect);
        CellLineTop(localrect);
        CellLineRight(localrect);
        Canvas->Pen->Color = clWhite;
        localrect =Rect;
        localrect.Left +=2;
        localrect.Right -=2;

        CellLineBottom(localrect);
    }
}

bool __fastcall TCellGrid::TopLineUnion(int Col, int Row)
{// явл€етьс€ ли эта €чейка простой или Union но отличной от нижнего Union
    bool ret=false;
    if (Row-1 <0)
    {
        ret=true;
    } else
    if (GetCellSimple(Col, Row) !=NULL)
    {
        if (GetCellSimple(Col, Row)->UnionRect == NULL) ret=true;
        if (GetCellSimple(Col, Row-1) !=NULL &&
            GetCellSimple(Col, Row)->UnionRect != NULL &&
            GetCellSimple(Col, Row-1)->UnionRect != NULL &&
            !BeEqualRect(*GetCellSimple(Col, Row)->UnionRect, *GetCellSimple(Col, Row-1)->UnionRect)) ret=true;

        if (GetCellSimple(Col, Row-1) != NULL && GetCellSimple(Col, Row-1)->UnionRect == NULL) ret=true;            
    }
    if (GetCellSimple(Col, Row) == NULL) ret=true;
    if (GetCellSimple(Col, Row-1) ==NULL) ret=true;
    return ret;
}

bool __fastcall TCellGrid::LeftLineUnion(int Col, int Row)
{// явл€етьс€ ли эта €чейка простой или Union но отличной от нижнего Union
    bool ret=false;
    if (Col-1 <0)
    {
        ret=true;
    } else
    if (GetCellSimple(Col, Row) !=NULL)
    {
        if (GetCellSimple(Col, Row)->UnionRect == NULL) ret=true;
        if (GetCellSimple(Col-1, Row) !=NULL &&
            GetCellSimple(Col, Row)->UnionRect != NULL &&
            GetCellSimple(Col-1, Row)->UnionRect != NULL &&
            !BeEqualRect(*GetCellSimple(Col, Row)->UnionRect, *GetCellSimple(Col-1, Row)->UnionRect)) ret=true;

        if (GetCellSimple(Col-1, Row) != NULL && GetCellSimple(Col-1, Row)->UnionRect == NULL) ret=true;
    }
    if (GetCellSimple(Col, Row) == NULL) ret=true;
    if (GetCellSimple(Col-1, Row) ==NULL) ret=true;
    return ret;
}

bool __fastcall TCellGrid::RightLineUnion(int Col, int Row)
{// явл€етьс€ ли эта €чейка простой или Union но отличной от нижнего Union
    bool ret=false;
    if (Col+1 >ColCount)
    {
        ret=true;
    } else
    if (GetCellSimple(Col, Row) !=NULL)
    {
        if (GetCellSimple(Col, Row)->UnionRect == NULL)
            ret=true;

        if (GetCellSimple(Col+1, Row) !=NULL &&
            GetCellSimple(Col, Row)->UnionRect != NULL &&
            GetCellSimple(Col+1, Row)->UnionRect != NULL &&
            !BeEqualRect(*GetCellSimple(Col, Row)->UnionRect, *GetCellSimple(Col+1, Row)->UnionRect))
        ret=true;

        if (GetCellSimple(Col+1, Row) != NULL && GetCellSimple(Col+1, Row)->UnionRect == NULL) ret=true;
    }
    if (GetCellSimple(Col, Row) == NULL) ret=true;
    if (GetCellSimple(Col+1, Row) ==NULL) ret=true;
    return ret;
}

bool __fastcall TCellGrid::BottomLineUnion(int Col, int Row)
{// явл€етьс€ ли эта €чейка простой или Union но отличной от нижнего Union
    bool ret=false;
    if (Row+1 >RowCount)
    {
        ret=true;
    }else
    if (GetCellSimple(Col, Row) !=NULL)
    {
        if (GetCellSimple(Col, Row)->UnionRect == NULL) ret=true;
        if (GetCellSimple(Col, Row+1) !=NULL &&
            GetCellSimple(Col, Row)->UnionRect != NULL &&
            GetCellSimple(Col, Row+1)->UnionRect != NULL &&
            !BeEqualRect(*GetCellSimple(Col, Row)->UnionRect, *GetCellSimple(Col, Row+1)->UnionRect)) ret=true;

            if (GetCellSimple(Col, Row+1) != NULL && GetCellSimple(Col, Row+1)->UnionRect == NULL) ret=true;

    }
    if (GetCellSimple(Col, Row) == NULL) ret=true;
    if (GetCellSimple(Col, Row+1) ==NULL) ret=true;
    return ret;
}

int __fastcall TCellGrid::GetLeftBorder(int Col, int Row)
{
    int ret;
    if (Col <2 && Row <2)
    {
        ret =GetCellSimple(1,1)->Line.WidthLeft;
    }
    else if (Col <2)
    {
        if (GetCellSimple(1,Row) !=NULL)
        {
            ret =GetCellSimple(1,Row)->Line.WidthLeft;
        }
        else
            ret =GetCellSimple(1,1)->Line.WidthLeft;
    }
    else if (GetCellSimple(Col,Row) !=NULL)
    {
        ret =GetCellSimple(Col,Row)->Line.WidthLeft;
    }
    else if (GetCellSimple(Col-1,Row) !=NULL)
    {
        ret =GetCellSimple(Col-1,Row)->Line.WidthRight;
    }
    else if (GetCellSimple(1,Row) !=NULL)
    {
        ret =GetCellSimple(1,Row)->Line.WidthLeft;
    }
    else if (GetCellSimple(Col,1) !=NULL)
    {
        ret =GetCellSimple(Col,1)->Line.WidthLeft;
    }
    else if (GetCellSimple(Col-1,1) !=NULL)
    {
        ret =GetCellSimple(Col-1,1)->Line.WidthRight;
    }
    else if (GetCellSimple(1,1) !=NULL)
    {
        ret =GetCellSimple(1,1)->Line.WidthLeft;
    }
    return ret;
}

int __fastcall TCellGrid::GetLeftBorderEliminateCurrent(int Col, int Row)
{
    int ret;
    if (Col <2 && Row <2)
        ret =GetCellSimple(1,1)->Line.WidthLeft;
    else if (Col <2)
    {
        if (GetCellSimple(1,Row) !=NULL)
            ret =GetCellSimple(1,Row)->Line.WidthLeft;
        else
            ret =GetCellSimple(1,1)->Line.WidthLeft;
    }
    else if (GetCellSimple(Col-1,Row) !=NULL)
        ret =GetCellSimple(Col-1,Row)->Line.WidthRight;
    else if (GetCellSimple(1,Row) !=NULL)
        ret =GetCellSimple(1,Row)->Line.WidthLeft;
    else if (GetCellSimple(Col,1) !=NULL)
        ret =GetCellSimple(Col,1)->Line.WidthLeft;
    else if (GetCellSimple(Col-1,1) !=NULL)
        ret =GetCellSimple(Col-1,1)->Line.WidthRight;
    else if (GetCellSimple(1,1) !=NULL)
        ret =GetCellSimple(1,1)->Line.WidthLeft;

    return ret;
}

int __fastcall TCellGrid::GetRightBorder(int Col, int Row)
{
    int ret;
    if (Col <2 && Row <2)
        ret =GetCellSimple(1,1)->Line.WidthRight;
    else if (Col <2)
    {
        if (GetCellSimple(1,Row) !=NULL)
            ret =GetCellSimple(1,Row)->Line.WidthRight;
        else
            ret =GetCellSimple(1,1)->Line.WidthRight;
    }
    else if (GetCellSimple(Col,Row) !=NULL)
        ret =GetCellSimple(Col,Row)->Line.WidthRight;
    else if (GetCellSimple(Col+1,Row) !=NULL)
    {
        ret =GetCellSimple(Col+1,Row)->Line.WidthLeft;
    }
    else if (GetCellSimple(1,Row) !=NULL)
    {
        ret =GetCellSimple(1,Row)->Line.WidthRight;
    }
    else if (GetCellSimple(Col,1) !=NULL)
    {
        ret =GetCellSimple(Col,1)->Line.WidthRight;
    }
    else if (GetCellSimple(Col+1,1) !=NULL)
    {
        ret =GetCellSimple(Col+1,1)->Line.WidthLeft;
    }
    else if (GetCellSimple(1,1) !=NULL)
    {
        ret =GetCellSimple(1,1)->Line.WidthRight;
    }
    return ret;
}

int __fastcall TCellGrid::GetRightBorderEliminateCurrent(int Col, int Row)
{
    int ret;
    if (Col <2 && Row <2)
        ret =GetCellSimple(1,1)->Line.WidthRight;
    else if (Col <2)
    {
        if (GetCellSimple(1,Row) !=NULL)
            ret =GetCellSimple(1,Row)->Line.WidthRight;
        else
            ret =GetCellSimple(1,1)->Line.WidthRight;
    }
    else if (GetCellSimple(Col+1,Row) !=NULL)
        ret =GetCellSimple(Col+1,Row)->Line.WidthLeft;
    else if (GetCellSimple(1,Row) !=NULL)
        ret =GetCellSimple(1,Row)->Line.WidthRight;
    else if (GetCellSimple(Col,1) !=NULL)
        ret =GetCellSimple(Col,1)->Line.WidthRight;
    else if (GetCellSimple(Col+1,1) !=NULL)
        ret =GetCellSimple(Col+1,1)->Line.WidthLeft;
    else if (GetCellSimple(1,1) !=NULL)
        ret =GetCellSimple(1,1)->Line.WidthRight;
    return ret;
}

int __fastcall TCellGrid::GetTopBorder(int Col, int Row)
{
    int ret;
    if (Col <2 && Row <2)
    {
        ret =GetCellSimple(1,1)->Line.WidthTop;
    }
    else if (Row <2)
    {
        if (GetCellSimple(Col,1) !=NULL)
        {
            ret =GetCellSimple(Col,1)->Line.WidthTop;
        }
        else
            ret =GetCellSimple(1,1)->Line.WidthTop;
    }
    else if (GetCellSimple(Col,Row) !=NULL)
    {
        ret =GetCellSimple(Col,Row)->Line.WidthTop;
    }
    else if (GetCellSimple(Col,Row-1) !=NULL)
    {
        ret =GetCellSimple(Col,Row-1)->Line.WidthBottom;
    }
    else if (GetCellSimple(Col,1) !=NULL)
    {
        ret =GetCellSimple(Col,1)->Line.WidthTop;
    }
    else if (GetCellSimple(1,Row-1) !=NULL)
    {
        ret =GetCellSimple(1,Row-1)->Line.WidthBottom;
    }
    else if (GetCellSimple(1,Row) !=NULL)
    {
        ret =GetCellSimple(1,Row)->Line.WidthTop;
    }
    else if (GetCellSimple(1,1) !=NULL)
    {
        ret =GetCellSimple(1,1)->Line.WidthTop;
    }
    return ret;
}


int __fastcall TCellGrid::GetTopBorderEliminateCurrent(int Col, int Row)
{
    int ret;
    if (Col <2 && Row <2)
        ret =GetCellSimple(1,1)->Line.WidthTop;
    else if (Row <2)
    {
        if (GetCellSimple(Col,1) !=NULL)
            ret =GetCellSimple(Col,1)->Line.WidthTop;
        else
            ret =GetCellSimple(1,1)->Line.WidthTop;
    }
    else if (GetCellSimple(Col,Row-1) !=NULL)
        ret =GetCellSimple(Col,Row-1)->Line.WidthBottom;
    else if (GetCellSimple(Col,1) !=NULL)
        ret =GetCellSimple(Col,1)->Line.WidthTop;
    else if (GetCellSimple(1,Row-1) !=NULL)
        ret =GetCellSimple(1,Row-1)->Line.WidthBottom;
    else if (GetCellSimple(1,Row) !=NULL)
        ret =GetCellSimple(1,Row)->Line.WidthTop;
    else if (GetCellSimple(1,1) !=NULL)
        ret =GetCellSimple(1,1)->Line.WidthTop;
    return ret;
}

int __fastcall TCellGrid::GetBottomBorder(int Col, int Row)
{
    int ret;
    if (Col <2 && Row <2)
    {
        ret =GetCellSimple(1,1)->Line.WidthBottom;
    }
    else if (Row <2)
    {
        if (GetCellSimple(Col, 1) !=NULL)
        {
            ret =GetCellSimple(Col, 1)->Line.WidthBottom;
        }
        else
            ret =GetCellSimple(1,1)->Line.WidthBottom;
    }
    else if (GetCellSimple(Col,Row) !=NULL)
    {
        ret =GetCellSimple(Col,Row)->Line.WidthBottom;
    }
    else if (GetCellSimple(Col,Row+1) !=NULL)
    {
        ret =GetCellSimple(Col,Row+1)->Line.WidthTop;
    }
    else if (GetCellSimple(1,Row) !=NULL)
    {
        ret =GetCellSimple(1,Row)->Line.WidthBottom;
    }
    else if (GetCellSimple(Col,1) !=NULL)
    {
        ret =GetCellSimple(Col,1)->Line.WidthBottom;
    }
    else if (GetCellSimple(1,Row+1) !=NULL)
    {
        ret =GetCellSimple(1,Row+1)->Line.WidthTop;
    }
    else if (GetCellSimple(1,1) !=NULL)
    {
        ret =GetCellSimple(1,1)->Line.WidthBottom;
    }
    return ret;
}

int __fastcall TCellGrid::GetBottomBorderEliminateCurrent(int Col, int Row)
{
    int ret;
    if (Col <2 && Row <2)
        ret =GetCellSimple(1,1)->Line.WidthBottom;
    else if (Row <2)
    {
        if (GetCellSimple(Col, 1) !=NULL)
            ret =GetCellSimple(Col, 1)->Line.WidthBottom;
        else
            ret =GetCellSimple(1,1)->Line.WidthBottom;
    }
    else if (GetCellSimple(Col,Row+1) !=NULL)
        ret =GetCellSimple(Col,Row+1)->Line.WidthTop;
    else if (GetCellSimple(1,Row) !=NULL)
        ret =GetCellSimple(1,Row)->Line.WidthBottom;
    else if (GetCellSimple(Col,1) !=NULL)
        ret =GetCellSimple(Col,1)->Line.WidthBottom;
    else if (GetCellSimple(1,Row+1) !=NULL)
        ret =GetCellSimple(1,Row+1)->Line.WidthTop;
    else if (GetCellSimple(1,1) !=NULL)
        ret =GetCellSimple(1,1)->Line.WidthBottom;
    return ret;
}

//---------------------------------------------------------------------------
