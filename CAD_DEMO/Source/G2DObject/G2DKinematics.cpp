//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "math.h"
#include "G2DPointCutV.h"
#include "G2DFunctionsV.h"
#include "G2DDistanceLinkV.h"
#include "G2DAngleLinkV.h"

#include "G2DKinematics.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
bool IsLinkCompleted(TMTList<TG2DPoint>& Skeleton,TG2DPoint* Point,bool UseFixed,TMTList<TG2DLink>& Links)
{
    bool Result = false;
    //-------------check for fixed
    if (UseFixed)
    {
        //check for fixed points
        if (Point->Fixed )
            for(int p=0;p<Skeleton.Count&&!Result;p++)
                if ( Skeleton[p].Fixed && &Skeleton[p] != Point)
                    Result = true;
        //check for fixed cuts
        for (int c=0;c<Point->CutsCount && !Result ;c++)
            if (Point->GetCut(c).Fixed)
            {
                if ( Skeleton.IndexOf( (TG2DPoint*)Point->GetCut(c).GetAnotherPoint(Point) )!=-1 )
                    Result = true;
                for(int p=0;p<Skeleton.Count && !Result;p++)
                    for (int pc=0;pc<Skeleton[p].CutsCount && !Result ;pc++)
                    if (    Skeleton[p].GetCut(pc).Fixed &&
                            &Skeleton[p].GetCut(pc) != &Point->GetCut(c) )
                        Result = true;
            }
    }
    //--------------------------------------------------------------------------
    for (int i=0;i<Point->LinksCount;i++)
        if ( ((TG2DLink&)Point->GetLink(i)).IsLinkCompleted(Skeleton,Point) )
        {
            Result = true;
            if ( Links.IndexOf( & ((TG2DLink&)Point->GetLink(i)) ) == -1)
                Links.Add( & ((TG2DLink&)Point->GetLink(i)) );                  
        }

    for (int c=0;c<Point->CutsCount ;c++)
        for (int i=0;i<Point->GetCut(c).LinksCount;i++)
        {
            bool Res = ((TG2DLink&)Point->GetCut(c).GetLink(i)).IsLinkCompleted(Skeleton,Point);
            if ( Res == true )
            {
                if ( Links.IndexOf( & ((TG2DLink&)Point->GetCut(c).GetLink(i)) ) == -1)
                    Links.Add( & ((TG2DLink&)Point->GetCut(c).GetLink(i)) );
                Result = true;
            }
        }
    return Result;
}

bool IsLinkedTo(TMTList<TG2DPoint>& Skeleton,TG2DPoint* Point,bool UseFixed,TMTList<TG2DLink>& Links)
{
    bool Result = false;
    //-------------check for fixed
    if (UseFixed)
    {
        //check for fixed points
        if (Point->Fixed )
            for(int p=0;p<Skeleton.Count&&!Result;p++)
                if ( Skeleton[p].Fixed && &Skeleton[p] != Point)
                    Result = true;
        //check for fixed cuts
        for (int c=0;c<Point->CutsCount && !Result ;c++)
            if (Point->GetCut(c).Fixed)
            {
                if ( Skeleton.IndexOf( (TG2DPoint*)Point->GetCut(c).GetAnotherPoint(Point) )!=-1 )
                    Result = true;
                for(int p=0;p<Skeleton.Count && !Result;p++)
                    for (int pc=0;pc<Skeleton[p].CutsCount && !Result ;pc++)
                    if (    Skeleton[p].GetCut(pc).Fixed &&
                            &Skeleton[p].GetCut(pc) != &Point->GetCut(c) )
                        Result = true;
            }
    }
    //--------------------------------------------------------------------------
    for (int i=0;i<Point->LinksCount;i++)
        if ( ((TG2DLink&)Point->GetLink(i)).IsLinkedTo(Skeleton,Point) )
        {
            Result = true;
            if ( Links.IndexOf( & ((TG2DLink&)Point->GetLink(i)) ) == -1)
                Links.Add( & ((TG2DLink&)Point->GetLink(i)) );                  
        }

    for (int c=0;c<Point->CutsCount ;c++)
        for (int i=0;i<Point->GetCut(c).LinksCount;i++)
        {
            bool Res = ((TG2DLink&)Point->GetCut(c).GetLink(i)).IsLinkedTo(Skeleton,Point);
            if ( Res == true )
            {
                if ( Links.IndexOf( & ((TG2DLink&)Point->GetCut(c).GetLink(i)) ) == -1)
                    Links.Add( & ((TG2DLink&)Point->GetCut(c).GetLink(i)) );
                Result = true;
            }
        }
    return Result;
}



