// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "LuaModuleV.h"
#include "LuaStationV.h"
#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"



#include "DebugerU.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TDebuger *Debuger;
//---------------------------------------------------------------------------
// Êîíñòðóêòîð è äåñòðóêòîð äëÿ TVariables
//---------------------------------------------------------------------------

 TVariables::TVariables() : TObject()
{
    Name = new TStringList;
    Type = new TStringList;
    Value = new TStringList;
};

 TVariables::~TVariables()
{
    delete Name;
    delete Type;
    delete Value;
    delete this;
}

int  TVariables::Total()
{
    return Name->Count;
}
//---------------------------------------------------------------------------
// Êîíñòðóêòîð è äåñòðóêòîð TDebuger
//---------------------------------------------------------------------------
 TDebuger::TDebuger(TComponent* Owner)
    : TForm(Owner)
{
    hThread = NULL;
    bDebug = false;
    LuaAllOpen();
}
//---------------------------------------------------------------------------
 TDebuger::~TDebuger()
{
    delete this->Local;
    delete this->Global;
    delete this->StackWnd;
    LuaAllClose();
//    delete this->Editor;
}
//---------------------------------------------------------------------------
//Ïðîöåäóðû è ôóíêöèè âíå êëàññà TDebuger
//---------------------------------------------------------------------------
int  DebugFunc( LPVOID lpParam )
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
//Ìåòîäû êëàññà TDebuger
//---------------------------------------------------------------------------
void  TDebuger::ExitItemClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

void  TDebuger::TraceInItemClick(TObject *Sender)
{
    ResumeThread(hThread);
}
//---------------------------------------------------------------------------

void  TDebuger::StartItemClick(TObject *Sender)
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

void  TDebuger::DebugItemClick(TObject *Sender)
{
    TraceInItem->Enabled = this->bDebug;
    CloseItem->Enabled = this->bDebug;
    StartItem->Enabled = !(this->bDebug);
}
//---------------------------------------------------------------------------

void  TDebuger::StackItemClick(TObject *Sender)
{
    if (this->StackWnd!=NULL) this->StackWnd->WindowState=wsNormal;
    else this->StackWnd = new TStackWindow(Debuger);
}
//---------------------------------------------------------------------------

void  TDebuger::LocalItemClick(TObject *Sender)
{
    if (this->Local!=NULL) this->Local->WindowState=wsNormal;
    else
    {
        this->Local = new TGlobal(Debuger);
        this->Local->Caption="Local variables";
    }
}
//---------------------------------------------------------------------------

void  TDebuger::GlobalItemClick(TObject *Sender)
{
    if (this->Global!=NULL) this->Global->WindowState=wsNormal;
    else
    {
        this->Global = new TGlobal(Debuger);
        this->Global->Caption="Global variables";
    }
}
//---------------------------------------------------------------------------

void  TDebuger::CloseItemClick(TObject *Sender)
{
    this->bDebug = false;
    if (hThread) ResumeThread(hThread);
}
//---------------------------------------------------------------------------
//Íåâèçóàëüíûå ôóíêöèè
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

