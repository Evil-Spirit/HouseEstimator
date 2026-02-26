// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "ClassExplorerV.h"
#include "QuckList.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TClassExplorer *ClassExplorer;
//---------------------------------------------------------------------------
 TClassExplorer::TClassExplorer(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void  TClassExplorer::bCloseClick(TObject *Sender)
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

void  TClassExplorer::FormShow(TObject *Sender)
{
    RecurrentToTree(TMyObject::StaticType,NULL,TreeView1);
}
//---------------------------------------------------------------------------
