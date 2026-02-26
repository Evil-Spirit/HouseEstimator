// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef DialogCheckUH
#define DialogCheckUH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyDialogU.h"
//---------------------------------------------------------------------------
class TCheckForm : public TForm
{
  __published:
    TButton *EditB;
    TButton *LoadB;
    TButton *SaveB;
    TButton *CreateB;
    TButton *NewB;
    TButton *ExitB;
    void  SaveBClick(TObject *Sender);
    void  LoadBClick(TObject *Sender);
    void  EditBClick(TObject *Sender);
    void  CreateBClick(TObject *Sender);
    void  NewBClick(TObject *Sender);
    void  ExitBClick(TObject *Sender);

    public:
   TCheckForm(TComponent* Owner);
    TMyDialog* FDialog;
};

//---------------------------------------------------------------------------
extern  TCheckForm *CheckForm;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
