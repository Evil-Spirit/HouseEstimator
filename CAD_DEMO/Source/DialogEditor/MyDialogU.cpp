//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include <vcl.h>
#pragma hdrstop

#include "MyDialogU.h"
#include "MyDialogEditU.h"
#include "LuaEnvV.h"
#include "tolua++.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TClassNode* TMyProp::StaticType = NULL;
TClassNode* TMyPropObject::StaticType = NULL;
TClassNode* TMyComponent::StaticType = NULL;
TClassNode* TMyWinControl::StaticType = NULL;
TClassNode* TMyDialog::StaticType = NULL;

TMyDialog* CurDialog = NULL;

TMyObject* TMyProp::CreateFunction()
{
    return new TMyProp();
}

TMyObject* TMyPropObject::CreateFunction()
{
    return new TMyPropObject();
}

TMyObject* TMyComponent::CreateFunction()
{
    return new TMyComponent();
}

TMyObject* TMyWinControl::CreateFunction()
{
    return new TMyWinControl();
}

TMyObject* TMyDialog::CreateFunction()
{
    return new TMyDialog();
}

const AnsiString aFName = AnsiString("Name");
const AnsiString aFValue = AnsiString("Value");
const AnsiString aFData = AnsiString("Data");
const AnsiString aProperties = AnsiString("Properties");
const AnsiString aMethods = AnsiString("Methods");
const AnsiString aPropObjects = AnsiString("PropObjects");
const AnsiString aFClassId = AnsiString("ClassId");
const AnsiString aRoot = AnsiString("Root");
const AnsiString aMyControls = AnsiString("MyControls");
const AnsiString aPropKinds = AnsiString("PropKinds");

//---------------------------------------------------------------------------
TComponent* CreateComponent(TComponent* Owner, int aClassId)
{
    switch(aClassId)
    {
      case cnButton      : return new TButton(Owner);
      case cnForm        : return new TForm(Owner);
      case cnRadioButton : return new TRadioButton(Owner);
      case cnRadioGroup  : return new TRadioGroup(Owner);
      case cnPanel       : return new TPanel(Owner);
      case cnLabel       : return new TStaticText(Owner);
      case cnEdit        : return new TEdit(Owner);
      case cnMemo        : return new TMemo(Owner);
      case cnCheckBox    : return new TCheckBox(Owner);
      case cnListBox     : return new TListBox(Owner);
      case cnComboBox    : return new TComboBox(Owner);
      case cnGroupBox    : return new TGroupBox(Owner);
      case cnScrollBar   : return new TScrollBar(Owner);
      case cnPageControl : return new TPageControl(Owner);
      case cnTabSheet    : return new TTabSheet(Owner);
      default: return NULL;
    }
}

//---------------------------------------------------------------------------
//TMyDialog:
//---------------------------------------------------------------------------
TMyDialog::TMyDialog()
{
    Events = new TEvents;
    RegisterNewClass<TMyObject,TMyDialog>(this,false,&CreateFunction);
    GenerateGUIDIfNeed();
    TMyDialog::StaticType->UniqueNameFlag = true;
    Name = "New_Dialog";
    RegisterField(&Root,&aRoot,mtMyObject);
    Root.ClassId = cnForm;
}

//---------------------------------------------------------------------------
void TMyDialog::FillProps(TMyWinControl* _MyObject, TComponent* _Object)
{
    int i;
    for (i = 0; i < _MyObject->Properties.Count; i++)
    {
        if ( ! _MyObject->Properties[i].FValue.IsEmpty() )
        {
            if ( _MyObject->Properties[i].FName == "Color" )
                SetPropByKind( _MyObject->Properties[i].FData, tkEnumeration, _Object, _MyObject->Properties[i].FName, _MyObject->Properties[i].FValue);
            else
                if ( _MyObject->PropKinds[i] != tkClass )
                    SetPropByKind( _MyObject->Properties[i].FData, (unsigned)_MyObject->PropKinds[i], _Object, _MyObject->Properties[i].FName, _MyObject->Properties[i].FValue);
        }
    }
    for (i = 0; i < _MyObject->Methods.Count; i++)
        FillEvents(Events, _Object, _MyObject->Methods[i].FName, _MyObject->Methods[i].FValue);
}

