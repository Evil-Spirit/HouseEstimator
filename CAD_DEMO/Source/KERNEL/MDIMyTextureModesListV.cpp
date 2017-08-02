//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMyTextureModesListV.h"
#include "MDIMyTextureModesV.h"
#include "MetaClasses.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIMyTextureModesList *MDIMyTextureModesList;
//---------------------------------------------------------------------------
__fastcall TMDIMyTextureModesList::TMDIMyTextureModesList(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}

void AssignTextureModes(TMyTextureModes *Tar,TMyTextureModes *Sou)
{
    Tar->Assign(Sou);
    Tar->RecurrentCheck();
}

void FillSettingList(TListView *LV,TMyTextureModesList *F_Obj )
{
  LV->Items->Clear();
  for (int i=0;i<F_Obj->TEXMODES.Count;i++)
  {
    TListItem *It = LV->Items->Add();
    It->StateIndex = -1;
    It->Data = F_Obj->TEXMODES.Items[i];
    It->Caption = TextureModeStr[F_Obj->TEXMODES.Items[i]->Mode];
    It->ImageIndex = -1;
  }
}

bool TMDIMyTextureModesList::CheckCurrent(bool ApplyIfChecked)
{
    if (SSS->ControlCount == 0)
        return true;

    TMDIObjectEdit *__Obj = (TMDIObjectEdit *)SSS->Controls[0];
    if (!__Obj->Checked())
    {
        Application->MessageBox("Correct current mode","");
        for (int i=0;i<LV->Items->Count;i++)
            if (LV->Items->Item[i]->Data == __Obj->Obj)
                LV->Selected = LV->Items->Item[i];
        return false;
    }
    else if (ApplyIfChecked)
    {
        __Obj->Apply();
        delete __Obj;
    }
  return true;
}


void TMDIMyTextureModesList::SETUP()
{
  COPY = new TMyTextureModesList();
}

void TMDIMyTextureModesList::KILL()
{
  delete COPY;
}

void __fastcall TMDIMyTextureModesList::tbtAddClick(TObject *Sender)
{
    COPY->TEXMODES.Add( new TMyTextureModes() );
    COPY->TEXMODES.Last()->Mode = tmCeil;
    FillSettingList(LV,COPY);
}
//---------------------------------------------------------------------------
void TMDIMyTextureModesList::Refresh()
{
    COPY->Assign((TMyTextureModesList *)Obj);
    COPY->RecurrentCheck();
    FillSettingList(LV,COPY);
}

void TMDIMyTextureModesList::Apply()
{
  if (SSS->ControlCount>0 )
  {
    TMDIObjectEdit *__Obj = (TMDIObjectEdit *)SSS->Controls[0];
    __Obj->Apply();
    delete __Obj;
  }
  TMyTextureModesList *__Obj = (TMyTextureModesList *)Obj;
  __Obj->Assign(COPY);
  __Obj->RecurrentCheck();
}

bool TMDIMyTextureModesList::Checked()
{
    return CheckCurrent(false);
}

void __fastcall TMDIMyTextureModesList::LVClick(TObject *Sender)
{
    if (!LV->Selected)
        return;
    if ( CheckCurrent(true) )
    {
        for (int i=0;i<LV->Items->Count;i++)
            LV->Items->Item[i]->Caption =  TextureModeStr[((TMyTextureModes*)LV->Items->Item[i]->Data)->Mode];
        TMyTextureModes *Settings = (TMyTextureModes *)LV->Selected->Data;
        Settings->Edit(this,SSS,NULL);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDIMyTextureModesList::tbtDelClick(TObject *Sender)
{
  if (!LV->Selected)
    return;
  if (SSS->ControlCount>0 )
  {
    TMDIObjectEdit *__Obj = (TMDIObjectEdit *)SSS->Controls[0];
    delete __Obj;
  }

  int index =  COPY->TEXMODES.IndexOf((TMyTextureModes*)LV->Selected->Data);
  if (index!=-1)
  {
    COPY->TEXMODES.Delete(index);
    FillSettingList(LV,COPY);
  }
}
//---------------------------------------------------------------------------

