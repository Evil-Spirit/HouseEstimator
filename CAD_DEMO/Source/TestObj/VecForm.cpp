// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"

#include "VecForm.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
 TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void  TForm3::AcceptClick(TObject *Sender)
{
	if (IS_FLOAT(EditX->Text))
		Vector.x = StrToMBTi(EditX->Text);

	if (IS_FLOAT(EditY->Text))
		Vector.y = StrToMBTi(EditY->Text);

	if (IS_FLOAT(EditZ->Text))
		Vector.z = StrToMBTi(EditZ->Text);
}
//---------------------------------------------------------------------------

void  TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
//	Vector = Default;	
}
//---------------------------------------------------------------------------
void TForm3::SetDefault(TIntVec v)
{
	FDefault	= v;
	Vector		= v;
	EditX->Text = FloatToStr(Default.x);
	EditY->Text = FloatToStr(Default.y);
	EditZ->Text = FloatToStr(Default.z);
}

