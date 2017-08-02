//---------------------------------------------------------------------------

#include "TGPoint.h"
#include "TGCut.h"
#include "TGPolygon.h"

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"                                    


#include "TGObject.h"
#include "Misc.h"

#include "Poligon.h"
#include "LinearList.h"


#define INITIALIZE_EPSILON 0.0005

//---------------------------------------------------------------------------

#pragma hdrstop
#pragma package(smart_init)

void RegisterGeomObject()
{
	TGCut();
	TGPoint();
	TGPolygon();
	TGeomObject();
}
#pragma startup RegisterGeomObject

TClassNode* TGeomObject::StaticType = NULL;

const AnsiString aVERT = "Points";
const AnsiString aCUT = "Cuts";
const AnsiString aPOLY = "Polygons";


void SetMaterial( TVisPrimitiveObj* VCO, int PrimitiveInd, int MatsInd, const TColor& Amb, const TColor& Dif, const TColor& Emis, const TColor& Spec)
{
//	VCO->Primitive[PrimitiveInd]->Material = RenderMats[MatsInd];
	VCO->Primitive[PrimitiveInd]->Material->ColorAmbient->Color = Amb;
	VCO->Primitive[PrimitiveInd]->Material->ColorAmbient->Alpha = 1;
	VCO->Primitive[PrimitiveInd]->Material->ColorDiffuse->Color = Dif;
	VCO->Primitive[PrimitiveInd]->Material->ColorDiffuse->Alpha = 1;
	VCO->Primitive[PrimitiveInd]->Material->ColorEmission->Color = Emis;
	VCO->Primitive[PrimitiveInd]->Material->ColorEmission->Alpha = 1;
	VCO->Primitive[PrimitiveInd]->Material->ColorSpecular->Color = Spec;
	VCO->Primitive[PrimitiveInd]->Material->ColorSpecular->Alpha = 1;
}

TGeomObject::TGeomObject(): Extrude(*this), Transform(*this), Fix(*this), Boolean(*this), Slice(*this), Triangulate(*this), AnRender(*this,NULL), Graph(*this)
{
	RegisterNewClass< TMyObject, TGeomObject >(this, false, &CreateFunction);
	RegisterField(&FVertex,	&aVERT, mtMyObject);
	RegisterField(&FCuts, &aCUT, mtMyObject);
	RegisterField(&FPolygons, &aPOLY, mtMyObject);

	CreateCutFunction = TGCut::StaticType->CreateFunction;
	CreatePointFunction = TGPoint::StaticType->CreateFunction;
	CreatePolygonFunction = TGPolygon::StaticType->CreateFunction;
	SnapPointsToNearest	= false;

	SnapPoints			= true;
	SnapCuts			= true;
	SnapPolygons		= false;

	CheckPolygonData	= true;
	CheckCutData		= true;

	PEPS = INITIALIZE_EPSILON;
}

void TGeomObject::Assign(TMyObject* MO)
{
	if (!MO->Is(TGeomObject::StaticType) )
		throw EMyException("<TGeomObject::Assign> Copying error");
	Clear();

	TMyObject::Assign((TMyObject *)MO);
	TGeomObject *GO = (TGeomObject *)MO;

	TGeomObject &go = *GO;
//	TMTList <TGPoint> &pnts = FVertex;
//	TMTList <TGCut> &cuts = FCuts;

	IndexBy(go.FVertex);

	FCuts.Start();
	for (bool ok = go.FCuts.Start();ok;ok = go.FCuts.Next())
	{
		FCuts.GetCurrent()->Src = FVertex.Items[go.FCuts.GetCurrent()->Src->Index];
		FCuts.GetCurrent()->Dst = FVertex.Items[go.FCuts.GetCurrent()->Dst->Index];
		FCuts.Next();
	}	

	IndexBy(go.FCuts);
	
	TMTList <TGCut> plcut;
	FPolygons.Start();
	for (bool ok = go.FPolygons.Start();ok;ok = go.FPolygons.Next())
	{
		plcut.Clear();
		for (bool ok1 = go.FPolygons.GetCurrent()->FCuts.Start();ok1;ok1 = go.FPolygons.GetCurrent()->FCuts.Next())
			plcut.Add(FCuts.Items[go.FPolygons.GetCurrent()->FCuts.GetCurrent()->Index]);
		TGPolygon *p = FPolygons.GetCurrent();	

		for (bool ok1 = plcut.Start();ok1;ok1 = plcut.Next() )
			p->AddCut(plcut.GetCurrent());
//		p->FCuts.Assign(&plcut);

		p->FHoles.Start();
		for (bool ok1 = go.FPolygons.GetCurrent()->FHoles.Start();ok1;ok1 = go.FPolygons.GetCurrent()->FHoles.Next())
		{
			plcut.Clear();
			for (bool ok2 = go.FPolygons.GetCurrent()->FHoles.GetCurrent()->FCuts.Start();ok2;ok2 = go.FPolygons.GetCurrent()->FHoles.GetCurrent()->FCuts.Next())
				plcut.Add(FCuts.Items[go.FPolygons.GetCurrent()->FHoles.GetCurrent()->FCuts.GetCurrent()->Index]);
			for (bool ok2 = plcut.Start();ok2;ok2 = plcut.Next() )
				p->FHoles.GetCurrent()->AddCut(plcut.GetCurrent());
//			p->FHoles.GetCurrent()->FCuts.Assign(&plcut);
			p->FHoles.Next();
		}		
		FPolygons.Next();
	}
	
/*	TMDelTList <int> indices;

	GO->CutsToIndices(indices);
	IndicesToCuts(indices);
	for (int i=0;i<FPolygons.Count;i++)	
	{
		indices.Clear();
		GO->PolygonToIndices(GO->FPolygons.Items[i], indices);
		IndicesToPolygon(FPolygons.Items[i], indices);
		for (int j=0;j<FPolygons[i].FHoles.Count;j++)	
		{
			indices.Clear();
			GO->PolygonToIndices(GO->FPolygons[i].FHoles.Items[j], indices);
			IndicesToPolygon(FPolygons[i].FHoles.Items[j], indices);
			FPolygons[i].FHoles[j].FParent = FPolygons.Items[i];
		}
	}*/
}

void TGeomObject::Append(TGeomObject &go)
{
	TMTList <TGPoint> pnts;
	TMTList <TGCut> cuts;

	for (bool ok = go.FVertex.Start();ok;ok = go.FVertex.Next())
		pnts.Add(AddPoint(go.FVertex.GetCurrent()->Point));

	IndexBy(go.FVertex);
	
	for (bool ok = go.FCuts.Start();ok;ok = go.FCuts.Next())
		cuts.Add(AddCut(pnts.Items[go.FCuts.GetCurrent()->Src->Index], pnts.Items[go.FCuts.GetCurrent()->Dst->Index]));

	IndexBy(go.FCuts);
	
	TMTList <TGCut> plcut;
	for (bool ok = go.FPolygons.Start();ok;ok = go.FPolygons.Next())
	{
		plcut.Clear();
		for (bool ok1 = go.FPolygons.GetCurrent()->FCuts.Start();ok1;ok1 = go.FPolygons.GetCurrent()->FCuts.Next())
			plcut.Add(cuts.Items[go.FPolygons.GetCurrent()->FCuts.GetCurrent()->Index]);
		TGPolygon *p = AddPolygon(plcut);	
		for (bool ok1 = go.FPolygons.GetCurrent()->FHoles.Start();ok1;ok1 = go.FPolygons.GetCurrent()->FHoles.Next())
		{
			plcut.Clear();
			for (bool ok2 = go.FPolygons.GetCurrent()->FHoles.GetCurrent()->FCuts.Start();ok2;ok2 = go.FPolygons.GetCurrent()->FHoles.GetCurrent()->FCuts.Next())
				plcut.Add(cuts.Items[go.FPolygons.GetCurrent()->FHoles.GetCurrent()->FCuts.GetCurrent()->Index]);
			p->AddHole(plcut);	
		}		
	}	                                                     
}

void TGeomObject::CutsToIndices(TMDelTList<int>& indices) const
{
	indices.Clear();
	for ( int i = 0; i < FCuts.Count; i++)
	{
		indices.Add(new int(FVertex.IndexOf(FCuts[i].Src)));
		indices.Add(new int(FVertex.IndexOf(FCuts[i].Dst)));
	}
}

void TGeomObject::IndicesToCuts(TMDelTList<int>& indices)
{
	for ( int i = 0; i < FCuts.Count; i++)
	{
		FCuts[i].Src = FVertex.Items[indices[i*2]];
		FCuts[i].Dst = FVertex.Items[indices[i*2+1]];
	}
}
						   
