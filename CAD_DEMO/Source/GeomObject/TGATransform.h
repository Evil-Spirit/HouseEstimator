//---------------------------------------------------------------------------

#ifndef TGATransformH
#define TGATransformH
//---------------------------------------------------------------------------

#include "types.h"

class TGPolygon;

class COMMONAL_API TGATransform : public TGAlgorithm
{
public:

	TGATransform(TGeomObject &o) : TGAlgorithm(o){};

	void Rotate(const TIntVec &angle, const TIntVec &center);

	void Translate(const TIntVec &delta);
	void Translate(TMTList<TMyObject> &what, const TIntVec &delta);
	
	void Scale(const TIntVec &ratio);

	void ToPlaneAndOX(TMTList<TMyObject> &what, const TIntVec& Normal, const TIntVec& n);
	void ToPlane(TMTList<TMyObject> &what, const TIntVec& n);

};

#endif



