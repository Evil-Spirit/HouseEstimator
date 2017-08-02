 //---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "CameraEngineV.h"
#include "MetaClasses.h"
#include "ElementV.h"
#include "MDI3DV.h"
#include "UNDO.h"
#include "World.h"
#include "math.h"
#include "AUIV.h"
#include "MyGL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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

void TCameraEngine::Operation(TMDI3D* aView, TCameraOperation CO, MBTi Parameter)
{

    TPoint MousePoint = aView->View->ScreenToClient( Mouse->CursorPos );

    aView->A = TIntVec(*aView->View->Camera->LA_LookAt);
    aView->PlaneN = ( A - TIntVec(*aView->View->Camera->LA_Position) ).Normalize();
    TIntVec MouseObject = aView->ScreenToProject( TIntVec(MousePoint.x,MousePoint.y,0) );
    
    TIntVec NormalCam = aView->PlaneN;
    switch(CO){
        case coVERTICAL_TRANSLATION:
            aView->View->Camera->LA_Position->incZ(Parameter);
        break;
        case coHORISONTAL_TRANSLATION:
        {
//            TIntVec Normal = (TIntVec(0,0,1)*NormalCam).Normalize();
            aView->A = TIntVec(*aView->View->Camera->LA_LookAt);
            aView->PlaneN = ( aView->A - TIntVec(*aView->View->Camera->LA_Position) ).Normalize();
            TIntVec V0 = aView->ScreenToProject(TIntVec(0,0,0));
            TIntVec V = aView->ScreenToProject(TIntVec(Parameter,0,0));
            TIntVec Normal = V0 - V;
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
            TIntVec V0 = aView->ScreenToProject(TIntVec(0,0,0));
            TIntVec V = aView->ScreenToProject(TIntVec(0,Parameter,0));
            TIntVec Normal = V0 - V;
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
                if ( (TIntVec(*aView->View->Camera->LA_Position) - MouseObject).Length() > 0.0005 ) {
                    TIntVec VecP = PointOfLineOnCut(TIntVec(*aView->View->Camera->LA_Position), MouseObject, (TIntVec(*aView->View->Camera->LA_Position) - MouseObject).Length()/Parameter);
                    MBTi BC =(MouseObject - TIntVec(*aView->View->Camera->LA_LookAt) ).Length();
                    if ( (TIntVec(*aView->View->Camera->LA_LookAt) - MouseObject).Length() > 0.0005 ) {
                        TIntVec VecL = PointOfLineOnCut(TIntVec(*aView->View->Camera->LA_LookAt), MouseObject, (BC-BC*BE/BA)*SIGN(Parameter));
                        if ( (VecP-VecL).Length() > 0.05 && (VecP-VecL).Length() < 500 )
                        {
                            AssignVisVec(*aView->View->Camera->LA_Position, VecP);
                            AssignVisVec(*aView->View->Camera->LA_LookAt, VecL);
                        }
                    }
                }
            }
            else
            {
                TVisOrthographicCamera* VisOrtCam = (TVisOrthographicCamera*)aView->View->Camera;
                MBTi NewWidth = (VisOrtCam->ViewWidth+VisOrtCam->ViewHeight)/(2*Parameter)+VisOrtCam->ViewWidth;
                MBTi k1 = fabs(NewWidth / VisOrtCam->ViewWidth);
                MBTi NewViewWidth = VisOrtCam->ViewWidth + (VisOrtCam->ViewWidth)/(Parameter);
//                if ((NewViewWidth<20000 || Parameter<0) && (NewViewWidth>0.8 || Parameter>0))
                if ((NewViewWidth<250 || Parameter<0) && (NewViewWidth>0.8 || Parameter>0))
                {
                    VisOrtCam->ViewWidth += (VisOrtCam->ViewWidth)/(Parameter);
                    VisOrtCam->ViewHeight += (VisOrtCam->ViewHeight)/(Parameter);
                    MBTi L = (TIntVec(*aView->View->Camera->LA_LookAt) - MouseObject).Length();
                    TIntVec L_Normal = (MouseObject - TIntVec(*aView->View->Camera->LA_LookAt)).Normalize();
                    if ( (TIntVec(*aView->View->Camera->LA_LookAt) - MouseObject).Length() > 0.0005 ) {
                        TIntVec tmpVecL = PointOfLineOnCut(TIntVec(*aView->View->Camera->LA_LookAt), MouseObject, -L*(k1-1));
                        if ( (TIntVec(*aView->View->Camera->LA_Position) - TIntVec(*aView->View->Camera->LA_Position)+L_Normal).Length() > 0.0005 ) {
                            TIntVec tmpVecP = PointOfLineOnCut(TIntVec(*aView->View->Camera->LA_Position), TIntVec(*aView->View->Camera->LA_Position)+L_Normal, -L*(k1-1));
                            AssignVisVec(*aView->View->Camera->LA_LookAt, tmpVecL);
                            AssignVisVec(*aView->View->Camera->LA_Position, tmpVecP);
                        }
                    }
                }
            }
        }
        break;
        case coLA_DEPTH_TRANSLATION_NO_ORIENT:
        {
            if ( IS(aView->View->Camera,__classid(TVisPerspectiveCamera)) )
            {
                MBTi BA =(TIntVec(*aView->View->Camera->LA_Position) - TIntVec(*aView->View->Camera->LA_LookAt) ).Length();
                TIntVec VecP = PointOfLineOnCut (TIntVec(*aView->View->Camera->LA_Position),TIntVec(*aView->View->Camera->LA_LookAt),BA/(Parameter) );
                TIntVec VecL = *aView->View->Camera->LA_LookAt;
                if ( (VecP-VecL).Length() > 0.05 && (VecP-VecL).Length() < 500 )
                {
                    AssignVisVec(*aView->View->Camera->LA_Position, VecP);
                }
            }
            else
            {
                TVisOrthographicCamera* VisOrtCam = (TVisOrthographicCamera*)aView->View->Camera;
                MBTi NewViewWidth = VisOrtCam->ViewWidth + (VisOrtCam->ViewWidth)/(Parameter);
//                if ((NewViewWidth<20000 || Parameter<0) && (NewViewWidth>0.8 || Parameter>0))
                if ((NewViewWidth<250 || Parameter<0) && (NewViewWidth>0.8 || Parameter>0))
                {
                    VisOrtCam->ViewWidth += (VisOrtCam->ViewWidth)/(Parameter);
                    VisOrtCam->ViewHeight += (VisOrtCam->ViewHeight)/(Parameter);
                }
            }
        }
        break;
    }
}

