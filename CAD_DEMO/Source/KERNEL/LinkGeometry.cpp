//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LinkGeometry.h"
#include "Driver.h"
#include "ElementV.h"
#include "World.h"
#include "MyGL.h"
#include "AUIV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


/*TIntVec PTarget[2];
TIntVec PSource[2];
T3DScope SC1,SC2;
TIntVec STEPS[2][2];
TIntVec TSource[2];
TIntVec DSource[2];
TIntVec RSource;
T3DScope SC;
TIntVec Service_;

TIntVec _ANGLEEPS;
TIntVec _EPS;
TIntVec _SIZEEPS; */
void CorrectAngleAXE(MBTi& MBTiAB)
{
        while( MBTiAB<0 )
            MBTiAB+=360;
        while( MBTiAB>=360 )
            MBTiAB-=360;
}

void CorrectAngle(TIntVec& Angle)
{
    for(int i=0;i<3;i++)
    {
        while( Angle.a[i]<0 )
            Angle.a[i]+=360;
        while( Angle.a[i]>=360 )
            Angle.a[i]-=360;
    }


}


bool ControlAngle(const TIntVec& _Angle,const TIntVec& _Epsi)
{
    for (int i=0;i<3;i++)
        if ( ( fabs(_Angle.a[i]) > _Epsi.a[i] )
            && ( (360-fabs(_Angle.a[i]) ) > _Epsi.a[i] ) )
            return(false);
    return true;
}


void Get_SDAR_Change_WithAngle(    const TIntVec& PointA,
                            const TIntVec& PointB,
                            TElement* Source,
                            TLINKPATTERN& SGL,
                            bool IsDirectionPlus)
{

//Direction
    SGL.Direction = (IsDirectionPlus)? TIntVec(1,1,0) : TIntVec(-1,-1,0);

//size
    double DeltaX = PointB.x - PointA.x;
    double DeltaY = PointB.y - PointA.y;
    MBTi SizeX = (MBTi)sqrtDC( DeltaX*DeltaX+DeltaY*DeltaY );
    SGL.TS_Common = ZEROINTVEC;
    SGL.TS_Common.x = SizeX - Source->AbsSize.x;
}

void Get_SDAR_Change(           const TIntVec& PointA,
                                const TIntVec& PointB,
                                TElement* Source,
                                TLINKPATTERN& SGL,
                                bool IsDirectionPlus)
{
//RotateCenter
    SGL.RotateCenter = PointA;
//angle
    SGL.R_Common = ZEROINTVEC;
    MBTi MBTiAB = (AngleRadOX(PointA,PointB)*180/M_PI);
    MBTi MBTiBA = (AngleRadOX(PointB,PointA)*180/M_PI);
    CorrectAngleAXE(MBTiAB);
    CorrectAngleAXE(MBTiBA);
    MBTi MIN_VOLATILE_BA = MIN(fabs(MBTiBA-Source->AbsAngle.z),360-fabs(MBTiBA-Source->AbsAngle.z));
    MBTi MIN_VOLATILE_AB = MIN(fabs(MBTiAB-Source->AbsAngle.z),360-fabs(MBTiAB-Source->AbsAngle.z));
    if ( MIN_VOLATILE_BA<MIN_VOLATILE_AB )
    {
        SGL.R_Common.z = MBTiBA-Source->AbsAngle.z;
        Get_SDAR_Change_WithAngle(PointB,PointA,Source,SGL,!IsDirectionPlus);
    }
    else
    {
        SGL.R_Common.z = MBTiAB-Source->AbsAngle.z;
        Get_SDAR_Change_WithAngle(PointA,PointB,Source,SGL,IsDirectionPlus);
    }
}



