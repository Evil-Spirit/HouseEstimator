//---------------------------------------------------------------------------

#ifndef TGABooleanH
#define TGABooleanH
//---------------------------------------------------------------------------

#include "Types.h"

class TGPolygon;
class TGIntPoint;
class TGIntCut;

class COMMONAL_API TGABoolean/* : public TGAlgorithm*/
{
	TGeomObject &go;
public:	
	TGABoolean(TGeomObject &obj) : go(obj) {};

	bool PlanePolygonIntersect(TGPolygon *plane, TGPolygon *p, TMDelTList <TGIntPoint> &cps);
	bool IntersectPolygons(TGPolygon *p1, TGPolygon *p2, TMDelTList <TGIntCut> &r1, TMDelTList <TGIntCut> &r2, TMDelTList <TGIntPoint> &pnt_);

	void Operation(TGBoolean op, TGeomObject &obj, TGeomObject &result);
	void operator()(TGBoolean op, TGeomObject &obj, TGeomObject &result);

};

extern int TimeForPrepare;
extern int TimeForIntersect;
extern int TimeForFix;
extern int TimeForSplit;
extern int TimeForUnite;

#endif

