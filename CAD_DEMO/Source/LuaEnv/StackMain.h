//---------------------------------------------------------------------------

#ifndef StackMainH
#define StackMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "MyTemplates.h"
#include "Usefuls.h"
#include "FloatingV.h"

extern "C"
{
#include "lua.h"
}

//---------------------------------------------------------------------------
class COMMONAL_API TStackWindow : public TFloatForm
{
__published:	// IDE-managed Components
    TTreeView *Tree;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TStackWindow(TComponent* Owner);
    void __fastcall ViewStack(TMDelTList<TLuaVariable>* Vars); 
};
//---------------------------------------------------------------------------
//extern PACKAGE TStackWindow *StackWindow;
//---------------------------------------------------------------------------
#endif
