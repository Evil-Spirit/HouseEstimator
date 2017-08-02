 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MyControls.h"
//#include "Main.h"
#include "MyGL.h"
#include "InterFace.h"
#include "World.h"
#include "LogicNode.h"
#include "MySupportV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TAllActions *ALLACTIONS;

void InitActions()
{
    TACTIONTYPE * AT;
    TSYNGLEACTION *ST;

    ALLACTIONS = new TAllActions();
    ALLACTIONS->DefaultEnum = ioNone;
/*    //None
    AT = new TACTIONTYPE();
    AT->Description = "absent";
    AT->EnumIndex = ioNone;
    AT->DefaultEnum = -1;
    AT->DefaultImageIndex = 28;
    ALLACTIONS->ATS->Add(AT);     */

    //Move
    AT = new TACTIONTYPE();
    AT->Description = "Positioning";
    AT->EnumIndex = ioMove;
    AT->DefaultEnum = -1;
    AT->DefaultImageIndex = 7;
    AT->RightButtonTerminate = true;
    AT->MoveFirst = false;
    ALLACTIONS->ATS->Add(AT);
    //rotate
    AT = new TACTIONTYPE();
    AT->Description = "Rotation";
    AT->EnumIndex = ioRotate;
    AT->DefaultEnum = -1;
    AT->DefaultImageIndex = 8;
    AT->RightButtonTerminate = true;
    AT->MoveFirst = false;
    ALLACTIONS->ATS->Add(AT);
    //scale
    AT = new TACTIONTYPE();
    AT->Description = "Scale";
    AT->EnumIndex = ioScale;
    AT->DefaultEnum = 110;
    AT->DefaultImageIndex = 12;
    AT->RightButtonTerminate = true;
    AT->MoveFirst = false;
    ALLACTIONS->ATS->Add(AT);
    //scales
        ST = new TSYNGLEACTION();
        ST->ImageIndex = 9;
        ST->EnumIndex = 100;
        ST->Description = "Scale X";
        AT->Actions->Add(ST);
        //---------------------------------------------------------------------------
        ST = new TSYNGLEACTION();
        ST->ImageIndex = 10;
        ST->EnumIndex = 10;
        ST->Description = "Scale Y";
        AT->Actions->Add(ST);
        //---------------------------------------------------------------------------
        ST = new TSYNGLEACTION();
        ST->ImageIndex = 11;
        ST->EnumIndex = 1;
        ST->Description = "Scale Z";
        AT->Actions->Add(ST);
        //---------------------------------------------------------------------------
        ST = new TSYNGLEACTION();
        ST->ImageIndex = 12;
        ST->EnumIndex = 110;
        ST->Description = "Scale XY";
        AT->Actions->Add(ST);
        //---------------------------------------------------------------------------
        ST = new TSYNGLEACTION();
        ST->ImageIndex = 13;
        ST->EnumIndex = 11;
        ST->Description = "Scale YZ";
        AT->Actions->Add(ST);
        //---------------------------------------------------------------------------
        ST = new TSYNGLEACTION();
        ST->ImageIndex = 14;
        ST->EnumIndex = 101;
        ST->Description = "Scale XZ";
        AT->Actions->Add(ST);
        //---------------------------------------------------------------------------
        ST = new TSYNGLEACTION();
        ST->ImageIndex = 15;
        ST->EnumIndex = 111;
        ST->Description = "Scale XYZ";
        AT->Actions->Add(ST);
        //---------------------------------------------------------------------------
    //draw
    AT = new TACTIONTYPE();
    AT->Description = "Paint";
    AT->EnumIndex = ioDraw;
    AT->DefaultEnum = 1;
    AT->DefaultImageIndex = 17;
    AT->RightButtonTerminate = true;
    AT->MoveFirst = true;
    ALLACTIONS->ATS->Add(AT);
    //draws
        ST = new TSYNGLEACTION();
        ST->ImageIndex = 16;
        ST->EnumIndex = 0;
        ST->Description = "Once";
        AT->Actions->Add(ST);
        //---------------------------------------------------------------------------
        ST = new TSYNGLEACTION();
        ST->ImageIndex = 17;
        ST->EnumIndex = 1;
        ST->Description = "Repeatedly";
        AT->Actions->Add(ST);
        //---------------------------------------------------------------------------
    //construct
    AT = new TACTIONTYPE();
    AT->Description = "Construct";
    AT->EnumIndex = ioConstruct;
    AT->DefaultEnum = 0;
    AT->DefaultImageIndex = 31;
    AT->RightButtonTerminate = false;
    AT->MoveFirst = false;
    ALLACTIONS->ATS->Add(AT);
    //autoalign
    AT = new TACTIONTYPE();
    AT->Description = "Positioning And Snap";
    AT->EnumIndex = ioMoveAutoAlign;
    AT->DefaultEnum = -1;
    AT->DefaultImageIndex = 34;
    AT->RightButtonTerminate = true;
    AT->MoveFirst = false;
    ALLACTIONS->ATS->Add(AT);
    //wall construct
    AT = new TACTIONTYPE();
    AT->Description = "Construct Wall";
    AT->EnumIndex = ioWallConstruct;
    AT->DefaultEnum = 0;
    AT->DefaultImageIndex = 31;
    AT->RightButtonTerminate = true;
    AT->MoveFirst = false;
    ALLACTIONS->ATS->Add(AT);
}

