//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
           
#include "World.h"
#include "MyGL.h"
#include "MDI3DV.h"
#include "QuckList.h"
#include "LinkGeometry.h"
#include "UNDO.h"
#include "Select.h"
#include "LogicNode.h"
#include "MultiElementV.h"
#include "Label3DV.h"
#include "MySupportV.h"
#include "AUIV.h"
#include "Driver.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TMainTree* World;
TClassNode* TFloor::StaticType = NULL;
TClassNode* TMainTree::StaticType = NULL;

bool TMainTree::TechCheck(AnsiString& Str)
{
    /* TODO : отключение неправильного элемента */
//    Select->ErrElement = NULL;
    bool result = true;
    TMTList<TMyRegObject> *L = new TMTList<TMyRegObject>();
    SelectByCT(NULL,TElement::StaticType,L,false,true);

    for (int i=0;i<L->Count;i++)
        if (((TElement*)L->Items[i])->TechCheck(Str)==false)
        {
            /* TODO : включение неправильного элемента */
            //Select->ErrElement = (TElement*)L->Items[i];
            //Select->CreateErrView();
            result = false;
            break;
        }
    if (result && ((TMetaNode*)MetaNodeCollection->Head)->TB->Exists(trTechCheck))
    {
        TechnologyCheckPass = false;
        TechnologyCheckStr = "";
        ((TMetaNode*)MetaNodeCollection->Head)->TB->Run(trTechCheck);
        if (!TechnologyCheckPass)
        {
            result = false;
            Str = TechnologyCheckStr;
        }
    }
    delete L;
    return result;
}

void TMainTree::SelectAllLinks(TElement *Element, TMTList<TLink> *LL)
{
    if (!Element)
    {
        SelectAllLinks((TElement*)Head,LL);
        return;
    }
    for (int i=0;i<Element->FLinks.Count;i++)
        if ( LL->IndexOf(&Element->FLinks[i])== -1 )
            LL->Add(&Element->FLinks[i]);
    for (int i=0;i<Element->ChildList->Count;i++)
        SelectAllLinks((TElement*)Element->ChildList->Items[i],LL);
}

void TMainTree::CompleteToBufferUndo(TMTList<TMyRegObject>& Parents,TMemoryStream *MS)
{
    LLS.ShowProcess = false;
    ELS.ShowProcess = false;
    TMTList<TMyRegObject> AUTOS;
    SelectByCT(NULL,TElement::StaticType,&ELS,true,true);
    for (int i=0;i<ELS.Count;i++)
        if ( ((TElement*)ELS.Items[i])->MyMeta->IsAuto)
            AUTOS.Add(ELS.Items[i]);
    for (int i=0;i<ELS.Count;i++)
    {
        bool SaveInList = false;
        for (int k=0;k<Parents.Count;k++)
            if (ELS[i].In(Parents.Items[k]) || ELS.Items[i] == Parents.Items[k])
            {
                SaveInList = true;
                break;
            }
        if ( !SaveInList )
            for (int k=0;k<AUTOS.Count;k++)
                if (ELS[i].In(AUTOS.Items[k]) || ELS.Items[i] == AUTOS.Items[k])
                {
                    SaveInList = true;
                    break;
                }
        if (!SaveInList)
            ELS.RemoveOnly(i--);
    }

    for (int i=0;i<ELS.Count;i++)
        SelectAllLinks((TElement*)ELS.Items[i],&LLS);

    LLS.WriteData(MS);
    ELS.WriteData(MS);
    LLS.ShowProcess = true;
    ELS.ShowProcess = true;
    LLS.NoDelClear();
    ELS.NoDelClear();
}

void TMainTree::CompleteFromBufferUndo(TMemoryStream *MS)
{
    load = true;

    //удаление помещений
    SelectByCT(NULL,TElement::StaticType,&ELS,true,true);
    for (int i=0;i<ELS.Count;i++)
        if (((TElement*)ELS.Items[i])->MyMeta->IsAuto)
            ELS.Delete(i--);

    ELS.NoDelClear();

    LLS.ReadData(MS);
    ELS.ReadData(MS);
    TMTList<TMetaElement> MLST;
    for (int i=0;i<ELS.Count;i++)
        ELS[i].MyTree = this;

    if ( !CheckFields() )
        throw EMyException("Data check error.");

    if ( !Init() )
        throw EMyException("Init error.");
    load = false;
    LLS.NoDelClear();
    ELS.NoDelClear();
}


void TMainTree::CompleteToBuffer(TMyRegObject *Node,TMemoryStream *MS)
{

    SelectAllLinks((TElement*)Node,&LLS);
    SelectByCT(Node,TElement::StaticType,&ELS,true,true);

    LLS.WriteData(MS);
    ELS.WriteData(MS);
    
    LLS.NoDelClear();
    ELS.NoDelClear();
}

