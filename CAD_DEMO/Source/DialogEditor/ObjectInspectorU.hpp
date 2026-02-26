// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
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
#include "compat/vcl_qt.h"
#include <Variants.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit

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
	void  OIComboBoxChange(System::TObject* Sender);
	void  MethodValueListEditorStringsChange(System::TObject* Sender);
	void  PropertyValueListEditorStringsChange(System::TObject* Sender);
	void  PropertyValueListEditorEditButtonClick(System::TObject* Sender);
	void  PropertyValueListEditorMouseDown(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void  PropertyValueListEditorDrawCell(System::TObject* Sender, int ACol, int ARow, const Types::TRect &Rect, Grids::TGridDrawState State);
	void  FormShow(System::TObject* Sender);
	void  FormCreate(System::TObject* Sender);
	void  PropertyValueListEditorKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void  MethodValueListEditorKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void  PropertyValueListEditorSelectCell(System::TObject* Sender, int ACol, int ARow, bool &CanSelect);
	void  PropertyValueListEditorDblClick(System::TObject* Sender);
	void  PropertyValueListEditorMouseMove(System::TObject* Sender, Classes::TShiftState Shift, int X, int Y);
	void  PropertyValueListEditorMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void  MethodValueListEditorDblClick(System::TObject* Sender);
	void  MethodValueListEditorMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void  MethodValueListEditorMouseMove(System::TObject* Sender, Classes::TShiftState Shift, int X, int Y);
	
private:
	int FDrawFlag;
	bool Resizeable;
	bool NeedRefresh;
	void  OIStringsChange(EditorType _Type);
	int  RecursiveFind(Classes::TComponent* Root, HWND ActiveWindow);
	int  FindActiveEditor(void);
	
public:
	DynamicArray<Propdatau::TPropObject* >  Items;
	DynamicArray<Propdatau::TPropObject* >  SelectedObjects;
	Propdatau::TPropObject* AbstractObject;
	Classes::TNotifyEvent ObjectChanged;
	bool RefreshSelectionBorder;
	 virtual ~TObjectInspectorF(void);
	__property int DrawFlag = {read=FDrawFlag, write=FDrawFlag, nodefault};
	void  ClearOI(void);
	void  ReAct(System::TObject* _Object, bool ReDraw = false);
	void  RefreshOI(int &Line, int Edge, Propdatau::TPropObject* _Object);
	void  AddObject(const System::TObject* Value, AnsiString _Name);
	void  ObjectToSelect(Propdatau::TPropObject* _Object, bool NeedDraw = false, bool Add = false)/* overload */;
	void  ObjectToSelect(System::TObject* _Object, bool NeedDraw = false, bool Add = false)/* overload */;
	void  ObjectFromSelect(Propdatau::TPropObject* _Object)/* overload */;
	void  ObjectFromSelect(System::TObject* _Object)/* overload */;
	void  ClearSelect(void);
	void  DeleteObject(Propdatau::TPropObject* _Object, bool NeedDraw = true)/* overload */;
	void  DeleteObject(System::TObject* _Object, bool NeedDraw = true)/* overload */;
	void  ReReadProperty(Propdatau::TPropObject* _Object);
	void  MakeTmpList(const Propdatau::TPropObject* const * _Objects, const int _Objects_Size);
	void  DrawOpenRect(const Types::TPoint &MPoint, Propdatau::TPropObject* _Object);
	bool  OnOpenRect(const Types::TPoint &MPoint, Propdatau::TProp* Prop);
	int  FindEdgeByParent(Propdatau::TProp* Prop);
	int  ChildIsIn(AnsiString _Name, const Propdatau::TPropObject* const * List, const int List_Size);
	Propdatau::TProp*  GetPropByRaw(int _Index, Propdatau::TPropObject* _Object);
	Propdatau::TProp*  GetMethodByRaw(int _Index, Propdatau::TPropObject* _Object);
	int  OpenChildValue(Propdatau::TPropObject* _Object);
	int  FindByObject(System::TObject* _Object)/* overload */;
	int  FindByObject(Propdatau::TPropObject* _Object)/* overload */;
	Graphics::TColor  GetColor(AnsiString Color);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline  virtual TObjectInspectorF(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline  virtual TObjectInspectorF(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline  TObjectInspectorF(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define cStrEdge "    "
static const Shortint OpenRectWidth = 0xa;
extern  TObjectInspectorF* ObjInspector;
extern  int  PropertyCount(System::TObject* _Object, int &PropCount, int &MethodCount);
extern  void  SetPropByKind(AnsiString Data, Typinfo::TTypeKind Kind, System::TObject* _Object, AnsiString PropName, const Variant &PropValue, System::TObject* PropObject = (System::TObject*)(0x0));
extern  int  PropIsIn(AnsiString _Name, const Propdatau::TProp* const * List, const int List_Size);
extern  void  InitPropByObject(System::TObject* _MyObject, Propdatau::TPropObject* &_Object);

}	/* namespace Objectinspectoru */
using namespace Objectinspectoru;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ObjectInspectorU
