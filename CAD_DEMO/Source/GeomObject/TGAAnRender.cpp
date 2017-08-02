//---------------------------------------------------------------------------

#include "math.h"
#pragma hdrstop

#include "TGAAnRender.h"

//#include "TGObject.h"
#include "MYGL.h"
#include "Misc.h"
#include "Poligon.h"
#include "TGObject.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
const MBTi CrossEPS = 0.000000001;
const MBTi UpDownEPS = 0.00001;//pochti not used
const MBTi EqualEPS = 0.0000001;//pochti not used
const MBTi MyCEPS = 0.00001;//pochti not used
TGeomObject obj;

void TGAAnRender::DeleteBackFace()
{
	for ( int i = go.PolygonsCount - 1; i >= 0; i-- )
		if ( go.GetPolygon(i).Normal.z <= 0.01 )
        {
            for ( int k = 0; k < go.GetPolygon(i).Count; k++ )
                go.GetPolygon(i).GetCut(k).Smooth = false;
			go.DeletePolygon(i);
        }
//    go.FreeUnused(fuAll);
}

void TGAAnRender::TextToSB(AnsiString str)
{
//    SB->Panels[0].Items[1]->Text = str;
//    SB->Repaint();
}

bool TGAAnRender::EqualPolygonInds(int IndP, TMDelTList<int>& TmpInds)
{
/*    FillPolygonsFlags(flMARK, gfFALSE);
    int j;
    for ( j = 0; j < TmpInds.Count; j++ )
        for ( int k = 0; k < FCuts[TmpInds[j]].FPlane.Count; k++ )
            if ( FCuts[TmpInds[j]].FPlane.Items[k] )
                if ( TmpInds.Count == FCuts[TmpInds[j]].FPlane.Count )
                    FCuts[TmpInds[j]].FPlane[k].FFlags.Mark = gfTRUE;*/
    int j;
    for ( j = 0; j < go.PolygonsCount; j++ )
        if ( TmpInds.Count == go.GetPolygon(j).Count && go.GetPolygon(j).Flags.Mark )
        {
            int k;
            for ( k = 0; k < go.GetPolygon(j).Count; k++ )
            {
                int d;
                int Ind = go.IndexOf(&go.GetPolygon(j).GetCut(k));
                for ( d = 0; d < TmpInds.Count; d++ )
                    if ( TmpInds[d] == Ind )
                        break;
                if ( d == TmpInds.Count )
                    break;
            }
            if ( k == go.GetPolygon(j).Count )
                break;
        }

    if ( j < go.PolygonsCount )
    {
        int d;
        for ( d = 0; d < TmpInds.Count; d++ )
        {
            TIntVec Vec1, Vec2;
            int res1 = PlaneAndLineCrossed(obj.GetPolygon(IndP).Origin, obj.GetPolygon(IndP).Normal, go.GetCut(TmpInds[d]).Src->Point + TIntVec(0, 0, -1000), go.GetCut(TmpInds[d]).Src->Point + TIntVec(0, 0, 1000), false, false, Vec1, CrossEPS);
            int res2 = PlaneAndLineCrossed(go.GetPolygon(j).Origin, go.GetPolygon(j).Normal, go.GetCut(TmpInds[d]).Src->Point + TIntVec(0, 0, -1000), go.GetCut(TmpInds[d]).Src->Point + TIntVec(0, 0, 1000), false, false, Vec2, CrossEPS);
            if ( fabs(Vec1.z - Vec2.z) > UpDownEPS )
                if ( Vec1.z > Vec2.z )
                {
                    go.GetPolygon(j).Tag = IndP;
                    break;
                }else
                    break;
        }
        if ( d == TmpInds.Count )
            ErrorMsg("Equal Polygons cannot detect");
        return false;
    }else
        return true;
}

bool TGAAnRender::TestPolygon(TMDelTList<int>& TmpInds, TMDelTList< TMDelTList<int> >& PolysInd)
{
    int k;
    bool NeedPolygonize = false;
    for ( k = 0; k < TmpInds.Count; k++ )
        if ( TmpInds[k] == -1 )
        {
            TmpInds.Delete(k);
            k--;
        }else
        {
            int j = k+1;
            for ( ; j < TmpInds.Count; j++ )
                if ( TmpInds[k] ==  TmpInds[j] )
                    break;
            if ( j < TmpInds.Count )
            {
                TmpInds.Delete(k);
                k--;
                NeedPolygonize = true;
            }
        }

    if ( TmpInds.Count < 3 )
        return false;

    if ( NeedPolygonize )
    {
        TMDelTList< TMTList<TGCut> > Polys;
        TMTList<TGCut> TmpCuts;
        for ( int j = 0; j < TmpInds.Count; j++ )
            TmpCuts.Add(&go.GetCut(TmpInds[j]));
        go.Polygonize2d(TmpCuts, Polys);
        for ( int j = 0; j < Polys.Count; j++ )
        if ( Polys[j].Count > 2 )
        {
            TMDelTList<int> TInds;
            for ( int jj = 0; jj < Polys[j].Count; jj++ )
            {
                int ind = go.IndexOf(Polys[j].Items[jj]);
                if ( ind != -1 )
                    TInds.Add(new int(ind));
                else
                    throw EMyException("<TGeomObject::TestPolygon> FCuts.IndexOf(Polys[j].Items[jj]) == -1");
            }
            PolysInd.Add(new TMDelTList<int>);
            PolysInd.Last()->Assign(&TInds);
        }
    }else
    {
        PolysInd.Add(new TMDelTList<int>);
        PolysInd.Last()->Assign(&TmpInds);
    }
    return true;
}

