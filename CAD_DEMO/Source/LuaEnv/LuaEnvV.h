//---------------------------------------------------------------------------

#ifndef LuaEnvVH
#define LuaEnvVH

#include "Scintilla.h"
#include "SciLexer.h"
#include "FileMapper.h"
#include "LuaModuleV.h"
extern "C"
{
    #include "lualib.h"
    #include "lauxlib.h"
    #include "iup.h"
    #include "iuplua.h"
    #include "iupcontrols.h"
    #include "luacontrols.h"
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//Описание классов и типов переменных ЛУА
//---------------------------------------------------------------------------
class COMMONAL_API TLuaVariable : public TMyObject
{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TLuaVariable();
    virtual ~TLuaVariable();
    AnsiString Name,Type,Value;
};

static COMMONAL_API TClassNode* TLuaVariable::StaticType;
//---------------------------------------------------------------------------
class COMMONAL_API TLuaRegObject :public TMyRegObject
{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TLuaRegObject();
    virtual ~TLuaRegObject();
    TMDelTList<TLuaModule> Modules;
};

static COMMONAL_API TClassNode* TLuaRegObject::StaticType;
//---------------------------------------------------------------------------
class COMMONAL_API TLuaVariables
{
    public:
    __fastcall TLuaVariables(){};
    __fastcall ~TLuaVariables(){};
    void __fastcall FillGlobals(TMDelTList<TLuaVariable>* Vars);
    void __fastcall FillLocals(TMDelTList<TLuaVariable>* Vars);
    void __fastcall FillStack(TMDelTList<TLuaVariable>* Vars);
    //void __fastcall FillTable(TMDelTList<TLuaVariable>* Vars, int index);
    //void __fastcall FillTable(TMDelTList<TLuaVariable>* Vars, AnsiString name);


    TLuaVariable* __fastcall GetLocal(AnsiString Name, TLuaVariable *LuaVar);
    TLuaVariable* __fastcall GetGlobal(AnsiString Name, TLuaVariable *LuaVar);
    bool __fastcall SetGlobal(TLuaVariable *Var);
    bool __fastcall SetLocal(TLuaVariable *Var);
};

class TMessageHandler
{
    public:
    void __fastcall MyWndProc(tagMSG& , bool&);
};

extern COMMONAL_API lua_State* _LUA_;

COMMONAL_API void LuaAllOpen();
COMMONAL_API void LuaAllClose();
COMMONAL_API void DisplayMessage(int CODE);

COMMONAL_API AnsiString GetLuaValue(int index);
COMMONAL_API void InspectVariable(HANDLE, AnsiString);
COMMONAL_API int SetLuaValue(AnsiString type, AnsiString value);

extern PACKAGE TMessageHandler *MessageHandler;
////////////////////////////////////////////////////////////////
//Debuger features
////////////////////////////////////////////////////////////////
//Project mode
#define MODE_NORMAL 0
#define MODE_DEBUG  1

//Debug modes
#define DBGMODE_STOP        0
#define DBGMODE_WORK        1
#define DBGMODE_PAUSE       2
#define DBGMODE_TRACEIN     3
#define DBGMODE_STEPOVER    4
#define DBGMODE_BREAKPNT    5

//Messages from LUAModule:
#define MSG_LINEHOOK    1000
#define MSG_CALLHOOK	1001
#define MSG_RETHOOK		1002
#define MSG_BREAKPOINT	1003
#define MSG_READY       1004
#define MSG_SETMODE     1005
#define MSG_UPDATE      1006
#define MSG_FINISH      1007
#define MSG_FMSTATE     1008
#define MSG_UPDATEWATCH 1009
#define MSG_ERROR		1010
#define MSG_GETEVALUATE 1011


//Messages to LUAModule:
#define MSG_INIT		    2000
#define MSG_SETMASKHOOK		2001
#define MSG_GETLOCALVALUE	2002
#define MSG_GETGLOBALVALUE	2003
#define MSG_GETLOCALALL		2004
#define MSG_GETGLOBALALL	2005
#define MSG_SETLOCAL		2006
#define MSG_SETGLOBAL		2007
#define MSG_INSPECT 		2008
#define MSG_STOP		    2009
#define MSG_PAUSE		    2010
#define MSG_RESUME		    2011
#define MSG_TRACEIN         2012
#define MSG_STEPOVER        2013
#define MSG_GETMODE         2015
#define MSG_UPDATEALL       2016
#define MSG_EVALUATE        2017

extern COMMONAL_API int DebugMode;
extern COMMONAL_API GUID LuaModuleGUID;
extern COMMONAL_API AnsiString LuaFunctionGUID;
extern COMMONAL_API int LuaEnvMode;
extern COMMONAL_API HANDLE DebugHnd;
extern COMMONAL_API DWORD ApplHnd;
extern COMMONAL_API TFileMapStream *FileMap;
////////////////////////////////////////////////////////////////
//End of Debuger features
////////////////////////////////////////////////////////////////
#endif
