//---------------------------------------------------------------------------

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#include <Poligon.h>
#pragma hdrstop

#include "MyEdit.h"
#include "math.h"
#include "MyViewV.h"
#include "MyGL.h"
#include "G2DObjectV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TClassNode* TEditorAttributes::StaticType = NULL;
TClassNode* TGridAttributes::StaticType = NULL;
TClassNode* TGrid::StaticType = NULL;

const MBTi PointEPS = 0.01;
const MBTi CutEps = 0.001;
//---------------------------------------------------------------------------

const AnsiString aSnap = "Snap";
const AnsiString aSnapValuePix = "SnapValuePix";
const AnsiString aAdditionalFiguresSnap = "AdditionalFiguresSnap";
const AnsiString aSnapMyFigures = "SnapMyFigures";

const AnsiString aColors_Addition = "Colors.Addition";
const AnsiString aColors_MyFigures = "Colors.MyFigures";
const AnsiString aColors_Selected = "Colors.Selected";
const AnsiString aColors_Fixid = "Colors.Fixid";
const AnsiString aColors_BackGround = "Colors.BackGround";

const AnsiString aLinesWidth_Additional = "LinesWidth.Additional";
const AnsiString aLinesWidth_MyFigures = "LinesWidth.MyFigures";
const AnsiString aLinesWidth_Selected = "LinesWidth.Selected";
const AnsiString aLinesWidth_Fixid = "LinesWidth.Fixid";

TEditorAttributes::TEditorAttributes()
{
    RegisterNewClass< TMyObject, TEditorAttributes >(this, false, &CreateFunction);
    Snap = true;
    SnapValuePix = 10;
    SnapValue = 0;//неопределено
    AdditionalFiguresSnap = true;
    SnapMyFigures = true;
    Colors.Additional = (TColor)0x222211;//(TColor)0x338055;
    Colors.MyFigures = clBlue;
    Colors.Selected = clRed;
    Colors.BackGround = clGray;
    LinesWidth.Additional = 1;
    LinesWidth.MyFigures = 1;
    LinesWidth.Selected = 1;
    LinesWidth.Fixid = 1;

    RegisterField(&Snap, &aSnap, mtBool);
    RegisterField(&SnapValuePix, &aSnapValuePix, mtInt);
    RegisterField(&AdditionalFiguresSnap, &aAdditionalFiguresSnap, mtBool);
    RegisterField(&SnapMyFigures, &aSnapMyFigures, mtBool);

    RegisterField(&Colors.Additional, &aColors_Addition, mtInt);
    RegisterField(&Colors.MyFigures, &aColors_MyFigures, mtInt);
    RegisterField(&Colors.Selected, &aColors_Selected, mtInt);
    RegisterField(&Colors.Fixid, &aColors_Fixid, mtInt);
    RegisterField(&Colors.BackGround, &aColors_BackGround, mtInt);

    RegisterField(&LinesWidth.Additional, &aLinesWidth_Additional, mtInt);
    RegisterField(&LinesWidth.MyFigures, &aLinesWidth_MyFigures, mtInt);
    RegisterField(&LinesWidth.Selected, &aLinesWidth_Selected, mtInt);
    RegisterField(&LinesWidth.Fixid, &aLinesWidth_Fixid, mtInt);
}

TMyObject* TEditorAttributes::CreateFunction()
{
    return new TEditorAttributes();
}

/*void TEditorAttributes::SetColors(TEditorColors _Colors)
{
    FColors.Additional = _Colors.Additional;
    FColors.MyFigures = _Colors.MyFigures;
    FColors.Selected = _Colors.Selected;
    FColors.BackGround = _Colors.BackGround;
}*/
//----------------------------------Grid----------------------------------------
const AnsiString agSnap = "Snap";
const AnsiString agStep = "Step";
const AnsiString agZoomStep = "ZoomStep";
const AnsiString agSwitchEpsilon = "SwitchEpsilon";
const AnsiString agMultiplier = "Multiplier";
const AnsiString agSnapStep = "SnapStep";
const AnsiString agZoomLimit = "ZoomLimit";

