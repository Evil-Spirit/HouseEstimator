// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef VectorsViewVH
#define VectorsViewVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
//---------------------------------------------------------------------------
class TMyView : public TForm
{
__published:	// IDE-managed Components
/*    TVisView* View;
    void  Render(TVisView *aView);
    void  Click(TObject *Sender);
    void  MouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void  ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ViewMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  ViewKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);*/
private:	// User declarations
public:		// User declarations
     TMyView(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern  TMyView *MyView;
//---------------------------------------------------------------------------
#endif
