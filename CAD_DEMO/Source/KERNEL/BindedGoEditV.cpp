//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "BindedGoEditV.h"
#include "BaseToolV.h"
#include "MainToolsV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBindedGoEdit *BindedGoEdit;
//---------------------------------------------------------------------------
__fastcall TBindedGoEdit::TBindedGoEdit(TComponent* Owner, TGo* Obj, const TMDelTList<AnsiString>& BlocksNames, TMDelTList<int>& BlocksIds, int BlockType)
    : TForm(Owner)
{
    for (int i = 0; i < BlocksNames.Count; i++)
        cbNextBlock->Items->Add(BlocksNames[i]);
    if ( BlocksNames.Count > 0 )
        cbNextBlock->ItemIndex = 0;

    for ( int i = 0; i < 6; i++)
        cbEvent->Items->Add(CharEvent[i]);

    cbMouseButton->Items->Add("mbLeft");
    cbMouseButton->Items->Add("mbRight");
    cbMouseButton->Items->Add("mbMiddle");

    MyBlocksIds.Assign(&BlocksIds);
    FObj = Obj;
    flag = -1;
    if (BlockType == 1 || BlockType == 2)
    {
        cbMouseButton->Visible = false;
        cbEvent->Visible = false;
        eKey->Visible = false;
        lMouseButton->Visible = false;
        lEvent->Visible = false;
        lKey->Visible = false;
        bOk->Top = 40;
        bCancel->Top = 40;
        Height = 98;
    }
    FBlockType = BlockType;
    eKey->Tag = (WORD)VK_CONTROL;

    Left = Screen->Width / 2 - 110;
    Top = Screen->Height / 2 - 83;
}
//---------------------------------------------------------------------------

void __fastcall TBindedGoEdit::eKeyKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    eKey->Text = "";
    eKey->Tag = (int)Key;
    AnsiString A = TBindedBaseTool().KeyToStr(Key);
    if ( A.Length() > 3 )
        eKey->Text = A;
}

bool TBindedGoEdit::Checked()
{
    return true;
}

void TBindedGoEdit::Apply()
{
    if (cbEvent->ItemIndex >= 0 && cbEvent->ItemIndex < cbEvent->Items->Count)
        FObj->Event = cbEvent->ItemIndex;
    if (cbMouseButton->ItemIndex == 0)
        FObj->MouseButton = mbLeft;
    if (cbMouseButton->ItemIndex == 1)
        FObj->MouseButton = mbRight;
    if (cbMouseButton->ItemIndex == 2)
        FObj->MouseButton = mbMiddle;
    FObj->Key = (WORD)eKey->Tag;
    if (MyBlocksIds.Count > 0 && cbNextBlock->ItemIndex >= 0 && cbNextBlock->ItemIndex < cbNextBlock->Items->Count)
        FObj->NextBlockId = MyBlocksIds[cbNextBlock->ItemIndex];
}

void TBindedGoEdit::Refresh()
{
    cbEvent->ItemIndex = FObj->Event;
    eKey->Text = "";
    eKey->Text = TBindedBaseTool().KeyToStr(FObj->Key);
    eKey->Tag = (int)FObj->Key;
    if (FObj->MouseButton == mbLeft)
        cbMouseButton->ItemIndex = 0;
    if (FObj->MouseButton == mbRight)
        cbMouseButton->ItemIndex = 1;
    if (FObj->MouseButton == mbMiddle)
        cbMouseButton->ItemIndex = 2;
    for ( int i = 0; i < MyBlocksIds.Count; i++)
        if (MyBlocksIds[i] == FObj->NextBlockId)
        {
            cbNextBlock->ItemIndex = i;
            break;
        }
    cbEventChange(NULL);
/*    if (MyBlocksIds.Count > 0)
        cbNextBlock->ItemIndex = MyBlocksIds.IndexOf((const int*)&FObj->NextBlockId);*/
}
//---------------------------------------------------------------------------


void __fastcall TBindedGoEdit::bOkClick(TObject *Sender)
{
//    Apply(FObj);
    flag = 0;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TBindedGoEdit::bCancelClick(TObject *Sender)
{
    flag = 1;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TBindedGoEdit::cbEventChange(TObject *Sender)
{
    if ( FBlockType == 0 )
        if (cbEvent->ItemIndex < 3)
        {
            cbMouseButton->Visible = true;
            eKey->Visible = false;
            lMouseButton->Visible = true;
            lKey->Visible = false;
            bOk->Top = 104;
            bCancel->Top = 104;
            Height = 162;
        }else
            if ( cbEvent->ItemIndex == 5 )
            {
                cbMouseButton->Visible = false;
                eKey->Visible = false;
                lMouseButton->Visible = false;
                lKey->Visible = false;
                bOk->Top = 72;
                bCancel->Top = 72;
                Height = 130;
            }
            else
            {
                cbMouseButton->Visible = false;
                eKey->Visible = true;
                lMouseButton->Visible = false;
                lKey->Visible = true;
                bOk->Top = 104;
                bCancel->Top = 104;
                Height = 162;
            }
}
//---------------------------------------------------------------------------
void __fastcall TBindedGoEdit::eKeyChange(TObject *Sender)
{
    eKey->Text = eKey->Text.UpperCase();
    if ( eKey->Text.Length()>4 && eKey->Text[2] == 'V' && eKey->Text[3] == 'K' && eKey->Text[4] == '_' )
        eKey->Text = eKey->Text.Delete(1,1);
}
//---------------------------------------------------------------------------

