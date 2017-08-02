//---------------------------------------------------------------------------
//
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "Object.h"
#include "MyViewV.h"

#include "GeomObjV.h"
#include "Triangulation.h"
#include <Math.hpp>
#include <stdlib.h>
//#include "MyImportV.h"
#include "Convert.h"
#include "VecForm.h"
#include "Poligon.h"

#include "MarkForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VisComp"
#pragma link "VisMat"
#pragma link "VisTex"
#pragma resource "*.dfm"

#define RENDER_POLYGONS
#define RENDER_TRIANGULATE
#define RENDER_WIRE
//#define RENDER_NORMALS

//#define ERRORS
#define CLASSIFY
//#define SMOOTH
TForm1 *Form1;
TGeomObject obj[2];
TConstructFlags construct = coALL;
TRenderType render = rtMARK;
int select = 0;
TIntVec Ang;
//---------------------------------------------------------------------------
TMyView* MyView;
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	MyView =  new TMyView(this);
	MyView->Parent = this;
	MyView->Align = alClient;
	MyView->Visible = true;
	MyView->EditorRender = CustomRender;
	MyView->PlaneN = TIntVec(0,0,1);
	MyView->A = TIntVec(0,0,0);
	MyView->EditorMouseMove = EdMoMo;
	VCO = new TVisPrimitiveObj(NULL);
	VCO->ColorAsMaterial = cmAmbient;
	VCO->Color->Color = clGray;
	n = TIntVec(45,0,0);
	o = TIntVec(5,0,0);
}//---------------------------------------------------------------------------


// Для проверки CutConsistsPoint
AnsiString intToClass(int a)
{
	AnsiString temp;
	switch (a)
	{
		case etLEFT:
			temp = "etLEFT";
			break;
		case etRIGHT:
			temp = "etRIGHT";
			break;
		case etBETWEEN:
			temp = "etBETWEEN";
			break;
		case etBEHIND:
			temp = "etBEHIND";
			break;
		case etBEYOND:
			temp = "etBEYOND";
			break;
		case etORIGIN:
			temp = "etORIGIN";
			break;
		case etDESTINATION:
			temp = "etDESTINATION";
			break;
	}
	return temp;
}
AnsiString intToCom(int a)
{
	AnsiString temp;
	switch (a)
	{
		case comNONCROSS:
			temp = "comNONCROSS";
			break;
		case comCROSS:
			temp = "comCROSS";
			break;
		case comPARALLEL:
			temp = "comPARALLEL";
			break;
		case comTOUCH:
			temp = "comTOUCH";
			break;
		case comNEGATIVE:
			temp = "comNEGATIVE";
			break;
		case comPOSITIVE:
			temp = "comPOSITIVE";
			break;
		default:
			temp = "NULL";
			break;
	}
	return temp;
}

AnsiString intToLc(int a)
{
	AnsiString temp;
	switch (a)
	{
		case lcNONE:
			temp = "lcNONE";
			break;
		case lcCROSSING:
			temp = "lcCROSSING";
			break;
		case lcPARALLEL:
			temp = "lcPARALLEL";
			break;
		case lcEQUAL:
			temp = "lcEQUAL";
			break;
		case lcCOMMONPOINT:
			temp = "lcCOMMONPOINT";
			break;
		case lcCOLLINEAR:
			temp = "lcCOLLINEAR";
			break;
		case lcTOUCH:
			temp = "lcTOUCH";
			break;
		default:
			temp = "NULL";
			break;
	}
	return temp;
}

MBTi DistancePointCut(const TIntVec &P, const TIntVec &A, const TIntVec &B);

int SegmentSegmentCross2d(
	const TIntVec &A1,
	const TIntVec &B1,
	const TIntVec &A2,
	const TIntVec &B2,
	bool a1Fix,
	bool b1Fix,
	bool a2Fix,
	bool b2Fix ,
	TIntVec &itr,
	MBTi USEEPS);

TIntVec RandomVec(const TIntVec &cube = TIntVec(5,5,0), MBTi per = 1000.0)
{
	TIntVec half = cube*0.5*per;
	return 
		TIntVec(
			RandomRange(-half.x, +half.x)/per,
			RandomRange(-half.y, +half.y)/per,
			RandomRange(-half.z, +half.z)/per
		);
}

TGPoint *RandomPoint(TGeomObject &obj, const TIntVec &cube = TIntVec(5,5,0), MBTi per = 1000.0)
{
	return obj.AddPoint(RandomVec(cube, per));
}

TGCut *RandomCut(TGeomObject &obj, const TIntVec &cube = TIntVec(5,5,0), MBTi per = 1000.0)
{
	TGPoint *pnt1;
	TGPoint *pnt2;
/*	while((pnt2 = obj.AddPoint(cube, per)) == pnt1);
	return obj.AddCut(pnt1, pnt2);*/
}

void StatusValue(const AnsiString &str)
{
	Form1->StatusBar1->Panels->Items[0]->Text = str;
}

void StatusValue(MBTi val)
{
	StatusValue(MBTiToStr(val));
}

void StatusValue(bool val)
{
	StatusValue(BoolToStr(val, true));
}
				

