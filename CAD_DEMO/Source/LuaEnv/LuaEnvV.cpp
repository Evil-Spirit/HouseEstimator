//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LuaStationV.h"
#include "LuaEditorV.h"
#include "MyRegTreeV.h"
#include "tolua++.h"

//lexer includes

#include "LuaEnvV.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
//Инициализация глобальных переменных
//---------------------------------------------------------------------------
lua_State* _LUA_ = NULL;
int LuaEnvMode = MODE_NORMAL;
int DebugMode = DBGMODE_STOP;
HANDLE DebugHnd = NULL;
DWORD ApplHnd = 0;
TMessageHandler *MessageHandler=NULL;
TFileMapStream *FileMap = NULL;
TLuaModule* CurrentLM = NULL;
GUID LuaModuleGUID=IID_IUnknown;

AnsiString LuaFunctionGUID=AnsiString();
//---------------------------------------------------------------------------
//Локальные переменные
//---------------------------------------------------------------------------
int LevelHook=0,CurLevel=0;
bool Started=true;
int Handled=false;
tagMSG Message;

//---------------------------------------------------------------------------
//Клсс TLuaVariable
TClassNode* TLuaVariable::StaticType = NULL;
const AnsiString aName = "Name";
const AnsiString aType = "Type";
const AnsiString aValue = "Value";

TLuaVariable::TLuaVariable()
{
    RegisterNewClass<TMyObject,TLuaVariable>(this,false,&CreateFunction);
    RegisterField(&Name,&aName,mtString);
    RegisterField(&Type,&aType,mtString);
    RegisterField(&Value,&aValue,mtString);
}

TLuaVariable::~TLuaVariable()
{
}

TMyObject* TLuaVariable::CreateFunction()
{
    return new TLuaVariable();
}
//---------------------------------------------------------------------------
//Клсс TLuaRegObject
TClassNode* TLuaRegObject::StaticType = NULL;
const AnsiString aModules = "Modules";
const AnsiString aImageIndex = "ImageIndex";

TLuaRegObject::TLuaRegObject()
{
    RegisterNewClass<TMyRegObject,TLuaRegObject>(this,false,&CreateFunction);
    RegisterField(&Modules,&aModules,mtMyObject);
    RegisterField(&FImageIndex,&aImageIndex,mtInt);
}

TLuaRegObject::~TLuaRegObject()
{
}

TMyObject* TLuaRegObject::CreateFunction()
{
    return new TLuaRegObject();
}
////////////////////////////////////////////////////////////////
//Debuger features
////////////////////////////////////////////////////////////////
void Hooker(lua_State *l,lua_Debug *lua_d);

int Panic(lua_State *l)
{
    if (lua_isstring(l,lua_gettop(l)))
        MessageBox(DebugHnd,lua_tostring(l,lua_gettop(l)),"LUA Error!",MB_OK|MB_ICONERROR);
    else MessageBox(DebugHnd,"Unknown Lua error","LUA Error!",MB_OK|MB_ICONERROR);
    return 0;
}

void __fastcall SaveState(lua_Debug *ar)
{
    TMDelTList<TLuaVariable>* Vars = new TMDelTList<TLuaVariable>;
    TLuaVariables *All = new TLuaVariables();

    TMDelTList<AnsiString> *ModuleName = new TMDelTList<AnsiString>;
    FileMap->Position=0;

    if (CurrentLM)
    {
        ModuleName->Add(new AnsiString(CurrentLM->GUID));
        ModuleName->WriteData(FileMap);
    }
    else
    {
        ModuleName->Add(new AnsiString("Unknown"));
        ModuleName->WriteData(FileMap);
    }

    All->FillGlobals(Vars);
    Vars->WriteData(FileMap);
    All->FillLocals(Vars);
    Vars->WriteData(FileMap);
    All->FillStack(Vars);
    Vars->WriteData(FileMap);
    delete ModuleName;

    delete Vars;delete All;
}