bool TFlowInfo::FindSkeleton(TDistanceLink* DisLink,TSkeleton& Skeleton,TMTList<TG2DPoint>& PntList)
{
    //minimal skeleton
    Skeleton.Pnts.Add( DisLink->Client0 );
	PntList.Remove( DisLink->Client0 );
    Skeleton.Pnts.Add( DisLink->Client1 );
	PntList.Remove( DisLink->Client1 );
    Skeleton.Links.Add(DisLink);

    bool WasTwoLinkFound = true;
    while (WasTwoLinkFound)
    {
        WasTwoLinkFound = false;
        for (int e=0;e<PntList.Count;e++)
        {
            TMTList<TG2DLink> PntAndSkeletonLinks;
            if ( IsLinkCompleted(Skeleton.Pnts,PntList.Items[e],true,PntAndSkeletonLinks) )
                if (PntAndSkeletonLinks.Count>=2)
                {
                    for (int l=0;l<PntAndSkeletonLinks.Count;l++)
                        if ( Skeleton.Links.IndexOf( &PntAndSkeletonLinks[l] ) == -1)
                            Skeleton.Links.Add( &PntAndSkeletonLinks[l] );
                    Skeleton.Pnts.Add( PntList.Items[e] );
                    PntList.Delete(e);
                    e--;
                    WasTwoLinkFound = true;
                }
        }
    }
    return true;
}

void TFlowInfo::MergeSkeletonPointsAndLinks(int index1,int index2)
{
	//pnts						src						dst
	TMTListAdd_NE(Skeletons[index2].Pnts,Skeletons[index1].Pnts);
	//lnks						src						dst
	TMTListAdd_NE(Skeletons[index2].Links,Skeletons[index1].Links);

    Skeletons.Delete(index2);
}

bool TFlowInfo::SkeletonsHaveMoreThanTwoPoints(int index1,int index2)
{
    int CommonPointCount = 0;
    for (int i=0;i<Skeletons[index1].Pnts.Count && CommonPointCount<2;i++)
        CommonPointCount += ( Skeletons[index2].Pnts.IndexOf(Skeletons[index1].Pnts.Items[i] )!=-1);
    return (CommonPointCount >= 2);
}

bool TFlowInfo::FindSkeletons()
{
    TMTList<TDistanceLink> DisLinks;
    for (int i=0;i<AllPntList.Count;i++)
        for (int j=0;j<AllPntList[i].LinksCount;j++)
            if (
                    AllPntList[i].GetLink(j).Is( TDistanceLink::StaticType )&&
                    DisLinks.IndexOf( (TDistanceLink*)&AllPntList[i].GetLink(j) ) == -1 )
                DisLinks.Add( (TDistanceLink*)&AllPntList[i].GetLink(j) );

    while ( DisLinks.Count )
    {
        TMTList<TG2DPoint> PntListCopy;
        PntListCopy.Assign( &AllPntList );
		Skeletons.Add( new TSkeleton(this) );
        FindSkeleton(DisLinks.Items[0],*Skeletons.Last(),PntListCopy);
        for (int i=0;i<DisLinks.Count;)
            if ( Skeletons.Last()->Pnts.IndexOf( DisLinks[i].Client0 ) !=-1 &&
                 Skeletons.Last()->Pnts.IndexOf( DisLinks[i].Client1 ) !=-1 )
                DisLinks.Delete(i);
            else
                i++;
    }
    //--------------------------------------------------------------------------

    for (int i=0;i<Skeletons.Count;i++)
        for (int j=i+1;j<Skeletons.Count;j++)
            if ( SkeletonsHaveMoreThanTwoPoints(i,j) )
                MergeSkeletonPointsAndLinks(i,j--);
	return true;                
}

