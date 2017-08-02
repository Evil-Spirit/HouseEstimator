//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include <Math.hpp>
#include "CellGrid.h"
#include "TextEditU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

void __fastcall TCellGrid::SetNumerColRow(int ACol, int ARow, int type, TColor ColorBk)
{
    if (type ==1)
    {
        if (ACol ==1 && ARow >1)
        {
            AnsiString str;
            int CaptionLength;
            TRect rect, rectt;

            if (Canvas->Brush->Color != ColorBk)
                Canvas->Brush->Color = ColorBk;

            rect = GetGridRectToRectPixelNotUnionAndScroll(ACol,ARow);
            rectt = GetGridRectToRectPixelNotUnionReal(1,1);

            rect.Left = rectt.Left;
            rect.Right = rectt.Right;
//            str = IntToStr(ARow-1);
            str = IntToStr(ARow);
            CaptionLength = str.Length();

            if (Canvas->Font->Style !=TFontStyles())
                Canvas->Font->Style = TFontStyles();
            if (Canvas->Font->Color != clBlack)
                Canvas->Font->Color = clBlack;
            if (Canvas->Font->Size != 8)
                Canvas->Font->Size = 8;
            if (Canvas->Font->Name != "MS Sans Serif")
                Canvas->Font->Name = "MS Sans Serif";

            ::DrawText(Canvas->Handle, str.c_str(), CaptionLength, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        }
        else if (ACol >1 && ARow ==1)
        {
            AnsiString str;
            int CaptionLength;
            TRect rect, rectt;

            if (Canvas->Brush->Color != ColorBk)
                Canvas->Brush->Color = ColorBk;

            rect = GetGridRectToRectPixelNotUnionAndScroll(ACol,ARow);
            rectt = GetGridRectToRectPixelNotUnionReal(1,1);

            rect.Top = rectt.Top;
            rect.Bottom = rectt.Bottom;
//            str = IntToStr(ACol-1);
            str = IntToStr(ACol);
            CaptionLength = str.Length();

            if (Canvas->Font->Style !=TFontStyles())
                Canvas->Font->Style = TFontStyles();
            if (Canvas->Font->Color != clBlack)
                Canvas->Font->Color = clBlack;
            if (Canvas->Font->Size != 8)
                Canvas->Font->Size = 8;
            if (Canvas->Font->Name != "MS Sans Serif")
                Canvas->Font->Name = "MS Sans Serif";

            ::DrawText(Canvas->Handle, str.c_str(), CaptionLength, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        }
    }
}

bool  __fastcall TCellGrid::PointInGridRect(int Col, int Row,TGridRect Rect)
{
    return ((Col >= Rect.Left) && (Col <= Rect.Right) && (Row >= Rect.Top) && (Row <= Rect.Bottom));
}

void  __fastcall TCellGrid::DrawTextU2(int CurCol, int CurRow, const TRect& RectDrawText)// Рисование текста
{
    TCell* Cell = GetCell(CurCol,CurRow);
    AnsiString str =Cell->Text;
    int CaptionLength =str.Length();
    if (CaptionLength >0)
    {
        Canvas->Font->Name  =Cell->FontName;
        Canvas->Font->Size  =Cell->CellFlags.FontSize;
        Canvas->Font->Color =Cell->FontColor;

        TFontStyles Style;
        switch (Cell->CellFlags.FontStyle)
        {
            case 0:
            {// Обычный
                Style.Clear();
            }break;
            case 1:
            {// Курсив
                Style <<fsItalic;
            }break;
            case 2:
            {// Жирный
                Style <<fsBold;
            }break;
            case 3:
            {// Жирный курсив
                Style <<fsBold <<fsItalic;
            }break;
        }
        if (Cell->CellFlags.FontStrikeOut ==1)
        {// Зачеркнутый шрифт
            Style <<fsStrikeOut;
        }
        if (Cell->CellFlags.FontUnderline ==1)
        {// Подчеркнутый шрифт
            Style <<fsUnderline;
        }
        Canvas->Font->Style =Style;

        int iAlign;
        TRect rectMin=RectDrawText;
        rectMin.Right -=1;
        rectMin.Bottom -=2;
        if (Cell->CellFlags.TextWordBreak ==1)
            str =EditText->FormatMultiLine(str, rectMin);

        CaptionLength =str.Length();
        if (Cell->CellFlags.TextWordBreak ==1)
        {
            iAlign =DT_WORDBREAK | DT_CALCRECT;
            ::DrawText(Canvas->Handle, str.c_str(), CaptionLength, &rectMin, iAlign);
            rectMin.Right =RectDrawText.Right;
            iAlign =DT_WORDBREAK;
        }
        else
            iAlign=DT_SINGLELINE;

        if (Cell->CellFlags.TextHAlign ==0)
            iAlign =iAlign |DT_LEFT;
        if (Cell->CellFlags.TextHAlign ==1)
            iAlign =iAlign |DT_CENTER;
        if (Cell->CellFlags.TextHAlign ==2)
            iAlign =iAlign |DT_RIGHT;

        TRect rectCalc=RectDrawText;
        if (Cell->CellFlags.TextVAlign ==0)
            iAlign =iAlign |DT_TOP;

        if (Cell->CellFlags.TextVAlign ==1)
        {
            iAlign          =iAlign |DT_VCENTER;
            int icentermax  =(RectDrawText.Bottom-RectDrawText.Top)/2;
            int icentermin  =(rectMin.Bottom-rectMin.Top)/2;
            rectMin.Top     +=icentermax-icentermin;
            rectMin.Bottom  +=icentermax-icentermin;
        }
        if (Cell->CellFlags.TextVAlign ==2)
        {
            iAlign          =iAlign |DT_BOTTOM;
            int iW2         =RectDrawText.Bottom-rectMin.Bottom;
            rectMin.Bottom  =RectDrawText.Bottom;
            rectMin.Top     +=iW2;
        }

        if (rectMin.Bottom -rectMin.Top > RectDrawText.Bottom -RectDrawText.Top)
            rectMin =RectDrawText;

//        HFONT OldFont =SelectObject(Canvas->Handle, Font->Handle);
        ::DrawText(Canvas->Handle, str.c_str(), CaptionLength, &rectMin,iAlign);
//        SelectObject(Canvas->Handle, OldFont);
    }
}

void  __fastcall TCellGrid::SetColorCanvas(int CurCol, int CurRow)
{
    TRect CurrentAnchorSelect =GetAnchorCurrentSort();
    TCell* Cell2 = GetCell(CurCol,CurRow);
    if (Cell2!= NULL)
    {// Ячейка Существует
        if (Cell2->UnionRect != NULL)
        {// Ячейка Объедененная
            if (SelectColumn || SelectString)
            {// Столбец
                if (Rect1InRect2(*Cell2->UnionRect,CurrentAnchorSelect))
                {
                    Canvas->Brush->Color =SetColorCursor(Cell2->bgColor);
                } else
                    Canvas->Brush->Color =Cell2->bgColor;
            } else
            if (SelectTable)
            {
                Canvas->Brush->Color =SetColorCursor(Cell2->bgColor);
            } else
            {
                if (Rect1InRect2(TRect(StartMouseDown.X,StartMouseDown.Y,StartMouseDown.X,StartMouseDown.Y),*Cell2->UnionRect))
                {
                    Canvas->Brush->Color =Cell2->bgColor;
                } else
                if (Rect1InRect2(TRect(CurCol,CurRow,CurCol,CurRow),CurrentAnchorSelect))
                {
                    if (StartMouseDown.X ==CurCol && StartMouseDown.Y ==CurRow)
                    {
                        Canvas->Brush->Color =Cell2->bgColor;
                    } else
                        Canvas->Brush->Color =SetColorCursor(Cell2->bgColor);
                } else
                {
                    Canvas->Brush->Color =Cell2->bgColor;
                }
            }

        } else
        {// Ячейка НЕ Объедененная
            if (Rect1InRect2(TRect(CurCol,CurRow,CurCol,CurRow),CurrentAnchorSelect))
            {
                if (StartMouseDown.X ==CurCol && StartMouseDown.Y ==CurRow)
                {
                    Canvas->Brush->Color =Cell2->bgColor;
                } else
                    Canvas->Brush->Color =SetColorCursor(Cell2->bgColor);
            } else
            {
                Canvas->Brush->Color =Cell2->bgColor;
            }
        }
    } else
    {// Ячейка пустая
        if (GetCell(CurCol,1) !=NULL)
        {// Столбец
            if (Rect1InRect2(TRect(CurCol,CurRow,CurCol,CurRow),CurrentAnchorSelect))
            { // В области выделения
                if (StartMouseDown.X ==CurCol && StartMouseDown.Y ==CurRow)
                {
                    Canvas->Brush->Color =GetCell(CurCol,1)->bgColor;
                } else
                    Canvas->Brush->Color =SetColorCursor(GetCell(CurCol,1)->bgColor);
            } else
            { //За областью выделения
                Canvas->Brush->Color =GetCell(CurCol,1)->bgColor;
            }
        } else
        if (GetCell(1,CurRow) !=NULL)
        {// Строка
            if (Rect1InRect2(TRect(CurCol,CurRow,CurCol,CurRow),CurrentAnchorSelect))
            { // В области выделения
                if (StartMouseDown.X ==CurCol && StartMouseDown.Y ==CurRow)
                {
                    Canvas->Brush->Color =GetCell(1,CurRow)->bgColor;
                } else
                    Canvas->Brush->Color =SetColorCursor(GetCell(1,CurRow)->bgColor);
            } else
            { //За областью выделения
                Canvas->Brush->Color =GetCell(1,CurRow)->bgColor;
            }
        } else
        {// Таблица
            if (Rect1InRect2(TRect(CurCol,CurRow,CurCol,CurRow),CurrentAnchorSelect))
            { // В области выделения
                if (StartMouseDown.X ==CurCol && StartMouseDown.Y ==CurRow)
                {
                    Canvas->Brush->Color =GetCell(1,1)->bgColor;
                } else
                    Canvas->Brush->Color =SetColorCursor(GetCell(1,1)->bgColor);
            } else
            { //За областью выделения
                Canvas->Brush->Color =GetCell(1,1)->bgColor;
            }
        }
    }

}

void  __fastcall TCellGrid::DrawCells(long ACol,long ARow,int StartX,int StartY,int StopX,int StopY,TColor Color,TGridDrawState IncludeDrawState)
{
    Canvas->Lock();
    long CurCol, CurRow;
    TRect Where;
    TGridDrawState DrawState;
    TRect recttemp;
    TRect FixedOne;

    ColorCursor =clWhite;

// ---- Предварительный расчет ---
    TRect RectReal_22 =GetGridRectToRectPixelNotUnionReal(2,2);

    TRect RectReal_1FixedRows =GetGridRectToRectPixelNotUnionReal(1,FixedRows);
    TRect RectReal_FixedCols1 =GetGridRectToRectPixelNotUnionReal(FixedCols,1);

    TRect RectReal_FixedCols2 =GetGridRectToRectPixelNotUnionReal(FixedCols,2);
    TRect RectReal_2FixedRows =GetGridRectToRectPixelNotUnionReal(2,FixedRows);
// ---- Предварительный расчет --- END

    CurRow = ARow;
    Where.Top = StartY;
    while ((Where.Top < StopY) && (CurRow < RowCount))
    {
        CurCol = ACol;
        Where.Left = StartX;
        Where.Bottom = Where.Top + RowHeights[CurRow];
        while ((Where.Left < StopX) && (CurCol < ColCount))
        {
            Where.Right = Where.Left + ColWidths[CurCol];
            if ((Where.Right > Where.Left) && RectVisible(Canvas->Handle, &Where))
            {
                DrawState = IncludeDrawState;
                Focused = IsActiveControl();

                if (!DrawState.Contains(gdFocused)||
                    !Options.Contains(goEditing)||
                    !FEditorMode ||
                    ComponentState.Contains(csDesigning)
                )
                {
                    if ((DefaultDrawing)||(ComponentState.Contains(csDesigning)))
                    {

                        ColorSelect =(TColor)RGB(109,149,213); // Выделение нескольких яччек
                        if (MoveCellBorder && !PointInRect(CurCol,CurRow,TRect(StartMouseDown.X,StartMouseDown.Y,MouseUpCoord.X,MouseUpCoord.Y)))
                            ColorSelect =(TColor)RGB(255,255,255); // Выделение нескольких яччек

                        if (CurRow >1 && CurCol >1)
                            SetColorCanvas(CurCol, CurRow);
                        else
                        {
                            if (Canvas->Brush->Color != FixedColor)
                                Canvas->Brush->Color = FixedColor;
                            if (SelectTable)
                            {
                                if ((CurCol ==1)||(CurRow ==1))
                                {// Таблица
                                    Canvas->Brush->Color = ColorFixedSelectAll;
                                    ColorCursor = ColorFixedSelect;
                                }
                            } else
                            {
                                int Start = StartMouseDown.Y;
                                int End = MousePosCellMoveSelect.Y;
                                if (Start>End)
                                {
                                    Start = MousePosCellMoveSelect.Y;
                                    End = StartMouseDown.Y;
                                }
                                if (SelectString &&
                                    CurRow>=Start &&
                                    CurRow<=End)
                                {
                                    if ((CurCol ==1)&&(CurRow !=1))
                                    {// Строка
                                        Canvas->Brush->Color = ColorFixedSelect;
                                        ColorCursor = Canvas->Brush->Color;
                                    }
                                }

                                Start = StartMouseDown.X;
                                End = MousePosCellMoveSelect.X;
                                if (Start>End)
                                {
                                    Start = MousePosCellMoveSelect.X;
                                    End = StartMouseDown.X;
                                }
                                if (SelectColumn &&
                                    CurCol>=Start &&
                                    CurCol<=End)
                                {
                                    if ((CurRow ==1)&&(CurCol !=1))
                                    {// Столбец
                                        Canvas->Brush->Color = ColorFixedSelect;
                                        ColorCursor = Canvas->Brush->Color;
                                    }
                                }
                            }
                        }
                        if (StartVisible)
                        {
                            TRect temprect;
                            HRGN MyRgn;
                            TRect rectCurColCurRow;
                            TCell* getcell =GetCell(CurCol,CurRow);
                            if (CurCol ==0 || CurRow ==0 || (getcell!= NULL && getcell->UnionRect != NULL))
                                rectCurColCurRow =GetGridRectToRectPixelNotUnionAndScroll(CurCol,CurRow);

                            if (getcell!= NULL)
                            {// Ячейка существует
                                TRect RectClipText;
                                TRect RectDrawText;

                                if (getcell->UnionRect != NULL &&
                                 (!(CurCol > getcell->UnionRect->Left &&
                                    CurCol < getcell->UnionRect->Right &&
                                    CurRow > getcell->UnionRect->Top &&
                                    CurRow < getcell->UnionRect->Bottom)
                                )
                                )
                                {// Ячейка объедененная
                                    if (CurCol ==0 || CurRow ==0 )
                                    {
                                        recttemp =rectCurColCurRow;
                                        if (CurCol ==0)
                                        {
                                            recttemp.Left =1;
                                            recttemp.Right =SumCol(0,0);

                                            TRect RealRect, RealRect2;
                                            if (recttemp.Top < RectReal_1FixedRows .Top)
                                            {
                                                RealRect =GetGridRectToRectPixelUnionReal(CurCol,CurRow);
                                                RealRect2 = recttemp;
                                                RealRect2.Top =RealRect2.Bottom -(RealRect.Bottom-RealRect.Top);
                                                recttemp=RealRect2;
                                            }
                                        }
                                        if (CurRow ==0)
                                        {
                                            recttemp.Top =1;
                                            recttemp.Bottom =SumRow(0,0);
                                        }
                                        Canvas->FillRect(recttemp);
                                        AnsiString str = getcell->Text;
                                        int CaptionLength = str.Length();

                                        if (CaptionLength >0)
                                            ::DrawText(Canvas->Handle, str.c_str(), CaptionLength, &recttemp, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

                                    }
                                    else
                                    {
                                        int NewColStart,NewRowStart,NewColEnd,NewRowEnd;
                                        // получаем регион в ячейках указывающий на объедененную ячеку

                                        TRect rectCurrent = *getcell->UnionRect;
                                        NewColStart = getcell->UnionRect->Left;
                                        NewRowStart = getcell->UnionRect->Top;
                                        NewColEnd = getcell->UnionRect->Right;
                                        NewRowEnd = getcell->UnionRect->Bottom;

                                        recttemp =rectCurColCurRow;
                                        recttemp.Top+=1;
                                        recttemp.Left+=1;
                                        recttemp.Right-=1;
                                        recttemp.Bottom-=1;

                                        if ((GetCellSimple(CurCol, CurRow)->Line.WidthRight <2)&&
                                            (NewColEnd == CurCol))
                                        {
                                            CellLineRightColorBk(CurCol, CurRow);
                                        }
                                        if ((GetCellSimple(CurCol, CurRow)->Line.WidthBottom <2)&&
                                            (NewRowEnd == CurRow))
                                        {
                                            CellLineBottomColorBk(CurCol, CurRow);
                                        }
                                        if (CurRow ==NewRowStart)
                                            CellLineTopColorBk(CurCol, CurRow);
                                        if (CurCol ==NewColStart)
                                            CellLineLeftColorBk(CurCol, CurRow);

                                        if ((CurCol ==NewColStart && CurRow ==NewRowStart) ||
                                            (CurCol ==NewColEnd && CurRow ==NewRowEnd)
                                        )
                                        {
                                            if ((NewRowStart>1)&&(NewRowStart<FixedRows)&&
                                                (NewColStart>1)&&(NewColStart<FixedCols)
                                            )
                                            {
                                                MyRgn = ::CreateRectRgn(RectReal_22.Left,RectReal_22.Top,recttemp.Right+2,recttemp.Bottom+2);
                                                ::SelectClipRgn(Canvas->Handle,MyRgn);

                                                Canvas->FillRect(recttemp);

                                                RectClipText.Left=RectReal_22.Left;
                                                RectClipText.Top=RectReal_22.Top;
                                                RectClipText.Right=recttemp.Right+2;
                                                RectClipText.Bottom=recttemp.Bottom+2;
                                                RectDrawText=recttemp;

                                                ::SelectClipRgn(Canvas->Handle,NULL);
                                            }
                                            else if (NewRowStart>1 && NewRowStart<FixedRows)
                                            {
                                                MyRgn = ::CreateRectRgn(RectReal_FixedCols2.Left,RectReal_FixedCols2.Top,recttemp.Right+2,recttemp.Bottom+2);
                                                ::SelectClipRgn(Canvas->Handle,MyRgn);
                                                Canvas->FillRect(recttemp);
                                                ::SelectClipRgn(Canvas->Handle,NULL);

                                                TRect RealRect, RealRect2;
                                                if (recttemp.Top < RectReal_1FixedRows.Top)
                                                {
                                                    RealRect =GetGridRectToRectPixelUnionReal(CurCol,CurRow);
                                                    RealRect2 = recttemp;
                                                    RealRect2.Top =RealRect2.Bottom -(RealRect.Bottom-RealRect.Top);

                                                    RectClipText.Left =RectReal_FixedCols2.Left;
                                                    RectClipText.Top =RectReal_FixedCols2.Top;
                                                    RectClipText.Right =recttemp.Right+2;
                                                    RectClipText.Bottom =recttemp.Bottom+2;
                                                    RectDrawText =RealRect2;

                                                }
                                                else
                                                {
                                                    RectClipText.Left =RectReal_FixedCols2.Left;
                                                    RectClipText.Top =RectReal_FixedCols2.Top;
                                                    RectClipText.Right =recttemp.Right+2;
                                                    RectClipText.Bottom =recttemp.Bottom+2;
                                                    RectDrawText =recttemp;

                                                }
                                            }
                                            else
                                            {
                                                if ((NewColStart>1)&&(NewColStart<FixedCols))
                                                {
                                                    MyRgn = ::CreateRectRgn(RectReal_2FixedRows.Left,RectReal_2FixedRows.Top,recttemp.Right+2,recttemp.Bottom+2);
                                                    ::SelectClipRgn(Canvas->Handle,MyRgn);
                                                    Canvas->FillRect(recttemp);
                                                    ::SelectClipRgn(Canvas->Handle,NULL);

                                                    TRect RealRect, RealRect2;
                                                    if (recttemp.Top < RectReal_1FixedRows.Top)
                                                    {
                                                        RealRect =GetGridRectToRectPixelUnionReal(CurCol,CurRow);
                                                        RealRect2 = recttemp;
                                                        RealRect2.Top =RealRect2.Bottom -(RealRect.Bottom-RealRect.Top);

                                                        RectClipText.Left =RectReal_2FixedRows.Left;
                                                        RectClipText.Top =RectReal_2FixedRows.Top;
                                                        RectClipText.Right =recttemp.Right+2;
                                                        RectClipText.Bottom =recttemp.Bottom+2;
                                                        RectDrawText =RealRect2;
                                                    }
                                                    else
                                                    {
                                                        RectClipText.Left =RectReal_2FixedRows.Left;
                                                        RectClipText.Top =RectReal_2FixedRows.Top;
                                                        RectClipText.Right =recttemp.Right+2;
                                                        RectClipText.Bottom =recttemp.Bottom+2;
                                                        RectDrawText =recttemp;
                                                    }
                                                }
                                                else
                                                {
                                                    int xx,yy;
                                                    xx =RectReal_FixedCols2.Left;
                                                    yy =RectReal_2FixedRows.Top;
                                                    MyRgn = ::CreateRectRgn(xx,yy,recttemp.Right+2,recttemp.Bottom+2);
                                                    ::SelectClipRgn(Canvas->Handle,MyRgn);
                                                    Canvas->FillRect(recttemp);
                                                    ::SelectClipRgn(Canvas->Handle,NULL);

                                                    TRect RealRect, RealRect2;
                                                    int iTop =RectReal_1FixedRows.Top;
                                                    int iLeft =RectReal_FixedCols1.Left;
                                                    if ((recttemp.Top < iTop)||
                                                        (recttemp.Left < iLeft)
                                                    )
                                                    {
                                                        RealRect2 = recttemp;
                                                        RealRect =GetGridRectToRectPixelUnionReal(CurCol,CurRow);
                                                        if (recttemp.Top < iTop)
                                                        {
                                                            if ((OldRectDrawCellFixedT == recttemp.Bottom)&&(BeEqualRect(rectCurrent,CurrentRectDrawUnionFixed)))
                                                            {
                                                                RealRect2.Top = OldRectDrawCellFixedTop;
                                                            } else
                                                            {
                                                                OldRectDrawCellFixedT =recttemp.Bottom;
                                                                RealRect2.Top =RealRect2.Bottom -(RealRect.Bottom-RealRect.Top);
                                                                CurrentRectDrawUnionFixed =rectCurrent;
                                                                OldRectDrawCellFixedTop =RealRect2.Top;
                                                            }
                                                        }
                                                        if (recttemp.Left < iLeft)
                                                        {
                                                            if ((OldRectDrawCellFixedL == recttemp.Right)&&(BeEqualRect(rectCurrent,CurrentRectDrawUnionFixed)))
                                                                RealRect2.Left = OldRectDrawCellFixedLeft;
                                                            else
                                                            {
                                                                OldRectDrawCellFixedL =recttemp.Right;
                                                                RealRect2.Left =RealRect2.Right -(RealRect.Right-RealRect.Left);
                                                                if (RealRect2.Left <0)
                                                                    RealRect2.Left =0;
                                                                CurrentRectDrawUnionFixed =rectCurrent;
                                                                OldRectDrawCellFixedLeft =RealRect2.Left;
                                                            }
                                                        }
                                                        RectClipText.Left =xx;
                                                        RectClipText.Top =yy;
                                                        RectClipText.Right =recttemp.Right+2;
                                                        RectClipText.Bottom =recttemp.Bottom+2;
                                                        RectDrawText =RealRect2;
                                                    }
                                                    else
                                                    {
                                                        RectClipText.Left =xx;
                                                        RectClipText.Top =yy;
                                                        RectClipText.Right =recttemp.Right+2;
                                                        RectClipText.Bottom =recttemp.Bottom+2;
                                                        RectDrawText =recttemp;
                                                    }
                                                }
                                            }
                                            if (getcell->Text.Length()>0)
                                            {
                                                HRGN MyRgn3;
                                                MyRgn3 = ::CreateRectRgn(RectClipText.Left,RectClipText.Top,RectClipText.Right,RectClipText.Bottom);
                                                ::SelectClipRgn(Canvas->Handle,MyRgn3);
                                                DrawTextU2(CurCol, CurRow, RectDrawText);
                                                ::SelectClipRgn(Canvas->Handle,NULL);
                                                ::DeleteObject(MyRgn3);
                                            }
                                        }
                                        Line(CurCol, CurRow, Canvas->Brush->Color);

                                        int iClipL=0;
                                        int iClipR=0;

                                        int iClipT=0;
                                        int iClipB=0;

                                        if (SelectColumn)
                                        {// Столбец
                                            if (NewColStart ==CurCol) iClipL=-3;
                                            if (NewColEnd ==CurCol) iClipR=+3;

                                            if (NewColStart ==CurCol || NewColEnd ==CurCol)
                                                DrawCursorU2(CurCol, CurRow, Where.Left+iClipR, Where.Top+iClipB , Where.Right+1+iClipL, Where.Bottom+1+iClipT);

                                        }
                                        else
                                        if (SelectString)
                                        {// Строка
                                            if (NewRowStart ==CurRow) iClipT=-3;
                                            if (NewRowEnd ==CurRow) iClipB=+3;

                                            if (NewRowStart ==CurRow || NewRowEnd ==CurRow)
                                                DrawCursorU2(CurCol, CurRow, Where.Left+iClipR, Where.Top+iClipB , Where.Right+1+iClipL, Where.Bottom+1+iClipT);

                                        }
                                        else
                                        {// ячейка
                                            DrawCursorU2(CurCol, CurRow, Where.Left+iClipR, Where.Top+iClipB , Where.Right+1+iClipL, Where.Bottom+1+iClipT);
                                        }
                                    }
                                }
                                else
                                {// Заполненная ячейка
                                    if (!(getcell->UnionRect != NULL &&
                                        (CurCol > getcell->UnionRect->Left &&
                                        CurCol < getcell->UnionRect->Right &&
                                        CurRow > getcell->UnionRect->Top &&
                                        CurRow < getcell->UnionRect->Bottom))
                                    )
                                    {
                                        Canvas->FillRect(Where);
                                        DrawTextU2(CurCol, CurRow, Where);
                                        Line(CurCol, CurRow, Canvas->Brush->Color);
                                        DrawCursorU2(CurCol, CurRow, Where.Left, Where.Top, Where.Right+1, Where.Bottom+1);
                                    }
                                }
                            }
                            else
                            {// Пустая ячейка
                                if (CurCol ==0 || CurRow ==0 )
                                {
                                    temprect =Where;
                                    temprect.Bottom +=1;
                                    temprect.Right +=1;
                                    Canvas->FillRect(temprect);
                                }
                                else
                                {
                                    Canvas->FillRect(Where);
                                    Line(CurCol, CurRow, Canvas->Brush->Color);
                                    DrawCursorU2(CurCol, CurRow, Where.Left, Where.Top, Where.Right+1, Where.Bottom+1);
                                }
                            }
                            ::DeleteObject(MyRgn);
//---------- Область всех ячеек (пустых, созданных) ---------------------------
// Рисует линии на первых ячейка

                            FixedOne =Where;
                            FixedOne.Right++;
                            FixedOne.Bottom++;
                            if (CurCol >0 && CurRow >0)
                            {
                                if (CurCol ==1)
                                   DrawEdge(Canvas->Handle, (RECT*)&FixedOne, BDR_RAISEDINNER, BF_BOTTOM | BF_RIGHT | BF_LEFT);
                                if (CurRow ==1)
                                    DrawEdge(Canvas->Handle, (RECT*)&FixedOne, BDR_RAISEDINNER, BF_BOTTOM | BF_RIGHT | BF_TOP);
                            }
                            else if (CurRow ==0 ||CurCol ==0)
                            {
                                if (CurCol ==0 &&
                                    getcell != NULL &&
                                    getcell->UnionRect != NULL)
                                {
                                    FixedOne =rectCurColCurRow;
                                    FixedOne.Left = 1;
                                    FixedOne.Right =SumCol(0,0);
                                    SectionLine(FixedOne,1);
                                }
                                else if (CurRow ==0 &&
                                        getcell != NULL &&
                                        getcell->UnionRect != NULL)
                                {
                                    FixedOne =rectCurColCurRow;
                                    FixedOne.Top = 1;
                                    FixedOne.Bottom =SumRow(0,0);
                                    SectionLine(FixedOne,2);
                                }
                            }
                            SetNumerColRow(CurCol, CurRow,1, Canvas->Brush->Color);// Нумерация первых ячеек
//-------------------------------- END ---------------------------------
                        }
                    }
                }
            }
            Where.Left = Where.Right + DrawInfo.Horz.EffectiveLineWidth;
            CurCol++;
        }
        Where.Top = Where.Bottom + DrawInfo.Vert.EffectiveLineWidth;
        CurRow++;
    }
    Canvas->Unlock();
}

void __fastcall TCellGrid::Paint()
{
    if (UseRightToLeftAlignment())
        ChangeGridOrientation(true);
    UpdateRect = Canvas->ClipRect;
    CalcDrawInfo(DrawInfo);
    GridLineWidth = 1;
//    { Draw the cells in the four areas }
    Sel = Selection;
    TGridDrawState set;
    set.Clear(); // Пустое множество
    if (CursorMoveStarted())
        DrawCursorMove(CurrentMouseCoordTimer.X,CurrentMouseCoordTimer.Y);

    DrawCells(LeftCol, TopRow, DrawInfo.Horz.FixedBoundary - FColOffset, DrawInfo.Vert.FixedBoundary, DrawInfo.Horz.GridBoundary, DrawInfo.Vert.GridBoundary, Color, set);
    DrawCells(0, 0, 0, 0, DrawInfo.Horz.FixedBoundary, DrawInfo.Vert.FixedBoundary, FixedColor,set);
    DrawCells(LeftCol, 0, DrawInfo.Horz.FixedBoundary - FColOffset, 0, DrawInfo.Horz.GridBoundary, DrawInfo.Vert.FixedBoundary, FixedColor, set);
    DrawCells(0, TopRow, 0, DrawInfo.Vert.FixedBoundary, DrawInfo.Horz.FixedBoundary, DrawInfo.Vert.GridBoundary, FixedColor, set);

    if (CursorMoveStarted())
    {
        DrawCursorMove(CurrentMouseCoordTimer.X,CurrentMouseCoordTimer.Y);
        TRect Rect =
            GetUnionRect(
            GetGridRectToRectPixelNotUnionAndScroll(
            StartMouseDown.X, StartMouseDown.Y),
            GetGridRectToRectPixelNotUnionAndScroll(
            MouseUpCoord.X, MouseUpCoord.Y)
            );
        DrawCursor(Rect);
    }

//      { Fill in area not occupied by cells }
// *************** Обработка за областью таблицы
    if (DrawInfo.Horz.GridBoundary < DrawInfo.Horz.GridExtent)
    {
        Canvas->Brush->Color = Color;
        Canvas->FillRect(Rect(DrawInfo.Horz.GridBoundary, 0, DrawInfo.Horz.GridExtent, DrawInfo.Vert.GridBoundary));
    }
    if (DrawInfo.Vert.GridBoundary < DrawInfo.Vert.GridExtent)
    {
        Canvas->Brush->Color = Color;
        Canvas->FillRect(Rect(0, DrawInfo.Vert.GridBoundary, DrawInfo.Horz.GridExtent, DrawInfo.Vert.GridExtent));
    }
// *************************** END
    if (UseRightToLeftAlignment()) ChangeGridOrientation(false);
}

bool TCellGrid::CursorMoveStarted()
{
    return ((MoveCellBorder) && (CurrentMouseCoordTimer.X>0 && CurrentMouseCoordTimer.Y>0));
}
