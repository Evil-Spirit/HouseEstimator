//---------------------------------------------------------------------------


#include <vcl.h>
#include "MTL.h"
#include "Usefuls.h"
#include <windows.h>
#include "MyTemplates.h"
#pragma hdrstop

#include "LuaAttributeV.h"

//------ ---------------------------------------------------------------------

#pragma package(smart_init)
TClassNode* TLuaAttribute::StaticType = NULL;
TClassNode* TLuaAttributeList::StaticType = NULL;


//--------------------------------------------------------------------------
const AnsiString aName = AnsiString("Name");
const AnsiString aType = AnsiString("Type");
const AnsiString aVALUE = AnsiString("VALUE");
const AnsiString aMeter = AnsiString("Meter");
const AnsiString aDescription = AnsiString("Description");
const AnsiString aObjectTypeName = AnsiString("ObjectTypeName");
const AnsiString aAggregative = AnsiString("Aggregative");

void TLuaAttribute::SetObjectTypeName(const AnsiString& ObjectType)
{
    if (Type != mtAnyThing)
        throw EMyException("<TLuaAttribute::SetObjectTypeName>: Cannot assign type other than <mtAnyThing>.");
    FObjectTypeName = ObjectType;        
}

TLuaAttribute::TLuaAttribute()
{
    RegisterNewClass< TMyObject,TLuaAttribute >(this,false,&CreateFunction);

    ReadOnly = true;
    FAggregativeFlag = false;
    FObjectAddress = NULL;
    FObjectTypeName = AnsiString();
    FType = mtInt;
    Name = AnsiString();
    FVALUE = AnsiString("0");
    FCurValue = AnsiString("0");
    Description = AnsiString("No comments");
    Meter = AnsiString("");
    RegisterField(&FAggregativeFlag,&aAggregative,mtBool);
    RegisterField(&Name,&aName,mtString);
    RegisterField(&Type,&aType,mtInt);
    RegisterField(&FVALUE,&aVALUE,mtString);
    RegisterField(&Description,&aDescription,mtString);
    RegisterField(&Meter,&aMeter,mtString);
    RegisterField(&FObjectTypeName,&aObjectTypeName,mtString);
}

void TLuaAttribute::SetAggregative(bool _Value)
{
    FAggregativeFlag = _Value;
}

bool TLuaAttribute::GetAggregative() const
{
    return FAggregativeFlag && Type == mtMyObject; 
}

char* TLuaAttribute::GetLuaStrType()
{
    switch (Type)
    {
        case mtBool:
            return "boolean";
        case mtInt:
        case mtDouble:
        case mtFloat:
            return "number";
        case mtString:
            return "string";
        case mtMyObject:
        case mtVCLObject:
        case mtAnyThing:
            return FObjectTypeName.c_str();
        default:
            return "userdata";
    };
}

TMyObject* TLuaAttribute::CreateFunction()
{
    return new TLuaAttribute();
}

TLuaAttribute::~TLuaAttribute()
{
    ToEmpty();
}

char* TLuaAttribute::GetCharValue()
{
    return FCurValue.c_str();
}

char* TLuaAttribute::GetLuaValueRoundTo(int Digit)
{
    AnsiString* NewAnsi = new AnsiString(ValueRoundTo(Digit));
    Garbage.AddStr(NewAnsi);
    return NewAnsi->c_str();
}

void TLuaAttribute::SetCharValue(char* NewValue)
{
    SetVALUE(AnsiString(NewValue));
}

void TLuaAttribute::SetType(int Value)
{
    switch (Value)
    {
        case mtInt:
        case mtDouble:
        case mtFloat:
        case mtString:
        case mtMyObject:
        case mtVCLObject:
        case mtAnyThing:
        {
            //-------порядок имеет значение т.к. функция <ToEmpty> использует Type
            ToEmpty();
            FType = Value;
            Aggregative = false;
        }
    };
}

void TLuaAttribute::SaveData(FILE *F) const
{
    TMyObject::SaveData(F);
    if (FObjectAddress && Aggregative)
        ((TMyObject*)FObjectAddress)->SaveData(F);
}

