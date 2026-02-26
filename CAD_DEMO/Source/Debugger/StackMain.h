// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef StackMainH
#define StackMainH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyTemplates.h"
#include "Usefuls.h"

extern "C"
{
#include "lua.h"
}

//---------------------------------------------------------------------------
class TStackWindow : public TForm
{
__published:	// IDE-managed Components
    TTreeView *Tree;
    void  FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
     TStackWindow(TComponent* Owner);
    void  ViewStack(TMDelTList<TLuaVariable>* Vars); 
};
//---------------------------------------------------------------------------
extern  TStackWindow *StackWindow;
//---------------------------------------------------------------------------
#endif
