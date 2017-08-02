 //---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "InterFace.h"
#include "MetaClasses.h"
#include "ElementV.h"
#include "MDI3DV.h"
#include "UNDO.h"
#include "World.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TInterFace *BIF;
void TCameraEngine::Init(   TVisPerspectiveCamera *_Perspective,
                            TVisOrthographicCamera *_Orthographic    )
{
    Perspective = _Perspective;
    Orthographic = _Orthographic;
};

void TCameraEngine::ViewAll(TVisCamera *Camera)
{
    if (!BIF->MDI3D)
        return;
    TIntVec LOW=TIntVec(1<<30,1<<30,1<<30);
    TIntVec HI = LOW*(-1);
    BIF->BIF_MT->LOW_HI(LOW,HI,true,NULL,true);
    if (LOW == TIntVec(1<<30,1<<30,1<<30))
        return;
    TIntVec Aver = (LOW+HI)/2;
    TIntVec Range = HI - LOW;
    TIntVec AddCamera = TIntVec(Camera->Transformation->Translation->AsMathVector)*(-1);
    if (Camera->ClassType()==__classid(TVisOrthographicCamera))
    {
        Aver.z = 200;
        Aver *= -1;
        AssignVisVec(*(Camera->Transformation->Translation),Aver);

        ((TVisOrthographicCamera*)Camera)->ViewHeight = MAX(Range.x,Range.y);
        ((TVisOrthographicCamera*)Camera)->ViewWidth = MAX(Range.x,Range.y);
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
    BIF->InvalidateView();
};

void TInterFace::FirstInit(TMDI3D *_3D,TMainTree *newMT)
{
//attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if (_3D && !_3D->Mode)
        return;    
  if (_3D&&newMT)
  {
    if (BIF_MT != newMT)
    {
      BIF_MT = newMT;
//      MDIFloorControl->SetMainTree(BIF_MT);
    }
    if (VisView)
      VisView->AutoClearBuffers = TVisBufferType();
    if (_3D!=MDI3D)
    {
        bool ChangeMode = !MDI3D&&_3D || _3D&&MDI3D&&_3D->Mode!=MDI3D->Mode;
        MDI3D = _3D;
        InvalidateTextures();
        if (ChangeMode && Mode)
          BIF_MT->SetMode();
    }
    if (VisView)
      VisView->AutoClearBuffers = TVisBufferType()<<btDepth<<btColor;

    InvalidateView();
    }
    else
    {
        if (VisView)
          VisView->AutoClearBuffers = TVisBufferType();
        MDI3D = NULL;
        BIF_MT = NULL;
    }
}



void TInterFace::SetAdvancedTexturing(bool Value)
{
    FPrevAdvancedTexturing = FAdvancedTexturing;
    FAdvancedTexturing = Value;
    if (World)
        World->SetMode();
}

TInterFace::TInterFace()
{
    FAdvancedTexturing = false;
    FPrevAdvancedTexturing = false;
    BIF_MT = NULL;
    FElement = NULL;
    MDI3D = NULL;
};

TInterFace::~TInterFace()
{
}

void TInterFace::InvalidateView()
{
    if (VisView)
        VisView->InvalidateGL();
}

TMetaMyMode* TInterFace::GetMetaMyMode()
{
  if (MDI3D)
    return MDI3D->Mode;
  else
    return NULL;
}

TVisView *TInterFace::GetVisView()
{
  if (MDI3D)
    return MDI3D->View;
  else
    return NULL;
}

void TInterFace::CustomRender()
{
    if (BIF_MT && VisView)
        BIF_MT->Render(VisView);
}

