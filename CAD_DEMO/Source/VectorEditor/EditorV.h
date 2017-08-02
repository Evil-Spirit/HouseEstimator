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
    void __fastcall FormShow(TObject *Sender);
    void __fastcall PopupMenuItemClick(TObject *Sender);
    void __fastcall ActionExecute(TObject *Sender);
    void __fastcall ALExecute(TBasicAction *Action, bool &Handled);
    void __fastcall TBPropertyClick(TObject *Sender);
    void __fastcall TBViewAllClick(TObject *Sender);
    void __fastcall ALUpdate(TBasicAction *Action, bool &Handled);
    void __fastcall TBZoomAddClick(TObject *Sender);
    void __fastcall TBZoomSubClick(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
private:	// User declarations
//    TMDelTList< TMDelTList<TCutsToInt> > CutsToInt;
    bool FInvalidated;
public:		// User declarations
    TMyView* MyView;
    __fastcall TEditor2D(TComponent* Owner);
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
    __property bool Invalidated = {read = FInvalidated};
    void PostRePaint();
};
extern PACKAGE TEditor2D *Editor2D;
//---------------------------------------------------------------------------
#endif
