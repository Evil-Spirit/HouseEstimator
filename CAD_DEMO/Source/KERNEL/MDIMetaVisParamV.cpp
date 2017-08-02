//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaVisParamV.h"
#include "MDIObjectEditV.h"
#include "MDIPointerEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaVisParam *MDIMetaVisParam;
//---------------------------------------------------------------------------
__fastcall TMDIMetaVisParam::TMDIMetaVisParam(TComponent* Owner,TMetaVisParam *N)
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
