//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "CellGrid.h"
#include "OffsetCellU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOffsetCell *OffsetCell;
//---------------------------------------------------------------------------
__fastcall TOffsetCell::TOffsetCell(TComponent* Owner, TMGrid* _Grid)
    : TForm(Owner)
{
    Grid =_Grid;
}
//---------------------------------------------------------------------------
void __fastcall TOffsetCell::Button1Click(TObject *Sender)
{
    if (rbTopOffset->Checked )
        Grid->iOffsetCell =0;
    else
        Grid->iOffsetCell =1;

    Close();
}
//---------------------------------------------------------------------------
void __fastcall TOffsetCell::Button2Click(TObject *Sender)
{
    Grid->iOffsetCell =-1;
    Close();
}
//---------------------------------------------------------------------------


