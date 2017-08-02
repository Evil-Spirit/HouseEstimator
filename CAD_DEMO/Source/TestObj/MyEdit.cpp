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

//---------------------------------------------------------------------------

#pragma package(smart_init)

TClassNode* TRedPoint::StaticType = NULL;
TClassNode* TRedCut::StaticType = NULL;
TClassNode* TMyFigure::StaticType = NULL;
TClassNode* TCustomFigure::StaticType = NULL;
TClassNode* TInfinityLine::StaticType = NULL;
TClassNode* TEditorAttributes::StaticType = NULL;
TClassNode* TGridAttributes::StaticType = NULL;
TClassNode* TGrid::StaticType = NULL;

const MBTi PEPS = 0.01;
const MBTi CutEps = 0.001;
//---------------------------------------------------------------------------
void TMyFigure::CreateRC()
{
    RotateCenter.x = (BBoxLU.x + BBoxRD.x)/2;
    RotateCenter.y = (BBoxLU.y + BBoxRD.y)/2;
}

void TMyFigure::CreateBBox()
{
    MBTi minX = 1000000;
    MBTi minY = 1000000;
    MBTi maxX = -1000000;
    MBTi maxY = -1000000;
    for (int i = 0; i < PointsCount; i++)
    {
        if (minX > GetPoint(i).Point.x)
            minX = GetPoint(i).Point.x;
        if (minY > GetPoint(i).Point.y)
            minY = GetPoint(i).Point.y;
        if (maxX < GetPoint(i).Point.x)
            maxX = GetPoint(i).Point.x;
        if (maxY < GetPoint(i).Point.y)
            maxY = GetPoint(i).Point.y;
    }
    BBoxLU.x = minX;
    BBoxLU.y = minY;
    BBoxRD.x = maxX;
    BBoxRD.y = maxY;
}

void TMyFigure::ProcessCreateView()
{
    if(NeedCreateView)
    {
        VCO->Init();
        VCO->Color->Color = Color;
        VCO->ColorAsMaterial = cmAmbient;
        VCO->AddPrimitiveArray(GL_POINTS);
        for(int i = 0; i < PointsCount; i++)
        {
            VCO->Points->Add(ToVec(GetPoint(i).Point.x, GetPoint(i).Point.y, GetPoint(i).Point.z),ZEROVEC,ZEROVEC);
            VCO->AddIndex(i,0);
        }
        VCO->AddPrimitiveArray(GL_LINES);
        for(int i = 0; i < CutsCount; i++)
        {
            VCO->AddIndex(IndexOfPoint(GetCut(i).Src),1);
            VCO->AddIndex(IndexOfPoint(GetCut(i).Dst),1);
        }
    }
   // NeedCreateView = false;
}

const AnsiString amfAdditional = "Additional";
const AnsiString amfFixid = "Fixid";
const AnsiString amfColor = "Color";
const AnsiString amfLineWidth = "LineWidth";

TMyFigure::TMyFigure()
{
    RegisterNewClass< TMyObject, TMyFigure >(this, true, &CreateFunction);
    VCO = new TVisPrimitiveObj(NULL);
    Color = clBlue;
    NeedCreateView = true;
    Additional = false;
    Fixid = false;
    LineWidth = 1;
    RegisterField(&Additional, &amfAdditional, mtBool);
    RegisterField(&Fixid, &amfFixid, mtBool);
    RegisterField(&Color, &amfColor, mtInt);
    RegisterField(&LineWidth, &amfLineWidth, mtInt);
}

TMyFigure::~TMyFigure()
{
    delete VCO;
}

void TMyFigure::AboutToChange(void* Sender)
{
    TMyObject::AboutToChange(Sender);
    if (Sender != &FColor && Sender != &FLineWidth)
        NeedCreateView = true;
}

void TMyFigure::SetColor(TColor AColor)
{
    AboutToChange(&FColor);
    FColor = AColor;
}