void RecurrentSelectModules(TMDelTList<TLuaModule>& Mdls,TMyObject* Obj)
{
    TStringList* SL = new TStringList();
    for (int i=0;i<Obj->GetFieldCount();i++)
        if ( Obj->GetFieldType(i)==mtMyObject )
        {
            TMyObject* ChildObj = (TMyObject*)Obj->GetFieldAddress(i);
            if (ChildObj->Is(TLuaModule::StaticType))
            {
                Mdls.Add( new TLuaModule() );
                Mdls.Last()->AssignLST(ChildObj,SL);
            }
            else if (ChildObj->Is(TContainer<TLuaModule>::StaticType))
            {
                TContainer<TLuaModule>& ElseMdls = (TContainer<TLuaModule>&)(*ChildObj);
                for ( int j=0;j<ElseMdls.GetCount();j++ )
                {
                    Mdls.Add( new TLuaModule() );
                    Mdls.Last()->AssignLST( ElseMdls.GetItem(j),SL );
                }
            }
            else
                RecurrentSelectModules(Mdls,ChildObj);
        }
    delete SL;
}

void Assign(TMyRegObject *Src,TLuaRegObject *Dst)
{
    Dst->ImageIndex=Src->ImageIndex;
    Dst->Name=Src->Name;
    Dst->Description=Src->Description;
}

void ReccurentCopy(TMyRegObject *Root,TLuaRegObject *LuaReg)
{
    Assign(Root,LuaReg);
    RecurrentSelectModules(LuaReg->Modules,Root);
    for (int i=0;i<Root->ChildList->Count;i++)
    {
        TLuaRegObject *Item=new TLuaRegObject;
        LuaReg->MyTree->AddChild(LuaReg,Item);
        Item->Parent=LuaReg;
        ReccurentCopy(Root->ChildList->GetItem(i),Item);
    }
}

void __fastcall DebugInit()
{
    if (AnsiString(GetCommandLine()).Pos("INIT")!=0)
    {
        TMyObject *Element = (TMyObject*)(TLuaModule::StaticType->GetRegInfo(0)->Object);
        while (Element->MyObjectParent!=NULL)
            Element=Element->MyObjectParent;

        TMyRegObject *Root = (TMyRegObject*)Element;
        while (Root->Parent!=NULL)
            Root=Root->Parent;

        TLuaRegObject *RootNew = new TLuaRegObject;
        RootNew->MyTree = new TMyRegTree;
        RootNew->MyTree->AddChild(NULL,RootNew);
        ReccurentCopy(Root,RootNew);

        FileMap->Position=0;
        RootNew->MyTree->WriteData(FileMap);
        SendMessage(DebugHnd,WM_USER,MSG_READY,0);
        delete RootNew->MyTree;
        delete RootNew;
        SendMessage(DebugHnd,WM_USER,MSG_FINISH,0);
        TerminateProcess(GetCurrentProcess(),0);
    }
    PostMessage(DebugHnd,WM_USER,MSG_READY,0);
    DebugMode=DBGMODE_PAUSE;
}


void SaveGlobals()
{
    lua_Debug ar;
    lua_newtable(_LUA_); //Table for all local names
	lua_newtable(_LUA_); //Table for global variables
    int level =0 ;
    const char *name;
    while (lua_getstack(_LUA_,level,&ar) != NULL)
    {
        int i=0;
        while ((name = lua_getlocal(_LUA_, &ar, ++i)) != NULL)
        {
            lua_pushstring(_LUA_, name);
            lua_pushvalue(_LUA_,-1);
            lua_gettable(_LUA_,-4);
            if (!lua_isnil(_LUA_,-1))
            {
                lua_pop(_LUA_,3);
                continue;
            }
            else lua_pop(_LUA_,1);
            lua_pushvalue(_LUA_,-1);
            lua_newtable(_LUA_);

            lua_pushstring(_LUA_,"index");
            lua_pushnumber(_LUA_,i);
            lua_settable(_LUA_,-3);

            lua_pushstring(_LUA_,"level");
            lua_pushnumber(_LUA_,level);
            lua_settable(_LUA_,-3);

            lua_settable(_LUA_,-5);
            lua_pushvalue(_LUA_, -1);
            lua_pushvalue(_LUA_, -1);
            lua_insert(_LUA_, -4);
            lua_gettable(_LUA_, LUA_GLOBALSINDEX);
            lua_settable(_LUA_, -6);
            lua_settable(_LUA_, LUA_GLOBALSINDEX);
        }
        level++;
    }
}

