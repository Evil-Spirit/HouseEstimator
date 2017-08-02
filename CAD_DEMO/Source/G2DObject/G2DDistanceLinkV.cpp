//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "Poligon.h"
#include "MyGL.h"
#include "G2DObjectV.h"
#include "G2DDistanceLinkV.h"
#include "G2DFunctionsV.h"
#include "G2DPointCutV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TClassNode* TDistanceLink::StaticType = NULL;

bool TDistanceLink::IsLinked(TG2DPoint* GPoint0,TG2DPoint* GPoint1)
{
    return  (  (GPoint0 == (TG2DPoint*)Client0 &&
                GPoint1 == (TG2DPoint*)Client1)
                    ||
               (GPoint1 == (TG2DPoint*)Client0 &&
                GPoint0 == (TG2DPoint*)Client1)
            );
}

bool TDistanceLink::CanUpdateList(TMTList<TG2DPoint>& PointList)
{
	if ( ((TG2DPoint*)Client0)->Rules.Count == 2 )
    {
       	PointList.Add( ((TG2DPoint*)Client1) );
        return true;
    }
    else if ( ((TG2DPoint*)Client1)->Rules.Count == 2 )
    {
       	PointList.Add( ((TG2DPoint*)Client0) );
        return true;
    }
    return false;
};

bool TDistanceLink::HaveLinked(const TMTList<TG2DPoint>& PointList,const TG2DPoint* Point)
{
    return  ( PointList.IndexOf(Client0) != -1 && Point == (TG2DPoint*)Client1 ) ||
            ( PointList.IndexOf(Client1) != -1 && Point == (TG2DPoint*)Client0 );
}

bool TDistanceLink::PointInLink(TG2DPoint* Point)
{
    return Point == (TG2DPoint*)Client0 || Point == (TG2DPoint*)Client1;
}

bool TDistanceLink::GetFreePoints(const TMTList<TG2DPoint>& PointList,TMTList<TG2DPoint>& FreePointList)
{
    FreePointList.Clear();
    if ( PointList.IndexOf( (TG2DPoint*)Client0 ) == -1 )
        FreePointList.Add( (TG2DPoint*)Client0 );

    if ( PointList.IndexOf( (TG2DPoint*)Client1 ) == -1 )
        FreePointList.Add( (TG2DPoint*)Client1 );
    return FreePointList.Count==1;
}

/*
bool TryUpdateFixedPoint(TGUnit* Client0,TGUnit* Client1,TFlowInfo& FlowInfo)
{
    if ( FlowInfo.Fixed.IndexOf( Client0 ) !=-1 )
    {
        //client0 fixed
        if ( FlowInfo.Fixed.IndexOf( Client1 ) != -1 )
            return true;
        int HalfFixedIndex = FlowInfo.HalfFixed.IndexOf( Client1 );
        if ( HalfFixedIndex != -1 )
        {
            FlowInfo.HalfFixed.Delete(HalfFixedIndex);
            FlowInfo.Fixed.Add( Client1 );
        }
        else
            FlowInfo.HalfFixed.Add( Client1 );
        return true;
    }
    else
        return false;
}

void TDistanceLink::UpdateFixedPoints(TFlowInfo& FlowInfo)
{
    if ( !TryUpdateFixedPoint(Client0,Client1,FlowInfo) )
        TryUpdateFixedPoint(Client1,Client0,FlowInfo);
} */

/*
void TDistanceLink::UpdateDistanceLink(TGUnit* _Client,TFlowInfo& FlowInfo)
{
    TG2DPoint* Client = AssertCast<TG2DPoint>("<TAngleLink::UpdateAngleLink>",_Client);
    T2DGObject* Owner = AssertCast<T2DGObject>("<TAngleLink::UpdateAngleLink>",FlowInfo.Object);

    if ( !_Client || (Client0 != Client && Client1 != Client) )
    {
        AnsiString Str = "<TAngleLink::UpdateClient>: точка не принадлежит связке";
        throw EMyException(Str);
    }
    TG2DPoint* SourcePoint = Client0;
    TG2DPoint* UpdatePoint = Client1;
    if (Client == SourcePoint)
        ExchangeItem<TG2DPoint*>(SourcePoint,UpdatePoint);

    FlowInfo.UnResolved.Remove( this );
    Owner->ChangePointCoordinateRecursive(  UpdatePoint,
                                            PointOfLineOnCut(SourcePoint->Point,UpdatePoint->Point,Distance),
                                            FlowInfo
                                            );
} */

