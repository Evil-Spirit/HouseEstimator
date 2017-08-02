//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"
#pragma hdrstop

#include "TGATriangulation.h"

#include "MYGL.h"
#include "Poligon.h"
#include "TGObject.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void TGATriangulate::Find2BasePoints(TGPoint*& pnt1, TGPoint*& pnt2)
{
    //-= 1-я базовая точка
    for (int i=0; i<FVertex.Count; i++)  //еще условие по x
        if (FVertex[i].Point.y > pnt1->Point.y + EPS)
            pnt1 = FVertex.Items[i];
        else if ( fabs(FVertex[i].Point.y - pnt1->Point.y) < EPS  && FVertex[i].Point.x < pnt1->Point.x)
            pnt1 = FVertex.Items[i];

    //-= 2-я базовая точка
    float Angle = 1;
    float Length = 900000;
    for (int i=0; i<FVertex.Count; i++)
        if (FVertex.Items[i] != pnt1)
        {
            TIntVec tmp = pnt1->Point - FVertex[i].Point;
            float a = tmp.x;//*tmp.x;
            if (fabs(a)<EPS)
                a=0;
            if (a < 0)
                a *= -a;
            else
                a *= a;
            float CurLength = tmp.x*tmp.x+tmp.y*tmp.y;
            a /= CurLength;
            if (a < Angle || fabs(a-Angle)<0.00001 && CurLength<Length)
            {
                Angle = a;
                Length = CurLength;
                pnt2 = FVertex.Items[i];
            }
        }
}

bool TGATriangulate::SimpleIntersection(TIntVec& aSrcPoint, TIntVec& aDstPoint, TIntVec& bSrcPoint, TIntVec& bDstPoint)
{
    if ( ((bDstPoint.x - bSrcPoint.x)*(aSrcPoint.y - bSrcPoint.y)-(bDstPoint.y - bSrcPoint.y)*(aSrcPoint.x - bSrcPoint.x)) *
        ((bDstPoint.x - bSrcPoint.x)*(aDstPoint.y-bSrcPoint.y) - (bDstPoint.y - bSrcPoint.y)*(aDstPoint.x-bSrcPoint.x)) < -EPS )
    if ( ((aDstPoint.y - aSrcPoint.y)*(aSrcPoint.x - bSrcPoint.x)-(aDstPoint.x - aSrcPoint.x)*(aSrcPoint.y - bSrcPoint.y)) *
        ((aDstPoint.x - aSrcPoint.x)*(bDstPoint.y-aSrcPoint.y)-(aDstPoint.y - aSrcPoint.y)*(bDstPoint.x-aSrcPoint.x)) < -EPS )
      return true;
  return false;
}

/*bool TGATriangulate::SimpleIntersection2(TIntVec& aSrcPoint, TIntVec& aDstPoint, TGCut& b)
{
    bool bb = ((b.Dst->Point.x - b.Src->Point.x)*(aSrcPoint.y - b.Src->Point.y)-(b.Dst->Point.y - b.Src->Point.y)*(aSrcPoint.x - b.Src->Point.x)) *
        ((b.Dst->Point.x - b.Src->Point.x)*(aDstPoint.y-b.Src->Point.y) - (b.Dst->Point.y - b.Src->Point.y)*(aDstPoint.x-b.Src->Point.x)) < -EPS;
    if ( bb )
    {
        bool bb1 = ((aDstPoint.y - aSrcPoint.y)*(aSrcPoint.x - b.Src->Point.x)-(aDstPoint.x - aSrcPoint.x)*(aSrcPoint.y - b.Src->Point.y)) *
        ((aDstPoint.x - aSrcPoint.x)*(b.Dst->Point.y-aSrcPoint.y)-(aDstPoint.y - aSrcPoint.y)*(b.Dst->Point.x-aSrcPoint.x)) < -EPS;
    if ( bb1 )
      return true;
    }
  return false;
}

bool TGATriangulate::SimpleIntersection3(TGCut& a, TGCut& b)
{
    if ( ((b.Dst->Point.x - b.Src->Point.x)*(a.Src->Point.y - b.Src->Point.y)-(b.Dst->Point.y - b.Src->Point.y)*(a.Src->Point.x - b.Src->Point.x)) *
        ((b.Dst->Point.x - b.Src->Point.x)*(a.Dst->Point.y-b.Src->Point.y) - (b.Dst->Point.y - b.Src->Point.y)*(a.Dst->Point.x-b.Src->Point.x)) < -EPS )
    if ( ((a.Dst->Point.y - a.Src->Point.y)*(a.Src->Point.x - b.Src->Point.x)-(a.Dst->Point.x - a.Src->Point.x)*(a.Src->Point.y - b.Src->Point.y)) *
        ((a.Dst->Point.x - a.Src->Point.x)*(b.Dst->Point.y-a.Src->Point.y)-(a.Dst->Point.y - a.Src->Point.y)*(b.Dst->Point.x-a.Src->Point.x)) < -EPS )
      return true;
  return false;
}*/

