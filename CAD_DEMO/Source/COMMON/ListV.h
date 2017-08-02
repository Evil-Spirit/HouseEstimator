//---------------------------------------------------------------------------

#ifndef ListVH
#define ListVH
#include "ContainerV.h"
//---------------------------------------------------------------------------
template <class T>
class /*PACKAGE*/ TMListItem{
public:
    TMListItem(){};
    virtual ~TMListItem(){};
    TMListItem *Next;
    TMListItem *Prev;
    T* Data;
};

typedef void (*TDoSomeThing)(void* Obj);

template <class T>
class /*PACKAGE*/ TMTList : public TContainer<T>{
protected:
    int FCount;
    mutable int FCurrentIndex;
    mutable TMListItem<T> *FCurrent;
    static int FSimpleType;
    TMListItem<T> *FFirst;
    TMListItem<T> *FLast;
    void AddFirst(T* It);
    
    virtual int GetSimpleType() const;
    void AboutToChangeSimpleType();

    //---------------------------
    bool Direct_IndexOK(int i) const;
    void Direct_Iterate(int i) const;
    void Direct_DoNext() const;
    void Direct_DoPrev() const;
    void Direct_DoFirst() const;
    void Direct_DoLast() const;

    //--------------------------
    void DeleteCurrent();
    bool Find(const T* It) const;
    void KillValue(T* value);
public:
    static /*PACKAGE*/ TClassNode* StaticType;
    TMTList();
    TMyObject* CreateFunction();
	virtual ~TMTList();

    //acessing routin
    int GetCount() const {return FCount;} ;
    const T* GetItem(int i) const;
    T* GetItem(int i);
    T* GetCycleItem(int i);
    const T* GetCycleItem(int i) const;
    const T& Val(int i) const;
    T& Val(int i);
    const T& CycVal(int i) const;
    T& CycVal(int i);
    T* GetCurrent();
    __property int CurrentIndex = {read = FCurrentIndex};

    const T* GetCurrent() const;
    T& GetValCurrent();
    const T& GetValCurrent() const;

    const T& operator [](int i) const;
    T& operator [](int i);

    T* Last();
    const T* Last() const;
    T* First();
    const T* First() const;
    __property T* Items[int i] = {read = GetItem,write = SetItem};
    __property T* CycleItems[int i] = {read = GetCycleItem};
    __property int Count = {read = FCount};
    //последовательный доступ
    bool Next() const;
    bool Prev() const;
    bool Start() const;
    bool End() const;
    __property T* Current = {read = GetCurrent};
    __property T& CurVal = {read = GetValCurrent};
    void ForEachIndex(TDoSomeThing DoSomeThing);

    //add-remove routine
    virtual int Add(T* It);
    virtual void Insert(int index,T* Item);
    virtual void Delete(int i);
    virtual int Remove( T* Item);
    virtual void RealDelete(int i);
    virtual void SetItem(int id, T* newit);

    virtual void Clear();
    void RealClear();
    virtual void Assign (  TMyObject* MO);
    TMTList<T>& operator = (TMTList<T>& ML);

    int IndexOf(const T* It) const;
    bool Exists(const T* It) const;
    virtual bool Consists( const TMTList<T> *L) const;
    virtual bool Same ( const TMTList<T> *L) const;

    void Exchange(int i1,int i2);
    void Move(int ifrom,int idest);
    virtual void Invert();
    int DirectInsertIndex(T* VAL,int Count,TMyCompareProc Proc);
    void Sort(TMyCompareProc Proc);

};

template <class T>
/*extern PACKAGE*/ TClassNode* TMTList<T>::StaticType = NULL;
template <class T>
int TMTList<T>::FSimpleType = mtNotDefined;

template <class T>
int TMTList<T>::GetSimpleType() const
{
    if (FSimpleType == mtNotDefined)
    {
        FSimpleType = MYSIMPLETYPE(typeid(T));
        if (FSimpleType == mtMyRegObject)
            FSimpleType = mtMyObject;
    }
    return FSimpleType;
}

template <class T>
void TMTList<T>::KillValue(T* Value)
{
    if ( GetSimpleType() == mtMyObject)
        ((TMyObject*)Value)->KillFunction();
    else
        delete Value;
}

template <class T>
void TMTList<T>::AboutToChangeSimpleType()
{
    int mt = GetSimpleType();
    if ( mt != mtIntVec && mt < mtMyObject)
        AboutToChange(this);
}