void TMainTree::CompleteFromBuffer(TMemoryStream *MS)
{
    load = true;
    LLS.ShowProcess = true;
    ELS.ShowProcess = true;

    LLS.ReadData(MS);
    ELS.ReadData(MS);

    for (int i=0;i<ELS.Count;i++)
        ELS[i].MyTree = this;

    if ( !CheckFields() )
        throw EMyException("Data check error.");

    if ( !Init() )
        throw EMyException("Init error.");
    load = false;
    for (int i=0;i<ELS.Count;i++)
        AddChild(ELS[i].Parent,&ELS[i]);
    LLS.NoDelClear();
    ELS.NoDelClear();
}

int ValidateIndex(int Count,int Index)
{
    while ( Index >= Count )
        Index--;
    while ( Index < 0 )
        Index++;
    if ( Index < 0 || Index >= Count )
        Index = -1;
    return Index;
}

bool TMainTree::CheckFields()
{
    Floors.CheckFields();
    for (int i=0;i<Clients.Count;i++)
    {
        Clients[i].Floors.Clear();
//        Clients[i].Visible.Clear();
        for (int j=0;j<Floors.Count;j++)
        {
            Clients[i].Floors.Add(&Floors[j]);
            if (Clients[i].Visible.Count-1 < j)
                Clients[i].Visible.Add(new bool(false));
           ActiveIndex = ValidateIndex(Floors.Count,ActiveIndex);
        }
        while (Clients[i].Visible.Count>Floors.Count)
            Clients[i].Visible.Delete(Clients[i].Visible.Count-1);
    }
    return (LLS.CheckFields() && ELS.CheckFields());
}

//recurrent check   агрегатная иерархия tmyobject ()
// check data иерархия в дереве
bool TMainTree::Init()
{
    for (int i=0;i<LLS.Count;i++)
        if (LLS[i].Elements[0] == Head && Head->ChildList->IndexOf(LLS[i].Elements[1])!=-1)
            LLS.RemoveOnly(i--);
    for (int i=0;i<Floors.Count&&Head;i++)
    {
        TElement *El = Floors[i].First.ADR;
        El->UserChangePosition( TIntVec(0,0,Floors[i].AbsZ - El->AbsSize.z/2) - El->AbsPos,ZEROINTVEC);
        Connect((TElement*)Head,El,GetLinkAnyWay( ((TElement*)Head)->MyMeta,El->MyMeta));
    }
    return LLS.Init() && ELS.Init();
}

void TMainTree::WriteFile(const AnsiString& FileName)
{
    TMemoryStream* MS = new TMemoryStream();
    CHECK_FILE_SAVE(FileName);
    AnsiString Ext =  ExtractFileExt(FileName);
    Name = ExtractFileName(FileName).SubString(1,ExtractFileName(FileName).Length() - Ext.Length());
    TMyObject::WriteData(MS);
    MetaNodeCollection->WriteContextMD(MS);
    CompleteToBuffer(Head,MS);
    MS->SaveToFile(FileName);
    UndoStack.Clear();
    AskedToSave = true;
    delete MS;
}

void TMainTree::ReadFile(const AnsiString& FileName)
{
    if (FileExists(FileName))
    {
        Clear();
        if (World == this && MetaNodeCollection)
        {
            MetaNodeCollection->AfterProcessActions();
            MetaNodeCollection->PreProcessActions();
        }
        UndoStack.Clear();
        TMemoryStream* MS = new TMemoryStream();
        MS->LoadFromFile(FileName);
        TMyObject::ReadData(MS);
        MetaNodeCollection->ReadContextMD(MS);
        CompleteFromBuffer(MS);
        delete MS;
        AskedToSave = true;
    }
}

//-------------------MainTree-----------------------------------------
TMyObject* TFloor::CreateFunction()
{
    return new TFloor();
}

const AnsiString aAbsZ = AnsiString("AbsZ");
const AnsiString aVisible = AnsiString("Visible");
const AnsiString aFirst = AnsiString("First");
const AnsiString aHeight = AnsiString("Height");
const AnsiString aDescription = AnsiString("Description");
const AnsiString aUp_Lost = AnsiString("Up_Lost");
const AnsiString aDown_Lost = AnsiString("Down_Lost");

TFloor::TFloor()
{
    RegisterNewClass< TMyObject, TFloor >(this,false,&CreateFunction);
    Visible = true;
    Up_Lost = 0.25;
    Down_Lost = 0.5;
    Height = 3;
    AbsZ = 0;
    RegisterField(&AbsZ,&aAbsZ,mtMBTi);
    RegisterField(&Height,&aHeight,mtMBTi);
    RegisterField(&Visible,&aVisible,mtBool);
    RegisterField(&First,&aFirst,mtMyObject);
    RegisterField(&Description,&aDescription,mtString);
    RegisterField(&Up_Lost,&aUp_Lost,mtMBTi);
    RegisterField(&Down_Lost,&aDown_Lost,mtMBTi);


    VLIGHTS = new TVisNode(NULL);
    VLIGHTS->Transformation->Order = toTraRotSca;
    VLIGHTS->Transformation->Rotation->Order = roZXY;

    VFIRST = new TVisNode(NULL);
    VFIRST->Transformation->Order = toTraRotSca;
    VFIRST->Transformation->Rotation->Order = roZXY;
    VTRANS = new TVisNode(NULL);
    VTRANS->Transformation->Order = toTraRotSca;
    VTRANS->Transformation->Rotation->Order = roZXY;
    VLABEL = new TVisNode(NULL);
    VLABEL->Transformation->Order = toTraRotSca;
    VLABEL->Transformation->Rotation->Order = roZXY;
}