void TMyFigure::SetLineWidth(int ALineWidth)
{
    AboutToChange(&FLineWidth);
    FLineWidth = ALineWidth;
}

TMyObject* TMyFigure::CreateFunction()
{
    return new TMyFigure();
}

TRedCut& TMyFigure::GetCut(int i)
{
    throw EMyException("Can't use <TMyFigure::GetCut>");
}

TRedPoint& TMyFigure::GetPoint(int i)
{
    throw EMyException("Can't use <TMyFigure::GetPoint>");
}

const TRedCut& TMyFigure::GetCut(int i) const
{
    throw EMyException("Can't use <TMyFigure::GetCut>");
}

const TRedPoint& TMyFigure::GetPoint(int i) const
{
    throw EMyException("Can't use <TMyFigure::GetPoint>");
}

int TMyFigure::FindPoint(const TIntVec &V) const
{
    for(int i = 0; i < PointsCount; i++)
        if ( GetPoint(i).Point.Equal2D(V,PEPS) )
            return i;
    return -1;
}

int TMyFigure::IndexOfPoint(TRedPoint* Point) const
{
    for(int i = 0; i < PointsCount; i++)
        if (&GetPoint(i) == Point)
            return i;
    return -1;
}

int TMyFigure::IndexOfCut(TRedCut* Cut) const
{
    for(int i = 0; i < CutsCount; i++)
        if (&GetCut(i) == Cut)
            return i;
    return -1;
}

/*void TMyFigure::CreateView()
{
    NeedCreateView = true;
} */

void TMyFigure::Render(TMyView* aView)
{
    ProcessCreateView();
    VCO->Color->Color = TColor(Color);
    glLineWidth(LineWidth);
    VCO->Render(aView->View);
}

bool TMyFigure::Snap(const TIntVec &Point, TIntVec& SnapPoint, int& CutIndex, const MBTi CEPS, bool Infinity) const
{
    MBTi minCEPS = 100000000;
    int minIndex = -1;
    MBTi k1, k2, x, y, d;
    for (int i = 0; i < CutsCount; i++)
    {
        if (fabs(GetCut(i).Dst->Point.x - GetCut(i).Src->Point.x)<fabs(GetCut(i).Dst->Point.y - GetCut(i).Src->Point.y))
            if (fabs(GetCut(i).Dst->Point.x - GetCut(i).Src->Point.x)>CutEps)
            {
                k1 = (GetCut(i).Dst->Point.y - GetCut(i).Src->Point.y) / (GetCut(i).Dst->Point.x - GetCut(i).Src->Point.x);
                k2 = -1/k1;
                x = (k1*GetCut(i).Src->Point.x-GetCut(i).Src->Point.y-k2*Point.x+Point.y)/(k1 - k2);
                y = k2*(x-Point.x)+Point.y;
            }else{
                    x = GetCut(i).Dst->Point.x;
                    y = Point.y;
                    k1 = 0;
                 }
        else
            if (fabs(GetCut(i).Dst->Point.y - GetCut(i).Src->Point.y)>CutEps)
            {
                k1 = (GetCut(i).Dst->Point.x - GetCut(i).Src->Point.x) / (GetCut(i).Dst->Point.y - GetCut(i).Src->Point.y);
                k2 = -1/k1;
                y = (k1*GetCut(i).Src->Point.y-GetCut(i).Src->Point.x-k2*Point.y+Point.x)/(k1 - k2);
                x = k2*(y-Point.y)+Point.x;
            }else{
                     x = Point.x;
                     y = GetCut(i).Dst->Point.y;
                     k1 = 0;
                 }
        bool a,b;
        if (!Infinity)
        {
            if (GetCut(i).Src->Point.x > GetCut(i).Dst->Point.x)
                if (GetCut(i).Src->Point.x>=x && x>=GetCut(i).Dst->Point.x)
                    a = true;
                else
                    a = false;
            else
                if (GetCut(i).Src->Point.x<=x && x<=GetCut(i).Dst->Point.x)
                    a = true;
                else
                    a = false;
            if (GetCut(i).Src->Point.y > GetCut(i).Dst->Point.y)
                if (GetCut(i).Src->Point.y>=y && y>=GetCut(i).Dst->Point.y)
                    b = true;
                else
                    b = false;
            else
                if (GetCut(i).Src->Point.y<=y && y<=GetCut(i).Dst->Point.y)
                    b = true;
                else
                    b = false;
        }
        if((a&&b&&!Infinity)||Infinity)
        {
			d = sqrtDC(fabs(x-Point.x)*fabs(x-Point.x)+fabs(y-Point.y)*fabs(y-Point.y));
            if (d < minCEPS)
            {
                minCEPS = d;
                minIndex = i;
                CutIndex = minIndex;
                SnapPoint.x = x;
                SnapPoint.y = y;
                SnapPoint.z = Point.z;
            }
        }
    }
    if (minCEPS<=CEPS)
        return true;
    else
        return false;
}

