//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SUISkinEngine.hpp"
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmLogin : public TForm
{
__published:	// IDE-managed Components
  TButton *btnOK;
  TButton *btnCancel;
  TLabel *Label1;
  TLabel *Label2;
  TEdit *edtName;
  TEdit *edtPassword;
  TImage *Image1;
  void __fastcall FormShow(TObject *Sender);
  void __fastcall btnOKClick(TObject *Sender);
  void __fastcall btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfrmLogin(TComponent* Owner);
  bool btnOKPressed;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLogin *frmLogin;
//---------------------------------------------------------------------------
#endif
