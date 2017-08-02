//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LoginForm.h"
#include "Usefuls.h"
#include "SkinEngineV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SUISkinEngine"
#pragma resource "*.dfm"
TfrmLogin *frmLogin;
//---------------------------------------------------------------------------
__fastcall TfrmLogin::TfrmLogin(TComponent* Owner)
  : TForm(Owner)
{
  //SkinEngine->Active = false;
  //SkinEngine->SkinFile = GetSkinFile();
  //SkinEngine->Active = true;
  SkinEngine->AddForm_BCB(this);
}
//---------------------------------------------------------------------------
void __fastcall TfrmLogin::FormShow(TObject *Sender)
{
  btnOKPressed = false;    
}
//---------------------------------------------------------------------------
void __fastcall TfrmLogin::btnOKClick(TObject *Sender)
{
	btnOKPressed = true;
	if (edtName->Text.Trim().LowerCase() == AnsiString("1") &&
		edtPassword->Text.Trim().LowerCase() == AnsiString("1") )
	{
		ModalResult = mrOk;
		this->Close();
	}
	else
	{
		WarningMsg("Некорректный логин или пароль!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmLogin::btnCancelClick(TObject *Sender)
{
	Application->Terminate();
	  ModalResult = mrCancel;
	  this->Close();
}
//---------------------------------------------------------------------------