bool CheckAngleLink(    TElement *Target,
                        TElement *Source,
                        TLINKPATTERN &SGL,
                        TIntVec& AngleChange,
                        const TIntVec& _ANGLEEPS)
{
    //-----------------------------------------------------------
    CorrectAngle(AngleChange);
    //-----------------------------------------------------------
    for (int i=0;i<3;i++)
        if ( ( fabs(AngleChange.a[i]) > _ANGLEEPS.a[i] )
            && ( (360-fabs(AngleChange.a[i]) ) > _ANGLEEPS.a[i] ) )
            return false;
    //-----------------------------------------------------------
    T3DScope SC;
    SC = T3DScope(SGL.DL->Link->Angle.LOW,SGL.DL->Link->Angle.HI);
    TIntVec Result_Raznost((Target->AbsAngle - (Source->AbsAngle+AngleChange)));
    CorrectAngle(Result_Raznost);
    return (Result_Raznost)<=SC.HI && (Result_Raznost)>=SC.LOW;
}

bool CheckAngle(            TElement *Target,
                            TElement *Source,
                            TLINKPATTERN &SGL,
                            const TIntVec& _ANGLEEPS)
{
    T3DScope SC;
    SC = T3DScope(SGL.DL->Link->Angle.LOW,SGL.DL->Link->Angle.HI);
    TIntVec Angle = (Source->AbsAngle - Target->AbsAngle);
    CorrectAngle(Angle);
    SC.PointAbout(Angle,SGL.R_Common);
    for (int i=0;i<3;i++)
        if ( ( fabs(SGL.R_Common.a[i]) > _ANGLEEPS.a[i] )
            && ( (360-fabs(SGL.R_Common.a[i]) ) > _ANGLEEPS.a[i] ) )
            return false;

    return true;
}

bool PointPoint_Pos(         TElement *Target,
                            TElement *Source,
                            TLINKPATTERN &SGL,
                            bool _AnyWay)
{
    T3DScope SC1;
    T3DScope SC2;
	TIntVec PTarget[2];
    TIntVec PSource[2];
    TIntVec STEPS[2][2];

    TIntVec& _ANGLEEPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_ANGLEEPS : (Source->MyMeta->EPS.ANGLEEPS);
    TIntVec& _EPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_EPS : (Source->MyMeta->EPS.POSEPS);

    if ( !CheckAngle(Target,Source,SGL,_ANGLEEPS) )
        return false;

	Source->UserChangePosition(ZEROINTVEC,SGL.R_Common);
    //local points
    //target
    //-------------------------------------------------------------
    SGL.DL->Link->TargetScope(Target,Source,SC1);
    //-------------------------------------------------------------

    //source
    //-------------------------------------------------------------
    SGL.DL->Link->SourceScope(Target,Source,SC2);
    //-------------------------------------------------------------

    //грани связок таргета
    PTarget[0] = RotateAround(SC1.LOW+Target->AbsPos,Target->AbsAngle,Target->AbsPos);
    PTarget[1] = RotateAround(SC1.HI+Target->AbsPos,Target->AbsAngle,Target->AbsPos);

    //грани связок соча
    PSource[0] = RotateAround(SC2.LOW+Source->AbsPos,Source->AbsAngle,Source->AbsPos);
    PSource[1] = RotateAround(SC2.HI+Source->AbsPos,Source->AbsAngle,Source->AbsPos);

    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
        STEPS[i][j] = (PTarget[i] - PSource[j]);

    //проверка краев
    MBTi MeasureStep=Measure(_EPS);
    int i0=-1,j0=-1;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            if (Measure(STEPS[i][j])<MeasureStep)
            {
                MeasureStep = Measure(STEPS[i][j]);
                i0=i;
                j0=j;
            }
    if (i0!=-1&&j0!=-1&&(STEPS[i0][j0]).Length()<=_EPS.x)
    {
        SGL.TS_Common = PTarget[i0] - PSource[j0];
        Source->UserChangePosition(ZEROINTVEC,SGL.R_Common*(-1));
        SGL.CrossPoint = PTarget[i0];
		return true;
    }
    Source->UserChangePosition( ZEROINTVEC,SGL.R_Common*(-1));
    return false;
}