void RestoreGlobals()
{
    lua_Debug ar;
    int level=0,cur=-1,index;
    lua_pushnil(_LUA_);
	while (lua_next(_LUA_, -2))
	{
        lua_pushvalue(_LUA_, -2);
        lua_gettable(_LUA_,LUA_GLOBALSINDEX);
        lua_pushstring(_LUA_,"index");
        lua_gettable(_LUA_,-3);
        index=lua_tonumber(_LUA_,-1);
        lua_pop(_LUA_,1);

        lua_pushstring(_LUA_,"level");
        lua_gettable(_LUA_,-3);
        level=lua_tonumber(_LUA_,-1);
        lua_pop(_LUA_,1);
        lua_remove(_LUA_,-2);
        if (cur!=level)
        {
            cur=level;
            lua_getstack(_LUA_,level,&ar);
        }
        lua_setlocal(_LUA_,&ar,index);
        lua_pushvalue(_LUA_,-1);
        lua_pushvalue(_LUA_,-1);
        lua_gettable(_LUA_,-5);
        lua_settable(_LUA_, LUA_GLOBALSINDEX);
	}
    lua_pop(_LUA_,2);
}


void __fastcall TMessageHandler::MyWndProc(tagMSG &Message, bool &Handled)
{
    switch(Message.message)
    {
        case WM_QUIT:
        {
            delete FileMap;
            DebugMode=DBGMODE_STOP;
            SendMessage(DebugHnd,WM_USER,MSG_FINISH,0);
            lua_sethook(_LUA_,Hooker,0,0);
        };
        case WM_USER:
        {
            Handled=true;
            switch (Message.wParam)
            {
                case MSG_EVALUATE:
                {
                    TMDelTList<AnsiString> DataIn, DataOut;
                    FileMap->Position=0;
                    DataIn.ReadData(FileMap);
                    lua_sethook(_LUA_,Hooker,0,0);
                    SaveGlobals();
                    for (int i=0;i<DataIn.Count;i++)
                    {
                        int st=lua_gettop(_LUA_);
                        luaL_loadbuffer(_LUA_, (*DataIn.GetItem(i)).c_str(), (*DataIn.GetItem(i)).Length(), "Evalute");
                        lua_pcall(_LUA_, 0, LUA_MULTRET, 0);
                        int en=lua_gettop(_LUA_);
                        AnsiString Text="{";
                        if (en-st>0)
                            for (int i=0;i<en-st;i++)
                            {
                                Text+=GetLuaValue(-1-i)+",";
                            }
                        Text[Text.Length()]='}';
                        DataOut.Add(new AnsiString(Text));
                        lua_settop(_LUA_,st);
                    }
                    RestoreGlobals();
                    lua_sethook(_LUA_,Hooker,LUA_MASKLINE+LUA_MASKCALL+LUA_MASKRET,0);
                    FileMap->Position=0;
                    DataOut.WriteData(FileMap);
                    DataOut.Clear();
                    HANDLE hndWatchWnd = FindWindow("TGlobal","Watches");
                    if (hndWatchWnd) SendMessage(hndWatchWnd,WM_USER,MSG_UPDATE,0);
                    else SendMessage(DebugHnd,WM_USER,MSG_UPDATEWATCH,0);

                }break;
                case MSG_INIT:
                {
                    DebugInit();
                }break;
                case MSG_SETMASKHOOK:
                {
                    lua_sethook(_LUA_,Hooker,Message.lParam,1);
                    break;
                }
                case MSG_GETLOCALVALUE:
                {
                    FileMap->Position=0;
                    TLuaVariables* Temp = new TLuaVariables();
                    TLuaVariable *Var = new TLuaVariable();
                    Var->ReadData(FileMap);
                    FileMap->Position=0;
                    Temp->GetLocal(Var->Name,Var);
                    Var->WriteData(FileMap);
                    delete Temp; delete Var;
                }break;
                case MSG_GETGLOBALVALUE:
                {
                    FileMap->Position=0;
                    TLuaVariables* Temp = new TLuaVariables();
                    TLuaVariable *Var = new TLuaVariable();
                    Var->ReadData(FileMap);
                    FileMap->Position=0;
                    Temp->GetGlobal(Var->Name, Var);
                    Var->WriteData(FileMap);
                    delete Temp; delete Var;
                }break;
                case MSG_GETLOCALALL:
                {
                    FileMap->Position=0;
                    TMDelTList<TLuaVariable>* Vars = new TMDelTList<TLuaVariable>;
                    TLuaVariables* Temp = new TLuaVariables();
                    Temp->FillLocals(Vars);
                    Vars->WriteData(FileMap);
                    delete Vars; delete Temp;
                }break;
                case MSG_GETGLOBALALL:
                {
                    FileMap->Position=0;
                    TMDelTList<TLuaVariable> *Vars = new TMDelTList<TLuaVariable>;
                    TLuaVariables* Temp = new TLuaVariables();
                    Temp->FillGlobals(Vars);
                    Vars->WriteData(FileMap);
                    delete Vars; delete Temp;
                }break;
                case MSG_SETLOCAL:
                {
                    FileMap->Position=0;
                    TLuaVariables Temp;
                    TLuaVariable Var;
                    Var.ReadData(FileMap);
                    Temp.SetLocal(&Var);
                }break;
                case MSG_SETGLOBAL:
                {
                    FileMap->Position=0;
                    TLuaVariables Temp;
                    TLuaVariable Var;
                    Var.ReadData(FileMap);
                    Temp.SetGlobal(&Var);
                }break;
                case MSG_INSPECT:
                {
                    TMDelTList<AnsiString> name;
                    FileMap->Position=0;
                    name.ReadData(FileMap);
                    InspectVariable((HANDLE)Message.lParam,*name.Last());
                }break;
                case MSG_STOP:
                {
                    Application->Terminate();
                    DebugMode=DBGMODE_WORK;
                }break;
                case MSG_PAUSE:
                {
                    DebugMode=DBGMODE_PAUSE;
                    SendMessage(DebugHnd,WM_USER,MSG_SETMODE,DebugMode);
                }break;
                case MSG_RESUME:
                {
                    DebugMode=DBGMODE_WORK;
                    SendMessage(DebugHnd,WM_USER,MSG_SETMODE,DebugMode);
                    if (Application->MainForm)
                    {
                        ShowWindow(Application->MainForm->Handle,SW_SHOW);
                        SetForegroundWindow(Application->MainForm->Handle);
                    }

                }break;
                case MSG_TRACEIN:
                {
                    DebugMode=DBGMODE_TRACEIN;
                    SendMessage(DebugHnd,WM_USER,MSG_SETMODE,DebugMode);
                }break;
                case MSG_STEPOVER:
                {
                    DebugMode=DBGMODE_STEPOVER;
                    LevelHook=CurLevel;
                    SendMessage(DebugHnd,WM_USER,MSG_SETMODE,DebugMode);
                }break;
                case MSG_GETMODE:
                {
                    SendMessage(DebugHnd,WM_USER,MSG_SETMODE,DebugMode);
                }break;
                case MSG_UPDATEALL:
                {
                    TMDelTList<AnsiString> *ModuleName = new TMDelTList<AnsiString>;
                    FileMap->Position=0;
                    ModuleName->ReadData(FileMap);
                    if (ModuleName->Count>0)
                    {
                        for (int i=0;i<ModuleName->Count;i++)
                        {
                            CurrentLM = (TLuaModule*)TLuaModule::StaticType->RecurrentFindByGUID(*ModuleName->GetItem(i));
                            if (CurrentLM)
                            {
                                CurrentLM->BreakPoints.ReadData(FileMap);
                            }
                            else
                            {    //We need this to avoid unknown breakpoints
                                TMDelTList<int> *Temp = new TMDelTList<int>;
                                Temp->ReadData(FileMap);
                                delete Temp;
                            }
                        }
                    }
                    delete ModuleName;
                }break;
                case MSG_UPDATE:
                {
                    TMDelTList<AnsiString> *ModuleName = new TMDelTList<AnsiString>;
                    FileMap->Position=0;
                    ModuleName->ReadData(FileMap);
                    CurrentLM = (TLuaModule*)TLuaModule::StaticType->RecurrentFindByGUID(*ModuleName->Last());
                    if (CurrentLM)
                    {
                        CurrentLM->BreakPoints.ReadData(FileMap);
                        TFLuaEditor* Ed= (CurrentLM->FindEditor());
                        if (Ed) Ed->Refresh();
                    }
                    delete ModuleName;
                }break;
            }
        }
    };
}

