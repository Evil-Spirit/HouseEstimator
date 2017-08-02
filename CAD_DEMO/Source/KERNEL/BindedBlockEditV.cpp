//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "BindedBlockEditV.h"
#include "BindedGoEditV.h"
#include "MainToolsV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBindedBlockEdit *BindedBlockEdit;
//---------------------------------------------------------------------------
__fastcall TBindedBlockEdit::TBindedBlockEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
//    TBindedStateBlock* BST = (TBindedStateBlock*)_Obj;
//    Parent = (TWinControl*)Owner;
}

void TBindedBlockEdit::SETUP()
{
    if ( FObj->DynamicType->is( TBindedStateBlock::StaticType ) )
         FBlockType = 0;
    else
        if ( FObj->DynamicType->is( TBindedActionBlock::StaticType ) )
             FBlockType = 1;
        else
            if ( FObj->DynamicType->is( TBindedConditionalBlock::StaticType ) )
                 FBlockType = 2;
            else
                throw EMyException("The type of TBindedBaseBlock is incorrect");
    for ( int i = 0; i < 6; i++)
        cbExEvent->Items->Add(CharEvent[i]);
    if (FBlockType == 1 || FBlockType == 2)
    {
        cbExEvent->Enabled = false;
        tbNew->Enabled = false;
        tbDelete->Enabled = false;
        cbExEvent->Visible = false;
        tbNew->Visible = false;
        tbDelete->Visible = false;
        lExecutedEvent->Visible = false;
    }
    if ( !FObj->MyObjectParent->Is(TMDelTList<TBaseBlock>::StaticType) )
        throw EMyException("The type of Parent is incorrect.");
    if ( !FObj->MyObjectParent->MyObjectParent->Is(TBindedBaseTool::StaticType) )
        throw EMyException("The type of Parent is incorrect.");
    BT = (TBindedBaseTool*)FObj->MyObjectParent->MyObjectParent;
    BlocksCount = 0;
    FBlocksNames = new TMDelTList<AnsiString>;
    FBlocksIds = new TMDelTList<int>;
    for ( int i = 0; i < BT->BlocksCount(); i++ )
        if (BT->GetBlock(i) != FObj)
        {
            FBlocksNames->Add(new AnsiString(BT->GetBlockName(i)));
            FBlocksIds->Add(new int(BT->GetBlock(i)->Id));
            BlocksCount++;
        }
    TListColumn* LC = lvNextBlock->Columns->Add();
    LC->Caption = "NextBlock";
    Size0 = 200;
    if (FBlockType == 0)
    {
        LC = lvNextBlock->Columns->Add();
        LC->Caption = "Event";
        LC = lvNextBlock->Columns->Add();
        LC->Caption = "ReVision";

        Size0 = 66;
//        lvNextBlock->Columns->Items[1]->Width = 66;
//        lvNextBlock->Columns->Items[2]->Width = 66;
    }
    if (FBlockType == 2)
    {
        LC = lvNextBlock->Columns->Add();
        LC->Caption = "Type";
        Size0 = 100;
//        lvNextBlock->Columns->Items[1]->Width = 100;
    }
    NameChanged = false;
    FMyBaseBlock = new TBaseBlock;
    EditLuaModule();
    lvNextBlockResize( NULL );
//    lvNextBlock->ItemIndex = 0;
}

TBaseBlock* TBindedBlockEdit::GetFObj()
{
    return (TBaseBlock*)Obj;
}

TMDelTList<AnsiString>& TBindedBlockEdit::GetBlocksNames()
{
    return *FBlocksNames;
}

/*void TBindedBlockEdit::SetBlocksNames(TMDelTList<AnsiString> MDTL)
{
    FBlocksNames = &MDTL;
}*/

TMDelTList<int>& TBindedBlockEdit::GetBlocksIds()
{
    return *FBlocksIds;
}

/*void TBindedBlockEdit::SetBlocksIds(TMDelTList<int> MDTL)
{
    FBlocksIds = &MDTL;
}*/

void TBindedBlockEdit::KILL()
{
    delete FBlocksNames;
    delete FBlocksIds;
    delete FMyBaseBlock; 
}

