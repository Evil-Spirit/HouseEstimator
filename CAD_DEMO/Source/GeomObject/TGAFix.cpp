//---------------------------------------------------------------------------


#pragma hdrstop

#include "TGAFix.h"
#include "TGObject.h"

#include "Misc.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool TGAFix::Branches(TMTList<TGCut> &cuts)
{

	bool ret = false;
//	FillPointsFlags(flMARK, gfFALSE);
	bool WasDeleted = true;
	while ( WasDeleted )
	{
		WasDeleted = false;
		for (int i=0;i<cuts.Count;i++)
		{
			int cnt = 0;
//			if (cuts[i].Src->FFlags.Mark != gfTRUE)
			{
				for (int j=0;j<cuts[i].Src->CutsCount;j++)
					if ( cuts.IndexOf( &cuts[i].Src->GetCut(j)) != -1)
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
				for (int j=0;j<cuts[i].Dst->CutsCount;j++)
					if ( cuts.IndexOf( &cuts[i].Dst->GetCut(j) ) != -1)
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
	return ret;	
}

bool TGAFix::Repeated(TMTList<TGCut> &cuts, bool atall) //TODO: сделать полное удаление повторных по флaгу
{
	bool ret = false;
	for (int i=0;i<cuts.Count;i++)
		for (int j=i+1;j<cuts.Count;j++)
			if (cuts[i].Equals(cuts[j]))
			{
				cuts.Delete(j--);
				ret = true;
			}	
	return ret;		
}

bool TGAFix::BridgesByContourize(TMTList<TGCut> &cuts)
{
	TMTList <TGCut> contour;
	TMTList <TGCut> cuts_;
	cuts_.Assign(&cuts);
	bool ret = false;
	while (cuts_.Count>2)
	{
		go.Contourize2d(cuts_, contour);
		for (int i=0;i<contour.Count;i++)
			for (int j=i+1;j<contour.Count;j++)
				if (contour.Items[i] == contour.Items[j])
				{
					cuts.Remove(contour.Items[i]);
					ret = true;
				}	
		TMTListSub(cuts_, contour);			
	}
	return ret;
}

bool TGAFix::BridgesByPolygonize(TMTList<TGCut> &cuts)
{
	TMDelTList < TMTList<TGCut> > poly;
	go.Polygonize2d(cuts, poly);
	bool ret = false;
	for (int n=0;n<poly.Count;n++)
		for (int i=0;i<poly[n].Count;i++)
			for (int j=i+1;j<poly[n].Count;j++)
				if (poly[n].Items[i] == poly[n].Items[j])
				{
					cuts.Remove(poly[n].Items[i]);
					ret = true;
				}
	return ret;
}

bool TGAFix::Unused(TGeomPrimitiveType what)
{
	bool ret = false;
	if (what & gpCUTS)
	{    
		for (int i=0;i<go.CutsCount;i++)
			if ( !go.GetCut(i).Used() )
			{
				go.DeleteCut(i--);
				ret = true;
			}	
	}
	if (what & gpPOINTS)
	{
		for (int i=0;i<go.VertexCount;i++)
			if ( !go.GetVertex(i).Used() )
			{
				go.DeletePoint(i--);
				ret = true;
			}	
	}
	return ret;
}


void TGAFix::SynchronizeNormalsRecursive(TGPolygon *p)
{
	p->Flags.Mark = gfTRUE;
	for (int i=0;i<p->FHoles.Count;i++)
		if  (p->FHoles[i].Flags.Mark == gfFALSE)
		{
			TIntVec P_Normal = p->Normal;
			TIntVec H_Normal = p->FHoles[i].Normal;
			if ( (P_Normal-H_Normal).Length()>(P_Normal+H_Normal).Length() )
				p->FHoles[i].Invert();				
			SynchronizeNormalsRecursive( p->FHoles.Items[i] );
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
					throw EMyException("<SynchronizePolygonsWisesRecursive> : ўЄю-Єю эх Єръ!");
				if ( (pCut->CanConnect(*oCut)!=NULL) + (p->FParent!=NULL + o->FParent!=NULL == 1) == 1)
					o->Invert();
				SynchronizeNormalsRecursive(o);
			}	
	if (p->FParent && p->FParent->FFlags.Mark == gfFALSE)
	{
		TIntVec P_Normal = p->Normal;
		TIntVec PP_Normal = p->FParent->Normal;
		if ( (P_Normal-PP_Normal).Length()>(P_Normal+PP_Normal).Length() )
			p->FParent->Invert();				
		SynchronizeNormalsRecursive(p->FParent);
	}
}

void TGAFix::SynchronizeNormals(TGPolygon *p)
{
	if (!go.PolygonsCount)
		return;
	int st = 0;
	if (!p)
	{
		p = &go.GetPolygon(0);
		st = 1;
	}	

	go.FillPolygonsFlags(flMARK, gfFALSE);
	SynchronizeNormalsRecursive(p);

	for (int i=st;i<go.PolygonsCount;i++)
		if (!go.GetPolygon(i).Flags.Mark)
			SynchronizeNormalsRecursive(&go.GetPolygon(i));
}



