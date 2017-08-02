//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "math.h"
#pragma hdrstop

#include "GeomObjV.h"

#include "MYGL.h"
#include "Poligon.h"
#include "TGMisc.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
const MBTi CrossEPS = 0.000000001;
const MBTi UpDownEPS = 0.0001;
const MBTi EqualEPS = 0.0000001;
const MBTi MyCEPS = 0.0001;
void TGeomObject::GetBBox2D(TGPolygon *p, TMDelTList<TIntVec>& BBox)
{
    BBox.Clear();
    BBox.Add( new TIntVec(p->GetPoint(0).Point) );
    BBox.Add( new TIntVec(p->GetPoint(0).Point) );
    for ( int i = 1; i < p->Count; i++ )
    {
        UpdateMinVector(BBox[0], p->GetPoint(i).Point);
        UpdateMaxVector(BBox[1], p->GetPoint(i).Point);
    }
}

void TGeomObject::GetBBox(TGPolygon *p)
{
    TIntVec LUBBox, RDBBox;
    LUBBox = RDBBox = p->GetPoint(0).Point;
    for ( int i = 1; i < p->Count; i++ )
    {
        UpdateMinVector(LUBBox, p->GetPoint(i).Point);
        UpdateMaxVector(RDBBox, p->GetPoint(i).Point);
    }
    p->BBoxCenter = TIntVec((LUBBox.x + RDBBox.x)/2, (LUBBox.y + RDBBox.y)/2, (LUBBox.z + RDBBox.z)/2);
    p->BBoxLengthDiv2 = TIntVec(fabs(LUBBox.x - RDBBox.x)/2, fabs(LUBBox.y - RDBBox.y)/2, fabs(LUBBox.z - RDBBox.z)/2);
}

void TGeomObject::GetBBox(TGCut *cut)
{
    TIntVec LUBBox, RDBBox;
    LUBBox = RDBBox = cut->Src->Point;
    UpdateMinVector(LUBBox, cut->Dst->Point);
    UpdateMaxVector(RDBBox, cut->Dst->Point);
    cut->BBoxCenter = TIntVec((LUBBox.x + RDBBox.x)/2, (LUBBox.y + RDBBox.y)/2, (LUBBox.z + RDBBox.z)/2);
    cut->BBoxLengthDiv2 = TIntVec((RDBBox.x - LUBBox.x)/2, (RDBBox.y - LUBBox.y)/2, (RDBBox.z - LUBBox.z)/2);
}

void TGeomObject::CalculateBBoxes()
{
    for ( int i = 0; i < FPolygons.Count; i++ )
        GetBBox(FPolygons.Items[i]);
    for ( int i = 0; i < FCuts.Count; i++ )
        GetBBox(FCuts.Items[i]);
}

bool TGeomObject::CompareBBox2D(TGPolygon *p1, TGPolygon *p2)
{
    if ( (fabs(p1->BBoxCenter.x - p2->BBoxCenter.x) <= p1->BBoxLengthDiv2.x + p2->BBoxLengthDiv2.x + PEPS) &&
         (fabs(p1->BBoxCenter.y - p2->BBoxCenter.y) <= p1->BBoxLengthDiv2.y + p2->BBoxLengthDiv2.y + PEPS) )
        return true;
    else
        return false;
}

bool TGeomObject::CompareBBox2D(TGCut *p1, TGCut *p2)
{
    if ( (fabs(p1->BBoxCenter.x - p2->BBoxCenter.x) <= p1->BBoxLengthDiv2.x + p2->BBoxLengthDiv2.x + PEPS) &&
         (fabs(p1->BBoxCenter.y - p2->BBoxCenter.y) <= p1->BBoxLengthDiv2.y + p2->BBoxLengthDiv2.y + PEPS) )
        return true;
    else
        return false;
}

