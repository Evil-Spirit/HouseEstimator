//---------------------------------------------------------------------------

#ifndef ImagesUH
#define ImagesUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TCGIL : public TDataModule
{
__published:	// IDE-managed Components
    TImageList *ilBorders;
    TImageList *ilToolBar;
    void __fastcall DataModuleDestroy(TObject *Sender);
    void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TCGIL(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TCGIL *CGIL;
//---------------------------------------------------------------------------
#endif
