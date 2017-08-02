//---------------------------------------------------------------------------

#ifndef MDIMetaActionVH
#define MDIMetaActionVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
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
    __fastcall TMDIMetaAction(TComponent* Owner,TMetaNode *N);
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIMetaAction *MDIMetaAction;
//---------------------------------------------------------------------------
#endif
