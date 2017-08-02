//---------------------------------------------------------------------------

#ifndef MDILuaEditorVH
#define MDILuaEditorVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
class TLuaModule;
class TFLuaEditor;
//---------------------------------------------------------------------------
class PACKAGE TMDILuaEditor : public TForm
{
__published:	// IDE-managed Components
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    TLuaModule* LM;
    TFLuaEditor* LF;
    __fastcall TMDILuaEditor(TComponent* Owner,TLuaModule* _LM);
};
//---------------------------------------------------------------------------
extern PACKAGE TMDILuaEditor *MDILuaEditor;
//---------------------------------------------------------------------------
#endif
