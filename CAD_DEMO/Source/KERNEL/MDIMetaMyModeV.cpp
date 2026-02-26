// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaMyModeV.h"
//---------------------------------------------------------------------------
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaMyMode *MDIMetaMyMode;
//---------------------------------------------------------------------------
 TMDIMetaMyMode::TMDIMetaMyMode(TComponent* Owner,TMetaMyMode *MM)
  : TMDIMetaNode(Owner,MM)
{
}
//---------------------------------------------------------------------------
void TMDIMetaMyMode::MNApply()
{
  TMDIMetaNode::MNApply();
  ((TMetaMyMode*)MetaNode)->CAM = cbCAM->ItemIndex;
}

void TMDIMetaMyMode::MNRefresh()
{
  TMDIMetaNode::MNRefresh();
  cbCAM->ItemIndex = ((TMetaMyMode*)MetaNode)->CAM;
}
