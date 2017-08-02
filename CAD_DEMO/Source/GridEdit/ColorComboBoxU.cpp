#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "CellGrid.h"
#include "ColorComboBoxU.h"
#include "SelectColorU.h"
#include "CellParameterU.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------
void __fastcall TColorComboBox::WndProc(Messages::TMessage &Message)
{
    if (Message.Msg == WM_LBUTTONUP)
    {
        if (SC->Tag ==2)
            SC->Tag =0;
    }
    else if (
            Message.Msg == WM_LBUTTONDOWN ||
            Message.Msg == WM_MBUTTONDBLCLK ||
            Message.Msg == WM_MBUTTONDOWN ||
            Message.Msg == WM_MBUTTONUP ||
            Message.Msg == WM_LBUTTONDBLCLK)
    {
        if (SC->Tag ==0)
        {
            SC->Tag =1;
            AdjustDropDown2();
        }
        else
        {
            SC->Tag =0;
            SC->Close();
        }

    }
    else
        TCustomComboBox::WndProc(Message);
}

void __fastcall TColorComboBox::AdjustDropDown(void)
{
}

void __fastcall TColorComboBox::AdjustDropDown2()
{
    TPoint point =ClientToScreen(TPoint(0,0));

    int Left =point.x;
    int Top =point.y+this->Height;
    int ScreenH =Screen->Height;
    int ScreenW =Screen->Width;
    if (Top+SC->Height >ScreenH)
    {
        Top =point.y -SC->Height;
    }
    if (Left+SC->Width >ScreenW)
    {
        Left =point.x -SC->Width;
    }
    if (Left <1)
    {
        Left =Left +Width;
    }

    SC->Top =Top;
    SC->Left =Left;
    SC->Show();
}

__fastcall TColorComboBox::TColorComboBox(Classes::TComponent* AOwner, TCellGrid* _CellGrid, TForm* _Form)
    :TCustomComboBox(AOwner)
{
   CellGrid =_CellGrid;
   CellParameter =_Form;
   Style = csOwnerDrawFixed;
   SC = new TSelectColor(Application,CellGrid, this);
   SC->OnClose = SelectColorClose;
}

__fastcall TColorComboBox::~TColorComboBox(void)
{
    delete SC;
    SC=NULL;
}

void __fastcall TColorComboBox::SelectColorClose(TObject *Sender,TCloseAction &Action)
{
    if ( Color != SC->GetColor()  ||  SC->bAutoColor )
    {
        if (SC->bAutoColor) Tag=1;
        
        Color = SC->GetColor();
        if ( OnColorChange )
            OnColorChange( this );
    }
}




