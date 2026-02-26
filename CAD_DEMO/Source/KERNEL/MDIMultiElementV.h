// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMultiElementVH
#define MDIMultiElementVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIElementV.h"
//---------------------------------------------------------------------------
class TMetaMultiElement;
class COMMONAL_API TMDIMultiElement : public TMDIElement
{
__published:	// IDE-managed Components
    TTabSheet *tsMultiElement;
    TCheckBox *cbIsSizer;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    void SETUP();
     TMDIMultiElement(TComponent* Owner,TMetaMultiElement *MN);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMultiElement *MDIMultiElement;
//---------------------------------------------------------------------------
#endif
