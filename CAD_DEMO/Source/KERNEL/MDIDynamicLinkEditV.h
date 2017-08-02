//---------------------------------------------------------------------------

#ifndef MDIDynamicLinkEditVH
#define MDIDynamicLinkEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
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
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    virtual void MNApply();
    virtual bool MNChecked();

    void SETUP();
    __fastcall TMDIDynamicLinkEdit(TComponent* Owner,TDynamicLink *N);

};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIDynamicLinkEdit *MDIDynamicLinkEdit;
//---------------------------------------------------------------------------
#endif
