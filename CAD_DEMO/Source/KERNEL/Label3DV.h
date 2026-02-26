// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
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
    static TMyObject* CreateFunction();
    //----------------------------------
    TMetaLabel3D(TMetaNode *Parent,int _ID,const AnsiString& Name);
    TMetaLabel3D();
    virtual ~TMetaLabel3D(){};
};

/*class COMMONAL_API TLabel3D : public TElement {
protected:
    TMTList<TVisLabel> Labels3D;
    TVisNode *Label_Node;
    TMetaLabel3D *GetMetaLabel3D(){return((TMetaLabel3D*)MyMeta);};
    void SetText(const AnsiString& _Text );
public:
    //----------------------------------
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    //----------------------------------
    void SetCharText(char* _Text );
    TLabel3D();
    virtual ~TLabel3D();
    __property TMetaLabel3D *MetaLabel3D = {read = GetMetaLabel3D};
    virtual void StandartCreateView();
    virtual TVisRender *MyRender(){return(Label_Node);};
    // __property AnsiString Text {read=Description, write=SetText}; // [manual migration needed]
    virtual void UserChangePosition(const TIntVec& Move,const TIntVec& Rotate);
    bool Rotateble;
//    virtual void StandartRender2D(TDrawView *DrawView);
};
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
    static TMyObject* CreateFunction();
    //----------------------------------
    void SetCharText(char* _Text );
    TLabel3D();
    virtual ~TLabel3D();
    __property TMetaLabel3D *MetaLabel3D = {read = GetMetaLabel3D};
    virtual void StandartCreateView();
    virtual TVisRender *MyRender(){return(Label);};
    // __property AnsiString Text {read=Description, write=SetText}; // [manual migration needed]
    bool Rotateble;
};

#endif
