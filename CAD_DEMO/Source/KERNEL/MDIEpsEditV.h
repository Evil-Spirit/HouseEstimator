// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIEPSEDITVH
#define MDIEPSEDITVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
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
     TMDIEpsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIEpsEdit *MDIEpsEdit;

//---------------------------------------------------------------------------
#endif
