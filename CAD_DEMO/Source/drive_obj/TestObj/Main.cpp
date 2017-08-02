//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Object.cpp", Form1);
USEFORM("MyViewV.cpp", MyView);
USEFORM("VecForm.cpp", Form3);
USEFORM("MarkForm.cpp", Form4);
USEFORM("Convert.cpp", Form2);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

