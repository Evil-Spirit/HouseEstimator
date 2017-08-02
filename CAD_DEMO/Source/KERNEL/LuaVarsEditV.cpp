 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LuaVarsEditV.h"
#include "typeinfo.h"
#include "AddLuaVarV.h"
#include "MetaClasses.h"
#include "LuaAttributeV.h"

//#include "MDIConfigV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLuaVarsEdit *LuaVarsEdit;
//---------------------------------------------------------------------------
__fastcall TLuaVarsEdit::TLuaVarsEdit(  TComponent* Owner,
                                        TControl *_Parent,
                                        TMyObject *_Obj,
                                        const AnsiString& Text,
                                        void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
void _AutoSize(TListView *LV)
{
/*    for (int i=0;i<LV->Columns->Count;i++)
    {
        LV->Column[i]->Width=-1;
        LV->Update();
        LV->Column[i]->Width = MAX(LV->Column[i]->Width,LV->Column[i]->Tag);
    }*/
}

bool CheckName(TListView *LV, const AnsiString& newName,TListItem* LI)
{
    for (int j=0;j<LV->Items->Count;j++)
        if (LV->Items->Item[j]!=LI  && LV->Items->Item[j]->Caption == newName)
            return false;
    return true;
}

int FindTypeByName(const AnsiString& tName)
{
    if (StrTypes[mtInt]==tName)
        return mtInt;
    if (StrTypes[mtDouble]==tName)
        return mtDouble;
    if (StrTypes[mtString]==tName)
        return mtString;
    return mtString;
}

void __fastcall TLuaVarsEdit::btAddClick(TObject *Sender)
{
    TAddLuaVar *ALV= new TAddLuaVar(NULL);
    ALV->VarName = "NewVar";
    ALV->VarType = mtInt;
    ALV->VarVal = "0";
    do{
        ALV->ShowModal();
    }while(ALV->OK && !CheckName(LV,ALV->VarName,NULL));
    if (ALV->OK)
        AddItem(ALV->VarName,ALV->VarType,ALV->VarVal,ALV->Comment,ALV->Meter);
    delete ALV;
    _AutoSize(LV);
}
//---------------------------------------------------------------------------


void TLuaVarsEdit::AddItem( const AnsiString& _Name,
                            int _Type,
                            const AnsiString& _Value,
                            const AnsiString& _Comment,
                            const AnsiString& _Meter)
{
    TListItem *LI = LV->Items->Add();
    LI->Caption = _Name;
    LI->SubItems->Add(StrTypes[_Type]);
    LI->SubItems->Add(_Value);
    LI->SubItems->Add(_Comment);
    LI->SubItems->Add(_Meter);
}

void TLuaVarsEdit::AddLuaVar(TLuaAttribute *LV)
{
    AddItem(LV->Name,LV->Type,LV->VALUE,LV->Description,LV->Meter);
}

void TLuaVarsEdit::Refresh()
{
    LV->Items->Clear();
    for (int i=0;i<Element->Attributes->Count;i++)
        AddLuaVar(Element->Attributes->Items[i]);
    _AutoSize(LV);
}

void TLuaVarsEdit::Apply()
{
    Element->Attributes->Clear();
    for (int i=0;i<LV->Items->Count;i++)
    {
        TLuaAttribute *L = new TLuaAttribute();
        TListItem * LI = LV->Items->Item[i];
        L->ReadOnly = false;
        L->Name = LI->Caption;
        L->Type = FindTypeByName(LI->SubItems->Strings[0]);
        L->VALUE = LI->SubItems->Strings[1];
        L->Description = LI->SubItems->Strings[2];
        L->Meter = LI->SubItems->Strings[3];
        L->ReadOnly = true;
        Element->Attributes->Add(L);
    }
}


void __fastcall TLuaVarsEdit::btEditClick(TObject *Sender)
{
    if (!LV->Selected)
        return;
    TListItem *LI = LV->Selected;
    TAddLuaVar *ALV= new TAddLuaVar(NULL);
    ALV->VarName = LI->Caption;
    ALV->VarType = FindTypeByName(LI->SubItems->Strings[0]);
    ALV->VarVal = LI->SubItems->Strings[1];
    ALV->Comment = LI->SubItems->Strings[2];
    ALV->Meter = LI->SubItems->Strings[3];
    do{
        ALV->ShowModal();
    }while(ALV->OK && !CheckName(LV,ALV->VarName,LV->Selected));
    if (ALV->OK)
    {
        LI->Caption = ALV->VarName;
        LI->SubItems->Strings[0] = StrTypes[ALV->VarType];
        LI->SubItems->Strings[1] = ALV->VarVal;
        LI->SubItems->Strings[2] = ALV->Comment;
        LI->SubItems->Strings[3] = ALV->Meter;
    }
    delete ALV;
    _AutoSize(LV);
}
//---------------------------------------------------------------------------

void __fastcall TLuaVarsEdit::btDelClick(TObject *Sender)
{
    if (LV->Selected&&Application->MessageBox( (AnsiString("Delete variable ")+LV->Selected->Caption+AnsiString("?")).c_str(),"Confirmation",MB_YESNO)==IDYES)
    {
        int index = LV->Selected->Index;
        delete LV->Selected;
        if (index<LV->Items->Count)
            LV->Selected = LV->Items->Item[index];
    }
    _AutoSize(LV);
}
//---------------------------------------------------------------------------


