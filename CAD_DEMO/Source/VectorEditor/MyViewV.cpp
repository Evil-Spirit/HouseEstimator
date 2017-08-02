//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "MyViewV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VisCanvasView"
#pragma link "VisClass"
#pragma link "VisView"
#pragma link "VisAttr"
#pragma link "VisCam"
#pragma link "VisComp"
#pragma link "VisLight"
#pragma resource "*.dfm"
#include "EditorV.h"
#include "MyEdit.h"
#include "math.h"
TMyView* __MyView;
//---------------------------------------------------------------------------
__fastcall TMyView::TMyView(TComponent* Owner)
    : TForm(Owner)
{
    A = TIntVec(0,0,0);
    PlaneN = TIntVec(0,0,-1);
    CameraAction = 0;
}
void TMyView::WinFrom3D(const TIntVec& P1,TIntVec& RES)
{
    TVisMathVector V;
    gluProject(P1.x,P1.y,P1.z,ModMat,ProjMat,ViewPort,V.x,V.y,V.z);
    RES.x = V.x;
    RES.y = (ViewPort[3]-ViewPort[1])-V.y;
    RES.z = V.z;
}

bool TMyView::WinTo3D(int X,int Y,double value,TIntVec& RES)
{
    GLdouble  px,py,pz;
    GLint really;
    bool returned=false;
    really = ViewPort[3] - (GLint)Y-1;
    if (gluUnProject((GLdouble)X,(GLdouble)really,value,ModMat,ProjMat,ViewPort,&px,&py,&pz)==GL_TRUE)
        returned=true;
    RES.x = px;
    RES.y = py;
    RES.z = pz;
    return(returned);
}

TIntVec TMyView::ScreenToProject(MBTi x, MBTi y, MBTi z)
{
    glGetDoublev(GL_PROJECTION_MATRIX,ProjMat);
    glGetIntegerv(GL_VIEWPORT,ViewPort);
    glGetDoublev(GL_MODELVIEW_MATRIX,ModMat);
    TIntVec P1, P2;
    WinTo3D( floor(x), floor(y), 0.2, P1);
    WinTo3D( floor(x), floor(y), 0.6, P2);
    TIntVec Res;
    PlaneCrossPoint( A, PlaneN, P1, P2, Res);
/*    TIntVec RES;
    WinFrom3D(Res,RES);*/
    return Res;

}

TIntVec TMyView::ScreenToProject(const TIntVec& V)
{
    return  ScreenToProject(V.x, V.y, V.z);
}

TIntVec TMyView::ProjectToScreen(const TIntVec& Vv)
{
    glGetDoublev(GL_PROJECTION_MATRIX,ProjMat);
    glGetIntegerv(GL_VIEWPORT,ViewPort);
    glGetDoublev(GL_MODELVIEW_MATRIX,ModMat);
    TIntVec Res;
    WinFrom3D(Vv, Res);
    return Res;
}

void __fastcall TMyView::ViewRender(TVisView *aView)
{
//    if (EditorControls == NULL)
  //      return;
    VisAttributes->Render(aView);
    VisLight->Render(aView);
    Editor2D->EditorRender(aView);
}
//---------------------------------------------------------------------------

void __fastcall TMyView::ViewMouseWheel(TObject *Sender, TShiftState Shift,
      int WheelDelta, TPoint &MousePos, bool &Handled)
{
//    if (EditorControls == NULL)
  //      return;
    if (CameraAction == 0)
    {
        A = TIntVec(*View->Camera->LA_LookAt);
        PlaneN = ( A - TIntVec(*View->Camera->LA_Position) ).Normalize();
        MousePos = View->ScreenToClient(MousePos);
        CameraEngine.Operation(this,coLA_DEPTH_TRANSLATION,ScreenToProject(MousePos.x, MousePos.y, 0),-MBTi(WheelDelta)/9);
        View->InvalidateGL();
        A = ZEROINTVEC;
        PlaneN = TIntVec(0,0,-1);
    }
    Editor2D->EditorMouseWheel(Sender, Shift, WheelDelta, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TMyView::ViewMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//    if (EditorControls == NULL)
  //      return;
    if ( Button == mbRight && Shift.Contains(ssMiddle) )
        return; 
    Editor2D->EditorMouseDown(Sender, Button, Shift, X, Y);
}
//---------------------------------------------------------------------------

void __fastcall TMyView::ViewMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
//    if (EditorControls == NULL)
  //      return;
    Editor2D->EditorMouseUp(Sender, Button, Shift, X, Y);
}
//---------------------------------------------------------------------------

