//---------------------------------------------------------------------------

#include <vcl.h>                                                  
#include "Usefuls.h"  
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"                                    
#pragma hdrstop

#include "GeomObjV.h"

#include "MyGL.h"///!!!!!!!!
#include "Poligon.h"///!!!!!!!!
#pragma package(smart_init)

//#define DO_NOT_FREE_UNUSED
#define INITIALIZE_EPSILON 0.5

//---------------------------------------------------------------------------
#pragma package(smart_init)

void RegisterGeomObject()
{
	TGCut();
	TGPoint();
	TGPolygon();
}

#pragma startup RegisterGeomObject

TClassNode* TGeomObject::StaticType = NULL;

const AnsiString aVERT = "Points";
const AnsiString aCUT = "Cuts";
const AnsiString aPOLY = "Polygons";

TGeomObject::TGeomObject()
{
	RegisterNewClass< TMyObject, TGeomObject >(this, false, &CreateFunction);
	RegisterField(&FVertex,	&aVERT, mtMyObject);
	RegisterField(&FCuts, &aCUT, mtMyObject);
	RegisterField(&FPolygons, &aPOLY, mtMyObject);

	CreateCutFunction = TGCut::StaticType->CreateFunction;
	CreatePointFunction = TGPoint::StaticType->CreateFunction;
	CreatePolygonFunction = TGPolygon::StaticType->CreateFunction;
	SnapPoints = true;
	PEPS = INITIALIZE_EPSILON;
}							 

