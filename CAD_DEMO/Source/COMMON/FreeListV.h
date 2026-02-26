// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef FreeListVH
#define FreeListVH
//---------------------------------------------------------------------------
#include "ListV.h"

template <class T>
class /**/ TMDelTList : public TMTList<T>{
protected:
    void RegisterItem(T* Item);
    void UnRegisterItem(T* Item);
    static int FSimpleType;
    virtual int GetSimpleType() const;
public:
    static /**/ TClassNode* StaticType;
    TMDelTList();
	virtual ~TMDelTList();
    static TMyObject* CreateFunction();
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
/*extern */ int TMDelTList<T>::FSimpleType = mtNotDefined;

template <class T>
/*extern */ TClassNode* TMDelTList<T>::StaticType = NULL;

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
    int mt = this->GetSimpleType();
    if ( mt == mtMyObject || mt == mtMyRegObject)
        ((TMyObject*)Item)->SetMyObjectParentProp(this);
    else if ( mt == mtIntVec )
        ((TIntVec*)Item)->MyObjectParent = this;
}

template <class T>
void TMDelTList<T>::UnRegisterItem(T* Item)
{
    _TRY_
    {
        int mt = this->GetSimpleType();
        if ( (mt == mtMyObject || mt == mtMyRegObject) && ((TMyObject*)Item)->GetMyObjectParentProp() == this)
            ((TMyObject*)Item)->SetMyObjectParentProp(nullptr);
        else if ( mt == mtIntVec && ((TIntVec*)Item)->MyObjectParent == this )
            ((TIntVec*)Item)->MyObjectParent = nullptr;
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
    this->AboutToChange(this);
    int retval = TMTList<T>::Add(It);
    RegisterItem(It);
    return retval;
}

template <class T>
void TMDelTList<T>::Insert(int index,T* Item)
{
    this->AboutToChange(this);
    TMTList<T>::Insert(index,Item);
    RegisterItem(Item);
}


template <class T>
void TMDelTList<T>::Delete(int i)
{
    this->AboutToChange(this);
    this->Direct_Iterate(i);
    UnRegisterItem(this->FCurrent->Data);
    this->KillValue( this->FCurrent->Data );
    this->DeleteCurrent();
}

template <class T>
void TMDelTList<T>::RealDelete(int i)
{
    Delete(i);
}

template <class T>
void TMDelTList<T>::RemoveOnly(T* it)
{
    this->AboutToChange(this);
    UnRegisterItem(it);
    TMTList<T>::Remove(it);
}

template <class T>
void TMDelTList<T>::RemoveOnly(int index)
{
    this->AboutToChange(this);
    this->Direct_Iterate(index);
    UnRegisterItem(this->FCurrent->Data);
    this->DeleteCurrent();
}

template <class T>
int TMDelTList<T>::Remove( T* it)
{
    this->AboutToChange(this);
    if (this->Find(it))
    {
        int result = this->FCurrentIndex;
        UnRegisterItem(this->FCurrent->Data);
        this->KillValue( this->FCurrent->Data );
        this->DeleteCurrent();
        return result;
    }
    return -1;
}

template <class T>
void TMDelTList<T>::SetItem(int id, T* newit)
{
    this->AboutToChange(this);
    this->Direct_Iterate(id);
    UnRegisterItem(this->FCurrent->Data);
    this->FCurrent->Data = newit;
    RegisterItem(this->FCurrent->Data);
}

template <class T>
void TMDelTList<T>::SetCount(int aCount)
{
    while (this->FCount>aCount)
        Delete(this->FCount-1);
    while (this->FCount<aCount)
        Add(new T());
}

template <class T>
void TMDelTList<T>::Clear()
{
    this->AboutToChange(this);
    while(this->FCount)
        Delete(0);
}

template <class T>
void TMDelTList<T>::Invert()
{
    this->AboutToChange(this);
    TMTList<T> *L = new TMTList<T>();
    for (int i=0;i<this->GetCount();i++)
        L->Add(this->GetItem(i));
    TMTList<T>::Clear();
    for (int i=L->GetCount()-1;i>=0;i--)
        Add(L->GetItem(i));
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
    this->AboutToChange(this);
    while (this->FCount)
        RemoveOnly(0);
}

template <class T>
TMDelTList<T>& TMDelTList<T>::operator= (TMDelTList<T>& ML)
{
    this->AboutToChange(this);
    Assign(&ML);
    return *this;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
template <class T>
void TMDelTList<T>::Assign(TMyObject* MO)
{
    this->AboutToChange(this);
    if ( typeid(*MO)!=typeid(*this) )
        throw EMyException("Attempt to assign wrong type.");
    TMDelTList<T>* L = (TMDelTList<T>*)MO;

    int mtid = GetSimpleType();
    switch (mtid)
    {
        case  mtMyObject:
        {
            Clear();
            for (int i=0;i<L->GetCount();i++)
            {
                Add( (T*)((TMyObject*)L->GetItem(i))->DynamicType->CreateFunction() );
                ((TMyObject*)this->Last())->Assign((TMyObject*)L->GetItem(i));
            }
        }
        break;
        default:
        {
            Clear();
            for (int i=0;i<L->GetCount();i++)
            {
                Add(new T());
                CopyType(mtid,this->GetItem(i),L->GetItem(i));
            }
        }
    }
}


#endif
