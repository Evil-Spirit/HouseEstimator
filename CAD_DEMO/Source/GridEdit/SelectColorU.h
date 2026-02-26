// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef SelectColorUH
#define SelectColorUH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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



    void  CL11MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void  CL11MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  AutoFontColorClick(TObject *Sender);
    void  FormDeactivate(TObject *Sender);

private:	// User declarations
public:		// User declarations
    TCellGrid* CellGrid;
    TColorComboBox* ColorComboBox;
     TSelectColor(TComponent* Owner, TCellGrid* _CellGrid,TColorComboBox* _ColorComboBox);
    TColor  GetColor();
    void  CloseU2();
    bool bAutoColor;

};
//---------------------------------------------------------------------------
extern COMMONAL_API TSelectColor *SelectColor;
//---------------------------------------------------------------------------
#endif
