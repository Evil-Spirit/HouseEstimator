//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "UI.h"
#include "main.h"
#include "SkinEngineV.h"
//---------------------------------------------------------------------------
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
        #include "MDIMetaActionListV.h"
        #include "MDIMetaActionV.h"
        #include "MDIMetaMenuItemV.h"
    #endif
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma package(smart_init)
TMetaMenuItem* curMenuItem = NULL;
TMetaAction* curAction = NULL;

const AnsiString aFUImageIndex = AnsiString("FUIImageIndex");
const AnsiString aFEnabled = AnsiString("FEnabled");
const AnsiString aFVisible = AnsiString("FVisible");

TMenuItem* FindMenuItem(TMenuItem* What,TMenuItem* Where)
{
    if (Where == What)
        return Where;
    TMenuItem* Result = NULL;
    for (int i=0;i<Where->Count;i++)
    {
        Result = FindMenuItem(What,Where->Items[i]);
        if (Result)
            return Result;
    }
    return Result;
}

TMenuItem* FindMenuItem(TMenuItem* What,TMenu* Where)
{
    TMenuItem* Result = NULL;
    for (int i=0;i<Where->Items->Count;i++)
    {
        Result = FindMenuItem(What,Where->Items->Items[i]);
        if (Result)
            return Result;
    }
    return Result;
}

TMyObject* TMetaUI::CreateFunction()
{
    return new TMetaUI();
}

TMetaUI::TMetaUI()
{
    RegisterNewClass< TMetaNode, TMetaUI >(this,false,&CreateFunction);
    FUImageIndex = -1;
    FEnabled = false;
    FVisible = false;
    RegisterField(&FUImageIndex,&aFUImageIndex,mtInt);
    RegisterField(&FEnabled,&aFEnabled,mtBool);
    RegisterField(&FVisible,&aFVisible,mtBool);
    ChildType = cNone;
    ImageIndex = iiMetaUI;
}

void TMetaUI::SetUImageIndex(int newint)
{
    FUImageIndex = newint;
    CheckFields();
}

void TMetaUI::SetEnabled(bool newint)
{
    FEnabled = newint;
    CheckFields();
}

void TMetaUI::SetVisible(bool newint)
{
    FVisible = newint;
    CheckFields();
}

