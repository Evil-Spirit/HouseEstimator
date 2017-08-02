//---------------------------------------------------------------------------

#ifndef AdditionalInfinityLineH
#define AdditionalInfinityLineH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class TAdditionalInfinityLine : public TBaseTool{
private:
    TIntVec Point;
    TInfinityLine InfLine;
public:
    TAdditionalInfinityLine();
    virtual ~TAdditionalInfinityLine(){};
    void State1();
    void Action2();
    void State3();
    void Action4();
    void OnRender();
    AnsiString OnHint();
};
#endif
