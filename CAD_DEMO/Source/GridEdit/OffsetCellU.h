// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef OffsetCellUH
#define OffsetCellUH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TOffsetCell : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TButton *Button2;
    TRadioButton *rbLeftOffset;
    TRadioButton *rbTopOffset;
    TLabel *Label1;
    void  Button1Click(TObject *Sender);
    void  Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TOffsetCell(TComponent* Owner, TMGrid* _Grid);

    TMGrid* Grid;
};
//---------------------------------------------------------------------------
extern  TOffsetCell *OffsetCell;
//---------------------------------------------------------------------------
#endif
