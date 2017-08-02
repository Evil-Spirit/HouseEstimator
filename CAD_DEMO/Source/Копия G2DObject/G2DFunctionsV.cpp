//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "G2DFunctionsV.h"
#include "math.h"
#include "MyGL.h"
#include "Poligon.h"
#include "mem.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


TPoint PointFromVMV(const TVisMathVector& VMV)
{
    return TPoint(VMV.x,VMV.y);
}

MBTi Factor(TVisView* VisView,double Depth)
{
    if (!VisView->Current)
        VisView->Current = true;
    TIntVec Vec0 = VisView->WinTo3D(0,0,Depth);
    TIntVec Vec1 = VisView->WinTo3D(100,0,Depth);
    return (Vec1-Vec0).Length()/100;
}


void Arc3D( TMDelTList<TIntVec>& PointList,
            const TIntVec& Center,
            const TIntVec& P1,
            const TIntVec& P2,
            int Detail)
{
    TIntVec NewP1 = P1-Center;
    TIntVec NewP2 = P2-Center;
    MBTi Radius = NewP1.Length();
    MBTi angle1 = AngleRadOX(Center,P1);
    MBTi angle2 = AngleRad(P2,Center,P1)+angle1;
    MBTi angle_step = (angle2-angle1)/Detail;
    PointList.Add( new TIntVec(NewP1) );
	for (int i=1;i<Detail;i++)
    {
        long double cos,sin;
        SinCos(angle1+angle_step*i,sin,cos);
		PointList.Add( new TIntVec( cos*Radius,sin*Radius,NewP1.z ) );
        PointList.Add( new TIntVec( PointList[PointList.Count-1] ) );
    }
    PointList.Add( new TIntVec(NewP2) );
    for (int i=0;i<PointList.Count;i++)
        PointList[i]+=Center;
}

void MakeArrow(const TIntVec& P0,const TIntVec& P1,TIntVec& ArrowP11,TIntVec& ArrowP12,MBTi Length,MBTi Width,bool Back)
{
    TIntVec Angle;
    Angle.z = -((AngleRadOX(P0,P1))*180)/M_PI;
    TIntVec locP1 = RotateAround(P1,Angle,P0);
    ArrowP11 = TIntVec( (locP1.x + ( (Back)? Length : (-Length) ) ), locP1.y+Width, locP1.z);
    ArrowP12 = TIntVec( (locP1.x + ( (Back)? Length : (-Length) ) ) , locP1.y-Width, locP1.z);
    Angle.z = -Angle.z;
    ArrowP11 = RotateAround(ArrowP11,Angle,P0);
    ArrowP12 = RotateAround(ArrowP12,Angle,P0);
}

void MakeArrowsOnList(TMDelTList<TIntVec>& PointList,MBTi Length,MBTi Width,bool Back)
{
    if (PointList.Count<2)
        throw EMyException("<MakeArrowsOnList>: List size is less than 2.");
    TIntVec Arrows0;
    TIntVec Arrows1;
    TIntVec End = PointList[PointList.Count-1];
    TIntVec Start = PointList[0];
    MakeArrow(PointList[PointList.Count-2],PointList[PointList.Count-1],Arrows0,Arrows1,Length,Width,Back);
    PointList.Add(new TIntVec(Arrows0));
    PointList.Add(new TIntVec(End));
    PointList.Add(new TIntVec(Arrows1));
    PointList.Add(new TIntVec(End));

    MakeArrow(PointList[1],PointList[0],Arrows0,Arrows1,Length,Width,Back);
    PointList.Add(new TIntVec(Arrows0));
    PointList.Add(new TIntVec(Start));
    PointList.Add(new TIntVec(Arrows1));
    PointList.Add(new TIntVec(Start));
}

void Arc3D( TVisPrimitiveObj* Obj,
            int PrimitiveArrayIndex,
            const TIntVec& Center,
            const TIntVec& P1,
            const TIntVec& P2,
            int Detail)
{
    TMDelTList<TIntVec> PointList;
    Arc3D(PointList,Center,P1,P2,Detail);
    for (int i=0;i<PointList.Count;i++)
        Obj->AddIndex(Obj->Points->Add(PointList[i],ZEROVEC,ZEROVEC) ,PrimitiveArrayIndex );
}


void AddRayToPointList( TMDelTList<TIntVec>& PointList,
                        const TIntVec& ArcPoint,
                        const TIntVec& P0,
                        const TIntVec& P1,
                        const TIntVec& Center)
{
    if ( Classify(Center,P0,P1,_MBTi_eps_) == etBETWEEN )
    {
        PointList.Add(new TIntVec(Center));
    }
    else
    {
        MBTi P0Length = (P0-ArcPoint)&(P0-ArcPoint);
        MBTi P1Length = (P1-ArcPoint)&(P1-ArcPoint);
        PointList.Add(new TIntVec( (P0Length<P1Length)? P0:P1 ));
    }
    PointList.Add(new TIntVec(ArcPoint));
}

