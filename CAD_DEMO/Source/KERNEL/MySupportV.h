//---------------------------------------------------------------------------

#ifndef MySupportVH
#define MySupportVH
//---------------------------------------------------------------------------
class COMMONAL_API TMySupport : public TMyObject {
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
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

extern COMMONAL_API TClassNode* TMySupport::StaticType;

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
    TMyObject* CreateFunction();
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

    __property TMetaLabel3D*    MetaLabel3D = {read = GetMetaLabel3D};
    __property TDynamicLink*    DefaultLink = {read = GetDefaultLink};
    __property TMetaElement*    DefaultTarget = {read = GetDefaultTarget};
    __property TMetaElement*    DEFAULT_SIZE = {read = GetDEFAULT_SIZE};
    __property TMetaMyMode*     DEFAULT_MODE = {read = GetDEFAULT_MODE};
    __property TMetaMyMode*     _3D_MODE = {read = Get_3D_MODE};
    __property TMetaElement*    RootElement = {read = GetRootElement};
    __property TMetaElement*    SubRootElement = {read = GetSubRootElement};



    void PreProcessActions();
    void AfterProcessActions();
    TDynamicLink* FreeLink(TMetaElement * Target, TMetaElement * Source);    
    virtual void LoadContextMetaData(FILE * F);
    virtual void SaveContextMetaData(FILE * F);
    virtual void WriteContextMetaData(TMemoryStream *MS);
    virtual void ReadContextMetaData(TMemoryStream *MS);

    void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};

extern COMMONAL_API TClassNode* TKernelSupport::StaticType;



#endif
