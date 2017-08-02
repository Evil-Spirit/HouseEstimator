//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "G2DInfluenceU.h"
#include "math.h"
#include "G2DPointCutV.h"
#include "G2DFunctionsV.h"
#include "G2DDistanceLinkV.h"
#include "G2DAngleLinkV.h"

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


/*bool IsLinked(TG2DPoint* Point0,TG2DPoint* Point1,bool UseFixed,TMTList<TG2DLink>& Links)
{
    bool Result = false;
    if ( UseFixed && Point0->Fixed && Point1->Fixed && Point1 != Point0 )
        Result = true;
    for (int i=0;i<Point0->LinksCount;i++)
        if (    Point0->GetLink(i).ConsistsClient( Point1 ) &&
                ((TG2DLink&)Point0->GetLink(i)).IsLinked(Point0,Point1) )
                {
                    if ( Links.IndexOf( &((TG2DLink&)Point0->GetLink(i)) ) == -1 )
                        Links.Add( &((TG2DLink&)Point0->GetLink(i)) );
                    Result = true;
                }

    for (int c=0;c<Point0->CutsCount;c++)
        for (int i=0;i<Point0->GetCut(c).LinksCount;i++)
        {
            TG2DCut* Cut0 = (TG2DCut*)&(Point0->GetCut(c));
            if ( UseFixed && Cut0->Fixed && Point1->Fixed )
                Result = true;
            if (    Cut0->GetLink(i).ConsistsClient( Point1 ) &&
                    ((TG2DLink&)Cut0->GetLink(i)).IsLinked(Point0,Point1) )
            {
                    if ( Links.IndexOf( &((TG2DLink&)Point0->GetLink(i)) ) == -1 )
                        Links.Add( &((TG2DLink&)Point0->GetLink(i)) );
                    Result = true;
            }
        }

    for (int c=0;c<Point1->CutsCount;c++)
        for (int i=0;i<Point1->GetCut(c).LinksCount;i++)
        {
            TG2DCut* Cut1 = (TG2DCut*)&Point1->GetCut(c);
            if ( UseFixed && Cut1->Fixed && Point0->Fixed )
                Result = true;
            if (    Cut1->GetLink(i).ConsistsClient( Point0 ) &&
                    ((TG2DLink&)Cut1->GetLink(i)).IsLinked(Point0,Point1) )
            {
                    if ( Links.IndexOf( &((TG2DLink&)Point0->GetLink(i)) ) == -1 )
                        Links.Add( &((TG2DLink&)Point0->GetLink(i)) );
                    Result = true;
            }
        }

    for (int c=0;c<Point0->CutsCount;c++)
        for (int c1=0;c1<Point1->CutsCount;c1++)
        {
            TG2DCut* Cut0 = (TG2DCut*)&Point0->GetCut(c);
            TG2DCut* Cut1 = (TG2DCut*)&Point1->GetCut(c1);
            if ( UseFixed && Cut0->Fixed && Cut1->Fixed && (Cut0!=Cut1))
                Result = true;
            for (int i=0;i<Cut0->LinksCount;i++)
            if (    Cut0->GetLink(i).ConsistsClient( Cut1 ) &&
                    ((TG2DLink&)Cut0->GetLink(i)).IsLinked(Point0,Point1) )
            {
                    if ( Links.IndexOf( &((TG2DLink&)Cut0->GetLink(i)) ) == -1 )
                        Links.Add( &((TG2DLink&)Cut0->GetLink(i)) );
                    Result = true;
            }
        }
    return Result;
} */