/*	
void TForm1::EdMoMo(TObject *sender, TShiftState Shift, int x, int y)
{
	static TIntVec plane_N(0,0,1);
	static TIntVec plane_O;


	TPoint p;
	GetCursorPos(&p);
	p = MyView->ScreenToClient(p);
	TIntVec pos;
	pos.x = p.x;
	pos.y = p.y;
	pos = MyView->ScreenToProject(pos);

//	if ( Shift.Contains(ssRight) )
//		plane_O = pos;
//	else if ( Shift.Contains(ssLeft) )
//		plane_N = pos;
//		plane_N = pos - plane_O).Normalize();
//	else
//		return;
	
	TGeomObject a,b,c;
	a.Assign(&obj[select]);
	a.SnapPoints = false;

	TGPoint *pnt0 = a.AddPoint(TIntVec(-1,0,0));
	TGPoint *pnt1 = a.AddPoint(TIntVec(1,0,0));
	TGPoint *pnt2 = a.AddPoint(plane_O);
	TGPoint *pnt3 = a.AddPoint(plane_N);

	a.AddCut(pnt0, pnt1);
//	a.AddCut(pnt2, pnt3);
 
//	StatusValue(VectorsPerpendicular(pnt0->Point - pnt1->Point, pnt2->Point - pnt1->Point, PEPS));

	
//	PrimitiveLineUnit(&a, 10,10, pos + TIntVec(0,0,5) , TIntVec(0,0,0));
//	PrimitivePlane(&a, 10,10, plane_N, plane_O, coALL);

	TIntVec itr;
	int res;
	for (int i=0;i<10000;i++)
	{
		TIntVec rand = RandomVec(TIntVec(5,5,0));
//		if ((res = IsLinesCollinear(TIntVec(-1,0,0), TIntVec(1,0,0), plane_N, rand, PEPS )))
//		if (IsCutsCollinearAndCrossing(TIntVec(-1,0,0), TIntVec(1,0,0), plane_N, rand, PEPS ) == true)
//		if (Cross_Length())
		{
//			a.AddPoint(itr)->Tag = 1;
			a.AddPoint(rand);
		}	
	}	
		
	StatusValue(intToLc(res));	

//	TIntVec nl, no;
//	PlanePlaneCross(
//		a.GetPolygon(0).Normal,
//		a.GetPolygon(0).Origin,
//		a.GetPolygon(1).Normal,
//		a.GetPolygon(1).Origin,
//		nl, no, 0.5);
//	a.AddCut(no - nl*100, no + nl*100);
		
	
//	TGCut *cut = a.AddCut(pnt0, pnt1);

//	TGCut cut = RandomCut(obj[select]);
//	if (a.CutsCount)
//	{
//		for (int i=0;i<50000;i++)
//		{
//			TIntVec rand = RandomVec(TIntVec(10,10,0));
//			MBTi val = AngleRad(a.GetCut(0).Src->Point, a.GetCut(0).Dst->Point, rand)/M_PI*180;
//			if ( val >= 315 && val <= 360)
//				a.AddPoint(rand);
// 		}	
//	}
		
	
//	if (a.VertexCount)
//		a.GetVertex(0).Point = pos;
		
//	for (int i=0;i<200;i++)
//	{
//		TGPoint *pa = a.AddPoint();
//		TGPoint *pb = a.AddPoint(TIntVec(RandomRange(-2000,2000)/500.0, RandomRange(-2000,2000)/500.0, 0));
//		if (pa!=pb)
//		{
//			TGCut *ct = a.AddCut(pa,pb);
//			TIntVec itr;
//			int res;
//			if ((res = SegmentSegmentCross2d(
// 				ct->Src->Point,
//				ct->Dst->Point,
//				cut->Src->Point,
//				cut->Dst->Point,
//				true,
//				true,
//				true,
//				true,
//				itr,
//				0.0005)) == 1 || res == 2)
//			if (IsLinesCrossedFull(ct->Src->Point, ct->Dst->Point, cut->Src->Point, cut->Dst->Point, true, true, true, true, itr, 0.5))
//			if (IsCutsCrossed(ct->Src->Point, ct->Dst->Point, cut->Src->Point, cut->Dst->Point, itr, 0.5))
//			if (IsLineAndCutCrossed(ct->Src->Point, ct->Dst->Point, cut->Src->Point, cut->Dst->Point, itr, 0.5))
			{
				a.AddPoint(itr)->Tag = 1;
				ct->Flags.Intersect = 1;
			}	
		}	
	}
	
//	if (a.CutsCount)
//	{
//		for (int i=0;i<10000;i++)
//		{
//			TIntVec r((RandomRange(-2000,2000)/1000.0), RandomRange(-2000,2000)/1000.0, 0);
			
//			if (CutConsistsPoint(r, a.GetCut(0).Src->Point, a.GetCut(0).Dst->Point))
			if (DistancePointCut(r, a.GetCut(0).Src->Point, a.GetCut(0).Dst->Point)<PEPS)
//			int res = -1;
//			if ((res =Classify_(r, a.GetCut(0).Src->Point, a.GetCut(0).Dst->Point, PEPS)) == etBETWEEN || res == etDESTINATION || res == etORIGIN )
				a.AddPoint(r);
//			if (LineConsistsPoint(r, a.GetCut(0).Src->Point, a.GetCut(0).Dst->Point))
//			if (LineConsistsPoint(r, a.GetCut(0).Src->Point, a.GetCut(0).Dst->Point))
		}
//			bool result = false;
//			for (int i=0;i<a.CutsCount;i++)
//				if (EdgeType_(r, a.GetCut(i).Src->Point, a.GetCut(i).Dst->Point, PEPS) == 0)
//				{
//  					result = true;
//					break;
//				}
//			if (result)
//				a.AddPoint(r);
//		}	
//	}
	
//	if (a.PolygonsCount)
//	{
//		for (int i=0;i<50000;i++)
//		{
//			TIntVec r((RandomRange(-5000,5000)/1000.0), RandomRange(-5000,5000)/1000.0, 0);
//			
//			if (Classify_(r, a.GetCut(0).Src->Point, a.GetCut(0).Dst->Point, PEPS) == etDESTINATION)
//			if (CutConsistsPoint(r, a.GetCut(0).Src->Point, a.GetCut(0).Dst->Point) == 1)
//			int c;
//			if (((c = a.GetPolygon(0).PointInPolygon_UseHoles2d(r, PEPS)) == 0) || c == 2)
//				a.AddPoint(r);
//		}	
//	}
	


//		this->StatusBar1->Panels->operator [](0)->Text = intToClass (Classify_(pos, a.GetCut(0).Src->Point, a.GetCut(0).Dst->Point, PEPS));
//	for (int i=0;i<a.CutsCount;i++)
//		if (CutConsistsPoint(pnt->Point, a.GetCut(i).Src->Point, a.GetCut(i).Dst->Point))
//			a.SplitCut(&a.GetCut(i), pnt);
	VCO->Init();
	ConstructVCO(&a,construct);
	MyView->View->RenderScene();
}
*/
// Проверка !!!!!!!!!!!!!!!!!!!!!!!!!!
/*
void TForm1::EdMoMo(TObject *sender, TShiftState Shift, int x, int y)
{
	static TIntVec thePos = TIntVec(0,0,0);
	static TIntVec delta;
	static PreviosShiftState;
	if ( !Shift.Contains(ssLeft) )
	{
		PreviosShiftState = false;
		return;
	}	
	TPoint p;
	GetCursorPos(&p);
	p = MyView->ScreenToClient(p);
	TIntVec pos;
	pos.x = p.x;
	pos.y = p.y;
	pos = MyView->ScreenToProject(pos);
	if (!PreviosShiftState)
	{
		delta = thePos - pos;
		PreviosShiftState = true;
		return;
	}
	thePos = pos + delta;
	
//	while (1)
	{
	obj[1].Clear();
	for (int i=0;i<20;i++)
	{
		TGPoint *a = obj[1].AddPoint(TIntVec(RandomRange(-10000,10000)/500.0, RandomRange(-10000,10000)/500.0, 0));
		TGPoint *b = obj[1].AddPoint(TIntVec(RandomRange(-10000,10000)/500.0, RandomRange(-10000,10000)/500.0, 0));
		if (a!=b)
			obj[1].AddCut(a,b);
	}
	
/*
//	obj[0].Assign(&obj[1]);
	TMTList <TGCut> cuts;
	TMDelTList <TMTList <TGCut> > res;

	obj[1].drProcessCrossCuts2d(StatusBar1);

	cuts.Clear();
	for (int i=0;i<obj[1].CutsCount;i++)
		cuts.Add( &obj[1].GetCut(i) );
		
	obj[1].Polygonize2d(cuts, res);
	for (int i=0;i<res.Count;i++)
		obj[1].AddPolygon(res[i]);
	obj[1].StructureFix(sfxREMOVE_BRANCHES);
	obj[1].FreeUnused(fuPoints);
	
	VCO->Init();                       
	RefreshView();
	MyView->View->RenderScene();
	}

//	TGeomObject a,b,c;
//	a.Assign(&obj[0]);
//	b.Assign(&obj[1]);
//	a.Attach(b);
//	a.SolidObjectsBoolean(gbSPLIT,b,c);
//	ConstructVCO(&b,coWIRE);
//	ConstructVCO(&a,coWIRE);
//	ConstructVCO(&a,construct);
//	ConstructVCO(&b,construct);
//	c.SolidCheck();
//	ConstructVCO(&c,construct);
//	a.ToPrimitiveObj2(VCO);
//	ConstructVCO(&b,coWIRE);
//	obj[select].AddPoint(pos);
}
/**/

