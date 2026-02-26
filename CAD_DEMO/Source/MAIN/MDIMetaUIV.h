// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaUIVH
#define MDIMetaUIVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class TMetaNode;
class TMDIMetaUI : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsMetaUI;
    TCheckBox *cbEnabled;
    TCheckBox *cbVisible;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
     TMDIMetaUI(TComponent* Owner,TMetaNode* N);
};
//---------------------------------------------------------------------------
extern  TMDIMetaUI *MDIMetaUI;
//---------------------------------------------------------------------------
#endif
