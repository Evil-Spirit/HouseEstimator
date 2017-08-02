//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include <vcl.h>
#pragma hdrstop

#include "TreeViewF.h"
#include "MyDialogEditU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TObjectTreeView *TreeView = NULL;
enum {tvForm = 0, tvParentControl = 1, tvNonParentControl = 2};
//---------------------------------------------------------------------------
__fastcall TObjectTreeView::TObjectTreeView(TComponent* Owner) : TForm(Owner)
{
        TreeView = this;
        Selected = new TList;
        Selected->Clear();
        SelectChange = false;
        Show();
}

//---------------------------------------------------------------------------
void __fastcall TObjectTreeView::deUpButtonClick(TObject *Sender)
{
        //
}

//---------------------------------------------------------------------------
void __fastcall TObjectTreeView::deDownButtonClick(TObject *Sender)
{
        //
}

//---------------------------------------------------------------------------
void __fastcall TObjectTreeView::deDeleteButtonClick(TObject *Sender)
{
        if (deTreeView->Selected->AbsoluteIndex)
        {
                DeleteObject(deTreeView->Selected->Text);
                deTreeView->Selected->Delete();
        }
}

//---------------------------------------------------------------------------
void __fastcall TObjectTreeView::deAddButtonClick(TObject *Sender)
{
        //
}

//---------------------------------------------------------------------------
int TObjectTreeView::FindByName(AnsiString Name)
{
        int i;
        int Index;
        for (i = 0; i < deTreeView->Items->Count; i++)
                if (deTreeView->Items->Item[i]->Text == Name)
                {
                        Index = i;
                        break;
                }
        return Index;
}

//---------------------------------------------------------------------------
void TObjectTreeView::CreateTreeRecursion(TVCLEditorElement *_Node, TTreeNode *Root, int &Index)
{
        int i;
        for ( i = 0; i < _Node->VCLChildCount; i++ )
        {
                Index++;
                deTreeView->Items->AddChild(Root, _Node->VCLChild[i]->Component->Name);
                if (_Node->VCLChild[i]->CanHaveChild())
                        deTreeView->Items->Item[Index]->ImageIndex = tvParentControl;
                else
                        deTreeView->Items->Item[Index]->ImageIndex = tvNonParentControl;
                CreateTreeRecursion(_Node->VCLChild[i],deTreeView->Items->Item[Index], Index);
        }
}

//---------------------------------------------------------------------------
void TObjectTreeView::CreateTree(TVCLEditorElement *_Node)
{
        int i;
        int Index;
        deTreeView->Items->Clear();
        deTreeView->Items->Add(NULL, _Node->Component->Name);
        deTreeView->Items->Item[0]->ImageIndex = tvForm;
        if (_Node->VCLChildCount)
                deDeleteButton->Enabled = true;
        Index = 1;
        deTreeView->ReadOnly = true;
        for ( i = 0; i < _Node->VCLChildCount; i++ )
        {
                deTreeView->Items->AddChild(deTreeView->Items->Item[0], _Node->VCLChild[i]->Component->Name);
                if (_Node->VCLChild[i]->CanHaveChild())
                        deTreeView->Items->Item[Index]->ImageIndex = tvParentControl;
                else
                        deTreeView->Items->Item[Index]->ImageIndex = tvNonParentControl;
                CreateTreeRecursion(_Node->VCLChild[i], deTreeView->Items->Item[Index], Index);
        }
}

//---------------------------------------------------------------------------
void __fastcall TObjectTreeView::deTreeViewChange(TObject *Sender, TTreeNode *Node)
{
        if (!Node->AbsoluteIndex)
                deDeleteButton->Enabled = false;
        else
                deDeleteButton->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TObjectTreeView::deTreeViewKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
        int i;
        int Minimal = 0xFFFF;
        int Maximal;
        int Temporal;
        if (Key == VK_DELETE)
                deDeleteButtonClick(Sender);
        if (!Shift.Empty()) //and mbuttonpressed
        {
                TTreeNode *Node = deTreeView->GetNodeAt(deTreeView->ScreenToClient(Mouse->CursorPos).x, deTreeView->ScreenToClient(Mouse->CursorPos).y);
                if (Node)
                {
                        if (Shift.Contains(ssShift))
                        {
                                Maximal = Node->AbsoluteIndex;
                                for (i = 0; i < Selected->Count; i++)
                                        if ( ((TTreeNode*)Selected->Items[i])->AbsoluteIndex < Minimal)
                                                Minimal = ((TTreeNode*)Selected->Items[i])->AbsoluteIndex;
                                if (Minimal > Maximal)
                                {
                                        Temporal = Minimal;
                                        Minimal = Maximal;
                                        Maximal = Temporal;
                                }
                                Selected->Clear();
                                for (i = Minimal; i <= Maximal; i++)
                                        Selected->Add(deTreeView->Items->Item[i]);
                                if (Minimal != Maximal)
                                        SelectChange = true;
                        }
                        if (Shift.Contains(ssCtrl))
                        {
                                if (Selected->IndexOf(Node) != -1)
                                        Selected->Add(Node);
                                else
                                        Selected->Remove(Node);
                                SelectChange = true;
                        }
                }
        }
        if (SelectChange)
        {
                deTreeView->Select(Selected);
                SelectChange = false;
        }
}

