//---------------------------------------------------------------------------
#ifndef DialogCheckUH
#define DialogCheckUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
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
    void __fastcall SaveBClick(TObject *Sender);
    void __fastcall LoadBClick(TObject *Sender);
    void __fastcall EditBClick(TObject *Sender);
    void __fastcall CreateBClick(TObject *Sender);
    void __fastcall NewBClick(TObject *Sender);
    void __fastcall ExitBClick(TObject *Sender);

    public:
  __fastcall TCheckForm(TComponent* Owner);
    TMyDialog* FDialog;
};

//---------------------------------------------------------------------------
extern PACKAGE TCheckForm *CheckForm;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
