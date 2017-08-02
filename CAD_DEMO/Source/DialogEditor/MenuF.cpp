//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include <vcl.h>
#pragma hdrstop

#include "MenuF.h"
#include "MyDialogEditU.h"
#include "ToolBarU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainMenuF *MenuF = NULL;
//---------------------------------------------------------------------------
__fastcall TMainMenuF::TMainMenuF(TComponent* Owner) : TForm(Owner)
{
//    MenuF = this;
    Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainMenuF::mmObjectInspectorClick(TObject *Sender)
{
    ObjInspector->Show();
}

//---------------------------------------------------------------------------
void __fastcall TMainMenuF::mmObjectTreeViewClick(TObject *Sender)
{
//    TreeView->Show();
}

//---------------------------------------------------------------------------
void __fastcall TMainMenuF::mmToolBarClick(TObject *Sender)
{
    ToolBarF->Show();
}

//---------------------------------------------------------------------------
