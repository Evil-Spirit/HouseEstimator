//---------------------------------------------------------------------------

#ifndef MDIMetaUIVH
#define MDIMetaUIVH
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
class TMDIMetaUI : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsMetaUI;
    TCheckBox *cbEnabled;
    TCheckBox *cbVisible;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    __fastcall TMDIMetaUI(TComponent* Owner,TMetaNode* N);
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIMetaUI *MDIMetaUI;
//---------------------------------------------------------------------------
#endif
