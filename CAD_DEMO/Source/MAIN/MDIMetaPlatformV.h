// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaPlatformVH
#define MDIMetaPlatformVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIElementV.h"
//---------------------------------------------------------------------------
class TMetaPlatform;
class TMDIMetaPlatform : public TMDIElement
{
__published:	// IDE-managed Components
    TTabSheet *tsPlatform;
    TCheckBox *cbFirst;
    TCheckBox *cbLand;
    void  cbFirstClick(TObject *Sender);
    void  cbLandClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
     TMDIMetaPlatform(TComponent* Owner,TMetaPlatform *M);
};
//---------------------------------------------------------------------------
extern  TMDIMetaPlatform *MDIMetaPlatform;
//---------------------------------------------------------------------------
#endif
