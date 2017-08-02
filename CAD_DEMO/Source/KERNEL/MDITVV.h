//---------------------------------------------------------------------------

#ifndef MDITVVH
#define MDITVVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MDI3DV.h"
#include "VisAttr.hpp"
#include "VisCam.hpp"
#include "VisCanvasView.hpp"
#include "VisClass.hpp"
#include "VisComp.hpp"
#include "VisLight.hpp"
#include "VisMat.hpp"
#include "VisObj.hpp"
#include "VisView.hpp"
#include "VisPoly.hpp"
#include "VisPrimitiveObj.hpp"
#include "VisShape.hpp"
#include "VisTex.hpp"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include "VisCntrl.hpp"
#include "VisTimer.hpp"
#include "ElementV.h"
#include <Menus.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class COMMONAL_API TMDITV : public TMDI3D
{
__published:	// IDE-managed Components
    TPanel *pViewButtons;
    TToolBar *tbViewButtons;
    TToolButton *tbMinus;
    TToolButton *tbPlus;
    TVisNode *VisNode;
    TTimer *_Timer;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    void __fastcall ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormShow(TObject *Sender);
  void __fastcall tbPlusMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall tbMinusMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall _TimerTimer(TObject *Sender);
    void __fastcall ViewResize(TObject *Sender);
    void __fastcall ToolButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  void CustomRender(TVisCustomView *);
  TElement *EL;
    __fastcall TMDITV(TComponent* Owner,TWinControl *Parent,TMainTree* MT);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDITV *MDITV;
//---------------------------------------------------------------------------
#endif
