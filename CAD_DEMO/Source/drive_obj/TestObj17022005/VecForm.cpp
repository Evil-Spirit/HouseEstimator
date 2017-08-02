//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VecForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm3::AcceptClick(TObject *Sender)
{
	if (IS_FLOAT(EditX->Text))
		Vector.x = StrToMBTi(EditX->Text);

	if (IS_FLOAT(EditY->Text))
		Vector.y = StrToMBTi(EditY->Text);

	if (IS_FLOAT(EditZ->Text))
		Vector.z = StrToMBTi(EditZ->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
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