bool LineLine_Pos(   TElement *Target,
                    TElement *Source,
                    TLINKPATTERN &SGL,
                    bool _AnyWay)
{
    T3DScope SC1;
    T3DScope SC2;
    TIntVec PTarget[2];
    TIntVec PSource[2];
    int j0;

    TIntVec& _ANGLEEPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_ANGLEEPS : (Source->MyMeta->EPS.ANGLEEPS);
    TIntVec& _EPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_EPS : (Source->MyMeta->EPS.POSEPS);

    if ( !CheckAngle(Target,Source,SGL,_ANGLEEPS) )
        return false;

    Source->UserChangePosition(ZEROINTVEC,SGL.R_Common);
    //local points
    //target
    //-------------------------------------------------------------
    SGL.DL->Link->TargetScope(Target,Source,SC1);
    //-------------------------------------------------------------

    //source
    //-------------------------------------------------------------
    SGL.DL->Link->SourceScope(Target,Source,SC2);
    //-------------------------------------------------------------

    //грани связок таргета
    Target->AbsFromLocal(SC1.LOW,PTarget[0]);
    Target->AbsFromLocal(SC1.HI,PTarget[1]);

    //грани связок соча
    Source->AbsFromLocal(SC2.LOW,PSource[0]);
    Source->AbsFromLocal(SC2.HI,PSource[1]);

    //общее соединение
    int ResCrossing = IsCutAndLineCrossedExactly(PTarget[0],PTarget[1],PSource[0],PSource[1],SGL.CrossPoint);

    if (ResCrossing == lcNONE || ResCrossing == lcPARALLEL || ResCrossing == lcCOLLINEAR)//parralel
    {
		Source->UserChangePosition( ZEROINTVEC,SGL.R_Common*(-1));
		return false;//AreaPoint_Size(Target,Source,SGL,_AnyWay);
    }
    SGL.CrossPoint.z = PSource[0].z;
    MBTi Plus_Cut = (PSource[1]-SGL.CrossPoint).Length2D();
    MBTi Minus_Cut = (PSource[0]-SGL.CrossPoint).Length2D();
    j0 = (int)(Plus_Cut<Minus_Cut);

    TIntVec CrossPointLocal;
    Source->LocalFromAbs(SGL.CrossPoint,CrossPointLocal);
    TIntVec ChangeVec;
    SC2.PointAbout(CrossPointLocal,ChangeVec);
    ChangeVec.y=0;
    if (ChangeVec.x==0)
        SGL.TS_Common = ZEROINTVEC;
    else
        SGL.TS_Common = SGL.CrossPoint-PSource[j0];

    Source->UserChangePosition( ZEROINTVEC,SGL.R_Common*(-1));
	return SGL.TS_Common.Length()<=_EPS.x;
}

bool LineLine_Size( TElement *Target,
                    TElement *Source,
                    TLINKPATTERN &SGL,
                    bool _AnyWay)
{
    T3DScope SC1;
    T3DScope SC2;
    TIntVec PTarget[2];
    TIntVec PSource[2];
    int j0;
    
//    TIntVec& _ANGLEEPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_ANGLEEPS : (Source->MyMeta->EPS.ANGLEEPS);
    TIntVec& _EPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_EPS : (Source->MyMeta->EPS.POSEPS);
    //local points
    //target
    //-------------------------------------------------------------
    SGL.DL->Link->TargetScope(Target,Source,SC1);
    //-------------------------------------------------------------

    //source
    //-------------------------------------------------------------
    SGL.DL->Link->SourceScope(Target,Source,SC2);
    //-------------------------------------------------------------

    //грани связок таргета
    Target->AbsFromLocal(SC1.LOW,PTarget[0]);
    Target->AbsFromLocal(SC1.HI,PTarget[1]);

    //грани связок соча
    Source->AbsFromLocal(SC2.LOW,PSource[0]);
    Source->AbsFromLocal(SC2.HI,PSource[1]);

    int ResCrossing = IsCutAndLineCrossedExactly(PTarget[0],PTarget[1],PSource[0],PSource[1],SGL.CrossPoint);

    if (ResCrossing == lcNONE || ResCrossing == lcPARALLEL || ResCrossing == lcCOLLINEAR) // parralel
        return false;//AreaPoint_Size(Target,Source,SGL,_AnyWay);

    MBTi Plus_Cut = (PSource[1]-SGL.CrossPoint).Length2D();
    MBTi Minus_Cut = (PSource[0]-SGL.CrossPoint).Length2D();
    j0 = (int)(Plus_Cut<Minus_Cut);
    Get_SDAR_Change(PSource[1-j0],SGL.CrossPoint,Source,SGL,1);
    SGL.CrossPoint.z = PSource[0].z;

    TIntVec CrossPointLocal;
    Source->LocalFromAbs(SGL.CrossPoint,CrossPointLocal);
    TIntVec ChangeVec;
    SC2.PointAbout(CrossPointLocal,ChangeVec);
    ChangeVec.y=0;
    if (ChangeVec.x==0)
    {
        SGL.R_Common = ZEROINTVEC;
        SGL.TS_Common = ZEROINTVEC;
        SGL.Direction = ZEROINTVEC;
        SGL.RotateCenter = ZEROINTVEC;
    }
    if ( !((SGL.TS_Common).Length()<=_EPS.x) )
        return false;
    return true;
}

