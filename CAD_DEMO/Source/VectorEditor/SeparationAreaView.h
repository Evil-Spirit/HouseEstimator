//---------------------------------------------------------------------------

#ifndef SeparationAreaViewH
#define SeparationAreaViewH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "EditorXDToolV.h"
//---------------------------------------------------------------------------
//class TMyView;
class TSeparationAreaView : public TEditorXDTool{
private:
    TIntVec Point, MPoint;
    TMDelTList<TIntVec> Points;
public:
    TSeparationAreaView();
    virtual ~TSeparationAreaView(){};
    void State1(){};
    void Action2();
    void State3();
    void Action4();
    bool Conditional5();
    void OnRender();
    AnsiString OnHint();
    void Area(TEditor2D* MyEditorXD, TMyView* MyView, const TIntVec& V1, const TIntVec& V2, bool All);
};

class TSeparationAllView : public TSeparationAreaView{
public:
    TSeparationAllView();
    virtual ~TSeparationAllView(){};
    void Action();
};
#endif
