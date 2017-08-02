//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LuaModuleV.h"
#include "LuaEnvV.h"
#include "LuaStationV.h"
#include "LuaEditorV.h"
#include "QuckList.h"
#include "MDILuaEditorV.h"
#include "OutPutV.h"
#include "MyDialogU.h"

#include "tolua++.h"
#include "LuaAttributeV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
TClassNode* TLuaModule::StaticType = NULL;

//---------------------------------------------------------------------------
/*void PUSHATTRIBUTEVALUE(lua_State* tolua_S,int Type,void* Value,const AnsiString& TypeName)
{
    switch(Type)
    {
        case mtInt:
            tolua_pushnumber(tolua_S, *( (*)Address)  );
        break;
        case mtString:
            tolua_pushstring(tolua_S, ((AnsiString*)Address)->c_str() );
        break;
        case mtFloat:
            tolua_pushnumber(tolua_S, *((float*)Address) );
        break;
        case mtCharString:
            tolua_pushstring(tolua_S, (char*)Address );
        break;
        case mtMyObject:
            tolua_pushusertype(tolua_S,Address, (Address!= NULL) ? TypeName.c_str() : "TMyObject" );
        break;
        case mtVCLObject:
            tolua_pushusertype(tolua_S,Address, (Address!= NULL) ? TypeName.c_str() : "TObject" );
        break;
        case mtAnyThing:
            tolua_pushusertype(tolua_S,Address, (Address!= NULL) ? TypeName.c_str() : "userdata" );
        break;
        case mtDouble:
            tolua_pushnumber(tolua_S, *((double*)Address) );
        break;
        case mtBool:
            tolua_pushboolean(tolua_S, *((bool*)Address) );
        break;
        default:
            tolua_pushuserdata(tolua_S,Address);
        break;
    }
}  */

void PUSHATTRIBUTE(lua_State* tolua_S,TLuaAttribute* LA)
{
    switch(LA->Type)
    {
        case mtInt:
            tolua_pushnumber(tolua_S, LA->VALUE.ToInt()  );
        break;
        case mtString:
            tolua_pushstring(tolua_S, LA->VALUE.c_str() );
        break;
        case mtFloat:
            tolua_pushnumber(tolua_S,  TO_DOUBLE(LA->VALUE) );
        break;
        case mtCharString:
            tolua_pushstring(tolua_S, LA->VALUE.c_str() );
        break;
        case mtMyObject:
            tolua_pushusertype(tolua_S,LA->Value, (LA->Value!= NULL) ? LA->ObjectTypeName.c_str() : "TMyObject" );
        break;
        case mtVCLObject:
            tolua_pushusertype(tolua_S,LA->Value, (LA->Value!= NULL) ? LA->ObjectTypeName.c_str() : "TObject" );
        break;
        case mtAnyThing:
            tolua_pushusertype(tolua_S,LA->Value, (LA->Value!= NULL) ? LA->ObjectTypeName.c_str() : "userdata" );
        break;
        case mtDouble:
            tolua_pushnumber(tolua_S, TO_DOUBLE(LA->VALUE) );
        break;
        case mtBool:
            tolua_pushboolean(tolua_S, LA->VALUE.ToInt() );
        break;
        default:
            tolua_pushuserdata(tolua_S,LA->Value);
        break;
    }
}



void LuaCallBack(void* Table,const AnsiString& TableTypeName,const AnsiString& CallBackName,TMDelTList<TLuaAttribute>& Args  )
{
    //Sender::CallBackName(Sender,args)
    
    //push main table
    tolua_pushusertype(_LUA_,Table, TableTypeName.c_str() );

    //push function to be called
    lua_pushstring(_LUA_, CallBackName.c_str() );
    lua_gettable(_LUA_, -2);

    //push arguments
    tolua_pushusertype(_LUA_,Table, TableTypeName.c_str() );
    for ( int i=0;i<Args.Count;i++ )
        PUSHATTRIBUTE(_LUA_,Args.Items[i]);
    lua_call(_LUA_,Args.Count+1,0);

    //pop main table
    lua_pop(_LUA_, 1);
}


