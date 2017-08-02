//---------------------------------------------------------------------------

#ifndef MathVH
#define MathVH
#include "VectorV.h"


//---------------------------------------------------------------------------


const int mtInt				= 0;
const int mtDouble			= 1;
const int mtString			= 2;
const int mtIntVec			= 3;
const int mtCharString		= 4;
const int mtBool			= 5;
const int mtBoolVec			= 6;
const int mtFloat			= 7;
const int mtSignVec			= 8;
const int mtRect			= 9;
const int mtMBTi			= mtFloat;
const int mtMBTf			= mtFloat;
//--------------------------
const int mtVCLObject		= 50;
const int mtAnyThing		= 60;
//--------------------------
const int mtMyObject		= 100;
const int mtMyRegObject		= 110;
const int mtMTList			= 201;
const int mtMDelTList		= 202;
const int mtNone			= -1;
const int mtNotDefined		= -2;
//--------------------------

class TBoolVec;
class TMyObject;

//  онстанты

const TIntVec ZEROINTVEC		= TIntVec(0,0,0);
const TIntVec MAXINTVEC			= TIntVec(1<<28,1<<28,1<<28);
const TIntVec MINUSINTVEC		= TIntVec(-1,-1,-1);
const TIntVec VEC222			= TIntVec(2,2,2);
const TPoint ZEROPOINT			= TPoint(0,0);

const int etLEFT			= 0;
const int etRIGHT			= 1;
const int etBETWEEN			= 2;
const int etBEHIND			= 3;
const int etBEYOND			= 4;
const int etORIGIN			= 5;
const int etDESTINATION		= 6;

const int pcvNONE			= 0;
const int pcvCROSSED		= 1;

const MBTi A360				= 360;

const int PL_CROSS_PARALLEL     = 0; // пр€ма€ и плоскость параллельны
const int PL_CROSS_ONEPOINT     = 1; // одна точка
const int PL_CROSS_CONSISTS     = 2; // пр€ма€ принадлежит плоскости
const int PL_CROSS_OUTOFBORDER  = 3; // точка пресечени€ не лежит на луче

//вспомогательные

//шаг системы во флоате
const TIntVec UNISTEP = TIntVec(0.075,0.075,0.05);

//max step epsilon
const TIntVec MAXCATCHEPS = TIntVec(3000,3000,3000);
const TIntVec MAXSIZEEPS = TIntVec(3000,3000,3000);
const TIntVec MAXANGLEEPS = TIntVec(3000,3000,3000);

//точность св€зок
const MBTi LinkEpsInt		= 0.000005;
const TIntVec LINKINGEPS	= TIntVec(LinkEpsInt,LinkEpsInt,LinkEpsInt);

//точность в графе
const MBTi GraphEps			= 0.005;
const TIntVec GRAPHEPS		= TIntVec(GraphEps,GraphEps,GraphEps);

//точность в полигоне
const MBTi INTEPS			=0.005;
const TIntVec POLEPS 		= TIntVec(INTEPS,INTEPS,INTEPS);

//шаг карты
const TIntVec MAP 			= UNISTEP*4;

const int UserRound			= -10;

const int ettCROSSING		= 1;
const int ettINESSENTIAL	= 0;
const int ettTOUCHING		= 2;

//line crossing
const int lcNONE			= 0;
const int lcCROSSING		= 1;
const int lcPARALLEL		= 2;
const int lcEQUAL			= 3;
const int lcCOMMONPOINT		= 4;
const int lcCOLLINEAR		= 5;
const int lcTOUCH			= 6;

//crossing
const int comNONCROSS		= lcNONE;
const int comCROSS			= lcCROSSING;
const int comPARALLEL		= lcPARALLEL;
const int comTOUCH			= lcTOUCH;

const int comPOSITIVE		= 10;
const int comNEGATIVE		= 11;


//--------------------------
const int lcexFirst_0_InSecond	= 5;
const int lcexFirst_1_InSecond	= 6;
const int lcexSecond_0_InFirst	= 7;
const int lcexSecond_1_InFirst	= 8;

