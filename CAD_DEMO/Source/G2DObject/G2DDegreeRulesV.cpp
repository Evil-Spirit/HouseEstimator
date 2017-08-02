//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "G2DDegreeRulesV.h"
#include "G2DPointCutV.h"
//#include "G2DFunctionsV.h"
#include "math.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TClassNode* TDegreeRule::StaticType = NULL;
TClassNode* TLineDegreeRule::StaticType = NULL;
TClassNode* TCircleDegreeRule::StaticType = NULL;
TClassNode* TCircleDegreeOfAngle::StaticType = NULL;
TClassNode* TLimaconDegreeRule::StaticType = NULL;


TIntVec TDegreeRule::GetPoint() const
{
    return GPoint->Point;
}

TMyObject* TDegreeRule::CreateFunction()
{
    return new TDegreeRule();
}
TMyObject* TCircleDegreeRule::CreateFunction()
{
    return new TCircleDegreeRule();
}
TMyObject* TLineDegreeRule::CreateFunction()
{
    return new TLineDegreeRule();
}

TDegreeRule::TDegreeRule()
{
    GPoint = NULL;
    RegisterNewClass<TMyObject,TDegreeRule>(this,false,&CreateFunction);
}

TLineDegreeRule::TLineDegreeRule()
{
    RegisterNewClass<TDegreeRule,TLineDegreeRule>(this,false,&CreateFunction);
    GPX_SRC = NULL;
    GPX_DST = NULL;
    GPY_SRC = NULL;
    Strongly = false;
    Angle = 0;
    OffSet = 0;
}

void TLineDegreeRule::InitOffSetByPoint(TG2DPoint* Point)
{
	OffSet = LengthFromPointToLine( Point->Point, GPY_SRC->Point, GPY_SRC->Point + GetDirection() );
}

TIntVec TLineDegreeRule::GetPoint() const
{
/*    TIntVec CP;
    if ( CrossPointNotStrictly(
                                GPX_SRC->Point,
                                GPX_DST->Point,
                                GPY_SRC->Point,
                                GPY_SRC->Point+GetDirection(),
                                CP,
                                _MBTi_eps_
                                ) )
    {
        return CP;
    }
    else */
	return GPY_SRC->Point + GetDirection().Perpendicular2D().Normalize()*OffSet;
}

TIntVec TLineDegreeRule::GetDirection() const
{
    TIntVec Res = RotateAround(GPX_DST->Point,TIntVec(0,0,Angle),GPX_SRC->Point);
//    MBTi _Angle = AngleRad(Res,GPX_SRC->Point,GPX_DST->Point);
//    MBTi _Angle2 = AngleRad(GPX_DST->Point,GPX_SRC->Point,Res);
    return (Res - GPX_SRC->Point);
}

TCircleDegreeRule::TCircleDegreeRule()
{
    RegisterNewClass<TDegreeRule,TCircleDegreeRule>(this,false,&CreateFunction);
}


//------------------TCircleDegreeOfAngle-------------------------------
TIntVec TCircleDegreeOfAngle::GetPoint() const
{
    TIntVec CP;
    MBTi R;
    CircleByTwoPointsAndAngle(
                    GPX_DST->Point,
                    GPY_DST->Point,
                    Angle,
                    CP,
                    R);
    return CP;                        
}

MBTi TCircleDegreeOfAngle::GetRadius() const
{
    TIntVec CP;
    MBTi R;
    CircleByTwoPointsAndAngle(
                    GPX_DST->Point,
                    GPY_DST->Point,
                    Angle,
                    CP,
                    R);
    return R;
}

TMyObject* TCircleDegreeOfAngle::CreateFunction()
{
    return new TCircleDegreeOfAngle();
}

TCircleDegreeOfAngle::TCircleDegreeOfAngle()
{
    RegisterNewClass<TCircleDegreeRule,TCircleDegreeOfAngle>(this,false,&CreateFunction);
}

