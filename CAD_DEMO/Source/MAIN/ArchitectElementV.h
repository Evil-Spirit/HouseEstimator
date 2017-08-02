//---------------------------------------------------------------------------

#ifndef ArchitectElementVH
#define ArchitectElementVH
#include "ElementV.h"
#include "VisCustomObj.hpp"
//---------------------------------------------------------------------------

class TMetaArchitectElement : public TElement {
protected:
public:
    TMetaArchitectElement();
    virtual ~TMetaArchitectElement(){};
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
};
TClassNode* TMetaArchitectElement::StaticType = NULL;


class TArchitectElement : public TElement {
protected:
public:
    TArchitectElement();
    virtual ~TArchitectElement(){};
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    void HoleInMeFor(TElement* El, TPolygon* Hole);
};
TClassNode* TArchitectElement::StaticType = NULL;
#endif