bool TGATriangulate::CheckSimpleCrossing(TGPoint& a, TGPoint& b, TGPoint& c)
{
    for (int j=0; j<FCuts.Count; j++)
        if ( SimpleIntersection(a.Point, c.Point, FCuts[j].Src->Point, FCuts[j].Dst->Point) ||
             SimpleIntersection(a.Point, b.Point, FCuts[j].Src->Point, FCuts[j].Dst->Point) )
            return true;
    return false;
}

bool TGATriangulate::CheckBldCrossing(TGPoint& a, TGPoint& b, TGPoint& c)
{
    for (int j=0; j<CutsBuild.Count; j++)
        if (SimpleIntersection(a.Point, b.Point, CutsBuild[j].Src->Point, CutsBuild[j].Dst->Point) ||
            SimpleIntersection(a.Point, c.Point, CutsBuild[j].Src->Point, CutsBuild[j].Dst->Point) )
            return true;
    return false;
}

TGCut *TGATriangulate::ExistsCutIn_CutsBuild( TGPoint* p1,  TGPoint* p2 )
{
	for (int i=0;i<CutsBuild.Count;i++)
        if ( p1 == CutsBuild[i].Src && p2 == CutsBuild[i].Dst ||
             p1 == CutsBuild[i].Dst && p2 == CutsBuild[i].Src)
			return CutsBuild.Items[i];
	return NULL;
}

TGCut *TGATriangulate::ExistsCutIn_FCuts( TGPoint* p1,  TGPoint* p2 )
{
    if ( p1->FCuts.Count < p2->FCuts.Count )
    {
    	for ( int i = 0; i < p1->FCuts.Count; i++ )
            if ( p1 == p1->FCuts[i].Src && p2 == p1->FCuts[i].Dst ||
                 p1 == p1->FCuts[i].Dst && p2 == p1->FCuts[i].Src)
			return p1->FCuts.Items[i];
    }else{
    	for ( int i = 0; i < p2->FCuts.Count; i++ )
            if ( p1 == p2->FCuts[i].Src && p2 == p2->FCuts[i].Dst ||
                 p1 == p2->FCuts[i].Dst && p2 == p2->FCuts[i].Src)
			return p2->FCuts.Items[i];
    }
/*	for (int i=0;i<FCuts.Count;i++)
        if ( p1 == FCuts[i].Src && p2 == FCuts[i].Dst ||
             p1 == FCuts[i].Dst && p2 == FCuts[i].Src)
			return FCuts.Items[i];*/
	return NULL;
}

TGCut *TGATriangulate::ExistsCutIn_GObjFCuts( TGCut* cut )
{
    if ( cut->Src->FCuts.Count < cut->Dst->FCuts.Count )
    {
    	for ( int i = 0; i < cut->Src->FCuts.Count; i++ )
            if ( cut->Src == cut->Src->FCuts[i].Src && cut->Dst == cut->Src->FCuts[i].Dst ||
                 cut->Src == cut->Src->FCuts[i].Dst && cut->Dst == cut->Src->FCuts[i].Src)
//            if ( cut->Equal(cut->Src->FCuts[i]) )
    			return cut->Src->FCuts.Items[i];
    }else{
    	for ( int i = 0; i < cut->Dst->FCuts.Count; i++ )
            if ( cut->Src == cut->Dst->FCuts[i].Src && cut->Dst == cut->Dst->FCuts[i].Dst ||
                 cut->Src == cut->Dst->FCuts[i].Dst && cut->Dst == cut->Dst->FCuts[i].Src)
			return cut->Dst->FCuts.Items[i];
//            if ( cut->Equal(cut->Dst->FCuts[i]) )
//    			return cut->Dst->FCuts.Items[i];
    }
	return NULL;
}

TGCut *TGATriangulate::NewCut(TGPoint *p1, TGPoint *p2)
{
    if ( !p1 || !p2 )
		throw EMyException ("<TGeomObject::NewCut> невозможно добавить отрезок!");
    if (  (int)p1 == 48 || (int)p2 == 48 )
		throw EMyException ("<TGeomObject::NewCut> невозможно добавить отрезок!");
/*	if (FVertex.IndexOf(p1) == -1)
		throw EMyException ("<TGeomObject::AddCut> первой точки нет в отрезке!");

	if (FVertex.IndexOf(p2) == -1)
		throw EMyException ("<TGeomObject::AddCut> второй точки нет в отрезке!");

	if (p2 == p1)
		throw EMyException ("<TGeomObject::AddCut> невозможно добавить отрезок с равными концами!");*/
/*TODO : CreateFunction*/
	TGCut& cut = *((TGCut *)GObj.CreateCutFunction()/*new TGCut*/);
//	TGCut& cut = *(new TGCut);

//	cut.FPoint[0] = p1;
//	cut.FPoint[1] = p2;

	cut.Src = p1;
	cut.Dst = p2;
    cut.Smooth = true;
    cut.Tag = 0;
    GObj.FCuts.Add(&cut);
	return &cut;
}

