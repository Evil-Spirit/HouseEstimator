//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("EditorV.cpp", Editor2D);
USEFORM("ProgramPropertyV.cpp", ProgramProperty);
USEFORM("ParamEnteringV.cpp", ParamEntering);
USEFORM("MyViewV.cpp", MyView);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TEditor2D), &Editor2D);
		Application->CreateForm(__classid(TProgramProperty), &ProgramProperty);
		Application->CreateForm(__classid(TParamEntering), &ParamEntering);
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