void TGeomObject::PolygonToIndices(TGPolygon* GP,TMDelTList<int>& indices) const
{
	indices.Clear();
	for ( int j = 0; j < GP->FCuts.Count; j++)
		indices.Add( new int(FCuts.IndexOf(GP->FCuts.Items[j])) );
}

void TGeomObject::IndicesToPolygon(TGPolygon* GP,TMDelTList<int>& indices)
{
	GP->FCuts.Clear();
	for ( int j = 0; j < indices.Count; j++)
		GP->AddCut( FCuts.Items[indices[j]] );
}

void TGeomObject::SavePolygon(TGPolygon *poly, FILE *F) const
{
	TMDelTList <int> cuts;
	PolygonToIndices(poly, cuts);	
	cuts.SaveData(F);
	for (int i=0;i<poly->FHoles.Count;i++)	
		SavePolygon(poly->FHoles.Items[i], F);
		
}

void TGeomObject::LoadPolygon(TGPolygon *poly, FILE *F)
{
	TMDelTList <int> cuts;
	cuts.LoadData(F);
	IndicesToPolygon(poly, cuts);

	for (int i=0;i<poly->FHoles.Count;i++)
	{
		poly->FHoles[i].FParent = poly;
		LoadPolygon(poly->FHoles.Items[i], F);
	}	
		
}
void TGeomObject::WritePolygon(TGPolygon *poly,TMemoryStream *MS) const
{
	TMDelTList <int> cuts;
	PolygonToIndices(poly, cuts);	
	cuts.WriteData(MS);
	for (int i=0;i<poly->FHoles.Count;i++)	
		WritePolygon(poly->FHoles.Items[i], MS);
		
}

void TGeomObject::ReadPolygon(TGPolygon *poly, TMemoryStream *MS)
{
	TMDelTList <int> cuts;
	cuts.ReadData(MS);
	IndicesToPolygon(poly, cuts);

	for (int i=0;i<poly->FHoles.Count;i++)	
	{
		poly->FHoles[i].FParent = poly;
		ReadPolygon(poly->FHoles.Items[i], MS);
	}	
		
}

//запись и чтение из файла
void TGeomObject::SaveData(FILE *F) const
{
	TMyObject::SaveData(F);
	TMDelTList<int> indices;
	
	CutsToIndices(indices);

	indices.SaveData(F);
	for (int i=0;i<FPolygons.Count;i++)
		SavePolygon((TGPolygon *)FPolygons.GetItem(i), F);
}

void TGeomObject::LoadData(FILE *F)
{	
	TMyObject::LoadData(F);

	TMDelTList<int> indices;
	indices.LoadData(F);
	IndicesToCuts(indices);

	for (int i=0;i<FPolygons.Count;i++)
		LoadPolygon(FPolygons.Items[i], F);
}
//запись и чтение в поток
void TGeomObject::WriteData(TMemoryStream *MS) const
{
	TMyObject::WriteData( MS );
	TMDelTList<int> indices;
	CutsToIndices(indices);
	indices.WriteData(MS);
	for (int i=0;i<FPolygons.Count;i++)
		WritePolygon((TGPolygon *)FPolygons.GetItem(i), MS);
}

void TGeomObject::ReadData(TMemoryStream *MS)
{
	TMyObject::ReadData(MS);

	TMDelTList<int> indices;
	indices.ReadData(MS);

	IndicesToCuts(indices);

	for (int i=0;i<FPolygons.Count;i++)
		ReadPolygon(FPolygons.Items[i], MS);
}


void TGeomObject::DeletePoint(int index)
{
	if (index != -1)
		FVertex.Delete(index);
}

void TGeomObject::DeleteCut(int index)
{
	UpdateCutPointers(FCuts.Items[index]);
	FCuts.Delete(index);
}

void TGeomObject::DeletePolygon(int index)
{
	FPolygons.Delete(index);
}

void TGeomObject::Delete(TGPoint *target)
{
	DeletePoint(FVertex.IndexOf(target));
}

void TGeomObject::Delete(TGCut *target)
{
	DeleteCut(FCuts.IndexOf(target));
}

void TGeomObject::Delete(TGPolygon *target)
{
	DeletePolygon(FPolygons.IndexOf(target));
}

TGPoint *TGeomObject::AddPoint(const TIntVec &v)
{
	if (SnapPoints)
	{
		TGPoint *exists;
		if (SnapPointsToNearest && (exists = ExistsPointNearest(v))!=NULL)
		{
			exists->FFlags.Alredy = gfTRUE;
			return exists;
		}
		else
		if ((exists = ExistsPoint(v))!=NULL)
		{
			exists->FFlags.Alredy = gfTRUE;
			return exists;
		}
	}		
	TGPoint *point = (TGPoint *)CreatePointFunction();
	point->Point = v;
	FVertex.Add(point);
	return point;
}

TGPoint *TGeomObject::AddPoint(const TGPoint &p)
{
	return AddPoint(p.Point);
}

TGPolygon *TGeomObject::ExistsPolygon(const TGPolygon &what)
{
	for (int i=0;i<FPolygons.Count;i++)
		if (what.Equals(FPolygons[i]))
			return FPolygons.Items[i];
	return NULL;	
}

TGCut *TGeomObject::ExistsCut(TGPoint *p1, TGPoint *p2)
{
/*	for (int i=0;i<FCuts.Count;i++)
		if (what.Equals(FCuts[i]))
			return FCuts.Items[i];
	return NULL;	
*/
	if ( p1->FCuts.Count < p2->FCuts.Count )
	{
		for ( int i = 0; i < p1->FCuts.Count; i++ )
			if ( p1 == p1->FCuts[i].Src && p2 == p1->FCuts[i].Dst ||
				 p1 == p1->FCuts[i].Dst && p2 == p1->FCuts[i].Src)
			return p1->FCuts.Items[i];
	} else
	{
		for ( int i = 0; i < p2->FCuts.Count; i++ )
			if ( p1 == p2->FCuts[i].Src && p2 == p2->FCuts[i].Dst ||
				 p1 == p2->FCuts[i].Dst && p2 == p2->FCuts[i].Src)
			return p2->FCuts.Items[i];
	}
	return NULL;
}

TGCut *TGeomObject::ExistsCut(const TGCut &cut)
{
	return ExistsCut(cut.Src, cut.Dst);
}

TGPoint* TGeomObject::ExistsPoint(const TIntVec& v)
{
	for (int i=0;i<FVertex.Count;i++)
	  if (v.Equal(FVertex[i].Point, PEPS))
		  return FVertex.Items[i];

	return NULL;
}                                                                                             

TGPoint* TGeomObject::ExistsPoint(const TGPoint& v)
{
	return ExistsPoint(v.Point);
}                                                                                             

TGPoint* TGeomObject::ExistsPointNearest(const TIntVec& v)
{
	TGPoint *p = NULL;
	for (int i=0;i<FVertex.Count;i++)
		if (v.Equal(FVertex[i].Point, PEPS) && (!p || (v-p->Point).Length() > (v-FVertex[i].Point).Length()))
			p = FVertex.Items[i];
	return p;
}                                                                                             

TGPoint* TGeomObject::ExistsPointNearest(const TGPoint& v)
{
	return ExistsPointNearest(v.Point);
}                                                                                             


TGCut *TGeomObject::AddCut(TGPoint *p1, TGPoint *p2)
{
	if (CheckCutData && (FVertex.IndexOf(p1) == -1 || FVertex.IndexOf(p2) == -1 || p2 == p1))
		throw EMyException ("<TGeomObject::AddCut> ошибка данных!");

	TGCut *n;
	if (SnapCuts && (n = ExistsCut(p1, p2)) != NULL)
	{
		n->FFlags.Alredy = gfTRUE;
		return n;
	}

	TGCut *cut = (TGCut *)CreateCutFunction();
	cut->Src = p1;
	cut->Dst = p2;
	FCuts.Add(cut);
	return cut;
}

TGCut *TGeomObject::AddCut(const TGCut &c)
{
	TGCut *cut = AddCut(c.Src->Point, c.Dst->Point);
	cut->Assign((TGCut *)&c);
	return cut;
}


TGCut *TGeomObject::AddCut(int i1, int i2)
{
	return AddCut(FVertex.Items[i1], FVertex.Items[i2]);
}

TGCut *TGeomObject::AddCut(TIntVec v1, TIntVec v2)
{
	return AddCut(AddPoint(v1), AddPoint(v2));
}

