// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------


#include "SomeMath.h"
//---------------------------------------------------------------------------

bool PlanesParallel(const TIntVec& N1,const TIntVec& N2,MBTi USEEPS)
{
	return ( ((N1-N2).Length()<USEEPS) || ((N1+N2).Length()<USEEPS) );
}
int PlaneCrossPoint2(   const TIntVec& A,//òî÷êà íà ïëîñêîñòè
						const TIntVec& N,//íîðìàëü
						const TIntVec& X,//ïðÿìàÿ òî÷êà 1
						const TIntVec& Y,//ïðÿìàÿ òî÷êà 2
						TIntVec& O, //òî÷êà ïåðåñå÷åíèÿ
						MBTi USEEPS)    //ìåðà ïàðàëëåëüíîñòè
{
	TIntVec V = A - X ;
	// ðàññòîÿíèå äî ïëîñêîñòè ïî íîðìàëè
	MBTi d = ScalarP ( N, V );
	TIntVec W = Y - X;
	// ïðèáëèæåíèå ê ïëîñêîñòè ïî íîðìàëè ïðè ïðîõîæäåíèè îòðåçêà
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
//ïîèñê ïåðåñå÷åíèÿ ëó÷à è ïëîñêîñòè
//1 - îäíà òî÷êà
//2 - ïðÿìàÿ ïðèíàäëåæèò ïëîñêîñòè
//0 - ïðÿìàÿ è ïëîñêîñòü ïàðàëëåëüíû
//3 - òî÷êà ïðåñå÷åíèÿ íå ëåæèò íà ëó÷å
int PlaneAndLineCrossed(const TIntVec& A,//òî÷êà íà ïëîñêîñòè
						const TIntVec& N,//íîðìàëü
						const TIntVec& X,//ïðÿìàÿ òî÷êà 1
						const TIntVec& Y,//ïðÿìàÿ òî÷êà 2
						bool xFixed,
						bool yFixed,
						TIntVec& O, //òî÷êà ïåðåñå÷åíèÿ
						MBTi USEEPS)    //ìåðà ïàðàëëåëüíîñòè
{
	TIntVec V = A - X;
	// ðàññòîÿíèå äî ïëîñêîñòè ïî íîðìàëè
	MBTi d = ScalarP ( N, V );
	TIntVec W = Y - X;
	// ïðèáëèæåíèå ê ïëîñêîñòè ïî íîðìàëè ïðè ïðîõîæäåíèè îòðåçêà
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

//ïðîâåðêà êîëëèíåàðíîñòè äâóõ ïëîñêîñòåé
bool PlanesCollinear(   const TIntVec& X1,//òî÷êà íà ïëîñêîñòè
						const TIntVec& N1,//íîðìàëü
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


