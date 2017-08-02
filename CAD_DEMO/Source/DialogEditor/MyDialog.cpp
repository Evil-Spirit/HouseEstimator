//---------------------------------------------------------------------------
#include <basepch.h>
#pragma hdrstop

USEFORM("MyDialogEditU.cpp", MyDialogEdit);
USEFORM("ToolBarU.cpp", ToolBarForm);
USEFORM("MenuF.cpp", MainMenuF);
USEFORM("TreeViewF.cpp", ObjectTreeView);
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
 