void TGAAnRender::ProjectToXY()
{
    for ( int i = 0; i < obj.CutsCount; i++ )
        obj.GetCut(i).Tag = i;
	go.Clear();
	TMTList<int> PInds;
	TMTList<int> CInds;
	for ( int i = 0; i < obj.VertexCount; i++ )
	{
		TGPoint* TmpP = go.AddPoint(TIntVec(obj.GetVertex(i).Point.x, obj.GetVertex(i).Point.y, 0));
		PInds.Add(new int(go.IndexOf(TmpP)));
	}
	for ( int i = 0; i < obj.CutsCount; i++ )
	{
		int i1 = PInds[obj.IndexOf(obj.GetCut(i).Src)];
		int i2 = PInds[obj.IndexOf(obj.GetCut(i).Dst)];
		if (i1 != i2)
		{
			TGCut* TmpC = go.AddCut(&go.GetVertex(i1), &go.GetVertex(i2));

            if ( TmpC->Flags.Alredy == gfTRUE )
            {
                float z1 = (obj.GetCut(TmpC->Tag).Src->Point.z + obj.GetCut(TmpC->Tag).Dst->Point.z)/2;
                float z2 = (obj.GetCut(i).Src->Point.z + obj.GetCut(i).Dst->Point.z)/2;
                if ( z2 > z1 )
                {
                    TmpC->Flags = obj.GetCut(i).Flags;
                    TmpC->Smooth = obj.GetCut(i).Smooth;
                    TmpC->Tag = obj.GetCut(i).Tag;
                }
//        		throw EMyException ("ProjectToXY: Equal cuts");
            }else
            {
                TmpC->Flags = obj.GetCut(i).Flags;
                TmpC->Smooth = obj.GetCut(i).Smooth;
                TmpC->Tag = obj.GetCut(i).Tag;
            }
			CInds.Add(new int(go.IndexOf(TmpC)));
		}else
        {
			CInds.Add(new int(-1));
        }
	}

	for ( int i = 0; i < obj.PolygonsCount; i++ )
	{
//        SB->Panels[0].Items[0]->Text = IntToStr(int(float(i)/float(obj.PolygonsCount)*100))+'%';
//        SB->Repaint();
//        Application->ProcessMessages();

        obj.GetPolygon(i).Tag = i;
		TMDelTList<int> TmpInds;
		for ( int j = 0; j < obj.GetPolygon(i).Count; j++ )
			TmpInds.Add(new int(CInds[obj.IndexOf(&obj.GetPolygon(i).GetCut(j))]));

        TMDelTList< TMDelTList<int> > PolysInd;
        if ( !TestPolygon(TmpInds, PolysInd) )
            continue;

        for ( int ii = 0; ii < PolysInd.Count; ii++ )
        {
            bool test = EqualPolygonInds(i, PolysInd[ii]);
            if ( test && PolysInd[ii].Count > 2 )
            {
                TGPolygon* TmpPoly = go.AddPolygon(PolysInd[ii], TIntVec(0, 0, 1));
                TmpPoly->Tag = i;

                for ( int j = 0; j < obj.FPolygons[i].FHoles.Count; j++ )
                {
                    TMDelTList<int> TmpHInds;
                    for ( int k = 0; k < obj.FPolygons[i].FHoles[j].Count; k++ )
                        TmpHInds.Add(new int(CInds[obj.FCuts.IndexOf(obj.FPolygons[i].FHoles[j].FCuts.Items[k])]));

                    TMDelTList< TMDelTList<int> > PolysHInd;
                    if ( !TestPolygon(TmpHInds, PolysHInd) )
                        continue;
                    for ( int jj = 0; jj < PolysHInd.Count; jj++ )
                    {
                        TMTList<TGCut> TmpHCuts;
                        for ( int k = 0; k < PolysHInd[jj].Count; k++ )
                            TmpHCuts.Add(go.FCuts.Items[PolysHInd[jj][k]]);
                        TGPolygon* TmpHPg = TmpPoly->AddHole(TmpHCuts);
                        TmpHPg->Tag = TmpPoly->Tag;
                    }
                }
            }
        }
	}
}

