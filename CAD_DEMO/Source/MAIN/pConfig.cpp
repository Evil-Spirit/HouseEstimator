//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("about.cpp", AboutBox);
USEFORM("ExcelExchangeV.cpp", ExcelExchange);
USEFORM("LOGOV.cpp", Logo);
USEFORM("MDIConfigV.cpp", MDIConfig);
USEFORM("MDICountReportV.cpp", MDICountReport);
USEFORM("MDIMetaUIV.cpp", MDIMetaUI);
USEFORM("MDINomenclatureV.cpp", MDINomenclature);
USEFORM("MDIVisibleSelectFloorV.cpp", MDIVisibleSelectFloor);
USEFORM("..\KERNEL\MDITriggerBlockEditV.cpp", MDITriggerBlockEdit);
USEFORM("ClassExplorerV.cpp", ClassExplorer);
USEFORM("Main.cpp", Config);
USEFORM("RoofEditV.cpp", RoofForm);
USEFORM("LoginForm.cpp", frmLogin);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TConfig), &Config);
     Application->CreateForm(__classid(TAboutBox), &AboutBox);
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