void TGeomObject::Assign(TMyObject* MO)
{
	if (!MO->Is(TGeomObject::StaticType) )
		throw EMyException("Copying error");
	Clear();
	TMyObject::Assign((TMyObject *)MO);

	TGeomObject *GO = (TGeomObject *)MO;

	TMDelTList <int> indices;

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
	}
}
void TGeomObject::Append(TGeomObject &go)
{
	TMTList <TGPoint> pnts;
	TMTList <TGCut> cuts;

	for (int i(0);i<go.FVertex.Count;i++)
		pnts.Add(AddPoint(go.FVertex[i].Point));

	for (int i(0);i<go.FCuts.Count;i++)
		cuts.Add(AddCut(pnts.Items[go.IndexOf(go.FCuts[i].Src)], pnts.Items[go.IndexOf(go.FCuts[i].Dst)]));

	for (int i(0);i<go.FPolygons.Count;i++)
	{
		TMTList <TGCut> plcut;
		for (int j(0);j<go.FPolygons[i].FCuts.Count;j++)
			plcut.Add(cuts.Items[go.IndexOf(go.FPolygons[i].FCuts.Items[j])]);
		AddPolygon(plcut);	
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
	FVertex.Delete(index);
}
void TGeomObject::DeleteCut(int index)
{
	FCuts.Delete(index);
}
void TGeomObject::DeletePolygon(int index)
{
	FPolygons.Delete(index);
}

void TGeomObject::Delete(TGPoint *target)
{
	FVertex.Remove(target);
}
void TGeomObject::Delete(TGCut *target)
{
	FCuts.Remove(target);
}
void TGeomObject::Delete(TGPolygon *target)
{
	FPolygons.Remove(target);
}

TGPoint *TGeomObject::AddPoint(const TIntVec &v)
{
	if (SnapPoints)
	{
		if (SnapPointsToNearest)
		{
			TGPoint *p = NULL;
			MBTi ro, old_ro;
			for (int i=0;i<FVertex.Count;i++)
				if ( (( ro = (v-FVertex[i].Point).Length() ) < PEPS) && (!p || ro<old_ro) ) 
				{
					p = FVertex.Items[i];
					old_ro = ro;
				}
			if (p)
			{
				p->FFlags.Alredy = gfTRUE;
				return p;
			}	
		}
		else
		{
			for (int i=0;i<FVertex.Count;i++)
				if (v.Equal(FVertex[i].Point, PEPS)) 
				{
					FVertex[i].FFlags.Alredy = gfTRUE;
					return FVertex.Items[i];
				}	
		}
	}		
	TGPoint *point = (TGPoint *)CreatePointFunction();
	point->Point = v;
	FVertex.Add(point);
	return FVertex.Last();
}

TGPoint *TGeomObject::AddPoint(const TGPoint &p)
{
	return AddPoint(p.Point);
}

TGCut *TGeomObject::ExistsCut(const TGCut &what)
{
	for (int i=0;i<FCuts.Count;i++)
		if (what.Equal(FCuts[i]))
			return FCuts.Items[i];
	return NULL;	
}

TGPoint* TGeomObject::ExistsPoint(const TIntVec& v)
{
	for (int i=0;i<FVertex.Count;i++)
	  if (v.Equal(FVertex[i].Point, PEPS))
	  {
		  FVertex[i].FFlags.Alredy = gfTRUE;
		  return FVertex.Items[i];
	  }
	return NULL;
}                                                                                             


TGCut *TGeomObject::AddCut(TGPoint *p1, TGPoint *p2)
{
	if (FVertex.IndexOf(p1) == -1)
		throw EMyException ("<TGeomObject::AddCut> первой точки нет в отрезке!");

	if (FVertex.IndexOf(p2) == -1)
		throw EMyException ("<TGeomObject::AddCut> второй точки нет в отрезке!");

	if (p2 == p1)
		throw EMyException ("<TGeomObject::AddCut> невозможно добавить отрезок с равными концами!");

	TGCut& cut = *((TGCut *)CreateCutFunction()/*new TGCut*/);

	cut.Src = p1;
	cut.Dst = p2;
	TGCut *n;
	if ((n = ExistsCut(cut))!=NULL)
	{
		delete &cut;
		n->FFlags.Alredy = gfTRUE;
		return n;
	}

	FCuts.Add(&cut);
	return FCuts.Last();
}

TGCut *TGeomObject::AddCut(const TGCut &c)
{
	TGCut *cut = AddCut(c.Src->Point, c.Dst->Point);
	cut->Assign((TGCut *)&c);
	return cut;
}


TGCut *TGeomObject::AddCut(int i1, int i2)
{
	if (i1<FVertex.Count && i2<FVertex.Count)
		return AddCut(&FVertex[i1], &FVertex[i2]);
	else 
		return NULL;
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
	else
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

void TGeomObject::FreeUnused(TFreeUnusedType what)
{
	if (what & fuCuts)
	{    
		for (int i=0;i<FCuts.Count;i++)
			if ( !FCuts[i].Used() )
				FCuts.Delete(i--);
	}
	if (what & fuPoints)
	{
		for (int i=0;i<FVertex.Count;i++)
			if (FVertex[i].CutsCount == 0)
				FVertex.Delete(i--);
	}
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

void TGeomObject::ClosePolygon(TGPolygon *p)
{
	if (p->Closed) return;
	if (p->FCuts.Count<2) return;

	TGPoint *p1 = NULL;
	TGPoint *p2 = NULL;

	if (p->FCuts[0].Src == p->FCuts[1].Src || p->FCuts[0].Src == p->FCuts[1].Dst)
		p1 = p->FCuts[0].Dst;
	else	
		p1 = p->FCuts[0].Src;

	if (p->FCuts[p->FCuts.Count-1].Src == p->FCuts[p->FCuts.Count-2].Src || p->FCuts[p->FCuts.Count-1].Src == p->FCuts[p->FCuts.Count-2].Dst)
		p2 = p->FCuts[p->FCuts.Count-1].Dst;
	else	
		p2 = p->FCuts[p->FCuts.Count-1].Src;

	p->AddCut( AddCut(p1, p2) );
}
void TGeomObject::ClosePolygon(int index)
{
	ClosePolygon(FPolygons.Items[index]);
}
/*
bool TGeomObject::PolygonizeIsolated(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly)
{
	if (Cuts.Count<3)
		return false;

	TMTList<TGCut> cuts;
	cuts.Assign((TMyObject *)&Cuts);
	poly.Clear();

	for (int i=0;i<cuts.Count;i++)
		for (int j=i+1;j<cuts.Count;j++)
			if (cuts[i].CanConnect(cuts[j]))
			{
				cuts.Move(j,i+1);
				break;
			}

	while(cuts.Count>2)		
	{
		TGCut *cut		= cuts.Items[0];
		TGPoint *dst	= cut->Dst;
		TGPoint *begin	= cut->GetAnotherPoint(cut->Dst);
//		TGCut *begCut	= cut;

		poly.Add(new TMTList<TGCut>);
		poly.Last()->Add(cut);
//		do
		while( dst != begin )//;
		{
			cut = dst->GetTurnRightCut(cut, true);

			if (!cut)	
				return false;

			dst = cut->GetAnotherPoint(dst);

			poly.Last()->Add(cut);
		}
//		while( cut != begCut );

		for (int i=0;i<poly.Last()->Count;i++)
			cuts.Remove(poly.Last()->Items[i]);
	}                 
	return true;
}
*/
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
/*
bool HaveClosed(TGPoint *p)
{
	if (!p)
		throw EMyException("HaveClosed : TGPoint * == NULL");
	int count = 0;
	for (int i=0;i<p->CutsCount;i++)
		if (p->GetCut(i).Flags.Contour == gfTRUE)
			count++;
	return (count == p->CutsCount) || (count % 2 == 0);
			
}
*/
/*
void TGeomObject::RemoveBranches(TMTList<TGCut> &cuts)
{
	FillPointsFlags(flMARK, gfFALSE);
	bool WasDeleted = true;
	while ( WasDeleted )
	{
		WasDeleted = false;
		for (int i=0;i<cuts.Count;i++)
		{
			int cnt = 0;
//			if (cuts[i].Src->FFlags.Mark != gfTRUE)
			{
				for (int j=0;j<cuts[i].Src->FCuts.Count;j++)
					if ( cuts.IndexOf( cuts[i].Src->FCuts.Items[j] ) != -1)
						cnt++;
					
//				cuts[i].Src->FFlags.Mark = gfTRUE;
				if (cnt<2)
				{
					//--------------
//					cuts[i].Src->FFlags.Mark = gfFALSE;
//					cuts[i].Dst->FFlags.Mark = gfFALSE;
					cuts.Delete(i--);
					WasDeleted = true;
					continue;
				}
			}
			cnt = 0;
//			if (cuts[i].Dst->FFlags.Mark != gfTRUE)
			{
				for (int j=0;j<cuts[i].Dst->FCuts.Count;j++)
					if ( cuts.IndexOf( cuts[i].Dst->FCuts.Items[j] ) != -1)
						cnt++;
					
//				cuts[i].Dst->FFlags.Mark = gfTRUE;
				if (cnt<2)
				{
					//--------------
//					cuts[i].Src->FFlags.Mark = gfFALSE;
//					cuts[i].Dst->FFlags.Mark = gfFALSE;
					cuts.Delete(i--);
					WasDeleted = true;
					continue;
				}
			}	
		}
	}
}
void TGeomObject::RemoveBranches()
{
	RemoveBranches(FCuts);
}
*/

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
			if (MessageBox(NULL,"Получено в 100 раз больше отрезков, чем входные данные. Возможно, произошло зацикливание. Прервать операцию?", "TGeomObject::Polygonze2d", MB_YESNO | MB_ICONQUESTION | MB_SYSTEMMODAL) == ID_YES)
				break;
			else
				i = 0;	

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
	
	StructureFix(cuts, sfxREMOVE_BRANCHES | sfxREMOVE_REPEATED);
		
/*	for (int i=0;i<cuts.Count;i++)
		if (cuts[i].Src->FCuts.Count<2 || cuts[i].Dst->FCuts.Count<2)
			cuts.Delete(i--);
*/

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

void TGeomObject::DeleteBranches(TMTList<TGCut> &cuts)
{
	FillPointsFlags(flMARK, gfFALSE);
	bool WasDeleted = true;
	while (WasDeleted)
    {
        WasDeleted = false;
		for (int i=0;i<cuts.Count;i++)
        {
            int cnt = 0;
            if (cuts[i].Src->FFlags.Mark != gfTRUE)
            {
                for (int j=0;j<cuts[i].Src->FCuts.Count;j++)
                    if ( cuts.IndexOf( cuts[i].Src->FCuts.Items[j] ) != -1)
                        cnt++;

                cuts[i].Src->FFlags.Mark = gfTRUE;
                if (cnt<2)
                {
   					cuts[i].Dst->FFlags.Mark = gfFALSE;
                    cuts.Delete(i--);
                    WasDeleted = true;
                    continue;
                }
            }
            cnt = 0;
			if (cuts[i].Dst->FFlags.Mark != gfTRUE)
            {
                for (int j=0;j<cuts[i].Dst->FCuts.Count;j++)
                    if ( cuts.IndexOf( cuts[i].Dst->FCuts.Items[j] ) != -1)
						cnt++;

                cuts[i].Dst->FFlags.Mark = gfTRUE;
                if (cnt<2)
                {
   					cuts[i].Src->FFlags.Mark = gfFALSE;
                    cuts.Delete(i--);
                    WasDeleted = true;
                    continue;
                }
            }
        }
    }
}

bool TGeomObject::drPolygonize(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly)
{
	if (Cuts.Count<3)
		return false;

	TMTList<TGCut> cuts;
	cuts.Assign((TMyObject *)&Cuts);
	FillPointsFlags(flMARK, gfFALSE);


/*	for (int i=0;i<cuts.Count;i++)
		if (cuts[i].Src->FCuts.Count<2 || cuts[i].Dst->FCuts.Count<2)
			cuts.Delete(i--);
*/

	poly.Clear();

	FillCutsFlags(flMARK | flCONTOUR, gfFALSE);
	FillCutsFlags(cuts, flMARK, gfTRUE);

    DeleteBranches(cuts);
	while(cuts.Count>2)
	{
//DeleteBranches(cuts);
		if (cuts.Count<3)
			break;

		TGPoint *begin = GetLowestPoint2d(cuts);
		TGCut	*cut = begin->GetTurnLeftCut(true);
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
                		throw EMyException("drPolygonize: ветки после Contourize");
						//cuts.Remove(contour.Items[i]);

			begin = GetLowestPoint2d(cuts);
			cut = begin->GetTurnLeftCut(true);
			begCut = cut;
			dst = cut->GetAnotherPoint(begin);
		}
		poly.Add(new TMTList<TGCut>);
//		poly.Last()->Add(cut);
		int i=0;
		do
//		while( dst != begin )//;
		{
			if (i>cuts.Count)
			{
				ErrorMsg("Cannot Polygonize");
				poly.Clear();
				poly.Add(new TMTList<TGCut>);
				poly[0].Assign((TMTList<TGCut>*)&Cuts);
				return false;
			}
			cut = dst->GetTurnRightCut(cut, true);

			if (!cut)
				return false;

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


void TGeomObject::ClassifyPolygons(const TIntVec &n, const TIntVec &o, MBTi EPS)
{
	for (int i=0;i<FPolygons.Count;i++)
		FPolygons[i].FFlags.Origin = FPolygons[i].ClassifyByPlane(n, o, EPS);
}

int closed = true;
bool TGeomObject::ClassifySolidRecursive(TGPolygon *p)
{
	p->Flags.Mark = gfTRUE;

	for (int i=0;i<p->FCuts.Count;i++)
		if (!p->FCuts[i].Closed)
			return p->FFlags.Solid = gfFALSE;
					
	for (int i=0;i<p->FCuts.Count;i++)
		for (int j=0; j<p->FCuts[i].FPlane.Count;j++)
			if (p->FCuts[i].FPlane.Items[j] && p->FCuts[i].FPlane.Items[j] != p)
				if (!p->FCuts[i].FPlane.Items[j]->Flags.Mark && !ClassifySolidRecursive( p->FCuts[i].FPlane.Items[j]))
					return p->FFlags.Solid = gfFALSE; 
	return p->FFlags.Solid = gfTRUE;
}

void TGeomObject::ClassifySolid()
{
	closed = true;
	FillPolygonsFlags(flMARK, gfFALSE);
	for (int i=0;i<FPolygons.Count;i++)
		if (!FPolygons[i].Flags.Mark)
			ClassifySolidRecursive(FPolygons.Items[i]);
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

TGeomFlags FlagUnite(TGeomFlags &a, TGeomFlags &b)
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


void TGeomObject::CachePoints()
{
	PointsCache.Add(new TMDelTList <TCachedPoint>);
	for (int i=0;i<FVertex.Count;i++)
		PointsCache.Last()->Add(new TCachedPoint(FVertex.Items[i]));
}
void TGeomObject::RestorePoints()
{
	if (!PointsCache.Count)
		throw EMyException("<TGeomObject::RestorePoints> : В стеке ничего нет!");
	for (int i=0;i<PointsCache.Last()->Count;i++)
		if (FVertex.IndexOf(PointsCache.Last()->Items[i]->Target)!=-1)
		{
			PointsCache.Last()->Items[i]->Restore();
		}
	PointsCache.Remove(PointsCache.Last());
	if (PointsCache.Count>0)
	{
		FillPointsFlags(flCACHED, gfFALSE);
		for (int i=0;i<PointsCache.Last()->Count;i++)
			if (FVertex.IndexOf(PointsCache.Last()->Items[i]->Target)!=-1)
					PointsCache.Last()->Items[i]->Target->FFlags.Cached = gfTRUE;
	}		
}
TGCut *TGeomObject::DeletePointBetweenCollinear(TGPoint *pnt)
{
	if (FVertex.IndexOf(pnt) == -1)
		return NULL;
	if (pnt->FCuts.Count != 2)
		return NULL;

	TGCut *c1 = pnt->FCuts.Items[0];
	TGCut *c2 = pnt->FCuts.Items[1];

	if (c1->FPlane.Count!=c2->FPlane.Count)
		return NULL;

	for (int i=0;i<c1->FPlane.Count;i++)
	{
		bool found = false;
		for (int j=0;j<c1->FPlane.Count;j++)
			if (c1->FPlane.Items[i] == c2->FPlane.Items[j])
			{
				found = true;
				break;
			}
		if (!found)
			return NULL;
	}
	
/*	if (!c1->Left || !c1->Right)	
		return;
*/
	
	TGPoint *newSrc = pnt->FCuts[0].GetAnotherPoint(pnt);
	TGPoint *newDst = pnt->FCuts[1].GetAnotherPoint(pnt);

/*	TIntVec n1 = (newSrc->Point - pnt->Point).Normalize();
	TIntVec n2 = (newDst->Point - pnt->Point).Normalize()*(-1);
*/
	if (!VectorsParallel(newSrc->Point - pnt->Point, newDst->Point - pnt->Point, PEPS))
		return NULL;
	TMTList <TGPolygon> plane;
	TMDelTList <int> index;

	plane.Assign(&c1->FPlane);
	TGeomFlags flag;
	flag = c1->FFlags;

	FCuts.Remove(pnt->FCuts.Items[0]);

	for (int i=0;i<plane.Count;i++)
		if (plane.Items[i])
			index.Add( new int( plane[i].FCuts.IndexOf(pnt->FCuts.Items[0]) ) );

	FCuts.Remove(pnt->FCuts.Items[0]);
	FVertex.Remove(pnt);

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

void TGeomObject::SynchronizePolygonsWisesRecursive(TGPolygon *p)
{
	p->Flags.Mark = gfTRUE;
	for (int i=0;i<p->FHoles.Count;i++)
		if  (p->FHoles[i].FFlags.Mark == gfFALSE)
		{
			TIntVec P_Normal = p->Normal;
			TIntVec H_Normal = p->FHoles[i].Normal;
			if ( (P_Normal-H_Normal).Length()>(P_Normal+H_Normal).Length() )
				p->FHoles[i].Invert();				
			SynchronizePolygonsWisesRecursive( p->FHoles.Items[i] );
		}
	for (int i=0;i<p->FCuts.Count;i++)
		for (int j=0;j<p->FCuts[i].FPlane.Count;j++)
			if (p->FCuts[i].FPlane.Items[j] && p->FCuts[i].FPlane.Items[j] != p)
			{
				TGPolygon *o = p->FCuts[i].FPlane.Items[j];
				if (o->FFlags.Mark == gfTRUE)
					continue;
				TGCut *pCut = p->FCuts.CycleItems[ i + 1];
				TGCut *oCut = o->FCuts.CycleItems[ o->FCuts.IndexOf(p->FCuts.Items[i]) + 1];
				if (!pCut || !oCut)
					throw EMyException("<SynchronizePolygonsWisesRecursive> : что-то не так!");
				if ( (pCut->CanConnect(*oCut)!=NULL) + (p->FParent!=NULL + o->FParent!=NULL == 1) == 1)
					o->Invert();
				SynchronizePolygonsWisesRecursive(o);
			}	
	if (p->FParent && p->FParent->FFlags.Mark == gfFALSE)
	{
		TIntVec P_Normal = p->Normal;
		TIntVec PP_Normal = p->FParent->Normal;
		if ( (P_Normal-PP_Normal).Length()>(P_Normal+PP_Normal).Length() )
			p->FParent->Invert();				
		SynchronizePolygonsWisesRecursive(p->FParent);
	}
}

void TGeomObject::SynchronizePolygonsWises(TGPolygon *p)
{
	if (!FPolygons.Count)
		return;
/*	if (!p)
		p = FPolygons.Items[0];
	if (!p)	
		return;                */

	FillPolygonsFlags(flMARK, gfFALSE);
//	SynchronizePolygonsWisesRecursive(FPolygons.Items[0]);
	for (int i=0;i<FPolygons.Count;i++)
		if (!FPolygons[i].Flags.Mark)
			SynchronizePolygonsWisesRecursive(FPolygons.Items[i]);
}
void TGeomObject::CalculateNormals()
{
	for (int i =0;i<FPolygons.Count;i++)
		FPolygons[i].CalculatePlane();
}
void TGeomObject::TransformRotate(const TIntVec &angle, const TIntVec &center)
{
	for (int i=0;i<FVertex.Count;i++)
		FVertex[i].Point = RotateAround(FVertex[i].Point, angle, center);
	CalculateNormals();	
}

void TGeomObject::TransformScale(const TIntVec &scale)
{
	for (int i=0;i<FVertex.Count;i++)
	{
		FVertex[i].Point.x *= scale.x;
		FVertex[i].Point.y *= scale.y;
		FVertex[i].Point.z *= scale.z;
	}	
//	CalculateNormals();	
}

bool TGeomObject::SolidCheck()
{
	bool ret = true;
	FillCutsFlags(flERROR, gfFALSE);

	for (int i=0;i<FCuts.Count;i++)
	{
		if (FCuts[i].Src == NULL || FCuts[i].Dst == NULL)
			ErrorMsg("<TGeomObject::SolidCheck> : обнаружен отрезок, не имеющий одного из концов");
		if (!FCuts[i].Closed)
		{
			FCuts[i].FFlags.Error = gfTRUE;
			ret = false;
		}	
	}
	
	for (int i=0;i<FPolygons.Count;i++)
	{
		if (!FPolygons[i].Closed)
			ErrorMsg("<TGeomObject::SolidCheck> : обнаружен незамкнутый полигон");
		if (FPolygons[i].FCuts.Count<3)
			ErrorMsg("<TGeomObject::SolidCheck> : в полигоне меньше 3-х отрезков");
		if (FPolygons[i].FCuts.IndexOf(NULL) != -1)	
			ErrorMsg("<TGeomObject::SolidCheck> : полигон имеет пустой отрезок");
			
		for (int k=0;k<FPolygons[i].Count;k++)
			for (int l=k+1;l<FPolygons[i].Count;l++)
				if (&FPolygons[i].GetPoint(k) == &FPolygons[i].GetPoint(l))
					ErrorMsg("<TGeomObject::SolidCheck> : полигон содержит одинаковые вершины!");

		for (int j=0;j<FPolygons[i].FHoles.Count;j++)
		{
			if (!FPolygons[i].FHoles[j].Closed)
				ErrorMsg("<TGeomObject::SolidCheck> : обнаружен незамкнутый полигон-дырка");
			if (FPolygons[i].FHoles[j].FCuts.Count<3)
				ErrorMsg("<TGeomObject::SolidCheck> : в полигоне-дырке меньше 3-х отрезков");
			if (FPolygons[i].FHoles[j].FCuts.IndexOf(NULL) != -1)	
				ErrorMsg("<TGeomObject::SolidCheck> : полигон-дырка имеет пустой отрезок");
		}	
	}

	for (int i=0;i<FPolygons.Count;i++)
		for (int j=0;j<FPolygons[i].FHoles.Count;j++)
			if (FPolygons[i].FHoles[j].FParent != FPolygons.Items[i])
				ErrorMsg("<TGeomObject::SolidCheck> : дырка в полигоне не знает про него!");

	for (int i=0;i<FPolygons.Count;i++)
		if (FPolygons[i].FParent != NULL)
			ErrorMsg("<TGeomObject::SolidCheck> : У полигона есть родитель!");
				

	for (int i=0;i<FCuts.Count;i++)
		if (FCuts[i].FPlane.Count>2)
			WarningMsg("Отрезок принадлежит более, чем двум полигонам!");
			
	return ret;
}

void TGeomObject::SolidFix()
{
	for (int i=0;i<FCuts.Count;i++)
		if (FCuts[i].Src == NULL || FCuts[i].Dst == NULL || FCuts[i].Dst == FCuts[i].Src)
			FCuts.Delete(i--);
			
	for (int i=0;i<FPolygons.Count;i++)
	{
		for (int k=0;k<FPolygons[i].Count;k++)
			if (FPolygons[i].FCuts.CycleItems[k] == FPolygons[i].FCuts.CycleItems[k+1])
			{
				FPolygons[i].FCuts.Delete(k);	
				FPolygons[i].FCuts.Delete(k--);	
			}	
	}				
			

	for (int i=0;i<FPolygons.Count;i++)
		for (int j=0;j<FPolygons[i].FHoles.Count;j++)
		{
			for (int k=0;k<FPolygons[i].FHoles[j].Count;k++)
				if (FPolygons[i].FHoles[j].FCuts.CycleItems[k] == FPolygons[i].FHoles[j].FCuts.CycleItems[k+1])
					FPolygons[i].FHoles[j].FCuts.Delete(k+1);	
		}				
 
	for (int i=0;i<FCuts.Count;i++)
		if ( !FCuts[i].Closed )
			FCuts.Delete(i--);

	for (int i=0;i<FPolygons.Count;i++)
		if (!FPolygons[i].Closed || FPolygons[i].FCuts.Count<3 || FPolygons[i].FCuts.IndexOf(NULL) != -1)
			FPolygons.Delete(i--);

	for (int i=0;i<FPolygons.Count;i++)
		for (int j=0;j<FPolygons[0].FHoles.Count;j++)
			if (!FPolygons[i].FHoles[j].Closed || FPolygons[i].FHoles[j].FCuts.Count<3 || FPolygons[i].FHoles[j].FCuts.IndexOf(NULL) != -1)
				FPolygons[i].FHoles.Delete(j--);

	FreeUnused(fuAll);
}


void TGeomObject::ToPrimitiveObj(TVisPrimitiveObj *VCO, TConstructFlags flags)
{
	if (flags & coPOINTS)
	{
		VCO->AddPrimitiveArray(GL_POINTS);
		for ( int i=0;i<FVertex.Count;i++ )
			VCO->AddIndex(VCO->Points->Add( VisMathVec(FVertex[i].Point),ZEROVEC,ZEROVEC ), VCO->PrimitiveCount-1);
	}	
	if (flags & coCUTS)
	{
		for ( int i=0;i<FCuts.Count;i++ )
		{
			VCO->AddPrimitiveArray(GL_LINES);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(FCuts[i].Src->Point), ZEROVEC,ZEROVEC ), VCO->PrimitiveCount-1);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(FCuts[i].Dst->Point), ZEROVEC,ZEROVEC ), VCO->PrimitiveCount-1);
		}
	}	
	if (flags & coPOLYGONS)
	{
		for (int i=0;i<FPolygons.Count;i++)
		{
			VCO->AddPrimitiveArray(GL_TRIANGLES);
			TMDelTList<TIntVec> tris;
			Triangulate_(FPolygons.Items[i], tris); 
			TIntVec Normal = FPolygons[i].Normal; 
			for (int j=0;j<tris.Count;j++)
				VCO->AddIndex( VCO->Points->Add( VisMathVec(tris[j]), VisMathVec(Normal),ZEROVEC ),VCO->PrimitiveCount-1 );
		}	
	}
	if (flags & coNORMALS)
	{
		for ( int i=0;i<FPolygons.Count;i++)
		{
			TIntVec src(0,0,0);
			TIntVec dst;
			for (int j=0;j<FPolygons[i].Count;j++)
				src += FPolygons[i].GetPoint(j).Point;
			src /= (float)FPolygons[i].Count;
			dst = src + FPolygons[i].Normal/2;
			VCO->AddPrimitiveArray(GL_LINES);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(src), ZEROVEC, ZEROVEC), VCO->PrimitiveCount-1);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(dst), ZEROVEC, ZEROVEC), VCO->PrimitiveCount-1);
		}	
	}
	VCO->CalcNormals();	 	
}