void TGeomObject::ProjectToXY(TGeomObject &obj, TStatusBar* SB)
{
    for ( int i = 0; i < obj.FCuts.Count; i++ )
        obj.FCuts[i].Tag = i;
	Clear();
	TMTList<int> PInds;
	TMTList<int> CInds;
	for ( int i = 0; i < obj.VertexCount; i++ )
	{
		TGPoint* TmpP = AddPoint(TIntVec(obj.FVertex[i].Point.x, obj.FVertex[i].Point.y, 0));
		PInds.Add(new int(FVertex.IndexOf(TmpP)));
	}
	for ( int i = 0; i < obj.CutsCount; i++ )
	{
		int i1 = PInds[obj.FVertex.IndexOf(obj.FCuts[i].Src)];
		int i2 = PInds[obj.FVertex.IndexOf(obj.FCuts[i].Dst)];
		if (i1 != i2)
		{
			TGCut* TmpC = AddCut(i1, i2);

            if ( TmpC->FFlags.Alredy == gfTRUE )
            {
                float z1 = (obj.FCuts[TmpC->Tag].Src->Point.z + obj.FCuts[TmpC->Tag].Dst->Point.z)/2;
                float z2 = (obj.FCuts[i].Src->Point.z + obj.FCuts[i].Dst->Point.z)/2;
                if ( z2 > z1 )
                {
                    TmpC->FFlags = obj.FCuts[i].FFlags;
                    TmpC->Smooth = obj.FCuts[i].Smooth;
                    TmpC->Tag = obj.FCuts[i].Tag;
                }
//        		throw EMyException ("ProjectToXY: Equal cuts");
            }else
            {
                TmpC->FFlags = obj.FCuts[i].FFlags;
                TmpC->Smooth = obj.FCuts[i].Smooth;
                TmpC->Tag = obj.FCuts[i].Tag;
            }
			CInds.Add(new int(FCuts.IndexOf(TmpC)));
		}else
        {
			CInds.Add(new int(-1));
//            ErrorMsg(MSG_ERR_3);
        }
	}

	for ( int i = 0; i < obj.PolygonsCount; i++ )
	{
        SB->Panels[0].Items[0]->Text = IntToStr(int(float(i)/float(obj.PolygonsCount)*100))+'%';
        SB->Repaint();
        Application->ProcessMessages();

        obj.FPolygons[i].Tag = i;
		TMTList<int> TmpInds;
		for ( int j = 0; j < obj.FPolygons[i].Count; j++ )
			TmpInds.Add(new int(CInds[obj.FCuts.IndexOf(obj.FPolygons[i].FCuts.Items[j])]));

        int k;
        for ( k = 0; k < TmpInds.Count; k++ )
            if ( TmpInds[k] == -1 )
            {
                TmpInds.Delete(k);
                k--;
            }

        if ( TmpInds.Count < 3 )
            continue;

        FillPolygonsFlags(flMARK, gfFALSE);
        int j;
        for ( j = 0; j < TmpInds.Count; j++ )
            for ( int k = 0; k < FCuts[TmpInds[j]].FPlane.Count; k++ )
                if ( FCuts[TmpInds[j]].FPlane.Items[k] )
                    if ( TmpInds.Count == FCuts[TmpInds[j]].FPlane.Count )
                        FCuts[TmpInds[j]].FPlane[k].FFlags.Mark = gfTRUE;

		for ( j = 0; j < FPolygons.Count; j++ )
            if ( FPolygons[j].FFlags.Mark )
            {
                int k;
                for ( k = 0; k < FPolygons[j].Count; k++ )
                {
                    int d;
                    int Ind = FCuts.IndexOf(FPolygons[j].FCuts.Items[k]);
                    for ( d = 0; d < TmpInds.Count; d++ )
                        if ( TmpInds[d] == Ind )
                            break;
                    if ( d == TmpInds.Count )
                        break;
                }
                if ( k == FPolygons[j].Count )
                    break;
            }

        if ( j < FPolygons.Count )
        {
            int d;
            for ( d = 0; d < TmpInds.Count; d++ )
            {
                TIntVec Vec1, Vec2;
                int res1 = PlaneAndLineCrossed(obj.FPolygons[i].Origin, obj.FPolygons[i].Normal, FCuts[TmpInds[d]].Src->Point + TIntVec(0, 0, -1000), FCuts[TmpInds[d]].Src->Point + TIntVec(0, 0, 1000), false, false, Vec1, CrossEPS);
                int res2 = PlaneAndLineCrossed(FPolygons[j].Origin, FPolygons[j].Normal, FCuts[TmpInds[d]].Src->Point + TIntVec(0, 0, -1000), FCuts[TmpInds[d]].Src->Point + TIntVec(0, 0, 1000), false, false, Vec2, CrossEPS);
                if ( fabs(Vec1.z - Vec2.z) > UpDownEPS )
                    if ( Vec1.z > Vec2.z )
                    {
                        FPolygons[j].Tag = i;
                        break;
                    }else
                        break;
            }
            if ( d == TmpInds.Count )
                ErrorMsg("Equal Polygons cannot detect");
        }
        else
        {
//            if ( k == TmpInds.Count )
            {
//                if ( TmpInds.Count > 2 )
                {
                    TGPolygon* TmpPg = AddPolygon(TmpInds, TIntVec(0, 0, 1));
                    GetBBox( TmpPg );
                    TmpPg->Tag = i;
                    for ( int j = 0; j < obj.FPolygons[i].FHoles.Count; j++ )
                    {
                        TMTList<int> TmpHInds;
                        for ( int k = 0; k < obj.FPolygons[i].FHoles[j].Count; k++ )
                            TmpHInds.Add(new int(CInds[obj.FCuts.IndexOf(obj.FPolygons[i].FHoles[j].FCuts.Items[k])]));
                        TMTList<TGCut> TmpHCuts;
                        for ( int k = 0; k < TmpHInds.Count; k++ )
                            TmpHCuts.Add(FCuts.Items[TmpHInds[k]]);
                        TGPolygon* TmpHPg = TmpPg->AddHole(TmpHCuts);
                        TmpHPg->Tag = TmpPg->Tag;
                    }
                }
            }
        }
	}
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

void TGeomObject::DeleteBackFace()
{
	for ( int i = FPolygons.Count-1; i >= 0; i-- )
		if ( FPolygons[i].Normal.z <= 0.01 )
        {
            for ( int k = 0; k < FPolygons[i].FCuts.Count; k++ )
                FPolygons[i].FCuts[k].Smooth = false;
			DeletePolygon(i);
        }
    FreeUnused(fuAll);
/*	for ( int i = FCuts.Count-1; i >= 0; i-- )
    {
        int j;
        for ( j = 0; j < FCuts[i].FPlane.Count; j++ )
            if ( FCuts[i].FPlane.Items[j] != NULL )
                break;
        if ( j == FCuts[i].FPlane.Count )
            DeleteCut(i);
    }
	for ( int i = FVertex.Count-1; i >= 0; i-- )
        if ( FVertex[i].FCuts.Count == 0 )
            DeletePoint(i);*/
}

void TGeomObject::AddPolygonToCeils(TGPolygon* p, TGeomObject& obj, TMTList<TGPolygon>& Conveyor, TMTList<TGPolygon>& Ceils)
{
    TMTList<TGPolygon> Ceils1;
    Ceils1.Assign(&Ceils);
    Ceils.Clear();
    for ( int j = 0; j < Ceils1.Count; j++ )
    if ( p != NULL && Ceils1.Items[j] != NULL )
    {
      	TMTList<TGCut> Split1, Split2;
		TMDelTList< TMTList<TGCut> > poly[3];
	    if ( CompareBBox2D(p, Ceils1.Items[j]) && IntersectPolygons2DPoly2(p, Ceils1.Items[j], poly[0], poly[1], poly[2]))
        {
            for ( int jj = 0; jj < 3; jj++ )
                for ( int ii = 0; ii < poly[jj].Count; ii++ )
                {
                    TGPolygon* NewP = AddPolygon(poly[jj][ii], TIntVec(0, 0, 1) );
                    GetBBox( NewP );
                    if ( jj == 0 )
                    {
                        NewP->Tag = p->Tag;
                        if ( ii == 0 )
                            p = NewP;
                        else
                            Conveyor.Add(NewP);
                    }else if ( jj == 2 )
                    {
                        NewP->Tag = Ceils1[j].Tag;
                        Ceils.Add(NewP);
                    }else
                    {
                        int Ci = 0;
                        for ( ; Ci < poly[jj][ii].Count; Ci++ )
                        {
                            TIntVec Vec1, Vec2;
                            int res1 = PlaneAndLineCrossed(obj.FPolygons[p->Tag].Origin, obj.FPolygons[p->Tag].Normal, poly[jj][ii][Ci].Src->Point + TIntVec(0, 0, -1000), poly[jj][ii][Ci].Src->Point + TIntVec(0, 0, 1000), false, false, Vec1, CrossEPS);
                            int res2 = PlaneAndLineCrossed(obj.FPolygons[Ceils1[j].Tag].Origin, obj.FPolygons[Ceils1[j].Tag].Normal, poly[jj][ii][Ci].Src->Point + TIntVec(0, 0, -1000), poly[jj][ii][Ci].Src->Point + TIntVec(0, 0, 1000), false, false, Vec2, CrossEPS);
                            if ( fabs(Vec1.z - Vec2.z) > UpDownEPS )
                                if ( Vec1.z > Vec2.z )
                                {
                                    NewP->Tag = p->Tag;
                                    break;
                                }else
                                {
                                    NewP->Tag = Ceils1[j].Tag;
                                    break;
                                }
                        }
                        if ( Ci == poly[jj][ii].Count )
                        {
    	    				ErrorMsg("Cannot classify split from AnalyticalRender");
                            NewP->Tag = Ceils1[j].Tag;
                        }
                        Ceils.Add(NewP);
                    }
                }
            if ( poly[0].Count == 0 || Ceils1.Count == 0 )
                p = NULL;
        }else
            Ceils.Add(Ceils1.Items[j]);
        Ceils1.Delete(j);
        j--;
    }
    if ( p != NULL )
    {
        Ceils.Add(p);
        p = NULL;
    }
    if ( Ceils1.Count > 0 )
        for ( int i = 0; i < Ceils1.Count; i++ )
            Ceils.Add(Ceils1.Items[i]);
}

void TGeomObject::AddPolygonToCeilsUseHoles(TGPolygon* p, TGeomObject& obj, TMTList<TGPolygon>& Conveyor, TMTList<TGPolygon>& Ceils)
{
    long int addrP = (long int)p;
    TMTList<TGPolygon> Ceils1;
    Ceils1.Assign(&Ceils);
    Ceils.Clear();
/*                            for ( int kk = 0; kk < Ceils1.Count; kk++ )
                                if ( p->Equal(Ceils1[kk]) )
                                    throw EMyException("<TGeomObject::AddPolygonToCeilsUseHoles> p->Equal(Ceils1[kk])");*/
    long int TmpTicks1 = GetTickCount();
    long int num = 0;
    for ( int j = 0; j < Ceils1.Count; j++ )
    if ( p != NULL && Ceils1.Items[j] != NULL )
    {
        num++;
      	TMTList<TGCut> Split1, Split2;
		TMTList<TGPolygon> poly[3];
        bool test1 = false;
        bool test2 = false;
        long int addr = (long int)p;
        if ( CompareBBox2D(p, Ceils1.Items[j]) )
        {
            test1 = true;
    long int TmpTicks = GetTickCount();
            if ( !p->Equal(Ceils1[j]) ){
                test2 = IntersectPolygonsUseHoles(p, Ceils1.Items[j], poly[0], poly[1], poly[2]);
            }else
            {
/*                if ( p->Tag == Ceils1[j].Tag )
                    throw EMyException("<TGeomObject::AddPolygonToCeilsUseHoles>: p->Tag == Ceils1[j].Tag");*/
/*                if ( p->Tag != Ceils1[j].Tag )
                {
                    int Tag1 = p->Tag;
                    int Tag2 = Ceils1[j].Tag;
                    int Ci = 0;
                    for ( ; Ci < p->Count; Ci++ )
                    {
                        TIntVec Vec1, Vec2;
                        TIntVec Point = p->GetPoint(Ci).Point;
    //                    TIntVec Point = poly[jj][ii].FCuts[Ci].Src->Point;
                        int res1 = PlaneAndLineCrossed(obj.FPolygons[Tag1].Origin, obj.FPolygons[Tag1].Normal, Point + TIntVec(0, 0, -100), Point + TIntVec(0, 0, 100), false, false, Vec1, CrossEPS);
                        int res2 = PlaneAndLineCrossed(obj.FPolygons[Tag2].Origin, obj.FPolygons[Tag2].Normal, Point + TIntVec(0, 0, -100), Point + TIntVec(0, 0, 100), false, false, Vec2, CrossEPS);
                        if ( fabs(Vec1.z - Vec2.z) > UpDownEPS )
                            if ( Vec1.z > Vec2.z )
                            {
                                Ceils1[j].Tag = Tag1;
                                break;
                            }else
                            {
                                Ceils1[j].Tag = Tag2;
                                break;
                            }
                    }
                    if ( Ci == p->Count )
                    {
                        throw EMyException("<TGeomObject::AddPolygonToCeilsUseHoles>: cannot classify equal polygons");
                        Ceils1[j].Tag = Tag2;
                    }
                }
                for ( int k = 0; k < Ceils1[j].FHoles.Count; k++ )
                    if ( Ceils1[j].FHoles.Items[k] )
                        Ceils1[j].FHoles[k].Tag = Ceils1[j].Tag;
                Delete(p);
                p = NULL;
                continue;*/
            }
    TmpTicks = GetTickCount() - TmpTicks;
    TickCount5 += TmpTicks;
        }
	    if ( test2 && test1 )
        {
            int pTag = p->Tag;
            for ( int jj = 0; jj < 3; jj++ )
                for ( int ii = 0; ii < poly[jj].Count; ii++ )
                {
                    TGPolygon* NewP = poly[jj].Items[ii];
                    GetBBox( NewP );
                    if ( jj == 0 )
                    {
                        NewP->Tag = pTag;
                        for ( int k = 0; k < NewP->FHoles.Count; k++ )
                            if ( NewP->FHoles.Items[k] )
                                NewP->FHoles[k].Tag = NewP->Tag;
                        if ( ii == 0 )
                        {
/*                            for ( int kk = 0; kk < Ceils1.Count; kk++ )
                                if ( NewP->Equal(Ceils1[kk]) )
                                    throw EMyException("<TGeomObject::AddPolygonToCeilsUseHoles> NewP->Equal(Ceils1[kk])");
                            for ( int kk = 0; kk < Ceils.Count; kk++ )
                                if ( NewP->Equal(Ceils[kk]) )
                                    throw EMyException("<TGeomObject::AddPolygonToCeilsUseHoles> NewP->Equal(Ceils[kk])");*/
                            p = NewP;
                        }else
                        {
/*                            for ( int kk = 0; kk < Ceils1.Count; kk++ )
                                if ( NewP->Equal(Ceils1[kk]) )
                                    throw EMyException("<TGeomObject::AddPolygonToCeilsUseHoles> NewP->Equal(Ceils1[kk])");
                            for ( int kk = 0; kk < Ceils.Count; kk++ )
                                if ( NewP->Equal(Ceils[kk]) )
                                    throw EMyException("<TGeomObject::AddPolygonToCeilsUseHoles> NewP->Equal(Ceils[kk])");*/
                            Conveyor.Add(NewP);
                        }
                    }else if ( jj == 2 )
                    {
                        NewP->Tag = Ceils1[j].Tag;
                        for ( int k = 0; k < NewP->FHoles.Count; k++ )
                            if ( NewP->FHoles.Items[k] )
                                NewP->FHoles[k].Tag = NewP->Tag;
                        Ceils.Add(NewP);
                    }else
                    {
                        if ( pTag != Ceils1[j].Tag )
                        {
                            int Ci = 0;
                            for ( ; Ci < poly[jj][ii].Count; Ci++ )
                            {
                                TIntVec Vec1, Vec2;
                                TIntVec Point = poly[jj][ii].GetPoint(Ci).Point;
    //                            TIntVec Point = poly[jj][ii].FCuts[Ci].Src->Point;
                                int res1 = PlaneAndLineCrossed(obj.FPolygons[pTag].Origin, obj.FPolygons[pTag].Normal, Point + TIntVec(0, 0, -100), Point + TIntVec(0, 0, 100), false, false, Vec1, CrossEPS);
                                int res2 = PlaneAndLineCrossed(obj.FPolygons[Ceils1[j].Tag].Origin, obj.FPolygons[Ceils1[j].Tag].Normal, Point + TIntVec(0, 0, -100), Point + TIntVec(0, 0, 100), false, false, Vec2, CrossEPS);
                                if ( fabs(Vec1.z - Vec2.z) > UpDownEPS )
                                    if ( Vec1.z > Vec2.z )
                                    {
                                        NewP->Tag = pTag;
                                        break;
                                    }else
                                    {
                                        NewP->Tag = Ceils1[j].Tag;
                                        break;
                                    }
                            }
                            if ( Ci == poly[jj][ii].Count )
                            {
                                throw EMyException("<TGeomObject::AddPolygonToCeilsUseHoles>: cannot classify split");
                                NewP->Tag = Ceils1[j].Tag;
                            }
                        }else
                            NewP->Tag = pTag;
                        for ( int k = 0; k < NewP->FHoles.Count; k++ )
                            if ( NewP->FHoles.Items[k] )
                                NewP->FHoles[k].Tag = NewP->Tag;
                        Ceils.Add(NewP);
                    }
                }
            if ( poly[0].Count == 0 || Ceils1.Count == 0 )
                p = NULL;
        }else
        {
            Ceils.Add(Ceils1.Items[j]);
        }
        Ceils1.Delete(j);
        j--;
    }
    TmpTicks1 = GetTickCount() - TmpTicks1;
    TickCount4 += TmpTicks1;
    if ( p != NULL )
    {
        Ceils.Add(p);
        p = NULL;
    }
    if ( Ceils1.Count > 0 )
        for ( int i = 0; i < Ceils1.Count; i++ )
        {
            Ceils.Add(Ceils1.Items[i]);
        }
}

void TGeomObject::GetCeilsGroup(TGPolygon& p, TMTList<TGPolygon>& Poly)
{
    Poly.Add(&p);
    for ( int i = 0; i < p.FCuts.Count; i++ )
        if ( p.FCuts[i].FFlags.Mark == gfFALSE )
        {
            int j;
            for ( j = 0; j < p.FCuts[i].FPlane.Count; j++ )
                if ( p.FCuts[i].FPlane.Items[j] != NULL )
                    if ( p.FCuts[i].FPlane.Items[j] != &p && p.FCuts[i].FPlane[j].Tag == p.Tag )
                        break;
            if ( j != p.FCuts[i].FPlane.Count )
            {
                p.FCuts[i].FFlags.Mark = gfTRUE;
                GetCeilsGroup(p.FCuts[i].FPlane[j], Poly);
            }
        }
}

void TGeomObject::GetSmoothGroupForAnRen(TGPolygon& p, TMTList<TGPolygon>& Poly)
{
    Poly.Add(&p);
    for ( int i = 0; i < p.FCuts.Count; i++ )
        if ( p.FCuts[i].FFlags.Mark == gfTRUE )
        {
            int j;
            for ( j = 0; j < p.FCuts[i].FPlane.Count; j++ )
                if ( p.FCuts[i].FPlane.Items[j] != NULL )
                    if ( p.FCuts[i].FPlane.Items[j] != &p )
                    {
                        p.FCuts[i].FFlags.Mark = gfFALSE;
                        GetSmoothGroupForAnRen(p.FCuts[i].FPlane[j], Poly);
                    }
        }
}

bool TGeomObject::ConditionForSmooth(TGCut *cut, TGPolygon *p1, TGPolygon *p2)
{
//  if ( cut )
    for ( int i = 0; i < p1->Count; i++ )
        for ( int j = 0; j < p1->FCuts[i].FPlane.Count; j++ )
            if ( p1->FCuts[i].Smooth )
                p1->FCuts[i].FFlags.Mark = gfTRUE;

    if ( cut && cut->Smooth )
    {
/*        if ( cut )
            for ( int i = 0; i < p1->Count; i++ )
                if ( p2->FCuts.IndexOf(p1->FCuts.Items[i]) != -1 )
                    p1->FCuts[i].FFlags.Mark = gfTRUE;*/
        return true;
    }else
        return false;
}

bool TGeomObject::ConditionForTagAndHole(TGCut *cut, TGPolygon *p1, TGPolygon *p2)
{
//  if ( cut )
    for ( int i = 0; i < p1->Count; i++ )
        for ( int j = 0; j < p1->FCuts[i].FPlane.Count; j++ )
            if ( p1->FCuts[i].FPlane.Items[j] && p1->FCuts[i].FPlane.Items[j] != p1 )
/*              if ( !p1->FCuts[i].FPlane[j].FParent || !p1->FParent )
               if ( !(!p1->FCuts[i].FPlane[j].FParent && p1->FParent) )*/
                if ( p1->FCuts[i].FPlane[j].Tag == p1->Tag && p1->FParent && p1->FCuts[i].FPlane[j].FParent )
                    p1->FCuts[i].FFlags.Mark = gfTRUE;

    if ( p1->Tag == p2->Tag && p1->FParent && p2->FParent )
    {
/*        if ( cut )
            for ( int i = 0; i < p1->Count; i++ )
                if ( p2->FCuts.IndexOf(p1->FCuts.Items[i]) != -1 )
                    p1->FCuts[i].FFlags.Mark = gfTRUE;*/
        return true;
    }else
        return false;
}

bool TGeomObject::ConditionForTag(TGCut *cut, TGPolygon *p1, TGPolygon *p2)
{
//  if ( cut )
    for ( int i = 0; i < p1->Count; i++ )
        for ( int j = 0; j < p1->FCuts[i].FPlane.Count; j++ )
            if ( p1->FCuts[i].FPlane.Items[j] && p1->FCuts[i].FPlane.Items[j] != p1 )
/*              if ( !p1->FCuts[i].FPlane[j].FParent || !p1->FParent )
               if ( !(!p1->FCuts[i].FPlane[j].FParent && p1->FParent) )*/
                if ( p1->FCuts[i].FPlane[j].Tag == p1->Tag )
                    p1->FCuts[i].FFlags.Mark = gfTRUE;

    if ( p1->Tag == p2->Tag )
    {
/*        if ( cut )
            for ( int i = 0; i < p1->Count; i++ )
                if ( p2->FCuts.IndexOf(p1->FCuts.Items[i]) != -1 )
                    p1->FCuts[i].FFlags.Mark = gfTRUE;*/
        return true;
    }else
        return false;
}

void TGeomObject::PassByObject(TGPolygon *p, TConditionForPass& ConditionForPass)
{
	p->Flags.Mark = gfTRUE;
	for ( int i = 0; i < p->FHoles.Count; i++ )
		if ( p->FHoles[i].FFlags.Mark == gfFALSE )
            if ( ConditionForPass( NULL, p, p->FHoles.Items[i] ) )
		    	PassByObject( p->FHoles.Items[i], ConditionForPass );
	for ( int i = 0; i < p->FCuts.Count; i++ )
		for ( int j = 0; j < p->FCuts[i].FPlane.Count; j++ )
			if ( p->FCuts[i].FPlane.Items[j] && p->FCuts[i].FPlane.Items[j] != p )
			{
				TGPolygon *o = p->FCuts[i].FPlane.Items[j];
				if (o->FFlags.Mark == gfTRUE)
					continue;
                if ( ConditionForPass( p->FCuts.Items[i], p, o ) )
	    	    	PassByObject( o, ConditionForPass );
			}
	if (p->FParent && p->FParent->FFlags.Mark == gfFALSE)
        if ( ConditionForPass( NULL, p, p->FParent ) )
            PassByObject( p->FParent, ConditionForPass );
}

void TGeomObject::AnalyticalRenderConveyor(TGeomObject& obj, TStatusBar* SB)
{
    long int TmpTicks = GetTickCount();
    SB->Panels[0].Items[1]->Text = "DeleteBackFace";
    SB->Repaint();

	DeleteBackFace();

    SB->Panels[0].Items[1]->Text = "Assign";
    SB->Repaint();

	obj.Assign(this);

    SB->Panels[0].Items[1]->Text = "ProjectToXY";
    SB->Repaint();

	ProjectToXY(obj, SB);

return;
    SB->Panels[0].Items[1]->Text = "CalculateBBoxes";
    SB->Repaint();

    CalculateBBoxes();

    SB->Panels[0].Items[1]->Text = "ProcessCrossCuts2D";
    SB->Repaint();

    drProcessCrossCuts2d(SB);

/*    for ( int i = 0; i < FCuts.Count; i++ )
        for ( int j = i+1; j < FCuts.Count; j++ )
            if ( FCuts[i].Src == FCuts[j].Src && FCuts[i].Dst == FCuts[j].Dst ||
                 FCuts[i].Src == FCuts[j].Dst && FCuts[i].Dst == FCuts[j].Src )
                throw EMyException("ProcessCrossCuts: Наложение отрезков");*/

    for ( int i = 0; i < FCuts.Count; i++ )
        if ( !FCuts.Items[i] || !FCuts[i].Src || !FCuts[i].Dst )
            throw EMyException("ProcessCrossCuts: NULL mlya");
    for ( int i = 0; i < FPolygons.Count; i++ )
        for ( int j = 0; j < FPolygons[i].FCuts.Count; j++ )
            if ( FCuts.IndexOf(FPolygons[i].FCuts.Items[j]) == -1 )
                throw EMyException("ProcessCrossCuts: NULL mlya (-1) ");

    TMDelTList< TMTList<TGCut> > Polys;
/*    Polygonize2d(FCuts, Polys);
    for ( int i = 0; i < Polys.Count; i++ )
        AddPolygon(Polys[i]);
    return;*/
/*    TGeomObject objBuff;
    objBuff.Assign(this);*/
/*	for ( int i = 0; i < FPolygons.Count; i++ )
    {
        obj.FPolygons[i].Tag = i;
        FPolygons[i].Tag = i;
    }*/
    TMTList<TGPolygon> Ceils;
    TMTList<TGPolygon> Conveyor;
//    FPolygons.Delete(1);
    for ( int i = 0; i < FPolygons.Count; i++ )
        Conveyor.Add(FPolygons.Items[i]);
    SB->Panels[0].Items[1]->Text = "AnalyticalRender";
    SB->Repaint();
    int ConCount = Conveyor.Count;
    int num = 0;

    TmpTicks = GetTickCount() - TmpTicks;
    TickCount1 += TmpTicks;

//return;
    TGPolygon *DelP = NULL;
    TmpTicks = GetTickCount();
    for ( int i = 0; i < Conveyor.Count; i++ )
    {
        num++;
        AddPolygonToCeilsUseHoles(Conveyor.Items[i], obj, Conveyor, Ceils);

/*    for ( int i = 0; i < FPolygons.Count; i++ )
        for ( int j = i+1; j < FPolygons.Count; j++ )
            if ( FPolygons[i].Equal(FPolygons[j]) )
                throw EMyException("Equals polygons!");*/

//        AddPolygonToCeils(Conveyor.Items[i], obj, Conveyor, Ceils);
        Conveyor.Delete(i);
        i--;
        SB->Panels[0].Items[0]->Text = IntToStr(int(float(ConCount-Conveyor.Count)/float(ConCount)*100))+'%';
        SB->Repaint();
        Application->ProcessMessages();
    }
/*    int i;
    for ( i = FPolygons.Count-1 ;i >=0; i--  )
        if ( FPolygons[i].Count != 68 )
            FPolygons.Delete(i);
    FreeUnused(fuAll);
return;     */
    TmpTicks = GetTickCount() - TmpTicks;
    TickCount2 += TmpTicks;
//return;
    TmpTicks = GetTickCount();
    for ( int i = 0; i < Ceils.Count; i++ )
        if ( FPolygons.IndexOf( Ceils.Items[i] ) == -1 )
            ErrorMsg(MSG_ERR_4);
//            FPolygons.Add(Ceils.Items[i]);

    for ( int i = FPolygons.Count-1; i >= 0 ; i-- )
        if ( Ceils.IndexOf( FPolygons.Items[i] ) == -1 )
            FPolygons.Delete(i);
//return;
  for ( int i = 0; i < FPolygons.Count; i++ )
    for ( int iH = 0; iH < FPolygons[i].FHoles.Count; iH++ )
    {
        TMTList<TGCut> TmpCuts;
        TmpCuts.Assign(&FPolygons[i].FCuts);
        int TmpTag = FPolygons[i].Tag;

        FillCutsFlags(FCuts, flMARK, gfFALSE);
        FillPolygonsFlags(FPolygons, flMARK, gfFALSE);

//        GetCeilsGroup(FPolygons[i], TmpPoly);
        PassByObject(FPolygons[i].FHoles.Items[iH], ConditionForTagAndHole);
        int k;
        for ( k = 0; k < FPolygons[i].FHoles.Count; k++ )
            if ( k != iH )
                if ( FPolygons[i].FHoles[k].FFlags.Mark )
                    break;
        if ( k < FPolygons[i].FHoles.Count )
        {
            for ( int k = 0; k < FPolygons[i].FHoles.Count; k++ )
//                if ( FPolygons[i].FHoles[k].FFlags.Mark )
                {
                    for ( int j = 0; j < FPolygons[i].FHoles[k].Count; j++ )
                        if ( FPolygons[i].FHoles[k].FCuts[j].FFlags.Mark == gfFALSE )
                            if ( TmpCuts.IndexOf(FPolygons[i].FHoles[k].FCuts.Items[j]) == -1 )
                                TmpCuts.Add(FPolygons[i].FHoles[k].FCuts.Items[j]);
                }
            FPolygons.Remove(FPolygons.Items[i]);

            TMDelTList< TMTList<TGCut> > Poly;
            TGPoint *begin = GetLowestPoint2d(TmpCuts);
            TMTList <TGCut> contour;
            drPolygonize(TmpCuts, Poly);
            TMTList< TGPolygon > RPoly;
            for ( int j = 0; j < Poly.Count; j++ )
            {
                RPoly.Add(AddPolygon(Poly[j], TIntVec(0, 0, 1)));
                GetBBox(RPoly.Last());
                RPoly.Last()->Tag = TmpTag;
            }
            DetectHoles2d(RPoly);

            i--;
            break;
        }
    }
    FreeUnused(fuAll);

    for ( int i = 0; i < FPolygons.Count; i++ )
    {
        TMTList<TGCut> TmpCuts;
        TMTList<TGPolygon> TmpPoly;
        int TmpTag = FPolygons[i].Tag;

        FillCutsFlags(FCuts, flMARK, gfFALSE);
        FillPolygonsFlags(FPolygons, flMARK, gfFALSE);

//        GetCeilsGroup(FPolygons[i], TmpPoly);
        PassByObject(FPolygons.Items[i], ConditionForTag);

        for ( int j = 0; j < FPolygons.Count; j++ )
            if ( FPolygons[j].FFlags.Mark )
                TmpPoly.Add(FPolygons.Items[j]);
//                if ( TmpPoly.IndexOf(FPolygons.Items[j]) == -1 )
  //                  TmpPoly.Add(FPolygons.Items[j]);
    //            else
      //              ErrorMsg("AnalRen: Повторный полигон!");

//        for ( int j = 0; j < FPolygons.Count; j++ )
  //          if ( FPolygons[j].FCuts.Count == 0 )
    //        {
      //          ErrorMsg("FPolygons[j].FCuts.Count == 0");
        //        return;
          //  }

        if ( TmpPoly.Count > 1 )
        {
            for ( int k = 0; k < TmpPoly.Count; k++ )
            {
                for ( int j = 0; j < TmpPoly[k].Count; j++ )
                    if ( TmpPoly[k].FCuts[j].FFlags.Mark == gfFALSE )
                      if ( TmpCuts.IndexOf(TmpPoly[k].FCuts.Items[j]) == -1 )
                        TmpCuts.Add(TmpPoly[k].FCuts.Items[j]);
                for ( int d = 0; d < TmpPoly[k].FHoles.Count; d++ )
                    if ( TmpPoly[k].FHoles[d].FFlags.Mark )
                    {
                        for ( int j = 0; j < TmpPoly[k].FHoles[d].Count; j++ )
                            if ( TmpPoly[k].FHoles[d].FCuts[j].FFlags.Mark == gfFALSE )
                              if ( TmpCuts.IndexOf(TmpPoly[k].FHoles[d].FCuts.Items[j]) == -1 )
                                TmpCuts.Add(TmpPoly[k].FHoles[d].FCuts.Items[j]);
                    }
            }
            for ( int k = 0; k < TmpPoly.Count; k++ )
                if ( FPolygons.IndexOf(TmpPoly.Items[k]) != -1 )
                    FPolygons.Remove(TmpPoly.Items[k]);

            TMDelTList< TMTList<TGCut> > Poly;
            TGPoint *begin = GetLowestPoint2d(TmpCuts);
            TMTList <TGCut> contour;
            Polygonize2d(TmpCuts, Poly);
            TMTList< TGPolygon > RPoly;
            for ( int j = 0; j < Poly.Count; j++ )
            {
                RPoly.Add(AddPolygon(Poly[j], TIntVec(0, 0, 1)));
                GetBBox(RPoly.Last());
                RPoly.Last()->Tag = TmpTag;
                i=-1;
            }
            DetectHoles2d(RPoly);
//            for ( int j = 0; j < RPoly.Count; j++ )
  //              if ( RPoly[j].FCuts.Count == 0 )
    //            {
      //              ErrorMsg("RPoly[j].FCuts.Count == 0");
        //            return;
          //      }
        }
    }
    FreeUnused(fuAll);
//    FPolygons.Clear();
/*    TMTList<TGCut> Inds;
    FillCutsFlags(FCuts, flMARK, gfFALSE);
    for ( int i = 0; i < FCuts.Count; i++ )
    {
        if ( FCuts[i].Smooth )
        {
            int RealCutInd = FCuts[i].Tag;
            int ii;
            for ( ii = 0; ii < FCuts[i].FPlane.Count; ii++ )
                if ( FCuts[i].FPlane.Items[ii] != NULL )
                {
                    int jj;
                    for ( jj = 0; jj < obj.FCuts[RealCutInd].FPlane.Count; jj++ )
//                      if ( obj.FPolygons.Count > FCuts[i].FPlane[ii].Tag && FCuts[i].FPlane[ii].Tag >= 0 )
                        if ( obj.FCuts[RealCutInd].FPlane.Items[jj] != NULL && obj.FPolygons.Items[FCuts[i].FPlane[ii].Tag] == obj.FCuts[RealCutInd].FPlane.Items[jj] )
                            break;
                    if ( jj == obj.FCuts[RealCutInd].FPlane.Count )
                        break;
                }
            if ( ii == FCuts[i].FPlane.Count )
                if ( Inds.IndexOf(FCuts.Items[i]) == -1 )//на всякий пожарный, убрать при оптимизации
                {
                    Inds.Add(FCuts.Items[i]);
                    FCuts[i].FFlags.Mark = gfTRUE;
                }
        }
    }

    FPolygons.Clear();

    for ( int i = 0; i < Inds.Count; i++ )
        FCuts.Remove(Inds.Items[i]);

    TMDelTList< TMTList<TGCut> > Polys;
    Polygonize2d(FCuts, Polys);
    for ( int i = 0; i < Polys.Count; i++ )
        AddPolygon(Polys[i], TIntVec(0, 0, 1));

    DetectHolesAtAll(PEPS, MyCEPS);*/

    for ( int i = 0; i < FPolygons.Count; i++ )
    {
        TMTList<TGCut> TmpCuts;
        TMTList<TGPolygon> TmpPoly;
        int TmpTag = FPolygons[i].Tag;

        FillCutsFlags(FCuts, flMARK, gfFALSE);
        FillPolygonsFlags(FPolygons, flMARK, gfFALSE);

//        GetCeilsGroup(FPolygons[i], TmpPoly);
        PassByObject(FPolygons.Items[i], ConditionForSmooth);

        for ( int j = 0; j < FPolygons.Count; j++ )
            if ( FPolygons[j].FFlags.Mark )
                TmpPoly.Add(FPolygons.Items[j]);

        if ( TmpPoly.Count > 1 )
        {
            for ( int k = 0; k < TmpPoly.Count; k++ )
            {
                for ( int j = 0; j < TmpPoly[k].Count; j++ )
                    if ( TmpPoly[k].FCuts[j].FFlags.Mark == gfFALSE )
                      if ( TmpCuts.IndexOf(TmpPoly[k].FCuts.Items[j]) == -1 )
                        TmpCuts.Add(TmpPoly[k].FCuts.Items[j]);
                for ( int d = 0; d < TmpPoly[k].FHoles.Count; d++ )
                    if ( TmpPoly[k].FHoles[d].FFlags.Mark )
                    {
                        for ( int j = 0; j < TmpPoly[k].FHoles[d].Count; j++ )
                            if ( TmpPoly[k].FHoles[d].FCuts[j].FFlags.Mark == gfFALSE )
                              if ( TmpCuts.IndexOf(TmpPoly[k].FHoles[d].FCuts.Items[j]) == -1 )
                                TmpCuts.Add(TmpPoly[k].FHoles[d].FCuts.Items[j]);
                    }
            }
            for ( int k = 0; k < TmpPoly.Count; k++ )
                if ( FPolygons.IndexOf(TmpPoly.Items[k]) != -1 )
                    FPolygons.Remove(TmpPoly.Items[k]);

            TMDelTList< TMTList<TGCut> > Poly;
            TGPoint *begin = GetLowestPoint2d(TmpCuts);
            TMTList <TGCut> contour;
            Polygonize2d(TmpCuts, Poly);
            TMTList< TGPolygon > RPoly;
            for ( int j = 0; j < Poly.Count; j++ )
            {
                RPoly.Add(AddPolygon(Poly[j], TIntVec(0, 0, 1)));
                GetBBox(RPoly.Last());
                RPoly.Last()->Tag = TmpTag;
                i=-1;
            }
            DetectHoles2d(RPoly);
        }
    }

/*    for ( int i = 0; i < Inds.Count; i++ )
    if ( Inds[i].FFlags.Mark == gfTRUE )
    {
        TMTList<TGCut> TmpCuts;
        int TmpTag;
        for ( int k = 0; k < Inds[i].FPlane.Count; k++ )
            if( Inds[i].FPlane.Items[k] != NULL )
            {
                TMTList<TGPolygon> TmpPoly;
                GetSmoothGroupForAnRen(Inds[i].FPlane[k], TmpPoly);
                for ( int ii = 0; ii < TmpPoly.Count; ii++ )
                {
                    for ( int jj = 0; jj < TmpPoly[ii].Count; jj++ )
                        if ( TmpCuts.IndexOf(TmpPoly[ii].FCuts.Items[jj]) == -1 )
                            TmpCuts.Add(TmpPoly[ii].FCuts.Items[jj]);
                    TmpTag = TmpPoly[ii].Tag;
                    FPolygons.Remove(TmpPoly.Items[ii]);
                }

//1                for ( int ii = 0; ii < Inds[i].FPlane[k].Count; ii++ )
//                    if ( Inds.Items[i] != Inds[i].FPlane[k].FCuts.Items[ii] )
//1                        if ( TmpCuts.IndexOf(Inds[i].FPlane[k].FCuts.Items[ii]) == -1 )
//1                            TmpCuts.Add(Inds[i].FPlane[k].FCuts.Items[ii]);
//1                FPolygons.Remove(Inds[i].FPlane.Items[k]);
//1                k--;
            }

        TMDelTList< TMTList<TGCut> > Poly;
        TGPoint *begin = GetLowestPoint(TmpCuts);
        TMTList <TGCut> contour;
//        Contourize(TmpCuts, contour, begin);
        if ( Polygonize(TmpCuts, Poly) )
            if ( Poly.Count == 1 )
                for ( int k = 0; k < Poly.Count; k++ )
                {
                    TGPolygon* p = AddPolygon(Poly[k], TIntVec(0, 0, 1));
                    p->Tag = TmpTag;
                }
            else
                ErrorMsg("Poly.Count != 1");

    }else
        FCuts.Remove(Inds.Items[i]);*/
/*    TMTList<TGCut> TmpCuts;
    TMDelTList< TMTList<TGCut> > TmpPoly;
    for ( int i = 0; i < FCuts.Count; i++ )
        TmpCuts.Add(FCuts.Items[i]);
    Polygonize(TmpCuts, TmpPoly);
    for ( int i = 0; i < TmpPoly.Count; i++ )
        AddPolygon(TmpPoly[i], TIntVec(0, 0, 1));*/
/*    for ( int i = 0; i < FCuts.Count; i++ )
        if ( FCuts[i].FFlags.Mark )
        {
            TMTList<TGCut> TmpCuts;
            TMTList<TGPolygon> TmpPoly;
            for ( int k = 0; k < FCuts[i].FPlane.Count; k++ )
                TmpPoly.Add(FCuts[i].FPlane.Items[k]);

            if ( TmpPoly.Count > 1 )
            {
                for ( int k = 0; k < TmpPoly.Count; k++ )
                    for ( int j = 0; j < TmpPoly[k].Count; j++ )
                        if ( TmpCuts.IndexOf(TmpPoly[k].FCuts.Items[j]) == -1 )
                            TmpCuts.Add(TmpPoly[k].FCuts.Items[j]);
                for ( int k = 0; k < TmpPoly.Count; k++ )
                    FPolygons.Remove(TmpPoly.Items[k]);

                TMDelTList< TMTList<TGCut> > Poly;
                TGPoint *begin = GetLowestPoint(TmpCuts);
                TMTList <TGCut> contour;
                Contourize(TmpCuts, contour, begin);
                if ( Polygonize(contour, Poly) )
                {
                    for ( int k = 0; k < Poly.Count; k++ )
                    {
                        TGPolygon* p = AddPolygon(Poly[k], TIntVec(0, 0, 1));
                        p->Tag = TmpPoly[0].Tag;
                    }
                    i=-1;
                }
            }
        }*/
/*                FCuts.Delete(i);
                i--;*/

/*    for ( int i = 0; i < FCuts.Count; i++ )
    {
        int TmpTag = -1;
        for ( int ii = 0; ii < FCuts[i].FPlane.Count; ii++ )
            for ( int jj = ii+1; jj < FCuts[i].FPlane.Count; jj++ )
//                if ( ii != jj )
                    if (FCuts[i].FPlane.Items[ii] != NULL && FCuts[i].FPlane.Items[jj] != NULL)
                        if (FCuts[i].FPlane[ii].Tag == FCuts[i].FPlane[jj].Tag)
                        {
                            TMTList<TGCut> TmpCuts;
                            for ( int k = 0; k < FCuts[i].FPlane[ii].FCuts.Count; k++ )
                                if ( FCuts[i].FPlane[ii].FCuts.Items[k] != FCuts.Items[i]  FCuts[i].FPlane[jj].FCuts.IndexOf(FCuts[i].FPlane[ii].FCuts.Items[k]) == -1  )
                                    TmpCuts.Add(FCuts[i].FPlane[ii].FCuts.Items[k]);

                            for ( int k = 0; k < FCuts[i].FPlane[jj].FCuts.Count; k++ )
                                if ( FCuts[i].FPlane[jj].FCuts.Items[k] != FCuts.Items[i] FCuts[i].FPlane[ii].FCuts.IndexOf(FCuts[i].FPlane[jj].FCuts.Items[k]) == -1 )
                                    TmpCuts.Add(FCuts[i].FPlane[jj].FCuts.Items[k]);

                            TMDelTList< TMTList<TGCut> > Poly;
                    		TGPoint *begin = GetLowestPoint(TmpCuts);
                			TMTList <TGCut> contour;
                			Contourize(TmpCuts, contour, begin);
			                if ( Polygonize(contour, Poly) )
                            {
                                TGPolygon* pii = FCuts[i].FPlane.Items[ii];
                                TGPolygon* pjj = FCuts[i].FPlane.Items[jj];
                                FPolygons.Remove(pii);
                                FPolygons.Remove(pjj);

                                AddPolygon(Poly[0]);
                                break;
                                break;
                                i=-1;
                            }
                       }
    }*/
    FreeUnused(fuAll);
/*    for ( int i = 0; i < FPolygons.Count; i++ )
        FPolygons[i].FNormal = obj.FPolygons[FPolygons[i].Tag].FNormal;
    for ( int i = 0; i < FCuts.Count; i++ )
        FCuts[i].Smooth = false;*/
    SB->Panels[0].Items[0]->Text = "";
    SB->Panels[0].Items[1]->Text = "Process successfully!!!";
    SB->Repaint();
    TmpTicks = GetTickCount() - TmpTicks;
    TickCount3 += TmpTicks;
}

int TGeomObject::drPointInPolygon_UseHoles2d( TGPolygon* p, const TIntVec &Point, MBTi USEEPS, TGPolygon*& Hole )
{
	int result = p->PointInPolygon2d(Point,USEEPS);
	if (result != pipINSIDE)
		return result;
	for (int i=0;i<p->FHoles.Count;i++)
	{
	   int result_hole = p->FHoles.Items[i]->PointInPolygon2d(Point,USEEPS);
	   if ( result_hole == pipINSIDE)
       {
            Hole = p->FHoles.Items[i];
			return pipOUTSIDE;
       }
	   if ( result_hole == pipBOUNDARY)
       {
            Hole = p->FHoles.Items[i];
			return pipHOLEBOUNDARY;
       }
	}
	return pipINSIDE;
}

//Optimize Step1: Done
bool TGeomObject::ExistsPolygonInPolygonUseHoles2(TMTList<TGCut>& cuts, TGPolygon& PolygonUseHole, bool UseHoles)
{
    int j;
    int PIPQ = 0;
    for ( j = 0; j < cuts.Count; j++ )
    {
        int PIPC = PolygonUseHole.PointInPolygon_UseHoles2d( (cuts[j].Src->Point+cuts[j].Dst->Point)/2, PEPS);
        if ( PIPC == pipOUTSIDE )
            return false;
        if ( PIPC == pipINSIDE )
            return true;
        if ( PIPQ != PIPC )
            if ( PIPQ == 0 )
                PIPQ = PIPC;
            else
                throw EMyException("<TGeomObject::ExistsPolygonInPolygonUseHoles2>: Не отслеженная ситуация!");
    }

    TIntVec Vec = GetPointInPolygon2d(cuts);
    if ( PIPQ == pipHOLEBOUNDARY )
        if ( PolygonUseHole.PointInPolygon_UseHoles2d(Vec, PEPS) == pipOUTSIDE )
            return false;
        else
            return true;

    if ( PIPQ == pipBOUNDARY )
        if ( PolygonUseHole.PointInPolygon2d(Vec, PEPS) == pipOUTSIDE )
            return false;
        else
            return true;
    throw EMyException("<TGeomObject::ExistsPolygonInPolygonUseHoles2>: Не отслеженная ситуация!");
    return false;
}

//не забывать про флаг!!!
bool TGeomObject::ExistsPolygonInPolygonUseHoles(TMTList<TGCut>& cuts, TGPolygon& PolygonUseHole, bool DifferentHoles)
{
    int j;
    for ( j = 0; j < cuts.Count; j++ )
    {
        int PIPS = PolygonUseHole.PointInPolygon_UseHoles2d( cuts[j].Src->Point, PEPS);
        int PIPD = PolygonUseHole.PointInPolygon_UseHoles2d( cuts[j].Dst->Point, PEPS);
        int PIPC = PolygonUseHole.PointInPolygon_UseHoles2d( (cuts[j].Src->Point+cuts[j].Dst->Point)/2, PEPS);
        if ( PIPS == pipOUTSIDE || PIPD == pipOUTSIDE || PIPC == pipOUTSIDE )
            break;
    }
    if ( j == cuts.Count )
    {
        int jj;
        TGPolygon* TestH;
        for ( jj = 0; jj < cuts.Count; jj++ )
        {
            TGPolygon* TmpHole = NULL;
            int PIPS = drPointInPolygon_UseHoles2d( &PolygonUseHole, cuts[jj].Src->Point, PEPS, TmpHole);
            if ( DifferentHoles && TmpHole)
            {
                if ( jj == 0 )
                    TestH = TmpHole;
                else
                    if ( TestH != TmpHole )
                        break;
            }
            int PIPD = drPointInPolygon_UseHoles2d( &PolygonUseHole, cuts[jj].Dst->Point, PEPS, TmpHole);
            if ( DifferentHoles && TmpHole )
            {
                if ( jj == 0 && !TestH )
                    TestH = TmpHole;
                else
                    if ( TestH != TmpHole )
                        break;
            }
            int PIPC = drPointInPolygon_UseHoles2d( &PolygonUseHole, (cuts[jj].Src->Point+cuts[jj].Dst->Point)/2, PEPS, TmpHole);
            if ( DifferentHoles  && TmpHole )
            {
                if ( jj == 0 && !TestH )
                    TestH = TmpHole;
                else
                    if ( TestH != TmpHole )
                        break;
            }
            if ( PIPS != pipHOLEBOUNDARY || PIPD != pipHOLEBOUNDARY || PIPC != pipHOLEBOUNDARY )
                break;
        }
        if ( jj == cuts.Count )
        {
/*            TIntVec Vec = PointInPolygon2d(cuts);
//            if ( UseHoles )
                if ( PolygonUseHole.PointInPolygon_UseHoles2d(Vec, PEPS) == pipOUTSIDE )
                    return false;
                else
                    return true;
            else
                if ( PolygonUseHole.PointInPolygon2d(Vec, PEPS) == pipOUTSIDE )
                    return false;
                else
                    return true;*/
            return false;
        }else
        {
            int k;
            for ( k = 0; k < cuts.Count; k++ )
            {
                TGPolygon* TmpHole = NULL;
                int PIPS = drPointInPolygon_UseHoles2d( &PolygonUseHole, cuts[k].Src->Point, PEPS, TmpHole);
                int PIPD = drPointInPolygon_UseHoles2d( &PolygonUseHole, cuts[k].Dst->Point, PEPS, TmpHole);
                int PIPC = drPointInPolygon_UseHoles2d( &PolygonUseHole, (cuts[k].Src->Point+cuts[k].Dst->Point)/2, PEPS, TmpHole);
                if ( PIPS != pipBOUNDARY || PIPD != pipBOUNDARY || PIPC != pipBOUNDARY )
                    break;
            }
            if ( k < cuts.Count )
                return true;
            else
            {
                TIntVec Vec = GetPointInPolygon2d(cuts);
                if ( PolygonUseHole.PointInPolygon2d(Vec, PEPS) == pipOUTSIDE )
                    return false;
                else
                    return true;
            }
        }
    }else
        return false;
}

bool TGeomObject::ExistsPolygonInPolygon(TMTList<TGCut>& cuts, const TGPolygon& Polygon)
{
    int j;
    for ( j = 0; j < cuts.Count; j++ )
    {
        int PIPS = Polygon.PointInPolygon2d( cuts[j].Src->Point, PEPS);
        int PIPD = Polygon.PointInPolygon2d( cuts[j].Dst->Point, PEPS);
        int PIPC = Polygon.PointInPolygon2d( (cuts[j].Src->Point+cuts[j].Dst->Point)/2, PEPS);
        if ( PIPS == pipOUTSIDE || PIPD == pipOUTSIDE || PIPC == pipOUTSIDE )
            break;
    }
    if ( j == cuts.Count )
    {
        TIntVec Vec = GetPointInPolygon2d(cuts);
        if ( Polygon.PointInPolygon2d(Vec, PEPS) == pipOUTSIDE )
            return false;
        else
            return true;
    }else
        return false;
}

void TGeomObject::ConstructPolygonsFromHoles( TGPolygon& p, TMTList<TGPolygon>& poly)
{
    poly.Add(&p);
    for ( int i = 0; i < p.FHoles.Count; i++ )
        if ( p.FHoles.Items[i] )
        {
            for ( int j = 0; j < p.FHoles[i].FHoles.Count; j++ )
                if ( p.FHoles[i].FHoles.Items[j] )
                {
/*                    TMTList<TGCut> TmpCuts;
                    TmpCuts.Assign(&p.FHoles[i].FHoles[j].FCuts);
                    p.FHoles[i].FHoles.Delete(j);
                    j--;
                    p.FHoles[i].FHoles.
                    ConstructPolygonsFromHoles(AddPolygon);*/
                    ErrorMsg("<TGeomObject::IntersectPolygonsUseHoles>: Дырка в дырке!");
                }
        }
}

bool TGeomObject::IntersectPolygons2DPoly2( TGPolygon* p1, TGPolygon* p2, TMDelTList< TMTList<TGCut> > &Onlyp1, TMDelTList< TMTList<TGCut> > &Split, TMDelTList< TMTList<TGCut> > &Onlyp2)
{
    TMDelTList<int> ClassifyPolygons;
    TMTList<TGCut> Split1;
    TMDelTList< TMTList<TGCut> > Poly;
    Split1.Assign(&p1->FCuts);
	for ( int i = 0; i < p2->FCuts.Count; i++ )
        if (Split1.IndexOf(p2->FCuts.Items[i]) == -1 )
			Split1.Add(p2->FCuts.Items[i]);

//	drProcessCrossCuts2D2(Split1);

	bool ret = drPolygonize(Split1, Poly);

	if ( !ret )
        return false;
    for ( int i = 0; i < Poly.Count; i++ )
    {
        int j;
        for ( j = 0; j < Poly[i].Count; j++ )
        {
            int PIPS = p1->PointInPolygon2d( Poly[i][j].Src->Point, PEPS);
            int PIPD = p1->PointInPolygon2d( Poly[i][j].Dst->Point, PEPS);
            int PIPC = p1->PointInPolygon2d( (Poly[i][j].Src->Point+Poly[i][j].Dst->Point)/2, PEPS);
            if ( PIPS == pipOUTSIDE || PIPD == pipOUTSIDE || PIPC == pipOUTSIDE )
                break;
        }
        if ( j == Poly[i].Count )
//                Onlyp1.Add(&Poly[i]);
            ClassifyPolygons.Add(new int(1));
        else
            ClassifyPolygons.Add(new int(0));
    }

    for ( int i = 0; i < Poly.Count; i++ )
    {
        int j;
        for ( j = 0; j < Poly[i].Count; j++ )
        {
            int PIPS = p2->PointInPolygon2d( Poly[i][j].Src->Point, PEPS);
            int PIPD = p2->PointInPolygon2d( Poly[i][j].Dst->Point, PEPS);
            int PIPC = p2->PointInPolygon2d( (Poly[i][j].Src->Point+Poly[i][j].Dst->Point)/2, PEPS);
            if ( PIPS == pipOUTSIDE || PIPD == pipOUTSIDE || PIPC == pipOUTSIDE )
                break;
        }
/*                if ( !p2->PointInPolygon( Poly[i][j].Src->Point, PEPS) || !p2->PointInPolygon( Poly[i][j].Dst->Point, PEPS) )
                break;*/
        if ( j == Poly[i].Count )
            if (ClassifyPolygons[i] == 1)
                ClassifyPolygons[i] = 2;
    }

    for ( int i = 0; i < Poly.Count; i++ )
    {
        if ( ClassifyPolygons[i] == 0 )
        {
            Onlyp2.Add(new TMTList<TGCut>());
            Onlyp2.Last()->Assign(&Poly[i]);
        }
        else if ( ClassifyPolygons[i] == 1 )
        {
            Onlyp1.Add(new TMTList<TGCut>());
            Onlyp1.Last()->Assign(&Poly[i]);
        }else
        {
            Split.Add(new TMTList<TGCut>());
            Split.Last()->Assign(&Poly[i]);
        }
    }
    if ( Split.Count > 0 )
        return true;
    else
        return false;
}

bool TGeomObject::IntersectPolygonsUseHoles( TGPolygon* p1, TGPolygon* p2, TMTList<TGPolygon> &POnlyp1, TMTList<TGPolygon> &PSplit, TMTList<TGPolygon> &POnlyp2)
{
    TMDelTList<int> ClassifyPolygons;
    TMTList<TGCut> Split1;
    TMDelTList< TMTList<TGCut> > Poly;
//    TMTList<TGPolygon> FPolys;

/*    if ( p1->Count < p2->Count )
    {
        int i = 0;
        for ( ; i < p1->Count; i++ )
        {
            int j = 0;
            for ( ; j < p1->GetPoint(i).FCuts.Count; j++ )
                if ( p2->FCuts.IndexOf(p1->GetPoint(i).FCuts.Items[j]) != -1 )
                    break;
            if ( j < p1->GetPoint(i).FCuts.Count )
                break;
        }
        if ( i == p1->Count )
            return false;
    }else
    {
        int i = 0;
        for ( ; i < p2->Count; i++ )
        {
            int j = 0;
            for ( ; j < p2->GetPoint(i).FCuts.Count; j++ )
                if ( p1->FCuts.IndexOf(p2->GetPoint(i).FCuts.Items[j]) != -1 )
                    break;
            if ( j < p2->GetPoint(i).FCuts.Count )
                break;
        }
        if ( i == p2->Count )
            return false;
    }             */

    Split1.Assign(&p1->FCuts);
    for ( int i = 0; i < p1->FHoles.Count; i++ )
        for ( int j = 0; j < p1->FHoles[i].Count; j++ )
            if (Split1.IndexOf(p1->FHoles[i].FCuts.Items[j]) == -1 )
                Split1.Add(p1->FHoles[i].FCuts.Items[j]);

	for ( int i = 0; i < p2->FCuts.Count; i++ )
        if (Split1.IndexOf(p2->FCuts.Items[i]) == -1 )
			Split1.Add(p2->FCuts.Items[i]);

    for ( int i = 0; i < p2->FHoles.Count; i++ )
        for ( int j = 0; j < p2->FHoles[i].Count; j++ )
            if (Split1.IndexOf(p2->FHoles[i].FCuts.Items[j]) == -1 )
                Split1.Add(p2->FHoles[i].FCuts.Items[j]);

	if ( !drPolygonize(Split1, Poly) )
        return false;

    bool NoSplit = true;
    for ( int i = 0; i < Poly.Count; i++ )
        if ( ExistsPolygonInPolygonUseHoles2(Poly[i], *p1, false) )
            ClassifyPolygons.Add(new int(1));
        else
            ClassifyPolygons.Add(new int(-1));

    for ( int i = 0; i < Poly.Count; i++ )
        if ( ExistsPolygonInPolygonUseHoles2(Poly[i], *p2, false) )
            if (ClassifyPolygons[i] == 1)
            {
                ClassifyPolygons[i] = 0;
                NoSplit = false;
            }else
                ClassifyPolygons[i] = 2;
    if ( NoSplit )
        return false;
/*
0 - Split
1 - p1
2 - p2
*/
    for ( int i = 0; i < Poly.Count; i++ )
        if ( ClassifyPolygons[i] == 0 )
        {
            PSplit.Add(AddPolygon(Poly[i], TIntVec(0, 0, 1)));
//            PSplit.Add(FPolys.Items[i]);
            GetBBox(PSplit.Last());
        }else if ( ClassifyPolygons[i] == 1 )
        {
            POnlyp1.Add(AddPolygon(Poly[i], TIntVec(0, 0, 1)));
//            POnlyp1.Add(FPolys.Items[i]);
            GetBBox(POnlyp1.Last());
        }else if ( ClassifyPolygons[i] == 2 )
        {
            POnlyp2.Add(AddPolygon(Poly[i], TIntVec(0, 0, 1)));
//            POnlyp2.Add(FPolys.Items[i]);
            GetBBox(POnlyp2.Last());
        }

    long int TmpTicks = GetTickCount();
    DetectHoles2d(PSplit);
    DetectHoles2d(POnlyp1);
    DetectHoles2d(POnlyp2);
    TmpTicks = GetTickCount() - TmpTicks;
    TickCount6 += TmpTicks;

    TMTList<TGPolygon> Test;
    for ( int k = 0; k < PSplit.Count; k++ )
        ConstructPolygonsFromHoles(PSplit[k], Test);
    for ( int k = 0; k < POnlyp1.Count; k++ )
        ConstructPolygonsFromHoles(POnlyp1[k], Test);
    for ( int k = 0; k < POnlyp2.Count; k++ )
        ConstructPolygonsFromHoles(POnlyp2[k], Test);

    long int TmpTicks1 = GetTickCount();
    for ( int k = POnlyp1.Count-1; k >= 0; k-- )
        if ( FPolygons.IndexOf( POnlyp1.Items[k] ) == -1 )
        {
            TIntVec Vec = GetPointInPolygon2d(POnlyp1[k].FCuts);
            if ( p1->PointInPolygon_UseHoles2d(Vec, PEPS) == pipOUTSIDE )
            {
                //!!!Fpolygons.Remove(POnlyp1.Items[k]);
                POnlyp1.Delete(k);
            }else
                POnlyp1.Items[k] = AddPolygon(POnlyp1[k].FCuts, TIntVec(0, 0, 1) );
        }else
        {
            //!!!Fpolygons.Remove(POnlyp1.Items[k]);
//            POnlyp1.Delete(k);
        }

    for ( int k = PSplit.Count-1; k >= 0; k-- )
        if ( FPolygons.IndexOf( PSplit.Items[k] ) == -1 )
        {
            TIntVec Vec = GetPointInPolygon2d(PSplit[k].FCuts);
            if ( p1->PointInPolygon_UseHoles2d(Vec, PEPS) == pipOUTSIDE )
            {
                //!!!Fpolygons.Remove(PSplit.Items[k]);
                PSplit.Delete(k);
            }else
                PSplit.Items[k] = AddPolygon(PSplit[k].FCuts, TIntVec(0, 0, 1) );
        }else
        {
            //!!!Fpolygons.Remove(PSplit.Items[k]);
//            PSplit.Delete(k);
        }

    for ( int k = POnlyp2.Count-1; k >= 0; k-- )
        if ( FPolygons.IndexOf( POnlyp2.Items[k] ) == -1 )
        {
            TIntVec Vec = GetPointInPolygon2d(POnlyp2[k].FCuts);
            if ( p2->PointInPolygon_UseHoles2d(Vec, PEPS) == pipOUTSIDE )
            {
                //!!!Fpolygons.Remove(POnlyp2.Items[k]);
                POnlyp2.Delete(k);
            }else
                POnlyp2.Items[k] = AddPolygon(POnlyp2[k].FCuts, TIntVec(0, 0, 1) );
        }else
        {
            //!!!Fpolygons.Remove(POnlyp2.Items[k]);
//            POnlyp2.Delete(k);
        }

    for ( int k = 0; k < PSplit.Count; k++ )
        for ( int i = 0; i < Poly.Count; i++ )
            if ( ClassifyPolygons[i] != 0 )
                if ( ExistsPolygonInPolygonUseHoles2(Poly[i], PSplit[k], true) )
                    PSplit[k].AddHole(Poly[i]);

    for ( int k = 0; k < POnlyp1.Count; k++ )
        for ( int i = 0; i < Poly.Count; i++ )
            if ( ClassifyPolygons[i] == 0 || ClassifyPolygons[i] == -1 )
                if ( ExistsPolygonInPolygonUseHoles2(Poly[i], POnlyp1[k], true) )
                    POnlyp1[k].AddHole(Poly[i]);

    for ( int k = 0; k < POnlyp2.Count; k++ )
        for ( int i = 0; i < Poly.Count; i++ )
            if ( ClassifyPolygons[i] == 0 || ClassifyPolygons[i] == -1 )
                if ( ExistsPolygonInPolygonUseHoles2(Poly[i], POnlyp2[k], true) )
                    POnlyp2[k].AddHole(Poly[i]);

    /*TEST*/
    for ( int k = 0; k < POnlyp1.Count; k++ )
        for ( int i = 0; i < Poly.Count; i++ )
            if ( ClassifyPolygons[i] == 2 )
                if ( ExistsPolygonInPolygonUseHoles2(Poly[i], POnlyp1[k], true) )
                    POnlyp1[k].AddHole(Poly[i]);

    for ( int k = 0; k < POnlyp2.Count; k++ )
        for ( int i = 0; i < Poly.Count; i++ )
            if ( ClassifyPolygons[i] == 1 )
                if ( ExistsPolygonInPolygonUseHoles2(Poly[i], POnlyp2[k], true) )
                    POnlyp2[k].AddHole(Poly[i]);
    /*TEST*/
    TmpTicks1 = GetTickCount() - TmpTicks1;
    TickCount7 += TmpTicks1;

//    for ( int i = 0; i < POnlyp1->Count; i++ )

    if ( PSplit.Count > 0 )
        return true;
    else
    {
/*        POnlyp1.Clear();
        POnlyp2.Clear();
        POnlyp1.Add(p1);
        POnlyp2.Add(p2);*/
        return false;
    }
}

void TGeomObject::drProcessCrossCuts2d(TStatusBar* SB)
{
	drProcessCrossCuts2d(FCuts, SB);
}

bool TGeomObject::drConsistsPoint(const TGPoint& Point, const TGCut& Cut) const
{
	int res = Classify(Point.Point, Cut.Src->Point, Cut.Dst->Point, PEPS);
	return (res == etBETWEEN /*|| res == etDESTINATION || res == etORIGIN */);
}

bool TGeomObject::drSplitCut(TGCut *c, TGPoint *&newPnt, TGCut *&Result1, TGCut *&Result2)
{
//Modify newPoint
    TIntVec Vec;
    MBTi dx = c->Dst->Point.x - c->Src->Point.x;
    MBTi dy = c->Dst->Point.y - c->Src->Point.y;
    IsLinesCrossedExactly(c->Src->Point, c->Dst->Point, newPnt->Point, TIntVec(dy+newPnt->Point.x, -dx+newPnt->Point.y, 0), Vec);
//    FillPointsFlags(flALREDY, gfFALSE);
    TGPoint* Pnt = AddPoint(Vec);
    if ( newPnt != Pnt )
    {
        if ( Pnt->FFlags.Alredy == gfTRUE )
            Pnt->FFlags = FlagUnite(Pnt->FFlags, newPnt->FFlags);
        else
        {
            Pnt->FFlags = newPnt->FFlags;
            Pnt->Tag = newPnt->Tag;
        }
        for ( int i = newPnt->FCuts.Count-1; i >= 0; i-- )
        {
            TGCut* Buf = newPnt->FCuts.Items[i];
            if ( newPnt->FCuts[i].Src == newPnt )
                newPnt->FCuts[i].Src = Pnt;
            else if ( newPnt->FCuts[i].Dst == newPnt )
                newPnt->FCuts[i].Dst = Pnt;
            GetBBox(Buf);
        }
        Delete(newPnt);
        newPnt = Pnt;
    }
//Modify newPoint    */

	if (c->ConsistsPoint(newPnt))
		return false;
        
	TGCut *cn = AddCut(c->Src, newPnt);
    GetBBox(cn);
	TGCut *cn1 = AddCut(newPnt, c->Dst);
    GetBBox(cn1);

    if ( c == cn )
        throw EMyException("<TGeomObject::drSplitCut> c == cn");
    if ( c == cn1 )
        throw EMyException("<TGeomObject::drSplitCut> c == cn1");

	for (int i=0;i<c->FPlane.Count;i++)
		if (c->FPlane.Items[i])
        {
            int Ind = c->FPlane[i].FCuts.IndexOf(cn);
            int Ind1 = c->FPlane[i].FCuts.IndexOf(cn1);
            if ( Ind == -1 && Ind1 == -1 )
            {
                int index = c->FPlane[i].FCuts.IndexOf(c);
                if ( c->FPlane[i].FCuts.CycVal(index-1).CanConnect(*cn))
                {
                    c->FPlane[i].FCuts.Insert(index, cn1);
                    c->FPlane[i].FCuts.Insert(index, cn);
                }
                else
                {
                    c->FPlane[i].FCuts.Insert(index, cn);
                    c->FPlane[i].FCuts.Insert(index, cn1);
                }
                cn->FPlane.Add(c->FPlane.Items[i]);
                cn1->FPlane.Add(c->FPlane.Items[i]);
            }
            c->FPlane[i].FCuts.Remove(c);
            c->FPlane.Items[i] = NULL;
        }

	Result1 = cn;
	Result2 = cn1;
    if ( Result1 != NULL )
    {
        Result1->Tag = c->Tag;
        Result1->Smooth = c->Smooth;
        Result1->FFlags.Mark = gfFALSE;
    }
    if ( Result2 != NULL )
    {
        Result2->Tag = c->Tag;
        Result2->Smooth = c->Smooth;
        Result2->FFlags.Mark = gfFALSE;
    }

	FCuts.Remove(c);
	return true;
}

bool TGeomObject::SplitCutForCrossedCuts(TMTList<TGCut>& aCuts, TGCut *&c, TGPoint *&Pnt, TMTList<TGCut>& CutsConveyor)
{
    int IndexCutConv = CutsConveyor.IndexOf(c);
    TGCut *Res1, *Res2;
    if ( drSplitCut(c, Pnt, Res1, Res2) )
    {
        if (&aCuts != &FCuts)
        {
            aCuts.Remove(c);
            if (Res1 != NULL && aCuts.IndexOf(Res1) == -1)
                aCuts.Add(Res1);
            if (Res2 != NULL && aCuts.IndexOf(Res2) == -1)
                aCuts.Add(Res2);
        }
        if ( IndexCutConv != -1 )
            CutsConveyor.Delete(IndexCutConv);
        if ( Res1 != NULL && CutsConveyor.IndexOf(Res1) == -1 )
            CutsConveyor.Add(Res1);
        if ( Res2 != NULL && CutsConveyor.IndexOf(Res2) == -1 )
            CutsConveyor.Add(Res2);
        return true;
    }
    return false;
}

bool TGeomObject::drProcessCrossCuts2d(TMTList<TGCut>& aCuts, TStatusBar* SB)
{
    bool ret = false;
    TMTList<TGCut> CutsConveyor;
	for ( int i = 0; i < FCuts.Count; i++ )
        GetBBox(FCuts.Items[i]);
	for ( int i = 0; i < aCuts.Count; i++ )
        CutsConveyor.Add(aCuts.Items[i]);

    while ( CutsConveyor.Count > 0 )
    {
        SB->Panels[0].Items[0]->Text = IntToStr(int(float(CutsConveyor.Count)/float(aCuts.Count)*100))+'%';
        SB->Repaint();
        Application->ProcessMessages();
        TGCut &CutConv = CutsConveyor[0];
        for ( int j = 0; j < aCuts.Count; j++ )
            if ( aCuts.Items[j] != &CutConv && CompareBBox2D(&CutConv, aCuts.Items[j]) )
            {
                bool iC_jSrc = drConsistsPoint(*aCuts[j].Src, CutConv);
                bool iC_jDst = drConsistsPoint(*aCuts[j].Dst, CutConv);
                bool jC_iSrc = drConsistsPoint(*CutConv.Src, aCuts[j]);
                bool jC_iDst = drConsistsPoint(*CutConv.Dst, aCuts[j]);

                if (iC_jSrc || iC_jDst)
                {
                    if ( SplitCutForCrossedCuts(aCuts, &CutConv, iC_jSrc ? aCuts[j].Src : aCuts[j].Dst, CutsConveyor) )
                    {
                        ret = true;
                        break;
                    }
                    continue;
                }
                if (jC_iSrc || jC_iDst)
                {
                    if ( SplitCutForCrossedCuts(aCuts, aCuts.Items[j], jC_iSrc ? CutConv.Src : CutConv.Dst, CutsConveyor) )
                    {
                        j--;
                        ret = true;
                    }
                    continue;
                }

                if ( CutConv.Src == aCuts[j].Src || CutConv.Src == aCuts[j].Dst ||
                     CutConv.Dst == aCuts[j].Src || CutConv.Dst == aCuts[j].Dst)
                    continue;

                TIntVec Vec;
                if ( CutCutCross2d(CutConv.Src->Point, CutConv.Dst->Point,
                                   aCuts[j].Src->Point, aCuts[j].Dst->Point, Vec, CrossEPS) == 1 )
                {
                    TGPoint* TmpP = AddPoint(Vec);
                    TGCut* TmpCj = aCuts.Items[j];
                    TGCut* TmpCi = &CutConv;
                    if ( TmpP != TmpCj->Dst && TmpP != TmpCj->Src )
                        if ( SplitCutForCrossedCuts(aCuts, TmpCj, TmpP, CutsConveyor) )
                        {
                            j--;
                            ret = true;
                        }

                    if ( TmpP != TmpCi->Dst && TmpP != TmpCi->Src )
                        if ( SplitCutForCrossedCuts(aCuts, TmpCi, TmpP, CutsConveyor) )
                        {
                            ret = true;
                            break;
                        }
                }
            }
        if ( &CutConv == CutsConveyor.Items[0] )
            CutsConveyor.Delete(0);
    }
	return ret;
}

TIntVec TGeomObject::PointInPolygon(TGPolygon* p)
{
    if ( p->Count < 3 )
        return ZEROINTVEC;

    TGPolygon* GHP = p;
    TIntVec TmpNormal = GHP->FNormal;
    TIntVec ang = GetToPlaneTransformation(TmpNormal);
    for ( int i = 0; i < GHP->Count; i++ )
        GHP->GetPoint(i).Point = TransformTo(GHP->GetPoint(i).Point, ang);

    for (int i = 0; i < GHP->FHoles.Count; i++ )
        for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
            GHP->FHoles.Items[i]->GetPoint(j).Point = TransformTo(GHP->FHoles.Items[i]->GetPoint(j).Point, ang);

    TIntVec p0(p->GetPoint(0).Point), p1(p->GetPoint(1).Point), p2(p->GetPoint(2).Point);
    int i;
    for ( i = 2; i < p->Count; i++ )
    {
        if ( fabs(p1.y - p0.y) > PEPS )
        {
            MBTi k1 = (p1.x - p0.x)/(p1.y - p0.y);
            MBTi k2 = (p1.z - p0.z)/(p1.y - p0.y);
            p2 = p->GetPoint(i).Point;
            if ( fabs((p2.x - p0.x)/(p2.y - p0.y) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.y - p0.y) - k2) > MyCEPS )
                break;
        }else if (  fabs(p1.x - p0.x) > PEPS )
        {
            MBTi k1 = (p1.y - p0.y)/(p1.x - p0.x);
            MBTi k2 = (p1.z - p0.z)/(p1.x - p0.x);
            p2 = p->GetPoint(i).Point;
            if ( fabs((p2.y - p0.y)/(p2.x - p0.x) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.x - p0.x) - k2) > MyCEPS )
                break;
        }else
        {
            MBTi k1 = (p1.y - p0.y)/(p1.z - p0.z);
            MBTi k2 = (p1.x - p0.x)/(p1.z - p0.z);
            p2 = p->GetPoint(i).Point;
            if ( fabs((p2.y - p0.y)/(p2.z - p0.z) - k1) > MyCEPS || fabs((p2.x - p0.x)/(p2.z - p0.z) - k2) > MyCEPS )
                break;
        }
    }
    if ( i == p->Count )
    {
        ErrorMsg("< TGeomObject::PointInPolygon>: Точки полигона на одной линии");
        for ( int i = 0; i < GHP->Count; i++ )
            GHP->GetPoint(i).Point = TransformFrom(GHP->GetPoint(i).Point, ang);

        for (int i = 0; i < GHP->FHoles.Count; i++ )
            for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
                GHP->FHoles.Items[i]->GetPoint(j).Point = TransformFrom(GHP->FHoles.Items[i]->GetPoint(j).Point, ang);
        GHP->FNormal = TmpNormal;
        return TransformFrom(TIntVec((p0.x + p1.x)/2, (p0.y  + p1.y)/2, (p0.z + p1.z)/2), ang);
    }
