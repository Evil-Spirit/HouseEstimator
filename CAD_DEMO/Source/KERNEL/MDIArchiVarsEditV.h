// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIArchiVarsEditVH
#define MDIArchiVarsEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class TMetaNodeCollection;
class TMDIArchiVarsEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPanel *AFirstPlatform;
    TPanel *ADefaultLand;
    TPanel *APlatform_Land;
    TLabel *Label5;
    TLabel *Label7;
    TLabel *Label8;
private:	// User declarations
public:		// User declarations
    virtual void Refresh();
    virtual void Apply();
    virtual  bool Checked();
    virtual void SETUP();
     TMDIArchiVarsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    TMetaNodeCollection* MNC();
};
//---------------------------------------------------------------------------
extern  TMDIArchiVarsEdit *MDIArchiVarsEdit;
//---------------------------------------------------------------------------
#endif
