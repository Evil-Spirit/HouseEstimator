//---------------------------------------------------------------------------

#ifndef RoomVH
#define RoomVH
#include "ArchitectElementV.h"
//---------------------------------------------------------------------------
/*DeterminateMode */
const int dmNone=0;
const int dmSpaceInside=1;
const int dmSpaceOf=2;

class TMetaRoom : public TMetaElement{
protected:
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaRoom(TMetaNode *Parent,int _ID,const AnsiString& Name);
    TMetaRoom();
    virtual ~TMetaRoom(){};
    /*TMDelLSTList*/TMDelTList<TPointer<TMetaElement> > DeterminateList;
    int DeterminateMode;
    virtual void Fix_Changes(TMetaElement *MEL,TElement* ParentFilter);
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
TClassNode* TMetaRoom::StaticType = NULL;

class TRoom : public TArchitectElement {
protected:
    TVisPrimitiveObj* rFloor;
    TVisPrimitiveObj* rCeil;
    TMetaRoom *GetMetaRoom(){return((TMetaRoom*)MyMeta);};
    TVisNode* RoomRender;
    MBTi FFloorServiceZ;
    MBTi FCeilServiceZ;
    void SetCeilServiceZ(MBTi Value);
    void SetFloorServiceZ(MBTi Value);
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TRoom();
    virtual ~TRoom();
    __property MBTi CeilServiceZ = {read = FCeilServiceZ,write = SetCeilServiceZ};
    __property MBTi FloorServiceZ = {read = FFloorServiceZ,write = SetFloorServiceZ};
    TRenderParam FloorParam;
    TRenderParam CeilParam;
    void FloorCeilArea();
    MBTi GetFloorArea();
    MBTi GetCeilArea();
    int Status;//Status 0 - площадь не считается
    __property TMetaRoom *MetaRoom = {read = GetMetaRoom};
    virtual void StandartCreateView();
    virtual TVisRender *MyRender(){return(RoomRender);}
    TMTList <TElement> *Determinators;
    TMDelTList <TMTList <TElement> > *Exclusion;
    bool Init();
    void ApplyObject(const TIntVec& AbsPoint,TVisRender* Render,TMyObject* Object, int PrimID);
    virtual void ProcessTexturing();
};
TClassNode* TRoom::StaticType = NULL;

#endif
