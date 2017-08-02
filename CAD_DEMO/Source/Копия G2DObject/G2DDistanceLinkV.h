//---------------------------------------------------------------------------

#ifndef G2DDistanceLinkVH
#define G2DDistanceLinkVH
#include "G2DObjectV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TDistanceLink : public TG2DLink {
protected:
    void SetPoint(int index,TG2DPoint* aPoint);
    TG2DPoint* GetPoint(int index);
    MBTi FDistance;
    void SetDistance(MBTi aDistance);
//    virtual void UpdateDistanceLink(TG2DPoint* Client,TFlowInfo& FlowInfo);
public:
    MBTi Parallel_Offset_Param; /*m*/
    MBTi Perpendicular_Offset/*m*/;
    MBTi Leg_Offset /*pixels*/;
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TDistanceLink();
    virtual ~TDistanceLink();
    __property TG2DPoint* Client0 = {read = GetPoint,write = SetPoint,index = 0};
    __property TG2DPoint* Client1 = {read = GetPoint,write = SetPoint,index = 1};
    __property MBTi Distance = {read = FDistance,write = SetDistance};
    virtual void Render(TVisView* aView);

    virtual bool HaveLinked(const TMTList<TG2DPoint>& PointList,const TG2DPoint* Point);
    virtual bool UpdatePointRule(TG2DPoint* GPoint);
    virtual bool GetFreePoints(const TMTList<TG2DPoint>& PointList,TMTList<TG2DPoint>& FreePoint);
    virtual bool PointInLink(TG2DPoint* Point);
    bool IsLinked(TG2DPoint* GPoint0,TG2DPoint* GPoint1);
};

extern COMMONAL_API TClassNode* TDistanceLink::StaticType;
#endif