bool FindSkeleton(TDistanceLink* DisLink,TMTList<TG2DPoint>& Skeleton,TMTList<TG2DPoint>& PntList,TMTList<TG2DLink>& SkeletonLinks)
{
    //minimal skeleton
    Skeleton.Add( DisLink->Client0 );
    PntList.Remove( DisLink->Client0 );
    Skeleton.Add( DisLink->Client1 );
    PntList.Remove( DisLink->Client1 );
    SkeletonLinks.Add(DisLink);

    bool WasTwoLinkFound = true;
    while (WasTwoLinkFound)
    {
        WasTwoLinkFound = false;
        for (int e=0;e<PntList.Count;e++)
        {
            TMTList<TG2DLink> PntAndSkeletonLinks;
            if ( IsLinkCompleted(Skeleton,PntList.Items[e],true,PntAndSkeletonLinks) )
                if (PntAndSkeletonLinks.Count>=2)
                {
                    for (int l=0;l<PntAndSkeletonLinks.Count;l++)
                        if ( SkeletonLinks.IndexOf( &PntAndSkeletonLinks[l] ) == -1)
                            SkeletonLinks.Add( &PntAndSkeletonLinks[l] );
                    Skeleton.Add( PntList.Items[e] );
                    PntList.Delete(e);
                    e--;
                    WasTwoLinkFound = true;
                }
        }
    }
    return true;                
}


bool SkeletonsHaveMoreThanTwoPoints(TFlowInfo& FlowInfo,int index1,int index2)
{
    int CommonPointCount = 0;
    for (int i=0;i<FlowInfo.Skeletons[index1].Count && CommonPointCount<2;i++)
        CommonPointCount += (FlowInfo.Skeletons[index2].IndexOf(FlowInfo.Skeletons[index1].Items[i])!=-1);
    return (CommonPointCount >= 2);
}

void MergeSkeletons(TFlowInfo& FlowInfo,int index1,int index2)
{
    for (int i=0;i<FlowInfo.Skeletons[index2].Count;i++)
        if ( FlowInfo.Skeletons[index1].IndexOf( FlowInfo.Skeletons[index2].Items[i] )== -1 )
            FlowInfo.Skeletons[index1].Add( FlowInfo.Skeletons[index2].Items[i] );
            
    for (int i=0;i<FlowInfo.SkeletonLinks[index2].Count;i++)
        if ( FlowInfo.SkeletonLinks[index1].IndexOf( FlowInfo.SkeletonLinks[index2].Items[i] )== -1 )
            FlowInfo.SkeletonLinks[index1].Add( FlowInfo.SkeletonLinks[index2].Items[i] );
            
    FlowInfo.SkeletonLinks.Delete(index2);
    FlowInfo.Skeletons.Delete(index2);
}

void FindSkeletons(TFlowInfo& FlowInfo)
{
    TMTList<TDistanceLink> DisLinks;
    for (int i=0;i<FlowInfo.PntList.Count;i++)
        for (int j=0;j<FlowInfo.PntList[i].LinksCount;j++)
            if (
                    FlowInfo.PntList[i].GetLink(j).Is( TDistanceLink::StaticType )&&
                    DisLinks.IndexOf( (TDistanceLink*)&FlowInfo.PntList[i].GetLink(j) ) == -1 )
                DisLinks.Add( (TDistanceLink*)&FlowInfo.PntList[i].GetLink(j) );

    while ( DisLinks.Count )
    {
        TMTList<TG2DPoint> PntListCopy;
        PntListCopy.Assign( &FlowInfo.PntList );
        FlowInfo.Skeletons.Add( new TMTList<TG2DPoint>() );
        FlowInfo.SkeletonLinks.Add( new TMTList<TG2DLink>() );
        FindSkeleton(DisLinks.Items[0],*FlowInfo.Skeletons.Last(),PntListCopy,*FlowInfo.SkeletonLinks.Last());
        for (int i=0;i<DisLinks.Count;)
            if ( FlowInfo.Skeletons.Last()->IndexOf( DisLinks[i].Client0 ) !=-1 &&
                 FlowInfo.Skeletons.Last()->IndexOf( DisLinks[i].Client1 ) !=-1 )
                DisLinks.Delete(i);
            else
                i++;
    }
    //--------------------------------------------------------------------------
    for (int i=0;i<FlowInfo.Skeletons.Count;i++)
        for (int j=i+1;j<FlowInfo.Skeletons.Count;j++)
            if ( SkeletonsHaveMoreThanTwoPoints(FlowInfo,i,j) )
                MergeSkeletons(FlowInfo,i,j--);
}