void RunCode(void *Obj, AnsiString Type, AnsiString Code, AnsiString Name)
{
    AnsiString NewCode;
    int st=lua_gettop(_LUA_);
    tolua_pushusertype(_LUA_,Obj,Type.c_str());

    NewCode="function RunCode"+LuaFunctionGUID+"("+Name+");";
    NewCode+=Code;
    NewCode+="end;RunCode"+LuaFunctionGUID+'('+Name+");";

    int status=0;
    status = luaL_loadbuffer(_LUA_, NewCode.c_str(), NewCode.Length(), "Return value");
    if (status!=0) {}    //For case if error occured during loading module
    status = lua_pcall(_LUA_,1,LUA_MULTRET,0);
    if (status!=0) {}    //For case if error occured during executing module

    lua_settop(_LUA_,st);
    lua_pushstring(_LUA_,AnsiString("RunCode"+LuaFunctionGUID).c_str());
    lua_pushnil(_LUA_);
    lua_settable(_LUA_,LUA_GLOBALSINDEX);  //Clearing global function
}

void ShowError(TMyObject* LM)
{
    AnsiString _Error = AnsiString(lua_tostring(_LUA_,0))+ AnsiString("\n")+AnsiString(lua_tostring(_LUA_,-1));
    if (!_Error.Trim().IsEmpty())
    {
        int index = _Error.Pos(AnsiString("]:"));
        if (index!=0 && LM)
        {
            _Error.Delete(index,2);
            int index2 = _Error.Pos(AnsiString(":"));
            if (index2!=0)
            {
                if (ISINTEGER(_Error.SubString(index,index2-index)))
                    LinkStdOut(_Error,true,LM,_Error.SubString(index,index2-index).ToInt()-2,-10);
                return;
            }
        }           
        StdOut(_Error,true);
    } 
}

bool RUN_LUA(const AnsiString& Code)
{
    _TRY_
        int __ERROR = lua_dostring(_LUA_,Code.c_str());
        if (__ERROR!=0)
            ShowError(NULL);
        return true;
    _ENDTRY_(AnsiString("<RUN_LUA>: Ошибка при выполнении LUA-Модуля "),ShowError(NULL);return false;);
}

COMMONAL_API bool RUN_TEXT(TLuaModule *LM)
{
    _TRY_

        if (LM->MS->Size==0)
            return false;
        int __ERROR = lua_dostring(_LUA_,(const char *)LM->CODE.c_str());
        if (__ERROR!=0)
            ShowError(LM);
        return true;

    _ENDTRY_(AnsiString("<RUN_BUFFER>: Ошибка при выполнении LUA-Модуля ")+LM->Name,ShowError(LM);return false;);
}

bool RUN_BUFFER(TLuaModule *LM)
{
    _TRY_

        if (LM->MS->Size==0)
            return false;
        int __ERROR = lua_dobuffer(_LUA_,(const char *)LM->MS->Memory,LM->MS->Size,AnsiString(GUIDToString(LuaModuleGUID)+IntToStr((int)LM)).c_str());
        if (__ERROR!=0)
            ShowError(LM);
        return true;

    _ENDTRY_(AnsiString("<RUN_BUFFER>: Ошибка при выполнении LUA-Модуля ")+LM->Name,ShowError(LM);return false;);
}

bool ChangeOneFunctionView(AnsiString& CODE2,int Pos)
{
    int i=Pos;
    int i0;
    while ( CODE2[i]!='(' && i<=CODE2.Length() )
        i++;
    if (i>CODE2.Length())
        return false;
    i0 = Pos+LUA_TEXT_FUNCTION2.Length();
    AnsiString FuncName =CODE2.SubString(i0,i-i0).Trim();
    CODE2.Delete(Pos,i-Pos);
    CODE2.Insert(FuncName+LUA_TEXT_EQUAL+LUA_TEXT_FUNCTION2,Pos);
    return true;
}

