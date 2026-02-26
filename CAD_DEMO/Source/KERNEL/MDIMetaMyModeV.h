// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaMyModeVH
#define MDIMetaMyModeVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMetaMyMode : public TMDIMetaNode
{
__published:	// IDE-managed Components
  TTabSheet *tsMode;
  TComboBox *cbCAM;
  TLabel *lCAM;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
   TMDIMetaMyMode(TComponent* Owner,TMetaMyMode *MM);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaMyMode *MDIMetaMyMode;
//---------------------------------------------------------------------------
#endif
