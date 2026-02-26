// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIHasAngleVH
#define MDIHasAngleVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
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
 TMDIAngle(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIAngle *MDIAngle;
//---------------------------------------------------------------------------
#endif