TMetaUI::TMetaUI(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
{
    RegisterNewClass< TMetaNode, TMetaUI >(this,false,&CreateFunction);
    FUImageIndex = -1;
    FEnabled = false;
    FVisible = false;
    RegisterField(&FUImageIndex,&aFUImageIndex,mtInt);
    RegisterField(&FEnabled,&aFEnabled,mtBool);
    RegisterField(&FVisible,&aFVisible,mtBool);
    ChildType = cNone;
    ImageIndex = iiMetaUI;

    Parent = _Parent;
    Name = _Name;
}

TMyObject* TMetaActionList::CreateFunction()
{
    return new TMetaActionList();
}

const AnsiString aBMPSet = AnsiString("BMPSet");

TMetaActionList::TMetaActionList()
{
    RegisterNewClass< TMetaNode, TMetaActionList >(this,false,&CreateFunction);
    RegisterField(&BMPSet,&aBMPSet,mtMyObject);
    ImageIndex = iiMetaActionList;
    ChildType = cMetaAction;
    AL = new TActionList(NULL);
}

TMetaActionList::TMetaActionList(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
{
    RegisterNewClass< TMetaNode, TMetaActionList >(this,false,&CreateFunction);
    RegisterField(&BMPSet,&aBMPSet,mtMyObject);
    Parent = _Parent;
    Name = _Name;
    ImageIndex = iiMetaActionList;
    ChildType = cMetaAction;
    AL = new TActionList(NULL);
    CheckFields();
}

TMetaActionList::~TMetaActionList()
{
    while(AL->ActionCount)
        AL->Actions[0]->ActionList = NULL;
    delete AL;
}

bool TMetaActionList::CheckFields()
{
    AL->Images = GetIL();
    return true;
}

TImageList* TMetaActionList::GetIL()
{
    if (BMPSet.ADR)
        return BMPSet.ADR->IL;
    else
        return  NULL;
}

void TMetaActionList::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMetaActionList(Owner,this);
    #endif
}

TMyObject* TMetaAction::CreateFunction()
{
    return new TMetaAction();
}

TMetaAction::TMetaAction()
{
    RegisterNewClass< TMetaNode, TMetaAction >(this,false,&CreateFunction);
    ImageIndex = iiMetaAction;
    ChildType = cNone;
    RegisterField(&FUImageIndex,&aFUImageIndex,mtInt);
    RegisterField(&FEnabled,&aFEnabled,mtBool);
    RegisterField(&FVisible,&aFVisible,mtBool);

    FUImageIndex = -1;
    FEnabled = false;
    FVisible = false;
    Action = new TAction(NULL);
}

TMetaAction::TMetaAction(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
{
    RegisterNewClass< TMetaNode, TMetaAction >(this,false,&CreateFunction);
    Name = _Name;

    ImageIndex = iiMetaAction;
    ChildType = cNone;
    FUImageIndex = -1;
    FEnabled = false;
    FVisible = false;
    Parent = _Parent;
    RegisterField(&FUImageIndex,&aFUImageIndex,mtInt);
    RegisterField(&FEnabled,&aFEnabled,mtBool);
    RegisterField(&FVisible,&aFVisible,mtBool);
    FUImageIndex = -1;
    Action = new TAction(NULL);
    CheckFields();
}

TMetaAction::~TMetaAction()
{
    delete Action;
};

TMetaActionList* TMetaAction::GetMetaActionList()
{
    return ((TMetaActionList*)Parent);
}


bool TMetaAction::CheckFields()
{
    Action->ActionList = ((TMetaActionList*)Parent)->AL;
    Action->ImageIndex = FUImageIndex;
    Action->Enabled = FEnabled;
    Action->Visible = FVisible;
    Action->Caption = Description;
    if (TB->Exists(trUIExecute))
        Action->OnExecute = Config->LuaExecute;
    return true;
}


void TMetaAction::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMetaAction(Owner,this);
    #endif
}

bool TMetaAction::UsedTrigger(int Trigger)
{
    return (Trigger==trUIExecute) || (Trigger==trUIUpdate);
}

void TMetaAction::Update()
{
    TMetaAction* oldAction = curAction;
    curAction = this;
    if (TB->Exists(trUIUpdate))
        TB->Run(trUIUpdate);
    else if (!TB->Exists(trUIExecute))
    {
        Action->Enabled = false;
        Action->Visible = false;
    }
    else
    {
        Action->Enabled = FEnabled;
        Action->Visible = FVisible;
    }
    curAction = oldAction;
}

void TMetaAction::SetUImageIndex(int newint)
{
    FUImageIndex = newint;
    Action->ImageIndex = FUImageIndex;
}

void TMetaAction::SetEnabled(bool newint)
{
    FEnabled = newint;
    Action->Enabled = FEnabled;
}

void TMetaAction::SetVisible(bool newint)
{
    FVisible = newint;
    Action->Visible = FVisible;
}


void TMetaAction::Execute()
{
    TMetaAction* oldAction = curAction;
    curAction = this;
    TB->Run(trUIExecute);
    curAction = oldAction;
}


TMyObject* TMetaMenuItem::CreateFunction()
{
    return new TMetaMenuItem();
}

const AnsiString aMetaAction = AnsiString("MetaAction");
const AnsiString aChildBMPSet = AnsiString("ChildBMPSet");

TMetaMenuItem::TMetaMenuItem()
{
    RegisterNewClass< TMetaUI, TMetaMenuItem >(this,false,&CreateFunction);
    RegisterField(&ChildBMPSet,&aChildBMPSet,mtMyObject);
    RegisterField(&MetaAction,&aMetaAction,mtMyObject);
    ImageIndex = iiMetaMenuItem;
    MI = new TMenuItem(NULL);
    ChildType = cMetaMenuItem;
}

TMetaMenuItem::TMetaMenuItem(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
    :TMetaUI(_Parent,_ID,_Name)
{
    RegisterNewClass< TMetaUI, TMetaMenuItem >(this,false,&CreateFunction);
    RegisterField(&ChildBMPSet,&aChildBMPSet,mtMyObject);
    RegisterField(&MetaAction,&aMetaAction,mtMyObject);
    ImageIndex = iiMetaMenuItem;
    MI = new TMenuItem(NULL);
    ChildType = cMetaMenuItem;
    CheckFields();
}

TMetaMenuItem::~TMetaMenuItem()
{
    if ( FindMenuItem(MI,Config->MainMenu1) )
        Config->MainMenu1->Items->Remove(MI);
    while (MI->Count)
        MI->Remove(MI->Items[MI->Count-1]);
    delete MI;
}

void TMetaMenuItem::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDIMetaMenuItem(Owner,this);
    #endif
}

bool TMetaMenuItem::CheckFields()
{
    if (MetaAction.ADR)
        MI->Action = MetaAction.ADR->Action;
    else
    {
        MI->Action = NULL;
        MI->Enabled = Enabled;
        MI->Visible = Visible;
        MI->ImageIndex = UImageIndex;
        MI->Caption = Description;
    }
    MI->SubMenuImages = GetIL();
    if (TB->Exists(trUIExecute))
        MI->OnClick = Config->LuaExecute;

    if ( Parent->Is(TMetaMenuItem::StaticType) && !FindMenuItem(MI, ((TMetaMenuItem*)Parent)->MI ) )
        ((TMetaMenuItem*)Parent)->MI->Add(MI);
    else if ( !FindMenuItem(MI,Config->MainMenu1) )
    {
        Config->MainMenu1->Items->Add(MI);
        /*Config->*/SkinEngine->MenuItemAdded(Config->MainMenu1);
        /*Config->*/SkinEngine->UpdateTopMenu(Config);
    }
    return true;
}

bool TMetaMenuItem::UsedTrigger(int Trigger)
{
    return (Trigger==trUIUpdate) || (Trigger==trUIExecute);
}

void TMetaMenuItem::Update()
{
    TMetaMenuItem* oldMI = curMenuItem;
    curMenuItem = this;
    if (TB->Exists(trUIUpdate))
        TB->Run(trUIUpdate);
    else if (!MetaAction.ADR)
    {
        MI->Enabled = Enabled;
        MI->Visible = Visible;
    }
    curMenuItem = oldMI;
}

void TMetaMenuItem::Execute()
{
    TMetaMenuItem* oldMI = curMenuItem;
    curMenuItem = this;
    TB->Run(trUIExecute);
    curMenuItem = oldMI;
}

TImageList* TMetaMenuItem::GetIL()
{
    if (ChildBMPSet.ADR)
        return ChildBMPSet.ADR->IL;
    else
        return  NULL;
}

void ApplySkinTheme(TControl *Control)
{
  /*Config->*/SkinEngine->AddControl(Control);
  for (int n=0;n<Control->ComponentCount;n++)
    if (IS(Control->Components[n],__classid(TControl)))
      ApplySkinTheme((TControl*)Control->Components[n]);
}