void Hooker(lua_State *l,lua_Debug *lua_d)
{
    if (Started)
    {
        DebugInit();
        Started = false;
    }
   	switch(lua_d->event)
 	{
 		case LUA_HOOKRET:
        {
            CurLevel--;
            if (LevelHook>CurLevel) LevelHook=CurLevel;
            break;
        }
 		case LUA_HOOKCALL:
        {
            CurLevel++;
            if (DebugMode==DBGMODE_PAUSE)
            {
                ShowWindow(DebugHnd,SW_SHOW);
                SetForegroundWindow(DebugHnd);
            }
            break;
        }
 		case LUA_HOOKLINE:
        {
            lua_getinfo(l,"lS",lua_d);
            AnsiString Src = AnsiString(lua_d->source);
            if ((Src.Length()>38)&&(Src.SubString(1,38)==GUIDToString(LuaModuleGUID)))
                CurrentLM =(TLuaModule*)StrToInt(Src.SubString(39,Src.Length()-38));
            else break;

            if (DebugMode==DBGMODE_TRACEIN)
            {
                SaveState(lua_d);
                ShowWindow(DebugHnd,SW_SHOW);
                SetForegroundWindow(DebugHnd);
                SendMessage(DebugHnd,WM_USER,MSG_LINEHOOK,lua_d->currentline);
                DebugMode=DBGMODE_PAUSE;
                SendMessage(DebugHnd,WM_USER,MSG_SETMODE,DebugMode);
                break;
            }
            if ((DebugMode==DBGMODE_STEPOVER)&&(CurLevel<=LevelHook))
            {
                SaveState(lua_d);
                ShowWindow(DebugHnd,SW_SHOW);
                SetForegroundWindow(DebugHnd);
                SendMessage(DebugHnd,WM_USER,MSG_LINEHOOK,lua_d->currentline);
                DebugMode=DBGMODE_PAUSE;
                SendMessage(DebugHnd,WM_USER,MSG_SETMODE,DebugMode);
                break;
            }
            if ((CurrentLM)&&((FindInList(&(CurrentLM->BreakPoints),lua_d->currentline-1))!=-1))
            {
                SaveState(lua_d);
                ShowWindow(DebugHnd,SW_SHOW);
                SetForegroundWindow(DebugHnd);
                SendMessage(DebugHnd,WM_USER,MSG_BREAKPOINT,lua_d->currentline);
                DebugMode=DBGMODE_PAUSE;
                SendMessage(DebugHnd,WM_USER,MSG_SETMODE,DebugMode);
                break;
            }
        }

 	};
    while (DebugMode==DBGMODE_PAUSE)
    {
        if (PeekMessage(&Message,NULL,WM_USER,WM_USER,PM_REMOVE)!=0)
        {
            DispatchMessage(&Message);
            MessageHandler->MyWndProc(Message,&Handled);
        }

    }
};

