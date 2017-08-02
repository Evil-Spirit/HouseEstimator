 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LogicNode.h"
#include "MyGL.h"
#include "World.h"
#include "MySupportV.h"
#pragma package(smart_init)

TLinkNodes * LN;

TSide::TSide()
{
}

TSide::TSide(TIntVec *_P0,TIntVec *_P1)
{
    P0 = _P0;
    P1 = _P1;
    CenterP0 = NULL;
    CenterP1 = NULL;
    Node0 = NULL;
    Node1 = NULL;
    Element = NULL;
    Premises = NULL;
    ISWALLEND = false;
    ISWALLSTART = false;
}

TSide::TSide(TIntVec *_P0,TIntVec *_P1,TIntVec *_CP0,TIntVec *_CP1,TRouteNode* _Node0,TRouteNode* _Node1,int Type)
{
    P0 = _P0;
    P1 = _P1;
    CenterP0 = _CP0;
    CenterP1 = _CP1;
    Node0 = _Node0;
    Node1 = _Node1;
    SideType = Type;
    Element = NULL;
    Premises = NULL;
    ISWALLEND = false;
    ISWALLSTART = false;
}

bool TSide::IsOutSide()
{
    for (int i=0;i<LN->Buldings.Count;i++)
        if ( Premises == LN->Buldings.Items[i])
            return true;
    return false;
}

void TSide::UpdateEdge(TIntVec* NewDest, TIntVec* NewCenterDest,bool DestinationEdge,TRouteNode* NewNode)
{
    if (DestinationEdge)
    {
        P1 = NewDest;
        CenterP1 = NewCenterDest;
        Node1 = NewNode;
    }
    else
    {
        Node0 = NewNode;
        P0 = NewDest;
        CenterP0 = NewCenterDest;
    }
}

void TSide::SplitMeOrigin( TSide& New_, TIntVec* Middle, TIntVec* CenterMiddle,TRouteNode* RouteMiddle)
{
    New_.P1 = P1;
    New_.CenterP1 = CenterP1;
    New_.SideType = SideType;
    New_.Element = Element;

    New_.P0 = Middle;
    New_.CenterP0 = CenterMiddle;
    New_.Node0 = RouteMiddle;
    New_.Node1 = Node1;
    New_.ISWALLEND = ISWALLEND;

    ISWALLEND = false;
    P1 = Middle;
    CenterP1 = CenterMiddle;
    Node1 = RouteMiddle;
}

void TSide::SplitMeDestination( TSide& New_, TIntVec* Middle, TIntVec* CenterMiddle,TRouteNode* RouteMiddle)
{
    New_.P0 = P0;
    New_.CenterP0 = CenterP0;
    New_.SideType = SideType;
    New_.Element = Element;

    New_.P1 = Middle;
    New_.CenterP1 = CenterMiddle;
    New_.Node1 = RouteMiddle;
    New_.Node0 = Node0;
    New_.ISWALLSTART = ISWALLSTART;

    ISWALLSTART = false;

    P0 = Middle;
    CenterP0 = CenterMiddle;
    Node0 = RouteMiddle;
}


int TSide::Crossed(const TSide& ELSE,TIntVec& CROSS_POINT,MBTi USEEPS)
{
    return IsCutsCrossed(*(P0),*(P1),*(ELSE.P0),*(ELSE.P1),CROSS_POINT,USEEPS);
}

bool TSide::ConsistsPoint(const TIntVec& Point)
{
    switch(AnalizePoint(Point))
    {
        case etDESTINATION:
        case etORIGIN:
        case etBETWEEN:
            return true;
        default:
            return false;
    }
}

int TSide::AnalizePoint(const TIntVec& Point)
{
    return Classify(Point,*(P0),*(P1),INTEPS);
}



TRoutePoint::TRoutePoint(TRoutePoint* RPrev)
{
    if (RPrev)
    {
        TRoutePoint* RNext = RPrev->Next;
        RPrev->Next = this;
        RNext->Prev = this;
        Next = RNext;
        Prev = RPrev;
    }
    else
    {
        Prev = this;
        Next = this;
        InputSide = NULL;
        OutPutSide = NULL;
    }
    Pnt = NULL;
}

TRoutePoint::~TRoutePoint()
{
    if (Next != this)
    {
        Next->Prev = Prev;
        Prev->Next = Next;
    }
}

TRoutePoint::TRoutePoint()
{
    //нельзя использовать
    Prev = this;
    Next = this;
}

//---------------------------------------------------
TRay::TRay()
{
    XPlusDirection = false;
    ElementPoints = NULL;
    YMinusSide = NULL;
    YPlusSide = NULL;
    Point = NULL;
    AngleOX = 0;
}

bool TRouteNode::Satisfy(TLinkPair* LinkPair)
{
    LinkPair->UpdateIfNotActual();
    for (int i=0;i<LNKS.Count;i++)
        if (!LNKS[i].Satisfy(LinkPair->Pos))
            return false;
    return true;
}

void TRouteNode::ReCalculate_LinkPoint()
{
    LinkPoint = ZEROINTVEC;
    for (int i=0;i<LNKS.Count;i++)
    {
        LNKS[i].UpdateIfNotActual();
        LinkPoint+=LNKS[i].Pos;
    }
    if (LNKS.Count > 1)
        LinkPoint /= LNKS.Count;
}