bool TDistanceLink::UpdatePointRule(TG2DPoint* GPoint)
{
    TG2DPoint* Src_Point = AssertCast<TG2DPoint>("TDistanceLink::UpdatePointRule",AnotherClient(GPoint));
    TG2DPoint* Dst_Point = AssertCast<TG2DPoint>("TDistanceLink::UpdatePointRule",GPoint);
    TCircleDegreeRule* Rule = NULL;
    for (int i=0;i<Dst_Point->Rules.Count;i++)
        if ( Dst_Point->Rules[i].GLink == this )
        {
            Rule = (TCircleDegreeRule*)&Dst_Point->Rules[i];
            break;
        }
    if (!Rule)
    {
        Rule = new TCircleDegreeRule();
        Dst_Point->Rules.Add(Rule);
    }
    Rule->GPoint = Src_Point;
    Rule->Radius = Distance;
    return true;
/*
    if ( FlowInfo.Fixed.IndexOf( Client1 ) == -1 )
    {
        ((T2DGObject*)FlowInfo.Object)->ChangePointCoordinateRecursive((TG2DPoint*)Client1,FlowInfo);
        FlowInfo.UnResolved.Remove(this);
        return true;
    }
    else if ( FlowInfo.Fixed.IndexOf( Client0 ) == -1 )
    {
        ((T2DGObject*)FlowInfo.Object)->ChangePointCoordinateRecursive((TG2DPoint*)Client0,FlowInfo);
        FlowInfo.UnResolved.Remove(this);
        return true;
    }
    return false;   */
}

/*bool TDistanceLink::UpdatePointRule(TG2DPoint* GPoint,TFlowInfo& FlowInfo)
{
    //update rule

    if ( FlowInfo.Fixed.IndexOf( Client1 ) == -1 )
    {
        UpdateDistanceLink(Client1,FlowInfo);
        return true;
    }
    else if ( FlowInfo.Fixed.IndexOf( Client0 ) == -1 )
    {
        UpdateDistanceLink(Client0,FlowInfo);
        return true;
    }
    return false;

}

void TDistanceLink::Update(TFlowInfo& FlowInfo)
{
    UpdateDistanceLink(Client1,FlowInfo);
} */

TMyObject* TDistanceLink::CreateFunction()
{
    return new TDistanceLink();
}

const AnsiString aDistance = AnsiString("Distance");
const AnsiString aParallel_Offset_Param = AnsiString("Parallel_Offset_Param");
const AnsiString aPerpendicular_Offset = AnsiString("Perpendicular_Offset");
const AnsiString aLeg_Offset = AnsiString("Leg_Offset");

TDistanceLink::TDistanceLink()
{
    RegisterNewClass<TG2DLink,TDistanceLink>(this,false,&CreateFunction);
    Leg_Offset = 3;
    Perpendicular_Offset = 1;
    Parallel_Offset_Param = 0.5;
    RegisterField(&FDistance,&aDistance,mtMBTi);
    RegisterField(&Parallel_Offset_Param,&aParallel_Offset_Param,mtMBTi);
    RegisterField(&Perpendicular_Offset,&aPerpendicular_Offset,mtMBTi);
    RegisterField(&Leg_Offset,&aLeg_Offset,mtMBTi);
}

TDistanceLink::~TDistanceLink()
{

}

void TDistanceLink::SetDistance(MBTi aDistance)
{
    FDistance = aDistance;
}

