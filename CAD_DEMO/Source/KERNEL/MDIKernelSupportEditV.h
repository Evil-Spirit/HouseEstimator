// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIKernelSupportEditVH
#define MDIKernelSupportEditVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIObjectEditV.h"
//---------------------------------------------------------------------------
class TKernelSupport;
class COMMONAL_API TMDIKernelSupportEdit : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TPanel *AMetaLabel3D;
    TPanel *ADefaultLink;
    TPanel *ADefaultTarget;
    TPanel *ADEFAULT_SIZE;
    TPanel *ADEFAULT_MODE;
    TPanel *A_3D_MODE;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label5;
    TPanel *ARootElement;
    TLabel *Label8;
    TPanel *ASubRootElement;
private:	// User declarations
public:		// User declarations
    virtual void Refresh();
    virtual void Apply();
    virtual  bool Checked();
    virtual void SETUP();
     TMDIKernelSupportEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    TKernelSupport* MNC();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIKernelSupportEdit *MDIKernelSupportEdit;
//---------------------------------------------------------------------------
#endif
