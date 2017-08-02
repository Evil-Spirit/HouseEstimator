 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIHasStepV.h"
#include "MetaClasses.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIHasStep *MDIHasStep;
//---------------------------------------------------------------------------
__fastcall TMDIHasStep::TMDIHasStep(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
void TMDIHasStep::SETUP()
{
    P[0] = BaseStep;
    P[1] = DefMulti;
    Count=2;
}

void TMDIHasStep::Refresh()
{
    TMDIObjectEdit::Refresh();
    cbHard->Checked = ((THasStep*)Obj)->Hard;
}

void TMDIHasStep::Apply()
{
    TMDIObjectEdit::Apply();
    ((THasStep*)Obj)->Hard = cbHard->Checked;
    for (int i=0;i<3;i++)
        ((THasStep*)Obj)->DefMulti.a[i] = RoundTo(((THasStep*)Obj)->DefMulti.a[i],0);
}

bool TMDIHasStep::Checked()
{
    return (TMDIObjectEdit::Checked());
}