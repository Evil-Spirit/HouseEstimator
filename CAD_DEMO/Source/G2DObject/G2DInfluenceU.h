//---------------------------------------------------------------------------

#ifndef G2DInfluenceUH
#define G2DInfluenceUH
#include "G2DObjectV.h"
//---------------------------------------------------------------------------


class TCommonPoint {
public:
    TCommonPoint(){ Point=NULL; };
    ~TCommonPoint(){};
    TMTList< TMTList<TG2DPoint> > Skeletons;
    TG2DPoint* Point;
};

class TAngleLink;
class TDegreeRule;
class COMMONAL_API TFlowInfo {
private:
public:
    TFlowInfo(){};
    ~TFlowInfo(){};
    T2DGObject* Owner;
    TMTList<TG2DPoint> PntList;

    TG2DPoint* Point;
    TMTList<TG2DLink> Links;
    TMDelTList< TMTList<TG2DLink> > SkeletonLinks;

    TMTList<TG2DLink> NotSkeletonLinks;
    TMTList<TG2DPoint> NotSkeletonPntList;

    TMDelTList< TMTList<TG2DPoint> > MSPS;
//	TMDelTList< TMTList<TDegreeRule> > Skeleton_Rules;
    TMDelTList< TMTList<TG2DPoint> >  Skeletons;

    TMTList<TG2DCut> AllCuts;
    TMTList< TMTList<TG2DPoint> > EdgeCutSkeletons;
    TMDelTList< TMTList<TG2DCut> > EdgeCuts;//крайние отрезки дерева углов
    TMDelTList< TCommonPoint >  SkeletonCP;
    TMTList<TG2DPoint> InfluenceSequence;

    TMDelTList< TMDelTList< TMTList<TG2DCut> > >  SkeletonLegs;
    TMDelTList< TMTList<TG2DCut> > LinkedGroupOfCuts;
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
//void FillLinkedGroupOfCut(TFlowInfo& FlowInfo);



template <class T>
bool TMTListIntersect(const TMTList<T> &Src1, const TMTList<T> &Src2,TMTList<T> &Dst)
{
	bool HasIntersect = false;
	for (int i=0;i<Src1.Count;i++)
    	if ( Src2.IndexOf( Src1.Items[i] )!=-1 )
        {
			Dst.Add(Src1.Items[i]);
           	HasIntersect = true;
        }
    return HasIntersect;
}


#endif
