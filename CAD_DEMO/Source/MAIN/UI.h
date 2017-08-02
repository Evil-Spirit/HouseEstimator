//---------------------------------------------------------------------------

#ifndef UIH
#define UIH
//---------------------------------------------------------------------------
#include "MetaClasses.h"

TMenuItem* FindMenuItem(TMenuItem* What,TMenuItem* Where);
TMenuItem* FindMenuItem(TMenuItem* What,TMenu* Where);

class TMetaUI : public TMetaNode{
private:
    int FUImageIndex;
    bool FEnabled;
    bool FVisible;
    void SetUImageIndex(int newint);
    void SetEnabled(bool newint);
    void SetVisible(bool newint);
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    __property int UImageIndex = {read = FUImageIndex,write = SetUImageIndex};
    __property bool Enabled = {read = FEnabled,write = SetEnabled};
    __property bool Visible = {read = FVisible,write = SetVisible};
    TMetaUI();
    TMetaUI(TMetaNode *_Parent,int _ID,const AnsiString& _Name);
    virtual ~TMetaUI(){};
};
TClassNode* TMetaUI::StaticType = NULL;

class TMetaActionList : public TMetaNode{
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaActionList();
    TMetaActionList(TMetaNode *_Parent,int _ID,const AnsiString& _Name);
    virtual ~TMetaActionList();
    TPointer<TBMPSet> BMPSet;
    TImageList* GetIL();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    TActionList *AL;
    bool CheckFields();
};
TClassNode* TMetaActionList::StaticType = NULL;

class TMetaAction : public TMetaNode{
private:
    TMetaActionList *GetMetaActionList();
    int FUImageIndex;
    bool FEnabled;
    bool FVisible;
    void SetUImageIndex(int newint);
    void SetEnabled(bool newint);
    void SetVisible(bool newint);
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaAction();
    TMetaAction(TMetaNode *_Parent,int _ID,const AnsiString& _Name);
    virtual ~TMetaAction();
    __property int UImageIndex = {read = FUImageIndex,write = SetUImageIndex};
    __property bool Enabled = {read = FEnabled,write = SetEnabled};
    __property bool Visible = {read = FVisible,write = SetVisible};
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    virtual bool UsedTrigger(int Trigger);
    TAction *Action;
    bool CheckFields();
    void Update();
    void Execute();
    __property TMetaActionList* MetaActionList = {read = GetMetaActionList};
};
TClassNode* TMetaAction::StaticType = NULL;

class TMetaMenuItem : public TMetaUI{
    TMetaAction* GetAssociatedAction(){return MetaAction.ADR;};
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMetaMenuItem();
    TMetaMenuItem(TMetaNode *_Parent,int _ID,const AnsiString& _Name);
    virtual ~TMetaMenuItem();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    TMenuItem *MI;
    TPointer<TMetaAction> MetaAction;
    __property TMetaAction* AssociatedAction = {read = GetAssociatedAction};
    bool CheckFields();
    virtual bool UsedTrigger(int Trigger);
    void Update();
    void Execute();
    TPointer<TBMPSet> ChildBMPSet;
    TImageList* GetIL();
};
TClassNode* TMetaMenuItem::StaticType = NULL;

extern TMetaMenuItem* curMenuItem;
extern TMetaAction* curAction;

COMMONAL_API void ApplySkinTheme(TControl *Control);
#endif
