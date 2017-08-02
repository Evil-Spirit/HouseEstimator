//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "StringListEditorF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TStringListEditor *StringListEditor;
//---------------------------------------------------------------------------
__fastcall TStringListEditor::TStringListEditor(TComponent* Owner) : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TStringListEditor::OKClick(TObject *Sender)
{
    Close();
}

//---------------------------------------------------------------------------
void __fastcall TStringListEditor::CancelClick(TObject *Sender)
{
    Close();
}

//---------------------------------------------------------------------------