void TRouteNode::Add(TLinkPair* LinkPair)
{

    bool AddElement[2] = {true,true};
    for (int i=0;i<LNKS.Count;i++)
    {
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
            if (LNKS[i].Link->Elements[j] == LinkPair->Link->Elements[k])
                AddElement[k] = false;
        if ( !AddElement[0] && !AddElement[1])
            break;
    }
    LNKS.Add(LinkPair);
    //-------------------
    ReCalculate_LinkPoint();
    //some code here

    for (int j=0;j<2;j++)
        if (AddElement[j])
        {
            int index = LN->ExistsElem(LinkPair->Link->Elements[j]);
            LN->EP[index].Register_Route_Node_01(this);
        }
}

void TRouteNode::Delete(int index)
{
    //some code here
    TLinkPair* LinkPair = LNKS.Items[index];
    LNKS.Delete(index);
    //-------------------
    ReCalculate_LinkPoint();
    bool RemoveElement[2] = {true,true};
    for (int i=0;i<LNKS.Count;i++)
    {
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
            if (LNKS[i].Link->Elements[j] == LinkPair->Link->Elements[k])
                RemoveElement[k] = false;
        if ( !RemoveElement[0] && !RemoveElement[1])
            break;
    }
    for (int j=0;j<2;j++)
        if (RemoveElement[j])
        {
            int index = LN->ExistsElem(LinkPair->Link->Elements[j]);
            if (index!=-1)
                LN->EP[index].UnRegister_Route_Node_01(this);
        }
}

int TRouteNode::IndexOf(TLinkPair* LinkPair)
{
    return LNKS.IndexOf(LinkPair);
}

void TRouteNode::Direct_Insert_Ray_By_Angle(TRay* Ray)
{
    for (int i=0;i<Rays.Count;i++)
        if (Ray->AngleOX > Rays[i].AngleOX)
        {
            Rays.Insert(i,Ray);
            return;
        }
    Rays.Add(Ray);
}

void TRouteNode::CreateRays_03()
{
    Rays.Clear();
    CPS.Clear();
    TMTList<TElementPoints> EP;
    TMTList<TElement> ELS;
    for (int i=0;i<LNKS.Count;i++)
        for (int j=0;j<2;j++)
            if ( LN->Satisfy_Meta(LNKS[i].Link->Elements[j]) && ELS.IndexOf(LNKS[i].Link->Elements[j]) == -1)
                ELS.Add(LNKS[i].Link->Elements[j]);

    for (int i=0;i<ELS.Count;i++)
    {
        int index = LN->ExistsElem(ELS.Items[i]);
        EP.Add(LN->EP.Items[index]);
    }
    for (int i=0;i<EP.Count;i++)
    {
        int my_index = EP[i].FilterRNs.IndexOf(this);
        TIntVec* NextPoint = (my_index == EP[i].FilterRNs.Count-1)?  &EP[i].HI : &EP[i].FilterRNs[my_index+1].LinkPoint;
        TIntVec* PrevPoint = (my_index == 0)? &EP[i].LOW : &EP[i].FilterRNs[my_index-1].LinkPoint;
        int in_direction = EP[i].IsEdge(LinkPoint,CloseEPS.x);
        if (in_direction == 1 || in_direction == 0 )
        {
            //plusX
            TRay* Ray = new TRay();
            Ray->ElementPoints = EP.Items[i];
            Ray->XPlusDirection = true;
            Ray->Point = PrevPoint;
            Ray->AngleOX = (AngleRadOX(LinkPoint,*Ray->Point)*180)/M_PI;
            Ray->YMinusSide = EP[i].FindSide(stYMinus,&(LinkPoint),false);
            Ray->YPlusSide = EP[i].FindSide(stYPlus,&(LinkPoint),true);
            Direct_Insert_Ray_By_Angle(Ray);
        }
        if (in_direction == -1 || in_direction == 0 )
        {
            //minusX
            TRay* Ray = new TRay();
            Ray->ElementPoints = EP.Items[i];
            Ray->XPlusDirection = false;
            Ray->Point = NextPoint;
            Ray->AngleOX = (AngleRadOX(LinkPoint,*Ray->Point)*180)/M_PI;
            Ray->YMinusSide = EP[i].FindSide(stYMinus,&(LinkPoint),true);
            Ray->YPlusSide = EP[i].FindSide(stYPlus,&(LinkPoint),false);
            Direct_Insert_Ray_By_Angle(Ray);
        }
    };
}

void TRouteNode::Cross_Sides_04()
{
    for (int i=0;i<Rays.Count;i++)
    {
        TSide* Side_ = (Rays[i].XPlusDirection) ? Rays[i].YPlusSide : Rays[i].YMinusSide;
        TSide* Side_Next = (Rays.CycleItems[i+1]->XPlusDirection) ? Rays.CycleItems[i+1]->YMinusSide : Rays.CycleItems[i+1]->YPlusSide;
        TIntVec* NewCrossPoint = new TIntVec();
        CPS.Add(NewCrossPoint);
        TIntVec** UpdatePoint_ = &Side_->P1;
        TIntVec** UpdatePoint_Next = &Side_Next->P0;
        int res = IsLinesCrossedExactly(*Side_->P0,*Side_->P1,*Side_Next->P0,*Side_Next->P1,*NewCrossPoint);
        if ( res == lcPARALLEL || res == lcCOLLINEAR)
            *NewCrossPoint = (**UpdatePoint_ + **UpdatePoint_Next)/2;
        *UpdatePoint_ = NewCrossPoint;
        *UpdatePoint_Next = NewCrossPoint;
    }
}

