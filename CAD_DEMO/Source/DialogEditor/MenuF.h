//---------------------------------------------------------------------------
#ifndef MenuFH
#define MenuFH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMyDialogEdit;

class PACKAGE TMainMenuF : public TForm
{
  __published:
    TMainMenu *MainMenu;
    TMenuItem *mmView;
    TMenuItem *mmObjectInspector;
    TMenuItem *mmObjectTreeView;
    TMenuItem *mmToolBar;
    void __fastcall mmObjectInspectorClick(TObject *Sender);
    void __fastcall mmObjectTreeViewClick(TObject *Sender);
    void __fastcall mmToolBarClick(TObject *Sender);
    private:

    public:
  __fastcall TMainMenuF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainMenuF *MenuF;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