//        throw EMyException ("< TGeomObject::PointInPolygon>: Точки полигона на одной линии");

    TIntVec pCenter( (p2.x + p0.x)/2, (p2.y + p0.y)/2, (p2.z + p0.z)/2 );

    TIntVec p0XY = p0;
    TIntVec p1XY = p1;
    TIntVec p2XY = p2;
    TIntVec pCenterXY = pCenter;

    if ( Classify(pCenterXY, p0XY, p1XY, PEPS) == etLEFT || Classify(pCenterXY, p1XY, p2XY, PEPS) == etLEFT )
        pCenter = TIntVec(2*p1.x - pCenter.x, 2*p1.y - pCenter.y, 2*p1.z - pCenter.z);

//    return pCenter;

    TIntVec MinVec;
    MBTi MinDist = 1000000000;
    for ( int j = 0; j < p->Count; j++ )
        if ( p->FCuts[j].Src != &p->GetPoint(1) &&  p->FCuts[j].Dst != &p->GetPoint(1) )
        {
            TIntVec Vec;
            int Tmp = IsLinesCrossedFull( p->FCuts[j].Src->Point, p->FCuts[j].Dst->Point, p1, pCenter, true, true, true, false, Vec, CrossEPS);
            if ( Tmp != lcNONE && Tmp != lcPARALLEL )
            {
                MBTi Dist = fabs((p1.x - Vec.x)*(p1.x - Vec.x)) + fabs((p1.y - Vec.y)*(p1.y - Vec.y)) + fabs((p1.z - Vec.z)*(p1.z - Vec.z));
                if ( Dist < MinDist )
                {
                    MinDist = Dist;
                    MinVec = Vec;
                }
            }
        }

    for ( int i = 0; i < GHP->Count; i++ )
        GHP->GetPoint(i).Point = TransformFrom(GHP->GetPoint(i).Point, ang);

    for (int i = 0; i < GHP->FHoles.Count; i++ )
        for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
            GHP->FHoles.Items[i]->GetPoint(j).Point = TransformFrom(GHP->FHoles.Items[i]->GetPoint(j).Point, ang);
    GHP->FNormal = TmpNormal;

    TIntVec res;
    if ( MinDist != 1000000000 )
        res = TIntVec((MinVec.x + p1.x)/2, (MinVec.y  + p1.y)/2, (MinVec.z + p1.z)/2);
    else
        res = ZEROINTVEC;//TIntVec((pCenter.x + p1.x)/2, (pCenter.y  + p1.y)/2, (pCenter.z + p1.z)/2);
    return TransformFrom(res, ang);
}

