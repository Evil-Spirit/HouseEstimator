//---------------------------------------------------------------------------

#ifndef VectorsViewVH
#define VectorsViewVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TMyView : public TForm
{
__published:	// IDE-managed Components
/*    TVisView* View;
    void __fastcall Render(TVisView *aView);
    void __fastcall Click(TObject *Sender);
    void __fastcall MouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void __fastcall ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ViewMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ViewKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);*/
private:	// User declarations
public:		// User declarations
    __fastcall TMyView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyView *MyView;
//---------------------------------------------------------------------------
#endif
