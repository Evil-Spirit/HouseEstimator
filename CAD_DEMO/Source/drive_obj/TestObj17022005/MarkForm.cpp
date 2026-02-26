// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"

#include "MarkForm.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
 TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void  TForm4::AcceptClick(TObject *Sender)
{
//	selection = RadioGroup1->ItemIndex;
	if (Form4->RadioButton1->Checked)
		selection = 0;
	if (Form4->RadioButton2->Checked)
		selection = 1;
	value = LabeledEdit1->Text.ToInt();
}
//---------------------------------------------------------------------------

