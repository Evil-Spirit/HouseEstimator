//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "Poligon.h"
#include "MyGL.h"
#include "G2DAngleLinkV.h"
#include "G2DFunctionsV.h"
#include "G2DObjectV.h"
#include "G2DPointCutV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TMTList<TG2DPoint> ____PointList;
TClassNode* TAngleLink::StaticType = NULL;

bool TAngleLink::HaveLinked(const TMTList<TG2DPoint>& PointList,const TG2DPoint* Point)
{
//    GetFreePoints(PointList,)
    if( PointList.IndexOf( (TG2DPoint*)Client0->Src )!=-1 &&
                PointList.IndexOf( (TG2DPoint*)Client0->Dst )!=-1 )
        return Client1->ConsistsPoint(Point);
    else if (PointList.IndexOf( (TG2DPoint*)Client0->Src )!=-1 &&
                PointList.IndexOf( (TG2DPoint*)Client0->Dst )!=-1)
        return Client0->ConsistsPoint(Point);
    else
        return false;
}

bool TAngleLink::IsLinked(TG2DPoint* GPoint0,TG2DPoint* GPoint1)
{
    return  (  (Client0->ConsistsPoint(GPoint0) &&
                Client1->ConsistsPoint(GPoint1))
                    ||
               (Client1->ConsistsPoint(GPoint0) &&
                Client0->ConsistsPoint(GPoint1))
            );
}

bool TAngleLink::PointInLink(TG2DPoint* Point)
{
    return Client0->ConsistsPoint(Point) || Client1->ConsistsPoint(Point);
}

bool TAngleLink::GetFreePoints(const TMTList<TG2DPoint>& PointList,TMTList<TG2DPoint>& FreePointList)
{
    FreePointList.Clear();
    bool Result = false;
    if ( PointList.IndexOf( (TG2DPoint*)Client0->Src ) == -1 )
    {
        if (FreePointList.IndexOf((TG2DPoint*)Client0->Src) == -1)
            FreePointList.Add( (TG2DPoint*)Client0->Src );
    }
    else
        Result = true;

    if ( PointList.IndexOf( (TG2DPoint*)Client1->Src ) == -1 )
    {
        if (FreePointList.IndexOf((TG2DPoint*)Client1->Src) == -1)
            FreePointList.Add( (TG2DPoint*)Client1->Src );
    }
    else
        Result = true;

    if ( PointList.IndexOf( (TG2DPoint*)Client0->Dst ) == -1 )
    {
        if (FreePointList.IndexOf((TG2DPoint*)Client0->Dst) == -1)
            FreePointList.Add( (TG2DPoint*)Client0->Dst );
    }
    else
        Result = true;
    if ( PointList.IndexOf( (TG2DPoint*)Client1->Dst ) == -1 )
    {
        if (FreePointList.IndexOf((TG2DPoint*)Client1->Dst) == -1)
            FreePointList.Add( (TG2DPoint*)Client1->Dst );
    }
    else
        Result = true;
    return Result && FreePointList.Count>0;
}

TG2DPoint* TAngleLink::GetXStart()
{
    switch ( AngleLinkSector )
    {
        case    alsFirst:   return (TG2DPoint*)Client0->Src;
        case    alsSecond:  return (TG2DPoint*)Client1->Src;
        case    alsThird:   return (TG2DPoint*)Client0->Dst;
        default:            return (TG2DPoint*)Client1->Dst;
    }        
}

TG2DPoint* TAngleLink::GetXEnd()
{
    switch ( AngleLinkSector )
    {
        case    alsFirst:   return (TG2DPoint*)Client0->Dst;
        case    alsSecond:  return (TG2DPoint*)Client1->Dst;
        case    alsThird:   return (TG2DPoint*)Client0->Src;
        default:            return (TG2DPoint*)Client1->Src;
    }
}

TG2DPoint* TAngleLink::GetYStart()
{
    switch ( AngleLinkSector )
    {
        case    alsFirst:   return (TG2DPoint*)Client1->Src;
        case    alsSecond:  return (TG2DPoint*)Client0->Dst;
        case    alsThird:   return (TG2DPoint*)Client1->Dst;
        default:            return (TG2DPoint*)Client0->Src;
    }            
};

TG2DPoint* TAngleLink::GetYEnd()
{
    switch ( AngleLinkSector )
    {
        case    alsFirst:   return (TG2DPoint*)Client1->Dst;
        case    alsSecond:  return (TG2DPoint*)Client0->Src;
        case    alsThird:   return (TG2DPoint*)Client1->Src;
        default:            return (TG2DPoint*)Client0->Dst;
    }
}