TGCut *TGeomObject::CopyCutToObject(const TGCut &cut)
{
	TGPoint *p1 = AddPoint(cut.Src->Point);
	TGPoint *p2 = AddPoint(cut.Dst->Point);
	if ((p1!=p2) && p2 && p1)
	{
		TGCut *result = AddCut(p1, p2);
		result->FFlags = FlagUnite(result->FFlags, cut.FFlags);
		return result;
	}
	return NULL;
}

TGPolygon *TGeomObject::CopyPolygonToObject(const TGPolygon &poly )
{
	TMTList <TGPoint> points;
	TMTList <TGCut> cuts;

	//Добавляем точки полигона так, чтобы не получилось отрезков из двух одинаковых точек(В новом обьекте разные точки могут стать одной)
	for (int i=0;i<poly.Count;i++)	
	{
		TGPoint *p = AddPoint(poly.GetPoint(i).Point);
			if (points.IndexOf(p) == -1)
				points.Add(p);
	}	
		
	for (int i=0;i<points.Count;i++)
		cuts.Add(AddCut(points.Items[i], points.CycleItems[i+1]));

	TGPolygon *p = AddPolygon(cuts);
	for (int i=0;i<poly.FHoles.Count;i++)
	{
		cuts.Clear();
		points.Clear();
		
		// Добавляем точки полигона так, чтобы не получилось отрезков из двух одинаковых точек
		// (В новом обьекте разные точки могут стать одной)

		for (int j=0;j<poly.FHoles[i].Count;j++)	
		{
			TGPoint *p = AddPoint(poly.FHoles[i].GetPoint(j).Point);
				if (points.IndexOf(p) == -1)
					points.Add(p);
		}	

		for (int j=0;j<points.Count;j++)
			cuts.Add(AddCut(points.Items[j], points.CycleItems[j+1]));
			
		p->AddHole(cuts);
	}	
	return p;
}

TGPolygon *TGeomObject::AddPolygon(TMTList<TGCut> &cuts, const TIntVec &nrm)
{
	if (cuts.Count<3)
		return NULL;
//		throw EMyException ("<TGeomObject::AddPolygon> недостаточно данных!");
	
	FPolygons.Add((TGPolygon *)CreatePolygonFunction());
	TGPolygon *p = FPolygons.Last();;
	for (int i=0;i<cuts.Count;i++)
		p->AddCut(cuts.Items[i]);
	if (!p->Closed)
		throw EMyException ("<TGeomObject::AddPolygon> добавлен незамкнутый полигон!");

	if (nrm == TIntVec(0,0,0))
		p->CalculatePlane();
	else
		p->FNormal = nrm;

	return p;
}

TGPolygon *TGeomObject::AddPolygon(const TMTList<int>& indices, const TIntVec &nrm)
{
	TMTList <TGCut> Cuts;
	for (int i=0;i<indices.Count;i++)
		Cuts.Add(FCuts.Items[indices[i]]);
	return AddPolygon(Cuts, nrm);
}

TMyObject* TGeomObject::CreateFunction()
{
	return new TGeomObject();
}
void TGeomObject::Clear()
{
	FPolygons.Clear();
	FCuts.Clear();
	FVertex.Clear();
}

TGCut* TGeomObject::GetCutByPoints(TGPoint* P1, TGPoint* P2)
{
	//просто перебираем список отрезков одной из точек
	if (P1==NULL)
		return NULL;
	if (P2==NULL)
		return NULL;
	for (int i=0;i<P1->CutsCount;i++)
		if ( P1->FCuts[i].ConsistsDstAndSrc(P1,P2) )
			return &(P1->GetCut(i));
	return NULL;
}

TGPoint &TGeomObject::GetVertex(int index) const
{
	return (TGPoint &)FVertex[index];
}

TGPoint &TGeomObject::GetVertex(int index)
{
	return (TGPoint &)FVertex[index];
}

TGCut &TGeomObject::GetCut(int index) const
{
	return (TGCut &)FCuts[index];
}

TGCut &TGeomObject::GetCut(int index)
{
	return (TGCut &)FCuts[index];
}

TGPolygon &TGeomObject::GetPolygon(int index) const
{
	return (TGPolygon &)FPolygons[index];
}

TGPolygon &TGeomObject::GetPolygon(int index)
{
	return (TGPolygon &)FPolygons[index];
}

int TGeomObject::GetPolygonsCount() const
{
	return FPolygons.Count;
}

int TGeomObject::GetCutsCount() const
{
	return FCuts.Count;
}

int TGeomObject::GetVertexCount() const
{
	return FVertex.Count;
}
bool TGeomObject::GetClosed() const
{
	for (int i=0;i<FPolygons.Count;i++)
		if (!FPolygons[i].Closed) 
			return false;
	return true;
}
bool TGeomObject::GetSolid() const
{
	for (int i=0;i<FCuts.Count;i++)
		if (!FCuts[i].Closed) 
			return false;
	return true;
}
int TGeomObject::IndexOf(TGPoint *point) const
{
	return FVertex.IndexOf(point);
}

int TGeomObject::IndexOf(TGCut *cut) const
{
	return FCuts.IndexOf(cut);
}

int TGeomObject::IndexOf(TGPolygon *polygon) const
{
	return FPolygons.IndexOf(polygon);
}

bool TGeomObject::PolygonizeIsolated(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly)
{
	if (Cuts.Count<3)
		return false;

	TMTList<TGCut> cuts;
	cuts.Assign((TGCut *)&Cuts);

	FillCutsFlags(flMARK, gfFALSE);
	FillCutsFlags(cuts, flMARK, gfTRUE);

	poly.Clear();

	SortCutsByConnect(cuts);

	while(cuts.Count>2)		
	{
		TGCut *cut		= cuts.Items[0];
		TGPoint *dst	= cut->Dst;
		TGPoint *begin	= cut->GetAnotherPoint(cut->Dst);
//		TGCut *begCut	= cut;

		poly.Add(new TMTList<TGCut>);
		poly.Last()->Add(cut);

		while( dst != begin )
		{
			cut = dst->GetAnotherCut(cut, true);

			if (!cut)	
				return false;

			dst = cut->GetAnotherPoint(dst);

			poly.Last()->Add(cut);
		}

		for (int i=0;i<poly.Last()->Count;i++)
			cuts.Remove(poly.Last()->Items[i]);
	}                 
	return true;
}

TGPoint *TGeomObject::GetLowestPoint2d(const TMTList<TGCut> &cuts)
{
	TGPoint *src = NULL;
	TMTList <TGPoint> points;
	GetBasePoints(cuts, points);

	for (int i=0;i<points.Count;i++)
		if (!src || src->Point.y > points[i].Point.y)
			src = points.Items[i];

	return src;
}

bool TGeomObject::Contourize2d(const TMTList<TGCut> &Cuts, TMTList<TGCut> &contour, TGPoint *begin)
{
	TMTList<TGCut> cuts;
	cuts.Assign((TMyObject *)&Cuts);
	contour.Clear();
	FillCutsFlags(flMARK, gfFALSE);
	FillCutsFlags(cuts, flMARK, gfTRUE);
	FillCutsFlags(cuts, flBELONG, gfFALSE);

	if (begin == NULL) 
		begin = GetLowestPoint2d(cuts);					//Находим самую нижнюю точку
	TGCut	*cut = begin->GetTurnLeftCut(true);		//Находим отрезок, самый поворачивающий направо
//	TGCut	*begCut = cut;
	TGPoint *dst = begin;//cut->GetAnotherPoint(begin);
	int i=0;
	do
	{
		cut->Flags.Belong = gfTRUE;
		contour.Add(cut);

		dst = cut->GetAnotherPoint(dst);
		cut = dst->GetTurnLeftCut(cut, true);
		if (i>Cuts.Count*100)
				break;

		if (!cut)	
			return false;
//			throw EMyException("TGObject::Contourize2d:: nxtCut is NULL!");
		i++;
	}
	while( dst != begin || (dst == begin && cut->Flags.Belong == gfFALSE));
//	while( cut != begCut );

	return true;
}