void FreeActions()
{
    delete ALLACTIONS;
}

void TAllActions::FillMenuItem(TMenuItem *MMI,TNotifyEvent OnClick1,TNotifyEvent OnClick2)
{
/*    MMI->Clear();
    for (int i=0;i<ATS->Count;i++)
    {
        TMenuItem* MI = new TMenuItem(Config);
        MI->RadioItem = true;
        MI->GroupIndex = 10;
        MI->Caption = ATS->Items[i]->Description;
        MI->OnClick = OnClick1;
        MI->ImageIndex = ATS->Items[i]->DefaultImageIndex;
        MI->Tag = ATS->Items[i]->EnumIndex;
        MMI->Add(MI);
        for (int j=0;j<ATS->Items[i]->Actions->Count;j++)
        {
            MI->SubMenuImages = MMI->SubMenuImages;
            TMenuItem* _MI = new TMenuItem(Config);
            _MI->RadioItem = true;
            _MI->GroupIndex = 10+MI->Tag;
            _MI->Caption = ATS->Items[i]->Actions->Items[j]->Description;
            _MI->OnClick = OnClick2;
            _MI->ImageIndex = ATS->Items[i]->Actions->Items[j]->ImageIndex;
            _MI->Tag = ATS->Items[i]->Actions->Items[j]->EnumIndex;
            MI->Add(_MI);
        }
    }*/
}

TACTIONTYPE* TAllActions::FindByID(TIFOperations OP)
{
    for (int i=0;i<ATS->Count;i++)
        if (ATS->Items[i]->EnumIndex == OP)
            return ATS->Items[i];
    return NULL;
}


TIntVec SRV_PNT_2;
TIntVec MAPAccord(const TIntVec& Res,TElement *FEL)
{
    SRV_PNT_2 = RotateAround(Res-FEL->AbsPos,FEL->AbsAngle*(-1),ZEROINTVEC);
    for (int i=0;i<3;i++)
        SRV_PNT_2.a[i] = RoundTo(SRV_PNT_2.a[i]/MAP.a[i],0)*MAP.a[i] ;
   return RotateAround(SRV_PNT_2,FEL->AbsAngle,ZEROINTVEC)+FEL->AbsPos; 
}

TIntVec MAPAccord_STEP(const TIntVec& Res,TElement *FEL,const TIntVec& STEP)
{
    SRV_PNT_2 = RotateAround(Res-FEL->AbsPos,FEL->AbsAngle*(-1),ZEROINTVEC);
    for (int i=0;i<3;i++)
        SRV_PNT_2.a[i] = RoundTo(SRV_PNT_2.a[i]/STEP.a[i],0)*STEP.a[i] ;
   return RotateAround(SRV_PNT_2,FEL->AbsAngle,ZEROINTVEC)+FEL->AbsPos; 
}


TIntVec SRV_PNT;
TIntVec SRV_PNT_1;
T3DScope _SC;
T3DScope _SC2;


void Pos_Accord( TIntVec& New_E1_Position, TMetaLink *ML, TElement *EL0, TElement *EL1 , bool Point_1_HI )
{
    ML->TargetScope(EL0 ,EL1,_SC);
    ML->SourceScope(EL0 ,EL1,_SC2);

    if (Point_1_HI)
        SRV_PNT = _SC2.HI;
    else
        SRV_PNT = _SC2.LOW;

    SRV_PNT = RotateAround(SRV_PNT ,EL1->AbsAngle,ZEROINTVEC) + New_E1_Position;
    SRV_PNT_1 = RotateAround(SRV_PNT - EL0->AbsPos ,EL0->AbsAngle*(-1),ZEROINTVEC);
    _SC.Discrete(SRV_PNT_1,ML->STEP.BaseStep.XYZ_Multiply(ML->STEP.DefMulti));
    SRV_PNT_1 = RotateAround(SRV_PNT_1 ,EL0->AbsAngle,ZEROINTVEC) + EL0->AbsPos;
    New_E1_Position = New_E1_Position+SRV_PNT_1-SRV_PNT;
}

// центр 1 + позиция 1 = центр 2 + позиция 2
//interface objects






//-----------------------------------------------------------------------------

TMyControls::TMyControls()
{
    Render=0;
    Active = false;
    FirstRender = false;
    FMode = -1;    
    OnStop();
}

void TMyControls::Start()
{
    Render=0;
    FirstRender = true;
    Head = World->ActiveFloor->First.ADR; //return soon
    STEPLINK=NULL;
    OldSize = BIF->Element->AbsSize;
    OldPos = BIF->Element->AbsPos;
    OldRot = BIF->Element->AbsAngle;
    for (int i=0;i<BIF->Element->MyMeta->ChildList->Count;i++)
    {
        STEPLINK = (TDynamicLink*)BIF->Element->MyMeta->ChildList->Items[i];
        if (STEPLINK->El0 == Head->MyMeta)
            break;
        else
            STEPLINK = NULL;
    }
    OnStart();
    Active = true;
    BIF->MDI3D->NeedRender = true;
}

