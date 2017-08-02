//---------------------------------------------------------------------------

#ifndef MDIMetaToolEditVH
#define MDIMetaToolEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMetaToolEdit : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsMetaTool;
private:	// User declarations
public:		// User declarations
    __fastcall TMDIMetaToolEdit(TComponent* Owner,TMetaNode *N);
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
    virtual void SETUP();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaToolEdit *MDIMetaToolEdit;
//---------------------------------------------------------------------------
#endif
