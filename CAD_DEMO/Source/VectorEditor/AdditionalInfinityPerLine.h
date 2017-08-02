//---------------------------------------------------------------------------

#ifndef AdditionalInfinityPerLineH
#define AdditionalInfinityPerLineH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "EditorXDToolV.h"
//---------------------------------------------------------------------------
class TAdditionalInfinityPerLine : public TEditorXDTool{
private:
    TIntVec Point1,Point2;
    TIntVec CursorPos;
    TInfinityLine InfLine;
    bool PerLine;
public:
    TAdditionalInfinityPerLine();
    virtual ~TAdditionalInfinityPerLine(){};
    void State1();
    bool Conditional2();
    void Action3();
    void OnRender();
    AnsiString OnHint();
};
#endif
