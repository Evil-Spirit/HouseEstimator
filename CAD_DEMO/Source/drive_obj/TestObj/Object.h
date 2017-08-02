//---------------------------------------------------------------------------

#ifndef ObjectH
#define ObjectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "VisComp.hpp"
#include "VisMat.hpp"
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include "VisTex.hpp"
#include <ExtCtrls.hpp>
class TGeomObject;
#include "GeomObjV.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TVisMaterial *PointMaterial;
	TVisMaterial *MaterialOther;
	TVisMaterial *PolygonMaterial;
	TVisMaterial *MaterialLeft;
	TVisMaterial *MaterialRight;
	TVisMaterial *MaterialItr;
	TVisMaterial *MaterialPolyLeft;
	TVisMaterial *MaterialPolyRight;
	TMainMenu *MainMenu1;
	TMenuItem *Object1;
	TMenuItem *Load1;
	TMenuItem *Save1;
	TMenuItem *Operation1;
	TMenuItem *Optimize1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMenuItem *objClear1;
	TMenuItem *objSpiltByPlane1;
	TMenuItem *objSliceByPlane1;
	TMenuItem *objSolidCheck1;
	TMenuItem *obj1;
	TOpenDialog *OpenDialog2;
	TMenuItem *Convert1;
	TStatusBar *StatusBar1;
	TMenuItem *DetectHolesAtAll1;
	TMenuItem *RefreshView1;
	TMenuItem *CrossCutsAtAll1;
	TMenuItem *WeldPointsAtAll1;
	TMenuItem *Info1;
	TMenuItem *Create1;
	TMenuItem *Extrude1;
	TMenuItem *Primitive1;
	TMenuItem *Square1;
	TMenuItem *Circle1;
	TMenuItem *Ring1;
	TMenuItem *HoledRing1;
	TMenuItem *Rotate1;
	TMenuItem *Move1;
	TMenuItem *SyncronizePolygonsWises1;
	TMenuItem *Triangulate1;
	TMenuItem *HoledXRing1;
	TMenuItem *CalculateNormals1;
	TMenuItem *Object2;
	TMenuItem *N11;
	TMenuItem *N21;
	TMenuItem *Boolean1;
	TMenuItem *AB1;
	TMenuItem *AB2;
	TMenuItem *BA1;
	TMenuItem *AB3;
	TMenuItem *Clear1;
	TMenuItem *Render1;
	TMenuItem *Points1;
	TMenuItem *Cuts1;
	TMenuItem *Polygons1;
	TMenuItem *Normals1;
	TVisMaterial *HoleMaterial;
	TMenuItem *Holes1;
	TVisMaterial *MaterialMark;
	TMenuItem *ScaleTo1;
	TMenuItem *FreeUnused1;
	TMenuItem *Pyramid1;
	TMenuItem *Mark1;
	TMenuItem *Point1;
	TMenuItem *Cut1;
	TMenuItem *Polygon1;
	TMenuItem *fg1;
	TMenuItem *Mark2;
	TMenuItem *Classify1;
	TMenuItem *Error1;
	TMenuItem *Smooth1;
	TMenuItem *Color1;
	TMenuItem *ClearMarks1;
	TMenuItem *SavePolygonAsFigure1;
	TMenuItem *SaveObjectAsFigure1;
	TMenuItem *PolygonPlaceOnPlane1;
	TMenuItem *TransformToPlane1;
	TMenuItem *CalculateZEps1;
	TMenuItem *CalculateDeflection1;
	TMenuItem *ClearAllFlags1;
	TVisMaterial *MaterialBorder;
	TMenuItem *ResIntop1;
	TMenuItem *SliceByPlaneNoSplit1;
	TMenuItem *InvertNormals1;
	TMenuItem *Cut2;
	TMenuItem *Polygonize1;
	TMenuItem *Plane1;
	TMenuItem *GeometryFixCrossCuts1;
	TMenuItem *Contourize1;
	TMenuItem *RemoveBranches1;
	TMenuItem *FindBasePoints1;
	TMenuItem *Random1;
	TMenuItem *Cuts2;
	TMenuItem *PolygonizeBridgesRemove1;
	TMenuItem *ContourizeBridgesRemove1;
    TMenuItem *Analytical1;
    TMenuItem *RotateTimer1;
    TTimer *Timer1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Load1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall Optimize1Click(TObject *Sender);
	void __fastcall objClear1Click(TObject *Sender);
	void __fastcall objSpiltByPlane1Click(TObject *Sender);
	void __fastcall objSliceByPlane1Click(TObject *Sender);
	void __fastcall objSolidCheck1Click(TObject *Sender);
	void __fastcall obj1Click(TObject *Sender);
	void __fastcall Convert1Click(TObject *Sender);
	void __fastcall DetectHolesAtAll1Click(TObject *Sender);
	void __fastcall RefreshView1Click(TObject *Sender);
	void __fastcall CrossCutsAtAll1Click(TObject *Sender);
	void __fastcall WeldPointsAtAll1Click(TObject *Sender);
	void __fastcall Info1Click(TObject *Sender);
	void __fastcall Extrude1Click(TObject *Sender);
	void __fastcall Square1Click(TObject *Sender);
	void __fastcall Circle1Click(TObject *Sender);
	void __fastcall Ring1Click(TObject *Sender);
	void __fastcall HoledRing1Click(TObject *Sender);
	void __fastcall SyncronizePolygonsWises1Click(TObject *Sender);
	void __fastcall Triangulate1Click(TObject *Sender);
	void __fastcall HoledXRing1Click(TObject *Sender);
	void __fastcall CalculateNormals1Click(TObject *Sender);
	void __fastcall Rotate1Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N21Click(TObject *Sender);
	void __fastcall AB1Click(TObject *Sender);
	void __fastcall AB2Click(TObject *Sender);
	void __fastcall BA1Click(TObject *Sender);
	void __fastcall AB3Click(TObject *Sender);
	void __fastcall Clear1Click(TObject *Sender);
	void __fastcall Move1Click(TObject *Sender);
	void __fastcall Points1Click(TObject *Sender);
	void __fastcall Cuts1Click(TObject *Sender);
	void __fastcall Polygons1Click(TObject *Sender);
	void __fastcall Normals1Click(TObject *Sender);
	void __fastcall Holes1Click(TObject *Sender);
	void __fastcall ScaleTo1Click(TObject *Sender);
	void __fastcall FreeUnused1Click(TObject *Sender);
	void __fastcall Pyramid1Click(TObject *Sender);
	void __fastcall Point1Click(TObject *Sender);
	void __fastcall Mark2Click(TObject *Sender);
	void __fastcall Classify1Click(TObject *Sender);
	void __fastcall Error1Click(TObject *Sender);
	void __fastcall Smooth1Click(TObject *Sender);
	void __fastcall Color1Click(TObject *Sender);
	void __fastcall Cut1Click(TObject *Sender);
	void __fastcall Polygon1Click(TObject *Sender);
	void __fastcall ClearMarks1Click(TObject *Sender);
	void __fastcall SavePolygonAsFigure1Click(TObject *Sender);
	void __fastcall SaveObjectAsFigure1Click(TObject *Sender);
	void __fastcall PolygonPlaceOnPlane1Click(TObject *Sender);
	void __fastcall TransformToPlane1Click(TObject *Sender);
	void __fastcall CalculateZEps1Click(TObject *Sender);
	void __fastcall CalculateDeflection1Click(TObject *Sender);
	void __fastcall ClearAllFlags1Click(TObject *Sender);
	void __fastcall FixCuts1Click(TObject *Sender);
	void __fastcall ResIntop1Click(TObject *Sender);
	void __fastcall SliceByPlaneNoSplit1Click(TObject *Sender);
	void __fastcall InvertNormals1Click(TObject *Sender);
	void __fastcall Cut2Click(TObject *Sender);
	void __fastcall Polygonize1Click(TObject *Sender);
	void __fastcall Plane1Click(TObject *Sender);
	void __fastcall GeometryFixCrossCuts1Click(TObject *Sender);
	void __fastcall Contourize1Click(TObject *Sender);
	void __fastcall RemoveBranches1Click(TObject *Sender);
	void __fastcall FindBasePoints1Click(TObject *Sender);
	void __fastcall Cuts2Click(TObject *Sender);
	void __fastcall PolygonizeBridgesRemove1Click(TObject *Sender);
	void __fastcall ContourizeBridgesRemove1Click(TObject *Sender);
    void __fastcall Analytical1Click(TObject *Sender);
    void __fastcall RotateTimer1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TVisPrimitiveObj* VCO;
	__fastcall TForm1(TComponent* Owner);
	void CustomRender(TVisView* aView);
	void ConstructVCO(TGeomObject* GO, TConstructFlags co);
	void ConstructVCO();
	void RefreshView();
	void EdMoMo(TObject *sender, TShiftState s, int a, int b);
	TIntVec o,n;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

