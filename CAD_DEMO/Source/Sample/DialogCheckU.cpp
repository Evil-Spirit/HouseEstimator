// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include "compat/vcl_qt.h"
#include <stdlib.h>

#include "LuaEnvV.h"
#include "MyDialogEditU.h"
#include "DialogCheckU.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"

void RegisterDialogCheck()
{
  LuaAllOpen();
}

#pragma startup RegisterDialogCheck

TCheckForm *CheckForm;
//---------------------------------------------------------------------------
 TCheckForm::TCheckForm(TComponent* Owner) : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void  TCheckForm::SaveBClick(TObject *Sender)
{
    if (FDialog)
        FDialog->Save("checkfile.txt");
}

//---------------------------------------------------------------------------
void  TCheckForm::LoadBClick(TObject *Sender)
{
    if (FDialog)
    {
        FDialog->Load("checkfile.txt");
        FDialog->RecurrentCheck();
    }
}

//---------------------------------------------------------------------------
void  TCheckForm::EditBClick(TObject *Sender)
{
    if (FDialog)
        FDialog->Edit(NULL, NULL, NULL);
}

//---------------------------------------------------------------------------
void  TCheckForm::CreateBClick(TObject *Sender)
{
    if (FDialog)
        TForm* NewForm = FDialog->CreateForm(NULL, NULL);
}

//---------------------------------------------------------------------------
void  TCheckForm::NewBClick(TObject *Sender)
{
    FDialog = new TMyDialog();
}

//---------------------------------------------------------------------------
void  TCheckForm::ExitBClick(TObject *Sender)
{
    exit(EXIT_SUCCESS);
}

//---------------------------------------------------------------------------