bool PointPoint_Size(        TElement *Target,
                            TElement *Source,
                            TLINKPATTERN &SGL,
                            bool _AnyWay)
{
    T3DScope SC1;
    T3DScope SC2;
    TIntVec PTarget[2];
    TIntVec PSource[2];
    TIntVec STEPS[2][2];

    TIntVec& _ANGLEEPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_ANGLEEPS : (Source->MyMeta->EPS.ANGLEEPS);
    TIntVec& _EPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_EPS : (Source->MyMeta->EPS.POSEPS);

    //local points
    //target
    //-------------------------------------------------------------
    SGL.DL->Link->TargetScope(Target,Source,SC1);
    //-------------------------------------------------------------

    //source
    //-------------------------------------------------------------
    SGL.DL->Link->SourceScope(Target,Source,SC2);
    //-------------------------------------------------------------

    //грани связок таргета
    Target->AbsFromLocal(SC1.LOW,PTarget[0]);
    Target->AbsFromLocal(SC1.HI,PTarget[1]);

    //грани связок соча
    Source->AbsFromLocal(SC2.LOW,PSource[0]);
    Source->AbsFromLocal(SC2.HI,PSource[1]);

    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
        STEPS[i][j] = (PTarget[i] - PSource[j]);

    //проверка краев
    MBTi MeasureStep=Measure(_EPS);
    int i0=-1,j0=-1;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            if (Measure(STEPS[i][j])<MeasureStep)
            {
                MeasureStep = Measure(STEPS[i][j]);
                i0=i;
                j0=j;
            }
    bool ResOK = i0!=-1&&j0!=-1&&(STEPS[i0][j0]).Length()<=_EPS.x;
    if (!ResOK)
        return false;

    Get_SDAR_Change(PSource[1-j0],PTarget[i0],Source,SGL,1);
    SGL.CrossPoint = PTarget[i0];

    if ( CheckAngleLink(Target,Source,SGL,SGL.R_Common,_ANGLEEPS) == false )
        return false;

    if ( !((PTarget[i0] - PSource[j0]).Length()<=_EPS.x) )
        return false;

    return true;
}

