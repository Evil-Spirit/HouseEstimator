// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include "compat/vcl_qt.h"

#include "MenuF.h"
#include "MyDialogEditU.h"
#include "ToolBarU.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"

TMainMenuF *MenuF = NULL;
//---------------------------------------------------------------------------
 TMainMenuF::TMainMenuF(TComponent* Owner) : TForm(Owner)
{
//    MenuF = this;
    Show();
}
//---------------------------------------------------------------------------
void  TMainMenuF::mmObjectInspectorClick(TObject *Sender)
{
    ObjInspector->Show();
}

//---------------------------------------------------------------------------
void  TMainMenuF::mmObjectTreeViewClick(TObject *Sender)
{
//    TreeView->Show();
}

//---------------------------------------------------------------------------
void  TMainMenuF::mmToolBarClick(TObject *Sender)
{
    ToolBarF->Show();
}

//---------------------------------------------------------------------------
