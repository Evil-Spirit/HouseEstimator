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
#include "VisCanvasView.hpp"
#include "MyViewV.h"
#include "EditorXDToolV.h"

//---------------------------------------------------------------------------
struct TCutsToInt{
    int ScrIndex;
    int DstIndex;
};

class T2DGObject;

class TEditor2D : public TForm
{
__published:	// IDE-managed Components
    TToolBar *ToolBar;
    TActionList *AL;
    TStatusBar *SB;
    TToolButton *TBProperty;
    TImageList *ImageList;
    TToolBar *ToolBarV;
    TToolButton *TBMove;
    TToolButton *TBRotate;
    TToolButton *TBZoomAdd;
    TToolButton *TBZoomSub;
    TToolButton *TBIdle;
    TToolButton *TBViewAll;
    void  FormShow(TObject *Sender);
    void  PopupMenuItemClick(TObject *Sender);
    void  ActionExecute(TObject *Sender);
    void  ALExecute(TBasicAction *Action, bool &Handled);
    void  TBPropertyClick(TObject *Sender);
    void  TBViewAllClick(TObject *Sender);
    void  ALUpdate(TBasicAction *Action, bool &Handled);
    void  TBZoomAddClick(TObject *Sender);
    void  TBZoomSubClick(TObject *Sender);
    void  FormResize(TObject *Sender);
private:	// User declarations
//    TMDelTList< TMDelTList<TCutsToInt> > CutsToInt;
    bool FInvalidated;
public:		// User declarations
    TMyView* MyView;
     TEditor2D(TComponent* Owner);
    TGrid Grid;
    int NumberButtonDown;
    TMyEditorControls MyControls;
    MBTi TestGrid();
    TIntVec AllSnap(TIntVec Point, bool _GridSnap, bool _AdditionalLineSnap, bool TCFSnap, bool _Selected, bool AttributesGlobalForbit);
    bool AllFigureSnap(TIntVec Point, TIntVec& P1, TIntVec& P2, bool _AdditionalLineSnap, bool TCFSnap);
//    TMTList<TLinesAndCuts> LinesAndCuts;
    TSelection Selection;
    TMDelTList<T2DGObject> CustomFigures;
    TDepthLevels DepthLevels;
    TMyCursor MyCursor;
    TEditorAttributes Attributes;
    void EditorRender(TVisView *aView);
    void EditorMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void EditorMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void EditorMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void EditorKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void EditorKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void EditorMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    // __property bool Invalidated {read=FInvalidated}; // [manual migration needed]
    void PostRePaint();
};
extern  TEditor2D *Editor2D;
//---------------------------------------------------------------------------
#endif
