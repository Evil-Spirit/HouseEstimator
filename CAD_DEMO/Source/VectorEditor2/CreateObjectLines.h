//---------------------------------------------------------------------------

#ifndef CreateObjectLinesH
#define CreateObjectLinesH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
#include "MyEdit.h"
//---------------------------------------------------------------------------
class TCreateObjectLines : public TBaseTool{
private:
    TIntVec Point;
    T2DGObject* MO;
    TEditor2D* GetSender(){return (TEditor2D*)UIP.Sender;};
public:
    __property TEditor2D* Sender = {read = GetSender };
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
