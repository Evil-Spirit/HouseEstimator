//---------------------------------------------------------------------------

#ifndef MDIMetaMenuItemVH
#define MDIMetaMenuItemVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaUIV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMDIMetaMenuItem : public TMDIMetaUI
{
__published:	// IDE-managed Components
    TPanel *MetaAction;
    TLabel *Label3;
    TPanel *ChildBMPSet;
    TLabel *Label2;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    virtual void SETUP();
    __fastcall TMDIMetaMenuItem(TComponent* Owner,TMetaNode *N);
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIMetaMenuItem *MDIMetaMenuItem;
//---------------------------------------------------------------------------
#endif
