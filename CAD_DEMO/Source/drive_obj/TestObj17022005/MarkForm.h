// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MarkFormH
#define MarkFormH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
	void  AcceptClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	int selection;
	int value;
	 TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TForm4 *Form4;
//---------------------------------------------------------------------------
#endif

