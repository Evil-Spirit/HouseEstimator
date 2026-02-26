// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"

#include "SectionIn1.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TSectionIn *SectionIn;
//---------------------------------------------------------------------------
 TSectionIn::TSectionIn(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