void TGAAnRender::AddPolygonToCeilsUseHoles(TGPolygon* p, TMTList<TGPolygon>& Conveyor, TMTList<TGPolygon>& Ceils)
{
//    long int addrP = (long int)p;
    TMTList<TGPolygon> Ceils1;
    Ceils1.Assign(&Ceils);
    Ceils.Clear();
//    long int num = 0;
    for ( int j = 0; j < Ceils1.Count; j++ )
    if ( p != NULL && Ceils1.Items[j] != NULL )
    {
//        num++;
      	TMTList<TGCut> Split1, Split2;
		TMTList<TGPolygon> poly[3];
        bool test1 = false;
        bool test2 = false;
//        long int addr = (long int)p;
        if ( p->BBox.Overlaps2d(Ceils1[j].BBox, go.PEPS*2) )
        {
            test1 = true;
            if (/* !p->Equal(Ceils1[j]) */1){
//                if (p->Equals(Ceils1[j]))
  //                  int kkk = 0;
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
        }
	    if ( test2 && test1 )
        {
            int pTag = p->Tag;
            for ( int jj = 0; jj < 3; jj++ )
                for ( int ii = 0; ii < poly[jj].Count; ii++ )
                {
                    TGPolygon* NewP = poly[jj].Items[ii];
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
                        NewP->FFlags.Same = gfTRUE;
                    }else
                    {
                        if ( pTag != Ceils1[j].Tag )
                        {
                            int Ci = 0;
                            MBTi maxDist = -1;
                            for ( ; Ci < poly[jj][ii].Count; Ci++ )
                            {
                                TIntVec Vec1, Vec2;
                                TIntVec Point = poly[jj][ii].GetPoint(Ci).Point;
    //                            TIntVec Point = poly[jj][ii].FCuts[Ci].Src->Point;
                                int res1 = PlaneAndLineCrossed(obj.FPolygons[pTag].Origin, obj.FPolygons[pTag].Normal, Point + TIntVec(0, 0, -100), Point + TIntVec(0, 0, 100), false, false, Vec1, CrossEPS);
                                int res2 = PlaneAndLineCrossed(obj.FPolygons[Ceils1[j].Tag].Origin, obj.FPolygons[Ceils1[j].Tag].Normal, Point + TIntVec(0, 0, -100), Point + TIntVec(0, 0, 100), false, false, Vec2, CrossEPS);
                                if ( maxDist < fabs(Vec1.z - Vec2.z) )
                                {
                                    maxDist = fabs(Vec1.z - Vec2.z);
                                    if ( Vec1.z > Vec2.z )
                                        NewP->Tag = pTag;
                                    else
                                        NewP->Tag = Ceils1[j].Tag;
                                }
/*                                if ( fabs(Vec1.z - Vec2.z) > UpDownEPS )
                                    if ( Vec1.z > Vec2.z )
                                    {
                                        NewP->Tag = pTag;
                                        break;
                                    }else
                                    {
                                        NewP->Tag = Ceils1[j].Tag;
                                        break;
                                    }*/
                            }
                            if ( maxDist == -1 )
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
                        NewP->FFlags.Same = gfTRUE;
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
    if ( p != NULL )
    {
        Ceils.Add(p);
        p->FFlags.Same = gfTRUE;
        p = NULL;
    }
    if ( Ceils1.Count > 0 )
        for ( int i = 0; i < Ceils1.Count; i++ )
        {
            Ceils.Add(Ceils1.Items[i]);
        }
}

void TGAAnRender::AnalyticalRender()
{
    TextToSB("DeleteBackFace");
	DeleteBackFace();

    TextToSB("Assign");
    obj.Assign(&go);

    TextToSB("ProjectToXY");
	ProjectToXY();

    TextToSB("ProcessCrossCuts2D");
	drProcessCrossCuts2d();

    TMTList<TGPolygon> Ceils;
    TMTList<TGPolygon> Conveyor;
    for ( int i = 0; i < go.FPolygons.Count; i++ )
        Conveyor.Add(go.FPolygons.Items[i]);

/*&&&*/    go.FillPolygonsFlags(flSAME, gfFALSE);

    int ConCount = Conveyor.Count;
    TextToSB("AnalyticalRender");
    for ( int i = 0; i < Conveyor.Count; i++ )
    {
        AddPolygonToCeilsUseHoles(Conveyor.Items[i], Conveyor, Ceils);
        Conveyor.Delete(i--);
        TextToSB(IntToStr(int(float(ConCount-Conveyor.Count)/float(ConCount)*100))+'%');
        Application->ProcessMessages();
    }

    TextToSB("Test ceils and delete FPolygons");
    for ( int i = 0; i < Ceils.Count; i++ )
        if ( go.FPolygons.IndexOf( Ceils.Items[i] ) == -1 )
            ErrorMsg("? ??????? ???? ?? ???? ??? ? ?????????");
//            FPolygons.Add(Ceils.Items[i]);

    for ( int i = go.FPolygons.Count-1; i >= 0 ; i-- )
        if ( Ceils.IndexOf( go.FPolygons.Items[i] ) == -1 )
            go.FPolygons.Delete(i);

/*  TmpTicks = GetTickCount();
  SB->Panels[0].Items[1]->Text = "delete Cuts TagAndHole";
  SB->Repaint();
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
            Polygonize2d(TmpCuts, Poly);
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
//return;
    SB->Panels[0].Items[1]->Text = "delete Cuts Tag";
    SB->Repaint();
    FillCutsFlags(FCuts, flMARK, gfFALSE);
    FillPolygonsFlags(FPolygons, flMARK, gfFALSE);
//    num = 0;
    for ( int i = 0; i < FPolygons.Count; i++ )
    {
//        num++;
        TMTList<TGCut> TmpCuts;
        TMTList<TGCut> TmpCuts2;
        TMTList<TGPolygon> TmpPoly;
        int TmpTag = FPolygons[i].Tag;

//        GetCeilsGroup(FPolygons[i], TmpPoly);
        PassByObject(FPolygons.Items[i], ConditionForTag);

        for ( int j = 0; j < FPolygons.Count; j++ )
            if ( FPolygons[j].FFlags.Mark )
            {
                TmpPoly.Add(FPolygons.Items[j]);
                FPolygons[j].FFlags.Mark = gfFALSE;
            }
//                if ( TmpPoly.IndexOf(FPolygons.Items[j]) == -1 )
  //                  TmpPoly.Add(FPolygons.Items[j]);
    //            else
      //              ErrorMsg("AnalRen: ????????? ???????!");

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
                    {
                        if ( TmpCuts.IndexOf(TmpPoly[k].FCuts.Items[j]) == -1 )
                            TmpCuts.Add(TmpPoly[k].FCuts.Items[j]);
                    }else
                        TmpCuts2.Add(TmpPoly[k].FCuts.Items[j]);
                for ( int d = 0; d < TmpPoly[k].FHoles.Count; d++ )
                    if ( TmpPoly[k].FHoles[d].FFlags.Mark )
                    {
                        for ( int j = 0; j < TmpPoly[k].FHoles[d].Count; j++ )
                            if ( TmpPoly[k].FHoles[d].FCuts[j].FFlags.Mark == gfFALSE )
                            {
                                if ( TmpCuts.IndexOf(TmpPoly[k].FHoles[d].FCuts.Items[j]) == -1 )
                                    TmpCuts.Add(TmpPoly[k].FHoles[d].FCuts.Items[j]);
                            }else
                                TmpCuts2.Add(TmpPoly[k].FHoles[d].FCuts.Items[j]);
                        TmpPoly[k].FHoles[d].FFlags.Mark = gfFALSE;
                    }
            }

            for ( int k = 0; k < TmpPoly.Count; k++ )
               FillCutsFlags(TmpPoly[k].FCuts, flMARK, gfFALSE);
            for ( int k = 0; k < TmpPoly.Count; k++ )
                if ( FPolygons.IndexOf(TmpPoly.Items[k]) != -1 )
                    FPolygons.Remove(TmpPoly.Items[k]);

            TMDelTList< TMTList<TGCut> > Poly;
            TGPoint *begin = GetLowestPoint2d(TmpCuts);
            TMTList <TGCut> contour;
            bool ggg = false;
            if (ggg)
            {
                for ( int j = 0; j < TmpCuts2.Count; j++ )
                    TmpCuts2[j].Tag = gfTRUE;
            }
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
//    SB->Panels[0].Items[1]->Text = "delete Cuts Tag";
  //  SB->Repaint();
    //for ( int i = 0; i < FPolygons.Count; i++ )
//    {
  //      TMTList<TGCut> TmpCuts;
    //    TMTList<TGPolygon> TmpPoly;
      //  int TmpTag = FPolygons[i].Tag;

//        FillCutsFlags(FCuts, flMARK, gfFALSE);
//        FillPolygonsFlags(FPolygons, flMARK, gfFALSE);

//        PassByObject(FPolygons.Items[i], ConditionForTag);
//    }
    FreeUnused(fuAll);
  TmpTicks = GetTickCount() - TmpTicks;
  TickCount4 += TmpTicks;
//return;

    TmpTicks = GetTickCount();
    SB->Panels[0].Items[1]->Text = "delete Cuts Smooth";
    SB->Repaint();
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
            DetectHolesCreatePolygons2d(RPoly);
            TMTList<TGPolygon> Test;
            for ( int k = 0; k < RPoly.Count; k++ )
                ConstructPolygonsFromHoles(RPoly[k], Test);
        }
    }
    FreeUnused(fuAll);*/
    TextToSB("Process successfully!!!");
}

void TGAAnRender::operator()()
{
    AnalyticalRender();
}

bool TGAAnRender::ExistsPolygonInPolygonUseHoles2(TMTList<TGCut>& cuts, TGPolygon& PolygonUseHole, bool UseHoles)
{
    int j;
    int PIPQ = 0;
    for ( j = 0; j < cuts.Count; j++ )
    {
        int PIPC = PolygonUseHole.PointInPolygon_UseHoles2d( (cuts[j].Src->Point+cuts[j].Dst->Point)/2, go.PEPS/2);
        if ( PIPC == pipOUTSIDE )
            return false;
        if ( PIPC == pipINSIDE )
            return true;
        if ( PIPQ != PIPC )
            if ( PIPQ == 0 )
                PIPQ = PIPC;
            else
                throw EMyException("<TGeomObject::ExistsPolygonInPolygonUseHoles2>: ?? ??????????? ????????!");
    }

    TIntVec Vec = GetPointInPolygon2d(cuts);
    if ( PIPQ == pipHOLEBOUNDARY )
        if ( PolygonUseHole.PointInPolygon_UseHoles2d(Vec, go.PEPS/2) == pipOUTSIDE )
            return false;
        else
            return true;

    if ( PIPQ == pipBOUNDARY )
        if ( PolygonUseHole.PointInPolygon2d(Vec, go.PEPS/2) == pipOUTSIDE )
            return false;
        else
            return true;
    throw EMyException("<TGeomObject::ExistsPolygonInPolygonUseHoles2>: ?? ??????????? ????????!");
    return false;
}

void TGAAnRender::ConstructPolygonsFromHoles( TGPolygon& p, TMTList<TGPolygon>& poly)
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
                    ErrorMsg("<TGeomObject::IntersectPolygonsUseHoles>: ????? ? ?????!");
                }
        }
}

bool TGAAnRender::IntersectPolygonsUseHoles( TGPolygon* p1, TGPolygon* p2, TMTList<TGPolygon> &POnlyp1, TMTList<TGPolygon> &PSplit, TMTList<TGPolygon> &POnlyp2)
{
//    if ( p1->Equals(*p2) )
  //      return false;
    TMDelTList<int> ClassifyPolygons;
    TMTList<TGCut> Split1;
    TMDelTList< TMTList<TGCut> > Poly;
//    TMTList<TGPolygon> FPolys;

    if ( p1->Count < p2->Count )
    {
        int i = 0;
        for ( ; i < p1->Count; i++ )
        {
            int j = 0;
            for ( ; j < p1->GetPoint(i).CutsCount; j++ )
                if ( p2->FCuts.IndexOf(&p1->GetPoint(i).GetCut(j)) != -1 )
                    break;
            if ( j < p1->GetPoint(i).CutsCount )
                break;
        }
        if ( i == p1->Count )
            int kkk = 0;
    }else
    {
        int i = 0;
        for ( ; i < p2->Count; i++ )
        {
            int j = 0;
            for ( ; j < p2->GetPoint(i).CutsCount; j++ )
                if ( p1->FCuts.IndexOf(&p2->GetPoint(i).GetCut(j)) != -1 )
                    break;
            if ( j < p2->GetPoint(i).CutsCount )
                break;
        }
        if ( i == p2->Count )
            return false;
    }

    Split1.Assign(&p1->FCuts);
    for ( int i = 0; i < p1->FHoles.Count; i++ )
		TMTListAdd(Split1, p1->FHoles[i].FCuts);
/*        for ( int j = 0; j < p1->FHoles[i].Count; j++ )
//            if (Split1.IndexOf(p1->FHoles[i].FCuts.Items[j]) == -1 )
                Split1.Add(p1->FHoles[i].FCuts.Items[j]);*/

    TMTListAdd(Split1, p2->FCuts);
/*	for ( int i = 0; i < p2->FCuts.Count; i++ )
//        if (Split1.IndexOf(p2->FCuts.Items[i]) == -1 )
			Split1.Add(p2->FCuts.Items[i]);*/

    for ( int i = 0; i < p2->FHoles.Count; i++ )
		TMTListAdd(Split1, p2->FHoles[i].FCuts);
/*        for ( int j = 0; j < p2->FHoles[i].Count; j++ )
//            if (Split1.IndexOf(p2->FHoles[i].FCuts.Items[j]) == -1 )
                Split1.Add(p2->FHoles[i].FCuts.Items[j]);*/

	if ( !go.Polygonize2d(Split1, Poly) )
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
            PSplit.Add(go.AddPolygon(Poly[i], TIntVec(0, 0, 1)));
//            PSplit.Add(FPolys.Items[i]);
        }else if ( ClassifyPolygons[i] == 1 )
        {
            POnlyp1.Add(go.AddPolygon(Poly[i], TIntVec(0, 0, 1)));
//            POnlyp1.Add(FPolys.Items[i]);
        }else if ( ClassifyPolygons[i] == 2 )
        {
            POnlyp2.Add(go.AddPolygon(Poly[i], TIntVec(0, 0, 1)));
//            POnlyp2.Add(FPolys.Items[i]);
        }

    go.DetectHoles2d(PSplit);
    go.DetectHoles2d(POnlyp1);
    go.DetectHoles2d(POnlyp2);

    TMTList<TGPolygon> Test;
    for ( int k = 0; k < PSplit.Count; k++ )
        ConstructPolygonsFromHoles(PSplit[k], Test);
    for ( int k = 0; k < POnlyp1.Count; k++ )
        ConstructPolygonsFromHoles(POnlyp1[k], Test);
    for ( int k = 0; k < POnlyp2.Count; k++ )
        ConstructPolygonsFromHoles(POnlyp2[k], Test);

    for ( int k = POnlyp1.Count-1; k >= 0; k-- )
        if ( go.FPolygons.IndexOf( POnlyp1.Items[k] ) == -1 )
        {
            TIntVec Vec = GetPointInPolygon2d(POnlyp1[k].FCuts);
            if ( p1->PointInPolygon_UseHoles2d(Vec, go.PEPS) == pipOUTSIDE )
            {
                //!!!Fpolygons.Remove(POnlyp1.Items[k]);
                POnlyp1.Delete(k);
            }else
                POnlyp1.Items[k] = go.AddPolygon(POnlyp1[k].FCuts, TIntVec(0, 0, 1) );
        }else
        {
            //!!!Fpolygons.Remove(POnlyp1.Items[k]);
//            POnlyp1.Delete(k);
        }

    for ( int k = PSplit.Count-1; k >= 0; k-- )
        if ( go.FPolygons.IndexOf( PSplit.Items[k] ) == -1 )
        {
            TIntVec Vec = GetPointInPolygon2d(PSplit[k].FCuts);
            if ( p1->PointInPolygon_UseHoles2d(Vec, go.PEPS) == pipOUTSIDE )
            {
                //!!!Fpolygons.Remove(PSplit.Items[k]);
                PSplit.Delete(k);
            }else
                PSplit.Items[k] = go.AddPolygon(PSplit[k].FCuts, TIntVec(0, 0, 1) );
        }else
        {
            //!!!Fpolygons.Remove(PSplit.Items[k]);
//            PSplit.Delete(k);
        }

    for ( int k = POnlyp2.Count-1; k >= 0; k-- )
        if ( go.FPolygons.IndexOf( POnlyp2.Items[k] ) == -1 )
        {
            TIntVec Vec = GetPointInPolygon2d(POnlyp2[k].FCuts);
            if ( p2->PointInPolygon_UseHoles2d(Vec, go.PEPS) == pipOUTSIDE )
            {
                //!!!Fpolygons.Remove(POnlyp2.Items[k]);
                POnlyp2.Delete(k);
            }else
                POnlyp2.Items[k] = go.AddPolygon(POnlyp2[k].FCuts, TIntVec(0, 0, 1) );
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

void TGAAnRender::drProcessCrossCuts2d()
{
	drProcessCrossCuts2d(go.FCuts);
}

bool TGAAnRender::drConsistsPoint(const TGPoint& Point, const TGCut& Cut) const
{
	int res = Classify(Point.Point, Cut.Src->Point, Cut.Dst->Point, go.PEPS);
	return (res == etBETWEEN /*|| res == etDESTINATION || res == etORIGIN */);
}

bool TGAAnRender::drSplitCut(TGCut *c, TGPoint *&newPnt, TGCut *&Result1, TGCut *&Result2)
{
//Modify newPoint
    TIntVec Vec;
    MBTi dx = c->Dst->Point.x - c->Src->Point.x;
    MBTi dy = c->Dst->Point.y - c->Src->Point.y;
    if ( IsLinesCrossedFull(c->Src->Point, c->Dst->Point, newPnt->Point, TIntVec(dy+newPnt->Point.x, -dx+newPnt->Point.y, 0), false, false, false, false, Vec, CrossEPS) == 1 )
    {
    /*                for ( int i = 0; i < FVertex.Count; i++ )
                        if ( fabs(FVertex[i].Point.x) < 0.0001 && fabs(FVertex[i].Point.y) < 0.0001 )
                            ErrorMsg("Tets");*/
    //    FillPointsFlags(flALREDY, gfFALSE);
        TGPoint* Pnt = go.AddPoint(Vec);
        if ( newPnt != Pnt )
        {
            if ( Pnt->Flags.Alredy == gfTRUE )
                Pnt->Flags = FlagUnite(Pnt->Flags, newPnt->Flags);
            else
            {
                Pnt->Flags = newPnt->Flags;
                Pnt->Tag = newPnt->Tag;
            }
            for ( int i = newPnt->CutsCount-1; i >= 0; i-- )
            {
                TGCut* Buf = &newPnt->GetCut(i);
                if ( newPnt->GetCut(i).Src == newPnt )
                    newPnt->GetCut(i).Src = Pnt;
                else if ( newPnt->GetCut(i).Dst == newPnt )
                    newPnt->GetCut(i).Dst = Pnt;
            }
            go.Delete(newPnt);
            newPnt = Pnt;
        }
    }
//Modify newPoint    */

	if (c->ConsistsPoint(newPnt))
		return false;

	TGCut *cn = go.AddCut(c->Src, newPnt);
	TGCut *cn1 = go.AddCut(newPnt, c->Dst);

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

	go.FCuts.Remove(c);
	return true;
}

bool TGAAnRender::SplitCutForCrossedCuts(TMTList<TGCut>& aCuts, TGCut *&c, TGPoint *&Pnt, TMTList<TGCut>& CutsConveyor)
{
    int IndexCutConv = CutsConveyor.IndexOf(c);
    TGCut *Res1, *Res2;
    bool ggg = drSplitCut(c, Pnt, Res1, Res2);
    if ( ggg )
    {
        if (&aCuts != &go.FCuts)
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

bool TGAAnRender::drProcessCrossCuts2d(TMTList<TGCut>& aCuts)
{
    bool ret = false;
    TMTList<TGCut> CutsConveyor;
	for ( int i = 0; i < aCuts.Count; i++ )
        CutsConveyor.Add(aCuts.Items[i]);

    while ( CutsConveyor.Count > 0 )
    {
/*        SB->Panels[0].Items[0]->Text = IntToStr(int(float(CutsConveyor.Count)/float(aCuts.Count)*100))+'%';
		SB->Repaint();
        Application->ProcessMessages();*/
        TGCut &CutConv = CutsConveyor[0];
        for ( int j = 0; j < aCuts.Count; j++ )
        {
            bool test = CutConv.FBBox.Overlaps2d(aCuts[j].BBox, go.PEPS*2);
            if ( aCuts.Items[j] != &CutConv && test )
            {
                bool iC_jSrc = drConsistsPoint(*aCuts[j].Src, CutConv);
                bool iC_jDst = drConsistsPoint(*aCuts[j].Dst, CutConv);
                bool jC_iSrc = drConsistsPoint(*CutConv.Src, aCuts[j]);
                bool jC_iDst = drConsistsPoint(*CutConv.Dst, aCuts[j]);

                if (iC_jSrc || iC_jDst)
                {
                    bool test1 = SplitCutForCrossedCuts(aCuts, &CutConv, iC_jSrc ? aCuts[j].Src : aCuts[j].Dst, CutsConveyor);
                    if ( test1 )
                    {
                        ret = true;
                        break;
                    }
                    continue;
                }
                if (jC_iSrc || jC_iDst)
                {
                    bool test2 = SplitCutForCrossedCuts(aCuts, aCuts.Items[j], jC_iSrc ? CutConv.Src : CutConv.Dst, CutsConveyor);
                    if ( test2 )
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
                    TGPoint* TmpP = go.AddPoint(Vec);
                    TGCut* TmpCj = aCuts.Items[j];
                    TGCut* TmpCi = &CutConv;
                    if ( TmpP != TmpCj->Dst && TmpP != TmpCj->Src )
                    {
                        bool test1 = SplitCutForCrossedCuts(aCuts, TmpCj, TmpP, CutsConveyor);
                        if ( test1 )
                        {
                            j--;
                            ret = true;
                        }
                    }
                    if ( TmpP != TmpCi->Dst && TmpP != TmpCi->Src )
                    {
                        bool test1 = SplitCutForCrossedCuts(aCuts, TmpCi, TmpP, CutsConveyor);
                        if ( test1 )
                        {
                            ret = true;
                            break;
                        }
                    }
                }
            }
        }
        if ( &CutConv == CutsConveyor.Items[0] )
            CutsConveyor.Delete(0);
    }
	return ret;
}

TGPoint& TGAAnRender::drGetPoint(int index, TMTList<TGCut>& cuts)
{
	if ((cuts.GetCycleItem(index+1)->Src != cuts.Items[index]->Src) && (cuts.GetCycleItem(index+1)->Dst != cuts.Items[index]->Src))
		return *cuts[index].Src;
	else
		return *cuts[index].Dst;
}

TIntVec TGAAnRender::GetPointInPolygon2d(TMTList<TGCut>& cuts)
{
    if ( cuts.Count < 3 )
    {
        ErrorMsg("<TGeomObject::PointInPolygon>: ???-?? ????? < 3");
        return ZEROINTVEC;
    }

    TIntVec p0(drGetPoint(0, cuts).Point), p1(drGetPoint(1, cuts).Point), p2(drGetPoint(2, cuts).Point);
    int i;
    for ( i = 2; i < cuts.Count; i++ )
    {
        p2 = drGetPoint(i, cuts).Point;
        int res = Classify(p2, p0, p1, go.PEPS);
        if ( res == etLEFT || res == etRIGHT )
            break;
/*        if ( fabs(p1.y - p0.y) > EqualEPS )
        {
            MBTi k1 = (p1.x - p0.x)/(p1.y - p0.y);
            MBTi k2 = (p1.z - p0.z)/(p1.y - p0.y);
            p2 = drGetPoint(i, cuts).Point;
            if ( fabs((p2.x - p0.x)/(p2.y - p0.y) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.y - p0.y) - k2) > MyCEPS )
                break;
        }else if (  fabs(p1.x - p0.x) > EqualEPS )
        {
            MBTi k1 = (p1.y - p0.y)/(p1.x - p0.x);
            MBTi k2 = (p1.z - p0.z)/(p1.x - p0.x);
            p2 = drGetPoint(i, cuts).Point;
            if ( fabs((p2.y - p0.y)/(p2.x - p0.x) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.x - p0.x) - k2) > MyCEPS )
                break;
        }*//*else if (  fabs(p1.z - p0.z) > EqualEPS )
        {
            MBTi k1 = (p1.y - p0.y)/(p1.z - p0.z);
            MBTi k2 = (p1.x - p0.x)/(p1.z - p0.z);
            p2 = drGetPoint(i, cuts).Point;
            if ( fabs((p2.y - p0.y)/(p2.z - p0.z) - k1) > MyCEPS || fabs((p2.x - p0.x)/(p2.z - p0.z) - k2) > MyCEPS )
                break;
        }*/
    }
    if ( i == cuts.Count )
    {
        ErrorMsg("< TGeomObject::PointInPolygon>: ????? ???????? ?? ????? ?????");
        return TIntVec((p0.x + p1.x)/2, (p0.y  + p1.y)/2, (p0.z + p1.z)/2);
    }

    TIntVec pCenter( (p2.x + p0.x)/2, (p2.y + p0.y)/2, (p2.z + p0.z)/2 );

    if ( Classify(pCenter, p0, p1, CrossEPS) == etLEFT || Classify(pCenter, p1, p2, CrossEPS) == etLEFT )
        pCenter = TIntVec(2*p1.x - pCenter.x, 2*p1.y - pCenter.y, 2*p1.z - pCenter.z);

//    return pCenter;

    TIntVec MinVec;
    MBTi MinDist = 1000000000;
    for ( int j = 0; j < cuts.Count; j++ )
//        if ( cuts[j].Src != &drGetPoint(1, cuts) &&  cuts[j].Dst != &drGetPoint(1, cuts) )
        {
            TIntVec Vec;
            int Tmp = IsLinesCrossedFull( cuts[j].Src->Point, cuts[j].Dst->Point, p1, pCenter, true, true, true, false, Vec, go.PEPS);
            if ( Tmp == lcCROSSING )
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

TIntVec TGAAnRender::GetPointInPolygon2d(TGPolygon* p)
{
    if ( p->Count < 3 )
        return ZEROINTVEC;

    TIntVec p0(p->GetPoint(0).Point), p1(p->GetPoint(1).Point), p2(p->GetPoint(2).Point);
    int i;
    for ( i = 2; i < p->Count; i++ )
    {
        if ( fabs(p1.y - p0.y) > EqualEPS )
        {
            MBTi k1 = (p1.x - p0.x)/(p1.y - p0.y);
            MBTi k2 = (p1.z - p0.z)/(p1.y - p0.y);
            p2 = p->GetPoint(i).Point;
            if ( fabs((p2.x - p0.x)/(p2.y - p0.y) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.y - p0.y) - k2) > MyCEPS )
                break;
        }else if (  fabs(p1.x - p0.x) > EqualEPS )
        {
            MBTi k1 = (p1.y - p0.y)/(p1.x - p0.x);
            MBTi k2 = (p1.z - p0.z)/(p1.x - p0.x);
            p2 = p->GetPoint(i).Point;
            if ( fabs((p2.y - p0.y)/(p2.x - p0.x) - k1) > MyCEPS || fabs((p2.z - p0.z)/(p2.x - p0.x) - k2) > MyCEPS )
                break;
        }else if (  fabs(p1.z - p0.z) > EqualEPS )
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
        ErrorMsg("< TGeomObject::PointInPolygon>: ????? ???????? ?? ????? ?????");
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

