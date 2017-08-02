//---------------------------------------------------------------------------

#ifndef MDIArchiVarsEditVH
#define MDIArchiVarsEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ExtCtrls.hpp>
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
    __fastcall TMDIArchiVarsEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    TMetaNodeCollection* MNC();
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIArchiVarsEdit *MDIArchiVarsEdit;
//---------------------------------------------------------------------------
#endif
