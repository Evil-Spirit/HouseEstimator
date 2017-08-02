//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "G2DGeomV.h"
#include "G2DApproxCalcV.h"
#include "GeomObjV.h"
#include "math.h"
#include "values.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

MBTi LengthFromPointToLine(const TIntVec& Point,const TIntVec& Line1,const TIntVec& Line2)
{
	//возвращает длину и знак направление для использования вместе с Peppendicular2D
	MBTi SqrLength = fabs( (Line1-Line2) & (Line1-Line2) );
    if ( SqrLength < MINFLOAT )
    {
    	return (Line1-Point).Length();
    }

	TIntVec CR_PR = (Line1-Line2) * Point;
    if ( Classify(Point,Line1,Line2,EXACT_EPSILON) != etLEFT )
		return (CR_PR & CR_PR) / sqrtDC(SqrLength);
    else
		return (-1) * (CR_PR & CR_PR) / sqrtDC(SqrLength);
}

bool ConsistsNotStrictly(const TIntVec& P,const TIntVec& A,const TIntVec& B,MBTi USEEPS)
{
    switch( Classify(P,A,B,USEEPS) )
    {
        case etDESTINATION:
        case etORIGIN:
        case etBETWEEN:
            return true;
        default:
            return false;
    };
}

bool CrossPointStrictly(
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& B0,
                        const TIntVec& B1,
                        TIntVec& CP,
                        MBTi USEEPS)
{
    
    if (    ConsistsNotStrictly(A0,B0,B1,USEEPS) ||
            ConsistsNotStrictly(A1,B0,B1,USEEPS) ||
            ConsistsNotStrictly(B0,A0,A1,USEEPS) ||
            ConsistsNotStrictly(B1,A0,A1,USEEPS) )
    {
        //touching
        return false;
    }
    return (IsCutsCrossed(A0,A1,B0,B1,CP,USEEPS) == lcCROSSING);
}

bool CrossPointNotStrictly(
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& B0,
                        const TIntVec& B1,
                        TIntVec& CP,
                        MBTi USEEPS)
{
    switch ( IsLinesCrossedExactly(A0,A1,B0,B1,CP/*,USEEPS*/) )
    {
        case lcCOLLINEAR:
        {
            CP = A0;
            return true;
        }
        case lcCOMMONPOINT:
        case lcCROSSING:
        case lcEQUAL:
            return true;
        case lcNONE:
        case lcPARALLEL:
            return false;
        default:
            throw EMyException("<CrossPointNotStrictly>: неожиданный результат IsLinesCrossed");
    }
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

bool CircleByTwoPointsAndAngle(
                    const TIntVec& RotSrc,
                    const TIntVec& RotDst,
                    MBTi Angle,
                    TIntVec& CP,
                    MBTi& R)
{
    return CircleByThreePoints(RotSrc,RotDst,GetThirdPoint(RotSrc,RotDst,Angle),CP,R);
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
		CPS[0].y = sqrtDC( Deg(R1,2) - Deg(CPS[0].x,2) );
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
		CPS[0].x = sqrtDC( Deg(R1,2) - Deg(y,2) );
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
	return x0*Cos_a + y0*Sin_a + sqrtDC( SqrDet );
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
	MBTf R = x0*Cos_a + y0*Sin_a + sqrtDC( SqrDet );

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
        throw EMyException("<TPolarCircle::MoveToEdge>: Ошибка.");
	DD = sqrtDC(DD);
    TMDelTList<MBTf> Xs;
    MBTf ca_2_0 = ( 2*x0_2*y0_2 - 2*x0_2*R_2 + 2*y0_2*R_2 + 2*x0_4 + 4*DD )/(2*(y0_2+x0_2)*(y0_2+x0_2));
    MBTf ca_2_1 = ( 2*x0_2*y0_2 - 2*x0_2*R_2 + 2*y0_2*R_2 + 2*x0_4 - 4*DD )/(2*(y0_2+x0_2)*(y0_2+x0_2));
    Xs.Add( new MBTf(ca_2_0) );
    Xs.Add( new MBTf(ca_2_1) );
    for (int i=0;i<Xs.Count;i++)
        if ( Xs[i]<0 )
            Xs.Delete(i--);
    if ( Xs.Count == 0)
        throw EMyException("<TPolarCircle::MoveToEdge>: Ошибка.");
    TMDelTList<MBTf> Cos;
    for (int i=0;i<Xs.Count;i++)
		 AddRoot(Cos,-sqrtDC(Xs[i]),MBTf_EPS );
    int CosCount = Cos.Count;
    for (int i=0;i<CosCount;i++)
         AddRoot(Cos,-Cos[i],MBTf_EPS );
    for (int i=0;i<Cos.Count;i++)
        if ( fabs(Cos[i])>1 )
            Cos.Delete(i--);

    if ( Cos.Count == 0)
        throw EMyException("<TPolarCircle::MoveToEdge>: Ошибка.");
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
    CalcSqrDet( sqrtDC( 1 - Cos[0]*Cos[0]) ,Cos[0]);
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

bool TPascalLimacon::CrossingWithLine(const TIntVec& P0,const TIntVec& P1,TMDelTList<TIntVec>& Roots,MBTf USEEPS) const
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
        Pol.FindRoots(-1,1,_X,USEEPS*Accuracy_Booster);

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
            Roots.Add( new TIntVec( CalcPolarValueSimpleRotated(_X[i]) ) );
        if ( (PL_Value_N-L_Value_N).Length()<=USEEPS )
            Roots.Add( new TIntVec( CalcPolarValueSimpleRotated(-_X[i]) ) );
    }
    return Roots.Count>0;
}

