//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include "MathV.h"
#pragma hdrstop

#include "math.h"
#include "Math.hpp"
#include "stdlib.h"

#pragma package(smart_init)

/////////////
// Vectors //
/////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

TIntVec ABS(const TIntVec &v)
{
	return TIntVec(fabs(v.x), fabs(v.y), fabs(v.z));
}

TIntVec PointOfLineOnCut(const TIntVec &src, const TIntVec &dst, MBTi t)
{
	return src + (dst - src).Normalize()*t;
}
TIntVec PointOnCut(const TIntVec &src, const TIntVec &dst, MBTi t)
{
	return src + (dst - src)*t;
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
bool VectorsParallel(const TIntVec &N1, const TIntVec &N2, MBTi EPS)
{	
	
	TIntVec A1 = N1.Normalize();
	TIntVec A2 = N2.Normalize();
//	return 1-fabs(ScalarP(A1, A2))<EPS;

	return ((A1-A2).Length()<GET_CEPS(EPS) || (A1+A2).Length()<GET_CEPS(EPS));
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
bool VectorsPerpendicular(const TIntVec &N1, const TIntVec &N2, MBTi EPS)
{	
//	TIntVec A1 = N1.Normalize();
//	TIntVec A2 = (N1*N2*N2).Normalize();
//	return ((A1-A2).Length()<GET_CEPS(EPS) || (A1+A2).Length()<GET_CEPS(EPS));
	return fabs(ScalarP(N1, N2))<EPS;
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
bool VectorsParallel2d( TIntVec N1, TIntVec N2, MBTi EPS)
{
	N1.z = 0;
	N2.z = 0;
	TIntVec A1 = N1.Normalize();
	TIntVec A2 = N2.Normalize();
//	return 1-fabs(ScalarP(A1, A2))<EPS;
	return ((A1-A2).Length2D()<GET_CEPS(EPS) || (A1+A2).Length2D()<GET_CEPS(EPS));
}

double ASinACosDomainCheck(double num, MBTi EPS)
{
	double converted = num;
	if(converted > 1 && converted <= (1 + EPS))
	{
		converted = 1;
	}
	if(converted < -1 && converted >= (-1 - EPS))
	{
		converted = -1;
	}
	return converted;
}

double SqrtDomainCheck(double num, MBTi EPS)
{
	double converted = num;
	if(converted <0 && converted >= (-EPS))
	{
		converted = 0;
	}
	return converted;
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
C:\CAD_DEMO\Source\Math\MathV.cpp  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
bool VectorsPerpendicular2d(TIntVec N1, TIntVec N2, MBTi EPS)
{
	N1.z = 0;
	N2.z = 0;
	TIntVec A1 = N1.Normalize();
	TIntVec A2 = (N1*N2*N2).Normalize();
//	return fabs(ScalarP(A1, A2))<EPS;
	return ((A1-A2).Length2D()<GET_CEPS(EPS) || (A1+A2).Length2D()<GET_CEPS(EPS));
}

void AssignVec(TVisMathVector& Dest,const TIntVec& Src )
{
	Dest = Src;
}

void AssignVisVec(TVisVector& Dest,const TIntVec& Src )
{
	Dest.X = Src.x;
	Dest.Y = Src.y;
	Dest.Z = Src.z;
}

TVisMathVector VisMathVec(const TIntVec& Src)
{
	TVisMathVector temp;
	temp.x = Src.x;
	temp.y = Src.y;
	temp.z = Src.z;
	
	return temp;
}



TIntVec SIGNVEC(const TIntVec &Vec)
{
	return(TIntVec( SIGN(Vec.x),SIGN(Vec.y),SIGN(Vec.z) ));
}



//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////
// Classify //
//////////////

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! XX.03.2005!!
  !!!!!!!!!!!!!!!*/
int Classify(const TIntVec& P, const TIntVec& A, const TIntVec& B, MBTi EPS)
{
	TIntVec l = (B-A);
    l.z = 0;//поддержка на случай точек не на плоскости
	MBTi ro = DistancePointPlane(P, VectorP2d(l), A);
	if (ro<-EPS)
		return etLEFT;
	if (ro>EPS)
		return etRIGHT;

	if (P.Equal2D(A, EPS))
		return etORIGIN;
	if (P.Equal2D(B, EPS))
		return etDESTINATION;

	MBTi roA = DistancePointPlane(A, l, P);
	MBTi roB = DistancePointPlane(B, l, P);

	if (MIN(roA, roB)>0)
		return etBEHIND;

	if (MAX(roA, roB)<0)
		return etBEYOND;
	return etBETWEEN;	
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! XX.03.2005!!
  !!!!!!!!!!!!!!!*/
int EdgeType(const TIntVec& A, const TIntVec& V0,const TIntVec& V1,MBTi USEEPS)
{

  switch (Classify(A, V0, V1,USEEPS))
  {
	case etLEFT:
		return (((V0.y<A.y-USEEPS)&&(A.y-USEEPS<=V1.y)) ? ettCROSSING : ettINESSENTIAL);
	case etRIGHT:
		return (((V1.y<A.y-USEEPS)&&(A.y-USEEPS<=V0.y)) ? ettCROSSING : ettINESSENTIAL);
		
	case etBETWEEN:
	case etORIGIN:
	case etDESTINATION:
		return ettTOUCHING;
	case etBEYOND:
		if ((A.y <= V1.y+USEEPS) && (A.y > V0.y + USEEPS) && (A.x<V1.x))
			return ettCROSSING;
		return ettINESSENTIAL;

	case etBEHIND:
		if ((A.y > V1.y+USEEPS) && (A.y <= V0.y + USEEPS) && (A.x<V0.x))
			return ettCROSSING;
		return ettINESSENTIAL;
	default:
		return ettINESSENTIAL;          
  }
}

///////////////////////////
// Расстояния (Distance) //
///////////////////////////
//OK
/*
TODO : нормализовать нормаль

*/

MBTi DistancePointPlane(const TIntVec &P, const TIntVec &N, const TIntVec &O)
{
	TIntVec No = N.Normalize();
	return ScalarP(P, No) - ScalarP(O, No);
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
MBTi DistancePointLine(const TIntVec &P, const TIntVec &A, const TIntVec &B)
{
	TIntVec I;
	PlaneSegmentCross((A-B).Normalize(), P, A, B, false, false, I, MBTi_EPS);
	return (P-I).Length();
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/

  MBTi DistancePointLine2d(const TIntVec &P, const TIntVec &A, const TIntVec &B)
{
	return DistancePointPlane(P, VectorP2d(B-A), A);
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 26.03.2005!!
  !!!!!!!!!!!!!!!*/
MBTi DistancePointCut(const TIntVec &P, const TIntVec &A, const TIntVec &B)
{
	TIntVec I;
	int res = PlaneCutCrossClass((B-A).Normalize(), P, A, B,  I, 0);

	if ( res == comCROSS)
		return (P-I).Length();

	if ( res == comPOSITIVE)
		return (P-A).Length();

	if ( res == comNEGATIVE)
		return (P-B).Length();
		
//	throw EMyException("DistancePointCut - критическая ошибка!");
	return 0;
}

// ....
bool DistanceLineLine(const TIntVec &A1, const TIntVec &B1, const TIntVec &A2, const TIntVec &B2, MBTi &Dist, MBTi USEEPS)
{
	TIntVec L1 = B1-A1;
	TIntVec L2 = B2-A2;
	if (VectorsParallel(L1, L2, USEEPS))
		return false;
		
	TIntVec N = VectorP(L1, L2).Normalize();

	MBTi D1 = -ScalarP(B1, N);
	MBTi D2 = -ScalarP(A2, N);

	Dist = fabs(D1 - D2);
	
	return true;
}

///////////////////
// Углы (Angle)	 //
///////////////////

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!*/
TIntVec GetToPlaneTransformation(const TIntVec &n)
{
	TIntVec ang;
	ang.x = ArcTan2(n.y, n.z)/M_PI*180;
	TIntVec nNormal = RotateAround(n, TIntVec(ang.x,0,0), TIntVec(0,0,0));
	ang.y = -ArcTan2(nNormal.x, nNormal.z)/M_PI*180;
	ang.z = 0;
	return ang;
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!*/
TIntVec TransformTo(const TIntVec &v, const TIntVec &ang)
{
	TIntVec temp = v;
	temp = RotateAround(temp, TIntVec(ang.x, 0, 0), TIntVec(0,0,0));
	temp = RotateAround(temp, TIntVec(0, ang.y, 0), TIntVec(0,0,0));
	return temp;
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!*/
TIntVec TransformFrom(const TIntVec &v, const TIntVec &ang)
{
	TIntVec temp = v;
	temp = RotateAround(temp, TIntVec(0, -ang.y, 0), TIntVec(0,0,0));
	temp = RotateAround(temp, TIntVec(-ang.x, 0, 0), TIntVec(0,0,0));
	return temp;
}


/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!*/
MBTi AngleRad(  const TIntVec& Src0,
				const TIntVec& Dst0,
				const TIntVec& Src1,
				const TIntVec& Dst1, MBTi USEEPS)
{
	TIntVec SDVIG = Src1-Src0;
	return AngleRad(Dst0,Src0,Dst1-SDVIG, USEEPS);
}


/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!*/
MBTi AngleRad(const TIntVec& X1,const TIntVec& X2,const TIntVec& X3, MBTi USEEPS)
{
	//A - X1 B - X2 C - X3
	if (    (X1.x==X2.x && X1.y==X2.y) ||
			(X1.x==X3.x && X1.y==X3.y) ||
			(X3.x==X2.x && X3.y==X2.y) )
		return 0;

	TIntVec a = X2 - X1;
	TIntVec b = X3 - X1;

	bool ostry;

	switch (Classify(X3, X1, X2, USEEPS))
	{
		// угол меньше 180
		case etLEFT:    ostry = true;   break;
		// угол больше 180
		case etRIGHT:   ostry = false;  break;
		//развернутый
		case etBEYOND:  return M_PI;
		default:        return 0;
	}

	double a2 = ((double)(X1.x-X2.x))*((double)(X1.x-X2.x)) + ((double)(X1.y-X2.y))*((double)(X1.y-X2.y));
	double b2 = ((double)(X3.x-X2.x))*((double)(X3.x-X2.x)) + ((double)(X3.y-X2.y))*((double)(X3.y-X2.y));
	double c2 = ((double)(X1.x-X3.x))*((double)(X1.x-X3.x)) + ((double)(X1.y-X3.y))*((double)(X1.y-X3.y));

	 double cosC = (0.5)*(a2+b2-c2)/sqrtDC(a2*b2);

	MBTi res = acosDC(cosC);
	if (ostry)
		return res;
	else
		return 2*M_PI - res;
}

//            .X2
//           /
//         /
//       /
//  X1./----------.X3

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!*/
MBTi AngleRadOX(const TIntVec& X1,const TIntVec& X2, MBTi USEEPS)
{
	TIntVec X3 = X1;
	X3.x = X3.x+5;
	return AngleRad(X2,X1,X3, USEEPS);
}

long double FAngle[3];
long double SIN[3];
long double COS[3];
TIntVec Decart;

TIntVec RotateAround(const TIntVec& Point,const TIntVec& Angle,const TIntVec& Center)
{
	Decart = Point-Center;
	if (Decart==ZEROINTVEC)
		return(Point);
	for (int i=0;i<3;i++)
	{
		if (Angle.a[(i+2) % 3] == 0)
			continue;
		MBTi x = Decart.a[i];
		MBTi y = Decart.a[(i+1) % 3];
		MBTi _angle = (Angle.a[(i+2) % 3]*M_PI)/180;
		if (x!=0||y!=0)
		{
			if (_angle!=FAngle[i])
			{
				SinCos(_angle,SIN[i],COS[i]);
				FAngle[i] = _angle;
			}
			Decart.a[i]             = x*COS[i] - y*SIN[i];
			Decart.a[(i+1) % 3]     = x*SIN[i] + y*COS[i];
		}
	}
	return(Decart+Center);
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 26.03.2005!!
  !!!!!!!!!!!!!!!*/
bool LineConsistsPoint(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS)
{
	return (DistancePointLine(P, A, B) < USEEPS);
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 26.03.2005!!
  !!!!!!!!!!!!!!!*/
bool LineConsistsPoint2d(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS)
{
	return fabs(DistancePointLine2d(P, A, B)) < USEEPS;
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 26.03.2005!!
  !!!!!!!!!!!!!!!*/
bool CutConsistsPoint2d(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS)
{
	int res = Classify(P, A, B, USEEPS);
	return (res == etBETWEEN || res == etDESTINATION || res == etORIGIN );
//	return (DistancePointCut(P, A, B) < USEEPS);
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 26.03.2005!!
  !!!!!!!!!!!!!!!*/
bool CutConsistsPoint(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS)
{
	return (DistancePointCut(P, A, B) < USEEPS);
}


/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 26.03.2005!!
  !!!!!!!!!!!!!!!*/
bool PlanePlaneCross(	const TIntVec &N1, const TIntVec &O1,
						const TIntVec &N2, const TIntVec &O2,
						TIntVec &NL, TIntVec &OL, MBTi USEEPS)
{
	if (VectorsParallel(N1, N2, USEEPS))
		return false;
	NL = VectorP(N1, N2).Normalize();
	TIntVec N = VectorP(NL, N2).Normalize();
	if (PlaneLineCross(N1, O1, O2, O2 + N, OL, USEEPS) == 1)
		return true;
	return false;	
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
int PlaneSegmentCross(	const	TIntVec& N,	//нормаль
						const	TIntVec& A,	//точка на плоскости

						const	TIntVec& X,	//прямая точка 1
						const	TIntVec& Y,	//прямая точка 2

						bool	xFix,		//попадание начала
						bool	yFix,		//попаданеие конца

						TIntVec& O, 		//точка пересечения
						
						MBTi USEEPS)    	//мера параллельности
{
	if (VectorsPerpendicular(N, Y-X, USEEPS))
		return comNONCROSS;

	MBTi dX = DistancePointPlane(X, N, A);
	MBTi dY = DistancePointPlane(Y, N, A);

	if (xFix && ((MIN(dX, dY)>USEEPS && dX<dY) || (MAX(dX, dY)<-USEEPS) && dX>dY))
		return comNONCROSS;

	if (yFix && ((MIN(dX, dY)>USEEPS && dY<dX) || (MAX(dX, dY)<-USEEPS) && dY>dX))
		return comNONCROSS;
	
	if ((xFix || yFix) && MIN(fabs(dX), fabs(dY))<USEEPS)
		if (fabs(dY) < fabs(dX))
		{
			if (yFix)
			{
				O = Y;
				return comTOUCH;
			}
		} else
		{
			if (xFix)
			{
				O = X;
				return comTOUCH;
			}	
		}

	TIntVec V = A - X ;
	// расстояние до плоскости по нормали
	MBTi d = ScalarP ( N, V );
	
	TIntVec W = Y - X;

    //Drive
	// приближение к плоскости по нормали при прохождении отрезка
	if (!VectorsPerpendicular(N, W, USEEPS))
	{
		MBTi e = ScalarP ( N, W );
		O = X + W * (d/e);
		return comCROSS;
	}
	else
		return comNONCROSS;
    //Drive

    /*/Old */
	// приближение к плоскости по нормали при прохождении отрезка
	MBTi e = ScalarP ( N, W );
	
	/*TODO: Проверить деление на ноль*/
	
	O = X + W * (d/e);
	return comCROSS;
    //*/
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
int  PlaneCutCrossClass(	const TIntVec& N,//точка на плоскости
							const TIntVec& A,//нормаль
							const TIntVec& X,//прямая точка 1
							const TIntVec& Y,//прямая точка 2
							TIntVec& O, //точка пересечения
							MBTi USE_PEPS)    //мера параллельности
{
	// определить факт пересечения отрезка и плоскости.

	MBTi d1 = DistancePointPlane(X, N ,A);
	MBTi d2 = DistancePointPlane(Y, N ,A);

	if (MIN(d1, d2)>=USE_PEPS)
		return comPOSITIVE;
		
	if (MAX(d1, d2)<=-USE_PEPS)
		return comNEGATIVE;

	if (MIN(fabs(d1), fabs(d2))<USE_PEPS)
		if (fabs(d2) < fabs(d1))
		{
			O = Y;
			return comTOUCH;
		} else
		{
			O = X;
			return comTOUCH;
		}
	
	TIntVec V = A - X ;
	// расстояние до плоскости по нормали

	MBTi d = ScalarP ( N, V );
	TIntVec W = Y - X;

	// приближение к плоскости по нормали при прохождении отрезка
	if (!VectorsPerpendicular(N, W, USE_PEPS))
	{
		MBTi e = ScalarP ( N, W );
		O = X + W * (d/e);
		return comCROSS;
	}
/*	else if( fabs(d)<=USE_PEPS)
	{
		O = X;
		return PCC_COLLINEAR;
	}*/
	else
		return comNONCROSS;
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
int PlaneLineCross(	const	TIntVec& N,	//нормаль
					const	TIntVec& A,	//точка на плоскости

					const	TIntVec& X,	//прямая точка 1
					const	TIntVec& Y,	//прямая точка 2
					TIntVec& O, 		//точка пересечения
						
					MBTi USEEPS)    	//мера параллельности

{
	return PlaneSegmentCross(N, A, X, Y, false, false, O, USEEPS);
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
int PlaneCutCross(	const	TIntVec& N,	//нормаль
					const	TIntVec& A,	//точка на плоскости

					const	TIntVec& X,	//прямая точка 1
					const	TIntVec& Y,	//прямая точка 2
					TIntVec& O, 		//точка пересечения
						
					MBTi USEEPS)    	//мера параллельности

{
	return PlaneSegmentCross(N, A, X, Y, true, true, O, USEEPS);
}

/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
int CutCutCross2d(const TIntVec &A1, const TIntVec &B1, const TIntVec &A2, const TIntVec &B2, TIntVec &itr, MBTi USEEPS)
{
	MBTi ro;
	TIntVec L1 = B1 - A1;
	TIntVec L2 = B2 - A2;

/*	if (VectorsParallel(L1, L2))
		return false;
*/
	int A1C2 = Classify(A1, A2, B2, USEEPS);
	int B1C2 = Classify(B1, A2, B2, USEEPS);

	int A2C1 = Classify(A2, A1, B1, USEEPS);
	int B2C1 = Classify(B2, A1, B1, USEEPS);

	if (A1C2 == etORIGIN || A1C2 == etDESTINATION){itr = A1;return comTOUCH;}
	if (B1C2 == etORIGIN || B1C2 == etDESTINATION){itr = B1;return comTOUCH;}
	if (A2C1 == etORIGIN || A2C1 == etDESTINATION){itr = A2;return comTOUCH;}
	if (B2C1 == etORIGIN || B2C1 == etDESTINATION){itr = B2;return comTOUCH;}


	if (B2C1 == etBETWEEN) { itr = B2;return comTOUCH;}
	if (A2C1 == etBETWEEN) { itr = A2;return comTOUCH;}
	if (B1C2 == etBETWEEN) { itr = B1;return comTOUCH;}
	if (A1C2 == etBETWEEN) { itr = A1;return comTOUCH;}
		

	if (A1C2 == etLEFT && B1C2 == etLEFT ||
		A1C2 == etRIGHT && B1C2 == etRIGHT ||
		A2C1 == etLEFT && B2C1 == etLEFT ||
		A2C1 == etRIGHT && B2C1 == etRIGHT ||
		A1C2 == etBEHIND || A1C2 == etBEYOND ||
		B1C2 == etBEHIND || B1C2 == etBEYOND ||
		A2C1 == etBEHIND || A2C1 == etBEYOND ||
		B2C1 == etBEHIND || B2C1 == etBEYOND)
		return comNONCROSS;



	TIntVec N1 = VectorP2d(L1).Normalize();

	PlaneLineCross(N1, A1, A2, B2, itr, USEEPS);
	
	
	return comCROSS;
}


/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
int SegmentSegmentCross2d(
	const TIntVec &A1,
	const TIntVec &B1,
	const TIntVec &A2,
	const TIntVec &B2,
	bool a1Fix,
	bool b1Fix,
	bool a2Fix,
	bool b2Fix ,
	TIntVec &itr,
	MBTi USEEPS)
	
{
	TIntVec L1 = B1 - A1;
	TIntVec L2 = B2 - A2;

	if (VectorsParallel2d(L1, L2, USEEPS))
		return lcPARALLEL;
	
	int A1C2 = Classify(A1, A2, B2, USEEPS);
	int B1C2 = Classify(B1, A2, B2, USEEPS);

	int A2C1 = Classify(A2, A1, B1, USEEPS);
	int B2C1 = Classify(B2, A1, B1, USEEPS);
		
	if (a1Fix && (A1C2 == etORIGIN || A1C2 == etDESTINATION)){itr = A1;return lcCOMMONPOINT;}
	if (b1Fix && (B1C2 == etORIGIN || B1C2 == etDESTINATION)){itr = B1;return lcCOMMONPOINT;}
	if (a2Fix && (A2C1 == etORIGIN || A2C1 == etDESTINATION)){itr = A2;return lcCOMMONPOINT;}
	if (b2Fix && (B2C1 == etORIGIN || B2C1 == etDESTINATION)){itr = B2;return lcCOMMONPOINT;}

	if (b2Fix && B2C1 == etBETWEEN) { itr = B2;return lcTOUCH;}
	if (a2Fix && A2C1 == etBETWEEN) { itr = A2;return lcTOUCH;}
	if (b1Fix && B1C2 == etBETWEEN) { itr = B1;return lcTOUCH;}
	if (a1Fix && A1C2 == etBETWEEN) { itr = A1;return lcTOUCH;}

	bool canExit = false;
	if (A1C2 == etBEHIND) if (a2Fix) canExit = true; else { itr = A1;return lcTOUCH;}
	if (B1C2 == etBEHIND) if (a2Fix) canExit = true; else { itr = B1;return lcTOUCH;}

	if (A1C2 == etBEYOND) if (b2Fix) canExit = true; else { itr = A1;return lcTOUCH;}
	if (B1C2 == etBEYOND) if (b2Fix) canExit = true; else { itr = B1;return lcTOUCH;}

	if (A2C1 == etBEHIND) if (a1Fix) canExit = true; else { itr = A2;return lcTOUCH;}
	if (B2C1 == etBEHIND) if (a1Fix) canExit = true; else { itr = B2;return lcTOUCH;}

	if (A2C1 == etBEYOND) if (b1Fix) canExit = true; else { itr = A2;return lcTOUCH;}
	if (B2C1 == etBEYOND) if (b1Fix) canExit = true; else { itr = B2;return lcTOUCH;}

	if (canExit)
		return lcNONE;

	TIntVec N1 = VectorP2d(L1).Normalize();
	TIntVec N2 = VectorP2d(L2).Normalize();
	
	MBTi A1dC2 = DistancePointPlane(A1, N2, A2);
	MBTi B1dC2 = DistancePointPlane(B1, N2, A2);

	MBTi A2dC1 = DistancePointPlane(A2, N1, A1);
	MBTi B2dC1 = DistancePointPlane(B2, N1, A1);

	if (a1Fix && ( ( A1dC2 > USEEPS && A1dC2<B1dC2 ) || ( A1dC2 < -USEEPS && A1dC2>B1dC2 )))
		return lcNONE;

	if (b1Fix && ( ( B1dC2 > USEEPS && B1dC2<A1dC2 ) || ( B1dC2 < -USEEPS && B1dC2>A1dC2 )))
		return lcNONE;

	if (a2Fix && ( ( A2dC1 > USEEPS && A2dC1<B2dC1 ) || ( A2dC1 < -USEEPS && A2dC1>B2dC1 )))
		return lcNONE;

	if (b2Fix && ( ( B2dC1 > USEEPS && B2dC1<A2dC1 ) || ( B2dC1 < -USEEPS && B2dC1>A2dC1 )))
		return lcNONE;

	
	PlaneSegmentCross(N1, A1, A2, B2, false, false, itr, USEEPS);
	return lcCROSSING;
}


/*!!!!!!!!!!!!!!!
  !! Проверено !!
  !!!!!!!!!!!!!!!
  !! 28.03.2005!!
  !!!!!!!!!!!!!!!*/
bool CutOXCross2d(const TIntVec &p1, const TIntVec &p2, TIntVec &itr, MBTi EPS)
{
	if (MIN(p1.y, p2.y)>=EPS || MAX(p1.y, p2.y)<=-EPS)
		return false;

	TIntVec d = p2-p1;
	TIntVec o = p1;

	if (fabs(d.x)>EPS && fabs(d.y)/fabs(d.x)<=GET_CEPS(EPS)) 
		return false;

	if (MIN(fabs(p1.y), fabs(p2.y))<EPS)
		if (fabs(p2.y) < fabs(p1.y))
		{
			itr = p2;
			return true;
		} else
		{
			itr = p1;
			return true;
		}

	MBTi t = -o.y/d.y;

	itr.x = t*d.x + o.x;	
	itr.y = 0;
	itr.z = t*d.z + o.z;	

	return true;
}


/**********/
/**********/
/**********/
/**********/
/**********/

bool PlaneCrossPoint(   const TIntVec& A,//точка на плоскости
						const TIntVec& N,//нормаль
						const TIntVec& X,
						const TIntVec& Y,
						TIntVec& O)
{
	int res = PlaneLineCross(N, A, X, Y, O, MBTi_EPS);
	return (res != comNONCROSS);
}

bool PlaneCrossPoint(   const TIntVec& A,
						const TIntVec& B,
						const TIntVec& C,
						const TIntVec& X,
						const TIntVec& Y,
						TIntVec& O)
{
	TIntVec N = VectorP ( B - A, C - A );
	N = N.Normalize();
	return(PlaneCrossPoint(A,N,X,Y,O));
}

/***/
bool Cross_Length(MBTi P0,MBTi P1,MBTi S0,MBTi S1,MBTi& EDGE1,MBTi& EDGE2,MBTi Epsilon,MBTi Uverennost)
{
	MBTi MaxPointX = MAX(P0,P1);
	MBTi MinPointX = MIN(P0,P1);
	MBTi MaxStenaX = MAX(S0,S1);
	MBTi MinStenaX = MIN(S0,S1);
	MBTi ADD = Epsilon - Uverennost;
	if (ADD == 0 )
		ADD = 0.0001;
	if ( (MinStenaX + ADD) > MinPointX  && MaxStenaX < (MaxPointX + ADD))
	{
		EDGE1 = MinStenaX;
		EDGE2 = MaxStenaX;
		return true;
	}
	else if ((MinPointX + ADD) > MinStenaX && MaxPointX < (MaxStenaX + ADD))
	{
		EDGE1 = MinPointX;
		EDGE2 = MaxPointX;
		return true;
	}
	else if ((MaxStenaX + ADD) > MinPointX && MaxStenaX < (MaxPointX + ADD))
	{
		EDGE1 = MinPointX;
		EDGE2 = MaxStenaX;
		return true;
	}
	else if ((MinStenaX + ADD) > MinPointX && MinStenaX < (MaxPointX + ADD))
	{
		EDGE1 = MinStenaX;
		EDGE2 = MaxPointX;
		return true;
	}
	else
	{
		EDGE1 = 0;
		EDGE2 = 0;
		return false;
	}
}
/**/

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//для линий

int IsLinesCrossedExactly(const TIntVec& _P00,const TIntVec& _P01,const TIntVec& _P10,const TIntVec& _P11, TIntVec & CrossPoint)
{
	int result = SegmentSegmentCross2d(_P00, _P01, _P10, _P11, false, false, false, false, CrossPoint, EXACT_EPSILON);
	if (result == lcTOUCH)
		return lcCROSSING;
	return result;	
	
/*	if ( _P00.x == _P10.x &&  _P00.y == _P10.y && _P01.x == _P11.x && _P01.y == _P11.y )
	{
		CrossPoint = (_P00+_P10)/2;
		return(lcEQUAL);
	}
	if ( (_P00.x == _P10.x &&  _P00.y == _P10.y) || ( _P00.x == _P11.x && _P00.y == _P11.y) )
	{
		CrossPoint = _P00;
		return(lcCOMMONPOINT);
	}

	if ( (_P01.x == _P10.x &&  _P01.y == _P10.y) || (_P01.x == _P11.x && _P01.y == _P11.y) )
	{
		CrossPoint = _P01;
		return(lcCOMMONPOINT);
	}

	MBTi dx1 = _P01.x-_P00.x, dy1 = _P01.y-_P00.y; // Длина проекций первой линии на ось x и y
	MBTi dx2 = _P11.x-_P10.x, dy2 = _P11.y-_P10.y; // Длина проекций второй линии на ось x и y
	MBTi dxx = _P00.x-_P10.x, dyy = _P00.y-_P10.y;
	MBTi div, mul;

	if (  fabs(div = (dy2*dx1-dx2*dy1)) < _MBTi_eps_ )
	{
		return (lcPARALLEL); // Линии параллельны...
	}

	mul = dx2*dyy-dy2*dxx;

	MBTi Ua = mul/div;
	CrossPoint.x = _P00.x + Ua*(_P01.x-_P00.x);
	CrossPoint.y = _P00.y + Ua*(_P01.y-_P00.y);
	CrossPoint.z = _P00.z + Ua*(_P01.z-_P00.z);
	return lcCROSSING;*/
}

//для отрезков (точно)
int IsCutsCrossedExactly(const TIntVec& _P00,const TIntVec& _P01,const TIntVec& _P10,const TIntVec& _P11, TIntVec & CrossPoint)
{
	int result = SegmentSegmentCross2d(_P00, _P01, _P10, _P11, true, true, true, true, CrossPoint, EXACT_EPSILON);
	if (result == lcTOUCH)
		return lcCROSSING;
	return result;	
/*
	TIntVec max0;
	TIntVec max1;
	TIntVec min0;
    TIntVec min1;

    TIntVec P00=_P00;
    TIntVec P01=_P01;
	TIntVec P10=_P10;
    TIntVec P11=_P11;

    P00.z=0;
    P01.z=0;
    P10.z=0;
    P11.z=0;

    if ( P00 == P10 && P01== P11 )
    {
        CrossPoint = (P00+P01)/2;
        return(lcEQUAL);
    }

    if ( P00 == P10 || P00 == P11 )
    {
        CrossPoint = P00;
        return(lcCOMMONPOINT);
    }
	if ( P01 == P10 || P01 == P11 )
    {
        CrossPoint = P01;
        return(lcCOMMONPOINT);
    }

    for (int i=0;i<2;i++)
    {
		max0.a[i] = MAX(P00.a[i],P01.a[i]);
        max1.a[i] = MAX(P10.a[i],P11.a[i]);
        min0.a[i] = MIN(P00.a[i],P01.a[i]);
        min1.a[i] = MIN(P10.a[i],P11.a[i]);
    }
    if (min0.x > max1.x || max0.x < min1.x || min0.y > max1.y || max0.y < min1.y)
        return lcNONE;  // Момент, када линии имеют одну общую вершину...

    long double dx1 = P01.x-P00.x, dy1 = P01.y-P00.y; // Длина проекций первой линии на ось x и y
    long double dx2 = P11.x-P10.x, dy2 = P11.y-P10.y; // Длина проекций второй линии на ось x и y
    long double dxx = P00.x-P10.x, dyy = P00.y-P10.y;
    long double div, mul;


	if (  fabsl( div = dy2*dx1-dx2*dy1) <=0.00001 )
        return (lcPARALLEL); // Линии параллельны...

    long double Ub = ((dx1*dyy-dy1*dxx) / div);
    long double Ua = ((dx2*dyy-dy2*dxx) / div);
	if ( -0.00001<=Ua && Ua<=1.00001 && Ub<=1.00001 && Ub>=-0.00001 )
    {
        CrossPoint.x = ( P00.x + Ua*double(P01.x-P00.x) );
        CrossPoint.y = ( P00.y + Ua*double(P01.y-P00.y) );
        CrossPoint.z = _P00.z + Ua*double(_P01.z-_P00.z);
		return lcCROSSING;
	}
	else
		return lcNONE;*/
}

//для отрезка и линии (точно)
int IsCutAndLineCrossedExactly(const TIntVec& _P00,const TIntVec& _P01,const TIntVec& _P10,const TIntVec& _P11, TIntVec & CrossPoint)
{
	int result = SegmentSegmentCross2d(_P00, _P01, _P10, _P11, true, true, false, false, CrossPoint, EXACT_EPSILON);
	if (result == lcTOUCH)
		return lcCROSSING;
	return result;
/*	TIntVec P00=_P00;
	TIntVec P01=_P01;
	TIntVec P10=_P10;
	TIntVec P11=_P11;

	P00.z=0;
	P01.z=0;
	P10.z=0;
	P11.z=0;

	if ( P00 == P10 && P01== P11 )
	{
		CrossPoint = (P00+P01)/2;
		return(lcEQUAL);
    }

    if ( P00 == P10 || P00 == P11 )
	{
        CrossPoint = P00;
        return(lcCOMMONPOINT);
    }
    if ( P01 == P10 || P01 == P11 )
    {
        CrossPoint = P01;
        return(lcCOMMONPOINT);
    }

	long double dx1 = P01.x-P00.x, dy1 = P01.y-P00.y; // Длина проекций первой линии на ось x и y
    long double dx2 = P11.x-P10.x, dy2 = P11.y-P10.y; // Длина проекций второй линии на ось x и y
	long double dxx = P00.x-P10.x, dyy = P00.y-P10.y;
    long double div, mul;

    if (  fabsl( div = dy2*dx1-dx2*dy1) <=0.00001 )
        return (lcPARALLEL); // Линии параллельны...

    long double Ua = ((dx2*dyy-dy2*dxx) / div);
    if ( -0.00001<=Ua && Ua<=1.00001)
    {
        CrossPoint.x = ( P00.x + Ua*double(P01.x-P00.x) );
        CrossPoint.y = ( P00.y + Ua*double(P01.y-P00.y) );
		CrossPoint.z = _P00.z + Ua*double(_P01.z-_P00.z);
        return lcCROSSING;
    }
    else
		return lcNONE;*/
}

int IsLinesCrossedFull( const TIntVec& _P00,
						const TIntVec& _P01,
						const TIntVec& _P10,
						const TIntVec& _P11,
						bool p00Fixed,
						bool p01Fixed,
						bool p10Fixed,
						bool p11Fixed,
						TIntVec & CrossPoint,
						MBTi USEEPS)
{
	int result = SegmentSegmentCross2d(_P00, _P01, _P10, _P11, p00Fixed, p01Fixed, p10Fixed, p11Fixed, CrossPoint, USEEPS);
	if (result == lcTOUCH)
		return lcCROSSING;
	return result;	
/*	TIntVec P00=_P00;
	TIntVec P01=_P01;
    TIntVec P10=_P10;
    TIntVec P11=_P11;

	P00.z=0;
    P01.z=0;
    P10.z=0;
    P11.z=0;

    if ( P00.Equal2D(P10,USEEPS) && P01.Equal2D(P11,USEEPS) ||
         P01.Equal2D(P10,USEEPS) && P00.Equal2D(P11,USEEPS) )
    {
        CrossPoint = (P00+P01)/2;
        return(lcEQUAL);
    }

    if ( P00.Equal2D(P10,USEEPS) || P00.Equal2D(P11,USEEPS) )
    {
		CrossPoint = P00;
        return(lcCOMMONPOINT);
    }
    if ( P01.Equal2D(P10,USEEPS) || P01.Equal2D(P11,USEEPS) )
    {
        CrossPoint = P01;
        return(lcCOMMONPOINT);
    }

    long double dx1 = P01.x-P00.x, dy1 = P01.y-P00.y; // Длина проекций первой линии на ось x и y
    long double dx2 = P11.x-P10.x, dy2 = P11.y-P10.y; // Длина проекций второй линии на ось x и y
    long double dxx = P00.x-P10.x, dyy = P00.y-P10.y;
    long double div, mul;


    if (  fabsl( div = dy2*dx1-dx2*dy1) <= USEEPS )
    {
        // Линии параллельны...
        return (IsLinesCollinear(P00,P01,P10,P11,USEEPS)) ? lcCOLLINEAR : lcPARALLEL;
    }

    long double Ub = ((dx1*dyy-dy1*dxx) / div);
    long double Ua = ((dx2*dyy-dy2*dxx) / div);

    if ( ( p00Fixed && !( -USEEPS <= Ua ) ) ||
         ( p01Fixed && !( Ua <= USEEPS + 1 )  ) ||
         ( p10Fixed && !( -USEEPS <= Ub ) ) ||
		 ( p11Fixed && !( Ub <= USEEPS + 1 )  )    )
	{
		return lcNONE;
	}

	CrossPoint.x = ( P00.x + Ua*double(P01.x-P00.x) );
	CrossPoint.y = ( P00.y + Ua*double(P01.y-P00.y) );
	CrossPoint.z = _P00.z + Ua*double(_P01.z-_P00.z);
	return lcCROSSING;*/
}

int IsLineAndCutCrossed(const TIntVec& _P00,const TIntVec& _P01,const TIntVec& _P10,const TIntVec& _P11, TIntVec & CrossPoint, MBTi USEEPS)
{
	int result = SegmentSegmentCross2d(_P00, _P01, _P10, _P11, false, false, true, true, CrossPoint, USEEPS);
	if (result == lcTOUCH)
		return lcCROSSING;
	return result;	
/*	CrossPoint = TIntVec(0,0,0);

    switch (Classify(_P10,_P00,_P01,USEEPS))
    {
        case etLEFT:
            switch (Classify(_P11,_P00,_P01,USEEPS))
            {
                case etLEFT:
                    return lcNONE;
                case etRIGHT:
                    break;
                default:
                {
                    CrossPoint = _P11;
                    return lcCOMMONPOINT;
                }
            }break;
        case etRIGHT:
            switch (Classify(_P11,_P00,_P01,USEEPS))
            {
				case etLEFT:
                    break;
                case etRIGHT:
                    return lcNONE;
				default:
                {
                    CrossPoint = _P11;
					return lcCOMMONPOINT;
                }
            }break;
        default:
		{
            CrossPoint = _P10;
            return lcCOMMONPOINT;
        }
    }
    MBTi dx1 = _P01.x-_P00.x, dy1 = _P01.y-_P00.y; // Длина проекций первой линии на ось x и y
    MBTi dx2 = _P11.x-_P10.x, dy2 = _P11.y-_P10.y; // Длина проекций второй линии на ось x и y
    MBTi dxx = _P00.x-_P10.x, dyy = _P00.y-_P10.y;
    MBTi div = (dy2*dx1)-(dx2*dy1);
    MBTi mul =  dx1*dyy-dy1*dxx;
    if (fabs(div)<=USEEPS)
        return lcPARALLEL;
    MBTi Ub = mul/div;
    CrossPoint.x = _P10.x + Ub*(_P11.x-_P10.x);
    CrossPoint.y = _P10.y + Ub*(_P11.y-_P10.y);
    CrossPoint.z = _P10.z + Ub*(_P11.z-_P10.z);
	return lcCROSSING;*/
}

int IsLineAndCutCrossedExactly(const TIntVec& _P00,const TIntVec& _P01,const TIntVec& _P10,const TIntVec& _P11, TIntVec & CrossPoint)
{
	return IsLineAndCutCrossed(_P00,_P01,_P10,_P11,CrossPoint,_MBTi_eps_);
}

int IsCutsCrossed(const TIntVec& _P00,const TIntVec& _P01,const TIntVec& _P10,const TIntVec& _P11, TIntVec & CrossPoint,MBTi USEEPS)
{
	int result = SegmentSegmentCross2d(_P00, _P01, _P10, _P11, true, true, true, true, CrossPoint, USEEPS);
	if (result == lcTOUCH)
		return lcCROSSING;
	return result;	
/*    if ( fabs(_P00.x-_P10.x)<=USEEPS &&  fabs(_P00.y-_P10.y)<=USEEPS && fabs(_P01.x-_P11.x)<=USEEPS && fabs(_P01.y-_P11.y)<=USEEPS )
	{
		CrossPoint = (_P00+_P10)/2;
		return(lcEQUAL);
	}
	if ( (fabs(_P00.x-_P10.x)<=USEEPS &&  fabs(_P00.y-_P10.y)<=USEEPS) || (fabs(_P00.x-_P11.x)<=USEEPS && fabs(_P00.y-_P11.y)<=USEEPS) )
	{
		CrossPoint = _P00;
		return(lcCOMMONPOINT);
	}

	if ( (fabs(_P01.x-_P10.x)<=USEEPS &&  fabs(_P01.y-_P10.y)<=USEEPS) || (fabs(_P01.x-_P11.x)<=USEEPS && fabs(_P01.y-_P11.y)<=USEEPS) )
	{
		CrossPoint = _P01;
		return(lcCOMMONPOINT);
	}

	MBTi dx1 = _P01.x-_P00.x, dy1 = _P01.y-_P00.y; // Длина проекций первой линии на ось x и y
	MBTi dx2 = _P11.x-_P10.x, dy2 = _P11.y-_P10.y; // Длина проекций второй линии на ось x и y
	MBTi dxx = _P00.x-_P10.x, dyy = _P00.y-_P10.y;
	MBTi div, mul;

	if (  fabs( div = (dy2*dx1-dx2*dy1)) <= USEEPS )
		return (lcPARALLEL); // Линии параллельны...


	if (div > USEEPS)
	{
		mul = dx1*dyy-dy1*dxx;
		if ( mul  < -USEEPS || mul > div+USEEPS )
			return lcNONE; // Первый отрезок пересекается за своими границами...
		mul = dx2*dyy-dy2*dxx;
		if ( mul  < -USEEPS || mul > div+USEEPS )
			return lcNONE; // Второй отрезок пересекается за своими границами...
	}
	else
	{
		mul = -(dx1*dyy-dy1*dxx);
		if ( mul  < -USEEPS || mul > (-div)+USEEPS )
			return lcNONE; // Первый отрезок пересекается за своими границами...
		mul = -(dx2*dyy-dy2*dxx);
		if ( mul  < -USEEPS || mul > (-div)+USEEPS )
			return lcNONE; // Второй отрезок пересекается за своими границами...
	}

	MBTi Ua = fabs(mul/div);
	CrossPoint.x = _P00.x + Ua*(_P01.x-_P00.x);
	CrossPoint.y = _P00.y + Ua*(_P01.y-_P00.y);
	CrossPoint.z = _P00.z + Ua*(_P01.z-_P00.z);
	return lcCROSSING;*/
}

bool IsLinesParallel(   const TIntVec& _P00,
						const TIntVec& _P01,
						const TIntVec& _P10,
						const TIntVec& _P11,
						MBTi USEEPS)
{
/*	MBTi Angle1 = (AngleRadOX(_P00,_P01)*180)/M_PI;
	MBTi Angle2 = (AngleRadOX(_P10,_P11)*180)/M_PI;
	return (fabs(Angle2-Angle1)<=USEEPS) || (fabs(fabs(Angle2-Angle1)-180)<=USEEPS);
*/
	return VectorsParallel(_P00 - _P01, _P10 - _P11, USEEPS);	
}

/*TODO : */
bool IsLinesCollinear(  const TIntVec& _P00,
						const TIntVec& _P01,
						const TIntVec& _P10,
						const TIntVec& _P11,
						MBTi USEEPS)
{
	if (!IsLinesParallel(_P00, _P01, _P10, _P11, USEEPS))
		return false;
		
	return	LineConsistsPoint(_P10, _P00, _P01, USEEPS)
		&&	LineConsistsPoint(_P11, _P00, _P01, USEEPS)
		&&	LineConsistsPoint(_P00, _P10, _P11, USEEPS)
		&&	LineConsistsPoint(_P01, _P10, _P11, USEEPS);

/*	MBTi Angle1 = (AngleRadOX(_P00,_P01, MBTi_EPS)*180)/M_PI;
	MBTi Angle2 = (AngleRadOX(_P10,_P11, MBTi_EPS)*180)/M_PI;
	if (fabs(Angle2-Angle1)>(USEEPS*180/M_PI) && fabs(fabs(Angle2-Angle1)-180)>(USEEPS*180/M_PI))
		return false;
	TIntVec Angle3D;
	Angle3D.z = - Angle1;
	TIntVec P10 = RotateAround(_P10,Angle3D,_P00);
	return fabs(P10.y-_P00.y)<=USEEPS;*/
}

/*TODO : */
bool IsCutsCollinearAndCrossing(   const TIntVec& _P00,
								   const TIntVec& _P01,
								   const TIntVec& _P10,
								   const TIntVec& _P11,
								   MBTi USEEPS)
{
	if (!IsLinesCollinear(_P00, _P01, _P10, _P11, USEEPS))
		return false;

	int a = Classify(_P00, _P10, _P11, USEEPS);
	int b = Classify(_P01, _P10, _P11, USEEPS);

	return 
		!(  (a == etBEHIND && b == etBEHIND) ||
			(a == etBEYOND && b == etBEYOND)/* ||
			(a == etBEHIND && b == etORIGIN) ||
			(a == etBEYOND && b == etDESTINATION)*/);
}

