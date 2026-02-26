// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef LuaEditorVH
#define LuaEditorVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include <windows.h>
#include <richedit.h>
#include "MDIObjectEditV.h"

class TLuaModule;
struct SCNotification;
class TSciLexer;
//---------------------------------------------------------------------------
class COMMONAL_API TFLuaEditor : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    void  FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
    TLuaModule* GetModule();
public:		// User declarations
    // __property TLuaModule* Module {read=GetModule}; // [manual migration needed]
    TFLuaEditor(TComponent* Owner,TWinControl* _Parent,TLuaModule *_Module,const AnsiString& Text,void *Data);

	void  Notify(TSciLexer* SciLexer,SCNotification *notification);
    TSciLexer* SciLexer;
    void Refresh();
    void Apply();
    void SETUP();
    bool CheckSave();
};

COMMONAL_API AnsiString CheckSintax(const AnsiString& Code);

//---------------------------------------------------------------------------
extern COMMONAL_API TFLuaEditor *FLuaEditor;
//---------------------------------------------------------------------------
#endif
