//---------------------------------------------------------------------------

#ifndef LinkGeometryH
#define LinkGeometryH
//---------------------------------------------------------------------------
class TLINKPATTERN;
class TElement;
enum TRealLinkTypes {rltAreaPoint = 0,rltPointPoint = 1,rltLineLine = 2,rltLinePoint = 4};

bool COMMONAL_API CheckAngleLink(    TElement *Target,
                        TElement *Source,
                        TLINKPATTERN &SGL,
                        TIntVec& AngleChange,
                        const TIntVec& _ANGLEEPS);

void COMMONAL_API CorrectAngle(TIntVec& Angle);

bool COMMONAL_API PointPoint_Pos(    TElement *Target,
                                    TElement *Source,
                                    TLINKPATTERN &SGL,
                                    bool AnyWay);

bool COMMONAL_API PointPoint_Size(   TElement *Target,
                                    TElement *Source,
                                    TLINKPATTERN &SGL,
                                    bool AnyWay);

bool COMMONAL_API AreaPoint_Pos( TElement *Target,
                                TElement *Source,
                                TLINKPATTERN &SGL,
                                bool AnyWay);

bool COMMONAL_API AreaPoint_Size(    TElement *Target,
                                    TElement *Source,
                                    TLINKPATTERN &SGL,
                                    bool AnyWay);

bool COMMONAL_API LinePoint_Size(    TElement *Target,
                                    TElement *Source,
                                    TLINKPATTERN &SGL,
                                    bool AnyWay);

bool COMMONAL_API LinePoint_Pos(  TElement *Target,
                                TElement *Source,
                                TLINKPATTERN &SGL,
                                bool AnyWay);


bool COMMONAL_API LineLine_Pos(  TElement *Target,
                                TElement *Source,
                                TLINKPATTERN &SGL,
                                bool AnyWay);

bool COMMONAL_API LineLine_Size(  TElement *Target,
                                TElement *Source,
                                TLINKPATTERN &SGL,
                                bool AnyWay);
                    
bool COMMONAL_API SizeLink(  TElement *Target,
                            TElement *Source,
                            TLINKPATTERN &SGL,
                            bool AnyWay);

bool COMMONAL_API PosLink(   TElement *Target,
                            TElement *Source,
                            TLINKPATTERN &SGL,
                            bool AnyWay);


/*bool SizeConnect(   TElement *Target,
                    TElement *Source,
                    TLINKPATTERN &SGL,
                    bool _AnyWay);

bool ElementsCanLinkWall(   TElement *Target,
                            TElement *Source,
                            TLINKPATTERN &SGL,
                            bool _AnyWay); */