bool AreaPoint_Size(     TElement *Target,
                                    TElement *Source,
                                    TLINKPATTERN &SGL,
                                    bool _AnyWay)
{
    T3DScope SC1;
    T3DScope SC2;
    TIntVec PSource[2];
    TIntVec PTarget[2];
    TIntVec NewSource[2];
    TIntVec TSource[2];
    TIntVec STEPS[2][2];
    int j0;

    TIntVec& _ANGLEEPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_ANGLEEPS : (Source->MyMeta->EPS.ANGLEEPS);
    TIntVec& _EPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_EPS : (Source->MyMeta->EPS.POSEPS);

    //local points
    //target
    //-------------------------------------------------------------
    SGL.DL->Link->TargetScope(Target,Source,SC1);
    //-------------------------------------------------------------

    //source
    //-------------------------------------------------------------
    SGL.DL->Link->SourceScope(Target,Source,SC2);
    //-------------------------------------------------------------

    //грани связок соча
    Source->AbsFromLocal(SC2.LOW,PSource[0]);
    Source->AbsFromLocal(SC2.HI,PSource[1]);

    //грани связок соча  в координатах target
    Target->LocalFromAbs(PSource[0],TSource[0]);
    Target->LocalFromAbs(PSource[1],TSource[1]);

    //проверка краев 2
    //близость этих точек для таргета определяются
    //в Un_Opt то же самое но наоборот
    SGL.CrossPoint.z = PSource[0].z;
    for (int i=0;i<2;i++)
        SC1.PointAbout(TSource[i],STEPS[0][i]);

    j0 = (int)(Measure(STEPS[0][1])<Measure(STEPS[0][0]));
    if ( !((STEPS[0][j0]).Length()<=_EPS.x) )
        return false;

    NewSource[1-j0] = PSource[1-j0];
    NewSource[j0] = TSource[j0]+STEPS[0][j0];
    Target->AbsFromLocal(NewSource[j0],NewSource[j0]);

    Get_SDAR_Change(NewSource[1-j0],NewSource[j0],Source,SGL,1);
    SGL.CrossPoint = NewSource[j0];
    if ( CheckAngleLink(Target,Source,SGL,SGL.R_Common,_ANGLEEPS) == false )
        return false;

    return true;
}

bool LinePoint_Size(    TElement *Target,
                        TElement *Source,
                        TLINKPATTERN &SGL,
                        bool AnyWay)
{
    T3DScope SC1;
    T3DScope SC2;
    TIntVec PSource[2];
    TIntVec PTarget[2];
    TIntVec STarget[2];
    TIntVec NewSource[2];
    TIntVec TSource[2];
    TIntVec STEPS[2][2];
    int j0;

    TIntVec& _ANGLEEPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_ANGLEEPS : (Source->MyMeta->EPS.ANGLEEPS);
    TIntVec& _EPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_EPS : (Source->MyMeta->EPS.POSEPS);

    //local points
    //target
    //-------------------------------------------------------------
    SGL.DL->Link->TargetScope(Target,Source,SC1);
    //-------------------------------------------------------------

    //source
    //-------------------------------------------------------------
    SGL.DL->Link->SourceScope(Target,Source,SC2);
    //-------------------------------------------------------------

    //грани связок соча
    Target->AbsFromLocal(SC1.LOW,PTarget[0]);
    Target->AbsFromLocal(SC1.HI,PTarget[1]);

    //грани связок соча
    Source->AbsFromLocal(SC2.LOW,PSource[0]);
    Source->AbsFromLocal(SC2.HI,PSource[1]);

    //грани связок соча  в координатах target
    Target->LocalFromAbs(PSource[0],TSource[0]);
    Target->LocalFromAbs(PSource[1],TSource[1]);

    //сначала проверка по прямой
    int ResCrossing = IsCutAndLineCrossedExactly(PTarget[0],PTarget[1],PSource[0],PSource[1],SGL.CrossPoint);

    if (ResCrossing != lcNONE && ResCrossing != lcPARALLEL &&  ResCrossing != lcCOLLINEAR) //parralel
    {
        MBTi Plus_Cut = (PSource[1]-SGL.CrossPoint).Length2D();
        MBTi Minus_Cut = (PSource[0]-SGL.CrossPoint).Length2D();
        j0 = (int)(Plus_Cut<Minus_Cut);
        Get_SDAR_Change(PSource[1-j0],SGL.CrossPoint,Source,SGL,1);
        SGL.CrossPoint.z = PSource[0].z;
/*
        TIntVec CrossPointLocal;
        Source->LocalFromAbs(SGL.CrossPoint,CrossPointLocal);
        TIntVec ChangeVec;
        SC2.PointAbout(CrossPointLocal,ChangeVec);
        ChangeVec.y=0;
        if (ChangeVec.x==0)
        {
            SGL.R_Common = ZEROINTVEC;
            SGL.TS_Common = ZEROINTVEC;
            SGL.Direction = ZEROINTVEC;
            SGL.RotateCenter = ZEROINTVEC;
        }                  */
        if ( !((SGL.TS_Common).Length()<=_EPS.x) )
            return false;
        return true;
    }
    else
    {
        //проверка краев 2
        //близость этих точек для таргета определяются
        //в Un_Opt то же самое но наоборот
        SGL.CrossPoint.z = PSource[0].z;
        for (int i=0;i<2;i++)
            SC1.PointAbout(TSource[i],STEPS[0][i]);

        j0 = (int)(Measure(STEPS[0][1])<Measure(STEPS[0][0]));
        if ( !((STEPS[0][j0]).Length()<=_EPS.x) )
            return false;

        NewSource[1-j0] = PSource[1-j0];
        NewSource[j0] = TSource[j0]+STEPS[0][j0];
        Target->AbsFromLocal(NewSource[j0],NewSource[j0]);

        Get_SDAR_Change(NewSource[1-j0],NewSource[j0],Source,SGL,1);
        SGL.CrossPoint = NewSource[j0];
        if ( CheckAngleLink(Target,Source,SGL,SGL.R_Common,_ANGLEEPS) == false )
            return false;

        return true;
    }
}

