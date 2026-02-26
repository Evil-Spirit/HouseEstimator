// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//----------------------------------------------------------------------------
#ifndef MainH
#define MainH
//----------------------------------------------------------------------------

#include "VisTimer.hpp"
#include "compat/vcl_qt.h"
#include "BaseDockSiteFormV.h"
#include "FloatingV.h"
#include "compat/SUISkinEngine.hpp"


class TMetaElement;
class TMyMDIChild;
//äîëæåí áûòü îäèí è òîëüêî îäèí îïðåäåëåí
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
        void  FileNew1Execute(TObject *Sender);
        void  HelpAbout1Execute(TObject *Sender);
        void  FileExit1Execute(TObject *Sender);
    void  ScrollerMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ScrollerMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  FormCreate(TObject *Sender);
    void  FormDestroy(TObject *Sender);
    void  ConfiguratorExecute(TObject *Sender);
    void  ToolButton15Click(TObject *Sender);
    void  ToolButton16Click(TObject *Sender);
    void  mfNewClick(TObject *Sender);
    void  FileSaveAs1Execute(TObject *Sender);
    void  FileOpen1Execute(TObject *Sender);
    void  btCheckClick(TObject *Sender);
    void  mCountClick(TObject *Sender);
    void  mWorkCountClick(TObject *Sender);
    void  PrintDlg1Accept(TObject *Sender);
    void  PrintDlg1BeforeExecute(TObject *Sender);
  void  ToolButton12MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
  void  cbFloorsCloseUp(TObject *Sender);
  void  miModeClick(TObject *Sender);
    void  SearchFind1FindDialogFind(TObject *Sender);
    void  SearchReplace1ReplaceDialogReplace(TObject *Sender);
    void  MainTimerTimer(TObject *Sender);
    void  FindAllDialogFind(TObject *Sender);
    void  SearchAllModulesExecute(TObject *Sender);
    void  mShowElTreeClick(TObject *Sender);
    void  miFloorsClick(TObject *Sender);
    void  N10Click(TObject *Sender);
    void  N5Click(TObject *Sender);
    void  MActualFloorClick(TObject *Sender);
    void  N11Click(TObject *Sender);
    void  FormClose(TObject *Sender, TCloseAction &Action);
    void  ViewNetExecute(TObject *Sender);
    void  ViewLandExecute(TObject *Sender);
    void  tbCatalogClick(TObject *Sender);
    void  AdvTextureExecute(TObject *Sender);
    void  AdvTextureUpdate(TObject *Sender);
    void  mSimpleCountClick(TObject *Sender);
    void  FormShow(TObject *Sender);
    void  FileDigitalSaveExecute(TObject *Sender);
	void  RefreshClick(TObject *Sender);
	void  SelectBtnClick(TObject *Sender);
private:
public:
	virtual  TConfig(TComponent *Owner);
    void FillButtonBar(TMetaElement * MEL);
    void RefreshMenu(TMenuItem *MM=NULL);
    UpdateMenu();
    void  AppMessage(TMsg& AMessage, bool& Handled);
    void  AppActionUpdate(Classes::TBasicAction* Action, bool &Handled);
    void  AppActionExecute(Classes::TBasicAction* Action, bool &Handled);
    void  AppIdle(TObject *Sender, bool &Done);
    bool Process_Save_Project();//âîçâðàùàåò èñòèíà åñëè îòâåò íå cancel
    void  LuaExecute(TObject *Sender);
    TMDelTList<TMsg> Msgs;
};

//----------------------------------------------------------------------------
extern TConfig *Config;
extern TMyMDIChild * MDIChildCreate(void);

int Mes(char *Text,char*Caption=NULL);
TMenuItem *FindMIByTag(TMenuItem *MI,int _Tag);
TMenuItem *MIByActionAndMode(int _TagAction,int _TagMode);
TMenuItem *MIByAction(int _TagAction);


#endif
