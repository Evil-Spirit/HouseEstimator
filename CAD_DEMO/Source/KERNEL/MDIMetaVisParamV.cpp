// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaVisParamV.h"
#include "MDIObjectEditV.h"
#include "MDIPointerEditV.h"
//---------------------------------------------------------------------------
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaVisParam *MDIMetaVisParam;
//---------------------------------------------------------------------------
 TMDIMetaVisParam::TMDIMetaVisParam(TComponent* Owner,TMetaVisParam *N)
    : TMDIMetaNode(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDIMetaVisParam::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    ((TMDIObjectEdit *)TML->Controls[0])->Refresh();
    ((TMDIObjectEdit *)MAT->Controls[0])->Refresh();
    ((TMDIObjectEdit *)TEX->Controls[0])->Refresh();
}

void TMDIMetaVisParam::MNApply()
{
    TMDIMetaNode::MNApply();
    ((TMDIObjectEdit *)TML->Controls[0])->Apply();
    ((TMDIObjectEdit *)MAT->Controls[0])->Apply();
    ((TMDIObjectEdit *)TEX->Controls[0])->Apply();
}

bool TMDIMetaVisParam::MNChecked()
{
    if (TMDIMetaNode::MNChecked()==false)
        return(false);
    if ( ((TMDIObjectEdit *)MAT->Controls[0])->Checked()==false)
        return(false);
    if ( ((TMDIObjectEdit *)TEX->Controls[0])->Checked()==false)
        return(false);
    if ( ((TMDIObjectEdit *)TML->Controls[0])->Checked()==false)
        return(false);

    return true;
}

void TMDIMetaVisParam::SETUP()
{
    EditPointer(this,MAT,&(((TMetaVisParam *)MetaNode)->MAT),AnsiString(), TMetaMaterial::StaticType );
    EditPointer(this,TEX,&(((TMetaVisParam *)MetaNode)->TEX),AnsiString(), TMetaTexture::StaticType );
    ((TMetaVisParam *)MetaNode)->TML.Edit(this,TML,NULL);
}
