//---------------------------------------------------------------------------

#ifndef TGAAnRenderH
#define TGAAnRenderH
//---------------------------------------------------------------------------

#include "types.h"
class TGPolygon;
class TGAAnRender : public TGAlgorithm
{
private:
	void DeleteBackFace();
    void ProjectToXY();
    void TextToSB(AnsiString str);
	bool EqualPolygonInds(int IndP, TMDelTList<int>& TmpInds);
	bool TestPolygon(TMDelTList<int>& TmpInds, TMDelTList< TMDelTList<int> >& PolysInd);

public:

	TGAAnRender(TGeomObject &o, TStatusBar* _SB) : TGAlgorithm(o), SB(_SB){};

	TStatusBar* SB;
	void AnalyticalRender();
	void operator()();

	void drProcessCrossCuts2d();
	bool drConsistsPoint(const TGPoint& Point, const TGCut& Cut) const;
	bool drSplitCut(TGCut *c, TGPoint *&newPnt, TGCut *&Result1, TGCut *&Result2);
	bool SplitCutForCrossedCuts(TMTList<TGCut>& aCuts, TGCut *&c, TGPoint *&Pnt, TMTList<TGCut>& CutsConveyor);
	bool drProcessCrossCuts2d(TMTList<TGCut>& aCuts);
	void AddPolygonToCeilsUseHoles(TGPolygon* p, TMTList<TGPolygon>& Conveyor, TMTList<TGPolygon>& Ceils);
	bool IntersectPolygonsUseHoles( TGPolygon* p1, TGPolygon* p2, TMTList<TGPolygon> &POnlyp1, TMTList<TGPolygon> &PSplit, TMTList<TGPolygon> &POnlyp2);
	bool ExistsPolygonInPolygonUseHoles2(TMTList<TGCut>& cuts, TGPolygon& PolygonUseHole, bool UseHoles);
    TIntVec GetPointInPolygon2d(TGPolygon* p);
    TIntVec GetPointInPolygon2d(TMTList<TGCut>& cuts);
    TGPoint& drGetPoint(int index, TMTList<TGCut>& cuts);
    void ConstructPolygonsFromHoles( TGPolygon& p, TMTList<TGPolygon>& poly);
/*
    void MarkCuts(TMTList<TGCut>& cuts);
    void MarkPolygonCuts(TGPolygon* p);
    bool EqualCuts(TMTList<TGCut>& Cuts1, TMTList<TGCut>& Cuts2);
    void PolygonTriangulate(TGPolygon* p, TMTList<TGPolygon>& poly);//??????????? ? ?????????
    void evlProcessCrossCuts2D(TMTList<TGCut>& Cuts);
    TGPoint& drGetPoint(int index, TMTList<TGCut>& cuts);
	TIntVec PointInPolygon(TGPolygon* p);
    TIntVec GetPointInPolygon2d(TGPolygon* p);
	TIntVec GetPointInPolygon2d(TMTList<TGCut>& cuts);
    TIntVec GetPointInPolygonUseHoles(TGPolygon* p);
	TIntVec GetPointInPolygonUseHoles2d(TGPolygon* p);
    int  drPointInPolygon_UseHoles2d( TGPolygon* p, const TIntVec &Point, MBTi USEEPS, TGPolygon*& Hole);
    void ConstructPolygonsFromHoles( TGPolygon& p, TMTList<TGPolygon>& poly);
    bool ConditionForTag(TGCut *cut, TGPolygon *p1, TGPolygon *p2);
	bool ConditionForTagAndHole(TGCut *cut, TGPolygon *p1, TGPolygon *p2);
    bool ConditionForSmooth(TGCut *cut, TGPolygon *p1, TGPolygon *p2);
    void PassByObject(TGPolygon *p, TConditionForPass& ConditionForPass);
	int  FindCeilForPolygon(TGPolygon *p, TMDelTList< TMTList<TGPolygon> >& Ceils);
    bool EqualPolygonInds(TGeomObject &obj, int IndP, TMDelTList<int>& TmpInds);
    bool TestPolygon(TMDelTList<int>& TmpInds, TMDelTList< TMDelTList<int> >& PolysInd);
    void ProjectToXY(TGeomObject &obj, TStatusBar* SB);
    bool IntersectPolygons2DPoly2( TGPolygon* p1, TGPolygon* p2, TMDelTList< TMTList<TGCut> > &Onlyp1, TMDelTList< TMTList<TGCut> > &Split, TMDelTList< TMTList<TGCut> > &Onlyp2);
	bool IntersectPolygonsUseHoles( TGPolygon* p1, TGPolygon* p2, TMTList<TGPolygon> &POnlyp1, TMTList<TGPolygon> &PSplit, TMTList<TGPolygon> &POnlyp2);
    bool SplitCutForCrossedCuts(TMTList<TGCut>& aCuts, TGCut *&c, TGPoint *&Pnt, TMTList<TGCut>& CutsConveyor);
    void AnalyticalRenderConveyor(TGeomObject& obj, TStatusBar* SB);

    void GetCeilsGroup(TGPolygon& p, TMTList<TGPolygon>& Poly);
	void GetSmoothGroupForAnRen(TGPolygon& p, TMTList<TGPolygon>& Poly);
    void AddPolygonToCeils(TGPolygon* p, TGeomObject& obj, TMTList<TGPolygon>& Conveyor, TMTList<TGPolygon>& Ceils);
    void AddPolygonToCeilsUseHoles(TGPolygon* p, TGeomObject& obj, TMTList<TGPolygon>& Conveyor, TMTList<TGPolygon>& Ceils);
    bool ExistsPolygonInPolygon(TMTList<TGCut>& cuts, const TGPolygon& Polygon);
    bool ExistsPolygonInPolygonUseHoles(TMTList<TGCut>& cuts, TGPolygon& PolygonUseHole, bool DifferentHoles);
    bool ExistsPolygonInPolygonUseHoles2(TMTList<TGCut>& cuts, TGPolygon& PolygonUseHole, bool UseHoles);
	void DeleteBackFace();
	bool drPolygonize(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly);
    void DeleteBranches(TMTList<TGCut> &cuts);
    void drProcessCrossCuts2d(TStatusBar* SB);
	bool drProcessCrossCuts2d(TMTList<TGCut>& aCuts, TStatusBar* SB);
	bool drConsistsPoint(const TGPoint& Point, const TGCut& Cut) const;					// ?????????? ?????
	bool drSplitCut(TGCut *c, TGPoint *&newPnt, TGCut *&Result1, TGCut *&Result2);


	void Triangulate2();
    void ShiftVecCompToXY(TIntVec& Vec, int CompNum);
    void ShiftVecCompFromXY(TIntVec& Vec, int CompNum, MBTi VecComp);
	void Triangulate3(TGeomObject& obj);
    void ConstructVCO(TVisPrimitiveObj* VCO, TConstructFlags co, TRenderType render, TGeomObject& obj);
	void GetSmoothGroup(TGPoint* Pnt, int CutIndex, TMTList<TGPolygon>& Poly);
	void GetSmoothGroup2(TGPoint* Pnt, int CutIndex, int CurGroupInd, TMTList<TGPolygon>& Poly, TLList< TLList<int> >& FastPointDetect);
	void ScaleTo(MBTi maxSize);
	TGCut *ExistsCutFast( TGPoint& p1, TGPoint& p2 );
	TGCut *AddCutFast(TGPoint *p1, TGPoint *p2);
	TGCut *AddCutFast(TIntVec p1, TIntVec p2);
	TGCut *AddCutFast(const TGCut &c);
    TGPolygon *AddPolygonForTriangulate(TMTList<TGCut> &cuts, const TIntVec &nrm);
	void ToPrimitiveObj2(TVisPrimitiveObj *VCO, TConstructFlags co, TRenderType render);
	void SaveTwoPolygonAsFigure(int ind1, int ind2, AnsiString &name);
*/
};

#endif