template <class T>
TMyObject* TMTList<T>::CreateFunction()
{
    return new TMTList<T>();
}

template <class T>
void TMTList<T>::RealClear()
{
    AboutToChange(this);
    while(FCount)
        RealDelete(0);
}

template <class T>
void TMTList<T>::RealDelete(int idx)
{
    AboutToChange(this);
    Direct_Iterate(idx);
    KillValue(FCurrent->Data);
    DeleteCurrent();
}


template <class T>
void TMTList<T>::Sort(TMyCompareProc Proc)
{
    AboutToChange(this);
    int InsertIndex;
    for (int i=1;i<FCount;i++)
    {
        InsertIndex = DirectInsertIndex(Items[i],i,Proc);
        if (InsertIndex != i)
            Move(i,InsertIndex);
    }
}

template <class T>
int TMTList<T>::DirectInsertIndex(T *VAL,int _Count,TMyCompareProc Proc)
{
    for (int i=0;i<_Count;i++)
        if (Proc(Items[i],VAL))
            return i;
    return _Count;
}

template <class T>
void TMTList<T>::ForEachIndex(TDoSomeThing DoSomeThing)
{
    AboutToChangeSimpleType();
    if (Count==0)
        return;
    TMListItem<T>* IT = FFirst;
    do
    {
        DoSomeThing(IT->Data);
        IT = IT->Next;
    }
    while(IT);
}

template <class T>
T* TMTList<T>::GetCurrent()
{
    AboutToChangeSimpleType();
    if (FCurrent)
        return FCurrent->Data;
    else

         throw EMyException("The list is empty.");
}

template <class T>
const T* TMTList<T>::GetCurrent() const
{
    if (FCurrent)
        return FCurrent->Data;
    else
        throw EMyException("The list is empty.");
}

template <class T>
T& TMTList<T>::GetValCurrent()
{
    AboutToChangeSimpleType();
    return *GetCurrent();
}

template <class T>
const T& TMTList<T>::GetValCurrent() const
{
    return *GetCurrent();
}

template <class T>
bool TMTList<T>::Next() const
{
    if (FCurrent->Next)
    {
        Direct_DoNext();
        return true;
    }
    else
        return false;
}

template <class T>
bool TMTList<T>::Prev() const
{
    if (FCurrent->Prev)
    {
        Direct_DoPrev();
        return true;
    }
    else
        return false;
}

template <class T>
bool TMTList<T>::Start() const
{
    if (FCount>0)
    {
        Direct_DoFirst();
        return true;
    }
    else
        return false;
}

template <class T>
bool TMTList<T>::End() const
{
    if (FCount>0)
    {
        Direct_DoLast();
        return true;
    }
    else
        return false;
}

template <class T>
void TMTList<T>::Assign (  TMyObject* MO)
{
    AboutToChange(this);
    if ( MO)//  typeid(*MO) == typeid(TMTList<T>)
        //|| typeid(*MO) == typeid(TMDelTList<T>) )
  //      || typeid(*MO) == typeid(TMDelLSTList<T>))
    {
        TMTList<T>* L = (TMTList<T>*)MO;
        Clear();
        for (int i=0;i<L->Count;i++)
            Add(L->Items[i]);
    }
    else
        throw EMyException("Assign incorrect type");
}

template <class T>
TMTList<T>& TMTList<T>::operator= (TMTList<T>& ML)
{
    AboutToChange(this);
    Assign(&ML);
    return *this;
}


template <class T>
bool TMTList<T>::Consists( const TMTList<T> *L) const
{
    for (int i=0;i<L->Count;i++)
        if (IndexOf(L->Items[i])==-1)
            return false;
    return true;
}

template <class T>
bool TMTList<T>::Same ( const TMTList<T> *L) const
{
    return( Consists(L)&&L->Consists(this) );
}

template <class T>
void TMTList<T>::Invert()
{
    AboutToChange(this);
    TMTList<T> *L = new TMTList<T>();
    L->Assign(this);
    Clear();
    for (int i=L->Count-1;i>=0;i--)
        Add(L->Items[i]);
    delete L;
}


template <class T>
TMTList<T>::TMTList()
{
    //--------------------------------------------------------------
    RegisterNewClass< TContainer<T>,TMTList<T> >(this,false,&(CreateFunction));
    //--------------------------------------------------------------
    FCurrentIndex = -1;
    FCount = 0;
    FCurrent = NULL;
    FFirst = NULL;
    FLast = NULL;
}

