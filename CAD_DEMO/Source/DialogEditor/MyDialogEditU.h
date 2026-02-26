// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef MyDialogEditUH
#define MyDialogEditUH
#include "compat/vcl_qt.h"

#include "BaseToolV.h"
#include "ObjectInspectorU.hpp"
#include "TreeViewF.h"
#include "MenuF.h"
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
  	virtual void  Modified();
  	virtual void  Notification(TPersistent* AnObject, TOperation Operation);
    virtual TCustomForm*  GetCustomForm();
  	virtual void  SetCustomForm(TCustomForm* Value);
  	virtual bool  GetIsControl();
  	virtual void  SetIsControl(bool Value);
  	virtual bool  IsDesignMsg(Controls::TControl* Sender, Messages::TMessage &Message);
	  virtual void  PaintGrid();
  	virtual void  ValidateRename(Classes::TComponent* AComponent, const AnsiString CurName, const AnsiString NewName);
  	virtual AnsiString  UniqueName(const AnsiString BaseName);
	  virtual Classes::TComponent*  GetRoot();
   // __property bool IsControl {read=GetIsControl, write=SetIsControl}; // [manual migration needed]
   // __property TCustomForm* Form {read=GetCustomForm, write=SetCustomForm}; // [manual migration needed]
};

//---------------------------------------------------------------------------
class  TVCLEditorElement : public TMyRegObject
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
    // __property TWinControl* Control {read=FControl, write=SetControl}; // [manual migration needed]
    // __property TComponent* Component {read=FComponent, write=SetComponent}; // [manual migration needed]
    // __property int VCLChildCount {read=GetVCLChildCount}; // [manual migration needed]
    // __property TVCLEditorElement* VCLParent {read=GetVCLParent, write=SetVCLParent}; // [manual migration needed]
// [indexed property - needs manual migration]:     __property TVCLEditorElement* VCLChild[int] = {read = GetVCLChild};
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
class  TMyDialogEdit : public TForm
{
  __published:
    TActionList *AL;
    TImageList *ImageList;
    void  ALExecute(TBasicAction *Action, bool &Handled);
    void  ApplicationEventsActionUpdate(TBasicAction *Action, bool &Handled);
    void  ActionExecute(TObject *Sender);
    void  FormActivate(TObject *Sender);
    void  FormClose(TObject *Sender, TCloseAction &Action);
    void  FormResize(TObject *Sender);
    void  FormKeyDown(TObject *Sender, WORD &Key,TShiftState Shift);

    private:
    int FGridStep;
    bool FGrid;
    void  MyObjectChanged(TObject *Sender);
    void SetInterface();
    void SetOIRecurs(TVCLEditorElement *_Head, TMyWinControl *_Root);
    TMyDesigner MyDesigner;
    TMyDialog* FMyDialog;

    public:
     TMyDialogEdit(TComponent* Owner, TWinControl *Parent, TMyDialog *MyDialog);
     virtual ~TMyDialogEdit();
    bool ReDraw;
    // __property bool Grid {read=FGrid, write=FGrid}; // [manual migration needed]
    // __property int GridStep {read=FGridStep, write=FGridStep}; // [manual migration needed]
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
    virtual void  WndProc(TMessage &Message);
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
    void  MyOnClick(TObject* Sender);
    void  MyOnContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
    void  MyOnDragDrop(TObject *Sender, TObject *Source, int X, int Y);
    void  MyOnDragOver(TObject *Sender, TObject *Source, int X, int Y, TDragState State, bool &Accept);
    void  MyOnEndDock(TObject *Sender, TObject *Target, int X, int Y);
    void  MyOnEndDrag(TObject *Sender, TObject *Target, int X, int Y);
    void  MyOnEnter(TObject *Sender);
    void  MyOnExit(TObject *Sender);
    void  MyOnKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
    void  MyOnKeyPress(TObject *Sender, char &Key);
    void  MyOnKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
    void  MyOnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void  MyOnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
    void  MyOnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void  MyOnStartDock(TObject *Sender, TDragDockObject *&DragObject);
    void  MyOnStartDrag(TObject *Sender, TDragObject *&DragObject);
};

//---------------------------------------------------------------------------
extern  TMyDialogEdit *MyDialogEdit;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
