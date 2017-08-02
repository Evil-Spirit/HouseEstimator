  //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDI3DV.h"
//#include "MDITransformationV.h"
#include "MyGL.h"
#include "World.h"
#include "ElementV.h"
#include "TasksQueueV.h"
#include "AUIV.h"
#include "MySupportV.h"
#include "Select.h"
#include "SkinEngineV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MyMDIChildV"
#pragma link "VisCam"
#pragma link "VisCanvasView"
#pragma link "VisClass"
#pragma link "VisComp"
#pragma link "VisView"
#pragma link "VisAttr"
#pragma link "VisLight"
#pragma link "VisMat"
#pragma link "VisObj"
#pragma link "VisPrimitiveObj"
#pragma link "VisShape"
#pragma link "VisGeom"
#pragma link "VisTex"
#pragma resource "*.dfm"
TMDI3D *MDI3D;
//---------------------------------------------------------------------------
__fastcall TMDI3D::TMDI3D(TComponent* Owner,TMainTree* MT)
    : TMyMDIChild(Owner)
{
    SkinEngine->AddForm_BCB(this);
    ViewSet2D.NetSize = TIntVec(144,144,0.02);
    ViewSet3D.NetSize = CalculatePlatformSize();
    MyMT = MT;
    AUI.Register(MyMT,this);
    AUI.ActivateView(this);
    InvalidateTextures();
    _2DCamera->LA_UpNormal->X = -1;
    _2DCamera->LA_UpNormal->Y = 0;
    _2DCamera->LA_UpNormal->Z = 0;

    _2DCamera->LA_LookAt->X = 0;
    _2DCamera->LA_LookAt->Y = 0;
    _2DCamera->LA_LookAt->Z = 0;

    _2DCamera->LA_Position->X = 0;
    _2DCamera->LA_Position->Y = 0;
    _2DCamera->LA_Position->Z = 100;

/*    _3DCamera->LA_UpNormal->X = 0;
    _3DCamera->LA_UpNormal->Y = 0;
    _3DCamera->LA_UpNormal->Z = 1;

    _3DCamera->LA_LookAt->X = 0;
    _3DCamera->LA_LookAt->Y = 0;
    _3DCamera->LA_LookAt->Z = 0;*/

    _3DCamera->LA_Position->X = 10;
    _3DCamera->LA_Position->Y = -10;
    _3DCamera->LA_Position->Z = 12;

    //MyMT->RegisterClient(this);

//    BIF->FirstInit(this,MyMT);
}
//---------------------------------------------------------------------------
void TMDI3D::SaveValues()
{
    OldMode = FMode;
    Old3DCameraPos->Assign(_3DCamera->LA_Position);

    Old2DCameraPos->Assign(_2DCamera->Transformation->Translation);

    Old2DWidth = _2DCamera->ViewWidth;
    Old2DHeight = _2DCamera->ViewHeight;

    OldWidth = View->Width;
    OldHeight = View->Height;
}

bool TMDI3D::NeedToReCalcMatrices()
{
    if (FMode!=OldMode)
        return true;
    if ( View->Camera == _3DCamera )
    {
        if ( !VisVectorsEqual(_3DCamera->LA_Position,Old3DCameraPos) )
            return true;
    }
    else
    {
        if ( !VisVectorsEqual(_2DCamera->LA_Position,Old2DCameraPos) )
            return true;
        if ( _2DCamera->ViewHeight != Old2DHeight || _2DCamera->ViewWidth != Old2DWidth )
            return true;
    }
    if ( View->Width != OldWidth || View->Height != OldHeight)
        return true;
    return false;
}

void TMDI3D::WinFrom3D(const TVisMathVector& P1,TVisMathVector& RES)
{
    gluProject(P1.x,P1.y,P1.z,modmat,projmat,viewport,RES.x,RES.y,RES.z);
    RES.y = (viewport[3]-viewport[1])-RES.y;
}

void TMDI3D::WinFrom3D(const TIntVec& P1,TIntVec& RES)
{
    TVisMathVector V;
    gluProject(P1.x,P1.y,P1.z,modmat,projmat,viewport,V.x,V.y,V.z);
    RES.x = V.x;
    RES.y = (viewport[3]-viewport[1])-V.y;
    RES.z = V.z;
}

void TMDI3D::WinFrom3D(const TVisMathVector& P1,TIntVec& RES)
{
    TVisMathVector V;
    gluProject(P1.x,P1.y,P1.z,modmat,projmat,viewport,V.x,V.y,V.z);
    RES.x = V.x;
    RES.y = (viewport[3]-viewport[1])-V.y;
    RES.z = V.z;
}

void TMDI3D::WinFrom3D(const TVisVector* P1,TIntVec& RES)
{
    TVisMathVector V;
    gluProject(P1->X,P1->Y,P1->Z,modmat,projmat,viewport,V.x,V.y,V.z);
    RES.x = V.x;
    RES.y = (viewport[3]-viewport[1])-V.y;
    RES.z = V.z;
}

