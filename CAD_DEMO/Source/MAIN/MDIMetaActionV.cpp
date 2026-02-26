// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaActionV.h"
#include "UI.h"
//---------------------------------------------------------------------------
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaAction *MDIMetaAction;
//---------------------------------------------------------------------------
 TMDIMetaAction::TMDIMetaAction(TComponent* Owner,TMetaNode *N)
    : TMDIMetaNode(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDIMetaAction::SETUP()
{
    cbeUserImage->Images = ((TMetaAction*)MetaNode)->MetaActionList->GetIL();
    cbeUserImage->Clear();
    if (cbeUserImage->Images)
        for (int i=0;i<cbeUserImage->Images->Count;i++)
            cbeUserImage->ItemsEx->AddItem("",i,i,i,0,0);
}

void TMDIMetaAction::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    cbeUserImage->ItemIndex = ((TMetaAction *)MetaNode)->UImageIndex;
    cbEnabled->Checked = ((TMetaAction*)MetaNode)->Enabled;
    cbVisible->Checked = ((TMetaAction*)MetaNode)->Visible;
}

void TMDIMetaAction::MNApply()
{
    TMDIMetaNode::MNApply();
    ((TMetaAction *)MetaNode)->UImageIndex = cbeUserImage->ItemIndex;
    ((TMetaAction*)MetaNode)->Enabled = cbEnabled->Checked;
    ((TMetaAction*)MetaNode)->Visible = cbVisible->Checked;
}
