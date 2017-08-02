//---------------------------------------------------------------------------

#ifndef AdditionalDivLineH
#define AdditionalDivLineH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "EditorXDToolV.h"
//---------------------------------------------------------------------------
class TAdditionalDivLine : public TEditorXDTool{
private:
    TIntVec Point;
    TInfinityLine InfLine;
public:
    TAdditionalDivLine();
    virtual ~TAdditionalDivLine(){};
    void State1();
    void Action2();
    void State3();
    void Action4();
    void OnRender();
    AnsiString OnHint();

};
#endif
 