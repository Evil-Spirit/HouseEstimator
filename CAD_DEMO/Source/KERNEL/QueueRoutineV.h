//---------------------------------------------------------------------------

#ifndef QueueRoutineVH
#define QueueRoutineVH
//---------------------------------------------------------------------------

template <class T>
class /*PACKAGE*/ TPsevdoPointer {
private:
    void SetAdr(T* newAdr);
public:
    T* FAdr;
    __int64 TargetID;
    TPsevdoPointer();
    TPsevdoPointer(T *adr);
    virtual ~TPsevdoPointer(){};
    __property T* ADR = {read = FAdr,write = SetAdr};
};

template <class T>
TPsevdoPointer<T>::TPsevdoPointer(T *adr)
{
    FAdr = NULL;
    ADR = adr;
}

template <class T>
TPsevdoPointer<T>::TPsevdoPointer()
{
    FAdr = NULL;
}

template <class T>
void TPsevdoPointer<T>::SetAdr(T* newAdr)
{
    FAdr = newAdr;
    if (FAdr)
        TargetID = ((TElement*)FAdr)->IntId;
    else
        TargetID = 0;
}

class TElement;
int FindInPsevdoPointerList(const TMDelTList<TPsevdoPointer<TElement> >* List,const TPsevdoPointer<TElement>* Adress);
int FindElementInPsevdoPointerList(const TMDelTList<TPsevdoPointer<TElement> >* List,TElement* Adress);

class TElementQueueCollection;
class COMMONAL_API TElementQueue {
    friend class TElementQueueCollection;
protected:
    TMDelTList< TPsevdoPointer<TElement> > ElementList;
    TMDelTList< TPsevdoPointer<TElement> > AddList;
    TMDelTList< TPsevdoPointer<TElement> > ChangeList;
    TMDelTList< TPsevdoPointer<TElement> > RemoveList;
    int GetCount();
    bool FNeedRebuild;
    void CreateQueue();
    bool FGlobalEnabled;
    virtual void OnProcess(){};
    virtual void OnUpdate(){};
    virtual void OnChange(){};
public:
    TElementQueue();
    ~TElementQueue();
    virtual void Add(TElement* Element);
    virtual void Changed(TElement* Element);
    virtual void Remove(TElement* Element);
    virtual void Delete(int i);
    virtual void Clear();
    __property int Count = {read = GetCount};
    TElement* GetElement(int i);
    bool Enabled;
    void Process();
};

class COMMONAL_API TElementQueueCollection {
private:
    bool FEnabled;
    void SetEnabled(bool aEnabled);
public:
    TMTList<TElementQueue> Queues;
    TElementQueueCollection(){};
    ~TElementQueueCollection(){};
    __property bool Enabled = {read = FEnabled,write = SetEnabled};
    void Remove(TElement* Element);
    void Changed(TElement* Element);
};

extern COMMONAL_API TElementQueueCollection* FElementQueueCollection;
COMMONAL_API TElementQueueCollection& GetElementQueueCollection();
#define ElementQueueCollection GetElementQueueCollection()
#endif
