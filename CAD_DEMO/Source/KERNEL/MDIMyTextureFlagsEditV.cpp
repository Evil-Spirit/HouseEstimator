 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMyTextureFlagsEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIMyTextureFlagsEdit *MDIMyTextureFlagsEdit;
//---------------------------------------------------------------------------
__fastcall TMDIMyTextureFlagsEdit::TMDIMyTextureFlagsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
void TMDIMyTextureFlagsEdit::SETUP()
{
    CBE->Clear();
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());
    CBE->Items->Add(AnsiString());

    CBE->Items->Strings[txStandard] = AnsiString("txStandard");
    CBE->Items->Strings[txLinearX] = AnsiString("txLinearX");
    CBE->Items->Strings[txLinearY] = AnsiString("txLinearY");
    CBE->Items->Strings[txLinearZ] = AnsiString("txLinearZ");
    CBE->Items->Strings[txLinearXY] = AnsiString("txLinearXY");
    CBE->Items->Strings[txLinearYZ] = AnsiString("txLinearYZ");
    CBE->Items->Strings[txLinearZX] = AnsiString("txLinearZX");
    CBE->Items->Strings[txLinearYX] = AnsiString("txLinearYX");
    CBE->Items->Strings[txLinearZY] = AnsiString("txLinearZY");
    CBE->Items->Strings[txLinearXZ] = AnsiString("txLinearXZ");
    CBE->Items->Strings[txSphereZ] = AnsiString("txSphereZ");
    CBE->Items->Strings[txByNormal] = AnsiString("txByNormal");

    P[0] = Param;
    P[1] = Scale;
    P[2] = Shift;
    Count=3;
}

void TMDIMyTextureFlagsEdit::Refresh()
{
    TMDIObjectEdit::Refresh();
    CBE->ItemIndex = ((TMyTextureFlags*)Obj)->Mode;
}

void TMDIMyTextureFlagsEdit::Apply()
{
    TMDIObjectEdit::Apply();
    ((TMyTextureFlags*)Obj)->Mode = (TVisTextureMode)CBE->ItemIndex;
}

bool TMDIMyTextureFlagsEdit::Checked()
{
    if (!(TMDIObjectEdit::Checked()))
        return false;
    return (CBE->ItemIndex!=-1);
}
