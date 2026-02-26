// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIHasStepV.h"
#include "MetaClasses.h"
//---------------------------------------------------------------------------
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIHasStep *MDIHasStep;
//---------------------------------------------------------------------------
 TMDIHasStep::TMDIHasStep(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
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