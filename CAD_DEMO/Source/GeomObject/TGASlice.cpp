//---------------------------------------------------------------------------


#pragma hdrstop
// TGATransform.h
#include "TGASlice.h"

#include "TGObject.h"
#include "misc.h"
#include "math.h"
#include "Poligon.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#define PEPS go.PEPS

bool TGASlice::PlanePolygonIntersect(const TIntVec &n, const TIntVec &o, TGPolygon *p, TMTList <TGPoint> &cps)
{
	cps.Clear();
	TMTList <TGCut> cuts;
	cuts.Assign(&p->FCuts);
	for (int i=0;i<p->FHoles.Count;i++)
		TMTListAdd(cuts, p->FHoles[i].FCuts);

	// ¦рчЁхчрхь юЄЁхчъш яыюёъюёЄ№¦ фЁєуюую яюышуюэр
	for (int i=0;i<cuts.Count;i++)
	{
		TIntVec it;
		if (PlaneCutCross(n, o, cuts[i].Src->Point, cuts[i].Dst->Point, it, PEPS))
		{
			TGPoint *p = go.AddPoint(it);
			cps.Add(p);
			go.SplitCut(cuts.Items[i], p);
		}	
	}
	return true;
}

void TGASlice::SplitPolygonByPlane(TGPolygon *p, const TIntVec& n, const TIntVec& o, TMTList<TGPolygon> &Result)
{
	TIntVec dir, org;
	MBTi AngX, AngY, AngZ;

	if (!PlanePlaneCross(p->Normal, p->Origin, n, o, dir, org, PEPS)) 
		return;

	TMTList <TGPoint> cps;

//	SnapPoints = false;
	PlanePolygonIntersect(n ,o , p, cps);
//	SnapPoints = true;


	TMTList <TMyObject> toTransform;

//	toTransform.Assign(&cps);
	p->Cache();
		
	
	toTransform.Add(p);

	go.Transform.Translate(toTransform, TIntVec(0,0,0) - org);
	go.Transform.ToPlaneAndOX(toTransform, p->Normal, dir);

	for (int i=0;i<cps.Count;i++)
		for (int j=i+1;j<cps.Count;j++)
			if (cps[i].Point.x>cps[j].Point.x)
				cps.Exchange(i,j);

	TMTList <TGCut> split;
	for (int i=0;i<cps.Count-1;i++)
	{
		if (cps.Items[i] == cps.Items[i+1])	
			continue;
		// Принадлежность отрезков полигонам
		// Эпсилон принадлежности должен быть в несколько раз меньше эпсилона точек
		TIntVec mid = (cps[i].Point + cps[i+1].Point)/2.0;

		int a = p->PointInPolygon_UseHoles2d( mid, PEPS/2);

		// Если отрезок принадлежит обоим полигонам, добавляем общий отрезок
		if ((a == pipINSIDE || a == pipBOUNDARY || a == pipHOLEBOUNDARY))
		{
			split.Add(go.AddCut(cps.Items[i], cps.Items[i+1]));
			split.Last()->Flags.Intersect = gfTRUE;
		}	
	}
	go.SplitPolygon(p, split, Result);

	for (int i=0;i<Result.Count;i++)	
		Result[i].Restore();
}

void TGASlice::Split(const TIntVec &n, const TIntVec &o)
{
	go.FillCutsFlags(flINTERSECT, gfFALSE);
	TMTList<TGPolygon> pols;
	pols.Assign(&go.FPolygons);
	TMTList <TGPolygon> Result;

	for (int i = 0;i<pols.Count;i++)
		SplitPolygonByPlane(pols.Items[i], n, o, Result);

}

void TGASlice::ByPlane(const TIntVec &n, const TIntVec &o, TSliceType t)
{
	Split(n, o);
	
/*	ClassifyPolygons(n, o, PEPS);

	TMTList <TGPolygon> toDel;
	for (int i = 0;i<FPolygons.Count;i++)
		if (FPolygons[i].FFlags.Origin == gfNEGATIVE || FPolygons[i].FFlags.Origin == gfCOLLINEAR)
			toDel.Add(FPolygons.Items[i]);


	TMTList <TGCut> cuts;

	for (int i=0;i<FCuts.Count;i++)
		if (FCuts[i].FFlags.Intersect == gfTRUE)
			cuts.Add(FCuts.Items[i]);

	TMDelTList< TMTList<TGCut> > polyCut; 
	MBTi AngX, AngY;
	TransformToPlane(n*(-1), AngX, AngY);
	Polygonize2d(cuts, polyCut);
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
	TransformBack(AngX, AngY);
	
	FreeUnused(fuAll);*/
}

void TGASlice::operator()(const TIntVec &n, const TIntVec &o, TSliceType t)
{
	ByPlane(n, o, t);
}


TGPoint *TGASlice::CrossCutOX(TGCut &cut, MBTi EPS)
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

	return go.AddPoint(it);
}


void TGASlice::TransfixPolygonOX(TGPolygon *p, TMTList<TGCut> &Result)
{

	TIntVec dir, org;
	MBTi AngX, AngY, AngZ;

	TMTList <TGPoint> cps;
	TMTList <TGCut> cuts;

	cuts.Assign(&p->FCuts);

	for (int i=0;i<cuts.Count;i++)
	{
		TGPoint *cp = CrossCutOX(cuts[i], PEPS);
		if (cp)
			cps.Add(cp);
	}
	for (int j=0;j<p->FHoles.Count;j++)
	{
		cuts.Assign(&p->FHoles[j].FCuts);
		for (int i=0;i<cuts.Count;i++)
		{
			TGPoint *cp = CrossCutOX(cuts[i], PEPS);
			if (cp)
				cps.Add(cp);
		}
	}	

	for (int i=0;i<cps.Count;i++)
		for (int j=i+1;j<cps.Count;j++)
			if (cps[i].Point.x>cps[j].Point.x)
				cps.Exchange(i,j);

	for (int i=0;i<cps.Count-1;i++)
	{
		if (cps.Items[i] == cps.Items[i+1])	
			continue;
		// Принадлежность отрезков полигонам
		// Эпсилон принадлежности должен быть в несколько раз меньше эпсилона точек
		TIntVec mid = (cps[i].Point + cps[i+1].Point)/2.0;

		int a = p->PointInPolygon_UseHoles2d( mid, PEPS/2);

		// Если отрезок принадлежит обоим полигонам, добавляем общий отрезок
		if ((a == pipINSIDE || a == pipBOUNDARY || a == pipHOLEBOUNDARY))
		{
			Result.Add(go.AddCut(cps.Items[i], cps.Items[i+1]));
			Result.Last()->Flags.Intersect = gfTRUE;
		}	
	}
}


