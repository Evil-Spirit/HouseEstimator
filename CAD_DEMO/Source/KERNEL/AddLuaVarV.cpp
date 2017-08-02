 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "AddLuaVarV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddLuaVar *AddLuaVar;
//---------------------------------------------------------------------------
__fastcall TAddLuaVar::TAddLuaVar(TComponent* Owner)
    : TForm(Owner)
{
}

bool VariantNameOK(const AnsiString& Name)
{
    AnsiString AllowSyms = _ABC_+AnsiString("_");
    for (int i=1;i<Name.Length();i++)
        if (i==1&&AllowSyms.Pos(AnsiString(Name[i]))==0)
            return false;
        else if ((AllowSyms.Pos(AnsiString(Name[i]))==0) &&
            (DIGITS.Pos(AnsiString(Name[i]))==0))
            return false;
    return true;
}

//---------------------------------------------------------------------------
void __fastcall TAddLuaVar::FormCreate(TObject *Sender)
{
    cbVarType->Items->Clear();
    for (int i=0;i<3;i++)
        cbVarType->Items->Add(StrTypes[i]);
    cbVarType->ItemIndex = 0;
    VarType=0;
    VarName = "";
    VarVal = "0";
    Comment = "No comments";
    Meter = "";
}
//---------------------------------------------------------------------------
void __fastcall TAddLuaVar::FormShow(TObject *Sender)
{
    eVarName->Text = VarName;
    cbVarType->ItemIndex = VarType;
    eVarVal->Text = VarVal;
    eComment->Text = Comment;
    eMeter->Text = Meter;

    OK = false;
}
//---------------------------------------------------------------------------
void __fastcall TAddLuaVar::btOKClick(TObject *Sender)
{
    AnsiString AllowSyms = _ABC_+AnsiString("_");
    if (eVarName->Text.IsEmpty())
    {
        Application->MessageBox("Input name","Input name");
        return;
    }
    if (!VariantNameOK(eVarName->Text))
    {
        Application->MessageBox("The name is incorrect","The name is incorrect");
        return;
    }
    switch(cbVarType->ItemIndex)
    {
        case mtInt:
        {
            if (!ISINTEGER(eVarVal->Text))
                return;
        }
        break;
        case mtDouble:
        {
            if (!IS_FLOAT(eVarVal->Text))
                return;
        }
        break;
        case mtString:break;
        default:return;
    }
    if (eComment->Text.Trim().IsEmpty())
    {
        Application->MessageBox("The comment is empty","The comment is empty");
        return;
    }

    OK= true;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TAddLuaVar::btCancelClick(TObject *Sender)
{
    OK=false;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TAddLuaVar::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    VarType = cbVarType->ItemIndex;
    VarName = eVarName->Text.Trim().LowerCase();
    VarVal = eVarVal->Text.Trim();
    Comment = eComment->Text.Trim();
    Meter = eMeter->Text.Trim();
}
//---------------------------------------------------------------------------
