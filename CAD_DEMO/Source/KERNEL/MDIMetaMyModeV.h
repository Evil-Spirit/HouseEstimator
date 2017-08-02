//---------------------------------------------------------------------------

#ifndef MDIMetaMyModeVH
#define MDIMetaMyModeVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMetaMyMode : public TMDIMetaNode
{
__published:	// IDE-managed Components
  TTabSheet *tsMode;
  TComboBox *cbCAM;
  TLabel *lCAM;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
  __fastcall TMDIMetaMyMode(TComponent* Owner,TMetaMyMode *MM);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMetaMyMode *MDIMetaMyMode;
//---------------------------------------------------------------------------
#endif