bool TGeomObject::Polygonize2d(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly)
{
	if (Cuts.Count<3)
		return false;

	TMTList<TGCut> cuts;
	cuts.Assign((TMyObject *)&Cuts);
	
//	StructureFix(cuts, sfxREMOVE_BRANCHES | sfxREMOVE_REPEATED);
	Fix.Repeated(cuts);
	Fix.Branches(cuts);
		

	FillCutsFlags(flMARK | flCONTOUR, gfFALSE);
	FillCutsFlags(cuts, flMARK, gfTRUE);


		
	poly.Clear();

	if (cuts.Count<3)
		return false;

	while(cuts.Count>2)		
	{             
		TGPoint *begin = GetLowestPoint2d(cuts);
		TGCut	*cut = begin->GetTurnLeftCut(true);
		if (!cut)	
			throw EMyException("TGObject::Polygonize2d:: firstCut is NULL!");
		TGCut	*begCut = cut;
		TGPoint *dst = cut->GetAnotherPoint(begin);

		if (cut->FFlags.Contour != gfTRUE)
		{
			TMTList <TGCut> contour;
			Contourize2d(cuts, contour, begin);
			FillCutsFlags(contour, flCONTOUR, gfTRUE);
			for (int i=0;i<contour.Count;i++)
				for (int j=i+1;j<contour.Count;j++)
					if (contour.Items[i] == contour.Items[j])
						cuts.Remove(contour.Items[i]);
			
			FillCutsFlags(flMARK, gfFALSE);
			FillCutsFlags(cuts, flMARK, gfTRUE);

			begin = GetLowestPoint2d(cuts);
			cut = begin->GetTurnLeftCut(true);
			if (!cut)	
				throw EMyException("TGObject::Polygonize2d:: firstCut is NULL!");
			begCut = cut;
			dst = cut->GetAnotherPoint(begin);
		}

		poly.Add(new TMTList<TGCut>);
//		poly.Last()->Add(cut);
		int i=0;
		do
//		while( dst != begin )//;
		{
			if (i>cuts.Count*5)
			{
				ErrorMsg("Cannot Polygonize");
				poly.Clear();
				poly.Add(new TMTList<TGCut>);
				poly[0].Assign((TMTList<TGCut>*)&Cuts);
				return false;                           
			}	
			cut = dst->GetTurnRightCut(cut, true);

			if (!cut)	
				throw EMyException("TGObject::Polygonize2d:: nxtCut is NULL!");

			dst = cut->GetAnotherPoint(dst);
			poly.Last()->Add(cut);
			i++;
		}
		while(cut != begCut);

		for (int i=0;i<poly.Last()->Count;i++)
			if (poly.Last()->Items[i]->FFlags.Contour == gfTRUE)
			{
				poly.Last()->Items[i]->Flags.Mark = gfFALSE;
				cuts.Remove(poly.Last()->Items[i]);
			}	
			else
				poly.Last()->Items[i]->FFlags.Contour = gfTRUE;
	}
	return true;
}


void TGeomObject:: FillCutsTag(int ID)
{
	for (int i=0;i<FCuts.Count;i++)
		FCuts[i].Tag = ID;
}


void TGeomObject::FillCutsFlags(TClassifyFlags Flag, TClassify State)
{
	FillCutsFlags(FCuts, Flag, State);
}

void TGeomObject::FillCutsFlags(TMTList <TGCut> &cuts, TClassifyFlags Flag, TClassify State)
{
	for (int i=0;i<cuts.Count;i++)
		SetFlag(cuts[i].FFlags, Flag, State);
}
void TGeomObject::FillPolygonsFlags(TClassifyFlags Flag, TClassify State)
{
	FillPolygonsFlags(FPolygons, Flag, State);
}
void TGeomObject::FillPolygonsFlags(TMTList <TGPolygon> &poly, TClassifyFlags Flag, TClassify State)
{
	for (int i=0;i<poly.Count;i++)
	{
		SetFlag(poly[i].FFlags, Flag, State);
		for (int j=0;j<poly[i].FHoles.Count;j++)
			SetFlag(poly[i].FHoles[j].FFlags, Flag, State);
	}	
}

void TGeomObject::FillPointsFlags(TMTList<TMyObject> &what, TClassifyFlags fl, TClassify gf)
{
	for (int i=0;i<what.Count;i++)
		if (what.Items[i])
		{
			if (what[i].DynamicType == TGPoint::StaticType)
			{
					TGPoint *Element = (TGPoint *)what.Items[i];
					SetFlag(Element->Flags, fl, gf);
			} else if (what[i].DynamicType == TGCut::StaticType)
			{
					TGCut *Element = (TGCut *)what.Items[i];
					SetFlag(Element->Src->Flags, fl, gf);
					SetFlag(Element->Dst->Flags, fl, gf);
			} else if (what[i].DynamicType == TGPolygon::StaticType)
			{
				TGPolygon *Element = (TGPolygon *)what.Items[i];
				for (int j=0;j<Element->Count;j++)
				{
					SetFlag(Element->GetCut(j).Src->Flags, fl, gf);
					SetFlag(Element->GetCut(j).Dst->Flags, fl, gf);
				}	
				for (int k=0;k<Element->FHoles.Count;k++)
					for (int j=0;j<Element->FHoles[k].Count;j++)
					{
						SetFlag(Element->FHoles[k].GetCut(j).Src->Flags, fl, gf);
						SetFlag(Element->FHoles[k].GetCut(j).Dst->Flags, fl, gf);
					}	
			} else
			{
				throw EMyException(what[i].DynamicType->Name + " <TGeomObject::TransformToPlane> : неверный тип!");
			}	
		}	  
}

void TGeomObject::FillPointsFlags(TClassifyFlags Flag, TClassify State)
{
	FillPointsFlags(FVertex, Flag, State);
}
void TGeomObject::FillPointsFlags(TMTList <TGPoint> &point, TClassifyFlags Flag, TClassify State)
{
	for (int i=0;i<point.Count;i++)
		SetFlag(point[i].FFlags, Flag, State);
}


void TGeomObject:: FillPointsTag(const int ID)
{
	for (int i=0;i<FVertex.Count;i++)
		FVertex[i].Tag = ID;
}


void TGeomObject::CachePoints(TMTList <TGPoint> &pnt)
{
	for (int i=0;i<pnt.Count;i++)
		pnt[i].Cache();
}

void TGeomObject::RestorePoints(TMTList <TGPoint> &pnt)
{
	for (int i=0;i<pnt.Count;i++)
		pnt[i].Restore();
}

void TGeomObject::CachePoints()
{
	CachePoints(FVertex);
}

void TGeomObject::RestorePoints()
{
	RestorePoints(FVertex);
}

void TGeomObject::Cache(TMTList <TMyObject> &pnt)
{
	FillPointsFlags(flMARK, gfFALSE);
	FillPointsFlags(pnt, flMARK, gfTRUE);
	for (int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark == gfTRUE)	
			FVertex[i].Cache();
}
void TGeomObject::Restore(TMTList <TMyObject> &pnt)
{
	FillPointsFlags(flMARK, gfFALSE);
	FillPointsFlags(pnt, flMARK, gfTRUE);
	for (int i=0;i<FVertex.Count;i++)
		if (FVertex[i].FFlags.Mark == gfTRUE)	
			FVertex[i].Restore();
}


TGCut *TGeomObject::CompositeCuts(TGCut *c1, TGCut *c2)
{
	TGPoint *pnt = c1->CanConnect(*c2);
	if (!pnt)
		return NULL; 

	if (!TMTListCompare(c1->FPlane, c2->FPlane))	
		return NULL;

	TGPoint *newSrc = pnt->FCuts[0].GetAnotherPoint(pnt);
	TGPoint *newDst = pnt->FCuts[1].GetAnotherPoint(pnt);

	TMTList <TGPolygon> plane;
	TMDelTList <int> index;

	plane.Assign(&c1->FPlane);
	TGeomFlags flag = FlagUnite(c1->FFlags, c2->FFlags);

	FCuts.Remove(c1);

	for (int i=0;i<plane.Count;i++)
		if (plane.Items[i])
			index.Add( new int( plane[i].FCuts.IndexOf(c2) ) );

	FCuts.Remove(c2);

	if (!pnt->Used())
		Delete(pnt);

	TGCut *newCut = AddCut(newSrc, newDst);
	newCut->FFlags = flag;

	for (int i=0;i<plane.Count;i++)
		if (plane.Items[i])
			if (newCut->FPlane.IndexOf(plane.Items[i]) == -1)
				newCut->AddPlane(plane.Items[i]);

	for (int i=0;i<plane.Count;i++)
		if (plane.Items[i])
		{
			if (plane[i].FCuts.IndexOf(newCut) == -1)
				plane[i].FCuts.Insert(index[i], newCut);
			plane[i].FClosed = true;
		}
	return newCut;	
}

void TGeomObject::CalculateNormals()
{
	for (int i =0;i<FPolygons.Count;i++)
		FPolygons[i].CalculatePlane();
}



