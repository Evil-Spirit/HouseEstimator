#include <vcl.h>                           
#include "Usefuls.h"  
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"                                    
#pragma hdrstop

#include "GeomObjV.h"

#include "Poligon.h"
#include "MyGL.h"

#pragma package(smart_init)
//////////////////////
//		Misc		//
//////////////////////
TGPoint *TGeomObject::CutOX_Cross2D(TGCut &cut, MBTi EPS)
{
	TIntVec p1 = cut.Src->Point;
	TIntVec p2 = cut.Dst->Point;
	if (MIN(p1.y, p2.y)>=PEPS || MAX(p1.y, p2.y)<=-PEPS)
		return NULL;

	TIntVec d = p2-p1;
	TIntVec o = p1;

	if (fabs(d.x)>PEPS && fabs(d.y)/fabs(d.x)<=GET_CEPS(PEPS)) 
		return NULL;

	if (MIN(fabs(p1.y), fabs(p2.y))<PEPS)
		if (fabs(p2.y) < fabs(p1.y))
		{
			return cut.Dst;
		} else
		{
			return cut.Src;
		}
 
	float t = -o.y/d.y;
	TIntVec it;
	it.x = t*d.x + o.x;	
	it.y = 0;
	it.z = t*d.z + o.z;	

	return AddPoint(it);
}

TMDelTList < TMTwinElement < TMTList < TGCut >, TGPolygon *> > fuckin01;// TODO: Bad Words01
TMTwinElement < TMTList < TGCut >, TGPolygon *> fuckin02;// TODO: Bad Words02

enum TTransformType
{
	trROTATE_X,
	trROTATE_Y,
	trROTATE_Z,
	trTRANSLATE,
	trIDENTITY,
	trSCALE,
};
class TMatrix
{
	union
	{
		struct
		{	
			MBTi lData[16];
		};
		struct
		{
			MBTi mData[4][4];
		};
	};

public:	
	TMatrix()
	{
//		LoadIdentity();
	}
	TMatrix(TTransformType t, MBTi value)
	{
		switch (t)
		{
			case trROTATE_X:
				LoadRotateX(value);
				break;
			case trROTATE_Y:
				LoadRotateY(value);
				break;
			case trROTATE_Z:
				LoadRotateZ(value);
				break;

		}
	}
	void LoadIdentity()
	{
		mData[0][0] = 1.0f; mData[0][1] = 0.0f; mData[0][2] = 0.0f; mData[0][3] = 0.0f;
		mData[1][0] = 0.0f; mData[1][1] = 1.0f; mData[1][2] = 0.0f; mData[1][3] = 0.0f;
		mData[2][0] = 0.0f; mData[2][1] = 0.0f; mData[2][2] = 1.0f; mData[2][3] = 0.0f;
		mData[3][0] = 0.0f; mData[3][1] = 0.0f; mData[3][2] = 0.0f; mData[3][3] = 1.0f;
	}

	TIntVec operator*(const TIntVec &v) const
	{
		TIntVec temp;
		temp.x = mData[0][0]*v.x + mData[0][1]*v.y + mData[0][2]*v.z + mData[0][3];
		temp.y = mData[1][0]*v.x + mData[1][1]*v.y + mData[1][2]*v.z + mData[1][3];
		temp.z = mData[2][0]*v.x + mData[2][1]*v.y + mData[2][2]*v.z + mData[2][3];
		return temp;
	}

	TMatrix operator*(const TMatrix &m) const
	{
		TMatrix temp;
		int i, j;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++) {
				temp.mData[i][j] = 
					mData[i][0] * m.mData[0][j] +
					mData[i][1] * m.mData[1][j] +
					mData[i][2] * m.mData[2][j] +
					mData[i][3] * m.mData[3][j];
			}
		return temp;
	}

	void LoadRotateX(MBTi a)
	{
		LoadIdentity();
//		MBTi cs = cos(a*M_PI/180);
//		MBTi sn = sin(a*M_PI/180);
		long double cs, sn;
		SinCos(a, sn, cs);
		mData[1][1] = cs;
		mData[1][2] = -sn;
		mData[2][1] = sn;
		mData[2][2] = cs;   
	}
	void LoadRotateY(MBTi a)
	{
		LoadIdentity();
//		MBTi cs = cos(a*M_PI/180);
//		MBTi sn = sin(a*M_PI/180);
		long double cs, sn;
		SinCos(a, sn, cs);
		mData[0][0] = cs;
		mData[0][2] = -sn;
		mData[2][0] = sn;
		mData[2][2] = cs;
	}
	void LoadRotateZ(MBTi a)
	{
		LoadIdentity();
//		MBTi cs = cos(a*M_PI/180);
//		MBTi sn = sin(a*M_PI/180);
		long double cs, sn;
		SinCos(a, sn, cs);
		mData[0][0] = cs;
		mData[0][1] = -sn;
		mData[1][0] = sn;
		mData[1][1] = cs;
	}
	
};

#define OLD

void TGeomObject::TransformToPolygon(TGPolygon *p, const TIntVec& n, const TIntVec& o, MBTi &AngX, MBTi &AngY, MBTi &AngZ)
{
	CachePoints();
#ifdef OLD 
	TIntVec n_n = n;
	TIntVec angle;

	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = FVertex[i].Point - o;

	AngX = -ArcTan2(p->Normal.y, p->Normal.z)/M_PI*180;
	angle = TIntVec(-AngX, 0, 0);

	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));

	TIntVec nNormal = p->Normal;
	n_n = RotateAround(n_n, angle, TIntVec(0,0,0));

	AngY = ArcTan2(nNormal.x, nNormal.z)/M_PI*180;
	angle = TIntVec(0, -AngY, 0);
	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));
	n_n = RotateAround(n_n, angle, TIntVec(0,0,0));
	

	AngZ = ArcTan2(n_n.y, n_n.x)/M_PI*180;
	angle = TIntVec(0, 0, -AngZ);
	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));
#else		

	TIntVec n_n = n;
	TIntVec nrm = p->Normal;
	TIntVec angle;

	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = FVertex[i].Point - o;

	AngX = -ArcTan2(nrm.y, nrm.z);
	TMatrix mX(trROTATE_X, -AngX);
	nrm = mX * nrm;

	TIntVec nNormal = p->Normal;
	n_n = mX*n_n;

	AngY = -ArcTan2(nrm.x, nrm.z);
	TMatrix mY(trROTATE_Y, -AngY);
	n_n = mY*n_n;
	

	AngZ = ArcTan2(n_n.y, n_n.x);
	TMatrix mZ(trROTATE_Z, -AngZ);
	TMatrix mR = mZ * mY * mX;

	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = mR * FVertex[i].Point;
#endif
}

void TGeomObject::TransformBack(const TIntVec& n, const TIntVec& o, const MBTi &AngX, const MBTi &AngY, const MBTi &AngZ)
{
#ifdef OLD 
	TIntVec angle;

	angle = TIntVec(0, 0, AngZ);
	for(int i=0;i<FVertex.Count;i++)
		if (!FVertex[i].FFlags.Cached)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));

	angle = TIntVec(0, AngY, 0);
	for(int i=0;i<FVertex.Count;i++)
		if (!FVertex[i].FFlags.Cached)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));
	angle = TIntVec(AngX, 0, 0);
	for(int i=0;i<FVertex.Count;i++)
		if (!FVertex[i].FFlags.Cached)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));

	for(int i=0;i<FVertex.Count;i++)
		if (!FVertex[i].FFlags.Cached)
			FVertex[i].Point = FVertex[i].Point + o;
#else			

	TMatrix mX(trROTATE_X, AngX);
	TMatrix mY(trROTATE_Y, AngY);
	TMatrix mZ(trROTATE_Z, AngZ);
	TMatrix mR = mX * mY * mZ;

	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = mR * FVertex[i].Point;
			
	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = FVertex[i].Point + o;
#endif		
	RestorePoints();
}


void TGeomObject::TransformToPlane(const TIntVec& n, MBTi &AngX, MBTi &AngY)
{
	CachePoints();
	TIntVec n_n = n.Normalize();
	TIntVec angle;

	AngX = -ArcTan2(n_n.y, n_n.z)/M_PI*180;
	angle = TIntVec(-AngX, 0, 0);

	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));

	n_n = RotateAround(n_n, angle, TIntVec(0,0,0));

	AngY = ArcTan2(n_n.x, n_n.z)/M_PI*180;
	angle = TIntVec(0, -AngY, 0);
	for(int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));
}

