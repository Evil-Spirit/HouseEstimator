//---------------------------------------------------------------------------

#ifndef LuaEditorVH
#define LuaEditorVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <windows.h>
#include <richedit.h>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <StdCtrls.hpp>
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
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
    TLuaModule* GetModule();
public:		// User declarations
    __property TLuaModule* Module = {read = GetModule};
    TFLuaEditor(TComponent* Owner,TWinControl* _Parent,TLuaModule *_Module,const AnsiString& Text,void *Data);

	void __fastcall Notify(TSciLexer* SciLexer,SCNotification *notification);
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
