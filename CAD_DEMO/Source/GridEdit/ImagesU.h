// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ImagesUH
#define ImagesUH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class COMMONAL_API TCGIL : public TDataModule
{
__published:	// IDE-managed Components
    TImageList *ilBorders;
    TImageList *ilToolBar;
    void  DataModuleDestroy(TObject *Sender);
    void  DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TCGIL(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TCGIL *CGIL;
//---------------------------------------------------------------------------
#endif
