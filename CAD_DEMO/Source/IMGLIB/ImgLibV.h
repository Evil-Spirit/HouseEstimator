//---------------------------------------------------------------------------

#ifndef ImgLibVH
#define ImgLibVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>
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
    void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TImageLibrary(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TImageLibrary *ImageLibrary;
//---------------------------------------------------------------------------
#endif
