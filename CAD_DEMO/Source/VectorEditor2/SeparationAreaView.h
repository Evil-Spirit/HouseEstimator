//---------------------------------------------------------------------------

#ifndef SeparationAreaViewH
#define SeparationAreaViewH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class TSeparationAreaView : public TBaseTool{
private:
    TIntVec Point;
    TEditor2D* GetSender(){return (TEditor2D*)UIP.Sender;};
public:
    __property TEditor2D* Sender = {read = GetSender };
    TSeparationAreaView();
    virtual ~TSeparationAreaView(){};
    void State1(){};
    void Action2();
    void State3();
    void Action4();
    bool Conditional5();
     void OnRender();
    AnsiString OnHint();
};
#endif
