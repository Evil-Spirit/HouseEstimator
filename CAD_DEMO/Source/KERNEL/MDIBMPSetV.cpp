// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIBMPSetV.h"
#include "MDIBMPSetEditV.h"
//---------------------------------------------------------------------------
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIBMPSet *MDIBMPSet;
//---------------------------------------------------------------------------
 TMDIBMPSet::TMDIBMPSet(TComponent* Owner,TBMPSet *N)
    : TMDIMetaNode(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDIBMPSet::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    ((TMDIObjectEdit *)BMPSet->Controls[0])->Refresh();
}

void TMDIBMPSet::MNApply()
{
    TMDIMetaNode::MNApply();
    ((TMDIObjectEdit *)BMPSet->Controls[0])->Apply();
}

void TMDIBMPSet::SETUP()
{
    new TMDIBMPSetEdit(this,BMPSet,MetaNode,"",NULL);
}

