// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef MyViewVH
#define MyViewVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "VisCanvasView.hpp"
#include "VisClass.hpp"
#include "VisView.hpp"
#include "VisAttr.hpp"
#include "VisCam.hpp"
#include "VisComp.hpp"
#include "VisLight.hpp"
//---------------------------------------------------------------------------
#include "MyEdit.h"
#include "EditorXDToolV.h"
class TEditor2D;
//class TCameraEngine;
typedef void ( *TViewRender)(TVisView *aView);
typedef void ( *TViewMouseWheel)(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
typedef void ( *TViewMouseDown)(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
typedef void ( *TViewMouseUp)(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
typedef void ( *TViewKeyDown)(TObject *Sender, WORD &Key,
          TShiftState Shift);
typedef void ( *TViewKeyUp)(TObject *Sender, WORD &Key,
          TShiftState Shift);
typedef void ( *TViewMouseMove)(TObject *Sender, TShiftState Shift,
          int X, int Y);
/*typedef void ( *TEditorMouseMove)(void* Sender, TShiftState Shift, const TIntVec& MousePosition);
typedef void ( *TEditorMouseDown)(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& MousePosition);
typedef void ( *TEditorMouseUp)(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& MousePosition);
typedef void ( *TEditorKeyDown)(void* Sender, WORD &Key, TShiftState Shift);
typedef void ( *TEditorKeyUp)(void* Sender, WORD &Key, TShiftState Shift);
typedef void ( *TEditorExit)(void* Sender);
typedef void ( *TEditorRender)(void* Sender);
typedef AnsiString ( *TEditorHint)(void* Sender);*/

class TMyView : public TForm
{
__published:	// IDE-managed Components
    TVisView *View;
    TVisAttributes *VisAttributes;
    TVisLight *VisLight;
    TVisOrthographicCamera *VisOrtCam;
    TVisPerspectiveCamera *VisPerspCam;
    TActionList *ActionList;
    TImageList *ImageListV;
    TAction *IdleAction;
    TAction *MoveAction;
    TAction *RotateAction;
    void  ViewRender(TVisView *aView);
    void  ViewMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void  ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ViewMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  ViewKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  ViewMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void  MoveActionExecute(TObject *Sender);
    void  RotateActionExecute(TObject *Sender);
    void  IdleActionExecute(TObject *Sender);
    void  ActionListUpdate(TBasicAction *Action, bool &Handled);
private:	// User declarations
    TPoint OldPoint;
    bool WinTo3D(int X,int Y,double value,TIntVec& RES);
    void WinFrom3D(const TIntVec& P1,TIntVec& RES);
    GLdouble ProjMat[16], ModMat[16];
    int ViewPort[4];
public:		// User declarations
//------------------------------------------------------------------------------
    TViewRender EditorRender;
    TViewMouseWheel EditorMouseWheel;
    TViewMouseDown EditorMouseDown;
    TViewMouseUp EditorMouseUp;
    TViewKeyDown EditorKeyDown;
    TViewKeyUp EditorKeyUp;
    TViewMouseMove EditorMouseMove;
//------------------------------------------------------------------------------
    TIntVec A,PlaneN;
     TMyView(TComponent* Owner);
    TIntVec ScreenToProject(MBTi x, MBTi y, MBTi z);
    TIntVec ScreenToProject(const TIntVec& V);
    TIntVec ProjectToScreen(const TIntVec& Vv);
    MBTi Factor(int Pixels);
    TCameraEngine CameraEngine;
    int CameraAction;
};
//---------------------------------------------------------------------------
extern  TMyView *__MyView;
//---------------------------------------------------------------------------
#endif
