//---------------------------------------------------------------------------

#ifndef AdditionalBoxH
#define AdditionalBoxH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class TAdditionalBox : public TBaseTool{
private:
    TIntVec Point;
    bool AdditionalFigure;
    MBTi ZZZ;
public:
    TAdditionalBox(bool _AdditionalFigure);
    virtual ~TAdditionalBox(){};
    void State1();
    void Action2();
    void State3();
    void Action4();
    void OnRender();
    AnsiString OnHint();
};
#endif