TFloor::~TFloor()
{
    Clear();
    delete VLIGHTS;
    delete VFIRST;
    delete VTRANS;
    delete VLABEL;
}

void TFloor::Add(TElement *Chto)
{
    if (Chto == First.ADR)
        return;
    #ifdef _DEBUG
    if (First.ADR && !Chto->In(First.ADR) && Chto!=First.ADR)
        throw EMyException("Element is not related to the given floor");
    #endif
    if (Chto->MyRender())
    {
        if ( Chto->Is(TMultiElement::StaticType) )
        {
            VTRANS->AddIndirect(((TMultiElement*)Chto)->VTRANS);
            VFIRST->AddIndirect(((TMultiElement*)Chto)->VFIRST);
        }
        else
        {
            if ( Chto->Is(TLabel3D::StaticType) )
                VLABEL->AddIndirect(Chto->MyRender());
            else if ( !((TVisPrimitiveObj*)Chto->MyRender())->Material || ((TVisPrimitiveObj*)Chto->MyRender())->Material->ColorDiffuse->Alpha!=1)
                VTRANS->AddIndirect(Chto->MyRender());
            else
                VFIRST->AddIndirect(Chto->MyRender());
        }
    }
}

void TFloor::Remove(TElement *Chto)
{
    if (Chto == First.ADR)
        return;
    if ( Chto->Is(TMultiElement::StaticType) )
    {
        VFIRST->Remove(((TMultiElement*)Chto)->VFIRST);
        VTRANS->Remove(((TMultiElement*)Chto)->VTRANS);
    }
    else if ( Chto->Is(TLabel3D::StaticType) )
        VLABEL->Remove(Chto->MyRender());
    else if (Chto->MyRender())
    {
            VTRANS->Remove(Chto->MyRender());
            VFIRST->Remove(Chto->MyRender());
        /*int index = -1;
        if (Chto->MyMeta->GetVisMaterial(BIF->Mode)->ColorDiffuse->Alpha!=1 &&
            (index = VTRANS->IndexOf(Chto->MyRender()))!=-1 )
            VTRANS->Remove(Chto->MyRender());
        else
            VFIRST->Remove(Chto->MyRender()); */
    }
}

TElement* TFloor::GetFirstElement()
{
    return First.ADR;
}

void TFloor::Clear()
{
    First.ADR = NULL;
    VFIRST->Clear();
    VTRANS->Clear();
    VLABEL->Clear();
}

const AnsiString aFloors = AnsiString("Floors");
const AnsiString aRenderLand = AnsiString("RenderLand");
const AnsiString aRenderNet = AnsiString("RenderNet");

TFloorInfo::TFloorInfo()
{
    AddIndex = 0;
    EditIndex = 0;
    Height = 3;
    Up_Lost = 0.25;
    Down_Lost = 0;
    FloorFrom = -1;
    OK_Pressed = false;
    ElToMove = new TMTList<TMetaNode>();
    FloorName = "Ground floor";
}

TFloorInfo::~TFloorInfo()
{
    delete ElToMove;
}

void TClient3D::Render(TVisCustomView* aView,bool RenderNet)
{
  if ( IS( ((TVisView*)aView)->Camera,__classid(TVisPerspectiveCamera)) )
    {
        for (int i=0;i<Floors.Count;i++)
            if ( VisibleAll || i==ActiveIndex || Visible[i])
                Floors[i].VFIRST->Render(aView);

        if ( AUI.ActiveWorld == World && RenderNet && ActiveIndex>=0 && ActiveIndex<Floors.Count)
            Floors[ActiveIndex].First.ADR->Render(aView);

        for (int i=0;i<Floors.Count;i++)
            if (VisibleAll || i==ActiveIndex || Visible[i])
                Floors[i].VTRANS->Render(aView);
        for (int i=0;i<Floors.Count;i++)
            if (VisibleAll || i==ActiveIndex || Visible[i])
                Floors[i].VLABEL->Render(aView);
    }
    else
    {
        if (AUI.ActiveWorld == World && RenderNet && ActiveIndex>=0 && ActiveIndex<Floors.Count)
            Floors[ActiveIndex].First.ADR->Render(aView); 
        if (ActiveIndex>=0 && ActiveIndex<Floors.Count)
        {
                Floors[ActiveIndex].VFIRST->Render(aView);
                Floors[ActiveIndex].VTRANS->Render(aView);
                Floors[ActiveIndex].VLABEL->Render(aView);
        }
    }
}

