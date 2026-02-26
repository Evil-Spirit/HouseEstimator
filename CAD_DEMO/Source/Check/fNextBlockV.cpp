// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"

#include "fNextBlockV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TfNextBlock *fNextBlock;
//---------------------------------------------------------------------------
 TfNextBlock::TfNextBlock(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
