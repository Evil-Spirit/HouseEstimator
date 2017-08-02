#include <vcl.h>                           
#include "Usefuls.h"  
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"                                    
#pragma hdrstop

#include "GeomObjV.h"
#pragma package(smart_init)

TClassNode* TGCut::StaticType = NULL;

const AnsiString aCUTTAG("Tag");
const AnsiString aCUTSMOOTH("Smth");
const AnsiString aCUTFLAGS("Flg");
const AnsiString aBBoxCenter("BBoxCenter");
const AnsiString aBBoxLengthDiv2("BBoxLengthDiv2");
TGCut::TGCut()
{
	RegisterNewClass<TGUnit,TGCut>(this,false,&CreateFunction);

	RegisterField(&Tag, &aCUTTAG, mtInt);
	RegisterField(&Smooth, &aCUTSMOOTH, mtBool);
	RegisterField(&FFlags, &aCUTFLAGS, mtInt);	//Debug!

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
	Src=NULL;
	Dst=NULL;
	for (int i=0;i<FPlane.Count;i++)
		if (FPlane.Items[i]!=NULL) 
			FPlane[i].RemoveCut(this);
};
void TGCut::Assign(TMyObject* MO)
{
	if (!MO->Is(TGCut::StaticType) )
		throw EMyException("Copying error");

	TMyObject::Assign((TMyObject *)MO);

	TGCut* CF = (TGCut*)MO;
	FFlags		=  CF->FFlags;
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
}

bool TGCut::Equal(const TGCut& other) const
{
	return (other.Src == Src && other.Dst == Dst) || (other.Src == Dst && other.Dst == Src);	
}


//SameDIrection работает при условии, что CanConnect() != NULL
bool TGCut::SameDirection(const TGCut &cut) const
{
	return Src == cut.Dst || Dst == cut.Src;
}
/*
int TGCut::IndexOfPlane(TGPolygon* aPlane)
{
	if (FPlane[0] == aPlane)	
		return  0;
	else if (FPlane[1] == aPlane)
		return 1;
	else
		return -1;
}
*/
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
	throw EMyException("<TGCut::GetNonCommonPointWith>: нет связи с данным отрезком");		
}

TGPoint *TGCut::GetAnotherPoint(const TGPoint* Point) const
{
	if (Src == Point)
		return Dst;
	else if (Dst == Point)
		return Src;
	throw EMyException("<TGCut::GetAnotherPoint>: нет такой точки");		
}
/*
TGPolygon *TGCut::GetAnotherPolygon(TGPolygon* Plane)
{
	if (Left == Plane)
		return Right;
	else if (Right == Plane)
		return Left;
	throw EMyException("<TGCut::GetAnotherPolygon>: нет такой плоскости");		
}
*/ 
