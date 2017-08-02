//---------------------------------------------------------------------------

#ifndef ConvertH
#define ConvertH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TCheckBox *CheckBox1;
	TLabeledEdit *Edit1;
	TLabeledEdit *Edit2;
	TLabeledEdit *Edit3;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