//---------------------------------------------------------------------------
void TMyDialog::FillControls(TMyWinControl* _Object, TWinControl* Parent, TComponent* Owner)
{
    int i;
    AnsiString TempName;
    FillProps(_Object, Parent);
    if ( _Object == &Root )
        Parent->Visible = false;
    for (i = 0; i < _Object->MyControls.Count; i++)
    {
        TObject* NewObject;
        if ( _Object->MyControls.Items[i]->ClassId == cnTabSheet )
            NewObject = MakeObjectById(_Object->MyControls.Items[i]->ClassId, TempName, Parent);
        else
            NewObject = MakeObjectById(_Object->MyControls.Items[i]->ClassId, TempName, Owner);
        if ( IS ( NewObject, __classid(TWinControl) ) )
            ((TWinControl*)NewObject)->Parent = Parent;
        if ( IS ( NewObject, __classid ( TTabSheet ) ) )
        {
            ((TTabSheet*)NewObject)->Parent = Parent;
            ((TPageControl*)Parent)->ActivePage = ((TTabSheet*)NewObject);
            ((TTabSheet*)NewObject)->TabVisible = true;
            ((TTabSheet*)NewObject)->PageControl = ((TPageControl*)Parent);
        }
        FillControls(_Object->MyControls.Items[i], (TWinControl*)NewObject, Owner);
    }
}

//---------------------------------------------------------------------------
void BindComponentRecursive(int index,TComponent* Component)
{
    //push Field Name
    lua_pushstring(_LUA_, Component->Name.c_str() );
    //push Field Value
    tolua_pushusertype(_LUA_,Component, AnsiString( Component->ClassName() ).c_str() );
    //Set Table Field Value
    lua_settable(_LUA_, index);
    for ( int i = 0; i < Component->ComponentCount; i++ )
        BindComponentRecursive( index, Component->Components[i]);
}

//---------------------------------------------------------------------------
void BindForm(TForm* Form)
{
    //push main table
    tolua_pushusertype(_LUA_,Form, AnsiString( Form->ClassName() ).c_str() );
    int index = lua_gettop(_LUA_);
    for ( int i=0;i<Form->ComponentCount;i++ )
        BindComponentRecursive( index ,Form->Components[i]);
    //pop main table
    lua_pop(_LUA_, 1);
}

//---------------------------------------------------------------------------
TForm* TMyDialog::CreateForm(TComponent *Owner, TObject* Parent)
{
    TForm* NewForm = new TForm(Owner);
    NewForm->Parent = (TWinControl*)Parent;
    FillControls(&Root, NewForm, NewForm);
    Events->Owner = NewForm;
    BindForm(NewForm);
    return NewForm;
}

//---------------------------------------------------------------------------
TForm* TMyDialog::CreateForm()
{
    return CreateForm(Application, NULL);
}

//---------------------------------------------------------------------------
void TMyDialog::Edit(TComponent *Owner, TWinControl *Parent,void *Data)
{
    new TMyDialogEdit(Owner,Parent,this);
}

//---------------------------------------------------------------------------
TMyDialog::~TMyDialog()
{
    delete Events;
}

//---------------------------------------------------------------------------
//TMyComponent:
//---------------------------------------------------------------------------
TMyComponent::TMyComponent()
{
    FClassId = -1;
    RegisterNewClass <TMyPropObject,TMyComponent>(this, false, &CreateFunction);
    RegisterField(&FClassId, &aFClassId, mtInt);
}

//---------------------------------------------------------------------------
TMyComponent::~TMyComponent()
{
}

//---------------------------------------------------------------------------

void TMyComponent::InitObject(int _ClassId)
{
    int Number;
    AnsiString TempName;
    FClassId = _ClassId;
    TObject *TempObject = MakeObjectById(_ClassId, TempName);
    TPropObject *TempPropObject = new TPropObject();
    ((TControl*)TempObject)->Name = TempName;
    InitPropByObject(TempObject, TempPropObject);
    InitByPropObject(TempPropObject, this, NULL);
    delete TempObject;
    delete TempPropObject;
}

