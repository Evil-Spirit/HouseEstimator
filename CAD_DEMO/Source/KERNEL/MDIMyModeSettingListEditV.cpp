 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMyModeSettingListEditV.h"
#include "MDIElementSelectV.h"
#include "MetaClasses.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIMyModeSettingListEdit *MDIMyModeSettingListEdit;
//---------------------------------------------------------------------------
__fastcall TMDIMyModeSettingListEdit::TMDIMyModeSettingListEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
void AssignMyModeSettings(TMyModeSettings *Tar,TMyModeSettings *Sou)
{
	Tar->Assign(Sou);
	Tar->RecurrentCheck();
/*
    Tar->Meta_Mode.ADR = Sou->Meta_Mode.ADR;
    Tar->MAT.ADR = Sou->MAT.ADR;
    Tar->TEX.ADR = Sou->TEX.ADR;
    Tar->OverSize = Sou->OverSize;
	Tar->OverSizeMode = Sou->OverSizeMode;
	Tar->OverPos = Sou->OverPos;
	Tar->OverPosMode = Sou->OverPosMode;
	Tar->Render = Sou->Render;
	Tar->FLAT_2D = Sou->FLAT_2D;
	*/
}

void FillSettingList(TListView *LV,TMyModeSettingList *S_List )
{
  LV->Items->Clear();
  for (int i=0;i<S_List->Mode_Set_List->Count;i++)
  {
	TListItem *It = LV->Items->Add();
	if (S_List->Mode_Set_List->Items[i]->Meta_Mode.ADR)
	{
	  It->Caption = S_List->Mode_Set_List->Items[i]->Meta_Mode.ADR->Name;
	  It->ImageIndex = S_List->Mode_Set_List->Items[i]->Meta_Mode.ADR->ImageIndex;
	}
	It->StateIndex = -1;
	It->Data = S_List->Mode_Set_List->Items[i];
  }
}

void __fastcall TMDIMyModeSettingListEdit::tbtAddClick(TObject *Sender)
{
  TMetaNode *SN = SelectNode(TMetaMyMode::StaticType,true,true,NULL);
  bool Exists=false;
  for (int i=0;i<EditCopy->Mode_Set_List->Count;i++)
	if (EditCopy->Mode_Set_List->Items[i]->Meta_Mode.ADR == SN)
	{
	  Exists = true;
	  break;
	}
  if (SN && !Exists)
  {
	EditCopy->Mode_Set_List->Add( new TMyModeSettings() );
	EditCopy->Mode_Set_List->Items[EditCopy->Mode_Set_List->Count-1]->Meta_Mode.ADR = (TMetaMyMode*)SN;
	FillSettingList(LV,EditCopy);
  }
}
//---------------------------------------------------------------------------

void TMDIMyModeSettingListEdit::Refresh()
{
  TMyModeSettingList *__Obj = (TMyModeSettingList *)Obj;
  EditCopy->Mode_Set_List->Clear();
  for (int i=0;i<__Obj->Mode_Set_List->Count;i++)
  {
	EditCopy->Mode_Set_List->Add( new TMyModeSettings() );
	AssignMyModeSettings( EditCopy->Mode_Set_List->Items[i],
						  __Obj->Mode_Set_List->Items[i]);
  }
  FillSettingList(LV,EditCopy);
  EditCopy->DefaultMode.ADR = __Obj->DefaultMode.ADR;
}

void TMDIMyModeSettingListEdit::Apply()
{
  if (SSS->ControlCount>0 )
  {
	TMDIObjectEdit *__Obj = (TMDIObjectEdit *)SSS->Controls[0];
	__Obj->Apply();
	delete __Obj;
  }
  TMyModeSettingList *__Obj = (TMyModeSettingList *)Obj;
  __Obj->Mode_Set_List->Clear();
  for (int i=0;i<EditCopy->Mode_Set_List->Count;i++)
  {
	__Obj->Mode_Set_List->Add( new TMyModeSettings() );
	AssignMyModeSettings( __Obj->Mode_Set_List->Items[i],
						  EditCopy->Mode_Set_List->Items[i]);
  }
  __Obj->DefaultMode.ADR = EditCopy->DefaultMode.ADR;
}

bool TMDIMyModeSettingListEdit::Checked()
{
  if (SSS->ControlCount>0 )
  {
	TMDIObjectEdit *__Obj = (TMDIObjectEdit *)SSS->Controls[0];
	if (!__Obj->Checked())
	{
	  Application->MessageBox("Correct current mode","");
	  for (int i=0;i<LV->Items->Count;i++)
		if (LV->Items->Item[i]->Data == __Obj->Obj)
		  LV->Selected = LV->Items->Item[i];
	  return false;
	}
  }
  return true;
}

void TMDIMyModeSettingListEdit::SETUP()
{
  EditCopy = new TMyModeSettingList();
}

void TMDIMyModeSettingListEdit::KILL()
{
  delete EditCopy;
}
void __fastcall TMDIMyModeSettingListEdit::tbtDelClick(TObject *Sender)
{
  if (!LV->Selected)
	return;
  if (SSS->ControlCount>0 )
  {
	TMDIObjectEdit *__Obj = (TMDIObjectEdit *)SSS->Controls[0];
	delete __Obj;
  }

  int index = EditCopy->Mode_Set_List->IndexOf((TMyModeSettings*)LV->Selected->Data);
  if (index!=-1)
  {
	EditCopy->Mode_Set_List->Delete(index);
	FillSettingList(LV,EditCopy);
  }
}
//---------------------------------------------------------------------------
void __fastcall TMDIMyModeSettingListEdit::LVClick(TObject *Sender)
{
  if (!LV->Selected)
	return;
  if (SSS->ControlCount>0 )
  {
	TMDIObjectEdit *__Obj = (TMDIObjectEdit *)SSS->Controls[0];
	if (!__Obj->Checked())
	{
	  Application->MessageBox("Correct current mode","");
	  for (int i=0;i<LV->Items->Count;i++)
		if (LV->Items->Item[i]->Data == __Obj->Obj)
		  LV->Selected = LV->Items->Item[i];
	  return;
	}
	__Obj->Apply();
	delete __Obj;
  }

  TMyModeSettings *Settings = (TMyModeSettings *)LV->Selected->Data;

  IsDefault->OnClick = NULL;
  IsDefault->Checked = false;
  if(EditCopy->DefaultMode.ADR == Settings->Meta_Mode.ADR)
  {
	IsDefault->Checked = true;
  }
  IsDefault->OnClick = IsDefaultClick;

  Settings->Edit(this,SSS,NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMDIMyModeSettingListEdit::IsDefaultClick(TObject *Sender)
{
  if(!LV->Selected)
	return;
  if(IsDefault->Checked)
	EditCopy->DefaultMode.ADR = ((TMyModeSettings *)LV->Selected->Data)->Meta_Mode.ADR;
  else
	EditCopy->DefaultMode.ADR = NULL;
}
//---------------------------------------------------------------------------