/*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*/*/

const MBTi _MBTi_eps_		= 0.0005;
const MBTi MBTi_EPS			= _MBTi_eps_;

const MBTi VALID_RADIUS		= 5.0f;
const MBTi EXACT_EPSILON	= 0.00001;

#define GET_CEPS(EPS)		EPS/(2*VALID_RADIUS)



/*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*/*/


/////////////
// ¬екторы //
/////////////

COMMONAL_API void AssignVec(TVisMathVector& Dest,const TIntVec& Src );
COMMONAL_API void AssignVisVec(TVisVector& Dest,const TIntVec& Src );
COMMONAL_API TVisMathVector VisMathVec(const TIntVec& Src);


COMMONAL_API TIntVec SIGNVEC(const TIntVec &Vec);

COMMONAL_API bool VectorsParallel(const TIntVec &N1, const TIntVec &N2, MBTi EPS);
COMMONAL_API bool VectorsParallel2d(TIntVec N1, TIntVec N2, MBTi EPS);
COMMONAL_API bool VectorsPerpendicular(const TIntVec &N1, const TIntVec &N2, MBTi EPS);
COMMONAL_API bool VectorsPerpendicular2d(TIntVec N1, TIntVec N2, MBTi EPS);
COMMONAL_API TIntVec PointOfLineOnCut(const TIntVec &src, const TIntVec &dst, MBTi t);
COMMONAL_API TIntVec PointOnCut(const TIntVec &src, const TIntVec &dst, MBTi t);
COMMONAL_API double ASinACosDomainCheck(double num, MBTi EPS = EXACT_EPSILON);
COMMONAL_API double SqrtDomainCheck(double num, MBTi EPS = EXACT_EPSILON);
#define	acosDC(num)	acos(ASinACosDomainCheck(num))
#define	asinDC(num)	asin(ASinACosDomainCheck(num))
#define	sqrtDC(num)	sqrt(SqrtDomainCheck(num))

/////////////////////
// ќбщие алгоритмы //
/////////////////////

template <class T>
void XChg(T &t1, T &t2)
{
	T temp;
	temp = t1,
	t1 = t2,
	t2 = temp;
}

template <class T>
int SIGN(T V)
{
	return (V>0) ? 1 : (V<0) ? -1 : 0;
}

COMMONAL_API TIntVec ABS(const TIntVec &);

template <class T>
const T& MAX(const T & x,const T & y)
{
	return x > y ? x : y;
}

template <class T>
const T& MIN(const T & x,const T & y)
{
	return x < y ? x : y;
}
///////////////
// √еометри€ //
///////////////

//////////////
// Classify //
//////////////

// ClassifyPointByCut();
// ClassifyPointByLine();
// ClassifyPointByPlane();

// —тарые
COMMONAL_API int Classify(const TIntVec& P2, const TIntVec& P0, const TIntVec& Pl,MBTi EPS);
COMMONAL_API int EdgeType (const TIntVec& A, const TIntVec& V0,const TIntVec& V1,MBTi USEEPS);


///////////////////////////
// –ассто€ни€ (Distance) //
///////////////////////////

/*

*/
COMMONAL_API MBTi DistancePointPlane(const TIntVec &P, const TIntVec &N, const TIntVec &O);


COMMONAL_API MBTi DistancePointLine(const TIntVec &P, const TIntVec &A, const TIntVec &B);
COMMONAL_API MBTi DistancePointLine2d(const TIntVec &P, const TIntVec &A, const TIntVec &B);
COMMONAL_API MBTi DistancePointCut(const TIntVec &P, const TIntVec &A, const TIntVec &B);
/*!!!*/
COMMONAL_API bool DistanceLineLine(const TIntVec &A1, const TIntVec &B1, const TIntVec &A2, const TIntVec &B2, MBTi &Dist, MBTi USEEPS);
/*!!!*/


// —тарые

///////////////////
// ”глы (Angle)	 //
///////////////////