void TGeomObject::TransformBack(const MBTi &AngX, const MBTi &AngY)
{
	TIntVec angle;

	angle = TIntVec(0, AngY, 0);
	for(int i=0;i<FVertex.Count;i++)
		if (!FVertex[i].FFlags.Cached)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));

	angle = TIntVec(AngX, 0, 0);
	for(int i=0;i<FVertex.Count;i++)
		if (!FVertex[i].FFlags.Cached)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));
	RestorePoints();
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
void TGeomObject::TransformToPlane(const TIntVec& n, TMTList<TMyObject> &what, MBTi &AngX, MBTi &AngY, const TIntVec &org)
{
	if (!what.Count)
		return;
	FillPointsFlags(flMARK, gfFALSE);
	for (int i=0;i<what.Count;i++)
	if (what.Items[i])
	{
		if (what[i].DynamicType == TGPoint::StaticType)
		{
				TGPoint *Element = (TGPoint *)what.Items[i];
				Element->FFlags.Mark = gfTRUE;
		} else if (what[i].DynamicType == TGCut::StaticType)
		{
				TGCut *Element = (TGCut *)what.Items[i];
				Element->Src->FFlags.Mark = gfTRUE;
				Element->Dst->FFlags.Mark = gfTRUE;
		} else if (what[i].DynamicType == TGPolygon::StaticType)
		{
			TGPolygon *Element = (TGPolygon *)what.Items[i];
			for (int j=0;j<Element->FCuts.Count;j++)
			{
				Element->FCuts[j].Src->FFlags.Mark = gfTRUE;
				Element->FCuts[j].Dst->FFlags.Mark = gfTRUE;
			}	
			for (int k=0;k<Element->FHoles.Count;k++)
				for (int j=0;j<Element->FHoles[k].FCuts.Count;j++)
				{
					Element->FHoles[k].FCuts[j].Src->FFlags.Mark = gfTRUE;
					Element->FHoles[k].FCuts[j].Dst->FFlags.Mark = gfTRUE;
				}	
		} else
		{
			throw EMyException(what[i].DynamicType->Name + " <TGeomObject::TransformToPlane> : неверный тип!");
		}	
	}	  
	
	TIntVec angle;
	
	AngX = -ArcTan2(n.y, n.z)/M_PI*180;
	angle = TIntVec(-AngX, 0, 0);

	for ( int i=0;i<FVertex.Count;i++ )
		if (FVertex[i].FFlags.Mark)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, org);
	TIntVec nNormal = RotateAround(n, angle, TIntVec(0,0,0));

	AngY = ArcTan2(nNormal.x, nNormal.z)/M_PI*180;
	angle = TIntVec(0, -AngY, 0);
	for ( int i=0;i<FVertex.Count;i++ )
		if (FVertex[i].FFlags.Mark)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, org);
	nNormal = RotateAround(nNormal, angle, TIntVec(0,0,0));			
}

void TGeomObject::TransformBack(TMTList<TMyObject> &what, const MBTi &AngX, const MBTi &AngY, const TIntVec &org)
{
	if (!what.Count)
		return;
	FillPointsFlags(flMARK, gfFALSE);
	for (int i=0;i<what.Count;i++)
	{
		if (what[i].DynamicType == TGPoint::StaticType)
		{
				TGPoint *Element = (TGPoint *)what.Items[i];
				Element->FFlags.Mark = gfTRUE;
		} else if (what[i].DynamicType == TGCut::StaticType)
		{
				TGCut *Element = (TGCut *)what.Items[i];
				Element->Src->FFlags.Mark = gfTRUE;
				Element->Dst->FFlags.Mark = gfTRUE;
		} else if (what[i].DynamicType == TGPolygon::StaticType)
		{
			TGPolygon *Element = (TGPolygon *)what.Items[i];
			for (int j=0;j<Element->FCuts.Count;j++)
			{
				Element->FCuts[j].Src->FFlags.Mark = gfTRUE;
				Element->FCuts[j].Dst->FFlags.Mark = gfTRUE;
			}	
			for (int k=0;k<Element->FHoles.Count;k++)
				for (int j=0;j<Element->FHoles[k].FCuts.Count;j++)
				{
					Element->FHoles[k].FCuts[j].Src->FFlags.Mark = gfTRUE;
					Element->FHoles[k].FCuts[j].Dst->FFlags.Mark = gfTRUE;
				}	
		} else
		{
			throw EMyException("<TGeomObject::TransformBack> : неверный тип!");
		}	
	}	

	TIntVec angle;
	angle = TIntVec(0, AngY, 0);
	for ( int i=0;i<FVertex.Count;i++ )
		if (FVertex[i].FFlags.Mark)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, org);

	angle = TIntVec(AngX, 0, 0);
	for ( int i=0;i<FVertex.Count;i++ )
		if (FVertex[i].FFlags.Mark)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, org);
}
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
void TGeomObject::TransformMove(TMTList<TMyObject> &what, TIntVec &org, bool chkMark)
{
	if (!what.Count)
		return;
	FillPointsFlags(flBELONG, gfFALSE);
	if (chkMark)
		for (int i=0;i<FVertex.Count;i++)	
			FVertex[i].FFlags.Belong = FVertex[i].FFlags.Mark;
		
	FillPointsFlags(flMARK, gfFALSE);
	for (int i=0;i<what.Count;i++)
	if (what.Items[i])
	{
		if (what[i].DynamicType == TGPoint::StaticType)
		{
				TGPoint *Element = (TGPoint *)what.Items[i];
				Element->FFlags.Mark = !Element->FFlags.Belong;
		} else if (what[i].DynamicType == TGCut::StaticType)
		{
				TGCut *Element = (TGCut *)what.Items[i];
				Element->Src->FFlags.Mark = !Element->Src->FFlags.Belong;
				Element->Dst->FFlags.Mark = !Element->Dst->FFlags.Belong;
		} else if (what[i].DynamicType == TGPolygon::StaticType)
		{
			TGPolygon *Element = (TGPolygon *)what.Items[i];
			for (int j=0;j<Element->FCuts.Count;j++)
			{
				Element->FCuts[j].Src->FFlags.Mark = !Element->FCuts[j].Src->FFlags.Belong;
				Element->FCuts[j].Dst->FFlags.Mark = !Element->FCuts[j].Dst->FFlags.Belong;
			}	
			for (int k=0;k<Element->FHoles.Count;k++)
				for (int j=0;j<Element->FHoles[k].FCuts.Count;j++)
				{
					Element->FHoles[k].FCuts[j].Src->FFlags.Mark = !Element->FHoles[k].FCuts[j].Src->FFlags.Belong;
					Element->FHoles[k].FCuts[j].Dst->FFlags.Mark = !Element->FHoles[k].FCuts[j].Dst->FFlags.Belong;
				}	
		} else
		{
			throw EMyException(what[i].DynamicType->Name + " <TGeomObject::TransformToPlane> : неверный тип!");
		}	
	}	  

	for(int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = FVertex[i].Point + org;
}
void TGeomObject::TransformToPlaneAndOX(TMTList<TMyObject> &what, const TIntVec& Normal, const TIntVec& n, MBTi &AngX, MBTi &AngY, MBTi &AngZ, bool chkMark)
{
	if (!what.Count)
		return;
	FillPointsFlags(flBELONG, gfFALSE);
	if (chkMark)
		for (int i=0;i<FVertex.Count;i++)	
			FVertex[i].FFlags.Belong = FVertex[i].FFlags.Mark;
		
	FillPointsFlags(flMARK, gfFALSE);
	for (int i=0;i<what.Count;i++)
	if (what.Items[i])
	{
		if (what[i].DynamicType == TGPoint::StaticType)
		{
				TGPoint *Element = (TGPoint *)what.Items[i];
				Element->FFlags.Mark = !Element->FFlags.Belong;
		} else if (what[i].DynamicType == TGCut::StaticType)
		{
				TGCut *Element = (TGCut *)what.Items[i];
				Element->Src->FFlags.Mark = !Element->Src->FFlags.Belong;
				Element->Dst->FFlags.Mark = !Element->Dst->FFlags.Belong;
		} else if (what[i].DynamicType == TGPolygon::StaticType)
		{
			TGPolygon *Element = (TGPolygon *)what.Items[i];
			for (int j=0;j<Element->FCuts.Count;j++)
			{
				Element->FCuts[j].Src->FFlags.Mark = !Element->FCuts[j].Src->FFlags.Belong;
				Element->FCuts[j].Dst->FFlags.Mark = !Element->FCuts[j].Dst->FFlags.Belong;
			}	
			for (int k=0;k<Element->FHoles.Count;k++)
				for (int j=0;j<Element->FHoles[k].FCuts.Count;j++)
				{
					Element->FHoles[k].FCuts[j].Src->FFlags.Mark = !Element->FHoles[k].FCuts[j].Src->FFlags.Belong;
					Element->FHoles[k].FCuts[j].Dst->FFlags.Mark = !Element->FHoles[k].FCuts[j].Dst->FFlags.Belong;
				}	
		} else
		{
			throw EMyException(what[i].DynamicType->Name + " <TGeomObject::TransformToPlane> : неверный тип!");
		}	
	}	  

//	CachePoints();	
#ifdef OLD 
	TIntVec n_n = n;
	TIntVec angle;

/*	for(int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = FVertex[i].Point - o;
*/
	AngX = -ArcTan2(Normal.y, Normal.z)/M_PI*180;
	angle = TIntVec(-AngX, 0, 0);

	for(int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));

	TIntVec nNormal = Normal;
	n_n = RotateAround(n_n, angle, TIntVec(0,0,0));
	nNormal = RotateAround(nNormal, angle, TIntVec(0,0,0));

	AngY = ArcTan2(nNormal.x, nNormal.z)/M_PI*180;
	angle = TIntVec(0, -AngY, 0);
	for(int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));
	n_n = RotateAround(n_n, angle, TIntVec(0,0,0));
	

	AngZ = ArcTan2(n_n.y, n_n.x)/M_PI*180;
	angle = TIntVec(0, 0, -AngZ);
	for(int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));
#else		

	TIntVec n_n = n;
	TIntVec nrm = Normal;
	TIntVec angle;

/*	for(int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point -= o;
*/
	AngX = -ArcTan2(nrm.y, nrm.z);
	TMatrix mX(trROTATE_X, -AngX);
	nrm = mX * nrm;

	n_n = mX*n_n;
	nrm = mX*nrm;

	AngY = -ArcTan2(nrm.x, nrm.z);
	TMatrix mY(trROTATE_Y, -AngY);
	n_n = mY*n_n;
	

	AngZ = ArcTan2(n_n.y, n_n.x);
	TMatrix mZ(trROTATE_Z, -AngZ);
	TMatrix mR = mZ * mY * mX;

	for(int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = mR * FVertex[i].Point;
#endif
}

