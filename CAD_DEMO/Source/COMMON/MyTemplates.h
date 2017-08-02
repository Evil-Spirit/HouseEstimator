//---------------------------------------------------------------------------


#ifndef MyTemplatesH
#define MyTemplatesH
//#include "RegisterModule.h"
#include "FreeListV.h"


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//#define GetOldBase
const AnsiString aTargetGUID = AnsiString("TargetGUID");

template <class T>
class /*PACKAGE*/ TPointer :public TMyObject {
private:
#ifdef GetOldBase
    int ID;
    int Table;
#endif
    AnsiString FTargetGUID;
    T* FAdr;
    void SetAdr(T* newAdr);
    const AnsiString& GetTargetGUID() const;
public:
    static /*PACKAGE*/ TClassNode* StaticType;
    TMyObject* CreateFunction();
    TPointer();
    TPointer(T *adr);
    virtual ~TPointer(){};
    __property T* ADR = {read = FAdr,write = SetAdr};
    __property const AnsiString& TargetGUID = {read = GetTargetGUID};
    bool CheckFields();
    virtual void LookingTo(TMyObject * Target,TMTList<TMyObject>& OBJL) const;
    const std::type_info & Type() const {return typeid(T);}
};

template <class T>
TClassNode* TPointer<T>::StaticType = NULL;

#ifdef GetOldBase
const AnsiString aID = AnsiString("ID");
const AnsiString aTable = AnsiString("Table");
#endif

template <class T>
TPointer<T>::TPointer(T *adr)
{
    RegisterNewClass< TMyObject,TPointer<T> >(this,false,&CreateFunction);
    FAdr = NULL;
#ifdef GetOldBase
    ID = -1;
    Table = -1;
    RegisterField(&ID,&aID,mtInt);
    RegisterField(&Table,&aTable,mtInt);
#endif
    RegisterField(&FTargetGUID,&aTargetGUID,mtString);

    ADR = adr;
}

template <class T>
TMyObject* TPointer<T>::CreateFunction()
{
    return new TPointer<T>();
}

template <class T>
TPointer<T>::TPointer()
{
    RegisterNewClass< TMyObject,TPointer<T> >(this,false,&CreateFunction);
    FAdr = NULL;
#ifdef GetOldBase
    ID = -1;
    Table = -1;
    RegisterField(&ID,&aID,mtInt);
    RegisterField(&Table,&aTable,mtInt);
#endif
    RegisterField(&FTargetGUID,&aTargetGUID,mtString);
}

template <class T>
const AnsiString& TPointer<T>::GetTargetGUID() const
{
    return FTargetGUID;
}

template <class T>
void TPointer<T>::SetAdr(T* newAdr)
{
    AboutToChange(this);
    FAdr = newAdr;
    if (FAdr)
    {
        ((TMyObject*)FAdr)->GenerateGUIDIfNeed();
        FTargetGUID = ((TMyObject*)FAdr)->GUID;
    }
    else
        FTargetGUID = AnsiString();
}

template <class T>
bool TPointer<T>::CheckFields()
{
    AboutToChange(this);
#ifdef GetOldBase
    FTargetGUID = IntToStr(Table)+IntToStr(ID);
#endif
    if ( FTargetGUID.AnsiCompare( AnsiString("-1-1")  )==0 )
        FTargetGUID = AnsiString();
    if (!FTargetGUID.IsEmpty())
        FAdr = (T*)FindByGUID( ClassHead->Find(typeid(T)) ,FTargetGUID);
    return true;
}

template <class T>
void TPointer<T>::LookingTo(TMyObject*Target,TMTList<TMyObject>& OBJL) const
{
    if ( Target->Is( TMyObject::StaticType ) )
        if ( !((TMyObject*)Target)->GUID.IsEmpty() && (FTargetGUID == ((TMyObject*)Target)->GUID) )
//            if ( ID == ((TMyRegObject*)Target)->ID)
                OBJL.Add((TMyObject*)this);
/*    if ( Target->Is( TMyRegObject::StaticType ) )
        if (Table == ((TMyRegObject*)Target)->Table)
            if ( ID == ((TMyRegObject*)Target)->ID)
                OBJL.Add((TMyObject*)this);*/
}