//---------------------------------------------------------------------------
TLinkPair::TLinkPair()
{
    Pos = ZEROINTVEC;
    Link = NULL;
    Actual = false ;
};

void TLinkPair::Update()
{
    Link->Elements[0]->AbsFromLocal(Link->Position0,Pos);
    Actual = true;
}

void TLinkPair::UpdateIfNotActual()
{
    if (!Actual)
        Update();
}

bool TLinkPair::Satisfy(const TIntVec& ElseVec )
{
    UpdateIfNotActual();
    return (ABSINTVEC(Pos-ElseVec) <= CloseEPS);
}

void TLinkPair::GetTranslate(const TIntVec& From,TIntVec& Translate)
{
    UpdateIfNotActual();
    Translate = Pos - From;
}

//---------------------------------------------------------------------
TElementTrioPoint::TElementTrioPoint()
{
    RouteNode = NULL;
    RoutePnts[0] = NULL;
    RoutePnts[1] = NULL;
    RoutePnts[2] = NULL;
}

TSide* TElementPoints::FindSide(int Type,TIntVec* Point,bool ByDestination)
{
    for (int i=0;i<Sides.Count;i++)
        if (Type == Sides[i].SideType)
        {
            if (ByDestination && Sides[i].CenterP1 == Point)
                return Sides.Items[i];
            if (!ByDestination && Sides[i].CenterP0 == Point)
                return Sides.Items[i];
        }
    return NULL;
}

int TElementPoints::IsEdge(const TIntVec& Point,MBTi USEEPS)//(1) - plus, (-1) - minus
{
    TIntVec LocalPoint;
    Element->LocalFromAbs(Point,LocalPoint);
    if ( fabs(LocalPoint.x - Element->AbsSize.x/2) < USEEPS )
        return 1;
    if ( fabs(LocalPoint.x + Element->AbsSize.x/2) < USEEPS )
        return -1;
    return 0;
}

void TElementPoints::Register_Route_Node_01(TRouteNode* RN)
{
    if (AllRNs.IndexOf(RN)!=-1)
        return;
    TIntVec LocPoint;
    Element->LocalFromAbs(RN->LinkPoint,LocPoint);

    for (int i=0;i<AllRNs.Count;i++)
    {
        TIntVec CurLocPoint;
        Element->LocalFromAbs(AllRNs[i].LinkPoint,CurLocPoint);
        if (CurLocPoint.x > LocPoint.x )
        {
            AllRNs.Insert(i,RN);
            return;
        }
    }
    AllRNs.Add(RN);
}

void TElementPoints::UnRegister_Route_Node_01(TRouteNode* RN)
{
    AllRNs.Remove(RN);
    for (int i=0;i<Sides.Count;i++)
    {
        if (Sides[i].Node0 == RN)
            Sides[i].Node0 = NULL;
        if (Sides[i].Node1 == RN)
            Sides[i].Node1 = NULL;
    }
}


