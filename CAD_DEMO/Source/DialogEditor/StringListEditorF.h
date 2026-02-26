// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef StringListEditorFH
#define StringListEditorFH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TStringListEditor : public TForm
{
  __published:
    TPanel *MainPanel;
    TButton *OK;
    TButton *Cancel;
    TMemo *MainMemo;
    void  OKClick(TObject *Sender);
    void  CancelClick(TObject *Sender);
    public:
     TStringListEditor(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern  TStringListEditor *StringListEditor;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
