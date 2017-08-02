//---------------------------------------------------------------------------

#ifndef CatalogUnitVH
#define CatalogUnitVH
#include "MetaClasses.h"
//---------------------------------------------------------------------------

class COMMONAL_API TMetaCatalogUnit : public TMetaNode {
private:
    TMetaNode* GetAssociated();
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaCatalogUnit(TMetaNode *Parent,int _ID,const AnsiString& Name);
    TMetaCatalogUnit();
    virtual ~TMetaCatalogUnit(){};
    TPointer<TMyRegObject> ASSOCIATED;
    void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    __property TMetaNode* Associated = {read = GetAssociated};
    virtual void GetImage(bool Small,bool Masked,Graphics::TBitmap* bmp,Graphics::TBitmap* mask);
};

extern COMMONAL_API TClassNode* TMetaCatalogUnit::StaticType;

#endif
 