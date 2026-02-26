// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaToolEditV.h"
#include "MetaToolV.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaToolEdit *MDIMetaToolEdit;
//---------------------------------------------------------------------------
 TMDIMetaToolEdit::TMDIMetaToolEdit(TComponent* Owner,TMetaNode *N)
    : TMDIMetaNode(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDIMetaToolEdit::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    ((TMDIObjectEdit *)tsMetaTool->Controls[0])->Refresh();
}

void TMDIMetaToolEdit::MNApply()
{
    TMDIMetaNode::MNApply();
    ((TMDIObjectEdit *)tsMetaTool->Controls[0])->Apply();
}

void TMDIMetaToolEdit::SETUP()
{
    TMDIMetaNode::SETUP();
    ((TMetaTool*)MetaNode)->BindedTool.Edit(this,tsMetaTool,NULL);
}

bool TMDIMetaToolEdit::MNChecked()
{
    return TMDIMetaNode::MNChecked() && ((TMDIObjectEdit *)tsMetaTool->Controls[0])->Checked();

}

