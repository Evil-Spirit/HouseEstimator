//---------------------------------------------------------------------------

#ifndef ViewVH
#define ViewVH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
//---------------------------------------------------------------------------
//-----------&&&------------
class TMyView : public TMyObject{
private:
public:
    TMyView();
    ~TMyView();
    TVisView* VisView;
//    TMyCursor Cursor;
};
//-----------&&&------------
class TEditor2D;

class TMyCursor : public TMyObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TVisPrimitiveObj* VCO;
    TMyCursor();
//    TMyCursor(bool _Visible, MBTi _SizeCursor);
    ~TMyCursor(){};
    TIntVec Position;
    int Size;//pixels
    int LineWidth;
    TColor Color;
    bool Visible;
    void Render(TEditor2D* aView);
};

TClassNode* TMyCursor::StaticType = NULL;
#endif
