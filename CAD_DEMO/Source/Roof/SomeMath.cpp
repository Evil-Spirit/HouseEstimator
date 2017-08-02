//---------------------------------------------------------------------------

#pragma hdrstop

#include "SomeMath.h"
//---------------------------------------------------------------------------

bool PlanesParallel(const TIntVec& N1,const TIntVec& N2,MBTi USEEPS)
{
	return ( ((N1-N2).Length()<USEEPS) || ((N1+N2).Length()<USEEPS) );
}
int PlaneCrossPoint2(   const TIntVec& A,//точка на плоскости
						const TIntVec& N,//нормаль
						const TIntVec& X,//прямая точка 1
						const TIntVec& Y,//прямая точка 2
						TIntVec& O, //точка пересечения
						MBTi USEEPS)    //мера параллельности
{
	TIntVec V = A - X ;
	// расстояние до плоскости по нормали
	MBTi d = ScalarP ( N, V );
	TIntVec W = Y - X;
	// приближение к плоскости по нормали при прохождении отрезка
	MBTi e = ScalarP ( N, W );

	if( fabs(e)>USEEPS )
	{
		O = X + W * (d/e);
		return 1;
	}
	else if( fabs(d)<=USEEPS)
	{
		O = X;
		return 2;
	}
	else
		return 0;               
}
//поиск пересечения луча и плоскости
//1 - одна точка
//2 - прямая принадлежит плоскости
//0 - прямая и плоскость параллельны
//3 - точка пресечения не лежит на луче
int PlaneAndLineCrossed(const TIntVec& A,//точка на плоскости
						const TIntVec& N,//нормаль
						const TIntVec& X,//прямая точка 1
						const TIntVec& Y,//прямая точка 2
						bool xFixed,
						bool yFixed,
						TIntVec& O, //точка пересечения
						MBTi USEEPS)    //мера параллельности
{
	TIntVec V = A - X;
	// расстояние до плоскости по нормали
	MBTi d = ScalarP ( N, V );
	TIntVec W = Y - X;
	// приближение к плоскости по нормали при прохождении отрезка
	MBTi e = ScalarP ( N, W );

	if( fabs(e)>USEEPS )
	{
		MBTi k = d/e;
		O = X + W * k;
		if ( (xFixed && !( k>=-USEEPS)) || (yFixed && !(k<= 1+USEEPS)) ) 
			return PL_CROSS_OUTOFBORDER;
		else
			return PL_CROSS_ONEPOINT;
	}
	else if( fabs(d)<=USEEPS)
	{
		O = X;
		return PL_CROSS_CONSISTS;
	}
	else
		return PL_CROSS_PARALLEL;               
}

//проверка коллинеарности двух плоскостей
bool PlanesCollinear(   const TIntVec& X1,//точка на плоскости
						const TIntVec& N1,//нормаль
						const TIntVec& X2,
						const TIntVec& N2,
						MBTi USEEPS  )
{
	TIntVec CP;
	if ((N1-N2).Length()>USEEPS)
		return false;
	if ( fabs( ScalarP(N1, X1) - ScalarP(N2, X2) ) >USEEPS)
		return false;
	return true;
}

#pragma package(smart_init)

