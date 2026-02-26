// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "SimpleEditV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMDISimpleEdit *MDISimpleEdit;
//---------------------------------------------------------------------------
 TMDISimpleEdit::TMDISimpleEdit(TComponent* Owner)
    : TForm(Owner)
{
    delete this;
}

 TMDISimpleEdit::TMDISimpleEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
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
void  TMDISimpleEdit::lErrorClick(TObject *Sender)
{
    //
}