void TGeomObject::TransformBack(TMTList<TMyObject> &what, const TIntVec& n, const MBTi &AngX, const MBTi &AngY, const MBTi &AngZ, bool chkMark)
{
	if (!what.Count)
		return;
	FillPointsFlags(flBELONG, gfFALSE);
	
	if (chkMark)
		for (int i=0;i<FVertex.Count;i++)	
			FVertex[i].FFlags.Belong  = FVertex[i].FFlags.Mark;

	FillPointsFlags(flMARK, gfFALSE);
	for (int i=0;i<what.Count;i++)
	{
		if (what[i].DynamicType == TGPoint::StaticType)
		{
				TGPoint *Element = (TGPoint *)what.Items[i];
				Element->FFlags.Mark = !Element->FFlags.Belong;
		} else if (what[i].DynamicType == TGCut::StaticType)
		{
				TGCut *Element = (TGCut *)what.Items[i];
				Element->Src->FFlags.Mark = !Element->Src->FFlags.Belong;
				Element->Dst->FFlags.Mark = !Element->Dst->FFlags.Belong;
		} else if (what[i].DynamicType == TGPolygon::StaticType)
		{
			TGPolygon *Element = (TGPolygon *)what.Items[i];
			for (int j=0;j<Element->FCuts.Count;j++)
			{
				Element->FCuts[j].Src->FFlags.Mark = !Element->FCuts[j].Src->FFlags.Belong;
				Element->FCuts[j].Dst->FFlags.Mark = !Element->FCuts[j].Dst->FFlags.Belong;
			}	
			for (int k=0;k<Element->FHoles.Count;k++)
				for (int j=0;j<Element->FHoles[k].FCuts.Count;j++)
				{
					Element->FHoles[k].FCuts[j].Src->FFlags.Mark = !Element->FHoles[k].FCuts[j].Src->FFlags.Belong;
					Element->FHoles[k].FCuts[j].Dst->FFlags.Mark = !Element->FHoles[k].FCuts[j].Dst->FFlags.Belong;
				}	
		} else
		{
			throw EMyException("<TGeomObject::TransformBack> : неверный тип!");
		}	
	}	

#ifdef OLD 
	TIntVec angle;

	angle = TIntVec(0, 0, AngZ);
	for(int i=0;i<FVertex.Count;i++)
//		if (!FVertex[i].FFlags.Cached)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));

	angle = TIntVec(0, AngY, 0);
	for(int i=0;i<FVertex.Count;i++)
//		if (!FVertex[i].FFlags.Cached)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));
	angle = TIntVec(AngX, 0, 0);
	for(int i=0;i<FVertex.Count;i++)
//		if (!FVertex[i].FFlags.Cached)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = RotateAround(FVertex[i].Point, angle, TIntVec(0,0,0));

/*	for(int i=0;i<FVertex.Count;i++)
//		if (!FVertex[i].FFlags.Cached)
		if (FVertex[i].FFlags.Mark == gfTRUE)
			FVertex[i].Point = FVertex[i].Point + o;*/
#else			

	TMatrix mX(trROTATE_X, AngX);
	TMatrix mY(trROTATE_Y, AngY);
	TMatrix mZ(trROTATE_Z, AngZ);
	TMatrix mR = mX * mY * mZ;

	for(int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark = gfTRUE)
			FVertex[i].Point = (mR * FVertex[i].Point);
/*	for(int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark = gfTRUE)
			FVertex[i].Point = FVertex[i].Point + o;*/
#endif		
//	RestorePoints();
}
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
//////////////////////
//		Split		//
//////////////////////


bool TGeomObject::SplitCut(TGCut *c, TGPoint *newPnt)
{
	TGCut *c1, *c2;
	return SplitCut(c, newPnt, c1, c2);
}

//#define GEOMETRY_DEBUG			
bool TGeomObject::SplitCut(TGCut *c, TGPoint *newPnt, TGCut *&Result1, TGCut *&Result2)
{
	Result1 = c;
	Result2 = NULL;
	if (c->ConsistsPoint(newPnt)) 
		return false;

	TGCut *cn = AddCut(c->Src, newPnt);
	TGCut *cn1 = AddCut(newPnt, c->Dst);

	if (cn->FFlags.Alredy == gfFALSE)
	{
		cn->FPlane.Assign(&c->FPlane);
		cn->Assign(c);
	} else
	{
		TMTListUnite(cn->FPlane, c->FPlane);
		cn->FFlags = FlagUnite(cn->FFlags, c->FFlags);
	}
	if (cn1->FFlags.Alredy == gfFALSE)
	{
		cn1->FPlane.Assign(&c->FPlane);
		cn1->Assign(c);
	} else	
	{
		TMTListUnite(cn1->FPlane, c->FPlane);
		cn1->FFlags = FlagUnite(cn1->FFlags, c->FFlags);
	}	

	Result1 = cn;
	Result2 = cn1;

	for (int i=0;i<c->FPlane.Count;i++)
		if (c->FPlane.Items[i])
		{
			int index = c->FPlane[i].FCuts.IndexOf(c);
			if (c->FPlane[i].FCuts.CycVal(index-1).CanConnect(*cn))
			{
#ifdef GEOMETRY_DEBUG			
				if (c->FPlane[i].FCuts.IndexOf(cn1)!=-1 || c->FPlane[i].FCuts.IndexOf(cn)!=-1)
					throw EMyException("<TGeomObject::SplitCut> - наложение отрезков!");
#endif				
				if (c->FPlane[i].FCuts.IndexOf(cn1)==-1)
					c->FPlane[i].FCuts.Insert(index, cn1);
				if (c->FPlane[i].FCuts.IndexOf(cn)==-1)
					c->FPlane[i].FCuts.Insert(index, cn);
			}	
			else	
			{
#ifdef GEOMETRY_DEBUG			
				if (c->FPlane[i].FCuts.IndexOf(cn1)!=-1 || c->FPlane[i].FCuts.IndexOf(cn)!=-1)
					throw EMyException("<TGeomObject::SplitCut> - наложение отрезков!");
#endif				
				if (c->FPlane[i].FCuts.IndexOf(cn)==-1)
					c->FPlane[i].FCuts.Insert(index, cn);
				if (c->FPlane[i].FCuts.IndexOf(cn1)==-1)
					c->FPlane[i].FCuts.Insert(index, cn1);
			}	
			c->FPlane[i].FCuts.Remove(c);
			c->FPlane.Items[i] = NULL;
		}	

	FCuts.Remove(c);
	return true;
}
void TGeomObject::TransfixPolygon2d(TGPolygon *p, TMTList<TGPoint> &cps)
{
	if (!p)
		throw EMyException("TGeomObject::TransfixPolygon : NULL - полигон");
	cps.Clear();
	TMTList <TGCut> cuts;
	//Запоминаем отрезки полигона
	cuts.Assign(&p->FCuts);

	// Разрезаем отрезки полигона
	for (int i=0;i<cuts.Count;i++)
	{
		TGCut *rc1, *rc2;
		TGPoint *cp = SliceCutByPlane2d(cuts.Items[i], rc1, rc2);
		if (cp) 
			cps.Add(cp);
	}
	if (p->FParent)
		return;
	//Разрезаем дырки полигона
	for (int i=0;i<p->FHoles.Count;i++)
	{
		TMTList <TGPoint> pnts;
		TransfixPolygon2d(p->FHoles.Items[i], pnts);
		TMTListAdd(cps, pnts);
	}
//сортируем точки рассечения
	for (int i=0;i<cps.Count;i++)
		for (int j=i;j<cps.Count;j++)
			if (cps[i].Point.x>cps[j].Point.x)
				cps.Exchange(i,j);

//Удаляем повторные точки рассечения				
	for (int i=0;i<cps.Count;i++)
		if (cps.Items[i]==cps.CycleItems[i+1])
				cps.Delete(i--);
}