bool TPascalLimacon::CrossingWithCircle(const TIntVec& Center,MBTi Radius,TMDelTList<TIntVec>& Roots,MBTf USEEPS) const
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
    Pol.FindRoots(-1,1,_X,USEEPS*Accuracy_Booster);

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
            Roots.Add( new TIntVec( CalcPolarValueSimpleRotated(_X[i]) ) );
        if ( fabs(Length_N - Radius) < USEEPS )
            Roots.Add( new TIntVec( CalcPolarValueSimpleRotated(-_X[i]) ) );
    }
    return Roots.Count>0;
}

TIntVec TPascalLimacon::CalcPolarValueSimpleRotated(MBTf arg) const
{
    return RotateAround(CalcPolarValueSimple(arg),TIntVec(0,0,y),ZEROINTVEC)+OffSet;
}

TIntVec TPascalLimacon::FindClosestPoint(const TIntVec& P) const
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
    return CalcPolarValueSimpleRotated( Args[BestIndex] );
}


void TPascalLimacon::Initialize(const TIntVec& P0,const TIntVec& P1,MBTi aAngle,const TIntVec& PositionPoint)
{
    //нахождение параметров улитки
    TIntVec CPoint1 = P0;
    TIntVec CPoint2 = P1;
    if ( aAngle > 180 )
    {
        XChg(CPoint1,CPoint2);
        aAngle = 360-aAngle;
    }

    MBTi CAngle = aAngle;
    //нахождение окружности
    bool Inverted = false;
    if ( CAngle>90 )
    {
        XChg(CPoint1,CPoint2);
        CAngle = 180-aAngle;
        Inverted = true;
    }
    //--------------------------------------------------------------------------
    TIntVec CenterPoint;
    MBTi Radius;
    TIntVec ThirdPoint = GetThirdPoint(CPoint1,CPoint2,CAngle);
    CircleByThreePoints(CPoint1,CPoint2,ThirdPoint,CenterPoint,Radius);
    //--------------------------------------------------------------------------

    if (CAngle!=aAngle)
    {
    	//найдем другой ThirdPoint;
	    TMDelTList<TIntVec> Roots;
	    CrossCircleAndLine(CenterPoint,Radius,CenterPoint,ThirdPoint,Roots,false,_MBTi_eps_);
        if ( Roots.Count!=1 )
        {
            if ( (Roots[0]-ThirdPoint).Length() < (Roots[1]-ThirdPoint).Length() )
                ThirdPoint = Roots[1];
            else
                ThirdPoint = Roots[0];
        }
        XChg<TIntVec>(CPoint1,CPoint2);
        CAngle = aAngle;
    }

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
    y = AngleRadOX( Roots[0],CenterPoint)*180/M_PI;//,(CPoint1+CPoint2)/2)*180/M_PI + (90 - Inverted*(1-Inverted2)*180);//+-90
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
        Lst.Add( new TIntVec( CalcPolarValueSimpleRotated(a) ) );
    }
    ListToGeomObject(GO,Lst,true);
}

