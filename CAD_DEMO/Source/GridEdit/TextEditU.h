// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef TextEditUH
#define TextEditUH
//---------------------------------------------------------------------------
class TCellGrid;
class COMMONAL_API TEditText : public TRichEdit{
protected:
	virtual void  WndProc(Messages::TMessage &Message);
public:
    bool IsEsc;
     virtual TEditText(Classes::TComponent* Owner, TCellGrid* _CellGrid);
    inline  virtual ~TEditText(void) { }
    TCellGrid* CellGrid;
    void  KeyDownRich(TObject* Sender, Word &Key, TShiftState Shift);
    void  ExitRich(TObject* Sender);
    bool  IsPrintSymbol(const char& Key);
    AnsiString  FormatMultiLine(const AnsiString Text, const TRect& rect);// ðàçáèòü òåêñò ÷òîáû ïîäõîäèë ïî øèðèíå
};

#endif
