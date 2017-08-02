//---------------------------------------------------------------------------

#ifndef BaseToolVH
#define BaseToolVH

#include "VisView.hpp"
#include "VisCustomObj.hpp"
#include "MyEdit.h"

const int IdEscAction    = -1;
//Переходы
const int Mouse_Down    = 1;
const int Mouse_Up      = 2;
const int Mouse_Move    = 3;
const int Key_Down      = 4;
const int Key_Up        = 5;
const int ESC           = 6;
const int EXIT          = 11;
//Типы блоков
const int Block_State = 0;
const int Block_Action = 1;
const int Block_Conditional = 2;
//Тип функчий содержащих исполняемый код блока схемы

typedef void  (__closure *TCommands)();
typedef bool (__closure *TCondition)();

class TEditor2D;

class TUserInterfaceParam{
public:
    TUserInterfaceParam(){Sender=NULL;};
    ~TUserInterfaceParam(){};
    TIntVec OldCursorPos;
    TIntVec NewCursorPos;
    TEditor2D* Sender;
    WORD Key;
    TShiftState Shift;
};

class TGo;

class TBaseBlock : public TMyObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TBaseBlock();
    virtual ~TBaseBlock(){};
    int Id;
    TMDelTList<TGo> GOS;
};

TClassNode* TBaseBlock::StaticType = NULL;

class TGo : public TMyObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TGo(){};
    TGo(int _Event, TMouseButton _MouseButton, int _NextBlockId);
    TGo(int _Event, const WORD &_Key, int _NextBlockId);
    virtual ~TGo(){};
    int Event;
    WORD Key;
    TMouseButton MouseButton;
    int NextBlockId;
};

TClassNode* TGo::StaticType = NULL;

class TStateBlock : public TBaseBlock{
private:
    int FExexutedEvent;
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TStateBlock(){};
    TStateBlock(TCommands _Commands, int _Id, int _ExexutedEvent);
    TCommands Commands;
    __property int ExecutedEvent = {read = FExexutedEvent};
    virtual ~TStateBlock(){};
};

TClassNode* TStateBlock::StaticType = NULL;

class TActionBlock : public TBaseBlock{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TActionBlock(){};
    TActionBlock(TCommands _Commands, int _Id);
    TCommands Commands;
    virtual ~TActionBlock(){};
};

TClassNode* TActionBlock::StaticType = NULL;

class TConditionalBlock : public TBaseBlock{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TConditionalBlock(){};
    TConditionalBlock(TCondition _Condition, int _Id);
    TCondition Condition;
    virtual ~TConditionalBlock(){};
};

TClassNode* TConditionalBlock::StaticType = NULL;

class TBaseTool : public TMyObject{
private:
    TMDelTList<TBaseBlock> Blocks;
    int FExecutedId;
    int FindIndexFromId(int Id);
    void ProcessEscapeCommands();
protected:
    TCommands EscCommands;
    TUserInterfaceParam UIP;
    TVisPrimitiveObj* VCO;
    TVisPrimitiveObj* SnapCursor;
    __property int ExecutedId = {read = FExecutedId};
    void AddStateBlock(TCommands _Commands, int Id, const int _ExecutedEvent);
    void AddActionBlock(TCommands _Commands, int Id);
    void AddConditionalBlock(TCondition Condition,int Id);
    void AddGoToBlockId(int Id, int NextBlockId);
    void AddGoToBlockId(int Id, int NextBlockId, const int Event, TMouseButton MouseButton);
    void AddGoToBlockId(int Id, int NextBlockId, const int Event, const WORD &Key);
    void AddGoToBlockId(int Id, int TrueBlockId, int FalseBlockId);

    void GoToBlock(int Id);
    bool FindExit(int Event, TMouseButton MouseButton);
    bool FindExit(int Event, WORD &Key);
    bool FindExit(int Event);

    virtual void OnExit(TEditor2D* Sender){};
    virtual void OnRender(){};
    virtual AnsiString OnHint(){return "";};
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    int ImageId;
    TBaseTool();
    virtual ~TBaseTool();
    virtual void MouseMove(TEditor2D* Sender, TShiftState Shift);
    virtual void MouseDown(TEditor2D* Sender, TMouseButton Button, TShiftState Shift);
    virtual void MouseUp(TEditor2D* Sender, TMouseButton Button, TShiftState Shift);
    virtual void KeyDown(TEditor2D* Sender, WORD &Key, TShiftState Shift);
    virtual void KeyUp(TEditor2D* Sender, WORD &Key, TShiftState Shift);
    virtual void Exit(TEditor2D* Sender);
    virtual void Render(TEditor2D* Sender);

    virtual AnsiString Hint(TEditor2D* Sender);
};

TClassNode* TBaseTool::StaticType = NULL;

class TMyControls : public TMyObject{
private:
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TMyControls();
    virtual ~TMyControls(){};
    TMDelTList< TMDelTList<TBaseTool> > Matrix;
    TMDelTList<int> ActiveIndices;
    int ActiveList;
    void MouseMove(TEditor2D* Sender, TShiftState Shift);
    void MouseDown(TEditor2D* Sender, TMouseButton Button, TShiftState Shift);
    void MouseUp(TEditor2D* Sender, TMouseButton Button, TShiftState Shift);
    void KeyDown(TEditor2D* Sender, WORD &Key, TShiftState Shift);
    void KeyUp(TEditor2D* Sender, WORD &Key, TShiftState Shift);
    void Exit(TEditor2D* Sender);
    void Render(TEditor2D* Sender);
    AnsiString Hint(TEditor2D* Sender);
};

TClassNode* TMyControls::StaticType = NULL;

//---------------------------------------------------------------------------
#endif
