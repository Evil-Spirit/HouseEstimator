//---------------------------------------------------------------------------

#ifndef MDI2DVH
#define MDI2DVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MyMDIChildV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TMDI2D : public TMyMDIChild
{
__published:	// IDE-managed Components
  void __fastcall FormShow(TObject *Sender);
    void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMDI2D(TComponent* Owner);
    Graphics::TBitmap * BMP;
    TDrawView *DrawView;
    virtual void __fastcall AppMessage(TMsg& AMessage, bool& Handled);
};
extern COMMONAL_API TMDI2D* ConditionDV;

//---------------------------------------------------------------------------
extern COMMONAL_API TMDI2D *MDI2D;
//---------------------------------------------------------------------------
#endif