//----------------------------------------------------------
void TLineDegreeRule::SwitchPointToPoint(TG2DPoint* FromPoint,TG2DPoint* ToPoint,TG2DPoint* TargetPoint)
{
    if ( GPX_SRC == FromPoint )
        GPX_SRC = ToPoint;
    if ( GPX_DST == FromPoint )
        GPX_DST = ToPoint;
    if ( GPY_SRC == FromPoint )
        GPY_SRC = ToPoint;

    Angle = AngleRad( GPX_SRC->Point,GPX_DST->Point,GPY_SRC->Point,TargetPoint->Point )*180/M_PI;
}


TIntVec MovePointTo(const TIntVec& Point, const TDegreeRule& Rule)
{
    TIntVec Res;
    if ( Rule.Is(TCircleDegreeRule::StaticType) )
    {
        TCircleDegreeRule& CDR = (TCircleDegreeRule&)Rule;
        Res = PointOfLineOnCut(Point,CDR.Point,(Point - CDR.Point).Length()- CDR.Radius);
    }
    else if ( Rule.Is(TLineDegreeRule::StaticType) )
    {
        TLineDegreeRule& LDR = (TLineDegreeRule&)Rule;
        TIntVec N =  TIntVec(LDR.Direction.y,LDR.Direction.x,0);
        IsLinesCrossedExactly(LDR.Point,LDR.Point+LDR.Direction,Point,Point+N,Res);
    }
    else if ( Rule.Is(TLimaconDegreeRule::StaticType) )
    {
        TLimaconDegreeRule& LDR = (TLimaconDegreeRule&)Rule;
        return LDR.PL.FindClosestPoint(Point);
    }
    return Res;
}

bool CrossPointsOf(const TLineDegreeRule& Rule1,const TLineDegreeRule& Rule2,TMDelTList<TIntVec>& CPS,MBTi USEEPS)
{
    TIntVec CP;
    if ( CrossPointNotStrictly(
                                Rule1.Point,
                                Rule1.Point + Rule1.Direction,
                                Rule2.Point,
                                Rule2.Point + Rule2.Direction,
                                CP,
                                USEEPS
                                ) )
    {
        CPS.Add( new TIntVec(CP) );
        return true;
    }
    else
        return false;
}

bool LimaconCrossingWith(const TLimaconDegreeRule& Rule1,const TDegreeRule& Rule2,TMDelTList<TIntVec>& CPS,MBTi USEEPS)
{
    if 		(Rule2.Is( TCircleDegreeRule::StaticType) )
    {
    	TCircleDegreeRule& CDR = (TCircleDegreeRule&)Rule2;
    	return Rule1.PL.CrossingWithCircle(CDR.Point,CDR.Radius,CPS,USEEPS);
    }
    else if	(Rule2.Is( TLineDegreeRule::StaticType) )
    {
    	TLineDegreeRule& LDR = (TLineDegreeRule&)Rule2;
    	return Rule1.PL.CrossingWithLine(LDR.Point,LDR.Point + LDR.Direction,CPS,USEEPS);
    }
    else if	(Rule2.Is( TLimaconDegreeRule::StaticType) )
    {
    	TLimaconDegreeRule& LDR = (TLimaconDegreeRule&)Rule2;
    	return Rule1.PL.CrossingWithLimacon(LDR.PL,CPS,USEEPS);
    }
    else
        throw EMyException("<LimaconCrossingWith>: неизвестное сочетание законов.");
}