void TElementPoints::Create_Sides_02()
{
    UpdateIfNotActual();
    Sides.Clear();
    FirstPoints.Clear();
    FilterRNs.Clear();
    for (int i=0;i<AllRNs.Count;i++)
        if ( LN->Satisfy_Meta(AllRNs.Items[i]) )
            FilterRNs.Add(AllRNs.Items[i]);

    TIntVec LocalLOW;
    TIntVec LocalHI;
    Element->LocalFromAbs(LOW,LocalLOW);
    Element->LocalFromAbs(HI,LocalHI);

    TMDelTList<TIntVec> LocalNodes;
    for (int i=0;i<FilterRNs.Count;i++)
    {
        LocalNodes.Add(new TIntVec);
        Element->LocalFromAbs(FilterRNs[i].LinkPoint,LocalNodes[i]);
    }

    FirstPoints.Add( new TIntVec );
    Element->AbsFromLocal( TIntVec(-Element->AbsSize.x/2,-Element->AbsSize.y/2,Element->AbsSize.z/2),*(FirstPoints.Last()) );
    FirstPoints.Add( new TIntVec );
    Element->AbsFromLocal( TIntVec(-Element->AbsSize.x/2,Element->AbsSize.y/2,Element->AbsSize.z/2),*(FirstPoints.Last()) );

    FirstPoints.Add( new TIntVec );
    Element->AbsFromLocal( TIntVec(Element->AbsSize.x/2,Element->AbsSize.y/2,Element->AbsSize.z/2),*(FirstPoints.Last()) );
    FirstPoints.Add( new TIntVec );
    Element->AbsFromLocal( TIntVec(Element->AbsSize.x/2,-Element->AbsSize.y/2,Element->AbsSize.z/2),*(FirstPoints.Last()) );


    //create low side
    bool lowadded = false;
    bool hiadded = false;
    if (!LocalNodes.Count || fabs(LocalNodes[0].x - LocalLOW.x) > CloseEPS.x )
    {
        Sides.Add( new TSide(&FirstPoints[0],&FirstPoints[1],&(LOW),&(LOW),NULL,NULL,stXMinus ) );
        Sides.Last()->Element = Element;
        lowadded = true;
    }

    //create hi side
    if (!LocalNodes.Count || fabs(LocalNodes.Last()->x - LocalHI.x) > CloseEPS.x )
    {
        Sides.Add( new TSide(&FirstPoints[2],&FirstPoints[3],&(HI),&(HI),NULL,NULL,stXPlus ) );
        Sides.Last()->Element = Element;
        hiadded = true;
    }

    Sides.Add( new TSide(&FirstPoints[1],&FirstPoints[2],&(LOW),&(HI),NULL,NULL,stYPlus ) );
    Sides.Last()->ISWALLEND = true;
    Sides.Last()->ISWALLSTART = true;
    Sides.Last()->Element = Element;
    Sides.Add( new TSide(&FirstPoints[3],&FirstPoints[0],&(HI),&(LOW),NULL,NULL,stYMinus ) );
    Sides.Last()->Element = Element;
    Sides.Last()->ISWALLEND = true;
    Sides.Last()->ISWALLSTART = true;
    if (!lowadded)
    {
        Sides[Sides.Count-2].CenterP0 = &(FilterRNs[0].LinkPoint);
        Sides[Sides.Count-1].CenterP1 = &(FilterRNs[0].LinkPoint);
        Sides[Sides.Count-2].Node0 = &(FilterRNs[0]);
        Sides[Sides.Count-1].Node1 = &(FilterRNs[0]);
    }
    if (!hiadded)
    {
        Sides[Sides.Count-2].CenterP1 = &(FilterRNs.Last()->LinkPoint);
        Sides[Sides.Count-1].CenterP0 = &(FilterRNs.Last()->LinkPoint);
        Sides[Sides.Count-2].Node1 = FilterRNs.Last();
        Sides[Sides.Count-1].Node0 = FilterRNs.Last();
    }
    
    for (int i=1-lowadded;i<LocalNodes.Count-1+hiadded;i++)
    {
        TSide* newstYPlus = new TSide(NULL,NULL);
        TSide* newstYMinus = new TSide(NULL,NULL);
        TIntVec* YPlusMiddle = new TIntVec(LocalNodes[i].x,Element->AbsSize.y/2,Element->AbsSize.z/2);
        TIntVec* YMinusMiddle = new TIntVec(LocalNodes[i].x,-Element->AbsSize.y/2,Element->AbsSize.z/2);
        Element->AbsFromLocal(*YPlusMiddle,*YPlusMiddle);
        Element->AbsFromLocal(*YMinusMiddle,*YMinusMiddle);
        TIntVec* CenterMiddle = &(FilterRNs[i].LinkPoint);
        Sides[Sides.Count-2].SplitMeOrigin(*newstYPlus,YPlusMiddle,CenterMiddle,&(FilterRNs[i]));
        Sides[Sides.Count-1].SplitMeDestination(*newstYMinus,YMinusMiddle,CenterMiddle,&(FilterRNs[i]));
        Sides.Add(newstYPlus);
        Sides.Add(newstYMinus);
        FirstPoints.Add(YPlusMiddle);
        FirstPoints.Add(YMinusMiddle);
    }

}

void TElementPoints::Update()
{
    if (PNTS.Count==0)
    {
        PNTS.Add(new T3DScope());
        PNTS[0].LOW = ZEROINTVEC;
        PNTS[0].HI = ZEROINTVEC;
    }
    PNTS[0].LOW.x = -Element->AbsSize.x/2;
    PNTS[0].HI.x = Element->AbsSize.x/2;
    PNTS[0].LOW.z = Element->AbsSize.z/2;
    PNTS[0].HI.z = Element->AbsSize.z/2;
    
    LOW = TIntVec(-Element->AbsSize.x/2,0,Element->AbsSize.z/2);
    HI = TIntVec(Element->AbsSize.x/2,0,Element->AbsSize.z/2);
    Element->AbsFromLocal(LOW,LOW);
    Element->AbsFromLocal(HI,HI);
    Actual = true;
}

void TElementPoints::UpdateIfNotActual()
{
    if (!Actual)
        Update();
}

TIntVec Service_Vector;
void TElementPoints::GetTranslate(const TIntVec& From,TIntVec& Translate)
{
    UpdateIfNotActual();
    Element->LocalFromAbs(From,Service_Vector);
    PNTS[0].PointAbout(Service_Vector,Translate);
    Element->AbsFromLocal(Translate,Translate);
    Translate -= Element->AbsPos;
}

void TElementPoints::GetTranslateStep(const TIntVec& From,TIntVec& Translate,const TIntVec& Step)
{
    UpdateIfNotActual();
    Element->LocalFromAbs(From,Service_Vector);
    PNTS[0].PointAbout(Service_Vector,Translate,Step);
    Element->AbsFromLocal(Translate,Translate);
    Translate -= Element->AbsPos;
}

TElementPoints::TElementPoints()
{
    Element = NULL;
    Actual = false ;
};

//-----------------------------------------------------------------------------
int TLinkNodes::Exists(TLink *Link)
{
    for (int i=0;i<LP.Count;i++)
        if (LP[i].Link == Link)
            return i;
    return -1;
}