bool TGeomObject::SplitPolygon(TGPolygon *p, TMTList<TGCut> &Ct, TMTList<TGPolygon> &Result)
{
	Result.Clear();
	Result.Add(p);
	TMTList <TGCut> Cut;
	Cut.Assign(&Ct);
	if (!p || !p->Closed ) 
		return false;

	//Удаляем отрезки, содержащиеся в полигоне
	for (int i=0;i<Cut.Count;i++)
		if (p->FCuts.IndexOf(Cut.Items[i]) != -1)	
			Cut.Delete(i--);
	// Удаляем повторные отрезки
	for (int i=0;i<Cut.Count;i++)
		for (int j=i+1;j<Cut.Count;j++)
			if (Cut.Items[i] == Cut.Items[j])
				Cut.Delete(j--);
		
	// Если нечем резать - выходим
	if (!Cut.Count)
		return false;

	TMTList <TGCut> Heap;
	TMTList <TGPoint> polyPnt;
	TMDelTList <TGPolygon> Holes;

	// Куча отрезков для разбиения
	Heap.Assign(&p->FCuts);

	// Пересечение. ?????????
	for (int i=0;i<Cut.Count;i++)
	{
		Heap.Add(Cut.Items[i]);
		Heap.Last()->FFlags.Intersect = gfTRUE;
	}	
	// Не дырки
	FillCutsFlags(Heap, flHOLE, gfFALSE);
/*
	// Проверяем касание отрезков разбиения с дырками
	for (int j=0;j<p->FHoles.Count;j++)
	{
		bool linkH = false;
		bool linkC = false;
		for (int i=0;i<Cut.Count;i++)
		{
			for (int k=0;k<p->FHoles[j].FCuts.Count;k++)
				if (!linkH)
					if (Cut[i].CanConnect(p->FHoles[j].FCuts[k]))
					{	
						linkH = true; // Есть касание
						break;
					}
				else; else
					break;	
			for (int k=0;k<p->FCuts.Count;k++)
				if (!linkC)
					if (Cut[i].CanConnect(p->FCuts[k]))
					{	
						linkC = true; // Есть касание
						break;
					}	
				else; else
					break;
		}		
		
		// Если есть касание - добавить отрезки дырки в кучу, при этом удалив ее из из разряда дырок
		if (linkH)
		{
			for (int k=0;k<p->FHoles[j].FCuts.Count;k++)
				Heap.Add(p->FHoles[j].FCuts.Items[k]);
			// Только если дырка перестает быть дыркой мы ее удаляем	
			if (linkC)
				p->FHoles.Delete(j--);
		}		
	}			

*/				
	// Помним данные
	TIntVec norm = p->FNormal;
	TIntVec orig = p->Origin;

	// Запоминаем дырки 
	for (int i=0;i<p->FHoles.Count;i++)
	{
		TMTListAdd(Heap, p->FHoles[i].FCuts);
		Holes.Add(p->FHoles.Items[i]);
		p->FHoles.RemoveOnly(i--);
	}	

	for (int i=0;i<Heap.Count;i++)
		for (int j=i+1;j<Heap.Count;j++)
			if (Heap.Items[i] == Heap.Items[j])
				Heap.Delete(j--);
				
	// Удаляем разбиваемый полигон
	FPolygons.Remove(p);
	Result.Clear();

	TMDelTList< TMTList<TGCut> > Poly;		//Полигоны
	

	// Полигонизируем кучу...
	StructureFix(Heap, sfxREMOVE_BRIDGES_BY_POLYGONIZE);
	Polygonize2d(Heap, Poly);

	// Проверяем
/*	for (int i=0;i<Poly.Count;i++)
	{
		bool isHole = true;
		for (int j=0;j<Poly[i].Count;j++)
			if (Poly[i][j].FFlags.Hole != gfTRUE)
			{
				isHole = false;
				break;
			}	
		if (isHole)	
			Poly.RemoveOnly(i--);
	}
*/
	for (int i=0;i<Poly.Count;i++)
	{
/*		for (int l=0;l<Poly[i].Count;l++)
			for (int j=l+1;j<Poly[i].Count;j++)
				if (Poly[i].Items[l] == Poly[i].Items[j])
					Poly[i].Delete(j--);
		if (Poly[i].Count>2)*/
			Result.Add(AddPolygon(Poly[i], norm));	
	}	


	FillPolygonsFlags(Result, flHOLE, gfFALSE);
	for (int i=0;i<Result.Count;i++)
		for (int j=0;j<Holes.Count;j++)
			if (Holes[j].PolygonInPolygon2d(Result[i], PEPS) == pipINSIDE)
			{
				Result[i].FFlags.Hole = gfTRUE;
				Result[i].FParent = NULL;
				break;
			}	

/*	for (int i=0;i<Result.Count;i++)
		for (int j=0;j<Holes.Count;j++)
			if (Result[i].PolygonInPolygon(Holes[j], PEPS) == pipINSIDE)
			{
				Result[i].AddHole(Holes[j].FCuts);
				Holes[j].FCuts.Clear();
				Holes.Delete(j--);
			}
*/
			
	TMDelTList<TMDelTList<int> > matrix;
	for (int i=0;i<Result.Count;i++)
	{
		matrix.Add(new TMDelTList<int>);
		for (int j=0;j<Result.Count;j++)
			matrix.Last()->Add(new int(0));
	}	
	for (int i=0;i<matrix.Count;i++)
		for (int j=0;j<matrix[i].Count;j++)
			if (i!=j)
				matrix[i][j] = (Result[j].PolygonInPolygon2d(Result[i], PEPS) == pipINSIDE) ? 1 : 0;
			else
				matrix[i][j] = -1;

	TMTList <TGPolygon> toHell;
	for (int i=0;i<matrix.Count;i++)
	{
		int max = 0;
		int best = -1;
		
		for (int j=0;j<matrix[i].Count;j++)
			if (matrix[i][j] == 1)
			{
				int counter = 0;
				for (int k=0;k<matrix[j].Count;k++)
					if (matrix[j][k] == 1)
						counter++;
				if (best == -1 || counter>max)
				{
					max = counter;
					best = j;
				}	
			}
		if (best!=-1)
		{
			if (Result[i].Flags.Hole == gfTRUE)
			{
				Result[best].FHoles.Add(Result.Items[i]);
				Result[i].FParent = Result.Items[best];
				FillCutsFlags(Result[i].FCuts, flHOLE, gfTRUE);
				FPolygons.RemoveOnly(Result.Items[i]);
			} else                                    
			{
				Result[best].AddHole(Result[i].FCuts);
				toHell.Add(Result.Items[i]);
			}
		}	
	}
	for (int i=0;i<Result.Count;i++)
		if (Result[i].FFlags.Hole == gfTRUE && Result[i].FParent == NULL)
		{
			toHell.Add(Result.Items[i]);
			FPolygons.Remove(Result.Items[i]);
		}		
	TMTListSub(Result, toHell);
				
	
/*
	for(int i=0;i<FPolygons.Count;i++)
		if (FPolygons[i].IsHoled())	
			for (int j=0;j<FPolygons[i].FHoles.Count;j++)
				if(FPolygons[i].FHoles[j].IsHoled())
					for (int k=0;k<FPolygons[i].FHoles[j].FHoles.Count;k++)
					{
						FPolygons.Add(FPolygons[i].FHoles[j].FHoles.Items[k]);
						FPolygons[i].FHoles[j].FHoles.RemoveOnly(k--);
					}
*/			
	return true;	
}





void TGeomObject::SplitPolygonByPlane(TGPolygon *p, const TIntVec& n, const TIntVec& o, TMTList<TGPolygon> &Result)
{
	
	MBTi AngX, AngY, AngZ;
	TIntVec dir, org;

	//Находим линию пересечения	
	if (!PlanePlaneCross(n, o, p->Normal, p->Origin, dir, org, PEPS)) 
		return;

	//Поворачиваем объект в плоскость полигона
	TransformToPolygon(p, dir, org, AngX, AngY, AngZ);

	TMTList <TGCut> cuts;
	TMTList <TGPoint> cps;

/*	//Запоминаем отрезки полигона
	for (int i=0;i<p->FCuts.Count;i++)
		cuts.Add(p->FCuts.Items[i]);

	// Разрезаем отрезки полигона
	for (int i=0;i<cuts.Count;i++)
	{
		TGPoint *cp = SliceCutByPlane(cuts.Items[i], TIntVec(1,0,0), TIntVec(0,0,0));
		if (cp) 
			cps.Add(cp);
	}
	//Разрезаем дырки полигона
	for (int i=0;i<p->FHoles.Count;i++)
	{
		TMTList <TGCut> cuts;
		bool hasSplit = false;
		//Запоминаем отрезки дырки
		for (int j=0;j<p->FHoles[i].FCuts.Count;j++)
			cuts.Add(p->FHoles[i].FCuts.Items[j]);
		// Разрезаем отрезки дырки
		for (int j=0;j<cuts.Count;j++)
		{
			TGPoint *cp = SliceCutByPlane(cuts.Items[j], TIntVec(1,0,0), TIntVec(0,0,0));
			if (cp)
			{ 
				cps.Add(cp);
				hasSplit = true;
			}	
		}
	}
		
	
//сортируем точки рассечения
	for (int i=0;i<cps.Count;i++)
		for (int j=i;j<cps.Count;j++)
			if (cps[i].Point.x>cps[j].Point.x)
				cps.Exchange(i,j);

//Удаляем повторные точки рассечения				
	for (int i=0;i<cps.Count;i++)
		if (cps.Items[i]==cps.CycleItems[i+1])
				cps.Delete(i--);
*/
	TransfixPolygon2d(p, cps);			
//Добавляем отрезки рассечения
	TMTList<TGCut> Split;
	int a = 0xFF;			 
	for (int i=0;i<cps.Count-1;i++)
	{
		a = p->PointInPolygon_UseHoles2d( (cps[i].Point + cps[i+1].Point)/2.0f, PEPS/10.0f);
		if (a == pipINSIDE || a == pipBOUNDARY /*|| a == pipHOLEBOUNDARY*/ )
		{
			Split.Add(AddCut(cps.Items[i], cps.Items[i+1]));
			Split.Last()->FFlags.Intersect = gfTRUE;
//			if (p->FCuts.IndexOf(Split.Last())!=-1 || Split.IndexOf(Split.Last())!=Split.Count-1)
//				InfoMsg("gg");
		}	
	}	

//Рассекаем полигон
	SplitPolygon(p, Split, Result);

//Возвращаем объект обратно	
	TransformBack(dir, org, AngX, AngY, AngZ);
	
}

//////////////////////
//		Slice		//
//////////////////////

TGPoint *TGeomObject::SliceCutByPlane2d(TGCut *c, TGCut *&rc1, TGCut *&rc2)
{
/*	TIntVec CP;
	rc1 = c;
	rc2 = NULL;
	if (!CutOXCross2D(c->Src->Point, c->Dst->Point, CP, CEPS))
		return NULL;
	TGPoint *newPnt = AddPoint(CP);
	SplitCut(c, newPnt, rc1, rc2);
	return newPnt;
*/	
	rc1 = c;
	rc2 = NULL;
	TGPoint *CP;

	if ((CP = CutOX_Cross2D(*c, PEPS)) == NULL)
		return NULL;

	SplitCut(c, CP, rc1, rc2);

	return CP;
}

TGPoint *TGeomObject::SliceCutByPlane2d(int index, TGCut *&rc1, TGCut *&rc2)
{
	if (index>=FCuts.Count)
		return NULL;
	return SliceCutByPlane2d(FCuts.Items[index], rc1, rc2);
}


//////////////////////
//		Common		//
//////////////////////