void TDistanceLink::Render(TVisView* aView)
{

    TMDelTList<TIntVec> PointList;
    MBTi Length = (Client1->Point-Client0->Point).Length();
    TIntVec P0 = /*aView->WinFrom3D(*/ Client0->Point /*)*/;
    TIntVec P1 = /*aView->WinFrom3D(*/ Client1->Point /*)*/;
    //Parallel Ray
    TIntVec Ray = (P1 - P0);
    Ray = Ray.Normalize();
    //Perpendicular Ray
    TIntVec Per_Ray = Ray;
    Per_Ray.x = -Ray.y;
    Per_Ray.y = Ray.x;

    TIntVec NewP0 = P0;
    TIntVec NewP1 = P1;
    TIntVec LabelPos = PointOnCut(P0,P1,Parallel_Offset_Param);
    if ( Parallel_Offset_Param>1 )
        NewP1 = LabelPos;
    else if ( Parallel_Offset_Param<0 )
        NewP0 = LabelPos;

    //Legs,Arrows and Label Positions
    TIntVec ArrowPos0 = P0 + Per_Ray*(Perpendicular_Offset);
    TIntVec ArrowPos1 = P1 + Per_Ray*(Perpendicular_Offset);
    MBTi P0_Leg_OffSet = Leg_Offset*Factor(aView,P0.z);
    MBTi P1_Leg_OffSet = Leg_Offset*Factor(aView,P0.z);
    TIntVec Leg0 = P0 + Per_Ray*(Perpendicular_Offset+P0_Leg_OffSet);
    TIntVec Leg1 = P1 + Per_Ray*(Perpendicular_Offset+P1_Leg_OffSet);
    LabelPos = LabelPos + Per_Ray*(Perpendicular_Offset);

    //text and font and color
    Label->Caption = MBTiToStrF(Length,2);
    TIntVec LabelPos_Scr = aView->WinFrom3D( LabelPos );

    //text rect
    aView->GetCanvas()->Font->Assign( Label->Font );
    aView->Canvas->Font->Assign( Label->Font );
    TSize TextSize = aView->Canvas->TextExtent(Label->Caption);
    //text rect
    TIntVec LabelRectMin(LabelPos_Scr.x-TextSize.cx/2-2,LabelPos_Scr.y-TextSize.cy/2-2,0);
    TIntVec LabelRectMax(LabelPos_Scr.x+TextSize.cx/2+2,LabelPos_Scr.y+TextSize.cy/2+2,0);
    //text offset
    LabelPos_Scr.x -= TextSize.cx/2;
    LabelPos_Scr.y += TextSize.cy/2;

    //MainLine
    AddVectorToList(
                    PointList,
                    aView->WinFrom3D(NewP0 + Per_Ray*Perpendicular_Offset),
                    aView->WinFrom3D(NewP1 + Per_Ray*Perpendicular_Offset),
                    LabelRectMin,
                    LabelRectMax,
                    0.0001
                    );
    //PointList.Add( new TIntVec( NewP0 + Per_Ray*Perpendicular_Offset ) );
    //PointList.Add( new TIntVec( NewP1 + Per_Ray*Perpendicular_Offset ) );

    PointList.Add( new TIntVec( aView->WinFrom3D(P0) ) );
    PointList.Add( new TIntVec( aView->WinFrom3D(Leg0) ) );
    PointList.Add( new TIntVec( aView->WinFrom3D(P1) ) );
    PointList.Add( new TIntVec( aView->WinFrom3D(Leg1) ) );

    //Arrows
    TIntVec Arrow0,Arrow1;
    MakeArrow(aView->WinFrom3D(ArrowPos0),aView->WinFrom3D(ArrowPos1),Arrow0,Arrow1,15,5,false);
    PointList.Add( new TIntVec( Arrow0 ) );
    PointList.Add( new TIntVec( aView->WinFrom3D(ArrowPos1) ) );
    PointList.Add( new TIntVec( Arrow1 ) );
    PointList.Add( new TIntVec( aView->WinFrom3D(ArrowPos1) ) );
    MakeArrow(aView->WinFrom3D(ArrowPos1),aView->WinFrom3D(ArrowPos0),Arrow0,Arrow1,15,5,false);
    PointList.Add( new TIntVec( Arrow0 ) );
    PointList.Add( new TIntVec( aView->WinFrom3D(ArrowPos0) ) );
    PointList.Add( new TIntVec( Arrow1 ) );
    PointList.Add( new TIntVec( aView->WinFrom3D(ArrowPos0) ) );


    //Render Lines
    //Render
    for (int i=0;i<PointList.Count-1;)
    {
        aView->Canvas->MoveTo(PointList[i].x,PointList[i].y);
        i++;
        aView->Canvas->LineTo(PointList[i].x,PointList[i].y);
        i++;
    }
    aView->Canvas->TextOut(LabelPos_Scr.x,LabelPos_Scr.y,Label->Caption);
    Position = LabelPos_Scr;
    //AssignVisVec(*Label->Transformation->Translation,Position);
    //Label->Render(aView);
}

void TDistanceLink::SetPoint(int index,TG2DPoint* aPoint)
{
    SetClient(index,aPoint);
}

TG2DPoint* TDistanceLink::GetPoint(int index)
{
    return (TG2DPoint*)GetClient(index);
}



