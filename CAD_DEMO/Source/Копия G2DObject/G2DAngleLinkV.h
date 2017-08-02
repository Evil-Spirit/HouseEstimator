//---------------------------------------------------------------------------

#ifndef G2DAngleLinkVH
#define G2DAngleLinkVH
#include "G2DObjectV.h"
//---------------------------------------------------------------------------

class COMMONAL_API TAngleLink : public TG2DLink {
protected:
    void SetCut(int index,TGCut* Cut);
    TGCut* GetCut(int index);
    MBTi FAngle;
    void SetAngle(MBTi aAngle);
//    virtual void UpdateAngleLink(TG2DPoint* Client,TFlowInfo& FlowInfo);
public:
    TG2DPoint* GetXStart();
    TG2DPoint* GetXEnd();
    TG2DPoint* GetYStart();
    TG2DPoint* GetYEnd();

    TAngleLinkSector AngleLinkSector;
    MBTi LabelRadius;
    MBTi LabelAngle_Param;
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TAngleLink();
    virtual ~TAngleLink();
    __property TGCut* Client0 = {read = GetCut,write = SetCut,index = 0};
    __property TGCut* Client1 = {read = GetCut,write = SetCut,index = 1};
    __property MBTi Angle = {read = FAngle,write = SetAngle};
    virtual bool GetFreePoints(const TMTList<TG2DPoint>& PointList,TMTList<TG2DPoint>& FreePoint);

    virtual void Render(TVisView* aView);
    virtual bool UpdatePointRule(TG2DPoint* GPoint);
    virtual bool IsBestToUpdate(TG2DPoint* GPoint);
    virtual bool HaveLinked(const TMTList<TG2DPoint>& PointList,const TG2DPoint* Point);
    virtual bool PointInLink(TG2DPoint* Point);
    virtual bool IsLinked(TG2DPoint* GPoint1,TG2DPoint* GPoint2);
};

extern COMMONAL_API TClassNode* TAngleLink::StaticType;
extern TMTList<TG2DPoint> ____PointList; 
#endif
