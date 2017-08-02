 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include <windows.h>
#include "MyTemplates.h"
#pragma hdrstop

#include "QuckList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
void* TQuickList::GetCurrent()
{
    if (FCurrent)
        return FCurrent->Data;
    else
        throw EMyException("The list is empty");
}

bool TQuickList::Next() const
{
    if (FCurrent->Next)
    {
        Direct_DoNext();
        return true;
    }
    else
        return false;
}

bool TQuickList::Prev() const
{
    if (FCurrent->Prev)
    {
        Direct_DoPrev();
        return true;
    }
    else
        return false;
}

bool TQuickList::Start() const
{
    if (FCount>0)
    {
        Direct_DoFirst();
        return true;
    }
    else
        return false;
}

bool TQuickList::End() const
{
    if (FCount>0)
    {
        Direct_DoLast();
        return true;
    }
    else
        return false;
}

/*TQuickList::TQuickList()
{
    FCurrentIndex = -1;
    FCount = 0;
    FCurrent = NULL;
    FFirst = NULL;
    FLast = NULL;
}

TMyListItem *LI;

void TQuickList::AddFirst(void* It)
{
    LI = new TMyListItem();
    LI->Data = It;
    LI->Prev = NULL;
    LI->Next = NULL;

    FFirst = LI;
    FLast = LI;
    FCurrentIndex = 0;
    FCurrent = LI;
    FCount=1;
}

void TQuickList::Add(void* It)
{
    if (FCount==0)
        AddFirst(It);
    else
    {
        LI = new TMyListItem();
        LI->Data = It;
        LI->Prev = FLast;
        FLast->Next = LI;
        LI->Next = NULL;
        FLast = LI;
        FCount++;
    }
}

void TQuickList::First()
{
    if (FCount)
    {
        FCurrentIndex = 0;
        FCurrent = FFirst;
    }
    else
    {
        throw EMyException("Index is out of range");
    }
}

void TQuickList::Last()
{
    if (FCount)
    {
        FCurrentIndex = FCount-1;
        FCurrent = FLast;
    }
    else
    {
        throw EMyException("Index is out of range");
    }
}


void TQuickList::Next()
{
    if (FCurrentIndex+1<FCount)
    {
        FCurrent = FCurrent->Next;
        FCurrentIndex++;
    }
    else
    {
        throw EMyException("Index is out of range");
    }
}

void TQuickList::Prev()
{
    if (FCurrentIndex-1>=0)
    {
        FCurrent = FCurrent->Prev;
        FCurrentIndex--;
    }
    else
    {
        throw EMyException("Index is out of range");
    }
}

void TQuickList::Iterate(int i)
{
    if (FCurrentIndex != i)
    {
        if (FCurrentIndex+1 == i)
            Next();
        else if (FCurrentIndex-1 == i)
            Prev();
        else if (0 == i)
            First();
        else if (FCount-1 == i)
            Last();
        else
        {
            while (FCurrentIndex<i)
                Next();
            while (FCurrentIndex>i)
                Prev();
        }
    }
}

void* TQuickList::GetItem(int idx)
{
    Iterate(idx);
    return FCurrent->Data;
}

void TQuickList::SetItem(int idx, void* newit)
{
    Iterate(idx);
    FCurrent->Data = newit;
}

void TQuickList::Delete(int idx)
{
    Iterate(idx);
    DeleteCurrent();
}

void TQuickList::DeleteCurrent()
{
    TMyListItem *Item  = FCurrent;
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
        Prev();
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

TQuickList::~TQuickList()
{
    Clear();
}

int TQuickList::IndexOf(void* It)
{
    if (Find(It))
        return FCurrentIndex;
    else
        return -1;
}

bool TQuickList::Exists(void* It)
{
    return (IndexOf(It)!=-1);
}

void TQuickList::Clear()
{
    if (FCount)
    {
        First();
        while (FCount)
            DeleteCurrent();
    }
}

void TQuickList::Insert(int index,void* Item)
{
    if (FCount == 0 || index == FCount)
        Add(Item);
    else
    {
        Iterate(index);
        LI = new TMyListItem();
        LI->Data = Item;
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

bool TQuickList::Check()
{
    TMyListItem* IT;
    IT  = FFirst;
    int i=0;
    while (IT)
    {
        IT = IT->Next;
        i++;
    }
    if (i!=FCount)
        return false;
    i=0;
    IT = FLast;
    while (IT)
    {
        IT = IT->Prev;
        i++;
    }
    if (i!=FCount)
        return false;
    return true;
}

bool TQuickList::Find(void* It)
{
    if (!FCount)
        return false;
    First();
    if (FCurrent->Data == It)
        return true;
    if (FCount==1)
        return false;
    do
    {
        Next();
        if (FCurrent->Data == It)
            return true;
    }
    while (FCurrentIndex<FCount-1);
    return false;
}



void TQuickList::Remove(void* Item)
{
    if (Find(Item))
        DeleteCurrent();
}

void* TQuickList::GetLast()
{
    Last();
    return FCurrent->Data;
}

void* TQuickList::GetFirst()
{
    First();
    return FCurrent->Data;
}*/


