// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef DrawViewVH
#define DrawViewVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "MDI3DV.h"
//---------------------------------------------------------------------------
class TElement;
class TMDelTList<TIntVec>;
const int PointsCount=100;

extern TPoint TEMP_P[PointsCount];

class COMMONAL_API TDrawView : public TForm
{
__published:	// IDE-managed Components
  void  FormCreate(TObject *Sender);
  void  FormDestroy(TObject *Sender);
  void  FormPaint(TObject *Sender);
  void  FormResize(TObject *Sender);
    void  FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void  FormDblClick(TObject *Sender);
    void  FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void  FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void  FormMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
private:	// User declarations
  TFont *GetFont();
  TBrush *GetBrush();
  TPen *GetPen();
  TMPoint ScreenToObject(const TPoint& Point);

  int ObjectToScreenX(MBTi x);
  int ObjectToScreenY(MBTi y);

  double FScale;
  int FShiftX;
  int FShiftY;

  MBTi FaWidth;
  MBTi FaHeight;
  MBTi FCameraPosX;
  MBTi FCameraPosY;

  void Changed();
  void SetaWidth(MBTi value);
  void SetaHeight(MBTi value);
  void SetCameraPosX(MBTi value);
  void SetCameraPosY(MBTi value);

public:		// User declarations
   TDrawView(TComponent* Owner,TWinControl *_Parent);
   TDrawView(TComponent* Owner);
  Graphics::TBitmap * BMP;
  Graphics::TBitmap * RenderBMP;
  // __property MBTi aWidth {read=FaWidth, write=SetaWidth}; // [manual migration needed]
  // __property MBTi aHeight {read=FaHeight, write=SetaHeight}; // [manual migration needed]
  // __property MBTi CameraPosX {read=FCameraPosX, write=SetCameraPosX}; // [manual migration needed]
  // __property MBTi CameraPosY {read=FCameraPosY, write=SetCameraPosY}; // [manual migration needed]

  // __property int ShiftX {read=FShiftX}; // [manual migration needed]
  // __property int ShiftY {read=FShiftY}; // [manual migration needed]
  // __property double Scale {read=FScale}; // [manual migration needed]

  void PaintCanvas(TCanvas *Canvas);

  void MoveTo(const TElement *Sender,MBTi X,MBTi Y);
  void LineTo(const TElement *Sender,MBTi X,MBTi Y);
  void FloodFill(const TElement *Sender,MBTi X, MBTi Y, TColor Color, TFillStyle FillStyle);
  void Polygon(const TElement *Sender,TMDelTList<TIntVec>* pnts);
  void Ellips( TElement *Sender,MBTi X1,MBTi Y1,MBTi X2,MBTi Y2);

  void TextOut(const TElement *Sender,MBTi X,MBTi Y,char* text);
  MBTi TextHeight(const char* text);
  MBTi TextWidth(const char* text);

  __property TFont *Font = {read = GetFont};
  __property TBrush *Brush = {read = GetBrush};
  __property TPen *Pen = {read = GetPen};
  void TimerAction(TTimerActions TimerAction,double value);
  void GetImage(Graphics::TBitmap* BMP);

  //------------
  void In_Out();
  bool debug_in_out;
  int blue;
  int red;
  int point;
  void ConditionTriangulation();
  bool debug_condition;
    TPoint OldMovePoint;
};

extern COMMONAL_API TDrawView *CurDrawView;
void COMMONAL_API ForceConditionTriangulation(int blue,int red,int point);

TFontStyles COMMONAL_API CreateFontStyles(bool Bold,bool Italic,bool Underline,bool StrikeOut);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
