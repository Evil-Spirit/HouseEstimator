//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIPointerListEditV.h"
#include "MDIElementSelectV.h"
#include "MetaClasses.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIPointerListEdit *MDIPointerListEdit;
//---------------------------------------------------------------------------
__fastcall TMDIPointerListEdit::TMDIPointerListEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data, bool AllowDuplicates)
	: TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
	this->AllowDuplicates = AllowDuplicates;
	this->FEXCL = NULL;
}
//---------------------------------------------------------------------------
TMetaNode* TMDIPointerListEdit::SetEXCL(TMetaNode* EXCL)
{
	this->FEXCL = EXCL;
	if(FEXCL == (TMetaNode *)-1)
		tbReset->Visible = true;
	else
		tbReset->Visible = false;
	return this->FEXCL;
}
//---------------------------------------------------------------------------
TPointer<TMetaNode>* CreateMetaElementPointer()
{
	return (TPointer<TMetaNode>*)new TPointer<TMetaElement>;
}

TListItem *AddSyngleItemWithoutNULLCheck(TListView *LV,TMetaNode *MN)
{
	TListItem *IT = LV->Items->Add();
	IT->Caption = (MN != NULL ? MN->Name : AnsiString("<NULL>"));
	IT->ImageIndex = (MN != NULL ? MN->ImageIndex : -1);
	IT->StateIndex = -1;
	IT->Data = MN;
	return IT;
}

TListItem *AddSyngleItem(TListView *LV,TMetaNode *MN)
{
	if (!MN)
		return NULL;
	return AddSyngleItemWithoutNULLCheck(LV,MN);
}

void TMDIPointerListEdit::SETUP()
{
    List = (/*TMDelLSTList*/TMDelTList< TPointer<TMetaNode> >*)Obj;
    CN = (TClassNode*)DATA;
    EXCL = NULL;
    NewItem = NULL;
}

void TMDIPointerListEdit::Apply()
{
    List->Clear();
    for (int i=0;i<LV->Items->Count;i++)
    {
        TPointer<TMetaNode> *P_ME = NewItem();
        P_ME->ADR = (TMetaNode*)LV->Items->Item[i]->Data;
        List->Add(P_ME);
    }
}

void TMDIPointerListEdit::Refresh()
{
    LV->Clear();
	for (int i=0;i<List->Count;i++)
		if(FEXCL != (TMetaNode *)-1)
			AddSyngleItem(LV,List->Items[i]->ADR);
		else
			AddSyngleItemWithoutNULLCheck(LV,List->Items[i]->ADR);
}

bool TMDIPointerListEdit::Checked()
{
	return true;
};

void __fastcall TMDIPointerListEdit::btAddClick(TObject *Sender)
{
	TMetaNode *MN = SelectNode(CN,true,true,NULL);
	if (MN&&MN!=EXCL)
		if (!LV->FindData(0,MN,true,false) || AllowDuplicates)
			AddSyngleItem(LV,MN);
}
//---------------------------------------------------------------------------
void __fastcall TMDIPointerListEdit::btDelClick(TObject *Sender)
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

void __fastcall TMDIPointerListEdit::sbupClick(TObject *Sender)
{
    if (LV->Selected&&LV->Selected->Index!=0)
    {
        TListItem* LI = LV->Items->Insert(LV->Selected->Index-1);
        LI->Assign(LV->Selected);
        delete LV->Selected;
        LV->Selected = LI;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDIPointerListEdit::sbdownClick(TObject *Sender)
{
    if (LV->Selected&&LV->Selected->Index!=LV->Items->Count-1)
    {
        if (LV->Selected->Index!=LV->Items->Count-2)
        {
            TListItem* LI = LV->Items->Insert(LV->Selected->Index+2);
            LI->Assign(LV->Selected);
            delete LV->Selected;
            LV->Selected = LI;
        }
        else
        {
			TListItem* LI = LV->Items->Add();
            LI->Assign(LV->Selected);
            delete LV->Selected;
            LV->Selected = LI;
        }
    }

}

void __fastcall TMDIPointerListEdit::tbResetClick(TObject *Sender)
{
	AddSyngleItemWithoutNULLCheck(LV, NULL);
}
//---------------------------------------------------------------------------

