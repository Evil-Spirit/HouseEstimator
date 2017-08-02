//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "G2DApproxCalcV.h"
#include "G2DPointCutV.h"
#include <math.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)
int SIGN(MBTf Value,MBTf EPS)
{
    if ( Value>EPS )
        return 1;
    else if ( Value<-EPS )
        return -1;
    else
        return 0;
}

MBTf Dihotomia(TDihotomiaFunc Func,MBTf X0,MBTf X1,int Level,TMDelTList< TMTwinElement<bool,MBTf> > &Roots,MBTf EPS)
{
    //--------------------------------------------------------------------------
    MBTf ValueX0 = Func(X0,Level);
    if ( /*!IsNan(ValueX0) &&*/ ValueX0 == 0 )
        return X0;
    MBTf ValueX1 = Func(X1,Level);
    if ( /*!IsNan(ValueX1) &&*/ ValueX1 == 0 )
        return X1;

    if ( SIGN(ValueX0,EPS) == SIGN(ValueX1,EPS) && SIGN(ValueX0,EPS)!=0 )
    {
        Roots.Add( new TMTwinElement<bool,MBTf>() );
        Roots.Last()->Target = (X1+X0)/2;
        Roots.Last()->Data = false;
    }

    MBTf X = X0;
    MBTf _Value = ValueX0;
    MBTf PrevValue;
    //--------------------------------------------------------------------------
    do
    {
        PrevValue = _Value;
        X = (X0+X1)/2;
        _Value = Func(X,Level);
        //if ( IsNan(_Value) )

        if ( SIGN(_Value,EPS) == SIGN(ValueX0,EPS) )
        {
            X0 = X;
            ValueX0 = _Value;
        }
        else
        {
            X1 = X;
            ValueX1 = _Value;
        }

    }
    while ( fabs(PrevValue-_Value) != 0 );
    //--------------------------------------------------------------------------
    Roots.Add( new TMTwinElement<bool,MBTf>() );
    Roots.Last()->Target = (X1+X0)/2;
    Roots.Last()->Data = false;
}


void TEquation::FindDerivativeRoot(MBTf X0,MBTf X1,TMDelTList<MBTf>& X,int Level,MBTf EPS)
{
    if ( Level >= GetLevel() )
        throw EMyException("<TEquation::FindDerivativeRoot>: inadmissible level");
    if ( Level == GetLevel()-1 && SIGN(X0) == SIGN(X1) )
        throw EMyException("<TEquation::FindDerivativeRoot>: insufficient range");
    if ( Level == GetLevel()-1 )
    {
        AddRoot(X,Dihotomia(Derivative,X0,X1,Level,EPS),EPS);
        return;
    }
    TMDelTList<MBTf> CheckPoints;
    FindDerivativeRoot(X0,X1,CheckPoints,Level+1,EPS);
    TMDelTList<int> SGNS;

    if (CheckPoints.Count==0)
    {
        CheckPoints.Add( new MBTf(X0) );
        CheckPoints.Add( new MBTf(X1) );
        //return;//корней нет
    }
    else
    {
        if ( CheckPoints[0]!=X0 )
            CheckPoints.Insert( 0,new MBTf(X0) );
        if ( *CheckPoints.Last() != X1 )
            CheckPoints.Add( new MBTf(X1) );
    }
    for ( int i=0; i<CheckPoints.Count; i++ )
        SGNS.Add( new int( SIGN(Derivative(CheckPoints[i],Level),EPS) ) );
    for ( int i=0; i<CheckPoints.Count-1; i++ )
        if ( SGNS[i] == 0 )
        {
            if ( i!=0 )
            {
                if ( SGNS[i-1] == SGNS[i+1] )
                {
                    SGNS.Delete(i+1);
                    CheckPoints.Delete(i+1);
                    i--;
                }
                else
                {
                    SGNS.Delete(i);
                    CheckPoints.Delete(i);
                    i--;
                }
            }
        }
        else
        {
            if ( SGNS[i] == SGNS[i+1] )
            {
                SGNS.Delete(i+1);
                CheckPoints.Delete(i+1);
                i--;
            }
        }

    for (int i=0;i<CheckPoints.Count-1;i++)
        AddRoot(X,Dihotomia(Derivative,CheckPoints[i],CheckPoints[i+1],Level,EPS),EPS );
}

void TEquation::FindRoots(MBTf X0,MBTf X1,TMDelTList<MBTf>& X,MBTf EPS)
{
    try
    {
        Roots.Clear();
        FindDerivativeRoot(X0,X1,X,0,EPS);
    }
    catch(EMyException& MyExc)
    {
        ErrorMsg("<TEquation::FindRoots>: Equation solving error.");
    }

}


void TEquation::ToGeomObject(TGeomObject* GO,MBTf X0,MBTf X1,int Level,int Count)
{
    MBTf Step = (X1-X0)/Count;
    TMDelTList<TIntVec> Lst;
    for (int i=0;i<=Count;i++)
    {
        MBTf X = X0+i*Step;
        Lst.Add( new TIntVec(X,Derivative(X,Level),0) );
    }
    ListToGeomObject(GO,Lst,true);
}

void TEquation::RootsToGeomObject(TGeomObject* GO,MBTf X0,MBTf X1,MBTf EPS)
{
    TMDelTList<MBTf> X;
    TMDelTList<TIntVec> Lst;
    FindRoots(X0,X1,X,EPS);
    for (int i=0;i<X.Count;i++)
    {
        Lst.Add( new TIntVec(X[i],Derivative(X[i],0),0) );
    }
    ListToGeomObject(GO,Lst,false);
}

MBTf TPolinom::Derivative(MBTf X,int Level)
{
    MBTf Value = *DA[Level].Last();
    MBTf X_I = 1; 
    for ( int i=DA[Level].Count-2;i>=0;i-- )
    {
        X_I = X_I*X;
        Value = Value+DA[Level][i]*X_I;
    }
    return Value;
}

int TPolinom::GetLevel()
{
    return (DA[0].Count-1);
}

void TPolinom::Initialize(const TMTList<MBTf>& A)
{
    DA.Add( new TMDelTList<MBTf>() );
    for (int i=0;i<A.Count;i++)
        DA[0].Add( new MBTf(A[i]) );
    for (int i=1;i<A.Count;i++)
    {
        DA.Add( new TMDelTList<MBTf>() );
        for (int j=0;j<A.Count-i;j++)
            DA[i].Add( new MBTf( (DA[i-1].Count-1-j)*DA[i-1][j] ) );
    }
}


TFunctionCrossing::TFunctionCrossing()
{
    F1 = NULL;
    F2 = NULL;
    FLevel = -1;
}

void TFunctionCrossing::Initialize( const TMFunction& _F1,int Level1,const TMFunction& _F2,int Level2 )
{
    F1 = &_F1;
    F2 = &_F2;
    FLevel = MAX(Level1,Level2);
}

MBTf TFunctionCrossing::Derivative(MBTf X,int Level)
{
    if (Level == 0)
    {
        MBTf val1 = F1->CalcValue(X);
        MBTf val2 = F2->CalcValue(X);
        if ( IsNan(val1) || IsNan(val2) )
            return NaN;
        else
            return (val1 - val2);
    }
    else
        return (Derivative(X+ArgumentDelta,Level-1) - Derivative(X,Level-1))/ArgumentDelta;
}

int TFunctionCrossing::GetLevel()
{
    return FLevel;
}

