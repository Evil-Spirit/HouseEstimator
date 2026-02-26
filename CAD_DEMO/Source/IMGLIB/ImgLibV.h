// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ImgLibVH
#define ImgLibVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TImageLibrary : public TDataModule
{
__published:	// IDE-managed Components
    TImageList *ScrollImg;
    TImageList *ActionImages;
    TImageList *TreeImages;
    TImageList *ilStandart;
    TImageList *BlocksImageList;
  TImageList *ScrollImgDisabled;
    void  DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TImageLibrary(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TImageLibrary *ImageLibrary;
//---------------------------------------------------------------------------
#endif