////////////////////////////////////////////////////////////////
//End of Debuger features
////////////////////////////////////////////////////////////////
int GetDepth=0;
AnsiString GetLuaValue(int index)
{
   int type=lua_type(_LUA_,index);
   switch (type)
    {
        case LUA_TNIL:
        {
            return ("");
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
            return ("");
        }
        case LUA_TBOOLEAN:
        {
            return (BoolToStr(lua_toboolean(_LUA_,index),true));
        }
        case LUA_TTABLE:
        {
            GetDepth++;
            if (GetDepth>1)
            {
                GetDepth--;
                return ("0x"+IntToHex((int)lua_topointer(_LUA_,index),7));
            }
            int delta;
            AnsiString Table="";
            lua_pushnil(_LUA_);
            if (index<0) delta=-1;
            else delta=0;
            while (lua_next(_LUA_, index+delta)!=NULL)
            {
                Table+=GetLuaValue(-2)+":"+GetLuaValue(-1)+" ,";
                lua_pop(_LUA_, 1); // pop value, keep key for next iteration;
            }
            Table=Table.SubString(1,Table.Length()-2);
            GetDepth--;
            return Table;
        }
        case LUA_TUSERDATA:
        {
            GetDepth++;
            if (GetDepth>1)
            {
                GetDepth--;
                return ("0x"+IntToHex((int)lua_topointer(_LUA_,index),7));
            }
            if (lua_getmetatable (_LUA_,index)==0)
            {
                GetDepth--;
                return ("0x"+IntToHex((int)lua_topointer(_LUA_,index),7));
            }
            AnsiString Table="";
            /*lua_pushnil(_LUA_);
            while (lua_next(_LUA_, -2)!=NULL)
            {
                Table+=GetLuaValue(-1)+",";
                lua_pop(_LUA_, 1); // pop value, keep key for next iteration;
            }
            */
            lua_pushstring(_LUA_,".get");
            lua_gettable(_LUA_,-2);
            if (lua_istable(_LUA_,-1))    //There is data
            {
                lua_pushnil(_LUA_);
                while (lua_next(_LUA_, -2)!=NULL)
                {
                    int delta;
                    if (index<0) delta=-4; else delta=0;
                    lua_pushvalue(_LUA_,index+delta);
                    lua_pcall(_LUA_,1,1,0);
                    Table+=GetLuaValue(-2)+":"+GetLuaValue(-1)+" ,";
                    //InfoMsg(Table);
                    lua_pop(_LUA_, 1); // pop value, keep key for next iteration;
                }
            }
            lua_pop(_LUA_,2);
            Table = Table.SubString(1,Table.Length()-2);
            GetDepth--;
            return Table;
        }
        case LUA_TLIGHTUSERDATA:
        case LUA_TFUNCTION:
        case LUA_TTHREAD:
        default:
            return ("0x"+IntToHex((int)lua_topointer(_LUA_,index),7));
    }
};


