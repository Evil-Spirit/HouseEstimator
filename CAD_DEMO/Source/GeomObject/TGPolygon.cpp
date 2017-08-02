#include <vcl.h>                           
#include "Usefuls.h"  
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"                                    
#include "MathV.h"
#pragma hdrstop

#include "TGObject.h"

#include "MYGL.h"
#include "Poligon.h"
#pragma package(smart_init)

TClassNode* TGPolygon::StaticType = NULL;

const AnsiString aPOLYTAG("Tag");
const AnsiString aNORMAL("Nrm");
const AnsiString aORIGIN("Org");
const AnsiString aHOLES("Hls");
const AnsiString aFLAGS("Flg");

const AnsiString aBBoxCenter("BBoxCenter");
const AnsiString aBBoxLengthDiv2("BBoxLengthDiv2");

TIntVec BBoxCenter;
TIntVec BBoxLengthDiv2;

TGPolygon::TGPolygon()
{
	RegisterNewClass< TGUnit, TGPolygon >(this, false, &CreateFunction);
	RegisterField(&Tag, &aPOLYTAG, mtInt);
	RegisterField(&FNormal, &aNORMAL, mtIntVec);
	RegisterField(&FHoles, &aHOLES, mtMyObject);

	RegisterField(&FFlags, &aFLAGS, mtInt);	//Debug!
	
//Drive
	RegisterField(&BBoxCenter, &aBBoxCenter, mtIntVec);
	RegisterField(&BBoxLengthDiv2, &aBBoxLengthDiv2, mtIntVec);
//Drive


	FClosed = false;
	memset(&FFlags, 0, sizeof (FFlags));
	FParent = NULL;
	FNormal		= TIntVec(0,0,1);
}

TGPolygon::TGPolygon(TMTList <TGCut> &cuts)
{
	if (cuts.Count<3)
		throw EMyException ("<TGeomObject::AddPolygon> ýõôþ¸ªðªþ¢ýþ ôðýýv¿!");

	RegisterNewClass< TGUnit, TGPolygon >(this, false, &CreateFunction);
	RegisterField(&Tag, &aPOLYTAG, mtInt);
	RegisterField(&FNormal, &aNORMAL, mtIntVec);
	RegisterField(&FHoles, &aHOLES, mtMyObject);

	RegisterField(&FFlags, &aFLAGS, mtInt);	//Debug!

	FClosed = false;
	memset(&FFlags, 0, sizeof (FFlags));
	FParent = NULL;
	FNormal		= TIntVec(0,0,1);
	for (int i=0;i<cuts.Count;i++)
		if (AddCut(cuts.Items[i]) == grERROR)
			ErrorMsg("<TGPolygon::TGPolygon> ýõòþ÷üþöýþ ôþñðòøª¹ þª¨õ÷þú!");
}

void TGPolygon::Assign(TMyObject* MO)
{
	if (!MO->Is(TGPolygon::StaticType) )
		throw EMyException("+°øñúð úþÿø¨þòðýø ");

	TMyObject::Assign(MO);

//	TGPolygon* CF = (TGPolygon*)MO;
//	FFlags		= CF->FFlags;
}

TMyObject* TGPolygon::CreateFunction()
{
	return new TGPolygon();
}

bool TGPolygon::Equals(const TGPolygon& other) const
{
	if (FCuts.Count != other.FCuts.Count)
		return false;

	for (int i=0;i<FCuts.Count;i++)
		if (other.FCuts.IndexOf(FCuts.Items[i]) == -1)
			return false;
			
	return true;
}
TIntVec TGPolygon::GetOrigin() const
{
	return GetPoint(0).Point;
}

TIntVec TGPolygon::GetMidOrigin() const
{
	TIntVec temp(0,0,0);
	for (int i=0;i<Count;i++)
		temp += GetPoint(i).Point;
	temp /= (MBTi)Count;
	return temp;
}

