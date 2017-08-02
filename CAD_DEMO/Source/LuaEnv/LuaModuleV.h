//---------------------------------------------------------------------------

#ifndef LuaModuleVH
#define LuaModuleVH
//---------------------------------------------------------------------------
#ifndef UNUSED
#define UNUSED(x)	((void)(x))	/* to avoid warnings */
#endif


const AnsiString LUA_DEBUG = AnsiString("--LUA_DEBUG");
const AnsiString MODULE_ = AnsiString("MODULE_");
const AnsiString LUA_TEXT_FUNCTION = AnsiString("function ");
const AnsiString LUA_TEXT_END = AnsiString("end;");
const AnsiString LUA_TEXT_SCOPE = AnsiString("()");
const AnsiString LUA_TEXT_POINT = AnsiString(";");

const AnsiString LUA_TEXT_FUNCTION2 = AnsiString("function");
const AnsiString LUA_TEXT_EQUAL = AnsiString(" = ");
const AnsiString LUA_TEXT_DOWN_LINE = AnsiString("_");
const AnsiString LUA_TEXT_OPEN_SCOPE = AnsiString("{");
const AnsiString LUA_TEXT_CLOSE_SCOPE = AnsiString("};");
const AnsiString LUA_TEXT_GLOBAL = AnsiString("GLOBAL");
const AnsiString LUA_TEXT_NEWLINE = AnsiString("\n");

COMMONAL_API void Lua_Function(const AnsiString& Module_Name,const AnsiString& CODE,AnsiString& CODE2)
{
  CODE2 =  LUA_TEXT_FUNCTION + Module_Name + LUA_TEXT_SCOPE + LUA_TEXT_NEWLINE +
                    CODE + LUA_TEXT_NEWLINE+
                    LUA_TEXT_END;
}

class TFLuaEditor;
class TMyDialog;
class COMMONAL_API TLuaModule : public TMyObject{
private:
public:
    TLuaModule();
    virtual ~TLuaModule();
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TMemoryStream *MS;
    AnsiString CODE;
    TMyDialog& Dialog;
    bool RunText();
    bool Run();
    bool Run_Non_Form();
    bool Debug;
    bool Global;
    bool HasForm;
    AnsiString _ModuleName;
    virtual void WriteData(TMemoryStream *MS) const;
    virtual void ReadData(TMemoryStream *MS);
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
    TWinControl *LuaModuleEdit(TComponent *Owner,TWinControl *Parent);
    virtual bool CheckFields();
    TFLuaEditor* FindEditor();
    TMDelTList<int> BreakPoints;
    void AddBreakPoint(int Line);
    void RemoveBreakPoint(int Line);
    int NextBreakPoint(int Line);
    int OldLine;

};
extern COMMONAL_API TClassNode* TLuaModule::StaticType;

COMMONAL_API bool RUN_LUA(const AnsiString& Code);
COMMONAL_API bool RUN_TEXT(TLuaModule *LM);
COMMONAL_API bool RUN_BUFFER(TLuaModule *LM);

class lua_State;
void COMMONAL_API LuaCallBack(void* Table,const AnsiString& TableTypeName,const AnsiString& CallBackName,TMDelTList<TLuaAttribute>& Args  );
void COMMONAL_API PUSHATTRIBUTE(lua_State* tolua_S,TLuaAttribute* LA);
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#endif
