//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaMenuItemV.h"
#include "MDIPointerEditV.h"
#include "UI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaUIV"
#pragma resource "*.dfm"
TMDIMetaMenuItem *MDIMetaMenuItem;
//---------------------------------------------------------------------------
__fastcall TMDIMetaMenuItem::TMDIMetaMenuItem(TComponent* Owner,TMetaNode *N)
    : TMDIMetaUI(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDIMetaMenuItem::SETUP()
{
    EditPointer(this,MetaAction,&(((TMetaMenuItem *)MetaNode)->MetaAction),AnsiString(), TMetaAction::StaticType );
    EditPointer(this,ChildBMPSet,&(((TMetaMenuItem *)MetaNode)->ChildBMPSet),AnsiString(), TBMPSet::StaticType );
}

void TMDIMetaMenuItem::MNRefresh()
{
    TMDIMetaUI::MNRefresh();
    ((TMDIObjectEdit *)MetaAction->Controls[0])->Refresh();
    ((TMDIObjectEdit *)ChildBMPSet->Controls[0])->Refresh();
}

void TMDIMetaMenuItem::MNApply()
{
    TMDIMetaUI::MNApply();
    ((TMDIObjectEdit *)MetaAction->Controls[0])->Apply();
    ((TMDIObjectEdit *)ChildBMPSet->Controls[0])->Apply();
}

