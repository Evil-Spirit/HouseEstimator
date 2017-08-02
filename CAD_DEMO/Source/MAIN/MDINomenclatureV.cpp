 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"     
#pragma hdrstop

#include "NomenclatureV.h"
#include "MDINomenclatureV.h"
#include "SimpleEditV.h"
#include "MDIObjectEditV.h"
#include "MDIPointerEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDINomenclature *MDINomenclature;
//---------------------------------------------------------------------------
__fastcall TMDINomenclature::TMDINomenclature(TComponent* Owner,TMetaNode *N)
    : TMDIMetaNode(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDINomenclature::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    eStrCode->Text = ((TNomenclature*)MetaNode)->StringCode;
    ePrice->Text = FLOATTOSTR(((TNomenclature*)MetaNode)->SavePrice);
    eWeight->Text = FLOATTOSTR(((TNomenclature*)MetaNode)->SaveWeight);
    ((TMDISimpleEdit*)Size->Controls[0])->Refresh();
    ((TMDISimpleEdit*)Dimensions->Controls[0])->Refresh();
    mMemo->Lines->CommaText = ((TNomenclature*)MetaNode)->Memo;
    ((TMDIObjectEdit *)PME->Controls[0])->Refresh();

    ePrice->Text = FLOATTOSTR(((TNomenclature*)MetaNode)->SavePrice);
    eWeight->Text = FLOATTOSTR(((TNomenclature*)MetaNode)->SaveWeight);
    ecurPrice->Text = FLOATTOSTR(((TNomenclature*)MetaNode)->Price);
    ecurWeight->Text = FLOATTOSTR(((TNomenclature*)MetaNode)->Weight);


}


bool TMDINomenclature::MNChecked()
{
    if (!TMDIMetaNode::MNChecked())
        return false;
    if (!IS_FLOAT(ePrice->Text))
        return false;
    if (!IS_FLOAT(eWeight->Text))
        return false;

    if (!((TMDISimpleEdit*)Size->Controls[0])->CustomChecked())
        return false;
    if (!((TMDISimpleEdit*)Dimensions->Controls[0])->CustomChecked())
        return false;
    if ( ((TMDIObjectEdit *)PME->Controls[0])->Checked()==false)
        return(false);
    return true;
}


void TMDINomenclature::MNApply()
{
    TMDIMetaNode::MNApply();

    CopyType(mtIntVec,&(((TNomenclature*)MetaNode)->Size),((TMDISimpleEdit*)Size->Controls[0])->Value());
    CopyType(mtIntVec,&(((TNomenclature*)MetaNode)->Dimensions),((TMDISimpleEdit*)Dimensions->Controls[0])->Value()) ;
    ((TMDIObjectEdit *)PME->Controls[0])->Apply();

    ((TNomenclature*)MetaNode)->Price = TO_DOUBLE(ecurPrice->Text);
    ((TNomenclature*)MetaNode)->Weight = TO_DOUBLE(ecurWeight->Text);
    ((TNomenclature*)MetaNode)->SavePrice = TO_DOUBLE(ePrice->Text);
    ((TNomenclature*)MetaNode)->SaveWeight = TO_DOUBLE(eWeight->Text);

    ((TNomenclature*)MetaNode)->StringCode = eStrCode->Text;
    ((TNomenclature*)MetaNode)->Memo = mMemo->Lines->CommaText;
}


void TMDINomenclature::SETUP()
{
    CallDialog(this,Size,MetaNode,mtIntVec,AnsiString("Size"),NULL);
    ((TMDISimpleEdit*)Size->Controls[0])->L->Visible = false;
    CallDialog(this,Dimensions,MetaNode,mtIntVec,AnsiString("Dimensions"),NULL);
    ((TMDISimpleEdit*)Dimensions->Controls[0])->L->Visible = false;
    EditPointer(this,PME,&(((TNomenclature *)MetaNode)->PME),AnsiString(),TMetaElement::StaticType);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