bool FindAngleEdgesAndLinkedGroupsRec(TG2DCut* NotCut,TG2DCut* Cut,TFlowInfo& FlowInfo,int index)
{
    SetFlag(Cut->Flags,flMARK,gfTRUE);
    FlowInfo.LinkedGroupOfCuts[index].Add( Cut );
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
                ErrorMsg("<FindAngleTreeRec>: Эскиз переопределен.");
                return false;
            }
            bool res = FindAngleEdgesAndLinkedGroupsRec(Cut,ElseCut,FlowInfo,index);
            if (!res)
                return false;
        }
    if (!Was_AngleLink && FlowInfo.EdgeCuts[index].IndexOf( Cut ) == -1 )
        FlowInfo.EdgeCuts[index].Add(Cut);
    return true;
}

/*void MergeSkeletons(TFlowInfo& FlowInfo,int index1,int index2)
{
    for (int i=0;i<FlowInfo.Skeletons[index2].Count;i++)
        if ( FlowInfo.Skeletons[index1].IndexOf( FlowInfo.Skeletons[index2].Items[i] )== -1 )
            FlowInfo.Skeletons[index1].Add( FlowInfo.Skeletons[index2].Items[i] );

    for (int i=0;i<FlowInfo.SkeletonLinks[index2].Count;i++)
        if ( FlowInfo.SkeletonLinks[index1].IndexOf( FlowInfo.SkeletonLinks[index2].Items[i] )== -1 )
            FlowInfo.SkeletonLinks[index1].Add( FlowInfo.SkeletonLinks[index2].Items[i] );

    FlowInfo.SkeletonLinks.Delete(index2);
    FlowInfo.Skeletons.Delete(index2);
}*/

