 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDITriggerBlockEditV.h"
#include "LuaModuleV.h"
#include "TriggerBlockV.h"
#include "MetaClasses.h"
#include "MyMDIChildV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"

TMDITriggerBlockEdit *MDITriggerBlockEdit;
//---------------------------------------------------------------------------
__fastcall TMDITriggerBlockEdit::TMDITriggerBlockEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
TTriggerBlock *TMDITriggerBlockEdit::GetTB(){return (TTriggerBlock*)Obj;};

void UpdateLV(TListView *LV,TTriggerBlock *TB)
{
    LV->Clear();
    for (int i=0;i<TB->According->Count;i++)
    {
        TListItem *LI = LV->Items->Add();
        LI->Caption = TriggerTypeStr[TB->According->Items[i]->intY()];
        LI->Data = TB->According->Items[i];
        LI->ImageIndex = iiLuaModule;
    }
}

void __fastcall TMDITriggerBlockEdit::tbtAddClick(TObject *Sender)
{
    PM->Items->Clear();
    for (int i=0;i<TriggerTypeCount;i++)
    {
        if ( !((TMetaNode*)GetTB()->MyObjectParent)->UsedTrigger(i) )
            continue;
        TMenuItem *MI = new TMenuItem(PM);
        MI->Tag = i;
        MI->Caption = TriggerTypeStr[i];
        MI->OnClick = SelectClick;
        PM->Items->Add(MI);
    }
    TPoint P = tbtAdd->ClientToScreen(TPoint(0,0));
    PM->Popup(P.x,P.y);
}
//---------------------------------------------------------------------------
void __fastcall TMDITriggerBlockEdit::SelectClick(TObject *Sender)
{
    if (IS(Sender,__classid(TMenuItem)))
    {
        TMenuItem *MI =(TMenuItem*)Sender;
        for (int i=0;i<LV->Items->Count;i++)
        {
            TIntVec *IV = (TIntVec *)LV->Items->Item[i]->Data;
            if ( IV->intY() ==  MI->Tag )
                return;
        }
        GetTB()->AddTrigger(MI->Tag);
        if (MI->Tag == trGlobal)
            GetTB()->GetModule(MI->Tag)->Global = true;
        UpdateLV(LV,GetTB());
    }
}
//---------------------------------------------------------------------------
void __fastcall TMDITriggerBlockEdit::tbtDelClick(TObject *Sender)
{
    if (!LV->Selected)
        return;
    int index = LV->Selected->Index;
    TIntVec *IV = (TIntVec *)LV->Items->Item[index]->Data;

    AnsiString STR = AnsiString("Delete event handle: ")+TriggerTypeStr[IV->intY()]+AnsiString(" ?");
    if ( Application->MessageBox(STR.c_str(),"Confirmation",MB_YESNO ) == ID_NO)
        return;
    GetTB()->DeleteTrigger(IV->intY());
    UpdateLV(LV,GetTB());
    if (index<LV->Items->Count)
        LV->Selected = LV->Items->Item[index];
}
//---------------------------------------------------------------------------
void __fastcall TMDITriggerBlockEdit::tbtEditClick(TObject *Sender)
{
    if (!LV->Selected)
        return;
    int index = LV->Selected->Index;
    TIntVec *IV = (TIntVec *)LV->Items->Item[index]->Data;

    TComponent *_Owner = this;
    while (_Owner && !IS(_Owner,__classid(TMyMDIChild)))
        _Owner = _Owner->Owner;

    if (!_Owner)
        return;

    GetTB()->Modules->Items[IV->intX()]->Edit(_Owner,NULL,NULL);
    if (index<LV->Items->Count)
        LV->Selected = LV->Items->Item[index];
}
//---------------------------------------------------------------------------
void TMDITriggerBlockEdit::Refresh()
{
    UpdateLV(LV,GetTB());
}