int TQuickList::DirectInsertIndex(void* VAL,int _Count,TMyCompareProc Proc)
{
    for (int i=0;i<_Count;i++)
        if (Proc(Items[i],VAL))
            return i;
    return _Count;
}

void TQuickList::Sort(TMyCompareProc Proc)
{
    int InsertIndex;
    for (int i=1;i<FCount;i++)
    {
        InsertIndex = DirectInsertIndex(Items[i],i,Proc);
        if (InsertIndex != i)
            Move(i,InsertIndex);
    }
}

void TQuickList::Assign ( const TQuickList *L)
{
    Clear();
    for (int i=0;i<L->Count;i++)
        Add(L->Items[i]);
}

bool TQuickList::Consists( const TQuickList *L) const
{
    for (int i=0;i<L->Count;i++)
        if (IndexOf(L->Items[i])==-1)
            return false;
    return true;
}

bool TQuickList::Same ( const TQuickList *L) const
{
    return( Consists(L)&&L->Consists(this) );
}

void TQuickList::Invert()
{
    TQuickList *L = new TQuickList();
    L->Assign(this);
    Clear();
    for (int i=L->Count-1;i>=0;i--)
        Add(L->Items[i]);
    delete L;
}


TQuickList::TQuickList()
{
    FCurrentIndex = -1;
    FCount = 0;
    FCurrent = NULL;
    FFirst = NULL;
    FLast = NULL;
}

void TQuickList::AddFirst(void* It)
{
    TQuickListItem* LI = new TQuickListItem();
    LI->Data = It;
    LI->Prev = NULL;
    LI->Next = NULL;

    FFirst = LI;
    FLast = LI;
    FCurrentIndex = 0;
    FCurrent = LI;
    FCount=1;
}

int TQuickList::Add(void* It)
{
    if (FCount==0)
    {
        AddFirst(It);
        return 0;
    }
    else
    {
        TQuickListItem* LI = new TQuickListItem();
        LI->Data = It;
        LI->Prev = FLast;
        FLast->Next = LI;
        LI->Next = NULL;
        FLast = LI;
        FCount++;
        return FCount-1;
    }
}

bool TQuickList::Direct_IndexOK(int i) const
{
    if (i<0 || i >= FCount)
    {
            AnsiString STR = "Index is out of list range, Size - ";
            STR = STR+IntToStr(FCount)+AnsiString(", Index - ");
            STR = STR+IntToStr(i);
            throw EMyException(STR);
    }
    return true;
}