TMyObject* TCustomFigure::CreateFunction()
{
    return new TCustomFigure();
}

void TCustomFigure::CutsToIndices(TMDelTList<int>& CutPointIndices) const
{
    for ( int i = 0; i < CUTS.Count; i++)
    {
        CutPointIndices.Add(new int(PNTS.IndexOf(CUTS[i].Src)));
        CutPointIndices.Add(new int(PNTS.IndexOf(CUTS[i].Dst)));
    }
}

void TCustomFigure::IndicesToCuts(TMDelTList<int>& CutPointIndices)
{
    CUTS.Clear();
    for ( int i = 0; i < CutPointIndices.Count; i+=2)
    {
        CUTS.Add(new TRedCut());
        CUTS.Last()->Src = PNTS.Items[CutPointIndices[i]];
        CUTS.Last()->Dst = PNTS.Items[CutPointIndices[i+1]];
    }

}

void TCustomFigure::SaveData(FILE *F) const
{
    TMyFigure::SaveData(F);
    TMDelTList<int> CutPointIndices;
    CutsToIndices(CutPointIndices);
    CutPointIndices.SaveData(F);
    CutPointIndices.Clear();
}

void TCustomFigure::LoadData(FILE *F)
{
    TMyFigure::LoadData(F);
    TMDelTList<int> CutPointIndices;
    CutPointIndices.LoadData(F);
    IndicesToCuts(CutPointIndices);
    CutPointIndices.Clear();
//    NeedCreateView = true;
}

    //запись и чтение в поток
void TCustomFigure::WriteData(TMemoryStream *MS) const
{
    TMyFigure::WriteData(MS);
    TMDelTList<int> CutPointIndices;
    CutsToIndices(CutPointIndices);
    CutPointIndices.WriteData(MS);
    CutPointIndices.Clear();
}

void TCustomFigure::ReadData(TMemoryStream *MS)
{
    TMyFigure::ReadData(MS);
    TMDelTList<int> CutPointIndices;
    CutPointIndices.ReadData(MS);
    IndicesToCuts(CutPointIndices);
    CutPointIndices.Clear();
//    NeedCreateView = true;
}

void TCustomFigure::Assign(TMyObject* MO)
{
    if (!MO->Is(TCustomFigure::StaticType) )
        throw EMyException("Copying error");

    TMyFigure::Assign(MO);

    TCustomFigure* CF = (TCustomFigure*)MO;
    TMDelTList<int> CutPointIndices;
    CF->CutsToIndices(CutPointIndices);
    IndicesToCuts(CutPointIndices);
    CutPointIndices.Clear();
}

const AnsiString aPNTS = "PNTS";
const AnsiString aCUTS = "CUTS";

