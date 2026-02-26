// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIDynamicLinkEditVH
#define MDIDynamicLinkEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIDynamicLinkEdit : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *TabSheet1;
    TGroupBox *GroupBox9;
    TComboBoxEx *cbeElements;
    TGroupBox *GroupBox10;
    TComboBoxEx *cbeLinks;
    TCheckBox *cbNeeded;
    void  FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    virtual void MNApply();
    virtual bool MNChecked();

    void SETUP();
     TMDIDynamicLinkEdit(TComponent* Owner,TDynamicLink *N);

};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIDynamicLinkEdit *MDIDynamicLinkEdit;
//---------------------------------------------------------------------------
#endif