bool TMDI3D::GetPoint(int X,int Y,TIntVec& RES)
{
    GLdouble  px,py,pz;
    GLfloat value;
    GLint really;
    bool returned=false;
    really = viewport[3] - (GLint)Y-1;
    GLint mode;
    glGetIntegerv(GL_READ_BUFFER, &mode);
    glReadBuffer(GL_FRONT);
    glReadPixels((GLint)X,really,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&value);
    if (value!=1)
        if (gluUnProject((GLdouble)X,(GLdouble)really,value,modmat,projmat,viewport,&px,&py,&pz)==GL_TRUE)
        {
            returned=true;
            RES.x = px;
            RES.y = py;
            RES.z = pz;
        }
    glReadBuffer(mode);
    return(returned);
}

bool TMDI3D::WinTo3D(int X,int Y,double value,TIntVec& RES)
{
    GLdouble  px,py,pz;
    GLint really;
    bool returned=false;
    really = viewport[3] - (GLint)Y-1;
    if (gluUnProject((GLdouble)X,(GLdouble)really,value,modmat,projmat,viewport,&px,&py,&pz)==GL_TRUE)
        returned=true;
    RES.x = px;
    RES.y = py;
    RES.z = pz;
    return(returned);
}

TIntVec TMDI3D::ScreenToProject(MBTi x, MBTi y, MBTi z)
{
    TIntVec P1, P2;
    WinTo3D( floor(x), floor(y), 0.2, P1);
    WinTo3D( floor(x), floor(y), 0.6, P2);
    TIntVec Res;
    PlaneCrossPoint( A, PlaneN, P1, P2, Res);
    return Res;

}

TIntVec TMDI3D::ScreenToProject(const TIntVec& V)
{
    return  ScreenToProject(V.x, V.y, V.z);
}

TIntVec TMDI3D::ProjectToScreen(const TIntVec& Vv)
{
    TIntVec Res;
    WinFrom3D(Vv, Res);
    return Res;
}

MBTi TMDI3D::Factor(int Pixels)
{
    A = TIntVec(*View->Camera->LA_LookAt);
    PlaneN = ( A - TIntVec(*View->Camera->LA_Position) ).Normalize();
    MBTi RES = (ScreenToProject(0,0,0)-ScreenToProject(Pixels,0,0)).Length();
    A = ZEROINTVEC;
    PlaneN = TIntVec(0, 0, 1);
    return RES; 
}

void __fastcall TMDI3D::ViewRender(TVisView *aView)
{
    bool NeedToRecalc = NeedToReCalcMatrices();
    if (NeedToRecalc && !View->AutoClearBuffers.Contains(btDepth) )
        View->ClearBuffers( TVisBufferType()<<btDepth<<btColor );
    if (this != AUI.ActiveView)
        return;
    if (World && World->load)
        return;
    if (AUI.ActiveWorld && AUI.ActiveWorld->ModeIndex !=  MetaNodeCollection->KernelSupport->Modes.IndexOf(Mode))
        AUI.ActiveWorld->UpdateMode();
        
    TaskQueue.ActionCame();

    if (NeedToRecalc)
    {
        Light0->Transformation->Translation->Assign(aView->Camera->LA_Position);
        glGetDoublev(GL_PROJECTION_MATRIX,projmat);
        glGetIntegerv(GL_VIEWPORT,viewport);
        glGetDoublev(GL_MODELVIEW_MATRIX,modmat);
        SaveValues();
    }

    Attributes->Render(aView);
    Light0->Render(aView);
    CustomRender(aView);

    GetPoint(WinPoint.x,WinPoint.y,GettedPoint);

    NeedRender = false;
}
//---------------------------------------------------------------------------
 
void TMDI3D::CameraAction(TCameraOperation CameraOperation,double value)
{
    CameraEngine.Operation(this,CameraOperation,value);
    View->InvalidateGL();
}

void __fastcall TMDI3D::ViewMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    WinPoint.x = X;
    WinPoint.y = Y;
    if (Shift.Contains(ssMiddle))
    {
        OldMovePoint.x = X;
        OldMovePoint.y = Y;
        Screen->Cursor = (TCursor)crHand;
    }
    else
        CustomMouseDown(Button, Shift,  X,  Y);
}
//---------------------------------------------------------------------------

void __fastcall TMDI3D::ViewMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    if (Shift.Contains(ssMiddle))
    {
        if (Shift.Contains(ssRight))
        {
            if ( View->Camera == _3DCamera ) {
                CameraEngine.Operation(this, coZ_POSITION_ROTATION, MBTi(X-OldMovePoint.x)*0.5);
                CameraEngine.Operation(this, coXY_POSITION_ROTATION, MBTi(Y-OldMovePoint.y));
            }
        }
        else
        {
            CameraEngine.Operation(this, coHORISONTAL_TRANSLATION, MBTi(X-OldMovePoint.x) );
            CameraEngine.Operation(this, coLA_VERTICAL_TRANSLATION, MBTi(Y-OldMovePoint.y) );
        }
        OldMovePoint.x = X;
        OldMovePoint.y = Y;
        AUI.InvalidateView();
    }
    else
    {
        OldMovePoint.x = X;
        OldMovePoint.y = Y;
        //------------------------------------
        if (NeedRender)
        {
            AUI.InvalidateView();
            return;
        }
        CustomMouseMove(Shift,  X,  Y);
        NeedRender = true;
        //------------------------------------
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDI3D::ViewMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    CustomMouseUp(Button, Shift,  X,  Y);
}
//---------------------------------------------------------------------------

