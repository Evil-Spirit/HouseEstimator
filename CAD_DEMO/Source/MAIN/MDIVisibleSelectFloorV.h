//---------------------------------------------------------------------------

#ifndef MDIVisibleSelectFloorVH
#define MDIVisibleSelectFloorVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
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
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall rbActualAndClick(TObject *Sender);
    void __fastcall btOKClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
    __fastcall TMDIVisibleSelectFloor(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMDIVisibleSelectFloor *MDIVisibleSelectFloor;
//---------------------------------------------------------------------------
#endif
