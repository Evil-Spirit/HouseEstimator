// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDINomenclatureVH
#define MDINomenclatureVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDIMetaNodeV.h"
//---------------------------------------------------------------------------
class TMDINomenclature : public TMDIMetaNode
{
__published:	// IDE-managed Components
    TTabSheet *TabSheet1;
    TGroupBox *GroupBox1;
    TGroupBox *GroupBox2;
    TPanel *Size;
    TPanel *Dimensions;
    TEdit *eStrCode;
    TLabel *lStrCode;
    TLabel *lPrice;
    TEdit *ePrice;
    TComboBoxEx *ComboBoxEx1;
    TLabel *lWeight;
    TEdit *eWeight;
    TGroupBox *GroupBox3;
    TMemo *mMemo;
    TLabel *Label2;
    TEdit *ecurPrice;
    TEdit *ecurWeight;
    TLabel *Label4;
    TPanel *PME;
private:	// User declarations
public:		// User declarations
    virtual void MNRefresh();
    virtual void MNApply();
    virtual bool MNChecked();
    virtual void SETUP();
     TMDINomenclature(TComponent* Owner,TMetaNode *N);
};
//---------------------------------------------------------------------------
extern  TMDINomenclature *MDINomenclature;
//---------------------------------------------------------------------------
#endif