int SetLuaValue(AnsiString type, AnsiString value)
{

    if (type=="number")
    {
        lua_pushnumber(_LUA_,StrToInt(value));
        return 1;
    }
    if (type=="string")
    {
        lua_pushstring(_LUA_,value.c_str());
        return 1;
    }
    if (type=="boolean")
    {
        lua_pushboolean(_LUA_,StrToBool(value));
        return 1;
    }
    lua_pushnil(_LUA_);
    return 0;
};

void InspectVariable(HANDLE hnd,AnsiString Text)
{
    AnsiString PreCode = "local Value = "+Text+";";
    AnsiString Code =PreCode+
        "local VariableType = type(Value);"
        "if (VariableType ~= \"table\") and (VariableType ~= \"userdata\") and (VariableType ~= \"function\") then"
        "    return Value;"
        "elseif (VariableType == \"function\") then"
        "    return "+Text+"();"
        "elseif (VariableType ~= \"userdata\") then"
        "    local list = {};"
        "    local index=1;"
        "    for key,value in Value do"
        "        list[ index ] = key;"
        "        index = index+1;"
        "        list[ index ] = value;"
        "        index = index+1;"
        "    end;"
        "    return unpack(list);"
        "else"
        "    local list = {};"
        "    local index=1;"
        "    local metatable = getmetatable(Value);"
        "    local dotget = metatable[\".get\"];"
        "    for key,value in dotget do"
        "        list[ index ] = key;"
        "        index = index+1;"
        "        list[ index ] = Value[key];"
        "        index = index+1;"
        "    end;"
        "    for key,value in metatable do"
        "        list[ index ] = key;"
        "        index = index+1;"
        "        list[ index ] = value;"
        "        index = index+1;"
        "    end;"
        "    return unpack(list);"
        "end;";
    TMDelTList<TLuaVariable> Variables;
    SaveGlobals();
    int st=lua_gettop(_LUA_);
    luaL_loadbuffer(_LUA_, Code.c_str(), Code.Length(), "Return value");
    int status=lua_pcall(_LUA_, 0, LUA_MULTRET, 0);
    int en=lua_gettop(_LUA_);
    Variables.Clear();
    Variables.Add(new TLuaVariable);
    TLuaVariable *Var=Variables.Last();
    Var->Name=Text;
    if (en-st>1)
    {
        for (int i=0;i<(en-st)/2;i++)
            {
                Variables.Add(new TLuaVariable);
                TLuaVariable *Var=Variables.Last();
                Var->Value=GetLuaValue(-2*i-1);
                Var->Type=AnsiString(tolua_typename(_LUA_,-2*i-1));
                lua_pop(_LUA_,1);
                Var->Name=GetLuaValue(-2*i-2);
            }
    }
    else
    {
        Variables.Add(new TLuaVariable);
        TLuaVariable *Var=Variables.Last();
        if (!status)
        {
            Var->Value=GetLuaValue(-1);
            Var->Type=tolua_typename(_LUA_,-1);
            lua_pop(_LUA_,1);
            Var->Name=Text;
        }
        else Var->Name="--None--";
    }
    lua_settop(_LUA_,st);
    RestoreGlobals();
    FileMap->Position=0;
    Variables.WriteData(FileMap);
    SendMessage(hnd,WM_USER,MSG_UPDATE,0);
    FileMap->Ready=true;
    Variables.Clear();
}


