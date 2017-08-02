//---------------------------------------------------------------------------

#ifndef MainVH
#define MainVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TLuaModule;
class TLuaEditorInterface;

class TMain : public TForm
{
__published:	// IDE-managed Components
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShortCut(TWMKey &Msg, bool &Handled);
private:	// User declarations
public:		// User declarations
    __fastcall TMain(TComponent* Owner);
    TLuaModule* LM;
    TLuaEditorInterface* LE;
};
//---------------------------------------------------------------------------
extern PACKAGE TMain *Main;
//---------------------------------------------------------------------------
#endif
