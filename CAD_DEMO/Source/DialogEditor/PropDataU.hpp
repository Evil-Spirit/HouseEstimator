// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PropDataU.pas' rev: 6.00

#ifndef PropDataUHPP
#define PropDataUHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <ValEdit.hpp>	// Pascal unit
#include "compat/vcl_qt.h"
#include <Variants.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Propdatau
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum PropIdent { piSet, piSetElement, piClass, piEnumeration, piPointer, piNone };
#pragma option pop

class DELPHICLASS TProp;
class DELPHICLASS TPropObject;
typedef DynamicArray<TPropObject* >  PropDataU__3;

typedef DynamicArray<TProp* >  PropDataU__4;

typedef DynamicArray<TProp* >  PropDataU__5;

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
	AnsiString FData;
	
private:
	void  SetProperty(const Typinfo::PPropInfo Value);
	Typinfo::PPropInfo  GetProperty(void);
	
public:
	bool SawFlag;
	 TProp(void);
	// __property AnsiString Data {read=FData, write=FData}; // [manual migration needed]
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


//-- var, const, procedure ---------------------------------------------------
static const Byte MaxPropLen = 0xff;
extern  System::TObject*  DefaultObject(const System::TObject* Value, Classes::TComponent* Owner);

}	/* namespace Propdatau */
using namespace Propdatau;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PropDataU
