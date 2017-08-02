//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaMyModeV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaMyMode *MDIMetaMyMode;
//---------------------------------------------------------------------------
__fastcall TMDIMetaMyMode::TMDIMetaMyMode(TComponent* Owner,TMetaMyMode *MM)
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
