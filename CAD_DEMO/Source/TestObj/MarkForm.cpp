//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MarkForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::AcceptClick(TObject *Sender)
{
//	selection = RadioGroup1->ItemIndex;
	if (Form4->RadioButton1->Checked)
		selection = 0;
	if (Form4->RadioButton2->Checked)
		selection = 1;
	value = LabeledEdit1->Text.ToInt();
}
//---------------------------------------------------------------------------