void TForm1::EdMoMo(TObject *sender, TShiftState Shift, int x, int y)
{
	static TIntVec thePos = TIntVec(0,0,0);
	static TIntVec delta;
	static PreviosShiftState;
	if ( !Shift.Contains(ssLeft) )
	{
		PreviosShiftState = false;
		return;
	}	
	TPoint p;
	GetCursorPos(&p);
	p = MyView->ScreenToClient(p);
	TIntVec pos;
	pos.x = p.x;
	pos.y = p.y;
	pos = MyView->ScreenToProject(pos);
	if (!PreviosShiftState)
	{
		delta = thePos - pos;
		PreviosShiftState = true;
		return;
	}
	thePos = pos + delta;
	
	obj[1].Clear();
//	PrimitiveHoledRing(&obj[1], 4,5,6);
//	PrimitiveSquare(&obj[1], 10,10);
	PrimitivePyramid(&obj[1], 10,10,5);
//	obj[1].Extrude(TIntVec(0,0,5));
//	obj[1].TransformRotate(TIntVec(45,0,0), TIntVec(0,0,0));
	obj[1].TransformTranslate(thePos);
	TGeomObject a,b,c;
	a.Assign(&obj[0]);
	b.Assign(&obj[1]);
//	a.Attach(b);
	a.SolidObjectsBoolean(gbSPLIT,b,c);
//	a.SplitByPlane(TIntVec(1,1,1), thePos);
	VCO->Init();
//	ConstructVCO(&b,coWIRE);
//	ConstructVCO(&a,coWIRE);
//	ConstructVCO(&a,construct);
//	ConstructVCO(&b,construct);
//	c.SolidCheck();
	ConstructVCO(&c,construct);
//	a.ToPrimitiveObj2(VCO);
//	ConstructVCO(&b,coWIRE);
//	obj[select].AddPoint(pos);
//	RefreshView();
	MyView->View->RenderScene();
}

/*
void TForm1::EdMoMo(TObject *sender, TShiftState Shift, int x, int y)
{
	static TIntVec thePos = TIntVec(0,0,0);
	static TIntVec delta;
	static PreviosShiftState;
	if ( !Shift.Contains(ssLeft) )
	{
		PreviosShiftState = false;
		return;
	}	
	TPoint p;
	GetCursorPos(&p);
	p = MyView->ScreenToClient(p);
	TIntVec pos;
	pos.x = p.x;
	pos.y = p.y;
	pos = MyView->ScreenToProject(pos);
	if (!PreviosShiftState)
	{
		delta = thePos - pos;
		PreviosShiftState = true;
		return;
	}
	thePos = pos + delta;
	
	obj[1].Clear();
//	PrimitiveHoledRing(&obj[1], 4,5,6);
//	PrimitiveSquare(&obj[1], 10,10);
	PrimitivePyramid(&obj[1], 10,10,5);
//	obj[1].AddCut(TIntVec(10,10,10), pos);
	obj[1].TransformTranslate(thePos);
	TGeomObject c;
	c.Append(obj[0]);
	c.Append(obj[1]);
	c.GeometryFix(fxCUTSCROSS);
	VCO->Init();
	ConstructVCO(&c,construct);
	MyView->View->RenderScene();
}
*/
void TForm1::CustomRender(TVisView* aView)
{
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);
	glDepthFunc(GL_LEQUAL);
//	glDepthFunc(GL_ALWAYS);
	VCO->Render(aView);
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