bool TFlowInfo::FindAngleEdgesAndLinkedGroupsRec(TG2DCut* NotCut,TG2DCut* Cut,int index)
{
    SetFlag(Cut->Flags,flMARK,gfTRUE);
    //--------------------------------
    CutGroups[index].Cuts.Add( Cut );
    //--------------------------------
    bool Was_AngleLink = false;
    int LinkCount = 0;
    for (int i=0;i<Cut->LinksCount;i++)
        if ( Cut->GetLink(i).Is( TAngleLink::StaticType ) )
        {
            TAngleLink* AL = (TAngleLink*)&Cut->GetLink(i);
            TG2DCut* ElseCut = (TG2DCut*)AL->AnotherClient(Cut);
            if (ElseCut == NotCut)
                continue;
            LinkCount++;
            Was_AngleLink = NotCut || (!NotCut && LinkCount>=2);
            if ( ElseCut->Flags.Mark == gfTRUE )
            {
                ErrorMsg("<FindAngleTreeRec>: Ёскиз переопределен.");
                return false;
            }
            bool res = FindAngleEdgesAndLinkedGroupsRec(Cut,ElseCut,index);
            if (!res)
                return false;
        }
	        
    if (!Was_AngleLink && CutGroups[index].Edges.IndexOf( Cut ) == -1 )
        CutGroups[index].Edges.Add(Cut);
    return true;
}

bool TFlowInfo::FindAngleEdges()
{
    TMTList<TG2DCut> ElseCuts;
    ElseCuts.Assign( &AllCutList );
    while (ElseCuts.Count)
    {
        for ( int i=0;i<ElseCuts.Count;i++ )
            SetFlag(ElseCuts[i].Flags,flMARK,gfFALSE);
        bool res = FindAngleEdgesAndLinkedGroupsRec(NULL,ElseCuts.Items[0],CutGroups.Add( new TCutGroup ));
        if (!res)
            return false;
        for ( int i=0;i<ElseCuts.Count;i++ )
            if (ElseCuts[i].Flags.Mark == gfTRUE)
                ElseCuts.Delete(i--);
    }

	//объединение св€зных отрезков
    for (int i=0; i<CutGroups.Count; i++)
		for (int k=0; k<Skeletons.Count; k++)
        {
			bool FirstAdd = true;
			for (int j=0; j<CutGroups[i].Cuts.Count; j++)
            	if (Skeletons[k].Pnts.IndexOf( (TG2DPoint*)CutGroups[i].Cuts[j].Src)!=-1 &&
					Skeletons[k].Pnts.IndexOf( (TG2DPoint*)CutGroups[i].Cuts[j].Dst)!=-1)
                {
                    if (FirstAdd)
                    {
                        CutGroups[i].Skeletons.Add( &Skeletons[k] );
                        FirstAdd = false;
                    }
                   	Skeletons[k].Cuts.Add( &CutGroups[i].Cuts[j] );
                }
        }
    for (int i1=0;i1<CutGroups.Count;i1++)
	    for (int i2=0;i2<CutGroups.Count;i2++)
        {
            TMTList < TSkeleton > Intersection;
        	if ( i1!=i2 && TMTListIntersect(CutGroups[i1].Skeletons,CutGroups[i2].Skeletons,Intersection) )
            {
				TMTListAdd_NE( CutGroups[i2].Skeletons,CutGroups[i1].Skeletons );
				TMTListAdd_NE( CutGroups[i2].Edges,CutGroups[i1].Edges );
				TMTListAdd_NE( CutGroups[i2].Cuts,CutGroups[i1].Cuts );
                CutGroups.Delete(i2);
                i1--;
                break;
            }
        }

	//удаление св€зных отрезков полностью наход€щихс€ внутри скелетона, пока не надо
    

	//нахождение ножек скелетона
    for (int i1=0;i1<CutGroups.Count;i1++)
	    for (int s1=0;s1<CutGroups[i1].Skeletons.Count;s1++)
        {
        	TMTList<TG2DCut> Legs;
		    for (int j=0;j<CutGroups[i1].Cuts.Count;j++)
    	    	if ( ((CutGroups[i1].Skeletons[s1].Pnts.IndexOf((TG2DPoint*)CutGroups[i1].Cuts[j].Src)!=-1) +
                	 (CutGroups[i1].Skeletons[s1].Pnts.IndexOf((TG2DPoint*)CutGroups[i1].Cuts[j].Dst)!=-1)) == 1 )
                	Legs.Add( &CutGroups[i1].Cuts[j] );
			if (Legs.Count>1)
            {
            	int SkeletonIndex = Skeletons.IndexOf( &CutGroups[i1].Skeletons[s1] );
                if ( Skeletons[ SkeletonIndex ].Legs.Count>0 )
                	throw EMyException("<TFlowInfo::FindAngleEdges>: ошибка.");
                Skeletons[ SkeletonIndex ].Legs.Assign( &Legs );
            }
        }
    return true;
}


