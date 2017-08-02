//---------------------------------------------------------------------------

#ifndef G2DPointVH
#define G2DPointVH
#include "GeomObjV.h"
//---------------------------------------------------------------------------

const MBTf MBTf_EPS = 0.0000000001; //10^(-10)  для расчетов с чисто MBTf
const MBTf THRESHOLD_EPS = 0.0000001; //10^(-7) точность граничная для MBTi и MBTf
const MBTi MBTi_EXACT_EPS = 0.00001; //10^(-5) наиболее низкий EPS для MBTi


class TG2DLink;
class TG2DPoint;
class COMMONAL_API TDegreeRule : public TMyObject{
protected:
    virtual TIntVec GetPoint() const;
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TDegreeRule();
    ~TDegreeRule(){};
    TG2DPoint* GPoint;
    TG2DLink* GLink;
    __property TIntVec Point = {read=GetPoint};
    virtual void SwitchPointToPoint(TG2DPoint* FromPoint,TG2DPoint* ToPoint,TG2DPoint* TargetPoint)
    {
        throw EMyException("<TDegreeRule::SwitchPointToPoint>: Нереализовано в классах наследниках.");
    };
};
extern COMMONAL_API TClassNode* TDegreeRule::StaticType;

class COMMONAL_API TCircleDegreeRule  : public TDegreeRule{
protected:
    virtual MBTi GetRadius()const {return FRadius;};
    MBTi FRadius;
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TCircleDegreeRule();
    ~TCircleDegreeRule(){};
    __property MBTi Radius = {read = GetRadius,write = FRadius};
};

extern COMMONAL_API TClassNode* TCircleDegreeRule::StaticType;

class COMMONAL_API TLineDegreeRule  : public TDegreeRule{
protected:
    virtual TIntVec GetPoint() const;
    virtual TIntVec GetDirection() const;
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TLineDegreeRule();
    ~TLineDegreeRule(){};
    TG2DPoint* GPX_SRC;
    TG2DPoint* GPX_DST;
    TG2DPoint* GPY_SRC;
    MBTi Angle;
    bool Strongly;
    __property TIntVec Direction = {read=GetDirection};
    void SwitchPointToPoint(TG2DPoint* FromPoint,TG2DPoint* ToPoint,TG2DPoint* TargetPoint);
};


class COMMONAL_API TCircleDegreeOfAngle  : public TCircleDegreeRule{
protected:
    virtual TIntVec GetPoint() const;
    virtual MBTi GetRadius() const;
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TG2DPoint* GPX_DST;
    TG2DPoint* GPY_DST;
    MBTi Angle;
    TCircleDegreeOfAngle();
    ~TCircleDegreeOfAngle(){};
};

extern COMMONAL_API TClassNode* TCircleDegreeOfAngle::StaticType;


bool COMMONAL_API CrossCircleAndLine(
                    const TIntVec& C1,MBTi R1,
                    const TIntVec& P1,const TIntVec& P2,
                    TMDelTList<TIntVec>& CPS,bool Strongly,MBTi USEEPS);

bool COMMONAL_API CrossCircles(
                    const TIntVec& C1,MBTi R1,
                    const TIntVec& C2,MBTi R2,
                    TMDelTList<TIntVec>& CPS,MBTi USEEPS);

bool COMMONAL_API CrossPointsOf(
                    const TLineDegreeRule& Rule1,
                    const TLineDegreeRule& Rule2,
                    TMDelTList<TIntVec>& CPS,MBTi USEEPS);

bool COMMONAL_API CircleByThreePoints(
                    const TIntVec& P1,
                    const TIntVec& P2,
                    const TIntVec& P3,
                    TIntVec& CP,
                    MBTi& R);

bool COMMONAL_API CircleByTwoPointsAndAngle(
                    const TIntVec& RotSrc,
                    const TIntVec& RotDst,
                    MBTi Angle,
                    TIntVec& CP,
                    MBTi& R);


TIntVec COMMONAL_API GetThirdPoint(
                    const TIntVec& RotSrc,
                    const TIntVec& RotDst,
                    MBTi Angle
                    );

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
    TMyObject* CreateFunction();
    TG2DCut();
    virtual ~TG2DCut(){};
};
extern COMMONAL_API TClassNode* TG2DCut::StaticType;

void COMMONAL_API ListToGeomObject(TGeomObject* GO,const TMDelTList<TIntVec>& Pnts,bool Solid);

class COMMONAL_API TMFunction {
public:
    TMFunction(){};
    ~TMFunction(){};
    virtual TIntVec CalcPolarValue(MBTf arg)const {throw EMyException("<TMFunction::CalcPolarValue>: нет реализации.");};
    virtual MBTf CalcValue(MBTf arg) const {throw EMyException("<TMFunction::CalcPolarValue>: нет реализации.");};
    virtual void ToGeomObject(TGeomObject* GO,MBTi a0,MBTi a1,int Count);
};

class COMMONAL_API TPascalLimacon : public TMFunction
{
public:
    TPascalLimacon(){Index=0;};
    ~TPascalLimacon(){};
    MBTf l;
    MBTf a;
    //--------------------
    MBTf y;
    TIntVec OffSet;
    MBTf CalcValue(MBTf arg) const;
    TIntVec CalcPolarValue(MBTf arg)const;
    MBTf CalcValueSimple(MBTf arg) const;
    TIntVec CalcPolarValueSimple(MBTf arg) const;
    int Index;
    //              .P1
//             /
//           /
//         /
//       / Angle
//    ./---------------.P0
    void Initialize(const TIntVec& P0,const TIntVec& P1,MBTi Angle,const TIntVec& PositionPoint);
    bool CrossingWithLine(const TIntVec& P0,const TIntVec& P1,TMDelTList<TIntVec>& Roots,MBTf USEEPS = MBTi_EXACT_EPS);
    bool CrossingWithCircle(const TIntVec& Center,MBTi Radius,TMDelTList<TIntVec>& Roots,MBTf USEEPS = MBTi_EXACT_EPS);
    TIntVec FindClosestPoint(const TIntVec& P0);
    virtual void ToGeomObject_All(TGeomObject* GO,int Count);
};

class COMMONAL_API TPolarLine : public TMFunction {
public:
    TPolarLine(){};
    ~TPolarLine(){};
    MBTf a;
    MBTf b;
    MBTf c;
    MBTf CalcValue(MBTf arg) const;
    TIntVec CalcPolarValue(MBTf arg)const;
    void Initialize(const TIntVec& P1,const TIntVec& P2);
};

class COMMONAL_API TPolarCircle : public TMFunction {
public:
    TPolarCircle(){Index=0;};
    ~TPolarCircle(){};
    int Index;
    MBTf Radius;
    TIntVec Center;
    MBTf CalcValue(MBTf arg) const;
    TIntVec CalcPolarValue(MBTf arg)const;
    MBTf MoveToEdge(MBTf arg) const;
    MBTf CalcSqrDet(MBTf arg) const;
    MBTf CalcSqrDet(const long double& Sin_a,const long double& Cos_a) const;
};

template <class FLOATTYPE>
void AddRoot(TMDelTList<FLOATTYPE>& Roots,FLOATTYPE Root,FLOATTYPE EPS)
{
    for (int i=0;i<Roots.Count;i++)
        if ( Roots[i] == Root )
            return;
    Roots.Add( new FLOATTYPE(Root) );
}

extern    TMDelTList<int> SGNS2;



#endif