void TLinkNodes::Reg(TLink *Link)
{
    if (Exists(Link)!=-1)
        return;

    LP.Add(new TLinkPair());
    LP[LP.Count-1].Link = Link;

    //------------------------------
    NetActual = false;
    for (int i=0;i<RNS.Count;i++)
        if (RNS[i].Satisfy(LP.Last()) && RNS[i].IndexOf(LP.Last())==-1 )
        {
            RNS[i].Add(LP.Last());
            return;
        }
    RNS.Add(new TRouteNode());
    RNS.Last()->Add(LP.Last());
}

void TLinkNodes::UnReg(TLink *Link)
{
    int index = Exists(Link);
    if ( index!=-1)
    {
        for (int i=0;i<RNS.Count;i++)
        {
            int rns_index = RNS[i].IndexOf( LP.Items[index] );
            if (rns_index!=-1)
            {
                RNS[i].Delete(rns_index);
                if ( RNS[i].LNKS.Count == 0 )
                    RNS.Delete(i);
                break;
            }
        }
        LP.Delete(index);
    }
    NetActual = false;
    ProcessVisualNodeByLink(Link,true);
}

void TLinkNodes::Changed(TElement *Elem)
{
    int index = ExistsElem(Elem);
    if (index!=-1)
    {
        EP[index].Actual = false;
        NetActual = false;
    }
}

void TLinkNodes::Changed(TLink *Link)
{
    int index = Exists(Link);
    LP[index].Actual = false;
    NetActual = false;
}

void TLinkNodes::GetLinksForVec(const TIntVec& Vec,TMTList<TLink>* LNKL,TElement* Parent)
{
    LNKL->Clear();
    for (int i=0;i<LP.Count;i++)
        if (LP[i].Link->Elements[0]->In(Parent) &&
            LP[i].Link->Elements[1]->In(Parent) &&
            LP[i].Satisfy(Vec))
            LNKL->Add(LP[i].Link);
}

void TLinkNodes::GetLinksForLink(TLink *Link,TMTList<TLink>* LNKL,bool Excluded)
{
    TElement* Parent = NULL;
    if (World->Head)
        for (int i=0;i<World->Head->ChildList->Count;i++)
            if (Link->Elements[0]->In(World->Head->ChildList->Items[i]) ||
                Link->Elements[1]->In(World->Head->ChildList->Items[i]) )
            {
                Parent = (TElement*)World->Head->ChildList->Items[i];
                break;
            }
    if (!Parent)
        return;
    if (!Excluded && ( !Link->Elements[0]->In(Parent) || !Link->Elements[0]->In(Parent) ) )
        return;

    TIntVec Vec;
    Link->Elements[0]->AbsFromLocal(Link->Position0,Vec);
    GetLinksForVec(Vec,LNKL,Parent);
}

TElement* TLinkNodes::SelectNearestPoint(const TIntVec& Point,TMTList<TMetaElement>* ELS,TMDelTList<TIntVec>* Steps,TIntVec& Trans)
{
    TIntVec ServTrans;
    Trans = TIntVec(1<<30,1<<30,1<<30);
    TElement* Elems = NULL;
    int index;
    for (int i=0;i<EP.Count;i++)
        if (  (index=ELS->IndexOf(EP[i].Element->MyMeta)) != -1  )
        {
            if (Steps && Steps->Count>index)
                EP[i].GetTranslateStep(Point,ServTrans,*(Steps->Items[index]));
            else
                EP[i].GetTranslate(Point,ServTrans);
            if (Measure(Trans)>Measure(ServTrans))
            {
                Trans = ServTrans;
                Elems = EP[i].Element;
            }
        }
    if (Trans == TIntVec(1<<30,1<<30,1<<30))
        Trans = ZEROINTVEC;
    return Elems;
}

void TLinkNodes::SetMetaFilter( TMTList<TMetaElement>& newFilter)
{
    if ( !FEMetaFilter.Same(&newFilter) )
    {
        FEMetaFilter.Assign(&newFilter);
        NetActual = false;
    }
}

void TLinkNodes::ClearMetaFilter()
{
    if (FEMetaFilter.Count!=0)
    {
        FEMetaFilter.Clear();
        NetActual = false;
    }
};

void TLinkNodes::AddToMetaFilter(TMetaElement* MetaElement)
{
    if (FEMetaFilter.IndexOf(MetaElement) == -1)
    {
        FEMetaFilter.Add(MetaElement);
        NetActual = false;
    }
};

void TLinkNodes::RemoveFromMetaFilter(TMetaElement* MetaElement)
{
    int index = FEMetaFilter.IndexOf(MetaElement);
    if (index!=-1)
    {
        FEMetaFilter.Delete(index);
        NetActual = false;
    }
}

int TLinkNodes::IndexOfFilterMetaElement(TMetaElement* MetaElement)
{
    return FEMetaFilter.IndexOf(MetaElement);
}