int TGPolygon::AddCut(TGCut* Cut)
{
/*	if (Closed)
	{
		throw EMyException("<TGPolygon::AddCut> ôþñðòûõýøõ þª¨õ÷úð ò ÷ðüúýºªvù ÿþûøóþý");
		return grERROR;
	}	
*/
	if (!Cut)
		throw EMyException("<TGPolygon::AddCut> ýõòþ÷üþöýþ ôþñðòøª¹ NULL");
		
	if (FCuts.IndexOf(Cut) != -1)
		throw EMyException("<TGPolygon::AddCut> ýõòþ÷üþöýþ ôþñðòøª¹ ¸º•õ¸ªòº¦•øù þª¨õ÷þú!");

//		return grERROR;

	int ret = grERROR;

	if (FCuts.Count == 0)
	{                   
		FCuts.Add(Cut);
		Cut->AddPlane(this);			
			
		return grOK;
	}

	bool canConnectToBegin	= ( Cut->CanConnect(FCuts[0]) != NULL)/* && !Cut->Equal(FCuts[0])*/;
	bool canConnectToEnd	= ( Cut->CanConnect(*FCuts.Last())!= NULL)/* && !Cut->Equal(*FCuts.Last())*/;

	// Týð¢ðûð ýºöýþ ¦¨þòõ¨øª¹ úþýõ¡ - ¢ªþñv ýõ ÿþûº¢øª¹ øýòõ¨¸øø þª¨õ÷úþò.
	if ( canConnectToEnd)
	{
		FCuts.Add(Cut);
		Cut->AddPlane(this);			
		ret = grOK;
	} else 
	if ( canConnectToBegin)
	{
		FCuts.Insert(0,Cut);
		Cut->AddPlane(this);			
		ret = grOK;
	}

	if (canConnectToBegin && canConnectToEnd)
		if (FCuts.Count>2)
			FClosed = true;
			
	return ret;
}

int  SIGN_NOZERO(MBTi a)
{
	return (a<0) ? -1 : 1;
}
TIntVec SIGNVEC_NOZERO(const TIntVec v)
{
	return TIntVec(SIGN_NOZERO(v.x), SIGN_NOZERO(v.y), SIGN_NOZERO(v.z));
}

MBTi inline sqr(MBTi x)
{
	return x*x;
}

bool TGPolygon::FindBasisPoints(TMTList<TGPoint> &points)
{
	if (Count<3)
		return false;
	if (Count == 3)
	{
		points.Add(&GetPoint(0));
		points.Add(&GetPoint(1));
		points.Add(&GetPoint(2));
		return true;
	}
	points.Clear();
	TGPoint *p0 = &GetPoint(0);
	TGPoint *bestP1 = NULL;
	TGPoint *bestP2 = NULL;
	MBTi min_k = 0;

	for (int i=1;i<Count;i++)
		for (int j=i+1;j<Count;j++)
		{
			TGPoint *p1 = &GetPoint(i);
			TGPoint *p2 = &GetPoint(j);
			MBTi a = (p1->Point-p0->Point).Length();
			MBTi b = (p2->Point-p0->Point).Length();
			MBTi c = (p2->Point-p1->Point).Length();
//			if (a<PEPS || b<PEPS)
//				throw EMyException("<TGPolygon::FindBasisPoints> - ÿûþ¿þù ÿþûøóþý!");
			MBTi k = fabs(sqr(c)-sqr(a)-sqr(b))/sqr(a*b);
			if (!bestP1 || !bestP2 || min_k>k)
			{
				bestP1 = p1;
				bestP2 = p2;
				min_k = k;
			}
		}
	points.Add(p0);
	points.Add(bestP1);
	points.Add(bestP2);

/*	if (IndexOf(points.Items[0])>IndexOf(points.Items[1]))
		points.Exchange(0, 1);*/
	if (IndexOf(points.Items[1])>IndexOf(points.Items[2]))
		points.Exchange(1, 2);
	return true;	
}

/*
bool TGPolygon::IsConvex(int index)
{
	
}
*/


bool TGPolygon::CalculatePlane()
{
	bool ret = false;
	if (!Closed)
		return false;
	TMTList<TGPoint> basis;

/*	if (!FindBasisPoints(basis))
		throw EMyException("<TGPolygon::CalculatePlane> =õòþ÷üþöýþ ¨ð¸¸¢øªðª¹ ýþ¨üðû¹!");
	FNormal = VectorP(basis[2].Point - basis[0].Point,  basis[1].Point - basis[0].Point).Normalize();
*/
	TIntVec normal;
	for (int i=0;i<Count;i++)
	{
		TIntVec v1 = GetPoint((i-1+Count)%Count).Point-GetPoint(i).Point;
		TIntVec v2 = GetPoint((i+1)%Count).Point-GetPoint(i).Point;
		if (!VectorsParallel(v1, v2, /**//**//**//**//**/0.0005/**//**//**//**//**//**/)) //TODO: !!!!
			normal += ABS(VectorP(v1, v2));
	}		
	normal = normal.Normalize();
	TIntVec dir;
	
	TGPoint *LowRight = NULL;

	for (int i=0;i<Count;i++)
	{
		TGPoint *Pretnder = &GetPoint(i);
		if (!LowRight)
		{
			LowRight = Pretnder;
			continue;
		}
		if ( Pretnder->Point.x < LowRight->Point.x - EXACT_EPSILON )
			LowRight = Pretnder;
		else if ( fabs(Pretnder->Point.x-LowRight->Point.x)<=EXACT_EPSILON ) 
		{
				if( Pretnder->Point.y<LowRight->Point.y-EXACT_EPSILON )	
					LowRight = Pretnder;
				else if (fabs(Pretnder->Point.y-LowRight->Point.y)<=EXACT_EPSILON )
				{
					if ( Pretnder->Point.z<LowRight->Point.z-EXACT_EPSILON )
						LowRight = Pretnder;
				}
		}
	}

	if (LowRight)
	{

		int index = IndexOf(LowRight);
		TGPoint *mid = LowRight;
		TGPoint *src = &GetPoint((index - 1 + Count) % Count);
		TGPoint *dst = &GetPoint((index + 1) % Count);

		dir = VectorP(src->Point - mid->Point, dst->Point - mid->Point).Normalize();
		ret = true;
	}
	FNormal = normal.XYZ_Multiply(SIGNVEC_NOZERO(dir));
	return ret;                       
}

