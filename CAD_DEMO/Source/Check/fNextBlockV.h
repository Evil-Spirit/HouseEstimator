// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef fNextBlockVH
#define fNextBlockVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TfNextBlock : public TForm
{
__published:	// IDE-managed Components
    TLabel *lNextBlock;
    TComboBox *cbNextBlock;
private:	// User declarations
public:		// User declarations
     TfNextBlock(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TfNextBlock *fNextBlock;
//---------------------------------------------------------------------------
#endif
