// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef ToolBarUH
#define ToolBarUH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"

#include "BaseToolV.h"
#include "MyDialogEditU.h"
//---------------------------------------------------------------------------
class  TToolBarForm : public TForm
{
  __published:
    TToolBar *ToolBar;

    private:

    public:
    TMyDialogEdit *Dialog;
    TMyControls DialogTools;
     TToolBarForm(TComponent* Owner);
    void SetToolBar();    
};
//---------------------------------------------------------------------------
extern  TToolBarForm *ToolBarF;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