void ChangeFunctionView(const AnsiString& CODE,AnsiString& CODE2)
{
    CODE2 = CODE;
    AnsiString Function_Replacer = LUA_TEXT_DOWN_LINE+LUA_TEXT_FUNCTION2.SubString(2,LUA_TEXT_FUNCTION2.Length()-1);
    while (CODE.Pos(Function_Replacer)!=0)
        Function_Replacer = LUA_TEXT_DOWN_LINE+Function_Replacer;
    int index = CODE2.Pos(LUA_TEXT_FUNCTION2);
    while (index!=0)
    {
        ChangeOneFunctionView(CODE2,index);
        Replace(CODE2,LUA_TEXT_FUNCTION2,Function_Replacer);
        index = CODE2.Pos(LUA_TEXT_FUNCTION2);
    }
    ReplaceAll(CODE2,Function_Replacer,LUA_TEXT_FUNCTION2);
}

void CreateGlobal(const AnsiString& CODE,AnsiString& CODE2)
{
    ChangeFunctionView(CODE,CODE2);
    CODE2 = LUA_TEXT_GLOBAL + LUA_TEXT_EQUAL + LUA_TEXT_OPEN_SCOPE + LUA_TEXT_NEWLINE +
            CODE2 + LUA_TEXT_NEWLINE +
            LUA_TEXT_CLOSE_SCOPE;
}



static int dumpwriter(lua_State* L, const void* p, size_t size, void* u)
{
 UNUSED(L);
 TMemoryStream *MS = (TMemoryStream *)u;
 MS->Write(p,size);
 return true;
}

const AnsiString aName = AnsiString("Name");
const AnsiString aCODE = AnsiString("CODE");
const AnsiString aGlobal = AnsiString("Global");
const AnsiString aHasForm = AnsiString("HasForm");
const AnsiString aDebug = AnsiString("Debug");
const AnsiString aBreakPoints = AnsiString("BreakPoints");
const AnsiString aDialog = AnsiString("Dialog");
const AnsiString aGUID = AnsiString("GUID");

//    void WriteOne(const void * Data,int type,TMemoryStream *MS);
  //  int ReadOne( void * Data,int type,TMemoryStream *MS);


void TLuaModule::WriteData(TMemoryStream *_MS) const
{
    TMyObject::WriteData(_MS);
/*    WriteOne(&aName,mtString,_MS);
    WriteOne(&mtString,mtInt,_MS);
    WriteOne(&Name,mtString,_MS);

    WriteOne(&aGlobal,mtString,_MS);
    WriteOne(&mtBool,mtInt,_MS);
    WriteOne(&Global,mtBool,_MS);

    WriteOne(&aHasForm,mtString,_MS);
    WriteOne(&mtBool,mtInt,_MS);
    WriteOne(&HasForm,mtBool,_MS);

    TMemoryStream* MS = new TMemoryStream();

    int l = CODE.Length();
    char *s = CODE.c_str();

    if (luaL_loadbuffer(_LUA_, s, l, "")==0)
        lua_dump (_LUA_, dumpwriter, MS);

    int mainsize = MS->Size;
    WriteOne(&(mainsize),mtInt,_MS);
    MS->Position = 0;
    _MS->Write(MS->Memory,mainsize);
    delete MS;
    
    WriteOne(&MYEND,mtString,_MS);  */
}