void TLuaAttribute::WriteData(TMemoryStream *MS) const
{
    TMyObject::WriteData(MS);
    if (FObjectAddress && Aggregative)
        ((TMyObject*)FObjectAddress)->WriteData(MS);
}

void TLuaAttribute::LoadData(FILE *F)
{
    TMyObject::LoadData(F);
    if ( !ObjectTypeName.IsEmpty() )
    {
        if ( Aggregative )
        {
            Object = Create_Default_Constructor(ObjectTypeName);
            ((TMyObject*)Object)->LoadData(F);
        }
        else
            Object = NULL;
    }
}

void TLuaAttribute::ReadData(TMemoryStream *MS)
{
    TMyObject::ReadData(MS);
    if ( !ObjectTypeName.IsEmpty() )
    {
        if ( Aggregative )
        {
            Object = Create_Default_Constructor(ObjectTypeName);
            ((TMyObject*)Object)->ReadData(MS);
        }
        else
            Object = NULL;
    }
}

void TLuaAttribute::Assign(TMyObject *MS)
{
    TMyObject::Assign(MS);
    if ( !ObjectTypeName.IsEmpty() )
    {
        if (Aggregative)
        {
            Object = Create_Default_Constructor(ObjectTypeName);
            ((TMyObject*)Object)->Assign( (TMyObject*)((TLuaAttribute*)MS)->Object );
        }
        else
        {
            Object = ((TLuaAttribute*)MS)->Object;
        }
    }
}

void* TLuaAttribute::NewGetObject()
{
    return FObjectAddress;
}

void Kill_NameSpace_Text(AnsiString& Str)
{
    int ns_pos = 0;
    while ( (ns_pos = Str.Pos("::")) != 0 )
        Str.Delete(1,ns_pos);
}

void TLuaAttribute::NewSetObject(void* aObject)
{
    ToEmpty();
    if (aObject)
    {
        if ( Type == mtMyObject )
        {
            FObjectAddress = aObject;
            FObjectTypeName = ((TMyObject*)aObject)->DynamicType->Name;
        }
        else if (Type == mtVCLObject)
        {
            FObjectAddress = aObject;
            FObjectTypeName = ((TObject*)aObject)->ClassName();
            Kill_NameSpace_Text(FObjectTypeName);
        }
        else if (Type == mtAnyThing)
        {
            FObjectAddress = aObject;
            FObjectTypeName = "userdata";
        }
        else
            throw EMyException("<TLuaAttribute::NewSetObject> Error!");
    }
}

void* TLuaAttribute::NewGetValue()
{
    if ( Type == mtMyObject || Type == mtVCLObject || Type == mtAnyThing )
        return NewGetObject();
    else
    {
        return STRTOTYPE(FVALUE,Type);
    }
}

void TLuaAttribute::NewSetValue(void* aNewValue)
{
    if ( Type == mtMyObject || Type == mtVCLObject || Type == mtAnyThing  )
        NewSetObject(aNewValue);
    else
        SetCharValue((char*)aNewValue);
}


void TLuaAttribute::SetVALUE(const AnsiString &newVALUE)
{
    switch (Type)
    {
        case mtInt:
        {
            if (ISINTEGER(newVALUE))
                FCurValue = newVALUE;
            else
            {
                AnsiString Str = AnsiString("Attribute ") + Name + AnsiString(" has type <INTEGER>");
                Str = Str + AnsiString(".\nCan not assign ") + newVALUE;
                throw EMyException(Str);
            }
            break;
        }
        case mtDouble:
        case mtFloat:
        {
            if (IS_FLOAT(newVALUE))
                FCurValue = MBTiToStr(StrToMBTi(newVALUE));
            else
            {
                AnsiString Str = AnsiString("Attribute ") + Name + AnsiString(" has type <REAL>");
                Str = Str + AnsiString(".\nCan not assign ") + newVALUE;
                throw EMyException(Str);
            }
            break;
        }
        case mtString:
        {
            FCurValue = newVALUE;
        }
    }
    if (!ReadOnly)
        FVALUE = FCurValue;
}

