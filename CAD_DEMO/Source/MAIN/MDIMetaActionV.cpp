//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaActionV.h"
#include "UI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaAction *MDIMetaAction;
//---------------------------------------------------------------------------
__fastcall TMDIMetaAction::TMDIMetaAction(TComponent* Owner,TMetaNode *N)
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
