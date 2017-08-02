//---------------------------------------------------------------------------

#ifndef MDIMyTextureModesVH
#define MDIMyTextureModesVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDIMyTextureModes : public TMDIObjectEdit
{
__published:	// IDE-managed Components
    TComboBox *cbMode;
    TLabel *lMode;
    TGroupBox *gbMinMax;
    TLabel *Label1;
    TEdit *edZMax;
    TLabel *Label2;
    TEdit *edZMin;
    void __fastcall cbModeChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMDIMyTextureModes(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data);
    void SETUP();
    void Refresh();
    bool Checked();
    void Apply();
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIMyTextureModes *MDIMyTextureModes;
//---------------------------------------------------------------------------
#endif