TIntVec TGeomObject::GetPointInPolygon2d(TGPolygon* p)
{
    if ( p->Count < 3 )
        return ZEROINTVEC;

    TIntVec p0(p->GetPoint(0).Point), p1(p->GetPoint(1).Point), p2(p->GetPoint(2).Point);
    int i;
    for ( i = 2; i < p->Count; i++ )
    {
        if ( fabs(p1.y - p0.y) > PEPS )
        {
            MBTi k1 = (p1.x - p0.x)/(p1.y - p0.y);
            MBTi k2 = (p1.z - p0.z)/(p1.y - p0.y);
            p2 = p->GetPoint(i).Point;
            if ( fabs((p2.x - p0.x)/(p2.y - p0.y) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.y - p0.y) - k2) > MyCEPS )
                break;
        }else if (  fabs(p1.x - p0.x) > PEPS )
        {
            MBTi k1 = (p1.y - p0.y)/(p1.x - p0.x);
            MBTi k2 = (p1.z - p0.z)/(p1.x - p0.x);
            p2 = p->GetPoint(i).Point;
            if ( fabs((p2.y - p0.y)/(p2.x - p0.x) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.x - p0.x) - k2) > MyCEPS )
                break;
        }else
        {
            MBTi k1 = (p1.y - p0.y)/(p1.z - p0.z);
            MBTi k2 = (p1.x - p0.x)/(p1.z - p0.z);
            p2 = p->GetPoint(i).Point;
            if ( fabs((p2.y - p0.y)/(p2.z - p0.z) - k1) > MyCEPS || fabs((p2.x - p0.x)/(p2.z - p0.z) - k2) > MyCEPS )
                break;
        }
    }
    if ( i == p->Count )
    {
        ErrorMsg("< TGeomObject::PointInPolygon>: Точки полигона на одной линии");
        return TIntVec((p0.x + p1.x)/2, (p0.y  + p1.y)/2, (p0.z + p1.z)/2);
    }

    TIntVec pCenter( (p2.x + p0.x)/2, (p2.y + p0.y)/2, (p2.z + p0.z)/2 );

    if ( Classify(pCenter, p0, p1, CrossEPS) == etLEFT || Classify(pCenter, p1, p2, CrossEPS) == etLEFT )
        pCenter = TIntVec(2*p1.x - pCenter.x, 2*p1.y - pCenter.y, 2*p1.z - pCenter.z);

