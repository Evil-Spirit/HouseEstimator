// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIEPSEDITV.h"
#include "MetaClasses.h"
//---------------------------------------------------------------------------
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIEpsEdit *MDIEpsEdit;
//---------------------------------------------------------------------------
 TMDIEpsEdit::TMDIEpsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------

void TMDIEpsEdit::SETUP()
{
P[0] = POSEPS;
P[1] = ANGLEEPS;
P[2] = SIZEEPS;
Count=3;
}