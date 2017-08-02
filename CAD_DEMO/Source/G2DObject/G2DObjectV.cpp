//---------------------------------------------------------------------------

#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "math.h"
#include "G2DPointCutV.h"
#include "G2DFunctionsV.h"
#include "G2DDistanceLinkV.h"
#include "G2DAngleLinkV.h"

#include "G2DKinematics.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
const MBTi PointEPS = PEPS;
const MBTi CutEps = 0.001;
TClassNode* T2DGObject::StaticType = NULL;
TClassNode* TG2DLink::StaticType = NULL;

void RegisterTG2DObject()
{
    TG2DCut();
    TG2DPoint();
    TAngleLink();
    TDistanceLink();
    T2DGObject();
    TDegreeRule();
    TCircleDegreeRule();
    TLineDegreeRule();
    TCircleDegreeOfAngle();
}
#pragma startup RegisterTG2DObject

void SetFlag(TGeomFlags &tgt, TClassifyFlags Flag, TClassify State)
{
	if (Flag & flORIGIN)
		tgt.Origin = State;
	if (Flag & flHOLE)
		tgt.Hole = State;
	if (Flag & flINTERSECT)
		tgt.Intersect = State;
	if (Flag & flCONTOUR)
		tgt.Contour = State;
	if (Flag & flMARK)
		tgt.Mark = State;
	if (Flag & flBELONG)
		tgt.Belong = State;
	if (Flag & flALREDY)
		tgt.Alredy = State;
	if (Flag & flSAME)
		tgt.Same = State;
	if (Flag & flERROR)
		tgt.Error = State;
	if (Flag & flCACHED)
		tgt.Cached = State;
}

void T2DGObject::FillLinksFlags(TClassifyFlags Flag, TClassify State)
{
    FillLinksFlags(FLinks, Flag, State);
}

void T2DGObject::FillLinksFlags(TMTList <TG2DLink> &Links, TClassifyFlags Flag, TClassify State)
{
	for (int i=0;i<Links.Count;i++)
		SetFlag(Links[i].FFlags, Flag, State);
}

bool TG2DLink::IsLinkedTo(TMTList<TG2DPoint>& Skeleton,TG2DPoint* Point)
{
    TMTList<TG2DPoint> NotInList;
    return (GetFreePoints(Skeleton,NotInList) && NotInList.IndexOf(Point) != -1);
}

TG2DPoint* TG2DLink::ReadyToUpdate(const TMTList<TG2DPoint>& PointList)
{
    TMTList<TG2DPoint> NotInList;
    GetFreePoints(PointList,NotInList);
    if (NotInList.Count == 1)
        return NotInList.Items[0];
    else
        return NULL;
}

bool TG2DLink::IsLinkCompleted(const TMTList<TG2DPoint>& PointList,const TG2DPoint* Point)
{
    return ReadyToUpdate(PointList) == Point;
}

TMyObject* TG2DLink::CreateFunction()
{
    return new TG2DLink();
}

const AnsiString aFFlags = AnsiString("FFlags");

TG2DLink::TG2DLink()
{
    RegisterNewClass<TGBaseLink,TG2DLink>(this,false,&CreateFunction);
    RegisterField(&FFlags,&aFFlags,mtInt);
	memset(&FFlags, 0, sizeof(FFlags));
}

TG2DLink::~TG2DLink()
{          
}

//-----------------------------------------------------------------------------
TG2DCut& T2DGObject::GetCut(int index)
{
    return (TG2DCut&)TGeomObject::GetCut(index);
}

const TG2DCut& T2DGObject::GetCut(int index) const
{
    return (TG2DCut&)TGeomObject::GetCut(index);
}

TG2DPoint& T2DGObject::GetVertex(int index)
{
    return (TG2DPoint&)TGeomObject::GetVertex(index);
}

const TG2DPoint& T2DGObject::GetVertex(int index) const
{
    return (TG2DPoint&)TGeomObject::GetVertex(index);
}


int T2DGObject::GetLinkCount()
{
    return FLinks.Count;
}