//    return pCenter;

    TIntVec MinVec;
    MBTi MinDist = 1000000000;
    for ( int j = 0; j < p->Count; j++ )
        if ( p->FCuts[j].Src != &p->GetPoint(1) &&  p->FCuts[j].Dst != &p->GetPoint(1) )
        {
            TIntVec Vec;
            int Tmp = IsLinesCrossedFull( p->FCuts[j].Src->Point, p->FCuts[j].Dst->Point, p1, pCenter, true, true, true, false, Vec, CrossEPS);
            if ( Tmp != lcNONE && Tmp != lcPARALLEL )
            {
                MBTi Dist = fabs((p1.x - Vec.x)*(p1.x - Vec.x)) + fabs((p1.y - Vec.y)*(p1.y - Vec.y)) + fabs((p1.z - Vec.z)*(p1.z - Vec.z));
                if ( Dist < MinDist )
                {
                    MinDist = Dist;
                    MinVec = Vec;
                }
            }
        }

    TIntVec res;
    if ( MinDist != 1000000000 )
        res = TIntVec((MinVec.x + p1.x)/2, (MinVec.y  + p1.y)/2, (MinVec.z + p1.z)/2);
    else
        res = ZEROINTVEC;//TIntVec((pCenter.x + p1.x)/2, (pCenter.y  + p1.y)/2, (pCenter.z + p1.z)/2);
    return res;
}

