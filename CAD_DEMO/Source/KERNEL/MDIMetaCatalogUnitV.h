//---------------------------------------------------------------------------

#ifndef MDIMetaCatalogUnitVH
#define MDIMetaCatalogUnitVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMetaCatalogUnit : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TPanel *ASSOCIATED;
private:	// User declarations
public:		// User declarations
    __fastcall TMDIMetaCatalogUnit(TComponent* Owner,TMetaNode *N);
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
    virtual void SETUP();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaCatalogUnit *MDIMetaCatalogUnit;
//---------------------------------------------------------------------------
#endif