bool TGPolygon::ConsistsCut(TGCut *cut)
{
	return (FCuts.IndexOf(cut) != -1);
}

int TGPolygon::IndexOf(TGPoint *pnt)
{
	for (int i=0;i<Count;i++)
		if (&GetPoint(i) == pnt)
			return i;
	return -1;
}


TGPolygon::~TGPolygon()
{
	FHoles.Clear();
	ClearCuts();	
}

void TGPolygon::ClearCuts()
{
	while (FCuts.Count)
		DeleteCut(0);
}

bool TGPolygon::IsHoled() const
{
	return FHoles.Count;
}
void TGPolygon::DeleteCut(TGCut *cut)
{
	FClosed = false;
	if ( cut->RemovePlane(this) != -1 )
		FCuts.Remove(cut);
	else
		throw EMyException("TGPolygon::RemoveCut : þª¨õ÷þú ò ÿþûøóþýõ ýõ ÷ýðõª þ ýõü.");
}

void TGPolygon::DeleteCut(int index)
{
	FClosed = false;
	
	if ( FCuts.Items[index]->RemovePlane( this ) != -1 )
		FCuts.Delete(index);
	else
		throw EMyException("TGPolygon::DeleteCut : þª¨õ÷þú ò ÿþûøóþýõ ýõ ÷ýðõª þ ýõü.");

}

const TGPoint &TGPolygon::GetPoint(int index) const
{
	if ((FCuts.GetCycleItem(index+1)->Src != FCuts.Items[index]->Src) && (FCuts.GetCycleItem(index+1)->Dst != FCuts.Items[index]->Src))
		return *FCuts[index].Src;
	else
		return *FCuts[index].Dst;
}
TGPoint &TGPolygon::GetPoint(int index)
{
	if ((FCuts.GetCycleItem(index+1)->Src != FCuts.Items[index]->Src) && (FCuts.GetCycleItem(index+1)->Dst != FCuts.Items[index]->Src))
		return *FCuts[index].Src;
	else
		return *FCuts[index].Dst;
}



int TGPolygon::GetCount() const
{
	return FCuts.Count;
}
const TGCut &TGPolygon::GetCut(int index) const
{
	return FCuts[index];
}
TGCut &TGPolygon::GetCut(int index)
{
	return FCuts[index];
}

void TGPolygon::PlaceOnPlane(MBTi &AngX, MBTi &AngY, const TIntVec &org)
{
	TIntVec angle;
	
	AngX = -ArcTan2(Normal.y, Normal.z)/M_PI*180;
	angle = TIntVec(-AngX, 0, 0);

	for(int i=0;i<Count;i++)
		GetPoint(i).Point = RotateAround(GetPoint(i).Point, angle, org);
//	TIntVec nNormal = RotateAround(Normal, angle, TIntVec(0,0,0));

	AngY = ArcTan2(Normal.x, Normal.z)/M_PI*180;
	angle = TIntVec(0, -AngY, 0);
	for(int i=0;i<Count;i++)
		GetPoint(i).Point = RotateAround(GetPoint(i).Point, angle, org);
}
void TGPolygon::BackFromPlane(const MBTi &AngX, const MBTi &AngY, const TIntVec &org)
{
	TIntVec angle;

	angle = TIntVec(0, AngY, 0);
	for(int i=0;i<Count;i++)
		GetPoint(i).Point = RotateAround(GetPoint(i).Point, angle, org); 

	angle = TIntVec(AngX, 0, 0);
	for(int i=0;i<Count;i++)
		GetPoint(i).Point = RotateAround(GetPoint(i).Point, angle, org);

}