TGCut *TGATriangulate::AddCut(TGPoint *p1, TGPoint *p2)
{
    TGCut* TmpC = NewCut(p1, p2);
//    TGCut* TmpC = GObj.AddCut(p1, p2);
  	CutsBuild.Add(TmpC);
//    if ( !TmpC->FFlags.Alredy )
  //      TmpC->Smooth = true;
	return TmpC;
}

int TGATriangulate::classify(TIntVec& p2,TIntVec &p0, TIntVec &p1)
{
  TIntVec a = p1 - p0;
  TIntVec b = p2 - p0;
  float sa = a.x * b.y - b.x * a.y;
  if (sa > 0.0) return etLEFT;
  if (sa < 0.0) return etRIGHT;
  if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0)) return etBEHIND;
  if (a.x*a.x+a.y*a.y < b.x*b.x+b.y*b.y) return etBEYOND;
  if (p0 == p2) return etORIGIN;
  if (p1 == p2) return etDESTINATION;
  return etBETWEEN;
}

bool TGATriangulate::FindDeloneBrother(TGPoint* pnt1, TGPoint* pnt2)
{
    for (int i=0; i<CutsBuild.Count; i++)
        if ( pnt1 == CutsBuild[i].Src && pnt2 == CutsBuild[i].Dst ||
             pnt1 == CutsBuild[i].Dst && pnt2 == CutsBuild[i].Src)
            return true;
        else if ( SimpleIntersection(pnt1->Point, pnt2->Point, CutsBuild[i].Src->Point, CutsBuild[i].Dst->Point))
            return false;

    TGCut* TC = ExistsCutIn_FCuts(pnt1, pnt2);
    if ( TC == NULL )
    {
        AddCut(pnt1, pnt2)->Smooth = true;
    }else
    {
        CutsBuild.Add(TC);
    }

    MBTi _max = 1;
    TGPoint* iN = NULL;
    for (int i = 0; i < FVertex.Count; i++)
    {
        if (FVertex.Items[i] != pnt1 && FVertex.Items[i] != pnt2)                                   //  nCut->AnalizePoint(pAll[i],EPS)
            if ( classify(FVertex[i].Point, pnt1->Point, pnt2->Point) == etRIGHT )
            {
                TIntVec ii1 = FVertex[i].Point - pnt1->Point;
                TIntVec ii2 = FVertex[i].Point - pnt2->Point;
                float Angle = ii1.x*ii2.x+ii1.y*ii2.y;//*ii1.Scalar2D(ii2));x*Vec.x+y*Vec.y
                float tmp = (ii1.x*ii1.x+ii1.y*ii1.y)*(ii2.x*ii2.x+ii2.y*ii2.y);
                if (fabs(Angle)<EPS)
                    Angle=0;
                if (tmp == 0.0)
                    continue;
                if (Angle < 0.0)
                    Angle *= -Angle;
                else
                    Angle *= Angle;
                Angle /= tmp;
                if ( (-1/*+EPS*/ < Angle && Angle < _max/*-EPS*/) )
                    if (!CheckSimpleCrossing(FVertex[i], *pnt1, *pnt2))
                    {
                        _max = Angle;
                        iN = FVertex.Items[i];
                    }
            } // if (LEFT)
    } // for
//    bool not_cross = !CheckBldCrossing(*iN, *pnt1, *pnt2);
    if ( _max != 1 && iN == NULL )
        throw EMyException("");
    if ( _max != 1 && FindDeloneBrother(pnt1, iN) && FindDeloneBrother(iN, pnt2) )
    {
        TGCut* TC = ExistsCutIn_FCuts(iN, pnt1);
        if ( TC->Tag > 1 )
            return true;
        TGCut* TC1 = ExistsCutIn_FCuts(pnt1, pnt2);
        if ( TC1->Tag > 1 )
            return true;
        TGCut* TC2 = ExistsCutIn_FCuts(pnt2, iN);
        if ( TC2->Tag > 1 )
            return true;
        Triangles.Add(TC);
        Triangles.Add(TC1);
        Triangles.Add(TC2);
        TC->Tag++;
        TC1->Tag++;
        TC2->Tag++;

//TEST
/*    for ( int i = 0; i < Triangles.Count; i+=3 )
        for ( int j = i+3; j < Triangles.Count; j+=3 )
        {
            TMTList<TGCut> Cuts1;
            TMTList<TGCut> Cuts2;
            Cuts1.Add(Triangles.Items[i]);
            Cuts1.Add(Triangles.Items[i+1]);
            Cuts1.Add(Triangles.Items[i+2]);
            Cuts2.Add(Triangles.Items[j]);
            Cuts2.Add(Triangles.Items[j+1]);
            Cuts2.Add(Triangles.Items[j+2]);
            int k = 0;
            if ( Cuts1.Count == Cuts2.Count )
                for ( ; k < Cuts1.Count; k++ )
                    if ( Cuts2.IndexOf(Cuts1.Items[k]) == -1)
                          break;
            if ( k == Cuts1.Count )
                ErrorMsg("<TGATriangulate::Triangulate> Equal triangles");
        }*/
//TEST
    }
	return true;
}

