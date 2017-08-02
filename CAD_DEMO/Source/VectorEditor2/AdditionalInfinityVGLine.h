//---------------------------------------------------------------------------

#ifndef AdditionalInfinityVGLineH
#define AdditionalInfinityVGLineH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class TAdditionalInfinityVGLine : public TBaseTool{
private:
    TInfinityLine InfLine;
    MBTi dx,dy;
public:
    TAdditionalInfinityVGLine(MBTi _dx,MBTi _dy);
    virtual ~TAdditionalInfinityVGLine(){};
    void State1();
    void Action2();
    void OnRender();
    AnsiString OnHint();
};
#endif
