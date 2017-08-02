//---------------------------------------------------------------------------
#ifndef PictureEditorFH
#define PictureEditorFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TPictureEditor : public TForm
{
  __published:
    TButton *OK;
    TButton *Cancel;
    TPanel *MainPanel;
    TButton *Load;
    TButton *Save;
    TButton *Clear;
    TPanel *WorkPanel;
    TImage *Image;
    TOpenPictureDialog *OpenPictureDialog;
    TSavePictureDialog *SavePictureDialog;
    void __fastcall OKClick(TObject *Sender);
    void __fastcall CancelClick(TObject *Sender);
    void __fastcall ClearClick(TObject *Sender);
    void __fastcall SaveClick(TObject *Sender);
    void __fastcall LoadClick(TObject *Sender);
    public:
  __fastcall TPictureEditor(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TPictureEditor *PictureEditor;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