TLink* TLinkNodes::SelectNearestLink(const TIntVec& Point,TIntVec& Trans,TMetaElement* El0,TMetaElement* El1)
{
    if (LP.Count==0)
        return NULL;
    TIntVec ServTrans;
    Trans = TIntVec(1<<10,1<<10,1<<10);
    TLink* Link = NULL;
    for (int i=0;i<LP.Count;i++)
        if (El0 == LP[i].Link->MyMeta->El0 && El1 == LP[i].Link->MyMeta->El1 ||
            El0 == LP[i].Link->MyMeta->El1 && El1 == LP[i].Link->MyMeta->El0)
        {
            LP[i].GetTranslate(Point,ServTrans);
            if (Measure(Trans)>Measure(ServTrans))
            {
                Trans = ServTrans;
                Link = LP[i].Link;
            }
        }
    return Link;
}

void TLinkNodes::CreateAllSides_02()
{
    for (int i=0;i<EP.Count;i++)
        if (Satisfy_Meta(EP[i].Element))
            EP[i].Create_Sides_02();
}

void TLinkNodes::CreateAllRays_03()
{
    for (int i=0;i<RNS.Count;i++)
        if (Satisfy_Meta(RNS.Items[i]))
            RNS[i].CreateRays_03();
}

void TLinkNodes::Cross_All_Sides_04()
{
    for (int i=0;i<RNS.Count;i++)
        if (Satisfy_Meta(RNS.Items[i]))
            RNS[i].Cross_Sides_04();
}

TSide* FindInSidesByEdge(TMTList<TSide>* Sides,TIntVec* EDGE,bool ByDestination)
{
    for (int i=0;i<Sides->Count;i++)
        if (ByDestination && Sides->Items[i]->P1 == EDGE || !ByDestination && Sides->Items[i]->P0 == EDGE)
        {
            TSide* S = Sides->Items[i];
            Sides->Delete(i);
            return S;
        }
    return NULL;
}

void TLinkNodes::CreatePolygons_05()
{
    RPTS.Clear();
    TMTList<TSide> Sides;
    TMDelTList<TMTList<TSide> > Directed_Sides;
    for (int i=0;i<EP.Count;i++)
        if (Satisfy_Meta(EP[i].Element))
            for (int j=0;j<EP[i].Sides.Count;j++)
                Sides.Add(EP[i].Sides.Items[j]);
    while (Sides.Count)
    {
        TSide* S = NULL;
        Directed_Sides.Add(new TMTList<TSide>);
        Directed_Sides.Last()->Add(Sides.First());
        Sides.Delete(0);
        while ( (S = FindInSidesByEdge(&Sides,Directed_Sides.Last()->Last()->P1,false))!=NULL )
            Directed_Sides.Last()->Add(S);
    }
    for (int i=0;i<Directed_Sides.Count;i++)
    {
        RPTS.Add( new TMDelTList<TRoutePoint> );
        for (int j=0;j<Directed_Sides[i].Count;j++)
        {
            TRoutePoint* RP = (j==0)? new TRoutePoint(NULL) : new TRoutePoint(RPTS[i].Items[j-1]);
            RPTS[i].Add(RP);
            RP->Pnt = Directed_Sides[i][j].P0;
            RP->InputSide = (j==0)? Directed_Sides[i].Last() : Directed_Sides[i].Items[j-1];
            RP->OutPutSide = Directed_Sides[i].Items[j];
        }
    }
}


void TLinkNodes::ReBuildNet()
{
    RPTS.Clear();
    Premises.Clear();
    Buldings.Clear();
    SERVICE.Clear();

    CreateAllSides_02();
    CreateAllRays_03();
    Cross_All_Sides_04();
    CreatePolygons_05();
    NetActual = true;
}

void TLinkNodes::UpdateIfNotActual()
{
    if (!NetActual)
        ReBuildNet();
}


void TLinkNodes::RegElem(TElement *Elem)
{
    if (ExistsElem(Elem)!=-1)
        return;
    EP.Add(new TElementPoints());
    EP[EP.Count-1].Element = Elem;
    Elem->ElementPoints = EP.Last();
    NetActual = false;
//    EP[EP.Count-1].First_Route_Points();
}

int TLinkNodes::ExistsElem(TElement *Elem)
{
    for (int i=0;i<EP.Count;i++)
        if (EP[i].Element == Elem)
            return i;
    return -1;
}

void TLinkNodes::UnRegElem(TElement *Elem)
{
    int index = ExistsElem(Elem);
    Elem->ElementPoints = NULL;
    if ( index!=-1 )
    {
        EP.Delete(index);
        NetActual = false;
    }
}

bool TLinkNodes::Satisfy_Meta(TElement* El)
{
    if (FEMetaFilter.Count==0)
        return true;
    return FEMetaFilter.IndexOf(El->MyMeta)!=-1;
}

bool TLinkNodes::Satisfy_Meta(TLink* Link)
{
    if (FEMetaFilter.Count==0)
        return true;
    return (FEMetaFilter.IndexOf(Link->MyMeta->El0)!=-1) && (FEMetaFilter.IndexOf(Link->MyMeta->El1)!=-1) ;
}

bool TLinkNodes::Satisfy_Meta(TRouteNode* RN)
{
    if (RN->LNKS.Count==0 || FEMetaFilter.Count==0)
        return true;
    for (int i=0;i<RN->LNKS.Count;i++)
        if (Satisfy_Meta(RN->LNKS[i].Link) )
            return true;
    return false;
}

