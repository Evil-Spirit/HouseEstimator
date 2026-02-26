// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
//---------------------------------------------------------------------
//---------------------------------------------------------------------------
#if !defined(INTERNET_VER) && !defined(TRADE_VER)
#endif


//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TConfig), &Config);
         Application->CreateForm(__classid(TAboutBox), &AboutBox);
         Application->CreateForm(__classid(TPB), &PB);
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->Run();

	return 0;
}
//---------------------------------------------------------------------