bool FindAngleEdges(TFlowInfo& FlowInfo)
{
    TMTList<TG2DCut> ElseCuts;
    ElseCuts.Assign( &FlowInfo.AllCuts );
    while (ElseCuts.Count)
    {
        for ( int i=0;i<ElseCuts.Count;i++ )
            SetFlag(ElseCuts[i].Flags,flMARK,gfFALSE);

		int index = FlowInfo.EdgeCuts.Add( new TMTList<TG2DCut> );
        FlowInfo.LinkedGroupOfCuts.Add( new TMTList<TG2DCut> );
        bool res = FindAngleEdgesAndLinkedGroupsRec(NULL,ElseCuts.Items[0],FlowInfo,index);
        if (!res)
            return false;
        for ( int i=0;i<ElseCuts.Count;i++ )
            if (ElseCuts[i].Flags.Mark == gfTRUE)
                ElseCuts.Delete(i--);
    }

	//объединение связных отрезков
    // список < списков < Скелетонов<        > > >
    TMDelTList< TMTList < TMTList< TG2DPoint > > > GroupSkeletons;
    for (int i=0; i<FlowInfo.LinkedGroupOfCuts.Count; i++)
    {
      	GroupSkeletons.Add( new TMTList < TMTList< TG2DPoint > >() );
		for (int k=0; k<FlowInfo.Skeletons.Count; k++)
			for (int j=0; j<FlowInfo.LinkedGroupOfCuts[i].Count; j++)
            	if (FlowInfo.Skeletons[k].IndexOf( (TG2DPoint*)FlowInfo.LinkedGroupOfCuts[i][j].Src)!=-1 &&
					FlowInfo.Skeletons[k].IndexOf( (TG2DPoint*)FlowInfo.LinkedGroupOfCuts[i][j].Dst)!=-1)
                {
					GroupSkeletons[i].Add( &FlowInfo.Skeletons[k] );
                    break;
                }
    }
    for (int i1=0;i1<FlowInfo.LinkedGroupOfCuts.Count;i1++)
	    for (int i2=0;i2<FlowInfo.LinkedGroupOfCuts.Count;i2++)
        {
            TMTList < TMTList< TG2DPoint > > Intersection;
        	if ( TMTListIntersect(GroupSkeletons[i1],GroupSkeletons[i2],Intersection) )
            {
				TMTListAdd_NE( GroupSkeletons[i2],GroupSkeletons[i1] );
				TMTListAdd_NE( FlowInfo.EdgeCuts[i2],FlowInfo.EdgeCuts[i1] );
				TMTListAdd_NE( FlowInfo.LinkedGroupOfCuts[i2],FlowInfo.LinkedGroupOfCuts[i1] );
                GroupSkeletons.Delete(i2);
                FlowInfo.EdgeCuts.Delete(i2);
                FlowInfo.LinkedGroupOfCuts.Delete(i2);
                i1--;
                break;
            }
        }

    for (int i=0;i<FlowInfo.Skeletons.Count;i++)
        SkeletonLegs.Add( new TMDelTList< TMTList<TG2DCut> > );

	//нахождение ножек скелетона
    for (int i1=0;i1<FlowInfo.LinkedGroupOfCuts.Count;i1++)
	    for (int s1=0;s1<GroupSkeletons[i1].Count;s1++)
        {
        	TMTList<TG2DCut> Legs
		    for (int j=0;j<FlowInfo.LinkedGroupOfCuts[i].Count;j++)
    	    	if ( GroupSkeletons[i1].IndexOf((TG2DPoint*)FlowInfo.LinkedGroupOfCuts[i][j].Src)+
                	GroupSkeletons[i1].IndexOf((TG2DPoint*)FlowInfo.LinkedGroupOfCuts[i][j].Dst) == 1 )
                	Legs.Add( &FlowInfo.LinkedGroupOfCuts[i][j] );
			if (Legs.Count>1)
            {
            	int SkeletonIndex = FlowInfo.Skeletons.IndexOf(&GroupSkeletons[i1]);
             	SkeletonLegs[ SkeletonIndex ].Add( new TMTList<TG2DCut> );
                SkeletonLegs[ SkeletonIndex ].Last()->Assign(&Legs);
            }
        }
    return true;
}

void FillNotSkeletonsLinksAndCommonPoints(TFlowInfo& FlowInfo)
{
    //not skeleton links
    for ( int i=0;i<FlowInfo.Links.Count;i++ )
    {
        bool NotExists = true;
        for ( int j=0;j<FlowInfo.SkeletonLinks.Count && NotExists;j++ )
            if ( FlowInfo.SkeletonLinks[j].IndexOf( &FlowInfo.Links[i] ) != -1 )
                NotExists = false;
        if (NotExists)
            FlowInfo.NotSkeletonLinks.Add( &FlowInfo.Links[i] );
    }
    //common points
    for ( int i=0;i<FlowInfo.Skeletons.Count;i++ )
       for ( int j=0;j<FlowInfo.Skeletons[i].Count;j++ )
    {
        //find if exists
        bool Exists = false;
        for (int cp=0;cp<FlowInfo.SkeletonCP.Count&&!Exists;cp++)
            if ( FlowInfo.SkeletonCP[cp].Point == &FlowInfo.Skeletons[i][j] )
                Exists = true;
        if (Exists)
            continue;
        FlowInfo.SkeletonCP.Add( new TCommonPoint() );
        FlowInfo.SkeletonCP.Last()->Point = &FlowInfo.Skeletons[i][j];
        for (int s=0;s<FlowInfo.Skeletons.Count;s++)
            if ( FlowInfo.Skeletons[s].IndexOf( FlowInfo.SkeletonCP.Last()->Point ) != -1 )
                FlowInfo.SkeletonCP.Last()->Skeletons.Add( &FlowInfo.Skeletons[s] );
        if ( FlowInfo.SkeletonCP.Last()->Skeletons.Count < 2 )
            FlowInfo.SkeletonCP.Delete( FlowInfo.SkeletonCP.Count-1 );
    }

}


