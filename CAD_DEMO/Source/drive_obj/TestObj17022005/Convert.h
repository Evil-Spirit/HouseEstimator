// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ConvertH
#define ConvertH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
	void  CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	 TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

