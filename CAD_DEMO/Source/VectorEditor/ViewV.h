// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
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
    void  Render(TVisView *aView);
    void  Click(TObject *Sender);
    void  MouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
    void  ViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ViewMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  ViewKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  ViewKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
};*/
//-----------&&&------------
class TEditor2D;
class TMyView;

class  TMyCursor : public TMyObject{
public:
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
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

#endif
