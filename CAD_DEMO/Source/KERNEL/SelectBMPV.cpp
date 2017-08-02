 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
      
#include "SelectBMPV.h"
#include "MetaClasses.h"
#include "MDIBMPSetEditV.h"
#include "MetaNodeCollectionV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSelectBMP *SelectBMP;
//---------------------------------------------------------------------------
__fastcall TSelectBMP::TSelectBMP(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TSelectBMP::FormShow(TObject *Sender)
{
    CBE->Clear();
    LV->Clear();
    int _Index = -1;
    TBMPSet *_BMPS;
    TComboExItem *CEI;
    TMTList<TMyRegObject> *List = new TMTList<TMyRegObject>();

    MetaNodeCollection->SelectByCT(NULL, TBMPSet::StaticType ,List,true,true);
    for (int i=0;i<List->Count;i++)
    {
        _BMPS = (TBMPSet *)List->Items[i];
        int ind = _BMPS->ImageIndex;
        CEI = CBE->ItemsEx->AddItem(_BMPS->Name,ind,ind,ind,0,0);
        CEI->Data = _BMPS;
        if (_BMPS == BMPS)
            _Index = i;
    }
    CBE->ItemIndex = _Index;
    if (_Index!=-1)
    {
        _BMPS = (TBMPSet *)CBE->ItemsEx->Items[CBE->ItemIndex]->Data;
        FillLV(LV,_BMPS->IL);
        if (Index<LV->Items->Count)
            LV->ItemIndex = Index;
    }
   BMPS = NULL;
   Index = -1;
}
//---------------------------------------------------------------------------
void __fastcall TSelectBMP::FormCreate(TObject *Sender)
{
   BMPS = NULL;
   Index = -1;
   Clear = false;
}
//---------------------------------------------------------------------------
void __fastcall TSelectBMP::btOKClick(TObject *Sender)
{
    if ( CBE->ItemIndex==-1 || LV->ItemIndex==-1 )
        return;
    BMPS = (TBMPSet *)CBE->ItemsEx->Items[CBE->ItemIndex]->Data;
    Index = LV->ItemIndex;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TSelectBMP::btCancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TSelectBMP::btClearClick(TObject *Sender)
{
    if (Application->MessageBox("Clear?","Confirmation",MB_YESNO)==ID_YES)
    {
        BMPS = NULL;
        Index = -1;
        Clear = true;
        Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TSelectBMP::CBEChange(TObject *Sender)
{
    if (CBE->ItemIndex!=-1)
    {
        TBMPSet *_BMPS = (TBMPSet *)CBE->ItemsEx->Items[CBE->ItemIndex]->Data;
        LV->SmallImages = _BMPS->IL;
        LV->LargeImages = _BMPS->IL;
        FillLV(LV,_BMPS->IL);
    }
}
//---------------------------------------------------------------------------

