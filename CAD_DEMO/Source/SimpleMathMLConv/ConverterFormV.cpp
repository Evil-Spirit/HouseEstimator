//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConverterFormV.h"
#include "ConverterV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConverterForm *ConverterForm;
//---------------------------------------------------------------------------
__fastcall TConverterForm::TConverterForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TConverterForm::Button1Click(TObject *Sender)
{
	AnsiString _Text = RichEdit1->Text;
	AnsiString Result;
    Convert(_Text,Result);
	RichEdit2->Text = Result;
}
//---------------------------------------------------------------------------
