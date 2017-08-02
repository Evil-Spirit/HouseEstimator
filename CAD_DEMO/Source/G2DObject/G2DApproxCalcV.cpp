//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "G2DApproxCalcV.h"
#include "G2DGeomV.h"
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

void Dihotomia(TDihotomiaFunc Func,MBTf X0,MBTf X1,int Level,TMDelTList< TMTwinElement<bool,MBTf> > &Roots,MBTf EPS)
{
    //--------------------------------------------------------------------------
    MBTf ValueX0 = Func(X0,Level);
    if (  ValueX0 == 0 )
    {
        Roots.Add( new TMTwinElement<bool,MBTf>() );
        Roots.Last()->Target = X0;
        Roots.Last()->Data = true;
    }
    MBTf ValueX1 = Func(X1,Level);
    if (  ValueX1 == 0 )
    {
        Roots.Add( new TMTwinElement<bool,MBTf>() );
        Roots.Last()->Target = X1;
        Roots.Last()->Data = true;
    }

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
    Roots.Last()->Target = X;
    Roots.Last()->Data = true;
}

void TEquation::FindDerivativeRoot(MBTf X0,MBTf X1,TMDelTList< TMTwinElement<bool,MBTf> >& Roots,int Level,MBTf EPS)
{
    if ( Level >= GetLevel() )
        throw EMyException("<TEquation::FindDerivativeRoot>: недопустимый уровень");
    if ( Level == GetLevel()-1 )
    {
		Dihotomia(&Derivative,X0,X1,Level,Roots,EPS);
        return;
    }
	TMDelTList< TMTwinElement<bool,MBTf> > CheckPoints;
    FindDerivativeRoot(X0,X1,CheckPoints,Level+1,EPS);

	CheckPoints.Insert( 0,new TMTwinElement<bool,MBTf> );
    CheckPoints[0].Target = X0;
    CheckPoints[0].Data = false;
    
	CheckPoints.Add( new TMTwinElement<bool,MBTf> );
    CheckPoints.Last()->Target = X1;
    CheckPoints.Last()->Data = false;

    for (int i=0;i<CheckPoints.Count-1;i++)
		Dihotomia(&Derivative,CheckPoints[i].Target,CheckPoints[i+1].Target,Level,Roots,EPS);
}

void TEquation::CleanRoots(TMDelTList< TMTwinElement<bool,MBTf> >& Roots,MBTf EPS)
{
	for (int i=0;i<Roots.Count;i++)
    	if ( Roots[i].Data == false )
        	Roots.Delete(i--);
	for (int i=0;i<Roots.Count-1;i++)
    	if ( fabs(Roots[i].Target - Roots[i+1].Target) <= EPS )
        {
        	if ( fabs( Derivative(Roots[i].Target,0) )> fabs( Derivative(Roots[i+1].Target,0) ) )
            	Roots.Delete(i--);
            else
            {
            	Roots.Delete(i+1);
                i--;
            }
        }
}

void TEquation::FindRoots(MBTf X0,MBTf X1,TMDelTList<MBTf>& X,MBTf EPS,bool Clean)
{
    try
    {
        X.Clear();
		TMDelTList< TMTwinElement<bool,MBTf> > Roots;
        FindDerivativeRoot(X0,X1,Roots,0,EPS);
        if (Clean)
        	CleanRoots(Roots,EPS);
        for (int i=0;i<Roots.Count;i++)
        	X.Add( new MBTf( Roots[i].Target ) );
    }
    catch(EMyException& MyExc)
    {
        ErrorMsg("<TEquation::FindRoots>: Произошла ошибка при нахождении корней.");
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