void TFlowInfo::FillNotSkeletonsLinksAndCommonPoints()
{
    //not skeleton links
    for ( int i=0;i<AllLinks.Count;i++ )
    {
        bool Exists = false;
        for ( int j=0;j<Skeletons.Count && !Exists;j++ )
            if ( Skeletons[j].Links.IndexOf( &AllLinks[i] ) != -1 )
                Exists = true;
        if (!Exists)
            NotSkeletonLinks.Add( &AllLinks[i] );
    }
    
    //common points
    for ( int i=0;i<Skeletons.Count;i++ )
		for ( int j=0;j<Skeletons[i].Pnts.Count;j++ )
        {
        	if ( SkeletonCommonPoints.IndexOf( &Skeletons[i].Pnts[j] ) != -1 )
            	continue;
            TG2DPoint* P = &Skeletons[i].Pnts[j];
            for (int s=0;s<Skeletons.Count ;s++)
                if ( s!=i && Skeletons[s].Pnts.IndexOf( P ) != -1 )
                {
		            SkeletonCommonPoints.Add( P );
                    break;
                }
        }

}


void TSkeleton::FixByDistance(TG2DPoint* GPoint,TMTList<TG2DPoint>& NotPnts)
{
	//check for changing
    for (int k=0;k<Pnts.Count;k++)
    {
        if ( Pnts[k].Fixed || NotPnts.IndexOf(&Pnts[k]) != -1 )
            continue;
        if ( Pnts[k].Rules.Count>=2 )
            return;
    }
    for (int k=0;k<Pnts.Count;k++)
    {
        if ( Pnts[k].Fixed || NotPnts.IndexOf(&Pnts[k]) != -1 )
            continue;
        TCircleDegreeRule* CDR = new TCircleDegreeRule();
        CDR->GPoint = GPoint;
        CDR->Radius = (GPoint->Point - Pnts[k].Point).Length();
        FixingPoint = &Pnts[k];
        FlowInfo->RegisterPointFreedomDegree(&Pnts[k],CDR);
        FixingPoint = NULL;
    }
}

void TSkeleton::FixByAngle(TG2DPoint* GPoint1,TG2DPoint* GPoint2,TMTList<TG2DPoint>& NotPnts)
{
    //check for changing
    for (int k=0;k<Pnts.Count;k++)
    {
        if ( Pnts[k].Fixed || NotPnts.IndexOf(&Pnts[k]) != -1 )
            continue;
        if ( Pnts[k].Rules.Count>=2 )
            return;
    }
    for (int k=0;k<Pnts.Count;k++)
    {
        if ( Pnts[k].Fixed || NotPnts.IndexOf(&Pnts[k]) != -1 )
            continue;

		TLineDegreeRule* LDR = new TLineDegreeRule();
        LDR->GPX_SRC = GPoint1;
        LDR->GPX_DST = GPoint2;
        LDR->GPY_SRC = GPoint1;
        LDR->Angle = AngleRad(Pnts[k].Point,GPoint1->Point,GPoint2->Point)*180/M_PI;
        LDR->Strongly = true;
        FixingPoint = &Pnts[k];
        FlowInfo->RegisterPointFreedomDegree(&Pnts[k],LDR);
        FixingPoint = NULL;
    }
}