void T2DGObject::FromGeomObject(TGeomObject* GO)
{
    Clear();
    for ( int i=0;i<GO->VertexCount;i++ )
        AddPoint( GO->GetVertex(i).Point );

    for ( int i=0;i<GO->CutsCount;i++ )
        AddCut( &GetVertex( GO->IndexOf(GO->GetCut(i).Src) ),&GetVertex( GO->IndexOf(GO->GetCut(i).Dst) ) );

}


void T2DGObject::ToGeomObject(TGeomObject* GO)
{
    GO->Clear();
    for ( int i=0;i<VertexCount;i++ )
        GO->AddPoint( GetVertex(i).Point );

    for ( int i=0;i<CutsCount;i++ )
        GO->AddCut( &GO->GetVertex( IndexOf(GetCut(i).Src) ),&GO->GetVertex( IndexOf(GetCut(i).Dst) ) );
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void T2DGObject::CreateRC()
{
    RotateCenter.x = (BBoxLU.x + BBoxRD.x)/2;
    RotateCenter.y = (BBoxLU.y + BBoxRD.y)/2;
}

void T2DGObject::CreateBBox()
{
    MBTi minX = 1000000;
    MBTi minY = 1000000;
    MBTi maxX = -1000000;
    MBTi maxY = -1000000;
    for (int i = 0; i < VertexCount; i++)
    {
        if (minX > GetVertex(i).Point.x)
            minX = GetVertex(i).Point.x;
        if (minY > GetVertex(i).Point.y)
            minY = GetVertex(i).Point.y;
        if (maxX < GetVertex(i).Point.x)
            maxX = GetVertex(i).Point.x;
        if (maxY < GetVertex(i).Point.y)
            maxY = GetVertex(i).Point.y;
    }
    BBoxLU.x = minX;
    BBoxLU.y = minY;
    BBoxRD.x = maxX;
    BBoxRD.y = maxY;
}

const AnsiString amfAdditional = "Additional";
const AnsiString amfFixid = "Fixid";
const AnsiString amfColor = "Color";
const AnsiString amfLineWidth = "LineWidth";
const AnsiString amfLinks = "Links";

T2DGObject::T2DGObject()
    :
    PointPen( *(new TVisPen()) ),
    RibPen( *(new TVisPen()) ),
    LinkPen( *(new TVisPen()) ),
    GP_ZERO( *(new TG2DPoint()) ),
    GP_X_AXE( *(new TG2DPoint()) ),
    GP_Y_AXE( *(new TG2DPoint()) ),
    GP_X( *(new TG2DCut()) ),
    GP_Y( *(new TG2DCut()) )
{

    pFlowInfo = NULL;
    NeedCreateView = true;
    RegisterNewClass< TGeomObject, T2DGObject >(this, true, &CreateFunction);
    Additional = false;
    Fixid = false;
    RegisterField(&Additional, &amfAdditional, mtBool);
    RegisterField(&Fixid, &amfFixid, mtBool);
    RegisterField(&FLinks, &amfLinks, mtMyObject);

    PointPen.Width = 3;
    PointPen.Color = clSilver;
    RibPen.Width = 1;
    RibPen.Color = clSilver;
    LinkPen.Width = 1;
    LinkPen.Color = clYellow;
    //----Use TG2DPoint-----------
    TG2DPoint();
    CreatePointFunction = TG2DPoint::StaticType->CreateFunction;
    CreateCutFunction = TG2DCut::StaticType->CreateFunction;
    //----------------------------------------------------------
    GP_X_AXE.Point.x = 1;
    GP_Y_AXE.Point.y = 1;
    GP_X.Src = &GP_ZERO;
    GP_X.Dst = &GP_X_AXE;
    GP_Y.Src = &GP_ZERO;
    GP_Y.Dst = &GP_Y_AXE;
}

T2DGObject::~T2DGObject()
{
    delete &PointPen;
    delete &RibPen;
    delete &LinkPen;

    delete &GP_ZERO;
    delete &GP_X_AXE;
    delete &GP_Y_AXE;
    delete &GP_X;
    delete &GP_Y;

}

void T2DGObject::CreateView()
{
    NeedCreateView = true;    
}

void T2DGObject::ProcessCreateView()
{
    if (NeedCreateView)
    {
        NeedCreateView = false;
    }
}

void SetAttribs()
{
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
    glDisable(GL_CLIP_PLANE2);
    glDisable(GL_CLIP_PLANE3);
    glDisable(GL_CLIP_PLANE4);
    glDisable(GL_CLIP_PLANE5);
    glDisable(GL_CULL_FACE);
    glDisable(GL_POLYGON_SMOOTH);
    glDisable(GL_DITHER);
    glDisable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
    glShadeModel(GL_FLAT);
}

void ResetAttribs()
{
    glPopAttrib();
    glEnable(GL_DEPTH_TEST);
}

void T2DGObject::RenderSelection(
                            TVisView* aView,
                            const TVisPen& SelPointPen,
                            const TVisPen& SelRibPen,
                            const TVisPen& SelLinkPen,
                            TMTList<TGPoint>& SelPoints,
                            TMTList<TGCut>& SelCuts,
                            TMTList<TG2DLink>& SelLinks
                             )
{
    //-----------------
    SetAttribs();
    //-----------------

    //origin
    SetPen(*aView->Canvas->Pen,SelPointPen,NULL);
    aView->Canvas->Pen->Color = clOrange;
    aView->Canvas->ExecutePenAttribs(true);
    glPointSize(SelPointPen.Width);
    glBegin(GL_POINTS);
    glVertex3fv( (float*)(&GP_ZERO.Point) );
    glVertex3fv( (float*)(&GP_X_AXE.Point) );
    glVertex3fv( (float*)(&GP_Y_AXE.Point) );
    glEnd();
    SetPen(*aView->Canvas->Pen,SelRibPen,NULL);
    aView->Canvas->Pen->Color = clOrange;
    aView->Canvas->ExecutePenAttribs(true);
    glBegin(GL_LINES);
    for ( int i=0;i<SelCuts.Count;i++ )
    {
        glVertex3fv( (float*)(&GP_ZERO.Point) );
        glVertex3fv( (float*)(&GP_X_AXE.Point) );
        glVertex3fv( (float*)(&GP_ZERO.Point) );
        glVertex3fv( (float*)(&GP_Y_AXE.Point) );
    }
    glEnd();


    //links
    SetPen(*aView->Canvas->Pen,SelLinkPen,NULL);
    aView->Canvas->ExecutePenAttribs(true);
    for (int i = 0;i<SelLinks.Count;i++)
    {
        //if (SelLinks[i].Visible)
        {
            SelLinks[i].Label->Font->Color =  SelLinkPen.Color;
            SelLinks[i].Render(aView);
        }
    }

    //points
    SetPen(*aView->Canvas->Pen,SelPointPen,NULL);
    aView->Canvas->ExecutePenAttribs(true);
    glPointSize(SelPointPen.Width);
    glBegin(GL_POINTS);
    for ( int i=0;i<SelPoints.Count;i++ )
        glVertex3fv( (float*)(&SelPoints[i].Point) );
    glEnd();

    //lines
    SetPen(*aView->Canvas->Pen,SelRibPen,NULL);
    aView->Canvas->ExecutePenAttribs(true);
    glBegin(GL_LINES);
    for ( int i=0;i<SelCuts.Count;i++ )
    {
        glVertex3fv( (float*)(&SelCuts[i].Src->Point) );
        glVertex3fv( (float*)(&SelCuts[i].Dst->Point) );
    }
    glEnd();

    ResetAttribs();
}



void T2DGObject::Render(TVisView* aView)
{
    RenderSelection(
                        aView,
                        PointPen,
                        RibPen,
                        LinkPen,
                        FVertex,
                        FCuts,
                        FLinks ); 
}

TMyObject* T2DGObject::CreateFunction()
{
    return new T2DGObject();
}

int T2DGObject::FindPoint(const TIntVec &V) const
{
    for(int i = 0; i <  VertexCount; i++)
        if ( GetVertex(i).Point.Equal2D(V,PointEPS) )
            return i;
    return -1;
}

/*void T2DGObject::Render(TEditor2D* aView)
{
    ProcessCreateView();
    VCO->Color->Color = TColor(Color);
    glLineWidth(LineWidth);
    VCO->Render(aView->View);
}*/

bool T2DGObject::Snap(const TIntVec &Point, TIntVec& SnapPoint, int& CutIndex, const MBTi CEPS, bool Infinity) const
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

TG2DLink& T2DGObject::GetLink(int index)
{
    return FLinks[index];
}

int T2DGObject::AddLink(TG2DLink* Link)
{
    return FLinks.Add(Link);
}

void T2DGObject::MakeTempPoints()
{
    for ( int i=0;i<FVertex.Count;i++ )
        ((TG2DPoint*)FVertex.Items[i])->Temp = ((TG2DPoint*)FVertex.Items[i])->Point;
}

void T2DGObject::ReturnTempPoints()
{
    for ( int i=0;i<FVertex.Count;i++ )
        ((TG2DPoint*)FVertex.Items[i])->Point = ((TG2DPoint*)FVertex.Items[i])->Temp;
}


TG2DLink* CreateAngleLink(TG2DCut* Cut1,TG2DCut* Cut2,TAngleLinkSector aAngleLinkSector)
{
    TAngleLink* AngleLink = new TAngleLink();
    AngleLink->Client0 = Cut1;
    AngleLink->Client1 = Cut2;

    AngleLink->AngleLinkSector = aAngleLinkSector;

    MBTi Length0 = (AngleLink->Client0->Dst->Point - AngleLink->Client0->Src->Point).Length();
    MBTi Length1 = (AngleLink->Client1->Dst->Point - AngleLink->Client1->Src->Point).Length();
    AngleLink->LabelRadius = MIN(Length0,Length1);
    AngleLink->Angle = (AngleRad(   AngleLink->Client1->Src->Point,
                                    AngleLink->Client1->Dst->Point,
                                    AngleLink->Client0->Src->Point,
                                    AngleLink->Client0->Dst->Point)*180)/M_PI;
    return AngleLink;
}

TG2DLink* CreateDistanceLink(TG2DPoint* Point1,TG2DPoint* Point2)
{
    TDistanceLink* DistanceLink = new TDistanceLink();
    DistanceLink->Client0 = Point1;
    DistanceLink->Client1 = Point2;
    DistanceLink->Distance = (Point2->Point - Point1->Point).Length();
    return DistanceLink;
}


TG2DLink* T2DGObject::MakeAngleLink(TG2DCut* Cut1,TG2DCut* Cut2,TAngleLinkSector aAngleLinkSector)
{
    for ( int i=0;i<FLinks.Count;i++ )
        if (    FLinks[i].Is( TAngleLink::StaticType ) &&
                Cut1 != Cut2 &&
                FLinks[i].ConsistsClient(Cut1) &&
                FLinks[i].ConsistsClient(Cut2) )
            throw EMyException("<T2DGObject::MakeAngleLink>: связка уже существует.");
            
    FLinks.Add( CreateAngleLink(Cut1,Cut2,aAngleLinkSector) );
    return FLinks.Last();
}

TG2DLink* T2DGObject::MakeDistanceLink(TG2DPoint* Point1,TG2DPoint* Point2)
{
    for ( int i=0;i<FLinks.Count;i++ )
        if ( FLinks[i].Is( TDistanceLink::StaticType ) &&
                Point1 != Point2 &&
                FLinks[i].ConsistsClient(Point1) &&
                FLinks[i].ConsistsClient(Point2) )
            throw EMyException("<T2DGObject::MakeDistanceLink>: связка уже существует.");

    FLinks.Add( CreateDistanceLink(Point1,Point2) );
    return FLinks.Last();
}

void T2DGObject::Clear() // Очистить геометрический обьект
{
    FLinks.Clear();
    TGeomObject::Clear();
}


void T2DGObject::SelectGroupForPointRec(TG2DPoint* Point,TFlowInfo& FlowInfo)
{
}

bool T2DGObject::LinkOnTheSet(TMTList<TG2DPoint> &PntList,TG2DLink* Link)
{
    for (int i=0;i<PntList.Count;i++)
        for (int j=i+1;j<PntList.Count;j++)
            if ( Link->IsLinked(PntList.Items[i],PntList.Items[j]) )
                return true;
    return false;
}


//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void T2DGObject::SelectGroupForPoint(TG2DPoint* Point,TFlowInfo& FlowInfo)
{
    FillPointsFlags(flMARK,gfFALSE);
    FlowInfo.AllPntList.Add(Point);
    Point->Flags.Mark = gfTRUE;
    bool WasAdded = true;
    while (WasAdded)
    {
        WasAdded = false;
        for ( int i=0;i<FVertex.Count;i++ )
            if ( FVertex.Items[i]->Flags.Mark != gfTRUE  )
                if (  IsLinkedTo(FlowInfo.AllPntList,(TG2DPoint*)FVertex.Items[i],true, TMTList<TG2DLink>() )  )
                {
                    FlowInfo.AllPntList.Add( (TG2DPoint*)FVertex.Items[i] );
                    FVertex.Items[i]->Flags.Mark = gfTRUE;
                    WasAdded = true;
                }
    }

    //--------------------------------------------------------------------------
    for ( int i=0;i<FLinks.Count;i++ )
        if ( LinkOnTheSet( FlowInfo.AllPntList,FLinks.Items[i] ) )
            FlowInfo.AllLinks.Add( FLinks.Items[i] );
    //--------------------------------------------------------------------------
    for (int i=0;i<FCuts.Count;i++)
        if (FlowInfo.AllPntList.IndexOf( (TG2DPoint*)FCuts[i].Src ) != -1 &&
            FlowInfo.AllPntList.IndexOf( (TG2DPoint*)FCuts[i].Dst ) != -1 )
            FlowInfo.AllCutList.Add( (TG2DCut*)FCuts.Items[i] );
}

//--------------------------------------------------------------------------
void T2DGObject::Delete(TGBaseLink* Link)
{
    DeleteLink( FLinks.IndexOf((TG2DLink*)Link) );
}

void T2DGObject::DeleteLink(int index)
{
    FLinks.Delete(index);    
}

void T2DGObject::Delete(TGCut* Cut)
{
    DeleteCut( FCuts.IndexOf(Cut) );
}

void T2DGObject::Delete(TGPoint* Point)
{
    DeletePoint( FVertex.IndexOf(Point) );
}

void T2DGObject::DeleteCut(int index)
{
    while ( GetCut(index).LinksCount )
        Delete( &GetCut(index).GetLink(0) );
    TGeomObject::DeleteCut(index);
}

void T2DGObject::DeletePoint(int index)
{
    while ( GetVertex(index).LinksCount )
        Delete( &GetVertex(index).GetLink(0) );
    TGeomObject::DeletePoint(index);
}

void T2DGObject::Delete(TGPolygon* Link)
{
    TGeomObject::Delete(Link);
}

TMTList<TG2DPoint> _Points;
void T2DGObject::PrepareMoving(TG2DPoint* Point)
{
    if (pFlowInfo)
        throw EMyException("<T2DGObject::PrepareMoving>: текущая операция позиционирования не заверешена.");
    pFlowInfo = new TFlowInfo();
    pFlowInfo->Owner = this;
    pFlowInfo->_MainPoint = Point;
    SelectGroupForPoint(Point,*pFlowInfo);
    pFlowInfo->CreateInfluence(Point);
}

void T2DGObject::EndMoving()
{
    for ( int i=0;i<FVertex.Count;i++ )
        ((TG2DPoint&)FVertex[i]).Rules.Clear();
    for ( int i=0;i<FCuts.Count;i++ )
        ((TG2DCut&)FCuts[i]).Rules.Clear();
    GP_ZERO.Rules.Clear();
    GP_X_AXE.Rules.Clear();
    GP_Y_AXE.Rules.Clear();
    GP_X.Rules.Clear();
    GP_Y.Rules.Clear();
    delete pFlowInfo;
    pFlowInfo = NULL;
}

void T2DGObject::ContinueMoving(const TIntVec& NewValue)
{
    MakeTempPoints();
    pFlowInfo->_MainPoint->Point = NewValue;
    bool Result = true;
    for (int i=0;i<pFlowInfo->InfluenceSequence.Count;i++)
        Result = Result && pFlowInfo->InfluenceSequence[i].Update();
    if (!Result)
        ReturnTempPoints();
}
