//---------------------------------------------------------------------------

#ifndef ArchitectureSupportVH
#define ArchitectureSupportVH
#include "MySupportV.h"
//---------------------------------------------------------------------------
class TMainTree;
double PACKAGE GetTotalArea(TMainTree* aWorld,int FloorIndex);


class TMetaPlatform;
class TDynamicLink;
class TArchitectSupport : public TMySupport {
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TArchitectSupport();
    ~TArchitectSupport(){};
    //--------------------------------------------------------------------------
    TPointer<TMetaPlatform> AFirstPlatform;
    TPointer<TMetaPlatform> ADefaultLand;
    TPointer<TDynamicLink> APlatform_Land;

    TMetaPlatform* GetFirstPlatform();
    TMetaPlatform* GetDefaultLand();
    TDynamicLink* GetPlatform_Land();


    __property TMetaPlatform*   FirstPlatform = {read = GetFirstPlatform};
    __property TMetaPlatform*   DefaultLand = {read = GetDefaultLand};
    __property TDynamicLink*    Platform_Land = {read = GetPlatform_Land};

    void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    
    void PreProcessActions();
    void AfterProcessActions();

    bool inited;
};

TClassNode* TArchitectSupport::StaticType = NULL;
#endif