void TGeomObject::CollapsePoints(TMTList <TGPoint> pnt)
{
	for (int i=0;i<pnt.Count;i++)	
		for (int j=i+1;j<pnt.Count;j++)	
			if (pnt.Items[i] == pnt.Items[j])
				pnt.Delete(j--);
	if(pnt.Count<2)
		return;
	TIntVec newPnt;
	for (int i=0;i<pnt.Count;i++)
		newPnt += pnt[i].Point;
	newPnt /= pnt.Count;
	pnt[0].Point = newPnt;
	for (int i=1;i<pnt.Count;i++)
	{
		for (int j=0;j<pnt[i].FCuts.Count;j++)
		{
			while(pnt[i].FCuts.Count)
			{
				if (pnt[i].FCuts[j].Src == pnt.Items[i])
					pnt[i].FCuts[j].Src = pnt.Items[0];
				else	
					pnt[i].FCuts[j].Dst = pnt.Items[0];
			}
			Delete(pnt.Items[i]);	
		}	
	}	
}

void TGeomObject::SavePolygonAsFigure(int ind, const AnsiString &name)
{
	TMemoryStream* MSS = new TMemoryStream();
	TGeomObject obj;
	obj.CopyPolygonToObject(FPolygons[ind]);
	MBTi a,b;
	obj.FPolygons[0].PlaceOnPlane(a,b,TIntVec(0,0,0));
	obj.WriteData(MSS);
	MSS->SaveToFile(name);
	delete MSS;
}
void TGeomObject::SaveObjectAsFigure(int ind, const TMemoryStream *f)
{
/*	TGeomObject obj;
	obj.Assign(this);
	MBTi a,b,c;
	obj.TransformToPolygon(obj.FPolygons.Items[ind],TIntVec(0,0,0), TIntVec(1,0,0),a,b,c);
	obj.WriteData((TMemoryStream *)f);*/
}
void TGeomObject::SaveCutsAsFigure(const TMTList <TGCut> &cuts, const AnsiString &name)
{
	TGeomObject go;
	for (int i=0;i<cuts.Count;i++)
		go.CopyCutToObject(cuts[i]);
	go.Write(name);	
}


void TGeomObject::SortByLine(const TIntVec &nrm, TMTList <TGPoint> &pnt)
{
	for (int i=0;i<pnt.Count;i++)	
		for (int j=i+1;j<pnt.Count;j++)
			if (DistancePointPlane(pnt[i].Point, nrm, pnt[j].Point)>0)
				pnt.Exchange(i, j);
}
bool TGeomObject::SplitCut(TGCut *c, TGPoint *newPnt)
{
	TGCut *c1, *c2;
	return SplitCut(c, newPnt, c1, c2);
}

//#define GEOMETRY_DEBUG			
bool TGeomObject::SplitCut(TGCut *c, TGPoint *newPnt, TGCut *&Result1, TGCut *&Result2)
{
	Result1 = c;
	Result2 = NULL;
	if (c->ConsistsPoint(newPnt)) 
		return false;

	TGCut *cn = AddCut(c->Src, newPnt);
	TGCut *cn1 = AddCut(newPnt, c->Dst);

	if (cn->FFlags.Alredy == gfFALSE)
	{
		cn->FPlane.Assign(&c->FPlane);
		cn->Assign(c);
	} else
	{
		TMTListUnite(cn->FPlane, c->FPlane);
		cn->FFlags = FlagUnite(cn->FFlags, c->FFlags);
	}
	if (cn1->FFlags.Alredy == gfFALSE)
	{
		cn1->FPlane.Assign(&c->FPlane);
		cn1->Assign(c);
	} else	
	{
		TMTListUnite(cn1->FPlane, c->FPlane);
		cn1->FFlags = FlagUnite(cn1->FFlags, c->FFlags);
	}	

	Result1 = cn;
	Result2 = cn1;

	for (int i=0;i<c->FPlane.Count;i++)
		if (c->FPlane.Items[i])
		{
			int index = c->FPlane[i].FCuts.IndexOf(c);
			if (c->FPlane[i].FCuts.CycVal(index-1).CanConnect(*cn))
			{
#ifdef GEOMETRY_DEBUG			
				if (c->FPlane[i].FCuts.IndexOf(cn1)!=-1 || c->FPlane[i].FCuts.IndexOf(cn)!=-1)
					throw EMyException("<TGeomObject::SplitCut> - эрыюцхэшх юЄЁхчъют!");
#endif				
				if (c->FPlane[i].FCuts.IndexOf(cn1)==-1)
					c->FPlane[i].FCuts.Insert(index, cn1);
				if (c->FPlane[i].FCuts.IndexOf(cn)==-1)
					c->FPlane[i].FCuts.Insert(index, cn);
			}	
			else	
			{
#ifdef GEOMETRY_DEBUG			
				if (c->FPlane[i].FCuts.IndexOf(cn1)!=-1 || c->FPlane[i].FCuts.IndexOf(cn)!=-1)
					throw EMyException("<TGeomObject::SplitCut> - эрыюцхэшх юЄЁхчъют!");
#endif				
				if (c->FPlane[i].FCuts.IndexOf(cn)==-1)
					c->FPlane[i].FCuts.Insert(index, cn);
				if (c->FPlane[i].FCuts.IndexOf(cn1)==-1)
					c->FPlane[i].FCuts.Insert(index, cn1);
			}	
			c->FPlane[i].FCuts.Remove(c);
			c->FPlane.Items[i] = NULL;
		}	

	FCuts.Remove(c);
	UpdateCutPointers(c, Result1, Result2);
	return true;
}
bool TGeomObject::MultiSplitCut(TGCut *c, const TMTList<TGPoint> &newPnt, TMTList<TGCut> &Result)
{
	if (!c)
		throw EMyException("<TGeomObject::MultiSplitCut> : NULL отрезок!");

	Result.Clear();
	TMTList<TGPoint> pnt;
	pnt.Assign(&((TMTList<TGPoint> &)newPnt));
		
	TIntVec nrm = c->Dst->Point - c->Src->Point;

	SortByLine(nrm, pnt);
	
	for (int i=0;i<pnt.Count-1;i++)	
		if (pnt.Items[i] == pnt.Items[i+1])
			pnt.Delete(i--);

	TGCut *current = c;
	for (int i=0;i<pnt.Count;i++)
	{
		TGCut *nc;
		if (!current->ConsistsPoint(pnt.Items[i]))
			SplitCut(current, pnt.Items[i], nc, current);
		else
			continue;	
		Result.Add(nc);
	}
	Result.Add(current);
	return true;
}

bool TGeomObject::MultiSplitCut(TGCut *c, const TMTList<TGPoint> &newPnt)
{
	TMTList <TGCut > res;
	return MultiSplitCut(c, newPnt, res);
}


void TGeomObject::RegisterCutPointers(TMTList <TGCut> *user)
{
	FUserCuts.Add(user);
}

void TGeomObject::UnRegisterCutPointers(TMTList <TGCut> *user)
{
	FUserCuts.Remove(user);
}

void TGeomObject::UnRegisterCutPointersAtAll()
{
	FUserCuts.Clear();
}

void TGeomObject::UpdateCutPointers(TGCut *o, TMTList <TGCut> n)
{
	for (int i=0;i<FUserCuts.Count;i++)
	{
		int ind  = FUserCuts[i].IndexOf(o);
		if (ind!=-1)
		{
			FUserCuts[i].Delete(ind);
			for (int i=0;i<n.Count;i++)
				FUserCuts[i].Insert(ind, n.Items[i]);
				
		}
	}
}
void TGeomObject::UpdateCutPointers(TGCut *o, TGCut *n)
{
	for (int i=0;i<FUserCuts.Count;i++)
	{
		int ind  = FUserCuts[i].IndexOf(o);
		if (ind!=-1)
		{
			FUserCuts[i].Delete(ind);
			FUserCuts[i].Insert(ind, n);
				
		}
	}
}
void TGeomObject::UpdateCutPointers(TGCut *o, TGCut *n, TGCut *n2)
{
/*	if (!n || !n2)
		throw EMyException("<TGeomObject::UpdateCutPointers> :: NULL!!!"); 
	if (n2->DynamicType->Name != TGCut::StaticType->Name ||
		n ->DynamicType->Name != TGCut::StaticType->Name)
		throw EMyException("<TGeomObject::UpdateCutPointers> :: Несовтадение типа!"); 
*/		
	for (int i=0;i<FUserCuts.Count;i++)
	{
		int ind;
		while ( (ind  = FUserCuts[i].IndexOf(o))!=-1 )
		{
			FUserCuts[i].Delete(ind);
			if (FUserCuts[i].IndexOf(n2) == -1)
				FUserCuts[i].Insert(ind, n2);

			if (FUserCuts[i].IndexOf(n) == -1)
				FUserCuts[i].Insert(ind, n);
				
		}
	}
}
void TGeomObject::UpdateCutPointers(TGCut *o)
{
	for (int i=0;i<FUserCuts.Count;i++)
	{
		int ind  = FUserCuts[i].IndexOf(o);
		if (ind!=-1)
			FUserCuts[i].Delete(ind);
	}
}