/*
TIntVec RoSource[2];
TIntVec CloseSource[2];
//bool DEBUG=true;

bool SizeConnect(   TElement *Target,
                    TElement *Source,
                    TLINKPATTERN &SGL,
                    bool _AnyWay)
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

    TIntVec _ANGLEEPS;
    TIntVec _EPS;
    TIntVec _SIZEEPS;


    bool CanContinue = false;
    if (    SGL.DL->Link->WallLink
            && BIF->Driver.FloorElement)
        if ((!Source->Parent && Target->In(BIF->Driver.FloorElement)) ||
            (!Target->Parent && Source->In(BIF->Driver.FloorElement)) )
            CanContinue = true;
    if (!CanContinue)
        return false;
    //пока только для стен
    //вызов данной функции только для стен
    //должно быть обеспечено чтобы точки находились на оси стены
    _ANGLEEPS = Source->MyMeta->EPS.ANGLEEPS;
    _SIZEEPS = (Source->MyMeta->EPS.SIZEEPS);
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

    //два края стены
    DSource[0] = MINUSINTVEC*Source->AbsSize/VEC222;
    DSource[0].y=0;
    Source->AbsFromLocal(DSource[0],DSource[0]);
    DSource[0].z=PTarget[0].z;
    DSource[1] = Source->AbsSize/VEC222;
    DSource[1].y=0;
    Source->AbsFromLocal(DSource[1],DSource[1]);
    DSource[1].z=PTarget[1].z;

    //----------
//    PSource[0] = DSource[0];
//    PSource[1] = DSource[1];
    //----------

    //выберем край стены
    int SideInd=-1;
    //расстояния до targeta
    MBTi Measures[2];
    for (int i=0;i<2;i++)
    {
        Target->LocalFromAbs(DSource[i],RoSource[i]);
        SC1.PointAbout(RoSource[i],CloseSource[i]);
        Measures[i] = Measure(CloseSource[i]);
    }
    MBTi MinMeasure=1<<28;
    for (int i=0;i<2;i++)
        if (MinMeasure>Measures[i])
        {
            MinMeasure=Measures[i];
            SideInd = i;
        }
//    SideInd = (SideInd>=2);// 1 или 0 край стены

    //рассчитаем теперь дирекшн
    //и вокруг чего вращать будем
    MBTi Mes0 = Measure(PSource[SideInd]-DSource[0]);
    MBTi Mes1 = Measure(PSource[SideInd]-DSource[1]);
    if (Mes0==Mes1)
    {
        //Точка связки находится одинаково близко
        //от обоих краев РЕШЕНИЯ НЕТ
        return false;
    }
    if (Mes0<Mes1)
    {
        SGL.Direction = TIntVec(-1,-1,0);
        SGL.RotateCenter = DSource[1];
    }
    else
    {
        SGL.Direction = TIntVec(1,1,0);
        SGL.RotateCenter = DSource[0];
    }

    //теперь сдвиг так чтобы центр вращения оказался в нуле
    //запомним сдвиг
    PTarget[0] = PTarget[0] - SGL.RotateCenter;
    PTarget[1] = PTarget[1] - SGL.RotateCenter;
    PSource[SideInd] = PSource[SideInd] - SGL.RotateCenter;
    PSource[1-SideInd] = PSource[1-SideInd] - SGL.RotateCenter;

    //рассчитаем углы всех трех точек относительно нуля
    if ( PTarget[0].x==0&&PTarget[0].y==0 || PTarget[1].x==0&&PTarget[1].y==0 )
    {
        SGL.Direction = ZEROINTVEC;
        SGL.TS_Common=ZEROINTVEC;
        SGL.R_Common=ZEROINTVEC;
        SGL.CrossPoint = SGL.RotateCenter;
        return true;
    }
    if (PSource[SideInd].x==0 && PSource[SideInd].y==0)
    {
        Application->MessageBox(""Null object"","Application Terminated!");
        Application->Terminate();
        return false;
    }
    //проверка на близость к краям
    STEPS[0][0] = PTarget[0] - PSource[SideInd];
    STEPS[0][1] = PTarget[1] - PSource[SideInd];
    int MinMeasureIndex = Measure(STEPS[0][1]) < Measure(STEPS[0][0]);

    if ( !(ABSINTVEC(STEPS[0][MinMeasureIndex]) <= _SIZEEPS) )
        MinMeasureIndex = -1;

    //проверка на угол к краю
    bool AngleOK=true;
    if (MinMeasureIndex!=-1)
    {
        MBTi PointAngle = AngleOf(ZEROMPOINT,PSource[SideInd].AsPoint());
        MBTi TargetAngle = AngleOf(ZEROMPOINT,PTarget[MinMeasureIndex].AsPoint());
        MBTi AngleStepZ = (TargetAngle-PointAngle);
        SGL.R_Common = TIntVec(0,0,AngleStepZ);
        for (int i=0;i<3;i++)
            if ( ( fabs(SGL.R_Common.a[i]) > _ANGLEEPS.a[i] )
            && ( (360-fabs(SGL.R_Common.a[i]) ) > _ANGLEEPS.a[i] ) )
                AngleOK = false;
    }
    if (!AngleOK || MinMeasureIndex == -1)
    {
        MBTi PointAngle = AngleOf(ZEROMPOINT,PSource[SideInd].AsPoint());
        MBTi TargetMinAngle = AngleOf(ZEROMPOINT,PTarget[0].AsPoint());
        MBTi TargetMaxAngle = AngleOf(ZEROMPOINT,PTarget[1].AsPoint());
        while( fabs(TargetMaxAngle - TargetMinAngle)>180)
        {
            PointAngle = CycleOf( PointAngle+180, 360);
            TargetMinAngle = CycleOf( TargetMinAngle+180, 360);
            TargetMaxAngle = CycleOf( TargetMaxAngle+180, 360);
        }
        MBTi MaxScope = MAX(TargetMaxAngle,TargetMinAngle);
        MBTi MinScope = MIN(TargetMaxAngle,TargetMinAngle);

        MBTi AngleStepZ = (MaxScope-PointAngle)*(MaxScope<PointAngle)+
            (MinScope-PointAngle)*(MinScope>PointAngle);
        SGL.R_Common = TIntVec(0,0,AngleStepZ);
        //проверка на удовлетворение углу
        for (int i=0;i<3;i++)
            if ( ( fabs(SGL.R_Common.a[i]) > _ANGLEEPS.a[i] )
            && ( (360-fabs(SGL.R_Common.a[i]) ) > _ANGLEEPS.a[i] ) )
                return(false);
    }

    //шаг угла необходимый для совершения связки

    TIntVec OldCenter = PSource[SideInd]/VEC222;
    RSource = RotateAround(PSource[SideInd],SGL.R_Common,ZEROINTVEC);
    TIntVec NewCenter = RSource/VEC222;
    if (OldCenter.x==NewCenter.x && OldCenter.y==NewCenter.y)
        SGL.R_Common = ZEROINTVEC;
    else
    {
        MBTi OldAngle;
        MBTi NewAngle;
        OldAngle = AngleOf(ZEROMPOINT, OldCenter.AsPoint());
        NewAngle = AngleOf(ZEROMPOINT, NewCenter.AsPoint());
        SGL.R_Common = TIntVec(0,0,NewAngle - OldAngle);
    }

    if (MinMeasureIndex != -1)
    {
        SGL.CrossPoint = PTarget[MinMeasureIndex];
    }
    else if (IsLinesCrossedExactly(    ZEROINTVEC,
                                       RSource,
                                        PTarget[0],
                                        PTarget[1],
                                        SGL.CrossPoint  ) == lcPARRALEL)
    {
        return(false);
    }
    SGL.CrossPoint.z = RSource.z;

    SGL.TS_Common = RSource - SGL.CrossPoint;
    MBTi Sign;
    if (Measure(RSource)>Measure(SGL.CrossPoint))
        Sign=-1;
    else
        Sign=1;
    SGL.CrossPoint = SGL.CrossPoint + SGL.RotateCenter;
    //повернуть SizeChange
    double DeltaX = SGL.TS_Common.x;
    double DeltaY = SGL.TS_Common.y;
    MBTi SizeX = (MBTi)sqrtDC( DeltaX*DeltaX+DeltaY*DeltaY );
    SGL.TS_Common = TIntVec(Sign*SizeX,0,0);

    if ( !(ABSINTVEC(SGL.TS_Common) <= _SIZEEPS) )
        return(false);

    if (!(Source->MyMeta->Size.Valid(SGL.TS_Common+Source->AbsSize)))
        return(false);
    return true;
}*/                            