TElement * TMyControls::ReStart()
{
    OldSize = BIF->Element->AbsSize;
    OldPos = BIF->Element->AbsPos;
    OldRot = BIF->Element->AbsAngle;
    Render=0;
    FirstRender = true;
    Active = true;
    return (OnReStart());
}


void TMyControls::Stop()
{
    Render=0;
    FirstRender = false;
    OnStop();
    Active = false;
}

void TMyControls::Continue()
{
    Render++;
    if (Render>4&&FirstRender)
        if (BIF->VisView)
        {
            BIF->InvalidateView();
            Application->ProcessMessages();
            return;
        }
    TPoint P = BIF->VisView->ScreenToClient(Mouse->CursorPos);
    BIF->Element->SetSize(OldSize);
    BIF->Element->UserChangePosition(OldPos-BIF->Element->AbsPos,OldRot-BIF->Element->AbsAngle);
    if (P.x<=0||P.y<=0||P.x>=BIF->VisView->ClientWidth||P.y>=BIF->VisView->ClientHeight)
    {
//        if (Screen->Cursor==crNone)
//            Screen->Cursor=crDefault;
    }
    else
    {
//        if (Screen->Cursor!=crNone)
//            Screen->Cursor=crNone;
    }
    if (!FirstRender)
    {
        //return this
        //это для помещения чтобы оно не ездило
        if (BIF->Element->MyMeta->IsAuto)
            return;
        OnContinue();
        BIF->InvalidateView();
    }
    BIF->MDI3D->NeedRender = true;
}

void TMyControls::Toggle()
{
    if (Active)
        Stop();
    else
        Start();
}

void TMyControls::CustomRender()
{
    Render=0;
    TPoint P = BIF->VisView->ScreenToClient(Mouse->CursorPos);
    if (P.x<=0||P.y<=0||P.x>=BIF->VisView->ClientWidth||P.y>=BIF->VisView->ClientHeight)
    {
//        if (Screen->Cursor==crNone)
//            Screen->Cursor=crDefault;
        return;
    }
    else
    {
//        if (Screen->Cursor!=crNone)
//            Screen->Cursor=crNone;
    }
    if (OnCustomRender(P)&&FirstRender)
        FirstRender = false;
}









//rotation
void TRotater::OnStart()
{
    //по каким координатам
    StartPoint = Mouse->CursorPos;
    StartAngle = BIF->Element->AbsAngle;
    BIF->Driver.MainMode = ocmPosition;
    BIF->Driver.CorrectMode = ocmNone;
}

/*void TRotater::OnCustomRender()
{

} **/

void TRotater::OnContinue()
{
    MBTi Rot = CycleOf(Mouse->CursorPos.x-StartPoint.x,360);
    Rot = Rot + StartAngle.z - BIF->Element->AbsAngle.z;
    BIF->Element->UserChangePosition(ZEROINTVEC,TIntVec(0,0,Rot));
    OldRot = BIF->Element->AbsAngle;
    BIF->Element->CurrentEnabled = true;
}


void TRotater::OnStop()
{
///
}


//rotation
TScaler::TScaler()
{
    StartPoint = ZEROINTVEC;
    Direction = ZEROINTVEC;
}

void TScaler::OnSetMode(int newMode)
{
    for (int i=0;i<3;i++)
        Direction.a[2-i] =(newMode%(int)IntPower(10,i+1))/(int)IntPower(10,i);
}

TMover::TMover()
{
    StartPoint = ZEROINTVEC;
}

bool TMover::CorrectSettings(TSelectMode SM,TShiftState SS)
{
    bool changed;
    bool _Vertical;
    if (SM == smSyngle)
    {
        changed = true;
        _Vertical = (SS.Contains(ssRight)&&SS.Contains(ssLeft));
    }
    else
    {
        changed = true;
        _Vertical = (SS.Contains(ssRight)) ;
    }
    if (changed)
    {
        changed = changed*(Mode != _Vertical);
        Mode =_Vertical;
    }
    return changed;
}

void TMover::OnStart()
{
    OnStop();
    Render=0;
    StartPoint = BIF->MDI3D->GettedPoint;
    Pl0 = BIF->MDI3D->GettedPoint;
    if (BIF->Element->AbsPos.x == 0 && BIF->Element->AbsPos.y == 0)
    {
        Pl0.z = BIF->Element->AbsPos.z;
    }
    if (Mode)
    {
        TIntVec CAMPOS = TIntVec(BIF->MDI3D->View->Camera->LA_Position->AsMathVector);
        TIntVec VIEWPOS = TIntVec(BIF->MDI3D->View->Camera->LA_LookAt->AsMathVector);
        CAMPOS.z = VIEWPOS.z;
        Normal = (CAMPOS-VIEWPOS);
        float Length = Normal.Length2D();
        if (Length>0.0001)
            Normal = Normal/Length;
    }
    else
        Normal = TIntVec(0,0,1);
    //BIF->Driver.MainMode = ocmPosition;
    BIF->Driver.MainMode = ocmPosition;
    BIF->Driver.CorrectMode = ocmSize;
    //BIF->Driver.CorrectMode = ocmSize;
}

