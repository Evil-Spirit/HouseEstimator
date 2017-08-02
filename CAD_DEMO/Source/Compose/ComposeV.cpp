//---------------------------------------------------------------------------
#include "MTL.h"
#include "Usefuls.h"
#include "MyTemplates.h"
#include "..\GeomObject\Triangulation.h"
#include "..\GeomObject\Poligon.h"
#include <vcl.h>

#pragma hdrstop

#include "ComposeV.h"
#include "Compose.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


MBTi xCos(TIntVec v1, TIntVec v2)
{
	TIntVec normal = TIntVec(-v1.y, v1.x, 0);
	v1 = v1*-1;
	v1 = v1.Normalize();
	v2 = v2.Normalize();
	MBTi cs = ScalarP(v1, v2);
	MBTi Angle = acosDC(cs);
	if (ScalarP(normal, v2)<0) Angle = 2*M_PI - Angle;
	return Angle;
}

void moveToPolygonAndDelete(TMDelTList<TLPoint> &Pnts, TMDelTList<TLCut> &Cuts, TMTList<TLCut> &cts, TPolygon &poly, TMDelTList<int>& indices)
{
	indices.Clear();
	for (int i=0;i<cts.Count;i++)
	{
		if(	cts[i].Src != cts[(i+1)%cts.Count].Src &&
			cts[i].Src != cts[(i+1)%cts.Count].Dst)
			poly.Vertex->Add(new TIntVec(cts[i].Src->Point));
		else
			poly.Vertex->Add(new TIntVec(cts[i].Dst->Point));
		indices.Add(new int(cts[i].Tag));
	}	
		
	for (int i=0;i<cts.Count;i++)
		Cuts.Remove(&cts[i]);
				
	for (int i=0;i<Pnts.Count;i++)
		if (!Pnts[i].Cuts.Count)
			Pnts.Delete(i--);
			
}

TLPoint *isTheBranchPoint(TMDelTList<TLPoint> &Pnts)
{
	for (int i=0;i<Pnts.Count;i++)
		if (Pnts[i].Cuts.Count>2)
			return &Pnts[i];
	return NULL;
}	