//------------------------------------------------------------------------------
template <class T>
class TMQueue {
protected:
    TMTList<T> FObjects;
    TMTList<T> FAddList;
    TMTList<T> FChangeList;
    TMTList<T> FRemoveList;
    int GetCount();
    bool FNeedRebuild;
    bool FGlobalEnabled;
    virtual void OnProcess(){};
    virtual void OnUpdate(){};
public:
    void CreateQueue();
    TMQueue();
    ~TMQueue();
    void Add(T* aObject);
    void Changed(T* aObject);
    void Remove(T* aObject);
    void Delete(int i);
    T* GetObject(int i);
    virtual void Clear();
    __property int Count = {read = GetCount};
    bool Enabled;
    void Process();
};
//------------------------------------------------------------------------------
template <class T>
TMQueue<T>::TMQueue()
{
    FGlobalEnabled = true;
    Enabled = true;
    FNeedRebuild = false;
}

template <class T>
TMQueue<T>::~TMQueue()
{
    Clear();
}

template <class T>
void TMQueue<T>::Changed(T* aObject)
{
    FChangeList.Add(aObject);
}

template <class T>
void TMQueue<T>::Add(T* aObject)
{
    FAddList.Add(aObject);
}

template <class T>
void TMQueue<T>::Remove(T* aObject)
{
    FRemoveList.Add(aObject);
}

template <class T>
void TMQueue<T>::Delete(int i)
{
    FRemoveList.Add( GetObject(i) );
}

template <class T>
void TMQueue<T>::Clear()
{
    FObjects.Clear();
    FAddList.Clear();
    FRemoveList.Clear();
    FChangeList.Clear();
}

template <class T>
void TMQueue<T>::CreateQueue()
{
    for (int i=0;i<FAddList.Count;i++)
        if (FObjects.IndexOf(FAddList.Items[i])==-1)
        {
            FObjects.Add(FAddList.Items[i]);
            FNeedRebuild = true;
        }
    for (int i=0;i<FRemoveList.Count;i++)
    {
        FObjects.Remove(FRemoveList.Items[i]);
        FNeedRebuild = true;
    }
    for (int i=0;i<FChangeList.Count;i++)
        if (FObjects.IndexOf(FChangeList.Items[i])!=-1)
    {
        FNeedRebuild = true;
        break;
    }
    FAddList.Clear();
    FRemoveList.Clear();
    FChangeList.Clear();
}

template <class T>
void TMQueue<T>::Process()
{
    CreateQueue();
    if (Enabled && FGlobalEnabled)
    {
        if (FNeedRebuild)
        {
            OnUpdate();
            FNeedRebuild = false;
        }
        OnProcess();
    }
}

template <class T>
T* TMQueue<T>::GetObject(int i)
{
    CreateQueue();
    return FObjects.Items[i];
}

template <class T>
int TMQueue<T>::GetCount()
{
    CreateQueue();
    return FObjects.Count;
}

//-----------------------------------------------------------




template <class T>
int FindInList(const TMTList<T>* List,const T& Value)
{
    int i=0;
    for (bool OK = List->Start();OK;OK = List->Next(),i++)
        if ( *(List->GetCurrent()) == Value )
            return i;
    return -1;
/*
    for (int i=0;i<List->Count;i++)
        if ( *(List->Items[i]) == Value )
            return i;
    return -1;
    */
}

template <class T>
int FindInPointerList(const TMDelTList<TPointer<T> >* List,const T* Adress)
{
    int i=0;
    for (bool OK = List->Start();OK;OK = List->Next(),i++)
        if ( List->GetCurrent()->ADR == Adress )
            return i;
    return -1;
}

template <class T>
void DeleteItem(TQuickList* List,int index)
{
    delete ((T*)List->Items[index]);
    List->Delete(index);
}

template <class T>
void KillList(TQuickList* List)
{
    while (List->Count)
        DeleteItem<T>(List,0);
}

#endif
