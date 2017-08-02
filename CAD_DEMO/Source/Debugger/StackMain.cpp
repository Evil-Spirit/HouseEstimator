//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LuaModuleV.h"
#include "LuaStationV.h"
#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"
#include "StackMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStackWindow *StackWindow;

//---------------------------------------------------------------------------
__fastcall TStackWindow::TStackWindow(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TStackWindow::ViewStack(TMDelTList<TLuaVariable>* Vars)
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

void __fastcall TStackWindow::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action=caHide;
}
//---------------------------------------------------------------------------



