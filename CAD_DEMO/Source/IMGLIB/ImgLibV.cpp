//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ImgLibV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//ImageLibrary->ActionImages
//ImageLibrary->ilStandart
//ImageLibrary->ScrollImg
//ImageLibrary->TreeImages
//ImageLibrary->BlocksImageList
TImageLibrary *ImageLibrary = NULL;
//---------------------------------------------------------------------------
__fastcall TImageLibrary::TImageLibrary(TComponent* Owner)
    : TDataModule(Owner)
{
    ImageLibrary = this;     
}
//---------------------------------------------------------------------------
void __fastcall TImageLibrary::DataModuleDestroy(TObject *Sender)
{
    ImageLibrary = NULL;
}
//---------------------------------------------------------------------------
void RegisterImageLIbrary()
{
    ImageLibrary = new TImageLibrary(Application);
}
#pragma startup RegisterImageLIbrary 66

void UnRegisterImageLIbrary()
{
    delete ImageLibrary;
}
#pragma exit UnRegisterImageLIbrary 66