bool LinePoint_Pos(  TElement *Target,
					TElement *Source,
                    TLINKPATTERN &SGL,
                    bool AnyWay)
{
    T3DScope SC1;
    T3DScope SC2;
    TIntVec PSource[2];
	TIntVec PTarget[2];
    TIntVec STarget[2];
    TIntVec NewSource[2];
    TIntVec TSource[2];
    TIntVec STEPS[2][2];
	int j0;

    TIntVec& _ANGLEEPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_ANGLEEPS : (Source->MyMeta->EPS.ANGLEEPS);
    TIntVec& _EPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_EPS : (Source->MyMeta->EPS.POSEPS);

    //local points
    //target
    //-------------------------------------------------------------
    SGL.DL->Link->TargetScope(Target,Source,SC1);
    //-------------------------------------------------------------

    //source
    //-------------------------------------------------------------
    SGL.DL->Link->SourceScope(Target,Source,SC2);
    //-------------------------------------------------------------

    //грани связок соча
    Target->AbsFromLocal(SC1.LOW,PTarget[0]);
    Target->AbsFromLocal(SC1.HI,PTarget[1]);

    //грани связок соча
    Source->AbsFromLocal(SC2.LOW,PSource[0]);
    Source->AbsFromLocal(SC2.HI,PSource[1]);

    //грани связок соча  в координатах target
    Target->LocalFromAbs(PSource[0],TSource[0]);
    Target->LocalFromAbs(PSource[1],TSource[1]);

    //сначала проверка по прямой
    int ResCrossing = IsCutAndLineCrossedExactly(PTarget[0],PTarget[1],PSource[0],PSource[1],SGL.CrossPoint);

    if (ResCrossing != lcNONE && ResCrossing != lcPARALLEL && ResCrossing != lcCOLLINEAR) //parralel
    {
        MBTi Plus_Cut = (PSource[1]-SGL.CrossPoint).Length2D();
        MBTi Minus_Cut = (PSource[0]-SGL.CrossPoint).Length2D();
        j0 = (int)(Plus_Cut<Minus_Cut);
        SGL.CrossPoint.z = PSource[0].z;
        SGL.TS_Common = SGL.CrossPoint - PSource[j0];
		return (SGL.TS_Common).Length()<=_EPS.x;
    }
    else
    {
        //проверка краев 2
        //близость этих точек для таргета определяются
        //в Un_Opt то же самое но наоборот
        if (!CheckAngle(Target,Source,SGL,_ANGLEEPS))
			return false;
        SGL.CrossPoint.z = PSource[0].z;
		for (int i=0;i<2;i++)
			SC1.PointAbout(TSource[i],STEPS[0][i]);

		j0 = (int)(Measure(STEPS[0][1])<Measure(STEPS[0][0]));
        if ( !((STEPS[0][j0]).Length()<=_EPS.x) )
		{
            Source->UserChangePosition( ZEROINTVEC,SGL.R_Common*(-1));
			return false;
        }

        NewSource[1-j0] = PSource[1-j0];
        NewSource[j0] = TSource[j0]+STEPS[0][j0];
		Target->AbsFromLocal(NewSource[j0],NewSource[j0]);
		SGL.CrossPoint = NewSource[j0];
        SGL.TS_Common = NewSource[j0]-PSource[j0];
		return true;
    }
}

