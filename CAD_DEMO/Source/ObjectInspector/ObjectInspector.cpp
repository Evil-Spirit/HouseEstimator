//---------------------------------------------------------------------------
#include <basepch.h>
#pragma hdrstop
USEFORMNS("ObjectInspectorU.pas", Objectinspectoru, ObjectInspectorF);
USEFORMNS("PictureEditorU.pas", Pictureeditoru, PictureEditorF);
USEFORMNS("StringListEditorU.pas", Stringlisteditoru, StringListEditorF);
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