void TGeomObject::CompositePolygons(const TMTList<TGPolygon> &poly, TMDelTList < TMTList <TGCut> > &res)
{
	TMTList <TGCut> resCuts;
	for (int i=0;i<poly.Count;i++)
		for (int j=0;j<poly[i].FCuts.Count;j++)	
		{
			int n = resCuts.IndexOf(poly[i].FCuts.Items[j]);
			if (n == -1)
				resCuts.Add((TGCut *)poly[i].FCuts.GetItem(j));
			else
				resCuts.Delete(n);	
		}
	if (PolygonizeIsolated(resCuts, res));
}

void TGeomObject::SortCutsByConnect(TMTList <TGCut> &cuts) const
{
	if (cuts.Count<2)
		return;

	for (int i=0;i<cuts.Count;i++)
		for (int j=i+1;j<cuts.Count;j++)
			if (cuts[i].CanConnect(cuts[j]))
			{
				cuts.Move(j,i+1);
				break;
			}
}

void TGeomObject::SaveObjCutsAsFigure(const  AnsiString &name)
{
	SaveCutsAsFigure(FCuts, name);
}

void TGeomObject::DetectHoles2d(TMTList<TGPolygon> &poly)
{
	TMDelTList<TMDelTList<int> > matrix;
	for (int i=0;i<poly.Count;i++)
	{
		matrix.Add(new TMDelTList<int>);
		for (int j=0;j<poly.Count;j++)
			matrix.Last()->Add(new int(0));
	}	
	for (int i=0;i<matrix.Count;i++)
		for (int j=0;j<matrix[i].Count;j++)
			if (i!=j)
			{
				matrix[i][j] = (poly[j].PolygonInPolygon2d(poly[i], PEPS) == pipINSIDE) ? 1 : 0;
//				int mmm = 1;
			}	
			else
				matrix[i][j] = -1;
			
	for (int i=0;i<matrix.Count;i++)
	{
		int max = 0;
		int best = -1;
		
		for (int j=0;j<matrix[i].Count;j++)
			if (matrix[i][j] == 1)
			{
				int counter = 0;
				for (int k=0;k<matrix[j].Count;k++)
					if (matrix[j][k] == 1)
						counter++;
				if (best == -1 || counter>max)
				{
					max = counter;
					best = j;
				}	
			}
		if (best!=-1)
		{
			poly[best].FHoles.Add(poly.Items[i]);
			poly[i].FParent = poly.Items[best];
			FillCutsFlags(poly[i].FCuts, flHOLE, gfTRUE);
			FPolygons.RemoveOnly(poly.Items[i]);
		}	
	}	

	for(int i=0;i<FPolygons.Count;i++)
		if (FPolygons[i].IsHoled())	
			for (int j=0;j<FPolygons[i].FHoles.Count;j++)
				if(FPolygons[i].FHoles[j].IsHoled())
					for (int k=0;k<FPolygons[i].FHoles[j].FHoles.Count;k++)
					{
						FPolygons.Add(FPolygons[i].FHoles[j].FHoles.Items[k]);
						FPolygons[i].FHoles[j].FHoles.RemoveOnly(k--);
					}
}

void TGeomObject::DetectHolesCreatePolygons2d(TMTList<TGPolygon> &poly)
{
	TMDelTList<TMDelTList<int> > matrix;
	for (int i=0;i<poly.Count;i++)
	{
		matrix.Add(new TMDelTList<int>);
		for (int j=0;j<poly.Count;j++)
			matrix.Last()->Add(new int(0));
	}	
	for (int i=0;i<matrix.Count;i++)
		for (int j=0;j<matrix[i].Count;j++)
			if (i!=j)
				matrix[i][j] = (poly[j].PolygonInPolygon2d(poly[i], PEPS) == pipINSIDE) ? 1 : 0;
			else
				matrix[i][j] = -1;
			
	for (int i=0;i<matrix.Count;i++)
	{
		int max = 0;
		int best = -1;
		
		for (int j=0;j<matrix[i].Count;j++)
			if (matrix[i][j] == 1)
			{
				int counter = 0;
				for (int k=0;k<matrix[j].Count;k++)
					if (matrix[j][k] == 1)
						counter++;
				if (best == -1 || counter>max)
				{
					max = counter;
					best = j;
				}	
			}
		if (best!=-1)
			poly[best].AddHole(poly[i].FCuts);
	}	
}

