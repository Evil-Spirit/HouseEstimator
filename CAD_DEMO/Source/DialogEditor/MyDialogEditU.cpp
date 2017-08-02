//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include <vcl.h>
#pragma hdrstop

#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#include "MyDialogEditU.h"
#include "ToolBarU.h"
#include "DialogEditorToolsU.h"
#include "MyDialogU.h"

TMyDialogEdit *MyDialogEdit = NULL;
//---------------------------------------------------------------------------
void MyDialogEditStartup()
{
    ToolBarF = new TToolBarForm (Application);
    MenuF = new TMainMenuF (Application);
    ObjInspector = new TObjectInspectorF (Application);
}

//---------------------------------------------------------------------------
void MyDialogEditExit()
{
    delete ToolBarF;
    ToolBarF = NULL;
    delete MenuF;
    MenuF = NULL;
    delete ObjInspector;
    ObjInspector = NULL;
}

//---------------------------------------------------------------------------
#pragma startup MyDialogEditStartup
#pragma exit MyDialogEditExit
//---------------------------------------------------------------------------
TShiftState KeysToShiftState(int Keys)
{
    TShiftState Shift;
    Shift.Clear();
    if ( (Keys & MK_CONTROL) == MK_CONTROL)
        Shift<<ssCtrl;
    if ( (Keys & MK_SHIFT) == MK_SHIFT)
        Shift<<ssShift;
    if ( (Keys & MK_LBUTTON) == MK_LBUTTON)
        Shift<<ssLeft;
    if ( (Keys & MK_MBUTTON) == MK_MBUTTON )
        Shift<<ssMiddle;
    if ( (Keys & MK_RBUTTON) == MK_RBUTTON )
        Shift<<ssRight;
    return Shift;
}

//---------------------------------------------------------------------------
TShiftState MyKeyDataToShiftState(int KeyData)
{
    const AltMask = 0x20000000;
    TShiftState Shift;
    Shift.Clear();
    if (GetKeyState(VK_SHIFT) < 0 )
        Shift<<ssShift;
    if (GetKeyState(VK_CONTROL) < 0)
        Shift<<ssCtrl;
    if ((KeyData & AltMask) != 0)
        Shift<<ssAlt;
    return Shift;
}

//---------------------------------------------------------------------------
TObject* MakeObjectById(int _ClassId, AnsiString &TempName, TComponent* Owner)
{
    TObject *TempObject;
    switch( _ClassId )
    {
        case cnButton      : TempObject = new TButton(Owner); TempName = "Button"; break;
        case cnRadioButton : TempObject = new TRadioButton(Owner); TempName = "RadioButton"; break;
        case cnRadioGroup  : TempObject = new TRadioGroup(Owner); TempName = "RadioGroup"; break;
        case cnPanel       : TempObject = new TPanel(Owner); TempName = "Panel"; break;
        case cnLabel       : TempObject = new TStaticText(Owner); TempName = "Label"; break;
        case cnEdit        : TempObject = new TEdit(Owner); TempName = "Edit"; break;
        case cnMemo        : TempObject = new TMemo(Owner); TempName = "Memo"; break;
        case cnCheckBox    : TempObject = new TCheckBox(Owner); TempName = "CheckBox"; break;
        case cnListBox     : TempObject = new TListBox(Owner); TempName = "ListBox"; break;
        case cnComboBox    : TempObject = new TComboBox(Owner); TempName = "ComboBox"; break;
        case cnGroupBox    : TempObject = new TGroupBox(Owner); TempName = "GroupBox"; break;
        case cnScrollBar   : TempObject = new TScrollBar(Owner); TempName = "ScrollBar"; break;
        case cnForm        : TempObject = new TForm(Owner); TempName = "Form"; break;
        case cnPageControl : TempObject = new TPageControl(Owner); TempName = "PageControl"; break;
        case cnTabSheet    : TempObject = new TTabSheet(Owner); TempName = "TabSheet"; break;
        default: TempObject = NULL; TempName = '\0';
    }
    return TempObject;
}

//---------------------------------------------------------------------------
//TMyDesigner:
//---------------------------------------------------------------------------
TMyDesigner::TMyDesigner()
{
}

//---------------------------------------------------------------------------
TMyDesigner::~TMyDesigner()
{
    Form = NULL;
}

//---------------------------------------------------------------------------
ULONG __stdcall TMyDesigner::Release()
{
    return 0;
}

//---------------------------------------------------------------------------
ULONG __stdcall TMyDesigner::AddRef()
{
    return 0;
}

//---------------------------------------------------------------------------
HRESULT __stdcall TMyDesigner::QueryInterface(const GUID &IID, void **ppv)
{
    return 0;
}

//---------------------------------------------------------------------------
void __fastcall TMyDesigner::Modified()
{
}

//---------------------------------------------------------------------------
void __fastcall TMyDesigner::Notification(TPersistent* AnObject, TOperation Operation)
{
}

//---------------------------------------------------------------------------
TCustomForm* __fastcall TMyDesigner::GetCustomForm()
{
    return FCustomForm;
}

//---------------------------------------------------------------------------
void __fastcall TMyDesigner::SetCustomForm(TCustomForm* Value)
{
    FCustomForm = Value;
}

//---------------------------------------------------------------------------
bool __fastcall TMyDesigner::GetIsControl(void)
{
    return true;
}