bool CrossPointsOf(const TDegreeRule& Rule1,const TDegreeRule& Rule2,TMDelTList<TIntVec>& CPS,MBTi USEEPS)
{
    if (	Rule1.Is( TCircleDegreeRule::StaticType) &&
            Rule2.Is( TCircleDegreeRule::StaticType ) )
    {
        //circles
        return CrossCircles(
                                Rule1.Point,
                                ((TCircleDegreeRule&)Rule1).Radius,
                                Rule2.Point,
                                ((TCircleDegreeRule&)Rule2).Radius,
                                CPS,USEEPS);
    }
    else if (	Rule1.Is( TLineDegreeRule::StaticType ) &&
                Rule2.Is( TLineDegreeRule::StaticType ) )
    {
        //lines
        return CrossPointsOf((TLineDegreeRule&)Rule1,(TLineDegreeRule&)Rule2,CPS,USEEPS);
    }
    else if (	Rule1.Is( TCircleDegreeRule::StaticType ) &&
                Rule2.Is( TLineDegreeRule::StaticType ) )
    {
        //circle and line
        return CrossCircleAndLine(
                                Rule1.Point,
                                ((TCircleDegreeRule&)Rule1).Radius,
                                ((TLineDegreeRule&)Rule2).Point,
                                ((TLineDegreeRule&)Rule2).Point+((TLineDegreeRule&)Rule2).Direction,
                                CPS,((TLineDegreeRule&)Rule2).Strongly,USEEPS);
    }
    else if (	Rule1.Is( TLineDegreeRule::StaticType ) &&
                Rule2.Is( TCircleDegreeRule::StaticType ) )
    {
        //line and circle
        return CrossCircleAndLine(
                                Rule2.Point,
                                ((TCircleDegreeRule&)Rule2).Radius,
                                ((TLineDegreeRule&)Rule1).Point,
                                ((TLineDegreeRule&)Rule1).Point+((TLineDegreeRule&)Rule1).Direction,
                                CPS,((TLineDegreeRule&)Rule1).Strongly,USEEPS);
    }
    else if (   Rule1.Is( TLimaconDegreeRule::StaticType ) )
    {
    	return	LimaconCrossingWith((TLimaconDegreeRule&)Rule1,Rule2,CPS,USEEPS);
    }
    else if (   Rule2.Is( TLimaconDegreeRule::StaticType ) )
    {
    	return	LimaconCrossingWith((TLimaconDegreeRule&)Rule2,Rule1,CPS,USEEPS);
    }
    else
        throw EMyException("<CrossPointsOf>: неизвестное сочетание законов.");
}

TMyObject* TLimaconDegreeRule::CreateFunction()
{
	return new TLimaconDegreeRule();
}

TLimaconDegreeRule::TLimaconDegreeRule()
{
	SkP1 = NULL;
	BaseP1 = NULL;
	SkP2 = NULL;
	BaseP2 = NULL;
	PositionPoint = NULL;
}

void TLimaconDegreeRule::InitPascalLimacon()
{
	TIntVec Center;
	if ( !CrossPointNotStrictly(
			BaseP1->Point,
			SkP1->Point,
			BaseP2->Point,
			SkP2->Point,
			Center,
            MBTi_EPS) )
    {
    	throw EMyException("<TLimaconDegreeRule::InitPascalLimacon>: Limacon Initialization failed.");
    }

	MBTi Angle = AngleRad(BaseP2->Point,Center,BaseP1->Point)*180/M_PI;

   PL.Initialize(BaseP1->Point,BaseP2->Point,Angle,PositionPoint->Point);
}

bool SwitchRulePointToPoint( TG2DPoint* FromPoint,TG2DPoint* ToPoint,TDegreeRule* Rule )
{
	if ( Rule->Is( TLineDegreeRule::StaticType ) )
    {
		((TLineDegreeRule*)Rule)->InitOffSetByPoint(ToPoint);
        FromPoint->Rules.RemoveOnly( Rule );
        ToPoint->Rules.Add( Rule );
        return true;
    }
    else if ( Rule->Is( TLimaconDegreeRule::StaticType ) )
    {
		((TLimaconDegreeRule*)Rule)->PositionPoint = ToPoint;
        ((TLimaconDegreeRule*)Rule)->InitPascalLimacon();
        FromPoint->Rules.RemoveOnly( Rule );
        ToPoint->Rules.Add( Rule );
        return true;
    }
	return false;	
}


