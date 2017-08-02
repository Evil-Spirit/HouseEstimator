//---------------------------------------------------------------------------

#ifndef G2DKinematicsH
#define G2DKinematicsH
#include "G2DObjectV.h"
//---------------------------------------------------------------------------

class TCutGroup;
class TSkeleton {
private:
protected:
	TFlowInfo* FFlowInfo;
	int GetLimitDegreeCount(){return (Pnts.Count>1)? 3 : 2; }
	TMTList<TGUnit> FCheckedUnits;
	TMTList<TG2DCut> FCheckedCuts;
	TMTList<TG2DPoint> FCheckedPoints;
	TMTList<TDegreeRule> FCheckedRules;
    int GetCheckedUnitCount()				{	return FCheckedUnits.Count;			};
    int GetCheckedCutCount()				{	return FCheckedCuts.Count;			};
    int GetCheckedPointCount()				{	return FCheckedPoints.Count;  		};
    int GetCheckedRuleCount()				{	return FCheckedRules.Count;			};
public:
	TSkeleton(){FFlowInfo = NULL;LimaconOK = false;FixingPoint = NULL;};
	TSkeleton(TFlowInfo* aFlowInfo){FFlowInfo = aFlowInfo;LimaconOK = false;FixingPoint = NULL;};
	~TSkeleton(){};
	TMTList<TG2DPoint> Pnts;
	TMTList<TG2DCut> Cuts;
	__property int LimitDegreeCount 	= 	{	read 	= 	GetLimitDegreeCount		};
	__property TFlowInfo* FlowInfo 		= 	{	read 	= 	FFlowInfo				};

	//access routine
    int IndexOfUnit(TGUnit* Unit)			{	return FCheckedUnits.IndexOf(Unit);		};
    int IndexOfCut(TG2DCut* Cut)			{	return FCheckedCuts.IndexOf(Cut);		};
    int IndexOfPoint(TG2DPoint* Point)		{	return FCheckedPoints.IndexOf(Point);	};
    int IndexOfRule(TDegreeRule* Rule)		{	return FCheckedRules.IndexOf(Rule);		};
    TGUnit* GetCheckedUnit(int index)		{	return FCheckedUnits.Items[index];		};
    TG2DCut* GetCheckedCut(int index)		{	return FCheckedCuts.Items[index];		};
    TG2DPoint* GetCheckedPoint(int index)	{	return FCheckedPoints.Items[index];		};
    TDegreeRule* GetCheckedRule(int index)	{	return FCheckedRules.Items[index];		};
    __property int CheckedUnitCount 	=	{	read 	= 	GetCheckedUnitCount			};
    __property int CheckedCutCount 		= 	{	read 	= 	GetCheckedCutCount			};
    __property int CheckedPointCount 	= 	{	read 	= 	GetCheckedPointCount		};
    __property int CheckedRuleCount 	= 	{	read 	= 	GetCheckedRuleCount			};


	void FixByDistance(TG2DPoint* GPoint,TMTList<TG2DPoint>& NotPnts);
	void FixByAngle(TG2DPoint* GPoint1,TG2DPoint* GPoint2,TMTList<TG2DPoint>& NotPnts);
	bool HasOneLevel();
    bool RealizeGroup(TCutGroup& CG);
    TDegreeRule ServiceRule;
	//add unit
    bool RegisterFreedomDegree(TG2DPoint* Point,TDegreeRule* Rule);
    bool Check();
    TMTList<TG2DLink> Links;

	//-------------------------------------------------------------------------
	TMTList<TG2DCut> Legs;
	TMTList<TG2DPoint> SkeletonLegPoints;
	TMTList<TG2DPoint> NotSkeletonLegPoints;
    bool LimaconOK;
    bool CheckLimacon();
    TG2DPoint* FixingPoint;
};

class TCutGroup {
public:
	TCutGroup(){Realized = false;};
	virtual ~TCutGroup(){};
	TMTList<TG2DCut> Cuts;
    TMTList< TSkeleton > Skeletons;
	TMTList<TG2DCut> Edges;
    bool Realized;
    bool Realize();
};

class COMMONAL_API TFlowInfo {
private:
public:
    TFlowInfo(){};
    ~TFlowInfo(){};
    T2DGObject* Owner;
    TMDelTList< TSkeleton > Skeletons;
    TMTList< TG2DPoint >  SkeletonCommonPoints;
    TMDelTList< TCutGroup >  CutGroups;
    TG2DPoint* _MainPoint;

    //all
    TMTList<TG2DPoint> AllPntList;
    TMTList<TG2DCut> AllCutList;
    TMTList<TG2DLink> AllLinks;

    //not skeleton
    TMTList<TG2DPoint> NotSkeletonPntList;
    TMTList<TG2DCut> NotSkeletonCutList;
    TMTList<TG2DLink> NotSkeletonLinks;


    //sequence
    TMTList<TG2DPoint> InfluenceSequence;

	bool FindSkeletons();
	bool FindSkeleton(TDistanceLink* DisLink,TSkeleton& Skeleton,TMTList<TG2DPoint>& PntList);

	void FillNotSkeletonsLinksAndCommonPoints();

	bool IsSkeletonsFixed();


	bool ForcePoint(TG2DPoint* Point);
	bool ProcessAddCut(TG2DCut* Cut);
    bool IsRealized(TG2DCut* Cut);
    TCutGroup* GroupOf(TG2DCut* Cut);

	bool Ensure_Not_Skeleton_Links(TG2DPoint* GPoint);

	bool SkeletonsHaveMoreThanTwoPoints(int index1,int index2);
	void MergeSkeletonPointsAndLinks(int index1,int index2);
	bool ProcessFindLinks();

	bool FindAngleEdgesAndLinkedGroupsRec(TG2DCut* NotCut,TG2DCut* Cut,int index);
	bool FindAngleEdges();

    bool RegisterPointFreedomDegree(TG2DPoint* GPoint,TDegreeRule* Rule);

    //bool IsLinked(TG2DPoint* Point0,TG2DPoint* Point1,bool UseFixed,TMTList<TG2DLink>& Links);
    bool CreateInfluenceSequence(TG2DPoint* MainPoint);
	bool CreateInfluence(TG2DPoint* Point);

};
template <class T>
bool TMTListIntersect(TMTList<T> &Src1, TMTList<T> &Src2,TMTList<T> &Dst)
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

bool IsLinkedTo(TMTList<TG2DPoint>& Skeleton,TG2DPoint* Point,bool UseFixed,TMTList<TG2DLink>& Links);

#endif
