// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaUIV.h"
#include "UI.h"
//---------------------------------------------------------------------------
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaUI *MDIMetaUI;
//---------------------------------------------------------------------------
 TMDIMetaUI::TMDIMetaUI(TComponent* Owner,TMetaNode* N)
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
