//---------------------------------------------------------------------------
#ifndef ToolBarUH
#define ToolBarUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>

#include "BaseToolV.h"
#include "MyDialogEditU.h"
//---------------------------------------------------------------------------
class PACKAGE TToolBarForm : public TForm
{
  __published:
    TToolBar *ToolBar;

    private:

    public:
    TMyDialogEdit *Dialog;
    TMyControls DialogTools;
    __fastcall TToolBarForm(TComponent* Owner);
    void SetToolBar();    
};
//---------------------------------------------------------------------------
extern PACKAGE TToolBarForm *ToolBarF;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
