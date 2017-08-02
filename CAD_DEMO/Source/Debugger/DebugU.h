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
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>

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
    void __fastcall StartItemUpdate(TObject *Sender);
    void __fastcall StopItemUpdate(TObject *Sender);
    void __fastcall TraceInItemUpdate(TObject *Sender);
    void __fastcall PauseItemUpdate(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall StepOverItemUpdate(TObject *Sender);
    void __fastcall StopItemExecute(TObject *Sender);
    void __fastcall PauseItemExecute(TObject *Sender);
    void __fastcall TraceInItemExecute(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall StepOverItemExecute(TObject *Sender);
    void __fastcall FndDialogFind(TObject *Sender);
    void __fastcall FindItemExecute(TObject *Sender);
    void __fastcall FindItemUpdate(TObject *Sender);
    void __fastcall ShowTreeItemExecute(TObject *Sender);
    void __fastcall ShowTreeItemUpdate(TObject *Sender);
    void __fastcall OnTreeDblClick(TObject *Sender);
    void __fastcall OnBrkpntDblClick(TObject *Sender);
    void __fastcall StartItemExecute(TObject *Sender);
    void __fastcall ShowBrkpntItemExecute(TObject *Sender);
    void __fastcall ShowBrkpntItemUpdate(TObject *Sender);
    void __fastcall ViewStackExecute(TObject *Sender);
    void __fastcall ViewStackUpdate(TObject *Sender);
    void __fastcall ViewLocalVarsExecute(TObject *Sender);
    void __fastcall ViewLocalVarsUpdate(TObject *Sender);
    void __fastcall ViewGlobalVarsUpdate(TObject *Sender);
    void __fastcall ViewGlobalVarsExecute(TObject *Sender);
    void __fastcall EvaluteModify1Click(TObject *Sender);
    void __fastcall WatchItemExecute(TObject *Sender);
    void __fastcall WatchItemUpdate(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);

private:
    void __fastcall UpdateBreakpoints(TObject *Sender);
    void __fastcall UpdateWatches(TObject *Sender);
public:
	virtual __fastcall TDebugForm(TComponent *Owner);
    void __fastcall WndProc(Messages::TMessage &Message);
    __fastcall ~TDebugForm();
    TGlobal *GlobalVars,*LocalVars,*BreakPointsWnd, *WatchWnd;
    TStackWindow *StackWnd, *TreeWnd;
    //sOldPosition OldPosition;
};

//----------------------------------------------------------------------------
extern TDebugForm *DebugForm;

//----------------------------------------------------------------------------
#endif
