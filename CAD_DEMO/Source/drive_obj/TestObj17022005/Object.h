// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ObjectH
#define ObjectH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "VisComp.hpp"
#include "VisMat.hpp"
#include "VisTex.hpp"
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
	TVisTexture *VisTexture1;
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
	TMenuItem *AnalyticalRender1;
    TTimer *Timer1;
	void  FormCreate(TObject *Sender);
	void  Load1Click(TObject *Sender);
	void  Save1Click(TObject *Sender);
	void  Optimize1Click(TObject *Sender);
	void  objClear1Click(TObject *Sender);
	void  objSpiltByPlane1Click(TObject *Sender);
	void  objSliceByPlane1Click(TObject *Sender);
	void  objSolidCheck1Click(TObject *Sender);
	void  obj1Click(TObject *Sender);
	void  Convert1Click(TObject *Sender);
	void  DetectHolesAtAll1Click(TObject *Sender);
	void  RefreshView1Click(TObject *Sender);
	void  CrossCutsAtAll1Click(TObject *Sender);
	void  WeldPointsAtAll1Click(TObject *Sender);
	void  Info1Click(TObject *Sender);
	void  Extrude1Click(TObject *Sender);
	void  Square1Click(TObject *Sender);
	void  Circle1Click(TObject *Sender);
	void  Ring1Click(TObject *Sender);
	void  HoledRing1Click(TObject *Sender);
	void  SyncronizePolygonsWises1Click(TObject *Sender);
	void  Triangulate1Click(TObject *Sender);
	void  HoledXRing1Click(TObject *Sender);
	void  CalculateNormals1Click(TObject *Sender);
	void  Rotate1Click(TObject *Sender);
	void  N11Click(TObject *Sender);
	void  N21Click(TObject *Sender);
	void  AB1Click(TObject *Sender);
	void  AB2Click(TObject *Sender);
	void  BA1Click(TObject *Sender);
	void  AB3Click(TObject *Sender);
	void  Clear1Click(TObject *Sender);
	void  Move1Click(TObject *Sender);
	void  Points1Click(TObject *Sender);
	void  Cuts1Click(TObject *Sender);
	void  Polygons1Click(TObject *Sender);
	void  Normals1Click(TObject *Sender);
	void  Holes1Click(TObject *Sender);
	void  ScaleTo1Click(TObject *Sender);
	void  FreeUnused1Click(TObject *Sender);
	void  Pyramid1Click(TObject *Sender);
	void  Point1Click(TObject *Sender);
	void  Mark2Click(TObject *Sender);
	void  Classify1Click(TObject *Sender);
	void  Error1Click(TObject *Sender);
	void  Smooth1Click(TObject *Sender);
	void  Color1Click(TObject *Sender);
	void  Cut1Click(TObject *Sender);
	void  Polygon1Click(TObject *Sender);
	void  ClearMarks1Click(TObject *Sender);
	void  SavePolygonAsFigure1Click(TObject *Sender);
	void  SaveObjectAsFigure1Click(TObject *Sender);
	void  PolygonPlaceOnPlane1Click(TObject *Sender);
	void  TransformToPlane1Click(TObject *Sender);
	void  AnalyticalRender1Click(TObject *Sender);
    void  Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TVisPrimitiveObj* VCO;
	 TForm1(TComponent* Owner);
	void CustomRender(TVisView* aView);
	void ConstructVCO(TGeomObject* GO, TConstructFlags co);
	void ConstructVCO();
	void RefreshView();
	void EdMoMo(TObject *sender, TShiftState s, int a, int b);
};
//---------------------------------------------------------------------------
extern  TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