bool ConsistsNotStrictly(const TIntVec& P,const TIntVec& A,const TIntVec& B,MBTi USEEPS)
{
    switch( Classify(P,A,B,USEEPS) )
    {
        case etDESTINATION:
        case etORIGIN:
        case etBETWEEN:
            return true;
        default:
            return false;
    };
}

bool CrossPointStrictly(
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& B0,
                        const TIntVec& B1,
                        TIntVec& CP,
                        MBTi USEEPS)
{
    
    if (    ConsistsNotStrictly(A0,B0,B1,USEEPS) ||
            ConsistsNotStrictly(A1,B0,B1,USEEPS) ||
            ConsistsNotStrictly(B0,A0,A1,USEEPS) ||
            ConsistsNotStrictly(B1,A0,A1,USEEPS) )
    {
        //touching
        return false;
    }
    return (IsCutsCrossed(A0,A1,B0,B1,CP,USEEPS) == lcCROSSING);
}

bool CrossPointNotStrictly(
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& B0,
                        const TIntVec& B1,
                        TIntVec& CP,
                        MBTi USEEPS)
{
    switch ( IsLinesCrossedExactly(A0,A1,B0,B1,CP/*,USEEPS*/) )
    {
        case lcCOLLINEAR:
        {
            CP = A0;
            return true;
        }
        case lcCOMMONPOINT:
        case lcCROSSING:
        case lcEQUAL:
            return true;
        case lcNONE:
        case lcPARALLEL:
            return false;
        default:
            throw EMyException("<CrossPointNotStrictly>: Unexpected result IsLinesCrossed");
    }
}

void AddVectorToList(   TMDelTList<TIntVec>& PointList,
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& P00,
                        const TIntVec& P11,
                        MBTi USEEPS)
{
    if (    ( A0.x<P00.x && A1.x<P00.x )||
            ( A0.y<P00.y && A1.y<P00.y )||
            ( A0.x>P11.x && A1.x>P11.x )||
            ( A0.y>P11.y && A1.y>P11.y )    )
    {
        PointList.Add( new TIntVec(A0) );
        PointList.Add( new TIntVec(A1) );
        return;
    }


    TIntVec P10 = TIntVec(P11.x,P00.y,P00.z);
    TIntVec P01 = TIntVec(P00.x,P11.y,P00.z);
    TMTList<TIntVec> TmpList;
    TIntVec CP1,CP2,CP3,CP4;
    if ( CrossPointStrictly(A0,A1,P00,P10,CP1,USEEPS) )
        TmpList.Add( &(CP1) );
    if ( CrossPointStrictly(A0,A1,P00,P01,CP2,USEEPS) )
        TmpList.Add( &(CP2) );
    if ( CrossPointStrictly(A0,A1,P11,P10,CP3,USEEPS) )
        TmpList.Add( &(CP3) );
    if ( CrossPointStrictly(A0,A1,P11,P01,CP4,USEEPS) )
        TmpList.Add( &(CP4) );

    bool Changed = true;
    while (Changed)
    {
        Changed = false;
        for (int i=0;i<TmpList.Count-1;i++)
            //dot product
            if ( ( (TmpList[i]-A0) & (TmpList[i]-A0) ) > ( (TmpList[i+1]-A0) & (TmpList[i+1]-A0) ) /* i+1 closer to A0 than i */)
            {
                TmpList.Exchange(i,i+1);
                Changed = true;
            }
    }
    TmpList.Insert(0, (TIntVec*)&(A0) );
    TmpList.Add( (TIntVec*)&(A1) );
    for (int i=0;i<TmpList.Count-1;i++)
    {
        TIntVec Middle = (TmpList[i]+TmpList[i+1])/2;
        if (    Middle.x <= P11.x &&
                Middle.x >= P00.x &&
                Middle.y <= P11.y &&
                Middle.y >= P00.y )
            continue;
        PointList.Add( new TIntVec(TmpList[i]) );
        PointList.Add( new TIntVec(TmpList[i+1]) );
    }
}

void CopyPen(const TVisPen& Src,TVisPen& Dst)
{
    memcpy(&Dst,&Src,sizeof(TVisPen));
}

void SetPen(TVisPen& ChangedPen,const TVisPen& NewPen,TVisPen* SavePen)
{
    if (SavePen)
        CopyPen(ChangedPen,*SavePen);
    CopyPen(NewPen,ChangedPen);
}