template <class T>
void TMTList<T>::AddFirst(T* It)
{
    AboutToChange(this);
    TMListItem<T>* LI = new TMListItem<T>();
    LI->Data = It;
    LI->Prev = NULL;
    LI->Next = NULL;

    FFirst = LI;
    FLast = LI;
    FCurrentIndex = 0;
    FCurrent = LI;
    FCount=1;
}

template <class T>
int TMTList<T>::Add(T* It)
{
    AboutToChange(this);
    //RegisterItem(Item);
    if (FCount==0)
    {
        AddFirst(It);
        return 0;
    }
    else
    {
        TMListItem<T>* LI = new TMListItem<T>();
        LI->Data = (T*)It;
        LI->Prev = FLast;
        FLast->Next = LI;
        LI->Next = NULL;
        FLast = LI;
        FCount++;
        return FCount-1;
    }
}

template <class T>
bool TMTList<T>::Direct_IndexOK(int i) const
{
    if (i>=0 && i<FCount)
        return true;
    else
    {
            AnsiString STR = AnsiString("<")+DynamicType->Name+AnsiString(">: ");
            STR = STR+ AnsiString("Index is out of list range, Size - ");
            STR = STR+IntToStr(FCount)+AnsiString(", Index - ");
            STR = STR+IntToStr(i);
            throw EMyException(STR);
    }
}

template <class T>
void TMTList<T>::Direct_Iterate(int i) const
{
    if (i<0 || i >= FCount)
    {
        AnsiString STR = AnsiString("<")+DynamicType->Name+AnsiString(">: ");
        STR = STR+ AnsiString("Index is out of list range, Size - ");
        STR = STR+IntToStr(FCount)+AnsiString(", Index - ");
        STR = STR+IntToStr(i);
        throw EMyException(STR);
    }
    else if (FCurrentIndex == i)
        return;
    else if (i == 0)
    {
        FCurrentIndex = 0;
        FCurrent = FFirst;
    }
    else if ( i == FCount-1)
    {
        FCurrentIndex = FCount-1;
        FCurrent = FLast;
    }
    else
    {
        while (FCurrentIndex<i)
        {
            FCurrent = FCurrent->Next;
            FCurrentIndex++;
        }
        while (FCurrentIndex>i)
        {
            FCurrent = FCurrent->Prev;
            FCurrentIndex--;
        }
    }
}

template <class T>
void TMTList<T>::Direct_DoNext() const
{
    FCurrent = FCurrent->Next;
    FCurrentIndex++;
}

template <class T>
void TMTList<T>::Direct_DoPrev() const
{
    FCurrent = FCurrent->Prev;
    FCurrentIndex--;
}

template <class T>
void TMTList<T>::Direct_DoFirst() const
{
    FCurrentIndex = 0;
    FCurrent = FFirst;
}

template <class T>
void TMTList<T>::Direct_DoLast() const
{
    FCurrentIndex = FCount-1;
    FCurrent = FLast;
}

template <class T>
T* TMTList<T>::GetItem(int idx)
{
    AboutToChangeSimpleType();

    Direct_Iterate(idx);
    return FCurrent->Data;
}

template <class T>
const T* TMTList<T>::GetItem(int idx) const
{
    Direct_Iterate(idx);
    return FCurrent->Data;
}

template <class T>
T& TMTList<T>::Val(int i)
{
    AboutToChangeSimpleType();
    Direct_Iterate(i);
    return *(FCurrent->Data);
}

template <class T>
const T& TMTList<T>::Val(int i) const
{
    Direct_Iterate(i);
    return *(FCurrent->Data);
}

template <class T>
T* TMTList<T>::GetCycleItem(int i)
{
    AboutToChangeSimpleType();
    while (i>=FCount)
        i -= FCount;
    while (i<0)
        i += FCount;
    Direct_Iterate(i);
    return FCurrent->Data;
}

template <class T>
const T* TMTList<T>::GetCycleItem(int i) const
{
    while (i>=FCount)
        i -= FCount;
    while (i<0)
        i += FCount;
    Direct_Iterate(i);
    return FCurrent->Data;
}

template <class T>
T& TMTList<T>::CycVal(int i)
{
    AboutToChangeSimpleType();
    return *(GetCycleItem(i));
}

template <class T>
const T& TMTList<T>::CycVal(int i) const
{
    return *(GetCycleItem(i));
}

template <class T>
T& TMTList<T>::operator [](int i)
{
    AboutToChangeSimpleType();
    Direct_Iterate(i);
    return *(FCurrent->Data);
}

