//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaToolEditV.h"
#include "MetaToolV.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaToolEdit *MDIMetaToolEdit;
//---------------------------------------------------------------------------
__fastcall TMDIMetaToolEdit::TMDIMetaToolEdit(TComponent* Owner,TMetaNode *N)
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

