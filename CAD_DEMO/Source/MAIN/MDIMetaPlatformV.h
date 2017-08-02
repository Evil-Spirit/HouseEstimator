//---------------------------------------------------------------------------

#ifndef MDIMetaPlatformVH
#define MDIMetaPlatformVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIElementV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMetaPlatform;
class TMDIMetaPlatform : public TMDIElement
{
__published:	// IDE-managed Components
    TTabSheet *tsPlatform;
    TCheckBox *cbFirst;
    TCheckBox *cbLand;
    void __fastcall cbFirstClick(TObject *Sender);
    void __fastcall cbLandClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    __fastcall TMDIMetaPlatform(TComponent* Owner,TMetaPlatform *M);
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIMetaPlatform *MDIMetaPlatform;
//---------------------------------------------------------------------------
#endif