template <class T>
const T& TMTList<T>::operator [](int i) const
{
    Direct_Iterate(i);
    return *(FCurrent->Data);
}


template <class T>
void TMTList<T>::SetItem(int idx, T* newit)
{
    AboutToChange(this);
    Direct_Iterate(idx);
    FCurrent->Data = newit;
}

template <class T>
void TMTList<T>::Delete(int idx)
{
    AboutToChange(this);
    Direct_Iterate(idx);
    DeleteCurrent();
}


template <class T>
void TMTList<T>::DeleteCurrent()
{
    TMListItem<T> *Item  = FCurrent;
    if (Item->Next && Item->Prev)
    {
        FCurrent = FCurrent->Next;
        Item->Prev->Next = Item->Next;
        Item->Next->Prev = Item->Prev;
    }
    else if (Item->Next)
    {
        FCurrent = FCurrent->Next;
        FFirst = FCurrent;
        Item->Next->Prev = NULL;
    }
    else if (Item->Prev)
    {
        Direct_DoPrev();
        FLast = FCurrent;
        Item->Prev->Next = NULL;
    }
    else
    {
        FLast = NULL;
        FCurrent = NULL;
        FFirst = NULL;
        FCurrentIndex = -1;
    }
    delete Item;
    FCount--;
}

template <class T>
TMTList<T>::~TMTList<T>()
{
    Clear();
}

template <class T>
int TMTList<T>::IndexOf(const T* It) const
{
    if (Find(It))
        return FCurrentIndex;
    else
        return -1;
}

template <class T>
bool TMTList<T>::Exists(const T* It) const
{
    return (IndexOf(It)!=-1);
}

template <class T>
void TMTList<T>::Clear()
{
    AboutToChange(this);
    if (FCount)
    {
        Direct_DoFirst();
        while (FCount)
            DeleteCurrent();
    }
}

template <class T>
void TMTList<T>::Insert(int index,T* Item)
{
    AboutToChange(this);
    if (FCount == 0 || index == FCount)
        Add(Item);
    else
    {
        Direct_Iterate(index);
        TMListItem<T>* LI = new TMListItem<T>();
        LI->Data = (T*)Item;
        LI->Next = FCurrent;
        LI->Prev = NULL;
        if (FCurrent->Prev)
        {
            LI->Prev = FCurrent->Prev;
            FCurrent->Prev->Next = LI;
        }
        else
            FFirst = LI;
        FCurrent->Prev = LI;
        FCurrent = LI;
        FCount++;
    }
}

template <class T>
bool TMTList<T>::Find(const T* It) const
{
    if (!FCount)
        return false;
    Direct_DoFirst();
    if (FCurrent->Data == It)
        return true;
    if (FCount==1)
        return false;
    do
    {
        Direct_DoNext();
        if (FCurrent->Data == It)
            return true;
    }
    while (FCurrentIndex<FCount-1);
    return false;
}

template <class T>
int TMTList<T>::Remove( T* Item)
{
    AboutToChange(this);
    if (Find(Item))
    {
        int result = FCurrentIndex;
        DeleteCurrent();
        return result;
    }
    return -1;
}

template <class T>
T* TMTList<T>::Last()
{
    AboutToChangeSimpleType();
    Direct_IndexOK(FCount-1);
    Direct_DoLast();
    return FCurrent->Data;
}

template <class T>
const T* TMTList<T>::Last() const
{
    Direct_IndexOK(FCount-1);
    Direct_DoLast();
    return FCurrent->Data;
}

template <class T>
T* TMTList<T>::First()
{
    AboutToChangeSimpleType();
    Direct_IndexOK(0);
    Direct_DoFirst();
    return FCurrent->Data;
}

template <class T>
const T* TMTList<T>::First() const
{
    Direct_IndexOK(0);
    Direct_DoFirst();
    return FCurrent->Data;
}

template <class T>
void TMTList<T>::Exchange(int i1,int i2)
{
    AboutToChange(this);
  TMListItem<T> *P1;
  TMListItem<T> *P2;
  T* P0;

  Direct_Iterate(i1);
  P1=FCurrent;;
  Direct_Iterate(i2);
  P2=FCurrent;;

  P0 = P1->Data;
  P1->Data = P2->Data;
  P2->Data = P0;

}

template <class T>
void TMTList<T>::Move(int ifrom,int idest)
{
    AboutToChange(this);
  T* P0;
  P0 = Items[ifrom];
  DeleteCurrent();
  Insert(idest,P0);
}


#endif
