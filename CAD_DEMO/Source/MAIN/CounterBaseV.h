//---------------------------------------------------------------------------

#ifndef CounterBaseVH
#define CounterBaseVH
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TElement;
class TNomenclature;

const int PaymentCount = 0;
const int WorkCount = 1;
const int SimpleCount = 2;

class TFieldEx{
public:
    TFieldEx(){};
    virtual ~TFieldEx(){};
    AnsiString Meter;
    int Digits;
    bool Visible;
    bool Accumulate;
    bool Total;
};

class TCounterBase;

class TQuerryNode{
    TQuerryNode* FParent;
    void SetParent(TQuerryNode* newParent);
    TCounterBase* CB;
public:
    Graphics::TBitmap* BMP;
    TQuerryNode(TQuerryNode* newParent,TCounterBase* _CB,TMetaNode* _Nom);
    virtual ~TQuerryNode();
    TMTList<TQuerryNode> Childs;
    __property TQuerryNode* Parent = {read = FParent, write = SetParent};
    TMetaNode* Nom;
    int index;
    int o_index;
    TMDelTList<AnsiString> vData;
	TMDelTList<AnsiString>& GetvData();
    void GoMultiply_1();
    void ChildConnect_2();
    void ChildConnect_2_5();
    void TotalCheck_3();
    void DoQuerry_4();
//    void CheckEmpty_5();
  //  bool IsEmpty();
    void CopyBMP_6();
    void Clear();
    void Select(TMTList<TQuerryNode>& QNS,bool TreeView,bool AllDirectory);
    AnsiString GetValue(int);
    AnsiString GetExcelValue(int);
    AnsiString GetValueNotRounded(int);
    TQuerryNode* FindByMetaNode(TMetaNode* MN);
};

class THierarchyQuerry{
    TCounterBase* CB;
public:
    TQuerryNode* Head;
    THierarchyQuerry(TCounterBase* _CB);
    virtual ~THierarchyQuerry();
    void FullProcess();
};

class TCounterBase{
private:
    int UnvisibleInTheMiddle();
    void UnVisibleToEnd();
    TMDelTList<TLuaAttribute>* GetVFields(){return &vFields;};
    TMDelTList<TFieldEx>* GetVFieldExs(){return &vFieldExs;};
    TMTList<TNomenclature>* GetVNom(){return &vNom;};
    TMTList<TMyObject>* GetVObjects(){return &vObj;};
    TMDelTList< TMDelTList< TMDelTList<AnsiString> > >* GetVData(){return &vData;};
public:
    void ProcessAddField(   const AnsiString& FieldName,
                            int Type,
                            const AnsiString& Meters,
                            int Digits,
                            bool Visible,
                            bool Accumulate,
                            bool Total);

    int ProcessAddObject(TMyObject *Sender);
    int ProcessAddNomenclature(TNomenclature* Nom);

    AnsiString* Iterate(TMyObject* Sender,
                        TNomenclature* Nom,
                        const AnsiString& FieldName,
                        const AnsiString& KeyField,
                        const AnsiString& KeyValue,
                        bool ByKeyValue);

    bool ProcessUpdateField(    TMyObject *Sender,
                                TNomenclature * Nom,
                                const AnsiString& FieldName,
                                const AnsiString& NewData,
                                bool Add);

    bool ProcessUpdateFieldByValue( TMyObject *Sender,
                                    TNomenclature * Nom,
                                    const AnsiString& FieldName,
                                    const AnsiString& NewData,
                                    bool Add,
                                    const AnsiString& KeyField,
                                    const AnsiString& KeyData);

    __property TMDelTList<TLuaAttribute> *Fields = {read = GetVFields};
    __property TMDelTList<TFieldEx> *FieldExs = {read = GetVFieldExs};
    __property TMTList<TNomenclature> *Nomenclature = {read = GetVNom};
    __property TMTList<TMyObject> *Objects = {read = GetVObjects};
    //first by object, second by nomemclature, third by field
    __property TMDelTList< TMDelTList< TMDelTList<AnsiString> > >*Data = {read = GetVData};

    TMDelTList<TLuaAttribute> vFields;
    TMDelTList<TFieldEx> vFieldExs;
    TMTList<TNomenclature> vNom;
    TMTList<TMyObject> vObj;
    //first by object, second by nomemclature, third by field
    TMDelTList< TMDelTList< TMDelTList<AnsiString> > > vData ;

    TCounterBase();
    virtual ~TCounterBase();

    void DefineField(char *FieldName,int Type,char* Meter,int Digit,bool Visible,bool Accumulate, bool Total);
    bool FieldExists(char *FieldName);
    //--------------------------------------------------------------------------
    bool SetData(TMyObject *Sender,TNomenclature * Nom,char* FieldName,char* Data);
    bool AddData(TMyObject *Sender,TNomenclature * Nom,char* FieldName,char* Data);

    bool SetDataByValue(TMyObject *Sender,TNomenclature * Nom,char* FieldName,char* Data,char* KeyField,char* KeyData);
    bool AddDataByValue(TMyObject *Sender,TNomenclature * Nom,char* FieldName,char* Data,char* KeyField,char* KeyData);

    void Clear();
    AnsiString GetSum(int i0,int j0,int k0,bool Round);
    char* GetSum(TMyObject *Sender,TNomenclature * Nom,char* FieldName,bool Round);
    AnsiString GetSumByNomFilter(TMyRegObject* Parent,int i0,int k0,bool Round);
    char* GetSumByNomFilter(TMyRegObject* Parent,TMyObject *Sender,char* FieldName,bool Round);

    bool ShowImages;
    int CountMode;
    int GetVisibleFieldCount();
    void ForceCount();
};

extern TCounterBase* Counter;


#endif
