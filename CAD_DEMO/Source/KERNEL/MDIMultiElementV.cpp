// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMultiElementV.h"
#include "MultiElementV.h"
#include "MDIElementSelectV.h"
#include "MDIPointerListEditV.h"
//---------------------------------------------------------------------------
#pragma link "MDIElementV"
#pragma resource "*.dfm"
TMDIMultiElement *MDIMultiElement;
//---------------------------------------------------------------------------
 TMDIMultiElement::TMDIMultiElement(TComponent* Owner,TMetaMultiElement *MN)
    : TMDIElement(Owner,MN)
{

}
//---------------------------------------------------------------------------

TListItem *AddSyngleItem(TListView *LV,TMetaElement *MN)
{
    if (!MN)
        return NULL;
    TListItem *IT = LV->Items->Add();
    IT->Caption = MN->Name;
    IT->ImageIndex = MN->ImageIndex;
    IT->StateIndex = -1;
    IT->Data = MN;
    return IT; 
}

void TMDIMultiElement::SETUP()
{
    TMDIElement::SETUP();
    EditPointerList(  this,tsMultiElement,
                        ((TMetaMultiElement *)MetaNode)->UNITS,
                        AnsiString(),
                        TMetaElement::StaticType,MetaNode,CreateMetaElementPointer);
}

void TMDIMultiElement::MNRefresh()
{
    TMDIElement::MNRefresh();
    ((TMDIObjectEdit*)tsMultiElement->Controls[0])->Refresh();
    TMetaMultiElement *MME = (TMetaMultiElement *)MetaNode;
    cbIsSizer->Checked = MME->IsSizer;
}

void TMDIMultiElement::MNApply()
{
    TMDIElement::MNApply();
    ((TMDIObjectEdit*)tsMultiElement->Controls[0])->Apply();
    TMetaMultiElement *MME = (TMetaMultiElement *)MetaNode;
    MME->IsSizer = cbIsSizer->Checked;
}