/*__fastcall TBindedBlockEdit::TBindedBlockEdit(TComponent* Owner, TBaseBlock* Obj)
    : TForm(Owner)
{
    Parent = (TWinControl*)Owner;
    Top = 0;
    Left = 0;
    FObj = Obj;
    if ( FObj->DynamicType->is( TBindedStateBlock::StaticType ) )
         FBlockType = 0;
    else
        if ( FObj->DynamicType->is( TBindedActionBlock::StaticType ) )
             FBlockType = 1;
        else
            if ( FObj->DynamicType->is( TBindedConditionalBlock::StaticType ) )
                 FBlockType = 2;
    for ( int i = 0; i < 6; i++)
        cbExEvent->Items->Add(CharEvent[i]);
    if (FBlockType == 1 || FBlockType == 2)
    {
        cbExEvent->Enabled = false;
        tbNew->Enabled = false;
        tbDelete->Enabled = false;
        cbExEvent->Visible = false;
        tbNew->Visible = false;
        tbDelete->Visible = false;
        lExecutedEvent->Visible = false;
    }
    if ( !FObj->MyObjectParent->Is(TMDelTList<TBaseBlock>::StaticType) )
        throw EMyException("The type of Parent is incorrect.");
    if ( !FObj->MyObjectParent->MyObjectParent->Is(TBindedBaseTool::StaticType) )
        throw EMyException("The type of Parent is incorrect.");
    BT = (TBindedBaseTool*)FObj->MyObjectParent->MyObjectParent;
    for ( int i = 0; i < BT->BlocksCount(); i++ )
        if (BT->GetBlock(i) != FObj)
        {
            BlocksNames.Add(new AnsiString(BT->GetBlockName(i)));
            BlocksIds.Add(new int(BT->GetBlock(i)->Id));
        }
    TListColumn* LC = lvNextBlock->Columns->Add();
    LC->Caption = "NextBlock";
    Size0 = 200;
    if (FBlockType == 0)
    {
        LC = lvNextBlock->Columns->Add();
        LC->Caption = "Event";
        LC = lvNextBlock->Columns->Add();
        LC->Caption = "ReVision";

        Size0 = 66;
        lvNextBlock->Columns->Items[1]->Width = 66;
        lvNextBlock->Columns->Items[2]->Width = 66;
    }
    if (FBlockType == 2)
    {
        LC = lvNextBlock->Columns->Add();
        LC->Caption = "Type";
        Size0 = 100;
        lvNextBlock->Columns->Items[1]->Width = 100;
    }
    NameChanged = false;
//    lvNextBlock->ItemIndex = 0;
}*/

void TBindedBlockEdit::FillForm()
{
    lvNextBlock->Clear();
    BT = (TBindedBaseTool*)FObj->MyObjectParent->MyObjectParent;
    for (int i = 0; i < MyBaseBlock.GOS.Count; i++)
    {
        TListItem* LI = lvNextBlock->Items->Add();
        int j;
        for ( j = 0; j < BlocksCount; j++ )
            if ( BlocksIds[j] == MyBaseBlock.GOS[i].NextBlockId )
            {
                LI->Caption = BlocksNames[j];
                break;
            }
        if ( BlocksCount == 0 || j == BlocksCount )
            LI->ImageIndex = 0;
        else
            if ( BlocksIds[j] == -1 )
                LI->ImageIndex = 0;
            else
                if  ( BT->GetBlockFromId(BlocksIds[j])->Is(TStateBlock::StaticType) )
                    LI->ImageIndex = 1;
                else
                    if  ( BT->GetBlockFromId(BlocksIds[j])->Is(TActionBlock::StaticType) )
                        LI->ImageIndex = 2;
                    else
                        if  ( BT->GetBlockFromId(BlocksIds[j])->Is(TConditionalBlock::StaticType) )
                            LI->ImageIndex = 3;
        if (j == BlocksCount)
        {
            LI->Caption = "None";
            /* TODO : выделить цветом *///LI->
        }
        if (FBlockType==0)
        {
            LI->SubItems->Add(AnsiString(CharEvent[MyBaseBlock.GOS[i].Event]));
            if (MyBaseBlock.GOS[i].Event < 3)
            {
                if (MyBaseBlock.GOS[i].MouseButton == mbLeft)
                    LI->SubItems->Add("mbLeft");
                else
                    if (MyBaseBlock.GOS[i].MouseButton == mbRight)
                        LI->SubItems->Add("mbRight");
                    else
                        if (MyBaseBlock.GOS[i].MouseButton == mbMiddle)
                            LI->SubItems->Add("mbMiddle");
            }else
                if (MyBaseBlock.GOS[i].Event != 5)
                    LI->SubItems->Add(TBindedBaseTool().KeyToStr(MyBaseBlock.GOS[i].Key));
        }else
            if (i)
                LI->SubItems->Add(AnsiString("False"));
            else
                LI->SubItems->Add(AnsiString("True"));
    }
//  lvNextBlock->Columns->Items[0]->Width = Size0;
}

bool TBindedBlockEdit::Checked()
{
    for (int i = 0; i < MyBaseBlock.GOS.Count; i++)
    {
        int j;
        for ( j = 0; j < BlocksCount; j++ )
            if ( BlocksIds[j] == MyBaseBlock.GOS[i].NextBlockId )
                break;
        if ( j == BlocksCount)
            return false;
    }
    /* TODO : заполнить */
    return true;
}

