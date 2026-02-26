// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMyTextureModesV.h"
#include "MetaClasses.h"
//---------------------------------------------------------------------------
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIMyTextureModes *MDIMyTextureModes;
//---------------------------------------------------------------------------
 TMDIMyTextureModes::TMDIMyTextureModes(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------

void TMDIMyTextureModes::SETUP()
{
    for (int i=0;i<4;i++)
        cbMode->Items->Add(TextureModeStr[i]);
    cbMode->ItemIndex = 0;
}

void TMDIMyTextureModes::Refresh()
{
    cbMode->ItemIndex = ((TMyTextureModes *)Obj)->Mode;
    edZMin->Text = FLOATTOSTR(((TMyTextureModes *)Obj)->ZMin);
    edZMax->Text = FLOATTOSTR(((TMyTextureModes *)Obj)->ZMax);
    cbModeChange(cbMode);
}

bool TMDIMyTextureModes::Checked()
{
    return IS_FLOAT(edZMin->Text)&&IS_FLOAT(edZMax->Text);
}

void TMDIMyTextureModes::Apply()
{
    ((TMyTextureModes *)Obj)->Mode = cbMode->ItemIndex;
    ((TMyTextureModes *)Obj)->ZMin = TO_DOUBLE(edZMin->Text);
    ((TMyTextureModes *)Obj)->ZMax = TO_DOUBLE(edZMax->Text);
}

void  TMDIMyTextureModes::cbModeChange(TObject *Sender)
{
    gbMinMax->Enabled = (cbMode->ItemIndex >= 2);
}
//---------------------------------------------------------------------------
