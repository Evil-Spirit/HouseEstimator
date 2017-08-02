//---------------------------------------------------------------------------

#ifndef SectionDialog1H
#define SectionDialog1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class PACKAGE TSectionDialog : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit1;
    TButton *Button1;
    TButton *Button2;
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TCellGrid* CellGrid;
    __fastcall TSectionDialog(TComponent* Owner,TCellGrid* _CellGrid);
};
//---------------------------------------------------------------------------
extern PACKAGE TSectionDialog *SectionDialog;
//---------------------------------------------------------------------------
#endif
