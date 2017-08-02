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
    char* GetCharValue();
    void SetCharValue(char* NewValue);
    bool FAggregativeFlag;
    void SetAggregative(bool _Value);
    bool GetAggregative() const;
    void SetObjectTypeName(const AnsiString& ObjectType);
public:
    //---------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //---------------------------------
    TLuaAttribute();
    virtual ~TLuaAttribute();
    __property bool Aggregative = {read = GetAggregative,write = SetAggregative};
    __property AnsiString VALUE = {read = FCurValue,write = SetVALUE};
    __property void* Value = {read = NewGetValue,write = NewSetValue};
    __property void* Object = {read = NewGetObject,write = NewSetObject};
    __property int Type = {read = FType,write = SetType};
    __property AnsiString ObjectTypeName = {read = FObjectTypeName,write = SetObjectTypeName};

    AnsiString Meter;
    void ToEmpty();
    bool ReadOnly;
    bool EqualTo(const AnsiString& Another,int Digit);
    bool IsEmpty();
    void AddData(const AnsiString& Data);
    char* GetLuaValueRoundTo(int Digit);
    char* GetLuaStrType();
    AnsiString ValueRoundTo(int Digit);
    AnsiString ExcelValue(int Digit);

    virtual void SaveData(FILE *F) const ;
    virtual void LoadData(FILE *F);
    virtual void WriteData(TMemoryStream *MS) const;
    virtual void ReadData(TMemoryStream *MS);
    virtual void Assign(TMyObject *MS);
    virtual bool CheckFields();
};

extern COMMONAL_API TClassNode* TLuaAttribute::StaticType;

class COMMONAL_API TLuaAttributeList : public TMyObject {
private:
    int GetAttributeICount();
    int GetAttributeCount();
public:
    //---------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
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

    char* GetAttributeName(int index);
    int GetAttributeIndex(char* Name);
    void Clear();
    __property int AttributeCount = { read = GetAttributeCount };
    __property int AttributeICount = { read = GetAttributeICount };
    virtual bool CheckFields();
};

extern COMMONAL_API TClassNode* TLuaAttributeList::StaticType;


#endif
