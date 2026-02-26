// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaToolEditVH
#define MDIMetaToolEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMetaToolEdit : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsMetaTool;
private:	// User declarations
public:		// User declarations
     TMDIMetaToolEdit(TComponent* Owner,TMetaNode *N);
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
    virtual void SETUP();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaToolEdit *MDIMetaToolEdit;
//---------------------------------------------------------------------------
#endif
