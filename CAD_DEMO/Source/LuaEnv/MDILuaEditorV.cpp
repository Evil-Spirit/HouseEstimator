//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDILuaEditorV.h"
#include "LuaEditorV.h"
#include "LuaModuleV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMDILuaEditor *MDILuaEditor;
//---------------------------------------------------------------------------
__fastcall TMDILuaEditor::TMDILuaEditor(TComponent* Owner,TLuaModule* _LM)
    : TForm(Owner)
{
    LM = _LM;
    LF = new TFLuaEditor(this,this,LM,"",NULL);
    LF->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TMDILuaEditor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    LF->Apply();
    Action = caFree;
}
//---------------------------------------------------------------------------