void TForm1::ConstructVCO(TGeomObject* GO, TConstructFlags co)
{
//	TGeomObject g;
//	TGeomObject *GO = &g;
//	g.Assign(G);
//	G->Triangulate3(g);
	
	if (co & coPOLYGONS)
	{
		for (int i=0;i<GO->PolygonsCount;i++)
			{
				TGPolygon& POL = GO->GetPolygon(i);
				VCO->AddPrimitiveArray(GL_TRIANGLES);
				switch (render)
				{
				case rtCLASSIFY:
					VCO->Primitive[VCO->PrimitiveCount-1]->Material = 	
						  (POL.Flags.Origin == gfPOSITIVE)
						? MaterialPolyRight  
						: (POL.Flags.Origin == gfNEGATIVE)
						? MaterialPolyLeft
						: PolygonMaterial;
					break;
				case rtERROR:
					VCO->Primitive[VCO->PrimitiveCount-1]->Material = 
						  (POL.Flags.Error == gfTRUE)
						? MaterialPolyRight  
						: PolygonMaterial;
					break;
				case rtSMOOTH:
					VCO->Primitive[VCO->PrimitiveCount-1]->Material = PolygonMaterial;
					break;
				case  rtCOLOR:
					VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
					VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = (TColor)0;
					VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmDiffuse;
					VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = (TColor)colors[i % 6];
					break;
				case rtMARK :
					VCO->Primitive[VCO->PrimitiveCount-1]->Material = 
						  (POL.Tag == gfTRUE)
						? MaterialMark  
						: PolygonMaterial;
					break;
				}
						
//				POL.CalculatePlane();
				TIntVec Normal = POL.Normal; 
				TMDelTList<TIntVec> tris;
				Triangulate_(&POL, tris); 
				for (int j=0;j<tris.Count;j++)
					VCO->AddIndex( VCO->Points->Add( VisMathVec(tris[j]), VisMathVec(Normal),ZEROVEC ),VCO->PrimitiveCount-1 );
/*				for (int j=0;j<POL.Count;j++)
					VCO->AddIndex( VCO->Points->Add( VisMathVec(POL.GetPoint(j).Point), VisMathVec(Normal),ZEROVEC ),VCO->PrimitiveCount-1 );*/
			}	
	}	
	if (co & coPOINTS)
	{
		for (int i=0;i<GO->VertexCount;i++)
		{
			VCO->AddPrimitiveArray(GL_POINTS);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(GO->GetVertex(i).Point), ZEROVEC, ZEROVEC ),VCO->PrimitiveCount-1);
			
			if (GO->GetVertex(i).Tag == gfTRUE)
				VCO->Primitive[VCO->PrimitiveCount-1]->Material = MaterialMark; 
			else	
				VCO->Primitive[VCO->PrimitiveCount-1]->Material = PointMaterial; 
		}		
	}	

	if (co & coCUTS)
	{
		for ( int i=0;i<GO->CutsCount;i++ )
		{
			VCO->AddPrimitiveArray(GL_LINES);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(GO->GetCut(i).Src->Point), ZEROVEC,ZEROVEC ),VCO->PrimitiveCount-1);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(GO->GetCut(i).Dst->Point), ZEROVEC,ZEROVEC ), VCO->PrimitiveCount-1);
			switch (render)
			{
			case rtCLASSIFY:
				VCO->Primitive[VCO->PrimitiveCount-1]->Material = 
					  (GO->GetCut(i).Flags.Origin == gfPOSITIVE)
					? MaterialRight  
					: (GO->GetCut(i).Flags.Origin == gfNEGATIVE)
					? MaterialLeft
					: (GO->GetCut(i).Flags.Boundary == gfTRUE)
					? MaterialBorder
					: (GO->GetCut(i).Flags.Intersect == gfTRUE)
					? MaterialItr
					: MaterialOther;
				break;
			case rtERROR:
				VCO->Primitive[VCO->PrimitiveCount-1]->Material = 
					  (GO->GetCut(i).Flags.Error == gfTRUE)
					? MaterialItr
					: MaterialOther;
				break;
			case rtSMOOTH:
				VCO->Primitive[VCO->PrimitiveCount-1]->Material = 
					  (!GO->GetCut(i).Smooth)
					? MaterialItr
					: MaterialOther;
				break;
			case rtMARK:
				VCO->Primitive[VCO->PrimitiveCount-1]->Material = 
					  (GO->GetCut(i).Tag == 1)
					? MaterialItr
					: MaterialOther;
				break;
			case rtCOLOR:
				VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
				VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = (TColor)0;
				VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmDiffuse;
				VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = (TColor)colors[i % 6];
				break;
			}
		}	
	}	
	
	if (co & coNORMALS)
	{
		for ( int i=0;i<GO->PolygonsCount;i++)
		{
			TIntVec src = GO->GetPolygon(i).GetMidOrigin();
			TIntVec dst;

			dst = src + GO->GetPolygon(i).Normal/2;
			VCO->AddPrimitiveArray(GL_LINES);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(src), ZEROVEC, ZEROVEC), VCO->PrimitiveCount-1);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(dst), ZEROVEC, ZEROVEC), VCO->PrimitiveCount-1);

			VCO->Primitive[VCO->PrimitiveCount-1]->Material = MaterialItr;
		}	
	}

	if (co & coPOLYGONHOLES)
	{
		for (int i=0;i<GO->PolygonsCount;i++)
		for (int k=0;k<GO->GetPolygon(i).FHoles.Count;k++)
			{
				TGPolygon& POL = GO->GetPolygon(i).FHoles[k];
				VCO->AddPrimitiveArray(GL_TRIANGLES);
				VCO->Primitive[VCO->PrimitiveCount-1]->Material = HoleMaterial;
/*				switch (render)
				{
				case rtCLASSIFY:
					VCO->Primitive[VCO->PrimitiveCount-1]->Material = 	
						  (POL.Flags.Origin == gfPOSITIVE)
						? MaterialPolyRight  
						: (POL.Flags.Origin == gfNEGATIVE)
						? MaterialPolyLeft
						: PolygonMaterial;
					break;
				case rtERROR:
					VCO->Primitive[VCO->PrimitiveCount-1]->Material = 
						  (POL.Flags.Error == gfTRUE)
						? MaterialPolyRight  
						: PolygonMaterial;
					break;
				case rtSMOOTH:
					VCO->Primitive[VCO->PrimitiveCount-1]->Material = PolygonMaterial;
					break;
				case  rtCOLOR:
					VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
					VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = 0;
					VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmDiffuse;
					VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = colors[i % 6];
					break;
				case rtMARK :
					VCO->Primitive[VCO->PrimitiveCount-1]->Material = 
						  (POL.Tag == gfTRUE)
						? MaterialMark  
						: PolygonMaterial;
					break;
				}
  */
				TMDelTList<TIntVec> tris;
				Triangulate_(&POL, tris); 
				TIntVec Normal = POL.Normal; 
				for (int j=0;j<tris.Count;j++)
					VCO->AddIndex( VCO->Points->Add( VisMathVec(tris[j]), VisMathVec(Normal),ZEROVEC ),VCO->PrimitiveCount-1 );
			}	
	}	

//VCO->CalcNormals();	 	

}

MBTi Epsilon1 = 0.005;
MBTi Epsilon2 = GET_CEPS(0.005);
MBTi Epsilon3 = 0.005;

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	VCO->Init();
}
//---------------------------------------------------------------------------

