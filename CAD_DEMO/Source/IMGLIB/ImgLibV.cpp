// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"

#include "ImgLibV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//ImageLibrary->ActionImages
//ImageLibrary->ilStandart
//ImageLibrary->ScrollImg
//ImageLibrary->TreeImages
//ImageLibrary->BlocksImageList
TImageLibrary *ImageLibrary = NULL;
//---------------------------------------------------------------------------
 TImageLibrary::TImageLibrary(TComponent* Owner)
    : TDataModule(Owner)
{
    ImageLibrary = this;     
}
//---------------------------------------------------------------------------
void  TImageLibrary::DataModuleDestroy(TObject *Sender)
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
