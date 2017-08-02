//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Convert.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)	
	{
//		Edit1->Enabled = true;
		Edit2->Enabled = true;
		Edit3->Enabled = true;
	} else
	{
//		Edit1->Enabled = false;
		Edit2->Enabled = false;
		Edit3->Enabled = false;
	}
}
//---------------------------------------------------------------------------