//---------------------------------------------------------------------------
//TMyWinControl:
//---------------------------------------------------------------------------
TMyWinControl::TMyWinControl()
{
    RegisterNewClass <TMyComponent,TMyWinControl>(this, false, &CreateFunction);
    RegisterField(&MyControls,&aMyControls,mtMyObject);
}

//---------------------------------------------------------------------------
TMyWinControl::~TMyWinControl()
{
}

//---------------------------------------------------------------------------
//TMyPropObject:
//---------------------------------------------------------------------------
TMyProp::TMyProp()
{
    RegisterNewClass <TMyObject,TMyProp>(this, false, &CreateFunction);
    RegisterField(&FName,&aFName,mtString);
    RegisterField(&FValue,&aFValue,mtString);
    RegisterField(&FData,&aFData,mtString);
}

//---------------------------------------------------------------------------
TMyProp::~TMyProp()
{
}

//---------------------------------------------------------------------------
//TMyPropObject:
//---------------------------------------------------------------------------
TMyPropObject::TMyPropObject()
{
    RegisterNewClass<TMyProp,TMyPropObject>(this,false,&CreateFunction);
    RegisterField(&Properties,&aProperties,mtMyObject);
    RegisterField(&Methods,&aMethods,mtMyObject);
    RegisterField(&PropObjects,&aPropObjects,mtMyObject);
    RegisterField(&PropKinds,&aPropKinds,mtMyObject);
    Parent = NULL;
}

//---------------------------------------------------------------------------
TMyPropObject::~TMyPropObject()
{
}

//---------------------------------------------------------------------------
int TMyPropObject::ChildIsIn(AnsiString _Name, TMDelTList <TMyPropObject> List)
{
    int i;
    int result;
    result = -1;
    for (i = 0; i < List.Count; i++)
        if ( List[i].FName == _Name )
        {
            result = i;
            break;
        }
    return result;
}

//---------------------------------------------------------------------------
void TMyPropObject::InitByPropObject(TPropObject* _Object, TMyPropObject* _MyObject, TMyPropObject* _Parent)
{
    int i;
    _MyObject->FName = _Object->FName;
    _MyObject->Parent = _Parent;
    _MyObject->Methods.Clear();
    _MyObject->Properties.Clear();
    _MyObject->PropKinds.Clear();
    _MyObject->PropObjects.Clear();
}

//---------------------------------------------------------------------------
void TMyPropObject::ToPropObject(TPropObject* _Object, TMyPropObject* _MyObject)
{
    int i;
    int PropCount;
    int MethodCount;
    _Object->Name = _MyObject->FName;
    if(_Object->Parent)
        _Object->Parent->PropertyList[PropIsIn(_Object->Name, &(_Object->Parent->PropertyList[0]), _Object->Parent->PropertyList.Length)]->PropertyValue = _MyObject->FValue;
    PropertyCount( _Object->ThisObject, PropCount, MethodCount );
    for ( i = 0; i < MethodCount; i++ )
    {
        _Object->MethodList.Length++;
        _Object->MethodList[i] = new TProp();
    }
    for ( i = 0; i < PropCount; i++ )
    {
        _Object->PropertyList.Length++;
        _Object->PropertyList[i] = new TProp();
    }
    for ( i = 0; i < _MyObject->PropObjects.Count; i++ )
    {
        _Object->ChildList.Length++;
        _Object->ChildList[i] = new TPropObject();
        ToPropObject(_Object->ChildList[i], _MyObject->PropObjects.Items[i]);
    }
}

