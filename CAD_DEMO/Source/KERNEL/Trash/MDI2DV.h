// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDI2DVH
#define MDI2DVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MyMDIChildV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDI2D : public TMyMDIChild
{
__published:	// IDE-managed Components
  void  FormShow(TObject *Sender);
    void  FormMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void  FormCreate(TObject *Sender);
    void  FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
     TMDI2D(TComponent* Owner);
    Graphics::TBitmap * BMP;
    TDrawView *DrawView;
    virtual void  AppMessage(TMsg& AMessage, bool& Handled);
};
extern COMMONAL_API TMDI2D* ConditionDV;

//---------------------------------------------------------------------------
extern COMMONAL_API TMDI2D *MDI2D;
//---------------------------------------------------------------------------
#endif
