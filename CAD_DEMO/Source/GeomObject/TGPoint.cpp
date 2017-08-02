#include <vcl.h>                           
#include "Usefuls.h"  
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"                                    
#pragma hdrstop

#include "TGObject.h"

#include "Poligon.h"
#pragma package(smart_init)

TClassNode* TGPoint::StaticType = NULL;

const AnsiString aPOINT("Pnt");
const AnsiString aPNTTAG("Tag");
const AnsiString aPNTFLAGS("Flg");

TGPoint::TGPoint()
{
	RegisterNewClass<TGUnit, TGPoint>(this,false, &CreateFunction);
	RegisterField(&Point, &aPOINT, mtIntVec);
	RegisterField(&Tag, &aPNTTAG, mtInt);
	RegisterField(&FFlags, &aPNTFLAGS, mtInt);
	memset(&FFlags, 0, sizeof(FFlags));
	Tag = 0;
	FCache = NULL;
};

TGPoint::TGPoint(const TIntVec &v)
{
	RegisterNewClass<TGUnit, TGPoint>(this, false, &CreateFunction);
	RegisterField(&Point, &aPOINT, mtIntVec);
	RegisterField(&Point, &aPNTTAG, mtInt);
	Point = v;
	memset(&FFlags, 0, sizeof(FFlags));
	Tag = 0;
	FCache = NULL;
};

TGPoint::~TGPoint()
{
	for (int i=0;i<FCuts.Count;)
		if (FCuts[i].Src == this)
			FCuts[i].Src = NULL;
		else if (FCuts[i].Dst == this)
			FCuts[i].Dst = NULL;
		else
			i++;

	if (FCache)
		delete FCache;
};

void TGPoint::Assign(TMyObject* MO)
{
	if (!MO->Is(TGPoint::StaticType) )
		throw EMyException("+°øñúð úþÿø¨þòðýø ");

	TMyObject::Assign((TMyObject *)MO);

//	TGPoint* CF = (TGPoint*)MO;
//	FCuts.Assign(&CF->FCuts);
//	FFlags =  CF->FFlags;
}

TMyObject* TGPoint::CreateFunction()
{
	return new TGPoint();
}

int TGPoint::GetCutsCount() const
{
	return FCuts.Count;
} 

bool TGPoint::GetClosed() const
{
	for (int i=0;i<FCuts.Count;i++)
		if (!FCuts[i].Closed) 
			return false;
	return true;
} 
TGCut &TGPoint::GetCut(int index)
{
	return FCuts[index];
} 
const TGCut &TGPoint::GetCut(int index) const 
{
	return FCuts[index];
} 


TGCut *TGPoint::GetTurnRightCut(TGCut *cut, bool MarkedOnly) const
{
	if (!cut || !cut->ConsistsPoint(this))
		return NULL;
	
	TGPoint *nxtDst = NULL;
	TGCut *nxtCut = NULL;
	TGPoint *src = cut->GetAnotherPoint(this);
	for (int i=0;i<FCuts.Count;i++)
		if (cut != FCuts.Items[i] && (!MarkedOnly || FCuts[i].Flags.Mark))
		{
			TGPoint *oth = FCuts[i].GetAnotherPoint(this);
			if ((nxtDst == NULL ||
				AngleRad(src->Point, Point, oth->Point)>
				AngleRad(src->Point, Point, nxtDst->Point)))
			{
				nxtDst = oth;
				nxtCut = (TGCut*)FCuts.GetItem(i);
			}
		}	
	return nxtCut;	
}			
TGCut *TGPoint::GetTurnLeftCut(TGCut *cut, bool MarkedOnly) const
{
	if (!cut || !cut->ConsistsPoint(this))
		return NULL;
	
	TGPoint *nxtDst = NULL;
	TGCut *nxtCut = NULL;
	TGPoint *src = cut->GetAnotherPoint(this);
	for (int i=0;i<FCuts.Count;i++)
		if (cut != FCuts.Items[i] && (!MarkedOnly || FCuts[i].Flags.Mark))
		{
			TGPoint *oth = FCuts[i].GetAnotherPoint(this);
			if ((nxtDst == NULL ||
				AngleRad(src->Point, Point, oth->Point)<
				AngleRad(src->Point, Point, nxtDst->Point)))
			{
				nxtDst = oth;
				nxtCut = (TGCut*)FCuts.GetItem(i);
			}
		}	
	return nxtCut;	
}			
TGCut *TGPoint::GetTurnRightCut(bool MarkedOnly) const
{
	TGCut *cut = NULL;
	TGPoint *dst = NULL;
	for (int i=0;i<FCuts.Count;i++)
		if (!MarkedOnly || FCuts[i].Flags.Mark)
		{	
			TGPoint *oth = FCuts[i].GetAnotherPoint(this);
			if ((cut == NULL ||
				((oth->Point - Point).Normalize()).x >
				((dst->Point - Point).Normalize()).x))
			{
				cut = (TGCut*)FCuts.GetItem(i);
				dst = oth;
			}
		}
	return cut;		
}
TGCut *TGPoint::GetTurnLeftCut(bool MarkedOnly) const
{
	TGCut *cut = NULL;
	TGPoint *dst = NULL;
	for (int i=0;i<FCuts.Count;i++)
		if (!MarkedOnly || FCuts[i].Flags.Mark)
		{	
			TGPoint *oth = FCuts[i].GetAnotherPoint(this);
			if ((cut == NULL ||
				((oth->Point - Point).Normalize()).x <
				((dst->Point - Point).Normalize()).x))
			{
				cut = (TGCut*)FCuts.GetItem(i);
				dst = oth;
			}
		}	
	return cut;	
}

void TGPoint::Changed(void* Field)
{
	TMyObject::Changed(Field);
	if (Field == &Point)
	{
		for (int i=0;i<FCuts.Count;i++)
		{
			FCuts[i].FFlags.NeedCalcN = gfTRUE;
			FCuts[i].FFlags.NeedCalcB = gfTRUE;
			for (int j=0;j<FCuts[i].FPlane.Count;j++)
				if (FCuts[i].FPlane.Items[j])
				{
					FCuts[i].FPlane[j].FFlags.NeedCalcN = gfTRUE;
					FCuts[i].FPlane[j].FFlags.NeedCalcB = gfTRUE;
				}	
		}			
	}
}

TGCut *TGPoint::GetAnotherCut(const TGCut *cut, bool MarkedOnly)
{
	for (int i=0;i<FCuts.Count;i++)
		if (FCuts.Items[i] != cut && (!MarkedOnly || FCuts[i].Flags.Mark))
			return FCuts.Items[i];
	return NULL;
}

bool TGPoint::Used() const
{
	return (FCuts.Count > 0);
}

void TGPoint::Cache()
{
	if (FCache == NULL)
	{
		FCache = new TIntVec(Point);
	} else
	{
		*FCache = Point;
	}
	FFlags.Cached = gfTRUE;
}

void TGPoint::Restore()
{
	if (FCache)
	{
		Point = *FCache;
		delete FCache;
		FCache = NULL;
	}
	FFlags.Cached = gfFALSE;
}

/*bool TGPoint::Equals(const TGPoint &other)
{
	return Point.Equal(other.Point, PEPS);
}*/



 