//---------------------------------------------------------------------------
int TMyPropObject::GetClassId(TObject* _Object)
{
    if (IS (_Object, __classid(TButton)))
        return cnButton;
    if (IS (_Object, __classid(TPanel)))
        return cnPanel;
    if (IS (_Object, __classid(TStaticText)))
        return cnLabel;
    if (IS (_Object, __classid(TCheckBox)))
        return cnCheckBox;
    if (IS (_Object, __classid(TComboBox)))
        return cnComboBox;
    if (IS (_Object, __classid(TListBox)))
        return cnListBox;
    if (IS (_Object, __classid(TGroupBox)))
        return cnGroupBox;
    if (IS (_Object, __classid(TRadioGroup)))
        return cnRadioGroup;
    if (IS (_Object, __classid(TScrollBar)))
        return cnScrollBar;
    if (IS (_Object, __classid(TRadioButton)))
        return cnRadioButton;
    if (IS (_Object, __classid(TMemo)))
        return cnMemo;
    if (IS (_Object, __classid(TEdit)))
        return cnEdit;
    if (IS (_Object, __classid(TForm)))
        return cnForm;
    if (IS (_Object, __classid(TPageControl)))
        return cnPageControl;
    if (IS (_Object, __classid(TTabSheet)))
        return cnTabSheet;
    return cnNone;
}

//---------------------------------------------------------------------------
void TMyPropObject::FromPropObject(TPropObject* _Object, TMyPropObject* _MyObject, bool GetId)
{
    int i, j;
    if ( GetId )
        ((TMyWinControl*)_MyObject)->ClassId = GetClassId(_Object->FObject);
    _MyObject->FName = _Object->Name;
    if(_Object->Parent)
        _MyObject->FValue = _Object->FParent->PropertyList[ PropIsIn(_Object->Name, &(_Object->Parent->PropertyList[0]), _Object->Parent->PropertyList.Length) ]->PropertyValue;
    for ( i = j = 0; i < _Object->MethodList.Length; i++ )
    {
        if (_Object->MethodList[i]->DefaultValue != _Object->MethodList[i]->PropertyValue)
        {
            _MyObject->Methods.Add(new TMyProp());
            _MyObject->Methods[j].FName = _Object->MethodList[i]->PropertyName;
            _MyObject->Methods[j].FValue = _Object->MethodList[i]->PropertyValue;
            _MyObject->Methods[j].FData = NULL;
            j++;
        }
    }
    for ( i = j = 0; i < _Object->PropertyList.Length; i++ )
    {
        if ((_Object->PropertyList[i]->PropertyName == "Top") || (_Object->PropertyList[i]->PropertyName == "Left") ||
           (_Object->PropertyList[i]->PropertyName == "Height") || (_Object->PropertyList[i]->PropertyName == "Width") ||
           (_Object->PropertyList[i]->PropertyName == "Name") || (_Object->PropertyList[i]->DefaultValue != _Object->PropertyList[i]->PropertyValue))
        {
            _MyObject->Properties.Add(new TMyProp());
            _MyObject->PropKinds.Add(new int(_Object->PropertyList[i]->PropertyKind));
            _MyObject->Properties[j].FName = _Object->PropertyList[i]->PropertyName;
            _MyObject->Properties[j].FValue = _Object->PropertyList[i]->PropertyValue;
            _MyObject->Properties[j].FData = _Object->PropertyList[i]->Data;
            j++;
        }
    }
    for ( i = j = 0; i < _Object->ChildList.Length; i++ )
        if ( ! Default ( _Object->ChildList[i] ) )
        {
            _MyObject->PropObjects.Add(new TMyPropObject());
            InitByPropObject(_Object->ChildList[i], _MyObject->PropObjects.Items[j], _MyObject);
            FromPropObject(_Object->ChildList[i], _MyObject->PropObjects.Items[j], false);
            j++;
        }
}

//---------------------------------------------------------------------------
bool TMyPropObject::Default(TPropObject* _Object)
{
    int i;
    int Result = true;
    if ( _Object )
    {
        for ( i = 0; i < _Object->ChildList.Length; i++ )
          Result = Default( ((TPropObject*)_Object->PropertyList[i]->ThisObject) );
        if ( _Object->Parent->PropertyList[PropIsIn(_Object->Name, &(_Object->Parent->PropertyList[0]), _Object->Parent->PropertyList.Length)]->PropertyValue != _Object->Parent->PropertyList[PropIsIn(_Object->Name, &(_Object->Parent->PropertyList[0]), _Object->Parent->PropertyList.Length)]->DefaultValue )
          Result = false;
    }
    return Result;
}

//---------------------------------------------------------------------------
