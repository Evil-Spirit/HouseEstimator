//---------------------------------------------------------------------------

#include <basepch.h>
#pragma hdrstop
USEFORM("MDIObjectEditV.cpp", MDIObjectEdit);
USEFORM("SimpleEditV.cpp", MDISimpleEdit);
USEFORM("MDISignVectorEditV.cpp", MDISIGNVECEDIT);
USEFORM("MDIBoolVectorEditV.cpp", MDIBOOLVECEDIT);
USEFORM("MDIVectorEditV.cpp", MDIVECEDIT);
USEFORM("MyMDIChildV.cpp", MyMDIChild);
USEFORM("FloatingV.cpp", FloatForm);
USEFORM("BaseFormV.cpp", BaseForm);
USEFORM("BaseDockSiteFormV.cpp", BaseDockSiteForm);
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
 