bool FindCut(TVisPrimitiveObj *VCO, int pri, int pol, int b, int e )
{
	for (int i=0;i<VCO->PrimitiveCount;i++)
		if (VCO->Primitive[i]->PrimitiveType == GL_TRIANGLES)
			for (int j=0;j<VCO->Primitive[i]->Count;j+=3)
				if (i!= pri || j!= pol)
				{
					bool found = false;
					for (int k=j;k<j+3;k++)
						if (VCO->Primitive[i]->Indices[k] == b)
						{
							found = true;
							break;
						}	
					if (!found)	
						continue;

					found = false;
					for (int k=j;k<j+3;k++)
						if (VCO->Primitive[i]->Indices[k] == e)
						{
							found = true;
							break;
						}
					if (!found)
						continue;
					return true;
				}
	return false;
}

void TGeomObject::FromPrimitiveObj(TVisPrimitiveObj *VCO)
{
	Clear();
	for (int i=0;i<VCO->PrimitiveCount;i++)
		if (VCO->Primitive[i]->PrimitiveType == GL_TRIANGLES)
		{	
			TMTList <TGPoint> pnts;
			for (int j=0;j<VCO->Points->Count;j++)
				pnts.Add(AddPoint(TIntVec( VCO->Points->PointVec[j])));

			TMTList <TGCut> c;
			c.Add(NULL);
			c.Add(NULL);
			c.Add(NULL);
			for (int j=0;j<VCO->Primitive[i]->Count;j+=3)
			{
				if (pnts.Items[VCO->Primitive[i]->Indices[j]] == pnts.Items[VCO->Primitive[i]->Indices[j+1]] ||
					pnts.Items[VCO->Primitive[i]->Indices[j+1]] == pnts.Items[VCO->Primitive[i]->Indices[j+2]] ||
					pnts.Items[VCO->Primitive[i]->Indices[j+2]] == pnts.Items[VCO->Primitive[i]->Indices[j]])
					continue;
				c.Items[0] = AddCut(
					pnts.Items[VCO->Primitive[i]->Indices[j]],
					pnts.Items[VCO->Primitive[i]->Indices[j+1]]);
				if (FindCut(VCO, i, j,
					VCO->Primitive[i]->Indices[j],
					VCO->Primitive[i]->Indices[j+1]))
				c.Items[0]->Smooth = true;
					
				c.Items[1] = AddCut(
					pnts.Items[VCO->Primitive[i]->Indices[j+1]],
					pnts.Items[VCO->Primitive[i]->Indices[j+2]]);

				if (FindCut(VCO, i, j,
					VCO->Primitive[i]->Indices[j+1],
					VCO->Primitive[i]->Indices[j+2]))
				c.Items[1]->Smooth = true;

				c.Items[2] = AddCut(
					pnts.Items[VCO->Primitive[i]->Indices[j+2]],
					pnts.Items[VCO->Primitive[i]->Indices[j]]);

				if (FindCut(VCO, i, j,
					VCO->Primitive[i]->Indices[j+2],
					VCO->Primitive[i]->Indices[j]))
				c.Items[2]->Smooth = true;

				AddPolygon(c);
			}
		}
}


