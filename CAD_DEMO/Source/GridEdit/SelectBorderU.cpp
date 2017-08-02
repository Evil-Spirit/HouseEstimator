//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "SelectBorderU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSelectBorder *SelectBorder;
//---------------------------------------------------------------------------
__fastcall TSelectBorder::TSelectBorder(TComponent* Owner)
    : TForm(Owner)
{
    SelectBorderIndex =-1;
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::FormDeactivate(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::SetIndex(int Index)
{
    SelectBorderIndex =Index;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton1Click(TObject *Sender)
{
    SetIndex(1);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton2Click(TObject *Sender)
{
    SetIndex(2);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton4Click(TObject *Sender)
{
    SetIndex(3);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton5Click(TObject *Sender)
{
    SetIndex(4);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton6Click(TObject *Sender)
{
    SetIndex(5);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton7Click(TObject *Sender)
{
    SetIndex(6);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton8Click(TObject *Sender)
{
    SetIndex(7);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton9Click(TObject *Sender)
{
    SetIndex(8);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton10Click(TObject *Sender)
{
    SetIndex(9);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton11Click(TObject *Sender)
{
    SetIndex(10);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton12Click(TObject *Sender)
{
    SetIndex(11);
}
//---------------------------------------------------------------------------
void __fastcall TSelectBorder::ToolButton13Click(TObject *Sender)
{
    SetIndex(12);
}
//---------------------------------------------------------------------------
