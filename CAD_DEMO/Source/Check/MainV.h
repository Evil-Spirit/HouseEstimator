// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MainVH
#define MainVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TLuaModule;
class TLuaEditorInterface;

class TMain : public TForm
{
__published:	// IDE-managed Components
    void  FormCreate(TObject *Sender);
    void  FormClose(TObject *Sender, TCloseAction &Action);
    void  FormShortCut(TWMKey &Msg, bool &Handled);
private:	// User declarations
public:		// User declarations
     TMain(TComponent* Owner);
    TLuaModule* LM;
    TLuaEditorInterface* LE;
};
//---------------------------------------------------------------------------
extern  TMain *Main;
//---------------------------------------------------------------------------
#endif
