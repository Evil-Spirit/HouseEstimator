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

enum TCameraOperation { coVERTICAL_TRANSLATION = 0,
                        coHORISONTAL_TRANSLATION = 1,
                        coLA_VERTICAL_TRANSLATION = 2,
                        coZ_POSITION_ROTATION = 3,
                        coZ_LOOKAT_ROTATION = 4,
                        coXY_POSITION_ROTATION = 5,
                        coXY_LOOKAT_ROTATION = 6,
                        coLA_DEPTH_TRANSLATION = 7
                        };


class TMyView;						
class TCameraEngine {
private:
    void Vec2RotateZ(TVisVector& A, const TIntVec& B, MBTi Parameter);
    void Vec2RotateXY(TVisVector& A, const TIntVec& B, MBTi Parameter);
public:
    TIntVec A, PlaneN;
    bool UsePlane;
    TCameraEngine();
    ~TCameraEngine();
    void Toggle(TMyView* aView);
    void Operation(TMyView* aView, TCameraOperation CO, const TIntVec& MouseObject, MBTi Parameter);
};

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
	TVisLight *VisLight1;
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
