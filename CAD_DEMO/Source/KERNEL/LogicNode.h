//---------------------------------------------------------------------------

#ifndef LogicNodeH
#define LogicNodeH
//---------------------------------------------------------------------------
#include "ElementV.h"

const TIntVec CloseEPS = TIntVec(0.005,0.005,0.005);


class THoledPolygon;


//side type
const int stYMinus = 0;
const int stYPlus = 1;
const int stXMinus=2;
const int stXPlus=3;

class TElement;
class TPolygon;
class TRouteNode;
class COMMONAL_API TSide
{
    public:
    TSide();
    TSide(TIntVec *_P0,TIntVec *_P1);
    TSide(TIntVec *_P0,TIntVec *_P1,TIntVec *_CP0,TIntVec *_CP1,TRouteNode* _Node0,TRouteNode* _Node1,int Type);
    virtual ~TSide(){};
    int SideType;
    TRouteNode* Node0;
    TIntVec* CenterP0;
    TIntVec* P0;
    TRouteNode* Node1;
    TIntVec* CenterP1;
    TIntVec* P1;
    TPolygon* Premises;
    TElement* Element;
    int Crossed(const TSide& ELSE,TIntVec& CROSS_POINT,MBTi USEEPS);
    int AnalizePoint(const TIntVec& Point);
    bool ConsistsPoint(const TIntVec& Point);
    void SplitMeDestination( TSide& New_, TIntVec* Middle, TIntVec* CenterMiddle,TRouteNode* RouteMiddle);
    void SplitMeOrigin( TSide& New_, TIntVec* Middle, TIntVec* CenterMiddle,TRouteNode* RouteMiddle);
    void UpdateEdge(TIntVec* NewDest, TIntVec* NewCenterDest,bool DestinationEdge,TRouteNode* NewNode);
    bool IsOutSide();

    bool ISWALLEND;
    bool ISWALLSTART;
} ;


class COMMONAL_API TLinkPair {
private:
public:
    TLinkPair();
    virtual ~TLinkPair(){};
    TIntVec Pos;
    TLink *Link;
    bool Actual;
    void Update();
    void UpdateIfNotActual();
    bool Satisfy(const TIntVec& ElseVec);
    void GetTranslate(const TIntVec& From,TIntVec& Translate);
};

class TRouteNode;
class TElementPoints;

class COMMONAL_API TRay {
public:
    TRay();
    virtual ~TRay(){};
    bool XPlusDirection;
    TElementPoints* ElementPoints;
    TSide* YMinusSide;
    TSide* YPlusSide;
    TIntVec* Point;
    MBTi AngleOX;
};

class COMMONAL_API TRoutePoint {
public:
    TRoutePoint(TRoutePoint* RPrev);
    TRoutePoint();
    virtual ~TRoutePoint();
    TIntVec* Pnt;
    TSide* InputSide;
    TSide* OutPutSide;
    TRoutePoint* Next;
    TRoutePoint* Prev;
};

class COMMONAL_API TRouteNode{
private:
    void ReCalculate_LinkPoint();
    void Direct_Insert_Ray_By_Angle(TRay* Ray);
    //---------------lua-----------------------
    int GetRayCount() {return Rays.Count;}
    int GetRayCrossCount() {return CPS.Count;};
    int GetLinkPairCount() {return LNKS.Count;};
    //--------------end lua---------------------
public:
    TRouteNode(){};
    virtual ~TRouteNode(){};

    TIntVec LinkPoint ;
    TMTList<TLinkPair> LNKS;
    TElement* Element;
    TMDelTList<TRay> Rays;
    TMDelTList<TIntVec> CPS;
    void CreateRays_03();
    void Cross_Sides_04();

    bool Satisfy(TLinkPair* LinkPair);
    void Add(TLinkPair* LinkPair);
    void Delete(int index);
    int IndexOf(TLinkPair* LinkPair);
    //-------------------lua-------------------------
    __property int RayCount = {read = GetRayCount};
    __property int LinkPairCount = {read = GetLinkPairCount};
    __property int RayCrossCount = {read = GetRayCrossCount};
    TLinkPair* GetLinkPair(int i) {return LNKS.Items[i];};
    TRay* GetRay(int i) {return Rays.Items[i];};
    TIntVec* GetRayCross(int i) {return CPS.Items[i];};
    //-------------------end lua-------------------------
};

class COMMONAL_API TElementTrioPoint {
public:
    TElementTrioPoint();
    virtual ~TElementTrioPoint(){};
    TIntVec* RoutePnts[3];
    TRouteNode* RouteNode;
};

class COMMONAL_API TElementPoints{
private:
    int GetSideCount() {return Sides.Count;}
    int GetFilteredRouteNodesCount() {return FilterRNs.Count;}
    int GetAllRouteNodesCount() {return AllRNs.Count;}
public:
    bool Body;
    bool Actual;
    void Update();
    TElement* Element;

    //Router
    TMDelTList<TIntVec> FirstPoints;
    TIntVec LOW;
    TIntVec HI;
    TMDelTList<TSide> Sides;
    void Create_Sides_02();
    TMTList<TRouteNode> AllRNs;//упорядочены по localX
    TMTList<TRouteNode> FilterRNs;//упорядочены по localX
    void Register_Route_Node_01(TRouteNode* RN);
    void UnRegister_Route_Node_01(TRouteNode* RN);
    int IsEdge(const TIntVec& Point,MBTi USEEPS);//(1) - plus, (-1) - minus
    TSide* FindSide(int Type,TIntVec* Point,bool ByDestination);
    //end Router