MBTf TPascalLimacon::DetectDefinitionEdgeSign(MBTf a0,MBTf a1,MBTf EPS)
{
    bool a0_OK = CalcSignValue(a0)>=0;
    MBTf OKArg = (a0_OK) ? a0 : a1;
    MBTf NotOKArg = (a0_OK) ? a1 : a0;
    
    while ( fabs(OKArg - NotOKArg)>EPS )
    {
        MBTf Arg = (OKArg + NotOKArg)/2;
        if ( CalcSignValue(Arg) >= 0 )
            OKArg = Arg;
        else
            NotOKArg = Arg;
    }
    return OKArg;
}

bool TPascalLimacon::ValidateDefinitionInterval(MBTf& a0,MBTf& a1,MBTf EPS)
{
    bool a0_OK = CalcSignValue(a0)>0;
    bool a1_OK = CalcSignValue(a1)>0;
    if ( !a0_OK && !a1_OK)
        return false;
    else if ( !a1_OK )
        a1 = DetectDefinitionEdgeSign(a0,a1,EPS);
    else if ( !a0_OK )
        a0 = DetectDefinitionEdgeSign(a0,a1,EPS);
    if ( a0 > a1 )
        a0 -= 360;
    if ( IsNan( CalcValue( (a0+a1)/2 ) ) )
        XChg(a0,a1);
    if ( a0 > a1 )
        a0 -= 360;
    return true;
}

MBTf TPascalLimacon::DetectDefinitionEdge(MBTf a0,MBTf a1,MBTf EPS)
{
    bool a0_NotNan = !IsNan(CalcValue(a0));
    MBTf ExistsArg = (a0_NotNan) ? a0 : a1;
    MBTf NotExistsArg = (a0_NotNan) ? a1 : a0;
    while ( fabs(ExistsArg - NotExistsArg)>EPS )
    {
        MBTf Arg = (ExistsArg+NotExistsArg)/2;
        if ( IsNan( CalcValue(Arg) ) )
            NotExistsArg = Arg;
        else
            ExistsArg = Arg;
    }
    return ExistsArg;
}

//при условии что на этом промежутке один интервал
bool TPascalLimacon::FindDefinitionInterval(MBTf& a0,MBTf& a1,int MaxCount,MBTf EPS)
{
    int CountOfDivision = 2;
    bool a0_NotNan = !IsNan(CalcValue(a0));
    bool a1_NotNan = !IsNan(CalcValue(a1));
    if ( a0_NotNan != a1_NotNan )
    {
        if (a0_NotNan)
        {
            a1 = DetectDefinitionEdge(a0,a1,EPS);
            return ValidateDefinitionInterval(a0, a1, EPS);
        }
        else
        {
            a0 = DetectDefinitionEdge(a0,a1,EPS);
            return ValidateDefinitionInterval(a0, a1, EPS);
        }
    }
    else  //a0_NotNan == a1_NotNan !!!!
    {
        bool Finded = false;
        MBTf FindedX = a0;
        while (!Finded && CountOfDivision <= MaxCount)
        {
            MBTf Step = (a1-a0)/CountOfDivision;
            for (int i=1;i<CountOfDivision;i++)
            {
                if ( !IsNan( CalcValue(a0+Step*i) ) != a0_NotNan )
                {
                    Finded = true;
                    FindedX = a0+Step*i;
                    break;
                };
            }
            CountOfDivision = CountOfDivision*2;
        }
        if (Finded)
        {
//            if ( !a0_NotNan )
            {
                a0 = DetectDefinitionEdge(a0,FindedX,EPS);
                a1 = DetectDefinitionEdge(FindedX,a1,EPS);
                return ValidateDefinitionInterval(a0, a1, EPS);
            }
        }
        else if (a0_NotNan)
            return true;
        else
            return false;
    }
}

