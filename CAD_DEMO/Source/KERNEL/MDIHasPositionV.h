// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIHasPositionVH
#define MDIHasPositionVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIPosition : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPanel *STEP;
    TPanel *PLOW;
    TPanel *PHI;
private:	// User declarations
public:		// User declarations
virtual void SETUP();
//virtual bool LocalChecked();
//virtual bool LocalApply(){return(true);};
     TMDIPosition(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIPosition *MDIPosition;
//---------------------------------------------------------------------------
#endif
