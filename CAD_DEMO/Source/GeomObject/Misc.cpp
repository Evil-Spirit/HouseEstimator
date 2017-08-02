//---------------------------------------------------------------------------


#pragma hdrstop

#include "Misc.h"
#include "TGCut.h"
#include "TGPoint.h"
#include "Poligon.h"
#include "TGPolygon.h"
#include "TGObject.h"
#include "Triangulation.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

TIntVec GetToPlaneAnglesXZ(const TIntVec &n)
{
	MBTi AngZ = -ArcTan2(n.y, n.x)/M_PI*180+90;
	TIntVec nNormal = RotateAround(n, TIntVec(0, 0, AngZ), TIntVec(0,0,0));
	MBTi AngX = ArcTan2(nNormal.y, nNormal.z)/M_PI*180;

	return TIntVec(AngX, 0, AngZ);
}

void TransformXZ(const TIntVec &a, TIntVec &v)
{
	v = RotateAround(v, TIntVec(-a.x, 0, 0), TIntVec(0,0,0));
	v = RotateAround(v, TIntVec(0, 0, -a.z), TIntVec(0,0,0));
}

void BackXZ(const TIntVec &a, TIntVec &v)
{
	v = RotateAround(v, TIntVec(0, 0, a.z), TIntVec(0,0,0));
	v = RotateAround(v, TIntVec(a.x, 0, 0), TIntVec(0,0,0));
}

void GetBasePoints(const TMTList<TGCut> &cuts, TMTList<TGPoint> &points)
{
	points.Clear();
	for (int i=0;i<cuts.Count;i++)
	{
		if (points.IndexOf(cuts[i].Src) == -1)
			points.Add(cuts[i].Src);

		if (points.IndexOf(cuts[i].Dst) == -1)
			points.Add(cuts[i].Dst);
	}
}

TGeomFlags FlagUnite(const TGeomFlags &a, const TGeomFlags &b)
{
	TGeomFlags tgt;
	tgt.Origin = gfUNDEFINED;

	tgt.Hole = a.Hole | b.Hole;
	tgt.Intersect = a.Intersect | b.Intersect;
	tgt.Contour = a.Contour | b.Contour;
	tgt.Mark = a.Mark | b.Mark;
	tgt.Belong = a.Belong | b.Belong;
	tgt.Alredy = gfFALSE;
	tgt.Same = gfFALSE;
	tgt.Error = gfFALSE;
	tgt.Cached = a.Cached | b.Cached;
	tgt.Boundary = a.Boundary | b.Boundary;
	return tgt;
}

void GPolygonToPolygon(TGPolygon& GHP,TPolygon& HP)
{
	for (int i=0;i<GHP.Count;i++)			
		HP.Vertex->Add(new TIntVec(GHP.GetPoint(i).Point));
}

void GPolygonToHPolygon(TGPolygon& GHP,THoledPolygon& HP)
{
	HP.Clear();
	GPolygonToPolygon(GHP,HP);
	for (int i=0;i<GHP.FHoles.Count;i++)			
	{
		HP.Holes->Add( new TPolygon() );
		GPolygonToPolygon(GHP.FHoles[i],*HP.Holes->Last());
	}
}


//#define MATRIX_TRANSFORM

void Triangulate_(TGPolygon* GHP, TMDelTList <TIntVec> &tris)
{
	if (!GHP->Count)
		return;
	THoledPolygon HP;
	GPolygonToHPolygon(*GHP,HP);
	TIntVec ang;
	ang = GetToPlaneTransformation(GHP->Normal);
	for (int i=0;i<HP.Vertex->Count;i++)
		*HP.Vertex->Items[i] = TransformTo(*HP.Vertex->Items[i], ang);

	for (int i=0;i<HP.Holes->Count;i++)
		for (int j=0;j<HP.Holes->Items[i]->Vertex->Count;j++)
			*HP.Holes->Items[i]->Vertex->Items[j] = TransformTo(*HP.Holes->Items[i]->Vertex->Items[j], ang);

	HP.KillCollinear_1(0.0005);
	for (int i=0;i<HP.Holes->Count;i++)
		HP.Holes->Items[i]->KillCollinear_1(0.0005);
	Deloune->EPS = 0.0001;
	TMTList<TIntVec>* tri = Deloune->Triangulate(&HP);

	tris.Clear();
	for (int i=0;i<tri->Count;i++)
		tris.Add(new TIntVec(TransformFrom(*tri->Items[i], ang)));
}

void SetFlag(TGeomFlags &tgt, TClassifyFlags Flag, TClassify State)
{
	if (Flag & flORIGIN)
		tgt.Origin = State;
	if (Flag & flHOLE)
		tgt.Hole = State;
	if (Flag & flINTERSECT)
		tgt.Intersect = State;
	if (Flag & flCONTOUR)
		tgt.Contour = State;
	if (Flag & flMARK)
		tgt.Mark = State;
	if (Flag & flBELONG)
		tgt.Belong = State;
	if (Flag & flALREDY)
		tgt.Alredy = State;
	if (Flag & flSAME)
		tgt.Same = State;
	if (Flag & flERROR)
		tgt.Error = State;
	if (Flag & flCACHED)
		tgt.Cached = State;
	if (Flag & flBOUNDARY)
		tgt.Boundary = State;
}
void ConstructVCO(TVisPrimitiveObj *VCO, TGeomObject* GO)
{
	VCO->AddPrimitiveArray(GL_TRIANGLES);
	for (int i=0;i<GO->PolygonsCount;i++)
	{
			TGPolygon& POL = GO->GetPolygon(i);
//			VCO->Primitive[VCO->PrimitiveCount-1]->Material = MaterialDefault;
			TIntVec Normal = POL.Normal;
			TMDelTList<TIntVec> tris;
			Triangulate_(&POL, tris);
			for (int j=0;j<tris.Count;j++)
				VCO->AddIndex( VCO->Points->Add( VisMathVec(tris[j]), VisMathVec(Normal),ZEROVEC ),VCO->PrimitiveCount-1 );
	}
}