TGPoint& TGeomObject::drGetPoint(int index, TMTList<TGCut>& cuts)
{
	if ((cuts.GetCycleItem(index+1)->Src != cuts.Items[index]->Src) && (cuts.GetCycleItem(index+1)->Dst != cuts.Items[index]->Src))
		return *cuts[index].Src;
	else
		return *cuts[index].Dst;
}

TIntVec TGeomObject::GetPointInPolygon2d(TMTList<TGCut>& cuts)
{
    if ( cuts.Count < 3 )
        return ZEROINTVEC;

    TIntVec p0(drGetPoint(0, cuts).Point), p1(drGetPoint(1, cuts).Point), p2(drGetPoint(2, cuts).Point);
    int i;
    for ( i = 2; i < cuts.Count; i++ )
    {
        if ( fabs(p1.y - p0.y) > EqualEPS )
        {
            MBTi k1 = (p1.x - p0.x)/(p1.y - p0.y);
            MBTi k2 = (p1.z - p0.z)/(p1.y - p0.y);
            p2 = drGetPoint(i, cuts).Point;
            if ( fabs((p2.x - p0.x)/(p2.y - p0.y) - k1) > 0.000001 || fabs((p2.z - p0.z)/(p2.y - p0.y) - k2) > 0.000001 )
                break;
        }else if (  fabs(p1.x - p0.x) > EqualEPS )
        {
            MBTi k1 = (p1.y - p0.y)/(p1.x - p0.x);
            MBTi k2 = (p1.z - p0.z)/(p1.x - p0.x);
            p2 = drGetPoint(i, cuts).Point;
            if ( fabs((p2.y - p0.y)/(p2.x - p0.x) - k1) > 0.000001 || fabs((p2.z - p0.z)/(p2.x - p0.x) - k2) > 0.000001 )
                break;
        }
    }
    if ( i == cuts.Count )
    {
        ErrorMsg("< TGeomObject::PointInPolygon>: Точки полигона на одной линии");
        return TIntVec((p0.x + p1.x)/2, (p0.y  + p1.y)/2, (p0.z + p1.z)/2);
    }

    TIntVec pCenter( (p2.x + p0.x)/2, (p2.y + p0.y)/2, (p2.z + p0.z)/2 );

    if ( Classify(pCenter, p0, p1, CrossEPS) == etLEFT || Classify(pCenter, p1, p2, CrossEPS) == etLEFT )
        pCenter = TIntVec(2*p1.x - pCenter.x, 2*p1.y - pCenter.y, 2*p1.z - pCenter.z);

//    return pCenter;

    TIntVec MinVec;
    MBTi MinDist = 1000000000;
    for ( int j = 0; j < cuts.Count; j++ )
        if ( cuts[j].Src != &drGetPoint(1, cuts) &&  cuts[j].Dst != &drGetPoint(1, cuts) )
        {
            TIntVec Vec;
            int Tmp = IsLinesCrossedFull( cuts[j].Src->Point, cuts[j].Dst->Point, p1, pCenter, true, true, true, false, Vec, CrossEPS);
            if ( Tmp != lcNONE && Tmp != lcPARALLEL )
            {
                MBTi Dist = fabs((p1.x - Vec.x)*(p1.x - Vec.x)) + fabs((p1.y - Vec.y)*(p1.y - Vec.y)) + fabs((p1.z - Vec.z)*(p1.z - Vec.z));
                if ( Dist < MinDist )
                {
                    MinDist = Dist;
                    MinVec = Vec;
                }
            }
        }

    TIntVec res;
    if ( MinDist != 1000000000 )
        res = TIntVec((MinVec.x + p1.x)/2, (MinVec.y  + p1.y)/2, (MinVec.z + p1.z)/2);
    else
        res = ZEROINTVEC;//TIntVec((pCenter.x + p1.x)/2, (pCenter.y  + p1.y)/2, (pCenter.z + p1.z)/2);
    return res;
}

