//---------------------------------------------------------------------------

#ifndef MDIEPSEDITVH
#define MDIEPSEDITVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDIEpsEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPanel *POSEPS;
    TPanel *ANGLEEPS;
    TPanel *SIZEEPS;
private:	// User declarations
public:		// User declarations
    virtual void SETUP();
    __fastcall TMDIEpsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIEpsEdit *MDIEpsEdit;

//---------------------------------------------------------------------------
#endif
