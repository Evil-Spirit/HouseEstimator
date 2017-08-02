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
#include <Math.h>
//#include "MyImportV.h"
#include "Convert.h"
#include "VecForm.h"
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
enum TRenderType
{
	rtCLASSIFY,
	rtERROR,
	rtSMOOTH,
	rtCOLOR,
	rtMARK
};
TForm1 *Form1;
TGeomObject obj[2];
TConstructFlags construct = coALL;
TRenderType render = rtMARK;
int select = 0;
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
}
//---------------------------------------------------------------------------

/*void TForm1::EdMoMo(TObject *sender, TShiftState Shift, int x, int y)
{
	if ( !Shift.Contains(ssCtrl) )
		return;
	TPoint p;
	GetCursorPos(&p);
	p = MyView->ScreenToClient(p);
	TIntVec pos;
	pos.x = p.x;
	pos.y = p.y;
	pos = MyView->ScreenToProject(pos);
	obj[1].Clear();
//	PrimitiveHoledRing(&obj[1], 4,5,6);
//	PrimitiveSquare(&obj[1], 10,10);
	PrimitivePyramid(&obj[1], 10,10,5);
//	obj[1].Extrude(TIntVec(0,0,5));
	obj[1].TransformTranslate(pos);
	TGeomObject a,b,c;
	a.Assign(&obj[0]);
	b.Assign(&obj[1]);
	a.SolidObjectsBoolean(gbA_MINUS_B,b,c);
	VCO->Init();
	a.Triangulate2();
	ConstructVCO(&a,construct);
//	ConstructVCO(&b,construct);
	ConstructVCO(&b,coWIRE);
//	obj[select].AddPoint(pos);
//	RefreshView();
	MyView->View->RenderScene();
}*/

/*void TForm1::EdMoMo(TObject *sender, TShiftState Shift, int x, int y)
{
	if ( !Shift.Contains(ssCtrl) )
		return;
	TPoint p;
	GetCursorPos(&p);
	p = MyView->ScreenToClient(p);
	TIntVec pos;
	pos.x = p.x;
	pos.y = p.y;
	pos = MyView->ScreenToProject(pos);
	TGeomObject a;
	a.Assign(&obj[0]);
	a.SliceByPlane(TIntVec(1,1,1), pos);
//	a.SplitByPlane(TIntVec(1,1,1), pos);
	VCO->Init();
	obj[1].Assign(&a);
	a.Triangulate2();
	ConstructVCO(&a,construct);
	MyView->View->RenderScene();
}*/

/*void TForm1::EdMoMo(TObject *sender, TShiftState Shift, int x, int y)
{
	if ( !Shift.Contains(ssCtrl) )
		return;
	TPoint p;
	GetCursorPos(&p);
	p = MyView->ScreenToClient(p);
	TIntVec pos;
	pos.x = p.x;
	pos.y = p.y;
	pos = MyView->ScreenToProject(pos);
	obj[0].Clear();
	obj[1].Clear();
//	PrimitiveHoledRing(&obj[1], 4,5,6);
	PrimitiveHoledRing(&obj[0], 8, 10, 14);
	TMTList<int> Poly;
	for (int i = 0; i < obj[0].CutsCount; i++ )
		Poly.Add(new int(i));
	obj[0].AddPolygon(Poly);
	PrimitiveSquare(&obj[1], 8,10);
	Poly.Clear();
	for (int i = 0; i < obj[1].CutsCount; i++ )
		Poly.Add(new int(i));
	obj[1].AddPolygon(Poly);
//	PrimitivePyramid(&obj[1], 10,10,5);
//	obj[1].Extrude(TIntVec(0,0,5));
	obj[1].TransformTranslate(pos);

	TMTList<TGCut> CS;
	for (int i = 0; i < obj[1].CutsCount; i++ )
		CS.Add(obj[0].AddCut(obj[1].GetCut(i)));
	obj[0].AddPolygon(CS);

	obj[1].Clear();
	obj[0].drProcessCrossCuts2D(Form1->StatusBar1);
//	a.SolidObjectsBoolean(gbA_MINUS_B,b,c);
	VCO->Init();
//	a.Triangulate2();
//	ConstructVCO(&obj[0],coWIRE);
//	ConstructVCO(&b,construct);
//	ConstructVCO(&b,construct);
//	ConstructVCO(&b,coWIRE);
//	obj[select].AddPoint(pos);
	RefreshView();
//	MyView->View->RenderScene();
}*/