void TMover::OnContinue()
{
    TIntVec Moving;
    TIntVec Vec;
    //TPoint P = BIF->VisView->ScreenToClient(Mouse->CursorPos);
    TPoint P = BIF->MDI3D->WinPoint;
    TIntVec OnePoint;
    TIntVec TwoPoint;
    BIF->MDI3D->WinTo3D(P.x,P.y,0.8,OnePoint);
    BIF->MDI3D->WinTo3D(P.x,P.y,0.97,TwoPoint);

    if (!PlaneCrossPoint(Pl0,Normal,OnePoint,TwoPoint,Vec))
        return;
    if (Mode == 0)
    {
        if (BIF->Element->AbsPos.x == 0 && BIF->Element->AbsPos.y == 0 )
        {
//            Vec.z = BIF->Element->MyMeta->StartZED + World->ActiveFloor->AbsZ;//return soon
            StartPoint = BIF->Element->AbsPos;
            BIF->Element->CurrentEnabled = true;
        }
        else
            Vec.z = StartPoint.z;
    }
    Moving = Vec - StartPoint;
    if ( !(BIF->Element->MyMeta->Size.STEP.Hard) )
    {
        A = Moving+OldPos;
        if (Head && STEPLINK)
        {
            Pos_Accord(A,STEPLINK->Link,Head,BIF->Element,false);
            Moving = A - OldPos;
        }
    }
/*    if (BIF->Element->MyMeta->IsSupport)
    {
        A = BIF->Element->AbsSize/VEC222;
        A.y = 0;
        A = RotateAround(OldPos+A,BIF->Element->AbsAngle,OldPos)+Moving;
        A1 = MAPAccord(A,(TElement*)BIF->BIF_FC->Trees->Items[0]->Head);
        if (Measure(Moving)>0)
            Moving = Moving + A1 - A;
    }*/
    StartPoint = StartPoint+Moving;
    BIF->Element->UserChangePosition(Moving+OldPos-BIF->Element->AbsPos,ZEROINTVEC);
    OldPos = BIF->Element->AbsPos;
}

void TMover::OnStop()
{
    StartPoint = ZEROINTVEC;
}

bool TMover::OnCustomRender(const TPoint& P)
{
    return true;
}

TIntVec _StartPoint;
TIntVec SRV__Scale;
void TScaler::OnContinue()
{
    TPoint P = BIF->MDI3D->WinPoint;
    TIntVec OnePoint;
    TIntVec TwoPoint;
    TIntVec Vec;
    BIF->MDI3D->WinTo3D(P.x,P.y,0.8,OnePoint);
    BIF->MDI3D->WinTo3D(P.x,P.y,0.97,TwoPoint);

    if (!PlaneCrossPoint(Pl0,Normal,OnePoint,TwoPoint,Vec))
        return;

    TIntVec Sizing = RotateAround(Vec-StartPoint,BIF->Element->AbsAngle*(-1),ZEROINTVEC).XYZ_Multiply(_Direction);
    if (Sizing==ZEROINTVEC)
        return;
    StartPoint = Vec;
    SRV__Scale = SRV__Scale+Sizing;
    OldSize = SRV__Scale;
    TIntVec QuadroDirection = _Direction.XYZ_Multiply(_Direction);
    TIntVec __STEP__ = BIF->Element->MyMeta->Size.STEP.BaseStep.XYZ_Multiply(BIF->Element->MyMeta->Size.STEP.DefMulti);
    __STEP__ = __STEP__.XYZ_Multiply(QuadroDirection);
    if ( !(BIF->Element->MyMeta->Size.STEP.Hard))
        _Discrete(  BIF->Element->MyMeta->Size.LOW,
                    __STEP__,
                    OldSize);
    BIF->Element->ChangeSize((OldSize-BIF->Element->AbsSize).XYZ_Multiply(QuadroDirection),_Direction);
    OldPos = BIF->Element->AbsPos;
    BIF->Element->CurrentEnabled = true;
}

void TScaler::OnStop()
{
    StartPoint = ZEROINTVEC;
}

void TScaler::OnStart()
{
    BIF->Driver.MainMode = ocmSize;
    BIF->Driver.CorrectMode = ocmPosition;
    SRV__Scale = BIF->Element->AbsSize;
    StartPoint = BIF->MDI3D->GettedPoint;
    Pl0 = BIF->MDI3D->GettedPoint;
    if (Direction.z == 0)
        Normal = TIntVec(0,0,1);
    else if (Direction.x != 0)
        Normal = TIntVec(0,1,0);
    else
        Normal = TIntVec(1,0,0);

    TIntVec SDVIG;
    BIF->Element->LocalFromAbs(BIF->MDI3D->GettedPoint,SDVIG);
    for (int i=0;i<3;i++)
        _Direction.a[i] = Direction.a[i]*SIGN(SDVIG.a[i]);
};