TMyObject* TMainTree::CreateFunction()
{
    return new TMainTree();
}

const AnsiString aName = AnsiString("Name");

TMainTree::TMainTree()
{
    RegisterNewClass< TMyRegTree, TMainTree >(this,false,&CreateFunction);
    AUI.Register(this);    
    //--------------------------------------------------------------------------
    FModeIndex = 0;
    FPrevModeIndex = 0;
    //--------------------------------------------------------------------------
    load = false;
    CheckPremises = true;
    LLS.ShowProcess = true;
    ELS.ShowProcess = true;
    AskedToSave = true;
    RenderLand = false;
    RenderNet = true;
    Name = ValidateFileName_Dir_Ext("New",MainDir,eHOME);
    if (!World)
        UndoStack.Clear();
    FloorInfo = new TFloorInfo();
    SERVICE = new /*TMDelLSTList*/TMDelTList<TPointer<TElement> >;
    if (World == NULL && MetaNodeCollection)
        MetaNodeCollection->PreProcessActions();
    RegisterField(&Name,&aName,mtString);
    RegisterField(&RenderLand,&aRenderLand,mtBool);
    RegisterField(&RenderNet,&aRenderNet,mtBool);
    RegisterField(&Floors,&aFloors,mtMyObject);
    if (MetaNodeCollection->KernelSupport->RootElement)
    {
        TElement *El = CreateElementFunction(this,MetaNodeCollection->KernelSupport->RootElement);
        El->UserChangePosition( TIntVec(0,0,0-El->AbsSize.z/2)-El->AbsPos,ZEROINTVEC);
        El->CurrentEnabled = true;
        AddFirst(El);
    }
}

TMainTree::~TMainTree()
{
//    AUI.UnRegister(this);    
//  /* TODO : отключение действия обратить внимание */  Select->Terminate();
    Clear();
    delete FloorInfo;
    delete SERVICE;
    if (World == this)
    {
        MetaNodeCollection->AfterProcessActions();
        World = NULL;
    }
    LLS.NoDelClear();
    ELS.NoDelClear();
}

TFloor* TMainTree::GetActiveFloor()
{
    TClient3D* Active = ActiveClient;
    if ( Active ) {
        if ( Active->ActiveIndex == -1 )
            return NULL;
        return Floors.Items[Active->ActiveIndex];
    } else if (Floors.Count>0)
        return Floors.Items[0];
    else
        return NULL;
}


TClient3D* TMainTree::FindClient(TMDI3D* aView)
{
    for (int i=0;i<Clients.Count;i++)
        if ( Clients[i].MDI3D == aView )
            return Clients.Items[i];
    return NULL;
}

TClient3D* TMainTree::GetActiveClient()
{
    return FindClient( AUI.ActiveView );
}

void TMainTree::RegisterClient(TMDI3D *new_3D)
{
    if (FindClient(new_3D))
        return;
    TClient3D* Active3D = ActiveClient;
    TClient3D* newClient = new TClient3D();
    Clients.Add(newClient);
    newClient->MDI3D = new_3D;
    if (Active3D)
    {
        newClient->ActiveIndex = Active3D->ActiveIndex;
        newClient->VisibleAll = Active3D->VisibleAll;
    }
    else
    {
        newClient->ActiveIndex = 0;
        newClient->VisibleAll = true;
    }
    for (int i=0;i<Floors.Count;i++)
    {
        newClient->Floors.Add(Floors.Items[i]);
        newClient->Visible.Add(new bool());
        if (Active3D)
            newClient->Visible[i] = Active3D->Visible[i];
        else
            newClient->Visible[i] = false;
    }
}

void TMainTree::UnRegisterClient(TMDI3D *_3D)
{
    TClient3D* deleteClient = FindClient(_3D);
    if (deleteClient)
        Clients.Delete(Clients.IndexOf(deleteClient));
}

int TMainTree::FloorOf(TElement* El)
{
    for (int i=0;i<Floors.Count;i++)
        if (Floors[i].First.ADR && (El->In(Floors[i].First.ADR) || El == Floors[i].First.ADR) )
            return i;
    return -1;
}

int TMainTree::FloorOfUseDriver(TElement* El)
{
    if (El == Driver.Element)
        return FloorOf(Driver.FloorElement);
    else
        return FloorOf(El);
}

bool TMainTree::IsFloorElement(TElement* El)
{
    for (int i=0;i<Floors.Count;i++)
        if (Floors[i].First.ADR == El)
            return true;
    return false;        
}


