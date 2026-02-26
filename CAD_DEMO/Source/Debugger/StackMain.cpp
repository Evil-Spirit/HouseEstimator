// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "LuaModuleV.h"
#include "LuaStationV.h"
#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"
#include "StackMain.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TStackWindow *StackWindow;

//---------------------------------------------------------------------------
 TStackWindow::TStackWindow(TComponent* Owner)
    : TForm(Owner)
{
}

void  TStackWindow::ViewStack(TMDelTList<TLuaVariable>* Vars)
{
    Tree->Items->Clear();
    TTreeNode *Prnt=Tree->Items->Add(NULL,"Stack");

    if (Vars->Count>0)
    {
        TLuaVariable *Item = Vars->First();
        for (int i=0;i<Vars->Count;i++)
        {
            Tree->Items->AddChild(Prnt,Item->Type+":"+Item->Value);
            Vars->Next();
            Item = Vars->Current;
        }
        Tree->FullExpand();
    }
}

//---------------------------------------------------------------------------

void  TStackWindow::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action=caHide;
}
//---------------------------------------------------------------------------



