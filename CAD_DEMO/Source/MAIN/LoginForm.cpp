// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"

#include "LoginForm.h"
#include "Usefuls.h"
#include "SkinEngineV.h"
//---------------------------------------------------------------------------
#pragma link "SUISkinEngine"
#pragma resource "*.dfm"
TfrmLogin *frmLogin;
//---------------------------------------------------------------------------
 TfrmLogin::TfrmLogin(TComponent* Owner)
  : TForm(Owner)
{
  //SkinEngine->Active = false;
  //SkinEngine->SkinFile = GetSkinFile();
  //SkinEngine->Active = true;
  SkinEngine->AddForm_BCB(this);
}
//---------------------------------------------------------------------------
void  TfrmLogin::FormShow(TObject *Sender)
{
  btnOKPressed = false;    
}
//---------------------------------------------------------------------------
void  TfrmLogin::btnOKClick(TObject *Sender)
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
		WarningMsg("Íåêîððåêòíûé ëîãèí èëè ïàðîëü!");
	}
}
//---------------------------------------------------------------------------
void  TfrmLogin::btnCancelClick(TObject *Sender)
{
	Application->Terminate();
	  ModalResult = mrCancel;
	  this->Close();
}
//---------------------------------------------------------------------------
