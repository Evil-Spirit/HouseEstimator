// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#ifndef EditorVH
#define EditorVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
    void  ViewRender(TVisView *aView);
//    void  FormShow(TObject *Sender);
    void  ViewClick(TObject *Sender);
    void  ViewMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void  FormShow(TObject *Sender);
    void  ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ViewMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  ViewKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  PopupMenuItemClick(TObject *Sender);
    void  ApplicationEventsActionUpdate(TBasicAction *Action,
          bool &Handled);
    void  ActionExecute(TObject *Sender);
    void  ALExecute(TBasicAction *Action, bool &Handled);
    void  ViewResize(TObject *Sender);
    void  ViewMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void  ToolButton1Click(TObject *Sender);
private:	// User declarations
    TPoint OldPoint;
    void WinFrom3D(const TIntVec& P1,TIntVec& RES);
    bool WinTo3D(int X,int Y,double value,TIntVec& RES);
    //PGLdouble ProjMat, ModMat;
    //PGLInt ViewPort;
    TIntVec A,PlaneN;
//    TMDelTList< TMDelTList<TCutsToInt> > CutsToInt;
public:		// User declarations
     TEditor2D(TComponent* Owner);
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
extern  TEditor2D *Editor2D;
//---------------------------------------------------------------------------
#endif