//---------------------------------------------------------------------------
TVCLEditorElement* TObjectTreeView::GetVCLEdEl(AnsiString Name, TVCLEditorElement* Head)
{
        int i;
        TVCLEditorElement* Result = NULL;
        if (Head->Component->Name == Name)
                Result = Head;
        else
        {
                for (i = 0; i < Head->VCLChildCount; i++)
                        if (GetVCLEdEl(Name, Head->VCLChild[i]))
                        {
                                Result = GetVCLEdEl(Name, Head->VCLChild[i]);
                                break;
                        }
        }
        return Result;
}

//---------------------------------------------------------------------------
int TObjectTreeView::GetVCLEdEl(AnsiString Name)
{
        int i;
        int Index = -1;
        for (i = 0; i < DialogEdit->Selected.Count; i++)
                if ( DialogEdit->Selected[i].Component->Name == Name )
                {
                        Index = i;
                        break;
                }
        return Index;
}

//---------------------------------------------------------------------------
void TObjectTreeView::DeleteObject(TComponent *_Object)
{
        if (deTreeView->Items->Item[FindByName(_Object->Name)]->AbsoluteIndex)
        {
                deTreeView->Items->Delete(deTreeView->Items->Item[FindByName(_Object->Name)]);
                DeleteObject(_Object->Name);
        }
}

//---------------------------------------------------------------------------
void TObjectTreeView::DeleteObject(AnsiString Name)
{
        int Index;
//        if (deTreeView->Items->Item[FindByName(Name)]->AbsoluteIndex)
//                deTreeView->Items->Delete(deTreeView->Items->Item[FindByName(Name)]);
        Index = GetVCLEdEl(Name);
        if (Index != -1)
        {
                if(DialogEdit->Selected.Items[Index]->Component)
                        delete DialogEdit->Selected.Items[Index]->Component;
                if(DialogEdit->Selected.Items[Index]->Control)
                {
                    DialogEdit->Selected[Index].VCLParent->Control->Invalidate();
                    delete DialogEdit->Selected.Items[Index]->Control;
                }
                delete DialogEdit->Selected.Items[Index];
        }
}

//---------------------------------------------------------------------------
void TObjectTreeView::SelectObject(TComponent *_Object, bool Add)
{
        TShiftState Shift;
        Shift.Clear();
        if ( Add )
            Shift>>(ssShift);
        deTreeView->Select(deTreeView->Items->Item[FindByName(_Object->Name)], Shift);
        //is it RIGHT???
}

//---------------------------------------------------------------------------
void TObjectTreeView::SelectObject(AnsiString Name)
{
        //First - clear SelectList
        DialogEdit->Selected.Add(GetVCLEdEl(Name, DialogEdit->Head));
}

//---------------------------------------------------------------------------
void TObjectTreeView::NewParent(AnsiString ChildName, AnsiString ParentName)
{
        if ((FindByName(ChildName)) && (GetVCLEdEl(ParentName, DialogEdit->Head)->CanHaveChild()) )
        {
                deTreeView->Items->Add(deTreeView->Items->Item[FindByName(ParentName)], ChildName);
                if (GetVCLEdEl(ChildName, DialogEdit->Head)->CanHaveChild())
                        deTreeView->Items->Item[FindByName(ChildName)]->ImageIndex = tvParentControl;
                else
                        deTreeView->Items->Item[FindByName(ChildName)]->ImageIndex = tvNonParentControl;
                deTreeView->Items->Delete(deTreeView->Items->Item[FindByName(ChildName)]);
                GetVCLEdEl(ChildName, DialogEdit->Head)->VCLParent = GetVCLEdEl(ParentName, DialogEdit->Head);
                GetVCLEdEl(ChildName, DialogEdit->Head)->Control->Parent = GetVCLEdEl(ParentName, DialogEdit->Head)->Control;
        }
}

//---------------------------------------------------------------------------
