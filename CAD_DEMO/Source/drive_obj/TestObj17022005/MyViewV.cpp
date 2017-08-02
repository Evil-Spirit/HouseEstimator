//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "MyViewV.h"
#include "MyGL.h"
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
#include "math.h"
TMyView* __MyView;
//---------------------------------------------------------------------------
//-----------------------------TCameraEngine------------------------------------
TCameraEngine::TCameraEngine()
{
    A = ZEROINTVEC;
    PlaneN = TIntVec(0,0,-1);
    UsePlane = false;
}

TCameraEngine::~TCameraEngine()
{
}

void TCameraEngine::Vec2RotateZ(TVisVector& A, const TIntVec& B, MBTi Parameter)
{
    AssignVisVec(A, RotateAround(TIntVec(A),TIntVec(0,0,-Parameter),B));
}

void TCameraEngine::Vec2RotateXY(TVisVector& A, const TIntVec& B, MBTi Parameter)
{
    TIntVec RES;
	MBTi GIP = sqrtDC( pow((A.X-B.x),2) + pow((A.Y-B.y),2));
    MBTi _Angle = AngleRad( A, B, TIntVec(10,0,0)+B);
    RES = A;
    RES.x = B.x+GIP;
    RES.y = B.y;
    RES = RotateAround(RES,TIntVec(0,-Parameter/3,0),B);
    RES = RotateAround(RES,TIntVec(0,0,(_Angle*180)/M_PI),B);
    GIP = sqrtDC( pow((RES.x-B.x),2) + pow((RES.y-B.y),2));
    if (GIP<0.05 || !( (RES.x-B.x)*(A.X-B.x)>0 && (RES.y-B.y)*(A.Y-B.y)>0  ))
        RES = A;
    AssignVisVec(A, RES);
}

