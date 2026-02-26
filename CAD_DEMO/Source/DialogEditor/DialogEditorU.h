// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef DialogEditorUH
#define DialogEditorUH
#include "compat/vcl_qt.h"
#include <BaseToolV.h>

class TPropObject;
#include "ObjectInspectorU.hpp"
#include "ExchangeFormU.h"
//---------------------------------------------------------------------------
const long ListValue=255;

void DrawGrid(TCanvas* NeedCanvas,TRect Rect,int GridStep);
//----------------------------------------------------------------------------
class TMyProp : public TMyObject
{
    public:
    //-------------------------------
    TMyObject* CreateFunction();
    static TClassNode* StaticType;
    //-------------------------------
    AnsiString FName;
    AnsiString FValue;
    TMyProp();
    ~TMyProp();
};

extern TClassNode* TMyProp::StaticType;

//---------------------------------------------------------------------------
class TMyPropObject : public TMyProp
{
    public:
    //-------------------------------
    TMyObject* CreateFunction();
    static TClassNode* StaticType;
    //-------------------------------
    TObject* FObject;
    TMDelTList <TMyProp> Properties;
    TMDelTList <TMyProp> Methods;
    TMDelTList <TMyPropObject> PropObjects;

    TMyPropObject();
    ~TMyPropObject();
};

extern TClassNode* TMyPropObject::StaticType;

//---------------------------------------------------------------------------
class TVCLEditorElement : public TMyRegObject
{
private:
    int GetVCLChildCount();
    TVCLEditorElement* GetVCLChild(int i);
    TVCLEditorElement* GetVCLParent();
    void SetVCLParent(TVCLEditorElement* aParent);
    int FClassId;
    TForm* FForm;
    TWinControl* FWC;
    TMyPropObject* FMyPropObject;
    void SetForm(TForm* aForm);
    void SetWC(TWinControl* aWC);
    void ReCalculateRects();
    TRect Bounds;
public:
    TRect Rects[8];
    bool Changed;
    void DrawSelection();
    // __property TForm* Form {read=FForm, write=SetForm}; // [manual migration needed]
    // __property TWinControl* WC {read=FWC, write=SetWC}; // [manual migration needed]
    // __property int VCLChildCount {read=GetVCLChildCount}; // [manual migration needed]
    // __property TVCLEditorElement* VCLParent {read=GetVCLParent, write=SetVCLParent}; // [manual migration needed]
// [indexed property - needs manual migration]:     __property TVCLEditorElement* VCLChild[int] = {read = GetVCLChild};

    TVCLEditorElement();
    virtual ~TVCLEditorElement();
    TPoint LocalToParent(TWinControl* WinControl, const TPoint& Point);
    TPoint ParentToLocal(TWinControl* WinControl, const TPoint& Point);
    bool CanHaveChild();
    void SelectChildsByRect(const TRect& Rect,TMTList<TVCLEditorElement>& SelectList);
    void AddChild(TVCLEditorElement* Elem);
    void RemoveChild(TVCLEditorElement* Elem);
    void GetName(int _ClassId);
    void LoadPropObject(TComponent* Owner);
    void FillPropObject(TPropObject &_Object, TMyPropObject &_MyObject);
    int ChildIsIn(AnsiString _Name, TMyPropObject *List);
    void SavePropObject(TPropObject _Object);
    void FillMyPropObject(TPropObject &_Object, TMyPropObject &_MyObject);
};

//---------------------------------------------------------------------------
class TDialogEditorF : public TForm
{
__published:	// IDE-managed Components
    TActionList *AL;
    TImageList *ImageList;
    void  ALExecute(TBasicAction *Action, bool &Handled);
    void  ApplicationEventsActionUpdate(TBasicAction *Action,
          bool &Handled);
    void  AllKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  AllKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  AllMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  AllMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void  AllMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  MaskPaint(TObject *Sender);
    void  FormDestroy(TObject *Sender);
    void  FormPaint(TObject *Sender);
    void  Action1Execute(TObject *Sender);
    void  FormActivate(TObject *Sender);

private:
    int FGridStep;
    bool FGrid;
    void  MyObjectChanged(TObject *Sender);
public:
    TMyControls DialogTools;
    TVCLEditorElement Head;
    TMTList<TVCLEditorElement> Selected;
    TMTList<TRect> BorderFrame;
    bool Change;
     TDialogEditorF(TComponent* Owner);
    // __property bool Grid {read=FGrid, write=FGrid}; // [manual migration needed]
    // __property int GridStep {read=FGridStep, write=FGridStep}; // [manual migration needed]
    void DrawGrid();
    void DrawSelection(void* Sender);
    TVCLEditorElement* GetVCLEdEl(TWinControl* WC);
    TObject* Sender(int x, int y);
    void InvalidateSelection();
    void ClearSelection();
    TObjectInspectorF *ObjInspector;
};
//---------------------------------------------------------------------------
extern  TDialogEditorF *DialogEditorF;
//---------------------------------------------------------------------------
#endif