void TGeomObject::Triangulate()
{
	TMTList <TGPolygon> pl;
	pl.Assign(&FPolygons);
	for (int i=0;i<pl.Count;i++)
	{
		TMDelTList<TIntVec> tris;
		Triangulate_(pl.Items[i], tris); 
		FPolygons.Remove(pl.Items[i]);
		for (int j=0;j<tris.Count;j+=3)
		{
			TMTList <TGCut> c;
			c.Add(AddCut(tris[j], tris[j+1]));
			c.Add(AddCut(tris[j+1], tris[j+2]));
			c.Add(AddCut(tris[j+2], tris[j]));
			AddPolygon(c);
		}
	}	
}

TGCut *TGeomObject::ExistsCutFast( TGPoint& p1, TGPoint& p2 )
{
    if ( p1.FCuts.Count < p2.FCuts.Count )
    {
    	for ( int i = 0; i < p1.FCuts.Count; i++ )
            if ( &p1 == p1.FCuts[i].Src && &p2 == p1.FCuts[i].Dst ||
                 &p1 == p1.FCuts[i].Dst && &p2 == p1.FCuts[i].Src)
			return p1.FCuts.Items[i];
    }else{
    	for ( int i = 0; i < p2.FCuts.Count; i++ )
            if ( &p1 == p2.FCuts[i].Src && &p2 == p2.FCuts[i].Dst ||
                 &p1 == p2.FCuts[i].Dst && &p2 == p2.FCuts[i].Src)
			return p2.FCuts.Items[i];
    }
	return NULL;
}