void __fastcall TLuaVariables::FillGlobals(TMDelTList<TLuaVariable>* Vars)
{
    int type;
    Vars->Clear();
    lua_pushvalue(_LUA_, LUA_GLOBALSINDEX);
	lua_pushnil(_LUA_);  //Push first key
	while (lua_next(_LUA_, -2))
	{
        if (AnsiString(lua_tostring(_LUA_,-2)).SubString(1,3).UpperCase()=="IUP")
        {
            lua_pop(_LUA_, 1);
            continue;  //Filter IUP
        }
        Vars->Add(new TLuaVariable);
        TLuaVariable* Var = Vars->Last();

        Var->Name = AnsiString(lua_tostring(_LUA_,-2));
        Var->Type = AnsiString(tolua_typename(_LUA_,-1));
        lua_pop(_LUA_,1);
        Var->Value = GetLuaValue(-1);
		lua_pop(_LUA_, 1); // pop value, keep key for next iteration;
	}
	lua_pop(_LUA_, 1); // pop table of globals;
}

void __fastcall TLuaVariables::FillLocals(TMDelTList<TLuaVariable>* Vars)
{
    lua_Debug ar;
    int i,type,level=0;
    AnsiString name;

    Vars->Clear();
    while (lua_getstack(_LUA_, level, &ar) != 0)
    {
        i=1;
        while ((name = AnsiString(lua_getlocal(_LUA_, &ar, i++))) != "")
        {
            Vars->Add(new TLuaVariable);
            TLuaVariable* Var = Vars->Last();

            Var->Name=name;
            Var->Type=AnsiString(tolua_typename(_LUA_,-1));
            lua_pop(_LUA_,1);
            Var->Value=GetLuaValue(-1);
            lua_pop(_LUA_, 1);  /* remove variable value */
        }
        level++;
    }
}

void __fastcall TLuaVariables::FillStack(TMDelTList<TLuaVariable>* Vars)
{
    int dat,tot=lua_gettop(_LUA_);
    Vars->Clear();
    for (int n=1;n<=tot;n++)
    {
        Vars->Add(new TLuaVariable);
        TLuaVariable* Var = Vars->Last();
        Var->Type=AnsiString(tolua_typename(_LUA_,n));
        lua_pop(_LUA_,1);
        Var->Value=GetLuaValue(n);
    }
}



TLuaVariable* __fastcall TLuaVariables::GetLocal(AnsiString Name, TLuaVariable *LuaVar)
{
    lua_Debug ar;

    int i,type,level=0;
    const char* name;

    while (lua_getstack(_LUA_, level, &ar) != 0)
    {
        i=1;
        while ((name = lua_getlocal(_LUA_, &ar, i++)) != NULL)
        {
            if(strcmp(Name.c_str(),name)==0) break; //We found the key
            lua_pop(_LUA_, 1);  /* remove variable value */
        }
        if(strcmp(Name.c_str(),name)==0) break;
        level++;
    }
    LuaVar->Name = Name;
    LuaVar->Type = AnsiString(tolua_typename(_LUA_,-1));
    lua_pop(_LUA_,1);
    LuaVar->Value = GetLuaValue(-1);
    lua_pop(_LUA_,1);

    return LuaVar;
};


TLuaVariable* __fastcall TLuaVariables::GetGlobal(AnsiString Name, TLuaVariable *LuaVar)
{
    lua_pushstring(_LUA_,Name.c_str());
    lua_gettable(_LUA_,LUA_GLOBALSINDEX);
    LuaVar->Name = Name;
    LuaVar->Type = AnsiString(lua_typename(_LUA_,-1));
    LuaVar->Value = GetLuaValue(-1);
    lua_pop(_LUA_,1);
    return LuaVar;
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
    lua_Debug ar;
    int i=0,level=0;
    const char* name;

    while (lua_getstack(_LUA_, level, &ar) != 0)
    {
        i=0;
        while ((name = lua_getlocal(_LUA_, &ar, ++i)) != NULL)
        {
            if(strcmp(Var->Name.c_str(),name)==0) break; //We found the key
            lua_pop(_LUA_, 1);  /* remove variable value */
        }
    if(strcmp(Var->Name.c_str(),name)==0) break;
    level++;
    }
    SetLuaValue(Var->Type,Var->Value);
    name = lua_setlocal(_LUA_, &ar ,i);
    return (strcmp(name,Var->Name.c_str())==0);
};