TIntVec TGeomObject::GetPointInPolygonUseHoles(TGPolygon* p)
{
    if ( p->Count < 3 )
        return ZEROINTVEC;

    TGPolygon* GHP = p;
    TIntVec TmpNormal = GHP->FNormal;
    TIntVec ang = GetToPlaneTransformation(TmpNormal);
    for ( int i = 0; i < GHP->Count; i++ )
        GHP->GetPoint(i).Point = TransformTo(GHP->GetPoint(i).Point, ang);

    for (int i = 0; i < GHP->FHoles.Count; i++ )
        for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
            GHP->FHoles.Items[i]->GetPoint(j).Point = TransformTo(GHP->FHoles.Items[i]->GetPoint(j).Point, ang);

    TIntVec p0(p->GetPoint(0).Point), p1(p->GetPoint(1).Point), p2(p->GetPoint(2).Point);
    int i;
    for ( i = 1; i < p->Count; i++ )
    {
        int iH;
        for ( iH = 0; iH < p->FHoles.Count; iH++ )
        {
            int j;
            for ( j = 0; j < p->FHoles[iH].Count; j++ )
                if ( p->FHoles[iH].FCuts[j].Src == &p->GetPoint(i) || p->FHoles[iH].FCuts[j].Src == &p->GetPoint(i) )
                    break;
            if ( j < p->FHoles[iH].Count )
                break;
        }
        if ( iH == p->FHoles.Count )
        {
            p1 = p->GetPoint(i).Point;
            if ( i == 0 )
                p0 = p->GetPoint(p->Count-1).Point;
            else
                p0 = p->GetPoint(i - 1).Point;
            if ( i == p->Count-1 )
                p2 = p->GetPoint(0).Point;
            else
                p2 = p->GetPoint(i + 1).Point;

            if ( fabs(p1.y - p0.y) > PEPS )
            {
                MBTi k1 = (p1.x - p0.x)/(p1.y - p0.y);
                MBTi k2 = (p1.z - p0.z)/(p1.y - p0.y);
                if ( fabs((p2.x - p0.x)/(p2.y - p0.y) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.y - p0.y) - k2) > MyCEPS )
                    break;
            }else if (  fabs(p1.x - p0.x) > PEPS )
            {
                MBTi k1 = (p1.y - p0.y)/(p1.x - p0.x);
                MBTi k2 = (p1.z - p0.z)/(p1.x - p0.x);
                if ( fabs((p2.y - p0.y)/(p2.x - p0.x) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.x - p0.x) - k2) > MyCEPS )
                    break;
            }else
            {
                MBTi k1 = (p1.y - p0.y)/(p1.z - p0.z);
                MBTi k2 = (p1.x - p0.x)/(p1.z - p0.z);
                if ( fabs((p2.y - p0.y)/(p2.z - p0.z) - k1) > MyCEPS || fabs((p2.x - p0.x)/(p2.z - p0.z) - k2) > MyCEPS )
                    break;
            }
        }
    }
    if ( i == p->Count )
    {
        ErrorMsg("< TGeomObject::PointInPolygonUseHoles>: Ошибка выбора точек проверки");
        for ( int i = 0; i < GHP->Count; i++ )
            GHP->GetPoint(i).Point = TransformFrom(GHP->GetPoint(i).Point, ang);

        for (int i = 0; i < GHP->FHoles.Count; i++ )
            for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
                GHP->FHoles.Items[i]->GetPoint(j).Point = TransformFrom(GHP->FHoles.Items[i]->GetPoint(j).Point, ang);
        GHP->FNormal = TmpNormal;
        return ZEROINTVEC;
    }

    TIntVec pCenter((p0.x+p2.x)/2, (p0.y+p2.y)/2, (p0.z+p2.z)/2);

    TIntVec p0XY = p0;
    TIntVec p1XY = p1;
    TIntVec p2XY = p2;
    TIntVec pCenterXY = pCenter;

    if ( Classify(pCenterXY, p0XY, p1XY, CrossEPS) == etLEFT || Classify(pCenterXY, p1XY, p2XY, CrossEPS) == etLEFT )
        pCenter = TIntVec(2*p1.x - pCenter.x, 2*p1.y - pCenter.y, 2*p1.z - pCenter.z);

