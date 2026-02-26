// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaRoomV.h"
#include "MDIElementSelectV.h"
#include "RoomV.h"
//---------------------------------------------------------------------------
#pragma link "MDIElementV"
#pragma resource "*.dfm"
TMDIMetaRoom *MDIMetaRoom;
//---------------------------------------------------------------------------
 TMDIMetaRoom::TMDIMetaRoom(TComponent* Owner,TMetaRoom *M)
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


void  TMDIMetaRoom::tbtAddClick(TObject *Sender)
{
    TMetaElement *MN = (TMetaElement *)SelectNode(TMetaElement::StaticType,true,true,NULL);
    if (MN&&MN!=MetaNode)
        if (!LV->FindData(0,MN,true,false))
            AddSyngleItem(LV,MN);
}
//---------------------------------------------------------------------------

void  TMDIMetaRoom::tbtDelClick(TObject *Sender)
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

