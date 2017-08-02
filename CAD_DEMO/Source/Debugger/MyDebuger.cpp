 //---------------------------------------------------------------------------

#include <basepch.h>
#pragma hdrstop
USEFORM("..\LuaEnv\LuaEditorV.cpp", FLuaEditor);
USEFORM("..\LuaEnv\MDILuaEditorV.cpp", MDILuaEditor);
USEFORM("..\LuaEnv\OutPutV.cpp", OutPut);
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
 