void FixSkeletonByDistance(TG2DPoint* GPoint,TMTList<TG2DPoint>& NotPnts,TMTList<TG2DPoint>& Pnts)
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
        Pnts[k].Rules.Add( new TCircleDegreeRule() );
        Pnts[k].Rules.Last()->GPoint = GPoint;
        ((TCircleDegreeRule*)Pnts[k].Rules.Last())->Radius = (GPoint->Point - Pnts[k].Point).Length();
    }
}

void FixSkeletonByAngle(TG2DPoint* GPoint1,TG2DPoint* GPoint2,TMTList<TG2DPoint>& NotPnts,TMTList<TG2DPoint>& Pnts)
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

        Pnts[k].Rules.Add( new TLineDegreeRule() );
        ((TLineDegreeRule*)Pnts[k].Rules.Last())->GPX_SRC = GPoint1;
        ((TLineDegreeRule*)Pnts[k].Rules.Last())->GPX_DST = GPoint2;
        ((TLineDegreeRule*)Pnts[k].Rules.Last())->GPY_SRC = GPoint1;
        ((TLineDegreeRule*)Pnts[k].Rules.Last())->Angle = AngleRad(Pnts[k].Point,GPoint1->Point,GPoint2->Point)*180/M_PI;
        ((TLineDegreeRule*)Pnts[k].Rules.Last())->Strongly = true;
    }
}

bool UpdateSkeletonAndSequenceIfNeed(
                                TG2DPoint* GPoint,
  //                              TDegreeRule* Rule,
                                TFlowInfo& FlowInfo,
                                int index)
{
    TMTList<TG2DPoint>& MSP = FlowInfo.MSPS[index];
//    TMTList<TG2DPoint>& Rules = FlowInfo.Skeleton_Rules[index];
    TMTList<TG2DPoint>& Skeleton = FlowInfo.Skeletons[index];
    TMTList<TG2DPoint>& Sequence = FlowInfo.InfluenceSequence;
//    if ( Rules.Count == 3 )
  //  	throw EMyException("UpdateSkeletonAndSequenceIfNeed: переопределен.");
    if (MSP.Items[0] && MSP.Items[1])
        return true;
    if (MSP.Items[0] == GPoint || MSP.Items[1] == GPoint)
        return true;
    else if ( MSP.Items[0] )
    {
        MSP.Items[1] = GPoint;
        FixSkeletonByAngle(MSP.Items[0],MSP.Items[1],Sequence,Skeleton);
        for (int i=0;i<Skeleton.Count;i++)
            if ( Sequence.IndexOf( Skeleton.Items[i] ) == -1 )
                Sequence.Add( Skeleton.Items[i] );
        //FixSkeletonByDistance(GPoint,Sequence,Skeleton);
        return true;
    }
    else
    {
        MSP.Items[0] = GPoint;
        FixSkeletonByDistance(MSP.Items[0],Sequence,Skeleton);
        for (int i=0;i<Skeleton.Count;i++)
            if ( Skeleton.Items[i] != MSP.Items[0] && Skeleton[i].Rules.Count == 2 )
                return ProcessAddPointToSequence(Skeleton.Items[i],FlowInfo);
        return true;                
    }
}

bool SkeletonHasLessThanOneLevel(int index,TFlowInfo& FlowInfo)
{
    if ( (FlowInfo.MSPS[index].Items[0]!=NULL) +
                (FlowInfo.MSPS[index].Items[1]!=NULL) >=1 )
        return true;
    for (int i=0;i<FlowInfo.Skeletons[index].Count;i++)
        if ( FlowInfo.Skeletons[index][i].Rules.Count == 0 )
            return false;
    return true;
}

