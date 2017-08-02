//---------------------------------------------------------------------------

#ifndef FreeListVH
#define FreeListVH
//---------------------------------------------------------------------------
#include "ListV.h"

template <class T>
class /*PACKAGE*/ TMDelTList : public TMTList<T>{
protected:
    void RegisterItem(T* Item);
    void UnRegisterItem(T* Item);
    static int FSimpleType;
    virtual int GetSimpleType() const;
public:
    static /*PACKAGE*/ TClassNode* StaticType;
    TMDelTList();
	virtual ~TMDelTList();
    TMyObject* CreateFunction();
    //add-remove routine
    virtual int Add(T* It);
    virtual void Insert(int index,T* Item);
    virtual void Delete(int i);
    virtual int Remove( T* it);
    void RemoveOnly( T* it);
    void RemoveOnly(int index);
    virtual void RealDelete(int i);
    virtual void SetItem(int id, T* newit);
    void SetCount(int Count);

    virtual void Clear();
    virtual void NoDelClear();
    virtual void Assign (  TMyObject* MO);
    TMDelTList<T>& operator= (TMDelTList<T>& ML);

    virtual void Invert();


    virtual bool Consists( const TMTList<T> *L) const;
    virtual bool Same (  const TMTList<T> *L) const;
};

template <class T>
/*extern PACKAGE*/ int TMDelTList<T>::FSimpleType = mtNotDefined;

template <class T>
/*extern PACKAGE*/ TClassNode* TMDelTList<T>::StaticType = NULL;

//------------------------------------------------------------------------------
template <class T>
int TMDelTList<T>::GetSimpleType() const
{
    if (FSimpleType == mtNotDefined)
    {
        T();
        FSimpleType = MYSIMPLETYPE(typeid(T));
        if (FSimpleType == mtMyRegObject)
            FSimpleType = mtMyObject;
    }
    return FSimpleType;
}

template <class T>
void TMDelTList<T>::RegisterItem(T* Item)
{
    int mt = GetSimpleType();
    if ( mt == mtMyObject || mt == mtMyRegObject)
        ((TMyObject*)Item)->MyObjectParent = this;
    else if ( mt == mtIntVec )
        ((TIntVec*)Item)->MyObjectParent = this;
}

template <class T>
void TMDelTList<T>::UnRegisterItem(T* Item)
{
    _TRY_
    {
        int mt = GetSimpleType();
        if ( (mt == mtMyObject || mt == mtMyRegObject) && ((TMyObject*)Item)->MyObjectParent == this)
            ((TMyObject*)Item)->MyObjectParent = NULL;
        else if ( mt == mtIntVec && ((TIntVec*)Item)->MyObjectParent == this )
            ((TIntVec*)Item)->MyObjectParent = NULL;
    }
    _ENDTRY_("<TMDelTList<T>::UnRegisterItem>: Child was destroyed before Unregister",);
}

template <class T>
TMDelTList<T>::TMDelTList()
{
    //-------------------------------------------------------------------
    RegisterNewClass< TMTList<T>,TMDelTList<T> >(this,false,&(CreateFunction));
    //-------------------------------------------------------------------
}

template <class T>
TMDelTList<T>::~TMDelTList()
{
    Clear();
}

template <class T>
TMyObject* TMDelTList<T>::CreateFunction()
{
    return new TMDelTList<T>();
}

template <class T>
int TMDelTList<T>::Add(T* It)
{
    AboutToChange(this);
    int retval = TMTList<T>::Add(It);
    RegisterItem(It);
    return retval;
}

template <class T>
void TMDelTList<T>::Insert(int index,T* Item)
{
    AboutToChange(this);
    TMTList<T>::Insert(index,Item);
    RegisterItem(Item);
}


template <class T>
void TMDelTList<T>::Delete(int i)
{
    AboutToChange(this);
    Direct_Iterate(i);
    UnRegisterItem(FCurrent->Data);
    KillValue( FCurrent->Data );
    DeleteCurrent();
}

template <class T>
void TMDelTList<T>::RealDelete(int i)
{
    Delete(i);
}

template <class T>
void TMDelTList<T>::RemoveOnly(T* it)
{
    AboutToChange(this);
    UnRegisterItem(it);
    TMTList<T>::Remove(it);
}

template <class T>
void TMDelTList<T>::RemoveOnly(int index)
{
    AboutToChange(this);
    Direct_Iterate(index);
    UnRegisterItem(FCurrent->Data);
    DeleteCurrent();
}

template <class T>
int TMDelTList<T>::Remove( T* it)
{
    AboutToChange(this);
    if (Find(it))
    {
        int result = FCurrentIndex;
        UnRegisterItem(FCurrent->Data);
        KillValue( FCurrent->Data );
        DeleteCurrent();
        return result;
    }
    return -1;
}

template <class T>
void TMDelTList<T>::SetItem(int id, T* newit)
{
    AboutToChange(this);
    Direct_Iterate(id);
    UnRegisterItem(FCurrent->Data);
    FCurrent->Data = newit;
    RegisterItem(FCurrent->Data);
}

template <class T>
void TMDelTList<T>::SetCount(int aCount)
{
    while (FCount>aCount)
        Delete(FCount-1);
    while (FCount<aCount)
        Add(new T());
}

template <class T>
void TMDelTList<T>::Clear()
{
    AboutToChange(this);
    while(FCount)
        Delete(0);
}

template <class T>
void TMDelTList<T>::Invert()
{
    AboutToChange(this);
    TMTList<T> *L = new TMTList<T>();
    for (int i=0;i<Count;i++)
        L->Add(Items[i]);
    TMTList<T>::Clear();
    for (int i=L->Count-1;i>=0;i--)
        Add(L->Items[i]);
    delete L;
}

template <class T>
bool TMDelTList<T>::Consists( const TMTList<T> *L) const
{
    throw EMyException("'Consists' is not implemented!");
}

template <class T>
bool TMDelTList<T>::Same ( const TMTList<T> *L) const
{
    throw EMyException("'Same' is not implemented!");
}

template <class T>
void TMDelTList<T>::NoDelClear ()
{
    AboutToChange(this);
    while (FCount)
        RemoveOnly(0);
}

template <class T>
TMDelTList<T>& TMDelTList<T>::operator= (TMDelTList<T>& ML)
{
    AboutToChange(this);
    Assign(&ML);
    return *this;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
template <class T>
void TMDelTList<T>::Assign(TMyObject* MO)
{
    AboutToChange(this);
    if ( typeid(*MO)!=typeid(*this) )
        throw EMyException("Attempt to assign wrong type.");
    TMDelTList<T>* L = (TMDelTList<T>*)MO;

    int mtid = GetSimpleType();
    switch (mtid)
    {
        case  mtMyObject:
        {
            Clear();
            for (int i=0;i<L->Count;i++)
            {
                Add( (T*)((TMyObject*)L->Items[i])->DynamicType->CreateFunction() );
                ((TMyObject*)Last())->Assign((TMyObject*)L->Items[i]);
            }
        }
        break;
        default:
        {
            Clear();
            for (int i=0;i<L->Count;i++)
            {
                Add(new T());
                CopyType(mtid,Items[i],L->Items[i]);
            }
        }
    }
}


#endif