void TForm1::EdMoMo(TObject *sender, TShiftState Shift, int x, int y)
{
	if ( !Shift.Contains(ssShift) )
		return;
	TPoint p;
	GetCursorPos(&p);
	p = MyView->ScreenToClient(p);
	TIntVec pos;
	pos.x = p.x;
	pos.y = p.y;
	pos = MyView->ScreenToProject(pos);
    for ( int i = 0; i < obj[0].FPolygons.Count; i++ )
    {
        TIntVec Vec;
//        PlaneAndLineCrossed(obj[0].FPolygons[i].Origin, obj[0].FPolygons[i].Normal, pos + TIntVec(0, 0, -1000), pos + TIntVec(0, 0, 1000), false, false, Vec, 0.000001);
    }
	VCO->Init();
	RefreshView();
}

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
//					VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
					VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = 0xFFFFFF;
					VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmDiffuse;
//					VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = colors[GO->GetPolygon(i).Tag % 6];
					break;
				case rtMARK :
					VCO->Primitive[VCO->PrimitiveCount-1]->Material =
						  (POL.Tag == gfTRUE)
						? MaterialMark  
						: PolygonMaterial;
					break;
				}
						
				TMDelTList<TIntVec> tris;
				Triangulate_(&POL, tris);
				TIntVec Normal = POL.Normal;
				for (int j=0;j<tris.Count;j++)
					VCO->AddIndex( VCO->Points->Add( VisMathVec(tris[j]+TIntVec(0,0,0)), VisMathVec(Normal),ZEROVEC ),VCO->PrimitiveCount-1 );
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
				TMDelTList<TIntVec> tris;
				Triangulate_(&POL, tris);
				TIntVec Normal = POL.Normal;
				for (int j=0;j<tris.Count;j++)
					VCO->AddIndex( VCO->Points->Add( VisMathVec(tris[j]), VisMathVec(Normal),ZEROVEC ),VCO->PrimitiveCount-1 );
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
			VCO->AddIndex(VCO->Points->Add( VisMathVec(GO->GetCut(i).Src->Point+TIntVec(0, 0, 0)), ZEROVEC,ZEROVEC ),VCO->PrimitiveCount-1);
			VCO->AddIndex(VCO->Points->Add( VisMathVec(GO->GetCut(i).Dst->Point+TIntVec(0, 0, 0)), ZEROVEC,ZEROVEC ), VCO->PrimitiveCount-1);
			switch (render)
			{
			case rtCLASSIFY:
				VCO->Primitive[VCO->PrimitiveCount-1]->Material = 
					  (GO->GetCut(i).Flags.Origin == gfPOSITIVE)
					? MaterialRight  
					: (GO->GetCut(i).Flags.Origin == gfNEGATIVE)
					? MaterialLeft
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
					  (GO->GetCut(i).Tag == gfTRUE)
					? MaterialMark
					: MaterialOther;
				break;
			case rtCOLOR:
//				VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmAmbient;
				VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = 0xFFFFFF;
				VCO->Primitive[VCO->PrimitiveCount-1]->ColorAsMaterial = cmDiffuse;
//				VCO->Primitive[VCO->PrimitiveCount-1]->Color->Color = colors[i % 6];
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
//VCO->CalcNormals();	 	
}

