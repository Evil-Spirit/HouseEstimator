// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"

#include "Convert.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
 TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void  TForm2::CheckBox1Click(TObject *Sender)
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