bool TScaler::OnCustomRender(const TPoint& _P)
{
/*    if (!BIF->Element)
        return false;
    TPoint P = BIF->VisView->ScreenToClient(Mouse->CursorPos);
    if (P.x<=0||P.y<=0||P.x>=BIF->VisView->ClientWidth||P.y>=BIF->VisView->ClientHeight)
        return false;
    if (FirstRender==true)
    {
        //Анализ Z-------------------------------------------------------------

        BIF->VisView->ClearBuffers(TVisBufferType()<<btColor<<btDepth);
        BIF->Atr->Render(BIF->VisView);
        BIF->Element->Render(BIF->VisView);
        if (!GetPointOnRender2(P.x,P.y,_GetPoint))
            AssignVec(_GetPoint, BIF->Element->AbsPos);
        BIF->Invisible->Transformation ->Translation->AsMathVector = _GetPoint;
        TIntVec Angle = ZEROINTVEC;
        if (Direction.z==1&&(Direction.x+Direction.y)!=2)
        {
            Angle = ABSINTVEC(Direction)*TIntVec(-90,-90,0) + BIF->Element->AbsAngle;
            if (Angle == BIF->Element->AbsAngle)
                Angle.x +=-90;
        }
        else
            Angle = BIF->Element->AbsAngle;
        Angle = Angle % 180;
        BIF->Invisible->Transformation ->Rotation->AsMathVector =  VisMathVec(Angle);
        BIF->VisView->ClearBuffers(TVisBufferType()<<btColor<<btDepth);
    }
    BIF->Atr->Render(BIF->VisView);
    BIF->Invisible->Render(BIF->VisView);
    if (!GetPointOnRender2(P.x,P.y,_GetPoint))
    {
        BIF->VisView->ClearBuffers(TVisBufferType()<<btColor<<btDepth);
        BIF->MDI3D->Attributes->Render(BIF->VisView);
        return false;
    }
    BIF->VisView->ClearBuffers(TVisBufferType()<<btColor<<btDepth);
    BIF->MDI3D->Attributes->Render(BIF->VisView);
    if (FirstRender==true)
    {
        StartPoint =_GetPoint;
    }              */
    return true;
}

void TDrawer::OnContinue()
{
    TPoint P = BIF->MDI3D->WinPoint;
    TIntVec OnePoint;
    TIntVec TwoPoint;
    TIntVec Vec;
    BIF->MDI3D->WinTo3D(P.x,P.y,0.8,OnePoint);
    BIF->MDI3D->WinTo3D(P.x,P.y,0.97,TwoPoint);

    if (!PlaneCrossPoint(Pl0,Normal,OnePoint,TwoPoint,Vec))
        return;

    if (Head && STEPLINK)
        *(CPoints->Items[1]) = MAPAccord_STEP(Vec,Head,STEPLINK->Link->STEP.BaseStep.XYZ_Multiply(STEPLINK->Link->STEP.DefMulti));
    else
        *(CPoints->Items[1]) = Vec;
    BIF->Element->ConstructBy2Points(CPoints);
    BIF->Element->CurrentEnabled = true;
    OldSize = BIF->Element->AbsSize;
    OldPos = BIF->Element->AbsPos;
    OldRot = BIF->Element->AbsAngle;
}

bool TDrawer::AllowMultiple()
{
    return (BIF->GetOperation()==ioDraw&&Mode ==dtMultiple&&!Application->Terminated);
};

TDrawer::TDrawer()
{
    Restart = false;
    CPoints=new TMDelTList<TIntVec>;
    CPoints->Add(new TIntVec(ZEROINTVEC));
    CPoints->Add(new TIntVec(ZEROINTVEC));
}

TDrawer::~TDrawer()
{
    if (CPoints)
        delete CPoints;
    CPoints=NULL;
}

void TDrawer::OnStop()
{
}

void TDrawer::OnStart()
{
    //BIF->Driver.MainMode = ocmSize;
    BIF->Driver.MainMode = ocmSize;
    BIF->Driver.CorrectMode = ocmPosition;
    //BIF->Driver.CorrectMode = ocmPosition;

    Pl0 = BIF->MDI3D->GettedPoint;
    Normal = TIntVec(0,0,1);
    if (!Restart)
    {
        TIntVec SDVIG;
        BIF->Element->LocalFromAbs(BIF->MDI3D->GettedPoint,SDVIG);
        SDVIG.z=0;
        SDVIG.y=0;
        if (SDVIG.x == 0)
            SDVIG.x = 0.15;
        TIntVec StartPoint = (ZEROINTVEC-SIGNVEC(SDVIG)).XYZ_Multiply((BIF->Element->AbsSize/2));
        StartPoint.y=0;
        BIF->Element->AbsFromLocal(StartPoint,StartPoint);
        *(CPoints->Items[0]) = StartPoint;//MAPAccord(StartPoint,Head);  //return soon
    }
    else
        Restart = false;
}

TElement* TDrawer::OnReStart()
{
    TElement *El = CreateElementFunction(World,BIF->Element->MyMeta);
    El->DoNotDelete = true;
    TIntVec Vec = El->AbsPos;
    //Vec.z = El->MyMeta->StartZED+World->ActiveFloor->AbsZ;
    El->UserChangePosition(Vec-El->AbsPos,ZEROINTVEC);
//    TIntVec T1 = BIF->Element->AbsPos - BIF->Element->AbsSize/VEC222;
//    T0.y = BIF->Element->AbsPos.y;
    TIntVec T1 = BIF->Element->AbsPos + BIF->Element->AbsSize/2;
    T1.y = BIF->Element->AbsPos.y;
    T1.z = BIF->Element->AbsPos.z;
//    T0 = RotateAround(T0,BIF->Element->AbsAngle,BIF->Element->AbsPos);
    T1 = RotateAround(T1,BIF->Element->AbsAngle,BIF->Element->AbsPos);
//    if (Measure(T0-*(CPoints->Items[1]))<Measure(T1-*(CPoints->Items[1])))
//        *(CPoints->Items[0]) = T0;
//    else
    *(CPoints->Items[0]) = T1;
    *(CPoints->Items[1]) = *(CPoints->Items[0])+TIntVec(0.33,0,0);
    El->ConstructBy2Points(CPoints);
    El->CurrentEnabled = true;
    El->DoNotDelete = false;
    Restart = true;
    return El;
}