bool Ensure_Not_Skeleton_Links(TG2DPoint* GPoint,TFlowInfo& FlowInfo)
{
    //now check links
    bool IsFindedLink=true;
    while (IsFindedLink)
    {
        IsFindedLink = false;
        for ( int i=0;i<FlowInfo.NotSkeletonLinks.Count;i++ )
        {
            TMTList<TG2DLink> UpdateLinks;
            TG2DPoint* NewGPoint = FlowInfo.NotSkeletonLinks[i].ReadyToUpdate(FlowInfo.InfluenceSequence);
            if (NewGPoint)
            {
                UpdateLinks.Add( &FlowInfo.NotSkeletonLinks[i] );
                for ( int j=i+1;j<FlowInfo.NotSkeletonLinks.Count;j++ )
                    if ( FlowInfo.NotSkeletonLinks[j].ReadyToUpdate( FlowInfo.InfluenceSequence ) == NewGPoint )
                        UpdateLinks.Add( &FlowInfo.NotSkeletonLinks[j] );

                IsFindedLink = true;
                if ( NewGPoint->Rules.Count + UpdateLinks.Count > 2 )
                {
                    ErrorMsg("<ProcessAddPointToSequence>: Эскиз переопределен.");
                    return false;
                }

                while (UpdateLinks.Count)
                {
                    UpdateLinks[0].UpdatePointRule( NewGPoint );
                    FlowInfo.NotSkeletonLinks.Remove(&UpdateLinks[0]);
                    UpdateLinks.Delete(0);
                }
                //--------------------------------------------
                if (NewGPoint->Rules.Count == 2)
                    if (!ProcessAddPointToSequence(NewGPoint,FlowInfo))
                        return false;
            }
        }
    }

    //если <обе точки принадлежат одному скелетону> И <число степеней свободы скелетона == одна> тогда
        // создаем связку
    for (int i=0;i<FlowInfo.NotSkeletonLinks.Count;i++)
    {
        TMTList<TG2DPoint> FreePoints;
        if ( !FlowInfo.NotSkeletonLinks[i].GetFreePoints(FlowInfo.InfluenceSequence,FreePoints) )
            continue;
        if ( FreePoints.Count>2 )
            continue;
        int index = -1;
        for (int i=0;i<FlowInfo.Skeletons.Count && index == -1;i++)
            if (    FlowInfo.Skeletons[i].IndexOf( &FreePoints[0] )!=-1 &&
                    FlowInfo.Skeletons[i].IndexOf( &FreePoints[1] )!=-1 )
                index = i;
        if ( index != -1 && SkeletonHasLessThanOneLevel(index,FlowInfo) )
        {
            //создаем связку
            TG2DPoint* UpdatedPoint = ( FlowInfo.NotSkeletonLinks[i].IsBestToUpdate( &FreePoints[0] ) ) ? &FreePoints[0] : &FreePoints[1];
            TG2DPoint* SwitchedPoint = (UpdatedPoint == &FreePoints[1]) ? &FreePoints[0] : &FreePoints[1];
            FlowInfo.NotSkeletonLinks[i].UpdatePointRule( UpdatedPoint );
            if (FlowInfo.MSPS[index].Items[0] && FlowInfo.MSPS[index].Items[0] != SwitchedPoint)
                FreePoints[1].Rules.Last()->SwitchPointToPoint( SwitchedPoint,FlowInfo.MSPS[index].Items[0],UpdatedPoint );
            FlowInfo.NotSkeletonLinks.Delete(i);
            return ProcessAddPointToSequence( &FreePoints[1] ,FlowInfo);
        }
    }
    return true;
}

