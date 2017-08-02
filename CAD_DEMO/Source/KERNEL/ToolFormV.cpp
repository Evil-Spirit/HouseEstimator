//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "ToolFormV.h"
#include <Windows.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TToolForm *ToolForm;
//---------------------------------------------------------------------------
__fastcall TToolForm::TToolForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TToolForm::FormResize(TObject *Sender)
{
/*    int D = Width - 164;
    eDecX->Width += D;
    eDecY->Width += D;
    ePolR->Width += D;
    ePolA->Width += D;*/
}
//---------------------------------------------------------------------------

void __fastcall TToolForm::pCoordinatesResize(TObject *Sender)
{
    int W = pCoordinates->Width - eDecX->Left - 5;
    eDecX->Width = W;
    eDecY->Width = W;
    ePolR->Width = W;
    ePolA->Width = W;
}
//---------------------------------------------------------------------------

