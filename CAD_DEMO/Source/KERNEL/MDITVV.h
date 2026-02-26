// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MDITVVH
#define MDITVVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
#include "VisCntrl.hpp"
#include "VisTimer.hpp"
#include "ElementV.h"
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
    void  ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  FormShow(TObject *Sender);
  void  tbPlusMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void  tbMinusMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void  _TimerTimer(TObject *Sender);
    void  ViewResize(TObject *Sender);
    void  ToolButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  void CustomRender(TVisCustomView *);
  TElement *EL;
     TMDITV(TComponent* Owner,TWinControl *Parent,TMainTree* MT);
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDITV *MDITV;
//---------------------------------------------------------------------------
#endif