void TCameraEngine::Operation(TMyView* aView, TCameraOperation CO, const TIntVec& MouseObject, MBTi Parameter)
{
    TIntVec NormalCam =  ( TIntVec(*aView->View->Camera->LA_LookAt)-
        TIntVec(*aView->View->Camera->LA_Position) ).Normalize();
    switch(CO){
        case coVERTICAL_TRANSLATION:
            aView->View->Camera->LA_Position->incZ(Parameter);
        break;
        case coHORISONTAL_TRANSLATION:
        {
//            TIntVec Normal = (TIntVec(0,0,1)*NormalCam).Normalize();
            aView->A = TIntVec(*aView->View->Camera->LA_LookAt);
            aView->PlaneN = ( aView->A - TIntVec(*aView->View->Camera->LA_Position) ).Normalize();
            TIntVec MouseObj = aView->ScreenToProject(MouseObject);
            TIntVec V = aView->ScreenToProject(TIntVec(MouseObject.x+Parameter, MouseObject.y, 0));
            TIntVec Normal = MouseObj - V;
            AssignVisVec(*aView->View->Camera->LA_Position, TIntVec(*aView->View->Camera->LA_Position) + Normal );
            AssignVisVec(*aView->View->Camera->LA_LookAt, TIntVec(*aView->View->Camera->LA_LookAt) + Normal );
            aView->A = ZEROINTVEC;
            aView->PlaneN = TIntVec(0, 0, -1);
        }
        break;
        case coLA_VERTICAL_TRANSLATION:
        {
//            TIntVec Normal = (TIntVec(0,0,1)*NormalCam).Normalize();
//            Normal = (Normal*NormalCam).Normalize();
/*            TIntVec MouseScreen = aView->ProjectToScreen(MouseObject);
            TIntVec V = aView->ScreenToProject(TIntVec(MouseScreen.x, MouseScreen.y+Parameter, 0));
            TIntVec Normal = MouseObject - V;*/
            aView->A = TIntVec(*aView->View->Camera->LA_LookAt);
            aView->PlaneN = ( aView->A - TIntVec(*aView->View->Camera->LA_Position) ).Normalize();
            TIntVec MouseObj = aView->ScreenToProject(MouseObject);
            TIntVec V = aView->ScreenToProject(TIntVec(MouseObject.x, MouseObject.y+Parameter, 0));
            TIntVec Normal = MouseObj - V;
            AssignVisVec(*aView->View->Camera->LA_Position, TIntVec(*aView->View->Camera->LA_Position) + Normal );
            AssignVisVec(*aView->View->Camera->LA_LookAt, TIntVec(*aView->View->Camera->LA_LookAt) + Normal );
            aView->A = ZEROINTVEC;
            aView->PlaneN = TIntVec(0, 0, -1);
        }
        break;
		case coZ_LOOKAT_ROTATION:
        {
            Vec2RotateZ(*aView->View->Camera->LA_LookAt, TIntVec(*aView->View->Camera->LA_Position), Parameter);
        }
        break;
        case coZ_POSITION_ROTATION:
            Vec2RotateZ(*aView->View->Camera->LA_Position, TIntVec(*aView->View->Camera->LA_LookAt), Parameter);
        break;
		case coXY_LOOKAT_ROTATION:
        {
            Vec2RotateXY(*aView->View->Camera->LA_LookAt, TIntVec(*aView->View->Camera->LA_Position), Parameter);
        }
        break;
        case coXY_POSITION_ROTATION:
            Vec2RotateXY(*aView->View->Camera->LA_Position, TIntVec(*aView->View->Camera->LA_LookAt), Parameter);
        break;
        case coLA_DEPTH_TRANSLATION:
        {
            if ( IS(aView->View->Camera,__classid(TVisPerspectiveCamera)) )
            {
                MBTi BA =(TIntVec(*aView->View->Camera->LA_Position) - TIntVec(*aView->View->Camera->LA_LookAt) ).Length();
                MBTi BE =BA - (TIntVec(*aView->View->Camera->LA_Position) - TIntVec(*aView->View->Camera->LA_LookAt)).Length()/fabs(Parameter);
                TIntVec VecP = PointOfLineOnCut(TIntVec(*aView->View->Camera->LA_Position), MouseObject, (TIntVec(*aView->View->Camera->LA_Position) - MouseObject).Length()/Parameter);
                MBTi BC =(MouseObject - TIntVec(*aView->View->Camera->LA_LookAt) ).Length();
                TIntVec VecL = PointOfLineOnCut(TIntVec(*aView->View->Camera->LA_LookAt), MouseObject, (BC-BC*BE/BA)*SIGN(Parameter));
/*                if (fabs(VecP.z-VecL.z)<fabs(aView->View->Camera->ViewFar-aView->View->Camera->ViewNear))
                {*/
                    AssignVisVec(*aView->View->Camera->LA_Position, VecP);
                    AssignVisVec(*aView->View->Camera->LA_LookAt, VecL);
                //}
            }
            else
            {
                TVisOrthographicCamera* VisOrtCam = (TVisOrthographicCamera*)aView->View->Camera;
                MBTi NewWidth = (VisOrtCam->ViewWidth+VisOrtCam->ViewHeight)/(2*Parameter)+VisOrtCam->ViewWidth;
                MBTi k1 = fabs(NewWidth / VisOrtCam->ViewWidth);
                MBTi NewViewWidth = VisOrtCam->ViewWidth + (VisOrtCam->ViewWidth)/(Parameter);
                if ((NewViewWidth<20000 || Parameter<0) && (NewViewWidth>0.8 || Parameter>0))
                {
                    VisOrtCam->ViewWidth += (VisOrtCam->ViewWidth)/(Parameter);
                    VisOrtCam->ViewHeight += (VisOrtCam->ViewHeight)/(Parameter);
                    MBTi L = (TIntVec(*aView->View->Camera->LA_LookAt) - MouseObject).Length();
                    TIntVec L_Normal = (MouseObject - TIntVec(*aView->View->Camera->LA_LookAt)).Normalize();
                    AssignVisVec(*aView->View->Camera->LA_LookAt,
                        PointOfLineOnCut(TIntVec(*aView->View->Camera->LA_LookAt),
                            MouseObject,
                            -L*(k1-1))
                    );
                    AssignVisVec(*aView->View->Camera->LA_Position,
                        PointOfLineOnCut(TIntVec(*aView->View->Camera->LA_Position),
                            TIntVec(*aView->View->Camera->LA_Position)+L_Normal,
                            -L*(k1-1))
                    );
                }
/*                AssignVisVec(*aView->View->Camera->LA_Position,
                    PointOfLineOnCut(TIntVec(*aView->View->Camera->LA_Position),
                        TIntVec(*aView->View->Camera->LA_Position)+NormalCam,
                        (TIntVec(*aView->View->Camera->LA_Position)-TIntVec(*aView->View->Camera->LA_LookAt)).Length()-
                        VisOrtCam->ViewWidth/2*tan(75*M_PI/180))
                );*/
            }
        }
        break;
    }
/*    if ( IS(aView->View->Camera,__classid(TVisPerspectiveCamera)) )
    {
    }*/
}