TGCut *TGeomObject::AddCutFast(TGPoint *p1, TGPoint *p2)
{
	if (FVertex.IndexOf(p1) == -1)
		throw EMyException ("<TGeomObject::AddCut> первой точки нет в отрезке!");

	if (FVertex.IndexOf(p2) == -1)
		throw EMyException ("<TGeomObject::AddCut> второй точки нет в отрезке!");

	if (p2 == p1)
		throw EMyException ("<TGeomObject::AddCut> невозможно добавить отрезок с равными концами!");

	TGCut& cut = *((TGCut *)CreateCutFunction());

	TGCut *n;
//	if ((n = GObj.ExistsCut(cut))!=NULL)
	if ((n = ExistsCutFast(*p1, *p2))!=NULL)
	{
		delete &cut;
		n->FFlags.Alredy = gfTRUE;
		return n;
	}
	cut.Src = p1;
	cut.Dst = p2;
	FCuts.Add(&cut);
	return &cut;
}

TGCut* TGeomObject::AddCutFast(const TGCut &c)
{
	TGCut *cut = AddCutFast(c.Src, c.Dst);
	cut->Assign((TGCut *)&c);
	return cut;
}

TGCut* TGeomObject::AddCutFast(TIntVec p1, TIntVec p2)
{
    return AddCutFast(AddPoint(p1), AddPoint(p2));
}