void TGeomObject::DetectHoles2d(TMTList<TGPolygon> &poly)
{
	TMDelTList<TMDelTList<int> > matrix;
	for (int i=0;i<poly.Count;i++)
	{
		matrix.Add(new TMDelTList<int>);
		for (int j=0;j<poly.Count;j++)
			matrix.Last()->Add(new int(0));
	}	
	for (int i=0;i<matrix.Count;i++)
		for (int j=0;j<matrix[i].Count;j++)
			if (i!=j)
			{
				matrix[i][j] = (poly[j].PolygonInPolygon2d(poly[i], PEPS) == pipINSIDE) ? 1 : 0;
//				int mmm = 1;
			}	
			else
				matrix[i][j] = -1;
			
	for (int i=0;i<matrix.Count;i++)
	{
		int max = 0;
		int best = -1;
		
		for (int j=0;j<matrix[i].Count;j++)
			if (matrix[i][j] == 1)
			{
				int counter = 0;
				for (int k=0;k<matrix[j].Count;k++)
					if (matrix[j][k] == 1)
						counter++;
				if (best == -1 || counter>max)
				{
					max = counter;
					best = j;
				}	
			}
		if (best!=-1)
		{
			poly[best].FHoles.Add(poly.Items[i]);
			poly[i].FParent = poly.Items[best];
			FillCutsFlags(poly[i].FCuts, flHOLE, gfTRUE);
			FPolygons.RemoveOnly(poly.Items[i]);
		}	
	}	

	for(int i=0;i<FPolygons.Count;i++)
		if (FPolygons[i].IsHoled())	
			for (int j=0;j<FPolygons[i].FHoles.Count;j++)
				if(FPolygons[i].FHoles[j].IsHoled())
					for (int k=0;k<FPolygons[i].FHoles[j].FHoles.Count;k++)
					{
						FPolygons.Add(FPolygons[i].FHoles[j].FHoles.Items[k]);
						FPolygons[i].FHoles[j].FHoles.RemoveOnly(k--);
					}
}

void TGeomObject::DetectHolesCreatePolygons2d(TMTList<TGPolygon> &poly)
{
	TMDelTList<TMDelTList<int> > matrix;
	for (int i=0;i<poly.Count;i++)
	{
		matrix.Add(new TMDelTList<int>);
		for (int j=0;j<poly.Count;j++)
			matrix.Last()->Add(new int(0));
	}	
	for (int i=0;i<matrix.Count;i++)
		for (int j=0;j<matrix[i].Count;j++)
			if (i!=j)
				matrix[i][j] = (poly[j].PolygonInPolygon2d(poly[i], PEPS) == pipINSIDE) ? 1 : 0;
			else
				matrix[i][j] = -1;
			
	for (int i=0;i<matrix.Count;i++)
	{
		int max = 0;
		int best = -1;
		
		for (int j=0;j<matrix[i].Count;j++)
			if (matrix[i][j] == 1)
			{
				int counter = 0;
				for (int k=0;k<matrix[j].Count;k++)
					if (matrix[j][k] == 1)
						counter++;
				if (best == -1 || counter>max)
				{
					max = counter;
					best = j;
				}	
			}
		if (best!=-1)
			poly[best].AddHole(poly[i].FCuts);
	}	
}

void TGeomObject::SplitByPlane(const TIntVec &n, const TIntVec &o)
{
	FillCutsFlags(flINTERSECT, gfFALSE);
	TMTList<TGPolygon> pols;
	pols.Assign(&FPolygons);
	TMTList <TGPolygon> Result;

	for (int i = 0;i<pols.Count;i++)
		SplitPolygonByPlane(pols.Items[i], n, o, Result);

}

void TGeomObject::SliceByPlane(const TIntVec &n, const TIntVec &o)
{
	SplitByPlane(n, o);
	
	ClassifyPolygons(n, o, PEPS/**100*/);

	TMTList <TGPolygon> toDel;
	for (int i = 0;i<FPolygons.Count;i++)
		if (FPolygons[i].FFlags.Origin == gfNEGATIVE || FPolygons[i].FFlags.Origin == gfCOLLINEAR)
			toDel.Add(FPolygons.Items[i]);

	ClassifySolid();

	TMTList <TGCut> cuts;

	for (int i=0;i<FCuts.Count;i++)
		if ((FCuts[i].FFlags.Intersect == gfTRUE) && FCuts[i].Left && FCuts[i].Left->FFlags.Solid)
			cuts.Add(FCuts.Items[i]);

	TMDelTList< TMTList<TGCut> > polyCut; 
	MBTi AngX, AngY;
	TransformToPlane(n*(-1), AngX, AngY);
//	ProcessCrossCuts2d(cuts);
	Polygonize2d(cuts, polyCut);
	TransformBack(AngX, AngY);
	for (int i=0;i<polyCut.Count;i++)
	{
		bool toDel = true;
		for (int j=0;j<polyCut[i].Count;j++)
		{
			bool last = false;
			bool res = true;
			int cnt = 0;
			for (int k=0;k<polyCut[i][j].FPlane.Count;k++)
				if (polyCut[i][j].FPlane.Items[k])
				{
					cnt++;
					if (!k)
					{
						last = (polyCut[i][j].FPlane[k].FFlags.Origin  == gfPOSITIVE);
					}
					else if ( (polyCut[i][j].FPlane[k].FFlags.Origin  == gfPOSITIVE) != last )
					{
						res = false;
						break;
					}
				}	
			if (!res || cnt<2)
			{
				toDel = false;
				break;
			}	
		}
		if (toDel)
			polyCut.Delete(i--);
	}	

	for (int i = 0;i<toDel.Count;i++)
		FPolygons.Remove(toDel.Items[i]);
			
	
	TMTList<TGPolygon> poly;
	for (int i=0;i<polyCut.Count;i++)
		poly.Add( AddPolygon(polyCut[i]) );

	DetectHoles2d(poly);	
	
	FreeUnused(fuAll);
}

void TGeomObject::SliceByPlaneNoSplit(const TIntVec &n, const TIntVec &o)
{
	
	ClassifyPolygons(n, o, PEPS/**100*/);

	TMTList <TGPolygon> toDel;
	for (int i = 0;i<FPolygons.Count;i++)
		if (FPolygons[i].FFlags.Origin == gfNEGATIVE || FPolygons[i].FFlags.Origin == gfCOLLINEAR/* || FPolygons[i].FFlags.Origin == gfINTERSECT*/)
			toDel.Add(FPolygons.Items[i]);

	for (int i = 0;i<toDel.Count;i++)
		FPolygons.Remove(toDel.Items[i]);

	FreeUnused(fuAll);
}


//////////////////////
//	Intersect		//
//////////////////////

// p1 из *this
// p2 из Other
int TimeForTransform = 0;
int TimeForIntersect = 0;
int TimeForDetect = 0;
int TimeForSplit = 0;
int TimeForPolygonize = 0;
int TimeTotalIntersect = 0;
int TimeTotal = 0;
int TimeTotalSplit = 0;

/*TGPoint *GetTwPnt(TMTwinElement<TGPoint*, TGPoint*> &el)
{
	if (el.Data)
		return el.Data;
	if (el.Target)
		return el.Target;
	return NULL;	
} */

class TGIntPoint
{
public:
	TIntVec		Point;

	TGCut		*Cut;
	TGPolygon	*Poly;

	TGPoint 	*Target;

	TGIntPoint()
	{
		Target	= NULL;
		Poly	= NULL;
		Cut		= NULL;
	}

	TGIntPoint(const TGIntPoint &point)
	{
		Target	= point.Target;
		Poly	= point.Poly;
		Cut		= point.Cut;
		Point	= point.Point;
	}

	TGIntPoint(const TIntVec &point, TGCut *cut, TGPolygon *poly)
	{
		Target	= NULL;
		Poly	= poly;
		Cut		= cut;
		Point	= point;
	}

	bool Equals(const TGIntPoint &other) const
	{
		return (other.Cut == Cut) && (other.Poly == Poly);
	}
};

class TGIntCut
{
public:
	TGIntPoint	*Src;
	TGIntPoint	*Dst;
	TGIntCut()
	{
		Src = NULL;
		Dst = NULL;
	}
	TGIntCut(const TGIntCut& cut)
	{
		Src = cut.Src;
		Dst = cut.Dst;
	}
	TGIntCut(TGIntPoint *src, TGIntPoint *dst)
	{
		Src = src;
		Dst = dst;
	}
};

bool TGeomObject::PlanePolygonIntersect(TGPolygon *plane, TGPolygon *p, TMDelTList <TGIntPoint> &cps)
{
	cps.Clear();
	// Разрезаем отрезки плоскостью другого полигона
	for (int i=0;i<p->FCuts.Count;i++)
	{
		TIntVec it;
		if (PlaneCutCross(plane->Normal, plane->Origin, p->FCuts[i].Src->Point, p->FCuts[i].Dst->Point, it, PEPS))
			cps.Add(new TGIntPoint(it, p->FCuts.Items[i], plane));
	}

	//Разрезаем дырки полигона плоскостью другого полигона
	for (int i=0;i<p->FHoles.Count;i++)
	{
		// Разрезаем отрезки дырки
		for (int j=0;j<p->FHoles[i].FCuts.Count;j++)
		{
			TIntVec it;
			if (PlaneCutCross(plane->Normal, plane->Origin, p->FHoles[i].FCuts[j].Src->Point, p->FHoles[i].FCuts[j].Dst->Point, it, PEPS))
				cps.Add(new TGIntPoint(it, p->FHoles[i].FCuts.Items[i], plane));
		}
	}
	return true;
}

