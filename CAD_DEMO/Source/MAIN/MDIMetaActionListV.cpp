// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaActionListV.h"
#include "MDIPointerEditV.h"
#include "UI.h"
//---------------------------------------------------------------------------
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaActionList *MDIMetaActionList;
//---------------------------------------------------------------------------
 TMDIMetaActionList::TMDIMetaActionList(TComponent* Owner,TMetaNode *N)
    : TMDIMetaNode(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDIMetaActionList::SETUP()
{
    EditPointer(this,BMPSet,&(((TMetaActionList *)MetaNode)->BMPSet),AnsiString(), TBMPSet::StaticType );
}

void TMDIMetaActionList::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    ((TMDIObjectEdit *)BMPSet->Controls[0])->Refresh();
}

void TMDIMetaActionList::MNApply()
{
    TMDIMetaNode::MNApply();
    ((TMDIObjectEdit *)BMPSet->Controls[0])->Apply();
}

