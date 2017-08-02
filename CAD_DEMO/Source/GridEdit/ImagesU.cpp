//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include <vcl.h>
#pragma hdrstop

#include "ImagesU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCGIL *CGIL = NULL;
//---------------------------------------------------------------------------
__fastcall TCGIL::TCGIL(TComponent* Owner)
    : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void RegisterImages()
{
    new TCGIL( Application );
}

#pragma startup RegisterImages

void __fastcall TCGIL::DataModuleDestroy(TObject *Sender)
{
    CGIL = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TCGIL::DataModuleCreate(TObject *Sender)
{
    if (CGIL)
        throw EMyException("<TCGIL::DataModuleCreate>: CGIL уже создан.");
    CGIL = this;
}
//---------------------------------------------------------------------------