void TForm1::RefreshView()
{
	VCO->Init();
	obj[0].ToPrimitiveObj2(VCO, construct, render);
//  	obj[1].ToPrimitiveObj2(VCO, construct, render);
//	ConstructVCO(&obj[0], construct);
  //	ConstructVCO(&obj[1], construct);
//	obj[1].ToPrimitiveObj2(VCO, construct);
//	obj[0].ToPrimitiveObj2(VCO, construct);
///	obj.ConstructVCO(*VCO);
//	obj.ToPrimitiveObj(VCO, coWIRE | coSOLID);
//	obj.ToPrimitiveObj2(VCO);
/*	for (int i=0;i<VCO->PrimitiveCount;i++)
		VCO->Primitive[i]->Material = PolygonMaterial;
*/		
	MyView->View->RenderScene();
}
void __fastcall TForm1::Load1Click(TObject *Sender)
{
	if (OpenDialog1->Execute())
	{
		if (ExtractFileExt(OpenDialog1->FileName).LowerCase() == ".sgo")
		{
		 //	LoadGeometry(OpenDialog1->FileName, VCO);
		 //	obj[select].FromPrimitiveObj(VCO);
		} else
		if (ExtractFileExt(OpenDialog1->FileName).LowerCase() == ".gob")
		{
			TMemoryStream* MSL = new TMemoryStream();
			MSL->LoadFromFile(OpenDialog1->FileName);
			obj[select].ReadData(MSL);
			delete MSL;
		} else
		{
			ErrorMsg("Неизвестный формат файла!");
		}
		RefreshView();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Save1Click(TObject *Sender)
{
	SaveDialog1->FileName = ChangeFileExt(ExtractFileName(OpenDialog1->FileName), ".gob");
	if (SaveDialog1->Execute())
	{
		TMemoryStream* MSS = new TMemoryStream();
		obj[select].WriteData(MSS);
		MSS->SaveToFile(SaveDialog1->FileName);
		delete MSS;   	
	}	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Convert1Click(TObject *Sender)
{
	if (Form2->ShowModal() == mrOk)
		if (OpenDialog2->Execute())
			for (int i=0;i<OpenDialog2->Files->Count;i++)
			{
				if (ExtractFileExt(OpenDialog2->Files->operator[](i)).LowerCase() == ".sgo")
				{
					/*StatusBar1->Panels->operator [](0)->Text = "Открытие...";
					LoadGeometry(OpenDialog2->Files->operator[](i), VCO);

					if (Form2->CheckBox2->Checked)
						MyView->View->RenderScene();

					StatusBar1->Panels->operator [](0)->Text = "Конвертация...";
					obj[select].FromPrimitiveObj(VCO);

					if (Form2->CheckBox2->Checked)
						RefreshView();            
					if (Form2->CheckBox1->Checked)
					{
						StatusBar1->Panels->operator [](0)->Text = "Оптимизация...";
						MBTi Epsilon1;
						MBTi Epsilon2;
						MBTi Epsilon3;

						if (IS_FLOAT(Form2->Edit2->Text))
							Epsilon2 = StrToMBTi(Form2->Edit2->Text);
						else
						{
							Epsilon2 = CEPS; Form2->Edit2->Text = FloatToStr(CEPS);InfoMsg("Incorrect input");
						}

						if (IS_FLOAT(Form2->Edit3->Text))
							Epsilon3 = StrToMBTi(Form2->Edit3->Text);
						else
						{
							Epsilon3 = PEPS; Form2->Edit3->Text = FloatToStr(PEPS);InfoMsg("Incorrect input");
						}

						if (Form2->CheckBox3->Checked)
							if (Form2->CheckBox4->Checked)
								obj[select].Optimize(Epsilon2, Epsilon3, true, true);
							else	
								obj[select].Optimize(Epsilon2, Epsilon3, true, false);
						else	
							if (Form2->CheckBox4->Checked)
								obj[select].Optimize(Epsilon2, Epsilon3, false, true);
							else	
								obj[select].Optimize(Epsilon2, Epsilon3, false, false);
					}	
					if (Form2->CheckBox2->Checked)
						RefreshView();            
					
					StatusBar1->Panels->operator [](0)->Text = "Сохранение...";

					TMemoryStream* MSS = new TMemoryStream();
					obj[select].WriteData(MSS);
					MSS->SaveToFile("..\\TGObjects\\" + ChangeFileExt(ExtractFileName(OpenDialog2->Files->operator[](i)), ".gob"));
					delete MSS;   	

					StatusBar1->Panels->operator [](0)->Text = "Done";
					*/
				} else
				{
					ErrorMsg("Неправильный или неизвестный формат файла!");
				}
			}
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Optimize1Click(TObject *Sender)
{
	if (Form2->ShowModal() == mrOk)
	{
		if (IS_FLOAT(Form2->Edit2->Text))
		{
			Epsilon2 = StrToMBTi(Form2->Edit2->Text);
		}
		else
		{
			Epsilon2 = GET_CEPS(0.005); Form2->Edit2->Text = FloatToStr(GET_CEPS(0.005));InfoMsg("Incorrect input");
		}

		if (IS_FLOAT(Form2->Edit3->Text))
		{
			Epsilon3 = StrToMBTi(Form2->Edit3->Text);
		}
		else
		{
			Epsilon3 = 0.005; Form2->Edit3->Text = FloatToStr(0.005);InfoMsg("Incorrect input");
		}
		/*int was = */obj[select].PolygonsCount;
		if (Form2->CheckBox3->Checked)
			if (Form2->CheckBox4->Checked)
				obj[select].Optimize(Epsilon2, Epsilon3, true, true);
			else	
				obj[select].Optimize(Epsilon2, Epsilon3, true, false);
		else	
			if (Form2->CheckBox4->Checked)
				obj[select].Optimize(Epsilon2, Epsilon3, false, true);
			else	
				obj[select].Optimize(Epsilon2, Epsilon3, false, false);
		RefreshView();
/*		for (int i=0;i<10;i++)
			Beep(1000, 100);
*///	InfoMsg("Was = "+IntToStr(was)+", Now = "+IntToStr(obj.PolygonsCount));	
	}	
}   	
//---------------------------------------------------------------------------


void __fastcall TForm1::objClear1Click(TObject *Sender)
{
	obj[select].Clear();
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::objSpiltByPlane1Click(TObject *Sender)
{
	TIntVec n, o;
	Form3->Caption = "Normal";
	Form3->Default = TIntVec(1,1,1);
	if (Form3->ShowModal() == mrOk)
		n = Form3->Vector;
	else
		return;	

	Form3->Caption = MSG_ERR_5;
	Form3->Default = TIntVec(0,0,0);
	if (Form3->ShowModal() == mrOk)
		o = Form3->Vector;
	else
		return;	
	
	obj[select].SplitByPlane(n, o);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::objSliceByPlane1Click(TObject *Sender)
{
	TIntVec n, o;
	Form3->Caption = "Normal";
	Form3->Default = TIntVec(1,1,1);
	if (Form3->ShowModal() == mrOk)
		n = Form3->Vector;
	else
		return;	

	Form3->Caption = MSG_ERR_5;
	Form3->Default = TIntVec(0,0,0);
	if (Form3->ShowModal() == mrOk)
		o = Form3->Vector;
	else
		return;	


	obj[select].SliceByPlane(n, o);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::objSolidCheck1Click(TObject *Sender)
{
	obj[select].SolidCheck();
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::obj1Click(TObject *Sender)
{
	obj[select].SolidFix();
	RefreshView();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::DetectHolesAtAll1Click(TObject *Sender)
{
	obj[select].DetectHolesAtAll(Epsilon2, Epsilon3);
	RefreshView();
/*	for (int i=0;i<10;i++)
		Beep(1000, 100);
*/		
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RefreshView1Click(TObject *Sender)
{
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrossCutsAtAll1Click(TObject *Sender)
{
	obj[select].CrossCutsAtAll(Epsilon2, Epsilon3);
	RefreshView();
/*	for (int i=0;i<10;i++)
		Beep(1000, 100);
*/		
}
//---------------------------------------------------------------------------


void __fastcall TForm1::WeldPointsAtAll1Click(TObject *Sender)
{
	obj[select].WeldPointsAtAll(Epsilon3);	
//	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Info1Click(TObject *Sender)
{
	InfoMsg("Vertexes	= " + IntToStr(obj[select].VertexCount) + "\n" + 
			"Cuts		= " + IntToStr(obj[select].CutsCount) + "\n" +
			"Polygons	= " + IntToStr(obj[select].PolygonsCount));	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Extrude1Click(TObject *Sender)
{
	Form3->Caption = "Direction";
	Form3->Default = TIntVec(0,0,10);
	if (Form3->ShowModal() != mrOk)
		return;
	obj[select].Extrude(Form3->Vector);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Square1Click(TObject *Sender)
{
	Form3->Caption = "Rectangle";
	Form3->Default = TIntVec(10,10,0);
	if (Form3->ShowModal() != mrOk)
		return;
	PrimitiveSquare(&obj[select], Form3->Vector.x, Form3->Vector.y);	
	RefreshView();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Pyramid1Click(TObject *Sender)
{
	Form3->Caption = "Pyramid";
	Form3->Default = TIntVec(10,10,5);
	if (Form3->ShowModal() != mrOk)
		return;
	PrimitivePyramid(&obj[select], Form3->Vector.x, Form3->Vector.y, Form3->Vector.z);	
	RefreshView();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Circle1Click(TObject *Sender)
{
	Form3->Caption = "Circle";
	Form3->Default = TIntVec(10,8,0);
	if (Form3->ShowModal() != mrOk)
		return;
	PrimitiveCircle(&obj[select], Form3->Vector.x, (int)Form3->Vector.y);	
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Ring1Click(TObject *Sender)
{
	Form3->Caption = "Ring";
	Form3->Default = TIntVec(4,6,8);
	if (Form3->ShowModal() != mrOk)
		return;
	PrimitiveRing(&obj[select], Form3->Vector.x, Form3->Vector.y, (int)Form3->Vector.z);	
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HoledRing1Click(TObject *Sender)
{
	Form3->Caption = MSG_1;
	Form3->Default = TIntVec(4,6,8);
	if (Form3->ShowModal() != mrOk)
		return;
	PrimitiveHoledRing(&obj[select], Form3->Vector.x, Form3->Vector.y, (int)Form3->Vector.z);	
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SyncronizePolygonsWises1Click(TObject *Sender)
{
	obj[select].SynchronizePolygonsWises();
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Triangulate1Click(TObject *Sender)
{
	obj[select].Triangulate();	
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HoledXRing1Click(TObject *Sender)
{
	Form3->Caption = MSG_2;
	Form3->Default = TIntVec(4,6,8);
	if (Form3->ShowModal() != mrOk)
		return;
	PrimitiveXRing(&obj[select], Form3->Vector.x, Form3->Vector.y, (int)Form3->Vector.z);	
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CalculateNormals1Click(TObject *Sender)
{
	obj[select].CalculateNormals();	
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Rotate1Click(TObject *Sender)
{
	Form3->Caption = "Angles";
	Form3->Default = n;
	if (Form3->ShowModal() == mrOk)
		n = Form3->Vector;
	else
		return;	
		Form3->Caption = MSG_3;
	Form3->Default =o;
	if (Form3->ShowModal() == mrOk)
		o = Form3->Vector;
	else
		return;	
	for (int i=0;i<10 ;i++)
		obj[select].TransformRotate(n, o);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
	select = 0;
	Menu->Items->Items[4]->Items[0]->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
	select = 1;
	Menu->Items->Items[4]->Items[1]->Checked = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::AB1Click(TObject *Sender)
{
	TGeomObject temp;
	obj[0].SolidObjectsBoolean(gbA_XOR_B, obj[1], temp);
	obj[1].Clear();
	obj[0].Assign(&temp);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AB2Click(TObject *Sender)
{
//	int start = GetTickCount();
	TGeomObject temp;
	obj[0].SolidObjectsBoolean(gbA_MINUS_B, obj[1], temp);
	obj[1].Clear();
	obj[0].Assign(&temp);
//	InfoMsg("Elapsed time: "+MBTiToStr((MBTi)(GetTickCount()-start)/1000)+" sec.");
/*	InfoMsg("Elapsed Transformation time: "+IntToStr(TimeForTransform)+
			"\nElapsed Intersection time :"+IntToStr(TimeForIntersect)+
			"\nElapsed Detection time :"+IntToStr(TimeForDetect)+
			"\nElapsed Split time :"+IntToStr(TimeForSplit)+
			"\nElapsed TotalSplit time :"+IntToStr(TimeTotalSplit)+
			"\nElapsed Other time :"+IntToStr(TimeTotal - TimeForTransform - TimeForIntersect - TimeForDetect)+
			"\nElapsed Total time :"+IntToStr(TimeTotal));*/
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BA1Click(TObject *Sender)
{
	TGeomObject temp;
	obj[0].SolidObjectsBoolean(gbB_MINUS_A, obj[1], temp);
	obj[1].Clear();
	obj[0].Assign(&temp);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AB3Click(TObject *Sender)
{
	TGeomObject temp;
	obj[0].SolidObjectsBoolean(gbA_AND_B, obj[1], temp);
	obj[1].Clear();
	obj[0].Assign(&temp);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Clear1Click(TObject *Sender)
{
	for (int i=0;i<2;i++)
		obj[i].Clear();
	Menu->Items->Items[4]->Items[0]->OnClick(this);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Move1Click(TObject *Sender)
{
	Form3->Caption = "Direction";
	Form3->Default = TIntVec(1,0,0);
	if (Form3->ShowModal() != mrOk)
		return;
	obj[select].TransformTranslate(Form3->Vector);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Points1Click(TObject *Sender)
{
	if (construct & coPOINTS)
		construct &= ~coPOINTS;
	else	
		construct |= coPOINTS;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cuts1Click(TObject *Sender)
{
	if (construct & coCUTS)
		construct &= ~coCUTS;
	else	
		construct |= coCUTS;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Polygons1Click(TObject *Sender)
{
	if (construct & coPOLYGONS)
		construct &= ~coPOLYGONS;
	else	
		construct |= coPOLYGONS;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Normals1Click(TObject *Sender)
{
	if (construct & coNORMALS)
		construct &= ~coNORMALS;
	else	
		construct |= coNORMALS;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Holes1Click(TObject *Sender)
{
	if (construct & coPOLYGONHOLES)
		construct &= ~coPOLYGONHOLES;
	else	
		construct |= coPOLYGONHOLES;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScaleTo1Click(TObject *Sender)
{
	Form3->Caption = "Dimensions";
	Form3->Default = TIntVec(10,0,0);
	if (Form3->ShowModal() != mrOk)
		return;
	obj[select].ScaleTo(Form3->Vector.x);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FreeUnused1Click(TObject *Sender)
{
	obj[select].FreeUnused(fuAll);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Mark2Click(TObject *Sender)
{
	Menu->Items->Items[6]->Items[6]->Checked = true;
	render = rtMARK;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Classify1Click(TObject *Sender)
{
	Menu->Items->Items[6]->Items[7]->Checked = true;
	render = rtCLASSIFY;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Error1Click(TObject *Sender)
{
	Menu->Items->Items[6]->Items[8]->Checked = true;
	render = rtERROR;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Smooth1Click(TObject *Sender)
{
	Menu->Items->Items[6]->Items[9]->Checked = true;
	render = rtSMOOTH;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Color1Click(TObject *Sender)
{
	Menu->Items->Items[6]->Items[10]->Checked = true;
	render = rtCOLOR;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Point1Click(TObject *Sender)
{
	if (Form4->ShowModal() != mrOk)
		return;
	switch (Form4->selection)
	{
		case 0:
			if (Form4->value>=0 && Form4->value<obj[select].VertexCount)
				obj[select].GetVertex(Form4->value).Tag = gfTRUE;
			break;
		case 1:
			for (int i=0;i<obj[select].VertexCount;i++)
				if (obj[select].GetVertex(i).CutsCount == Form4->value)
					obj[select].GetVertex(i).Tag = gfTRUE;
			break;	
	}
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cut1Click(TObject *Sender)
{
	if (Form4->ShowModal() != mrOk)
		return;
	switch (Form4->selection)
	{
		case 0:
			if (Form4->value>=0 && Form4->value<obj[select].CutsCount)
				obj[select].GetCut(Form4->value).Tag = gfTRUE;
			break;
		case 1:
/*			for (int i=0;i<obj[select].CutsCount;i++)
				if (obj[select].GetCut(i).CutsCount == Form4->value)
					obj[select].GetCut(i).Tag = gfTRUE;*/
			break;	
	}
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Polygon1Click(TObject *Sender)
{
	if (Form4->ShowModal() != mrOk)
		return;
	switch (Form4->selection)
	{
		case 0:
			if (Form4->value>=0 && Form4->value<obj[select].PolygonsCount)
				obj[select].GetPolygon(Form4->value).Tag = gfTRUE;
			break;
		case 1:
			for (int i=0;i<obj[select].PolygonsCount;i++)
				if (obj[select].GetPolygon(i).Count == Form4->value)
					obj[select].GetPolygon(i).Tag = gfTRUE;
			break;	
	}
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearMarks1Click(TObject *Sender)
{
	for (int i=0;i<obj[select].VertexCount;i++)
		obj[select].GetVertex(i).Tag = gfFALSE;
	for (int i=0;i<obj[select].CutsCount;i++)
		obj[select].GetCut(i).Tag = gfFALSE;
	for (int i=0;i<obj[select].PolygonsCount;i++)
		obj[select].GetPolygon(i).Tag = gfFALSE;
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SavePolygonAsFigure1Click(TObject *Sender)
{
	if (Form4->ShowModal() != mrOk)
		return;
	switch (Form4->selection)
	{
		case 0:
			if (Form4->value>=0 && Form4->value<obj[select].PolygonsCount)
			{
				obj[select].SavePolygonAsFigure(Form4->value, "C:\\(WORK)\\Config_\\BIN\\Attributes\\Import.gob");
				
			}	
			break;
		case 1:
/*			for (int i=0;i<obj[select].PolygonsCount;i++)
				if (obj[select].GetPolygon(i).Count == Form4->value)
					obj[select].GetPolygon(i).Tag = gfTRUE;*/
			break;	
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveObjectAsFigure1Click(TObject *Sender)
{
	if (Form4->ShowModal() != mrOk)
		return;
	switch (Form4->selection)
	{
		case 0:
			if (Form4->value>=0 && Form4->value<obj[select].PolygonsCount)
			{
				MBTi a,b,c;
				TGeomObject oj;
				oj.Assign(&obj[select]);
				oj.TransformToPolygon(oj.FPolygons.Items[Form4->value],TIntVec(0,0,0), TIntVec(1,0,0),a,b,c);
				oj.Write("C:\\(WORK)\\Config_\\BIN\\Attributes\\Import.gob");
			}	
			break;
		case 1:
/*			for (int i=0;i<obj[select].PolygonsCount;i++)
				if (obj[select].GetPolygon(i).Count == Form4->value)
					obj[select].GetPolygon(i).Tag = gfTRUE;*/
			TMTList <TGCut> cut;
			obj[select].SaveCutsAsFigure(cut, "nodata.obj");
			break;	
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PolygonPlaceOnPlane1Click(TObject *Sender)
{
	if (Form4->ShowModal() != mrOk)
		return;
	switch (Form4->selection)
	{
		case 0:
			if (Form4->value>=0 && Form4->value<obj[select].PolygonsCount)
			{
				MBTi a,b;
				obj[select].FPolygons[Form4->value].PlaceOnPlane(a,b,TIntVec(0,0,0));
			}	
			break;  
		case 1:
/*			for (int i=0;i<obj[select].PolygonsCount;i++)
				if (obj[select].GetPolygon(i).Count == Form4->value)
					obj[select].GetPolygon(i).Tag = gfTRUE;*/
			break;	
	}
	RefreshView();
}
//---------------------------------------------------------------------------
MBTi AngX1, AngY1, AngZ1;
void __fastcall TForm1::TransformToPlane1Click(TObject *Sender)
{
	if (Form4->ShowModal() != mrOk)
		return;
	switch (Form4->selection)
	{
		case 0:
			if (Form4->value>=0 && Form4->value<obj[select].PolygonsCount)
			{
				MBTi a,b;
				obj[select].TransformToPolygon(obj[select].FPolygons.Items[Form4->value], TIntVec(0,0,0), TIntVec(0,0,0), AngX1, AngY1, AngZ1)	;
			}	
			break;  
		case 1:
/*			for (int i=0;i<obj[select].PolygonsCount;i++)
				if (obj[select].GetPolygon(i).Count == Form4->value)
					obj[select].GetPolygon(i).Tag = gfTRUE;*/
			break;	
	}
	RefreshView();
}
//---------------------------------------------------------------------------
//obj.SavePolygonAsFigure(1, AnsiString("C:\\(WORK)\\Config_\\BIN\\Attributes\\Import.gob"))

void __fastcall TForm1::CalculateZEps1Click(TObject *Sender)
{
	TGeomObject go;
	go.Assign(&obj[select]);
	MBTi AngX, AngY, AngZ;
	for (int j=0;j<go.PolygonsCount;j++)
	{
		for (int i=0;i<1000;i++)
		{
			go.TransformToPolygon(go.FPolygons.Items[j], TIntVec(0,0,1), TIntVec(0,0,0), AngX, AngY, AngZ);
			go.TransformBack(TIntVec(0,0,1), TIntVec(0,0,0), AngX, AngY, AngZ);
		}
		MBTi defl = 0;
		MBTi max = 0;
		TGPolygon &poly = go.FPolygons[j];
		for (int i=0;i<poly.Count;i++)
		{
			MBTi t = fabs(ScalarP(poly.Normal, poly.GetPoint(i).Point) - ScalarP(poly.Normal, poly.Origin));
			defl += t;
			if (max<t)
				max = t;
		}
//		InfoMsg("The Total Deflection = " + FloatToStr(defl));
		InfoMsg("The Maximum Deflection = " + FloatToStr(max));
	}
	MBTi Eps = 0;
	for (int i=0;i<go.VertexCount;i++)
		Eps+=(go.GetVertex(i).Point - obj[select].GetVertex(i).Point).Length();
		
	InfoMsg("The Epsiolon = "+FloatToStr(Eps));
	obj[select].Assign(&go);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CalculateDeflection1Click(TObject *Sender)
{
	if (Form4->ShowModal() != mrOk)
		return;
	MBTi defl = 0;
	MBTi max = 0;
	switch (Form4->selection)
	{
		case 0:
			if (Form4->value>=0 && Form4->value<obj[select].PolygonsCount)
			{
				TGPolygon &poly = obj[select].FPolygons[Form4->value];
				for (int i=0;i<poly.Count;i++)
				{
					MBTi t = fabs(ScalarP(poly.Normal, poly.GetPoint(i).Point) - ScalarP(poly.Normal, poly.Origin));
					defl += t;
					if (max<t)
						max = t;
				}
			}	
			break;  
		case 1:
			break;	
	}
	InfoMsg("The Total Deflection = " + FloatToStr(defl));
	InfoMsg("The Maximum Deflection = " + FloatToStr(max));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearAllFlags1Click(TObject *Sender)
{
	obj[select].FillPolygonsFlags(flALL, gfFALSE);
	obj[select].FillCutsFlags(flALL, gfFALSE);
	obj[select].FillPointsFlags(flALL, gfFALSE);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FixCuts1Click(TObject *Sender)
{
	obj[select].GeometryFix(gfxPOINTSINCUTS);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResIntop1Click(TObject *Sender)
{
	TGeomObject temp;
	obj[0].SolidObjectsBoolean(gbA_AND_B, obj[1], temp);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SliceByPlaneNoSplit1Click(TObject *Sender)
{
	TIntVec n, o;
	Form3->Caption = "Normal";
	Form3->Default = TIntVec(1,1,1);
	if (Form3->ShowModal() == mrOk)
		n = Form3->Vector;
	else
		return;

	Form3->Caption = MSG_ERR_5;
	Form3->Default = TIntVec(0,0,0);
	if (Form3->ShowModal() == mrOk)
		o = Form3->Vector;
	else
		return;	


	obj[select].SliceByPlaneNoSplit(n, o);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InvertNormals1Click(TObject *Sender)
{
	for (int i=0;i<obj[select].PolygonsCount;i++)		
		obj[select].GetPolygon(i).Invert();
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cut2Click(TObject *Sender)
{
	TIntVec a, b;
	Form3->Caption = "A";
	Form3->Default = TIntVec(-1,-1,0);
	if (Form3->ShowModal() == mrOk)
		a = Form3->Vector;
	else
		return;	

	Form3->Caption = "B";
	Form3->Default = TIntVec(1,1,0);
	if (Form3->ShowModal() == mrOk)
		b = Form3->Vector;
	else
		return;	

	obj[select].AddCut(a, b);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Polygonize1Click(TObject *Sender)
{
	TMTList <TGCut> cuts;
	TMDelTList <TMTList <TGCut> > res;

	for (int i=0;i<obj[select].CutsCount;i++)
		cuts.Add( &obj[select].GetCut(i) );
		
	obj[select].Polygonize2d(cuts, res);
	for (int i=0;i<res.Count;i++)
		obj[select].AddPolygon(res[i]);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Plane1Click(TObject *Sender)
{
	TIntVec n, o, s;

	Form3->Caption = "Rectangle";
	Form3->Default = TIntVec(10,10,0);
	if (Form3->ShowModal() == mrOk)
		s = Form3->Vector;
	else
		return;	

	Form3->Caption = "Normal";
	Form3->Default = TIntVec(1,1,1);
	if (Form3->ShowModal() == mrOk)
		n = Form3->Vector;
	else
		return;	

	Form3->Caption = MSG_ERR_5;
	Form3->Default = TIntVec(0,0,0);
	if (Form3->ShowModal() == mrOk)
		o = Form3->Vector;
	else
		return;	
	PrimitivePlane(&obj[select], s.x, s.y, n, o, coALL);
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GeometryFixCrossCuts1Click(TObject *Sender)
{
	TMTList <TGCut> cuts;

	for (int i=0;i<obj[select].CutsCount;i++)
		cuts.Add( &obj[select].GetCut(i) );

	obj[select].drProcessCrossCuts2d(StatusBar1);

	for (int i=0;i<obj[select].CutsCount;i++)
		for (int j=i+1;j<obj[select].CutsCount;j++)
			if (obj[select].GetCut(i).Equal(obj[select].GetCut(j)))
			{
				obj[select].GetCut(i).Tag = gfTRUE;
				obj[select].GetCut(j).Tag = gfTRUE;
				InfoMsg("NOG!");
			}
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Contourize1Click(TObject *Sender)
{
	TMTList <TGCut> cuts;
	TMTList <TGCut> contour;
	TMDelTList <TMTList <TGCut> > res;

	for (int i=0;i<obj[select].CutsCount;i++)
		cuts.Add( &obj[select].GetCut(i) );

	while(cuts.Count)		
	{
		obj[select].Contourize2d(cuts, contour);
		TMTListSub(cuts, contour);
		obj[select].AddPolygon(contour);
	}
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RemoveBranches1Click(TObject *Sender)
{
	obj[select].StructureFix(sfxREMOVE_BRANCHES | sfxREMOVE_REPEATED);
	obj[select].FreeUnused(fuPoints);
	
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FindBasePoints1Click(TObject *Sender)
{
	if (obj[select].PolygonsCount)
	{	
		TMTList<TGPoint> pnt;
		if (obj[select].GetPolygon(0).FindBasisPoints(pnt))
			for (int i=0;i<pnt.Count;i++)	
				pnt[i].Tag = gfTRUE;
		else
			return;	
		RefreshView();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cuts2Click(TObject *Sender)
{
	obj[select].Clear();
	for (int i=0;i<100;i++)
	{
		TGPoint *a = obj[select].AddPoint(TIntVec(RandomRange(-10000,10000)/500.0, RandomRange(-10000,10000)/500.0, 0));
		TGPoint *b = obj[select].AddPoint(TIntVec(RandomRange(-10000,10000)/500.0, RandomRange(-10000,10000)/500.0, 0));
		if (a!=b)
			obj[select].AddCut(a,b);
	}

	RefreshView();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PolygonizeBridgesRemove1Click(TObject *Sender)
{
	obj[select].StructureFix(sfxREMOVE_BRIDGES_BY_POLYGONIZE);
	obj[select].FreeUnused(fuPoints);
	
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContourizeBridgesRemove1Click(TObject *Sender)
{
	obj[select].StructureFix(sfxREMOVE_BRIDGES_BY_CONTOURIZE);
	obj[select].FreeUnused(fuPoints);
	
	RefreshView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Analytical1Click(TObject *Sender)
{
/*
    long int TmpTicks = GetTickCount();
    TmpTicks = GetTickCount() - TmpTicks;
    TickCount += TmpTicks;
*/
	TickCount1 = 0;
	TickCount2 = 0;
	TickCount3 = 0;
	TickCount4 = 0;
	TickCount5 = 0;
	TickCount6 = 0;
	TickCount7 = 0;
	TGeomObject MyObj;
	MyObj.Assign(&obj[0]);
    long int TmpTicks = GetTickCount();
	obj[0].AnalyticalRenderConveyor(MyObj,StatusBar1);
    TmpTicks = GetTickCount() - TmpTicks;

	AnsiString TmpStr;
	TmpStr.printf("AnalyticalRender\nAll Time: %d\n1: %d\n2: %d\n3: %d\n4: %d\n5: %d\n6: %d\n7: %d\n", TmpTicks, TickCount1, TickCount2, TickCount3, TickCount4, TickCount5, TickCount6, TickCount7);
	ErrorMsg(TmpStr);

	RefreshView();
//    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RotateTimer1Click(TObject *Sender)
{
    if ( Timer1->Enabled )
    {
        Timer1->Enabled = false;
        return;
    }
	Form3->Caption = MSG_4;
	Form3->Default = TIntVec(5,2,0);
	if (Form3->ShowModal() == mrOk)
		Ang = Form3->Vector;
	else
		return;

	TIntVec vec;
	Form3->Caption = "Time interval";
	Form3->Default = TIntVec(3000,0,0);
	if (Form3->ShowModal() == mrOk)
		vec = Form3->Vector;
	else
		return;
    Timer1->Enabled = true;
    Timer1->Interval = vec.x;
    obj[1].Assign(&obj[0]);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//    obj[1].TransformRotate(Ang, ZEROINTVEC);
    obj[1].TransformRotate(TIntVec(random(90), random(90), random(90)), ZEROINTVEC);
	TGeomObject MyObj;
    obj[0].Assign(&obj[1]);
	obj[0].AnalyticalRenderConveyor(MyObj, StatusBar1);
	RefreshView();
}
//---------------------------------------------------------------------------

