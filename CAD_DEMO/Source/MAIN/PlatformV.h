//---------------------------------------------------------------------------

#ifndef PlatformVH
#define PlatformVH
#include "ArchitectElementV.h"
//---------------------------------------------------------------------------
class TMetaPlatform :public TMetaElement{
protected:
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaPlatform(TMetaNode *Parent,int _ID,const AnsiString& Name);
    TMetaPlatform();
    virtual ~TMetaPlatform(){};
    bool First;
    bool Land;
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
TClassNode* TMetaPlatform::StaticType = NULL;

class TPlatform : public TArchitectElement {
protected:
    TVisCustomObj *POL;
    TMetaPlatform *GetMetaPlatform(){return((TMetaPlatform*)MyMeta);};
    virtual void SetMetaObject(TMyRegObject* aMetaObject);
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TPlatform();
    virtual ~TPlatform();
    __property TMetaPlatform *MetaPlatform = {read = GetMetaPlatform};
    virtual void StandartCreateView();
    virtual TVisRender *MyRender(){return(POL);}
    virtual bool Init();
    void FillCompletePolygon(THoledPolygon* CP);
};
TClassNode* TPlatform::StaticType = NULL;

void ApplyPlatformSize(const TIntVec& SIZE);
#endif