bool TGeomObject::SplitPolygon(TGPolygon *p, TMTList<TGCut> &Ct, TMTList<TGPolygon> &Result)
{
	// Подготовка
	Result.Clear();
	Result.Add(p);
	if (!p || !p->Closed ) 
		return false;
		
	TMTList <TGCut> Cut;
	Cut.Assign(&Ct);

	//Удаляем отрезки, содержащиеся в полигоне
	for (int i=0;i<Cut.Count;i++)
		if (p->FCuts.IndexOf(Cut.Items[i]) != -1)	
			Cut.Delete(i--);
			
	// Удаляем повторные отрезки
	for (int i=0;i<Cut.Count;i++)
		for (int j=i+1;j<Cut.Count;j++)
			if (Cut.Items[i] == Cut.Items[j])
				Cut.Delete(j--);
		
	// Если нечем резать - выходим
	if (!Cut.Count)
		return false;

	TMTList <TGCut> Heap;			// Куча отрезков
	TMTList <TGPoint> polyPnt;		// Точки полинона
	TMDelTList <TGPolygon> Holes;	// Дырки

	// Куча отрезков для разбиения
	Heap.Assign(&p->FCuts);

	for (int i=0;i<Cut.Count;i++)
		Heap.Add(Cut.Items[i]);
	// Не дырки
	FillCutsFlags(Heap, flHOLE, gfFALSE);

	// Помним данные
	TIntVec norm = p->FNormal;
	TIntVec orig = p->Origin;

	// Запоминаем дырки 
	for (int i=0;i<p->FHoles.Count;i++)
	{
		TMTListAdd(Heap, p->FHoles[i].FCuts);
		Holes.Add(p->FHoles.Items[i]);
		p->FHoles.RemoveOnly(i--);
	}	

	// Удаляем повторные отрезки
	for (int i=0;i<Heap.Count;i++)
		for (int j=i+1;j<Heap.Count;j++)
			if (Heap.Items[i] == Heap.Items[j])
				Heap.Delete(j--);
				
	// Удаляем разбиваемый полигон
	FPolygons.Remove(p);
	Result.Clear();

	TMDelTList< TMTList<TGCut> > Poly;		//Полигоны

	// Полигонизируем кучу...
	Fix.BridgesByPolygonize(Heap);
	Polygonize2d(Heap, Poly);

	for (int i=0;i<Poly.Count;i++)
		Result.Add(AddPolygon(Poly[i], norm));	

	// Никто не дырка:)
	FillPolygonsFlags(Result, flHOLE, gfFALSE);

	// Отмечаем полигоны дыками, исходя из того, что полигоны пренадлежат дыркам. Можно оптимизировать, вставив TGPolygon::Equals
	for (int i=0;i<Result.Count;i++)
		for (int j=0;j<Holes.Count;j++)
			if (Holes[j].PolygonInPolygon2d(Result[i], PEPS) == pipINSIDE)
			{
				Result[i].FFlags.Hole = gfTRUE;
				Result[i].FParent = NULL;
				break;
			}	

	// Строим матрицу принадлежностей
	TMDelTList<TMDelTList<int> > matrix;

	for (int i=0;i<Result.Count;i++)
	{
		matrix.Add(new TMDelTList<int>);
		for (int j=0;j<Result.Count;j++)
			matrix.Last()->Add(new int(0));
	}	
	for (int i=0;i<matrix.Count;i++)
		for (int j=0;j<matrix[i].Count;j++)
			if (i!=j)
				matrix[i][j] = (Result[j].PolygonInPolygon2d(Result[i], PEPS) == pipINSIDE) ? 1 : 0;
			else
				matrix[i][j] = -1;

				
	TMTList <TGPolygon> toHell;
	
	for (int i=0;i<matrix.Count;i++)
	{
		int max = 0;
		int best = -1;
		
		for (int j=0;j<matrix[i].Count;j++)
			if (matrix[i][j] == 1)
			{
				int counter = 0;
				for (int k=0;k<matrix[j].Count;k++)
					if (matrix[j][k] == 1)
						counter++;
				if (best == -1 || counter>max)
				{
					max = counter;
					best = j;
				}	
			}
		if (best!=-1)
		{
			Result[best].AddHole(Result[i].FCuts);
		}	
	}
	for (int i=0;i<Result.Count;i++)
		if (Result[i].FFlags.Hole == gfTRUE)
		{
			toHell.Add(Result.Items[i]);
			FPolygons.Remove(Result.Items[i]);
		}		
	TMTListSub(Result, toHell);
				
	return true;	
}
void TGeomObject::ToPrimitiveObj2(TVisPrimitiveObj* VCO, TConstructFlags co, TRenderType render)
{
/*	TGeomObject TmpObj;
	TmpObj.Assign(this);
	TmpObj.FillCutsFlags(flSAME, gfTRUE);
	if ( render == rtCOLOR )
		for ( int i = 0; i < TmpObj.PolygonsCount; i++ )
			TmpObj.GetPolygon(i).Tag = i % 6;
	TmpObj.Triangulate.Triangulate();
	TmpObj.ConstructVCO(VCO, co, render, *this);
	for ( int i = 0; i < CutsCount; i++ )
		GetCut(i).Tag = 0;
	for ( int i = 0; i < PolygonsCount; i++ )
	   GetPolygon(i).Tag = 0;*/
}
/*
void TGeomObject::ConstructVCO(TVisPrimitiveObj* VCO, TConstructFlags co, TRenderType render, TGeomObject& obj)
{
//	VCO->AutoCalcNormals = false;
	TLList<int> SPInds;
	TLList< TLList<int> > FastPointDetect;
	for ( int i = 0; i < FPolygons.Count; i++ )
	{
		FPolygons[i].IndexForSmoothGroups = i;
		FastPointDetect.Add(new TLList<int>);
		for ( int j = 0; j < FPolygons[i].Count; j++ )
			FastPointDetect.Last()->Add(new int(-1));
	}
	for ( int PInd = 0; PInd < VertexCount; PInd++ )
	{
		FillCutsFlags(FVertex[PInd].FCuts, flMARK, gfFALSE);
		//FillPolygonsFlags
		for ( int i = 0; i < FVertex[PInd].FCuts.Count; i++ )
		{
			TGCut& VCuti = FVertex[PInd].FCuts[i];
			for ( int j = 0; j < VCuti.FPlane.Count; j++ )
				if ( VCuti.FPlane.Items[j] != NULL )
					SetFlag(VCuti.FPlane[j].FFlags, flMARK, gfFALSE);
		}
		//FillPolygonsFlags
		for ( int i = 0; i < FVertex[PInd].FCuts.Count; i++ )
		{
			TGCut& VCuti = FVertex[PInd].FCuts[i];
			if ( VCuti.Smooth && VCuti.Flags.Mark == 0 )
			{
				TMTList<TGPolygon>* PLast = new TMTList<TGPolygon>;
				GetSmoothGroup2(FVertex.Items[PInd], i, SPInds.Count, *PLast, FastPointDetect);
				if ( PLast->Count > 0 )
				{
					TIntVec Normal = PLast->Items[0]->Normal;
					for ( int SGi = 1; SGi < PLast->Count; SGi++ )
						Normal += PLast->Items[SGi]->Normal;
					Normal = Normal.Normalize();
					SPInds.Add(new int(VCO->Points->Add( VisMathVec(FVertex[PInd].Point),VisMathVec(Normal),ZEROVEC )));
				}
			}
		}
	}

	if (co & coPOLYGONS)
	{
		if ( render != rtCOLOR )
		{
			VCO->AddPrimitiveArray(GL_TRIANGLES);
			VCO->AddPrimitiveArray(GL_TRIANGLES);
			VCO->AddPrimitiveArray(GL_TRIANGLES);
			switch (render)
			{
				case rtSMOOTH:
					SetMaterial(VCO, VCO->PrimitiveCount-1, 0, (const TColor)clBlack, (const TColor)clSkyBlue, (const TColor)clBlack, (const TColor)clBlack);
					break;
				case rtCLASSIFY :
					SetMaterial(VCO, VCO->PrimitiveCount-3, 0, (const TColor)clBlack, (const TColor)clSkyBlue, clBlack, clBlack);
					SetMaterial(VCO, VCO->PrimitiveCount-2, 1, (const TColor)clBlack, (const TColor)clBlue, clBlack, clBlack);
					SetMaterial(VCO, VCO->PrimitiveCount-1, 2, (const TColor)clBlack, (const TColor)clRed, clBlack, clBlack);
                    break;
                case rtMARK :
                    SetMaterial(VCO, VCO->PrimitiveCount-2, 0, clBlack, clLime, clBlack, clBlack);
                    SetMaterial(VCO, VCO->PrimitiveCount-1, 1, clBlack, clSkyBlue, clBlack, clBlack);
					break;
                case rtERROR:
                    SetMaterial(VCO, VCO->PrimitiveCount-1, 0, clBlack, clWhite, clBlack, clBlack);
                    break;
            }
        }
        for ( int i = 0; i < FPolygons.Count; i++ )
            if (FPolygons[i].Closed)
            {
                if ( render == rtCOLOR )
                {
                    VCO->AddPrimitiveArray(GL_TRIANGLES);
//                    SetMaterial(VCO, VCO->PrimitiveCount-1, FPolygons[i].Tag + 3, clBlack, colors[FPolygons[i].Tag], clBlack, clBlack);
                }
				TIntVec Normal = FPolygons[i].Normal;
				for ( int j = FPolygons[i].Count-1; j >= 0; j-- )
                {
                    TGPoint* TmpP = &FPolygons[i].GetPoint(j);
                    if ( FastPointDetect[i][j] == -1 )
                        if ( (FPolygons[i].Tag == gfTRUE && render == rtMARK) || (FPolygons[i].Flags.Origin == gfPOSITIVE && render == rtCLASSIFY) )
                            VCO->AddIndex( VCO->Points->Add( VisMathVec(TmpP->Point),VisMathVec(Normal),ZEROVEC ), VCO->PrimitiveCount-2 );
                        else
                            if ( FPolygons[i].Flags.Origin != gfNEGATIVE && render == rtCLASSIFY )
                                VCO->AddIndex( VCO->Points->Add( VisMathVec(TmpP->Point),VisMathVec(Normal),ZEROVEC ), VCO->PrimitiveCount-3 );
                            else
                                VCO->AddIndex( VCO->Points->Add( VisMathVec(TmpP->Point),VisMathVec(Normal),ZEROVEC ), VCO->PrimitiveCount-1 );
					else
                        if ( (FPolygons[i].Tag == gfTRUE && render == rtMARK) || (FPolygons[i].Flags.Origin == gfPOSITIVE && render == rtCLASSIFY) )
                            VCO->AddIndex( SPInds[FastPointDetect[i][j]] , VCO->PrimitiveCount-2 );
                        else
                            if ( FPolygons[i].Flags.Origin != gfNEGATIVE && render == rtCLASSIFY )
                                VCO->AddIndex( SPInds[FastPointDetect[i][j]] , VCO->PrimitiveCount-3 );
                            else
                                VCO->AddIndex( SPInds[FastPointDetect[i][j]] , VCO->PrimitiveCount-1 );
                }
            }
    }

	if ((co & coPOINTS) && (render != rtERROR) )
	{
		if ( render != rtCOLOR )
        {
            VCO->AddPrimitiveArray(GL_POINTS);
            VCO->AddPrimitiveArray(GL_POINTS);
            switch (render)
            {
                case rtSMOOTH:
                    SetMaterial(VCO, VCO->PrimitiveCount-1, 9, clBlack, clBlack, clRed, clBlack);
                    break;
                case rtCOLOR:
                    SetMaterial(VCO, VCO->PrimitiveCount-1, 9, clBlack, clBlack, clRed, clBlack);
                    break;
				case rtMARK :
                    SetMaterial(VCO, VCO->PrimitiveCount-2, 9, clBlack, clBlack, clLime, clBlack);
                    SetMaterial(VCO, VCO->PrimitiveCount-1, 10, clBlack, clBlack, clRed, clBlack);
                    break;
            }
        }
		for ( int i = 0; i < obj.VertexCount; i++ )
        {
            if ( render == rtCOLOR )
            {
                VCO->AddPrimitiveArray(GL_POINTS);
//                SetMaterial(VCO, VCO->PrimitiveCount-1, i % 6 + 11, clBlack, clBlack, colors[i % 6], clBlack);
            }
            if ( obj.FVertex[i].Tag == gfTRUE )
				VCO->AddIndex( VCO->Points->Add( VisMathVec(obj.FVertex[i].Point), ZEROVEC, ZEROVEC ), VCO->PrimitiveCount-2 );
            else
                VCO->AddIndex( VCO->Points->Add( VisMathVec(obj.FVertex[i].Point), ZEROVEC, ZEROVEC ), VCO->PrimitiveCount-1 );
        }
	}

	if (co & coCUTS)
	{
        if ( render != rtCOLOR )
        {
            VCO->AddPrimitiveArray(GL_LINES);
            VCO->AddPrimitiveArray(GL_LINES);
			switch (render)
            {
                case rtSMOOTH:
                    SetMaterial(VCO, VCO->PrimitiveCount-2, 17, clBlack, clBlack, (TColor)0x000080FF, clBlack);
                    SetMaterial(VCO, VCO->PrimitiveCount-1, 18, clBlack, clBlack, clYellow, clBlack);
                    break;
                case rtMARK :
                    SetMaterial(VCO, VCO->PrimitiveCount-2, 17, clBlack, clBlack, clLime, clBlack);
                    SetMaterial(VCO, VCO->PrimitiveCount-1, 18, clBlack, clBlack, clYellow, clBlack);
                    break;
                case rtERROR:
                    SetMaterial(VCO, VCO->PrimitiveCount-1, 18, clBlack, clBlack, clBlack, clBlack);
                    break;
            }
		}
		for ( int i = 0; i < obj.CutsCount; i++ )
			if ( render != rtERROR || !obj.FCuts[i].Smooth )
//            if ( obj.FCuts[i].FFlags.Same )
			{
				if ( render == rtCOLOR )
				{
					VCO->AddPrimitiveArray(GL_LINES);
//                    SetMaterial(VCO, VCO->PrimitiveCount-1,  i % 6 + 19, clBlack, clBlack, colors[i % 6], clBlack);
				}

				if ( ( obj.FCuts[i].Tag == gfTRUE && render == rtMARK) || (obj.FCuts[i].Smooth && render == rtSMOOTH) )
				{
					VCO->AddIndex(VCO->Points->Add( VisMathVec(obj.GetCut(i).Src->Point), ZEROVEC,ZEROVEC ),VCO->PrimitiveCount-2);
					VCO->AddIndex(VCO->Points->Add( VisMathVec(obj.GetCut(i).Dst->Point), ZEROVEC,ZEROVEC ), VCO->PrimitiveCount-2);
				}else
				{
					VCO->AddIndex(VCO->Points->Add( VisMathVec(obj.GetCut(i).Src->Point), ZEROVEC,ZEROVEC ),VCO->PrimitiveCount-1);
					VCO->AddIndex(VCO->Points->Add( VisMathVec(obj.GetCut(i).Dst->Point), ZEROVEC,ZEROVEC ), VCO->PrimitiveCount-1);
				}
			}
	}

	if ((co & coNORMALS) && (render != rtERROR))
	{
		VCO->AddPrimitiveArray(GL_LINES);
		SetMaterial(VCO, VCO->PrimitiveCount-1,  25, clBlack, clBlack, clRed, clBlack);
		for ( int i = 0; i < obj.FPolygons.Count; i++ )
		{
			TIntVec src = obj.FPolygons[i].GetMidOrigin();
			TIntVec dst;

			dst = src + obj.FPolygons[i].Normal/2;
			VCO->AddIndex(VCO->Points->Add( VisMathVec(src), ZEROVEC, ZEROVEC), VCO->PrimitiveCount-1);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(dst), ZEROVEC, ZEROVEC), VCO->PrimitiveCount-1);
		}
	}

	if (co & coPOLYGONHOLES)
	{
		VCO->AddPrimitiveArray(GL_TRIANGLES);
		if ( render == rtERROR )
			SetMaterial(VCO, VCO->PrimitiveCount-1, 26, clBlack, clBlack, clBlack, clBlack);
		else
			SetMaterial(VCO, VCO->PrimitiveCount-1, 26, clBlack, clTeal, clBlack, clBlack);
		VCO->Primitive[VCO->PrimitiveCount-1]->Material->ColorDiffuse->Alpha = 0.5;
		for ( int k = 0; k < obj.FPolygons.Count; k++ )
			for ( int i = 0; i < obj.FPolygons[k].FHoles.Count; i++ )
			{
				TMTList<TGPolygon> poly;
				PolygonTriangulate(obj.FPolygons[k].FHoles.Items[i], poly);

				TIntVec Normal = obj.FPolygons[k].Normal;
//                Normal = TIntVec(-Normal.x, -Normal.y, -Normal.z);
				for ( int j = 0; j < poly.Count; j++ )
    				for ( int d = 0; d < poly[j].Count; d++ )
                    {
                        TGPoint* TmpP = &poly[j].GetPoint(d);
                        VCO->AddIndex( VCO->Points->Add( VisMathVec(TmpP->Point),VisMathVec(Normal),ZEROVEC ), VCO->PrimitiveCount-1 );
                    }
            }
    }

}

void TGeomObject::GetSmoothGroup2(TGPoint* Pnt, int CutIndex, int CurGroupInd, TMTList<TGPolygon>& Poly, TLList< TLList<int> >& FastPointDetect)
{
	Pnt->FCuts[CutIndex].Flags.Mark = 1;
	for ( int i = 0; i < Pnt->FCuts[CutIndex].FPlane.Count; i++ )
	{
		TGPolygon* TmpPoli = Pnt->FCuts[CutIndex].FPlane.Items[i];
		if ( TmpPoli != NULL )
		{
			int GrInd = TmpPoli->IndexForSmoothGroups;
			for ( int j = 0; j < Pnt->FCuts.Count; j++ )
			  if ( CutIndex != j )
				if ( TmpPoli->Flags.Mark == 0 &&
					 TmpPoli->FCuts.IndexOf(Pnt->FCuts.Items[j]) != -1 )
				{
					Poly.Add(TmpPoli);
//                    int GrInd = FPolygons.IndexOf(Pnt->FCuts[CutIndex].FPlane.Items[i]);
					for ( int PInd = 0; PInd < TmpPoli->Count; PInd++ )
						if ( &TmpPoli->GetPoint(PInd) == Pnt )
						{
							FastPointDetect[GrInd][PInd] = CurGroupInd;
							break;
                        }
                    Pnt->FCuts[CutIndex].FPlane[i].Flags.Mark = 1;
                    if ( Pnt->FCuts[j].Smooth && Pnt->FCuts[j].Flags.Mark == 0 )
                        GetSmoothGroup2(Pnt, j, CurGroupInd, Poly, FastPointDetect);
                }
        }
    }
}

void TGeomObject::PolygonTriangulate(TGPolygon* p, TMTList<TGPolygon>& poly)
{
	TGTriangulate CTrian(*this);
	TMTList<TGCut> TmpCuts;

	TGPolygon* GHP = p;
	TIntVec TmpNormal = GHP->FNormal;
	TIntVec ang;
	ang = GetToPlaneTransformation(TmpNormal);
	for ( int i = 0; i < GHP->Count; i++ )
		GHP->GetPoint(i).Point = TransformTo(GHP->GetPoint(i).Point, ang);

	for (int i = 0; i < GHP->FHoles.Count; i++ )
		for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
			GHP->FHoles.Items[i]->GetPoint(j).Point = TransformTo(GHP->FHoles.Items[i]->GetPoint(j).Point, ang);

    TmpCuts.Clear();
//        TmpVertex.Clear();
//        TmpVertex.Assign(&obj.FVertex);
    TmpCuts.Assign(CTrian.Triangulate(GHP));
//        obj.FVertex.Assign(&TmpVertex);

    for ( int i = 0; i < GHP->Count; i++ )
        GHP->GetPoint(i).Point = TransformFrom(GHP->GetPoint(i).Point, ang);

    for (int i = 0; i < GHP->FHoles.Count; i++ )
        for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
			GHP->FHoles.Items[i]->GetPoint(j).Point = TransformFrom(GHP->FHoles.Items[i]->GetPoint(j).Point, ang);

    for ( int i = 0; i < TmpCuts.Count; i+=3 )
    {
        TMTList<TGCut> TmpCutsToPoly;
        TmpCutsToPoly.Add(AddCutFast(TmpCuts[i+2].Src->Point, TmpCuts[i+2].Dst->Point));
        TmpCutsToPoly.Add(AddCutFast(TmpCuts[i+1].Src->Point, TmpCuts[i+1].Dst->Point));
        TmpCutsToPoly.Add(AddCutFast(TmpCuts[i].Src->Point, TmpCuts[i].Dst->Point));
        poly.Add(AddPolygon( TmpCutsToPoly, TmpNormal));
        FPolygons.Last()->Tag = p->Tag;
    }
}
*/
