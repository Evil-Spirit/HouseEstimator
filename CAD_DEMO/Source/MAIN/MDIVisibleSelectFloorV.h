// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDIVisibleSelectFloorVH
#define MDIVisibleSelectFloorVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TMDIVisibleSelectFloor : public TForm
{
__published:	// IDE-managed Components
    TButton *btOK;
    TButton *btCancel;
    TRadioButton *rbAll;
    TRadioButton *rbActual;
    TRadioButton *rbActualAnd;
    TListBox *LB;
    void  FormCreate(TObject *Sender);
    void  rbActualAndClick(TObject *Sender);
    void  btOKClick(TObject *Sender);
    void  FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
     TMDIVisibleSelectFloor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TMDIVisibleSelectFloor *MDIVisibleSelectFloor;
//---------------------------------------------------------------------------
#endif
