// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef PictureEditorFH
#define PictureEditorFH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
    void  OKClick(TObject *Sender);
    void  CancelClick(TObject *Sender);
    void  ClearClick(TObject *Sender);
    void  SaveClick(TObject *Sender);
    void  LoadClick(TObject *Sender);
    public:
   TPictureEditor(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern  TPictureEditor *PictureEditor;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