void TQuickList::Direct_Iterate(int i) const
{
    if (i<0 || i >= FCount)
    {
        AnsiString STR = "Index is out of list range, Size - ";
        STR = STR+IntToStr(FCount)+AnsiString(", Index - ");
        STR = STR+IntToStr(i);
        throw EMyException(STR);
    }
    else if ( FCurrentIndex == i )
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

void TQuickList::Direct_DoNext() const
{
    FCurrent = FCurrent->Next;
    FCurrentIndex++;
}

void TQuickList::Direct_DoPrev() const
{
    FCurrent = FCurrent->Prev;
    FCurrentIndex--;
}

void TQuickList::Direct_DoFirst() const
{
    FCurrentIndex = 0;
    FCurrent = FFirst;
}

void TQuickList::Direct_DoLast() const
{
    FCurrentIndex = FCount-1;
    FCurrent = FLast;
}

void* TQuickList::GetItem(int idx) const
{
    Direct_Iterate(idx);
    return FCurrent->Data;
}

void TQuickList::SetItem(int idx, void* newit)
{
    Direct_Iterate(idx);
    FCurrent->Data = newit;
}

void TQuickList::Delete(int idx)
{
    Direct_Iterate(idx);
    DeleteCurrent();
}

void TQuickList::DeleteCurrent()
{
    TQuickListItem *Item  = FCurrent;
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

TQuickList::~TQuickList()
{
    Clear();
}

int TQuickList::IndexOf(const void* It) const
{
    if (Find(It))
        return FCurrentIndex;
    else
        return -1;
}

bool TQuickList::Exists(const void* It) const
{
    return (IndexOf(It)!=-1);
}

void TQuickList::Clear()
{
    if (FCount)
    {
        Direct_DoFirst();
        while (FCount)
            DeleteCurrent();
    }
}

void TQuickList::Insert(int index,void* Item)
{
    if (FCount == 0 || index == FCount)
        Add(Item);
    else
    {
        Direct_Iterate(index);
        TQuickListItem* LI = new TQuickListItem();
        LI->Data = Item;
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

bool TQuickList::Find(const void* It) const
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

int TQuickList::Remove(const void* Item)
{
    if (Find(Item))
    {
        int result = FCurrentIndex;
        DeleteCurrent();
        return result;
    }
    return -1;
}

void* TQuickList::Last() const
{
    Direct_IndexOK(FCount-1);
    Direct_DoLast();
    return FCurrent->Data;
}

void* TQuickList::First() const
{
    Direct_IndexOK(0);
    Direct_DoFirst();
    return FCurrent->Data;
}

void TQuickList::Exchange(int i1,int i2)
{
  TQuickListItem *P1;
  TQuickListItem *P2;
  void* P0;

  Direct_Iterate(i1);
  P1=FCurrent;;
  Direct_Iterate(i2);
  P2=FCurrent;;

  P0 = P1->Data;
  P1->Data = P2->Data;
  P2->Data = P0;

}

void TQuickList::Move(int ifrom,int idest)
{
  void* P0;
  P0 = Items[ifrom];
  DeleteCurrent();
  Insert(idest,P0);
}




/*class COMMONAL_API TMyGlobalParent : public TMyObject {
    mutable TMTList<TMyObject>* AddList;
    mutable TMTList<TMyObject>* RemoveList;
    void Clear();
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMyGlobalParent();
    virtual ~TMyGlobalParent();
    //---------------------fields acess--------------------------
    virtual void OnFieldAccess() const;
    virtual void RegisterField(void *FA,const AnsiString *FN,int FT);
    virtual void UnRegisterField(int i);
    virtual void UnRegisterField(void *FA);
    //---------------------fields acess--------------------------
};
extern COMMONAL_API TClassNode* TMyGlobalParent::StaticType;
extern COMMONAL_API TMyGlobalParent* MyGlobalParent;

TClassNode* TMyGlobalParent::StaticType = NULL;
TMyGlobalParent* MyGlobalParent;

TMyObject* FindByGUID(const AnsiString& GUID)
{
    return MyGlobalParent->RecurrentFindByGUID(GUID);
}

TMyObject* TMyObject::RecurrentFindByGUID(const AnsiString& aGUID)
{
//    if ( FGUID.AnsiCompare(aGUID) == 0 )
//        return this;
    OnFieldAccess();
    for (bool OK = FAS->Start();OK;OK = FAS->Next())
    {
        TFieldTrio* FT = (TFieldTrio*)FAS->Current;
        if ( FT->Type == mtMyObject)
        {
            TMyObject* Obj = ((TMyObject*)FT->Address);
            if ( Obj->GUID == aGUID )
                return Obj;
        }
    }
    for (bool OK = FAS->Start();OK;OK = FAS->Next())
    {
        TFieldTrio* FT = (TFieldTrio*)FAS->Current;
        if ( FT->Type == mtMyObject)
        {
            TMyObject* Result = ((TMyObject*)FT->Address)->RecurrentFindByGUID(aGUID);
            if ( Result )
                return Result;
        }
    }
    return NULL;
}


TMyObject* TMyGlobalParent::CreateFunction()
{
    return new TMyGlobalParent();
}

TMyGlobalParent::TMyGlobalParent()
{
    AddList = new TMTList<TMyObject>();
    RemoveList = new TMTList<TMyObject>();
}

TMyGlobalParent::~TMyGlobalParent()
{
    delete AddList;
    delete RemoveList;
}

const AnsiString aGlobalParentChild = AnsiString("GlobalParentChild");
void TMyGlobalParent::OnFieldAccess() const
{
    for (bool OK = RemoveList->Start();OK;OK = RemoveList->Next())
    {
        while ( AddList->Remove(RemoveList->Current)!=-1 );
        int index = IterateByAdr(FAS,RemoveList->Current);
        if (index != -1)
        {
            TFieldTrio* FIELDTRIO = (TFieldTrio*)FAS->Items[index];
            delete FIELDTRIO;
            FAS->Delete(index);
        }
    }
    for (bool OK = AddList->Start();OK;OK = AddList->Next())
    {
        TFieldTrio* FIELDTRIO = new TFieldTrio();
        FIELDTRIO->Address = AddList->Current;
        FIELDTRIO->Name = &aGlobalParentChild;
        FIELDTRIO->Type = mtMyObject;
        FAS->Add(FIELDTRIO);
    }
    AddList->Clear();
    RemoveList->Clear();
}

void TMyGlobalParent::RegisterField(void *FA,const AnsiString *FN,int FT)
{
    AddList->Add( (TMyObject*)FA );
}

void TMyGlobalParent::UnRegisterField(int i)
{
    RemoveList->Add( (TMyObject*)((TFieldTrio*)FAS->Items[i])->Address );
}

void TMyGlobalParent::UnRegisterField(void *FA)
{
    RemoveList->Add( (TMyObject*)FA );
}


*/