//---------------------------------------------------------------------------
void __fastcall TMyDesigner::SetIsControl(bool Value)
{
}

//---------------------------------------------------------------------------
void TMyDialogEdit::AddPage()
{
    if ( ( Selected.Count == 1 ) && ( IS ( Selected.Items[0]->Control, __classid ( TPageControl ) ) ) )
    {
          TTabSheet* NewSheet = (TTabSheet*)CreateComponent(Selected.Items[0]->Control, cnTabSheet);
          NewSheet->Name = GetName(cnTabSheet);
          NewSheet->Parent = Selected.Items[0]->Control;
          NewSheet->ComponentState<<csDesigning;
          ((TPageControl*)Selected.Items[0]->Control)->ActivePage = NewSheet;
          NewSheet->Show();
          NewSheet->TabVisible = true;
          NewSheet->PageControl =   ((TPageControl*)Selected.Items[0]->Control);
          TVCLEditorElement* VCL = GetVCLEdEl(Selected.Items[0]->Control);
          TVCLEditorElement* NewVCL = new TVCLEditorElement();
          NewVCL->Component = NewSheet;
          NewVCL->Control = NewSheet;
          VCL->AddChild(NewVCL);
          ObjInspector->AddObject(NewSheet, NewSheet->Name);
//          TreeView->Tree = Head;
    }
}

//---------------------------------------------------------------------------
void TMyDialogEdit::DeletePage()
{
    if ( ( Selected.Count == 1 ) && ( IS ( Selected.Items[0]->Control, __classid ( TPageControl ) ) ) )
        if (((TPageControl*)Selected.Items[0]->Control)->ActivePage)
        {
            TVCLEditorElement* VCL = GetVCLEdEl(((TPageControl*)Selected.Items[0]->Control)->ActivePage);
            ObjInspector->DeleteObject(VCL->Control);
            delete VCL->Control;
            delete VCL;
//            TreeView->Tree = Head;
        }
    if ( ( Selected.Count == 1 ) && ( IS ( Selected.Items[0]->Control, __classid ( TTabSheet ) ) ) )
        if (((TTabSheet*)Selected.Items[0]->Control))
        {
            ObjInspector->DeleteObject(((TTabSheet*)Selected.Items[0]->Control));
            TVCLEditorElement* VCL = GetVCLEdEl(((TTabSheet*)Selected.Items[0]->Control));
            delete ((TTabSheet*)Selected.Items[0]->Control);
            delete VCL;
//            TreeView->Tree = Head;
        }
    Invalidate();
}

//---------------------------------------------------------------------------
void TMyDialogEdit::DeleteSelectedItems()
{
    DrawSelection(true,true,false);
    TRect *BorderRect[255];
    for(int i = 0; i < Selected.Count; i++)
    {
        BorderRect[i] = new TRect(0,0,0,0);
        if ( i == Selected.Count - 1 )
            ObjInspector->DeleteObject(Selected.Items[i]->Component);
        else
            ObjInspector->DeleteObject(Selected.Items[i]->Component, false);
        if ( (Selected.Items[i]->Control->Parent) && (Selected.Items[i]->Control->Parent != this) )
           Selected.Items[i]->Control->Parent->Invalidate();
        if (Selected.Items[i]->Component)
        {
            if ( !IS (Selected.Items[i]->Component, __classid(TWinControl)))
            {
                Selected[i].VCLParent->Control->Invalidate();
                delete Selected.Items[i]->Control;
            }
            delete Selected.Items[i]->Component;
        }
        delete Selected.Items[i];
    }
    Selected.Clear();
//    TreeView->Tree = Head;
    Invalidate();
}

//---------------------------------------------------------------------------
void __fastcall TMyDialogEdit::WndProc(TMessage &Message)
{
    switch ( Message.Msg )
    {
        case CN_KEYDOWN :
          if (((TWMKey&)Message).CharCode == VK_DELETE)
          {
              DeleteSelectedItems();
              break;
          }
          if (((TWMKey&)Message).CharCode == VK_ADD)
          {
              AddPage();
              break;
          }
          if (((TWMKey&)Message).CharCode == VK_SUBTRACT)
          {
              DeletePage();
              break;
          }
    }
    TForm::WndProc(Message);
}

