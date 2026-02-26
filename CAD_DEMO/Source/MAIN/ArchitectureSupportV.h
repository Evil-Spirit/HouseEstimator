// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ArchitectureSupportVH
#define ArchitectureSupportVH
#include "MySupportV.h"
//---------------------------------------------------------------------------
class TMainTree;
double  GetTotalArea(TMainTree* aWorld,int FloorIndex);


class TMetaPlatform;
class TDynamicLink;
class TArchitectSupport : public TMySupport {
public:
    //----------------------------------
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
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


    // __property TMetaPlatform* FirstPlatform {read=GetFirstPlatform}; // [manual migration needed]
    // __property TMetaPlatform* DefaultLand {read=GetDefaultLand}; // [manual migration needed]
    // __property TDynamicLink* Platform_Land {read=GetPlatform_Land}; // [manual migration needed]

    void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    
    void PreProcessActions();
    void AfterProcessActions();

    bool inited;
};

TClassNode* TArchitectSupport::StaticType = NULL;
#endif