void TGATriangulate::TriangulateByPoints()
{
    TGPoint* P1 = FVertex.Items[0];
    TGPoint* P2 = NULL;
    Find2BasePoints(P1, P2);
    if ( P2 == NULL )
        throw EMyException("<TGATriangulate::TriangulateByPoints> После Find2BasePoints P2 == NULL");
    FindDeloneBrother(P1, P2);
}

TMTList<TGCut>* TGATriangulate::Triangulate(TGPolygon *p)
{
    Triangles.Clear();
    if ( p->Count < 3 )
        return &Triangles;
//    FCuts.Clear();
    FVertex.Clear();
    CutsBuild.Clear();
    FCuts.Assign(&p->FCuts);
    for ( int i = 0; i < FCuts.Count; i++ )
        FCuts[i].Tag = 0;
    for( int i = 0; i < p->Count; i++ )
        FVertex.Add(&(p->Points[i]));
    for ( int j = 0; j < p->FHoles.Count; j++ )
        for( int i = 0; i < p->FHoles[j].Count; i++ )
        {
            FCuts.Add(&p->FHoles[j].FCuts[i]);
            FCuts.Last()->Tag = 0;
            FVertex.Add(&(p->FHoles[j].Points[i]));
        }

    TriangulateByPoints();

    for (int i = 0; i < Triangles.Count; )
    {
        TIntVec Center = (Triangles[i].Src->Point+Triangles[i+1].Src->Point+Triangles[i+2].Src->Point)/6;
        Center += (Triangles[i].Dst->Point+Triangles[i+1].Dst->Point+Triangles[i+2].Dst->Point)/6;
        if ( p->PointInPolygon_UseHoles2d(Center, EPS) == pipOUTSIDE)
        {
            Triangles.Delete(i);
            Triangles.Delete(i);
            Triangles.Delete(i);
        }else
            i+=3;
     }
/*     for ( int i = 0; i < FCuts.Count; i++ )
         for ( int j = CutsBuild.Count-1; j >= 0; j-- )
            if ( CutsBuild[j].Equal(FCuts[i]) )
            {
//                delete CutsBuild[j];
                CutsBuild.Delete(j);
            }*/
/*     for ( int j = 0; j < Triangles.Count; j++ )
        for ( int i = 0; i < CutsBuild.Count; i++ )
            if ( (Triangles[j].Src == FCuts[i].Src && Triangles[j].Dst == FCuts[i].Dst) ||
                 (Triangles[j].Src == FCuts[i].Dst && Triangles[j].Dst == FCuts[i].Src))
            {
                Triangles[j].Smooth = FCuts[i].Smooth;
                break;
            }else
            if ( Triangles[j].Equal( CutsBuild[i] ) )
                Triangles[j].Smooth = true;*/
/*    for ( int j = 0; j < Triangles.Count; j++ )
       Triangles[j].Smooth = true;*/
    return &Triangles;
}
void TGATriangulate::Triangulate()
{
	TGATriangulate CTrian(*this);
    TMTList<TGCut> TmpCuts;
//    TMDelTList<TGPoint> TmpVertex;
	int FirstCout = GObj.PolygonsCount;
    for ( int PolyIndex = FirstCout-1; PolyIndex >= 0; PolyIndex-- )
//    for ( int PolyIndex = 0; PolyIndex < FirstCout; PolyIndex++ )
    {
		TGPolygon* GHP = GObj.FPolygons.Items[PolyIndex];
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
			TmpCutsToPoly.Add(GObj.AddCut(TmpCuts[i]));
			TmpCutsToPoly.Add(GObj.AddCut(TmpCuts[i+1]));
			TmpCutsToPoly.Add(GObj.AddCut(TmpCuts[i+2]));
			GObj.AddPolygon( TmpCutsToPoly, TmpNormal);
			GObj.FPolygons.Last()->Tag = GObj.FPolygons[PolyIndex].Tag;
			GObj.FPolygons.Last()->FFlags = GObj.FPolygons[PolyIndex].FFlags;
		}
		GObj.FPolygons.Delete(PolyIndex);
	}
}