bool TSkeleton::CheckLimacon()
{
	if (LimaconOK)
    	return true;
	if (Legs.Count==0)
    	return true;//нет ножек
//    if ( IndexOfCut( &Legs[0] )==-1 )
//    	return true;//нет зафиксированных по углу ножек

	
	//-------------------------------------------------------
    NotSkeletonLegPoints.Clear();
    SkeletonLegPoints.Clear();
    for (int i=0;i<Legs.Count;i++)
    	if ( Pnts.IndexOf( (TG2DPoint*)Legs[i].Src ) == -1 )
        {
        	NotSkeletonLegPoints.Add( (TG2DPoint*)Legs[i].Src );
        	SkeletonLegPoints.Add( (TG2DPoint*)Legs[i].Dst );
        }
        else
        {
        	NotSkeletonLegPoints.Add( (TG2DPoint*)Legs[i].Dst );
        	SkeletonLegPoints.Add( (TG2DPoint*)Legs[i].Src );
        }
	//-------------------------------------------------------

    for ( int i=0; i<NotSkeletonLegPoints.Count; i++)
    	if ( NotSkeletonLegPoints[i].Rules.Count < 2 )
        {
        	NotSkeletonLegPoints.Delete( i );
        	SkeletonLegPoints.Delete( i-- );
        }

    if ( SkeletonLegPoints.Count<2 )
    	return true;//нет ножек с зафиксированными точками
	//-------------------------------------------------------
    if ( FCheckedRules.Count > 1 )
    {
//    	throw EMyException("<TSkeleton::CheckLimacon>: переопределение.");
        return true;
    }
	//-------------------------------------------------------
    LimaconOK = true;

    if ( SkeletonLegPoints.Count<2 )
    	throw EMyException("<TSkeleton::CheckLimacon>: ошибка.");


	int LimaconCount = 0;        

	TMTList<TG2DPoint> ChangedPoints;
	TMTList<TDegreeRule> AddedRules;
    for (int i=0;i<CheckedPointCount && LimaconCount<2;i++)
	{
        TLimaconDegreeRule* LDR = new TLimaconDegreeRule();
		ChangedPoints.Add(GetCheckedPoint(i));
        AddedRules.Add( LDR );

        LDR->SkP1 = &SkeletonLegPoints[ 0 ];
        LDR->SkP2 = &SkeletonLegPoints[ 1 ];
        LDR->BaseP1 = &NotSkeletonLegPoints[ 0 ];
        LDR->BaseP2 = &NotSkeletonLegPoints[ 1 ];
        LDR->PositionPoint = GetCheckedPoint(i);
        LDR->InitPascalLimacon();
        AddedRules.Add( LDR );
        LimaconCount++;
    }

    for (int i=0;i<Pnts.Count && LimaconCount<2;i++)
	{
		if ( Pnts[i].Rules.Count >= 2 )
        	continue;
        TLimaconDegreeRule* LDR = new TLimaconDegreeRule();

		ChangedPoints.Add( &Pnts[i] );
        AddedRules.Add( LDR );

        LDR->SkP1 = &SkeletonLegPoints[ 0 ];
        LDR->SkP2 = &SkeletonLegPoints[ 1 ];
        LDR->BaseP1 = &NotSkeletonLegPoints[ 0 ];
        LDR->BaseP2 = &NotSkeletonLegPoints[ 1 ];
        LDR->PositionPoint = &Pnts[ i ];
        LDR->InitPascalLimacon();

        LimaconCount++;

    }
    if ( LimaconCount<2 )
    	throw EMyException("<TSkeleton::CheckLimacon>: ошибка.");

    for (int i=0;i<ChangedPoints.Count;i++)
    	if (!FlowInfo->RegisterPointFreedomDegree( ChangedPoints.Items[i],AddedRules.Items[i] ) )
			return false;
            
	return true;
}


bool TSkeleton::Check()
{
    if ( FCheckedRules.Count > 3 )
	  	throw EMyException("<TSkeleton::Check>: переопределен.");

    if ( FCheckedRules.Count == 3 )
    {
    	if ( FCheckedPoints.Count == 1 )
        {
        	//ситуаци€ когда зафиксирован отрезок
            //но ни с чем не св€зан
            throw EMyException("<TSkeleton::Check>: ќшибка.");
        }
        FixByAngle(FCheckedPoints.Items[0],FCheckedPoints.Items[1],FlowInfo->InfluenceSequence);
    }
    else if ( FCheckedRules.Count == 2 )
    {
        FixByDistance(FCheckedPoints.Items[0],FlowInfo->InfluenceSequence);
    }
	return true;
}

bool TSkeleton::RegisterFreedomDegree(TG2DPoint* Point,TDegreeRule* Rule)
{
	if (FixingPoint == Point)
		return true;
        
	//if (IndexOfRule( Rule )!=-1 && !Rule->Is( TLimaconFreedomDegree::StaticType ) )
	//  	return true;

    if ( FCheckedRules.Count == 3 )
    	return true;
    
    FCheckedRules.Add(Rule);

    if ( IndexOfUnit(Point) == -1)
    	FCheckedUnits.Add(Point);

	if ( FCheckedPoints.IndexOf( Point ) == -1)
      	FCheckedPoints.Add( Point );
        
    return Check();
}

