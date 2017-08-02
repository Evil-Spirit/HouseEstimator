//---------------------------------------------------------------------------

#ifndef LinearListH
#define LinearListH

#include "ContainerV.h"
//---------------------------------------------------------------------------

typedef void (*TDoSomeThing)(void* Obj);

template <class T>
class TLList : public TContainer<T>{
private:
	T** FList;
protected:
	int FCapacity;	
	
	//---------------------------	
	int FCount;
	static int FSimpleType;
	virtual int GetSimpleType() const;
	void AboutToChangeSimpleType();

	//--------------------------
	bool Direct_IndexOK(int i) const;

	//--------------------------
	void KillValue(T* value);
public:		
	static TClassNode* StaticType;
	TLList();
	TMyObject* CreateFunction();
	virtual ~TLList();

	//acessing routin
	int GetCount() const {return FCount;};
	void SetCount(int NewCount);
	
	const T* GetItem(int i) const;
	T* GetItem(int i);
	T* GetCycleItem(int i);
	const T* GetCycleItem(int i) const;

	const T& Val(int i) const;
	T& Val(int i);
	const T& CycVal(int i) const;
	T& CycVal(int i);

	const T& operator [](int i) const;
	T& operator [](int i);

	T* Last();
	const T* Last() const;
	T* First();
	const T* First() const;
	__property T* Items[int i] = {read = GetItem,write = SetItem};
	__property T* CycleItems[int i] = {read = GetCycleItem};
	__property int Count = { read = GetCount, write = SetCount};
	
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
	TLList<T>& operator = (TLList<T>& ML);

	int IndexOf(const T* It) const;
	bool Exists(const T* It) const;
	virtual bool Consists( const TLList<T> *L) const;
	virtual bool Same ( const TLList<T> *L) const;

	void Exchange(int i1, int i2);
	void Move(int ifrom, int idest);
	virtual void Invert();
	int DirectInsertIndex(T* VAL,int Count,TMyCompareProc Proc);
	void Sort(TMyCompareProc Proc);
	
	//--------------------------
	void Grow();
	void SetCapacity(int NewCapacity);
	void Pack();
	__property int Capacity = { read = FCapacity, write = SetCapacity};
	__property T** List = { read = FList };
};

template <class T>
TClassNode* TLList<T>::StaticType = NULL;

template <class T>
int TLList<T>::FSimpleType = mtNotDefined;

template <class T>
TLList<T>::TLList()
{
	//--------------------------------------------------------------
	RegisterNewClass< TContainer<T>,TLList<T> >(this, false, &CreateFunction);
	//--------------------------------------------------------------
	FCount = 0;
	FCapacity = 0;
	FList = NULL;
}

template <class T>
TMyObject* TLList<T>::CreateFunction()
{
	return new TLList<T>();
}

template <class T>
TLList<T>::~TLList<T>()
{
	Clear();
}

template <class T>
void TLList<T>::SetCount(int NewCount)
{
	if ( NewCount < 0 )
	{
		AnsiString STR = AnsiString("<")+DynamicType->Name+AnsiString(">: ");
		STR = STR + AnsiString("Error while changing list size. Current size - ");
		STR = STR+IntToStr(NewCount);
		throw EMyException(STR);
	}
	if( NewCount > FCapacity )
		SetCapacity(NewCount);
	if( NewCount > FCount )
		setmem(FList+FCount, (NewCount - FCount) * sizeof(T*), 0);
	else
	for ( int i = FCount - 1; i >= 0; i-- )
		Delete(i);
	FCount = NewCount;
}

template <class T>
T* TLList<T>::GetItem(int idx)
{
	AboutToChangeSimpleType();
	Direct_IndexOK(idx);
	return FList[idx];
}

template <class T>
const T* TLList<T>::GetItem(int idx) const
{
	Direct_IndexOK(idx);
	return FList[idx];
}

template <class T>
T& TLList<T>::Val(int i)
{
	AboutToChangeSimpleType();
	Direct_IndexOK(i);
	return *(FList[i]);
}

template <class T>
const T& TLList<T>::Val(int i) const
{
	Direct_IndexOK(i);
	return *(FList[i]);
}

