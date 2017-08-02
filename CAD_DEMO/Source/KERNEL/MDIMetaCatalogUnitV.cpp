//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaCatalogUnitV.h"
#include "MDIPointerEditV.h"
#include "MDIObjectEditV.h"
#include "CatalogUnitV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIMetaCatalogUnit *MDIMetaCatalogUnit;
//---------------------------------------------------------------------------
__fastcall TMDIMetaCatalogUnit::TMDIMetaCatalogUnit(TComponent* Owner,TMetaNode *N)
    : TMDIMetaNode(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDIMetaCatalogUnit::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    ((TMDIObjectEdit*)ASSOCIATED->Controls[0])->Refresh();
}

void TMDIMetaCatalogUnit::MNApply()
{
    TMDIMetaNode::MNApply();
    ((TMDIObjectEdit*)ASSOCIATED->Controls[0])->Apply();
}

bool TMDIMetaCatalogUnit::MNChecked()
{
    return TMDIMetaNode::MNChecked() && ((TMDIObjectEdit*)ASSOCIATED->Controls[0])->Checked();
}

void TMDIMetaCatalogUnit::SETUP()
{
    TMTList< TClassNode > LST;
    LST.Add( TMetaElement::StaticType );
    LST.Add( TMetaTexture::StaticType );
    LST.Add( TMetaMaterial::StaticType );
    EditPointerByList(this,ASSOCIATED,&(((TMetaCatalogUnit*)MetaNode)->ASSOCIATED),AnsiString(),&LST);
}
