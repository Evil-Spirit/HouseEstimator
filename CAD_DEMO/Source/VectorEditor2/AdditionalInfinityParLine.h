//---------------------------------------------------------------------------

#ifndef AdditionalInfinityParLineH
#define AdditionalInfinityParLineH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class TAdditionalInfinityParLine : public TBaseTool{
private:
    TIntVec Point1, Point2, D, Point;
    TInfinityLine InfLine;
    bool PerLine;
public:
    TAdditionalInfinityParLine();
    virtual ~TAdditionalInfinityParLine(){};
    void State1();
    bool Conditional2();
    void Action3();
    void State4();
    void Action5();
    void OnRender();
    AnsiString OnHint();
};
#endif