    TMDelTList<T3DScope> PNTS;

    TElementPoints();
    virtual ~TElementPoints(){};
    void UpdateIfNotActual();
    bool Satisfy(const TIntVec& ElseVec);
    void GetTranslate(const TIntVec& From,TIntVec& Translate);
    void GetTranslateStep(const TIntVec& From,TIntVec& Translate,const TIntVec& Step);

    //---------------lua-------------------------------------
    __property int SideCount = {read = GetSideCount};
    __property int FilteredRouteNodesCount = {read = GetFilteredRouteNodesCount};
    __property int AllRouteNodesCount = {read = GetAllRouteNodesCount};
    TSide* GetSide(int i){return Sides.Items[i];}
    TRouteNode* GetFilteredRouteNode(int i){return FilterRNs.Items[i];}
    TRouteNode* GetAllRouteNode(int i){return AllRNs.Items[i];}
};

class COMMONAL_API TLinkNodes {
private:

    int GetRNSCount(){return RNS.Count;};
    int GetEPCount(){return EP.Count;};
    int GetPremisesPolygonCount() {return Premises.Count;};
    int GetBuildingPolygonCount() {return Buldings.Count;};
    int GetRouterListsCount() {return RPTS.Count;}
    int GetMetaFilterCount(){return FEMetaFilter.Count;};
public:
    TMTList<TMetaElement> FEMetaFilter;
    bool NetActual;
    bool GetPremisesActual(TElement* newParentFilter);
    TLinkNodes(){ParentFilter = NULL;};
    virtual ~TLinkNodes(){};

    TMDelTList<TLinkPair> LP;
    TMDelTList<TElementPoints> EP;
    TMDelTList<TRouteNode> RNS;

    void Reg(TLink *Link);
    int Exists(TLink *Link);
    void UnReg(TLink *Link);
    void RegElem(TElement *Elem);
    int ExistsElem(TElement *Elem);
    void UnRegElem(TElement *Elem);
    void GetLinksForVec(const TIntVec& Vec,TMTList<TLink>* LNKL,TElement* Parent);
    void GetLinksForLink(TLink *Link,TMTList<TLink>* LNKL,bool Excluded);
    void Changed(TLink *Link);
    void Changed(TElement *Elem);
    TIntVec GetPos(TLink *Link);
    TElement* SelectNearestPoint(const TIntVec& Point,TMTList<TMetaElement>* ELS,TMDelTList<TIntVec>* Steps,TIntVec& Trans);
    TLink* SelectNearestLink(const TIntVec& Point,TIntVec& Trans,TMetaElement* El0,TMetaElement* El1);

    TMDelTList<TMDelTList<TRoutePoint> > RPTS;
    TMDelTList<THoledPolygon> Premises;
    TMDelTList<THoledPolygon> Buldings;
    TMDelTList<TMTList<TIntVec> > SERVICE;
    //--------------------------------------------------------------------------

    void ReBuildNet();
    void UpdateIfNotActual();
    void CreateAllSides_02();
    void CreateAllRays_03();
    void Cross_All_Sides_04();
    void CreatePolygons_05();
    void DefinePermises_06(TElement* ParentFilter);

    //---------------------lua----------------------------------------------
    __property int RouteNodeCount = {read = GetRNSCount};
    __property int ElementFragmentsCount = {read = GetEPCount};
    __property int PremisesPolygonCount = {read = GetPremisesPolygonCount};
    __property int BuildingPolygonCount = {read = GetBuildingPolygonCount};
    __property int RouterListsCount = {read = GetRouterListsCount};

    TRouteNode* GetRouteNode(int i) {return RNS.Items[i];};
    TElementPoints* GetElementFragments(int i) {return EP.Items[i];};
    THoledPolygon* GetPremisesPolygon(int i) {return Premises.Items[i];};
    THoledPolygon* GetBuildingPolygon(int i) {return Buldings.Items[i];};

    int GetRouterCount(int i) {return RPTS[i].Count;};
    TRoutePoint* GetRouter(int i,int j) { return RPTS.Items[i]->Items[j];}

    void ClearMetaFilter();
    void AddToMetaFilter(TMetaElement* MetaElement);
    void RemoveFromMetaFilter(TMetaElement* MetaElement);
    void SetMetaFilter(TMTList<TMetaElement>& MFL);
    int IndexOfFilterMetaElement(TMetaElement* MetaElement);
    void SetDefaultMetaFilter();

    __property int FilterMetaElementCount = {read = GetMetaFilterCount};
    TMetaElement*  GetFilterMetaElement(int i) {return FEMetaFilter.Items[i];}
    //-------------------------------------------------------------------------
    TElement* ParentFilter;




    bool Satisfy_Meta(TElement* El);
    bool Satisfy_Meta(TLink* Link);
    bool Satisfy_Meta(TRouteNode* RN);
};

extern COMMONAL_API TLinkNodes * LN;


const int ntNULL = 0;
const int ntONE = 1;
const int ntTWO = 2;
const int ntTHREE = 3;
const int ntFOUR = 4;
const int ntFIVE = 5;
const int MaxCount = 4;
const MBTi MinAngle = 45;
const MBTi AngleEps = 0.0001;

int COMMONAL_API AnalizeNode(TMTList<TLink>* LNKL,const TIntVec& __EPS,int AXE);

int COMMONAL_API AllowLink(TLink *Link,TMTList<TLink>* LNKL=NULL);

bool COMMONAL_API ProcessVisualNodeByLink(TLink *Link,bool Excluded);



#endif
