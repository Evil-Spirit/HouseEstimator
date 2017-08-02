//---------------------------------------------------------------------------

#ifndef TGASliceH
#define TGASliceH
//---------------------------------------------------------------------------

#include "types.h"

class TGPolygon;

enum TSliceType
{
	slREMOVE_POSITIVE,
	slREMOVE_NEGATIVE,
	slSPLIT
};

class COMMONAL_API TGASlice : public TGAlgorithm
{
	void Split(const TIntVec &n, const TIntVec &o);
public:

	TGASlice(TGeomObject &o) : TGAlgorithm(o){};

	bool PlanePolygonIntersect(const TIntVec &n, const TIntVec &o, TGPolygon *p, TMTList <TGPoint> &cps);
	void SplitPolygonByPlane(TGPolygon *p, const TIntVec& n, const TIntVec& o, TMTList<TGPolygon> &Result);

	void ByPlane(const TIntVec &n, const TIntVec &o, TSliceType t);
	void operator()(const TIntVec &n, const TIntVec &o, TSliceType t);

	TGPoint *CrossCutOX(TGCut &cut, MBTi EPS);
	void TransfixPolygonOX(TGPolygon *p, TMTList<TGCut> &Result);

	
};

#endif

