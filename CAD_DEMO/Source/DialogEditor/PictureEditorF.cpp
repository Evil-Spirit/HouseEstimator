//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PictureEditorF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TPictureEditor *PictureEditor;
//---------------------------------------------------------------------------
__fastcall TPictureEditor::TPictureEditor(TComponent* Owner) : TForm(Owner)
{
    SavePictureDialog->FilterIndex = 2;
}

//---------------------------------------------------------------------------
void __fastcall TPictureEditor::OKClick(TObject *Sender)
{
    Close();
}

//---------------------------------------------------------------------------
void __fastcall TPictureEditor::CancelClick(TObject *Sender)
{
    Close();
}

//---------------------------------------------------------------------------
void __fastcall TPictureEditor::ClearClick(TObject *Sender)
{
    Image->Visible = false;
    Save->Enabled = false;
    Clear->Enabled = false;
}

//---------------------------------------------------------------------------
void __fastcall TPictureEditor::SaveClick(TObject *Sender)
{
    SavePictureDialog->Execute();
    if ( ! SavePictureDialog->FileName.IsEmpty() )
        Image->Picture->SaveToFile( SavePictureDialog->FileName );
}

//---------------------------------------------------------------------------
void __fastcall TPictureEditor::LoadClick(TObject *Sender)
{
    OpenPictureDialog->Execute();
    if ( ! OpenPictureDialog->FileName.IsEmpty() )
    {
        Image->Picture->LoadFromFile( OpenPictureDialog->FileName );
        Save->Enabled = true;
        Clear->Enabled = true;
    }
    Image->Visible = true;
}

//---------------------------------------------------------------------------