void TMDI3D::ToggleCamera()
{
    if (View->Camera == _3DCamera)
    {
        View->Camera = _2DCamera;
        Attributes->Lighting = false;
    }
    else
    {
        View->Camera = _3DCamera;
        Attributes->Lighting = true;
    }
}

void TMDI3D::TogglePolygonMode()
{
    if (Attributes->PolygonMode == pmFill)
        Attributes->PolygonMode = pmLine;
    else
        Attributes->PolygonMode = pmFill;          
}

void __fastcall TMDI3D::ViewKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  switch(Key)
  {
    case char(37):          if ( View->Camera == _3DCamera )
                                CameraAction(coZ_POSITION_ROTATION,-15);
            break;
    case char(38):          if ( View->Camera == _3DCamera )
                                CameraAction(coXY_POSITION_ROTATION,15);        
            break;
    case char(39):          if ( View->Camera == _3DCamera )
                                CameraAction(coZ_POSITION_ROTATION,15);
            break;
    case char(40):          if ( View->Camera == _3DCamera )
                                CameraAction(coXY_POSITION_ROTATION,-15);
            break;
    case char(100):         CameraAction(coHORISONTAL_TRANSLATION,-15);     break;
    case char(104):         CameraAction(coLA_VERTICAL_TRANSLATION,15);     break;
    case char(102):         CameraAction(coHORISONTAL_TRANSLATION,15);      break;
    case char(98):          CameraAction(coLA_VERTICAL_TRANSLATION,-15);    break;
    case char(VK_ADD):      CameraAction(coLA_DEPTH_TRANSLATION,15);        break;
    case char(VK_SUBTRACT): CameraAction(coLA_DEPTH_TRANSLATION,-15);       break;
    case char(VK_F1	):
    {
        if ( MySelection.Count )
            MySelection.GetElement(0)->Edit(Application,NULL,NULL);
    }break;
    default:
        CustomKeyDown(Key,Shift);
    break;
  }
}

void __fastcall TMDI3D::FormClose(TObject *Sender, TCloseAction &Action)
{
    TMyMDIChild::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------
void TMDI3D::SetMode(TMetaMyMode *nMode)
{
  if (nMode!=FMode)
  {

    if(nMode && nMode->CAM == camOrthographic)
    {
      CurSet = &ViewSet2D;
      View->Camera = _2DCamera;
        Attributes  = Attr2D;
//      Attributes->Lighting = false;
    }
    else
    {
      CurSet = &ViewSet3D;
        Attributes  = Attr3D;
      View->Camera = _3DCamera;
//      Attributes->Lighting = true;
    }
    FMode = nMode;
        View->BackgroundColor = CurSet->BackColor;
        View->Color = CurSet->BackColor;
  }
}

void __fastcall TMDI3D::ViewMouseWheel(TObject *Sender, TShiftState Shift,
      int WheelDelta, TPoint &MousePos, bool &Handled)
{
    A = TIntVec(*View->Camera->LA_LookAt);
    PlaneN = ( A - TIntVec(*View->Camera->LA_Position) ).Normalize();
    MousePos = View->ScreenToClient(MousePos);
    CameraEngine.Operation(this,coLA_DEPTH_TRANSLATION,-MBTi(WheelDelta)/9);
    AUI.InvalidateView();
}
//---------------------------------------------------------------------------

void __fastcall TMDI3D::FormDestroy(TObject *Sender)
{
    AUI.UnRegister(this);
    delete Old3DCameraPos;
    delete Old2DCameraPos;
}
//---------------------------------------------------------------------------

void __fastcall TMDI3D::FormActivate(TObject *Sender)
{
    ::SetFocus(View->Handle);
    AUI.ActivateView(this);
}
//---------------------------------------------------------------------------


void __fastcall TMDI3D::FormCreate(TObject *Sender)
{
    AntiAliasingLine = false;
    NeedRender = true;
    
    Old3DCameraPos = new TVisVector();
    TMetaMyMode *OldMode;
    Old2DCameraPos = new TVisVector();

    Attributes  = Attr2D;
    ViewSet2D.BackColor = (TColor)0x00574E46;
    ViewSet2D.NetColor = clGray;
    ViewSet2D.NetLine = nLine;
    ViewSet2D.STEP = 0.3;

    ViewSet3D.BackColor = (TColor)0x00C7A278;//0x00EC922D;//0x00A99E96; //0x008D7E72
    ViewSet3D.NetColor = clGray;
    ViewSet3D.NetLine = nLine;
    ViewSet3D.STEP = 1.2;
    CurSet = &ViewSet3D;
}
//---------------------------------------------------------------------------


void __fastcall TMDI3D::ViewKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    CustomKeyUp(Key,Shift);
}
//---------------------------------------------------------------------------

