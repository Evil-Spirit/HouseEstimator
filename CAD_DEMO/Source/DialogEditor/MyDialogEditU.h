//---------------------------------------------------------------------------
#ifndef MyDialogEditUH
#define MyDialogEditUH
#include <ActnList.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ImgList.hpp>

#include "BaseToolV.h"
#include "ObjectInspectorU.hpp"
#include "TreeViewF.h"
#include "MenuF.h"
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
const long ListValue=255;

class TMyDialog;
class TMyWinControl;
class TEvents;

void DrawGrid(TCanvas* NeedCanvas,TRect Rect,int GridStep);
void FillEvents(TEvents* Events, TComponent* Component, AnsiString Name, AnsiString Value);
TObject* MakeObjectById(int _ClassId, AnsiString &TempName, TComponent* Owner = NULL);
void FillProps(TMyWinControl* _MyObject, TComponent* _Object);

enum TClassId {cnNone = 0, cnButton = 1, cnRadioButton = 2, cnRadioGroup = 3,
cnPanel = 4, cnLabel = 5, cnEdit = 6, cnMemo = 7, cnCheckBox = 8, cnListBox = 9,
cnComboBox = 10, cnScrollBar = 11, cnGroupBox = 12, cnPageControl = 13,
cnMouse = 14, cnForm = 15, cnTabSheet = 16};

//---------------------------------------------------------------------------
class TMyDesigner : public IDesignerHook
{
    private:
    TCustomForm* FCustomForm;

    public:
    TMyDesigner();
    ~TMyDesigner();
    virtual ULONG __stdcall Release();
    virtual ULONG __stdcall AddRef();
    virtual HRESULT __stdcall QueryInterface(const GUID &IID, void **ppv);
  	virtual void __fastcall Modified();
  	virtual void __fastcall Notification(TPersistent* AnObject, TOperation Operation);
    virtual TCustomForm* __fastcall GetCustomForm();
  	virtual void __fastcall SetCustomForm(TCustomForm* Value);
  	virtual bool __fastcall GetIsControl();
  	virtual void __fastcall SetIsControl(bool Value);
  	virtual bool __fastcall IsDesignMsg(Controls::TControl* Sender, Messages::TMessage &Message);
	  virtual void __fastcall PaintGrid();
  	virtual void __fastcall ValidateRename(Classes::TComponent* AComponent, const AnsiString CurName, const AnsiString NewName);
  	virtual AnsiString __fastcall UniqueName(const AnsiString BaseName);
	  virtual Classes::TComponent* __fastcall GetRoot();
   __property bool IsControl = {read = GetIsControl, write = SetIsControl};
   __property TCustomForm* Form = {read = GetCustomForm, write = SetCustomForm};
};

//---------------------------------------------------------------------------
class PACKAGE TVCLEditorElement : public TMyRegObject
{
    private:
    int GetVCLChildCount();
    TVCLEditorElement* GetVCLChild(int i);
    TVCLEditorElement* GetVCLParent();
    void SetVCLParent(TVCLEditorElement* aParent);
    int FClassId;
    TWinControl* FControl;
    TComponent* FComponent;
    void SetControl(TWinControl* aControl);
    void SetComponent(TComponent* aComponent);
    TRect Bounds;

    public:
    TRect Rects[8];
    bool Changed;
    __property TWinControl* Control = {read = FControl, write = SetControl};
    __property TComponent* Component = {read = FComponent, write = SetComponent};
    __property int VCLChildCount = {read = GetVCLChildCount};
    __property TVCLEditorElement* VCLParent = {read = GetVCLParent,write = SetVCLParent};
    __property TVCLEditorElement* VCLChild[int] = {read = GetVCLChild};
    TVCLEditorElement();
    virtual ~TVCLEditorElement();
    TPoint LocalToParent(TWinControl* WinControl, const TPoint& Point);
    TPoint ParentToLocal(TWinControl* WinControl, const TPoint& Point);
    bool CanHaveChild();
    void ReCalculateRects();
    void SelectChildsByRect(const TRect& Rect,TMTList<TVCLEditorElement>& SelectList);
    void AddChild(TVCLEditorElement* Elem);
    void RemoveChild(TVCLEditorElement* Elem);
    void InvalidateFrame(TVCLEditorElement* Parent, TRect Border);
};