bool TFlowInfo::RegisterPointFreedomDegree(TG2DPoint* GPoint,TDegreeRule* Rule)
{
	if ( GPoint->Rules.Count > 2 )
    	throw EMyException("<TFlowInfo::RegisterPointFreedomDegree>: ќшибка");
    //-----------------------------------------------------------------------
    GPoint->Rules.Add(Rule);
    
    if ( GPoint->Rules.Count == 2 && InfluenceSequence.IndexOf(GPoint) == -1)
    {
        InfluenceSequence.Add(GPoint);
    }

    //повторного наложени€ ограничений не будет т.к. в UpdateSkeletonAndSequenceIfNeed
    //провер€етс€
    for (int i=0;i<Skeletons.Count;i++)
        if ( Skeletons[i].Pnts.IndexOf(GPoint) != -1 )
            if ( !Skeletons[i].RegisterFreedomDegree(GPoint,Rule) )
                return false;

    if ( GPoint->Rules.Count == 2 )
	    return Ensure_Not_Skeleton_Links(GPoint);
	else
    	return true;        
}

bool TSkeleton::HasOneLevel()
{
	return (LimitDegreeCount - FCheckedRules.Count) <= 1;
}

bool TSkeleton::RealizeGroup(TCutGroup& CG)
{
	TMTListAdd( Cuts,FCheckedCuts );
    bool OneCutCompletelyInSkeleton = false;
    for (int i=0;i<Cuts.Count;i++)
    {
    	FCheckedUnits.Add( &Cuts[i] );
        if ( Pnts.IndexOf( (TG2DPoint*)Cuts[i].Src )!=-1 &&
        	 Pnts.IndexOf( (TG2DPoint*)Cuts[i].Dst )!=-1 )
        {
        	OneCutCompletelyInSkeleton = true;
        }
    }
    return !OneCutCompletelyInSkeleton;
//    if ( !OneCutCompletelyInSkeleton )
  //		FCheckedRules.Add( &ServiceRule );
}

bool TCutGroup::Realize()
{
	if (Realized)
    	return true;

	for ( int i=0;i<Cuts.Count;i++ )
		Cuts[i].Rules.Add( new TDegreeRule() );

	TMDelTList<bool> RealizedGroups;        
	for ( int i=0;i<Skeletons.Count;i++ )
        RealizedGroups.Add( new bool(Skeletons[i].RealizeGroup(*this)) );

	Realized = true;
            
	for ( int i=0;i<Skeletons.Count;i++ )
    	if (RealizedGroups[i] && !Skeletons[i].Check())
        	return false;
	return true;            
}

bool TFlowInfo::ProcessAddCut(TG2DCut* Cut)
{
	TCutGroup* CutGroup = GroupOf(Cut);
    return !CutGroup || CutGroup->Realized || CutGroup->Realize();
}

TCutGroup* TFlowInfo::GroupOf(TG2DCut* Cut)
{
	for ( int i=0;i<CutGroups.Count;i++ )
      	if ( CutGroups[i].Cuts.IndexOf( Cut )!=-1 )
			return &CutGroups[i];
	return NULL;
}

bool TFlowInfo::IsRealized(TG2DCut* Cut)
{
	TCutGroup* CutGroup = GroupOf(Cut);
	return !CutGroup || CutGroup->Realized;
}