bool TDrawer::OnCustomRender(const TPoint& P)
{
    return true;
}

TConstructor::TConstructor()
{
    AllArrows = new TMTList<TVisPrimitiveObj>();
    CurArrow = new TVisPrimitiveObj(NULL);
    CreateArrow(CurArrow,TIntVec(0.3,0.3,0.3),clRed);
    MEs = new TMTList<TMetaElement>();
}

TConstructor::~TConstructor()
{
    delete CurArrow;
    AllArrows->RealClear();
    delete AllArrows;
    delete MEs;
}

void TConstructor::OnStop()
{
    TMDelTList<TIntVec>& PNTS = *(POL.Vertex);
    if (BIF->Element&&Active)
    {
        if (PNTS.Count!=0)
            PNTS.Delete(PNTS.Count-1);
        BIF->Element->ConstructByNPoints(&PNTS);
        PNTS.Clear();
    }
}

TElement* TConstructor::OnReStart()
{
    TMDelTList<TIntVec>& PNTS = *(POL.Vertex);
    AllArrows->Add( new TVisPrimitiveObj(NULL) );
    CreateArrow(AllArrows->Last(),TIntVec(0.3,0.3,0.3),clBlue);
    AssignVisVec(*(AllArrows->Last()->Transformation->Translation),PNTS[PNTS.Count-1]);
    PNTS.Add(new TIntVec());
    return BIF->Element;
}

bool TConstructor::AllowMultiple()
{
    return (    BIF->GetOperation()==ioConstruct &&
                !Application->Terminated);
}    

void TConstructor::OnStart()
{
    TMDelTList<TIntVec>& PNTS = *(POL.Vertex);
        Pl0 = BIF->MDI3D->GettedPoint;
        Normal = TIntVec(0,0,1);
        PNTS.Clear();
        PNTS.Add(new TIntVec());
        AllArrows->RealClear();
        MEs->Clear();
        Steps.Clear();
        //StartZ = BIF->Element->MyMeta->StartZED + World->ActiveFloor->AbsZ;
        for (int i=0;i<BIF->Element->MyMeta->ChildList->Count;i++)
        {
            TDynamicLink* DL = (TDynamicLink*)BIF->Element->MyMeta->ChildList->Items[i];
            if (MEs->IndexOf(DL->El0)==-1 && DL->El0->InWeb)
            {
                MEs->Add(DL->El0);
                Steps.Add(new TIntVec());
                if (DL->Link->STEP.Hard)
                    Steps[Steps.Count-1] = ZEROINTVEC;
                else
                    Steps[Steps.Count-1] = DL->Link->STEP.BaseStep.XYZ_Multiply(DL->Link->STEP.DefMulti);
            }
        }
}

bool TConstructor::Object_OK()
{
    TMDelTList<TIntVec>& PNTS = *(POL.Vertex);
    if (PNTS.Count==0)
        return false;
    TIntVec* END = PNTS.Last();
    PNTS.RemoveOnly(PNTS.Count-1);
    bool result = POL.Valid(_MBTi_eps_);
    PNTS.Add(END);
    return result;
}

void TConstructor::OnContinue()
{
    TMDelTList<TIntVec>& PNTS = *(POL.Vertex);
    TPoint P = BIF->MDI3D->WinPoint;
    TIntVec OnePoint;
    TIntVec TwoPoint;
    TIntVec Vec;
    BIF->MDI3D->WinTo3D(P.x,P.y,0.8,OnePoint);
    BIF->MDI3D->WinTo3D(P.x,P.y,0.97,TwoPoint);

    if (!PlaneCrossPoint(Pl0,Normal,OnePoint,TwoPoint,Vec))
        return;


    TIntVec OldCurVec = CurVec;
    CurVec = Vec;
    TIntVec Trans = ZEROINTVEC;
    LN->SelectNearestPoint(CurVec,MEs,&Steps,Trans);
    CurVec+=Trans;
    if (OldCurVec == CurVec)
        return;
    AssignVisVec(*(CurArrow->Transformation->Translation),CurVec);
    PNTS[PNTS.Count-1] = CurVec;
    TMDelTList<TIntVec> PNTS2;
    PNTS2.Assign(&PNTS);
    BIF->Element->ConstructByNPoints(&PNTS2);
    BIF->Element->CurrentEnabled = true;
    OldSize = BIF->Element->AbsSize;
    OldPos = BIF->Element->AbsPos;
    OldRot = BIF->Element->AbsAngle;
}