bool TGeomObject::IntersectPolygons(TGPolygon *p1, TGPolygon *p2, TMDelTList <TGIntCut> &r1, TMDelTList <TGIntCut> &r2, TMDelTList <TGIntPoint> &pnt)
{
	TIntVec dir, org;

	r1.Clear();
	r2.Clear();
	pnt.Clear();
	if (!PlanePlaneCross(p1->Normal, p1->Origin, p2->Normal, p2->Origin, dir, org, PEPS)) 
		return false;

	TMDelTList <TGIntPoint> cp;
	TMTList <TGPoint> cps;

	PlanePolygonIntersect(p1, p2, pnt);
/*	for (int i=0;i<cp.Count;i++)
		cps.Add(AddPoint(cp[i].Point));
*/  
	PlanePolygonIntersect(p2, p1, cp);

	for (int i=0;i<cp.Count;i++)
		pnt.Add( new TGIntPoint(cp[i]));
/*	for (int i=0;i<cp.Count;i++)
		cps.Add(AddPoint(cp[i].Point));


	for (int i=0;i<cps.Count;i++)	
		for (int j=i+1;j<cps.Count;j++)
			if (DistancePointPlane(cps[i].Point, dir, cps[j].Point)>0)
				cps.Exchange(i, j);

	for (int i=0;i<cps.Count-1;i++)
		AddCut(cps.Items[i], cps.Items[i+1])->FFlags.Intersect = gfTRUE;
*/
/*
	TMTList <TMyObject> toTransform1;
	TMTList <TMyObject> toTransform2;

	toTransform1.Add(p1);
	toTransform2.Add(p2);

	MBTi AngX1, AngY1, AngZ1;
	MBTi AngX2, AngY2, AngZ2;

	TransformMove(toTransform1, TIntVec(0,0,0) - org, false);
	TransformMove(toTransform2, TIntVec(0,0,0) - org, true);

	TransformToPlaneAndOX(toTransform1, p1->Normal, dir, AngX1, AngY1, AngZ1, false);
	TransformToPlaneAndOX(toTransform2, p2->Normal, dir, AngX2, AngY2, AngZ2, true);

	if ((p1->GetLowestPoint2d()->Point.y>PEPS)||(p1->GetHighestPoint2d()->Point.y<-PEPS) ||
		(p2->GetLowestPoint2d()->Point.y>PEPS)||(p2->GetHighestPoint2d()->Point.y<-PEPS))
		return false;

	
	TMTList <TGCut> cuts;			// буффер отрезков полигонов
	TMDelTList <TGPolygon> holes;	// дырки....
	TMTList < TGPoint > cps;

	// запоминаем отрезки первого полигона
	cuts.Assign(&p1->FCuts);		

	// Разрезаем отрезки плоскостью другого полигона
	for (int i=0;i<cuts.Count;i++)
	{
		TGCut *r1, *r2;
		TGPoint *cp = SliceCutByPlane2d(cuts.Items[i], r1, r2);
		
		if (cp)
			cps.Add(cp);
	}

	//Разрезаем дырки полигона плоскостью другого полигона
	for (int i=0;i<p1->FHoles.Count;i++)
	{
		TMTList <TGCut> cuts;
		//Запоминаем отрезки дырки
		cuts.Assign(&p1->FHoles[i].FCuts);

		// Разрезаем отрезки дырки
		for (int j=0;j<cuts.Count;j++)
		{
			TGCut *r1, *r2;
			TGPoint *cp = SliceCutByPlane2d(cuts.Items[j], r1, r2);
			if (cp)
				cps.Add(cp);
		}
	}

	// запоминаем отрезки воторого полигона  
	cuts.Assign(&p2->FCuts);

	// пересекаем отрезки с плоскостью другого полигона
	for (int i=0;i<cuts.Count;i++)
	{
		TGCut *r1, *r2;
		TGPoint *cp = SliceCutByPlane2d(cuts.Items[i], r1, r2);
		if (cp)
			cps.Add(cp);
	}

	//Разрезаем дырки полигона плоскостью другого полигона
	for (int i=0;i<p2->FHoles.Count;i++)
	{
		TMTList <TGCut> cuts;
		//Запоминаем отрезки дырки
		cuts.Assign(&p2->FHoles[i].FCuts);

		// Разрезаем отрезки дырки        
		for (int j=0;j<cuts.Count;j++)
		{
			TGCut *r1, *r2;
			TGPoint *cp = SliceCutByPlane2d(cuts.Items[j], r1, r2);
			if (cp)
				cps.Add(cp);
		}
	}

	// Сортируем точки рассечения
	for (int i=0;i<cps.Count;i++)
		for (int j=i+1;j<cps.Count;j++)
			if (cps[i].Point.x>cps[j].Point.x)
				cps.Exchange(i,j);

	// Удаляем повторные точки рассечения
	for (int i=0;i<cps.Count;i++)
		if (cps.Items[i] == cps.CycleItems[i+1])
				cps.Delete(i--);

	if (cps.Count<2)
		return false;
  
	// Индексный буффер общих отрезков

	TMDelTList < int > intCut1;
	TMDelTList < int > intCut2;

	int borCount1 = 0;
	int borCount2 = 0;

	// Находим общие отрезки
	for (int i=0;i<cps.Count-1;i++)
	{
		// Принадлежность отрезков полигонам
		// Эпсилон принадлежности должен быть в несколько раз меньше эпсилона точек
		TIntVec mid = (cps[i].Point + cps[i+1].Point)/2.0;
		MBTi PEPS_3 = PEPS/4.0;
		
		int a = p1->PointInPolygon2d( mid, PEPS_3);
		int a2 = p2->PointInPolygon2d( mid, PEPS_3);

		int ah = p1->PointInPolygon_UseHoles2d( mid, PEPS_3);
		int ah2 = p2->PointInPolygon_UseHoles2d( mid, PEPS_3);

		// Если отрезок принадлежит обоим полигонам, добавляем общий отрезок
		if ((a == pipINSIDE || a == pipBOUNDARY) && (a2 == pipINSIDE || a2 == pipBOUNDARY))
		{
			if (ah2 != pipOUTSIDE)
			{
				if ((a == pipBOUNDARY || ah == pipHOLEBOUNDARY || a2 == pipBOUNDARY || ah2 == pipHOLEBOUNDARY))
				{
					intCut1.Insert(0, new int(i) );
					borCount1++;
				}	
				else	
					intCut1.Add(new int(i) );
			}	

			if (ah != pipOUTSIDE)
			{
				if ((a2 == pipBOUNDARY || ah2 == pipHOLEBOUNDARY || a == pipBOUNDARY || ah == pipHOLEBOUNDARY))
				{
					intCut2.Insert(0, new int(i) );
					borCount2++;
				}
				else	
					intCut2.Add(new int(i) );
			}	
		}	
	}

	for (int i=0;i<intCut1.Count;i++)
	{
		TGCut *ct = AddCut(cps.Items[intCut1[i]], cps.Items[intCut1[i]+1]);
		r1.Add(ct);
		r1.Last()->FFlags.Intersect = gfTRUE;
//		r1.Last()->FFlags.Boundary = (i<borCount1) ? gfTRUE : gfFALSE; 
		r1.Last()->FFlags.Same = (r1.Last()->Dst->Point.x - r1.Last()->Src->Point.x > 0) ? gfTRUE : gfFALSE;
	}
	for (int i=0;i<intCut2.Count;i++)
	{
		TGCut *ct = AddCut(cps.Items[intCut2[i]], cps.Items[intCut2[i]+1]);
		r2.Add(ct);
		r2.Last()->FFlags.Intersect = gfTRUE;
//		r2.Last()->FFlags.Boundary = (i<borCount2) ? gfTRUE : gfFALSE; 
		r2.Last()->FFlags.Same = (r2.Last()->Dst->Point.x - r2.Last()->Src->Point.x > 0) ? gfFALSE : gfTRUE;
	}

	// Возвращаем полигоны с плоскости

//	TransformBack(toTransform2, dir, AngX2, AngY2, AngZ2, false);
//	TransformBack(toTransform1, dir, AngX1, AngY1, AngZ1, true);

//	toTransform1.Assign(&r1);
//	toTransform2.Assign(&r2);

	TransformBack(toTransform2, dir, AngX2, AngY2, AngZ2, false);
	TransformBack(toTransform1, dir, AngX1, AngY1, AngZ1, true);

	TransformMove(toTransform2, org, false);
	TransformMove(toTransform1, org, true);
*/
	
	return true;
}
void TGeomObject::FillPolygonsOriginInIntersectionRecursive(TGPolygon *p, TClassify state)
{
	if (p->FFlags.Mark == gfTRUE)
		return;
		
	p->FFlags.Origin = state;
	p->FFlags.Mark = gfTRUE;

	bool borderParent = true;
	if (p->FParent && p->FParent->FFlags.Mark == gfFALSE)
	{
		bool hasIntersect = false;
		for (int i=0;i<p->FCuts.Count;i++)
		{
			borderParent = true;
			int count = 0;
			for (int j=0;j<p->FParent->FHoles.Count;j++)
				if (p->FCuts[i].FPlane.IndexOf(p->FParent->FHoles.Items[j])!=-1)
				{
					count++;
					if (count>1)
					{
						borderParent = false;
						break;
					}	
				}	
			if (borderParent)
			{
				hasIntersect = p->FCuts[i].Flags.Intersect == gfTRUE;
				break;
			}
		}
		if (borderParent)
		{
			TClassify newState = (!hasIntersect) ? state : (state == gfPOSITIVE) ? gfNEGATIVE : gfPOSITIVE;
			FillPolygonsOriginInIntersectionRecursive(p->FParent,  newState);
		}	
	}
	
		
	for (int k=0;k<p->FHoles.Count;k++)
		if (p->FHoles[k].FFlags.Mark == gfFALSE)
		{
			bool hasIntersect = false;
			for (int i=0;i<p->FHoles[k].FCuts.Count;i++)
			{
				int count = 0;
				borderParent = true;
				for (int j=0;j<p->FHoles.Count;j++)
					if (p->FHoles[k].FCuts[i].FPlane.IndexOf(p->FHoles.Items[j])!=-1)
					{
						count++;
						if (count>1)
						{
							borderParent = false;
							break;
						}	
					}	
				if (borderParent)
				{
					hasIntersect = p->FHoles[k].FCuts[i].Flags.Intersect == gfTRUE;
					break;
				}         
			}
			if (borderParent && !hasIntersect)
			{
				TClassify newState = (!hasIntersect) ? state : (state == gfPOSITIVE) ? gfNEGATIVE : gfPOSITIVE;
				FillPolygonsOriginInIntersectionRecursive(p->FHoles.Items[k],  newState);
			}
		}	
		
	for(int i=0;i<p->FCuts.Count;i++)
	{
		if (p->FCuts[i].Flags.Intersect == gfFALSE)// && p->FCuts[i].Flags.Mark == gfFALSE
		{
			for (int j=0;j<p->FCuts[i].FPlane.Count;j++)
				if (p->FCuts[i].FPlane.Items[j] && p->FCuts[i].FPlane.Items[j] != p)
				{
					TGPolygon *another = p->FCuts[i].FPlane.Items[j];
					if (another->Flags.Mark == gfFALSE)
						FillPolygonsOriginInIntersectionRecursive(another, state);
				}	
		}
	}	
}
void TGeomObject::FillPolygonsOriginInBorders(TGPolygon *p, TClassify state)
{
//	enterCnt = 0;
	FillCutsFlags(flMARK, gfFALSE);
	FillPolygonsOriginInIntersectionRecursive(p, state);
}