//---------------------------------------------------------------------------
bool __fastcall TMyDesigner::IsDesignMsg(Controls::TControl* Sender, Messages::TMessage &Message)
{
//Posylat' soobshenie iz OI (Use FindActiveEditor):
    if ( ObjInspector->RefreshSelectionBorder )
    {
        ((TMyDialogEdit*)Form)->DrawSelection(true,false,false);
        ((TMyDialogEdit*)Form)->Selected.Clear();
//        for (int i = 0; i < ObjInspector->SelectedObjects.Length; i++ )
//zamenit' 0 na i:
          if ( (((TWinControl*)ObjInspector->SelectedObjects[0]->ThisObject)) != ((TMyDialogEdit*)Form) )
              ((TMyDialogEdit*)Form)->Selected.Add(((TMyDialogEdit*)Form)->GetVCLEdEl(((TWinControl*)ObjInspector->SelectedObjects[0]->ThisObject)));
        ((TMyDialogEdit*)Form)->DrawSelection(false,true,true);
        ObjInspector->RefreshSelectionBorder = false;
    }

    //MEDLENNO

    switch (Message.Msg)
    {
        case WM_KEYDOWN     :   ToolBarF->DialogTools.KeyDown(Sender, ((TWMKey&)Message).CharCode, MyKeyDataToShiftState(((TWMKey&)Message).KeyData));
                                break;
        case WM_KEYUP       :   ToolBarF->DialogTools.KeyUp(Sender, ((TWMKey&)Message).CharCode, MyKeyDataToShiftState(((TWMKey&)Message).KeyData));
                                break;
        case WM_MOUSEMOVE   :   ToolBarF->DialogTools.MouseMove(Sender, KeysToShiftState(((TWMMouse&)Message).Keys), TIntVec(((TWMMouse&)Message).XPos, ((TWMMouse&)Message).YPos, 0));
                                break;
        case WM_LBUTTONUP   :   ToolBarF->DialogTools.MouseUp(Sender, mbLeft, KeysToShiftState(((TWMMouse&)Message).Keys), TIntVec(((TWMMouse&)Message).XPos, ((TWMMouse&)Message).YPos, 0));
                                break;
        case WM_LBUTTONDOWN :   ToolBarF->DialogTools.MouseDown(Sender, mbLeft, KeysToShiftState(((TWMMouse&)Message).Keys), TIntVec(((TWMMouse&)Message).XPos, ((TWMMouse&)Message).YPos, 0));
                                break;
    }
    return Message.Msg == WM_LBUTTONDOWN || Message.Msg == WM_MOUSEMOVE || Message.Msg == WM_LBUTTONDBLCLK || Message.Msg == WM_LBUTTONUP || Message.Msg == WM_RBUTTONDOWN || Message.Msg == WM_RBUTTONDBLCLK || Message.Msg == WM_RBUTTONUP || Message.Msg == WM_KEYDOWN || Message.Msg == WM_KEYUP;
}


//---------------------------------------------------------------------------
void __fastcall TMyDesigner::PaintGrid()
{
    TColor MyColor = ~(Form->Color);
    for(int i = 0; i < ((TMyDialogEdit*)Form)->Width; i += ((TMyDialogEdit*)Form)->GridStep)
        for(int j = 0; j < ((TMyDialogEdit*)Form)->Height; j += ((TMyDialogEdit*)Form)->GridStep)
            Form->Canvas->Pixels[i][j] = MyColor;
    ToolBarF->DialogTools.Render(this);
    ((TMyDialogEdit*)Form)->DrawSelection(false,false,true);
}

//---------------------------------------------------------------------------
void __fastcall TMyDesigner::ValidateRename(Classes::TComponent* AComponent, const AnsiString CurName, const AnsiString NewName)
{
}

//---------------------------------------------------------------------------
AnsiString __fastcall TMyDesigner::UniqueName(const AnsiString BaseName)
{
    return "";
}

//---------------------------------------------------------------------------
Classes::TComponent* __fastcall TMyDesigner::GetRoot()
{
    return NULL;
}

//---------------------------------------------------------------------------
//TVCLEditorElement:
//---------------------------------------------------------------------------
TVCLEditorElement::TVCLEditorElement()
{
    Changed = true;
}

//---------------------------------------------------------------------------
void TVCLEditorElement::AddChild(TVCLEditorElement* Elem)
{
    Elem->VCLParent = this;
}

//---------------------------------------------------------------------------
void TVCLEditorElement::RemoveChild(TVCLEditorElement* Elem)
{
    Elem->VCLParent = NULL;
}

//---------------------------------------------------------------------------
TVCLEditorElement::~TVCLEditorElement()
{
}

//---------------------------------------------------------------------------
void TVCLEditorElement::SetControl(TWinControl* aControl)
{
    FControl = aControl;
    if (FControl)
        FControl->Tag = (int)this;
}

//---------------------------------------------------------------------------
void TVCLEditorElement::SetComponent(TComponent* aComponent)
{
    FComponent = aComponent;
    if (FComponent)
        FComponent->Tag = (int)this;
}

//---------------------------------------------------------------------------
TVCLEditorElement* TMyDialogEdit::GetVCLEdEl(TWinControl* WinControl)
{
 return ( (TVCLEditorElement*)(WinControl->Tag) );
}

//---------------------------------------------------------------------------
int TVCLEditorElement::GetVCLChildCount()
{
    return ChildList->Count;
}

//---------------------------------------------------------------------------
TVCLEditorElement* TVCLEditorElement::GetVCLChild(int i)
{
    return  ((TVCLEditorElement*)ChildList->Items[i]);
}

//---------------------------------------------------------------------------
TVCLEditorElement* TVCLEditorElement::GetVCLParent()
{
    return ( (TVCLEditorElement*)Parent );
}

//---------------------------------------------------------------------------
void TVCLEditorElement::SetVCLParent(TVCLEditorElement* aParent)
{
    Parent = aParent;
}

//---------------------------------------------------------------------------
Types::TPoint TVCLEditorElement::LocalToParent(TWinControl* WinControl, const Types::TPoint &Point)
{
    return WinControl->ScreenToClient( Control->ClientToScreen(Point) );
}

//---------------------------------------------------------------------------
Types::TPoint TVCLEditorElement::ParentToLocal(TWinControl* WinControl, const Types::TPoint &Point)
{
    return Control->ScreenToClient( WinControl->ClientToScreen(Point) );
}

//---------------------------------------------------------------------------
bool TVCLEditorElement::CanHaveChild()
{
    return  IS (Component, __classid(TForm)  ) ||
            IS (Component, __classid(TPanel)  ) ||
            IS (Component, __classid(TTabSheet)  ) ||
            IS (Component, __classid(TGroupBox)  );
}

