//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
        
#include "QueueRoutineV.h"
#include "ElementV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

int FindInPsevdoPointerList(const TMDelTList<TPsevdoPointer<TElement> >* List,const TPsevdoPointer<TElement>* Adress)
{
    int i=0;
    for (bool OK = List->Start();OK;OK = List->Next(),i++)
        if ( List->GetCurrent()->TargetID == Adress->TargetID )
            return i;
    return -1;
}

int FindElementInPsevdoPointerList(const TMDelTList<TPsevdoPointer<TElement> >* List,TElement* Adress)
{
    int i=0;
    for (bool OK = List->Start();OK;OK = List->Next(),i++)
        if ( List->GetCurrent()->TargetID == Adress->IntId )
            return i;
    return -1;
}

TElementQueueCollection* FElementQueueCollection = NULL;

TElementQueueCollection& GetElementQueueCollection()
{
    if ( !FElementQueueCollection )
        FElementQueueCollection = new TElementQueueCollection();
    return *FElementQueueCollection;
}

TElementQueue::TElementQueue()
{

    ElementQueueCollection.Queues.Add(this);
    FGlobalEnabled = true;
    Enabled = true;
    FNeedRebuild = false;
}

TElementQueue::~TElementQueue()
{
    ElementQueueCollection.Queues.Remove(this);
    Clear();
}

void TElementQueue::Changed(TElement* Element)
{
    if ( !ChangeList.Count || ChangeList.Last()->TargetID != Element->IntId)
        ChangeList.Add( new TPsevdoPointer<TElement>(Element) );
}

void TElementQueue::Add(TElement* Element)
{
    AddList.Add( new TPsevdoPointer<TElement>(Element) );
    OnChange();
}

void TElementQueue::Remove(TElement* Element)
{
    RemoveList.Add( new TPsevdoPointer<TElement>(Element) );
    OnChange();
}

void TElementQueue::Delete(int i)
{
    RemoveList.Add( new TPsevdoPointer<TElement> ( GetElement(i) ) );
    OnChange();
}

void TElementQueue::Clear()
{
    bool Changed = ElementList.Count||AddList.Count||RemoveList.Count||ChangeList.Count;
    ElementList.Clear();
    AddList.Clear();
    RemoveList.Clear();
    ChangeList.Clear();
    if (Changed)
        OnChange();
}

void TElementQueue::CreateQueue()
{
    for (int i=0;i<AddList.Count;i++)
        if ( FindInPsevdoPointerList(&ElementList,AddList.Items[i]) == -1 )
        {
            ElementList.Add( new TPsevdoPointer<TElement>());
            ElementList.Last()->FAdr = AddList[i].ADR;
            ElementList.Last()->TargetID = AddList[i].TargetID;
            FNeedRebuild = true;
        }
    for (int i=0;i<RemoveList.Count;i++)
    {
        int index = FindInPsevdoPointerList(&ElementList,RemoveList.Items[i]);
        if (index!=-1)
            ElementList.Delete(index);
        FNeedRebuild = true;
    }
    for (int i=0;i<ChangeList.Count;i++)
        if (FindInPsevdoPointerList(&ElementList,ChangeList.Items[i])!=-1)
        {
            FNeedRebuild = true;
            break;
        }
    AddList.Clear();
    RemoveList.Clear();
    ChangeList.Clear();
}

void TElementQueue::Process()
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

TElement* TElementQueue::GetElement(int i)
{
    CreateQueue();
    return ElementList[i].ADR;
}

int TElementQueue::GetCount()
{
    CreateQueue();
    return ElementList.Count;
}

//-----------------------------------------------------------
//-----------------------------------------------------------
void TElementQueueCollection::Remove(TElement* Element)
{
    for (int i=0;i<Queues.Count;i++)
        Queues[i].Remove(Element);
}

void TElementQueueCollection::SetEnabled(bool aEnabled)
{
    FEnabled = aEnabled;
    for (int i=0;i<Queues.Count;i++)
        Queues[i].FGlobalEnabled = FEnabled;
}

void TElementQueueCollection::Changed(TElement* Element)
{
    for (int i=0;i<Queues.Count;i++)
        Queues[i].Changed(Element);
}

