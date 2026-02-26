// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include "compat/vcl_qt.h"

#include "CellGrid.h"
#include "OffsetCellU.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TOffsetCell *OffsetCell;
//---------------------------------------------------------------------------
 TOffsetCell::TOffsetCell(TComponent* Owner, TMGrid* _Grid)
    : TForm(Owner)
{
    Grid =_Grid;
}
//---------------------------------------------------------------------------
void  TOffsetCell::Button1Click(TObject *Sender)
{
    if (rbTopOffset->Checked )
        Grid->iOffsetCell =0;
    else
        Grid->iOffsetCell =1;

    Close();
}
//---------------------------------------------------------------------------
void  TOffsetCell::Button2Click(TObject *Sender)
{
    Grid->iOffsetCell =-1;
    Close();
}
//---------------------------------------------------------------------------


