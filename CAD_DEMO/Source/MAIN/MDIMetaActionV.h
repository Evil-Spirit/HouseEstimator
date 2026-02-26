// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaActionVH
#define MDIMetaActionVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class TMetaNode;

class TMDIMetaAction : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsAction;
    TStaticText *StaticText1;
    TComboBoxEx *cbeUserImage;
    TCheckBox *cbEnabled;
    TCheckBox *cbVisible;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    virtual void SETUP();
     TMDIMetaAction(TComponent* Owner,TMetaNode *N);
};
//---------------------------------------------------------------------------
extern  TMDIMetaAction *MDIMetaAction;
//---------------------------------------------------------------------------
#endif
