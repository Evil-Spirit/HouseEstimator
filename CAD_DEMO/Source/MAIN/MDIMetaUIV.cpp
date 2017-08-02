//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaUIV.h"
#include "UI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaUI *MDIMetaUI;
//---------------------------------------------------------------------------
__fastcall TMDIMetaUI::TMDIMetaUI(TComponent* Owner,TMetaNode* N)
    : TMDIMetaNode(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDIMetaUI::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    cbEnabled->Checked = ((TMetaUI*)MetaNode)->Enabled;
    cbVisible->Checked = ((TMetaUI*)MetaNode)->Visible;
}

void TMDIMetaUI::MNApply()
{
    TMDIMetaNode::MNApply();
    ((TMetaUI*)MetaNode)->Enabled = cbEnabled->Checked;
    ((TMetaUI*)MetaNode)->Visible = cbVisible->Checked;
}
