//---------------------------------------------------------------------------


#pragma hdrstop

#include "TGAExtrude.h"
#include "TGObject.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TGPoint *TGAExtrude::Point(TGPoint *p, const TIntVec& d)
{
	if (go.FVertex.IndexOf(p)==-1) 
		return NULL; 
	TGPoint *newPnt = go.AddPoint(p->Point + d);
	if (!p->Closed)
		go.AddCut(p, newPnt);
	return newPnt;
}


TGPoint *TGAExtrude::Point(int index, const TIntVec& d)
{
	return Point(go.FVertex.Items[index], d);
}


TGCut *TGAExtrude::Cut(TGCut *c, const TIntVec& d, bool inv)
{
	TGPoint* NewSrc = Point(c->Src, d);
	TGPoint* NewDst = Point(c->Dst, d);
	TGCut* NewCut = go.AddCut(NewSrc,NewDst );

	if (!c->Closed)
	{
		TMTList <TGCut> cts;
		cts.Add( go.AddCut(c->Src,NewSrc ) );    //0
		cts.Add( go.AddCut(NewSrc,NewDst ) );    //1
		cts.Add( go.AddCut(c->Dst,NewDst ) );    //2
		cts.Add( c );		 				//3
		if (inv)
			cts.Invert();
		/*TGPolygon *p = */go.AddPolygon(cts);
	}	
	return NewCut;
}

TGCut *TGAExtrude::Cut(int index, const TIntVec& d, bool inv)
{
	return Cut(go.FCuts.Items[index], d, inv);
}

void TGAExtrude::Polygon(TGPolygon *p, const TIntVec& d)
{
	if (!p->Closed)
		 return; 

	TMTList<TGCut> cuts;

	for (int i=0;i<p->Count;i++)
		cuts.Add(Cut(&p->GetCut(i), d));
	cuts.Invert();	

	TGPolygon *nPoly = go.AddPolygon(cuts);
	for (int i=0;i<p->FHoles.Count;i++)
	{
		cuts.Clear();
		for (int j=p->FHoles[i].Count-1;j>=0;j--)
			cuts.Add(Cut(&p->FHoles[i].GetCut(j), d, true));
		nPoly->AddHole(cuts);
	}		

}

void TGAExtrude::Polygon(int index, const TIntVec& d)
{
	Polygon(go.FPolygons.Items[index], d);
}

void TGAExtrude::Object(const TIntVec& d)
{
	int count = go.FPolygons.Count;
	for (int i=0;i<count;i++)
		Polygon(i, d);
}

void TGAExtrude::operator()(const TIntVec& d)
{
	Object(d);
}


