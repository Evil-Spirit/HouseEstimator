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

void __fastcall TCellGrid::Test_Speed()
{
//    for (int y=100; y>=2; y--)
//        for (int x=10; x>=2; x--)
    TRect rect =TRect(2,2,DrawInfo.Horz.LastFullVisibleCell+1,DrawInfo.Vert.LastFullVisibleCell+1);
    for (int y=rect.Bottom; y>=rect.Top; y--)
        for (int x=rect.Right; x>=rect.Left; x--)
        {
            gCellFlag->CellFlags.FontSize   =6+random(10);
            gCellFlag->f_FontSize           =true;

            gCellFlag->FontColor            =(TColor)RGB(random(255),random(255),random(255));
            gCellFlag->f_FontColor          =true;

            gCellFlag->bgColor              =(TColor)RGB(random(255),random(255),random(255));
            gCellFlag->f_bgColor            =true;
            gCellFlag->LineColorNot         =true;
            gCellFlag->f_LineColorNot       =true;

            gCellFlag->f_Text               =true;
            gCellFlag->Text                 ="X: " + IntToStr(x) + " - Y: " + IntToStr(y);

            if (GetCellSimple(x,y) !=NULL)
                ClearCell(x,y);

            if (Matrix->GetCellSimple(x,y) !=NULL)
                Matrix->DelCell(x,y);
            Matrix->NewCell(x,y);
            TCellFlag* setcell =Matrix->GetCellSimple(x,y);
            SetAllFlag(setcell,false);
            CopyFlag1ToFlag2(gCellFlag,setcell);
        }
        Matrix->RectCopy =rect;
        PasteBuffInGrid(rect.Left,rect.Top);

    Invalidate();

}

void __fastcall TCellGrid::Test_CellInfo(TGridCoord& CellHit1)
{

        AnsiString str,str2,str3,str4;
        if ( GetCellSimple(CellHit1.X, CellHit1.Y) !=NULL )
        {

            if (GetCellSimple(CellHit1.X,CellHit1.Y)->CellFlags.ValueType ==0)
                str3 ="\n Текст";
            if (GetCellSimple(CellHit1.X,CellHit1.Y)->CellFlags.ValueType ==1)
                str3 ="\n Выражение";
            if (GetCellSimple(CellHit1.X,CellHit1.Y)->CellFlags.ValueType ==2)
                str3 ="\n Шаблон";

            str = "Col: " + IntToStr(CellHit1.X) + ", ";
            str += "Row: " + IntToStr(CellHit1.Y) + "\n";
            str += "Text= " + GetCellSimple(CellHit1.X, CellHit1.Y)->Text + "\n";
            str += "LineLeft: " + IntToStr(GetCellSimple(CellHit1.X, CellHit1.Y)->Line.WidthLeft) + "\n";
            str += "LineTop: " + IntToStr(GetCellSimple(CellHit1.X, CellHit1.Y)->Line.WidthTop) + "\n";
            str += "LineRight: " + IntToStr(GetCellSimple(CellHit1.X, CellHit1.Y)->Line.WidthRight) + "\n";
            str += "LineBottom: " + IntToStr(GetCellSimple(CellHit1.X, CellHit1.Y)->Line.WidthBottom) + "\n \n";

            TMyObject* MO =GetCellSimple(CellHit1.X, CellHit1.Y);
            str += "\n DynamicType->Name: " + ((TCell*)MO)->DynamicType->Name;
            if (((TCell*)MO)->DynamicType->Name =="TCellTab")
            {
                str += "\n ColWidth: " + IntToStr(((TCellTab*)MO)->ColWidth);
                str += "\n RowHeight: " + IntToStr(((TCellTab*)MO)->RowHeight);
            }
            if (((TCell*)MO)->DynamicType->Name =="TCellColRow")
            {
                str += "\n ColRowWidth: " + IntToStr(((TCellColRow*)MO)->ColRowWidth);
            }

            if (GetCellSimple(CellHit1.X, CellHit1.Y)->UnionRect !=NULL)
            {
                str2 = "\n UnionLeft: " + IntToStr(GetCellSimple(CellHit1.X, CellHit1.Y)->UnionRect->Left) + "\n";
                str2 += "UnionTop: " + IntToStr(GetCellSimple(CellHit1.X, CellHit1.Y)->UnionRect->Top) + "\n";
                str2 += "UnionRight: " + IntToStr(GetCellSimple(CellHit1.X, CellHit1.Y)->UnionRect->Right) + "\n";
                str2 += "UnionBottom: " + IntToStr(GetCellSimple(CellHit1.X, CellHit1.Y)->UnionRect->Bottom) + "\n \n";
            }

            str2 += "\n RectLeft: " + IntToStr(GetGridRectToRectPixelForBorder(CellHit1.X, CellHit1.Y).Left) + "\n";
            str2 += "RectTop: " + IntToStr(GetGridRectToRectPixelForBorder(CellHit1.X, CellHit1.Y).Top) + "\n";
            str2 += "RectRight: " + IntToStr(GetGridRectToRectPixelForBorder(CellHit1.X, CellHit1.Y).Right) + "\n";
            str2 += "RectBottom: " + IntToStr(GetGridRectToRectPixelForBorder(CellHit1.X, CellHit1.Y).Bottom) + "\n \n";
            str2 += "TypeText: " + str3;
            str2 += "\n Перенос по словам в ячейке: " +IntToStr(GetCellSimple(CellHit1.X,CellHit1.Y)->CellFlags.TextWordBreak);
            if (GetCellSimple(CellHit1.X,CellHit1.Y)->LineColorNot)
                str2 += "\n LineColor: true";
            else
                str2 += "\n LineColor: false";

        }
        else
        {
            str="Cell not cteating ";
        }
        str4 = "\nEndColCell: " +IntToStr(EndColRowCell.x);
        str4 += "\nEndRowCell: " +IntToStr(EndColRowCell.y);

        if (GetCellSimple(1,CellHit1.Y) !=NULL)
            str4 += "\n Перенос по словам в cтроке: " +IntToStr(GetCellSimple(1,CellHit1.Y)->CellFlags.TextWordBreak);
        if (GetCellSimple(CellHit1.X,1) !=NULL)
            str4 += "\n Перенос по словам в cтолбце: " +IntToStr(GetCellSimple(CellHit1.X,1)->CellFlags.TextWordBreak);

        str4 += "\n Перенос по словам в Таблице: " +IntToStr(GetCellSimple(1,1)->CellFlags.TextWordBreak);
        str4 +="\n LeftBorder: " + IntToStr(GetLeftBorder(CellHit1.X,CellHit1.Y));
        str4 +="\n TopBorder: " + IntToStr(GetTopBorder(CellHit1.X,CellHit1.Y));
        str4 +="\n RightBorder: " + IntToStr(GetRightBorder(CellHit1.X,CellHit1.Y));
        str4 +="\n BottomBorder: " + IntToStr(GetBottomBorder(CellHit1.X,CellHit1.Y));
        str4 +="\n Color: " + IntToStr(GetCellParam(CellHit1.X,CellHit1.Y)->bgColor);


        ShowMessage(str+str2+str3+str4);
        TMouseButton BT;
        BT << mbLeft;
        TShiftState Shift;
        CellGridMouseUp(NULL,BT,Shift,100,100);
}