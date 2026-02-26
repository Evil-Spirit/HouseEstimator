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
enum PropIdent { piSet, piSetElement, piClass, piEnumeration, piPointer, piNone };
#pragma option pop

#pragma option push -b-
enum EditorType { etMethod, etProperty };
#pragma option pop

class DELPHICLASS TProp;
class DELPHICLASS TPropObject;
typedef DynamicArray<TPropObject* >  ObjectInspectorU__3;

typedef DynamicArray<TProp* >  ObjectInspectorU__4;

typedef DynamicArray<TProp* >  ObjectInspectorU__5;

class PASCALIMPLEMENTATION TPropObject : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	PropIdent FPropId;
	bool FOpenFlag;
	bool FRefresh;
	AnsiString FName;
	System::TObject* FObject;
	DynamicArray<TPropObject* >  ChildList;
	TPropObject* FParent;
	DynamicArray<TProp* >  PropertyList;
	DynamicArray<TProp* >  MethodList;
	AnsiString FSetValue;
	int FSetLength;
	
private:
	AnsiString  NextWord(char * &Value);
	
public:
	 TPropObject(void);
	 virtual ~TPropObject(void);
	void  SetObject(AnsiString _Name, const System::TObject* Value, const System::TObject* Default, bool _Copy = true, TPropObject* _Parent = (TPropObject*)(0x0));
	Variant  GetPropertyValue(AnsiString Name)/* overload */;
	bool  IsAnyType(int Index, const Typinfo::TTypeKinds PropType);
	TPropObject*  GetChild(AnsiString _Name);
	__property bool OpenFlag = {read=FOpenFlag, write=FOpenFlag, nodefault};
	// __property AnsiString Name {read=FName, write=FName}; // [manual migration needed]
	__property bool Refresh = {read=FRefresh, write=FRefresh, nodefault};
	// __property TPropObject* Parent {read=FParent, write=FParent}; // [manual migration needed]
	// __property System::TObject* ThisObject {read=FObject, write=FObject}; // [manual migration needed]
};


class PASCALIMPLEMENTATION TProp : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	AnsiString FPropertyName;
	#pragma pack(push, 1)
	Typinfo::TPropInfo FPropertyInfo;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Typinfo::TTypeInfo FPropertyType;
	#pragma pack(pop)
	
	Typinfo::TTypeInfo *FPPropertyType;
	Typinfo::TTypeKind FPropertyKind;
	Variant FPropertyValue;
	Variant FDefaultValue;
	TPropObject* FObject;
	TPropObject* FParent;
	Classes::TStrings* Lines;
	Graphics::TPicture* Picture;
	
private:
	void  SetProperty(const Typinfo::PPropInfo Value);
	Typinfo::PPropInfo  GetProperty(void);
	
public:
	bool SawFlag;
	 TProp(void);
	// __property Typinfo::PPropInfo PropertyInfo {read=GetProperty, write=SetProperty}; // [manual migration needed]
	// __property Typinfo::TTypeInfo PropertyType {read=FPropertyType, write=FPropertyType}; // [manual migration needed]
	// __property Typinfo::PTypeInfo PPropertyType {read=FPPropertyType, write=FPPropertyType}; // [manual migration needed]
	// __property Variant PropertyValue {read=FPropertyValue, write=FPropertyValue}; // [manual migration needed]
	// __property Variant DefaultValue {read=FDefaultValue, write=FDefaultValue}; // [manual migration needed]
	__property Typinfo::TTypeKind PropertyKind = {read=FPropertyKind, write=FPropertyKind, nodefault};
	// __property AnsiString PropertyName {read=FPropertyName, write=FPropertyName}; // [manual migration needed]
	// __property TPropObject* ThisObject {read=FObject, write=FObject}; // [manual migration needed]
	// __property TPropObject* Parent {read=FParent, write=FParent}; // [manual migration needed]
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline  virtual ~TProp(void) { }
	#pragma option pop
	
};


typedef DynamicArray<TPropObject* >  ObjectInspectorU__7;

typedef DynamicArray<TPropObject* >  ObjectInspectorU__8;

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
	void  OIStringsChange(EditorType _Type);
	
public:
	DynamicArray<TPropObject* >  Items;
	DynamicArray<TPropObject* >  SelectedObjects;
	TPropObject* AbstractObject;
	Classes::TNotifyEvent ObjectChanged;
	 virtual ~TObjectInspectorF(void);
	__property int DrawFlag = {read=FDrawFlag, write=FDrawFlag, nodefault};
	void  ReAct(System::TObject* _Object, bool ReDraw = false);
	void  RefreshOI(int &Line, int Edge, TPropObject* _Object);
	void  AddObject(const System::TObject* Value, AnsiString _Name);
	void  ObjectToSelect(TPropObject* _Object, bool NeedDraw = false, bool Add = false)/* overload */;
	void  ObjectToSelect(System::TObject* _Object, bool NeedDraw = false, bool Add = false)/* overload */;
	void  ObjectFromSelect(TPropObject* _Object)/* overload */;
	void  ObjectFromSelect(System::TObject* _Object)/* overload */;
	void  ClearSelect(void);
	void  DeleteObject(TPropObject* _Object, bool NeedDraw = true)/* overload */;
	void  DeleteObject(System::TObject* _Object, bool NeedDraw = true)/* overload */;
	void  ReReadProperty(TPropObject* _Object);
	void  MakeTmpList(const TPropObject* const * _Objects, const int _Objects_Size);
	void  DrawOpenRect(const Types::TPoint &MPoint, TPropObject* _Object);
	bool  OnOpenRect(const Types::TPoint &MPoint, TProp* Prop);
	int  FindEdgeByParent(TProp* Prop);
	int  ChildIsIn(AnsiString _Name, const TPropObject* const * List, const int List_Size);
	TProp*  GetPropByRaw(int _Index, TPropObject* _Object);
	TProp*  GetMethodByRaw(int _Index, TPropObject* _Object);
	int  OpenChildValue(TPropObject* _Object);
	int  FindByObject(System::TObject* _Object)/* overload */;
	int  FindByObject(TPropObject* _Object)/* overload */;
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
static const Byte MaxPropLen = 0xff;
#define cStrEdge "    "
static const Shortint OpenRectWidth = 0xa;
extern  TObjectInspectorF* ObjectInspectorF;
extern  int  PropertyCount(System::TObject* _Object, int &PropCount, int &MethodCount);
extern  void  SetPropByKind(Typinfo::TTypeKind Kind, System::TObject* _Object, AnsiString PropName, const Variant &PropValue, System::TObject* PropObject = (System::TObject*)(0x0));
extern  int  PropIsIn(AnsiString _Name, const TProp* const * List, const int List_Size);
extern  void  InitPropByObject(System::TObject* _MyObject, TPropObject* &_Object);
extern  System::TObject*  DefaultObject(const System::TObject* Value, Classes::TComponent* Owner);

}	/* namespace Objectinspectoru */
using namespace Objectinspectoru;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ObjectInspectorU
