//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "BindedBaseToolEditV.h"
#include "BindedBlockEditV.h"
//#include "BaseToolV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBindedBaseToolEdit *BindedBaseToolEdit;
//---------------------------------------------------------------------------
__fastcall TBindedBaseToolEdit::TBindedBaseToolEdit(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------

bool TBindedBaseToolEdit::Checked()
{
    for ( int i = 0; i < MyTool.BlocksCount(); i++ )
        for ( int j = 0; j < MyTool.GetBlock(i)->GOS.Count; j++ )
            if ( !MyTool.CheckId(MyTool.GetBlock(i)->GOS[j].NextBlockId) )
                return false;
    return true;
}

void TBindedBaseToolEdit::Apply()
{
    if (pBlocks->ControlCount > 0)
    {
        TBindedBlockEdit* BBE = (TBindedBlockEdit*)pBlocks->Controls[0];
        BBE->Apply();
    }
    FObj->Assign(&MyTool);
}

void TBindedBaseToolEdit::FillForm()
{
    lvBlocks->Clear();
    for (int i = 0; i < MyTool.BlocksCount(); i++)
    {
        TListItem* LI = lvBlocks->Items->Add();
        LI->ImageIndex = (MyTool.GetBlock(i)->Id+1);
        LI->Caption = MyTool.GetBlock(i)->Name;
        if  ( MyTool.GetBlock(i)->Is(TStateBlock::StaticType) )
            LI->ImageIndex = 1;
        else
            if  ( MyTool.GetBlock(i)->Is(TActionBlock::StaticType) )
                LI->ImageIndex = 2;
            else
                if  ( MyTool.GetBlock(i)->Is(TConditionalBlock::StaticType) )
                    LI->ImageIndex = 3;
        if (MyTool.GetBlock(i)->Id == -1)
            LI->ImageIndex = 0;
    }
    lvBlocks->Columns->Items[0]->Width = 83;
    lvBlocks->Columns->Items[0]->Width = lvBlocks->ClientWidth;
}

void TBindedBaseToolEdit::SETUP()
{
    FMyTool = new TBindedBaseTool;
    lvBlocksResize( NULL );
}

void TBindedBaseToolEdit::KILL()
{
    delete FMyTool;
}

TBindedBaseTool& TBindedBaseToolEdit::GetMyTool()
{
    return *FMyTool;
}

/*void TBindedBaseToolEdit::SetMyTool(TBindedBaseTool _BBT)
{
    FMyTool = &_BBT;
}*/

void TBindedBaseToolEdit::Refresh()
{
    MyTool.Assign(FObj);
    FillForm();
}

void TBindedBaseToolEdit::GenerateImage( int _Id, int BlockType )
{
/*    Graphics::TBitmap* Image = new Graphics::TBitmap();
    Image->Width = 24;
    Image->Height = 24;
    Image->Canvas->Pen->Style = psDash;
    if ( BlockType == 0 )
        Image->Canvas->Rectangle(0, 0, 23, 23);
    else
        if ( BlockType == 1 )
            Image->Canvas->Rectangle(0, 0, 15, 15);
        else
            Image->Canvas->Rectangle(0, 0, 8, 8);

    if ( _Id >= 10 )
        Image->Canvas->TextOutA(2,2,IntToStr(_Id));
    else
        Image->Canvas->TextOutA(2,2,"0"+IntToStr(_Id));
    BlocksImageList->Width = 24;
    BlocksImageList->Height = 24;
    BlocksImageList->Add(Image, NULL);*/
}

void __fastcall TBindedBaseToolEdit::spmStateBlockClick(TObject *Sender)
{
    ApplyAndDestroyBlock();
    MyTool.AddStateBlock(Mouse_Move);
    EditBlock();
    FillForm();
    lvBlocks->ItemIndex = lvBlocks->Items->Count-1;
}
//---------------------------------------------------------------------------

void __fastcall TBindedBaseToolEdit::spmActionBlockClick(TObject *Sender)
{
    ApplyAndDestroyBlock();
    MyTool.AddActionBlock();
    EditBlock();
    FillForm();
    lvBlocks->ItemIndex = lvBlocks->Items->Count-1;
}
//---------------------------------------------------------------------------

void __fastcall TBindedBaseToolEdit::spmConditionalBlockClick(
      TObject *Sender)
{
    ApplyAndDestroyBlock();
    MyTool.AddConditionalBlock();
    EditBlock();
    FillForm();
    lvBlocks->ItemIndex = lvBlocks->Items->Count-1;
}
//---------------------------------------------------------------------------
void TBindedBaseToolEdit::ApplyAndDestroyBlock()
{
    if (lvBlocks->ItemIndex < 0 || lvBlocks->ItemIndex >= lvBlocks->Items->Count)
        return;
    bool buff = false;
    if ( pBlocks->ControlCount > 0 && pBlocks->Controls[0] != NULL )
    {
        TBindedBlockEdit* BBE = (TBindedBlockEdit*)pBlocks->Controls[0];
        BBE->Apply();
        buff = BBE->NameChanged;
        delete BBE;
    }
    if ( buff )
        FillForm();
}

void TBindedBaseToolEdit::EditBlock()
{
    if (lvBlocks->ItemIndex < 0 || lvBlocks->ItemIndex >= lvBlocks->Items->Count)
        return;
    MyTool.GetBlock(lvBlocks->ItemIndex)->Edit(this, pBlocks, NULL);
}

void __fastcall TBindedBaseToolEdit::lvBlocksSelectItem(TObject *Sender,
      TListItem *Item, bool Selected)
{
    ApplyAndDestroyBlock();
    EditBlock();
}
//---------------------------------------------------------------------------


void __fastcall TBindedBaseToolEdit::tbDeleteClick(TObject *Sender)
{
    if (lvBlocks->ItemIndex < 0 || lvBlocks->ItemIndex >= lvBlocks->Items->Count || lvBlocks->Items->Count < 1 )
        return;
    TListItem* LI = lvBlocks->Items->Item[lvBlocks->ItemIndex];
    int DBId = MyTool.GetBlockIdFromName(LI->Caption);
    if ( DBId == IdEscAction)
        return;
    if ( pBlocks->ControlCount > 0 && pBlocks->Controls[0] != NULL )
    {
        TBindedBlockEdit* BBE = (TBindedBlockEdit*)pBlocks->Controls[0];
        delete BBE;
    }
//    if ( lvBlocks->ItemIndex == lvBlocks->Items->Count-1 )
//        BlocksImageList->Delete(lvBlocks->ItemIndex-1);
    MyTool.DeleteBlock(MyTool.GetBlockIdFromName(LI->Caption));
    for ( int i = 0; i < MyTool.BlocksCount(); i++ )
        for ( int j = 0; j <  MyTool.GetBlock(i)->GOS.Count; j++ )
            if ( MyTool.GetBlock(i)->GOS[j].NextBlockId == DBId )
                MyTool.GetBlock(i)->GOS[j].NextBlockId = IdEscAction;
    FillForm();
    if (lvBlocks->ItemIndex < 0 || lvBlocks->ItemIndex >= lvBlocks->Items->Count || lvBlocks->Items->Count < 1 )
        return;
    MyTool.GetBlock(lvBlocks->ItemIndex)->Edit(this, pBlocks, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TBindedBaseToolEdit::lvBlocksResize(TObject *Sender)
{
    lvBlocks->Columns->Items[0]->Width = lvBlocks->ClientWidth;
}
//---------------------------------------------------------------------------

void __fastcall TBindedBaseToolEdit::Button1Click(TObject *Sender)
{
//    ApplyAndDestroyBlock();
    //TRenderLuaModuleEdit* RenderLuaModuleEdit = new TRenderLuaModuleEdit(this);

    MyTool.RenderLuaModule.Edit(this, NULL, NULL);
    /*
    TMDIObjectEdit* ME = (TMDIObjectEdit*)RenderLuaModuleEdit->pRenderEdit->Controls[0];
    ME->Refresh();
    RenderLuaModuleEdit->ShowModal();
    ME->Apply();
    delete RenderLuaModuleEdit;*/
}
//---------------------------------------------------------------------------

void __fastcall TBindedBaseToolEdit::pmBlocksTypesPopup(TObject *Sender)
{
    pmBlocksTypes->Images = lvBlocks->SmallImages;        
}
//---------------------------------------------------------------------------

