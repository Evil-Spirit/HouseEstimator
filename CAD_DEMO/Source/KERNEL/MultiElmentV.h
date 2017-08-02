//---------------------------------------------------------------------------

#ifndef MultiElmentVH
#define MultiElmentVH

#include "ElementV.h"
#include "MetaClasses.h"

//---------------------------------------------------------------------------
class TMetaMultiElement : public TMetaElement{
protected:
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaMultiElement(TMetaNode *Parent,int _ID,const AnsiString& Name);
    TMetaMultiElement();
    virtual ~TMetaMultiElement();
    /*TMDelLSTList*/TMDelTList< TPointer<TMetaElement> > *UNITS;
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    bool IsSizer;
};
TClassNode* TMetaMultiElement::StaticType = NULL;

class TMultiElement : public TElement{
protected:
    TMetaMultiElement *GetMetaMultiElement(){return((TMetaMultiElement*)MyMeta);};
    int GetMetaPartCount();
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TVisNode *VFIRST;
    TVisNode *VTRANS;
    TMultiElement(TMainTree *_MyTree,TMetaNode *_Meta);
    TMultiElement();
    virtual ~TMultiElement();
    __property TMetaMultiElement *MetaMultiElement = {read = GetMetaMultiElement};
    virtual TVisRender *MyRender(){return(VFIRST);};
    TMDelTList < TMDelTList< TElement > > *ELS;
    TElement *Add(int index);
    TElement *AddOnly(int index);
    void DeleteOne(TElement *El);
    void DeleteOne(int typeindex,int index);
    void Clear();
    virtual void StandartCreateView();
    __property int MetaPartCount = {read = GetMetaPartCount};
    TElement *GetPart(int i,int j);
    int CountOf(int type);
    bool CheckFields();
    virtual void Render(TVisCustomView *aView);
    void SetEnabled(int type,bool Value);
    //-------------------------------------------------------------------------
    virtual void ProcessTasks(int Action);
    virtual void ProcessTexturing();
};
TClassNode* TMultiElement::StaticType = NULL;


#endif
