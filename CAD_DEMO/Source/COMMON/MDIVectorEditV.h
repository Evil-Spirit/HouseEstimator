//---------------------------------------------------------------------------

#ifndef MDIVectorEditVH
#define MDIVectorEditVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//#include "MDIObjectEditV.h"
#include "SimpleEditV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDIVECEDIT : public TMDISimpleEdit
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *Edit1;
    TEdit *Edit2;
    TEdit *Edit3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
	TCheckBox *IsProportional;
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
__fastcall TMDIVECEDIT(TComponent* Owner,TControl *_Parent,TMyObject *_Obj,const AnsiString& _Text,void *_Data);

void SETUP();
void *Value();
bool CustomChecked();
void Refresh();
TEdit *A[3];

};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDIVECEDIT *MDIVECEDIT;
//---------------------------------------------------------------------------
#endif
