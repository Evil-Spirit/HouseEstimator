// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
USEFORMNS("ObjectInspectorU.pas", Objectinspectoru, ObjectInspectorF);
USEFORMNS("PictureEditorU.pas", Pictureeditoru, PictureEditorF);
USEFORMNS("StringListEditorU.pas", Stringlisteditoru, StringListEditorF);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//   Package source.
//---------------------------------------------------------------------------
#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
//---------------------------------------------------------------------------