bool TConstructor::OnCustomRender(const TPoint& P)
{
    if (!BIF->Element)
        return false;
        glLineWidth(1);
        for (int i=0;i<AllArrows->Count;i++)
            AllArrows->Items[i]->Render(BIF->VisView);
        CurArrow->Render(BIF->VisView);
        glLineWidth(BIF->MDI3D->Attributes->LineWidth);
    return true;
}
//------------------------------------------------------------------------------
TWallConstructor::TWallConstructor()
{
    Restart = false;
    AllArrows = new TMTList<TVisPrimitiveObj>();
    CurArrow = new TVisPrimitiveObj(NULL);
    CreateArrow(CurArrow,TIntVec(0.3,0.3,0.3),clRed);
    MEs = new TMTList<TMetaElement>();
}

TWallConstructor::~TWallConstructor()
{
    delete CurArrow;
    AllArrows->RealClear();
    delete AllArrows;
    delete MEs;
}

void TWallConstructor::OnStop()
{
}

TElement* TWallConstructor::OnReStart()
{
    if (PNTS.Count==2)
    {
        TElement *El = CreateElementFunction(World,BIF->Element->MyMeta);
        El->DoNotDelete = true;
        TIntVec Vec = El->AbsPos;
        //Vec.z = El->MyMeta->StartZED+World->ActiveFloor->AbsZ;
        El->UserChangePosition(Vec-El->AbsPos,ZEROINTVEC);
        TIntVec T1 = ZEROINTVEC;
        T1.x = BIF->Element->AbsSize.x/2;
        BIF->Element->AbsFromLocal(T1,T1);
        PNTS.Clear();
        PNTS.Add(new TIntVec(T1));
        PNTS.Add(new TIntVec(T1));
        AllArrows->RealClear();
        AllArrows->Add( new TVisPrimitiveObj(NULL) );
        CreateArrow(AllArrows->Last(),TIntVec(0.3,0.3,0.3),clRed);
        AssignVisVec(*(AllArrows->Last()->Transformation->Translation),PNTS[0]+TIntVec(0,0,BIF->Element->AbsSize.z/2+0.01));
        El->CurrentEnabled = false;
        El->DoNotDelete = false;
        Restart = true;
        return El;
    }
    else
    {
        AllArrows->Add( new TVisPrimitiveObj(NULL) );
        CreateArrow(AllArrows->Last(),TIntVec(0.3,0.3,0.3),clRed);
        AssignVisVec(*(AllArrows->Last()->Transformation->Translation),PNTS[PNTS.Count-1]+TIntVec(0,0,BIF->Element->AbsSize.z/2+0.01));
        PNTS.Add(new TIntVec());
        Restart = false;
        return BIF->Element;
    }
}

bool TWallConstructor::AllowMultiple()
{
    return (    BIF->GetOperation()==ioWallConstruct &&
                !Application->Terminated);
}    

void TWallConstructor::OnStart()
{
    BIF->Driver.MainMode = ocmSize;
    BIF->Driver.CorrectMode = ocmPosition;
    if (!Restart)
    {
        Pl0 = BIF->MDI3D->GettedPoint;
        Normal = TIntVec(0,0,1);
        PNTS.Clear();
        PNTS.Add(new TIntVec());
        AllArrows->RealClear();
        MEs->Clear();
        Steps.Clear();
        //StartZ = BIF->Element->MyMeta->StartZED + World->ActiveFloor->AbsZ;

        if (STEPLINK)
            for (int i=0;i<MetaNodeCollection->KernelSupport->WEBMETA.Count;i++)
            {
                MEs->Add(MetaNodeCollection->KernelSupport->WEBMETA.Items[i]);
                Steps.Add(new TIntVec());
                Steps[Steps.Count-1] = STEPLINK->Link->STEP.BaseStep.XYZ_Multiply(STEPLINK->Link->STEP.DefMulti);
            }
    }
    else
        Restart = false;
}

bool TWallConstructor::Object_OK()
{
    return true;
/*    if (PNTS.Count<2)
        return false;
    MBTi Size = (PNTS[1]-PNTS[0]).Length();
    return fabs(Size)>=BIF->Element->MyMeta->Size.LOW.x;  */
}

void TWallConstructor::OnContinue()
{
    TPoint P = BIF->MDI3D->WinPoint;
    TIntVec OnePoint;
    TIntVec TwoPoint;
    TIntVec Vec;
    BIF->MDI3D->WinTo3D(P.x,P.y,0.8,OnePoint);
    BIF->MDI3D->WinTo3D(P.x,P.y,0.97,TwoPoint);

    if (!PlaneCrossPoint(Pl0,Normal,OnePoint,TwoPoint,Vec))
        return;
    //BIF->Element->UserChangePosition(TIntVec(0,0,BIF->Element->MyMeta->StartZED + World->ActiveFloor->AbsZ-BIF->Element->AbsPos.z),ZEROINTVEC);

    TIntVec OldCurVec = CurVec;
    CurVec = Vec;
    TIntVec Trans = ZEROINTVEC;
    LN->SelectNearestPoint(CurVec,MEs,&Steps,Trans);
    if (STEPLINK && PNTS.Count == 1 && Trans.Length2D()<(BIF->Element->MyMeta->EPS.POSEPS).x)
            PNTS[PNTS.Count-1] = CurVec+Trans;
    else if (Head && STEPLINK)
        PNTS[PNTS.Count-1] = MAPAccord_STEP(CurVec,Head,STEPLINK->Link->STEP.BaseStep.XYZ_Multiply(STEPLINK->Link->STEP.DefMulti));
    else
        PNTS[PNTS.Count-1] = Vec;
    PNTS[PNTS.Count-1].z = BIF->Element->AbsPos.z;
    AssignVisVec(*(CurArrow->Transformation->Translation),PNTS[PNTS.Count-1]+TIntVec(0,0,BIF->Element->AbsSize.z/2+0.01));
    if (PNTS.Count==2 && Object_OK())
    {
        BIF->Element->ConstructBy2Points(&PNTS);
        BIF->Element->CurrentEnabled = true;
    }
    OldSize = BIF->Element->AbsSize;
    OldPos = BIF->Element->AbsPos;
    OldRot = BIF->Element->AbsAngle;

}

