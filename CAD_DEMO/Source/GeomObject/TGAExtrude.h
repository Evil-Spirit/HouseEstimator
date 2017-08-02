//---------------------------------------------------------------------------

#ifndef TGAExtrudeH
#define TGAExtrudeH
//---------------------------------------------------------------------------

#include "types.h"

class TGPolygon;

class COMMONAL_API TGAExtrude : public TGAlgorithm
{
public:

	TGAExtrude(TGeomObject &o) : TGAlgorithm(o){};

	TGPoint *Point(TGPoint *p, const TIntVec& d);
	TGPoint *Point(int index, const TIntVec& d);

	TGCut *Cut(TGCut *c, const TIntVec& d, bool inv = false);
	TGCut *Cut(int index, const TIntVec& d, bool inv = false);

	void Polygon(TGPolygon *p, const TIntVec& d);
	void Polygon(int index, const TIntVec& d);

	void Object(const TIntVec& d);
	void operator()(const TIntVec& d);	
};

#endif



