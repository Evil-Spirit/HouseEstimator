 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIBMPSetV.h"
#include "MDIBMPSetEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIBMPSet *MDIBMPSet;
//---------------------------------------------------------------------------
__fastcall TMDIBMPSet::TMDIBMPSet(TComponent* Owner,TBMPSet *N)
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