void TMainTree::RecurrentSelectByElementLinks(TUnit *Node,TMetaElement *ME_B,TMTList<TElement> *List)
{
    //return this
    for (int i=0;i<Node->ChildList->Count;i++)
        RecurrentSelectByElementLinks((TUnit *)Node->ChildList->Items[i],ME_B,List);
    if ( Node->Is(TElement::StaticType) )
    {
        TMetaElement *ME_A = ((TElement *)Node)->MyMeta;
        //выгружаются в список все объекты
        //даже с необязательными связками
        for (int i=0;i<ME_A->ChildList->Count;i++)
            if ( ((TDynamicLink *)(ME_A->ChildList->Items[i]))->Exists(ME_B))
            {
                if (List->IndexOf((TElement*)Node)!=-1)
                    continue;
                List->Add((TElement*)Node);
                return;
            }
        for (int i=0;i<ME_B->ChildList->Count;i++)
            if ( ((TDynamicLink *)(ME_B->ChildList->Items[i]))->Exists(ME_A))
            {
                if (List->IndexOf((TElement*)Node)!=-1)
                    continue;
                List->Add((TElement*)Node);
                return;
            }
    }
}

void TMainTree::SelectByElementLinks(TElement *Element,TMTList<TElement> *List)
{
    if (!Head)
        return;
    RecurrentSelectByElementLinks((TElement *)Head,Element->MyMeta,List);
}

void TMainTree::Render(TVisCustomView *aView)
{
    if (load)
        return;
        if (Head && RenderLand)
            ((TElement*)Head)->Render(aView);
        TClient3D* Client = ActiveClient;

        if (Client)
            Client->Render(aView,RenderNet);
        for (int i=0;i<SERVICE->Count;i++)
            SERVICE->Items[i]->ADR->Render(aView);

}


/*void TMainTree::Render2D(TDrawView *DrawView)
{
    if (Head && RenderLand)
        ((TElement*)Head)->Render2D(DrawView);
    TClient3D* Client = NULL;
    for (int i=0;i<Clients.Count;i++)
        if ( Clients[i].MyView(DrawView))
        {
            Client = Clients.Items[i];
            break;
        }

    if (Client)
        Client->Render2D(DrawView,RenderNet);
    for (int i=0;i<SERVICE->Count;i++)
        SERVICE->Items[i]->ADR->Render2D(DrawView);
}*/


void TMainTree::RemoveElement(TElement *Float)
{
    int pointerlist;
    int floorindex;
    if (Float == Head)
        Head = NULL;
    else if ( (pointerlist = FindInPointerList(SERVICE,Float))!=-1 )
        SERVICE->Delete(pointerlist);
    else if ( (floorindex=FloorOf(Float))!=-1 )
    {
        Floors[floorindex].Remove(Float);
    }
    else
        for (int i=0;i<Floors.Count;i++)
            Floors[i].Remove(Float);

//        MDIFloorControl->DeleteElement(Float);
}

void TMainTree::RecurrentSelectByMetaElement(TMyRegObject* RO,TMetaElement* MetaElement,TMTList<TElement>* LST)
{
    for (int i=0;i<RO->ChildList->Count;i++)
        RecurrentSelectByMetaElement((TMyRegObject*)RO->ChildList->Items[i],MetaElement,LST);

    if ( ((TElement*)RO)->MyMeta == MetaElement )
        LST->Add((TElement*)RO);
}

bool TMainTree::SelectByMetaElement(int Floor,TMetaElement* MetaElement,TMTList<TElement>* LST)
{
    TMyRegObject* ParentFilter = NULL;
    if (Floor>=0 && Floor<Floors.Count)
        ParentFilter = Floors[Floor].First.ADR;
    else
        ParentFilter = Head;
    LST->Clear();
    if (ParentFilter)
        RecurrentSelectByMetaElement(ParentFilter,MetaElement,LST);
    return (LST->Count>0) ;
}

int TMainTree::GetActiveIndex()
{
    TClient3D* Active = ActiveClient;
    if (Active && Active->ActiveIndex!=-1)
        return Active->ActiveIndex;
    else
        return 0;
}

void TMainTree::SetActiveIndex(int index)
{
    TClient3D* Active = ActiveClient;
    if (Active)
        Active->ActiveIndex = index;
}

void TMainTree::EditActiveFloor()
{
    FloorInfo->AddIndex = ActiveIndex;
    FloorInfo->EditIndex = ActiveIndex;
    FloorInfo->FloorName = ActiveFloor->GetCharDescription();
    FloorInfo->Height = ActiveFloor->Height;
    FloorInfo->Up_Lost = ActiveFloor->Up_Lost;
    FloorInfo->Down_Lost = ActiveFloor->Down_Lost;
    FloorInfo->OK_Pressed = false;
    if (this == World)
        ((TMetaNode*)MetaNodeCollection->Head)->TB->Run(trEditFloor);

    if (!FloorInfo->OK_Pressed)
        return;
}


