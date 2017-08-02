//---------------------------------------------------------------------------
#ifndef EditorVH
#define EditorVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "VisAttr.hpp"
#include "VisCam.hpp"
#include "VisCanvasView.hpp"
#include "VisClass.hpp"
#include "VisComp.hpp"
#include "VisMat.hpp"
#include "VisObj.hpp"
#include "VisPrimitiveObj.hpp"
#include "VisShape.hpp"
#include "VisView.hpp"
#include "VisLight.hpp"
#include "VisTex.hpp"
#include "VisGeom.hpp"
#include "VisCustomObj.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>

#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <AppEvnts.hpp>
#include <ActnList.hpp>
#include <Graphics.hpp>

#include "MyEdit.h"
#include "ViewV.h"

//---------------------------------------------------------------------------
struct TCutsToInt{
    int ScrIndex;
    int DstIndex;
};

class TEditor2D : public TForm
{
__published:	// IDE-managed Components
    TVisView *View;
    TVisOrthographicCamera *VisOrtCam;
    TVisAttributes *VisAttributes1;
    TVisLight *VisLight1;
    TToolBar *ToolBar;
    TImageList *ImageList;
    TActionList *AL;
    TStatusBar *SB;
    TToolButton *ToolButton1;
    TApplicationEvents *ApplicationEvents1;
    void __fastcall ViewRender(TVisView *aView);
//    void __fastcall FormShow(TObject *Sender);
    void __fastcall ViewClick(TObject *Sender);
    void __fastcall ViewMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ViewMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ViewKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall PopupMenuItemClick(TObject *Sender);
    void __fastcall ApplicationEventsActionUpdate(TBasicAction *Action,
          bool &Handled);
    void __fastcall ActionExecute(TObject *Sender);
    void __fastcall ALExecute(TBasicAction *Action, bool &Handled);
    void __fastcall ViewResize(TObject *Sender);
    void __fastcall ViewMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall ToolButton1Click(TObject *Sender);
private:	// User declarations
    TPoint OldPoint;
    void WinFrom3D(const TIntVec& P1,TIntVec& RES);
    bool WinTo3D(int X,int Y,double value,TIntVec& RES);
    //PGLdouble ProjMat, ModMat;
    //PGLInt ViewPort;
    TIntVec A,PlaneN;
//    TMDelTList< TMDelTList<TCutsToInt> > CutsToInt;
public:		// User declarations
    __fastcall TEditor2D(TComponent* Owner);
    TIntVec ScreenToProject(MBTi x, MBTi y, MBTi z);
    TIntVec ScreenToProject(const TIntVec& V);
    TIntVec ProjectToScreen(const TIntVec& Vv);
    TGrid Grid;
    int NumberButtonDown;
    TMyControls MyControls;
    //TSeparationAreaView SelectArea;
    //TCreateObjectLines SelectArea;
//    bool GridSnap;
//    bool AdditionalLinesSnap;
    //TMDelTList<int> ButtonIndices;
//    TMTList<TToolButton> ToolButtons;
    void TestGrid(const TIntVec &V1,const TIntVec &V2);
//    void UpdateButtons();
    TIntVec AllSnap(TIntVec Point, bool _GridSnap, bool _AdditionalLineSnap, bool TCFSnap, bool _Selected, bool AttributesGlobalForbit);
    bool AllFigureSnap(TIntVec Point, TIntVec& P1, TIntVec& P2, bool _AdditionalLineSnap, bool TCFSnap);
//    TMTList<TLinesAndCuts> LinesAndCuts;
    TSelection Selection;
    TMDelTList<T2DGObject> CustomFigures;
    TDepthLevels DepthLevels;
    TMyCursor MyCursor;
    TEditorAttributes Attributes;
};
extern PACKAGE TEditor2D *Editor2D;
//---------------------------------------------------------------------------
#endif
