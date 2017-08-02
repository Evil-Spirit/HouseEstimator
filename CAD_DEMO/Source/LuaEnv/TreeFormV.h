//---------------------------------------------------------------------------

#ifndef TreeFormVH
#define TreeFormVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
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
    __fastcall TTreeWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
//extern PACKAGE TStackWindow *StackWindow;
//---------------------------------------------------------------------------
#endif