//---------------------------------------------------------------------------
void TVCLEditorElement::SelectChildsByRect(const Types::TRect& SelectRect,TMTList<TVCLEditorElement>& SelectList)
{
    SelectList.Clear();
    Types::TRect TempRect;
    for (int i=0;i<VCLChildCount;i++)
    {
        Types::TRect BRect = (((TVCLEditorElement*)ChildList->Items[i])->Control->BoundsRect);
        if ( Types::IntersectRect(TempRect,SelectRect,BRect) == true )
            SelectList.Add( (VCLChild[i]) );
    }
}

//---------------------------------------------------------------------------
void TVCLEditorElement::InvalidateFrame(TVCLEditorElement* Parent, TRect Border)
{
    int i;
    TRect Intersection;
    TRect MyRect = Rect(0,0,1,1);
    if (IntersectRect(Intersection, MyRect, Border))
        Control->Invalidate();
    for (i = 0; i < GetVCLChildCount(); i++)
        VCLChild[i]->InvalidateFrame(Parent, Border);
}

//---------------------------------------------------------------------------
void TVCLEditorElement::ReCalculateRects()
{
        enum {LeftBottom=7,LeftMiddle=0,LeftTop=1,MiddleTop=2,
              RightTop=3,RightMiddle=4,RightBottom=5,MiddleBottom=6};
        int w = Control->Width;
        int h = Control->Height;
        Rects[LeftTop] = Types::TRect(0,0,0,0);
        Rects[LeftBottom] = Types::TRect(0,h,0,h);
        Rects[RightTop] = Types::TRect(w,0,w,0);
        Rects[RightBottom] = Types::TRect(w,h,w,h);
        Rects[LeftMiddle] = Types::TRect(0,h/2,0,h/2);
        Rects[MiddleTop] = Types::TRect(w/2,0,w/2,0);
        Rects[RightMiddle] = Types::TRect(w,h/2,w,h/2);
        Rects[MiddleBottom] = Types::TRect(w/2,h,w/2,h);
        for(int j = 0; j < 8; j++)
            Rects[j] = Rect(Rects[j].left+Control->Left-2, Rects[j].top+Control->Top-2, Rects[j].right+Control->Left+2, Rects[j].bottom+Control->Top+2);
        Changed = false;
}

//---------------------------------------------------------------------------
//TMyDialogEdit:
//---------------------------------------------------------------------------
int TMyDialogEdit::RightNameNumber(TVCLEditorElement* VCL,AnsiString _Name, int _Number)
{
    for(int i = 0; i<VCL->VCLChildCount; i++)
        _Number = RightNameNumber(VCL->VCLChild[i], _Name, _Number);
    if(VCL->Component->Name == _Name + (AnsiString)_Number)
    {
        VCL = Head;
        _Number = RightNameNumber(VCL, _Name, _Number + 1);
    }
    return _Number;
}

//---------------------------------------------------------------------------
AnsiString TMyDialogEdit::GetName(int _ClassId)
{
    AnsiString ComponentName;
    int ComponentNumber;
    MakeObjectById(_ClassId, ComponentName);
    ComponentNumber = RightNameNumber(Head, ComponentName,1);
    return (ComponentName + (AnsiString)ComponentNumber);
}

//---------------------------------------------------------------------------
void __fastcall TMyDialogEdit::MyObjectChanged(TObject *Sender)
{
    TControl* Control = (TControl*)Sender;
        Control->Invalidate();
}

//---------------------------------------------------------------------------
__fastcall TMyDialogEdit::TMyDialogEdit(TComponent* Owner, TWinControl *_Parent, TMyDialog *MyDialog) : TForm(Owner)
{
    int OldTag;
    KeyPreview = true;
    ReDraw = true;
    Parent = _Parent;
    GridStep = 8;
    Head = new TVCLEditorElement;
    Head->Control = this;
    Head->Component = this;
    OldTag = Head->Component->Tag;
    FMyDialog = MyDialog;
    Grid = true;
    Change = false;
    Selected.Clear();
//    TreeView->DialogEdit = this;
//    TreeView->Tree = Head;
//    SDELAT' ANALOGICHNO OI - PRI ACTIVATE;
    //-------------------------------
    Show();
    ComponentState<<csDesigning;
    ComponentState<<csDesignInstance;
    MyDesigner.Form = this;
    Designer = &MyDesigner;
    ToMyDialogEditor(Head, NULL, &FMyDialog->Root);
//    SetInterface();
//    Name = MyDialog->Name;
//VOZVRASHAET STAROE IMYA - IMENIT' OI???
    Head->Component->Tag = OldTag;
}
//---------------------------------------------------------------------------
__fastcall TMyDialogEdit::~TMyDialogEdit()
{
    FMyDialog->Name = Name;
    delete Head;
    FMyDialog = NULL;
    Head = NULL;
}

