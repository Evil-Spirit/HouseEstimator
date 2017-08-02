//---------------------------------------------------------------------------

#ifndef MDISignVectorEditVH
#define MDISignVectorEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIObjectEditV.h"
#include "SimpleEditV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDISIGNVECEDIT : public TMDISimpleEdit
{
__published:	// IDE-managed Components
    TComboBox *ComboBox1;
    TComboBox *ComboBox2;
    TComboBox *ComboBox3;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
private:	// User declarations
public:		// User declarations
    __fastcall TMDISIGNVECEDIT(TComponent* Owner);
__fastcall TMDISIGNVECEDIT(TComponent* Owner,TControl *_Parent,TMyObject *_Obj,const AnsiString& _Text,void *_Data);
void Refresh();
void *Value();
void SETUP();
TComboBox *A[3];
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDISIGNVECEDIT *MDISIGNVECEDIT;
//---------------------------------------------------------------------------
#endif