bool TAngleLink::IsBestToUpdate(TG2DPoint* GPoint)
{
    if (!GPoint)
        throw EMyException("<TAngleLink::IsBestToUpdate>: Ошибка");
    return GPoint != Client0->CanConnect(*Client1);
};

bool TAngleLink::UpdatePointRule(TG2DPoint* GPoint)
{
    TG2DPoint* Client = AssertCast<TG2DPoint>("<TAngleLink::UpdatePointRule>",GPoint);

    TG2DPoint* XStart = GetXStart();
    TG2DPoint* XEnd = GetXEnd();
    TG2DPoint* YStart = GetYStart();
    TG2DPoint* YEnd = GetYEnd();

    for (int i=0;i<Client->Rules.Count;i++)
        if ( Client->Rules[i].GLink == this )
            Client->Rules.Delete(i--);
    if ( GPoint == Client0->CanConnect(*Client1) )
    {
        MBTi UseAngle = Angle;
        TCircleDegreeOfAngle* Rule = new TCircleDegreeOfAngle();
        Client->Rules.Add(Rule);

        if ( GPoint != YStart )
        {
            ExchangeItem<TG2DPoint*>(YEnd,YStart);
            UseAngle = UseAngle+180;
        }
        if ( GPoint != XStart )
        {
            ExchangeItem<TG2DPoint*>(XEnd,XStart);
            UseAngle = UseAngle-180;
        }
        if (UseAngle>=360)
            UseAngle -= 360;
        if (UseAngle<0)
            UseAngle += 360;
        if ( UseAngle>=180 )
        {
            UseAngle = 360 - UseAngle;
            ExchangeItem<TG2DPoint*>(YEnd,XEnd);
        }
        Rule->GPX_DST = XEnd;
        Rule->GPY_DST = YEnd;
        
        Rule->Angle = UseAngle;
        return true;
    }

    TLineDegreeRule* Rule = new TLineDegreeRule();
    Client->Rules.Add(Rule);

    if ( Client && (!Client0->ConsistsPoint(Client) && !Client1->ConsistsPoint(Client)) )
    {
        AnsiString Str = "<TAngleLink::UpdateClient>: точка не принадлежит связке";
        throw EMyException(Str);
    }


    MBTi UseAngle = Angle;

    if ( Client == XStart || Client == XEnd )
    {
        ExchangeItem<TG2DPoint*>(XStart,YStart);
        ExchangeItem<TG2DPoint*>(XEnd,YEnd);
        UseAngle = 360-UseAngle;
    }

    if ( Client == YStart )
    {
        ExchangeItem<TG2DPoint*>(YEnd,YStart);
        UseAngle = UseAngle+180;
    }

    Rule->GPX_SRC = (TG2DPoint*)XStart;
    Rule->GPX_DST = (TG2DPoint*)XEnd;
    Rule->GPY_SRC = (TG2DPoint*)YStart;
    Rule->Angle = UseAngle;
    return true;
}