// —тарые
//            .X1
//           /
//         /
//       / Angle
//  X2./----------.X3
//против часовой стрелки

COMMONAL_API TIntVec GetToPlaneTransformation(const TIntVec &n);
COMMONAL_API TIntVec TransformTo(const TIntVec &v, const TIntVec &ang);
COMMONAL_API TIntVec TransformFrom(const TIntVec &v, const TIntVec &ang);

COMMONAL_API MBTi AngleRad(const TIntVec& X1, const TIntVec& X2, const TIntVec& X3, MBTi USEEPS = EXACT_EPSILON);

//       Dst0 /
//          /
//        /
// Src0 /  Angle
//    . --------------
//      Src1        Dst1

COMMONAL_API MBTi AngleRad(	const TIntVec& Src0,
							const TIntVec& Dst0,
							const TIntVec& Src1,
							const TIntVec& Dst1, MBTi USEEEPS = EXACT_EPSILON);

COMMONAL_API MBTi AngleRadOX(const TIntVec& X1, const TIntVec& X2, MBTi USEEEPS = EXACT_EPSILON);

COMMONAL_API TIntVec RotateAround(const TIntVec& Point,const TIntVec& Angle,const TIntVec& Center);


///////////////////////////////
// ѕринадлежность (Consists) //
///////////////////////////////

COMMONAL_API bool LineConsistsPoint(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS);
COMMONAL_API bool LineConsistsPoint2d(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS);

COMMONAL_API bool CutConsistsPoint(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS);
COMMONAL_API bool CutConsistsPoint2d(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS);


// —тарые



///////////////////////////////
// ѕересечение (Cross)
///////////////////////////////

COMMONAL_API bool PlanePlaneCross(	const TIntVec &N1, const TIntVec &O1,
									const TIntVec &N2, const TIntVec &O2,
									TIntVec &NL, TIntVec &OL, MBTi USEEPS);

/******************************************************************************************/
COMMONAL_API int PlaneLineCross(	const TIntVec& N,	//нормаль
									const TIntVec& A,	//точка на плоскости
									const TIntVec& X,	//пр€ма€ точка 1
									const TIntVec& Y,	//пр€ма€ точка 2
									TIntVec& O, 		//точка пересечени€
									MBTi USEEPS);

COMMONAL_API int PlaneCutCross(	const TIntVec& N,	//нормаль
									const TIntVec& A,	//точка на плоскости
									const TIntVec& X,	//пр€ма€ точка 1
									const TIntVec& Y,	//пр€ма€ точка 2
									TIntVec& O, 		//точка пересечени€
									MBTi USEEPS);

									
COMMONAL_API int PlaneSegmentCross(	const	TIntVec& N,	//нормаль
									const	TIntVec& A,	//точка на плоскости

									const	TIntVec& X,	//пр€ма€: точка 1
									const	TIntVec& Y,	//пр€ма€: точка 2

									bool	xFix,		//попадание начала
									bool	yFix,		//попадание конца
			
									TIntVec& O, 		//точка пересечени€
						
									MBTi USEEPS);    	// Epsilon

COMMONAL_API int  PlaneCutCrossClass(	const TIntVec& N,//точка на плоскости
										const TIntVec& A,//нормаль
										const TIntVec& X,//пр€ма€ точка 1
										const TIntVec& Y,//пр€ма€ точка 2
										TIntVec& O, //точка пересечени€
										MBTi USE_PEPS);    //мера параллельности
/**********************************************************************************************/
COMMONAL_API int CutCutCross2d(
	const TIntVec &A1,
	const TIntVec &B1,
	const TIntVec &A2,
	const TIntVec &B2,
	TIntVec &itr,
	MBTi USEEPS);

COMMONAL_API bool CutOXCross2d(const TIntVec &p1, const TIntVec &p2, TIntVec &itr, MBTi EPS);

	
COMMONAL_API int SegmentSegmentCross2d(
	const TIntVec &A1,
	const TIntVec &B1,
	const TIntVec &A2,
	const TIntVec &B2,
	bool a1Fix,
	bool b1Fix,
	bool a2Fix,
	bool b2Fix ,
	TIntVec &itr,
	MBTi USEEPS);
									
