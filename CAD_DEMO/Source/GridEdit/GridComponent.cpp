//---------------------------------------------------------------------------

#include <basepch.h>
#pragma hdrstop
USEFORM("SectionDialogU.cpp", SectionDialog);
USEFORM("CellParameterU.cpp", CellParameter);
USEFORM("SelectColorU.cpp", SelectColor);
USEFORM("SelectBorderU.cpp", SelectBorder);
USEFORM("ImagesU.cpp", CGIL); /* TDataModule: File Type */
USEFORM("OffsetCellU.cpp", OffsetCell);
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
 