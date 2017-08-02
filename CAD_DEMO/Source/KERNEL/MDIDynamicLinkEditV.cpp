 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include <typeinfo.h>

#include "MDIDynamicLinkEditV.h"
//#include "MDILuaEditorV.h"
#include "TriggerBlockV.h"
#include "MetaNodeCollectionV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIDynamicLinkEdit *MDIDynamicLinkEdit;
//---------------------------------------------------------------------------
__fastcall TMDIDynamicLinkEdit::TMDIDynamicLinkEdit(TComponent* Owner,TDynamicLink *N)
    : TMDIMetaNode(Owner,N)
{
}
//---------------------------------------------------------------------------
void TMDIDynamicLinkEdit::MNApply()
{
    TMDIMetaNode::MNApply();
    TMetaLink *ML = (TMetaLink *)(cbeLinks->ItemsEx->ComboItems[cbeLinks->ItemIndex]->Data);
    TMetaElement *ME=(TMetaElement *)(cbeElements->ItemsEx->ComboItems[cbeElements->ItemIndex]->Data);
    TDynamicLink *DL = (TDynamicLink *)MetaNode;
    DL->EL0.ADR = ME;
    DL->ML.ADR = ML;
    DL->Needed = cbNeeded->Checked;
}


bool TMDIDynamicLinkEdit::MNChecked()
{
    if (TMDIMetaNode::MNChecked()==false)
        return(false);
    if (cbeLinks->ItemIndex<0)
        return(false);
    if (cbeElements->ItemIndex<0)
        return(false);
    return(true);
}

void TMDIDynamicLinkEdit::SETUP()
{
    cbeLinks->Clear();
    cbeElements->Clear();

    int EInd = -1;
    int LInd = -1;
    TMetaElement *ME;
    TComboExItem *CEI;
    TMetaLink *ML;
    TDynamicLink *DL= (TDynamicLink *)MetaNode;
    TMTList<TMyRegObject> *List = new TMTList<TMyRegObject>();

    MetaNodeCollection->SelectByCT(NULL,TMetaElement::StaticType ,List,false,true);
    for (int i=0;i<List->Count;i++)
    {
        ME = (TMetaElement *)List->Items[i];
        int ind = ME->ImageIndex;
        CEI = cbeElements->ItemsEx->AddItem(ME->Name,ind,ind,ind,0,0);
        CEI->Data = ME;

        if (ME == DL->EL0.ADR)
            EInd = i;
    }

    List->Clear();
    MetaNodeCollection->SelectByCT(NULL,TMetaLink::StaticType ,List,true,false);
    for (int i=0;i<List->Count;i++)
    {
        ML = (TMetaLink *)List->Items[i];
        int ind = ML->ImageIndex;
        CEI = cbeLinks->ItemsEx->AddItem(ML->Name,ind,ind,ind,0,0);
        CEI->Data = ML;
        if (ML == DL->ML.ADR)
            LInd = i;
    }

    cbeElements->ItemIndex = EInd;
    cbeLinks->ItemIndex = LInd;
    cbNeeded->Checked = DL->Needed;
}

void __fastcall TMDIDynamicLinkEdit::FormClose(TObject *Sender,
      TCloseAction &Action)
{
     TMyMDIChild::FormClose(Sender,Action);    
}
//---------------------------------------------------------------------------


