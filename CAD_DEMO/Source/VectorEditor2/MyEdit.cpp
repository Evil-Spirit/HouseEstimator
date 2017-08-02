//---------------------------------------------------------------------------

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#include <Poligon.h>
#pragma hdrstop

#include "MyEdit.h"
#include "math.h"
#include "EditorV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

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

void TGrid::Create(const TIntVec &aa, const TIntVec &b, MBTi DepthLevel)
{
    if (Attr.ChangeMinToMax)
    {
        Attr.Step *= Attr.Multiplier;
        Attr.ChangeMinToMax = false;
    }
    if (Attr.ChangeMaxToMin)
    {
        Attr.Step /= Attr.Multiplier;
        Attr.ChangeMaxToMin = false;
    }
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

    VCO_MIN->Init();
    VCO_MIN->Color->Color = Attr.Colors.MIN;
    VCO_MIN->ColorAsMaterial = cmAmbient;
    VCO_MIN->AddPrimitiveArray(GL_LINES);

    TIntVec a;
    a.x = ((MBTi)floor( aa.x / Attr.Step ))*Attr.Step;
    a.y = ((MBTi)floor( aa.y / Attr.Step ))*Attr.Step;
    for(double d = a.x; d < b.x; d += Attr.Step)
    {
        VCO_MIN->AddIndex(VCO_MIN->Points->Add(ToVec(d,a.y,DepthLevel-20),ZEROVEC,ZEROVEC),0);
        VCO_MIN->AddIndex(VCO_MIN->Points->Add(ToVec(d,b.y,DepthLevel-20),ZEROVEC,ZEROVEC),0);
    }
    for(double d = a.y; d < b.y; d += Attr.Step)
    {
        VCO_MIN->AddIndex(VCO_MIN->Points->Add(ToVec(a.x,d,DepthLevel-20),ZEROVEC,ZEROVEC),0);
        VCO_MIN->AddIndex(VCO_MIN->Points->Add(ToVec(b.x,d,DepthLevel-20),ZEROVEC,ZEROVEC),0);
    }
    VCO_MIN->CalcNormals();

    VCO_MAX->Init();
    VCO_MAX->Color->Color = Attr.Colors.MAX;
    VCO_MAX->ColorAsMaterial = cmAmbient;
    VCO_MAX->AddPrimitiveArray(GL_LINES);
    TIntVec a2;
    a2.x = ((MBTi)floor( aa.x / (Attr.Step*Attr.Multiplier) ))*(Attr.Step*Attr.Multiplier);
    a2.y = ((MBTi)floor( aa.y / (Attr.Step*Attr.Multiplier) ))*(Attr.Step*Attr.Multiplier);
    for(double d = a2.x; d < b.x; d += Attr.Step*Attr.Multiplier)
    {
        VCO_MAX->AddIndex(VCO_MAX->Points->Add(ToVec(d,a2.y,DepthLevel-15),ZEROVEC,ZEROVEC),0);
        VCO_MAX->AddIndex(VCO_MAX->Points->Add(ToVec(d,b.y,DepthLevel-15),ZEROVEC,ZEROVEC),0);
    }
    for(double d = a2.y; d < b.y; d += Attr.Step*Attr.Multiplier)
    {
        VCO_MAX->AddIndex(VCO_MAX->Points->Add(ToVec(a2.x,d,DepthLevel-15),ZEROVEC,ZEROVEC),0);
        VCO_MAX->AddIndex(VCO_MAX->Points->Add(ToVec(b.x,d,DepthLevel-15),ZEROVEC,ZEROVEC),0);
    }
    VCO_MAX->CalcNormals();
    MBTi CurStep = Attr.Step;
    int i;
    for(i = 0; floor(CurStep) == 0; CurStep*=10, i++);
    Precision = i+1;
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

void TGrid::Render(TEditor2D* aView)
{
    if (!Attr.Visible)
        return;
    VCO_MIN->Color->Color = Attr.Colors.MIN;
    glLineWidth(Attr.LinesWidth.MIN);
    VCO_MIN->Render(aView->View);
    VCO_MAX->Color->Color = Attr.Colors.MAX;
    glLineWidth(Attr.LinesWidth.MAX);
    VCO_MAX->Render(aView->View);
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

int TSelected::FindCutIndex(int Index) const
{
    return  FindInList(&CutIndices,Index);
}

bool TSelection::FindCutAndFigureIndices(T2DGObject* MF, const int& FigureCutIndex, int& FigureIndex, int& SelectedCutIndex)
{
    SelectedCutIndex = FigureIndex = FindFigure(MF);
    if (FigureIndex == -1)
        return false;
    SelectedCutIndex = Figures[FigureIndex].FindCutIndex(FigureCutIndex);
    return (SelectedCutIndex != -1);
}

TDepthLevels::TDepthLevels()
{
/*    Grid = -3;
    Fixid = -2;
    Additional = -1;
    Figures = 0;
    Selected = 1;*/
/*    Grid = 10;
    Fixid = 20;
    Additional = 30;
    Figures = 40;
    Selected = 50;*/
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