void TGeomObject::ClassifyPolygonsByIntersectBorderRecursive(TGCut *cut)
{	
/*	if(cut->FFlags.Hole == gfTRUE)
		return;
*/		
	cut->FFlags.Mark = gfTRUE;
	TGPoint *src = (cut->Flags.Same) ? cut->Src : cut->Dst;
	TGPoint *dst = (cut->Flags.Same) ? cut->Dst : cut->Src;
//	TGPolygon *left		= cut->Left;
//	TGPolygon *right	= cut->Right; 

	TGPoint *common;	
		
	for (int x=0;x<cut->FPlane.Count;++x)
		if (cut->FPlane.Items[x])
//			if (cut->FPlane[x].Flags.Mark == gfFALSE)
				for (int i=0;i != cut->FPlane[x].Count ; i ++ )
					if ( (cut != cut->FPlane[x].FCuts.Items[i]) && ((common = cut->FPlane[x].FCuts[i].CanConnect(*cut)) != NULL))
					{
						 bool cut_Is_Next = ( cut == cut->FPlane[x].FCuts.CycleItems[i+1] );
						 bool Pol_Is_Blue =  cut_Is_Next && (src == common) || 
											!cut_Is_Next && (dst == common); 

						FillPolygonsOriginInBorders(cut->FPlane.Items[x], (Pol_Is_Blue)? gfPOSITIVE : gfNEGATIVE);
					} 
}

void TGeomObject::ClassifyPolygonsByIntersectBorder()
{
	FillCutsFlags(flORIGIN, gfUNDEFINED);
	FillCutsFlags(flMARK, gfFALSE);
	FillPolygonsFlags(flORIGIN, gfUNDEFINED);
	FillPolygonsFlags(flMARK, gfFALSE);

	for (int i=0;i<FCuts.Count;i++)
		if (FCuts[i].Flags.Intersect == gfTRUE && FCuts[i].Flags.Boundary == gfFALSE)
			ClassifyPolygonsByIntersectBorderRecursive(FCuts.Items[i]);
}


