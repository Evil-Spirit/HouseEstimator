#include <vcl.h>                           
#include "Usefuls.h"  
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"                                    
#pragma hdrstop

#include "GeomObjV.h"

#include "Poligon.h"
#include "MyGL.h"
#include "Triangulation.h"
#pragma package(smart_init)

void GPolygonToPolygon(TGPolygon& GHP,TPolygon& HP)
{
	for (int i=0;i<GHP.Count;i++)			
		HP.Vertex->Add(new TIntVec(GHP.GetPoint(i).Point));
}

void GPolygonToHPolygon(TGPolygon& GHP,THoledPolygon& HP)
{
	HP.Clear();
	GPolygonToPolygon(GHP,HP);
	for (int i=0;i<GHP.FHoles.Count;i++)			
	{
		HP.Holes->Add( new TPolygon() );
		GPolygonToPolygon(GHP.FHoles[i],*HP.Holes->Last());
	}
}


//#define MATRIX_TRANSFORM

void Triangulate_(TGPolygon* GHP, TMDelTList <TIntVec> &tris)
{
	if (!GHP->Count)
		return;
	THoledPolygon HP;
	GPolygonToHPolygon(*GHP,HP);
	TIntVec ang;
	ang = GetToPlaneTransformation(GHP->Normal);
	for (int i=0;i<HP.Vertex->Count;i++)
		*HP.Vertex->Items[i] = TransformTo(*HP.Vertex->Items[i], ang);

	for (int i=0;i<HP.Holes->Count;i++)
		for (int j=0;j<HP.Holes->Items[i]->Vertex->Count;j++)
			*HP.Holes->Items[i]->Vertex->Items[j] = TransformTo(*HP.Holes->Items[i]->Vertex->Items[j], ang);

	HP.KillCollinear_1(0.0005);
	for (int i=0;i<HP.Holes->Count;i++)
		HP.Holes->Items[i]->KillCollinear_1(0.0005);
	Deloune->EPS = 0.0001;
	TMTList<TIntVec>* tri = Deloune->Triangulate(&HP);

	tris.Clear();
	for (int i=0;i<tri->Count;i++)
		tris.Add(new TIntVec(TransformFrom(*tri->Items[i], ang)));
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/*

enum TCrossResult
{
	crNONE		= 0,
	crCROSS		= 1,
	crTOUCH		= 2,
	
};
enum TGeoClassify
{
	clPOSITIVE		= 1,
	clRIGHT			= 1,

	clNEGATIVE		= -1,
	clLEFT			= -1,

	clTOUCH			= 2,
	clCROSS			= 3,
	clNONE			= 0,

};


//OK
bool VectorsParallel(const TIntVec &N1, const TIntVec &N2, MBTi EPS)
{	
	
	TIntVec A1 = N1.Normalize();
	TIntVec A2 = N2.Normalize();
//	return 1-fabs(ScalarP(A1, A2))<EPS;

	return ((A1-A2).Length()<GET_CEPS(EPS) || (A1+A2).Length()<GET_CEPS(EPS));
}

//OK
bool VectorsPerpendicular(const TIntVec &N1, const TIntVec &N2, MBTi EPS)
{	
	TIntVec A1 = N1.Normalize();
	TIntVec A2 = (N1*N2*N2).Normalize();
//	return fabs(ScalarP(A1, A2))<EPS;
	return ((A1-A2).Length()<GET_CEPS(EPS) || (A1+A2).Length()<GET_CEPS(EPS));
}

bool VectorsParallel2d(const TIntVec &N1, const TIntVec &N2, MBTi EPS)
{	
	
	TIntVec A1 = N1.Normalize();
	TIntVec A2 = N2.Normalize();
//	return 1-fabs(ScalarP(A1, A2))<EPS;

	return ((A1-A2).Length2D()<GET_CEPS(EPS) || (A1+A2).Length2D()<GET_CEPS(EPS));
}

//OK
bool VectorsPerpendicular2d(const TIntVec &N1, const TIntVec &N2, MBTi EPS)
{	
	TIntVec A1 = N1.Normalize();
	TIntVec A2 = (N1*N2*N2).Normalize();
//	return fabs(ScalarP(A1, A2))<EPS;
	return ((A1-A2).Length2D()<GET_CEPS(EPS) || (A1+A2).Length2D()<GET_CEPS(EPS));
}



//OK
MBTi DistancePointPlane(const TIntVec &P, const TIntVec &N, const TIntVec &O)
{
	return ScalarP(P, N) - ScalarP(O, N);
}

//OK
MBTi DistancePointLine(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS)
{
	TIntVec I;
	PlaneSegmentCross((A-B).Normalize(), P, A, B, false, false, I, USEEPS);
	return (P-I).Length();
}

//OK
MBTi DistancePointLine2d(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS)
{
	TIntVec I;
	PlaneSegmentCross((A-B).Normalize(), P, A, B, false, false, I, USEEPS);
	return (P-I).Length2D();
}

//OK
MBTi DistancePointCut(const TIntVec &P, const TIntVec &A, const TIntVec &B)
{
	TIntVec I;
	int res = PlaneSegmentCross(P, (B-A).Normalize(), A, B, true, true,  I, 0);

	if ( res == clCROSS)
		return (P-I).Length();

	if ( res == clPOSITIVE)
		return (P-A).Length();

	if ( res == clNEGATIVE)
		return (P-B).Length();
		
	throw EMyException("DistancePointCut - критическая ошибка!");
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

TCrossResult PlaneSegmentCross(	const	TIntVec& N,	//нормаль
						const	TIntVec& A,	//точка на плоскости

						const	TIntVec& X,	//прямая точка 1
						const	TIntVec& Y,	//прямая точка 2

						bool	xFix,		//попадание начала
						bool	yFix,		//попаданеие конца

						TIntVec& O, 		//точка пересечения
						
						MBTi USEEPS)    	//мера параллельности
{
	if (VectorsPerpendicular(N, Y-X, USEEPS))
		return crNONE;

	MBTi dX = DistancePointPlane(X, N, A);
	MBTi dY = DistancePointPlane(Y, N, A);

	if (xFix && ((MIN(dX, dY)>USEEPS && dX<dY) || (MAX(dX, dY)<USEEPS) && dX>dY))
		return crNONE;

	if (yFix && ((MIN(dX, dY)>USEEPS && dY<dX) || (MAX(dX, dY)<USEEPS) && dY>dX))
		return crNONE;
	
	if ((xFix || yFix) && MIN(fabs(dX), fabs(dY))<USEEPS)
		if (fabs(dY) < fabs(dX))
		{
			if (yFix)
			{
				O = Y;
				return crTOUCH;
			}
		} else
		{
			if (xFix)
			{
				O = X;
				return crTOUCH;
			}	
		}

	TIntVec V = A - X ;
	// расстояние до плоскости по нормали
	MBTi d = ScalarP ( N, V );
	
	TIntVec W = Y - X;
	
	// приближение к плоскости по нормали при прохождении отрезка
	MBTi e = ScalarP ( N, W );
	
	O = X + W * (d/e);
	
	return crCROSS;
}
TCrossResult PlaneLineCross(	const TIntVec& N,	//нормаль
								const TIntVec& A,	//точка на плоскости
								const TIntVec& X,	//прямая точка 1
								const TIntVec& Y,	//прямая точка 2
								TIntVec& O, 		//точка пересечения
								MBTi USEEPS)    	
{              		
	return crNONE;
}


// отлажено
TGeoClassify PlaneCutCrossClass(	const TIntVec& A,//точка на плоскости
						const TIntVec& N,//нормаль
						const TIntVec& X,//прямая точка 1
						const TIntVec& Y,//прямая точка 2
						TIntVec& O, //точка пересечения
						MBTi USE_PEPS)    //мера параллельности
{
	// определить факт пересечения отрезка и плоскости.

	MBTi d1 = DistancePointPlane(X, N ,A);
	MBTi d2 = DistancePointPlane(Y, N ,A);

	if (MIN(d1, d2)>=USE_PEPS)
		return clPOSITIVE;
		
	if (MAX(d1, d2)<=-USE_PEPS)
		return clNEGATIVE;

	if (MIN(fabs(d1), fabs(d2))<USE_PEPS)
		if (fabs(d2) < fabs(d1))
		{
			O = Y;
			return clTOUCH;
		} else
		{
			O = X;
			return clTOUCH;
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
		return clCROSS;
	}	
	else
		return clNONE;
}



//отлажено
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

 
bool LineLineCross(const TIntVec &A1, const TIntVec &B1, const TIntVec &A2, const TIntVec &B2, TIntVec &itr, MBTi USEEPS)
{
	return false;
}

bool CutCutCross(const TIntVec &A1, const TIntVec &B1, const TIntVec &A2, const TIntVec &B2, TIntVec &itr, MBTi USEEPS)
{
	return false;
}

TIntVec VectorP2d(const TIntVec &src);

int Classify_(const TIntVec& P, const TIntVec& A, const TIntVec& B, MBTi EPS);


// ОК
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
		return crNONE;
	
	TIntVec N1 = VectorP2d(L1).Normalize();
	TIntVec N2 = VectorP2d(L2).Normalize();
	
	MBTi A1dC2 = DistancePointPlane(A1, N2, A2);
	MBTi B1dC2 = DistancePointPlane(B1, N2, A2);

	MBTi A2dC1 = DistancePointPlane(A2, N1, A1);
	MBTi B2dC1 = DistancePointPlane(B2, N1, A1);

	if (a1Fix && ( ( A1dC2 > USEEPS && A1dC2<B1dC2 ) || ( A1dC2 < -USEEPS && A1dC2>B1dC2 )))
		return crNONE;

	if (b1Fix && ( ( B1dC2 > USEEPS && B1dC2<A1dC2 ) || ( B1dC2 < -USEEPS && B1dC2>A1dC2 )))
		return crNONE;

	if (a2Fix && ( ( A2dC1 > USEEPS && A2dC1<B2dC1 ) || ( A2dC1 < -USEEPS && A2dC1>B2dC1 )))
		return crNONE;

	if (b2Fix && ( ( B2dC1 > USEEPS && B2dC1<A2dC1 ) || ( B2dC1 < -USEEPS && B2dC1>A2dC1 )))
		return crNONE;

	int A1C2 = Classify_(A1, A2, B2, USEEPS);
	int B1C2 = Classify_(B1, A2, B2, USEEPS);

	int A2C1 = Classify_(A2, A1, B1, USEEPS);
	int B2C1 = Classify_(B2, A1, B1, USEEPS);
		
	if (a1Fix && (A1C2 == etORIGIN || A1C2 == etDESTINATION)){itr = A1;return crTOUCH;}
	if (b1Fix && (B1C2 == etORIGIN || B1C2 == etDESTINATION)){itr = B1;return crTOUCH;}
	if (a2Fix && (A2C1 == etORIGIN || A2C1 == etDESTINATION)){itr = A2;return crTOUCH;}
	if (b2Fix && (B2C1 == etORIGIN || B2C1 == etDESTINATION)){itr = B2;return crTOUCH;}

	if (b2Fix && B2C1 == etBETWEEN) { itr = B2;return crTOUCH;}
	if (a2Fix && A2C1 == etBETWEEN) { itr = A2;return crTOUCH;}
	if (b1Fix && B1C2 == etBETWEEN) { itr = B1;return crTOUCH;}
	if (a1Fix && A1C2 == etBETWEEN) { itr = A1;return crTOUCH;}

	if (A1C2 == etBEHIND) if (a2Fix) return crNONE; else { itr = A1;return crTOUCH;}
	if (B1C2 == etBEHIND) if (a2Fix) return crNONE; else { itr = B1;return crTOUCH;}

	if (A1C2 == etBEYOND) if (b2Fix) return crNONE; else { itr = A1;return crTOUCH;}
	if (B1C2 == etBEYOND) if (b2Fix) return crNONE; else { itr = B1;return crTOUCH;}

	if (A2C1 == etBEHIND) if (a1Fix) return crNONE; else { itr = A2;return crTOUCH;}
	if (B2C1 == etBEHIND) if (a1Fix) return crNONE; else { itr = B2;return crTOUCH;}

	if (A2C1 == etBEYOND) if (b1Fix) return crNONE; else { itr = A2;return crTOUCH;}
	if (B2C1 == etBEYOND) if (b1Fix) return crNONE; else { itr = B2;return crTOUCH;}

	
	
	PlaneSegmentCross(N1, A1, A2, B2, false, false, itr, USEEPS);
	return crCROSS;
}


//OK
bool LineConsistsPoint(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS)
{
	return (DistancePointLine(P, A, B, USEEPS) < USEEPS);
}


//OK
bool CutConsistsPoint(const TIntVec &P, const TIntVec &A, const TIntVec &B, MBTi USEEPS)
{
	int res = Classify_(P, A, B, USEEPS);
	return (res == etBETWEEN || res == etDESTINATION || res == etORIGIN );
//	return (DistancePointCut(P, A, B) < USEEPS);
}


//OK
bool CutOXCross2D(const TIntVec &p1, const TIntVec &p2, TIntVec &itr, MBTi EPS)
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

MBTi sqr(MBTi x)
{
	return x*x;
}

TIntVec VectorP2d(const TIntVec &src)
{
	return VectorP(src, TIntVec(0, 0, 1));
}


//OK
int Classify_(const TIntVec& P, const TIntVec& A, const TIntVec& B, MBTi EPS)
{
	TIntVec l = (B-A).Normalize();
	MBTi ro = DistancePointPlane(P, VectorP2d(l), A);
	if (ro<-EPS)
		return etLEFT;
	if (ro>EPS)
		return etRIGHT;

	if (P.Equal(A, EPS))
		return etORIGIN;
	if (P.Equal(B, EPS))
		return etDESTINATION;

	MBTi roA = DistancePointPlane(A, l, P);
	MBTi roB = DistancePointPlane(B, l, P);

	if (MIN(roA, roB)>0)
		return etBEHIND;

	if (MAX(roA, roB)<0)
		return etBEYOND;
	return etBETWEEN;	
}

//OK
int ClassifyLine(const TIntVec& P, const TIntVec& A, const TIntVec& B, MBTi EPS)
{
	TIntVec l = (B-A).Normalize();
	MBTi ro = DistancePointPlane(P, VectorP2d(l), A);
	if (ro<-EPS)
		return etLEFT;
	if (ro>EPS)
		return etRIGHT;
	return etBETWEEN;	
}


// ОК
int EdgeType(const TIntVec& A, const TIntVec& V0,const TIntVec& V1,MBTi USEEPS)
{

  switch (Classify_(A, V0, V1,USEEPS))
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






*/ 
