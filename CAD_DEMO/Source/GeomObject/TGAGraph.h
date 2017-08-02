//------------------------------------------------------------------------------

#ifndef TGAGraphH
#define TGAGraphH

#include "types.h"

//------------------------------------------------------------------------------

class TGAGraph : public TGAlgorithm
{
    MBTi MinWayRec(MBTi WayDepth, TGPoint* curN, TGPoint* B, TMTList<TGCut>& way);
    MBTi MinWayRec(MBTi WayDepth, TGPoint* curN, TGPoint* B, TMTList<TGCut>& way, TMTList<TGPoint>& notUsed);
    MBTi NextMinWayRec(MBTi WayDepth, TGPoint* curN, TGPoint* B, TMTList<TGCut>& way, TMDelTList< TMTList<TGCut> >& NUWays, TMTList<TGPoint>& notUsed);
    MBTi MinPassByNodesRec(TGPoint* A, TMTList<TGCut>& way);
    MBTi MinPassByNodesRec1(TGPoint* A, TMTList<TGCut>& way);
    MBTi MinPassByNodesRec1(TGPoint* A, TMTList<TGCut>& way, TMTList<MBTi>& weights);
    MBTi MinPassByMainsNodesRec(TGPoint* A, TMTList<TGCut>& way, TMTList<TGPoint>& Mains);
public:
	TGAGraph(TGeomObject &o) : TGAlgorithm(o){};

//------------------------------------------------------------------------------
    MBTi MinWay(TGPoint* A, TGPoint* B, TMTList<TGCut>& way);
    MBTi MinWay(TGPoint* A, TGPoint* B, TMTList<TGCut>& way, TMTList<TGPoint>& notUsed);
    MBTi NextMinWay(TGPoint* A, TGPoint* B, TMTList<TGCut>& way, TMDelTList< TMTList<TGCut> >& NUWays, TMTList<TGPoint>& notUsed);
    MBTi LenghtWay(TMTList<TGCut>& way);

    MBTi LenghtWay(TMTList<TGCut>& way, TMTList<MBTi>& weights);
    bool ExistCycle(TMTList<TGCut>& way);
    void GetBool(unsigned long int n, int CountBit, TMTList<int>& way);
    //WayConsistsNode
    bool NodeExistWay(TGPoint* Node, TMTList<TGCut>& way);
    //IsWay
    bool TrueWayRec(TGPoint* Node, TGPoint* cur, TMTList<TGCut>& way);
    //void MinSkeleton(TMTList<TGCut>& Skeleton);
    void MinPassByNodes(TGPoint* A, TMTList<TGCut>& way);
    void MinPassByMainsNodes(TGPoint* A, TMTList<TGCut>& way, TMTList<TGPoint>& Mains);
    void MinPassByNodes(TGPoint* A, TMTList<TGCut>& way, TMTList<MBTi>& weights);
//------------------------------------------------------------------------------

    virtual ~TGAGraph(){};
};

#endif
