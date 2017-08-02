//---------------------------------------------------------------------------

#ifndef G2DObjectVH
#define G2DObjectVH
#include "GeomObjV.h"
#include "VisView.hpp"
//---------------------------------------------------------------------------
#pragma option push -b-
enum TG2DLinksType {lt2Fix,lt2Coincidence,lt2Angle,lt2Distance,lt2Length};
#pragma option pop

#pragma option push -b-
enum TAngleLinkSector {alsFirst,alsSecond,alsThird,alsFourth};
#pragma option pop

static const TColor clOrange = 0x88ff;

/*
class TG2DCut : public TGCut {
protected:
    TMDelTList< TPointer<TG2DLink> > FLinks;
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TG2DCut(){};
    virtual ~TG2DCut(){};
};
*/

class TG2DPoint;
class TG2DCut;
class T2DGObject;
class TG2DLink;
class TFlowInfo;
void SetFlag(TGeomFlags &tgt, TClassifyFlags Flag, TClassify State);

class COMMONAL_API TG2DLink : public TGBaseLink {
protected:
public:
    TG2DLink();
    virtual ~TG2DLink();
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
	TGeomFlags FFlags;
    virtual bool UpdatePointRule(TG2DPoint* GPoint){throw EMyException("<TG2DLink::IsBestToUpdate>: Нереализовано.");};
    virtual bool IsBestToUpdate(TG2DPoint* GPoint){throw EMyException("<TG2DLink::IsBestToUpdate>: Нереализовано.");};
    virtual bool GetFreePoints(const TMTList<TG2DPoint>& PointList,TMTList<TG2DPoint>& FreePoint){throw EMyException("<TG2DLink::IsBestToUpdate>: Нереализовано.");};
    virtual bool PointInLink(TG2DPoint* Point){throw EMyException("<TG2DLink::PointInLink>: Нереализовано.");};

    virtual bool HaveLinked(const TMTList<TG2DPoint>& PointList,const TG2DPoint* Point){throw EMyException("<TG2DLink::HaveLinked>: Нереализовано.");};
    virtual bool IsLinked(TG2DPoint* GPoint1,TG2DPoint* GPoint2){throw EMyException("<TG2DLink::IsLinked>: Нереализовано.");};
    bool IsLinkedTo(TMTList<TG2DPoint>& Skeleton,TG2DPoint* Point);
    bool IsLinkCompleted(const TMTList<TG2DPoint>& PointList,const TG2DPoint* Point);
    TG2DPoint* ReadyToUpdate(const TMTList<TG2DPoint>& PointList);
	virtual bool CanUpdateList(TMTList<TG2DPoint>& PointList){throw EMyException("<TG2DLink::CanUpdateList>: Нереализовано.");};
};

extern COMMONAL_API TClassNode* TG2DLink::StaticType;

TG2DLink* CreateAngleLink(TG2DCut* Cut1,TG2DCut* Cut2,TAngleLinkSector AngleLinkSector);
TG2DLink* CreateDistanceLink(TG2DPoint* Point1,TG2DPoint* Point2);

class TDistanceLink;
class COMMONAL_API T2DGObject : public TGeomObject{
protected:
    bool NeedCreateView;
    TMDelTList<TG2DLink> FLinks;
    int GetLinkCount();
	void FillLinksFlags(TClassifyFlags Flag, TClassify State);
	void FillLinksFlags(TMTList <TG2DLink> &Links, TClassifyFlags Flag, TClassify State);
    void FillLinksRecursive(TGUnit* Unit,TFlowInfo& FlowInfo);
    //-----------------Позиционирование со связками ----------------------------
    void MakeTempPoints();
    void ReturnTempPoints();
    TFlowInfo* pFlowInfo;
    bool LinkOnTheSet(TMTList<TG2DPoint> &PntSet,TG2DLink* Link);
    void SelectGroupForPoint(TG2DPoint* Point,TFlowInfo& FlowInfo);
    void SelectGroupForPointRec(TG2DPoint* Point,TFlowInfo& FlowInfo);
    //--------------------------------------------------------------------------
public:
    //-------------------Standart-----------------------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    T2DGObject();
    virtual ~T2DGObject();
    //--------------------Параметры прорисовки----------------------------------
    TVisPen& PointPen;
    TVisPen& RibPen;
    TVisPen& LinkPen;
    //----------------------старое----------------------------------------------
    TIntVec RotateCenter;
    TIntVec BBoxLU, BBoxRD;
    bool Additional;
    bool Fixid;
    void CreateRC();
    void CreateBBox();
    virtual int FindPoint(const TIntVec& V) const;
    virtual bool Snap(const TIntVec &Point, TIntVec& SnapPoint, int& CutIndex, MBTi CEPS, bool Infinity) const;
    //----------------------обычно----------------------------------------------
    void ProcessCreateView();
    void CreateView();
    void Render(TVisView* aView);
    void RenderSelection(   TVisView* aView,
                            const TVisPen& SelPointPen,
                            const TVisPen& SelRibPen,
                            const TVisPen& SelLinkPen,
                            TMTList<TGPoint>& SelPoints,
                            TMTList<TGCut>& SelCuts,
                            TMTList<TG2DLink>& SelLinks
                             );
    //-----------------------access,delete routine-----------------------------------                             
    TG2DPoint& GetVertex(int index);
    const TG2DPoint& GetVertex(int index) const;
    TG2DCut& GetCut(int index);
    const TG2DCut& GetCut(int index) const;
    void ToGeomObject(TGeomObject* GO);
    void FromGeomObject(TGeomObject* GO);
    __property int LinksCount = {read = GetLinkCount};
    TG2DLink& GetLink(int index);
    int AddLink(TG2DLink* Link);
	virtual void Delete(TGCut* Cut);
	virtual void Delete(TGPoint* Point);
	virtual void Delete(TGBaseLink* Link);
	virtual void Delete(TGPolygon* Link);
	virtual void DeleteLink(int index);
	virtual void DeleteCut(int index);
	virtual void DeletePoint(int index);
    //------------End Link Access-------------------------

    TG2DLink* MakeAngleLink(TG2DCut* Cut1,TG2DCut* Cut2,TAngleLinkSector AngleLinkSector);
    TG2DLink* MakeDistanceLink(TG2DPoint* Point1,TG2DPoint* Point2);

    //-----------------Позиционирование со связками ----------------------------
    TG2DCut& GP_X;
    TG2DCut& GP_Y;
    TG2DPoint& GP_ZERO;
    TG2DPoint& GP_X_AXE;
    TG2DPoint& GP_Y_AXE;
    void PrepareMoving(TG2DPoint* Point);
    void ContinueMoving(const TIntVec& NewValue);
    void EndMoving();
	virtual void Clear();																// Очистить геометрический обьект
    //-------------------------------------------- ----------------------------
};

extern COMMONAL_API TClassNode* T2DGObject::StaticType;

extern TMTList<TG2DPoint> _Points;

#endif