bool EmptyVariant(const AnsiString& Value)
{
    return Value.IsEmpty() || Value.Trim() == AnsiString("0");
}

bool TLuaAttribute::IsEmpty()
{
    return EmptyVariant(FCurValue);
}

bool TLuaAttribute::EqualTo(const AnsiString& Data,int Digit)
{
    switch (Type)
    {
        case mtInt:
            if (ISINTEGER(Data))
                return FCurValue.ToInt() == Data.ToInt();
            else
                return false;
        case mtDouble:
        case mtFloat:
            if (IS_FLOAT(Data))
                return RoundTo(TO_DOUBLE(FCurValue),Digit) == RoundTo(TO_DOUBLE(Data),Digit);
            else
                return false;
        default:
            return FCurValue.Trim() == Data.Trim();
    }
}

// TLuaAttribute::ToEmpty - save FTypeName
void TLuaAttribute::ToEmpty()
{
    if (FObjectAddress)
    {
        if ( Aggregative )
            delete (TMyObject*)FObjectAddress;
        FObjectAddress = NULL;
        if ( Type == mtMyObject )
            FObjectTypeName = "TMyObject";
        else if ( Type == mtVCLObject )
            FObjectTypeName = "TObject";
        else if ( Type == mtAnyThing )
            FObjectTypeName = "userdata";
        else
            throw EMyException("<TLuaAttribute::ToEmpty> Error!");
    }
    FCurValue = (Type == mtString) ? AnsiString() : AnsiString("0");
}


void TLuaAttribute::AddData(const AnsiString& Data)
{
    if (ReadOnly)
        throw EMyException(AnsiString("Attribute ") + Name + AnsiString(" is read only.") );
    switch (Type)
    {
        case mtInt:
        {
            if (ISINTEGER(Data))
            {
                if (FCurValue.IsEmpty())
                    FCurValue = AnsiString("0");
                FCurValue = IntToStr( FCurValue.ToInt() + Data.ToInt() );
            }
            else
            {
                AnsiString Str = AnsiString("Can not assign to variable ") + Name +
				AnsiString(" (Type:") + StrTypes[Type] + AnsiString(") ") + AnsiString(" value of other type");

                throw EMyException(Str);
            }
            break;
        }
        case mtDouble:
        case mtFloat:
        {
            if (IS_FLOAT(Data))
            {
                if (FCurValue.IsEmpty())
                    FCurValue = AnsiString("0");
                FCurValue = FLOATTOSTR( TO_DOUBLE(FCurValue) + TO_DOUBLE(Data) );
            }
            else
            {
                AnsiString Str = AnsiString("Can not assign to variable ") + Name +
				AnsiString(" (Type:") + StrTypes[Type] + AnsiString(") ") + AnsiString(" value of other type");
                throw EMyException(Str);
            }
            break;
        }
        case mtString:
        {
            if (FCurValue == AnsiString("0"))
                FCurValue = Data;
            else
                FCurValue = FCurValue + AnsiString("\n") + Data;
        }
    }
    if (!ReadOnly)
        FVALUE = FCurValue;
}

bool TLuaAttribute::CheckFields()
{
    if (!TMyObject::CheckFields())
        return false;
    FCurValue = FVALUE;
    return !Object || !Aggregative || Type != mtMyObject || ((TMyObject*)Object)->CheckFields();
}

AnsiString TLuaAttribute::ExcelValue(int Digit)
{
    if (Type == mtDouble || Type == mtFloat)
        return FloatToStr( RoundTo( TO_DOUBLE(FCurValue),Digit) ) ;
    else
        return FCurValue;
}

