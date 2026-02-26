// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef ColorComboBoxUH
#define ColorComboBoxUH
//---------------------------------------------------------------------------
class TSelectColor;

class TColorComboBox : public TCustomComboBox {
protected:
    TNotifyEvent FOnColorChange;

__published:
    __property Font;
    __property Color;
    // __property TNotifyEvent OnColorChange {read=FOnColorChange, write=FOnColorChange}; // [manual migration needed]
public:
    TCellGrid* CellGrid;
    TSelectColor* SC;
    TForm* CellParameter;
	 virtual TColorComboBox(Classes::TComponent* AOwner,TCellGrid* _CellGrid,  TForm* _Form);
	 virtual ~TColorComboBox(void);
    void  AdjustDropDown(void);
    void  AdjustDropDown2();
	virtual void  WndProc(Messages::TMessage &Message);
    void  SelectColorClose(TObject *Sender,TCloseAction &Action);
};
#endif