void __fastcall TMyView::ViewKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
//    if (EditorControls == NULL)
  //      return;
    MBTi WheelDelta = 0;
    if (Key == VK_ADD )
    {
        WheelDelta = 10;
    }
    if (Key == VK_SUBTRACT )
    {
        WheelDelta = -10;
    }
    if (WheelDelta != 0)
    {
        A = TIntVec(*View->Camera->LA_LookAt);
        PlaneN = ( A - TIntVec(*View->Camera->LA_Position) ).Normalize();
        TPoint MousePos = View->ScreenToClient(Mouse->CursorPos);
        CameraEngine.Operation(this,coLA_DEPTH_TRANSLATION,ScreenToProject(MousePos.x, MousePos.y, 0),-MBTi(WheelDelta));
        View->InvalidateGL();
        A = ZEROINTVEC;
        PlaneN = TIntVec(0,0,-1);
    }
    Editor2D->EditorKeyDown(Sender, Key, Shift);
}
//---------------------------------------------------------------------------

void __fastcall TMyView::ViewKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
//    if (EditorControls == NULL)
  //      return;
    Editor2D->EditorKeyUp( Sender, Key, Shift);
}
//---------------------------------------------------------------------------

/*void __fastcall TMyView::Resize(TObject *Sender)
{
    Grid.Attr.ReBuild = true;
    View->InvalidateGL();
}*/
//---------------------------------------------------------------------------

void __fastcall TMyView::ViewMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
//    if (EditorControls == NULL)
  //      return;
    TPoint P(X,Y);
    A = TIntVec(*View->Camera->LA_LookAt);
    PlaneN = ( A - TIntVec(*View->Camera->LA_Position) ).Normalize();


    TIntVec ChangeX = ScreenToProject(TIntVec(X,0,0)) -
    ScreenToProject(TIntVec(OldPoint.x,0,0));

    TIntVec ChangeY = ScreenToProject(TIntVec(0,Y,0)) -
    ScreenToProject(TIntVec(0,OldPoint.y,0));

    if (CameraAction == 0)
    {

        if (Shift.Contains(ssMiddle))
        {
            if (Shift.Contains(ssRight))
            {
                CameraEngine.Operation(this, coZ_POSITION_ROTATION,ScreenToProject(X, Y, 0), MBTi(X-OldPoint.x)*0.5);
                CameraEngine.Operation(this, coXY_POSITION_ROTATION,ScreenToProject(X, Y, 0), MBTi(Y-OldPoint.y));
            }
            else
            {
                CameraEngine.Operation(this, coHORISONTAL_TRANSLATION,TIntVec(X, Y, 0)/*ScreenToProject(X, Y, 0)*/, X-OldPoint.x);
                CameraEngine.Operation(this, coLA_VERTICAL_TRANSLATION,TIntVec(X, Y, 0)/*ScreenToProject(X, Y, 0)*/, Y-OldPoint.y);
            }
            View->InvalidateGL();
        }
    }else
        if (Shift.Contains(ssLeft))
        {
            if (CameraAction == 1)
            {
                CameraEngine.Operation(this, coHORISONTAL_TRANSLATION,TIntVec(X, Y, 0), X-OldPoint.x);
                CameraEngine.Operation(this, coLA_VERTICAL_TRANSLATION,TIntVec(X, Y, 0), Y-OldPoint.y);
            }else
                if (CameraAction == 2)
                {
                    CameraEngine.Operation(this, coZ_POSITION_ROTATION,ScreenToProject(X, Y, 0), MBTi(X-OldPoint.x)*0.5);
                    CameraEngine.Operation(this, coXY_POSITION_ROTATION,ScreenToProject(X, Y, 0), MBTi(Y-OldPoint.y));
                }
            View->InvalidateGL();
        }
    OldPoint.x = X;
    OldPoint.y = Y;
    A = ZEROINTVEC;
    PlaneN = TIntVec(0,0,-1);
    Editor2D->EditorMouseMove(Sender, Shift, X, Y);
}

MBTi TMyView::Factor(int Pixels)
{
    A = TIntVec(*View->Camera->LA_LookAt);
    PlaneN = ( A - TIntVec(*View->Camera->LA_Position) ).Normalize();
    MBTi RES = (ScreenToProject(0,0,0)-ScreenToProject(Pixels,0,0)).Length();
    A = ZEROINTVEC;
    PlaneN = TIntVec(0, 0, 1);
    return RES; 
}


void __fastcall TMyView::IdleActionExecute(TObject *Sender)
{
    CameraAction = 0;
}
//---------------------------------------------------------------------------

void __fastcall TMyView::MoveActionExecute(TObject *Sender)
{
    CameraAction = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMyView::RotateActionExecute(TObject *Sender)
{
    CameraAction = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMyView::ActionListUpdate(TBasicAction *Action,
      bool &Handled)
{
    if (Action == IdleAction)
    {
        IdleAction->Checked = (CameraAction == 0);
        Handled = true;
    }
    else if (Action == MoveAction)
    {
        MoveAction->Checked = (CameraAction == 1);
        Handled = true;
    }
    else if (Action == RotateAction)
    {
        RotateAction->Checked = (CameraAction == 2);
        Handled = true;
    }
    else
        Handled = true;

}
//---------------------------------------------------------------------------



