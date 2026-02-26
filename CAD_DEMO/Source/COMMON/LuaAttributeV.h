// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
               
#ifndef LuaAttributeVH
#define LuaAttributeVH
//---------------------------------------------------------------------------
COMMONAL_API bool EmptyVariant(const AnsiString& Value);

class TLuaAttributeList;
class COMMONAL_API TLuaAttribute : public TMyObject {
    friend class TMyRegObject;
private:
    void SetVALUE(const AnsiString &newVALUE);
    AnsiString FVALUE;
    AnsiString FCurValue;
    int FType;
    void SetType(int NewType);
    //-----------------------------------
    AnsiString FObjectTypeName;
    void* FObjectAddress;
    void* NewGetObject();
    void NewSetObject(void* aObject);
    void* NewGetValue();
    //-----------------------------------
    void NewSetValue(void* aNewValue);
    const char* GetCharValue();
    void SetCharValue(char* NewValue);
    bool FAggregativeFlag;
    void SetAggregative(bool _Value);
    bool GetAggregative() const;
    void SetObjectTypeName(const AnsiString& ObjectType);
public:
    //---------------------------------
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    //---------------------------------
    TLuaAttribute();
    virtual ~TLuaAttribute();
    // __property bool Aggregative {read=GetAggregative, write=SetAggregative}; // replaced by proxy:
    struct _AggregProxy {
        TLuaAttribute* const _o;
        explicit _AggregProxy(TLuaAttribute* o) noexcept : _o(o) {}
        _AggregProxy& operator=(const _AggregProxy&) = default;
        operator bool() const { return _o->GetAggregative(); }
        _AggregProxy& operator=(bool v) { _o->SetAggregative(v); return *this; }
    } Aggregative{this};
    // __property AnsiString VALUE {read=FCurValue, write=SetVALUE}; // replaced by:
    AnsiString& VALUE = FCurValue;
    // __property void* Value {read=NewGetValue, write=NewSetValue}; // replaced by:
    struct _ValProxy {
        TLuaAttribute* const _o;
        explicit _ValProxy(TLuaAttribute* o) noexcept : _o(o) {}
        _ValProxy& operator=(const _ValProxy&) = default;
        operator void*() const { return _o->NewGetValue(); }
        _ValProxy& operator=(void* v) { _o->NewSetValue(v); return *this; }
    } Value{this};
    // __property void* Object {read=NewGetObject, write=NewSetObject}; // replaced by:
    struct _ObjProxy {
        TLuaAttribute* _o;
        explicit _ObjProxy(TLuaAttribute* o) noexcept : _o(o) {}
        operator void*() const { return _o->NewGetObject(); }
        _ObjProxy& operator=(void* v) { _o->NewSetObject(v); return *this; }
    } Object{this};
    // __property int Type {read=FType, write=SetType}; // replaced by:
    struct _TypeProxy {
        TLuaAttribute* const _o;
        explicit _TypeProxy(TLuaAttribute* o) noexcept : _o(o) {}
        _TypeProxy& operator=(const _TypeProxy&) = default;
        operator int() const { return _o->FType; }
        bool operator==(int x) const { return _o->FType == x; }
        bool operator!=(int x) const { return _o->FType != x; }
        _TypeProxy& operator=(int v) { _o->SetType(v); return *this; }
    } Type{this};
    // __property AnsiString ObjectTypeName {read=FObjectTypeName, write=SetObjectTypeName}; // replaced by:
    struct _OTNProxy {
        TLuaAttribute* const _o;
        explicit _OTNProxy(TLuaAttribute* o) noexcept : _o(o) {}
        _OTNProxy& operator=(const _OTNProxy&) = default;
        operator AnsiString() const { return _o->FObjectTypeName; }
        bool operator==(const AnsiString& s) const { return _o->FObjectTypeName == s; }
        bool operator!=(const AnsiString& s) const { return _o->FObjectTypeName != s; }
        bool IsEmpty() const { return _o->FObjectTypeName.IsEmpty(); }
        _OTNProxy& operator=(const AnsiString& v) { _o->SetObjectTypeName(v); return *this; }
    } ObjectTypeName{this};

    AnsiString Meter;
    void ToEmpty();
    bool ReadOnly;
    bool EqualTo(const AnsiString& Another,int Digit);
    bool IsEmpty();
    void AddData(const AnsiString& Data);
    const char* GetLuaValueRoundTo(int Digit);
    const char* GetLuaStrType();
    AnsiString ValueRoundTo(int Digit);
    AnsiString ExcelValue(int Digit);

    virtual void SaveData(FILE *F) const ;
    virtual void LoadData(FILE *F);
    virtual void WriteData(TMemoryStream *MS) const;
    virtual void ReadData(TMemoryStream *MS);
    virtual void Assign(TMyObject *MS);
    virtual bool CheckFields();
};


class COMMONAL_API TLuaAttributeList : public TMyObject {
private:
    int GetAttributeICount();
    int GetAttributeCount();
public:
    //---------------------------------
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    //---------------------------------
    TMDelTList<TLuaAttribute>* VarList;
    TMDelTList<TLuaAttribute>* IndexList;
    TLuaAttributeList();
    virtual ~TLuaAttributeList();
    TLuaAttribute* GetAttribute(char* Name);
    TLuaAttribute* GetAttributeI(int index);

    TLuaAttribute* AddAttribute(int type,char* Name);
    TLuaAttribute* AddAttribute(char* Name);
    TLuaAttribute* AddAttributeI(int type);
    TLuaAttribute* AddAttributeI(void);

    void* GetAttributeValue(char* Name);
    void* GetAttributeIValue(int index);
    void SetAttributeValue(char* Name,void* Value);
    void SetAttributeIValue(int index,void* Value);

    void DeleteAttributeI(int index);
    void DeleteAttribute(char* Name);

    const char* GetAttributeName(int index);
    int GetAttributeIndex(char* Name);
    void Clear();
    // __property int AttributeCount {read=GetAttributeCount}; // [manual migration needed]
    // __property int AttributeICount {read=GetAttributeICount}; // [manual migration needed]
    virtual bool CheckFields();
};



#endif
