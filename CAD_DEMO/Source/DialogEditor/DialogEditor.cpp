//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("ToolBarU.cpp", ToolBarForm);
USEFORM("MyDialogEditU.cpp", MyDialogEdit);
USEFORMNS("ObjectInspector\ObjectInspectorU.pas", Objectinspectoru, ObjectInspectorF);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TMyDialogEdit), &MyDialogEdit);
         Application->CreateForm(__classid(TObjectInspectorF), &ObjectInspectorF);
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
