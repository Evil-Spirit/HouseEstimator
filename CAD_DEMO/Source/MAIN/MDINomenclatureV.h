//---------------------------------------------------------------------------

#ifndef MDINomenclatureVH
#define MDINomenclatureVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDIMetaNodeV.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
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
    __fastcall TMDINomenclature(TComponent* Owner,TMetaNode *N);
};
//---------------------------------------------------------------------------
extern PACKAGE TMDINomenclature *MDINomenclature;
//---------------------------------------------------------------------------
#endif