/*void TAngleLink::UpdateAngleLink(TGUnit* _Client,TFlowInfo& FlowInfo)
{
    TG2DPoint* Client = AssertCast<TG2DPoint>("<TAngleLink::UpdateAngleLink>",_Client);
    T2DGObject* Owner = AssertCast<T2DGObject>("<TAngleLink::UpdateAngleLink>",FlowInfo.Object);

    if ( Client && (!Client0->ConsistsPoint(Client) && !Client1->ConsistsPoint(Client)) )
    {
        AnsiString Str = "<TAngleLink::UpdateClient>: точка не принадлежит связке";
        throw EMyException(Str);
    }

    TG2DPoint* XStart = GetXStart();
    TG2DPoint* XEnd = GetXEnd();
    TG2DPoint* YStart = GetYStart();
    TG2DPoint* YEnd = GetYEnd();

    if ( Client == XStart || Client == XEnd )
    {
        ExchangeItem<TG2DPoint*>(XStart,YStart);
        ExchangeItem<TG2DPoint*>(XEnd,YEnd);
    }

    TIntVec Center;
    int res = IsLinesCrossedExactly(XStart->Point,XEnd->Point,YStart->Point,YEnd->Point,Center);
    if ( res == lcPARALLEL || res == lcCOLLINEAR )
    {
        throw EMyException("MSG_ERR_7");
    }

    TIntVec XRay = (XEnd->Point-XStart->Point).Normalize();
    MBTi Length = (YEnd->Point-YStart->Point).Length();
    TIntVec NewYStart = Center + XRay*(XStart->Point-Center).Length();
    TIntVec NewYEnd = NewYStart + XRay*Length;
//    TIntVec NewYEnd = Center + XRay*(XEnd->Point-Center).Length();
    NewYStart = RotateAround( NewYStart,TIntVec(0,0,Angle),Center );
    NewYEnd = RotateAround( NewYEnd,TIntVec(0,0,Angle),Center );

    if ( Client == YEnd )
    {
        TIntVec SDVIG = NewYStart - YStart->Point;
        FlowInfo.UnResolved.Remove(this);
        Owner->ChangePointCoordinateRecursive(YEnd,NewYEnd - SDVIG,FlowInfo);
//        YEnd->Point = NewYEnd - SDVIG;
    }
    else if ( Client == YStart )
    {
        TIntVec SDVIG = NewYEnd - YEnd->Point;
        FlowInfo.UnResolved.Remove(this);
        Owner->ChangePointCoordinateRecursive(YStart,NewYStart - SDVIG,FlowInfo);
//        YStart->Point = NewYStart - SDVIG;
    }
    else
    {
        //под вопросом
        FlowInfo.UnResolved.Remove(this);
        Owner->ChangePointCoordinateRecursive(YStart,NewYStart,FlowInfo);
        Owner->ChangePointCoordinateRecursive(YEnd,NewYEnd,FlowInfo);
    }
}     */
/*
bool TAngleLink::UpdateAccordingly(TFlowInfo& FlowInfo)
{

    TG2DPoint* XStart = GetXStart();
    TG2DPoint* XEnd = GetXEnd();
    TG2DPoint* YStart = GetYStart();
    TG2DPoint* YEnd = GetYEnd();
    if ( FlowInfo.Fixed.IndexOf(YEnd) == -1 )
    {
        UpdateAngleLink(YEnd,FlowInfo);
        return true;
    }
    else if ( FlowInfo.Fixed.IndexOf(YStart) == -1 )
    {
        UpdateAngleLink(YStart,FlowInfo);
        return true;
    }
    else if ( FlowInfo.Fixed.IndexOf(XEnd) == -1 )
    {
        UpdateAngleLink(XEnd,FlowInfo);
        return true;
    }
    else if ( FlowInfo.Fixed.IndexOf(XStart) == -1 )
    {
        UpdateAngleLink(XStart,FlowInfo);
        return true;
    }
    return false;

}

void TAngleLink::Update(TFlowInfo& FlowInfo)
{
    UpdateAngleLink(NULL,FlowInfo);
} */


TMyObject* TAngleLink::CreateFunction()
{
    return new TAngleLink();
}

const AnsiString aAngle = AnsiString("Angle");
const AnsiString aAngleLinkSector = AnsiString("AngleLinkSector");
const AnsiString aLabelRadius = AnsiString("LabelRadius");
const AnsiString aLabelAngle_Param = AnsiString("LabelAngle_Param");

TAngleLink::TAngleLink()
{
    RegisterNewClass<TG2DLink,TAngleLink>(this,false,&CreateFunction);
    LinkDirection = ld0To1;
    LabelRadius = 0;
    LabelAngle_Param = 0.5;
    RegisterField(&FAngle,&aAngle,mtMBTi);;
    RegisterField(&AngleLinkSector,&aAngleLinkSector,mtInt);;
    RegisterField(&LabelRadius,&aLabelRadius,mtMBTi);;
    RegisterField(&LabelAngle_Param,&aLabelAngle_Param,mtMBTi);;
}

TAngleLink::~TAngleLink()
{
}

void TAngleLink::SetAngle(MBTi aAngle)
{
    FAngle = aAngle;
}


