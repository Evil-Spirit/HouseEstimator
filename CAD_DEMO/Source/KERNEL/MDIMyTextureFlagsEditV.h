// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIMyTextureFlagsEditVH
#define MDIMyTextureFlagsEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
#include "VisTex.hpp"
#include "MetaClasses.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMyTextureFlagsEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPanel *Param;
    TPanel *Scale;
    TPanel *Shift;
    TComboBox *CBE;
    TLabel *Label1;
private:	// User declarations
public:		// User declarations
virtual void Refresh();
virtual void Apply();
virtual  bool Checked();
    virtual void SETUP();
     TMDIMyTextureFlagsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMyTextureFlagsEdit *MDIMyTextureFlagsEdit;
//---------------------------------------------------------------------------
#endif
