 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "DrawViewV.h"
#include "ElementV.h"
#include "MyGL.h"
#include "World.h"
#include "LogicNode.h"
#include "Triangulation.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDrawView *CurDrawView=NULL;
TPoint TEMP_P[PointsCount];
//---------------------------------------------------------------------------
__fastcall TDrawView::TDrawView(TComponent* Owner,TWinControl *_Parent)
  : TForm(Owner)
{
    Parent = _Parent;
}
  __fastcall TDrawView::TDrawView(TComponent* Owner)
  : TForm(Owner)
{
    throw EMyException("Invalid constructor");
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TDrawView::Changed()
{
  if (BMP->Width<BMP->Height)
    FScale = ( ((double)(BMP->Width)) / FaWidth );
  else
    FScale = ( ((double)(BMP->Height)) / FaHeight );

  FShiftX = BMP->Width/2 - RoundTo(FCameraPosX*FScale,0);
  FShiftY = BMP->Height/2 - RoundTo(FCameraPosY*FScale,0);
}

void TDrawView::SetaWidth(MBTi value)
{
  FaWidth = value;
  Changed();
}

void TDrawView::SetaHeight(MBTi value)
{
  FaHeight = value;
  Changed();
}

void TDrawView::SetCameraPosX(MBTi value)
{
  FCameraPosX = value;
  Changed();
}

void TDrawView::SetCameraPosY(MBTi value)
{
  FCameraPosY = value;
  Changed();
}

int TDrawView::ObjectToScreenX(MBTi x)
{
  return FShiftX+RoundTo(x*FScale,0);
}

int TDrawView::ObjectToScreenY(MBTi y)
{
  return (BMP->Height - (FShiftY+RoundTo(y*FScale,0)));
}

TMPoint TDrawView::ScreenToObject(const TPoint& Point)
{
  return TMPoint(0,0);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TDrawView::PaintCanvas(TCanvas *Canvas)
{
    Canvas->Brush->Color = clWhite;
    Canvas->Pen->Color = clBlack;
    Canvas->FillRect(TRect(0,0,BMP->Width,BMP->Height));
    if (debug_in_out && World)
        In_Out();
    else if (debug_condition)
        ConditionTriangulation();
    else if ( AUI && AUI->ActiveWorld )
        AUI->ActiveWorld->Render2D(this);
    if (BMP->Width<RenderBMP->Width || BMP->Height<RenderBMP->Height)
    {
        delete RenderBMP;
        RenderBMP = new Graphics::TBitmap();
                        RenderBMP->HandleType = bmDIB;

    }

  RenderBMP->Width = BMP->Width;
  RenderBMP->Height = BMP->Height;
  RenderBMP->Canvas->Draw(0,0,BMP);
/*  Canvas->Rectangle(20,20,Width-20,Height-20);
  Canvas->Rectangle(30,30,Width-30,Height-30);
  Canvas->Brush->Color = clGreen;
  Canvas->FloodFill(25,25,clBlack,fsBorder);*/
}

void __fastcall TDrawView::FormCreate(TObject *Sender)
{
  BMP = new Graphics::TBitmap();
                        BMP->HandleType = bmDIB;
  RenderBMP = new Graphics::TBitmap();
                        RenderBMP->HandleType = bmDIB;

  debug_in_out = false;
  debug_condition = false;
  FaWidth = 20;
  FaHeight = 20;
  FCameraPosX = 0;
  FCameraPosY = 0;
  Changed();
}
//---------------------------------------------------------------------------

void __fastcall TDrawView::FormDestroy(TObject *Sender)
{
  delete BMP;
  delete RenderBMP;
}
//---------------------------------------------------------------------------
void __fastcall TDrawView::FormPaint(TObject *Sender)
{
  PaintCanvas(BMP->Canvas);
  Canvas->Draw(0,0,RenderBMP);
}
//---------------------------------------------------------------------------

void __fastcall TDrawView::FormResize(TObject *Sender)
{
    if (BMP->Width>Width || BMP->Height>Height)
    {
        delete BMP;
        BMP = new Graphics::TBitmap();
                        BMP->HandleType = bmDIB;
    }
  BMP->Width = Width;
  BMP->Height = Height;
  Changed();
  Paint();
}
//---------------------------------------------------------------------------
TFont *TDrawView::GetFont()
{
  return BMP->Canvas->Font;
}

TBrush *TDrawView::GetBrush()
{
  return BMP->Canvas->Brush;
}

TPen *TDrawView::GetPen()
{
  return BMP->Canvas->Pen;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
TIntVec DV_TEMP_VEC;
void TDrawView::MoveTo(const TElement *Sender,MBTi X,MBTi Y)
{
  if (Sender)
  {
    DV_TEMP_VEC.x=X;
    DV_TEMP_VEC.y=Y;
    DV_TEMP_VEC= RotateAround(DV_TEMP_VEC,Sender->AbsAngle,ZEROINTVEC)+Sender->AbsPos;
    BMP->Canvas->MoveTo( ObjectToScreenX(DV_TEMP_VEC.x),ObjectToScreenY(DV_TEMP_VEC.y) );
  }
}

void TDrawView::LineTo(const TElement *Sender,MBTi X,MBTi Y)
{
  if (Sender)
  {
    DV_TEMP_VEC.x=X;
    DV_TEMP_VEC.y=Y;
    DV_TEMP_VEC= RotateAround(DV_TEMP_VEC,Sender->AbsAngle,ZEROINTVEC)+Sender->AbsPos;
    BMP->Canvas->LineTo( ObjectToScreenX(DV_TEMP_VEC.x),ObjectToScreenY(DV_TEMP_VEC.y) );
  }
}

void TDrawView::Ellips(TElement *Sender,MBTi X1,MBTi Y1,MBTi X2,MBTi Y2)
{
    TIntVec Vec2;
  if (Sender)
  {
    DV_TEMP_VEC.x=X1;
    DV_TEMP_VEC.y=Y1;
    Vec2.x=X2;
    Vec2.y=Y2;
    Sender->AbsFromLocal(DV_TEMP_VEC,DV_TEMP_VEC);
    Sender->AbsFromLocal(Vec2,Vec2);
    BMP->Canvas->Ellipse( ObjectToScreenX(DV_TEMP_VEC.x),ObjectToScreenY(DV_TEMP_VEC.y),ObjectToScreenX(Vec2.x),ObjectToScreenY(Vec2.y) );
  }
}


void TDrawView::FloodFill(const TElement *Sender,MBTi X, MBTi Y, TColor Color, TFillStyle FillStyle)
{
  if (Sender)
  {
    DV_TEMP_VEC.x=X;
    DV_TEMP_VEC.y=Y;
    DV_TEMP_VEC= RotateAround(DV_TEMP_VEC,Sender->AbsAngle,ZEROINTVEC)+Sender->AbsPos;
    BMP->Canvas->FloodFill( ObjectToScreenX(DV_TEMP_VEC.x),ObjectToScreenY(DV_TEMP_VEC.y),Color,FillStyle );
  }
}

TFontStyles CreateFontStyles(bool Bold,bool Italic,bool Underline,bool StrikeOut)
{
  TFontStyles FS = TFontStyles();
  if (Bold)
    FS = FS<<fsBold;
  if (Italic)
    FS = FS<<fsItalic;
  if (Underline)
    FS = FS<<fsUnderline;
  if (StrikeOut)
    FS = FS<<fsStrikeOut;
  return FS;
}

void TDrawView::TextOut(const TElement *Sender,MBTi X,MBTi Y,char* text)
{
  if (Sender)
  {
    DV_TEMP_VEC.x=X;
    DV_TEMP_VEC.y=Y;
    DV_TEMP_VEC= RotateAround(DV_TEMP_VEC,Sender->AbsAngle,ZEROINTVEC)+Sender->AbsPos;
    BMP->Canvas->TextOut( ObjectToScreenX(DV_TEMP_VEC.x),ObjectToScreenY(DV_TEMP_VEC.y),AnsiString(text));
  }
}

MBTi TDrawView::TextHeight(const char* text)
{
  return ((MBTi)BMP->Canvas->TextHeight(AnsiString(text)))/Scale;
}

MBTi TDrawView::TextWidth(const char* text)
{
  return ((MBTi)BMP->Canvas->TextWidth(AnsiString(text)))/Scale;
}

void TDrawView::TimerAction(TTimerActions TimerAction,double value)
{
    int sign= ((TimerAction % 2)==0);
    float ver;
    float hor;
    hor = float(sign)*4*value - float(1-sign)*4*value;
    ver = float(sign)*4*value - float(1-sign)*4*value;
    switch(TimerAction)
    {
      case taCameraTop:
      case taCameraDown:
      case taCameraRTop:
      case taCameraRDown:
          CameraPosY = CameraPosY + (ver/6);
      break;
      case taCameraLeft:
      case taCameraRight:
      case taCameraRLeft:
      case taCameraRRight:
          CameraPosX = CameraPosX - (hor/6);
      break;
      case taZoomPlus:
      case taZoomMinus:
        double z=   aWidth +
                    aHeight;
        z=  z*((TimerAction == taZoomPlus)*(1 - 0.08*value) + (TimerAction == taZoomMinus)*(1+0.08*value));
        aWidth = z/2;
        aHeight = z/2;
      break;
    }
    Paint();
}

void TDrawView::Polygon(const TElement *Sender,TMDelTList<TIntVec>* pnts)
{
  if (Sender)
    for (int i=0;i<MIN(pnts->Count,PointsCount);i++)
    {
      DV_TEMP_VEC= RotateAround(*(pnts->Items[i]),Sender->AbsAngle,ZEROINTVEC)+Sender->AbsPos;
      TEMP_P[i].x = ObjectToScreenX(DV_TEMP_VEC.x);
      TEMP_P[i].y = ObjectToScreenY(DV_TEMP_VEC.y);
    }
  BMP->Canvas->Polygon(TEMP_P,MIN(pnts->Count,PointsCount)-1);
}

void DrawArrow(TDrawView* DV,TElement*El, const TIntVec& P0,const TIntVec& P1 )
{
    TIntVec Angle = ZEROINTVEC;
    Angle.z = -((AngleRadOX(P0,P1))*180)/M_PI;
    TIntVec locP1 = RotateAround(P1,Angle,P0);
    TIntVec ArrowP11 = TIntVec(locP1.x-0.1,locP1.y+0.025,locP1.z);
    TIntVec ArrowP12 = TIntVec(locP1.x-0.1,locP1.y-0.025,locP1.z);
    Angle.z = -Angle.z;
    ArrowP11 = RotateAround(ArrowP11,Angle,P0);
    ArrowP12 = RotateAround(ArrowP12,Angle,P0);
    DV->MoveTo(El,P0.x,P0.y);
    DV->LineTo(El,P1.x,P1.y);
    DV->MoveTo(El,ArrowP11.x,ArrowP11.y);
    DV->LineTo(El,P1.x,P1.y);
    DV->MoveTo(El,ArrowP12.x,ArrowP12.y);
    DV->LineTo(El,P1.x,P1.y);
}

void DrawPoint(TDrawView* DV,TElement*El, const TIntVec& P0 )
{
    DV->MoveTo(El,P0.x-0.1,P0.y-0.1);
    DV->LineTo(El,P0.x+0.1,P0.y-0.1);
    DV->LineTo(El,P0.x+0.1,P0.y+0.1);
    DV->LineTo(El,P0.x-0.1,P0.y+0.1);
    DV->LineTo(El,P0.x-0.1,P0.y-0.1);
}

void DrawTriangle(TDrawView* DV,TElement*El, const TIntVec& P0,const TIntVec& P1,const TIntVec& P2 )
{
    DV->MoveTo(El,P0.x,P0.y);
    DV->LineTo(El,P1.x,P1.y);
    DV->LineTo(El,P2.x,P2.y);
    DV->LineTo(El,P0.x,P0.y);
}

void TDrawView::ConditionTriangulation()
{
    TElement* Land = (TElement*)World->Head;
    if (!Land)
        return;
    if (point == -100)
    {
        for (int i=0;i<Delone.Triangles.Count;)
        {
            DrawTriangle(this,Land,Delone.Triangles[i],Delone.Triangles[i+1],Delone.Triangles[i+2]);
            i+=3;
        }
        return;
    }
    if (point == -200)
    {
        for (int i=0;i<Delone.Tri_Ribs.Count;)
        {
            DrawArrow(this,Land,*((TIntVec*)Delone.Tri_Ribs[i].ORGN),*((TIntVec*)Delone.Tri_Ribs[i].DEST));
            DrawArrow(this,Land,*((TIntVec*)Delone.Tri_Ribs[i+1].ORGN),*((TIntVec*)Delone.Tri_Ribs[i+1].DEST));
            DrawArrow(this,Land,*((TIntVec*)Delone.Tri_Ribs[i+2].ORGN),*((TIntVec*)Delone.Tri_Ribs[i+2].DEST));
            i+=3;
        }
        return;
    }

    for (int i=0;i<Delone.rAll.Count;i++)
    {
        if (i==red)
            Pen->Color = clRed;
        else if (i == blue)
            Pen->Color = clBlue;
        else
            Pen->Color = clBlack;
        DrawArrow(this,Land,*((TIntVec*)Delone.rAll[i].ORGN),*((TIntVec*)Delone.rAll[i].DEST));
    }
    if (point>=0 && point<Delone.pAll.Count)
    {
        Pen->Color = clRed;
        DrawPoint(this,Land, (TIntVec&)Delone.pAll[point] );
    }
}


void TDrawView::In_Out()
{
    TElement* Land = (TElement*)World->Head;
    if (!Land)
        return;

    if (!LN->NetActual)
        LN->ReBuildNet();

    Pen->Color = clBlack;
    for (int i=0;i<LN->RPTS.Count;i++)
        for (int j=0;j<LN->RPTS[i].Count;j++)
            DrawArrow(this,Land,*LN->RPTS[i][j].Pnt,*LN->RPTS[i].CycleItems[j+1]->Pnt);

    for (int i=0;i<LN->RNS.Count;i++)
        Ellips(Land,    LN->RNS[i].LinkPoint.x-0.01,
                        LN->RNS[i].LinkPoint.y-0.01,
                        LN->RNS[i].LinkPoint.x+0.01,
                        LN->RNS[i].LinkPoint.y+0.01);

/*    for (int i=0;i<LN->EP.Count;i++)
        for (int j=0;j<LN->EP[i].Sides.Count;j++)
            DrawArrow(this,Land,*LN->EP[i].Sides[j].P0,*LN->EP[i].Sides[j].P1);

    Pen->Color = clBlue;
    for (int i=0;i<LN->RNS.Count;i++)
        for (int j=0;j<LN->RNS[i].Rays.Count;j++)
        {
            if (LN->RNS[i].Rays[j].XPlusDirection)
                DrawArrow(this,Land,*LN->RNS[i].Rays[j].Point,LN->RNS[i].LinkPoint);
            else
                DrawArrow(this,Land,LN->RNS[i].LinkPoint,*LN->RNS[i].Rays[j].Point);
        }*/
}
void __fastcall TDrawView::FormDblClick(TObject *Sender)
{
    debug_in_out = !debug_in_out;
    Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TDrawView::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  switch(Key)
  {
    case char(37):
    {
      TimerAction(taCameraLeft,0.6);
    } break;
    case char(38):
    {
      TimerAction(taCameraTop,0.6);
    } break;
    case char(39):
    {
      TimerAction(taCameraRight,0.6);
    } break;
    case char(40):
    {
      TimerAction(taCameraDown,0.6);
    } break;
    case char(100):
    {
      TimerAction(taCameraRLeft,0.6);
    } break;
    case char(104):
    {
      TimerAction(taCameraRTop,0.6);
    } break;
    case char(102):
    {
      TimerAction(taCameraRRight,0.6);
    } break;
    case char(98):
    {
      TimerAction(taCameraRDown,0.6);
    } break;
    case char(107):
    {
      TimerAction(taZoomPlus,0.6);
    } break;
    case char(109):
    {
      TimerAction(taZoomMinus,0.6);
    } break;
  }
}
//---------------------------------------------------------------------------

void TDrawView::GetImage(Graphics::TBitmap* FillBMP)
{
    Graphics::TBitmap* OldBMP = BMP;
    try
    {
        try
        {
            BMP = FillBMP;
            Changed();
            PaintCanvas(BMP->Canvas);
            BMP = OldBMP;
            Changed();
            PaintCanvas(BMP->Canvas);
        }
        __except(EXCEPTION_EXECUTE_HANDLER)
        {
			throw EMyException("Draft create error");
        }
    }
    catch(EMyException)
    {
        BMP = OldBMP;
        Changed();
        PaintCanvas(BMP->Canvas);
    }
}

void ForceConditionTriangulation(int blue,int red,int point)
{
    TDrawView* DV = new TDrawView(Application,NULL);
    DV->debug_condition = true;
    DV->blue = blue;
    DV->red = red;
    DV->point = point;
    DV->ShowModal();
    delete DV;
}
void __fastcall TDrawView::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if (Shift.Contains(ssMiddle))
    {
        Screen->Cursor = (TCursor)crHand;
        double XTrans = -(X - OldMovePoint.x);
        double YTrans = -(OldMovePoint.y - Y);
        OldMovePoint.x = X;
        OldMovePoint.y = Y;
//        BIF->BIF_FC->SuperNode->Transformation->Rotation->incX(XRotation);
  //      BIF->BIF_FC->SuperNode->Transformation->Rotation->incZ(ZRotation);
        TimerAction(taCameraRTop,YTrans/(-10));
        TimerAction(taCameraRRight,XTrans/(-10));
        Invalidate();
  }
}
//---------------------------------------------------------------------------

void __fastcall TDrawView::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Shift.Contains(ssMiddle))
    {
        OldMovePoint.x = X;
        OldMovePoint.y = Y;
        Screen->Cursor = (TCursor)crHand;
    }
    
}
//---------------------------------------------------------------------------

void __fastcall TDrawView::FormMouseWheel(TObject *Sender,
      TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled)
{
    if (WheelDelta>0)
      TimerAction(taZoomMinus,((double)WheelDelta)/100);
    else
      TimerAction(taZoomPlus,-((double)WheelDelta)/100);
    
}
//---------------------------------------------------------------------------