bool ProcessAddPointToSequence(TG2DPoint* GPoint,TFlowInfo& FlowInfo)
{
    //---------------------------------------
    //Ensure_Not_Skeleton_Links(GPoint,FlowInfo);
    //---------------------------------------

    if ( FlowInfo.InfluenceSequence.IndexOf(GPoint) == -1)
    {
        FlowInfo.InfluenceSequence.Add(GPoint);
    }
    //повторного наложения ограничений не будет т.к. в UpdateSkeletonAndSequenceIfNeed
    //проверяется
    for (int i=0;i<FlowInfo.Skeletons.Count;i++)
        if ( FlowInfo.Skeletons[i].IndexOf(GPoint) != -1 )
            if ( !UpdateSkeletonAndSequenceIfNeed(GPoint,FlowInfo,i) )
                return false;

    //---------------------------------------
    return Ensure_Not_Skeleton_Links(GPoint,FlowInfo);
    //---------------------------------------
}

bool Is_Skeletons_Fixed(TFlowInfo& FlowInfo)
{
    for (int i=0;i<FlowInfo.Skeletons.Count;i++)
        if ( !FlowInfo.MSPS[i].Items[0] || !FlowInfo.MSPS[i].Items[1] )
            return false;
    return true;
}

bool CheckPointOnEdgeCuts(TG2DPoint* CheckedPoint,TFlowInfo& FlowInfo)
{
    for (int i=0;i<FlowInfo.EdgeCuts.Count;i++)
        for (int j=0;j<FlowInfo.EdgeCuts[i].Count;j++)
            for (int k=j+1;k<FlowInfo.EdgeCuts[i].Count;k++)
                if ( FlowInfo.EdgeCuts[i][j].CanConnect( FlowInfo.EdgeCuts[i][k] ) == CheckedPoint)
                    return true;
    for (int i=0;i<FlowInfo.EdgeCutSkeletons.Count;i++)
        if ( FlowInfo.EdgeCutSkeletons[i].IndexOf(CheckedPoint) != -1)
            return true;
    return false;
}

bool ThereIsAFullLinks(TFlowInfo& FlowInfo)
{
    for (int i=0;i<FlowInfo.NotSkeletonLinks.Count;i++)
    {
        TMTList<TG2DPoint> FreePoints;
        FlowInfo.NotSkeletonLinks[0].GetFreePoints(FlowInfo.InfluenceSequence,FreePoints);
        if ( !FreePoints.Count )
            return true;
    }
    return false;
}

bool CreateInfluenceSequence(TG2DPoint* MainPoint,TFlowInfo& FlowInfo)
{
    ThereIsAFullLinks(FlowInfo);
    bool Result = true;
    FlowInfo.InfluenceSequence.Clear();
    //Main_Skeleton_Points
    for (int i=0;i<FlowInfo.Skeletons.Count;i++)
    {
        FlowInfo.MSPS.Add( new TMTList<TG2DPoint>() );
        FlowInfo.MSPS[i].Add( NULL );
        FlowInfo.MSPS[i].Add( NULL );
    }

    //Apply origin,axes, fixed points and cuts
    Result = Result && ProcessAddPointToSequence(&FlowInfo.Owner->GP_X_AXE,FlowInfo);
    //-------------------------------------------------
    Result = Result && ProcessAddPointToSequence(&FlowInfo.Owner->GP_Y_AXE,FlowInfo);
    //-------------------------------------------------
    Result = Result && ProcessAddPointToSequence(&FlowInfo.Owner->GP_ZERO,FlowInfo);
    //-------------------------------------------------


    //Apply MainPoint
    Result = Result && ProcessAddPointToSequence(MainPoint,FlowInfo);

    //Apply CommonPoints
    for (int i=0;i<FlowInfo.SkeletonCP.Count;i++)
        Result = Result && ProcessAddPointToSequence(FlowInfo.SkeletonCP[i].Point ,FlowInfo);


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
    //фиксация скелетонов
    while ( !Is_Skeletons_Fixed(FlowInfo) )
    {
        for (int i=0;i<FlowInfo.MSPS.Count;i++)
            for (int j=0;j<FlowInfo.Skeletons[i].Count;j++)
                if (    FlowInfo.Skeletons[i][j].Rules.Count<2 &&
                        FlowInfo.InfluenceSequence.IndexOf( &FlowInfo.Skeletons[i][j] )==-1 /*&&
                        !CheckPointOnEdgeCuts (&FlowInfo.Skeletons[i][j],FlowInfo) лишнее т.к. связок уже нет*/ )
                    Result = Result && ProcessAddPointToSequence( &FlowInfo.Skeletons[i][j] ,FlowInfo);
    }
    //---------------------------------------------------


    for (int i=0;i<FlowInfo.PntList.Count;i++)
        if ( FlowInfo.InfluenceSequence.IndexOf( FlowInfo.PntList.Items[i] ) == -1 )
            FlowInfo.InfluenceSequence.Add( FlowInfo.PntList.Items[i] );
    return Result;            
}

