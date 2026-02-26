// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDILuaEditorVH
#define MDILuaEditorVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
class TLuaModule;
class TFLuaEditor;
//---------------------------------------------------------------------------
class  TMDILuaEditor : public TForm
{
__published:	// IDE-managed Components
    void  FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    TLuaModule* LM;
    TFLuaEditor* LF;
     TMDILuaEditor(TComponent* Owner,TLuaModule* _LM);
};
//---------------------------------------------------------------------------
extern  TMDILuaEditor *MDILuaEditor;
//---------------------------------------------------------------------------
#endif
