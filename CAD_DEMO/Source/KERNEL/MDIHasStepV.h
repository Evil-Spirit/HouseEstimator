// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIHasStepVH
#define MDIHasStepVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIHasStep : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPanel *BaseStep;
    TPanel *DefMulti;
    TCheckBox *cbHard;
private:	// User declarations
public:		// User declarations
    virtual void Refresh();
    virtual void Apply();
    virtual  bool Checked();
    virtual void SETUP();
 TMDIHasStep(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIHasStep *MDIHasStep;
//---------------------------------------------------------------------------
#endif
