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
	AnsiString __fastcall NextWord(char * &Value);
	
public:
	__fastcall TPropObject(void);
	__fastcall virtual ~TPropObject(void);
	void __fastcall SetObject(AnsiString _Name, const System::TObject* Value, const System::TObject* Default, bool _Copy = true, TPropObject* _Parent = (TPropObject*)(0x0));
	Variant __fastcall GetPropertyValue(AnsiString Name)/* overload */;
	bool __fastcall IsAnyType(int Index, const Typinfo::TTypeKinds PropType);
	TPropObject* __fastcall GetChild(AnsiString _Name);
	__property bool OpenFlag = {read=FOpenFlag, write=FOpenFlag, nodefault};
	__property AnsiString Name = {read=FName, write=FName};
	__property bool Refresh = {read=FRefresh, write=FRefresh, nodefault};
	__property TPropObject* Parent = {read=FParent, write=FParent};
	__property System::TObject* ThisObject = {read=FObject, write=FObject};
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
	void __fastcall SetProperty(const Typinfo::PPropInfo Value);
	Typinfo::PPropInfo __fastcall GetProperty(void);
	
public:
	bool SawFlag;
	__fastcall TProp(void);
	__property Typinfo::PPropInfo PropertyInfo = {read=GetProperty, write=SetProperty};
	__property Typinfo::TTypeInfo PropertyType = {read=FPropertyType, write=FPropertyType};
	__property Typinfo::PTypeInfo PPropertyType = {read=FPPropertyType, write=FPPropertyType};
	__property Variant PropertyValue = {read=FPropertyValue, write=FPropertyValue};
	__property Variant DefaultValue = {read=FDefaultValue, write=FDefaultValue};
	__property Typinfo::TTypeKind PropertyKind = {read=FPropertyKind, write=FPropertyKind, nodefault};
	__property AnsiString PropertyName = {read=FPropertyName, write=FPropertyName};
	__property TPropObject* ThisObject = {read=FObject, write=FObject};
	__property TPropObject* Parent = {read=FParent, write=FParent};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TProp(void) { }
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
	void __fastcall OIStringsChange(EditorType _Type);
	
public:
	DynamicArray<TPropObject* >  Items;
	DynamicArray<TPropObject* >  SelectedObjects;
	TPropObject* AbstractObject;
	Classes::TNotifyEvent ObjectChanged;
	__fastcall virtual ~TObjectInspectorF(void);
	__property int DrawFlag = {read=FDrawFlag, write=FDrawFlag, nodefault};
	void __fastcall ReAct(System::TObject* _Object, bool ReDraw = false);
	void __fastcall RefreshOI(int &Line, int Edge, TPropObject* _Object);
	void __fastcall AddObject(const System::TObject* Value, AnsiString _Name);
	void __fastcall ObjectToSelect(TPropObject* _Object, bool NeedDraw = false, bool Add = false)/* overload */;
	void __fastcall ObjectToSelect(System::TObject* _Object, bool NeedDraw = false, bool Add = false)/* overload */;
	void __fastcall ObjectFromSelect(TPropObject* _Object)/* overload */;
	void __fastcall ObjectFromSelect(System::TObject* _Object)/* overload */;
	void __fastcall ClearSelect(void);
	void __fastcall DeleteObject(TPropObject* _Object, bool NeedDraw = true)/* overload */;
	void __fastcall DeleteObject(System::TObject* _Object, bool NeedDraw = true)/* overload */;
	void __fastcall ReReadProperty(TPropObject* _Object);
	void __fastcall MakeTmpList(const TPropObject* const * _Objects, const int _Objects_Size);
	void __fastcall DrawOpenRect(const Types::TPoint &MPoint, TPropObject* _Object);
	bool __fastcall OnOpenRect(const Types::TPoint &MPoint, TProp* Prop);
	int __fastcall FindEdgeByParent(TProp* Prop);
	int __fastcall ChildIsIn(AnsiString _Name, const TPropObject* const * List, const int List_Size);
	TProp* __fastcall GetPropByRaw(int _Index, TPropObject* _Object);
	TProp* __fastcall GetMethodByRaw(int _Index, TPropObject* _Object);
	int __fastcall OpenChildValue(TPropObject* _Object);
	int __fastcall FindByObject(System::TObject* _Object)/* overload */;
	int __fastcall FindByObject(TPropObject* _Object)/* overload */;
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
static const Byte MaxPropLen = 0xff;
#define cStrEdge "    "
static const Shortint OpenRectWidth = 0xa;
extern PACKAGE TObjectInspectorF* ObjectInspectorF;
extern PACKAGE int __fastcall PropertyCount(System::TObject* _Object, int &PropCount, int &MethodCount);
extern PACKAGE void __fastcall SetPropByKind(Typinfo::TTypeKind Kind, System::TObject* _Object, AnsiString PropName, const Variant &PropValue, System::TObject* PropObject = (System::TObject*)(0x0));
extern PACKAGE int __fastcall PropIsIn(AnsiString _Name, const TProp* const * List, const int List_Size);
extern PACKAGE void __fastcall InitPropByObject(System::TObject* _MyObject, TPropObject* &_Object);
extern PACKAGE System::TObject* __fastcall DefaultObject(const System::TObject* Value, Classes::TComponent* Owner);

}	/* namespace Objectinspectoru */
using namespace Objectinspectoru;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ObjectInspectorU