bool TFlowInfo::Ensure_Not_Skeleton_Links(TG2DPoint* GPoint)
{
	if (GPoint->Rules.Count<2)
    	throw EMyException("<TFlowInfo::Ensure_Not_Skeleton_Links>: ќшибка.");

	for (int i=0;i<GPoint->CutsCount;i++)
    	if ( ((TG2DPoint*)GPoint->GetCut(i).GetAnotherPoint( GPoint ))->Rules.Count == 2 )
        	//отрезок надо запушить
            ProcessAddCut( (TG2DCut*)&(GPoint->GetCut(i)) );

    bool IsFindedLink=true;
    while (IsFindedLink)
    {
        IsFindedLink = false;
        TMTList<TG2DPoint> UpdatePoints;
        TMDelTList< TMTList<TG2DLink> > UpdatePointLinks;

        for ( int i=0;i<NotSkeletonLinks.Count;i++ )
        {
            TMTList<TG2DPoint> UpdateList;
        	if ( NotSkeletonLinks[i].CanUpdateList(UpdateList) )
            {
            	for ( int j=0;j<UpdateList.Count;j++ )
                {
                	int index = UpdatePoints.IndexOf(UpdateList.Items[j]);
                    if (index == -1)
                    {
                    	index = UpdatePoints.Add(UpdateList.Items[j]);
                        UpdatePointLinks.Add( new TMTList<TG2DLink> );
                    }
					UpdatePointLinks[index].Add( &NotSkeletonLinks[i] );
                }
                NotSkeletonLinks.Delete(i--);
            	IsFindedLink = true;
            }
        }

        for ( int i=0;i<UpdatePoints.Count;i++ )
        {
            if ( UpdatePoints[i].Rules.Count + UpdatePointLinks[i].Count > 2 )
            {
                ErrorMsg("<TFlowInfo::Ensure_Not_Skeleton_Links>: Ёскиз переопределен.");
                return false;
            }
            while (UpdatePointLinks[i].Count)
            {
                UpdatePointLinks[i][0].UpdatePointRule( UpdatePoints.Items[i] );
                TDegreeRule* Rule = UpdatePoints[i].Rules.Last();
                UpdatePoints[i].Rules.RemoveOnly( UpdatePoints[i].Rules.Count-1 );
                UpdatePointLinks[i].Delete(0);
                if ( !RegisterPointFreedomDegree(UpdatePoints.Items[i],Rule) )
                	return false;
            }
        }
	}
	return true;
}

bool TFlowInfo::ProcessFindLinks()
{
	for (int i=0;i<InfluenceSequence.Count;i++)
    	if ( !Ensure_Not_Skeleton_Links(&InfluenceSequence[i]) )
        	return false;
    return true;
}


bool TFlowInfo::ForcePoint(TG2DPoint* Point)
{
	while ( Point->Rules.Count<2 )
        if (!RegisterPointFreedomDegree(Point,new TDegreeRule()))
        	return false;
    return true;
}

bool TFlowInfo::CreateInfluenceSequence(TG2DPoint* MainPoint)
{
//    ThereIsAFullLinks(FlowInfo);
    bool Result = true;
    InfluenceSequence.Clear();
    //Main_Skeleton_Points

    //Apply origin,axes, fixed points and cuts
    Result = Result && ForcePoint(&Owner->GP_X_AXE);
    Result = Result && ForcePoint(&Owner->GP_Y_AXE);
    Result = Result && ForcePoint(&Owner->GP_ZERO);

    //Apply MainPoint
    Result = Result && ForcePoint(MainPoint);

    //Apply CommonPoints
    for (int i=0;i<SkeletonCommonPoints.Count;i++)
	    Result = Result && ForcePoint(SkeletonCommonPoints.Items[i]);

	/*
    //Apply NotSkeletonLinks
    while ( Result && FlowInfo.NotSkeletonLinks.Count )
    {
        TMTList< TG2DPoint > TotalPoints;
        for (int i=0;i<FlowInfo.NotSkeletonLinks.Count;i++)
        {
            TMTList<TG2DPoint> FreePoints;
            FlowInfo.NotSkeletonLinks[i].GetFreePoints( FlowInfo.InfluenceSequence, FreePoints );
            for (int j=0;j<FreePoints.Count;j++)
                if ( TotalPoints.IndexOf(&FreePoints[j])==-1 )
                    TotalPoints.Add(&FreePoints[j]);
        }
        TG2DPoint* BestPoint = NULL;
        //все точки плохие
        //если берем одну из плохих точек внутри скелетона,
        //то лучше уже с rules
        for (int k=0;k<TotalPoints.Count && !BestPoint;k++)
            if ( !CheckPointOnEdgeCuts (&TotalPoints[k],FlowInfo) )
                BestPoint = &TotalPoints[k];
        if (!BestPoint)
        {
            //ищем скелетон
            for (int k=0;k<TotalPoints.Count && !BestPoint;k++)
                if ( !BestPoint || BestPoint->Rules.Count<TotalPoints[k].Rules.Count )
                    BestPoint = &TotalPoints[k];
        }
        Result = Result && ProcessAddPointToSequence( BestPoint ,FlowInfo);
    }        
    //-------------------Apply else-free points in Skeletons--------------------
    //фиксаци€ скелетонов
    while ( !Is_Skeletons_Fixed(FlowInfo) )
    {
        for (int i=0;i<FlowInfo.MSPS.Count;i++)
            for (int j=0;j<FlowInfo.Skeletons[i].Count;j++)
                if (    FlowInfo.Skeletons[i][j].Rules.Count<2 &&
                        FlowInfo.InfluenceSequence.IndexOf( &FlowInfo.Skeletons[i][j] )==-1 )
                    Result = Result && ProcessAddPointToSequence( &FlowInfo.Skeletons[i][j] ,FlowInfo);
    }
    //---------------------------------------------------
	*/
    
    for (int i=0;i<AllCutList.Count;i++)
    	if ( AllCutList[i].Rules.Count == 0 )
        {
        	ProcessAddCut( &AllCutList[i] );
            ProcessFindLinks();
        }

    for (int i=0;i<AllPntList.Count;i++)
        if ( InfluenceSequence.IndexOf( AllPntList.Items[i] ) == -1 )
        	Result = Result && ForcePoint( AllPntList.Items[i] );

    for (int i=0;i<InfluenceSequence.Count;i++)
	    for (int j=0;j<InfluenceSequence[i].Rules.Count;j++)
	    	if ( InfluenceSequence[i].Rules[j].DynamicType == TDegreeRule::StaticType ) //is base abstract class
    	    	InfluenceSequence[i].Rules.Delete(j--);	

    return Result;            
}

