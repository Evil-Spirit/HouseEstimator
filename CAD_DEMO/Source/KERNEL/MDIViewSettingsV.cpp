// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "MTL.h"
#include "Usefuls.h"
#include "MyTemplates.h"

#include "MDIViewSettingsV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMDIViewSettings *MDIViewSettings;
//---------------------------------------------------------------------------
 TMDIViewSettings::TMDIViewSettings(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void  TMDIViewSettings::shBackColor2dMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TShape* SH = (TShape*)Sender;
    CD->Color = SH->Brush->Color;
    if (CD->Execute())
        SH->Brush->Color = CD->Color;
}
//---------------------------------------------------------------------------
