//---------------------------------------------------------------------------

#ifndef ViewVH
#define ViewVH
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
//---------------------------------------------------------------------------
//-----------&&&------------
/*class TMyView : public TMyObject{
private:
public:
    TMyView();
    ~TMyView();
    TVisView* View;
    TVisOrthographicCamera *VisOrtCam;
    TVisPerspectiveCamera *VisPerspCam;
    TVisAttributes *VisAttributes;
    TVisLight *VisLight;
    void __fastcall Render(TVisView *aView);
    void __fastcall Click(TObject *Sender);
    void __fastcall MouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void __fastcall ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ViewMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ViewKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
};*/
//-----------&&&------------
class TEditor2D;
class TMyView;

class PACKAGE TMyCursor : public TMyObject{
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
    void Render(TMyView* aView);
};

extern PACKAGE TClassNode* TMyCursor::StaticType;
#endif