bool TFlowInfo::CreateInfluence(TG2DPoint* Point)
{
    bool Result = true;
    //---------------------------------
    FindSkeletons();//сначала скелетоны а потом сервис
    //-------Apply-Fixed---------------
    //---------------------------------------------------
    //Find Fixed Cuts
    TMTList<TG2DCut> FxdCuts;
    for (int i=0;i<AllPntList.Count;i++)
        for (int j=0;j<AllPntList[i].CutsCount;j++)
            if (    AllPntList[i].GetCut(j).Fixed &&
                    FxdCuts.IndexOf( (TG2DCut*) &AllPntList[i].GetCut(j) ) == -1 )
                FxdCuts.Add( (TG2DCut*) &AllPntList[i].GetCut(j) );

    //----------------------------------------------------
    TMDelTList<TG2DCut> ServCut;
    TMDelTList<TG2DLink> ServLink;
    for (int i=0;i<FxdCuts.Count;i++)
    {
        ServLink.Add( CreateAngleLink(&Owner->GP_X,&FxdCuts[i],alsFirst) );
        AllLinks.Add(ServLink.Last());
    }

	AllCutList.Add( &Owner->GP_X );
	AllCutList.Add( &Owner->GP_Y );
    //Apply Fixed Points
    for (int i=0;i<AllPntList.Count;i++)
        if ( AllPntList[i].Fixed )
        {
            ServCut.Add( new TG2DCut() );
            ServCut.Last()->Src = &Owner->GP_ZERO;
            ServCut.Last()->Dst = &AllPntList[i];
            AllCutList.Add( ServCut.Last() );

            ServLink.Add( CreateAngleLink(&Owner->GP_X,ServCut.Last(),alsFirst) );
            AllLinks.Add(ServLink.Last());

            ServLink.Add( CreateDistanceLink(&Owner->GP_ZERO,&AllPntList[i]) );
            AllLinks.Add(ServLink.Last());
        }

    //---------------------------------
    Result = Result && FindAngleEdges();
    FillNotSkeletonsLinksAndCommonPoints();
    //---------------------------------
    //Fill Not Skeleton Points
    for (int i=0;i<AllPntList.Count;i++)
    {
        bool PointInSkeleton = false;
        for (int j=0;j<Skeletons.Count && !PointInSkeleton;j++)
            if ( Skeletons[j].Pnts.IndexOf( AllPntList.Items[i] ) == -1 )
                PointInSkeleton = true;
        if ( PointInSkeleton )
            NotSkeletonPntList.Add( AllPntList.Items[i] );
    }
    //---------------------------------
    return Result && CreateInfluenceSequence(Point);
    //---------------------------------
}