void TGeomObject::Triangulate2()
{
    TGTriangulate CTrian(*this);
    TMTList<TGCut> TmpCuts;
//    TMDelTList<TGPoint> TmpVertex;
    int FirstCout = PolygonsCount;
    for ( int PolyIndex = FirstCout-1; PolyIndex >= 0; PolyIndex-- )
//    for ( int PolyIndex = 0; PolyIndex < FirstCout; PolyIndex++ )
    {
        TGPolygon* GHP = FPolygons.Items[PolyIndex];
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
			TmpCutsToPoly.Add(AddCutFast(TmpCuts[i]));
			TmpCutsToPoly.Add(AddCutFast(TmpCuts[i+1]));
			TmpCutsToPoly.Add(AddCutFast(TmpCuts[i+2]));
			AddPolygon( TmpCutsToPoly, TmpNormal);
            FPolygons.Last()->Tag = FPolygons[PolyIndex].Tag;
		}
		FPolygons.Delete(PolyIndex);
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

void TGeomObject::ShiftVecCompToXY(TIntVec& Vec, int CompNum)
{
	if ( CompNum == 0 )
		Vec.x = Vec.z;
	else if ( CompNum == 1 )
        Vec.y = Vec.z;
    Vec.z = 0;
//    Vec.y = -Vec.y;
}

void TGeomObject::ShiftVecCompFromXY(TIntVec& Vec, int CompNum, MBTi VecComp)
{
    if ( CompNum == 0 )
		Vec.z = Vec.x;
    else if ( CompNum == 1 )
        Vec.z = Vec.y;
    Vec.a[CompNum] = VecComp;
//    Vec.y = -Vec.y;
}

void TGeomObject::Triangulate3(TGeomObject& obj)
{
    obj.Assign(this);
    TGTriangulate CTrian(obj);
    TMTList<TGCut> TmpCuts;
    int FirstCout = obj.PolygonsCount;
    for ( int PolyIndex = 0; PolyIndex < FirstCout; PolyIndex++ )
    {
        TGPolygon* GHP = obj.FPolygons.Items[PolyIndex];

        int CompNum;
		TIntVec Vec = GHP->Normal;
        if ( fabs(Vec.x) >= fabs(Vec.y) && fabs(Vec.x) >= fabs(Vec.z) )
            CompNum = 0;
        else if (  fabs(Vec.y) >= fabs(Vec.x) && fabs(Vec.y) >= fabs(Vec.z) )
            CompNum = 1;
		else if (  fabs(Vec.z) >= fabs(Vec.y) && fabs(Vec.z) >= fabs(Vec.x) )
            CompNum = 2;

    	for ( int i = 0; i < GHP->Count; i++ )
            ShiftVecCompToXY(GHP->GetPoint(i).Point, CompNum);
    	for (int i = 0; i < GHP->FHoles.Count; i++ )
    		for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
                ShiftVecCompToXY(GHP->FHoles.Items[i]->GetPoint(j).Point, CompNum);

        TmpCuts.Clear();
        TmpCuts.Assign(CTrian.Triangulate(GHP));
		TIntVec TmpNormal = GHP->Normal;

    	for ( int i = 0; i < GHP->Count; i++ )
            ShiftVecCompFromXY( GHP->GetPoint(i).Point, CompNum, FPolygons[PolyIndex].GetPoint(i).Point.a[CompNum]);

    	for (int i = 0; i < GHP->FHoles.Count; i++ )
			for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
                ShiftVecCompFromXY(GHP->FHoles.Items[i]->GetPoint(j).Point, CompNum, FPolygons[PolyIndex].FHoles[i].GetPoint(j).Point.a[CompNum]);

        for ( int i = 0; i < TmpCuts.Count; i+=3 )
        {
            TMTList<TGCut> TmpCutsToPoly;
			TmpCutsToPoly.Add(obj.AddCut(TmpCuts[i]));
            TmpCutsToPoly.Add(obj.AddCut(TmpCuts[i+1]));
            TmpCutsToPoly.Add(obj.AddCut(TmpCuts[i+2]));
            obj.AddPolygon( TmpCutsToPoly, TmpNormal);
        }
    }
    for ( int i = 0; i < FirstCout; i++ )
        obj.FPolygons.Delete(0);
}

void TGeomObject::GetSmoothGroup(TGPoint* Pnt, int CutIndex, TMTList<TGPolygon>& Poly)
{
    Pnt->FCuts[CutIndex].Flags.Mark = 1;
    for ( int i = 0; i < Pnt->FCuts[CutIndex].FPlane.Count; i++ )
    {
        TGPolygon* TmpPoli = Pnt->FCuts[CutIndex].FPlane.Items[i];
        if ( TmpPoli != NULL )
            for ( int j = 0; j < Pnt->FCuts.Count; j++ )
              if ( CutIndex != j )
                if ( TmpPoli->Flags.Mark == 0 &&
                     TmpPoli->FCuts.IndexOf(Pnt->FCuts.Items[j]) != -1 )
                {
                    Poly.Add(TmpPoli);
					Pnt->FCuts[CutIndex].FPlane[i].Flags.Mark = 1;
                    if ( Pnt->FCuts[j].Smooth && Pnt->FCuts[j].Flags.Mark == 0 )
                        GetSmoothGroup(Pnt, j, Poly);
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

const colors[] =
{
	0x00FF0000,
	0x0000FF00,
	0x000000FF,
	0x00FFFF00,
	0x0000FFFF,
	0x00FF00FF,
};
/*
enum TConstructFlags
{
	coPOINTS		= 0x0001,
	coCUTS			= 0x0002,
	coPOLYGONS		= 0x0004,
	coNORMALS		= 0x0008,
	coPOLYGONHOLES  = 0x0010,

	coWIRE			= 0x0001 | 0x0002,
	coSOLID			= 0x0004,
	coALL			= 0xFFFF
};
*/
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
    if ( render == rtERROR )
        render = rtMARK;
	if (co & coPOLYGONS)
	{
        if ( render != rtCOLOR )
        {
            VCO->AddPrimitiveArray(GL_TRIANGLES);
            VCO->AddPrimitiveArray(GL_TRIANGLES);
            switch (render)
            {
                case rtSMOOTH:
                    VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
                    VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clSkyBlue;
                    break;
                case rtCLASSIFY :
                        VCO->Primitive[VCO->PrimitiveCount-2]->ColorAsMaterial = cmDiffuse;
                        VCO->Primitive[VCO->PrimitiveCount-2]->Color->Color = clBlue;
                        VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
                        VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clRed;
                    break;
                case rtMARK :
                        VCO->Primitive[VCO->PrimitiveCount-2]->ColorAsMaterial = cmDiffuse;
                        VCO->Primitive[VCO->PrimitiveCount-2]->Color->Color = clLime;
                        VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
                        VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clSkyBlue;
                    break;
            }
        }
        for ( int i = 0; i < FPolygons.Count; i++ )
            if (FPolygons[i].Closed)
            {
                if ( render == rtCOLOR )
                {
                    VCO->AddPrimitiveArray(GL_TRIANGLES);
    				VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
    				VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = colors[FPolygons[i].Tag];
                }
                TIntVec Normal = FPolygons[i].Normal;
				for ( int j = FPolygons[i].Count-1; j >= 0; j-- )
                {
                    TGPoint* TmpP = &FPolygons[i].GetPoint(j);
                    if ( FastPointDetect[i][j] == -1 )
                        if ( (FPolygons[i].Tag == gfTRUE && render == rtMARK) || (FPolygons[i].Flags.Origin == gfPOSITIVE && render == rtCLASSIFY) )
                            VCO->AddIndex( VCO->Points->Add( VisMathVec(TmpP->Point),VisMathVec(Normal),ZEROVEC ), VCO->PrimitiveCount-2 );
                        else
                            VCO->AddIndex( VCO->Points->Add( VisMathVec(TmpP->Point),VisMathVec(Normal),ZEROVEC ), VCO->PrimitiveCount-1 );
                    else
                        if ( (FPolygons[i].Tag == gfTRUE && render == rtMARK) || (FPolygons[i].Flags.Origin == gfPOSITIVE && render == rtCLASSIFY) )
                            VCO->AddIndex( SPInds[FastPointDetect[i][j]] , VCO->PrimitiveCount-2 );
                        else
                            VCO->AddIndex( SPInds[FastPointDetect[i][j]] , VCO->PrimitiveCount-1 );
                }
            }
    }

  	if (co & coPOLYGONHOLES)
	{
        for ( int k = 0; k < obj.FPolygons.Count; k++ )
            for ( int i = 0; i < obj.FPolygons[k].FHoles.Count; i++ )
            {
                VCO->AddPrimitiveArray(GL_TRIANGLES);
                VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmDiffuse;
                VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clTeal;
                VCO->Primitive[VCO->PrimitiveCount-1]->Color->Alpha = 0.5;

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

	if (co & coPOINTS)
	{
        if ( render != rtCOLOR )
        {
            VCO->AddPrimitiveArray(GL_POINTS);
            VCO->AddPrimitiveArray(GL_POINTS);
            switch (render)
            {
                case rtSMOOTH:
                    VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmEmission;
                    VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clRed;
                    break;
                case rtCOLOR:
                    VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmEmission;
                    VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clRed;
                    break;
                case rtMARK :
                    VCO->Primitive[VCO->PrimitiveCount-2]->ColorAsMaterial = cmEmission;
                    VCO->Primitive[VCO->PrimitiveCount-2]->Color->Color = clLime;
                    VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
                    VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clRed;
                    break;
            }
        }
		for ( int i = 0; i < obj.VertexCount; i++ )
        {
            if ( render == rtCOLOR )
            {
                VCO->AddPrimitiveArray(GL_POINTS);
                VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmEmission;
                VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = colors[i % 6];
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
                    VCO->Primitive[VCO->PrimitiveCount-2]->ColorAsMaterial = cmEmission;
                    VCO->Primitive[VCO->PrimitiveCount-2]->Color->Color = (TColor)0x000080FF;
                    VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmEmission;
                    VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clYellow;
                    break;
                case rtMARK :
                    VCO->Primitive[VCO->PrimitiveCount-2]->ColorAsMaterial = cmEmission;
                    VCO->Primitive[VCO->PrimitiveCount-2]->Color->Color = clLime;
                    VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmEmission;
                    VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clYellow;
                    break;
            }
        }
		for ( int i = 0; i < obj.CutsCount; i++ )
//            if ( !obj.FCuts[i].Smooth )
//            if ( obj.FCuts[i].FFlags.Same )
            {
                if ( render == rtCOLOR )
                {
                    VCO->AddPrimitiveArray(GL_LINES);
                    VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmEmission;
                    VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = colors[i % 6];
                }

                if ( ( obj.FCuts[i].Tag == gfTRUE && render == rtMARK) || (obj.FCuts[i].Smooth && render == rtSMOOTH) )
                {
                    VCO->AddIndex(VCO->Points->Add( VisMathVec(obj.GetCut(i).Src->Point/*+TIntVec(0, 0, 0)*/), ZEROVEC,ZEROVEC ),VCO->PrimitiveCount-2);
                    VCO->AddIndex(VCO->Points->Add( VisMathVec(obj.GetCut(i).Dst->Point/*+TIntVec(0, 0, 0)*/), ZEROVEC,ZEROVEC ), VCO->PrimitiveCount-2);
                }else
                {
                    VCO->AddIndex(VCO->Points->Add( VisMathVec(obj.GetCut(i).Src->Point/*+TIntVec(0, 0, 0)*/), ZEROVEC,ZEROVEC ),VCO->PrimitiveCount-1);
                    VCO->AddIndex(VCO->Points->Add( VisMathVec(obj.GetCut(i).Dst->Point/*+TIntVec(0, 0, 0)*/), ZEROVEC,ZEROVEC ), VCO->PrimitiveCount-1);
                }
            }
	}
	if (co & coNORMALS)
	{
    	VCO->AddPrimitiveArray(GL_LINES);
        VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmEmission;
        VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = clBlue;
		for ( int i = 0; i < obj.FPolygons.Count; i++ )
		{
			TIntVec src = obj.FPolygons[i].GetMidOrigin();
			TIntVec dst;

			dst = src + obj.FPolygons[i].Normal/2;
			VCO->AddIndex(VCO->Points->Add( VisMathVec(src), ZEROVEC, ZEROVEC), VCO->PrimitiveCount-1);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(dst), ZEROVEC, ZEROVEC), VCO->PrimitiveCount-1);
		}	
	}
}

//Drive
long int TickCount1;
long int TickCount2;
long int TickCount3;
long int TickCount4;
long int TickCount5;
long int TickCount6;
long int TickCount7;
long int TickCount8;
//Drive

void TGeomObject::ToPrimitiveObj2(TVisPrimitiveObj* VCO, TConstructFlags co, TRenderType render)
{
    TGeomObject TmpObj;
    TmpObj.Assign(this);
    TmpObj.FillCutsFlags(flSAME, gfTRUE);
    if ( render == rtCOLOR )
        for ( int i = 0; i < TmpObj.PolygonsCount; i++ )
            TmpObj.GetPolygon(i).Tag = i % 6;
    TmpObj.Triangulate2();
	TmpObj.ConstructVCO(VCO, co, render, *this);
}

void TGeomObject::Optimize(MBTi _PEPS, MBTi _CEPS, bool det, bool cross)
{
	TMTList <TGPolygon> old;
	TMTList <TGPoint> cache;

	cache.Assign(&FVertex);
	for (int i=0;i<cache.Count;i++)
		DeletePointBetweenCollinear(cache.Items[i]);
	FreeUnused(fuAll);

	
	old.Assign(&FPolygons);
	int iii=0;
	while (old.Count>0)
	{
		iii++;
		TMTList <TGPolygon> same;
		same.Add(old.Items[0]);
		TIntVec org0 = old[0].MidOrigin;
		for (int i = 1;i<old.Count;i++)
			if ((old[0].Normal.Equal( old[i].Normal, _CEPS)) && fabs(ScalarP(old[0].Normal, old[i].MidOrigin) - ScalarP(old[0].Normal, org0))<_PEPS)
				same.Add(old.Items[i]);
		if (same.Count > 1 || (same[0].FHoles.Count))
		{
			TMTList <TGCut> cuts;
			TMTList <TGCut> toDel;
			for (int i=0;i<same.Count;i++)
			{
				for (int j=0;j<same[i].FCuts.Count;j++)
					cuts.Add(same[i].FCuts.Items[j]);
				for (int k=0;k<same[i].FHoles.Count;k++)
					for (int j=0;j<same[i].FHoles[k].FCuts.Count;j++)
						cuts.Add(same[i].FHoles[k].FCuts.Items[j]);
			}		
			TIntVec nrm = same[0].Normal;
			for (int i=0;i<cuts.Count;i++)
			{
				int ExistsCount = 0;
				int TotalCount = 0;
				for (int l=0;l<cuts[i].FPlane.Count;l++)
				{	
					ExistsCount += (same.IndexOf( cuts[i].FPlane.Items[l] )	!= -1);
					TotalCount  += (cuts[i].FPlane.Items[l]!=NULL);
				}
				if ( (TotalCount == ExistsCount) && (TotalCount == 2) )
					toDel.Add(cuts.Items[i]);
			}
			for (int i=0;i<same.Count;i++)
			{
				old.Remove(same.Items[i]);
				FPolygons.Remove(same.Items[i]);
			}
			for (int i=0;i<toDel.Count;i++)
			{
				FCuts.Remove(toDel.Items[i]);
				cuts.Remove(toDel.Items[i]);
			}	
			TMDelTList< TMTList <TGCut> > poly;
			TMTList<TMyObject> tt;
			MBTi AngX, AngY;

			tt.Assign(&cuts);
			TransformToPlane(nrm, tt, AngX, AngY);
			if (cross)
				ProcessCrossCuts2d(cuts);
			for (int j=0;j<cuts.Count;j++)
				for (int k=j+1;k<cuts.Count;k++)
					if (cuts.Items[j] == cuts.Items[k])
						cuts.Delete(k--);
			tt.Assign(&cuts);
			if(cuts.Count>=3)
				Polygonize2d(cuts, poly);
			else
			{
				InfoMsg("");
			}	
			same.Clear();
			for (int i=0;i<poly.Count;i++)
				for (int j=0;j<poly[i].Count;j++)
					for (int k=j+1;k<poly[i].Count;k++)
						if (poly[i].Items[j] == poly[i].Items[k])
							poly[i].Delete(k--);
				
			for (int i=0;i<poly.Count;i++)
				if (poly[i].Count<3)
					poly.Delete(i--);
			for (int i=0;i<poly.Count;i++)	
				same.Add(AddPolygon(poly[i], nrm));
			TransformBack(tt, AngX, AngY);
		} else
		{
			old.Delete(0);
		}
	}

	cache.Assign(&FVertex);
	for (int i=0;i<cache.Count;i++)
		DeletePointBetweenCollinear(cache.Items[i]);
	FreeUnused(fuAll);
	if (det)	
		DetectHolesAtAll(_PEPS, _CEPS);
}

void TGeomObject::CrossCutsAtAll(MBTi _PEPS, MBTi _CEPS)
{
	TMTList <TGPolygon> old;

	old.Assign(&FPolygons);
	int iii=0;
	while (old.Count>0)
	{
		iii++;
		TMTList <TGPolygon> same;
		same.Add(old.Items[0]);
		TIntVec org0 = old[0].MidOrigin;
		for (int i = 1;i<old.Count;i++)
			if ((old[0].Normal.Equal( old[i].Normal, _CEPS)) && fabs(ScalarP(old[0].Normal, old[i].MidOrigin) - ScalarP(old[0].Normal, org0))<_PEPS)
				same.Add(old.Items[i]);
		if (same.Count > 1)
		{
			TMTList <TGCut> cuts;
			TMTList <TGCut> toDel;
			for (int i=0;i<same.Count;i++)
				old.Remove(same.Items[i]);

			for (int i=0;i<same.Count;i++)
			{
				for (int j=0;j<same[i].FCuts.Count;j++)
					cuts.Add(same[i].FCuts.Items[j]);
				for (int k=0;k<same[i].FHoles.Count;k++)
					for (int j=0;j<same[i].FHoles[k].FCuts.Count;j++)
						cuts.Add(same[i].FHoles[k].FCuts.Items[j]);
			}		

			TIntVec nrm = same[0].Normal;

			TMTList<TMyObject> tt;
			MBTi AngX, AngY;

			tt.Assign(&cuts);
			TransformToPlane(nrm, tt, AngX, AngY);
			ProcessCrossCuts2d(cuts);
			tt.Assign(&cuts);
			TransformBack(tt, AngX, AngY);
		} else
		{
			old.Delete(0);
		}
	}
}

void TGeomObject::DetectHolesAtAll(MBTi _PEPS, MBTi _CEPS)
{
	TMTList <TGPolygon> old;

	old.Assign(&FPolygons);
	int iii=0;
	while (old.Count>0)
	{
		iii++;
		TMTList <TGPolygon> same;
		same.Add(old.Items[0]);
		TIntVec org0 = old[0].MidOrigin;
		for (int i = 1;i<old.Count;i++)
			if ((old[0].Normal.Equal( old[i].Normal, _CEPS)) && fabs(ScalarP(old[0].Normal, old[i].MidOrigin) - ScalarP(old[0].Normal, org0))<_PEPS)
				same.Add(old.Items[i]);
		if (same.Count > 1)
		{
			TMTList <TGCut> cuts;
			TMTList <TGCut> toDel;
			for (int i=0;i<same.Count;i++)
				old.Remove(same.Items[i]);
			TIntVec nrm = same[0].Normal;

			TMTList<TMyObject> tt;
			MBTi AngX, AngY;

			tt.Assign(&same);
			TransformToPlane(nrm, tt, AngX, AngY);
			DetectHoles2d(same);              
			TransformBack(tt, AngX, AngY);
		} else
		{
			old.Delete(0);
		}
	}
}


void TGeomObject::ProcessCrossCuts2d(TMTList<TGCut>& Cuts)
{
	int i;
	int j;

	while(1)
	{
		int pCount1 = Cuts.Count;
		for( i = 0; i < pCount1; i++ )
		{
			int pCount2 = Cuts.Count;
			for( j = i+1; j < pCount2; j++ )
				{
					TIntVec Vec;
					int Tmp = IsCutsCrossed(Cuts[i].Src->Point, Cuts[i].Dst->Point,
											Cuts[j].Src->Point, Cuts[j].Dst->Point,
											Vec, PEPS);

					if ( Tmp == lcCROSSING && ExistsPoint(Vec) == NULL /* || Tmp == lcEQUAL || Tmp == lcCOMMONPOINT*/ )
					{
						TGPoint* TmpP = AddPoint(Vec);
						TGCut* TmpCj = Cuts.Items[j];
						TGCut* TmpCi = Cuts.Items[i];
						TGCut *Res1, *Res2;
						SplitCut(TmpCi, TmpP, Res1, Res2);
						if (Res2 != NULL)
						{
							Cuts.Remove(TmpCi);
							if (Cuts.IndexOf(Res1) == -1)	
								Cuts.Add(Res1);
							if (Cuts.IndexOf(Res2) == -1)	
								Cuts.Add(Res2);
						}
						SplitCut(TmpCj, TmpP, Res1, Res2);
						if (Res2 != NULL)
						{
							Cuts.Remove(TmpCj);
							if (Cuts.IndexOf(Res1) == -1)	
								Cuts.Add(Res1);
							if (Cuts.IndexOf(Res2) == -1)	
								Cuts.Add(Res2);
						}
						break;
					}
				}
			if ( j < pCount2 )
				break;
		}
		if ( i == pCount1 )
			break;
	}
}

void TGeomObject::ProcessCrossCuts2d()
{
	ProcessCrossCuts2d(FCuts);
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
			FVertex.Remove(pnt.Items[i]);	
		}	
	}	
}
void TGeomObject::WeldPointsAtAll(MBTi EPS)
{
	for (int i=0;i<FVertex.Count;i++)
	{
		TMTList <TGPoint> points;
		points.Add(FVertex.Items[i]);
		for (int j=i+1;j<FVertex.Count;j++)
			if (points[0].Point.Equal(FVertex[j].Point, EPS))
				points.Add(FVertex.Items[i]);
		CollapsePoints(points);		
	}	
	SolidFix();
}

void TGeomObject::TransformTranslate(const TIntVec &dir)
{
	for (int i=0;i<FVertex.Count;i++)
		FVertex[i].Point += dir;
}
void TGeomObject::ScaleTo(MBTi maxSize)
{
	TIntVec min(0,0,0);
	TIntVec max(0,0,0);
	for (int i=0;i<FVertex.Count;i++)
		if (i==0)
		{
			min = FVertex[i].Point;
			max = FVertex[i].Point;
		} else
		{
			min.x = MIN(min.x, FVertex[i].Point.x);
			min.y = MIN(min.y, FVertex[i].Point.y);
			min.z = MIN(min.z, FVertex[i].Point.z);

			max.x = MAX(max.x, FVertex[i].Point.x);
			max.y = MAX(max.y, FVertex[i].Point.y);
			max.z = MAX(max.z, FVertex[i].Point.z);
		}
	TIntVec bBox = max-min;
	MBTi dim = MAX(bBox.x, MAX(bBox.y, bBox.z));
	MBTi scale = maxSize/dim;
	for (int i=0;i<FVertex.Count;i++)
		FVertex[i].Point*=scale;
	
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
void TGeomObject::SaveTwoPolygonAsFigure(int ind1, int ind2, AnsiString &name)
{
	TMemoryStream* MSS = new TMemoryStream();
	TGeomObject obj;
	obj.CopyPolygonToObject(FPolygons[ind1]);
	obj.CopyPolygonToObject(FPolygons[ind2]);
	MBTi a,b;
/*	obj.FPolygons[0].PlaceOnPlane(a,b,TIntVec(0,0,0));
	obj.FPolygons[1].PlaceOnPlane(a,b,TIntVec(0,0,0));*/
	obj.WriteData(MSS);
	MSS->SaveToFile(name);
	delete MSS;
}
void TGeomObject::SaveObjectAsFigure(int ind, const TMemoryStream *f)
{
	TGeomObject obj;
	obj.Assign(this);
	MBTi a,b,c;
	obj.TransformToPolygon(obj.FPolygons.Items[ind],TIntVec(0,0,0), TIntVec(1,0,0),a,b,c);
	obj.WriteData((TMemoryStream *)f);
}
void TGeomObject::SaveCutsAsFigure(const TMTList <TGCut> &cuts, const AnsiString &name)
{
	TGeomObject go;
	for (int i=0;i<cuts.Count;i++)
		go.AddCut(cuts[i]);
	go.Write(name);	
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

bool TGeomObject::GeometryFix(TMTList<TGCut> &cuts, TGeomFixFlags flags)
{
	TMTList <TGPoint> pnts;
	GetBasePoints(cuts, pnts);
	bool fixed = false;
	if (flags & gfxPOINTSINCUTS)	
	{
		for (int i=0;i<pnts.Count;i++)
		{
			for (int j=0;j<cuts.Count;j++)
				if (!cuts[j].ConsistsPoint(pnts.Items[i]) && CutConsistsPoint(pnts[i].Point, cuts[j].Src->Point, cuts[j].Dst->Point, PEPS))
				{
					TGCut *c1, *c2;
					SplitCut(cuts.Items[j], pnts.Items[i], c1, c2);
					cuts.Delete(j);
					fixed = true;
					int t = j;
					j--;
					if (cuts.IndexOf(c2) == -1)
					{
						cuts.Insert(t, c2);
						j++;
					}
					if (cuts.IndexOf(c1) == -1)
					{
						cuts.Insert(t, c1);
						j++;
					}
				}
		}
	}
/*	if (flags & fxCUTSCROSS)
	{
		TIntVec itr;
		for (int i=0;i<cuts.Count;i++)
			for (int j=0;j<cuts.Count;j++)
				if (!cuts[i].Equal(cuts[j]) && CutCutCross(cuts[i].Src->Point, cuts[i].Dst->Point, cuts[j].Src->Point, cuts[j].Dst->Point,itr, PEPS))
				{
					TGCut *c1, *c2;
					TGPoint *it = AddPoint(itr);
					SplitCut(cuts.Items[j], it, c1, c2);
					cuts.Delete(j);
					int t = j;
					j--;
					if (cuts.IndexOf(c2) == -1)
					{
						cuts.Insert(t, c2);
						j++;
					}
					if (cuts.IndexOf(c1) == -1)
					{
						cuts.Insert(t, c1);
						j++;
					}

					SplitCut(cuts.Items[i], it, c1, c2);
					cuts.Delete(j);
					t = j;
					i--;
					if (cuts.IndexOf(c2) == -1)
					{
						cuts.Insert(t, c2);
						i++;
					}
					if (cuts.IndexOf(c1) == -1)
					{
						cuts.Insert(t, c1);
						i++;
					}
				}
	}	*/
	return fixed;
}
void TGeomObject::GeometryFix(TGeomFixFlags flags)
{
	TMTList <TGPoint> &pnts = FVertex;
	TMTList <TGCut> &cuts = FCuts;
	if (flags & gfxPOINTSINCUTS)	
	{
		for (int i=0;i<pnts.Count;i++)
		{
			for (int j=0;j<cuts.Count;j++)
				if (!cuts[j].ConsistsPoint(pnts.Items[i]) && CutConsistsPoint(pnts[i].Point, cuts[j].Src->Point, cuts[j].Dst->Point, PEPS))
				{
					TGCut *c1, *c2;
					SplitCut(cuts.Items[j], pnts.Items[i], c1, c2);
				}
		}
	}
/*	if (flags & fxCUTSCROSS)
	{
		TIntVec itr;
		int count = cuts.Count;
		for (int i=0;i<cuts.Count;i++)
			for (int j=0;j<cuts.Count;j++)
				if (!cuts[i].Equal(cuts[j]) && CutCutCross(cuts[i].Src->Point, cuts[i].Dst->Point, cuts[j].Src->Point, cuts[j].Dst->Point,itr, PEPS))
				{
					TGCut *c1, *c2;
					TGPoint *it = AddPoint(itr);
					SplitCut(cuts.Items[j], it, c1, c2);
					SplitCut(cuts.Items[i], it, c1, c2);
				}
	}	*/
}

bool TGeomObject::StructureFix(TMTList<TGCut> &cuts, TStructFixFlags flags)
{
	bool ret = false;

	if (flags & sfxREMOVE_REPEATED)
	{
		for (int i=0;i<cuts.Count;i++)
			for (int j=i+1;j<cuts.Count;j++)
				if (cuts[i].Equal(cuts[j]))
				{
					cuts.Delete(j--);
					ret = true;
				}	
	}

	if (flags & sfxREMOVE_BRANCHES)
	{
//		FillPointsFlags(flMARK, gfFALSE);
		bool WasDeleted = true;
		while ( WasDeleted )
		{
			WasDeleted = false;
			for (int i=0;i<cuts.Count;i++)
			{
				int cnt = 0;
	//			if (cuts[i].Src->FFlags.Mark != gfTRUE)
				{
					for (int j=0;j<cuts[i].Src->FCuts.Count;j++)
						if ( cuts.IndexOf( cuts[i].Src->FCuts.Items[j] ) != -1)
							cnt++;
					
	//				cuts[i].Src->FFlags.Mark = gfTRUE;
					if (cnt<2)
					{
						//--------------
	//					cuts[i].Src->FFlags.Mark = gfFALSE;
	//					cuts[i].Dst->FFlags.Mark = gfFALSE;
						cuts.Delete(i--);
						WasDeleted = true;
						ret = true;
						continue;
					}
				}
				cnt = 0;
	//			if (cuts[i].Dst->FFlags.Mark != gfTRUE)
				{
					for (int j=0;j<cuts[i].Dst->FCuts.Count;j++)
						if ( cuts.IndexOf( cuts[i].Dst->FCuts.Items[j] ) != -1)
							cnt++;
					
	//				cuts[i].Dst->FFlags.Mark = gfTRUE;
					if (cnt<2)
					{
						//--------------
	//					cuts[i].Src->FFlags.Mark = gfFALSE;
	//					cuts[i].Dst->FFlags.Mark = gfFALSE;
						cuts.Delete(i--);
						WasDeleted = true;
						ret = true;
						continue;
					}
				}	
			}
		}
	}
	if (flags & sfxREMOVE_BRIDGES_BY_CONTOURIZE)
	{
		TMTList <TGCut> contour;
		TMTList <TGCut> cuts_;
		cuts_.Assign(&cuts);
		while (cuts_.Count>2)
		{
			Contourize2d(cuts_, contour);
			for (int i=0;i<contour.Count;i++)
				for (int j=i+1;j<contour.Count;j++)
					if (contour.Items[i] == contour.Items[j])
						cuts.Remove(contour.Items[i]);
			TMTListSub(cuts_, contour);			
		}			
	}
	if (flags & sfxREMOVE_BRIDGES_BY_POLYGONIZE)
	{
		TMDelTList < TMTList<TGCut> > poly;
		Polygonize2d(cuts, poly);
		for (int n=0;n<poly.Count;n++)
			for (int i=0;i<poly[n].Count;i++)
				for (int j=i+1;j<poly[n].Count;j++)
					if (poly[n].Items[i] == poly[n].Items[j])
						cuts.Remove(poly[n].Items[i]);
	}
	return ret;
}

bool TGeomObject::StructureFix(TStructFixFlags flags)
{
	return StructureFix(FCuts, flags);
}

bool TGeomObject::StructureFix(TGPolygon *, TStructFixFlags flags)
{
	TMTList <TGCut> cuts;
	cuts.Assign(&FCuts);
	bool ret = StructureFix(cuts, flags);
	for (int i=0;i<FCuts.Count;i++)
		if (cuts.IndexOf(FCuts.Items[i]) == -1)
			DeleteCut(i--);
	return ret;
}

void TGeomObject::CopyCutsToObject(const TGeomObject &obj)
{
	for (int i=0;i<obj.FCuts.Count;i++)
		CopyCutToObject(obj.FCuts[i]);
}	


void TGeomObject::CopyPolygonsToObject(const TGeomObject &obj)
{
	for (int i=0;i<obj.FPolygons.Count;i++)
		CopyPolygonToObject(obj.FPolygons[i]);
}




