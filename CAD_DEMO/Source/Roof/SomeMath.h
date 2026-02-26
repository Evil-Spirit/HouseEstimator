// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef SomeMathH
#define SomeMathH

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "RoofV.h"
#include "Poligon.h"
#include "math.h"
#include "MyGL.h"

//---------------------------------------------------------------------------
#define PL_CROSS_ONEPOINT 1
#define PL_CROSS_PARALLEL 0
#define PL_CROSS_OUTOFBORDER 3
#define PL_CROSS_CONSISTS 2

bool __declspec(dllexport) PlanesParallel(const TIntVec& N1,const TIntVec& N2,MBTi USEEPS);

int __declspec(dllexport) PlaneCrossPoint2(   const TIntVec& A,//òî÷êà íà ïëîñêîñòè
						const TIntVec& N,//íîðìàëü
						const TIntVec& X,//ïðÿìàÿ òî÷êà 1
						const TIntVec& Y,//ïðÿìàÿ òî÷êà 2
						TIntVec& O, //òî÷êà ïåðåñå÷åíèÿ
						MBTi USEEPS);    //ìåðà ïàðàëëåëüíîñòè

int __declspec(dllexport) PlaneAndLineCrossed(const TIntVec& A,//òî÷êà íà ïëîñêîñòè
						const TIntVec& N,//íîðìàëü
						const TIntVec& X,//ïðÿìàÿ òî÷êà 1
						const TIntVec& Y,//ïðÿìàÿ òî÷êà 2
						bool xFixed,
						bool yFixed,
						TIntVec& O, //òî÷êà ïåðåñå÷åíèÿ
						MBTi USEEPS);    //ìåðà ïàðàëëåëüíîñòè

bool __declspec(dllexport) PlanesCollinear(   const TIntVec& X1,//òî÷êà íà ïëîñêîñòè
						const TIntVec& N1,//íîðìàëü
						const TIntVec& X2,
						const TIntVec& N2,
						MBTi USEEPS  );
#endif

