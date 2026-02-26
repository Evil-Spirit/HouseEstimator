// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MySupportVH
#define MySupportVH
//---------------------------------------------------------------------------
class COMMONAL_API TMySupport : public TMyObject {
public:
    //----------------------------------
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    //----------------------------------
    TMySupport();
    virtual ~TMySupport(){};
    virtual void PreProcessActions(){};
    virtual void AfterProcessActions(){};

    virtual void LoadContextMetaData(FILE * F){};
    virtual void SaveContextMetaData(FILE * F){};
    virtual void WriteContextMetaData(TMemoryStream *MS){};
    virtual void ReadContextMetaData(TMemoryStream *MS){};
};


class TMetaLink;
class TMetaElement;
class TMetaMyMode;
class TDynamicLink;
class TMetaLabel3D;

class COMMONAL_API TKernelSupport : public TMySupport {
    TDynamicLink* GetDefaultLink();
    TMetaElement* GetDefaultTarget();
    TMetaElement* GetDEFAULT_SIZE();
    TMetaMyMode* GetDEFAULT_MODE();
    TMetaMyMode* Get_3D_MODE();
    TMetaLabel3D* GetMetaLabel3D();
    TMetaElement* GetRootElement();
    TMetaElement* GetSubRootElement();
public:
    bool inited;
    //----------------------------------
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    //----------------------------------
    TKernelSupport();
    ~TKernelSupport(){};

    TMDelTList<TMetaLink> MLinks;
    TMDelTList<TDynamicLink> DLinks;
    TMTList<TMetaElement> WEBMETA;
    TMTList<TMetaElement>  MAE;
    TMTList< TMetaMyMode > Modes;

    TPointer<TMetaElement> ADEFAULT_SIZE;
    TPointer<TMetaMyMode> ADEFAULT_MODE;
    TPointer<TMetaMyMode> A_3D_MODE;
    TPointer<TDynamicLink> ADefaultLink;
    TPointer<TMetaElement> ADefaultTarget;
    TPointer<TMetaLabel3D> AMetaLabel3D;
    TPointer<TMetaElement> ARootElement;
    TPointer<TMetaElement> ASubRootElement;

    // __property TMetaLabel3D* MetaLabel3D {read=GetMetaLabel3D}; // [manual migration needed]
    // __property TDynamicLink* DefaultLink {read=GetDefaultLink}; // [manual migration needed]
    // __property TMetaElement* DefaultTarget {read=GetDefaultTarget}; // [manual migration needed]
    // __property TMetaElement* DEFAULT_SIZE {read=GetDEFAULT_SIZE}; // [manual migration needed]
    // __property TMetaMyMode* DEFAULT_MODE {read=GetDEFAULT_MODE}; // [manual migration needed]
    // __property TMetaMyMode* _3D_MODE {read=Get_3D_MODE}; // [manual migration needed]
    // __property TMetaElement* RootElement {read=GetRootElement}; // [manual migration needed]
    // __property TMetaElement* SubRootElement {read=GetSubRootElement}; // [manual migration needed]



    void PreProcessActions();
    void AfterProcessActions();
    TDynamicLink* FreeLink(TMetaElement * Target, TMetaElement * Source);    
    virtual void LoadContextMetaData(FILE * F);
    virtual void SaveContextMetaData(FILE * F);
    virtual void WriteContextMetaData(TMemoryStream *MS);
    virtual void ReadContextMetaData(TMemoryStream *MS);

    void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};




#endif