//---------------------------------------------------------------------------
void __fastcall TMyDialogEdit::FormClose(TObject *Sender, TCloseAction &Action)
{
    FromMyDialogEditor(Head, &FMyDialog->Root);
    ComponentState>>csDesigning;
    ComponentState>>csDesignInstance;
    MyDesigner.Form = NULL;
    Designer = NULL;
    ObjInspector->ClearOI();
    ToolBarF->Dialog = NULL;
    ToolBarF->Hide();
    Action = caFree;
}
//---------------------------------------------------------------------------
void TMyDialogEdit::DrawSelection(int Index, TVCLEditorElement* _Object)
{
    int i;
    Canvas->Pen->Mode = pmXor;
    Canvas->Pen->Color = clBlack;
    TPoint *Points = new TPoint[4];
    if (_Object->VCLParent->Control == this)
    {
        for(i = 0; i < 8; i++)
        {
            Points[0] = Point(Selected[Index].Rects[i].Left, Selected[Index].Rects[i].Bottom);
            Points[1] = Point(Selected[Index].Rects[i].Left, Selected[Index].Rects[i].Top);
            Points[2] = Point(Selected[Index].Rects[i].Right, Selected[Index].Rects[i].Top);
            Points[3] = Point(Selected[Index].Rects[i].Right, Selected[Index].Rects[i].Bottom);
            Canvas->Polygon( Points, 3 );
        }
    }
    else
    {
        for(i = 0; i < 8; i++)
        {
            Points[0] = Point(_Object->VCLParent->Control->Left + Selected[Index].Rects[i].Left, _Object->VCLParent->Control->Top + Selected[Index].Rects[i].Bottom);
            Points[1] = Point(_Object->VCLParent->Control->Left + Selected[Index].Rects[i].Left, _Object->VCLParent->Control->Top + Selected[Index].Rects[i].Top);
            Points[2] = Point(_Object->VCLParent->Control->Left + Selected[Index].Rects[i].Right, _Object->VCLParent->Control->Top + Selected[Index].Rects[i].Top);
            Points[3] = Point(_Object->VCLParent->Control->Left + Selected[Index].Rects[i].Right, _Object->VCLParent->Control->Top + Selected[Index].Rects[i].Bottom);
            Canvas->Polygon( Points, 3 );
        }
    }
    Canvas->Pen->Mode = pmCopy;
    delete Points;
}

//---------------------------------------------------------------------------
void TMyDialogEdit::DrawSelection(bool EraseOld, bool ReCalculate, bool DrawNew)
{
    int i;
    TPenMode Mode = Canvas->Pen->Mode;
    for(i = 0; i < Selected.Count; i++)
    {
        if (EraseOld)
            DrawSelection(i ,Selected.Items[i]);
        if (ReCalculate)
            Selected[i].ReCalculateRects();
        if (DrawNew)
            DrawSelection(i ,Selected.Items[i]);
    }
    Canvas->Pen->Mode = Mode;
}

//---------------------------------------------------------------------------
void __fastcall TMyDialogEdit::ALExecute(TBasicAction *Action, bool &Handled)
{
    ToolBarF->DialogTools.Exit(this);
    ToolBarF->DialogTools.ActiveList = Action->Tag;
}

//---------------------------------------------------------------------------
void __fastcall TMyDialogEdit::ApplicationEventsActionUpdate(TBasicAction *_Action, bool &Handled)
{
    TAction* Action = (TAction*)_Action;
    int ind = Action->Tag;
    Action->Checked = (ind == ToolBarF->DialogTools.ActiveList);
    Action->ImageIndex = ToolBarF->DialogTools.Matrix[ind][ToolBarF->DialogTools.ActiveIndices[ind]].ImageId;
    Action->Caption = ToolBarF->DialogTools.Matrix[ind][ToolBarF->DialogTools.ActiveIndices[ind]].Description;
    Action->Hint = ToolBarF->DialogTools.Matrix[ind][ToolBarF->DialogTools.ActiveIndices[ind]].Description;
    Action->Enabled = true;
    Handled = true;
}

//---------------------------------------------------------------------------
void TMyDialogEdit::ClearSelection()
{
    for (int i=0;i<Selected.Count;i++)
        Selected[i].VCLParent->Control->Invalidate();
    Selected.Clear();
}

//---------------------------------------------------------------------------
void __fastcall TMyDialogEdit::ActionExecute(TObject *Sender)
{
    //
}

//---------------------------------------------------------------------------
void __fastcall TMyDialogEdit::FormActivate(TObject *Sender)
{
    if (::GetFocus() != Handle)
        ::SetFocus(Handle);
    SetInterface();
}

//---------------------------------------------------------------------------
void TMyDialogEdit::SetInterface()
{
    ToolBarF->Dialog = this;
    ToolBarF->SetToolBar();
    ObjInspector->Hide();
    ObjInspector->ClearOI();
    ObjInspector->ObjectChanged = MyObjectChanged;
    SetOIRecurs(Head, &FMyDialog->Root);
    ObjInspector->Show();
}

//---------------------------------------------------------------------------
void TMyDialogEdit::SetOIRecurs(TVCLEditorElement *_Head, TMyWinControl *_Root)
{
    int i;
    ObjInspector->AddObject(_Head->Control, _Head->Control->Name);
    for (i = 0; i < _Root->Methods.Count; i++)
        ObjInspector->Items[ObjInspector->Items.Length - 1]->MethodList[PropIsIn(_Root->Methods[i].FName, &(ObjInspector->Items[ObjInspector->Items.Length - 1]->MethodList[0]), ObjInspector->Items[ObjInspector->Items.Length - 1]->MethodList.Length)]->PropertyValue = _Root->Methods[i].FValue;
    for (i = 0; i < _Head->VCLChildCount; i++)
        SetOIRecurs(_Head->VCLChild[i], &_Root->MyControls[i]);
}

