//---------------------------------------------------------------------------

#pragma hdrstop

#include "TGABoolean.h"
#include "TGObject.h"
#include "TGPoint.h"
#include "TGCut.h"
#include "TGPolygon.h"
#include "Poligon.h"
#include "Misc.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)

#define PEPS_2	go.PEPS
#define PEPS	go.PEPS

int TimeForPrepare		= 0;
int TimeForIntersect	= 0;
int TimeForFix			= 0;
int TimeForSplit		= 0;
int TimeForUnite		= 0;


class TGIntPoint
{
public:
	bool used; //mark

	TIntVec		Point;	//геом. точка

	TGCut		*Cut;   //пара
	TGPolygon	*Poly;

	TGPoint 	*Target;	//искомая точка 

	TGIntPoint()
	{
		Target	= NULL;
		Poly	= NULL;
		Cut		= NULL;
	}

	TGIntPoint(const TGIntPoint &point) //копирование
	{
		Target	= point.Target;
		Poly	= point.Poly;
		Cut		= point.Cut;
		Point	= point.Point;
		used	= point.used;
	}

	TGIntPoint(const TIntVec &point, TGCut *cut, TGPolygon *poly) //создание
	{
		Target	= NULL;
		Poly	= poly;
		Cut		= cut;
		Point	= point;
		used	= false;
	}

	bool Equals(const TGIntPoint &other) const 
	{
		return (other.Cut == Cut) && (other.Poly == Poly);
	}
};

class TGIntCut
{
public:
	TGIntPoint	*Src;
	TGIntPoint	*Dst;
//	TGCut		*Target;

	TGIntCut()
	{
		Src		= NULL;
		Dst		= NULL;
//		Target	= NULL;
	}
	TGIntCut(const TGIntCut& cut)
	{
		Src = cut.Src;
		Dst = cut.Dst;
//		Target	= NULL;
	}
	TGIntCut(TGIntPoint *src, TGIntPoint *dst)
	{
		Src = src;
		Dst = dst;
//		Target	= NULL;
	}
};

struct TPolySlot
{
	TMDelTList < TGIntCut > Data;
	TMTList < TGCut > Cuts;
	TGPolygon *Target;
};



bool TGABoolean::PlanePolygonIntersect(TGPolygon *plane, TGPolygon *p, TMDelTList <TGIntPoint> &cps)
{
	cps.Clear();
	// Разрезаем отрезки плоскостью другого полигона
	for (int i=0;i<p->FCuts.Count;i++)
	{
		TIntVec it;
		if (PlaneCutCross(plane->Normal, plane->Origin, p->FCuts[i].Src->Point, p->FCuts[i].Dst->Point, it, PEPS))
			cps.Add(new TGIntPoint(it, p->FCuts.Items[i], plane));
	}
	//Разрезаем дырки полигона плоскостью другого полигона
	for (int i=0;i<p->FHoles.Count;i++)
	{
		// Разрезаем отрезки дырки
		for (int j=0;j<p->FHoles[i].FCuts.Count;j++)
		{
			TIntVec it;
			if (PlaneCutCross(plane->Normal, plane->Origin, p->FHoles[i].FCuts[j].Src->Point, p->FHoles[i].FCuts[j].Dst->Point, it, PEPS))
				cps.Add(new TGIntPoint(it, p->FHoles[i].FCuts.Items[j], plane));
		}
	}
	return true;
}

