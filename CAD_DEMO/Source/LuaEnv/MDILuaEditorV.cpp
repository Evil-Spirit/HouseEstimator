// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDILuaEditorV.h"
#include "LuaEditorV.h"
#include "LuaModuleV.h"

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMDILuaEditor *MDILuaEditor;
//---------------------------------------------------------------------------
 TMDILuaEditor::TMDILuaEditor(TComponent* Owner,TLuaModule* _LM)
    : TForm(Owner)
{
    LM = _LM;
    LF = new TFLuaEditor(this,this,LM,"",NULL);
    LF->Refresh();
}
//---------------------------------------------------------------------------
void  TMDILuaEditor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    LF->Apply();
    Action = caFree;
}
//---------------------------------------------------------------------------

