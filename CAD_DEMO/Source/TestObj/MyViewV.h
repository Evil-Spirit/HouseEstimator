//---------------------------------------------------------------------------

#ifndef MyViewVH
#define MyViewVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VisCanvasView.hpp"
#include "VisClass.hpp"
#include "VisView.hpp"
#include "VisAttr.hpp"
#include "VisCam.hpp"
#include "VisComp.hpp"
#include "VisLight.hpp"
#include <ImgList.hpp>
//---------------------------------------------------------------------------
#include <ActnList.hpp>

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
typedef void (__closure *TViewRender)(TVisView *aView);
typedef void (__closure *TViewMouseWheel)(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
typedef void (__closure *TViewMouseDown)(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
typedef void (__closure *TViewMouseUp)(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
typedef void (__closure *TViewKeyDown)(TObject *Sender, WORD &Key,
          TShiftState Shift);
typedef void (__closure *TViewKeyUp)(TObject *Sender, WORD &Key,
          TShiftState Shift);
typedef void (__closure *TViewMouseMove)(TObject *Sender, TShiftState Shift,
          int X, int Y);
/*typedef void (__closure *TEditorMouseMove)(void* Sender, TShiftState Shift, const TIntVec& MousePosition);
typedef void (__closure *TEditorMouseDown)(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& MousePosition);
typedef void (__closure *TEditorMouseUp)(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& MousePosition);
typedef void (__closure *TEditorKeyDown)(void* Sender, WORD &Key, TShiftState Shift);
typedef void (__closure *TEditorKeyUp)(void* Sender, WORD &Key, TShiftState Shift);
typedef void (__closure *TEditorExit)(void* Sender);
typedef void (__closure *TEditorRender)(void* Sender);
typedef AnsiString (__closure *TEditorHint)(void* Sender);*/

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
    void __fastcall ViewRender(TVisView *aView);
    void __fastcall ViewMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void __fastcall ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ViewMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ViewKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ViewMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall MoveActionExecute(TObject *Sender);
    void __fastcall RotateActionExecute(TObject *Sender);
    void __fastcall IdleActionExecute(TObject *Sender);
    void __fastcall ActionListUpdate(TBasicAction *Action, bool &Handled);
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
    __fastcall TMyView(TComponent* Owner);
    TIntVec ScreenToProject(MBTi x, MBTi y, MBTi z);
    TIntVec ScreenToProject(const TIntVec& V);
    TIntVec ProjectToScreen(const TIntVec& Vv);
    MBTi Factor(int Pixels);
    TCameraEngine CameraEngine;
    int CameraAction;
};
//---------------------------------------------------------------------------
extern PACKAGE TMyView *__MyView;
//---------------------------------------------------------------------------
#endif
