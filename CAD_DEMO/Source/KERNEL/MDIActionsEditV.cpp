 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MetaClasses.h"
#include "MDIActionsEditV.h"
#include "MDIPointerListEditV.h"
#include "MetaToolV.h"
//#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIActionsEdit *MDIActionsEdit;
//---------------------------------------------------------------------------
__fastcall TMDIActionsEdit::TMDIActionsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
TMyActionSettings *TMDIActionsEdit::MAS()
{
    return ((TMyActionSettings*)Obj);
}

TPointer<TMetaNode>* CreateTPointer_TMetaTool_()
{
    return (TPointer<TMetaNode>*)new TPointer<TMetaTool>();
}
void TMDIActionsEdit::SETUP()
{
    EditPointerList(this,Tools,&(MAS()->Tools),"Tools",TMetaTool::StaticType,NULL,CreateTPointer_TMetaTool_);
    EditPointerList(this,CreateTools,&(MAS()->CreateTools),"Creation tools",TMetaTool::StaticType,NULL,CreateTPointer_TMetaTool_);
}
void TMDIActionsEdit::Refresh()
{
    ((TMDIObjectEdit*)Tools->Controls[0])->Refresh();
    ((TMDIObjectEdit*)CreateTools->Controls[0])->Refresh();
}

void TMDIActionsEdit::Apply()
{
    ((TMDIObjectEdit*)Tools->Controls[0])->Apply();
    ((TMDIObjectEdit*)CreateTools->Controls[0])->Apply();
}
bool TMDIActionsEdit::Checked()
{
    return  ((TMDIObjectEdit*)Tools->Controls[0])->Checked() &&
            ((TMDIObjectEdit*)CreateTools->Controls[0])->Checked();
};

void __fastcall TMDIActionsEdit::FormResize(TObject *Sender)
{
    Tools->Width = ClientWidth/2;    
}
//---------------------------------------------------------------------------