void TGeomObject::SolidObjectsBoolean(TGBoolean op, TGeomObject &obj, TGeomObject &result)
{                                   

////////////////
//	Данные
////////////////

	// Соотвестствие полигонов и отрезков пересечения
	TMDelTList < TMTwinElement < TMTList < TGCut >, TGPolygon *> > pl1; 
	TMDelTList < TMTwinElement < TMTList < TGCut >, TGPolygon *> > pl2; 

	// отрезки пересечения
	TMDelTList <TGIntCut>  split1;
	TMDelTList <TGIntCut>  split2;
	TMDelTList <TGIntPoint>  splitPnt;

	// Обьект, в котором производятся пересечения полигонов
	TGeomObject temp;
	// Обьект - хранилище отрезков шва пересечения обьектов
	TGeomObject intersection;

///////////////
// Подготовка
///////////////

	result.Clear();
	result.SnapPoints = false;

//	result.assign(this);
//	result.append(obj);

	// Инициализируем списки соответствия
	for (int i=0;i<FPolygons.Count;i++)
	{
		pl1.Add(new TMTwinElement < TMTList < TGCut >, TGPolygon *>);
		pl1.Last()->Target = result.CopyPolygonToObject(FPolygons[i]);
	}
	
	for (int i=0;i<obj.FPolygons.Count;i++)
	{
		pl2.Add(new TMTwinElement < TMTList < TGCut >, TGPolygon *>);
		pl2.Last()->Target = result.CopyPolygonToObject(obj.FPolygons[i]);
	}

///////////////////////////	
//	Настройка обьектов
///////////////////////////	

	//	Отключение привязок точек в temp
	//	Тем не менее, привязка шва к отрезку будет осуществляться внутри функции SliceCutByPlane2d
	temp.SnapPoints = false;

	//	Включение опции улавливания шва по шву по критерию наиболее ближних точек
	intersection.SnapPointsToNearest = true;
	
	
//////////////////	
// Пересечение
//////////////////

	for (int i=0;i<pl1.Count;i++)
		for (int j=0;j<pl2.Count;j++)	
		{
//			temp.Clear();

			// коприрование двух пересекаемых полигонов в temp
			TGPolygon *p1 = pl1[i].Target;
			TGPolygon *p2 = pl2[j].Target;

			// Если произошло пересечение - добавить отрезки шва
			TMDelTList <TGIntPoint> spPnt;
			if (result.IntersectPolygons(p1, p2, split1, split2, spPnt));

			for (int i=0;i<spPnt.Count;i++)
				splitPnt.Add( new TGIntPoint(spPnt[i]));

/*			{
				for (int k=0;k<split1.Count;k++)
				{
					// Копируем отрезок в Intersect
					TGCut *ct = intersection.CopyCutToObject(split1[k]);
					
					// Если его нет в списке принадлежностей и он не свернулся в точку, добавляем его
					if (ct && pl1[i].Data.IndexOf(ct) == -1)	
						pl1[i].Data.Add(ct);
				}	

				for (int k=0;k<split2.Count;k++)
				{
					// Копируем отрезок в Intersect
					TGCut *ct = intersection.CopyCutToObject(split2[k]);

					// Если его нет в списке принадлежностей и он не свернулся в точку, добавляем его
					if (ct && pl2[j].Data.IndexOf(ct) == -1)	
						pl2[j].Data.Add(ct);
				}
			 
			}*/
		}
//////////////////
// Обьединение
//////////////////
	for (int i=0;i<splitPnt.Count;i++)
	{
		int	found = -1;
		for (int j=0;j<i;j++)
			if (splitPnt[i].Equals(splitPnt[j]))
			{
				found = j;
				break;
			}
		if (found != -1)
			splitPnt[i].Target = splitPnt[found].Target;
		else
			splitPnt[i].Target = result.AddPoint(splitPnt[i].Point);
	}	

/*
	TGeomObject o1;
	TGeomObject o2;

	o1.SnapPointsToNearest = true;
	o2.SnapPointsToNearest = true;
	result.SnapPointsToNearest = true;

	o1.CopyCutsToObject(intersection);
	o2.CopyCutsToObject(intersection);

	o1.CopyPolygonsToObject(*this);
	o2.CopyPolygonsToObject(obj);

	result.Clear();
	result.CopyCutsToObject(intersection);

	result.CopyPolygonsToObject(o1);
	result.CopyPolygonsToObject(o2);
/*	
	
	
	TMTList<TGCut> cuts;

	TMTList <TGPoint> pnts;
	pnts.Assign(&result.FVertex);
	

	result.Clear();
	result.SnapPointsToNearest = true;
	for (int i=0;i<pnts.Count;i++)
	{
		cuts.Assign(&result.FCuts);
		for (int j=0;j<cuts.Count;j++)
			if (!cuts[j].ConsistsPoint(pnts.Items[i]) && CutConsistsPoint(pnts[i].Point, cuts[j].Src->Point, cuts[j].Dst->Point, PEPS))
			{
				TGCut *c1, *c2;
				TGCut *old = cuts.Items[j];
				result.SplitCut(cuts.Items[j], pnts.Items[i], c1, c2);

			}
	}

	for (int i=0;i<result.FPolygons.Count;i++)
		if (result.StructureFix(result.FPolygons.Items[i], sfxREMOVE_REPEATED | sfxREMOVE_BRANCHES))
			result.FPolygons[i].CalculatePlane();


//	result.SnapPoints = false;

	pnts.Assign(&result.FVertex);
//	tmp.Assign(&result.FVertex);

	TMTList <TGCut> tmpCuts;
	tmpCuts.Assign(&result.FCuts);

	for (int i=0;i<pl1.Count;i++)
		for (int j=0;j<pl1[i].Data.Count;j++)
		{
			TGCut *c = result.CopyCutToObject(pl1[i].Data[j]);
			if (c)
				pl1[i].Data.Items[j] = c;
			else
				pl1[i].Data.Delete(j--);	
		}	

	for (int i=0;i<pl2.Count;i++)
		for (int j=0;j<pl2[i].Data.Count;j++)
		{
			TGCut *c = result.CopyCutToObject(pl2[i].Data[j]);
			if (c)
				pl2[i].Data.Items[j] = c;
			else
				pl2[i].Data.Delete(j--);	
		}	

	TMTList <TGPoint> tmpIntPnts;
	tmpIntPnts.Assign(&result.FVertex);
	
	TMTListSub(tmpIntPnts, pnts);
			
// Касание отрезков
	for (int i=0;i<pnts.Count;i++)
	{
		cuts.Assign(&result.FCuts);
		for (int j=0;j<cuts.Count;j++)
			if (!cuts[j].ConsistsPoint(pnts.Items[i]) && CutConsistsPoint(pnts[i].Point, cuts[j].Src->Point, cuts[j].Dst->Point, PEPS))
			{
				TGCut *c1, *c2;
				TGCut *old = cuts.Items[j];
				result.SplitCut(cuts.Items[j], pnts.Items[i], c1, c2);

				for (int k=0;k<pl1.Count;k++)
				{
					int n = -1;
					while ((n = pl1[k].Data.IndexOf(old)) != -1)
					{
						pl1[k].Data.Delete(n);
						pl1[k].Data.Insert(n, c1);
						pl1[k].Data.Insert(n, c2);
					}	
				}	
				for (int k=0;k<pl2.Count;k++)
				{
					int n = -1;
					while ((n = pl2[k].Data.IndexOf(old)) != -1)
					{
						pl2[k].Data.Delete(n);
						pl2[k].Data.Insert(n, c1);
						pl2[k].Data.Insert(n, c2);
					}	
				}	    
			}
	}
/*	pnts.Assign(&tmpIntPnts);
	for (int i=0;i<pnts.Count;i++)
	{
		cuts.Assign(&result.FCuts);
		for (int j=0;j<cuts.Count;j++)
			if (!cuts[j].ConsistsPoint(pnts.Items[i]) && CutConsistsPoint(pnts[i].Point, cuts[j].Src->Point, cuts[j].Dst->Point, PEPS))
			{
				TGCut *c1, *c2;
				TGCut *old = cuts.Items[j];
				result.SplitCut(cuts.Items[j], pnts.Items[i], c1, c2);

				for (int k=0;k<pl1.Count;k++)
				{
					int n = -1;
					while ((n = pl1[k].Data.IndexOf(old)) != -1)
					{
						pl1[k].Data.Delete(n);
						pl1[k].Data.Insert(n, c1);
						pl1[k].Data.Insert(n, c2);
					}	
				}	
				for (int k=0;k<pl2.Count;k++)
				{
					int n = -1;
					while ((n = pl2[k].Data.IndexOf(old)) != -1)
					{
						pl2[k].Data.Delete(n);
						pl2[k].Data.Insert(n, c1);
						pl2[k].Data.Insert(n, c2);
					}	
				}	    
			}
	}
	
/**************************************************************************************/
/*	for (int i=0;i<pl1.Count;i++)
		for (int j=0;j<pl1[i].Data.Count;j++)
			if (result.FCuts.IndexOf(pl1[i].Data.Items[j]) != -1 && pl1[i].Data[j].Used())
				pl1[i].Data[j].FFlags.Boundary = gfTRUE; 

	for (int i=0;i<pl2.Count;i++)
		for (int j=0;j<pl2[i].Data.Count;j++)
			if (result.FCuts.IndexOf(pl2[i].Data.Items[j]) != -1 && pl2[i].Data[j].Used())
				pl2[i].Data[j].FFlags.Boundary = gfTRUE; 
/**************************************************************************************/
/*
	result.SnapPointsToNearest = false;

	for (int i=0;i<pl1.Count;i++)
	{
		MBTi AngX, AngY;
		TMTList < TMyObject > toTransform;

		TMTListAdd(toTransform, (TMTList <TMyObject> &)pl1[i].Target->FCuts);
		
		for (int j=0;j<pl1[i].Target->FHoles.Count;j++)
			TMTListAdd(toTransform, (TMTList <TMyObject> &)pl1[i].Target->FHoles[j].FCuts);

		for (int j=0;j<pl1[i].Data.Count;j++)
			toTransform.Add(pl1[i].Data.Items[j]);

			
		result.TransformToPlane(pl1[i].Target->Normal, toTransform, AngX, AngY);
		
		TMTList < TGPolygon > Result;
//		pl1[i].Target->CalculatePlane();
		result.SplitPolygon(pl1[i].Target, pl1[i].Data, Result);
		
		result.TransformBack((TMTList <TMyObject>&)toTransform, AngX, AngY);
	}

	for (int i=0;i<pl2.Count;i++)
	{
		MBTi AngX, AngY;
		TMTList < TMyObject > toTransform;

		TMTListAdd(toTransform, (TMTList <TMyObject> &)pl2[i].Target->FCuts);

		for (int j=0;j<pl2[i].Target->FHoles.Count;j++)
			TMTListAdd(toTransform, (TMTList <TMyObject> &)pl2[i].Target->FHoles[j].FCuts);
			
	
		for (int j=0;j<pl2[i].Data.Count;j++)
			toTransform.Add(pl2[i].Data.Items[j]);
			
		result.TransformToPlane(pl2[i].Target->Normal, toTransform, AngX, AngY);

		TMTList < TGPolygon > Result;
		result.SplitPolygon(pl2[i].Target, pl2[i].Data, Result);
 
		result.TransformBack((TMTList <TMyObject>&)toTransform, AngX, AngY);
	} 
	
/*
	TGeomObject go;
	for (int i=0;i<pl1.Count;i++)
	{
		temp.Clear();

		MBTi AngX, AngY;
		TMTList < TMyObject > toTransform;

		TMTListAdd(toTransform, (TMTList <TMyObject> &)pl1[i].Target->FCuts);
		
		for (int j=0;j<pl1[i].Target->FHoles.Count;j++)
			TMTListAdd(toTransform, (TMTList <TMyObject> &)pl1[i].Target->FHoles[j].FCuts);

		for (int j=0;j<pl1[i].Data.Count;j++)
			toTransform.Add(pl1[i].Data.Items[j]);
  
		TGPolygon *p = temp.CopyPoligonToObject(*pl1[i].Target);
			
		result.TransformToPlane(pl1[i].Target->Normal, toTransform, AngX, AngY);
		
		TMTList < TGPolygon > Result;
		result.SplitPolygon(pl1[i].Target, pl1[i].Data, Result);
		
		result.TransformBack((TMTList <TMyObject>&)toTransform, AngX, AngY);
	}

	for (int i=0;i<pl2.Count;i++)
	{
		MBTi AngX, AngY;
		TMTList < TMyObject > toTransform;

		TMTListAdd(toTransform, (TMTList <TMyObject> &)pl2[i].Target->FCuts);

		for (int j=0;j<pl2[i].Target->FHoles.Count;j++)
			TMTListAdd(toTransform, (TMTList <TMyObject> &)pl2[i].Target->FHoles[j].FCuts);
			
	
		for (int j=0;j<pl2[i].Data.Count;j++)
			toTransform.Add(pl2[i].Data.Items[j]);
			
		result.TransformToPlane(pl2[i].Target->Normal, toTransform, AngX, AngY);

		TMTList < TGPolygon > Result;
		result.SplitPolygon(pl2[i].Target, pl2[i].Data, Result);
 
		result.TransformBack((TMTList <TMyObject>&)toTransform, AngX, AngY);
	} 

*/	
//	obj.SynchronizePolygonsWises();
//	SynchronizePolygonsWises();
//	obj.ClassifyPolygonsByIntersectBorder();
//	result.FreeUnused(fuAll);

////////////////////////////////////////////////////			
//	result.ClassifyPolygonsByIntersectBorder();
////////////////////////////////////////////////////			

	
//	result.SolidCheck();
//	TimeTotalSplit = GetTickCount() - ttStart;
/*
	result.Clear();
	if (op == gbSPLIT)
	{
		for (int i=0;i<FPolygons.Count;i++)	
				TGPolygon *p = result.CopyPolygonToObject(FPolygons[i]);

		for (int i=0;i<obj.FPolygons.Count;i++)	
			TGPolygon *p = result.CopyPolygonToObject(obj.FPolygons[i]);
	}
	else
	{
		TClassify aTake = 
			 (op == gbA_MINUS_B || op == gbUNION) 
				? gfPOSITIVE :
			 (op == gbB_MINUS_A || op == gbINTERSECTION) 
				? gfNEGATIVE 
				: gfPOSITIVE;

		TClassify bTake = 
			(op == gbA_MINUS_B || op == gbINTERSECTION) 
				? gfNEGATIVE :
			(op == gbB_MINUS_A || op == gbUNION)
				? gfPOSITIVE
				: gfPOSITIVE;
							  
		bool aFlip = op == gbB_MINUS_A;
		bool bFlip = op == gbA_MINUS_B;
						
		for (int i=0;i<FPolygons.Count;i++)	
			if (FPolygons[i].Flags.Origin == aTake)
			{
				TGPolygon *p = result.CopyPolygonToObject(FPolygons[i]);
				if (aFlip)
					p->Invert();
				
			}	

		for (int i=0;i<obj.FPolygons.Count;i++)	
			if (obj.FPolygons[i].Flags.Origin == bTake)
			{
				TGPolygon *p = result.CopyPolygonToObject(obj.FPolygons[i]);
				if (bFlip)
					p->Invert();
			}
	}	
//	obj.CalculateNormals();	
//	CalculateNormals();	*/
//	result.FreeUnused(fuAll);
}