/*void __fastcall TLuaVariables::FillTable(TMDelTList<TLuaVariable>* Vars, int index)
{
    int type;
    Vars->Clear();
 	lua_pushnil(_LUA_);
	while (lua_next(_LUA_, index)!=NULL)
	{
        Vars->Add(new TLuaVariable);
        TLuaVariable* Var = Vars->Last();
        if (lua_isstring(_LUA_,-2)) Var->Name = AnsiString(lua_tostring(_LUA_,-2));
        else Var->Name="NONE";
        //type = lua_type(_LUA_,-1);
        Var->Type = AnsiString(tolua_typename(_LUA_,-1));
        lua_pop(_LUA_,1);
        Var->Value = GetLuaValue(-1);
		lua_pop(_LUA_, 1); // pop value, keep key for next iteration;
	}
}

void __fastcall TLuaVariables::FillTable(TMDelTList<TLuaVariable>* Vars, AnsiString name)
{
    int type;
    Vars->Clear();
 	lua_pushnil(_LUA_);
	while (lua_next(_LUA_, -2)!=NULL)
	{
        Vars->Add(new TLuaVariable);
        TLuaVariable* Var = Vars->Last();
        if (lua_isstring(_LUA_,-2)) Var->Name = AnsiString(lua_tostring(_LUA_,-2));
        else Var->Name="NONE";
        Var->Type = AnsiString(tolua_typename(_LUA_,-1));
        lua_pop(_LUA_,1);
        Var->Value = GetLuaValue(-1);
		lua_pop(_LUA_, 1); // pop value, keep key for next iteration;
	}
    lua_pop(_LUA_,1);
}
*/

void DisplayMessage(int CODE)
{
    LPVOID lpMessageBuffer;

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM,
        NULL,
        CODE,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), //The user default language
        (LPTSTR) &lpMessageBuffer,
        0,
        NULL );
    MessageBox(NULL,(char*) lpMessageBuffer, AnsiString("Ошибка "+IntToStr(CODE)).c_str(), MB_OK|MB_ICONERROR);
    LocalFree( lpMessageBuffer );
};


void LuaAllOpen()
{
    GUID *FunctionGuid = new GUID;
    CreateGUID(*FunctionGuid);
    LuaFunctionGUID=GUIDToString(*FunctionGuid);
    delete FunctionGuid;
    ReplaceAll(LuaFunctionGUID,"-","_");
    ReplaceAll(LuaFunctionGUID,"{","");
    ReplaceAll(LuaFunctionGUID,"}","");

    IupOpen();
    //-----------
    IupControlsOpen();
    //-----------

    _LUA_ = lua_open();

    //загрузка библиотеки Lexer
	::LoadLibrary("SciLexer.DLL");
    //инициализация информации о классах

    luaopen_base(_LUA_);
    luaopen_string(_LUA_);
    luaopen_table(_LUA_);
    luaopen_math(_LUA_);
    luaopen_io(_LUA_);
    luaopen_debug(_LUA_);
    luaopen_loadlib(_LUA_);

    iuplua_open(_LUA_); /* iup Binding Lua */
    //-------------
    controlslua_open(_LUA_); /* Inicialize CPI controls binding Lua */    //controlslua_open(_LUA_);

////////////////////////////////////////////////////////////////////
//Debuger features
////////////////////////////////////////////////////////////////////
    if ( LuaEnvMode == MODE_DEBUG )
    {
        lua_register(_LUA_, "_ALERT", Panic);
        lua_register(_LUA_, "_ERRORMESSAGE", Panic);
        lua_atpanic(_LUA_,Panic);
        lua_sethook(_LUA_,Hooker,LUA_MASKLINE+LUA_MASKCALL+LUA_MASKRET,0);
        CreateGUID(LuaModuleGUID);
        MessageHandler = new TMessageHandler;
        Application->OnMessage=MessageHandler->MyWndProc;
        DebugHnd=FindWindow("TDebugForm","Debuger");
        FileMap = new TFileMapStream("LUA");
    }
}

void LuaAllClose()
{
//    IupControlsClose();
    IupClose();

	lua_close(_LUA_);
    _LUA_ = NULL;
    if ( LuaEnvMode == MODE_DEBUG )
    {
        delete FileMap;
        DebugMode=DBGMODE_STOP;
        SendMessage(DebugHnd,WM_USER,MSG_SETMODE,DebugMode);
        SendMessage(DebugHnd,WM_USER,MSG_FINISH,0);
    }

}


