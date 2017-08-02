//---------------------------------------------------------------------------

#ifndef MDIKernelSupportEditVH
#define MDIKernelSupportEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ExtCtrls.hpp>
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
    __fastcall TMDIKernelSupportEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    TKernelSupport* MNC();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIKernelSupportEdit *MDIKernelSupportEdit;
//---------------------------------------------------------------------------
#endif
