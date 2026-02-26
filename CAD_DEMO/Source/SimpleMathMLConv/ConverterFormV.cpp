// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"

#include "ConverterFormV.h"
#include "ConverterV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TConverterForm *ConverterForm;
//---------------------------------------------------------------------------
 TConverterForm::TConverterForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void  TConverterForm::Button1Click(TObject *Sender)
{
	AnsiString _Text = RichEdit1->Text;
	AnsiString Result;
    Convert(_Text,Result);
	RichEdit2->Text = Result;
}
//---------------------------------------------------------------------------