void TLuaModule::ReadData(TMemoryStream *_MS)
{
    TMyObject::ReadData(_MS);
/*    AnsiString NewAName;
    AnsiString NewAGlobal;
    AnsiString NewAHasForm;
    AnsiString NewMyEnd;
    int NameType;
    int GlobalType;
    int HasFormType;

    //-------------------------------------------------------
    if (ReadOne(&NewAName,mtString,_MS) != -1)
          throw EMyException("Неизвестная ошибка");

    if (ReadOne(&NameType,mtInt,_MS) != -1)
          throw EMyException("Неизвестная ошибка");

    if (NewAName!=aName || NameType!=mtString)
          throw EMyException("Неизвестная ошибка");

    if (ReadOne(&Name,mtString,_MS) != -1)
          throw EMyException("Неизвестная ошибка");
    //-------------------------------------------------------
    if (ReadOne(&NewAGlobal,mtString,_MS) != -1)
          throw EMyException("Неизвестная ошибка");

    if (ReadOne(&GlobalType,mtInt,_MS) != -1)
          throw EMyException("Неизвестная ошибка");

    if (NewAGlobal!=aGlobal || GlobalType!=mtBool)
          throw EMyException("Неизвестная ошибка");

    if (ReadOne(&Global,mtBool,_MS) != -1)
          throw EMyException("Неизвестная ошибка");
    //-------------------------------------------------------
    if (ReadOne(&NewAHasForm,mtString,_MS) != -1)
          throw EMyException("Неизвестная ошибка");

    if (ReadOne(&HasFormType,mtInt,_MS) != -1)
          throw EMyException("Неизвестная ошибка");

    if (NewAHasForm!=aHasForm || HasFormType!=mtBool)
          throw EMyException("Неизвестная ошибка");

    if (ReadOne(&HasForm,mtBool,_MS) != -1)
          throw EMyException("Неизвестная ошибка");
    //-------------------------------------------------------
    int MainSize = 0;
    if (ReadOne(&MainSize,mtInt,_MS) != -1)
          throw EMyException("Неизвестная ошибка");
    //-------------------------------------------------------
    TMemoryStream* MS = new TMemoryStream();
    MS->Position=0;
    MS->Size = MainSize;
    _MS->Read(MS->Memory,MainSize);
    delete MS;
    //-------------------------------------------------------
    if (ReadOne(&NewMyEnd,mtString,_MS) != -1)
          throw EMyException("Неизвестная ошибка");
          */
}

TMyObject* TLuaModule::CreateFunction()
{
    return new TLuaModule();
}
TLuaModule::TLuaModule()
    :Dialog( *(new TMyDialog()) )
{
    RegisterNewClass< TMyObject, TLuaModule >(this,false,&CreateFunction);
    CODE = AnsiString();
    Debug = false;
    HasForm = false;
    Global = false;
    FGUID = AnsiString();
    RegisterField(&Name,&aName,mtString);
    RegisterField(&Global,&aGlobal,mtBool);
    RegisterField(&CODE,&aCODE,mtString);
    RegisterField(&HasForm,&aHasForm,mtBool);
    RegisterField(&Debug,&aDebug,mtBool);
    RegisterField(&BreakPoints,&aBreakPoints,mtMyObject);
    RegisterField(&FGUID,&aGUID,mtString);
//    RegisterField(&Dialog,&aDialog,mtMyObject);
    MS = new TMemoryStream();
    _ModuleName = AnsiString();
    BreakPoints.Clear();
    GenerateGUID();
    TLuaModule::StaticType->RegisterInstance(this);
}

void TLuaModule::AddBreakPoint(int Line)
{
    int i=0;
    if (BreakPoints.Count!=0)
        while ((i<BreakPoints.Count)&&(BreakPoints[i]<Line)) i++;
    BreakPoints.Insert(i,new int(Line));
}

void TLuaModule::RemoveBreakPoint(int Line)
{
    for (int i=0;i<(BreakPoints.Count);i++)
        if (BreakPoints[i]==(Line)) BreakPoints.Delete(i);
}

int TLuaModule::NextBreakPoint(int Line)
{
    for (int i=0;i<(BreakPoints.Count-1);i++)
        if (BreakPoints[i]>Line) return BreakPoints[i];
    return NULL;
}

TLuaModule::~TLuaModule()
{
    //LuaStation.UnRegister(this);
    delete MS;
    delete &Dialog;
}