//    return pCenter;

    TIntVec MinVec;
    MBTi MinDist = 1000000000;
    TMTList<TGCut> cuts;
    cuts.Assign(&p->FCuts);
    for ( int i = 0; i < p->FHoles.Count; i++ )
        for ( int j = 0; j < p->FHoles[i].Count; j++ )
            cuts.Add(p->FHoles[i].FCuts.Items[j]);
    for ( int j = 0; j < cuts.Count; j++ )
        if ( cuts[j].Src != &p->GetPoint(1) &&  cuts[j].Dst != &p->GetPoint(1) )
        {
            TIntVec Vec;
            int Tmp = IsLinesCrossedFull( cuts[j].Src->Point, cuts[j].Dst->Point, p1, pCenter, true, true, true, false, Vec, CrossEPS);
            if ( Tmp != lcNONE && Tmp != lcPARALLEL )
            {
                MBTi Dist = (p1.x - Vec.x)*(p1.x - Vec.x) + (p1.y - Vec.y)*(p1.y - Vec.y) + (p1.z - Vec.z)*(p1.z - Vec.z);
                if ( Dist < MinDist )
                {
                    MinDist = Dist;
                    MinVec = Vec;
                }
            }
        }

    for ( int i = 0; i < GHP->Count; i++ )
        GHP->GetPoint(i).Point = TransformFrom(GHP->GetPoint(i).Point, ang);

    for (int i = 0; i < GHP->FHoles.Count; i++ )
        for (int j = 0; j < GHP->FHoles.Items[i]->Count; j++ )
            GHP->FHoles.Items[i]->GetPoint(j).Point = TransformFrom(GHP->FHoles.Items[i]->GetPoint(j).Point, ang);
    GHP->FNormal = TmpNormal;

    TIntVec res;
    if ( MinDist != 1000000000 )
        res = TIntVec((MinVec.x + p1.x)/2, (MinVec.y  + p1.y)/2, (MinVec.z + p1.z)/2);
    else
        res = TIntVec((pCenter.x + p1.x)/2, (pCenter.y  + p1.y)/2, (pCenter.z + p1.z)/2);
    return TransformFrom(res, ang);
}

TIntVec TGeomObject::GetPointInPolygonUseHoles2d(TGPolygon* p)
{
    if ( p->Count < 3 )
        return ZEROINTVEC;

    TIntVec p0(p->GetPoint(0).Point), p1(p->GetPoint(1).Point), p2(p->GetPoint(2).Point);
    int i;
    for ( i = 1; i < p->Count; i++ )
    {
        int iH;
        for ( iH = 0; iH < p->FHoles.Count; iH++ )
        {
            int j;
            for ( j = 0; j < p->FHoles[iH].Count; j++ )
                if ( p->FHoles[iH].FCuts[j].Src == &p->GetPoint(i) || p->FHoles[iH].FCuts[j].Src == &p->GetPoint(i) )
                    break;
            if ( j < p->FHoles[iH].Count )
                break;
        }
        if ( iH == p->FHoles.Count )
        {
            p1 = p->GetPoint(i).Point;
            if ( i == 0 )
                p0 = p->GetPoint(p->Count-1).Point;
            else
                p0 = p->GetPoint(i - 1).Point;
            if ( i == p->Count-1 )
                p2 = p->GetPoint(0).Point;
            else
                p2 = p->GetPoint(i + 1).Point;

            if ( fabs(p1.y - p0.y) > EqualEPS )
            {
                MBTi k1 = (p1.x - p0.x)/(p1.y - p0.y);
                MBTi k2 = (p1.z - p0.z)/(p1.y - p0.y);
                if ( fabs((p2.x - p0.x)/(p2.y - p0.y) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.y - p0.y) - k2) > MyCEPS )
                    break;
            }else if (  fabs(p1.x - p0.x) > EqualEPS )
            {
                MBTi k1 = (p1.y - p0.y)/(p1.x - p0.x);
                MBTi k2 = (p1.z - p0.z)/(p1.x - p0.x);
                if ( fabs((p2.y - p0.y)/(p2.x - p0.x) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.x - p0.x) - k2) > MyCEPS )
                    break;
            }
        }
    }
    if ( i == p->Count )
    {
        ErrorMsg("< TGeomObject::PointInPolygonUseHoles>: Ошибка выбора точек проверки");
        return ZEROINTVEC;
    }

    TIntVec pCenter((p0.x+p2.x)/2, (p0.y+p2.y)/2, (p0.z+p2.z)/2);

    if ( Classify(pCenter, p0, p1, CrossEPS) == etLEFT || Classify(pCenter, p1, p2, CrossEPS) == etLEFT )
        pCenter = TIntVec(2*p1.x - pCenter.x, 2*p1.y - pCenter.y, 2*p1.z - pCenter.z);

//    return pCenter;

    TIntVec MinVec;
    MBTi MinDist = 1000000000;
    TMTList<TGCut> cuts;
    cuts.Assign(&p->FCuts);
    for ( int i = 0; i < p->FHoles.Count; i++ )
        for ( int j = 0; j < p->FHoles[i].Count; j++ )
            cuts.Add(p->FHoles[i].FCuts.Items[j]);
    for ( int j = 0; j < cuts.Count; j++ )
        if ( cuts[j].Src != &p->GetPoint(1) &&  cuts[j].Dst != &p->GetPoint(1) )
        {
            TIntVec Vec;
            int Tmp = IsLinesCrossedFull( cuts[j].Src->Point, cuts[j].Dst->Point, p1, pCenter, true, true, true, false, Vec, CrossEPS);
            if ( Tmp != lcNONE && Tmp != lcPARALLEL )
            {
                MBTi Dist = (p1.x - Vec.x)*(p1.x - Vec.x) + (p1.y - Vec.y)*(p1.y - Vec.y) + (p1.z - Vec.z)*(p1.z - Vec.z);
                if ( Dist < MinDist )
                {
                    MinDist = Dist;
                    MinVec = Vec;
                }
            }
        }

    TIntVec res;
    if ( MinDist != 1000000000 )
        res = TIntVec((MinVec.x + p1.x)/2, (MinVec.y  + p1.y)/2, (MinVec.z + p1.z)/2);
    else
        res = TIntVec((pCenter.x + p1.x)/2, (pCenter.y  + p1.y)/2, (pCenter.z + p1.z)/2);
    return res;
}

void TGeomObject::evlProcessCrossCuts2D(TMTList<TGCut>& Cuts)
{
//	TMTList<TGCut> Cuts;
//	Cuts.Assign(&FCuts);
//	GeometryFix(Cuts, fxPOINTSINCUTS);
	
	for(int i=0;i<Cuts.Count;i++)
		for(int j=i+1;j<Cuts.Count;j++)
		{
			TIntVec itr;
			int res = -1;
			if ((res = CutCutCross2d(Cuts[i].Src->Point, Cuts[i].Dst->Point, Cuts[j].Src->Point, Cuts[j].Dst->Point, itr, PEPS)) == 1)
			{
				TGPoint *p = AddPoint(itr);
				TGCut *c1, *c2, *c3, *c4;
				SplitCut(Cuts.Items[i], p, c1, c2);
				SplitCut(Cuts.Items[j], p, c3, c4);
				Cuts.Delete(j);
				Cuts.Delete(i--);
				if (c1) Cuts.Add(c1);
				if (c2) Cuts.Add(c2);
				if (c3) Cuts.Add(c3);
				if (c4) Cuts.Add(c4);
				break;
			}
		}
//	GeometryFix(Cuts, fxPOINTSINCUTS);
	
}

