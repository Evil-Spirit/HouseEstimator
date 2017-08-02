//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MyRegTreeV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TClassNode* TMyRegTree::StaticType = NULL;

TMyObject* TMyRegTree::CreateFunction()
{
    return new TMyRegTree();
}


TMyRegTree::TMyRegTree()
{
    RegisterNewClass< TMyObject, TMyRegTree >(this,false,&CreateFunction);
    Head = NULL;
}

TMyRegTree::~TMyRegTree()
{
    if (Head)
        delete Head;
}

TMyRegObject *TMyRegTree::AddChild(TMyRegObject *Node,TMyRegObject *NewNode)
{
    if (!Node)
    {
        if (Head)
            delete Head;
        Head = NewNode;
        OnAddNode(NULL,Head);
//        NewNode->Parent = NULL;
        return Head;
    }
    NewNode->Parent = Node;
    NewNode->MyTree = this;
    if (Node&&Node->TN)
        RecurrentFillTreeView(NewNode,(TTreeView*)(Node->TN->TreeView));
    OnAddNode(Node,NewNode);
    return NewNode;
}

void TMyRegTree::GetLookingTo(TMyRegObject *Node,TMyRegObject *MyRegObject,TMTList<TMyObject>& OBJL) const
{
    if (Node == NULL)
    {
        GetLookingTo(Head,MyRegObject,OBJL);
        return;
    }

    for (int i=0;i<Node->ChildList->Count;i++)
        GetLookingTo((TMyRegObject *)Node->ChildList->Items[i],MyRegObject,OBJL);
    Node->RecurrentLookingTo(MyRegObject,OBJL);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void TMyRegTree::RecurrentSave(TMyRegObject *Node,FILE *F) const
{
    if (Node->ServiceNode)
        return;
    CountProcess(Node->Name,1);
    fputs(AnsiString(typeid(*Node).name()).c_str(),F);
    fputs("\n",F);
    Node->SaveData(F);
    fputs(IntToStr(Node->SaveChildCount).c_str(),F);
    fputs("\n",F);
    for (int i=0;i<Node->ChildList->Count;i++)
    {
        RecurrentSave(((TMyRegObject *)Node->ChildList->Items[i]),F);
    }
}

void TMyRegTree::RecurrentLoad(TMyRegObject *Node,FILE *F)
{
    char str[256];
    AnsiString CT;
    int count;
    fgets(str,256,F);
    count = AnsiString(str).Trim().ToInt();
    for (int i=0;i<count;i++)
    {
        fgets(str,256,F);
        CT = AnsiString(str).Trim();
        TMyRegObject * NewMN = (TMyRegObject*)Create_Default_Constructor(CT);
        NewMN->MyTree = this;
        NewMN->LoadData(F);
        /*if ( NewMN->Table==0 )
        {
            if (!Parent)
                Parent = MGT->FindByID(0,99);
                if ( Parent && ( Node == Parent || Node->In(Parent) ) )
                {
                    int ADD = 1000;
                    while (MGT->FindByID(NewMN->Table,NewMN->ID+ADD))
                        ADD++;
                    NewMN->RegThis(NewMN->Table,NewMN->ID+ADD,MGT->ValidateName(NewMN->Table,NewMN->Name) );
                }
            else if (!NewMN->RegThis(NewMN->Table,NewMN->ID,NewMN->Name))
                    throw EMyException("Can not register class.");
        }
        else if (typeid(*NewMN) == typeid(TNomenclature))
        {
            if ( MGT->FindByID(NewMN->Table,NewMN->ID) ||
                MGT->FindByName(NewMN->Table,NewMN->Name) )
                NewMN->NewRegThis(NewMN->Table,NewMN->Name);
            else if (!NewMN->RegThis(NewMN->Table,NewMN->ID,NewMN->Name))
                    throw EMyException("Can not register class.");
        }
        else if (!NewMN->RegThis(NewMN->Table,NewMN->ID,NewMN->Name))
            throw EMyException("Can not register class.");  */
        AddChild(Node,NewMN);
        RecurrentLoad(NewMN,F);
    }
}

void TMyRegTree::SaveData(FILE *F) const
{
    TMyObject::SaveData(F);
    TMTList<TMyRegObject> MROL;
    SelectByCT(Head,TMyRegObject::StaticType,&MROL,true,true);
    StartProcess("Сохранение метаданных ...",MROL.Count);
    RecurrentSave(Head,F);
    //для того чтобы закрылся mdiconfig иначе процесс
    //PB->Visible = false;
}

void TMyRegTree::LoadData(FILE *F)
{
    TMyObject::LoadData(F);
    char str[256];
    AnsiString CT;
    fgets(str,256,F);
    CT = AnsiString(str).Trim();
    TMyRegObject* H=(TMyRegObject*)Create_Default_Constructor(CT);
    H->MyTree = this;
    H->LoadData(F);
    AddChild(NULL,H);
    RecurrentLoad(Head,F);
}

void TMyRegTree::RecurrentWrite(TMyRegObject *Node,TMemoryStream *MS) const
{
  AnsiString RW_CN;
  int RW_Count;
    if (Node->ServiceNode)
        return;
    RW_CN = AnsiString(typeid(*Node).name());
    WriteOne(&RW_CN,mtString,MS);
    Node->WriteData(MS);
    RW_Count = Node->SaveChildCount;
    WriteOne(&RW_Count,mtInt,MS);
    for (int i=0;i<Node->ChildList->Count;i++)
        RecurrentWrite(((TMyRegObject *)Node->ChildList->Items[i]),MS);
}

void TMyRegTree::RecurrentRead(TMyRegObject *Node,TMemoryStream *MS)
{
  AnsiString RW_CN;
  int RW_Count;
  if (ReadOne(&RW_Count,mtInt,MS)!=-1)
    throw EMyException("Can not read from stream");
  for (int i=0;i<RW_Count;i++)
    {
        if (ReadOne(&RW_CN,mtString,MS)!=-1)
            throw EMyException("Can not read from stream");
        TMyRegObject * NewMN = (TMyRegObject*)Create_Default_Constructor(RW_CN);
        NewMN->MyTree = this;
        NewMN->ReadData(MS);
        AddChild(Node,NewMN);
        RecurrentRead(NewMN,MS);
    }
}



void TMyRegTree::WriteData(TMemoryStream *MS) const
{
  TMyObject::WriteData(MS);
  RecurrentWrite(Head,MS);
}

void TMyRegTree::ReadData(TMemoryStream *MS)
{
  AnsiString RW_CN;
  TMyObject::ReadData(MS);
  if (ReadOne(&RW_CN,mtString,MS)!=-1)
      throw EMyException("Can not read from stream");
  TMyRegObject* H=(TMyRegObject*)Create_Default_Constructor(RW_CN);
  H->MyTree = this;
  H->ReadData(MS);
  AddChild(NULL,H);
  RecurrentRead(Head,MS);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool TMyRegTree::CheckData(TMyRegObject *Node)
{
    if (Node==NULL)
        return(CheckData(Head));
    for (int i=0;i<Node->ChildList->Count;i++)
        if ( CheckData( (TMyRegObject *)(Node->ChildList->Items[i]) )==false )
            return(false);
    return(Node->RecurrentCheck());
}

bool TMyRegTree::CheckFields()
{
    return CheckData(NULL);
}

void TMyRegTree::RecurrentFillTreeView(TMyRegObject *Node,TTreeView *TreeView)
{
    TTreeNode *TreeNode = (TTreeNode *)Node->Parent->TN;
    Node->TN=TreeView->Items->AddChild(TreeNode,Node->Name);
    Node->TN->Data=Node;
    Node->ImageIndex = Node->ImageIndex;

    for (int i=0;i<Node->ChildList->Count;i++)
    {
        RecurrentFillTreeView(((TMyRegObject *)Node->ChildList->Items[i]),TreeView);
    }
}

void TMyRegTree::FillTreeView(TTreeView *TreeView)
{
    TreeView->Items->Clear();
    Head->TN=TreeView->Items->Add(NULL,Head->Name);
    Head->TN->Data=Head;
    Head->ToTree();
    for (int i=0;i<Head->ChildList->Count;i++)
    {
        RecurrentFillTreeView(((TMyRegObject *)Head->ChildList->Items[i]),TreeView);
    }
}

void TMyRegTree::SelectByCT(TMyRegObject *Node,TClassNode* CN,TMTList<TMyRegObject> *List,bool self,bool Childs)const
{
    if (Node==NULL)
    {
        if (Head==NULL)
            return;
        SelectByCT(Head,CN,List, self, Childs);
        return;
    }
    if ( CN == Node->DynamicType && self)
        List->Add(Node);

    if ( Node->Is(CN) && (CN != Node->DynamicType) && Childs)
        List->Add(Node);

    for (int i=0;i<Node->ChildList->Count;i++)
        SelectByCT((TMyRegObject *)(Node->ChildList->Items[i]),CN,List,self, Childs);
}

