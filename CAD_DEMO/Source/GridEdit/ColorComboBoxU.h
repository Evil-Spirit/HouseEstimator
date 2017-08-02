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
    __property TNotifyEvent OnColorChange = {read = FOnColorChange,write = FOnColorChange};
public:
    TCellGrid* CellGrid;
    TSelectColor* SC;
    TForm* CellParameter;
	__fastcall virtual TColorComboBox(Classes::TComponent* AOwner,TCellGrid* _CellGrid,  TForm* _Form);
	__fastcall virtual ~TColorComboBox(void);
    void __fastcall AdjustDropDown(void);
    void __fastcall AdjustDropDown2();
	virtual void __fastcall WndProc(Messages::TMessage &Message);
    void __fastcall SelectColorClose(TObject *Sender,TCloseAction &Action);
};
#endif