bool TLinkNodes::GetPremisesActual(TElement* newParentFilter)
{
    return NetActual && (newParentFilter == ParentFilter) && Buldings.Count>0;
}

void SetPolygonToRouterSides(TPolygon* POL,TMDelTList<TRoutePoint>& Router)
{
    for (int i=0;i<Router.Count;i++)
    {
        Router[i].InputSide->Premises = POL;
        Router[i].OutPutSide->Premises = POL;
    }
}

void TLinkNodes::SetDefaultMetaFilter()
{
    SetMetaFilter(MetaNodeCollection->KernelSupport->WEBMETA);
}

void TLinkNodes::DefinePermises_06(TElement* newParentFilter)
{
    if (!World && !World->Head)
        return;
    if (!newParentFilter)
        newParentFilter = (TElement*)World->Head;
    if (GetPremisesActual(newParentFilter))
        return;
    UpdateIfNotActual();
    Premises.Clear();
    Buldings.Clear();
    SERVICE.Clear();
    
    ParentFilter = newParentFilter;
    TMDelTList<TPolygon > POLS;
    TMDelTList<bool> ClockWize;
    for (int i=0;i<RPTS.Count;i++)
    {
        bool not_use = false;
        SERVICE.Add(new TMTList<TIntVec>);
        for (int j=0;j<RPTS[i].Count;j++)
        {
            if ( ParentFilter && !RPTS[i][j].InputSide->Element->In(ParentFilter) )
            {
                not_use = true;
                break;
            }
            SERVICE.Last()->Add(RPTS[i].Items[j]->Pnt);
        }
        if (not_use)
            SERVICE.Delete(SERVICE.Count-1);
        else
        {
            POLS.Add(new TPolygon(SERVICE.Last()));
            ClockWize.Add( new bool(POLS.Last()->IsClockWize()==1) );
            POLS.Last()->Router = &RPTS[i];
        }
    }

    for (int i=0;i<POLS.Count;i++)
        if (!ClockWize[i])
        {
            Premises.Add( new THoledPolygon(SERVICE.Items[i]) );
            Premises.Last()->Router = POLS[i].Router;
            SetPolygonToRouterSides(Premises.Last(),*Premises.Last()->Router);
            SERVICE.Move(i,SERVICE.Count-1);
            POLS.Delete(i);
            ClockWize.Delete(i);
            i--;
        }
    TMTList<THoledPolygon> HPS2;
    while (POLS.Count)
    {
        HPS2.Clear();
        for (int i=0;i<Premises.Count;i++)
            if ( Premises[i].ConsistsPolygon(POLS.Items[0]) == p_pINSIDE )
                HPS2.Add(&Premises[i]);
        while (HPS2.Count>1)
            if( HPS2[0].ConsistsPolygon(&HPS2[1]) == p_pINSIDE)
                HPS2.Delete(0);
            else
                HPS2.Delete(1);
        if (HPS2.Count>0)
        {
            HPS2[0].Holes->Add( new TPolygon(SERVICE.Items[0]) );
            HPS2[0].Holes->Last()->Router = POLS.Items[0]->Router;
            SetPolygonToRouterSides(HPS2[0].Holes->Last(),*HPS2[0].Holes->Last()->Router);
            HPS2[0].Holes->Last()->Invert();
        }
        else
        {
            Buldings.Add( new THoledPolygon(SERVICE.Items[0]) );
            Buldings.Last()->Router = POLS.Items[0]->Router;
            SetPolygonToRouterSides(Buldings.Last(),*Buldings.Last()->Router);
            Buldings.Last()->Invert();
        }
        //иначе это внешний контур
        SERVICE.Move(0,SERVICE.Count-1);
        POLS.Delete(0);
        ClockWize.Delete(0);
    }
}

//TNodeType

bool ProcessVisualNodeByLink(TLink *L,bool Excluded)
{
  bool  _returned = true;
  if (L->MyMeta->Link->InWeb)
  {
    TMTList<TLink> *LL = new TMTList<TLink>();
    //-------------------------
    LN->GetLinksForLink(L, LL,Excluded);

    int i=0;
    while(i<LL->Count)
        if (!LL->Items[i]->MyMeta->Link->InWeb  || (LL->Items[i] == L && Excluded) )
            LL->Delete(i);
        else
            i++;

    if (LL->Count==0)
        return true;
    if (Excluded)
        L = LL->Items[0];
    int result = AnalizeNode( LL,POLEPS,0);

    switch (result)
    {
        case 0:
            _returned = false;
        break;
        case 1:
            L->ProcessVisual();
        break;
        default:
        {
            TLink *BL=NULL;
            MBTi Eps_180 = 1<<20;
            MBTi Cur_Eps;
            MBTi Ang;
            for (int i=0;i<LL->Count;i++)
            {
                Ang = LL->Items[i]->GeomAngle();
                while (Ang>=360)
                    Ang-=360;
                while (Ang<0)
                    Ang+=360;
                Cur_Eps = fabs( Ang-180 );
                bool BLSameEls = (BL)&&(BL->Elements[0]->MyMeta == BL->Elements[1]->MyMeta);
                bool LLItemSameEls = (LL->Items[i]->Elements[0]->MyMeta == LL->Items[i]->Elements[1]->MyMeta);
                if ( (BLSameEls<LLItemSameEls)||(BLSameEls==LLItemSameEls && Cur_Eps<Eps_180) )
                {
                    Eps_180 = Cur_Eps;
                    BL = LL->Items[i];
                }
            }
            for (int i=0;i<LL->Count;i++)
                LL->Items[i]->ProcessUnVisual();
            MBTi x0 = fabs(BL->GetPos(0).x);
            MBTi x1 = fabs(BL->GetPos(1).x);
            if (fabs(x0-BL->Elements[0]->AbsSize.x/2)>=CloseEPS.x)
                break;
            if (fabs(x1-BL->Elements[1]->AbsSize.x/2)>=CloseEPS.x)
                break;
            BL->ProcessVisual();
        }
    }
    delete LL;
  }
  return _returned;
}

