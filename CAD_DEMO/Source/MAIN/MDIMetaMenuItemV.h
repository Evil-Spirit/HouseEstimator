// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaMenuItemVH
#define MDIMetaMenuItemVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaUIV.h"
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
     TMDIMetaMenuItem(TComponent* Owner,TMetaNode *N);
};
//---------------------------------------------------------------------------
extern  TMDIMetaMenuItem *MDIMetaMenuItem;
//---------------------------------------------------------------------------
#endif
