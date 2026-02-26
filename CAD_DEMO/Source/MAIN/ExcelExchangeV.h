// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ExcelExchangeVH
#define ExcelExchangeVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TMetaNode;
//class Variant;

class TExcelExchange : public TForm
{
__published:	// IDE-managed Components
    TListView *LV;
    TButton *btOK;
    TCheckBox *cbCreateAttributes;
    TCheckBox *cbText;
    TComboBox *cbType;
    void  btOKClick(TObject *Sender);
    void  LVClick(TObject *Sender);
    void  cbTypeCloseUp(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TExcelExchange(TComponent* Owner);
};

//void ExcelExport(Variant* WS,TMetaNode* MN);
void ExcelExport(TMetaNode* MN,bool All,const AnsiString& FileName);
void ExcelImport(const AnsiString& FileName);
void Act(const AnsiString& FileName);
//---------------------------------------------------------------------------
extern  TExcelExchange *ExcelExchange;
//---------------------------------------------------------------------------
#endif
