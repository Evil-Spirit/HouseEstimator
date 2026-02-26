// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "compat/vcl_qt.h"

#include "SelectBorderU.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TSelectBorder *SelectBorder;
//---------------------------------------------------------------------------
 TSelectBorder::TSelectBorder(TComponent* Owner)
    : TForm(Owner)
{
    SelectBorderIndex =-1;
}
//---------------------------------------------------------------------------
void  TSelectBorder::FormDeactivate(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void  TSelectBorder::SetIndex(int Index)
{
    SelectBorderIndex =Index;
    Close();
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton1Click(TObject *Sender)
{
    SetIndex(1);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton2Click(TObject *Sender)
{
    SetIndex(2);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton4Click(TObject *Sender)
{
    SetIndex(3);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton5Click(TObject *Sender)
{
    SetIndex(4);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton6Click(TObject *Sender)
{
    SetIndex(5);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton7Click(TObject *Sender)
{
    SetIndex(6);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton8Click(TObject *Sender)
{
    SetIndex(7);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton9Click(TObject *Sender)
{
    SetIndex(8);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton10Click(TObject *Sender)
{
    SetIndex(9);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton11Click(TObject *Sender)
{
    SetIndex(10);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton12Click(TObject *Sender)
{
    SetIndex(11);
}
//---------------------------------------------------------------------------
void  TSelectBorder::ToolButton13Click(TObject *Sender)
{
    SetIndex(12);
}
//---------------------------------------------------------------------------
