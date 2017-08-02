#include <vcl.h>                           
#include "Usefuls.h"  
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"                                    
#pragma hdrstop

#include "GeomObjV.h"

#pragma package(smart_init)
						   
TGPoint *TGeomObject::ExtrudePoint(TGPoint *p, const TIntVec& d)
{
	if (FVertex.IndexOf(p)==-1) 
		return NULL; 
	TGPoint *newPnt = AddPoint(p->Point + d);
	if (!p->Closed)
		AddCut(p, newPnt);
	return newPnt;
}


TGPoint *TGeomObject::ExtrudePoint(int index, const TIntVec& d)
{
	if (index>=FVertex.Count) 
		return NULL;
	return ExtrudePoint(FVertex.Items[index], d);
}


TGCut *TGeomObject::ExtrudeCut(TGCut *c, const TIntVec& d, bool inv)
{
	if (FCuts.IndexOf(c)==-1) 
		return NULL; 
	TGPoint* NewSrc = ExtrudePoint(c->Src, d);
	TGPoint* NewDst = ExtrudePoint(c->Dst, d);
	TGCut* NewCut = AddCut(NewSrc,NewDst );

	if (!c->Closed)
	{
		TMTList <TGCut> cts;
		cts.Add( AddCut(c->Src,NewSrc ) );    //0
		cts.Add( AddCut(NewSrc,NewDst ) );    //1
		cts.Add( AddCut(c->Dst,NewDst ) );    //2
		cts.Add( c );		 				//3
		if (inv)
			cts.Invert();
		/*TGPolygon *p = */AddPolygon(cts);
	}	
	return NewCut;
}

TGCut *TGeomObject::ExtrudeCut(int index, const TIntVec& d, bool inv)
{
	if (index>=FCuts.Count) 
		return NULL;
	return ExtrudeCut(FCuts.Items[index], d, inv);
}

void TGeomObject::ExtrudePolygon(TGPolygon *p, const TIntVec& d)
{
	if (FPolygons.IndexOf(p)==-1 || !p->Closed)
		 return; 

	TMTList<TGCut> cuts;

	for (int i=0;i<p->FCuts.Count;i++)
		cuts.Add(ExtrudeCut(p->FCuts.Items[i], d));
	cuts.Invert();	

	TGPolygon *nPoly = AddPolygon(cuts);
	for (int i=0;i<p->FHoles.Count;i++)
	{
		cuts.Clear();
		for (int j=p->FHoles[i].Count-1;j>=0;j--)
			cuts.Add(ExtrudeCut(p->FHoles[i].FCuts.Items[j], d, true));
		nPoly->AddHole(cuts);
	}		

}

void TGeomObject::ExtrudePolygon(int index, const TIntVec& d)
{
	if (index>=FPolygons.Count) 
		return;
	ExtrudePolygon(FPolygons.Items[index], d);
}

void TGeomObject::Extrude(const TIntVec& d)
{
	int count = FPolygons.Count;
	for (int i=0;i<count;i++)
		ExtrudePolygon(i, d);
//	SynchronizePolygonsWises();
}

 
