// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "ToolFormV.h"
#include <Windows.hpp>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TToolForm *ToolForm;
//---------------------------------------------------------------------------
 TToolForm::TToolForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void  TToolForm::FormResize(TObject *Sender)
{
/*    int D = Width - 164;
    eDecX->Width += D;
    eDecY->Width += D;
    ePolR->Width += D;
    ePolA->Width += D;*/
}
//---------------------------------------------------------------------------

void  TToolForm::pCoordinatesResize(TObject *Sender)
{
    int W = pCoordinates->Width - eDecX->Left - 5;
    eDecX->Width = W;
    eDecY->Width = W;
    ePolR->Width = W;
    ePolA->Width = W;
}
//---------------------------------------------------------------------------

