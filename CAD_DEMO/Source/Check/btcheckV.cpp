//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "btcheckV.h"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    SBE = new TBindedStateBlock("FirstState",&State1, 1, Mouse_Down);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    SBE->Edit(this, NULL, NULL);
    SBE->ReFresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    delete SBE;
}
//---------------------------------------------------------------------------

void TForm1::State1()
{
}

