//---------------------------------------------------------------------------

#ifndef OffsetCellUH
#define OffsetCellUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TOffsetCell : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TButton *Button2;
    TRadioButton *rbLeftOffset;
    TRadioButton *rbTopOffset;
    TLabel *Label1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TOffsetCell(TComponent* Owner, TMGrid* _Grid);

    TMGrid* Grid;
};
//---------------------------------------------------------------------------
extern PACKAGE TOffsetCell *OffsetCell;
//---------------------------------------------------------------------------
#endif
