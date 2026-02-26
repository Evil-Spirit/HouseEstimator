// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "compat/SUISkinEngine.hpp"
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
  void  FormShow(TObject *Sender);
  void  btnOKClick(TObject *Sender);
  void  btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   TfrmLogin(TComponent* Owner);
  bool btnOKPressed;
};
//---------------------------------------------------------------------------
extern  TfrmLogin *frmLogin;
//---------------------------------------------------------------------------
#endif
