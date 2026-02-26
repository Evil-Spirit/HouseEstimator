// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIHasSizeVH
#define MDIHasSizeVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
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
     TMDISize(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);

};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDISize *MDISize;
//---------------------------------------------------------------------------
#endif