bool TMainTree::AddFloor(int index)
{
    if (index == -1)
        index = Floors.Count;
    FloorInfo->ElToMove->Clear();
    FloorInfo->OK_Pressed = true;
    FloorInfo->FloorFrom = ActiveIndex;
    FloorInfo->AddIndex = index;
    FloorInfo->EditIndex = index;
    if (this == World)
        ((TMetaNode*)MetaNodeCollection->Head)->TB->Run(trAddFloor);

    if (!FloorInfo->OK_Pressed)
        return false;

    //если добавляется этаж в середину то поднять этажи
    for (int i=index;i<Head->ChildList->Count;i++)
    {
        Floors[i].First.ADR->UserChangePosition(TIntVec(0,0,FloorInfo->Height),ZEROINTVEC);
        Floors[i].AbsZ = Floors[i].First.ADR->AbsPos.z+Floors[i].First.ADR->AbsSize.z/2;
        Connect((TElement *)Head,Floors[i].First.ADR, GetLinkAnyWay( ((TElement *)Head)->MyMeta,Floors[i].First.ADR->MyMeta) );
        //---------------------------------------------------------------------------------
            //---------------------------------------------------------------------------------
            TMTList<TLink> LL;
            SelectAllLinks(Floors[i].First.ADR,&LL);
            for(int i=0;i<LL.Count;i++)
                if (LL[i].MyMeta->Link->InWeb)
                    LN->Changed(&LL[i]);
            //---------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------
    }
    TFloor *Floor = new TFloor();
    Floor->Description = FloorInfo->FloorName;
    Floor->Height = FloorInfo->Height;
    Floor->Up_Lost = FloorInfo->Up_Lost;
    Floor->Down_Lost = FloorInfo->Down_Lost;
    if (index>0)
        Floor->AbsZ = Floors[index-1].AbsZ + Floors[index-1].Height;
    else
        Floor->AbsZ = 0;
    if (Head && MetaNodeCollection->KernelSupport->SubRootElement)
    {
        TElement *El = CreateElementFunction(this,MetaNodeCollection->KernelSupport->SubRootElement);
        El->UserChangePosition( TIntVec(0,0,Floor->AbsZ - El->AbsSize.z/2) - El->AbsPos,ZEROINTVEC);
        Floor->First.ADR = El;
        Connect((TElement *)Head,El,GetLinkAnyWay( ((TElement *)Head)->MyMeta,El->MyMeta) );
        El->CurrentEnabled = true;
    }
    Floors.Insert(index,Floor);
    Floor->Height = FloorInfo->Height;
    TMTList<TElement> DIRECT_LST;
    TMTList<TElement> NEW_LST;
    if (    Floors.Count >= 2 &&
            FloorInfo->FloorFrom != index &&
            FloorInfo->FloorFrom >= 0 &&
            FloorInfo->FloorFrom < Floors.Count &&
            Floors[FloorInfo->FloorFrom].First.ADR)
    {

        TMTList<TMyRegObject> LST;
        SelectByCT(Floors[FloorInfo->FloorFrom].First.ADR,TElement::StaticType,&LST,true,true);
        for (int i=0;i<LST.Count;i++)
            if ( FloorInfo->ElToMove->IndexOf(((TElement*)LST.Items[i])->MyMeta) == -1 )
                LST.Delete(i--);

        while (LST.Count)
            for (int i=0;i<LST.Count;i++)
                if ( LST.IndexOf(LST.Items[i]->Parent) == -1)
                {
                     DIRECT_LST.Add((TElement*)LST.Items[i]);
                     LST.Delete(i--);
                }
        StartProcess("Moving objects to the new floor...",DIRECT_LST.Count);
        for (int i=0;i<DIRECT_LST.Count;i++)
        {
            TElement* TAR = DIRECT_LST.Items[i];
            TElement *El = CreateElementFunction(this,TAR->MyMeta);
            NEW_LST.Add(El);
            CountProcess(El->Name,1);
            El->Assign(TAR);
            El->RecurrentCheck();
            El->Init();
            TIntVec POS = TAR->AbsPos;
            POS.z = POS.z + Floors[index].AbsZ - Floors[FloorInfo->FloorFrom].AbsZ;
            El->UserChangePosition(POS - El->AbsPos,TAR->AbsAngle - El->AbsAngle);
        }
    }
    for (int i=0;i<Clients.Count;i++)
    {
        Clients[i].Floors.Insert(index,Floor);
        Clients[i].Visible.Insert(index,new bool(false));
    }
    ActiveIndex = index;
    StartProcess("Positioning objects at the new floor ...",NEW_LST.Count);
    for (int i=0;i<NEW_LST.Count;i++)
    {
        CountProcess(NEW_LST.Items[i]->Name,1);
        NEW_LST[i].RunElementTrigger(trCreate);
        if (!GoDriver(NEW_LST.Items[i]))
        {
            AnsiString STR = AnsiString("Can not move object ");
            STR = STR + NEW_LST.Items[i]->MyMeta->Description;
            ShowMessage(STR);
            KillElement( NEW_LST.Items[i] );
            NEW_LST.Delete(i--);
        }
    }
    if (this == World && MetaNodeCollection->KernelSupport->WEBMETA.Count)
        Process_AddElement(MetaNodeCollection->KernelSupport->WEBMETA.Items[0],NULL);
    return true;
//    for (int i=0;i<FloorInfo->ElT )
}

