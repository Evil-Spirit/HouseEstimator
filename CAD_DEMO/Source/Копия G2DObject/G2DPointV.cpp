//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "G2DPointCutV.h"
#include "G2DFunctionsV.h"
#include "G2DFunctionsV.h"
#include "MyGL.h"
#include "math.h"
#include "G2DObjectV.h"
#include "Poligon.h"
#include "Math.hpp"
#include "G2DApproxCalcV.h"

//---------------------------------------------------------------------------


#pragma package(smart_init)

TClassNode* TG2DCut::StaticType = NULL;
TClassNode* TG2DPoint::StaticType = NULL;
TClassNode* TDegreeRule::StaticType = NULL;
TClassNode* TLineDegreeRule::StaticType = NULL;
TClassNode* TCircleDegreeRule::StaticType = NULL;
TClassNode* TCircleDegreeOfAngle::StaticType = NULL;


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

TIntVec TLineDegreeRule::GetPoint() const
{
    TIntVec CP;
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
    else
        return GPY_SRC->Point;

}

TIntVec TLineDegreeRule::GetDirection() const
{
    TIntVec Res = RotateAround(GPX_DST->Point,TIntVec(0,0,Angle),GPX_SRC->Point);
//    MBTi _Angle = AngleRad(Res,GPX_SRC->Point,GPX_DST->Point);
//    MBTi _Angle2 = AngleRad(GPX_DST->Point,GPX_SRC->Point,Res);
    return (Res - GPX_SRC->Point);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TG2DCut::TG2DCut()
{
    RegisterNewClass<TGCut,TG2DCut>(this,false,&CreateFunction);
    FFixed = false;
}

TMyObject* TG2DCut::CreateFunction()
{
    return new TG2DCut();
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TMyObject* TG2DPoint::CreateFunction()
{
    return new TG2DPoint();
}

TG2DPoint::TG2DPoint()
{
    RegisterNewClass<TGPoint,TG2DPoint>(this,false,&CreateFunction);
    FFixed = false;
}

bool CircleByThreePoints(
                    const TIntVec& P1,
                    const TIntVec& P2,
                    const TIntVec& P3,
                    TIntVec& CP,
                    MBTi& R)
{
    TIntVec Perp1_P = (P2+P1)/2;
    TIntVec Perp2_P = (P2+P3)/2;
    TIntVec Perp1_D = TIntVec(P2.y-P1.y,-(P2.x-P1.x),P1.z);
    TIntVec Perp2_D = TIntVec(P3.y-P2.y,-(P3.x-P2.x),P2.z);
    if ( CrossPointNotStrictly(
                                Perp1_P,
                                Perp1_P + Perp1_D,
                                Perp2_P,
                                Perp2_P + Perp2_D,
                                CP,
                                _MBTi_eps_
                                ) )
    {
        R = (P2-CP).Length();
        return true;
    }
    else
        return false;                         
}

TIntVec GetThirdPoint(
                    const TIntVec& RotSrc,
                    const TIntVec& RotDst,
                    MBTi Angle
                    )
{
    TIntVec Vec = RotDst-RotSrc;
    TIntVec Perp_Dir = TIntVec(-Vec.y,Vec.x,Vec.z).Normalize();
    TIntVec StartPoint = (RotDst+RotSrc)/2;
    MBTi _Tan = Tan( ((90 - Angle/2)*M_PI/180) );
    MBTi VecLength = Vec.Length();
    MBTi LengthOfPerp = (VecLength/2)*_Tan;
    return StartPoint+Perp_Dir*LengthOfPerp;
}

bool COMMONAL_API CircleByTwoPointsAndAngle(
                    const TIntVec& RotSrc,
                    const TIntVec& RotDst,
                    MBTi Angle,
                    TIntVec& CP,
                    MBTi& R)
{
    return CircleByThreePoints(RotSrc,RotDst,GetThirdPoint(RotSrc,RotDst,Angle),CP,R);
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


MBTi Deg(MBTi Number,int Degree)
{
    MBTi Res = 1;
    for (int i=0;i<Degree;i++)
        Res *= Number;
    return Res;
}  

bool CrossCircles(
                    const TIntVec& C1,MBTi R1,
                    const TIntVec& C2,MBTi R2,
                    TMDelTList<TIntVec>& CPS,MBTi USEEPS)
{
    CPS.Clear();
    MBTi a = (C1 - C2).Length();
    MBTi Angle = AngleRadOX(C1,C2)*180/M_PI;

    if ( fabs(a) < USEEPS )
        return false;

    MBTi Low_a_Level = fabs(R1 - R2);
    MBTi Hi_a_Level = R1 + R2;

    if ( a > (R1 + R2) + USEEPS )
        return false;
    else if ( a < fabs(R1 - R2) - USEEPS )
        return false;
    else if ( fabs( a-Hi_a_Level ) <= USEEPS || fabs( a - Low_a_Level ) <= USEEPS)
        CPS.Add( new TIntVec(R1,0,0) );
    else
    {
        CPS.Add( new TIntVec() );
        CPS.Add( new TIntVec() );
        CPS[0].x = (Deg(a,2)+Deg(R1,2)-Deg(R2,2))/(2*a);
        CPS[0].y = sqrt( Deg(R1,2) - Deg(CPS[0].x,2) );
        CPS[1].x = CPS[0].x;
        CPS[1].y = -CPS[0].y;
    }
    for(int i=0;i<CPS.Count;i++)
    {
        CPS[i] = RotateAround(CPS[i], TIntVec(0,0,Angle), ZEROINTVEC);
        CPS[i] += C1;
        CPS[i].z = C1.z;
    }
    return true;
}

bool CrossCircleAndLine(
                    const TIntVec& C1,MBTi R1,
                    const TIntVec& P1,const TIntVec& P2,
                    TMDelTList<TIntVec>& CPS,bool Strongly,MBTi USEEPS)
{
    if ( P1.Equal(P2,USEEPS) )
        return false;
    //расчитаем расстояние от прямой до центра окружности как высоту треугольника
    //через площадь
    MBTi Angle = AngleRadOX(P1,P2)*180/M_PI;
    MBTi y = RotateAround (P1-C1,TIntVec(0,0,-Angle),ZEROINTVEC).y;
    MBTi a = fabs(y);

    CPS.Clear();
    if ( a > R1 + USEEPS )
        return false;
    else if ( fabs(a-R1) <= USEEPS )
    {
        CPS.Add( new TIntVec(0,y,0) );
    }
    else
    {
        CPS.Add( new TIntVec() );
        CPS.Add( new TIntVec() );
        CPS[0].y = y;
        CPS[0].x = sqrt( Deg(R1,2) - Deg(y,2) );
        CPS[1].y = y;
        CPS[1].x = - CPS[0].x;
    }
    for(int i=0;i<CPS.Count;i++)
    {
        CPS[i] = RotateAround(CPS[i], TIntVec(0,0,Angle), ZEROINTVEC);
        CPS[i] += C1;
        CPS[i].z = C1.z;
    }
    if (Strongly && CPS.Count == 2)
    {
        TIntVec P2P1_Direct = (P2-P1).Normalize();
        TIntVec CP0_P1_Direct = (CPS[0]-P1).Normalize();
        TIntVec CP1_P1_Direct = (CPS[1]-P1).Normalize();

        if ( (P2P1_Direct-CP0_P1_Direct).Length() < (P2P1_Direct-CP1_P1_Direct).Length() )
            CPS.Delete(1);
        else
            CPS.Delete(0);
    }
        
    return true;
}




bool CrossPointsOf(const TDegreeRule& Rule1,const TDegreeRule& Rule2,TMDelTList<TIntVec>& CPS,MBTi USEEPS)
{
    if (
            Rule1.Is( TCircleDegreeRule::StaticType) &&
            Rule2.Is( TCircleDegreeRule::StaticType )
         )
    {
        //circles
        return CrossCircles(
                                Rule1.Point,
                                ((TCircleDegreeRule&)Rule1).Radius,
                                Rule2.Point,
                                ((TCircleDegreeRule&)Rule2).Radius,
                                CPS,USEEPS);
    }
    else if (
                Rule1.Is( TLineDegreeRule::StaticType ) &&
                Rule2.Is( TLineDegreeRule::StaticType )
            )
    {
        //lines
        return CrossPointsOf((TLineDegreeRule&)Rule1,(TLineDegreeRule&)Rule2,CPS,USEEPS);
    }
    else if (
                Rule1.Is( TCircleDegreeRule::StaticType ) &&
                Rule2.Is( TLineDegreeRule::StaticType )
            )
    {
        //circle and line
        return CrossCircleAndLine(
                                Rule1.Point,
                                ((TCircleDegreeRule&)Rule1).Radius,
                                ((TLineDegreeRule&)Rule2).Point,
                                ((TLineDegreeRule&)Rule2).Point+((TLineDegreeRule&)Rule2).Direction,
                                CPS,((TLineDegreeRule&)Rule2).Strongly,USEEPS);
    }
    else if (
                Rule1.Is( TLineDegreeRule::StaticType ) &&
                Rule2.Is( TCircleDegreeRule::StaticType )
            )
    {
        //line and circle
        return CrossCircleAndLine(
                                Rule2.Point,
                                ((TCircleDegreeRule&)Rule2).Radius,
                                ((TLineDegreeRule&)Rule1).Point,
                                ((TLineDegreeRule&)Rule1).Point+((TLineDegreeRule&)Rule1).Direction,
                                CPS,((TLineDegreeRule&)Rule1).Strongly,USEEPS);
    }
    else
        throw EMyException("<CrossPointsOf>: Unknown shapes combination.");
}

TIntVec _MoveTo(const TIntVec& Point, const TDegreeRule& Rule)
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
    return Res;
}

bool TG2DPoint::Update()
{
    //---------------------------------
    if ( Rules.Count == 2 )
    {
        TMDelTList<TIntVec> CPS;
        CrossPointsOf(Rules[0],Rules[1],CPS,_MBTi_eps_);
        if (CPS.Count==1)
            Point = CPS[0];
        else if (CPS.Count==2)
            Point = ( (Point-CPS[0]).Length() < (Point-CPS[1]).Length() ) ? CPS[0] :CPS[1];
        else
            return false;            
    }
    else if ( Rules.Count == 1 )
        Point = _MoveTo( Point, Rules[0] );
    else if ( Rules.Count > 2 )
        return false;

    return true;        
}

void ListToGeomObject(TGeomObject* GO,const TMDelTList<TIntVec>& Pnts,bool Solid)
{
    if ( Pnts.Count == 0 )
        return;
    TGPoint* PrevP = GO->AddPoint( Pnts[0] );
    for (int i=1;i<Pnts.Count;i++)
    {
        TGPoint* Point = GO->AddPoint( Pnts[i] );
        if (Solid)
            GO->AddCut(PrevP,Point);
        PrevP = Point;
    }
}

void TMFunction::ToGeomObject(TGeomObject* GO,MBTi a0,MBTi a1,int Count)
{
    TMDelTList<TIntVec> Lst;
    MBTi Step = (a1-a0)/Count;
    for (int i=0;i<=Count;i++)
    {
        MBTi a = a0+Step*i;
        Lst.Add( new TIntVec(CalcPolarValue(a)) );
    }
    ListToGeomObject(GO,Lst,true);
}

void TPolarLine::Initialize(const TIntVec& P1,const TIntVec& P2)
{
    TIntVec Delta = P2 - P1;
    a = Delta.y;
    b = -Delta.x;
    c = - (P1.y*b + a*P1.x);
}

MBTf TPolarLine::CalcValue(MBTf arg) const
{
    long double _Sin_ay,_Cos_ay;
    SinCos((arg)*M_PI/180,_Sin_ay,_Cos_ay);
    return -c/(a*_Cos_ay+b*_Sin_ay);
}

TIntVec TPolarLine::CalcPolarValue(MBTf arg) const
{
    long double Sin_a,Cos_a;
    SinCos((arg)*M_PI/180,Sin_a,Cos_a);
    MBTf R = -c/(a*Cos_a+b*Sin_a);
    return TIntVec( R*Cos_a,R*Sin_a,0 );
}

MBTf TPolarCircle::CalcSqrDet(const long double& Sin_a,const long double& Cos_a) const
{
    MBTf R = Radius;
    MBTf x0 = Center.x;
    MBTf y0 = Center.y;
    return (x0*Cos_a + y0*Sin_a)*(x0*Cos_a + y0*Sin_a) - y0*y0 - x0*x0 + R*R;
}

MBTf TPolarCircle::CalcValue(MBTf arg) const
{
    long double Sin_a,Cos_a;
    SinCos((arg)*M_PI/180,Sin_a,Cos_a);
    MBTf SqrDet = CalcSqrDet(Sin_a,Cos_a);
    if (SqrDet<0)
    {
        arg = MoveToEdge(arg);
        SinCos((arg)*M_PI/180,Sin_a,Cos_a);
//        SqrDet = CalcSqrDet(Sin_a,Cos_a);
        SqrDet=0;
    }
    MBTf x0 = Center.x;
    MBTf y0 = Center.y;
    return x0*Cos_a + y0*Sin_a + sqrt( SqrDet );
}

TIntVec TPolarCircle::CalcPolarValue(MBTf arg) const
{
    long double Sin_a,Cos_a;
    SinCos((arg)*M_PI/180,Sin_a,Cos_a);
    MBTf SqrDet = CalcSqrDet(Sin_a,Cos_a);
    if (SqrDet<0)
    {
        arg = MoveToEdge(arg);
        SinCos((arg)*M_PI/180,Sin_a,Cos_a);
//        SqrDet = CalcSqrDet(Sin_a,Cos_a);
        SqrDet=0;
    }
    MBTf x0 = Center.x;
    MBTf y0 = Center.y;
    MBTf R = x0*Cos_a + y0*Sin_a + sqrt( SqrDet );

    return TIntVec( R*Cos_a,R*Sin_a,0 );
}

MBTf TPolarCircle::CalcSqrDet(MBTf arg) const
{
    long double Sin_a,Cos_a;
    SinCos((arg)*M_PI/180,Sin_a,Cos_a);
    return CalcSqrDet(Sin_a,Cos_a);
}

MBTf TPolarCircle::MoveToEdge(MBTf arg) const
{
    //уже предполагается что дискриминант отрицательный
    MBTf x0 = Center.x;
    MBTf x0_2 = x0*x0;
    MBTf x0_4 = x0_2*x0_2;

    MBTf y0 = Center.y;
    MBTf y0_2 = y0*y0;
//    MBTf y0_4 = y0_2*y0_2;

    MBTf R = Radius;
    MBTf R_2 = R*R;
//    MBTf R_4 = R_2*R_2;

    MBTf DD = x0_2*y0_2*R_2 * ( x0_2 + y0_2 - R_2 );
    if (DD<-EXACT_EPSILON)
        throw EMyException("<TPolarCircle::MoveToEdge>: Error.");
    DD = sqrt(DD);
    TMDelTList<MBTf> Xs;
    MBTf ca_2_0 = ( 2*x0_2*y0_2 - 2*x0_2*R_2 + 2*y0_2*R_2 + 2*x0_4 + 4*DD )/(2*(y0_2+x0_2)*(y0_2+x0_2));
    MBTf ca_2_1 = ( 2*x0_2*y0_2 - 2*x0_2*R_2 + 2*y0_2*R_2 + 2*x0_4 - 4*DD )/(2*(y0_2+x0_2)*(y0_2+x0_2));
    Xs.Add( new MBTf(ca_2_0) );
    Xs.Add( new MBTf(ca_2_1) );
    for (int i=0;i<Xs.Count;i++)
        if ( Xs[i]<0 )
            Xs.Delete(i--);
    if ( Xs.Count == 0)
        throw EMyException("<TPolarCircle::MoveToEdge>: Error.");
    TMDelTList<MBTf> Cos;
    for (int i=0;i<Xs.Count;i++)
         AddRoot(Cos,-sqrt(Xs[i]),MBTf_EPS );
    int CosCount = Cos.Count;
    for (int i=0;i<CosCount;i++)
         AddRoot(Cos,-Cos[i],MBTf_EPS );
    for (int i=0;i<Cos.Count;i++)
        if ( fabs(Cos[i])>1 )
            Cos.Delete(i--);
            
    if ( Cos.Count == 0)
        throw EMyException("<TPolarCircle::MoveToEdge>: Error.");
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    TMDelTList<MBTf> aa;
    for (int i=0;i<Cos.Count;i++)
    {
        MBTf alpha = acosl(Cos[i])*180/M_PI;
        MBTf ret_a = CalcSqrDet(alpha);
        MBTf ret_minus_a = CalcSqrDet(-alpha);
        if ( fabs(ret_a) <= MBTi_EXACT_EPS )
            AddRoot(aa,alpha,(MBTf)MBTi_EXACT_EPS);
        if ( fabs(ret_minus_a)<=MBTi_EXACT_EPS )
            AddRoot(aa,-alpha,(MBTf)MBTi_EXACT_EPS);
    }
    for (int i=0;i<aa.Count;i++)
        aa[i] = (aa[i]>=0) ? aa[i] : aa[i]+360;
    arg = (arg>=0) ? arg : arg+360;
    CalcSqrDet( sqrt( 1 - Cos[0]*Cos[0]) ,Cos[0]);
    int BestIndex = -1;
    MBTf MinLength = 0;
    for (int i=0;i<aa.Count;i++)
        if ( BestIndex == -1 )
        {
            BestIndex = i;
            MinLength = fabs( aa[i]-arg );
        }
        else if (MinLength >fabs( aa[i]-arg ))
        {
            BestIndex = i;
            MinLength = fabs( aa[i]-arg );
        }
        else if (MinLength > ( 360 - fabs(aa[i]-arg) ))
        {
            BestIndex = i;
            MinLength = ( 360 - fabs(aa[i]-arg) );
        }
    return aa[BestIndex];
}

MBTf TPascalLimacon::CalcValueSimple(MBTf arg) const
{
    long double Sin_a,Cos_a;
    SinCos(arg*M_PI/180,Sin_a,Cos_a);
    return (a*Cos_a+l);
}

TIntVec TPascalLimacon::CalcPolarValueSimple(MBTf arg) const
{
    long double Sin_a,Cos_a;
    SinCos(arg*M_PI/180,Sin_a,Cos_a);
    MBTf R = (a*Cos_a+l);
    return TIntVec( R*Cos_a,R*Sin_a,0 );
}

bool TPascalLimacon::CrossingWithLine(const TIntVec& P0,const TIntVec& P1,TMDelTList<TIntVec>& Roots,MBTf USEEPS)
{
    Roots.Clear();
    TIntVec NewP0 = P0 - OffSet;
    TIntVec NewP1 = P1 - OffSet;
    NewP0 = RotateAround(NewP0,TIntVec(0,0,-y),ZEROINTVEC);
    NewP1 = RotateAround(NewP1,TIntVec(0,0,-y),ZEROINTVEC);
    //--------------------------------------------------------------------------
    TIntVec Delta = NewP1 - NewP0;
    MBTf la = Delta.y;
    MBTf lb = -Delta.x;
    MBTf lc = - (NewP0.y*lb + la*NewP0.x);

    TMDelTList<MBTf> _X;
    if (lc == 0)
    {
        //Этот случай не рассмотрен
        throw EMyException("<TPascalLimacon::CrossingWithLine>: Случай при lc==0 не рассмотрен.");
    }
    else
    {

        TMDelTList<MBTf> _A;
        MBTf a_2 = a*a;
        MBTf l_2 = l*l;
        MBTf lb_2 = lb*lb;
        MBTf la_2 = la*la;
        MBTf lc_2 = lc*lc;

        _A.Add( new MBTf( -a_2*lb_2 - a_2*la_2 ) );
        _A.Add( new MBTf( - 2*a*lb_2*l - 2*a*la_2*l ) );
        _A.Add( new MBTf( -l_2*lb_2 + a_2*lb_2 - l_2*la_2 - 2*a*la*lc ) );
        _A.Add( new MBTf( 2*a*lb_2*l - 2*l*la*lc ) );
        _A.Add( new MBTf( l_2*lb_2 - lc_2 ) );

        TPolinom Pol;
        Pol.Initialize( _A );
        Pol.FindRoots(-1,1,_X,MBTf_EPS);

        for (int i=0;i<_X.Count;i++)
            _X[i] = acos( _X[i] )*180/M_PI;
    }
    TPolarLine PL;
    PL.a = la;
    PL.b = lb;
    PL.c = lc;
    for (int i=0;i<_X.Count;i++)
    {
        TIntVec PL_Value_P = CalcPolarValueSimple( _X[i] );
        TIntVec L_Value_P = PL.CalcPolarValue( _X[i] );
        TIntVec PL_Value_N = CalcPolarValueSimple( -_X[i] );
        TIntVec L_Value_N = PL.CalcPolarValue( -_X[i] );
        if ( (PL_Value_P-L_Value_P).Length()<=USEEPS )
            Roots.Add( new TIntVec( CalcPolarValue(_X[i]) ) );
        if ( (PL_Value_N-L_Value_N).Length()<=USEEPS )
            Roots.Add( new TIntVec( CalcPolarValue(-_X[i]) ) );
    }
    return Roots.Count>0;
}

bool TPascalLimacon::CrossingWithCircle(const TIntVec& Center,MBTi Radius,TMDelTList<TIntVec>& Roots,MBTf USEEPS)
{
    Roots.Clear();
    TIntVec NewCenter = Center - OffSet;
    NewCenter = RotateAround(NewCenter,TIntVec(0,0,-y),ZEROINTVEC);
    //--------------------------------------------------------------------------

    TMDelTList<MBTf> _A;
    MBTf x0 = NewCenter.x;
    MBTf x0_2 = x0*x0;
    MBTf x0_3 = x0_2*x0;
    MBTf x0_4 = x0_2*x0_2;

    MBTf y0 = NewCenter.y;
    MBTf y0_2 = y0*y0;
    MBTf y0_4 = y0_2*y0_2;

    MBTf R = Radius;
    MBTf R_2 = R*R;
    MBTf R_4 = R_2*R_2;

    MBTf ua = a;
    MBTf ua_2 = ua*ua;
    MBTf ua_3 = ua_2*ua;
    MBTf ua_4 = ua_3*ua;

    MBTf ul = l;
    MBTf ul_2 = ul*ul;
    MBTf ul_3 = ul_2*ul;
    MBTf ul_4 = ul_3*ul;


    _A.Add( new MBTf( -4*ua_2*y0_2 - ua_4 + 4*ua_3*x0 - 4*ua_2*x0_2 ) );
    _A.Add( new MBTf( -4*ua_3*ul + 12*ua_2*ul*x0 - 8*ul*x0_2*ua - 8*ul*y0_2*ua ) );
    _A.Add( new MBTf( -6*ul_2*ua_2 + 12*ul_2*ua*x0 - 2*ua_2*x0_2 + 4*x0_3*ua + 2*ua_2*y0_2 + 4*y0_2*ua*x0 + 2*R_2*ua_2 - 4*R_2*ua*x0 - 4*ul_2*x0_2 - 4*ul_2*y0_2) );
    _A.Add( new MBTf( -4*ul_3*ua + 4*ul_3*x0 - 4*ul*x0_2*ua + 4*x0_3*ul + 4*ul*y0_2*ua + 4*y0_2*ul*x0 + 4*R_2*ua*ul - 4*R_2*ul*x0 ) );
    _A.Add( new MBTf( - x0_4 - R_4 - (2*x0_2*y0_2) + (2*y0_2*R_2) + 2*x0_2*R_2 - (2*ul_2*x0_2) + (2*ul_2*y0_2) + (2*ul_2*R_2) - ul_4 - y0_4 ) );

    TMDelTList<MBTf> _X;
    TPolinom Pol;
    Pol.Initialize( _A );
    Pol.FindRoots(-1,1,_X,MBTf_EPS);

    for (int i=0;i<_X.Count;i++)
        _X[i] = acos( _X[i] )*180/M_PI;

    TPolarCircle PC;
    PC.Radius = Radius;
    PC.Center = NewCenter;

    for (int i=0;i<_X.Count;i++)
    {
    
        TIntVec PL_Value_P = CalcPolarValueSimple( _X[i] );
        TIntVec PL_Value_N = CalcPolarValueSimple( -_X[i] );
        MBTi Length_P = (PL_Value_P - NewCenter).Length();
        MBTi Length_N = (PL_Value_N - NewCenter).Length();
        if ( fabs(Length_P - Radius) < USEEPS )
            Roots.Add( new TIntVec( CalcPolarValue(_X[i]) ) );
        if ( fabs(Length_N - Radius) < USEEPS )
            Roots.Add( new TIntVec( CalcPolarValue(-_X[i]) ) );
    }
    return Roots.Count>0;
}

TIntVec TPascalLimacon::FindClosestPoint(const TIntVec& P)
{
    TIntVec NewP = P - OffSet;
    NewP = RotateAround(NewP,TIntVec(0,0,-y),ZEROINTVEC);
    //---------------------------------------------------

    TMDelTList<MBTf> _A;
    TMDelTList<MBTf> _X;
    MBTf a_2 = a*a;
    MBTf a_3 = a_2*a;
    MBTf a_4 = a_3*a;
    MBTf l_2 = l*l;

    MBTi X0 = NewP.x;
    MBTi Y0_2 = NewP.y*NewP.y;
    MBTi X0_2 = NewP.x*NewP.x;

    _A.Add( new MBTf( -4*X0_2*a_2 + 4*X0*a_3 - a_4 - 4*Y0_2*a_2 ) );
    _A.Add( new MBTf( 6*l*a_2*X0 - 4*X0_2*a*l - 2*a_3*l - 4*Y0_2*l*a ) );
    _A.Add( new MBTf( a_4 + 4*X0_2*a_2 + 2*l_2*a*X0 + 4*Y0_2*a_2 - 4*X0*a_3 - Y0_2*l_2 - l_2*a_2 - X0_2*l_2 ) );
    _A.Add( new MBTf( 4*X0_2*a*l + 2*Y0_2*l*a - 6*l*a_2*X0 + 2*a_3*l ) );
    _A.Add( new MBTf( l_2*a_2 - 2*l_2*a*X0 + X0_2*l_2 - Y0_2*a_2 ) );

    TPolinom Pol;
    Pol.Initialize( _A );
    Pol.FindRoots(-1,1,_X,MBTf_EPS);
    Pol.FindRoots(-1,1,_X,MBTf_EPS);

    TMDelTList<MBTf> Args;
    for (int i=0;i<_X.Count;i++)
    {
        Args.Add( new MBTf( acos(_X[i])*180/M_PI ) );
        Args.Add( new MBTf( - *Args.Last() ) );
    }
    MBTi MinLength=0;
    int BestIndex = -1;
    for ( int i=0;i<Args.Count;i++)
    {
        TIntVec Path_Vec = NewP - CalcPolarValueSimple(Args[i]);
        MBTi Length_2 = Path_Vec&Path_Vec;
        if ( BestIndex == -1 || MinLength > Length_2 )
        {
            BestIndex = i;
            MinLength = Length_2;
        }
    }
    return CalcPolarValue( Args[BestIndex] );
}


void TPascalLimacon::Initialize(const TIntVec& P0,const TIntVec& P1,MBTi Angle,const TIntVec& PositionPoint)
{
    //нахождение параметров улитки
    TIntVec Point1 = P0;
    TIntVec Point2 = P1;
    if ( Angle>90 )
    {
        XChg<TIntVec>(Point1,Point2);
        Angle = 180-Angle;
    }
    //--------------------------------------------------------------------------
    //нахождение окружности
    TIntVec CenterPoint;
    MBTi Radius;
    TIntVec ThirdPoint = GetThirdPoint(Point1,Point2,Angle);
    CircleByThreePoints(Point1,Point2,ThirdPoint,CenterPoint,Radius);
    //--------------------------------------------------------------------------
    TMDelTList<TIntVec> Roots;

    CrossCircleAndLine(CenterPoint,Radius,ThirdPoint,PositionPoint,Roots,false,_MBTi_eps_);
    if ( Roots.Count!=1 )
    {
        if ( (Roots[0]-ThirdPoint).Length() < (Roots[1]-ThirdPoint).Length() )
            Roots.Delete(0);
        else
            Roots.Delete(1);
    }
    l = (ThirdPoint-PositionPoint).Length();
    a = 2*Radius;
    y = AngleRad( Roots[0],CenterPoint,(Point1+Point2)/2)*180/M_PI+90;
    OffSet = Roots[0];
}

void TPascalLimacon::ToGeomObject_All(TGeomObject* GO,int Count)
{
    MBTi a0 = 0;
    MBTi a1 = 360;
    TMDelTList<TIntVec> Lst;
    MBTi Step = (a1-a0)/Count;
    for (int i=0;i<=Count;i++)
    {
        MBTi a = a0+Step*i;
        Lst.Add( new TIntVec( RotateAround(CalcPolarValueSimple(a),TIntVec(0,0,y),ZEROINTVEC)+OffSet ) );
    }
    ListToGeomObject(GO,Lst,true);
}

MBTf TPascalLimacon::CalcValue(MBTf alpha) const
{
    if ( y==0 && OffSet.x==0&& OffSet.y==0 )
        return CalcValueSimple(alpha);
        
    long double sa,ca;
    SinCos( alpha*M_PI/180,sa,ca);

    long double sy,cy;
    SinCos( y*M_PI/180,sy,cy);

//    MBTf sa_2 = sa*sa;
    MBTf ca_2 = ca*ca;
//    MBTf sy_2 = sy*sy;
    MBTf cy_2 = cy*cy;

    MBTf x0 = OffSet.x;
    MBTf x0_2 = x0*x0;
    MBTf x0_3 = x0_2*x0;
    MBTf x0_4 = x0_3*x0;

    MBTf y0 = OffSet.y;
    MBTf y0_2 = y0*y0;
    MBTf y0_3 = y0_2*y0;
    MBTf y0_4 = y0_3*y0;

    MBTf a_2 = a*a;
    MBTf l_2 = l*l;

    TMDelTList<MBTf> A;
    A.Add( new MBTf( 1 ) );
    A.Add( new MBTf( -4*y0*sa - 4*ca*x0 - 2*a*sa*sy - 2*a*cy*ca ) );
    A.Add( new MBTf( 4*ca_2*x0_2 - 4*ca_2*y0_2 + 2*x0_2 - a_2*ca_2 - l_2 + 6* y0_2 + 8*ca*x0*y0*sa + 2*a*cy*x0 + a_2 - 4*ca_2*a*sy*y0 + 4*ca*x0*a*sa*sy + 2* a_2*cy*ca*sy*sa - a_2*cy_2 + 6* a*sy*y0 + 4*ca_2*a*cy*x0 + 2*a_2*cy_2*ca_2 + 4*sa*y0* a*cy*ca ) );
    A.Add( new MBTf( -4*sa*y0_3 - 4*ca*x0_3 - 6*ca*x0_2*a*cy - 4*ca*x0*a*sy*y0 - 4*ca*x0*y0_2 - 4*sa*y0*a*cy*x0 - 6*sa*y0_2*a*sy - 4*x0_2*sa*y0 + 2*l_2*sa*y0 - 2*a_2*cy*x0*sy*sa - 2*x0_2*a*sy*sa - 2*a_2*sa*y0 + 2*a_2*sa*y0*cy_2 + 2*l_2*ca*x0 - 2*a_2*cy*ca*sy*y0 - 2*a_2*cy_2*ca*x0 - 2*y0_2*a*cy*ca ) );
    A.Add( new MBTf( -a_2*y0_2*cy_2 + a_2*cy_2*x0_2 + 2*x0_3*a* cy + a_2*y0_2 + 2*y0_3*a*sy + x0_4 + y0_4 + 2*y0_2*a*cy*x0 - l_2*x0_2 + 2*x0_2*a*sy*y0 + 2*a_2*cy*x0*sy*y0 + 2*x0_2*y0_2 - l_2*y0_2 ) );

    TPolinom P;
    P.Initialize(A);
    TMDelTList<MBTf> X;

    P.FindRoots(-100000,100000,X,MBTf_EPS);

    if (X.Count>Index && X[Index]>=0)
        return X[Index];
    else
        return NaN;
}

TIntVec TPascalLimacon::CalcPolarValue(MBTf arg) const
{
    MBTf R = CalcValue(arg);
    if ( IsNan(R) )
        return TIntVec(0,0,0);
    long double Sin_a,Cos_a;
    SinCos((arg)*M_PI/180,Sin_a,Cos_a);
    return TIntVec( R*Cos_a,R*Sin_a,0 );
}

TMDelTList<int> SGNS2;



