//---------------------------------------------------------------------------

#ifndef Label3DVH
#define Label3DVH
#include "VisLabel.hpp"
#include "VisText.hpp"
#include "MetaClasses.h"
#include "ElementV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMetaLabel3D : public TMetaElement {
protected:
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaLabel3D(TMetaNode *Parent,int _ID,const AnsiString& Name);
    TMetaLabel3D();
    virtual ~TMetaLabel3D(){};
};
extern COMMONAL_API TClassNode* TMetaLabel3D::StaticType;

class COMMONAL_API TLabel3D : public TElement {
protected:
    TVisLabel* VisLabel;
    TVisText* VisText;
    TMetaLabel3D *GetMetaLabel3D(){return((TMetaLabel3D*)MyMeta);};
    void SetText(const AnsiString& _Text );
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    void SetCharText(char* _Text );
    TLabel3D();
    virtual ~TLabel3D();
    __property TMetaLabel3D *MetaLabel3D = {read = GetMetaLabel3D};
    virtual void StandartCreateView();
    virtual TVisRender *MyRender(){return(VisText);};
    __property AnsiString Text = {read = Description,write = SetText};
    virtual void UserChangePosition(const TIntVec& Move,const TIntVec& Rotate);
    bool Rotateble;
//    virtual void StandartRender2D(TDrawView *DrawView);
};
extern COMMONAL_API TClassNode* TLabel3D::StaticType;


#endif
