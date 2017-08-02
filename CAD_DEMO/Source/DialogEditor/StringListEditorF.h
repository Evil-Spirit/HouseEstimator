//---------------------------------------------------------------------------
#ifndef StringListEditorFH
#define StringListEditorFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TStringListEditor : public TForm
{
  __published:
    TPanel *MainPanel;
    TButton *OK;
    TButton *Cancel;
    TMemo *MainMemo;
    void __fastcall OKClick(TObject *Sender);
    void __fastcall CancelClick(TObject *Sender);
    public:
    __fastcall TStringListEditor(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TStringListEditor *StringListEditor;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
