//---------------------------------------------------------------------------

#ifndef G2DDegreeRulesVH
#define G2DDegreeRulesVH
#include "G2DGeomV.h"
//---------------------------------------------------------------------------
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
    MBTi OffSet;
    bool Strongly;
    void InitOffSetByPoint(TG2DPoint* Point);
    __property TIntVec Direction = {read=GetDirection};
    void SwitchPointToPoint(TG2DPoint* FromPoint,TG2DPoint* ToPoint,TG2DPoint* TargetPoint);
};
extern COMMONAL_API TClassNode* TLineDegreeRule::StaticType;

class COMMONAL_API TLimaconDegreeRule : public TDegreeRule{
protected:
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TLimaconDegreeRule();
    virtual ~TLimaconDegreeRule(){};
	TG2DPoint* SkP1;
	TG2DPoint* BaseP1;
	TG2DPoint* SkP2;
	TG2DPoint* BaseP2;
	TG2DPoint* PositionPoint;
    TPascalLimacon PL;
    void InitPascalLimacon();
};

extern COMMONAL_API TClassNode* TLimaconDegreeRule::StaticType;


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




bool COMMONAL_API CrossPointsOf(
                    const TLineDegreeRule& Rule1,
                    const TLineDegreeRule& Rule2,
                    TMDelTList<TIntVec>& CPS,MBTi USEEPS);
bool COMMONAL_API CrossPointsOf(
                    const TDegreeRule& Rule1,
                    const TDegreeRule& Rule2,
                    TMDelTList<TIntVec>& CPS,MBTi USEEPS);

TIntVec COMMONAL_API MovePointTo(const TIntVec& Point, const TDegreeRule& Rule);

#endif