bool TLuaModule::CheckFields()
{
    #if (!defined(INTERNET_VER) && !defined(TRADE_VER))
/*    Debug = CODE.Pos(LUA_DEBUG);
    HasForm = CODE.Pos("LuaUniForm");
    AnsiString CODE2;
        Lua_Function(_ModuleName,CODE,CODE2);
    int l = CODE2.Length();
    char *s = CODE2.c_str();

    AnsiString lua_call = _ModuleName+LUA_TEXT_SCOPE+LUA_TEXT_POINT;
    int cl = lua_call.Length();
    char *cs = lua_call.c_str();
        if ( lua_dobuffer(_LUA_, s, l, "")==0
        && luaL_loadbuffer(_LUA_, cs, cl, "")==0)
            lua_dump (_LUA_, dumpwriter, MS);
        else
            Debug = true; */
    Debug = CODE.Pos(LUA_DEBUG);
    HasForm = CODE.Pos("LuaUniForm");
    int l = CODE.Length();
    char *s = CODE.c_str();
    MS->Clear();
    MS->Position = 0;
    if (!ApplHnd)
        if ( luaL_loadbuffer(_LUA_, s, l, AnsiString(GUIDToString(LuaModuleGUID)+IntToStr((int)this)).c_str())==0 )
            lua_dump (_LUA_, dumpwriter, MS);
        else
            Debug = true;
    #endif
    if ((Global)&&(!ApplHnd))
        Run();
    return true;

    /*
    Debug = CODE.Pos(LUA_DEBUG);
    HasForm = CODE.Pos("LuaUniForm");

    AnsiString CODE2;
    if (Global)
        CODE2 = CODE;
    else
        Lua_Function(_ModuleName,CODE,CODE2);
    int l = CODE2.Length();
    char *s = CODE2.c_str();

    AnsiString lua_call = _ModuleName+LUA_TEXT_SCOPE+LUA_TEXT_POINT;
    int cl = lua_call.Length();
    char *cs = lua_call.c_str();

    MS->Clear();
    if (Global)
    {
        lua_dobuffer(_LUA_, s, l, "");
    }
    else
    {
        if ( lua_dobuffer(_LUA_, s, l, "")==0
        && luaL_loadbuffer(_LUA_, cs, cl, "")==0)
            lua_dump (_LUA_, dumpwriter, MS);
        else
            Debug = true;
    }
    return true;
    */
}

bool TLuaModule::Run_Non_Form()
{
/*    #if (!defined(INTERNET_VER) && !defined(TRADE_VER))
    if (!Debug)
    #endif */
        return RUN_BUFFER(this);
//        return RUN_LUA(CODE);
/*    #if (!defined(INTERNET_VER) && !defined(TRADE_VER))
    else
        return RUN_TEXT(this);
    #endif   */
}

bool TLuaModule::Run()
{
    if (HasForm)
    {
        /*TControl* _Owner = BIF->MDI3D;
        if (!_Owner)
            _Owner = (TControl*)ComponentExists(__classid(TMDI3D));
        if (!_Owner)
            _Owner = Config;
        if (!_Owner)
            throw EMyException("Создание объекта без владельца");  */
//        TComponent* _Owner = Application;
        bool result;
//        TLuaUniForm *LF = new TLuaUniForm(_Owner,this);
//        Dialog.CreateForm(Application,NULL);
        TMyDialog* BackDialog = CurDialog;
        CurDialog = &Dialog;
        result = Run_Non_Form();
        CurDialog = BackDialog;
//        delete LF;
        return result;
    }
    else
        return Run_Non_Form();
}

bool TLuaModule::RunText()
{
    return RUN_LUA(CODE);
}

TFLuaEditor* TLuaModule::FindEditor()
{
    TQuickList *Lst = new TQuickList();
    SelectComponents(__classid(TFLuaEditor),Lst);
    TFLuaEditor *L = NULL;
    for (int i=0;i<Lst->Count;i++)
        if ( ((TFLuaEditor *)Lst->Items[i])->Module ==this )
        {
            L = ((TFLuaEditor *)Lst->Items[i]);
            break;
        }
    delete Lst;
    if (L)
        L->SetFocus();
    return L;
}

TWinControl* TLuaModule::LuaModuleEdit(TComponent *Owner,TWinControl *Parent)
{
    TFLuaEditor *L = FindEditor();
    if (L)
    {
        L->SetFocus();
        return L;
    }
    else
    {
        if (HasForm)
            {}//Dialog.Edit(Owner,Parent,this);
        if ( Parent )
        {
            return new TFLuaEditor(Owner,Parent,this,"",NULL);
        }
        else
        {
            return new TMDILuaEditor(Owner,this);
        }
    }
}


void TLuaModule::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    LuaModuleEdit(Owner,Parent);
    #endif
}

