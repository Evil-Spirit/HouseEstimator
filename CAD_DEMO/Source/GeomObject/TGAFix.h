//---------------------------------------------------------------------------

#ifndef TGAFixH
#define TGAFixH
//---------------------------------------------------------------------------

#include "types.h"

class TGPolygon;

class COMMONAL_API TGAFix : public TGAlgorithm
{
	void SynchronizeNormalsRecursive(TGPolygon *p);

public:

	TGAFix(TGeomObject &o) : TGAlgorithm(o){};

	bool Branches(TMTList<TGCut> &cuts);
	bool Repeated(TMTList<TGCut> &cuts, bool atall = false);
	bool BridgesByPolygonize(TMTList<TGCut> &cuts);
	bool BridgesByContourize(TMTList<TGCut> &cuts);
	bool Unused(TGeomPrimitiveType what);
	void SynchronizeNormals(TGPolygon *p = NULL);
};

#endif

