//---------------------------------------------------------------------------

#ifndef MDIBMPSetVH
#define MDIBMPSetVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDIBMPSet : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *tsBMPSet;
    TPanel *BMPSet;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    virtual void SETUP();

    __fastcall TMDIBMPSet(TComponent* Owner,TBMPSet *N);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIBMPSet *MDIBMPSet;
//---------------------------------------------------------------------------
#endif