AnsiString TLuaAttribute::ValueRoundTo(int Digits)
{
    if (Type == mtDouble)
        return FLOATTOSTR( RoundTo( TO_DOUBLE(FCurValue),Digits) );
    else
        return FCurValue;
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
const AnsiString aVarList = AnsiString("VarList");
const AnsiString aIndexList = AnsiString("IndexList");
TLuaAttributeList::TLuaAttributeList()
{
    RegisterNewClass< TMyObject,TLuaAttributeList >(this,false,&CreateFunction);

    VarList = new TMDelTList<TLuaAttribute>;
    IndexList = new TMDelTList<TLuaAttribute>;
    RegisterField(VarList,&aVarList,mtMyObject);
    RegisterField(IndexList,&aIndexList,mtMyObject);
}

bool TLuaAttributeList::CheckFields()
{
    if (!TMyObject::CheckFields())
        return false;
    for (int i=0; i<VarList->Count; i++)
        VarList->Items[i]->ReadOnly = false;
    for (int i=0; i<IndexList->Count; i++)
        IndexList->Items[i]->ReadOnly = false;
    return true;
}

TMyObject* TLuaAttributeList::CreateFunction()
{
    return new TLuaAttributeList();
}

TLuaAttributeList::~TLuaAttributeList()
{
    delete VarList;
    delete IndexList;
}

int TLuaAttributeList::GetAttributeIndex(char* _name)
{
    AnsiString _Name = AnsiString(_name).Trim().LowerCase();
    for (int i=0;i<VarList->Count;i++)
        if (_Name == VarList->Items[i]->Name.Trim().LowerCase())
            return i;
    return -1;            
}

char* TLuaAttributeList::GetAttributeName(int index)
{
    return VarList->Items[index]->Name.c_str();
}

int TLuaAttributeList::GetAttributeICount()
{
    return IndexList->Count;
}

int TLuaAttributeList::GetAttributeCount()
{
    return VarList->Count;
}

TLuaAttribute* TLuaAttributeList::GetAttribute(char* _name)
{
    int index = GetAttributeIndex(_name);
    if (index!=-1)
        return VarList->Items[ index ];
    return NULL;
}

TLuaAttribute* TLuaAttributeList::GetAttributeI(int index)
{
    return IndexList->Items[index];
}

TLuaAttribute* TLuaAttributeList::AddAttributeI(void)
{
    IndexList->Add(new TLuaAttribute());
    IndexList->Last()->Type = 2;
    IndexList->Last()->ReadOnly = false;
    return IndexList->Last();
}

TLuaAttribute* TLuaAttributeList::AddAttributeI(int type)
{
    TLuaAttribute* Attribute = AddAttributeI();
    Attribute->Type = type;
    return Attribute;
}

TLuaAttribute* TLuaAttributeList::AddAttribute(char* _name)
{
    TLuaAttribute* Attribute = GetAttribute(_name);
    if (Attribute == NULL)
    {
        VarList->Add(new TLuaAttribute());
        Attribute = VarList->Last();
    }
    Attribute->Type = 2;
    Attribute->ReadOnly = false;
    Attribute->Name = AnsiString(_name).Trim();
    return Attribute;
}

TLuaAttribute* TLuaAttributeList::AddAttribute(int type,char* _name)
{
    TLuaAttribute* Attribute = AddAttribute(_name);
    Attribute->Type = type;
    return Attribute;
}

void* TLuaAttributeList::GetAttributeValue(char* _name)
{
    TLuaAttribute* Attribute = GetAttribute(_name);
    return (Attribute != NULL) ? Attribute->Value : NULL;
}

void* TLuaAttributeList::GetAttributeIValue(int index)
{
    TLuaAttribute* Attribute = GetAttributeI(index);
    return (Attribute != NULL) ? Attribute->Value : NULL;
}

void TLuaAttributeList::SetAttributeIValue(int index,void* Value)
{
    TLuaAttribute* Attribute = GetAttributeI(index);
    if (Attribute)
        Attribute->Value = Value;
}

void TLuaAttributeList::SetAttributeValue(char* _name,void* Value)
{
    TLuaAttribute* Attribute = GetAttribute(_name);
    if (Attribute)
        Attribute->Value = Value;
}

void TLuaAttributeList::DeleteAttribute(char* _name)
{
    int index = GetAttributeIndex(_name);
    if (index!=-1)
        VarList->Delete( index );
}

void TLuaAttributeList::DeleteAttributeI(int index)
{
    IndexList->Delete(index);
}

void TLuaAttributeList::Clear()
{
    VarList->Clear();
    IndexList->Clear();
}