TCustomFigure::TCustomFigure()
{
    RegisterNewClass< TMyFigure, TCustomFigure >(this, false, &CreateFunction);
    RegisterField(&PNTS, &aPNTS, mtMyObject);
    RegisterField(&CUTS, &aCUTS, mtMyObject);
}

int TCustomFigure::AddPoint(MBTi x, MBTi y, MBTi z)
{
    return AddPoint(TIntVec(x, y, z));
}

int TCustomFigure::AddPoint(const TIntVec& V)
{
    PNTS.Add(new TRedPoint);
    PNTS[PNTS.Count-1].Point = V;
    return PNTS.Count-1;
}
void TCustomFigure::AddCut(const TIntVec& P1,const TIntVec& P2)
{
    int Ind1 = AddPoint(P1);
    int Ind2 = AddPoint(P2);
    CUTS.Add(new TRedCut);
    CUTS[CUTS.Count-1].Src = PNTS.GetItem(Ind1);
    CUTS[CUTS.Count-1].Dst = PNTS.GetItem(Ind2);
    //CreateView();
    CreateBBox();
    CreateRC();
}

void TCustomFigure::ProcessDelPoint(TRedPoint* P)
{
    PNTS.Delete(PNTS.IndexOf(P));
}

void TCustomFigure::DelPoint(int Index)
{
    for(int i = 0;i < PNTS[Index].Cuts.Count;i++)
        DelCut(i);
}

int TCustomFigure::IndexOfPoint(TRedPoint* Point) const
{
    return PNTS.IndexOf(Point);
}

int TCustomFigure::IndexOfCut(TRedCut* Cut) const
{
    return CUTS.IndexOf(Cut);
}

void TCustomFigure::DelCut(int Index)
{
    TRedPoint* BufS = CUTS.Items[Index]->Src;
    TRedPoint* BufD = CUTS.Items[Index]->Dst;
    CUTS.Delete(Index);
    if(BufS->Cuts.Count == 0)
        ProcessDelPoint(BufS);
    if(BufD->Cuts.Count == 0)
        ProcessDelPoint(BufD);
    //CreateView();
    CreateBBox();
    CreateRC();
}

long int TCustomFigure::GetCutsCount() const
{
    return CUTS.Count;
}

long int TCustomFigure::GetPointsCount() const
{
    return PNTS.Count;
}

TRedCut& TCustomFigure::GetCut(int Index)
{
    return CUTS[Index];
}

TRedPoint& TCustomFigure::GetPoint(int Index)
{
    return PNTS[Index];
}

const TRedCut& TCustomFigure::GetCut(int Index) const
{
    return CUTS[Index];
}

const TRedPoint& TCustomFigure::GetPoint(int Index) const
{
    return PNTS[Index];
}

/*TIntVec* TCustomFigure::GetVector(int Index)
{
    return &PNTS[Index].Point;
}

void TCustomFigure::SetVector(int Index, const TIntVec& Vector)
{
    PNTS[Index].Point = Vector;
}*/
//------------------------------TInfinityLine------------------------------------------------
TMyObject* TInfinityLine::CreateFunction()
{
    return new TInfinityLine();
}

const AnsiString aRedPoints0 = "RedPoints[0]";
const AnsiString aRedPoints1 = "RedPoints[1]";
TInfinityLine::TInfinityLine()
{
    RegisterNewClass< TMyFigure, TInfinityLine >(this, false, &CreateFunction);
    VCO->Init();
    VCO->Color->Color = Color;
    VCO->ColorAsMaterial = cmAmbient;
    VCO->AddPrimitiveArray(GL_POINTS);
    VCO->AddPrimitiveArray(GL_LINES);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(VCO->Points->Add(ToVec(0,0,0),ZEROVEC,ZEROVEC),0);
    VCO->AddIndex(0,1);
    VCO->AddIndex(1,1);
    VCO->CalcNormals();
    Additional = true;
    RegisterField(&RedPoint[0], &aRedPoints0, mtMyObject);
    RegisterField(&RedPoint[1], &aRedPoints1, mtMyObject);
}

