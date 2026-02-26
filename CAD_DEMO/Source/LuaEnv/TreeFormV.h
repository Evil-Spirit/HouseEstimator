// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef TreeFormVH
#define TreeFormVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyTemplates.h"
#include "Usefuls.h"
#include "FloatingV.h"
#include "MyMDIChildV.h"

extern "C"
{
#include "lua.h"
}

//---------------------------------------------------------------------------
class COMMONAL_API TTreeWindow : public TMyMDIChild
{
__published:	// IDE-managed Components
    TTreeView *Tree;
private:	// User declarations
public:		// User declarations
     TTreeWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
//extern  TStackWindow *StackWindow;
//---------------------------------------------------------------------------
#endif
