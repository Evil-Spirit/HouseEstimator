//---------------------------------------------------------------------------

#ifndef SelectColorUH
#define SelectColorUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TColorComboBox;
class TCellGrid;

class COMMONAL_API TSelectColor : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TShape *CL11;
    TShape *CL21;
    TShape *CL31;
    TShape *CL41;
    TShape *CL51;
    TShape *CL61;
    TShape *CL71;
    TShape *CL81;
    TShape *CL12;
    TShape *CL13;
    TShape *CL14;
    TShape *CL15;
    TShape *CL22;
    TShape *CL23;
    TShape *CL24;
    TShape *CL25;
    TShape *CL32;
    TShape *CL33;
    TShape *CL34;
    TShape *CL35;
    TShape *CL42;
    TShape *CL43;
    TShape *CL44;
    TShape *CL45;
    TShape *CL52;
    TShape *CL53;
    TShape *CL54;
    TShape *CL55;
    TShape *CL62;
    TShape *CL63;
    TShape *CL64;
    TShape *CL65;
    TShape *CL72;
    TShape *CL73;
    TShape *CL74;
    TShape *CL75;
    TShape *CL82;
    TShape *CL83;
    TShape *CL84;
    TShape *CL85;
    TShape *GetColors;
    TShape *shAutoColor;
    TPanel *AutoFontColor;



    void __fastcall CL11MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall CL11MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall AutoFontColorClick(TObject *Sender);
    void __fastcall FormDeactivate(TObject *Sender);

private:	// User declarations
public:		// User declarations
    TCellGrid* CellGrid;
    TColorComboBox* ColorComboBox;
    __fastcall TSelectColor(TComponent* Owner, TCellGrid* _CellGrid,TColorComboBox* _ColorComboBox);
    TColor __fastcall GetColor();
    void __fastcall CloseU2();
    bool bAutoColor;

};
//---------------------------------------------------------------------------
extern COMMONAL_API TSelectColor *SelectColor;
//---------------------------------------------------------------------------
#endif