void Composing(TMDelTList<TLPoint>& Pnts, TMDelTList<TLCut>& Cuts, TMDelTList<TPolygon>& POLS, TMDelTList< TMDelTList<int> >& indices)
{
	indices.Clear();
	POLS.Clear();

	TLPoint *begin = NULL;
	TLPoint *src = NULL;
	TLPoint *dst = NULL;
	TLCut	*cut = NULL;
	TMTList<TLCut> new_cuts;

//Находим самую нижнюю точку
	for (int i=0;i<Pnts.Count;i++)
	{
		if (src == NULL)
			src = &Pnts[i];
		else
			if (src->Point.y > Pnts[i].Point.y)
				src = &Pnts[i];
	}
	begin = src;

//Находим отрезок, самый поворачивающий направо
	for (int i=0;i<src->Cuts.Count;i++)
		if (src->Cuts[i].Src == src)
		{
			if (cut == NULL ||
			((src->Cuts[i].Dst->Point - src->Point).Normalize()).x >
			((dst->Point - src->Point).Normalize()).x)
			{
				cut = &src->Cuts[i];
				dst = src->Cuts[i].Dst;
			}
		}
		else
		{
			if (cut == NULL ||
			((src->Cuts[i].Src->Point - src->Point).Normalize()).x >
			((dst->Point - src->Point).Normalize()).x)
			{
				cut = &src->Cuts[i];
				dst = src->Cuts[i].Src;
			}
		}

	new_cuts.Add(cut);
	do
	{
		TLPoint *nxtDst = NULL;
		TLCut *nxtCut = NULL;

		for (int i=0;i<dst->Cuts.Count;i++)
			if (cut != &dst->Cuts[i])
				if (dst == dst->Cuts[i].Src && dst != dst->Cuts[i].Dst )
				{
					if ( nxtDst == NULL ||
						AngleRad(src->Point, dst->Point, dst->Cuts[i].Dst->Point)-
						AngleRad(src->Point, dst->Point, nxtDst->Point)>-0.0001)
					{
						nxtDst = dst->Cuts[i].Dst;
						nxtCut = &dst->Cuts[i];
					}
				}
				else if (dst != dst->Cuts[i].Src )
				{
					if ( nxtDst == NULL ||
						AngleRad(src->Point, dst->Point, dst->Cuts[i].Src->Point)-
						AngleRad(src->Point, dst->Point, nxtDst->Point)>-0.0001)
					{
						nxtDst = dst->Cuts[i].Src;
						nxtCut = &dst->Cuts[i];
					}
				}
		src = dst;
		dst = nxtDst;
		cut = nxtCut;
		new_cuts.Add(cut);
	}
	while(begin != dst);

	for (int i=0;i<Cuts.Count;i++)
		if ( new_cuts.IndexOf(Cuts.Items[i])==-1 )
			Cuts.Delete(i--);

/*	for (int i=0;i<Cuts.Count;i++)
		for (int j=0;j<new_cuts.Count;j++)
			if ( new_cuts.Items[j] != Cuts.Items[i])
			{
				Cuts.Delete(i--);
			}	
*/
	for (int i=0;i<Pnts.Count;i++)
		if (!Pnts[i].Cuts.Count)
			Pnts.Delete(i--);
		
	Cuts.NoDelClear();
	for (int i=0;i<new_cuts.Count;i++)
		Cuts.Add(&new_cuts[i]);
//Удалениие "бантиков"
	TLPoint *point;
	while ( (point = isTheBranchPoint(Pnts))!= NULL)
	{
		for (int j=0;j<point->Cuts.Count;j++)
		{
			TLPoint *src = point;
			TLPoint *begin = src;
			TLCut *cut = &point->Cuts[j];
			TMTList<TLCut>	cts;
			cts.Add(cut);
			bool result = true;
			do
			{
				if (cut->Src == src)
					src = cut->Dst;
				else
					src = cut->Src;
				if (begin == src) break;
				if (src->Cuts.Count>2)
				{
					result = false;
					break;
				}
				else
				{
					if (&src->Cuts[0] == cut)
						cut = &src->Cuts[1];
					else
						cut = &src->Cuts[0];
				}
				cts.Add(cut);
			}
			while (begin != src);

			if (result)
			{
				POLS.Add(new TPolygon);
				indices.Add(new TMDelTList <int>);
				moveToPolygonAndDelete(Pnts, Cuts, cts, *POLS.Last(), *indices.Last());
				break;
			}
		}
	}
	TMTList<TLCut> cts;
	cts.Assign(&Cuts);

	POLS.Add(new TPolygon);
	indices.Add(new TMDelTList <int>);
	moveToPolygonAndDelete(Pnts, Cuts, cts, *POLS.Last(), *indices.Last());
}

void SyncIndices(TPolygon &Poly, TMDelTList<int> &Ind)
{
	if (Poly.IsClockWize() == cwClockWize )
	{
		Poly.Invert();
		Ind.Invert();
	}
	int shift = Ind[0];
	for (int i=0;i<shift;i++)
	{
		Poly.Vertex->Move(Poly.Vertex->Count - 1, 0);
		Ind.Move(Ind.Count - 1, 0);
	}
}
void ComposePolygon(TPolygon& Pol,TMDelTList<TPolygon>& Pols, TMDelTList< TMDelTList<int> >& indices)
{
	TMDelTList<TLPoint> Pnts;
	TMDelTList<TLCut> Cuts;
	Delone.Clear();
	Delone.MergePolygon(&Pol);
	Delone.DeleteClosePoints();
	Delone.ProcessCrossList();

	for (int i=0;i<Delone.pAll.Count;i++)
	{
		Pnts.Add( new TLPoint );
		Pnts.Last()->Point.x = Delone.pAll[i].x;
		Pnts.Last()->Point.y = Delone.pAll[i].y;
		Pnts.Last()->Point.z = Delone.pAll[i].z;
	}
	for (int i=0;i<Delone.rAll.Count;i++)
	{
		Cuts.Add(new TLCut);
		for (int j=0;j<Delone.pAll.Count;j++)
		{
			if (Delone.rAll[i].ORGN == &Delone.pAll[j])
				Cuts.Last()->Src = &Pnts[j];
			if (Delone.rAll[i].DEST == &Delone.pAll[j])
				Cuts.Last()->Dst = &Pnts[j];
		}
		Cuts.Last()->Tag = Delone.rAll[i].Tag;
	}
	Composing(Pnts, Cuts, Pols, indices);
	for (int i=0;i<Pols.Count;i++)
		SyncIndices(Pols[i], indices[i]);

}
