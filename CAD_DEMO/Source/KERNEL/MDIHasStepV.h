//---------------------------------------------------------------------------

#ifndef MDIHasStepVH
#define MDIHasStepVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ExtCtrls.hpp>
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
__fastcall TMDIHasStep(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIHasStep *MDIHasStep;
//---------------------------------------------------------------------------
#endif
