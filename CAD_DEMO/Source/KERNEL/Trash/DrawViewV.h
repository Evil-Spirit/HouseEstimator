//---------------------------------------------------------------------------

#ifndef DrawViewVH
#define DrawViewVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "MDI3DV.h"
//---------------------------------------------------------------------------
class TElement;
class TMDelTList<TIntVec>;
const int PointsCount=100;

extern TPoint TEMP_P[PointsCount];

class COMMONAL_API TDrawView : public TForm
{
__published:	// IDE-managed Components
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormDblClick(TObject *Sender);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
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
  __fastcall TDrawView(TComponent* Owner,TWinControl *_Parent);
  __fastcall TDrawView(TComponent* Owner);
  Graphics::TBitmap * BMP;
  Graphics::TBitmap * RenderBMP;
  __property MBTi aWidth = {read = FaWidth,write = SetaWidth};
  __property MBTi aHeight= {read = FaHeight,write = SetaHeight};
  __property MBTi CameraPosX= {read = FCameraPosX,write = SetCameraPosX};
  __property MBTi CameraPosY= {read = FCameraPosY,write = SetCameraPosY};

  __property int ShiftX= {read = FShiftX};
  __property int ShiftY= {read = FShiftY};
  __property double Scale= {read = FScale};

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
