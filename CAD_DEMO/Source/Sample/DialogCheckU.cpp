//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include <vcl.h>
#include <stdlib.h>
#pragma hdrstop

#include "LuaEnvV.h"
#include "MyDialogEditU.h"
#include "DialogCheckU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

void RegisterDialogCheck()
{
  LuaAllOpen();
}

#pragma startup RegisterDialogCheck

TCheckForm *CheckForm;
//---------------------------------------------------------------------------
__fastcall TCheckForm::TCheckForm(TComponent* Owner) : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TCheckForm::SaveBClick(TObject *Sender)
{
    if (FDialog)
        FDialog->Save("checkfile.txt");
}

//---------------------------------------------------------------------------
void __fastcall TCheckForm::LoadBClick(TObject *Sender)
{
    if (FDialog)
    {
        FDialog->Load("checkfile.txt");
        FDialog->RecurrentCheck();
    }
}

//---------------------------------------------------------------------------
void __fastcall TCheckForm::EditBClick(TObject *Sender)
{
    if (FDialog)
        FDialog->Edit(NULL, NULL, NULL);
}

//---------------------------------------------------------------------------
void __fastcall TCheckForm::CreateBClick(TObject *Sender)
{
    if (FDialog)
        TForm* NewForm = FDialog->CreateForm(NULL, NULL);
}

//---------------------------------------------------------------------------
void __fastcall TCheckForm::NewBClick(TObject *Sender)
{
    FDialog = new TMyDialog();
}

//---------------------------------------------------------------------------
void __fastcall TCheckForm::ExitBClick(TObject *Sender)
{
    exit(EXIT_SUCCESS);
}

//---------------------------------------------------------------------------


