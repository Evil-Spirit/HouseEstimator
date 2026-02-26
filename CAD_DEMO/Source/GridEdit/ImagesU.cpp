// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "compat/vcl_qt.h"

#include "ImagesU.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TCGIL *CGIL = NULL;
//---------------------------------------------------------------------------
 TCGIL::TCGIL(TComponent* Owner)
    : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void RegisterImages()
{
    new TCGIL( Application );
}

#pragma startup RegisterImages

void  TCGIL::DataModuleDestroy(TObject *Sender)
{
    CGIL = NULL;
}
//---------------------------------------------------------------------------

void  TCGIL::DataModuleCreate(TObject *Sender)
{
    if (CGIL)
        throw EMyException("<TCGIL::DataModuleCreate>: CGIL óæå ñîçäàí.");
    CGIL = this;
}
//---------------------------------------------------------------------------

