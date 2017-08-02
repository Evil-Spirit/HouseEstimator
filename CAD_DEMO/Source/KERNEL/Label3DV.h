//---------------------------------------------------------------------------

#ifndef Label3DV2H
#define Label3DV2H
#include "VisLabel.hpp"
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

/*class COMMONAL_API TLabel3D : public TElement {
protected:
    TMTList<TVisLabel> Labels3D;
    TVisNode *Label_Node;
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
    virtual TVisRender *MyRender(){return(Label_Node);};
    __property AnsiString Text = {read = Description,write = SetText};
    virtual void UserChangePosition(const TIntVec& Move,const TIntVec& Rotate);
    bool Rotateble;
//    virtual void StandartRender2D(TDrawView *DrawView);
};
extern COMMONAL_API TClassNode* TLabel3D::StaticType;
*/



class COMMONAL_API TLabel3D : public TElement {
protected:
    TVisPrimitiveObj *Label;
    TMetaLabel3D *GetMetaLabel3D(){return((TMetaLabel3D*)MyMeta);};
    void SetText(const AnsiString& _Text );
    TVisTexture* VT;   
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
    virtual TVisRender *MyRender(){return(Label);};
    __property AnsiString Text = {read = Description,write = SetText};
    bool Rotateble;
};
extern COMMONAL_API TClassNode* TLabel3D::StaticType;

#endif