bool CreateInfluence(TFlowInfo& FlowInfo,TG2DPoint* Point)
{
    bool Result = true;
    FindSkeletons(FlowInfo);
    Result = Result && FindAngleEdges(FlowInfo);
    //---------------------------------
    //-------Apply-Fixed---------------
    //---------------------------------------------------
    //Find Fixed Cuts
    TMTList<TG2DCut> FxdCuts;
    for (int i=0;i<FlowInfo.PntList.Count;i++)
        for (int j=0;j<FlowInfo.PntList[i].CutsCount;j++)
            if (    FlowInfo.PntList[i].GetCut(j).Fixed &&
                    FxdCuts.IndexOf( (TG2DCut*) &FlowInfo.PntList[i].GetCut(j) ) == -1 )
                FxdCuts.Add( (TG2DCut*) &FlowInfo.PntList[i].GetCut(j) );

    //----------------------------------------------------
    TMDelTList<TG2DCut> ServCut;
    TMDelTList<TG2DLink> ServLink;
    for (int i=0;i<FxdCuts.Count;i++)
    {
        ServLink.Add( CreateAngleLink(&FlowInfo.Owner->GP_X,&FxdCuts[i],alsFirst) );
        FlowInfo.Links.Add(ServLink.Last());
    }

    //Apply Fixed Points
    for (int i=0;i<FlowInfo.PntList.Count;i++)
        if ( FlowInfo.PntList[i].Fixed )
        {
            ServCut.Add( new TG2DCut() );
            ServCut.Last()->Src = &FlowInfo.Owner->GP_ZERO;
            ServCut.Last()->Dst = &FlowInfo.PntList[i];

            ServLink.Add( CreateAngleLink(&FlowInfo.Owner->GP_X,ServCut.Last(),alsFirst) );
            FlowInfo.Links.Add(ServLink.Last());

            ServLink.Add( CreateDistanceLink(&FlowInfo.Owner->GP_ZERO,&FlowInfo.PntList[i]) );
            FlowInfo.Links.Add(ServLink.Last());
        }

    //---------------------------------
    FillNotSkeletonsLinksAndCommonPoints(FlowInfo);
    //---------------------------------
    //Fill Not Skeleton Points
    for (int i=0;i<FlowInfo.PntList.Count;i++)
    {
        bool PointInSkeleton = false;
        for (int j=0;j<FlowInfo.Skeletons.Count && !PointInSkeleton;j++)
            if ( FlowInfo.Skeletons[j].IndexOf( FlowInfo.PntList.Items[i] ) == -1 )
                PointInSkeleton = true;
        if ( PointInSkeleton )
            FlowInfo.NotSkeletonPntList.Add( FlowInfo.PntList.Items[i] );
    }
    //---------------------------------
    return Result && CreateInfluenceSequence(Point,FlowInfo);
    //---------------------------------
}


