//---------------------------------------------------------------------------

#ifndef BaseToolVH
#define BaseToolVH

#include "VisView.hpp"
#include "VisCustomObj.hpp"

#include "LuaModuleV.h"
#include "LuaAttributeV.h"


//Переходы
const int Mouse_Down    = 0;
const int Mouse_Up      = 1;
const int Mouse_Move    = 2;
const int Key_Down      = 3;
const int Key_Up        = 4;
const int EXIT          = 5;
const int IdEscAction  = -1;
const AnsiString CharEvent[6] = {"Mouse_Down",
                                 "Mouse_Up",
                                 "Mouse_Move",
                                 "Key_Down",
                                 "Key_Up",
                                 "EXIT"};
//Типы блоков
const int btNone = 0;
const int Control = 1;
const int btMenu = 2;
//Типы формы
const int NoneForm = 0;
const int ToolFormOnly = 1;
const int ToolAndCustomForms = 2;
//Тип функчий содержащих исполняемый код блока схемы
typedef void  (__closure *TCommands)();
typedef bool (__closure *TCondition)();

typedef void (__closure *TChangeCursorPos)();

class TBindedGoEdit;
class TBindedBlockEdit;
class TBindedBaseToolEdit;
class TToolForm;

class COMMONAL_API TUserInterfaceParam : public TMyObject{
private:
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();

    TUserInterfaceParam();
    virtual ~TUserInterfaceParam(){};
    TChangeCursorPos ChangeCenter;
    TChangeCursorPos ChangeNewCursorPos;
    TChangeVec Center;
    TChangeVec NewCursorPos;
    void* Sender;
    WORD Key;
    TShiftState Shift;
    void Changed(void* Field);
};

extern COMMONAL_API TClassNode* TUserInterfaceParam::StaticType;

class TGo;

class TLuaModule;
class COMMONAL_API TBaseBlock : public TMyObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TLuaModule LuaModule;
    TBaseBlock();
    virtual ~TBaseBlock();
    void SetName(AnsiString _Name);
    int Id;
    int Type;
    TMDelTList<TGo> GOS;
};

extern COMMONAL_API TClassNode* TBaseBlock::StaticType;

class COMMONAL_API TGo : public TMyObject{
    void SetKey(WORD _Key);
    WORD GetKey();
    void SetMB(TMouseButton MB);
    TMouseButton GetMB();
    int FKey, FMouseButton;
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TGo();
    TGo(int _Event, TMouseButton _MouseButton, int _NextBlockId);
    TGo(int _Event, const WORD &_Key, int _NextBlockId);
    virtual ~TGo(){};
    int Event;
    __property WORD Key = { read = GetKey, write = SetKey };
    __property TMouseButton MouseButton = { read = GetMB, write = SetMB };
    int NextBlockId;
};

extern COMMONAL_API TClassNode* TGo::StaticType;

class COMMONAL_API TStateBlock : public TBaseBlock{
private:
    int FExexutedEvent;
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TStateBlock();
    TStateBlock(TCommands _Commands, int _Id, int _ExexutedEvent, int _Type, AnsiString _Description);
    TCommands Commands;
    __property int ExecutedEvent = {read = FExexutedEvent, write = FExexutedEvent};
    virtual ~TStateBlock(){};
};

extern COMMONAL_API TClassNode* TStateBlock::StaticType;

class COMMONAL_API TActionBlock : public TBaseBlock{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TActionBlock();
    TActionBlock(TCommands _Commands, int _Id, int _Type, AnsiString _Description);
    TCommands Commands;
    virtual ~TActionBlock(){};
};

extern COMMONAL_API TClassNode* TActionBlock::StaticType;

class COMMONAL_API TConditionalBlock : public TBaseBlock{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TConditionalBlock();
    TConditionalBlock(TCondition _Condition, int _Id, int _Type, AnsiString _Description);
    TCondition Condition;
    virtual ~TConditionalBlock(){};
};

extern COMMONAL_API TClassNode* TConditionalBlock::StaticType;

class COMMONAL_API TBaseTool : public TMyObject{
private:
    TPopupMenu* MenuToolCommands;
    TMTList< TMTList<TGo> > ToolCommands;
    void GetToolCommands(TMTList<TGo>* _GOS);
    void FillMenu();
    void __fastcall MenuClick(TObject *Sender);
    void ExecuteCommand(int _Index);
protected:
    void ProcessEscapeCommands();
    int FExecutedId;
    int FindIndexFromId(int Id);
    TCommands EscCommands;
    TMDelTList<TBaseBlock> Blocks;
    __property int ExecutedId = {read = FExecutedId};
    void AddGoToBlockId(int Id, int NextBlockId);
    void AddGoToBlockId(int Id, int NextBlockId, const int Event, TMouseButton MouseButton);
    void AddGoToBlockId(int Id, int NextBlockId, const int Event, const WORD& Key);
    void AddGoToBlockId(int Id, int TrueBlockId, int FalseBlockId);

    void GoToBlock(int Id);
    bool FindExit(int Event, TMouseButton MouseButton);
    bool FindExit(int Event, WORD &Key);
    bool FindExit(int Event);

    virtual void OnExit(void* Sender){};
    virtual void OnRender(){};
    virtual AnsiString OnHint(){return "";};
public:
    TUserInterfaceParam UIP;
    TVisPrimitiveObj* VCO;
    TVisPrimitiveObj* SnapCursor;

    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    int ImageId;
    TBaseTool();
    virtual ~TBaseTool();

    int GetUnicId();
    void SetName(AnsiString _Name);
    void AddStateBlock(TCommands _Commands, int Id, const int _ExecutedEvent, int _Type, AnsiString _Description);
    void AddActionBlock(TCommands _Commands, int Id, int _Type, AnsiString _Description);
    void AddConditionalBlock(TCondition Condition,int Id, int _Type, AnsiString _Description);

    virtual void MouseMove(void* Sender, TShiftState Shift, const TIntVec& CursorPosition);
    virtual void MouseDown(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition);
    virtual void MouseUp(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition);
    virtual void KeyDown(void* Sender, WORD &Key, TShiftState Shift);
    virtual void KeyUp(void* Sender, WORD &Key, TShiftState Shift);
    virtual void Exit(void* Sender);
    virtual void Render(void* Sender);

    virtual AnsiString Hint(void* Sender);
};

extern COMMONAL_API TClassNode* TBaseTool::StaticType;

class COMMONAL_API TMyControls : public TMyObject{
private:
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TMyControls();
    virtual ~TMyControls(){};
    TMDelTList< TMTList<TBaseTool> > Matrix;
    TMDelTList<int> ActiveIndices;
    int ActiveList;
    bool IndicesValid();
    void MouseMove(void* Sender, TShiftState Shift, const TIntVec& CursorPosition);
    void MouseDown(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition);
    void MouseUp(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition);
    void KeyDown(void* Sender, WORD &Key, TShiftState Shift);
    void KeyUp(void* Sender, WORD &Key, TShiftState Shift);
    void Exit(void* Sender);
    void Render(void* Sender);
    AnsiString Hint(void* Sender);
};

extern COMMONAL_API TClassNode* TMyControls::StaticType;

extern COMMONAL_API bool LuaConditionResult;
//---------------------------------------------------------------------------
#endif
