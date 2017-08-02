 //---------------------------------------------------------------------------

#include <basepch.h>
#pragma hdrstop
USEFORM("InspectorMain.cpp", DbgInspector);
USEFORM("LuaEditorV.cpp", FLuaEditor);
USEFORM("MDILuaEditorV.cpp", MDILuaEditor);
USEFORM("OutPutV.cpp", OutPut);
USEFORM("DebugU.cpp", DebugForm);
USEFORM("BaseVariableFormV.cpp", Global);
USEFORM("TreeFormV.cpp", TreeWindow);
USEFORM("StackMain.cpp", StackWindow);
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
//---------------------------------------------------------------------------
 