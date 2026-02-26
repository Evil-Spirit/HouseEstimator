// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef MenuFH
#define MenuFH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TMyDialogEdit;

class  TMainMenuF : public TForm
{
  __published:
    TMainMenu *MainMenu;
    TMenuItem *mmView;
    TMenuItem *mmObjectInspector;
    TMenuItem *mmObjectTreeView;
    TMenuItem *mmToolBar;
    void  mmObjectInspectorClick(TObject *Sender);
    void  mmObjectTreeViewClick(TObject *Sender);
    void  mmToolBarClick(TObject *Sender);
    private:

    public:
   TMainMenuF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TMainMenuF *MenuF;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
