//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "LuaModuleV.h"
#include "LuaStationV.h"
#pragma hdrstop

#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"

#include "GlobalMain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGlobal *Global;
//---------------------------------------------------------------------------
//Клсс TLuaVariables
/*TLuaVariables* __fastcall TLuaVariables::GetAllGlobal()
{
}
TLuaVariables* __fastcall TLuaVariables::GetAllLocal()
{
}
*/
AnsiString GetLuaValue(int index, int type)
{
   switch (type)
    {
        case LUA_TNIL:
        {
            return ("NULL");
        }
        case LUA_TNUMBER:
        {
            return (FloatToStr(lua_tonumber(_LUA_,index)));
        }
        case LUA_TSTRING:
        {
            return (AnsiString(lua_tostring(_LUA_,index)));
        }
        case LUA_TNONE:
        {
            return ("None");
        }
        case LUA_TBOOLEAN:
        {
            return (BoolToStr(lua_toboolean(_LUA_,index),false));
        }
        case LUA_TLIGHTUSERDATA:
        case LUA_TTABLE:
        case LUA_TFUNCTION:
        case LUA_TUSERDATA:
        case LUA_TTHREAD:
        default:
            return (IntToHex((int)lua_topointer(_LUA_,index),8));
    }
};


int SetLuaValue(AnsiString type, AnsiString value)
{
    if (type=="number")
    {
        lua_pushnumber(_LUA_,StrToInt(value));
        return 0;
    }
    if (type=="string")
    {
        lua_pushstring(_LUA_,value.c_str());
        return 0;
    }
    lua_pushnil(_LUA_);
    return 1;
};


TLuaVariable* __fastcall TLuaVariables::GetLocal(AnsiString Name)
{
    TLuaVariable *Var = new TLuaVariable;
    lua_Debug *ar;
    int i=1,type,level=0;
    const char* name;

    while (lua_getstack(_LUA_, level, ar) != 0)
    {
        while ((name = lua_getlocal(_LUA_, ar, i++)) != NULL)
        {
            if(strcmp(Name.c_str(),name)==0) break; //We found the key
            lua_pop(_LUA_, 1);  /* remove variable value */
        }
    if(strcmp(Name.c_str(),name)==0) break;
    level++;
    }
    Var->Name = Name;
    type = lua_type(_LUA_,-1);
    Var->Type = lua_typename(_LUA_,type);
    Var->Value = GetLuaValue(-1,type);
    lua_pop(_LUA_,1);
    return (Var);
};


TLuaVariable* __fastcall TLuaVariables::GetGlobal(AnsiString Name)
{
    TLuaVariable *Var = new TLuaVariable;
    lua_pushstring(_LUA_,Name.c_str());
    lua_gettable(_LUA_,LUA_GLOBALSINDEX);
    Var->Name = Name;
    int type = lua_type(_LUA_,-1);
    Var->Type = lua_typename(_LUA_,type);
    Var->Value = GetLuaValue(-1,type);
    lua_pop(_LUA_,1);
    return (Var);
};

bool __fastcall TLuaVariables::SetGlobal(TLuaVariable *Var)
{
    lua_pushstring(_LUA_,Var->Name.c_str());
    if (SetLuaValue(Var->Type,Var->Value))
    {
        lua_settable(_LUA_,LUA_GLOBALSINDEX);
        return 1;
    }
    else
    {
        lua_pop(_LUA_,1);
        return 0;
    }
};

bool __fastcall TLuaVariables::SetLocal(TLuaVariable *Var)
{
    lua_Debug *ar;
    int i=0,level=0;
    const char* name;

    while (lua_getstack(_LUA_, level, ar) != 0)
    {
        while ((name = lua_getlocal(_LUA_, ar, i++)) != NULL)
        {
            if(strcmp(Var->Name.c_str(),name)==0) break; //We found the key
            lua_pop(_LUA_, 1);  /* remove variable value */
        }
    if(strcmp(Var->Name.c_str(),name)==0) break;
    level++;
    }
    SetLuaValue(Var->Type,Var->Value);
    name = lua_setlocal(_LUA_, ar ,i);
    return (strcmp(name,Var->Name.c_str())==0);
};

//---------------------------------------------------------------------------
__fastcall TGlobal::TGlobal(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
__fastcall TGlobal::~TGlobal()
{
    List->Free();
}
//---------------------------------------------------------------------------
void TGlobal::ViewGlobal()
{
    TListItem *Item;
    List->Clear();
    lua_pushvalue(_LUA_, LUA_GLOBALSINDEX);
	lua_pushnil(_LUA_);  /* first key */
	while (lua_next(_LUA_, -2))
	{
        Item=List->Items->Add();
        Item->Caption=AnsiString(lua_tostring(_LUA_, -2));
        Item->SubItems->Add(AnsiString(lua_typename(_LUA_, lua_type(_LUA_, -1))));
        if (lua_isstring(_LUA_,-1)) Item->SubItems->Add(AnsiString(lua_tostring(_LUA_,-1)));
        if (lua_isnumber(_LUA_,-1)) Item->SubItems->Add(FloatToStr(lua_tonumber(_LUA_,-1)));
		lua_pop(_LUA_, 1); // pop value, keep key for next iteration;
    }
    lua_pop(_LUA_, 1); // pop table of globals; */
}
//---------------------------------------------------------------------------

void TGlobal::ViewLocal()
{
    lua_Debug ar;
    int i,level=0;
    const char *name;
    TListItem *Item;
    this->List->Clear();

    while (lua_getstack(_LUA_, level, &ar) != 0)
        {
            i = 1;
            while ((name = lua_getlocal(_LUA_, &ar, i++)) != NULL)
            {
                Item=List->Items->Add();
                Item->Caption=AnsiString(name);
                Item->SubItems->Add(AnsiString(lua_typename(_LUA_, lua_type(_LUA_, -1))));
                if (lua_isstring(_LUA_,-1)) Item->SubItems->Add(AnsiString(lua_tostring(_LUA_,-1)));
                if (lua_isnumber(_LUA_,-1)) Item->SubItems->Add(FloatToStr(lua_tonumber(_LUA_,-1)));
                lua_pop(_LUA_, 1);
            }
        level++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TGlobal::ListClick(TObject *Sender)
{
//   ShowMessage(((TListView*)Sender)->Selected->Caption);
//    TVariable *temp =Debuger->GetGlobalValue(_LUA_,((TListView*)Sender)->Selected->Caption);
//    ShowMessage(temp->Name);
}
//---------------------------------------------------------------------------


