// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//----------------------------------------------------------------------------
#ifndef DebugUH
#define DebugUH
//----------------------------------------------------------------------------
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include "compat/vcl_qt.h"

extern "C"
{
#include "lua.h"
}

class TGlobal;
class TStackWindow;

/*typedef struct _OldPosition
{
    TLuaModule *Module;
    int OldLine;
} sOldPosition;
*/

//----------------------------------------------------------------------------
class TDebugForm : public TForm
{
__published:
	TMainMenu *MainMenu1;
	TMenuItem *Window1;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowArrangeItem;
	TMenuItem *WindowMinimizeItem;
        TStatusBar *StatusBar;
    TActionList *ActionList;
        TWindowCascade *WindowCascade1;
        TWindowTileHorizontal *WindowTileHorizontal1;
        TWindowArrange *WindowArrangeAll1;
        TWindowMinimizeAll *WindowMinimizeAll1;
        TWindowTileVertical *WindowTileVertical1;
        TMenuItem *WindowTileItem2;
        TToolBar *ToolBar2;
        TImageList *ImageList1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TToolButton *ToolButton6;
    TToolButton *ToolButton7;
    TToolButton *ToolButton8;
    TToolButton *ToolButton9;
    TMenuItem *ViewItem;
    TMenuItem *StackViewItem;
    TMenuItem *LocalVariableItem;
    TMenuItem *GlobalVariableItem;
    TMenuItem *N1;
    TMenuItem *EvaluteModify1;
    TMenuItem *WatchViewItem;
    TMenuItem *Debug1;
    TMenuItem *Start1;
    TMenuItem *Pause1;
    TMenuItem *Stop1;
    TMenuItem *N2;
    TMenuItem *Tracein1;
    TMenuItem *Stepover1;
    TAction *StartItem;
    TAction *PauseItem;
    TAction *StopItem;
    TAction *TraceInItem;
    TAction *StepOverItem;
    TAction *ViewStack;
    TAction *ViewLocalVars;
    TAction *ViewGlobalVars;
    TAction *EvaluteItem;
    TAction *WatchItem;
    TMenuItem *N3;
    TMenuItem *FindModule1;
    TFindDialog *FndDialog;
    TMenuItem *ShowMdlsTree;
    TAction *FindItem;
    TAction *ShowTreeItem;
    TMenuItem *ShowBreakpoints;
    TAction *ShowBrkpntItem;
    TButton *Button1;
    void  StartItemUpdate(TObject *Sender);
    void  StopItemUpdate(TObject *Sender);
    void  TraceInItemUpdate(TObject *Sender);
    void  PauseItemUpdate(TObject *Sender);
    void  FormCreate(TObject *Sender);
    void  StepOverItemUpdate(TObject *Sender);
    void  StopItemExecute(TObject *Sender);
    void  PauseItemExecute(TObject *Sender);
    void  TraceInItemExecute(TObject *Sender);
    void  FormClose(TObject *Sender, TCloseAction &Action);
    void  StepOverItemExecute(TObject *Sender);
    void  FndDialogFind(TObject *Sender);
    void  FindItemExecute(TObject *Sender);
    void  FindItemUpdate(TObject *Sender);
    void  ShowTreeItemExecute(TObject *Sender);
    void  ShowTreeItemUpdate(TObject *Sender);
    void  OnTreeDblClick(TObject *Sender);
    void  OnBrkpntDblClick(TObject *Sender);
    void  StartItemExecute(TObject *Sender);
    void  ShowBrkpntItemExecute(TObject *Sender);
    void  ShowBrkpntItemUpdate(TObject *Sender);
    void  ViewStackExecute(TObject *Sender);
    void  ViewStackUpdate(TObject *Sender);
    void  ViewLocalVarsExecute(TObject *Sender);
    void  ViewLocalVarsUpdate(TObject *Sender);
    void  ViewGlobalVarsUpdate(TObject *Sender);
    void  ViewGlobalVarsExecute(TObject *Sender);
    void  EvaluteModify1Click(TObject *Sender);
    void  WatchItemExecute(TObject *Sender);
    void  WatchItemUpdate(TObject *Sender);
    void  Button1Click(TObject *Sender);

private:
    void  UpdateBreakpoints(TObject *Sender);
    void  UpdateWatches(TObject *Sender);
public:
	virtual  TDebugForm(TComponent *Owner);
    void  WndProc(Messages::TMessage &Message);
     ~TDebugForm();
    TGlobal *GlobalVars,*LocalVars,*BreakPointsWnd, *WatchWnd;
    TStackWindow *StackWnd, *TreeWnd;
    //sOldPosition OldPosition;
};

//----------------------------------------------------------------------------
extern TDebugForm *DebugForm;

//----------------------------------------------------------------------------
#endif
