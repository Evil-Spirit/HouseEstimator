//---------------------------------------------------------------------------

#ifndef G2DPointCutVH
#define G2DPointCutVH
#include "GeomObjV.h"
#include "G2DDegreeRulesV.h"
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
class COMMONAL_API TG2DPoint : public TGPoint {
private:
public:
    TIntVec Temp;
    TMDelTList<TDegreeRule> Rules;

    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TG2DPoint();
    virtual ~TG2DPoint(){};
    bool RemoveLevel(TG2DLink* Link);
    bool Update();
};
extern COMMONAL_API TClassNode* TG2DPoint::StaticType;

class COMMONAL_API TG2DCut : public TGCut {
private:
public:
    static TClassNode* StaticType;
    TMDelTList<TDegreeRule> Rules;
    TMyObject* CreateFunction();
    TG2DCut();
    virtual ~TG2DCut(){};
};
extern COMMONAL_API TClassNode* TG2DCut::StaticType;

#endif
