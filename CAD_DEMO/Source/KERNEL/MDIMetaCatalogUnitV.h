// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaCatalogUnitVH
#define MDIMetaCatalogUnitVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMetaCatalogUnit : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TPanel *ASSOCIATED;
private:	// User declarations
public:		// User declarations
     TMDIMetaCatalogUnit(TComponent* Owner,TMetaNode *N);
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
    virtual void SETUP();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaCatalogUnit *MDIMetaCatalogUnit;
//---------------------------------------------------------------------------
#endif