void TInfinityLine::Render(TMyView* aView)
{
//    CreateView();
    if (NeedCreateView)
    {
        TIntVec a = aView->ScreenToProject(0, aView->View->Height, 0);
        TIntVec b = aView->ScreenToProject(aView->View->Width, 0, 0);
        if (a.x > b.x)
        {
            MBTi buff = a.x;
            a.x = b.x;
            b.x = buff;
        }
        if (a.y > b.y)
        {
            MBTi buff = a.y;
            a.y = b.y;
            b.y = buff;
        }
        TIntVec P,V1,V2;
        bool V1b = false;
        bool V2b = false;
        int ICC = IsLinesCrossedExactly(TIntVec(a.x, a.y, 0),
                                       TIntVec(b.x, a.y, 0),
                                       GetPoint(0).Point,
                                       GetPoint(1).Point,P);
        if (ICC == lcCROSSING)
            if (P.x >= a.x && P.x < b.x)
            {
                V1 = P;
                V1b = true;
            }
        ICC = IsLinesCrossedExactly(TIntVec(b.x, a.y, 0),
                                    TIntVec(b.x, b.y, 0),
                                       GetPoint(0).Point,
                                       GetPoint(1).Point,P);
        if (ICC == lcCROSSING)
            if (P.y >= a.y && P.y < b.y)
                if (V1b)
                {
                    V2 = P;
                    V2b = true;
                }else
                {
                    V1 = P;
                    V1b = true;
                }
        ICC = IsLinesCrossedExactly(TIntVec(a.x, b.y, 0),
                                    TIntVec(b.x, b.y, 0),
                                       GetPoint(0).Point,
                                       GetPoint(1).Point,P);
        if (ICC == lcCROSSING)
            if (P.x >= a.x && P.x < b.x)
                if (V1b)
                {
                    V2 = P;
                    V2b = true;
                }else
                {
                    V1 = P;
                    V1b = true;
                }
        ICC = IsLinesCrossedExactly(TIntVec(a.x, a.y, 0),
                                    TIntVec(a.x, b.y, 0),
                                       GetPoint(0).Point,
                                       GetPoint(1).Point,P);
        if (ICC == lcCROSSING || ICC == lcCOMMONPOINT)
            if (P.y >= a.y && P.y < b.y)
                if (V1b)
                {
                    V2 = P;
                    V2b = true;
                }else
                {
                    V1 = P;
                    V1b = true;
                }
        if (V1b && V2b && (V1 != V2) )
        {
            RedPoint[0].Point = V1;
            RedPoint[1].Point = V2;
            VCO->Points->Point[0][0] = V1.x;
            VCO->Points->Point[0][1] = V1.y;
            VCO->Points->Point[0][2] = V1.z;
            VCO->Points->Point[1][0] = V2.x;
            VCO->Points->Point[1][1] = V2.y;
            VCO->Points->Point[1][2] = V2.z;
            VCO->CalcNormals();
        }
    }
    VCO->Color->Color = Color;
    glLineWidth(LineWidth);
    VCO->Render(aView->View);
}

void TInfinityLine::LoadData(FILE *F)
{
    TMyFigure::LoadData(F);
    RedCut.Src = &GetPoint(0);
    RedCut.Dst = &GetPoint(1);
//    NeedCreateView = true;
}

void TInfinityLine::ReadData(TMemoryStream *MS)
{
    TMyFigure::ReadData(MS);
    RedCut.Src = &GetPoint(0);
    RedCut.Dst = &GetPoint(1);
 //   NeedCreateView = true;
}

void TInfinityLine::Assign(TMyObject* MO)
{
    if (!MO->Is(TInfinityLine::StaticType))
        throw EMyException("Copying error");
    TMyFigure::Assign(MO);
    RedCut.Src = &GetPoint(0);
    RedCut.Dst = &GetPoint(1);
}

