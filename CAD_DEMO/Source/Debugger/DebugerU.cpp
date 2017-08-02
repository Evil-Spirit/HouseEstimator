//---------------------------------------------------------------------------

#include <vcl.h>

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "LuaModuleV.h"
#include "LuaStationV.h"
#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"


#pragma hdrstop

#include "DebugerU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDebuger *Debuger;
//---------------------------------------------------------------------------
// Конструктор и деструктор для TVariables
//---------------------------------------------------------------------------

__fastcall TVariables::TVariables() : TObject()
{
    Name = new TStringList;
    Type = new TStringList;
    Value = new TStringList;
};

__fastcall TVariables::~TVariables()
{
    delete Name;
    delete Type;
    delete Value;
    delete this;
}

int __fastcall TVariables::Total()
{
    return Name->Count;
}
//---------------------------------------------------------------------------
// Конструктор и деструктор TDebuger
//---------------------------------------------------------------------------
__fastcall TDebuger::TDebuger(TComponent* Owner)
    : TForm(Owner)
{
    hThread = NULL;
    bDebug = false;
    LuaAllOpen();
}
//---------------------------------------------------------------------------
__fastcall TDebuger::~TDebuger()
{
    delete this->Local;
    delete this->Global;
    delete this->StackWnd;
    LuaAllClose();
//    delete this->Editor;
}
//---------------------------------------------------------------------------
//Процедуры и функции вне класса TDebuger
//---------------------------------------------------------------------------
int __fastcall DebugFunc( LPVOID lpParam )
{   DWORD i=0;
    while ((Debuger->bDebug)&&(Debuger->hThread))
    {
        i++;
        SuspendThread(Debuger->hThread);
    }
    Debuger->bDebug = Debuger->hThread = 0;
    ExitThread(0);
    return 0;
}
//---------------------------------------------------------------------------
void hooker(lua_State *l,lua_Debug *lua_d)
{
    SuspendThread(Debuger->hThread);
}
//---------------------------------------------------------------------------
//Методы класса TDebuger
//---------------------------------------------------------------------------
void __fastcall TDebuger::ExitItemClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TDebuger::TraceInItemClick(TObject *Sender)
{
    ResumeThread(hThread);
}
//---------------------------------------------------------------------------

void __fastcall TDebuger::StartItemClick(TObject *Sender)
{
    DWORD dwThrdParam = 1;
    unsigned int dwThreadId;
    bDebug = hThread = (HANDLE)BeginThread(
        NULL,                       // no security attributes
        0,                          // use default stack size
        DebugFunc,                  // thread function
        &dwThrdParam,               // argument to thread function
        CREATE_SUSPENDED,           // use default creation flags
        dwThreadId);                // returns the thread identifier

   if (hThread == NULL) ShowMessage( MSG_ERR_2 );
}
//---------------------------------------------------------------------------

void __fastcall TDebuger::DebugItemClick(TObject *Sender)
{
    TraceInItem->Enabled = this->bDebug;
    CloseItem->Enabled = this->bDebug;
    StartItem->Enabled = !(this->bDebug);
}
//---------------------------------------------------------------------------

void __fastcall TDebuger::StackItemClick(TObject *Sender)
{
    if (this->StackWnd!=NULL) this->StackWnd->WindowState=wsNormal;
    else this->StackWnd = new TStackWindow(Debuger);
}
//---------------------------------------------------------------------------

void __fastcall TDebuger::LocalItemClick(TObject *Sender)
{
    if (this->Local!=NULL) this->Local->WindowState=wsNormal;
    else
    {
        this->Local = new TGlobal(Debuger);
        this->Local->Caption="Local variables";
    }
}
//---------------------------------------------------------------------------

void __fastcall TDebuger::GlobalItemClick(TObject *Sender)
{
    if (this->Global!=NULL) this->Global->WindowState=wsNormal;
    else
    {
        this->Global = new TGlobal(Debuger);
        this->Global->Caption="Global variables";
    }
}
//---------------------------------------------------------------------------

void __fastcall TDebuger::CloseItemClick(TObject *Sender)
{
    this->bDebug = false;
    if (hThread) ResumeThread(hThread);
}
//---------------------------------------------------------------------------
//Невизуальные функции
//---------------------------------------------------------------------------
TVariable *TDebuger::GetGlobalValue(lua_State *l,AnsiString Name)
{
    TVariable *Var = new TVariable;
    lua_pushstring(l,Name.c_str());
    lua_gettable(l,LUA_GLOBALSINDEX);
    int type = lua_type(l,-1);
    Var->Name = Name;
    Var->Type = AnsiString(lua_typename(l,type));
    switch (type)
    {   
        case LUA_TNIL:      {Var->Value = "NULL";
                            break;}
        case LUA_TBOOLEAN:  {Var->Value = BoolToStr(lua_toboolean(l,-1),true);
                            break;}
        case LUA_TNUMBER:   {Var->Value = FloatToStr(lua_tonumber(l,-1));
                            break;}
        case LUA_TSTRING:   {Var->Value = AnsiString(lua_tostring(l,-1));
                            break;}
        case LUA_TLIGHTUSERDATA:
        case LUA_TTABLE:
        case LUA_TFUNCTION:
        case LUA_TUSERDATA:
        case LUA_TTHREAD:
        Var->Value = IntToHex(int(lua_topointer(l,-1)),8);
    }
    lua_pop(l,1);
    return Var;
}

void TDebuger::SetGlobalValue(lua_State *l, AnsiString Name, TVariable *Var)
{
   const char *Value=Var->Value.c_str();
   lua_pushstring(l,Name.c_str());
   if (Var->Type=="string") lua_pushstring(l,Value);
   if (Var->Type=="number") lua_pushnumber(l,Var->Value.ToInt());
   lua_settable (l,LUA_GLOBALSINDEX);
}