bool TMainTree::FloorDeleted()
{
    for (int i=0;i<Floors.Count;i++)
    {
        Floors[i].First.CheckFields();
        if ( Floors[i].First.ADR && Floors[i].First.ADR->DestroyStarted)
            return true;
    }
    return false;
}


void TMainTree::RemoveFloor(int index)
{
    MBTi SdvigZ = 0;
    if (index+1<Floors.Count)
        SdvigZ = Floors[index+1].AbsZ - Floors[index].AbsZ;
    if (Head->ChildList->IndexOf(Floors[index].First.ADR)!=-1)
        KillElement( Floors[index].First.ADR );
    Floors.Delete(index);
//    if (MetaNodeCollection->Platform_Land)
        for (int i=index;i<Floors.Count;i++)
        {
            Floors[i].First.ADR->UserChangePosition(TIntVec(0,0,-SdvigZ),ZEROINTVEC);
            Floors[i].AbsZ = Floors[i].First.ADR->AbsPos.z+Floors[i].First.ADR->AbsSize.z/2;
            Connect((TElement *)Head,Floors[i].First.ADR,GetLinkAnyWay( ((TElement *)Head)->MyMeta,Floors[i].First.ADR->MyMeta) );
            //---------------------------------------------------------------------------------
            TMTList<TLink> LL;
            SelectAllLinks(Floors[i].First.ADR,&LL);
            for(int i=0;i<LL.Count;i++)
                if (LL[i].MyMeta->Link->InWeb)
                    LN->Changed(&LL[i]);
            //---------------------------------------------------------------------------------
        }
    for (int i=0;i<Clients.Count;i++)
    {
        Clients[i].Floors.Delete(index);
        Clients[i].Visible.Delete(index);
    }
    ActiveIndex = MIN(index,Floors.Count-1);
}

TMyRegObject *TMainTree::AddChild(TMyRegObject *Node,TMyRegObject *NewNode)
{
    NewNode->MyTree = this;
    if (!Node)
    {
        if (Head)
            Clear();
        Head = NewNode;
    }
    if (!load)
        OnAddNode((TElement*)Node,(TElement*)NewNode);
    AskedToSave  = false;
           
    return NewNode;
}

void TMainTree::OnAddNode(TMyRegObject* _Target,TMyRegObject* _Source)
{
     if (load)
        return;
    TElement *Source = (TElement *)_Source;
    int floorindex;
    Source->SetMode();
    if (Source != Head && Source->Parent!=Head)
    {
        if ( (floorindex = FloorOf(Source))==-1 )
            SERVICE->Add( new TPointer<TElement>(Source) );
        else
            Floors[floorindex].Add(Source);
    }

}

void TMainTree::ReFillElements()
{
    SERVICE->Clear();
    for (int i=0;i<Floors.Count;i++)
    {
        Floors.Items[i]->VFIRST->Clear();
        Floors.Items[i]->VTRANS->Clear();
        Floors.Items[i]->VLABEL->Clear();
    }
    TMTList<TMyRegObject> MROL;
    SelectByCT(NULL,TElement::StaticType,&MROL,true,true);
    for (int i=0;i<MROL.Count;i++)
        OnAddNode(MROL[i].Parent,&MROL[i]);
}

TElement *TMainTree::AddElement(TElement *Target,TElement *Source)
{
    return (TElement*)AddChild(Target,Source);
}

TElement *TMainTree::AddFirst(TElement *_Head)
{
    return (TElement*)AddChild(NULL,_Head);
}

void TMainTree::Clear()
{
    while (Floors.Count)
        RemoveFloor(Floors.Count-1);
    if (Head)
    {
        KillElement( ((TElement*)Head) );
        Head = NULL;
    }
    SERVICE->Clear();
//    Floors.Clear();
/*    TQuickList* L = new TQuickList();
    for (int i=0;i<Clients.Count;i++)
        L->Add(Clients[i].MDI3D);
    Clients.Clear();
    for (int i=0;i<L->Count;i++)
        RegisterClient((TMDI3D*)L->Items[i]);
    delete L;*/
}


