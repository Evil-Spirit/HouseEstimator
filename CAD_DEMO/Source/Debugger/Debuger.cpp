//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("DebugU.cpp", DebugForm);
USEFORM("GlobalMain.cpp", Global);
USEFORM("StackMain.cpp", StackWindow);
USEFORM("InspectorMain.cpp", DbgInspector);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TDebugForm), &DebugForm);
		Application->Run();
	return 0;
}
//---------------------------------------------------------------------





