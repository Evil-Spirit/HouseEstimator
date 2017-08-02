// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ObjectInspectorU.pas' rev: 6.00

#ifndef ObjectInspectorUHPP
#define ObjectInspectorUHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <PropDataU.hpp>	// Pascal unit
#include <StringListEditorU.hpp>	// Pascal unit
#include <PictureEditorU.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <ValEdit.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Objectinspectoru
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum EditorType { etMethod, etProperty };
#pragma option pop

typedef DynamicArray<Propdatau::TPropObject* >  ObjectInspectorU__2;

typedef DynamicArray<Propdatau::TPropObject* >  ObjectInspectorU__3;

class DELPHICLASS TObjectInspectorF;
class PASCALIMPLEMENTATION TObjectInspectorF : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* OIPanel;
	Stdctrls::TComboBox* OIComboBox;
	Comctrls::TStatusBar* OIStatusBar;
	Comctrls::TPageControl* OIPageControl;
	Comctrls::TTabSheet* OIProperties;
	Comctrls::TTabSheet* OIMethods;
	Valedit::TValueListEditor* MethodValueListEditor;
	Valedit::TValueListEditor* PropertyValueListEditor;
	void __fastcall OIComboBoxChange(System::TObject* Sender);
	void __fastcall MethodValueListEditorStringsChange(System::TObject* Sender);
	void __fastcall PropertyValueListEditorStringsChange(System::TObject* Sender);
	void __fastcall PropertyValueListEditorEditButtonClick(System::TObject* Sender);
	void __fastcall PropertyValueListEditorMouseDown(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall PropertyValueListEditorDrawCell(System::TObject* Sender, int ACol, int ARow, const Types::TRect &Rect, Grids::TGridDrawState State);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PropertyValueListEditorKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall MethodValueListEditorKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall PropertyValueListEditorSelectCell(System::TObject* Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall PropertyValueListEditorDblClick(System::TObject* Sender);
	void __fastcall PropertyValueListEditorMouseMove(System::TObject* Sender, Classes::TShiftState Shift, int X, int Y);
	void __fastcall PropertyValueListEditorMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall MethodValueListEditorDblClick(System::TObject* Sender);
	void __fastcall MethodValueListEditorMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall MethodValueListEditorMouseMove(System::TObject* Sender, Classes::TShiftState Shift, int X, int Y);
	
private:
	int FDrawFlag;
	bool Resizeable;
	bool NeedRefresh;
	void __fastcall OIStringsChange(EditorType _Type);
	int __fastcall RecursiveFind(Classes::TComponent* Root, HWND ActiveWindow);
	int __fastcall FindActiveEditor(void);
	
public:
	DynamicArray<Propdatau::TPropObject* >  Items;
	DynamicArray<Propdatau::TPropObject* >  SelectedObjects;
	Propdatau::TPropObject* AbstractObject;
	Classes::TNotifyEvent ObjectChanged;
	bool RefreshSelectionBorder;
	__fastcall virtual ~TObjectInspectorF(void);
	__property int DrawFlag = {read=FDrawFlag, write=FDrawFlag, nodefault};
	void __fastcall ClearOI(void);
	void __fastcall ReAct(System::TObject* _Object, bool ReDraw = false);
	void __fastcall RefreshOI(int &Line, int Edge, Propdatau::TPropObject* _Object);
	void __fastcall AddObject(const System::TObject* Value, AnsiString _Name);
	void __fastcall ObjectToSelect(Propdatau::TPropObject* _Object, bool NeedDraw = false, bool Add = false)/* overload */;
	void __fastcall ObjectToSelect(System::TObject* _Object, bool NeedDraw = false, bool Add = false)/* overload */;
	void __fastcall ObjectFromSelect(Propdatau::TPropObject* _Object)/* overload */;
	void __fastcall ObjectFromSelect(System::TObject* _Object)/* overload */;
	void __fastcall ClearSelect(void);
	void __fastcall DeleteObject(Propdatau::TPropObject* _Object, bool NeedDraw = true)/* overload */;
	void __fastcall DeleteObject(System::TObject* _Object, bool NeedDraw = true)/* overload */;
	void __fastcall ReReadProperty(Propdatau::TPropObject* _Object);
	void __fastcall MakeTmpList(const Propdatau::TPropObject* const * _Objects, const int _Objects_Size);
	void __fastcall DrawOpenRect(const Types::TPoint &MPoint, Propdatau::TPropObject* _Object);
	bool __fastcall OnOpenRect(const Types::TPoint &MPoint, Propdatau::TProp* Prop);
	int __fastcall FindEdgeByParent(Propdatau::TProp* Prop);
	int __fastcall ChildIsIn(AnsiString _Name, const Propdatau::TPropObject* const * List, const int List_Size);
	Propdatau::TProp* __fastcall GetPropByRaw(int _Index, Propdatau::TPropObject* _Object);
	Propdatau::TProp* __fastcall GetMethodByRaw(int _Index, Propdatau::TPropObject* _Object);
	int __fastcall OpenChildValue(Propdatau::TPropObject* _Object);
	int __fastcall FindByObject(System::TObject* _Object)/* overload */;
	int __fastcall FindByObject(Propdatau::TPropObject* _Object)/* overload */;
	Graphics::TColor __fastcall GetColor(AnsiString Color);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TObjectInspectorF(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TObjectInspectorF(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TObjectInspectorF(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define cStrEdge "    "
static const Shortint OpenRectWidth = 0xa;
extern PACKAGE TObjectInspectorF* ObjInspector;
extern PACKAGE int __fastcall PropertyCount(System::TObject* _Object, int &PropCount, int &MethodCount);
extern PACKAGE void __fastcall SetPropByKind(AnsiString Data, Typinfo::TTypeKind Kind, System::TObject* _Object, AnsiString PropName, const Variant &PropValue, System::TObject* PropObject = (System::TObject*)(0x0));
extern PACKAGE int __fastcall PropIsIn(AnsiString _Name, const Propdatau::TProp* const * List, const int List_Size);
extern PACKAGE void __fastcall InitPropByObject(System::TObject* _MyObject, Propdatau::TPropObject* &_Object);

}	/* namespace Objectinspectoru */
using namespace Objectinspectoru;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ObjectInspectorU
