 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaRoomV.h"
#include "MDIElementSelectV.h"
#include "RoomV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIElementV"
#pragma resource "*.dfm"
TMDIMetaRoom *MDIMetaRoom;
//---------------------------------------------------------------------------
__fastcall TMDIMetaRoom::TMDIMetaRoom(TComponent* Owner,TMetaRoom *M)
    : TMDIElement(Owner,M)
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

void TMDIMetaRoom::MNApply()
{
    TMDIElement::MNApply();
    TMetaRoom *MME = (TMetaRoom *)MetaNode;
    MME->DeterminateList.Clear();
    for (int i=0;i<LV->Items->Count;i++)
    {
        TPointer<TMetaElement> *P_ME = new TPointer<TMetaElement>();
        P_ME->ADR = (TMetaElement*)LV->Items->Item[i]->Data;
        MME->DeterminateList.Add(P_ME);
    }
    MME->DeterminateMode = cbDM->ItemIndex+1;
}

bool TMDIMetaRoom::MNChecked()
{
    if (TMDIElement::MNChecked()==false)
        return(false);
    return LV->Items->Count>0;
}

//---------------------------------------------------------------------------


void __fastcall TMDIMetaRoom::tbtAddClick(TObject *Sender)
{
    TMetaElement *MN = (TMetaElement *)SelectNode(TMetaElement::StaticType,true,true,NULL);
    if (MN&&MN!=MetaNode)
        if (!LV->FindData(0,MN,true,false))
            AddSyngleItem(LV,MN);
}
//---------------------------------------------------------------------------

void __fastcall TMDIMetaRoom::tbtDelClick(TObject *Sender)
{
    if (LV->Selected)
    {
        int index = LV->Selected->Index;
        delete (LV->Selected);
        if (index<LV->Items->Count)
            LV->Selected = LV->Items->Item[index];
    }
}
//---------------------------------------------------------------------------
void TMDIMetaRoom::MNRefresh()
{
    TMDIElement::MNRefresh();
    LV->Clear();
    TMetaRoom *MME = (TMetaRoom *)MetaNode;
    for (int i=0;i<MME->DeterminateList.Count;i++)
        AddSyngleItem(LV,MME->DeterminateList[i].ADR);
    cbDM->ItemIndex = ( (TMetaRoom *)MetaNode)->DeterminateMode-1;
}

