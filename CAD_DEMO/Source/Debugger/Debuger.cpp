// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TDebugForm), &DebugForm);
		Application->Run();
	return 0;
}
//---------------------------------------------------------------------





