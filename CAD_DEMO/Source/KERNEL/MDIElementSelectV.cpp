 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIElementSelectV.h"
//#include "MDIConfigV.h"
#include "MetaNodeCollectionV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMDIElementSelect *MDIElementSelect;
//---------------------------------------------------------------------------
__fastcall TMDIElementSelect::TMDIElementSelect(TComponent* Owner,TClassNode* CN,bool self,bool childs,TMetaNode *_Parent)
    : TForm(Owner)
{
    Selected = NULL;
    TMTList<TMyRegObject>* L = new TMTList<TMyRegObject>();
    MetaNodeCollection->SelectByCT(_Parent,CN,L,self,childs);
    LV->Clear();
    for (int i=0;i<L->Count;i++)
    {
        TMetaNode *MN = (TMetaNode*)L->Items[i];
        TListItem *IT = LV->Items->Add();
        IT->Caption = MN->Name;
        IT->ImageIndex = MN->ImageIndex;
        IT->StateIndex = -1;
        IT->Data = MN;
    }
    delete L;
}
//---------------------------------------------------------------------------
void __fastcall TMDIElementSelect::OKClick(TObject *Sender)
{
    if (!(LV->Selected))
        return;
    Selected = (TMetaNode*)(LV->Selected->Data);
    if (!Selected)
        return;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMDIElementSelect::btCancelClick(TObject *Sender)
{
    Selected = NULL;
    Close();    
}
//---------------------------------------------------------------------------

TMetaNode *SelectNode(TClassNode* CN,bool self,bool childs,TMetaNode *Parent)
{
    TMDIElementSelect *SEL = new TMDIElementSelect(NULL,CN,self,childs,Parent);
    SEL->ShowModal();
    TMetaNode *MN = SEL->Selected;
    delete SEL;
    return MN;     
}
