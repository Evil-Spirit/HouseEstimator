//---------------------------------------------------------------------------

#include <vcl.h>
#include "MTL.h"
#include "Usefuls.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIViewSettingsV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMDIViewSettings *MDIViewSettings;
//---------------------------------------------------------------------------
__fastcall TMDIViewSettings::TMDIViewSettings(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMDIViewSettings::shBackColor2dMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TShape* SH = (TShape*)Sender;
    CD->Color = SH->Brush->Color;
    if (CD->Execute())
        SH->Brush->Color = CD->Color;
}
//---------------------------------------------------------------------------