//---------------------------------------------------------------------------
class PACKAGE TMyDialogEdit : public TForm
{
  __published:
    TActionList *AL;
    TImageList *ImageList;
    void __fastcall ALExecute(TBasicAction *Action, bool &Handled);
    void __fastcall ApplicationEventsActionUpdate(TBasicAction *Action, bool &Handled);
    void __fastcall ActionExecute(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,TShiftState Shift);

    private:
    int FGridStep;
    bool FGrid;
    void __fastcall MyObjectChanged(TObject *Sender);
    void SetInterface();
    void SetOIRecurs(TVCLEditorElement *_Head, TMyWinControl *_Root);
    TMyDesigner MyDesigner;
    TMyDialog* FMyDialog;

    public:
    __fastcall TMyDialogEdit(TComponent* Owner, TWinControl *Parent, TMyDialog *MyDialog);
    __fastcall virtual ~TMyDialogEdit();
    bool ReDraw;
    __property bool Grid = {read = FGrid, write = FGrid};
    __property int GridStep = {read = FGridStep, write = FGridStep};
    TVCLEditorElement* Head;
    TMTList<TVCLEditorElement> Selected;
    TMTList<TRect> BorderFrame;
    bool Change;
    int RightNameNumber(TVCLEditorElement* VCL,AnsiString _Name, int _Number);
    void FillProps(TMyWinControl* _MyObject, TComponent* _Object);
    void DrawGrid(TCanvas* NeedCanvas,TRect Rect,int GridStep);
    void ToMyDialogEditor(TVCLEditorElement *_Head, TVCLEditorElement *Parent, TMyWinControl *_Root);
    void FromMyDialogEditor(TVCLEditorElement *_Head, TMyWinControl *_Root);
    void DrawFrameRect(int Index, TVCLEditorElement* _Object);
    void DrawSelection(bool EraseOld, bool ReCalculate, bool DrawNew);
    void DrawSelection(int Index, TVCLEditorElement* _Object);
    void InvalidateSelection();
    void ClearSelection();
    virtual void __fastcall WndProc(TMessage &Message);
    void DeleteSelectedItems();
    void DeletePage();
    void AddPage();
    TVCLEditorElement* GetVCLEdEl(TWinControl* WinControl);
    TObject* Sender(int x, int y);
    AnsiString GetName(int _ClassId);
};

//---------------------------------------------------------------------------
class COMMONAL_API TEvents
{
    public:
    TEvents(){};
    ~TEvents(){};
    TForm* Owner;
    void __fastcall MyOnClick(TObject* Sender);
    void __fastcall MyOnContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
    void __fastcall MyOnDragDrop(TObject *Sender, TObject *Source, int X, int Y);
    void __fastcall MyOnDragOver(TObject *Sender, TObject *Source, int X, int Y, TDragState State, bool &Accept);
    void __fastcall MyOnEndDock(TObject *Sender, TObject *Target, int X, int Y);
    void __fastcall MyOnEndDrag(TObject *Sender, TObject *Target, int X, int Y);
    void __fastcall MyOnEnter(TObject *Sender);
    void __fastcall MyOnExit(TObject *Sender);
    void __fastcall MyOnKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall MyOnKeyPress(TObject *Sender, char &Key);
    void __fastcall MyOnKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall MyOnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall MyOnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
    void __fastcall MyOnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall MyOnStartDock(TObject *Sender, TDragDockObject *&DragObject);
    void __fastcall MyOnStartDrag(TObject *Sender, TDragObject *&DragObject);
};

//---------------------------------------------------------------------------
extern PACKAGE TMyDialogEdit *MyDialogEdit;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