TRedCut& TInfinityLine::GetCut(int Index)
{
    return RedCut;
}

TRedPoint& TInfinityLine::GetPoint(int Index)
{
    return RedPoint[Index];
}

const TRedCut& TInfinityLine::GetCut(int Index) const
{
    return RedCut;
}

const TRedPoint& TInfinityLine::GetPoint(int Index) const 
{
    return RedPoint[Index];
}

/*void TInfinityLine::SetPointCoordinate(int Index, TIntVec V)
{
    FirstPoints[Index] = V;
}*/

//------------------------------TInfinityLine------------------------------------------------
const AnsiString arpPoint = "Point";
TRedPoint::TRedPoint()
{
    RegisterNewClass< TMyObject, TRedPoint >(this, false, &CreateFunction);
    RegisterField(&Point, &arpPoint, mtIntVec);
}

TMyObject* TRedPoint::CreateFunction()
{
    return new TRedPoint();
}
//---------------------------------TRedCut--------------------------------------
TMyObject* TRedCut::CreateFunction()
{
    return new TRedCut();
}
TRedCut::TRedCut()
{
    RegisterNewClass< TMyObject, TRedCut >(this, true, &CreateFunction);
    FSrc=NULL;
    FDst=NULL;
}
TRedCut::~TRedCut()
{
    Src = NULL;
    Dst = NULL;
}

//функция привязки начальной точки
void TRedCut::SetSrc(TRedPoint* Value)
{
    AboutToChange(this);
    //если нач. точка уже задана то
    //уберем себя из ее списка отрезков
    if (FSrc)
        FSrc->Cuts.Remove(this);

    //задаем новую нач. точку
    FSrc = Value;

    //если нач. точка уже задана то
    //добавим себя в список ее отрезков
    if (FSrc)
        FSrc->Cuts.Add(this);
}

void TRedCut::SetDst(TRedPoint* Value)
{
    AboutToChange(this);
    //если кон. точка уже задана то
    //уберем себя из ее списка отрезков
    if (FDst)
        FDst->Cuts.Remove(this);
    //задаем новую кон. точку
    FDst = Value;
    //если кон. точка уже задана то
    //добавим себя в список ее отрезков
    if (FDst)
        FDst->Cuts.Add(this);
}

/*//находим отрезок по двум точкам
TRedCut* GetCut(TRedPoint* P1,TRedPoint* P2)
{
    //просто перебираем список отрезков одной из точек
    for (int i=0;i<P1->Cuts.Count;i++)
        if ( P1->Cuts[i].ConsistsDstAndSrc(P1,P2) )
            return P1->Cuts.Items[i];
    return NULL;
}
*/
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
    VCO_OSI->Color->Color = Attr.Colors.OSI;
    glLineWidth(Attr.LinesWidth.OSI);
    VCO_OSI->Render(aView->View);

    if (Attr.Minimal)
        return;
        
    VCO_MIN->Color->Color = Attr.Colors.MIN;
    glLineWidth(Attr.LinesWidth.MIN);
    VCO_MIN->Render(aView->View);
    
    VCO_MAX->Color->Color = Attr.Colors.MAX;
    glLineWidth(Attr.LinesWidth.MAX);
    VCO_MAX->Render(aView->View);
}

TGrid::~TGrid()
{
//    delete Mat;
    delete VCO_MIN;
    delete VCO_MAX;
    delete VCO_OSI;
}

int TSelection::FindFigure(TMyFigure* MF) const
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

bool TSelection::FindCutAndFigureIndices(TMyFigure* MF, const int& FigureCutIndex, int& FigureIndex, int& SelectedCutIndex)
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
    Grid = 0.001;
    Fixid = 0.002;
    Additional = 0.003;
    Figures = 0.004;
    Selected = 0.005;
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

