// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"

#include "StringListEditorF.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"

TStringListEditor *StringListEditor;
//---------------------------------------------------------------------------
 TStringListEditor::TStringListEditor(TComponent* Owner) : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void  TStringListEditor::OKClick(TObject *Sender)
{
    Close();
}

//---------------------------------------------------------------------------
void  TStringListEditor::CancelClick(TObject *Sender)
{
    Close();
}

//---------------------------------------------------------------------------