bool TWallConstructor::OnCustomRender(const TPoint& P)
{
    if (!BIF->Element)
        return false;
        glLineWidth(1);
        for (int i=0;i<AllArrows->Count;i++)
            AllArrows->Items[i]->Render(BIF->VisView);
        CurArrow->Render(BIF->VisView);
        glLineWidth(BIF->MDI3D->Attributes->LineWidth);
    return true;
}
//------------------------------------------------------------------------------
TMoverAA::TMoverAA()
{
    StartPoint = ZEROINTVEC;
    CurrentDepth =0.5;
}

bool TMoverAA::CorrectSettings(TSelectMode SM,TShiftState SS)
{
    bool changed;
    bool _Vertical;
    if (SM == smSyngle)
    {
        changed = true;
        _Vertical = (SS.Contains(ssRight)&&SS.Contains(ssLeft));
    }
    else
    {
        changed = true;
        _Vertical = (SS.Contains(ssRight)) ;
    }
    if (changed)
    {
        changed = changed*(Mode != _Vertical);
        Mode =_Vertical;
    }
    return changed;
}

void TMoverAA::OnStart()
{
    OnStop();
    Render=0;
    StartPoint = BIF->MDI3D->GettedPoint;
    Pl0 = BIF->MDI3D->GettedPoint;
    if (BIF->Element->AbsPos.x == 0 && BIF->Element->AbsPos.y == 0)
    {
        Pl0.z = BIF->Element->AbsPos.z;
    }
    if (Mode)
    {
        TIntVec CAMPOS = TIntVec(BIF->MDI3D->View->Camera->LA_Position->AsMathVector);
        TIntVec VIEWPOS = TIntVec(BIF->MDI3D->View->Camera->LA_LookAt->AsMathVector);
        CAMPOS.z = VIEWPOS.z;
        Normal = (CAMPOS-VIEWPOS);
        float Length = Normal.Length2D();
        if (Length>0.0001)
            Normal = Normal/Length;
    }
    else
        Normal = TIntVec(0,0,1);
    BIF->Driver.MainMode = ocmPosition;
    BIF->Driver.CorrectMode = ocmSize;
}

void TMoverAA::OnContinue()
{
    TIntVec Moving;
    TIntVec Vec;
    //TPoint P = BIF->VisView->ScreenToClient(Mouse->CursorPos);
    TPoint P = BIF->MDI3D->WinPoint;
    TIntVec OnePoint;
    TIntVec TwoPoint;
    BIF->MDI3D->WinTo3D(P.x,P.y,0.8,OnePoint);
    BIF->MDI3D->WinTo3D(P.x,P.y,0.97,TwoPoint);

    if (!PlaneCrossPoint(Pl0,Normal,OnePoint,TwoPoint,Vec))
        return;
    if (Mode == 0)
    {
        if (BIF->Element->AbsPos.x == 0 && BIF->Element->AbsPos.y == 0 )
        {
            StartPoint = BIF->Element->AbsPos;
            BIF->Element->CurrentEnabled = true;
        }
        else
            Vec.z = StartPoint.z;
    }
    Moving = Vec - StartPoint;
    if ( !(BIF->Element->MyMeta->Size.STEP.Hard) )
    {
        A = Moving+OldPos;
        if (Head && STEPLINK)
        {
            Pos_Accord(A,STEPLINK->Link,Head,BIF->Element,false);
            Moving = A - OldPos;
        }
    }

/*    if (BIF->Element->MyMeta->IsSupport)
    {
        A = BIF->Element->AbsSize/VEC222;
        A.y = 0;
        A = RotateAround(OldPos+A,BIF->Element->AbsAngle,OldPos)+Moving;
        A1 = MAPAccord(A,(TElement*)BIF->BIF_FC->Trees->Items[0]->Head);
        if (Measure(Moving)>0)
            Moving = Moving + A1 - A;
    }*/
    StartPoint = StartPoint+Moving;
    BIF->Element->UserChangePosition(Moving+OldPos-BIF->Element->AbsPos,ZEROINTVEC);
    OldPos = BIF->Element->AbsPos;

    BIF->Element->RunElementTrigger(trAutoAlign);
    BIF->Element->CurrentEnabled = true;
}

void TMoverAA::OnStop()
{
    StartPoint = ZEROINTVEC;
}

bool TMoverAA::OnCustomRender(const TPoint& P)
{
    return true;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------