TGPolygon *TGPolygon::AddHole(TMTList<TGCut> &cuts)
{
	TGPolygon *p = (TGPolygon *)CreateFunction();
	FHoles.Add(p);

	for (int i=0;i<cuts.Count;i++)
	{
		p->AddCut(cuts.Items[i]);
		cuts[i].FFlags.Hole = gfTRUE;
	}

	if (!p->Closed)
		throw EMyException ("<TGeomObject::AddPolygon> ôþñðòûõý ýõ÷ðüúýºªvù ÿþûøóþý-ôv¨úð!");

	p->FNormal = Normal;
//	p->CalculatePlane();
	p->FParent = this;
	return p;
}

TBBox TGPolygon::GetBBox()
{
	if (FFlags.NeedCalcB == gfTRUE)
	{
		FBBox.Calculate(FCuts);
		FFlags.NeedCalcB = gfFALSE;
	}
	return FBBox;	
}	

TIntVec TGPolygon::GetNormal()
{
	if (FFlags.NeedCalcN == gfTRUE)
	{
		CalculatePlane();
		FFlags.NeedCalcN = gfFALSE;
	}
	return FNormal;	
}
void TGPolygon::SetNormal(const TIntVec &n)
{
	FNormal = n;
	FFlags.NeedCalcN = gfFALSE;
}


int TGPolygon::PointInPolygon2d(const TIntVec& Point,MBTi USEEPS)
{
	int parity = 0;
	for (int i=0;i<Count;i++)
	{
		switch (EdgeType(Point, GetPoint(i).Point, GetPoint((i + 1)%Count).Point, USEEPS))
		{
			case ettTOUCHING:
				return pipBOUNDARY;
			case ettCROSSING:
				parity = 1 - parity;
		}
	}
	return (parity ? pipINSIDE : pipOUTSIDE);
}

int TGPolygon::PointInPolygon_UseHoles2d(const TIntVec &Point,MBTi USEEPS)
{
	int result = PointInPolygon2d(Point,USEEPS);
	if (result != pipINSIDE)
		return result;
	for (int i=0;i<FHoles.Count;i++)
	{
	   int result_hole = FHoles.Items[i]->PointInPolygon2d(Point,USEEPS);
	   if ( result_hole == pipINSIDE)
			return pipOUTSIDE;
	   if ( result_hole == pipBOUNDARY)
			return pipHOLEBOUNDARY;
	}
	return pipINSIDE;
}
int TGPolygon::PolygonInPolygon2d(const TGPolygon& p, MBTi USEEPS)
{
	int inside = 0;
	int bound = 0;
	int outside = 0;
	for (int i=0;i<p.Count;i++)
	{
		int pip = PointInPolygon2d(p.GetPoint(i).Point, USEEPS);

		if (pip == pipINSIDE)
			inside++;
		else if (pip == pipBOUNDARY) 
			bound++;
		else
			outside++;
	}
	if (inside)
		if (outside)	
			return pipBOUNDARY;
		else
			return pipINSIDE;
	else if (outside)	
		return pipOUTSIDE;
	else if (PointInPolygon2d(p.GetMidOrigin(), USEEPS)== pipINSIDE)
		return pipINSIDE;
	else	
		return pipOUTSIDE;
}
int TGPolygon::PolygonInPolygon_UseHoles2d(const TGPolygon& p, MBTi USEEPS)
{
	int inside = 0;
	int bound = 0;
	int outside = 0;
	for (int i=0;i<p.Count;i++)
	{
		int pip = PointInPolygon_UseHoles2d(p.GetPoint(i).Point, USEEPS);

		if (pip == pipINSIDE)
			inside++;
		else if (pip == pipBOUNDARY || pip == pipHOLEBOUNDARY) 
			bound++;
		else
			outside++;
	}
	if (inside)
		if (outside)	
			return pipBOUNDARY;
		else
			return pipINSIDE;
	else if (outside)
		return pipOUTSIDE;
	else if (PointInPolygon_UseHoles2d(p.GetMidOrigin(), USEEPS) == pipINSIDE)
		return pipINSIDE;
	else
		return pipOUTSIDE;
}

void TGPolygon::Invert(bool jstInvert)
{
//	if (!FParent || jstInvert)
//	{
		FCuts.Invert();
		FNormal *= -1;
		for (int i=0;i<FHoles.Count;i++)
			FHoles[i].Invert(true);
//	} else
//	{
//		FParent->Invert();
//	}	
		
}

