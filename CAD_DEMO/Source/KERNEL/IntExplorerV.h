//---------------------------------------------------------------------------

#ifndef IntExplorerVH
#define IntExplorerVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <typeinfo.h>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>

#include "FloatingV.h"

class TMetaCatalogUnit;
class TMetaNode;
//---------------------------------------------------------------------------
//objectstatus;
const int osValidFolder=0;
const int osFolder=1;
const int osObject=2;


const TColor ExplorerBackColor = (TColor)RGB(120,162,199);//(173,189,201);
const TColor ExplorerFaceColor = (TColor)RGB(236,233,216);//clBtnFace;
const int ExplorerImageSizeX = 48;
const int ExplorerImageSizeY = 48;
const int PanelImageSizeX = 24;
const int PanelImageSizeY = 24;

int GetToolBarWidth()
{
	return PanelImageSizeX+7;
}

int GetToolBarHeight()
{
	return PanelImageSizeX+6;
}

const int IDMouseAction = -1;
const int OneSize = 100;
const int TwoSize = 200;


class COMMONAL_API TLVParam{
public:
    TLVParam(TMetaNode* FirstParent,const AnsiString& _Caption,int _ImageIndex);
    TLVParam();
    virtual ~TLVParam();
    AnsiString Caption;
    int ImageIndex;
    TImageList* BIG;
    TImageList* SML;
    TMetaNode* CurParent;
    TMetaNode* MaxParent;
    int ObjectStatus(TMetaNode* Object);
    TRect BIG_Where;
    TRect SML_Where;
};

const int esOneSize = 1;
const int esTwoSize = 2;
const int StateCount = 3;



const int SELECTION_CHANGED = 0;

class TMetaTool;
class TIntExplorer;
class COMMONAL_API TExplorerState : public TMyControlState {
public:
    TExplorerState(){};
    virtual ~TExplorerState(){};
    void ApplyToExplorer(TIntExplorer* Explorer);
    TMyControlState BackPanel;
    TMyControlState MainToolBar;
    TMyControlState MinPanel;
    TMyControlState ParentUp;
    TMyControlState UgolPanel;
    TMyControlState ToolPanel;
    TMyControlState ToolButtons;
};

class TMetaTool;
class TToolControlList;
class TBaseTool;
class COMMONAL_API TIntExplorer : public TFloatForm
{
__published:	// IDE-managed Components
    TImageList *IL;
    TImageList *il_folders;
    TPanel *UgolPanel;
    TImageList *MainIL;
    TPanel *BackPanel;
    TToolBar *MainToolBar;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TSpeedButton *ParentUp;
    TSaveDialog *SaveDialog1;
    TPanel *ClientPanel;
    TListView *LV;
    TPanel *ToolPanel;
    TToolBar *ToolButtons;
    TPanel *ToolForms;
    TImageList *IL_TOOLS;
  TImageList *ImageList1;
  TToolBar *MinPanel;
  TToolButton *btnMinimize;
    void __fastcall tbObjectsClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall tbUpClick(TObject *Sender);
    void __fastcall LVMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
    void __fastcall LVMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall MinimizeClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ToolClick(TObject *Sender);
private:	// User declarations
    TMDelTList<TLVParam> LVS;
    void UpdateView(bool CanStart);
    void RefreshAlign();
    TToolButton* CreateToolButton(TToolBar* TB,int index);
    void Start();
    TExplorerState ExpStates[3];
    void SetExplorerStates();
    //-----------------------------------
    TMetaCatalogUnit* FMetaCatalogUnit;
    void SetMetaCatalogUnit(TMetaCatalogUnit* Value);
    void ProcessActivateTools();
    TToolButton* CreateRealToolButton(TToolBar* ToolButtons,int index,TMetaTool* BaseTool,int ImageIndex);
    void UpdateToolImages(TMTList<TMetaTool>& Tools);
public:
    void SwitchTool(int NewToolIndex);
    void ActivateTools();
    TToolControlList& ControlList;
//    TMyControls FTools;
    virtual void OnMyResize();
    __fastcall TIntExplorer(TComponent* Owner);
    __property TMetaCatalogUnit *MetaCatalogUnit = {read = FMetaCatalogUnit,write = SetMetaCatalogUnit};
    void AUIChanged();
    //------------------------------------------------------------
    void _fastcall WndProc(Messages::TMessage &Message);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TIntExplorer *IntExplorer;
//---------------------------------------------------------------------------
#endif