const AnsiString agColors_OSI = "Colors.OSI";
const AnsiString agColors_MIN = "Colors.MIN";
const AnsiString agColors_MAX = "Colors.MAX";

const AnsiString agLinesWidth_OSI = "LinesWidth.OSI";
const AnsiString agLinesWidth_MIN = "LinesWidth.MIN";
const AnsiString agLinesWidth_MAX = "LinesWidth.MAX";

const AnsiString agVisible = "Visible";

TGridAttributes::TGridAttributes()
{
    RegisterNewClass< TMyObject, TGridAttributes >(this, false, &CreateFunction);
    Snap = true;
    Step = 0.1;
    Colors.OSI = (TColor)0x505050;
    Colors.MAX = (TColor)0xcccccc;
    Colors.MIN = (TColor)0xb0b0b0;
    LinesWidth.OSI = 1;
    LinesWidth.MAX = 1;
    LinesWidth.MIN = 1;
//    TolCut = 0.1;
    Visible = true;
    Multiplier = 10;
    ZoomStep = 0.0005;
    SwitchEpsilon = 10;//pixels
    ZoomLimit = 9990;
    SnapStep = 2;
    ChangeMinToMax = false;
    ChangeMaxToMin = false;
    ReBuild = true;
    Minimal = false;

    RegisterField(&Snap, &agSnap, mtBool);
    RegisterField(&Step, &agStep, mtMBTi);
    RegisterField(&ZoomStep, &agZoomStep, mtMBTi);
    RegisterField(&SwitchEpsilon, &agSwitchEpsilon, mtInt);
    RegisterField(&Multiplier, &agMultiplier, mtInt);
    RegisterField(&SnapStep, &agSnapStep, mtInt);
    RegisterField(&ZoomLimit, &agZoomLimit, mtInt);

    RegisterField(&Colors.OSI, &agColors_OSI, mtInt);
    RegisterField(&Colors.MIN, &agColors_MIN, mtInt);
    RegisterField(&Colors.MAX, &agColors_MAX, mtInt);

    RegisterField(&LinesWidth.OSI, &agLinesWidth_OSI, mtInt);
    RegisterField(&LinesWidth.MIN, &agLinesWidth_MIN, mtInt);
    RegisterField(&LinesWidth.MAX, &agLinesWidth_MAX, mtInt);

    RegisterField(&Visible, &agVisible, mtBool);
}

TMyObject* TGridAttributes::CreateFunction()
{
    return new TGridAttributes();
}

TMyObject* TGrid::CreateFunction()
{
    return new TGrid();
}

TIntVec TGrid::Snap(const TIntVec &Point) const
{
    MBTi RealSnapStep = Attr.Step / Attr.SnapStep;
    TIntVec V;
    V.x = (MBTi)floor( Point.x / RealSnapStep +0.5)*RealSnapStep;
    V.y = (MBTi)floor( Point.y / RealSnapStep +0.5)*RealSnapStep;
    V.z = Point.z;
    return V;
}

MBTi MOD(MBTi Value,MBTi Divider)
{
    MBTi RValue = fabs( fabs(Value) - fabs( floor( fabs( Value/Divider ) )*Divider ) );
    return RValue*Sign(Value*Divider);
}

MBTi ROUNDSTEP(MBTi Value,MBTi Divider)
{
    MBTi RValue = fabs( fabs(Value) - fabs( RoundTo( fabs( Value/Divider ),0 )*Divider ) );
    return RValue*Sign(Value*Divider);
}

MBTi DIV(MBTi Value,MBTi Divider)
{
    MBTi RValue = fabs( floor( fabs( Value/Divider ) )*Divider );
    return RValue*Sign(Value*Divider);
}