bool TGPolygon::DetectSelfHoles()
{
	if (Count<6)
		return false;
	bool ret = false;
/*	for (int k=0;k<Count;k++)
		for (int l=k+1;l<Count;l++)
			if (&GetPoint(k) == &GetPoint(l))
				throw EMyException("<TGeomObject::SolidCheck> : ÿþûøóþý ¸þôõ¨öøª þôøýðúþòvõ òõ¨°øýv!");
*/

	for (int k=0;k<Count;k++)
		if (!ret)
			for (int l=k+1;l<Count;l++)
			{
				if (&GetPoint(k) == &GetPoint(l))
				{
					ret = true;
					break;
				}
			}	
		else break;
	if (!ret)
		return false;
/**/
	for (int i=0;i<FCuts.Count;i++)
	{
		for (int j=0;j<FCuts[i].Src->FCuts.Count;j++)
			FCuts[i].Src->FCuts[j].FFlags.Mark = gfFALSE;

		for (int j=0;j<FCuts[i].Dst->FCuts.Count;j++)
			FCuts[i].Dst->FCuts[j].FFlags.Mark = gfFALSE;
	}
	for (int i=0;i<FCuts.Count;i++)
		FCuts[i].FFlags.Mark = gfTRUE;
	
	TMTList <TGCut> cuts;
	TMTList <TGPoint> pnts;
	
	TGPoint *begin = GetLowestPoint2d();
	TGCut	*cut = begin->GetTurnRightCut(true);
	TGCut	*begCut = cut;
	TGPoint *dst = cut->GetAnotherPoint(begin);

//	int i=0;
	do
	{
/*		if (i>cuts.Count)
		{
			ErrorMsg("<DetectSelfHoles> : FaTaL Error");
			return false;                           
		}	*/
		cut = dst->GetTurnLeftCut(cut, true);

		if (!cut)	
			return false;

		pnts.Add(dst);
		dst = cut->GetAnotherPoint(dst);
		cuts.Add(cut);
		int k = -1;
		if ((k = pnts.IndexOf(dst))!=-1 && (k != 0))
		{
			pnts.Add(dst);
			TMTList <TGCut> newCuts;
			for (int i=k+1;i<pnts.Count;i++)
			{
				newCuts.Add(cuts.Items[i-1]);
				cuts.Delete(i-1);
				pnts.Delete(i--);
			}
			for (int i=0;i<newCuts.Count;i++)
			{
				newCuts[i].FFlags.Mark = gfFALSE;
				DeleteCut(newCuts.Items[i]);
			}	
			AddHole(newCuts);
			cut = cuts.Last();	
		}
	}
	while(cut != begCut);
/**/
	FClosed = true;		
	return true;	
}

TGPoint *TGPolygon::GetLowestPoint2d()
{
	TGPoint *src = NULL;
	for (int i=0;i<FCuts.Count;i++)
	{
		if (src == NULL)
			src = FCuts[i].Src;
		else
		{
				if (src->Point.y > FCuts[i].Src->Point.y)
					src = FCuts[i].Src;

				if (src->Point.y > FCuts[i].Dst->Point.y)
					src = FCuts[i].Dst;
		}		
	}
	return src;
}
TGPoint *TGPolygon::GetHighestPoint2d()
{
	TGPoint *src = NULL;
	for (int i=0;i<FCuts.Count;i++)
	{
		if (src == NULL)
			src = FCuts[i].Src;
		else
		{
				if (src->Point.y < FCuts[i].Src->Point.y)
					src = FCuts[i].Src;

				if (src->Point.y < FCuts[i].Dst->Point.y)
					src = FCuts[i].Dst;
		}		
	}
	return src;
}

TClassify TGPolygon::ClassifyByPlane(const TIntVec &n, const TIntVec &o, MBTi EPS )
{
	int neg = 0;
	int pos = 0;
	for (int j=0;j<Count;j++)
	{
		MBTi ro = DistancePointPlane(GetPoint(j).Point, n, o);
		if (ro<-EPS)
			neg++;
//			return gfNEGATIVE;
		if (ro>EPS)
			pos++;
//			return gfPOSITIVE;
	}	           
	if (neg)
		if (pos)
			return gfINTERSECT;
		else	
			return gfNEGATIVE;
	else if (pos)		
		 return gfPOSITIVE;
		
	return gfCOLLINEAR;	
}
void TGPolygon::Cache()
{
	for (int i=0;i<Count;i++)
		GetPoint(i).Cache();
	for (int i=0;i<FHoles.Count;i++)
		FHoles[i].Cache();
}
void TGPolygon::Restore()
{
	for (int i=0;i<Count;i++)
		GetPoint(i).Restore();
	for (int i=0;i<FHoles.Count;i++)
		FHoles[i].Restore();
}

 

