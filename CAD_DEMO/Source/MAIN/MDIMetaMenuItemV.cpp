// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaMenuItemV.h"
#include "MDIPointerEditV.h"
#include "UI.h"
//---------------------------------------------------------------------------
#pragma link "MDIMetaUIV"
#pragma resource "*.dfm"
TMDIMetaMenuItem *MDIMetaMenuItem;
//---------------------------------------------------------------------------
 TMDIMetaMenuItem::TMDIMetaMenuItem(TComponent* Owner,TMetaNode *N)
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

