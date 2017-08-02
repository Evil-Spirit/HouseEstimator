 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "SimpleEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMDISimpleEdit *MDISimpleEdit;
//---------------------------------------------------------------------------
__fastcall TMDISimpleEdit::TMDISimpleEdit(TComponent* Owner)
    : TForm(Owner)
{
    delete this;
}

__fastcall TMDISimpleEdit::TMDISimpleEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TForm(Owner)
{
    Constructiong=true;
    Parent = (TWinControl *)_Parent;
    Visible=true;
    Align = alClient;
    Obj = _Obj;
    L->Caption = Text;
    SETUP();
    Refresh();
    Constructiong=false;
}
//---------------------------------------------------------------------------
void __fastcall TMDISimpleEdit::lErrorClick(TObject *Sender)
{
    //
}