void TMainTree::LOW_HI(TIntVec& LOW,TIntVec& HI,bool No_Platforms,TUnit *Node,bool VisibleOnly)
{
    if (!Head)
    {
        return;
    }
    if (!Node)
    {
        LOW_HI(LOW,HI,No_Platforms,(TElement *)Head,VisibleOnly);
        return;
    }
    bool do_element = true;
    TElement* El = (TElement* )Node;
    if (VisibleOnly)
    {
        TClient3D* CL = GetActiveClient();
        bool VisibleOK = true;
        if (CL && !CL->VisibleAll)
            for (int i=0;i<CL->Floors.Count;i++)
                if (!CL->Visible[i] && CL->ActiveIndex!=i && El->In(CL->Floors[i].First.ADR))
                {
                    VisibleOK = false;
                    break;
                }
        do_element = VisibleOK;
    }
    if (No_Platforms && do_element)
        do_element = ((Node != Head) || (Head->ChildList->IndexOf(Node)!=-1) );
///////////////////////////////////Drive////////////////////////////////////////
    if (No_Platforms && do_element)
        if ( ActiveFloor != NULL ) {
            int i = 0;
            for ( ; i < FloorCount; i++ )
                if ( Node == GetFloor(i)->FirstElement )
                    break;
            if ( i < FloorCount )
                do_element = false;
        }
///////////////////////////////////Drive////////////////////////////////////////                
    if (do_element)
        El->LOW_HI(LOW,HI);

    for (int i=0;i<Node->ChildList->Count;i++)
        LOW_HI(LOW,HI,No_Platforms,(TUnit *)Node->ChildList->Items[i],VisibleOnly);
}

void TMainTree::Process_AddElement(TMetaElement *Mel,TElement* UseFloorElement)
{
    if (CheckPremises)
        for (int i=0;i<MetaNodeCollection->KernelSupport->MAE.Count;i++)
            MetaNodeCollection->KernelSupport->MAE[i].Fix_Changes(Mel,UseFloorElement);
    AUI.InvalidateView();
}

int TMainTree::IndexOfFloor(TFloor* Floor)
{
    return Floors.IndexOf(Floor);
}

void TMainTree::AutoConnect(TElement * Target, TElement * Source)
{
    TDynamicLink* DLink = GetLinkAnyWay(Target->MyMeta,Source->MyMeta);
    Source->DoNotDelete = true;
    Source->DeleteNeededLink();
    Source->DoNotDelete = false;
    CreateLinkFunction(Target,Source,DLink,Source->AbsPos);
}

TLink* TMainTree::Connect(TElement * Target, TElement * Source,TDynamicLink *_HardLink)
{
    TLINKPATTERN SGL;

    if (_HardLink->Needed && Source->NeededLink!=-1)
    {
        Source->DoNotDelete = true;
        Source->KillLink(Source,Source->NeededLink);
        Source->DoNotDelete = false;
    }
    SGL.DL = _HardLink;
    RunLink(Target,Source,SGL,ocmPosition);
    Source->UserChangePosition(SGL.TS_Common,SGL.R_Common);
    return CreateLink(SGL.DL,Target,Source,SGL.CrossPoint);
}

bool GoDriver(TElement * Source,TElement* FloorElement)
{
    TElement* OldEl = Driver.Element;
    TElement* OldFloorElement = Driver.FloorElement;
    Driver.Init(Source,false,FloorElement);
    bool result = Driver.Stop();
    if (OldEl)
        Driver.Init(OldEl,true,OldFloorElement);
    return result;
}

void TMainTree::UpdateMode(TElement* Node)
{
    if (!Head)
        return;
    if (!Node)
    {
        //----------------------------------------------------------------------
        if (!AUI.Mode)
            return;
        FPrevModeIndex = FModeIndex;
        FModeIndex = MetaNodeCollection->KernelSupport->Modes.IndexOf(AUI.Mode);
        if (FModeIndex == -1)
            FModeIndex = 0;
        //----------------------------------------------------------------------
        UpdateMode((TElement*)Head);
    }
    else
    {
        for (int i=0;i<Node->ChildList->Count;i++)
            UpdateMode((TElement*)Node->ChildList->Items[i]);
        ((TElement*)Node)->SetMode();
    }
    for (int i=0;i<Floors.Count;i++)
        Floors[i].First.ADR->ForceCreateView();
    AUI.InvalidateView();
}

void TMainTree::UpdateRegCreateView(TElement* Node)
{
    if (!Head)
        return;
    if (!Node)
        UpdateRegCreateView((TElement*)Head);
    else
    {
        for (int i=0;i<Node->ChildList->Count;i++)
            UpdateRegCreateView((TElement*)Node->ChildList->Items[i]);
        ((TElement*)Node)->RegisterCreateView(NULL);
    }
    AUI.InvalidateView();
}

int TMainTree::GetFloorCount()
{
    return Floors.Count;
}

TFloor* TMainTree::GetFloor(int i)
{
    return Floors.Items[i];
}

void TMainTree::SetActiveFloor(int i)
{
    TClient3D* Active = ActiveClient;
    if (Active && i>=0 && i<Floors.Count)
    {
        Active->ActiveIndex = i;
        AUI.InvalidateView();
    }
}

void TMainTree::SizerList(int FloorIndex,const TMDelTList<T3DScope>& SZR)
{
    
}

TDynamicLink* GetLinkAnyWay(TMetaElement* MetaTarget,TMetaElement* MetaSource)
{
    TDynamicLink* DLink = MetaSource->SearchNeededLinkFor(MetaTarget);
    if (!DLink)
        DLink = MetaNodeCollection->FreeLink(MetaTarget,MetaSource);
    return DLink;
}

