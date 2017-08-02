//---------------------------------------------------------------------------


#pragma hdrstop

#include "Types.h"
#include "Misc.h"

#include "TGPoint.h"
#include "TGCut.h"
#include "TGPolygon.h"

//---------------------------------------------------------------------------

bool TBBox::Overlaps(const TBBox &other, MBTi EPS) const
{
	return !(Min.x >= other.Max.x+EPS || Max.x <= other.Min.x-EPS ||
			 Min.y >= other.Max.y+EPS || Max.y <= other.Min.y-EPS ||
			 Min.z >= other.Max.z+EPS || Max.z <= other.Min.z-EPS);
}

bool TBBox::Overlaps2d(const TBBox &other, MBTi EPS) const
{
	return !(Min.x >= other.Max.x+EPS || Max.x <= other.Min.x-EPS ||
			 Min.y >= other.Max.y+EPS || Max.y <= other.Min.y-EPS);
}

void TBBox::Calculate(const TMTList <TGPoint> &pnts)
{
	if (!pnts.Count)
		return;
	Max = pnts[0].Point;
	Min = pnts[0].Point;

	for (int i=1;i<pnts.Count;i++)
	{
		Max = TIntVec(MAX(Max.x, pnts[i].Point.x), MAX(Max.y, pnts[i].Point.y), MAX(Max.z, pnts[i].Point.z));
		Min = TIntVec(MIN(Min.x, pnts[i].Point.x), MIN(Min.y, pnts[i].Point.y), MIN(Min.z, pnts[i].Point.z));
	}
}

void TBBox::Calculate(const TGCut &cut)
{
	TIntVec src = cut.Src->Point;
	TIntVec dst = cut.Dst->Point;
	for (int i=0;i<3;i++)
		if (src.a[i]>dst.a[i])
		{
			Max.a[i] = src.a[i];
			Min.a[i] = dst.a[i];
		} else
		{
			Max.a[i] = dst.a[i];
			Min.a[i] = src.a[i];
		}
}

void TBBox::Calculate(const TMTList <TGCut> &cuts)
{
	TMTList <TGPoint> pnts;
	GetBasePoints(cuts, pnts);
	Calculate(pnts);
}


#pragma package(smart_init)