MBTi Epsilon1 = PEPS;
MBTi Epsilon2 = CEPS;
MBTi Epsilon3 = PEPS;

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	VCO->Init();
}
//---------------------------------------------------------------------------
int Angle = 0;
void TForm1::RefreshView()
{
	VCO->Init();
/*    for ( int i = 0; i < obj[0].CutsCount; i++ )
        obj[0].GetCut(i).Smooth = true;

    for ( int i = 0; i < obj[0].GetPolygon(0).Count; i++ )
        obj[0].GetPolygon(0).FCuts[i].Smooth = false;
    for ( int i = 0; i < obj[0].GetPolygon(obj[0].PolygonsCount-1).Count; i++ )
        obj[0].GetPolygon(obj[0].PolygonsCount-1).FCuts[i].Smooth = false;*/

/*	obj[0].TransformRotate(TIntVec(5,2,0), TIntVec(0, 0, 0));
    obj[1].Assign(&obj[0]);
	TGeomObject MyObj;
	MyObj.Assign(&obj[1]);
	obj[1].AnalyticalRenderConveyor(MyObj, Form1->StatusBar1 );*/
	TGeomObject MyObj;
//	MyObj.Assign(&obj[0]);
//	MyObj.ToPrimitiveObj2(VCO, construct);
//    obj[0].AnalyticalRenderObj(MyObj);
//    MyObj.FPolygons.Delete(1);
	ConstructVCO(&obj[0], construct);
	ConstructVCO(&obj[1], construct);
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
			Epsilon2 = CEPS; Form2->Edit2->Text = FloatToStr(CEPS);InfoMsg("Incorrect input");
		}

		if (IS_FLOAT(Form2->Edit3->Text))
		{
			Epsilon3 = StrToMBTi(Form2->Edit3->Text);
		}
		else
		{
			Epsilon3 = PEPS; Form2->Edit3->Text = FloatToStr(PEPS);InfoMsg("Incorrect input");
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
	TIntVec o,n;
	Form3->Caption = "Angles";
	Form3->Default = TIntVec(45,0,0);
	if (Form3->ShowModal() == mrOk)
		n = Form3->Vector;
	else
		return;

	Form3->Caption = MSG_3;
	Form3->Default = TIntVec(0,0,5);
	if (Form3->ShowModal() == mrOk)
		o = Form3->Vector;
	else
		return;

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
	int start = GetTickCount();
	TGeomObject temp;
	obj[0].SolidObjectsBoolean(gbA_MINUS_B, obj[1], temp);
/**///	obj[1].Clear();
/**///	obj[0].Assign(&temp);
//	InfoMsg("Elapsed time: "+MBTiToStr((MBTi)(GetTickCount()-start)/1000)+" sec.");
	InfoMsg("Elapsed Transformation time: "+IntToStr(TimeForTransform)+
			"\nElapsed Intersection time :"+IntToStr(TimeForIntersect)+
			"\nElapsed Detection time :"+IntToStr(TimeForDetect)+
			"\nElapsed Other time :"+IntToStr(TimeTotal - TimeForTransform - TimeForIntersect - TimeForDetect)+
			"\nElapsed Total time :"+IntToStr(TimeTotal));
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
	if (Form3->ShowModal() != mrOk)
		return;
	switch (0)
	{
		case 0:
			if (Form3->EditX->Text.ToInt() >= 0 && Form3->EditX->Text.ToInt() < obj[select].PolygonsCount &&
                Form3->EditY->Text.ToInt() >= 0 && Form3->EditY->Text.ToInt() < obj[select].PolygonsCount)
			{
//				obj[select].SavePolygonAsFigure(Form4->value, "C:\\Config_\\BIN\\Attributes\\Figures.gob");
				obj[select].SaveTwoPolygonAsFigure(Form3->EditX->Text.ToInt(), Form3->EditY->Text.ToInt(), "C:\\Config_\\BIN\\Attributes\\Figures.gob");
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
				oj.Write("C:\\DriveNoDel\\Config_ на drive\\BIN\\Attributes\\Figures.imp");
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
//obj.SavePolygonAsFigure(1, AnsiString("C:\\(WORK)\\Config_\\BIN\\Attributes\\Figures.imp"))

void __fastcall TForm1::AnalyticalRender1Click(TObject *Sender)
{
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

    for ( int i = 0; i < obj[0].FPolygons.Count; i++ )
    {
        TGPoint* TmpPoint = obj[0].AddPoint( obj[0].PointInPolygonUseHoles(obj[0].FPolygons.Items[i]) );
        TmpPoint->Tag = gfTRUE;
    }
//    TGPoint* TmpPoint = MyObj.AddPoint( MyObj.PointInPolygon(MyObj.FPolygons.Items[11]) );
  //  TmpPoint->Tag = gfTRUE;
    TmpTicks = GetTickCount() - TmpTicks;
	TickCount1 += TmpTicks;

	AnsiString TmpStr;
	TmpStr.printf("AnalyticalRender\nAll Time: %d\n1: %d\n2: %d\n3: %d\n4: %d\n5: %d\n", TickCount1, TickCount2, TickCount3, TickCount4, TickCount5, TickCount6);
	ErrorMsg(TmpStr);
    
	RefreshView();
 //   Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    RefreshView();
}
//---------------------------------------------------------------------------

