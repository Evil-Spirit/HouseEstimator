// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"

#include "PictureEditorF.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"

TPictureEditor *PictureEditor;
//---------------------------------------------------------------------------
 TPictureEditor::TPictureEditor(TComponent* Owner) : TForm(Owner)
{
    SavePictureDialog->FilterIndex = 2;
}

//---------------------------------------------------------------------------
void  TPictureEditor::OKClick(TObject *Sender)
{
    Close();
}

//---------------------------------------------------------------------------
void  TPictureEditor::CancelClick(TObject *Sender)
{
    Close();
}

//---------------------------------------------------------------------------
void  TPictureEditor::ClearClick(TObject *Sender)
{
    Image->Visible = false;
    Save->Enabled = false;
    Clear->Enabled = false;
}

//---------------------------------------------------------------------------
void  TPictureEditor::SaveClick(TObject *Sender)
{
    SavePictureDialog->Execute();
    if ( ! SavePictureDialog->FileName.IsEmpty() )
        Image->Picture->SaveToFile( SavePictureDialog->FileName );
}

//---------------------------------------------------------------------------
void  TPictureEditor::LoadClick(TObject *Sender)
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
