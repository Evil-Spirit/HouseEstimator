//---------------------------------------------------------------------------

#ifndef MDIHasAngleVH
#define MDIHasAngleVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDIAngle : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPanel *LOW;
    TPanel *HI;
    TPanel *Mirrored;
private:	// User declarations
public:		// User declarations
virtual void SETUP();
__fastcall TMDIAngle(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIAngle *MDIAngle;
//---------------------------------------------------------------------------
#endif