template <class T>
T* TLList<T>::GetCycleItem(int i)
{
	AboutToChangeSimpleType();
	while (i>=FCount)
		i -= FCount;
	while (i<0)
		i += FCount;
	return FList[i];
}

template <class T>
const T* TLList<T>::GetCycleItem(int i) const
{
	while (i>=FCount)
		i -= FCount;
	while (i<0)
		i += FCount;
	return FList[i];
}

template <class T>
T& TLList<T>::CycVal(int i)
{
	AboutToChangeSimpleType();
	return *(GetCycleItem(i));
}

template <class T>
const T& TLList<T>::CycVal(int i) const
{
	return *(GetCycleItem(i));
}

template <class T>
T& TLList<T>::operator [](int i)
{
	AboutToChangeSimpleType();
	Direct_IndexOK(i);
	return *(FList[i]);
}

template <class T>
const T& TLList<T>::operator [](int i) const
{
	Direct_IndexOK(i);
	return *(FList[i]);
}

template <class T>
T* TLList<T>::Last()
{
	AboutToChangeSimpleType();
	Direct_IndexOK(FCount-1);
	return FList[FCount-1];
}

template <class T>
const T* TLList<T>::Last() const
{
	Direct_IndexOK(FCount-1);
	return FList[FCount-1];
}

template <class T>
T* TLList<T>::First()
{
	AboutToChangeSimpleType();
	Direct_IndexOK(0);
	return FList[0];
}

template <class T>
const T* TLList<T>::First() const
{
	Direct_IndexOK(0);
	return FList[0];
}

template <class T>
void TLList<T>::ForEachIndex(TDoSomeThing DoSomeThing)
{
	AboutToChangeSimpleType();
	if (Count==0)
		return;
	for ( int i = 0; i < Count; i++ )
		DoSomeThing(FList[i]);
}

template <class T>
int TLList<T>::Add(T* It)
{
	AboutToChange(this);	
	int res = FCount;
	if ( res == FCapacity )
		Grow();
	FList[res] = (T*)It;
	FCount++;
	return res;
}

template <class T>
void TLList<T>::Insert(int index, T* Item)
{
	AboutToChange(this);
	Direct_IndexOK(index);
	if ( FCount == FCapacity )
		Grow();
	if ( index < FCount )
		memmove(FList+index+1, FList+index, (FCount - index) * sizeof(T*));
	FList[index] = Item;
	FCount++;
}

template <class T>
void TLList<T>::Delete(int Index)
{
	Direct_IndexOK(Index);
	FCount--;
	if ( Index < FCount )
		memmove(FList+Index, FList+Index+1, (FCount - Index) * sizeof(T*));
}

template <class T>
int TLList<T>::Remove(T* Item)
{
	AboutToChange(this);
	int Index = IndexOf(Item);
	if ( Index >= 0 )
		Delete(Index);
	return Index;
}

template <class T>
void TLList<T>::RealDelete(int idx)
{
	AboutToChange(this);
	Direct_IndexOK(idx);
	KillValue(FList[idx]);
	Delete(idx);
}

template <class T>
void TLList<T>::SetItem(int idx, T* newit)
{
	AboutToChange(this);
	Direct_IndexOK(idx);
	if ( newit != FList[idx] )
		FList[idx] = newit;
}

template <class T>
void TLList<T>::Clear()
{
	AboutToChange(this);
	if (FCount)
	{
		SetCount(0);
		SetCapacity(0);
	}
}

template <class T>
void TLList<T>::RealClear()
{
	AboutToChange(this);
	while(FCount)
		RealDelete(0);
}

template <class T>
void TLList<T>::Assign( TMyObject* MO )
{
	AboutToChange(this);
	if ( MO )
	{
		TLList<T>* L = (TLList<T>*)MO;
		Clear();
		for ( int i = 0; i < L->Count; i++ )
			Add( L->Items[i] );
	}else
		throw EMyException("Assign incorrect type");
}

template <class T>
TLList<T>& TLList<T>::operator = (TLList<T>& ML)
{
	AboutToChange(this);
	Assign(&ML);
	return *this;
}

