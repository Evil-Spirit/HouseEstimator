//---------------------------------------------------------------------------

#ifndef ExcelExchangeVH
#define ExcelExchangeVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
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
    void __fastcall btOKClick(TObject *Sender);
    void __fastcall LVClick(TObject *Sender);
    void __fastcall cbTypeCloseUp(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TExcelExchange(TComponent* Owner);
};

//void ExcelExport(Variant* WS,TMetaNode* MN);
void ExcelExport(TMetaNode* MN,bool All,const AnsiString& FileName);
void ExcelImport(const AnsiString& FileName);
void Act(const AnsiString& FileName);
//---------------------------------------------------------------------------
extern PACKAGE TExcelExchange *ExcelExchange;
//---------------------------------------------------------------------------
#endif
