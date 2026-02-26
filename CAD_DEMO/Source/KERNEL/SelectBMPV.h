// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef SelectBMPVH
#define SelectBMPVH
//---------------------------------------------------------------------------
#include "MetaClasses.h"
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class COMMONAL_API TSelectBMP : public TForm
{
__published:	// IDE-managed Components
    TListView *LV;
    TComboBoxEx *CBE;
    TButton *btOK;
    TButton *btCancel;
    TButton *btClear;
    void  FormShow(TObject *Sender);
    void  FormCreate(TObject *Sender);
    void  btOKClick(TObject *Sender);
    void  btCancelClick(TObject *Sender);
    void  btClearClick(TObject *Sender);
    void  CBEChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TBMPSet *BMPS;
    int Index;
    bool Clear;
     TSelectBMP(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TSelectBMP *SelectBMP;
//---------------------------------------------------------------------------
#endif