//---------------------------------------------------------------------------
void TMyDialogEdit::FillProps(TMyWinControl* _MyObject, TComponent* _Object)
{
    int i;
    for (i = 0; i < _MyObject->Properties.Count; i++)
    {
        if ( ! _MyObject->Properties[i].FValue.IsEmpty() )
        {
            if  ( ! ( ( _Object == this ) && ( _MyObject->Properties[i].FName == "Name" ) ) )
            {
                if ( ! ((TWinControl*)_Object)->Parent )
                    ((TWinControl*)_Object)->Parent = this;
                if ( _MyObject->Properties[i].FName == "Color" )
                    SetPropByKind( _MyObject->Properties[i].FData, tkEnumeration, _Object, _MyObject->Properties[i].FName, _MyObject->Properties[i].FValue);
                else
                    if ( _MyObject->PropKinds[i] != tkClass )
                        SetPropByKind( _MyObject->Properties[i].FData, (unsigned)_MyObject->PropKinds[i], _Object, _MyObject->Properties[i].FName, _MyObject->Properties[i].FValue);
            }
        }
    }
}

//---------------------------------------------------------------------------
void TMyDialogEdit::DrawFrameRect(int Index, TVCLEditorElement* _Object)
{
    Canvas->Pen->Width = 2;
    Canvas->Pen->Mode = pmXor;
    Canvas->Pen->Color = clWhite;
    TPoint *Points = new TPoint[5];
    if (_Object->VCLParent->Control == this)
    {
        Points[0] = Point(BorderFrame.Items[Index]->Left, BorderFrame.Items[Index]->Bottom);
        Points[1] = Point(BorderFrame.Items[Index]->Left, BorderFrame.Items[Index]->Top);
        Points[2] = Point(BorderFrame.Items[Index]->Right, BorderFrame.Items[Index]->Top);
        Points[3] = Point(BorderFrame.Items[Index]->Right, BorderFrame.Items[Index]->Bottom);
        Points[4] = Point(BorderFrame.Items[Index]->Left, BorderFrame.Items[Index]->Bottom);
    }
    else
    {
        Points[0] = Point(_Object->VCLParent->Control->Left + BorderFrame.Items[Index]->Left, _Object->VCLParent->Control->Top + BorderFrame.Items[Index]->Bottom);
        Points[1] = Point(_Object->VCLParent->Control->Left + BorderFrame.Items[Index]->Left, _Object->VCLParent->Control->Top + BorderFrame.Items[Index]->Top);
        Points[2] = Point(_Object->VCLParent->Control->Left + BorderFrame.Items[Index]->Right, _Object->VCLParent->Control->Top + BorderFrame.Items[Index]->Top);
        Points[3] = Point(_Object->VCLParent->Control->Left + BorderFrame.Items[Index]->Right, _Object->VCLParent->Control->Top + BorderFrame.Items[Index]->Bottom);
        Points[4] = Point(_Object->VCLParent->Control->Left + BorderFrame.Items[Index]->Left, _Object->VCLParent->Control->Top + BorderFrame.Items[Index]->Bottom);
    }
    Canvas->Polyline( Points, 4 );
    Canvas->Pen->Mode = pmCopy;
    Canvas->Pen->Width = 1;
    delete Points;
}

//---------------------------------------------------------------------------
void TMyDialogEdit::ToMyDialogEditor(TVCLEditorElement *_Head, TVCLEditorElement *Parent, TMyWinControl *_Root)
{
        int i, j;
        AnsiString TempName;
        if (_Head != Head)
        {
            TObject* _Object = MakeObjectById(_Root->ClassId, TempName, NULL);
            if ( !IS (_Object, __classid(TWinControl)))
                ((TWinControl*)_Object)->Parent = this;
            if ( IS ( _Object, __classid ( TTabSheet ) ) )
            {
                ((TTabSheet*)_Object)->Parent = Parent->Control;
                ((TPageControl*)Parent->Control)->ActivePage = ((TTabSheet*)_Object);
                ((TTabSheet*)_Object)->TabVisible = true;
                ((TTabSheet*)_Object)->PageControl = ((TPageControl*)Parent->Control);
            }
            FillProps(_Root, (TComponent*)_Object);
            _Head->Component = (TComponent*)_Object;
            if ( !IS (_Object, __classid(TWinControl)))
            {
                _Head->Control = new TForm(this);
                _Head->Control->Parent = this;
                _Head->Control->Top = 0;
                _Head->Control->Left = 0;
                _Head->Control->Height = 4 * GridStep;
                _Head->Control->Width = 4 * GridStep;
                ((TForm*)_Head->Control)->BorderStyle = bsNone;
                _Head->Control->Visible = true;
            }
            else
            {
                _Head->Control = (TWinControl*)_Head->Component;
                if ( Parent )
                {
                    _Head->Control->Parent = Parent->Control;
                    _Head->Parent = Parent;
                }
            }
            for(i = 0; i < 8; i++)
                 _Head->Rects[i] = Rect(0,0,0,0);
            _Head->ChildList->Clear();
            _Head->Control->ComponentState<<csDesigning;
            if (_Head->CanHaveChild())
                _Head->Control->ComponentState<<csDesignInstance;
        }
        else
        {
            FillProps(_Root, this);
            this->Visible = false;
        }
        for (i = 0; i < _Root->MyControls.Count; i++)
        {
                _Head->AddChild(new TVCLEditorElement);
                ToMyDialogEditor(_Head->VCLChild[i], _Head, _Root->MyControls.Items[i]);
        }
}