bool TGABoolean::IntersectPolygons(TGPolygon *p1, TGPolygon *p2, TMDelTList <TGIntCut> &r1, TMDelTList <TGIntCut> &r2, TMDelTList <TGIntPoint> &pnt_)
{
	TIntVec dir, org;
	MBTi AngX, AngY, AngZ;

	if (!p1->BBox.Overlaps(p2->BBox, 2*PEPS))
		return false;

	if (!PlanePlaneCross(p1->Normal, p1->Origin, p2->Normal, p2->Origin, dir, org, PEPS)) 
		return false;

	TMDelTList <TGIntPoint> cp;
	TMTList <TGPoint> cps;
	TMTList <TGIntPoint> pnt;

	PlanePolygonIntersect(p1, p2, cp);
	for (int i=0;i<cp.Count;i++)
	{
		pnt_.Add( new TGIntPoint(cp[i]));
		pnt.Add(pnt_.Last());
	}	

	PlanePolygonIntersect(p2, p1, cp);
	for (int i=0;i<cp.Count;i++)
	{
		pnt_.Add( new TGIntPoint(cp[i]));
		pnt.Add(pnt_.Last());
	}	

	TGeomObject  temp;
	temp.SnapPoints = false; 

	for (int i=0;i<pnt.Count;i++)
		cps.Add(temp.AddPoint(pnt[i].Point));

	
	TMTList <TMyObject> toTransform;
	TMDelTList < int > intCut1;
	TMDelTList < int > intCut2;

//	p1->Cache();
//	p2->Cache();

	TGPolygon *pp1 = temp.CopyPolygonToObject(*p1);
	TGPolygon *pp2 = temp.CopyPolygonToObject(*p2);

	toTransform.Assign(&cps);
	toTransform.Add(pp1);

	TIntVec normal = pp1->Normal;
	temp.Transform.Translate(toTransform, TIntVec(0,0,0) - org);
	temp.Transform.ToPlaneAndOX(toTransform, normal, dir);

	toTransform.Clear();
	toTransform.Add(pp2);
	
	temp.Transform.Translate(toTransform, TIntVec(0,0,0) - org);
	temp.Transform.ToPlaneAndOX(toTransform, p2->Normal, dir);

//	CopyPolygonToObject(*pp1);
//	CopyPolygonToObject(*pp2);

	for (int i=0;i<cps.Count;i++)
		for (int j=i+1;j<cps.Count;j++)
			if (cps[i].Point.x>cps[j].Point.x)
			{
				cps.Exchange(i,j);
				pnt.Exchange(i,j);
			}	

	for (int i=0;i<cps.Count-1;i++)
	{
		if (cps.Items[i] == cps.Items[i+1])	
			continue;
		// Принадлежность отрезков полигонам
		// Эпсилон принадлежности должен быть в несколько раз меньше эпсилона точек
		TIntVec mid = (cps[i].Point + cps[i+1].Point)/2.0;

#define PEPS_D2 PEPS/2
		int a = pp1->PointInPolygon2d( mid, PEPS_D2);
		int a2 = pp2->PointInPolygon2d( mid, PEPS_D2);
				  
		int ah = pp1->PointInPolygon_UseHoles2d( mid, PEPS_D2);
		int ah2 = pp2->PointInPolygon_UseHoles2d( mid, PEPS_D2);

		// Если отрезок принадлежит обоим полигонам, добавляем общий отрезок
		if ((a == pipINSIDE || a == pipBOUNDARY) && (a2 == pipINSIDE || a2 == pipBOUNDARY))
		{
			if (ah2 != pipOUTSIDE)
				intCut1.Add(new int(i) );

			if (ah != pipOUTSIDE)
				intCut2.Add(new int(i) );
		}	
	}

	for (int i=0;i<intCut1.Count;i++)
	{
		r1.Add(new TGIntCut(pnt.Items[intCut1[i]], pnt.Items[intCut1[i]+1]));
		pnt[intCut1[i]+1].used = true;
		pnt[intCut1[i]].used = true;
	}	

	for (int i=0;i<intCut2.Count;i++)
	{
		r2.Add(new TGIntCut(pnt.Items[intCut2[i]], pnt.Items[intCut2[i]+1]));
		pnt[intCut2[i]+1].used = true;
		pnt[intCut2[i]].used = true;
	}	

	for (int i=0;i<pnt.Count;i++)
		if (!pnt[i].used)
			pnt_.Remove(pnt.Items[i]);

	return true;
}




















