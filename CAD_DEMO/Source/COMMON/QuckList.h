//---------------------------------------------------------------------------

#ifndef QuckListH
#define QuckListH

//---------------------------------------------------------------------------
/*class TMyListItem{
public:
    TMyListItem(){};
    virtual ~TMyListItem(){};

    TMyListItem *Next;
    TMyListItem *Prev;
    void* Data;
};

class TQuickList {
    int FCurrentIndex;
    int FCount;
    TMyListItem *FCurrent;
    TMyListItem *FFirst;
    TMyListItem *FLast;
    void AddFirst(void* It);

    void Iterate(int i);
    void Next();
    void Prev();
    void First();
    void Last();
    void DeleteCurrent();
    void SetItem(int id, void* newit);
    void* GetItem(int i) ;
    bool Find(void* It);
public:
    TQuickList();
	virtual ~TQuickList();

    __property void* Items[int i] = {read = GetItem,write = SetItem};
    __property int Count = {read = FCount};

    void Add(void* It);

    void Delete(int i);

    int IndexOf(void* It) ;

    bool Exists(void* It) ;

    void Clear();

    void Insert(int index,void* Item);

    void Remove(void* Item);

    void* GetLast();

    void* GetFirst();

    bool Check();
}; */


class COMMONAL_API TQuickListItem{
public:
    TQuickListItem(){};
    virtual ~TQuickListItem(){};
    TQuickListItem *Next;
    TQuickListItem *Prev;
    void* Data;
};


class COMMONAL_API TQuickList{
protected:
    mutable int FCurrentIndex;
    int FCount;
    mutable TQuickListItem *FCurrent;
    TQuickListItem *FFirst;
    TQuickListItem *FLast;
    void AddFirst(void* It);

    //---------------------------
    bool Direct_IndexOK(int i) const;
    void Direct_Iterate(int i) const;
    void Direct_DoNext() const;
    void Direct_DoPrev() const;
    void Direct_DoFirst() const;
    void Direct_DoLast() const;
    //--------------------------
    void DeleteCurrent();
    bool Find(const void* It) const;
    void SetItem(int id, void* newit);
public:
    TQuickList();
	virtual ~TQuickList();

    void* GetItem(int i) const;
    __property void* Items[int i] = {read = GetItem,write = SetItem};
    __property int Count = {read = FCount};

    int Add(void* It);

    int IndexOf(const void* It) const;

    bool Exists(const void* It) const;

    void Insert(int index,void* Item);

    void* Last() const;

    void* First() const;

    void Exchange(int i1,int i2);

    void Move(int ifrom,int idest);

    virtual void Delete(int i);

    virtual void Clear();

    virtual int Remove(const void* Item);

    virtual void Invert();
    virtual void Assign ( const TQuickList *L);

    virtual bool Consists( const TQuickList *L) const;
    virtual bool Same ( const TQuickList *L) const;

    int DirectInsertIndex(void* VAL,int Count,TMyCompareProc Proc);
    void Sort(TMyCompareProc Proc);

    void* GetCurrent();
    bool Next() const;
    bool Prev() const;
    bool Start() const;
    bool End() const;
    __property void* Current = {read = GetCurrent};
};


#endif
