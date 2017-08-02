//---------------------------------------------------------------------------

#ifndef SelectH
#define SelectH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "EditorXDToolV.h"
#include "MyEdit.h"
#include "ViewV.h"
//---------------------------------------------------------------------------

class TMyCursor;
enum TSelectBlocks
{
    sbiBeforePointMoving = 7,
    sbiPointMoving = 8,
    sbiAfterPointMoving = 27,
    sbiCreateLinkAction = 29,
    sbiUpdateLink = 30
};

class TSelect : public TEditorXDTool{
private:
    TIntVec Point1,Point2;
    TIntVec SRP;
    T2DGObject* SelectedMF;
    TIntVec SelectedPoint;
    TIntVec SnapSelectedPoint;
    TVisPrimitiveObj* SelectedRender;
    MBTi Radius;
    TIntVec RotatePoint;
    TPointDouble pnts[12];
    bool CreateSelect;
    TIntVec BB[4];
    TIntVec FirstVector;
    TMyCursor SelectCursor, RotatedCursor;
    MBTi EpsValueP;
    TIntVec OldCursorPos;
    int SelectedPointIndex;
public:
    TSelect();
    virtual ~TSelect();
    void RotateCursor(MBTi Angle, TPoint Point);
    void State1();
    void Action2();
    bool Condition3();
    void State4();
    bool Condition5();
    void Action6();
    void Action7();
    void BeforePointMoving();
    void PointMoving();
    void Action10();
    bool Condition1to2();
    void Action1to2();
    void State1to2();
    void Action1to2ESC();
    void State15();
    void State16();
    bool Condition17();
    void State18();
    void Action18to19();
    bool Condition19();
    void State20();
    bool Condition21();
    bool Condition22();
    bool Condition23();
    void Action24();
    void AfterPointMoving();
    void Action26();
    void OnRender();
    AnsiString OnHint();
    void _EscCommands();
    void CreateLinkAction();
    void UpdateLink();

    MBTi EpsValue;
};
#endif
 