// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef SectionDialog1H
#define SectionDialog1H
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class  TSectionDialog : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit1;
    TButton *Button1;
    TButton *Button2;
    void  Button2Click(TObject *Sender);
    void  Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TCellGrid* CellGrid;
     TSectionDialog(TComponent* Owner,TCellGrid* _CellGrid);
};
//---------------------------------------------------------------------------
extern  TSectionDialog *SectionDialog;
//---------------------------------------------------------------------------
#endif
