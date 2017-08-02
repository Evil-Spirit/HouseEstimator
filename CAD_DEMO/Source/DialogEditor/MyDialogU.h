//---------------------------------------------------------------------------
#ifndef MyDialogUH
#define MyDialogUH
//---------------------------------------------------------------------------
#include "ObjectInspectorU.hpp"

class TVCLEditorElement;
class TMyDialogEdit;
class TMyWinControl;
class TEvents;

TComponent* CreateComponent(TComponent* Owner, int ClassId);
//---------------------------------------------------------------------------
class COMMONAL_API TMyProp : public TMyObject
{
    public:
    //-------------------------------
    TMyObject* CreateFunction();
    static TClassNode* StaticType;
    //-------------------------------
    AnsiString FName;
    AnsiString FValue;
    AnsiString FData;
    TMyProp();
    virtual ~TMyProp();
};

extern COMMONAL_API TClassNode* TMyProp::StaticType;

//---------------------------------------------------------------------------
class COMMONAL_API TMyPropObject : public TMyProp
{
    public:
    //-------------------------------
    TMyObject* CreateFunction();
    static TClassNode* StaticType;
    //-------------------------------
    TMyPropObject* Parent;
    TMDelTList <TMyProp> Properties;
    TMDelTList <int> PropKinds;
    TMDelTList <TMyProp> Methods;
    TMDelTList <TMyPropObject> PropObjects;
    int ChildIsIn(AnsiString _Name, TMDelTList <TMyPropObject> List);
    void InitByPropObject(TPropObject* _Object, TMyPropObject* _MyObject, TMyPropObject* _Parent);
    void ToPropObject(TPropObject* _Object, TMyPropObject* _MyObject);
    void FromPropObject(TPropObject* _Object, TMyPropObject* _MyObject, bool GetId = true);
    bool Default(TPropObject* _Object);    
    int GetClassId(TObject* _Object);
    TMyPropObject();
    virtual ~TMyPropObject();
};

extern COMMONAL_API TClassNode* TMyPropObject::StaticType;

//---------------------------------------------------------------------------
class COMMONAL_API TMyComponent : public TMyPropObject {
private:
    int FClassId;
    void InitObject(int _ClassId);
public:
    //-------------------------------
    TMyObject* CreateFunction();
    static TClassNode* StaticType;
    //-------------------------------

    TMyComponent();
    virtual ~TMyComponent();
  __property int ClassId = {read = FClassId, write = InitObject};
};

extern COMMONAL_API TClassNode* TMyComponent::StaticType;

//---------------------------------------------------------------------------
class COMMONAL_API TMyWinControl : public TMyComponent
{
    public:
    //-------------------------------
    TMyObject* CreateFunction();
    static TClassNode* StaticType;
    //-------------------------------
    TMDelTList <TMyWinControl> MyControls;
    TMyWinControl();
    virtual ~TMyWinControl();
};

extern COMMONAL_API TClassNode* TMyWinControl::StaticType;

//---------------------------------------------------------------------------
class COMMONAL_API TMyDialog : public TMyObject
{
    private:
    TEvents* Events;
    void FillProps(TMyWinControl* _MyObject, TComponent* _Object);    
    void FillControls(TMyWinControl* _Object, TWinControl* Parent, TComponent* Owner);

    public:
    //-------------------------------
    TMyObject* CreateFunction();
    static TClassNode* StaticType;
    //-------------------------------
    TMyWinControl Root;
    TMyDialog();
    virtual ~TMyDialog();
    virtual void Edit(TComponent *Owner, TWinControl *Parent, void *Data);
    TForm* CreateForm(TComponent *Owner, TObject* Parent);
    TForm* CreateForm();
};

extern COMMONAL_API TClassNode* TMyDialog::StaticType;
extern COMMONAL_API TMyDialog* CurDialog;
extern COMMONAL_API void BindComponentRecursive(int index,TComponent* Component);
extern COMMONAL_API void BindForm(TForm* Form);
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
