//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "CellGrid.h"
#include "TextEditU.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
const AnsiString _ABC = AnsiString("`~-+=!@#.,?|*/%$¹;:()[]{} 1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ");
// ----------- TEditText ------------------

__fastcall TEditText::TEditText(Classes::TComponent* Owner, TCellGrid* _CellGrid):
    TRichEdit(Owner)
{
    CellGrid =_CellGrid;
    Visible =false;
    Parent =_CellGrid;
    Ctl3D =false;
    WantTabs =true;
    WordWrap =false;

    IsEsc =false;

    BorderStyle = bsNone;
    OnKeyDown = KeyDownRich;
    OnExit = ExitRich;
}
void __fastcall TEditText::ExitRich(TObject* Sender)
{
    if (CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow) !=NULL &&
        CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->UnionRect !=NULL)
    {
    }
    else if (CellGrid->GetCellParam(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->CellFlags.TextWordBreak ==1)
    {
        WordWrap =true;
        TRect rectMax =CellGrid->CurrentEditCell;

        CellGrid->Canvas->Font->Name =CellGrid->GetCellParam(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->FontName;
        CellGrid->Canvas->Font->Size =CellGrid->GetCellParam(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->CellFlags.FontSize;
        AnsiString str =FormatMultiLine(Text,rectMax);
        ::DrawText(CellGrid->Canvas->Handle, str.c_str(),
        str.Length(), &rectMax, DT_WORDBREAK | DT_CALCRECT);
        if (CellGrid->GetRowHeights(CellGrid->CurrentEditRow) < rectMax.Bottom -rectMax.Top &&
            CellGrid->GetCellParam(1,CellGrid->CurrentEditRow)->CellFlags.TextHeightAuto ==1
        )
        {
            if (CellGrid->Height-100 >rectMax.Bottom -rectMax.Top)
                CellGrid->SetRowHeights(CellGrid->CurrentEditRow,rectMax.Bottom -rectMax.Top);
            else
                CellGrid->SetRowHeights(CellGrid->CurrentEditRow,CellGrid->Height-100);
        }
    }
    if (CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow) ==NULL)
        CellGrid->NewCellAndSetDefault2(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow,0);

    if (Text != "\t" &&  Text != "\r\n" && !IsEsc)
        CellGrid->GetCell(CellGrid->CurrentEditCol,CellGrid->CurrentEditRow)->Text =Text;
    IsEsc =false;
    Text ="";
    Visible = false;
    ::SetFocus(CellGrid->Handle);
}

AnsiString __fastcall TEditText::FormatMultiLine(const AnsiString Text, const TRect& rect)
{// ðàçáèòü òåêñò ÷òîáû ïîäõîäèë ïî øèðèíå
    AnsiString str, str2;
    TRect rectcalc =rect;
    int iWidth =rect.Right -rect.Left;
    int iLength =Text.Length();
    for (int i=1; i<=iLength; i++)
    {
        str2 +=Text[i];
        ::DrawText(CellGrid->Canvas->Handle, str2.c_str(),str2.Length(), &rectcalc, DT_SINGLELINE |DT_CALCRECT);
        if (iWidth-5 <= rectcalc.Right -rectcalc.Left && str2.Length()>1)
        {
            str +='\n';
            str2=Text[i];
        }
        rectcalc =rect;
        str +=Text[i];
    }
    return str;
}

void __fastcall TEditText::WndProc(Messages::TMessage &Message)
{
    switch ( Message.Msg )
    {
        case WM_CHAR:
        {
            if (IsPrintSymbol(char(Message.WParam)))
            {
                TRect rectMax=CellGrid->GetGridRectToRectPixelNotUnionAndScroll(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow);
                CellGrid->SetCanvasParameterCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow);
                Font =CellGrid->Canvas->Font;

                AnsiString textmulti = Text + char(Message.WParam);

                if (CellGrid->GetCellParam(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->CellFlags.TextWordBreak ==1)
                    textmulti =FormatMultiLine(textmulti,rectMax);

                CellGrid->GetRectDrawText(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow,textmulti,rectMax);

                if (CellGrid->GetCellParam(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->CellFlags.TextWordBreak ==0)
                {
                    if (rectMax.Right -rectMax.Left >Width)
                    {
                        if (rectMax.Right <CellGrid->DrawInfo.Horz.GridBoundary -15)
                            Width =rectMax.Right -rectMax.Left;
                    }
                }
                else
                {
                    if (rectMax.Bottom -rectMax.Top >Height)
                    {
                        if (rectMax.Bottom <CellGrid->DrawInfo.Vert.GridBoundary -15)
                            Height =rectMax.Bottom -rectMax.Top;
                    }
                }
            }
            TRichEdit::WndProc(Message);
        }break;
        default:
            TRichEdit::WndProc(Message);
    };
}

bool __fastcall TEditText::IsPrintSymbol(const char& Key)
{
    bool ret=false;
    int iLength =_ABC.Length();
    for (int i=1; i<iLength && !ret; i++)
    {
        if (_ABC[i] ==Key)
            ret =true;
    }
    return ret;
}

void __fastcall TEditText::KeyDownRich(TObject* Sender, Word &Key, TShiftState Shift)
{// îáðàáîò÷èê êëàâèàòóðû
    if (Key ==VK_TAB)
    {
        Visible = false;
        ::SetFocus(CellGrid->Handle);
        TRect rectt;
        if (CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow) !=NULL &&
            CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->UnionRect !=NULL
        )
        {
            rectt=CellGrid->GetGridRectToRectPixelUnionReal(CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->UnionRect->Right+1, CellGrid->CurrentEditRow);
            CellGrid->FCurrent.X =CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->UnionRect->Right+1;
            CellGrid->FAnchor.X =CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->UnionRect->Right+1;
        }
        else
        {
            rectt=CellGrid->GetGridRectToRectPixelUnionReal(CellGrid->CurrentEditCol+1, CellGrid->CurrentEditRow);
            CellGrid->FCurrent.X =CellGrid->CurrentEditCol+1;
            CellGrid->FAnchor.X =CellGrid->CurrentEditCol+1;
        }
        CellGrid->CellGridMouseDown(this ,mbLeft,Shift,rectt.Left, rectt.Top);
        CellGrid->CellGridMouseUp(this,mbLeft,Shift,rectt.Left, rectt.Top);

    }
    else if (Key ==VK_RETURN)
    {
        Visible = false;

        ::SetFocus(CellGrid->Handle);
        TRect rectt;
        if (CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow) !=NULL &&
            CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->UnionRect !=NULL
        )
        {
            rectt=CellGrid->GetGridRectToRectPixelUnionReal(CellGrid->CurrentEditCol, CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->UnionRect->Bottom+1);
            CellGrid->FCurrent.Y =CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->UnionRect->Bottom+1;
            CellGrid->FAnchor.Y =CellGrid->GetCell(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow)->UnionRect->Bottom+1;
        }
        else
        {
            rectt=CellGrid->GetGridRectToRectPixelUnionReal(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow+1);
            CellGrid->FCurrent.Y =CellGrid->CurrentEditRow+1;
            CellGrid->FAnchor.Y =CellGrid->CurrentEditRow+1;
        }
        CellGrid->CellGridMouseDown(this ,mbLeft,Shift,rectt.Left, rectt.Top);
        CellGrid->CellGridMouseUp(this,mbLeft,Shift,rectt.Left, rectt.Top);

    }
    else if (Key ==VK_ESCAPE)
    {
        IsEsc =true;
        Visible = false;
        ::SetFocus(CellGrid->Handle);
        TRect rectt=CellGrid->GetGridRectToRectPixelUnionReal(CellGrid->CurrentEditCol, CellGrid->CurrentEditRow+1);
        CellGrid->FCurrent.Y =CellGrid->CurrentEditRow+1;
        CellGrid->FAnchor.Y =CellGrid->CurrentEditRow+1;
        CellGrid->CellGridMouseDown(this ,mbLeft,Shift,rectt.Left, rectt.Top);
        CellGrid->CellGridMouseUp(this,mbLeft,Shift,rectt.Left, rectt.Top);
    }
}

