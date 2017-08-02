//---------------------------------------------------------------------------

#ifndef MDI3DVH
#define MDI3DVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MyMDIChildV.h"
#include "VisCam.hpp"
#include "VisCanvasView.hpp"
#include "VisClass.hpp"
#include "VisComp.hpp"
#include "VisView.hpp"
#include "VisAttr.hpp"
#include "VisLight.hpp"
#include "VisMat.hpp"
#include "VisObj.hpp"
#include "VisPrimitiveObj.hpp"
#include "VisShape.hpp"
#include "VisGeom.hpp"
#include <ExtCtrls.hpp>
#include "MetaClasses.h"
#include "VisTex.hpp"
#include "CameraEngineV.h"

//---------------------------------------------------------------------------

const crHand = -5;


const int nLine = 0;
const int nPoint = 1;
const int nPolygon = 2;

class COMMONAL_API TViewSettings {
public:
    TViewSettings(){};
    virtual ~TViewSettings(){};
    TIntVec NetSize;
    TColor BackColor;
    TColor NetColor;
    int NetLine;
    MBTi STEP;
};

                        
class COMMONAL_API TMDI3D : public TMyMDIChild
{
__published:	// IDE-managed Components
    TVisAttributes *Attr3D;
    TVisPerspectiveCamera *_3DCamera;
    TVisLight *Light0;
    TVisLight *Light1;
    TVisDisc *DiscInvisible;
    TVisMaterial *MaterialInvisible;
    TVisOrthographicCamera *_2DCamera;
    TVisAttributes *Attr2D;
	TPanel *Panel2;
	TVisView *View;
    void __fastcall ViewRender(TVisView *aView);
    void __fastcall ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ViewMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall ViewMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ViewMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ViewKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
protected:
  TMetaMyMode *FMode;
  virtual void SetMode(TMetaMyMode *nMode);
public:		// User declarations
    virtual void CustomRender(TVisCustomView *){};
    virtual void CustomMouseDown(TMouseButton Button,TShiftState Shift,int X,int Y){};
    virtual void CustomMouseMove(TShiftState Shift,int X,int Y){};
    virtual void CustomMouseUp(TMouseButton Button,TShiftState Shift,int X,int Y){};
    virtual void CustomKeyDown(WORD &Key,TShiftState Shift){};
    virtual void CustomKeyUp(WORD &Key,TShiftState Shift){};

    void ToggleCamera();
    void TogglePolygonMode();
    TMainTree* MyMT;
  __property TMetaMyMode *Mode = {read = FMode,write = SetMode};
  __fastcall TMDI3D(TComponent* Owner,TMainTree* MT);
    TViewSettings ViewSet2D;
    TViewSettings ViewSet3D;
    TViewSettings* CurSet;

    TVisAttributes* Attributes;
    TPoint OldMovePoint;

    GLdouble projmat[16],modmat[16];
    GLint  viewport[4];

    //---------------------------------
    TVisVector* Old3DCameraPos;
    TMetaMyMode *OldMode;
    TVisVector* Old2DCameraPos;

    double Old2DWidth;
    double Old2DHeight;
    int OldWidth;
    int OldHeight;
    bool NeedToReCalcMatrices();
    void SaveValues();
    void WinFrom3D(const TVisMathVector& P1,TVisMathVector& RES);
    void WinFrom3D(const TIntVec& P1,TIntVec& RES);
    void WinFrom3D(const TVisMathVector& P1,TIntVec& RES);
    void WinFrom3D(const TVisVector* P1,TIntVec& RES);
    bool WinTo3D(int X,int Y,double Z,TIntVec& RES);
    bool GetPoint(int X,int Y,TIntVec& RES);
    TIntVec GettedPoint;
    TPoint WinPoint;
    bool NeedRender;
    bool AntiAliasingLine;
    //---------------------------------
    TIntVec A,PlaneN;
    TIntVec ScreenToProject(MBTi x, MBTi y, MBTi z);
    TIntVec ScreenToProject(const TIntVec& V);
    TIntVec ProjectToScreen(const TIntVec& Vv);
    MBTi Factor(int Pixels);
    TCameraEngine CameraEngine;
    void CameraAction(TCameraOperation CameraOperation, double value);
    //---------------------------------
};
//---------------------------------------------------------------------------
extern COMMONAL_API TMDI3D *MDI3D;
//---------------------------------------------------------------------------
#endif