MBTf ValidateAngle(MBTf Angle)
{
    while (Angle>=360)
        Angle -= 360;
    while (Angle<0)
        Angle += 360;
    return Angle;        
}

MBTf TPascalLimacon::CalcSignValue(MBTf alpha) const
{
    if ( y==0 && OffSet.x==0&& OffSet.y==0 )
    {
		return CalcValueSimple(alpha);
    }

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
    TMDelTList< MBTf > X;

    P.FindRoots(MBTf_MIN,MBTf_MAX,X,MBTf_EPS);
    if (X.Count>Index)
        return X[Index];
    else
        return NaN;
}

MBTf TPascalLimacon::CalcValue(MBTf alpha) const
{
    MBTf Val = CalcSignValue(alpha);
    if ( !IsNan(Val) && ( Val>=0 || (y==0 && OffSet.x==0 && OffSet.y==0) ) )
        return Val;
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

bool TPascalLimacon::CrossingWithLimacon(TPascalLimacon& Lim,TMDelTList<TIntVec>& Roots,MBTf USEEPS) const
{
    long double Sin_y,Cos_y,Sin_sy,Cos_sy;
    SinCos(y*M_PI/180,Sin_y,Cos_y);
    SinCos(Lim.y*M_PI/180,Sin_sy,Cos_sy);
    //--------------------------------------
    MBTf My_y = y;
    TIntVec My_OffSet = OffSet;
    MBTf Lim_y = Lim.y;
    TIntVec Lim_OffSet = Lim.OffSet;
    //--------------------------------------
    y = y+(-Lim.y);
    OffSet.x = (My_OffSet.x-Lim.OffSet.x)*Cos_sy + (My_OffSet.y-Lim.OffSet.y)*Sin_sy;
    OffSet.y = (My_OffSet.y-Lim.OffSet.y)*Cos_sy - (My_OffSet.x-Lim.OffSet.x)*Sin_sy;

    Lim.y = 0;
    Lim.OffSet = ZEROINTVEC;
    //--------------------------------------
    MBTf x0 = OffSet.x;
    MBTf x0_2 = x0*x0;
    MBTf x0_3 = x0_2*x0;
    MBTf x0_4 = x0_3*x0;

    MBTf y0 = OffSet.y;
    MBTf y0_2 = y0*y0;
    MBTf y0_3 = y0_2*y0;
    MBTf y0_4 = y0_3*y0;

    MBTf a_2 = a*a;
    MBTf a_3 = a_2*a;
    MBTf a_4 = a_3*a;

    MBTf l_2 = l*l;
    MBTf l_3 = l_2*l;
    MBTf l_4 = l_3*l;

    MBTf ul2 = Lim.l;
    MBTf ul2_2 = ul2*ul2;
    MBTf ul2_3 = ul2_2*ul2;
    MBTf ul2_4 = ul2_3*ul2;

    MBTf ua2 = Lim.a;
    MBTf ua2_2 = ua2*ua2;
    MBTf ua2_3 = ua2_2*ua2;
    MBTf ua2_4 = ua2_3*ua2;

    long double sy,cy;
    SinCos(y*M_PI/180,sy,cy);

    MBTf sy_2 = sy*sy;
    MBTf sy_3 = sy_2*sy;
    MBTf sy_4 = sy_3*sy;

    MBTf cy_2 = cy*cy;
    MBTf cy_3 = cy_2*cy;
    MBTf cy_4 = cy_3*cy;


    MBTf COSGG0a1_i_0 = 2*y0_3*a*sy + 2*x0_3*a*cy - a_2*cy_2*ul2_2 - a_2*y0_2*cy_2 + 6*y0_2*ul2_2 + a_2*cy_2*x0_2 + 2*x0_2*ul2_2 - l_2*ul2_2 + a_2*ul2_2 + 2*a_2*cy*x0*sy*y0 + 2*x0_2*a*sy*y0 + ul2_4 + 2*a*cy*x0*ul2_2 + 6*a*sy*y0*ul2_2 + 2*x0_2*y0_2 - l_2*x0_2 - l_2*y0_2 + x0_4 + y0_4 + a_2*y0_2 + 2*y0_2*a*cy*x0;
    MBTf COSGG0a1_i_1 = -4*x0*ul2_3 - 4*x0_3*ul2 + 4*ua2*ul2_3 + 2*a_2*ua2*ul2 - 2*a_2*cy_2*ua2*ul2 - 2*l_2*ua2*ul2 - 2*a*cy*ul2_3 + 4*a*cy*x0*ua2*ul2 + 12*y0_2*ua2*ul2 + 4*x0_2*ua2*ul2 - 6*x0_2*a*cy*ul2 - 2*y0_2*a*cy*ul2 - 2*a_2*cy*sy*y0*ul2 - 4*x0*a*sy*y0*ul2 + 12*a*sy*y0*ua2*ul2 + 2*l_2*x0*ul2 - 2*a_2*cy_2*x0*ul2 - 4*x0*y0_2*ul2;
    MBTf COSGG0a1_i_2 = - l_2*ua2_2 - 4*y0_2*ul2_2 - 4*x0_3*ua2 + a_2*ua2_2 - a_2*ul2_2 + 4*x0_2*ul2_2 + 2*x0_2*ua2_2 + 6*y0_2*ua2_2 + 6*ua2_2*ul2_2 - a_2*cy_2*ua2_2 + 2*a_2*cy_2*ul2_2 - 12*x0*ua2*ul2_2 - 6*a*cy*ua2*ul2_2 + 2*a*cy*x0*ua2_2 + 4*a*cy*x0*ul2_2 - 4*a*sy*y0*ul2_2 - 6*x0_2*a*cy*ua2 - 2*a_2*cy*sy*y0*ua2 - 4*x0*a*sy*y0*ua2 + 6*a*sy*y0*ua2_2 + 2*l_2*x0*ua2 - 2*a_2*cy_2*x0*ua2 - 4*x0*y0_2*ua2 - 2*y0_2*a*cy*ua2;
    MBTf COSGG0a1_i_3 = 4*ua2_3*ul2 + 8*x0_2*ua2*ul2 - 2*a_2*ua2*ul2 - 8*y0_2*ua2*ul2 + 4*a_2*cy_2*ua2*ul2 - 12*x0*ua2_2*ul2 - 6*a*cy*ua2_2*ul2 + 8*a*cy*x0*ua2*ul2 - 8*a*sy*y0*ua2*ul2;
    MBTf COSGG0a1_i_4 = -4*x0*ua2_3 - 4*y0_2*ua2_2 - a_2*ua2_2 + 4*x0_2*ua2_2 + ua2_4 + 2*a_2*cy_2*ua2_2 + 4*a*cy*x0*ua2_2 - 4*a*sy*y0*ua2_2 - 2*a*cy*ua2_3;

    MBTf COSGG1a1_i_0 = -4*y0_3*ul2 - 4*y0*ul2_3 + 2*a_2*y0*cy_2*ul2 - 2*a_2*cy*x0*sy*ul2 - 6*y0_2*a*sy*ul2 - 2*x0_2*a*sy*ul2 - 2*a_2*y0*ul2 - 4*x0_2*y0*ul2 + 2*l_2*y0*ul2 - 2*a*sy*ul2_3 - 4*y0*a*cy*x0*ul2;
    MBTf COSGG1a1_i_1 = -4*x0_2*y0*ua2 - 2*a_2*cy*x0*sy*ua2 + 8*x0*y0*ul2_2 - 2*a_2*y0*ua2 + 2*a_2*y0*cy_2*ua2 + 2*a_2*cy*sy*ul2_2 + 4*x0*a*sy*ul2_2 - 12*y0*ua2*ul2_2 - 2*x0_2*a*sy*ua2 - 4*y0_3*ua2 + 4*y0*a*cy*ul2_2 - 6*a*sy*ua2*ul2_2 - 6*y0_2*a*sy*ua2 - 4*y0*a*cy*x0*ua2 + 2*l_2*y0*ua2;
    MBTf COSGG1a1_i_2 = -12*y0*ua2_2*ul2 - 6*a*sy*ua2_2*ul2 + 8*x0*a*sy*ua2*ul2 + 16*x0*y0*ua2*ul2 + 8*y0*a*cy*ua2*ul2 + 4*a_2*cy*sy*ua2*ul2;
    MBTf COSGG1a1_i_3 = -2*a*sy*ua2_3 + 8*x0*y0*ua2_2 + 4*x0*a*sy*ua2_2 + 4*y0*a*cy*ua2_2 - 4*y0*ua2_3 + 2*a_2*cy*sy*ua2_2;

    MBTf COSGG0a1_i_0_2 = COSGG0a1_i_0*COSGG0a1_i_0;
    MBTf COSGG0a1_i_1_2 = COSGG0a1_i_1*COSGG0a1_i_1;
    MBTf COSGG0a1_i_2_2 = COSGG0a1_i_2*COSGG0a1_i_2;
    MBTf COSGG0a1_i_3_2 = COSGG0a1_i_3*COSGG0a1_i_3;
    MBTf COSGG0a1_i_4_2 = COSGG0a1_i_4*COSGG0a1_i_4;

    MBTf COSGG1a1_i_0_2 = COSGG1a1_i_0*COSGG1a1_i_0;
    MBTf COSGG1a1_i_1_2 = COSGG1a1_i_1*COSGG1a1_i_1;
    MBTf COSGG1a1_i_2_2 = COSGG1a1_i_2*COSGG1a1_i_2;
    MBTf COSGG1a1_i_3_2 = COSGG1a1_i_3*COSGG1a1_i_3;

    TMDelTList<MBTf> Cfc_Invert;

	Cfc_Invert.Add( new MBTf( COSGG1a1_i_0_2 - COSGG0a1_i_0_2 ) );
	Cfc_Invert.Add( new MBTf( -2*COSGG0a1_i_0*COSGG0a1_i_1 + 2*COSGG1a1_i_0*COSGG1a1_i_1 ) );
	Cfc_Invert.Add( new MBTf( -2*COSGG0a1_i_0*COSGG0a1_i_2 + 2*COSGG1a1_i_0*COSGG1a1_i_2 + COSGG1a1_i_1_2 - COSGG0a1_i_1_2 - COSGG1a1_i_0_2 ) );
	Cfc_Invert.Add( new MBTf( -2*COSGG1a1_i_0*COSGG1a1_i_1 + 2*COSGG1a1_i_1*COSGG1a1_i_2 - 2*COSGG0a1_i_0*COSGG0a1_i_3 - 2*COSGG0a1_i_1*COSGG0a1_i_2 + 2*COSGG1a1_i_0*COSGG1a1_i_3 ) );
	Cfc_Invert.Add( new MBTf( -2*COSGG0a1_i_1*COSGG0a1_i_3 - 2*COSGG0a1_i_0*COSGG0a1_i_4 - 2*COSGG1a1_i_0*COSGG1a1_i_2 + 2*COSGG1a1_i_1*COSGG1a1_i_3 - COSGG0a1_i_2_2 - COSGG1a1_i_1_2 + COSGG1a1_i_2_2 ) );
	Cfc_Invert.Add( new MBTf( -2*COSGG0a1_i_1*COSGG0a1_i_4 - 2*COSGG1a1_i_0*COSGG1a1_i_3 - 2*COSGG0a1_i_2*COSGG0a1_i_3 - 2*COSGG1a1_i_1*COSGG1a1_i_2 + 2*COSGG1a1_i_2*COSGG1a1_i_3 ) );
	Cfc_Invert.Add( new MBTf( -2*COSGG1a1_i_1*COSGG1a1_i_3 - 2*COSGG0a1_i_2*COSGG0a1_i_4 - COSGG0a1_i_3_2 - COSGG1a1_i_2_2 + COSGG1a1_i_3_2 ) );
	Cfc_Invert.Add( new MBTf( -2*COSGG1a1_i_2*COSGG1a1_i_3 - 2*COSGG0a1_i_3*COSGG0a1_i_4 ) );
	Cfc_Invert.Add( new MBTf( - COSGG1a1_i_3_2 - COSGG0a1_i_4_2 ) );

    TMDelTList<MBTf> Cfc;
    for (int i=Cfc_Invert.Count-1;i>=0;i--)
	    Cfc.Add( new MBTf(Cfc_Invert[i]) );

    TMDelTList<MBTf> Cos;

	TPolinom P;
    P.Initialize(Cfc);
    P.FindRoots(-1,1,Cos,USEEPS*Accuracy_Booster);

    TMDelTList<MBTf> aCos;
    for (int i=0;i<Cos.Count;i++)
    {
    	aCos.Add( new MBTf( acosl(Cos[i])*180/M_PI ) );
    	aCos.Add( new MBTf( - (*aCos.Last()) ) );
    }

    for (int i=0;i<aCos.Count;i++)
    {
    	MBTf RValSimple = Lim.CalcSignValue( aCos[i] );
        for (Index=0;Index<4;Index++)
        {
			MBTf RVal = CalcSignValue( aCos[i] );
        	if ( !IsNan(RVal) && fabs( CalcSignValue( aCos[i] )-RValSimple )<=USEEPS )
                Roots.Add( new TIntVec( Lim.CalcPolarValue( aCos[i] ) ) );
        }
    }


    /*
    MBTf Def_Int[4][2];
    for (Index = 0;Index<4;Index++)
    {
        Def_Int[Index][0] = 0;
        Def_Int[Index][1] = 360;
        if ( !FindDefinitionInterval(Def_Int[Index][0],Def_Int[Index][1],MaxDivisionCount,USEEPS) )
        {
            Def_Int[Index][0] = NaN;
            Def_Int[Index][1] = NaN;
        }
    }

    MBTf Simple_Def_Int[2][2];
    for (int i = 0;i<2;i++)
    {
        Simple_Def_Int[i][0] = 0;
        Simple_Def_Int[i][1] = 360;
        Lim.Index = i;
        if (!Lim.FindDefinitionInterval(Simple_Def_Int[i][0],Simple_Def_Int[i][1],MaxDivisionCount,USEEPS))
        {
            Simple_Def_Int[i][0] = NaN;
            Simple_Def_Int[i][1] = NaN;
        }
    }

    MBTf CrossStructure[4][2][2];
    for ( int i=0; i<4; i++ )
        for ( int j=0; j<2; j++ )
        {
            float Edge0,Edge1;
            if (    (
                    (!IsNan(Def_Int[i][0]) && !IsNan(Def_Int[i][1])) &&
                    (!IsNan(Simple_Def_Int[j][0]) && !IsNan(Simple_Def_Int[j][1]))
                    )&&
                    Cross_Length(   Def_Int[i][0],Def_Int[i][1],
                                    Simple_Def_Int[j][0],Simple_Def_Int[j][1],
                                    Edge0,Edge1,
                                    USEEPS,0 )
                )
            {
                CrossStructure[i][j][0] = Edge0;
                CrossStructure[i][j][1] = Edge1;
            }
            else
            {
                CrossStructure[i][j][0] = NaN;
                CrossStructure[i][j][1] = NaN;
            }
        }

    TFunctionCrossing FC;
    FC.Initialize(*this,4,Lim,4);
    TMDelTList<MBTf> _Roots[4][2];
    for ( int i=2; i<3; i++ )
        for ( int j=1; j<2; j++ )
            if ( !IsNan(CrossStructure[i][j][0]) && !IsNan(CrossStructure[i][j][1]) )
            {
                Index = i;
                Lim.Index = j;
                FC.FindRoots( CrossStructure[i][j][0], CrossStructure[i][j][1], _Roots[i][j],USEEPS,true);
            }
    for ( int i=0; i<4; i++ )
        for ( int j=0; j<2; j++ )
            for (int k=0;k<_Roots[i][j].Count;k++)
            {
                Lim.Index = j;  
                Roots.Add( new TIntVec( Lim.CalcPolarValue(_Roots[i][j][k]) ) );
            }
    //--------------------------------------------------------------------------
    */
    y = My_y;
    OffSet = My_OffSet;
    Lim.y = Lim_y;
    Lim.OffSet = Lim_OffSet;
    //--------------------------------------------------------------------------
    for (int i=0;i<Roots.Count;i++)
    {
        Roots[i] = RotateAround(Roots[i],TIntVec(0,0,Lim_y),ZEROINTVEC)+Lim_OffSet;
    }
    return Roots.Count>0;
}


