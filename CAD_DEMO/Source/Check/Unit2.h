//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfNextBlock : public TForm
{
__published:	// IDE-managed Components
    TLabel *lNextBlock;
    TComboBox *cbNextBlock;
private:	// User declarations
public:		// User declarations
    __fastcall TfNextBlock(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfNextBlock *fNextBlock;
//---------------------------------------------------------------------------
#endif