void TAngleLink::Render(TVisView* aView)
{
    TIntVec Center;
    int res = IsLinesCrossedExactly(    Client0->Src->Point,
                                        Client0->Dst->Point,
                                        Client1->Src->Point,
                                        Client1->Dst->Point,
                                        Center);

    if ( res == lcPARALLEL || res == lcCOLLINEAR )
    {
//        Center = (Client0->Src->Point+Client0->Dst->Point+Client1->Src->Point+Client1->Dst->Point)/4;
        throw EMyException("MSG_ERR_7");
    }
    TIntVec A;
    TIntVec B;
    MBTi UseRadius = LabelRadius;
    if ( !Client0->CanConnect(*Client1) )
        switch ( AngleLinkSector )
        {
            case alsFirst:
                UseRadius = LabelRadius + (Client0->Dst->Point-Center).Length();
            break;
            case alsSecond:
                UseRadius = LabelRadius + (Client1->Dst->Point-Center).Length();
            break;
            case alsThird:
                UseRadius = LabelRadius + (Client0->Src->Point-Center).Length();
            break;
            case alsFourth:
                UseRadius = LabelRadius + (Client1->Src->Point-Center).Length();
            break;
        }
    TG2DPoint* XStart = GetXStart();
    TG2DPoint* XEnd = GetXEnd();
    TG2DPoint* YStart = GetYStart();
    TG2DPoint* YEnd = GetYEnd();
    A = (XEnd->Point-XStart->Point).Normalize()*UseRadius+Center;
    B = (YEnd->Point-YStart->Point).Normalize()*UseRadius+Center;

    //-------Label----------
    MBTi NewAngle = AngleRad(B,Center,A)*180/M_PI;

    TIntVec LabelPos = PointOfLineOnCut(Center,A,UseRadius);
    LabelPos = RotateAround(LabelPos,TIntVec(0,0,LabelAngle_Param*NewAngle),Center);
    Label->Caption = MBTiToStrF(NewAngle,2);

    //text rect
    TIntVec LabelPos_Scr = aView->WinFrom3D(LabelPos);
    aView->GetCanvas()->Font->Assign( Label->Font );
    aView->Canvas->Font->Assign( Label->Font );
    TSize TextSize = aView->Canvas->TextExtent(Label->Caption);
    //text rect
    TIntVec LabelRectMin(LabelPos_Scr.x-TextSize.cx/2-2,LabelPos_Scr.y-TextSize.cy/2-2,0);
    TIntVec LabelRectMax(LabelPos_Scr.x+TextSize.cx/2+2,LabelPos_Scr.y+TextSize.cy/2+2,0);
    //text offset
    LabelPos_Scr.x -= TextSize.cx/2;
    LabelPos_Scr.y += TextSize.cy/2;
    Position = LabelPos_Scr;
    //-------------Pie--------------

    int Detail = 40;
    if ( NewAngle <90 )
        Detail = 10;
    else if ( NewAngle <180)
        Detail = 20;
    else if ( NewAngle <270)
        Detail = 30;
    TMDelTList<TIntVec> ArcList;
    TMDelTList<TIntVec> TempList;
    
    Arc3D(TempList,Center,A,B,Detail);
    for (int i=0;i<TempList.Count;i++)
        TempList[i] = aView->WinFrom3D(TempList[i]);

    for (int i=0;i<TempList.Count-1;i++)
        AddVectorToList(
                        ArcList,
                        TempList[i],
                        TempList[i+1],
                        LabelRectMin,
                        LabelRectMax,
                        0.0001
                        );

    if (ArcList.Count<2)
    {
        ArcList.Clear();
        ArcList.Add( new TIntVec( aView->WinFrom3D(A) ) );
        ArcList.Add( new TIntVec( aView->WinFrom3D(B) ) );
    }
    //Arrows
    MakeArrowsOnList(ArcList,15,5,true/*Back*/);

    //Rays
    AddRayToPointList(  ArcList,
                        aView->WinFrom3D(A),
                        aView->WinFrom3D(XStart->Point),
                        aView->WinFrom3D(XEnd->Point),
                        aView->WinFrom3D(Center));

    AddRayToPointList(  ArcList,
                        aView->WinFrom3D(B),
                        aView->WinFrom3D(YStart->Point),
                        aView->WinFrom3D(YEnd->Point),
                        aView->WinFrom3D(Center));

    //Render
    for (int i=0;i<ArcList.Count-1;)
    {
        aView->Canvas->MoveTo(ArcList[i].x,ArcList[i].y);
        i++;
        aView->Canvas->LineTo(ArcList[i].x,ArcList[i].y);
        i++;
    }
    //------------------------------Label-------------------------------
    aView->Canvas->TextOut(LabelPos_Scr.x,LabelPos_Scr.y,Label->Caption);

}

void TAngleLink::SetCut(int index,TGCut* Cut)
{
    SetClient(index,Cut);
}

TGCut* TAngleLink::GetCut(int index)
{
    return (TGCut*)GetClient(index);
}