void TCameraEngine::Toggle(TMyView* aView)
{
    if (aView->View->Camera == aView->VisOrtCam)
        aView->View->Camera = aView->VisPerspCam;
    else
        aView->View->Camera = aView->VisOrtCam;
}
//-----------------------------TCameraEngine------------------------------------



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
	if ( !View->Current )
		View->Current = true;
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
	if ( !View->Current )
		View->Current = true;
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
	VisLight->Transformation->Translation->Assign(aView->Camera->LA_Position);
	VisLight->Render(aView);
//	VisLight1->Render(aView);
	if (EditorRender)
		EditorRender(aView);
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
		if ( Shift.Contains(ssAlt) )
			CameraEngine.Operation(this,coLA_DEPTH_TRANSLATION,ScreenToProject( View->Width/2, View->Height/2, 0),-MBTi(WheelDelta)/2);
		else
			CameraEngine.Operation(this,coLA_DEPTH_TRANSLATION,ScreenToProject(MousePos.x, MousePos.y, 0),-MBTi(WheelDelta));
		View->InvalidateGL();
		A = ZEROINTVEC;
		PlaneN = TIntVec(0,0,-1);
	}
	if (EditorMouseWheel)
		EditorMouseWheel(Sender, Shift, WheelDelta, MousePos, Handled);
}
//---------------------------------------------------------------------------

void __fastcall TMyView::ViewMouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
//    if (EditorControls == NULL)
  //      return;
	A = TIntVec(*View->Camera->LA_LookAt);
	PlaneN = ( A - TIntVec(*View->Camera->LA_Position) ).Normalize();
/*	if (Shift.Contains(ssAlt))
	{
		if ( Button == mbLeft )
				CameraEngine.Operation(this,coLA_DEPTH_TRANSLATION,ScreenToProject( View->Width/2, View->Height/2, 0), 10);			
		if ( Button == mbRight )
				CameraEngine.Operation(this,coLA_DEPTH_TRANSLATION,ScreenToProject( View->Width/2, View->Height/2, 0), -10);			
	}*/
	A = ZEROINTVEC;
	PlaneN = TIntVec(0,0,-1);
	if (EditorMouseDown)
		EditorMouseDown(Sender, Button, Shift, X, Y);
}
//---------------------------------------------------------------------------

void __fastcall TMyView::ViewMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
//    if (EditorControls == NULL)
  //      return;
	if (EditorMouseUp)
		EditorMouseUp(Sender, Button, Shift, X, Y);
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
        WheelDelta = -10;
    }
    if (Key == VK_SUBTRACT )
    {
        WheelDelta = 10;
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
	if (EditorKeyDown)
		EditorKeyDown(Sender, Key, Shift);
}
//---------------------------------------------------------------------------

void __fastcall TMyView::ViewKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
//    if (EditorControls == NULL)
  //      return;
	if (EditorKeyUp)
		EditorKeyUp( Sender, Key, Shift);
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
	if ( ::GetFocus() != Handle )
		::SetFocus(Handle);
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
		if (Shift.Contains(ssAlt))
		{
			CameraEngine.Operation(this, coXY_LOOKAT_ROTATION,ScreenToProject(X, Y, 0), -MBTi(Y-OldPoint.y)/3);
			CameraEngine.Operation(this, coZ_LOOKAT_ROTATION,ScreenToProject(X, Y, 0), MBTi(X-OldPoint.x)/3);
			View->InvalidateGL();
		}
		else 
			if (Shift.Contains(ssMiddle))
			{
				if (Shift.Contains(ssRight))
				{
					CameraEngine.Operation(this, coZ_POSITION_ROTATION,ScreenToProject(X, Y, 0), MBTi(X-OldPoint.x)*0.5);
					CameraEngine.Operation(this, coXY_POSITION_ROTATION,ScreenToProject(X, Y, 0), MBTi(Y-OldPoint.y));
				}
				else
				{
					CameraEngine.Operation(this, coHORISONTAL_TRANSLATION,ScreenToProject(X, Y, 0)/*ScreenToProject(X, Y, 0)*/, X-OldPoint.x);
					CameraEngine.Operation(this, coLA_VERTICAL_TRANSLATION,ScreenToProject(X, Y, 0)/*ScreenToProject(X, Y, 0)*/, Y-OldPoint.y);
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
	if (EditorMouseMove)
		EditorMouseMove(Sender, Shift, X, Y);
/*	if (Shift.Contains(ssAlt))
	{	
		Mouse->
		TPoint MP = View->ClientToScreen(TPoint(View->Width/2, View->Height/2));
		SetCursorPos(MP.x, MP.y);
	}*/
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






