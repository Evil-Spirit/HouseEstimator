//---------------------------------------------------------------------------


#pragma hdrstop

#include "TGPrimitive.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//#include "MTL.h"
//#include "Usefuls.h"  
//#include "MyTemplates.h"
#include "math.h"
#include "misc.h"

#pragma hdrstop
#pragma package(smart_init)

#include "TGObject.h"

void PrimitiveSquare(TGeomObject *obj, MBTi sx, MBTi sy)
{

	TGPoint *p0 = obj->AddPoint(TIntVec(+sx/2, +sy/2, 0));
	TGPoint *p1 = obj->AddPoint(TIntVec(-sx/2, +sy/2, 0));
	TGPoint *p2 = obj->AddPoint(TIntVec(-sx/2, -sy/2, 0));
	TGPoint *p3 = obj->AddPoint(TIntVec(+sx/2, -sy/2, 0));

	
	TMTList <TGCut> cuts;

	cuts.Add(obj->AddCut(p0, p1));// 0
	cuts.Add(obj->AddCut(p1, p2));// 1
	cuts.Add(obj->AddCut(p2, p3));// 2
	cuts.Add(obj->AddCut(p3, p0));// 3

//top
	obj->AddPolygon(cuts);
}

void PrimitiveRoundArrow(TGeomObject *obj, MBTi size, MBTi angle)
{
	TMTList <TGPoint> pnt;

	pnt.Add(obj->AddPoint(TIntVec(0		, 0		, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(0		, 1		, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(-0.25	, 1		, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(0.5   , 2		, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(1.25	, 1		, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(1		, 1		, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(1		, 0		, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(0.6	, -0.6	, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(0   	, -1   	, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(-1   	, -1   	, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(-1   	, -1.25	, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(-2   	, -0.5 	, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(-1   	, 0.25 	, -0.1)));
	pnt.Add(obj->AddPoint(TIntVec(-1   	, 0 	, -0.1)));
//	pnt.Add(obj->AddPoint(TIntVec(0   	, 0		, -0.1)));

	TMTList <TGCut> cuts;

	for (int i=0;i<pnt.Count;i++)
		cuts.Add(obj->AddCut(pnt.Items[i], pnt.Items[(i+1) % pnt.Count]));
//top
	obj->AddPolygon(cuts);
	obj->Extrude(TIntVec(0,0,0.2));
	obj->Transform.Scale(TIntVec(size, size, size));
	obj->Transform.Rotate(TIntVec(0,0,angle),TIntVec(0,0,0));
	for (int i=0;i<obj->PolygonsCount;i++)
		obj->GetPolygon(i).Invert();
}


void PrimitivePyramid(TGeomObject *obj, MBTi sx, MBTi sy, MBTi sz)
{

	TGPoint *p0 = obj->AddPoint(TIntVec(+sx/2, +sy/2, 0));
	TGPoint *p1 = obj->AddPoint(TIntVec(-sx/2, +sy/2, 0));
	TGPoint *p2 = obj->AddPoint(TIntVec(-sx/2, -sy/2, 0));
	TGPoint *p3 = obj->AddPoint(TIntVec(+sx/2, -sy/2, 0));
	TGPoint *p4 = obj->AddPoint(TIntVec(0, 0, sz));

	
	TMTList <TGCut> cuts;

	cuts.Add(obj->AddCut(p0, p1));// 0
	cuts.Add(obj->AddCut(p1, p2));// 1
	cuts.Add(obj->AddCut(p2, p3));// 2
	cuts.Add(obj->AddCut(p3, p0));// 3
//top
	obj->AddPolygon(cuts);
	cuts.Add(obj->AddCut(p0, p4));// 0
	cuts.Add(obj->AddCut(p1, p4));// 1
	cuts.Add(obj->AddCut(p2, p4));// 2
	cuts.Add(obj->AddCut(p3, p4));// 3

	for (int i=0;i<4;i++)
	{
		TMTList <TGCut> cts;
		cts.Add(cuts.Items[i+4]);
		cts.Add(cuts.Items[(i+1)%4+4]);
		cts.Add(cuts.Items[i]);
		obj->AddPolygon(cts);
	}

	
}


void PrimitiveCircle(TGeomObject *obj, MBTi Rad, int partCount)
{
	TMTList <TGPoint> points;
	for (int i=0;i<partCount;i++)
		points.Add(obj->AddPoint(TIntVec(cos(2*M_PI/partCount*i)*Rad,sin(2*M_PI/partCount*i)*Rad,0)));
	TMTList<TGCut> cts;
	for (int i=0;i<partCount;i++)
		cts.Add(obj->AddCut(points.Items[i], points.CycleItems[i+1]));
	obj->AddPolygon(cts);
}

void PrimitiveRing(TGeomObject *obj, MBTi Rad1, MBTi Rad2, int partCount)
{
	if (Rad2>Rad1) 
	{
		MBTi temp = Rad1;
		Rad1 = Rad2;
		Rad2 = temp;
	}
	TMTList <TGPoint> points;
	TMTList <TGCut>	cuts;
	for (int i=0;i<partCount;i++)	
		points.Add(obj->AddPoint(TIntVec(cos(2*M_PI/partCount*i)*Rad1,sin(2*M_PI/partCount*i)*Rad1,0)));

	for (int i=0;i<partCount;i++)	
		points.Add(obj->AddPoint(TIntVec(cos(2*M_PI/partCount*i)*Rad2,sin(2*M_PI/partCount*i)*Rad2,0)));


	for (int i=0;i<partCount;i++)	
		cuts.Add(obj->AddCut(points.Items[i], points.Items[(i+1)%partCount]));
			

	for (int i=0;i<partCount;i++)	
		cuts.Add(obj->AddCut(points.Items[i+partCount], points.Items[(i+1)%partCount+partCount]));

	for (int i=0;i<partCount;i++)	
		cuts.Add(obj->AddCut(points.Items[i], points.Items[i+partCount]));

	for (int i=0;i<partCount;i++)
	{
		TMTList <TGCut> toadd;

		toadd.Add(cuts.Items[i]);
		toadd.Add(cuts.Items[(i+1)%partCount + 2*partCount]);
		toadd.Add(cuts.Items[i+ partCount]);
		toadd.Add(cuts.Items[i + 2*partCount]);

		obj->AddPolygon(toadd);
	}
}

void PrimitiveHoledRing(TGeomObject *obj, MBTi Rad1, MBTi Rad2, int partCount)
{
	if (Rad2>Rad1) 
	{
		MBTi temp = Rad1;
		Rad1 = Rad2;
		Rad2 = temp;
	}

	TMTList <TGPoint> points;
	for (int i=0;i<partCount;i++)	
		points.Add(obj->AddPoint(TIntVec(cos(2*M_PI/partCount*i)*Rad1,sin(2*M_PI/partCount*i)*Rad1,0)));

	for (int i=0;i<partCount;i++)	
		points.Add(obj->AddPoint(TIntVec(cos(2*M_PI/partCount*i)*Rad2,sin(2*M_PI/partCount*i)*Rad2,0)));


	TMTList <TGCut>	cts;

	for (int i=0;i<partCount;i++)	
		cts.Add(obj->AddCut(points.Items[i], points.Items[(i+1)%partCount]));

	TGPolygon *p = obj->AddPolygon(cts);

	cts.Clear();

	for (int i=0;i<partCount;i++)	
		cts.Add(obj->AddCut(points.Items[i + partCount], points.Items[(i+1)%partCount + partCount]));

	p->AddHole(cts);
}

void PrimitiveXRing(TGeomObject *obj, MBTi Rad1, MBTi Rad2, int partCount)
{
	if (Rad2>Rad1) 
	{
		MBTi temp = Rad1;
		Rad1 = Rad2;
		Rad2 = temp;
	}
	TMTList <TGPoint> points;
	TMTList <TGCut>	cuts;
	for (int i=0;i<partCount;i++)	
		points.Add(obj->AddPoint(TIntVec(cos(2*M_PI/partCount*i)*Rad1,sin(2*M_PI/partCount*i)*Rad1,2)));

	for (int i=0;i<partCount;i++)	
		points.Add(obj->AddPoint(TIntVec(cos(2*M_PI/partCount*i)*Rad2,sin(2*M_PI/partCount*i)*Rad2,0)));


	for (int i=0;i<partCount;i++)	
		cuts.Add(obj->AddCut(points.Items[i], points.Items[(i+1)%partCount]));
			

	for (int i=0;i<partCount;i++)	
		cuts.Add(obj->AddCut(points.Items[i+partCount], points.Items[(i+1)%partCount+partCount]));

	for (int i=0;i<partCount;i++)	
		cuts.Add(obj->AddCut(points.Items[i], points.Items[i+partCount]));

	for (int i=0;i<partCount;i++)
	{
		TMTList <TGCut> toadd;

		toadd.Add(cuts.Items[i + 2*partCount]);
		toadd.Add(cuts.Items[i]);
		toadd.Add(cuts.Items[(i+1)%partCount + 2*partCount]);
		toadd.Add(cuts.Items[i+ partCount]);

		obj->AddPolygon(toadd);
	}
}

void PrimitivePlane(TGeomObject *obj, MBTi sx, MBTi sy, const TIntVec &no, const TIntVec &o, MBTi ang)
{

	TMTList <TGPoint> p;
	TMTList <TGCut> cuts;

	TIntVec n = no.Normalize();

	p.Add(obj->AddPoint(TIntVec(+sx/2, +sy/2, 0)));
	p.Add(obj->AddPoint(TIntVec(-sx/2, +sy/2, 0)));
	p.Add(obj->AddPoint(TIntVec(-sx/2, -sy/2, 0)));
	p.Add(obj->AddPoint(TIntVec(+sx/2, -sy/2, 0)));

/*		p.Add(obj->AddPoint(TIntVec(+sx/2, +sy, 0)));
	p.Add(obj->AddPoint(TIntVec(-sx/2, +sy, 0)));
	p.Add(obj->AddPoint(TIntVec(-sx/2, 0, 0)));
	p.Add(obj->AddPoint(TIntVec(+sx/2, 0, 0)));
*/
//		TIntVec ang = GetToPlaneTransformation(n);

///		MBTi AngZ = -ArcTan2(n.y, n.x)/M_PI*180+90;
//		TIntVec nNormal = RotateAround(n, TIntVec(0, 0, AngZ), TIntVec(0,0,0));
//		MBTi AngX = ArcTan2(nNormal.y, nNormal.z)/M_PI*180;

	TIntVec a = GetToPlaneAnglesXZ(n);
		
	for (int i=0;i<p.Count;i++)
	{
		p[i].Point = RotateAround(p[i].Point, TIntVec(0,0,ang), TIntVec(0,0,0));
		TransformXZ(a, p[i].Point);
	}	

	for (int i=0;i<p.Count;i++)
		p[i].Point += o;

	cuts.Add(obj->AddCut(p.Items[0], p.Items[3]));// 3
	cuts.Add(obj->AddCut(p.Items[3], p.Items[2]));// 2
	cuts.Add(obj->AddCut(p.Items[2], p.Items[1]));// 1
	cuts.Add(obj->AddCut(p.Items[1], p.Items[0]));// 0

	obj->AddPolygon(cuts);
}


void PrimitiveLineUnit(TGeomObject *obj, MBTi sx, MBTi sy, const TIntVec &a, const TIntVec &b)
{
	PrimitivePlane(obj, sx, sy, a-b, a, coALL);
	obj->Extrude.Polygon(&obj->GetPolygon(obj->PolygonsCount-1), b-a);
}



