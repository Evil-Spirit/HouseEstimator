//---------------------------------------------------------------------------

#ifndef CreateObjectLinesH
#define CreateObjectLinesH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "EditorXDToolV.h"
#include "MyEdit.h"
//---------------------------------------------------------------------------
class TCreateObjectLines : public TEditorXDTool{
private:
    TIntVec Point;
    T2DGObject* MO;
public:
    TCreateObjectLines();
    virtual ~TCreateObjectLines(){};
    void State1();
    void Action2();
    void State3();
    bool Conditional4();
    void Action5();
    void Action6();
    void OnRender();
    AnsiString OnHint();
};
#endif