void TGrid::Create(const TIntVec &aa, const TIntVec &b, MBTi dist, MBTi DepthLevel)
{
    if (dist == 0)
        dist = Attr.SwitchEpsilon+1;
    while(dist < Attr.SwitchEpsilon)
    {
        dist *= Attr.Multiplier;
        Attr.Step *= Attr.Multiplier;
    }
    while(dist/Attr.Multiplier > Attr.SwitchEpsilon)
    {
        dist /= Attr.Multiplier;
        Attr.Step /= Attr.Multiplier;
    }

/*    if (distx < Attr.SwitchEpsilon || disty < Attr.SwitchEpsilon)
        Attr.ChangeMinToMax = true;
    else
        if (distx/Attr.Multiplier > Attr.Multiplier || disty/Attr.Multiplier > Attr.Multiplier)
            Attr.ChangeMaxToMin = true;*/

/*    if (Attr.ChangeMinToMax)
    {
        Attr.Step *= Attr.Multiplier;
        Attr.ChangeMinToMax = false;
    }
    if (Attr.ChangeMaxToMin)
    {
        Attr.Step /= Attr.Multiplier;
        Attr.ChangeMaxToMin = false;
    }*/
    VCO_OSI->Init();
    VCO_OSI->Color->Color = Attr.Colors.OSI;
    VCO_OSI->ColorAsMaterial = cmAmbient;
    VCO_OSI->AddPrimitiveArray(GL_LINES);
    if (aa.x <= 0 && b.x >=0)
    {
        VCO_OSI->AddIndex(VCO_OSI->Points->Add(ToVec(0,aa.y,DepthLevel),ZEROVEC,ZEROVEC),0);
        VCO_OSI->AddIndex(VCO_OSI->Points->Add(ToVec(0,b.y,DepthLevel),ZEROVEC,ZEROVEC),0);
    }
    if (aa.y <= 0 && b.y >=0)
    {
        VCO_OSI->AddIndex(VCO_OSI->Points->Add(ToVec(aa.x,0,DepthLevel),ZEROVEC,ZEROVEC),0);
        VCO_OSI->AddIndex(VCO_OSI->Points->Add(ToVec(b.x,0,DepthLevel),ZEROVEC,ZEROVEC),0);
    }
    VCO_OSI->CalcNormals();

    MBTi CurStep = Attr.Step;
    int i;
    for(i = 0; floor(CurStep) == 0; CurStep*=10, i++);
    Precision = i+1;

    if (Attr.Minimal)
        return;

    VCO_MIN->Init();
    VCO_MIN->Color->Color = Attr.Colors.MIN;
    VCO_MIN->ColorAsMaterial = cmAmbient;
    VCO_MIN->AddPrimitiveArray(GL_LINES);

    TIntVec a;
    a.x = ((MBTi)ceil( aa.x / Attr.Step ))*Attr.Step;
    a.y = ((MBTi)ceil( aa.y / Attr.Step ))*Attr.Step;
    for(MBTi d = a.x; d < b.x; d += Attr.Step)
    {
        if (fabs(ROUNDSTEP(d, Attr.Step*Attr.Multiplier)) < 0.001 )
            continue;
        VCO_MIN->AddIndex(VCO_MIN->Points->Add(ToVec(d,aa.y,DepthLevel),ZEROVEC,ZEROVEC),0);
        VCO_MIN->AddIndex(VCO_MIN->Points->Add(ToVec(d,b.y,DepthLevel),ZEROVEC,ZEROVEC),0);
    }
    for(MBTi d = a.y; d < b.y; d += Attr.Step)
    {
        if ( fabs(ROUNDSTEP(d, Attr.Step*Attr.Multiplier)) < 0.001 )
            continue;
        VCO_MIN->AddIndex(VCO_MIN->Points->Add(ToVec(aa.x,d,DepthLevel),ZEROVEC,ZEROVEC),0);
        VCO_MIN->AddIndex(VCO_MIN->Points->Add(ToVec(b.x,d,DepthLevel),ZEROVEC,ZEROVEC),0);
    }
    VCO_MIN->CalcNormals();

    VCO_MAX->Init();
    VCO_MAX->Color->Color = Attr.Colors.MAX;
    VCO_MAX->ColorAsMaterial = cmAmbient;
    VCO_MAX->AddPrimitiveArray(GL_LINES);
    TIntVec a2;
    a2.x = ((MBTi)ceil( aa.x / (Attr.Step*Attr.Multiplier) ))*(Attr.Step*Attr.Multiplier);
    a2.y = ((MBTi)ceil( aa.y / (Attr.Step*Attr.Multiplier) ))*(Attr.Step*Attr.Multiplier);
    for(MBTi d = a2.x; d < b.x; d += Attr.Step*Attr.Multiplier)
    {
        if (fabs(d) < 0.00001)
            continue;
        VCO_MAX->AddIndex(VCO_MAX->Points->Add(ToVec(d,aa.y,DepthLevel),ZEROVEC,ZEROVEC),0);
        VCO_MAX->AddIndex(VCO_MAX->Points->Add(ToVec(d,b.y,DepthLevel),ZEROVEC,ZEROVEC),0);
    }
    for(MBTi d = a2.y; d < b.y; d += Attr.Step*Attr.Multiplier)
    {
        if (fabs(d) < 0.00001)
            continue;
        VCO_MAX->AddIndex(VCO_MAX->Points->Add(ToVec(aa.x,d,DepthLevel),ZEROVEC,ZEROVEC),0);
        VCO_MAX->AddIndex(VCO_MAX->Points->Add(ToVec(b.x,d,DepthLevel),ZEROVEC,ZEROVEC),0);
    }
    VCO_MAX->CalcNormals();
}

