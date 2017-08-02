//---------------------------------------------------------------------------

#ifndef AdditionalCutH
#define AdditionalCutH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class TAdditionalCut : public TBaseTool{
private:
    TIntVec Point;
public:
    TAdditionalCut();
    virtual ~TAdditionalCut(){};
    void State1();
    void Action2();
    void State3();
    void Action4();
    void OnRender();
    AnsiString OnHint();
};
#endif
