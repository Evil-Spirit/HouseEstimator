#include <vcl.h>                           
#include "Usefuls.h"  
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"                                    
#pragma hdrstop

#include "TGObject.h"
#pragma package(smart_init)

TClassNode* TGCut::StaticType = NULL;

const AnsiString aCUTTAG("Tag");
const AnsiString aCUTSMOOTH("Smth");
const AnsiString aCUTFLAGS("Flg");
const AnsiString aBBoxCenter("BBoxCenter");
const AnsiString aBBoxLengthDiv2("BBoxLengthDiv2");

TIntVec BBoxCenter;
TIntVec BBoxLengthDiv2;

TGCut::TGCut()
{
	RegisterNewClass<TGUnit, TGCut>(this, false, &CreateFunction);

	RegisterField(&Tag, &aCUTTAG, mtInt);
	RegisterField(&Smooth, &aCUTSMOOTH, mtBool);
	RegisterField(&FFlags, &aCUTFLAGS, mtInt);

//Drive
	RegisterField(&BBoxCenter, &aBBoxCenter, mtIntVec);
	RegisterField(&BBoxLengthDiv2, &aBBoxLengthDiv2, mtIntVec);
//Drive

	FPoint[0]	= NULL;
	FPoint[1]	= NULL;
	FLeft		= NULL;
	FRight		= NULL;
	Tag			= tgOTHER;
	Smooth		= false;
	memset(&FFlags, 0, sizeof(FFlags));
	FFlags.NeedCalcN = gfTRUE;
	FFlags.NeedCalcB = gfTRUE;
};

bool TGCut::Used() const
{
	for (bool OK = FPlane.Start();OK;OK = FPlane.Next())
		if ( FPlane.GetCurrent() )
			return true;
	return false;			
}

TGCut::~TGCut()
{
	Src = NULL;
	Dst = NULL;
	for (int i=0;i<FPlane.Count;i++)
		if (FPlane.Items[i]!=NULL) 
			FPlane[i].DeleteCut(this);
};

void TGCut::Assign(TMyObject* MO)
{
	if (!MO->Is(TGCut::StaticType) )
		throw EMyException("+°øñúð úþÿø¨þòðýø ");

	TMyObject::Assign((TMyObject *)MO);

//	TGCut* CF	= (TGCut*)MO;
//	FFlags		=  CF->FFlags;
}

TMyObject* TGCut::CreateFunction()
{
	return new TGCut();
}

bool TGCut::ConsistsDstAndSrc(const TGPoint* R1, const TGPoint* R2) const
{
	return ((R1==Src)&&(R2==Dst)) || ((R1==Dst)&&(R2==Src));
}

TGPoint *TGCut::CanConnect(const TGCut &cut) const
{
	if (Src == cut.Src || Src == cut.Dst) 
		return Src;

	if (Dst == cut.Src || Dst == cut.Dst) 
		return Dst;
	return NULL;
}

void TGCut::SetPoint(int index, TGPoint* Value)
{
	if (FPoint[index])
		FPoint[index]->FCuts.Remove(this);
	FPoint[index] = Value;
	if (FPoint[index])
		FPoint[index]->FCuts.Add(this);
	FFlags.NeedCalcN = gfTRUE;
	FFlags.NeedCalcB = gfTRUE;
}

bool TGCut::Equals(const TGCut& other) const
{
	return (other.Src == Src && other.Dst == Dst) || (other.Src == Dst && other.Dst == Src);	
}


void TGCut::SetPlane(int index, TGPolygon* aPlane)
{
	while (index>=FPlane.Count)
		FPlane.Add(NULL);
	FPlane.Items[index] = aPlane;    
}

const TGPolygon *TGCut::GetPlane(int index) const
{
	if (index<FPlane.Count) 
		return FPlane.Items[index];
	else 
		return NULL;	
}

void TGCut::AddPlane(TGPolygon *plane)
{
	if (Left == NULL)
		FLeft = plane;
	else if (Right == NULL)
		FRight = plane;
	else
		FPlane.Add(plane);
}	

int TGCut::RemovePlane(TGPolygon *plane)
{
	if (Left == plane)
	{
		FLeft = NULL;
		return 0;
	}
	else if (Right == plane)
	{
		FRight = NULL;
		return 1;
	}
	else
	{
		int a = FPlane.Remove(plane);
		return a;
	}	
}

bool TGCut::GetClosed() const
{
	int cnt = 0;
	for (int i=0;i<FPlane.Count;i++) 
		if (FPlane.Items[i])
			cnt++;
	return cnt>=2;
}

bool TGCut::ConsistsPoint(const TGPoint* Point) const
{
	return (Point == Src || Point == Dst);
}

TGPoint *TGCut::GetAnotherPoint(const TGCut &c) const
{
	if (!c.ConsistsPoint(Src)) 
		return Src;
	if (!c.ConsistsPoint(Dst)) 
		return Dst;
	throw EMyException("<TGCut::GetAnotherPoint>: ýõª ¸ò ÷ø ¸ ôðýývü þª¨õ÷úþü");		
}

TGPoint *TGCut::GetAnotherPoint(const TGPoint* Point) const
{
	if (Src == Point)
		return Dst;
	else if (Dst == Point)
		return Src;
	throw EMyException("<TGCut::GetAnotherPoint>: ýõª ªðúþù ªþ¢úø");		
}
/*
TGPolygon *TGCut::GetAnotherPolygon(TGPolygon* Plane)
{
	if (Left == Plane)
		return Right;
	else if (Right == Plane)
		return Left;
	throw EMyException("<TGCut::GetAnotherPolygon>: ýõª ªðúþù ÿûþ¸úþ¸ªø");		
}
*/ 

void TGCut::Cache()
{
	if (Src)
		Src->Cache();
	if (Dst)
		Dst->Cache();
}

void TGCut::Restore()
{
	if (Src)
		Src->Restore();
	if (Dst)
		Dst->Restore();
}
const TBBox &TGCut::GetBBox()
{
	if (FFlags.NeedCalcB == gfTRUE)
	{
		FBBox.Calculate(*this);
		FFlags.NeedCalcB = gfFALSE;
	}	
	return FBBox;
}