const AnsiString aAttr = "Attr";

TGrid::TGrid()
{
    RegisterNewClass< TMyObject, TGrid >(this, false, &CreateFunction);
    VCO_MIN = new TVisPrimitiveObj(NULL);
    VCO_MAX = new TVisPrimitiveObj(NULL);
    VCO_OSI = new TVisPrimitiveObj(NULL);

    RegisterField(&Attr, &aAttr, mtMyObject);
}

void TGrid::Render(TMyView* aView)
{
    if (!Attr.Visible)
        return;
    if (!Attr.Minimal)
    {
        VCO_MIN->Color->Color = Attr.Colors.MIN;
        glLineWidth(Attr.LinesWidth.MIN);
        VCO_MIN->Render(aView->View);

        VCO_MAX->Color->Color = Attr.Colors.MAX;
        glLineWidth(Attr.LinesWidth.MAX);
        VCO_MAX->Render(aView->View);
    }
    VCO_OSI->Color->Color = Attr.Colors.OSI;
    glLineWidth(Attr.LinesWidth.OSI);
    VCO_OSI->Render(aView->View);
}

TGrid::~TGrid()
{
//    delete Mat;
    delete VCO_MIN;
    delete VCO_MAX;
    delete VCO_OSI;
}

int TSelection::FindFigure(T2DGObject* MF) const
{
    for (int i=0;i<Figures.Count;i++)
        if (Figures[i].Figure == MF)
            return i;
    return -1;
}

int TSelected::FindCutIndex(TGCut* Cut) const
{
    return  SCuts.IndexOf(Cut);
}

bool TSelection::FindCutAndFigureIndices(T2DGObject* MF,TGCut* Cut, int& FigureIndex, int& SelectedCutIndex)
{
    SelectedCutIndex = FigureIndex = FindFigure(MF);
    if (FigureIndex == -1)
        return false;
    SelectedCutIndex = Figures[FigureIndex].FindCutIndex(Cut);
    return (SelectedCutIndex != -1);
}

TDepthLevels::TDepthLevels()
{
/*    Grid = -3;
    Fixid = -2;
    Additional = -1;
    Figures = 0;
    Selected = 1;*/
/*    Grid = 0.001;
    Fixid = 0.002;
    Additional = 0.003;
    Figures = 0.004;
    Selected = 0.005;*/
    Grid = 0;
    Fixid = 0;
    Additional = 0;
    Figures = 0;
    Selected = 0;    
}

TDepthLevels::TDepthLevels(MBTi _Grid, MBTi _Fixid, MBTi _Additional, MBTi _Figures, MBTi _Selected)
{
    Grid = _Grid;
    Fixid = _Fixid;
    Additional = _Additional;
    Figures = _Figures;
    Selected = _Selected;
}
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
                if ((NewViewWidth<200000 || Parameter<0) && (NewViewWidth>0.0001 || Parameter>0))
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