template <class T>
int TLList<T>::IndexOf( const T* Item) const
{
	int Index = 0;
	while (Index < FCount && FList[Index] != Item)
		Index++;
	if ( Index == FCount )
		return -1;
	else
		return Index;
}

template <class T>
bool TLList<T>::Exists( const T* It) const 
{
	return (IndexOf(It)!=-1);
}

template <class T>
bool TLList<T>::Consists( const TLList* L) const
{
	for ( int i = 0; i < L->Count; i++ )
		if ( IndexOf(L->Items[i]) == -1 )
			return false;
	return true;
}

template <class T>
bool TLList<T>::Same ( const TLList* L) const
{
	return( Consists(L)&&L->Consists(this) );
}

template <class T>
void TLList<T>::Exchange(int Index1, int Index2)
{
	AboutToChange(this);
	Direct_IndexOK(Index1);
	Direct_IndexOK(Index2);
	T* Item = FList[Index1];
	FList[Index1] = FList[Index2];
	FList[Index2] = Item;
}

template <class T>
void TLList<T>::Move(int CurIndex, int NewIndex)
{
	AboutToChange(this);
	if ( CurIndex == NewIndex )
		return;
	Direct_IndexOK(NewIndex);
	T* Item = GetItem(CurIndex);
	FList[CurIndex] = NULL;
	Delete(CurIndex);
	Insert(NewIndex, NULL);
	FList[NewIndex] = Item;
}

template <class T>
void TLList<T>::Invert()
{
	AboutToChange(this);
	TLList<T> *L = new TLList<T>();
	L->Assign(this);
	Clear();
	for ( int i = L->Count - 1; i >= 0; i-- )
		Add(L->Items[i]);
	delete L;
}

template <class T>
int TLList<T>::DirectInsertIndex(T *VAL, int _Count, TMyCompareProc Proc)
{
	for ( int i = 0; i < _Count; i+ +)
		if (Proc(Items[i],VAL))
			return i;
	return _Count;
}

template <class T>
void TLList<T>::Sort(TMyCompareProc Proc)
{
	AboutToChange(this);
	int InsertIndex;
	for ( int i = 1; i < FCount; i++)
	{
		InsertIndex = DirectInsertIndex(Items[i], i, Proc);
		if (InsertIndex != i)
			Move(i, InsertIndex);
	}
}

template <class T>
void TLList<T>::Grow()
{
	AboutToChange(this);
	int Delta;
	if ( FCapacity > 64 )
		Delta = FCapacity / 4;
	else
	if ( FCapacity > 8 )
		Delta = 16;
	else
		Delta = 4;
	SetCapacity(FCapacity + Delta);
}

template <class T>
void TLList<T>::SetCapacity(int NewCapacity)
{
	AboutToChange(this);
	if ( NewCapacity < FCount )
	{
		AnsiString STR = AnsiString("<")+DynamicType->Name+AnsiString(">: ");
		STR = STR + AnsiString("Error while expanding list size, current size - ");
		STR = STR + IntToStr(FCount)+AnsiString(", requested size - ");
		STR = STR + IntToStr(NewCapacity);
		throw EMyException(STR);
	}
	if ( NewCapacity != FCapacity)
	{
		FList = (T**)realloc((T*)FList, NewCapacity*sizeof(T*));
		FCapacity = NewCapacity;
	}
}

template <class T>
void TLList<T>::Pack()
{
	AboutToChange(this);
	for ( int i = FCount - 1; i >= 0; i-- )
		if ( Items[i] == NULL )
			Delete(i);
}

template <class T>
int TLList<T>::GetSimpleType() const
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
void TLList<T>::AboutToChangeSimpleType()
{
	int mt = GetSimpleType();
	if ( mt != mtIntVec && mt < mtMyObject)
		AboutToChange(this);
}

template <class T>
bool TLList<T>::Direct_IndexOK(int i) const
{
	if ( i >= 0 && i < FCount )
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
void TLList<T>::KillValue(T* Value)
{
	if ( GetSimpleType() == mtMyObject)
		((TMyObject*)Value)->KillFunction();
	else
		delete Value;
}
#endif
