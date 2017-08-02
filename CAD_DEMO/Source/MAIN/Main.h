//----------------------------------------------------------------------------
#ifndef MainH
#define MainH
//----------------------------------------------------------------------------

#include "VisTimer.hpp"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <StdActns.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>
#include "BaseDockSiteFormV.h"
#include "FloatingV.h"
#include "SUISkinEngine.hpp"
#include <AppEvnts.hpp>


class TMetaElement;
class TMyMDIChild;
//должен быть один и только один определен
//#define INTERNET_VER;
//#define TRADE_VER;

const int FULL_VERSION = 0;
const int INTERNET_VERSION = 1;
const int TRADE_VERSION = 2;

#if defined(INTERNET_VER)
const int PROG_VERSION = INTERNET_VERSION;
#elif defined(TRADE_VER)
const int PROG_VERSION = TRADE_VERSION;
#else
const int PROG_VERSION = FULL_VERSION;
#endif



enum   TMDITypes {mtMDI3D,mtMDI3DUser, mtMDI2D, mtMDIConfig} ;
//----------------------------------------------------------------------------
class TConfig : public TBaseDockSiteForm
{
__published:
	TMenuItem *File1;
	TMenuItem *FileNewItem;
	TMenuItem *FileOpenItem;
	TMenuItem *FileCloseItem;
	TMenuItem *Window1;
	TMenuItem *Help1;
	TMenuItem *N1;
	TMenuItem *FileExitItem;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowArrangeItem;
	TMenuItem *HelpAboutItem;
	TOpenDialog *OpenDialog;
	TMenuItem *FileSaveItem;
	TMenuItem *FileSaveAsItem;
	TMenuItem *Edit1;
	TMenuItem *CutItem;
	TMenuItem *CopyItem;
	TMenuItem *PasteItem;
	TMenuItem *WindowMinimizeItem;
        TActionList *ActionList1;
        TEditCut *EditCut1;
        TEditCopy *EditCopy1;
        TEditPaste *EditPaste1;
        TAction *FileNew1;
        TAction *FileSave1;
        TAction *FileExit1;
        TAction *FileOpen1;
        TAction *FileSaveAs1;
        TWindowCascade *WindowCascade1;
        TWindowTileHorizontal *WindowTileHorizontal1;
        TWindowArrange *WindowArrangeAll1;
        TWindowMinimizeAll *WindowMinimizeAll1;
        TAction *HelpAbout1;
        TWindowClose *FileClose1;
        TWindowTileVertical *WindowTileVertical1;
        TMenuItem *WindowTileItem2;
    TAction *Configurator;
    TMenuItem *miTransformation;
    TMenuItem *miFloors;
    TMenuItem *mfNew;
    TMenuItem *miView;
  TMenuItem *mShowElTree;
    TMenuItem *MActualFloor;
    TMenuItem *N10;
    TMenuItem *N11;
    TSaveDialog *SaveDialog1;
    TImageList *UserImages;
    TPopupMenu *PM;
    TControlBar *ControlBar1;
    TToolBar *ToolBar2;
    TToolButton *ToolButton9;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TToolButton *ToolButton6;
    TToolButton *ToolButton14;
    TEditUndo *EditUndo1;
    TEditSelectAll *EditSelectAll1;
    TMenuItem *Undo1;
    TMenuItem *Redo1;
    TMenuItem *Delete1;
    TMenuItem *SelectAll1;
    TMenuItem *N2;
    TToolBar *tbLua_Edit;
  TMenuItem *mCount;
    TMainMenu *MainMenu1;
    TEditDelete *EditDelete1;
    TMenuItem *Print1;
    TFilePrintSetup *FilePrintSetup1;
    TMenuItem *N4;
    TSearchFind *SearchFind1;
    TSearchFindNext *SearchFindNext1;
    TSearchReplace *SearchReplace1;
    TMenuItem *miModule;
    TMenuItem *N15;
    TMenuItem *N13;
    TMenuItem *N14;
    TToolBar *TBFloors;
  TToolButton *ToolButton20;
  TToolButton *ToolButton21;
  TToolButton *ToolButton23;
  TToolButton *ToolButton24;
  TPopupMenu *pmModes;
  TToolButton *ToolButton25;
  TToolButton *ToolButton7;
  TToolButton *ToolButton15;
  TToolButton *ToolButton22;
    TMenuItem *miCheck;
    TToolButton *ToolButton27;
    TToolButton *ToolButton28;
    TToolButton *ToolButton29;
    TToolButton *ToolButton30;
    TTimer *MainTimer;
    TFindDialog *FindAllDialog;
    TAction *SearchAllModules;
    TMenuItem *N3;
    TToolButton *ToolButton31;
    TMenuItem *N5;
    TPrintDlg *PrintDlg1;
    TAction *EditRedo1;
    TToolButton *ToolButton32;
    TAction *ViewNet;
    TAction *ViewLand;
    TMenuItem *NViewLand;
    TMenuItem *NViewNet;
    TToolButton *ToolButton8;
    TToolButton *ToolButton10;
    TToolButton *ToolButton11;
    TToolButton *tbCatalog;
    TToolBar *tbMyActions;
    TActionList *alViewObj;
    TPopupMenu *pmViewObj;
    TAction *AdvTexture;
    TToolButton *ToolButton33;
    TToolBar *MainToolBar;
    TAction *FileDigitalSave;
    TMenuItem *FileDigitalSave1;
	TToolBar *LuaModuleBar;
	TComboBox *LuaModulesCombo;
	TToolButton *Refresh;
	TToolButton *SelectBtn;
        TToolBar *tbCamera;
        TToolButton *Scroller;
        TToolButton *ToolButton19;
        TToolButton *ToolButton12;
        TToolButton *ToolButton17;
        TToolButton *ToolButton18;
        TToolButton *Z1;
        TToolButton *Z2;
        TToolButton *tbModes;
        TToolButton *ToolButton16;
        TToolButton *ToolButton26;
        TToolButton *ToolButton13;
	TImageList *ImageList;
	TToolButton *ToolButton34;
  TImageList *DisabledImages;
  TImageList *MainMenuImages;
  TPanel *Panel1;
  TComboBox *cbFloors;
        void __fastcall FileNew1Execute(TObject *Sender);
        void __fastcall HelpAbout1Execute(TObject *Sender);
        void __fastcall FileExit1Execute(TObject *Sender);
    void __fastcall ScrollerMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ScrollerMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall ConfiguratorExecute(TObject *Sender);
    void __fastcall ToolButton15Click(TObject *Sender);
    void __fastcall ToolButton16Click(TObject *Sender);
    void __fastcall mfNewClick(TObject *Sender);
    void __fastcall FileSaveAs1Execute(TObject *Sender);
    void __fastcall FileOpen1Execute(TObject *Sender);
    void __fastcall btCheckClick(TObject *Sender);
    void __fastcall mCountClick(TObject *Sender);
    void __fastcall mWorkCountClick(TObject *Sender);
    void __fastcall PrintDlg1Accept(TObject *Sender);
    void __fastcall PrintDlg1BeforeExecute(TObject *Sender);
  void __fastcall ToolButton12MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
  void __fastcall cbFloorsCloseUp(TObject *Sender);
  void __fastcall miModeClick(TObject *Sender);
    void __fastcall SearchFind1FindDialogFind(TObject *Sender);
    void __fastcall SearchReplace1ReplaceDialogReplace(TObject *Sender);
    void __fastcall MainTimerTimer(TObject *Sender);
    void __fastcall FindAllDialogFind(TObject *Sender);
    void __fastcall SearchAllModulesExecute(TObject *Sender);
    void __fastcall mShowElTreeClick(TObject *Sender);
    void __fastcall miFloorsClick(TObject *Sender);
    void __fastcall N10Click(TObject *Sender);
    void __fastcall N5Click(TObject *Sender);
    void __fastcall MActualFloorClick(TObject *Sender);
    void __fastcall N11Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ViewNetExecute(TObject *Sender);
    void __fastcall ViewLandExecute(TObject *Sender);
    void __fastcall tbCatalogClick(TObject *Sender);
    void __fastcall AdvTextureExecute(TObject *Sender);
    void __fastcall AdvTextureUpdate(TObject *Sender);
    void __fastcall mSimpleCountClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FileDigitalSaveExecute(TObject *Sender);
	void __fastcall RefreshClick(TObject *Sender);
	void __fastcall SelectBtnClick(TObject *Sender);
private:
public:
	virtual __fastcall TConfig(TComponent *Owner);
    void FillButtonBar(TMetaElement * MEL);
    void RefreshMenu(TMenuItem *MM=NULL);
    UpdateMenu();
    void __fastcall AppMessage(TMsg& AMessage, bool& Handled);
    void __fastcall AppActionUpdate(Classes::TBasicAction* Action, bool &Handled);
    void __fastcall AppActionExecute(Classes::TBasicAction* Action, bool &Handled);
    void __fastcall AppIdle(TObject *Sender, bool &Done);
    bool Process_Save_Project();//возвращает истина если ответ не cancel
    void __fastcall LuaExecute(TObject *Sender);
    TMDelTList<TMsg> Msgs;
};

//----------------------------------------------------------------------------
extern TConfig *Config;
extern TMyMDIChild *__fastcall MDIChildCreate(void);

int Mes(char *Text,char*Caption=NULL);
TMenuItem *FindMIByTag(TMenuItem *MI,int _Tag);
TMenuItem *MIByActionAndMode(int _TagAction,int _TagMode);
TMenuItem *MIByAction(int _TagAction);


#endif
