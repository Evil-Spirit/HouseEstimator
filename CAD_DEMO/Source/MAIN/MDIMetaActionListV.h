// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMetaActionListVH
#define MDIMetaActionListVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class TMetaNode;
class TMDIMetaActionList : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsAction;
    TLabel *Label3;
    TPanel *BMPSet;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    virtual void SETUP();
     TMDIMetaActionList(TComponent* Owner,TMetaNode* N);
};
//---------------------------------------------------------------------------
extern  TMDIMetaActionList *MDIMetaActionList;
//---------------------------------------------------------------------------
#endif
