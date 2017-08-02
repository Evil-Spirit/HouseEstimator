//---------------------------------------------------------------------------

#ifndef TextEditUH
#define TextEditUH
//---------------------------------------------------------------------------
class TCellGrid;
class COMMONAL_API TEditText : public TRichEdit{
protected:
	virtual void __fastcall WndProc(Messages::TMessage &Message);
public:
    bool IsEsc;
    __fastcall virtual TEditText(Classes::TComponent* Owner, TCellGrid* _CellGrid);
    inline __fastcall virtual ~TEditText(void) { }
    TCellGrid* CellGrid;
    void __fastcall KeyDownRich(TObject* Sender, Word &Key, TShiftState Shift);
    void __fastcall ExitRich(TObject* Sender);
    bool __fastcall IsPrintSymbol(const char& Key);
    AnsiString __fastcall FormatMultiLine(const AnsiString Text, const TRect& rect);// разбить текст чтобы подходил по ширине
};

#endif