void TGABoolean::Operation(TGBoolean op, TGeomObject &obj, TGeomObject &result)
{                                   
/**/int ttStart = GetTickCount();

////////////////
//	Данные
////////////////

	// Соотвестствие полигонов и отрезков пересечения
	TMDelTList < TPolySlot > pl1; 
	TMDelTList < TPolySlot > pl2; 

	// отрезки пересечения
//	TMDelTList <TGIntCut>  split1;
//	TMDelTList <TGIntCut>  split2;
	// точки пересечения
	TMDelTList <TGIntPoint>  splitPnt;

	// Обьект, в котором производятся пересечения полигонов
//	TGeomObject temp;
	// Обьект - хранилище отрезков шва пересечения обьектов
//	TGeomObject intersection;

///////////////
// Подготовка
///////////////

	result.Clear();
//	result.SnapPoints = false;

//	result.assign(this);
//	result.append(obj);

	// Инициализируем списки соответствия
	result.Append(go);
	
	for (int i=0;i<result.FPolygons.Count;i++)
	{
		pl1.Add(new TPolySlot);
		pl1.Last()->Target = result.FPolygons.Items[i];
	}

	int objStartIdx = result.FPolygons.Count;
	
	result.Append(obj);
	for (int i=objStartIdx;i<result.FPolygons.Count;i++)
	{
		pl2.Add(new TPolySlot);
		pl2.Last()->Target = result.FPolygons.Items[i];
	}

///////////////////////////	
//	Настройка обьектов
///////////////////////////	

	//	Отключение привязок точек в temp
	//	Тем не менее, привязка шва к отрезку будет осуществляться внутри функции SliceCutByPlane2d
//	temp.SnapPoints = false;

	//	Включение опции улавливания шва по шву по критерию наиболее ближних точек
//	intersection.SnapPointsToNearest = true;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
//	result.GeometryFix(gfxALL);
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
	
//	result.StructureFix(sfxREMOVE_BRANCHES);
//	return;
//////////////////	
// Пересечение
//////////////////

/**/TimeForPrepare = GetTickCount() - ttStart;
/**/ttStart = GetTickCount();
	for (int i=0;i<pl1.Count;i++)
		for (int j=0;j<pl2.Count;j++)	
		{
			TGPolygon *p1 = pl1[i].Target;
			TGPolygon *p2 = pl2[j].Target;

			if (IntersectPolygons(p1, p2, pl1[i].Data, pl2[j].Data, splitPnt));
		}
/**/TimeForIntersect = GetTickCount() - ttStart;
/**/ttStart = GetTickCount();
		
//////////////////
// Обьединение
//////////////////
	TMTList<TGPoint> splPnt;
	TMTList <TGPoint> resPnt;

	resPnt.Assign(&result.FVertex);	
	for (int i=0;i<splitPnt.Count;i++)
	{
		int	found = -1;
		for (int j=0;j<i;j++)
			if (splitPnt[i].Equals(splitPnt[j]))
			{
				found = j;
				break;
			}
		if (found != -1)
			splitPnt[i].Target = splitPnt[found].Target;
		else
		{
			(splitPnt[i].Target = result.AddPoint(splitPnt[i].Point));
			splPnt.Add(splitPnt[i].Target);
		}	
	}                           

	TMTList<TGCut> rCuts;
	TMTList<TGCut> sCuts;

	rCuts.Assign(&result.FCuts);
//	if (result.GeometryFix(rCuts, splPnt, gfxALL));
//		InfoMsg("Smthin hs chckt!(1)");

	for (int i=0;i<pl1.Count;i++)
	{
		for (int j=0;j<pl1[i].Data.Count;j++)
			if (pl1[i].Data[j].Src->Target != pl1[i].Data[j].Dst->Target)
			{
				pl1[i].Cuts.Add(result.AddCut(pl1[i].Data[j].Src->Target, pl1[i].Data[j].Dst->Target));
				pl1[i].Cuts.Last()->Flags.Intersect = gfTRUE;
			}	
		result.RegisterCutPointers(&pl1[i].Cuts);
	}		

	for (int i=0;i<pl2.Count;i++)
	{
		for (int j=0;j<pl2[i].Data.Count;j++)
			if (pl2[i].Data[j].Src->Target != pl2[i].Data[j].Dst->Target)
			{
				pl2[i].Cuts.Add(result.AddCut(pl2[i].Data[j].Src->Target, pl2[i].Data[j].Dst->Target));
				pl2[i].Cuts.Last()->Flags.Intersect = gfTRUE;
			}	
		result.RegisterCutPointers(&pl2[i].Cuts);
	}
//	result.RegisterCutPointers(&sCuts);
//	result.UnRegisterCutPointers(&sCuts);
	//раньше used означал точка касается отрезков рассечения
	//used теперь имеет смысл "mark"
	
	for (int i=0;i<splitPnt.Count;i++)
		splitPnt[i].used = false;                                   

	for (int i=0;i<splitPnt.Count;i++)
		if (!splitPnt[i].used)
		{
			TMTList<TGPoint> pnts;
			pnts.Add(splitPnt[i].Target);
			splitPnt[i].used = true;
//			splitPnt[i].Target->Tag = true;
//			splitPnt[i].Cut->Tag = true;
			for (int j=i+1;j<splitPnt.Count;j++)
				if (splitPnt[j].Cut == splitPnt[i].Cut)
				{
					splitPnt[j].used = true;
//					splitPnt[j].Target->Tag = gfTRUE;
					if (pnts.IndexOf(splitPnt[j].Target) == -1)
						pnts.Add(splitPnt[j].Target);
				}	
			result.MultiSplitCut(splitPnt[i].Cut, pnts);
		}

//	if (result.GeometryFix(sCuts, resPnt, gfxALL));
//		InfoMsg("Smthin hs chckt!(2)");

	sCuts.Clear();
	for (int i=0;i<pl1.Count;i++)
		TMTListUnite(sCuts, pl1[i].Cuts);

	for (int i=0;i<pl2.Count;i++)
		TMTListUnite(sCuts, pl2[i].Cuts);

	ttStart = GetTickCount();

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
//	result.GeometryFix(gfxALL);
//	result.GeometryFix(gfxALL);
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
			
////////////////////////////////////////////////////////////////////
	for (int i=0;i<pl1.Count;i++)
		for (int j=0;j<pl1[i].Cuts.Count;j++)
			if (result.FCuts.IndexOf(pl1[i].Cuts.Items[j])!= -1 && pl1[i].Cuts.Items[j]->Used())
				pl1[i].Cuts[j].Flags.Boundary = gfTRUE; 

	for (int i=0;i<pl2.Count;i++)
		for (int j=0;j<pl2[i].Cuts.Count;j++)
			if (result.FCuts.IndexOf(pl2[i].Cuts.Items[j])!= -1 && pl2[i].Cuts.Items[j]->Used())
				pl2[i].Cuts[j].Flags.Boundary = gfTRUE; 
////////////////////////////////////////////////////////////////////

	result.SnapPointsToNearest = false;

/**/TimeForFix = GetTickCount() - ttStart;
/**/ttStart = GetTickCount();

	TMTList <TGPolygon> poly1;
	TMTList <TGPolygon> poly2;

	for (int i=0;i<pl1.Count;i++)
	if (pl1[i].Cuts.Count)
	{
		MBTi AngX, AngY;
		TMTList < TMyObject > toTransform;

		TMTListAdd(toTransform, (TMTList <TMyObject> &)pl1[i].Target->FCuts);
		
		for (int j=0;j<pl1[i].Target->FHoles.Count;j++)
			TMTListAdd(toTransform, (TMTList <TMyObject> &)pl1[i].Target->FHoles[j].FCuts);

		for (int j=0;j<pl1[i].Cuts.Count;j++)
			toTransform.Add(pl1[i].Cuts.Items[j]);
			

		result.Cache(toTransform);
		result.Transform.ToPlane(toTransform, pl1[i].Target->Normal);
		
		TMTList < TGPolygon > Result;
		result.SplitPolygon(pl1[i].Target, pl1[i].Cuts, Result);
		TMTListAdd(poly1, Result);
		
		result.Restore(toTransform);
	}

	for (int i=0;i<pl2.Count;i++)
	if (pl2[i].Cuts.Count)
	{
		MBTi AngX, AngY;
		TMTList < TMyObject > toTransform;

		TMTListAdd(toTransform, (TMTList <TMyObject> &)pl2[i].Target->FCuts);

		for (int j=0;j<pl2[i].Target->FHoles.Count;j++)
			TMTListAdd(toTransform, (TMTList <TMyObject> &)pl2[i].Target->FHoles[j].FCuts);

		for (int j=0;j<pl2[i].Cuts.Count;j++)
			toTransform.Add(pl2[i].Cuts.Items[j]);

		result.Cache(toTransform);
		result.Transform.ToPlane(toTransform, pl2[i].Target->Normal);
		
		TMTList < TGPolygon > Result;
		result.SplitPolygon(pl2[i].Target, pl2[i].Cuts, Result);
		TMTListAdd(poly2, Result);
		result.Restore(toTransform);
	} 
	
////////////////////////////////////////////////////			
//	result.ClassifyPolygonsByIntersectBorder();
////////////////////////////////////////////////////			

	
//	result.SolidCheck();

/**/TimeForSplit = GetTickCount() - ttStart;
/**/ttStart = GetTickCount();

	result.UnRegisterCutPointersAtAll();
	if (op == gbSPLIT)
		return;
	else
	{
		TClassify aTake  = 
			 (op == gbA_MINUS_B || op == gbUNION) 
				? gfNEGATIVE :
			 (op == gbB_MINUS_A || op == gbINTERSECTION) 
				? gfPOSITIVE 
				: gfNEGATIVE;
				

		TClassify bTake =  
			(op == gbA_MINUS_B || op == gbINTERSECTION) 
				? gfNEGATIVE :
			(op == gbB_MINUS_A || op == gbUNION)
				? gfPOSITIVE
				: gfPOSITIVE;

		bool aTakeDiff = (op == gbA_MINUS_B || op == gbINTERSECTION);
		bool bTakeDiff = (op == gbB_MINUS_A || op == gbINTERSECTION);

		bool aTakeSame = (op == gbA_XOR_B || op == gbINTERSECTION);
		bool bTakeSame = false;
										  
		bool aFlip = op == gbB_MINUS_A;
		bool bFlip = op == gbA_MINUS_B;

		for (int i=0;i<poly1.Count;i++)
			if (poly1[i].Flags.Origin == gfUNDEFINED)	
			{
				int found = -1;
				for (int j=0;j<poly2.Count;j++)
					if (poly1[i].Equals(poly2[j]))
					{
						found = j;
						break;
					}
				if (found != -1)
				{
					if (poly1[i].Normal.Equal(poly2[found].Normal, EXACT_EPSILON))
					{
						poly1[i].FFlags.Origin = (aTakeSame) ? aTake : gfUNDEFINED;
						poly2[found].FFlags.Origin = (bTakeSame) ? bTake : gfUNDEFINED;
					}
					else
					{
						poly1[i].FFlags.Origin = (aTakeDiff) ? aTake : gfUNDEFINED;
						poly2[found].FFlags.Origin = (bTakeDiff) ? bTake : gfUNDEFINED;
					}
				}
			}
						
		for (int i=0;i<poly1.Count;i++)	
		{
			TGPolygon *p = poly1.Items[i];
			if (!(p->Flags.Origin == aTake/* || (aTakeUndef && p->Flags.Origin == gfUNDEFINED)*/))
			{
				result.FPolygons.Remove(p);
				poly1.Delete(i--);
			}	
		}	

		for (int i=0;i<poly2.Count;i++)	
		{
			TGPolygon *p = poly2.Items[i];
			if (!(p->Flags.Origin == bTake/* || (bTakeUndef && p->Flags.Origin == gfUNDEFINED)*/))
			{
				result.FPolygons.Remove(p);
				poly2.Delete(i--);
			}	
		}	
		if (aFlip)
			for (int i=0;i<poly1.Count;i++)	
				poly1[i].Invert();
		if (bFlip)
			for (int i=0;i<poly2.Count;i++)	
				poly2[i].Invert();
			

	}	
///////////////////////////////////////////////////
//	result.UniteHolesAtAll();
//	result.FreeUnused(fuAll);
////////////////////////////////////////////////////

/**/TimeForUnite = GetTickCount() - ttStart;
/**/ttStart = GetTickCount();
}

void TGABoolean::operator()(TGBoolean op, TGeomObject &obj, TGeomObject &result)
{
	Operation(op, obj, result);
}






