//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaActionListV.h"
#include "MDIPointerEditV.h"
#include "UI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaActionList *MDIMetaActionList;
//---------------------------------------------------------------------------
__fastcall TMDIMetaActionList::TMDIMetaActionList(TComponent* Owner,TMetaNode *N)
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