//---------------------------------------------------------------------------
void TMyDialogEdit::FromMyDialogEditor(TVCLEditorElement *_Head, TMyWinControl *_Root)
{
        int i;
        _Root->MyControls.Clear();
        _Root->FromPropObject( ObjInspector->Items[ObjInspector->FindByObject(_Head->Component)], _Root );
        for (i = 0; i < _Head->VCLChildCount; i++)
        {
                TMyWinControl *NewMyControl = new TMyWinControl;
                _Root->MyControls.Add(NewMyControl);
                FromMyDialogEditor(_Head->VCLChild[i], NewMyControl);
        }
}

//---------------------------------------------------------------------------
void __fastcall TMyDialogEdit::FormResize(TObject *Sender)
{
    ObjInspector->ReAct(this, true);
}

//---------------------------------------------------------------------------
void FillEvents(TEvents* Events, TComponent* Component, AnsiString Name, AnsiString Value)
{
    if ( Name == "OnClick" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnClick = NULL;
        else
            ((TButton*)Component)->OnClick = Events->MyOnClick;
    }
    if ( Name == "OnEnter" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnEnter = NULL;
        else
            ((TButton*)Component)->OnEnter = Events->MyOnEnter;
    }
    if ( Name == "OnContextPopup" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnContextPopup = NULL;
        else;
//            ((TButton*)Component)->OnContextPopup = Events->MyOnContextPopup;
    }
    if ( Name == "OnDragDrop" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnDragDrop = NULL;
        else
            ((TButton*)Component)->OnDragDrop = Events->MyOnDragDrop;
    }
    if ( Name == "OnDragOver" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnDragOver = NULL;
        else
            ((TButton*)Component)->OnDragOver = Events->MyOnDragOver;
    }
    if ( Name == "OnEndDock" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnEndDock = NULL;
        else
            ((TButton*)Component)->OnEndDock = Events->MyOnEndDock;
    }
    if ( Name == "OnEndDrag" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnEndDrag = NULL;
        else
            ((TButton*)Component)->OnEndDrag = Events->MyOnEndDrag;
    }
    if ( Name == "OnExit" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnExit = NULL;
        else
            ((TButton*)Component)->OnExit = Events->MyOnExit;
    }
    if ( Name == "OnKeyDown" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnKeyDown = NULL;
        else
            ((TButton*)Component)->OnKeyDown = Events->MyOnKeyDown;
    }
    if ( Name == "OnKeyPress" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnKeyPress = NULL;
        else
            ((TButton*)Component)->OnKeyPress = Events->MyOnKeyPress;
    }
    if ( Name == "OnKeyUp" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnKeyUp = NULL;
        else
            ((TButton*)Component)->OnKeyUp = Events->MyOnKeyUp;
    }
    if ( Name == "OnMouseDown" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnMouseDown = NULL;
        else
            ((TButton*)Component)->OnMouseDown = Events->MyOnMouseDown;
    }
    if ( Name == "OnMouseMove" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnMouseMove = NULL;
        else
            ((TButton*)Component)->OnMouseMove = Events->MyOnMouseMove;
    }
    if ( Name == "OnMouseUp" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnMouseUp = NULL;
        else
            ((TButton*)Component)->OnMouseUp = Events->MyOnMouseUp;
    }
    if ( Name == "OnStartDock" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnStartDock = NULL;
        else
            ((TButton*)Component)->OnStartDock = Events->MyOnStartDock;
    }
    if ( Name == "OnStartDrag" )
    {
        if (Value.IsEmpty())
            ((TButton*)Component)->OnStartDrag = NULL;
        else
            ((TButton*)Component)->OnStartDrag = Events->MyOnStartDrag;
    }
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnClick(TObject* Sender)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    LuaCallBack(Sender, Sender->ClassName(), "OnClick", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    Args[1].Type = mtAnyThing;
    Args[1].Value = &MousePos;
    Args[1].ObjectTypeName = "TPoint";
    Args.Add( new TLuaAttribute() );
    //AddInf
    Args[2].Type = mtBool;
    Args[2].Value = BoolToStr(Handled, true).c_str();
    LuaCallBack(Sender, Sender->ClassName(), "OnContextPopup", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnDragDrop(TObject *Sender, TObject *Source, int X, int Y)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    Args[1].Type = mtVCLObject;
    Args[1].Value = Source;
    Args.Add( new TLuaAttribute() );
    Args[2].Type = mtInt;
    Args[2].Value = IntToStr(X).c_str();
    Args.Add( new TLuaAttribute() );
    Args[3].Type = mtInt;
    Args[3].Value = IntToStr(Y).c_str();
    LuaCallBack(Sender, Sender->ClassName(), "OnDragDrop", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnDragOver(TObject *Sender, TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    Args[1].Type = mtVCLObject;
    Args[1].Value = Source;
    Args.Add( new TLuaAttribute() );
    Args[2].Type = mtInt;
    Args[2].Value = IntToStr(X).c_str();
    Args.Add( new TLuaAttribute() );
    Args[3].Type = mtInt;
    Args[3].Value = IntToStr(Y).c_str();
    Args.Add( new TLuaAttribute() );
    Args[4].Type = mtInt;
    Args[4].Value = IntToStr(State).c_str();
    Args.Add( new TLuaAttribute() );
    //AddInf
    Args[5].Type = mtBool;
    Args[5].Value = BoolToStr(Accept, true).c_str();
    LuaCallBack(Sender, Sender->ClassName(), "OnDragOver", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnEndDock(TObject *Sender, TObject *Target, int X, int Y)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    Args[1].Type = mtVCLObject;
    Args[1].Value = Target;
    Args.Add( new TLuaAttribute() );
    Args[2].Type = mtInt;
    Args[2].Value = IntToStr(X).c_str();
    Args.Add( new TLuaAttribute() );
    Args[3].Type = mtInt;
    Args[3].Value = IntToStr(Y).c_str();
    LuaCallBack(Sender, Sender->ClassName(), "OnEndDock", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnEndDrag(TObject *Sender, TObject *Target, int X, int Y)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    Args[1].Type = mtVCLObject;
    Args[1].Value = Target;
    Args.Add( new TLuaAttribute() );
    Args[2].Type = mtInt;
    Args[2].Value = IntToStr(X).c_str();
    Args.Add( new TLuaAttribute() );
    Args[3].Type = mtInt;
    Args[3].Value = IntToStr(Y).c_str();
    LuaCallBack(Sender, Sender->ClassName(), "OnEndDrag", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnEnter(TObject *Sender)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    LuaCallBack(Sender, Sender->ClassName(), "OnEnter", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnExit(TObject *Sender)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    LuaCallBack(Sender, Sender->ClassName(), "OnExit", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    //AddInf
    Args[1].Type = mtInt;
    Args[1].Value = IntToStr(Key).c_str();
    Args.Add( new TLuaAttribute() );
    Args[2].Type = mtAnyThing;
    Args[2].Value = &Shift;
    Args[2].ObjectTypeName = "TShiftState";
    LuaCallBack(Sender, Sender->ClassName(), "OnKeyDown", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnKeyPress(TObject *Sender, char &Key)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    //AddInf
    Args[1].Type = mtCharString;
    Args[1].Value = &Key;
    LuaCallBack(Sender, Sender->ClassName(), "OnKeyPress", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    //AddInf
    Args[1].Type = mtInt;
    Args[1].Value = IntToStr(Key).c_str();
    Args.Add( new TLuaAttribute() );
    Args[2].Type = mtAnyThing;
    Args[2].Value = &Shift;
    Args[2].ObjectTypeName = "TShiftState";
    LuaCallBack( Sender, Sender->ClassName(), "OnKeyUp", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    Args[1].Type = mtInt;
    Args[1].Value = IntToStr(Button).c_str();
    Args.Add( new TLuaAttribute() );
    Args[2].Type = mtAnyThing;
    Args[2].Value = &Shift;
    Args[2].ObjectTypeName = "TShiftState";
    Args.Add( new TLuaAttribute() );
    Args[3].Type = mtInt;
    Args[3].Value = IntToStr(X).c_str();
    Args.Add( new TLuaAttribute() );
    Args[4].Type = mtInt;
    Args[4].Value = IntToStr(Y).c_str();
    LuaCallBack(Sender, Sender->ClassName(), "OnMouseDown", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    Args[1].Type = mtAnyThing;
    Args[1].Value = &Shift;
    Args[1].ObjectTypeName = "TShiftState";
    Args.Add( new TLuaAttribute() );
    Args[2].Type = mtInt;
    Args[2].Value = IntToStr(X).c_str();
    Args.Add( new TLuaAttribute() );
    Args[3].Type = mtInt;
    Args[3].Value = IntToStr(Y).c_str();
    LuaCallBack(Sender, Sender->ClassName(), "OnMouseMove", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    Args[1].Type = mtInt;
    Args[1].Value = IntToStr(Button).c_str();
    Args.Add( new TLuaAttribute() );
    Args[2].Type = mtAnyThing;
    Args[2].Value = &Shift;
    Args[2].ObjectTypeName = "TShiftState";
    Args.Add( new TLuaAttribute() );
    Args[3].Type = mtInt;
    Args[3].Value = IntToStr(X).c_str();
    Args.Add( new TLuaAttribute() );
    Args[4].Type = mtInt;
    Args[4].Value = IntToStr(Y).c_str();
    LuaCallBack(Sender, Sender->ClassName(), "OnMouseUp", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnStartDock(TObject *Sender, TDragDockObject *&DragObject)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    //AddInf
    Args[1].Type = mtVCLObject;
    Args[1].Value = DragObject;
    LuaCallBack(Sender, Sender->ClassName(), "OnStartDock", Args );
}

//---------------------------------------------------------------------------
void __fastcall TEvents::MyOnStartDrag(TObject *Sender, TDragObject *&DragObject)
{
    TMDelTList<TLuaAttribute> Args;
    Args.Add( new TLuaAttribute() );
    Args[0].Type = mtVCLObject;
    Args[0].Value = Sender;
    Args.Add( new TLuaAttribute() );
    //AddInf
    Args[1].Type = mtVCLObject;
    Args[1].Value = DragObject;
    LuaCallBack(Sender, Sender->ClassName(), "OnStartDrag", Args );
}

//---------------------------------------------------------------------------
void __fastcall TMyDialogEdit::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    if ( Key == VK_DELETE )
      return;
}
//---------------------------------------------------------------------------



