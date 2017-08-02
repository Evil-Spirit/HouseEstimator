//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "ClassExplorerV.h"
#include "QuckList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TClassExplorer *ClassExplorer;
//---------------------------------------------------------------------------
__fastcall TClassExplorer::TClassExplorer(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TClassExplorer::bCloseClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void RecurrentToTree(TClassNode* CN,TTreeNode* PNode,TTreeView* TreeView)
{
    TTreeNode *TreeNode = NULL;
    if (PNode)
        TreeNode = TreeView->Items->AddChild(PNode,CN->Name+AnsiSpace+IntToStr(CN->RegList->Count));
    else
        TreeNode = TreeView->Items->Add(NULL,CN->Name);
    for (int i=0;i<CN->ChildCount;i++)
    {
        RecurrentToTree(CN->Childs[i],TreeNode,TreeView);
    }
}

void __fastcall TClassExplorer::FormShow(TObject *Sender)
{
    RecurrentToTree(TMyObject::StaticType,NULL,TreeView1);
}
//---------------------------------------------------------------------------