TIntVec SDVIG;
TIntVec SRV_STEP;
T3DScope SRV_SC0;
TIntVec SRV_Step;
bool AreaPoint_Pos( TElement *Target,
                    TElement *Source,
                    TLINKPATTERN &SGL,
                    bool AnyWay)
{
    TIntVec PTarget[2];
    TIntVec PSource[2];
    T3DScope SC1,SC2;
    TIntVec STEPS[2][2];
    TIntVec TSource[2];
    TIntVec DSource[2];
    TIntVec RSource;
    T3DScope SC;
    TIntVec Service_;

    TIntVec& _ANGLEEPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_ANGLEEPS : (Source->MyMeta->EPS.ANGLEEPS);
    TIntVec& _EPS = (Driver.IsNowCorrectMode) ? Driver.CORRECT_EPS : (Source->MyMeta->EPS.POSEPS);

    if (!CheckAngle(Target,Source,SGL,_ANGLEEPS))
        return false;

    Source->UserChangePosition(ZEROINTVEC,SGL.R_Common);

    //----------------------------
    TIntVec Point;
    SGL.DL->Link->SourcePoint(Target,Source,Point);
    Point = Point+Source->AbsPos;
    //----------------------------
    Service_ = RotateAround(Point,Source->AbsAngle,Source->AbsPos);
    Point = RotateAround(Service_,Target->AbsAngle*(-1),Target->AbsPos);
    //-------------------------------------------------------------
    SGL.DL->Link->TargetScope(Target,Source,SRV_SC0);
    //-------------------------------------------------------------
    SRV_SC0.Move(Target->AbsPos);
    bool RES_POINT_ABOUT;
    if (SGL.DL->Link->STEP.Hard)
        RES_POINT_ABOUT = SRV_SC0.PointAbout(Point,SRV_Step,SGL.DL->Link->STEP.BaseStep.XYZ_Multiply( SGL.DL->Link->STEP.DefMulti) ) ;
    else
        RES_POINT_ABOUT = SRV_SC0.PointAbout(Point,SRV_Step,ZEROINTVEC);

    if (!RES_POINT_ABOUT)
      SRV_Step = MAXCATCHEPS;
    Source->UserChangePosition(ZEROINTVEC,SGL.R_Common*(-1));
    SGL.TS_Common = RotateAround(SRV_Step,Target->AbsAngle,ZEROINTVEC);
    //точка связки
    SGL.CrossPoint = Service_ + SGL.TS_Common;
    return (ABSINTVEC(SGL.TS_Common)<= _EPS );
}

bool SizeLink(  TElement *Target,
                TElement *Source,
                TLINKPATTERN &SGL,
                bool AnyWay)
{
    switch( SGL.RealLinkType )
    {
        case rltPointPoint :
            return PointPoint_Size(Target,Source,SGL,AnyWay);
        case rltAreaPoint :
            return AreaPoint_Size(Target,Source,SGL,AnyWay);
        case rltLinePoint :
            return LinePoint_Size(Target,Source,SGL,AnyWay);
        default :
            return LineLine_Size(Target,Source,SGL,AnyWay);
    };
}

bool PosLink(   TElement *Target,
                TElement *Source,
                TLINKPATTERN &SGL,
                bool AnyWay)
{
    switch( SGL.RealLinkType )
    {
        case rltPointPoint :
			return PointPoint_Pos(Target,Source,SGL,AnyWay);
        case rltLineLine :
			return LineLine_Pos(Target,Source,SGL,AnyWay);
        case rltLinePoint :
            return LinePoint_Pos(Target,Source,SGL,AnyWay);
        default :
            return AreaPoint_Pos(Target,Source,SGL,AnyWay);
    };
}
