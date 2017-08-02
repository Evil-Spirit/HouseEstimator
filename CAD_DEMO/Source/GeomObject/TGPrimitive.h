//---------------------------------------------------------------------------

#ifndef TGPrimitiveH
#define TGPrimitiveH
//---------------------------------------------------------------------------

#include "mathV.h"
#include "types.h"

class TGeomObject;
COMMONAL_API void PrimitiveSquare(TGeomObject *obj, MBTi sx, MBTi sy);
COMMONAL_API void PrimitiveCircle(TGeomObject *obj, MBTi Rad, int partCount);
COMMONAL_API void PrimitiveRing(TGeomObject *obj, MBTi Rad1, MBTi Rad2, int partCount);
COMMONAL_API void PrimitiveHoledRing(TGeomObject *obj, MBTi Rad1, MBTi Rad2, int partCount);
COMMONAL_API void PrimitiveXRing(TGeomObject *obj, MBTi Rad1, MBTi Rad2, int partCount);
COMMONAL_API void PrimitivePyramid(TGeomObject *obj, MBTi sx, MBTi sy, MBTi sz);
COMMONAL_API void PrimitivePlane(TGeomObject *obj, MBTi sx, MBTi sy, const TIntVec &n, const TIntVec &o, MBTi ang = 0);
COMMONAL_API void PrimitiveLineUnit(TGeomObject *obj, MBTi sx, MBTi sy, const TIntVec &a, const TIntVec &b);
COMMONAL_API void PrimitiveRoundArrow(TGeomObject *obj, MBTi size, MBTi angle);

#endif