/*
bool ElementsCanLinkWall(   TElement *Target,
                            TElement *Source,
                            TLINKPATTERN &SGL,
                            bool _AnyWay)
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

    TIntVec _ANGLEEPS;
    TIntVec _EPS;
    TIntVec _SIZEEPS;

    _ANGLEEPS = Source->MyMeta->EPS.ANGLEEPS;
    _EPS = (Source->MyMeta->EPS.POSEPS);

    //Apply Angle
    SC = T3DScope(SGL.DL->Link->Angle.LOW,SGL.DL->Link->Angle.HI);
    TIntVec Angle = Source->AbsAngle -Target->AbsAngle;
    for (int i=0;i<3;i++)
        if (Angle.a[i]<0)
            Angle.a[i]=Angle.a[i]+360;
    SC.PointAbout(Angle,SGL.R_Common);
    for (int i=0;i<3;i++)
        if ( ( fabs(SGL.R_Common.a[i]) > _ANGLEEPS.a[i] )
            && ( (360-fabs(SGL.R_Common.a[i]) ) > _ANGLEEPS.a[i] ) )
            return(false);
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


    //проверка краев
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
        STEPS[i][j] = ABSINTVEC(PTarget[i] - PSource[j]);

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
    if (i0!=-1&&j0!=-1&&STEPS[i0][j0]<=_EPS)
    {
        SGL.TS_Common = PTarget[i0] - PSource[j0];
        Source->UserChangePosition(ZEROINTVEC,MINUSINTVEC*SGL.R_Common);
        SGL.CrossPoint = PTarget[i0];
        return true;
    }

    //проверка краев 2
    //близость этих точек для таргета определяются
    //в Un_Opt то же самое но наоборот
    SGL.CrossPoint.z = PSource[0].z;
    SC1.Move(Target->AbsPos);
    for (int i=0;i<2;i++)
    {
        TSource[i] = RotateAround(PSource[i],MINUSINTVEC*Target->AbsAngle,Target->AbsPos);
        SC1.PointAbout(TSource[i],STEPS[0][i]);
    }
    j0 = (int)(Measure(STEPS[0][1])<Measure(STEPS[0][0]));
    if (ABSINTVEC(STEPS[0][j0])<=_EPS)
    {
        SGL.TS_Common = RotateAround(STEPS[0][j0],Target->AbsAngle,ZEROINTVEC);
        //точка связки
        SGL.CrossPoint = PSource[j0] + SGL.TS_Common;
        Source->UserChangePosition( ZEROINTVEC,
                                    MINUSINTVEC*SGL.R_Common);
        return true;
    }

    //общее соединение

    switch (IsCutsCrossedExactly(PSource[0],PSource[1],PTarget[0],PTarget[1],SGL.CrossPoint))
    {
        case lcCOMMONPOINT:
        case lcCROSSING:
        case lcEQUAL:
        {
            SGL.CrossPoint.z = PSource[0].z;
            SGL.TS_Common = ZEROINTVEC;
            Source->UserChangePosition( ZEROINTVEC,
                                        MINUSINTVEC*SGL.R_Common);
            return true;
        }
        default:
        {
            Source->UserChangePosition(ZEROINTVEC,MINUSINTVEC*SGL.R_Common);
            return false;
        }
    }
}*/
#endif
