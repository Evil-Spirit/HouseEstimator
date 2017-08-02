//---------------------------------------------------------------------------

#ifndef MDIHasSizeVH
#define MDIHasSizeVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDISize : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPanel *LOW;
    TPanel *HI;
    TPanel *DEFAULT;
    TPanel *STEP;
private:	// User declarations
public:		// User declarations
    virtual void SETUP();
    __fastcall TMDISize(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);

};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDISize *MDISize;
//---------------------------------------------------------------------------
#endif
