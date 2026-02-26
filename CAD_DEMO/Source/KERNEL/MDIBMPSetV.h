// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIBMPSetVH
#define MDIBMPSetVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIBMPSet : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsBMPSet;
    TPanel *BMPSet;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    virtual void SETUP();

     TMDIBMPSet(TComponent* Owner,TBMPSet *N);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIBMPSet *MDIBMPSet;
//---------------------------------------------------------------------------
#endif
