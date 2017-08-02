//---------------------------------------------------------------------------

#ifndef MarkFormH
#define MarkFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "MTL.h"

//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *Accept;
	TRadioGroup *RadioGroup1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TLabeledEdit *LabeledEdit1;
	void __fastcall AcceptClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	int selection;
	int value;
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif

