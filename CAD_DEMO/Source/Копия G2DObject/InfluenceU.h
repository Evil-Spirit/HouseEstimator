//---------------------------------------------------------------------------

#ifndef InfluenceUH
#define InfluenceUH
#include "G2DObjectV.h"
//---------------------------------------------------------------------------
#include "TreeV.h"


class TCommonPoint {
public:
    TCommonPoint(){ Point=NULL; };
    ~TCommonPoint(){};
    TMTList< TMTList<TG2DPoint> > Skeletons;
    TG2DPoint* Point;
};

class TAngleLink;
class COMMONAL_API TFlowInfo {
private:
public:
    TFlowInfo(){};
    ~TFlowInfo(){};
    T2DGObject* Owner;
    TMTList<TG2DPoint> PntList;

    TMTList<TG2DPoint> ChangedPnts;
    TG2DPoint* Point;
    TMTList<TG2DLink> Links;
    TMDelTList< TMTList<TG2DLink> > SkeletonLinks;

    TMTList<TG2DLink> NotSkeletonLinks;
    TMTList<TG2DPoint> NotSkeletonPntList;

    TMDelTList< TMTList<TG2DPoint> > MSPS;
    TMDelTList< TMTList<TG2DPoint> >  Skeletons;

    TMTList<TG2DCut> AllCuts;
    TMTList< TMTList<TG2DPoint> > EdgeCutSkeletons;
    TMDelTList< TMTList<TG2DCut> > EdgeCuts;//крайние отрезки дерева углов
    TMDelTList< TCommonPoint >  SkeletonCP;
    TMTList<TG2DPoint> InfluenceSequence;
};

void FindSkeletons(TFlowInfo& FlowInfo);
bool FindSkeleton(TDistanceLink* DisLink,TMTList<TG2DPoint>& Skeleton,TMTList<TG2DPoint>& PntList);
void FillNotSkeletonsLinksAndCommonPoints(TFlowInfo& FlowInfo);
bool CreateInfluenceSequence(TG2DPoint* MainPoint,TFlowInfo& FlowInfo);
//bool IsLinked(TG2DPoint* Point0,TG2DPoint* Point1,bool UseFixed,TMTList<TG2DLink>& Links);
bool Is_Skeletons_Fixed(TFlowInfo& FlowInfo);
bool ProcessAddPointToSequence(TG2DPoint* GPoint,TFlowInfo& FlowInfo);
bool Ensure_Not_Skeleton_Links(TG2DPoint* GPoint,TFlowInfo& FlowInfo);
bool CreateInfluence(TFlowInfo& FlowInfo,TG2DPoint* Point);
bool FindAngleEdges(TFlowInfo& FlowInfo);

bool IsLinkedTo(TMTList<TG2DPoint>& Skeleton,TG2DPoint* Point,bool UseFixed,TMTList<TG2DLink>& Links);
bool IsLinkCompleted(TMTList<TG2DPoint>& Skeleton,TG2DPoint* Point,bool UseFixed,TMTList<TG2DLink>& Links);


template <class T>
void TMTListAdd_NE(TMTList<T> &src, TMTList<T> &dst)
{
	for (int i=0;i<dst.Count;i++)
        if ( src.IndexOf(dst.Items[i]) == -1 )
    		src.Add(dst.Items[i]);
}

#endif