int AnalizeNode(TMTList<TLink>* LNKL,const TIntVec& __EPS,int AXE)
{
    if (!LNKL->Count)
        return true;
    TMTList<TElement> *ELS = new TMTList<TElement>();
    TMDelTList<TIntVec> *LINKVECS = new TMDelTList<TIntVec>();
    TMDelTList<TIntVec> *SUN = new TMDelTList<TIntVec>();

    for (int i=0;i<LNKL->Count;i++)
    {
        if (!LNKL->Items[i]->MyMeta->Link->InWeb)
            continue;
        for (int j=0;j<2;j++)
            if (ELS->IndexOf(LNKL->Items[i]->Elements[j])==-1)
            {
                ELS->Add(LNKL->Items[i]->Elements[j]);
                LINKVECS->Add( new TIntVec(LNKL->Items[i]->GetPos(j)) );
            }
    }

    //-----------------------------------------------------------
    TIntVec SunCenter=RotateAround(   LNKL->Items[0]->GetPos(0),
                                    ELS->Items[0]->AbsAngle,
                                    ZEROINTVEC)+ELS->Items[0]->AbsPos;
    //-----------------------------------------------------------

    TIntVec Local_Pos;
    TIntVec Abs_Pos;
    for (int i=0;i<ELS->Count;i++)
    {

        //left
        Local_Pos = *(LINKVECS->Items[i]);
        Local_Pos.a[AXE] = -(ELS->Items[i]->AbsSize.a[AXE])/2;
        if ( fabs( Local_Pos.a[AXE] - LINKVECS->Items[i]->a[AXE] )>__EPS.a[AXE] )
        {
            Abs_Pos = RotateAround(    Local_Pos,
                                        ELS->Items[i]->AbsAngle ,
                                        ZEROINTVEC) + ELS->Items[i]->AbsPos;
            SUN->Add(new TIntVec(Abs_Pos));
        }

        //right
        Local_Pos.a[AXE] = (ELS->Items[i]->AbsSize.a[AXE])/2;
        if ( fabs( Local_Pos.a[AXE] - LINKVECS->Items[i]->a[AXE] )>__EPS.a[AXE] )
        {
            Abs_Pos = RotateAround(    Local_Pos,
                                       ELS->Items[i]->AbsAngle ,
                                       ZEROINTVEC) + ELS->Items[i]->AbsPos;
            SUN->Add(new TIntVec(Abs_Pos));
        }
    }
    //-----------------------------------------------------------------
    //--------------- теперь сам анализ -----------------
    int returned=-1;
    //проверка на количество лучей
    if (SUN->Count>4)
        returned = ntNULL;
    if (SUN->Count<2)
        returned = ntNULL;

    //проверка на углы лучей
    MBTi CurrentAngle;
    int _180thcount=0;
    if (returned != ntNULL)
    {
        for (int i=0;i<SUN->Count;i++)
            for (int j=i+1;j<SUN->Count;j++)
            {
                CurrentAngle = AngleRad(    *(SUN->Items[i]),
                                            SunCenter,
                                            *(SUN->Items[j]));
                CurrentAngle = CurrentAngle*180/M_PI;
                if ( CurrentAngle<=MinAngle-AngleEps || (360-CurrentAngle)<=MinAngle-AngleEps)
                {
                    returned = ntNULL;
                    break;
                }
                if ( fabs(CurrentAngle - 180) <= AngleEps )
                    _180thcount++;

            }
    }

    if (returned != ntNULL)
        switch (SUN->Count)
        {
            case 2:
                returned=ntONE;
            break;
            case 3:
            {
                if (_180thcount!=0)
                    returned = ntTWO;
                else
                    returned=ntTHREE;
            }break;
            case 4:
            {
                if (_180thcount!=0)
                    returned = ntFOUR;
                else
                    returned=ntFIVE;
            }break;
        }
    //-----------------------------------------------------------------
    delete SUN;
    delete ELS;
    delete LINKVECS;
    return returned;
}

int AllowLink(TLink *Link,TMTList<TLink>* LNKL)
{
    bool create = false;
    if (!LNKL)
    {
        LNKL = new TMTList<TLink>();
        create = true;
    }
    LNKL->Clear();
    LN->GetLinksForLink(Link, LNKL,false);
    int i=0;
    while(i<LNKL->Count)
        if (LNKL->Items[i]->MyMeta->Link->InWeb)
            i++;
        else
            LNKL->Delete(i);
    int result = AnalizeNode( LNKL,POLEPS,0);
    if (create)
        delete LNKL;
    return result;
}