// —тарые

// SegmentSegmentCross
// CutCutCross
// PlaneSegmentCross

// SegmentSegmentCross2d
// CutCutCross2d
// LineLineCross2d

// PlaneSegmentCross
// PlaneLineCross
// PlaneCutCross


COMMONAL_API int PlaneAndLineCrossed(
						const TIntVec& A,//точка на плоскости
						const TIntVec& N,//нормаль
						const TIntVec& X,//пр€ма€ точка 1
						const TIntVec& Y,//пр€ма€ точка 2
						bool xFixed,
						bool yFixed,
						TIntVec& O, //точка пересечени€
						MBTi USEEPS);    //мера параллельности


COMMONAL_API int IsLinesCrossedExactly(	const TIntVec& _P00,
										const TIntVec& _P01,
										const TIntVec& _P10,
										const TIntVec& _P11,
										TIntVec & CrossPoint);

COMMONAL_API int IsCutsCrossedExactly(  const TIntVec& _P00,
										const TIntVec& _P01,
										const TIntVec& _P10,
										const TIntVec& _P11,
										TIntVec & CrossPoint);

COMMONAL_API int IsLineAndCutCrossedExactly(const TIntVec& LINE0,const TIntVec& LINE1,const TIntVec& CUT0,const TIntVec& CUT1, TIntVec & CrossPoint);
COMMONAL_API int IsLineAndCutCrossed(const TIntVec& _P00,const TIntVec& _P01,const TIntVec& _P10,const TIntVec& _P11, TIntVec & CrossPoint,MBTi USEEPS);

COMMONAL_API int IsCutAndLineCrossedExactly(const TIntVec& _P00,const TIntVec& _P01,const TIntVec& _P10,const TIntVec& _P11, TIntVec & CrossPoint);


COMMONAL_API bool IsLinesParallel(   const TIntVec& _P00,
						const TIntVec& _P01,
						const TIntVec& _P10,
						const TIntVec& _P11,
						MBTi USEEPS);
						
COMMONAL_API bool IsLinesCollinear(   const TIntVec& _P00,
						const TIntVec& _P01,
						const TIntVec& _P10,
						const TIntVec& _P11,
						MBTi USEEPS);

COMMONAL_API bool IsCutsCollinearAndCrossing(   const TIntVec& _P00,
									const TIntVec& _P01,
									const TIntVec& _P10,
									const TIntVec& _P11,
									MBTi USEEPS);

COMMONAL_API bool Cross_Length(MBTi P0,MBTi P1,MBTi S0,MBTi S1,MBTi& EDGE1,MBTi& EDGE2,MBTi Epsilon,MBTi Uverennost);


COMMONAL_API bool PlaneCrossPoint(   const TIntVec& P1,
						const TIntVec& P2,
						const TIntVec& P3,
						const TIntVec& V1,
						const TIntVec& V2,
						TIntVec & CP);


COMMONAL_API bool PlaneCrossPoint(   const TIntVec& A,//точка на плоскости
						const TIntVec& PlaneN,//нормаль
						const TIntVec& X,
						const TIntVec& Y,
						TIntVec& O);


COMMONAL_API
int IsCutsCrossed( const TIntVec& _P00,
					const TIntVec& _P01,
					const TIntVec& _P10,
					const TIntVec& _P11,
					TIntVec & CrossPoint,
					MBTi USEEPS);

COMMONAL_API
int IsLinesCrossedFull( const TIntVec& _P00,
					const TIntVec& _P01,
					const TIntVec& _P10,
					const TIntVec& _P11,
					bool p00Fixed,
					bool p01Fixed,
					bool p10Fixed,
					bool p11Fixed,
					TIntVec & CrossPoint,
					MBTi USEEPS);
							
					

#endif
