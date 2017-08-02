//---------------------------------------------------------------------------

#ifndef PolinomVH
#define PolinomVH
#include "GeomObjV.h"

//---------------------------------------------------------------------------
class TGeomObject;

typedef MBTf (__closure *TDihotomiaFunc)(MBTf arg,int Level);
MBTf COMMONAL_API Dihotomia(TDihotomiaFunc Func,MBTf X0,MBTf X1,int Level,MBTf EPS);


class COMMONAL_API TEquation {
public:
    TEquation(){};
    ~TEquation(){};
    TMDelTList< TMTwinElement<bool,MBTf> > Roots;
    virtual MBTf Derivative(MBTf X,int Level){return 0;};
    virtual int GetLevel(){return 0;};
    void FindDerivativeRoot(MBTf X0,MBTf X1,TMDelTList<MBTf>& X,int Level,MBTf EPS);
    void FindRoots(MBTf X0,MBTf X1,TMDelTList<MBTf>& X,MBTf EPS);
    void ToGeomObject(TGeomObject* GO,MBTf X0,MBTf X1,int Level,int Count);
    void RootsToGeomObject(TGeomObject* GO,MBTf X0,MBTf X1,MBTf EPS);
};

class COMMONAL_API TPolinom : public TEquation{
public:
    TPolinom(){};
    ~TPolinom(){};
    //коэффициенты упорядочены по убыванию степени
    TMDelTList< TMDelTList<MBTf> > DA;
    void Initialize(const TMTList<MBTf>& A);
    virtual MBTf Derivative(MBTf X,int Level);
    virtual int GetLevel();
};

class TMFunction;
class COMMONAL_API TFunctionCrossing : public TEquation{
public:
    TFunctionCrossing();
    ~TFunctionCrossing(){};
    MBTf ArgumentDelta;
    const TMFunction* F1;
    const TMFunction* F2;
    int FLevel;
    void Initialize( const TMFunction& _F1,int Level1,const TMFunction& _F2,int Level2 );
    virtual MBTf Derivative(MBTf X,int Level);
    virtual int GetLevel();
};
#endif
