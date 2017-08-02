//---------------------------------------------------------------------------

#ifndef TGATriangulationH
#define TGATriangulationH
//---------------------------------------------------------------------------


class TGeomObject;

#include "TGPoint.h"
#include "TGCut.h"
#include "TGPolygon.h"

class COMMONAL_API TGATriangulate {
private:
public:
	MBTi EPS;
	TGeomObject& GObj;
//    TGATriangulate(){EPS = 0.0001;};
	TGATriangulate(TGeomObject& _GObj):GObj(_GObj){EPS = 0.0000001;};
	virtual ~TGATriangulate(){};
	TMTList<TGCut> CutsBuild;
	TMTList<TGPoint> FVertex;
	TMTList<TGCut> FCuts;
	TMTList<TGCut> Triangles;

	TGCut* ExistsCutIn_CutsBuild( TGPoint* p1,  TGPoint* p2 );
	TGCut* ExistsCutIn_FCuts( TGPoint* p1,  TGPoint* p2 );
	TGCut* ExistsCutIn_GObjFCuts( TGCut* cut );
	TGCut* AddCut(TGPoint* p1, TGPoint* p2);
	TGCut* NewCut(TGPoint* p1, TGPoint* p2);

	void MergePolygon(TGPolygon* P);
	int classify(TIntVec& p2,TIntVec &p0, TIntVec &p1);
	void Find2BasePoints(TGPoint*& pnt1, TGPoint*& pnt2);
	bool FindDeloneBrother(TGPoint* pnt1, TGPoint* pnt2);
	bool SimpleIntersection(TIntVec& aSrc, TIntVec& aDst, TIntVec& bSrc, TIntVec& bDst);
/*	bool SimpleIntersection2(TIntVec& aSrc, TIntVec& aDst, TGCut& b);
	bool SimpleIntersection3(TGCut& a, TGCut& b);*/
	bool CheckSimpleCrossing(TGPoint& a, TGPoint& b, TGPoint& c);
	bool CheckBldCrossing(TGPoint& a, TGPoint& b, TGPoint& c);
	void TriangulateByPoints();
	TMTList<TGCut>* Triangulate(TGPolygon *p);
	void TGATriangulate::Triangulate();

};


#endif
