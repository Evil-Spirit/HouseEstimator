//---------------------------------------------------------------------------

#ifndef WallVH
#define WallVH
//---------------------------------------------------------------------------
#include "ArchitectElementV.h"

class TMetaCube : public TMetaElement{
protected:
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaCube(TMetaNode *Parent,int _ID,const AnsiString& Name);
    TMetaCube();
    virtual ~TMetaCube(){};
    int HoleNormal;
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
TClassNode* TMetaCube::StaticType = NULL;

const int resPoint=0;
const int resRib=1;

class TRouteNode;

class TCube : public TArchitectElement {
protected:
    TMetaCube *GetMetaCube(){return((TMetaCube*)MyMeta);};
    void CalcFragments();
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    MBTi LEFT_LINK_HEIGHT;
    MBTi RIGHT_LINK_HEIGHT;
    THoledPolygon VHP;
    TCube();
    virtual ~TCube();
    __property TMetaCube *MetaCube = {read = GetMetaCube};
    virtual void StandartCreateView();
//    virtual void CreateTraditional();
  //  virtual void CreateByFragments();
    virtual TVisRender *MyRender(){return(VP);};
    bool AdvancedCreateView();
    void SynhronizeFragments();
    void CreateHPolygonSet(TMDelTList<THoledPolygon>& HPL);
    void CreatePolygonStruct(   THoledPolygon& HP,
                                TMDelTList< TMDelTList<int> >& tags,
                                TMDelTList< MBTi >& Zs,
                                TMDelTList< MBTi >& Xs,
                                TMDelTList<TIntVec>& LinesPoint,int SideType);
    void ApplyObject(const TIntVec& AbsPoint,TVisRender* Render,TMyObject* Object, int PrimID);
    void ApplyObjectToFragment(TMyObject* Object,int SideIndex,int Param);
    MBTi FragmentArea(int Fragment,int Param);
    void IterateContour(int Fragment,TMTList<TCube>& Cubes,TMDelTList<int>& Indices);
    void ValidateVHP();
    void NominateVHP();
    int CrossXYPolygon(const TIntVec& Point,int& index,TIntVec& CrossPoint);
    void GetWallEdge(TRouteNode* RN,TIntVec& CP);
    virtual void ProcessTexturing();
    void FillCompletePolygon(THoledPolygon* CP);
    TVisCustomObj *VP;
    void Changed(void* Sender);
};
TClassNode* TCube::StaticType = NULL;

#endif
