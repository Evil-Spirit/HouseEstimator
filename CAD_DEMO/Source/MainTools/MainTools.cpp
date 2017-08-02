//---------------------------------------------------------------------------

#include <basepch.h>
#pragma hdrstop
USEFORM("BindedBaseToolEditV.cpp", BindedBaseToolEdit);
USEFORM("BindedBlockEditV.cpp", BindedBlockEdit);
USEFORM("BindedGoEditV.cpp", BindedGoEdit);
USEFORM("ToolFormV.cpp", ToolForm);
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

 