void TCameraEngine::Toggle(TMDI3D* aView)
{
    if (aView->View->Camera == aView->_2DCamera)
        aView->View->Camera = aView->_3DCamera;
    else
        aView->View->Camera = aView->_2DCamera;
}
//-----------------------------TCameraEngine------------------------------------
void TCameraEngine::ViewAll(TVisCamera *Camera, bool No_Platforms_And_FirstFloorElem)
{
    if (! AUI.ActiveView )
        return;
    TIntVec LOW=TIntVec(1<<30,1<<30,1<<30);
    TIntVec HI = LOW*(-1);
    AUI.ActiveWorld->LOW_HI(LOW, HI,No_Platforms_And_FirstFloorElem,NULL,true);
    if (LOW == TIntVec(1<<30,1<<30,1<<30))
        return;
    TIntVec Aver = (LOW+HI)/2;
    TIntVec Range = HI - LOW;
    TIntVec AddCamera = TIntVec(Camera->Transformation->Translation->AsMathVector)*(-1);
    if (Camera->ClassType()==__classid(TVisOrthographicCamera))
    {
        TVisOrthographicCamera* OC = (TVisOrthographicCamera*)Camera;
//        Camera->Transformation->Translation->X = 0;
  //      Camera->Transformation->Translation->Y = 0;
/*      double VVHeight = (double)BIF->VisView->Height;
        double VVWidth = (double)BIF->VisView->Width;
        double RangeX = Range.x;
        double RangeY = Range.y;

        double _range = sqrtDC(RangeX*RangeX +RangeY*RangeY);

        if ( (VVHeight/VVWidth)<(RangeX/RangeY) )
            _range = RangeY;
        else
            _range = RangeX; */

/*        Aver.z = 0;
        Head->UserChangePosition(   MINUSINTVEC*Aver,
                                    ZEROINTVEC);*/
        Aver.z = 200;
        Aver *= -1;
        AssignVisVec(*(Camera->Transformation->Translation),Aver);

        TIntVec Center = (HI+LOW)/2;
        OC->LA_LookAt->X = Center.x;
        OC->LA_LookAt->Y = Center.y;
        OC->LA_LookAt->Z = Center.z;
        OC->LA_Position->X = Center.x;
        OC->LA_Position->Y = Center.y;
        OC->ViewHeight = MAX(Range.x,Range.y);
        OC->ViewWidth = MAX(Range.x,Range.y);
    }
    if (Camera->ClassType()==__classid(TVisPerspectiveCamera))
    {

        TVisPerspectiveCamera* PC = (TVisPerspectiveCamera*)Camera;
        if (PC->ViewAngle!=0 && PC->ViewAngle!=90)
        {
            TIntVec Center = (HI+LOW)/2;
//            double oldSize = (HI-Center).Length();
            TIntVec MoveVector = Center - TIntVec(PC->LA_LookAt->AsMathVector);
            TIntVec NewViewAt0 = TIntVec(PC->LA_Position->AsMathVector)+MoveVector;

            TIntVec P[9];
            P[0] = TIntVec(LOW.x,LOW.y,LOW.z);
            P[1] = TIntVec(LOW.x,LOW.y,HI.z);
            P[2] = TIntVec(LOW.x,HI.y,LOW.z);
            P[3] = TIntVec(LOW.x,HI.y,HI.z);
            P[4] = TIntVec(HI.x,LOW.y,LOW.z);
            P[5] = TIntVec(HI.x,LOW.y,HI.z);
            P[6] = TIntVec(HI.x,HI.y,LOW.z);
            P[7] = TIntVec(HI.x,HI.y,HI.z);
            P[8] = Center;

            TIntVec P_P[9];
            /*for(int i=0;i<9;i++)
                BIF->MDI3D->WinFrom3D(P[i],P_P[i]);

            TIntVec MIN = TIntVec(1<<30,1<<30,1<<30);
            TIntVec MAX = (-1)*MIN;
            int MinTop = 1000;
            int MaxBottom = -1000;
            int MinLeft = 1000;
            int MaxRight = -1000;
            for (int i=0;i<9;i++)
            {
                UpdateMinVector(MIN,P_P[i]);
                UpdateMaxVector(MAX,P_P[i]);
            }
            
            MinTop = MIN.y;
            MinLeft = MIN.x;
            MaxBottom = MAX.y;
            MaxRight = MAX.x;
            MinTop = MinTop-20;*/

            TIntVec Normal = (Center-NewViewAt0);
            Normal = Normal/(Normal).Length();
            for(int i=0;i<9;i++)
                if (PlaneCrossPoint(Center,Normal,P[i],NewViewAt0,P_P[i])==false)
                    return;

            double SizeMax = (HI - Center).Length();

            double Length = (SizeMax)*Cotan((PC->ViewAngle*M_PI)/(180*2));
            Length = Length*(1.1);
            
            TIntVec NewViewAt1 = PointOfLineOnCut(Center,NewViewAt0,Length);
            AssignVisVec(*PC->LA_LookAt,Center);
            AssignVisVec(*PC->LA_Position,NewViewAt1);
        }
    }
    AUI.InvalidateView();
};

