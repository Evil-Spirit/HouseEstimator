//---------------------------------------------------------------------------
#ifndef DialogEditorToolsUH
#define DialogEditorToolsUH
//---------------------------------------------------------------------------
#include "BaseToolV.h"

class TMyDialogEdit;
//---------------------------------------------------------------------------
class TCreateTool : public TBaseTool
{
    public:
    enum {WaitingMouseDown=1, SelectBorderFrame=2, GetCoords=3, CreateObject=4};
    TMyDialogEdit *DialogEdit;
    TWinControl* MyClickControl;
    int ClassId, FirstX, FirstY, TempX, TempY;
    TColor OldBrush;
    TCreateTool(int _ClassId);
    virtual ~TCreateTool(){};
    void ctState1_WaitingMouseDown();
    void ctState2_SelectBorderFrame();
    void ctAction1_GetCoords();
    void ctAction2_CreateObject();
};

//---------------------------------------------------------------------------
class TSelectTool : public TBaseTool
{
    public:
    enum {WaitingFirstAction=1,WaitingMouseUpClickForSelect=2,DragControls=3,
          WaitingMouseUpClickForReSize=4,IfShiftPressed=5,IfMouseOnBorder=6,
          IfMouseOnControl=7,IfShiftOnControl=8,IfShiftOnSelection=9,StartTool=10,
          ReactionOnButtonClick=12,SelectControls=13,
          DeleteControlFromList=14,InsertControlToList=15,SelectClickControl=16};
    enum {LeftBottom=7,LeftMiddle=0,LeftTop=1,MiddleTop=2,
          RightTop=3,RightMiddle=4,RightBottom=5,MiddleBottom=6};
    TMyDialogEdit *DialogEdit;
    TWinControl* MyClickControl;
    TColor OldColor[255];
    int DirectionIndex;
    int SelectionTop,SelectionLeft,px,py,tx,ty;
    int rdx,rdy;
    int ClassId;
    TSelectTool(int _ClassId);
    virtual ~TSelectTool(){};
    TControl* NewControl;
    //--------------------------------------------
    void stState1_WaitingFirstAction();
    void stState2_WaitingMouseUpClickForSelect();
    void stState3_DragControls();
    void stState4_WaitingMouseUpClickForReSize();
    //--------------------------------------------
    bool stCondition1_IfShiftPressed();
    bool stCondition2_IfMouseOnBorder();
    bool stCondition3_IfMouseOnControl();
    bool stCondition4_IfShiftOnControl();
    bool stCondition5_IfShiftOnSelection();
    //--------------------------------------------
    void stActive_SelectClickControl();
    void stActiveStart_StartTool();
    void stActive2_ReactionOnButtonClick();
    void stActive3_SelectControls();
    void stActive4_DeleteControlFromList();
    void stActive5_InsertControlToList();
    void OnRender();
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
