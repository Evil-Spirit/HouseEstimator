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
#include "MyEdit.h"
#include "EditorXDToolV.h"
#include <ActnList.hpp>
class TEditor2D;
//class TCameraEngine;
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

    TEditor2D* Editor2D;
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
