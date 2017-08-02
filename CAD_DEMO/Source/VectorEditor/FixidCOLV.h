//---------------------------------------------------------------------------

#ifndef FixidCOLVH
#define FixidCOLVH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
#include "MyEdit.h"
//---------------------------------------------------------------------------
class TCreateObjectLines : public TBaseTool{
private:
    TIntVec Point1, Point2;
    TIntVec CursorPos;
    TMyFigure* MO;
    MBTi SnapValueP;
public:
    TCreateObjectLines();
    virtual ~TCreateObjectLines(){};
    void State1();
    void Action2();
    void State3();
    bool Conditional4();
    void Action5();
    void Action6();
    void _EscCommands();
    void OnRender();
    AnsiString OnHint();

    MBTi SnapValue;
};
#endif