void TBindedBlockEdit::Apply()
{
    bool notCorrect = false;

    while ( eName->Text.Length()>0 && eName->Text[1] >= '0' && eName->Text[1] <= '9')
    {
        eName->Text = eName->Text.Delete(1, 1);
        notCorrect = true;
    }

    for ( int i = 1; i <= eName->Text.Length(); i++ )
        if ( (eName->Text[i] < 'a' || eName->Text[i] > 'z') &&
             (eName->Text[i] < '0' || eName->Text[i] > '9') &&
              eName->Text[i] != '_')
        {
            eName->Text = eName->Text.Delete(i, 1);
            notCorrect = true;
        }

    if ( eName->Text.Length() == 0 )
    {
        eName->Text = "Block"+IntToStr(FObj->Id);
        notCorrect = true;
    }

    for ( int i = 0; i < BlocksCount; i++)
        if ( eName->Text == BlocksNames[i] )
        {
            eName->Text += IntToStr(FObj->Id);
            break;
        }

    if (notCorrect)
            ErrorMsg("The name of the block has been fixed!");

    if ( FObj->Name != eName->Text )
        NameChanged = true;
    FObj->SetName(eName->Text);
    if (FBlockType == 0)
        ((TBindedStateBlock*)FObj)->ExecutedEvent = cbExEvent->ItemIndex;
    FObj->GOS.Assign(&MyBaseBlock.GOS);
    TMDIObjectEdit* ME = (TMDIObjectEdit*)pLuaModuleEdit->Controls[0];
    ME->Apply();
    FObj->LuaModule.Assign(&MyBaseBlock.LuaModule);
}

TBaseBlock& TBindedBlockEdit::GetMyBaseBlock()
{
    return *FMyBaseBlock;
}

void TBindedBlockEdit::Refresh()
{
    eName->Text = FObj->Name;
    if (FBlockType == 0)
        cbExEvent->ItemIndex = ((TBindedStateBlock*)FObj)->ExecutedEvent;
    MyBaseBlock.GOS.Assign(&FObj->GOS);
    MyBaseBlock.LuaModule.Assign(&FObj->LuaModule);
    TMDIObjectEdit* ME = (TMDIObjectEdit*)pLuaModuleEdit->Controls[0];
    ME->Refresh();
    FillForm();
}
//---------------------------------------------------------------------------

void __fastcall TBindedBlockEdit::tbNewClick(TObject *Sender)
{
    MyBaseBlock.GOS.Add(new TGo());
    MyBaseBlock.GOS.Last()->Event = Mouse_Down;
    MyBaseBlock.GOS.Last()->MouseButton = mbLeft;
    MyBaseBlock.GOS.Last()->Key = VK_CONTROL;
    MyBaseBlock.GOS.Last()->NextBlockId = -1;
    BindedGoEdit = new TBindedGoEdit(this, MyBaseBlock.GOS.Last(), BlocksNames, BlocksIds, FBlockType);
    BindedGoEdit->Refresh();
    BindedGoEdit->ShowModal();
    if (BindedGoEdit->flag == 1)
    {
        MyBaseBlock.GOS.Delete(MyBaseBlock.GOS.Count-1);
        return;
    }
    BindedGoEdit->Apply();
    FillForm();
}
//---------------------------------------------------------------------------



void __fastcall TBindedBlockEdit::tbEditClick(TObject *Sender)
{
    if (lvNextBlock->ItemIndex < 0 || lvNextBlock->ItemIndex>=lvNextBlock->Items->Count)
        return;
    BindedGoEdit = new TBindedGoEdit(this, &MyBaseBlock.GOS[lvNextBlock->ItemIndex], BlocksNames, BlocksIds, FBlockType);
    BindedGoEdit->Refresh();
    BindedGoEdit->ShowModal();
    if (BindedGoEdit->flag == 1)
        return;
    BindedGoEdit->Apply();
    FillForm();
}
//---------------------------------------------------------------------------

void __fastcall TBindedBlockEdit::tbDeleteClick(TObject *Sender)
{
    if (lvNextBlock->ItemIndex < 0 || lvNextBlock->ItemIndex >= lvNextBlock->Items->Count)
        return;
    MyBaseBlock.GOS.Delete(lvNextBlock->ItemIndex);
    FillForm();
}
//---------------------------------------------------------------------------

void __fastcall TBindedBlockEdit::FormDestroy(TObject *Sender)
{
    BlocksNames.Clear();
    BlocksIds.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TBindedBlockEdit::lvNextBlockDblClick(TObject *Sender)
{
    tbEditClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TBindedBlockEdit::eNameChange(TObject *Sender)
{
    eName->Text = eName->Text.Trim();
    eName->Text = eName->Text.LowerCase();
}
//---------------------------------------------------------------------------
void __fastcall TBindedBlockEdit::lvNextBlockResize(TObject *Sender)
{
    for ( int i = 0; i < lvNextBlock->Columns->Count; i++ )
        lvNextBlock->Columns->Items[i]->Width = lvNextBlock->ClientWidth / lvNextBlock->Columns->Count;
}

void TBindedBlockEdit::EditLuaModule()
{
//    FObj->LuaModule.Edit(this, pLuaModuleEdit, NULL);
    MyBaseBlock.LuaModule.Edit(this, pLuaModuleEdit, NULL);
}
//---------------------------------------------------------------------------


