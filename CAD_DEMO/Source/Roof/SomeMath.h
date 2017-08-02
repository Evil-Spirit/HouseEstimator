//---------------------------------------------------------------------------

#ifndef SomeMathH
#define SomeMathH

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

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

int __declspec(dllexport) PlaneCrossPoint2(   const TIntVec& A,//точка на плоскости
						const TIntVec& N,//нормаль
						const TIntVec& X,//прямая точка 1
						const TIntVec& Y,//прямая точка 2
						TIntVec& O, //точка пересечения
						MBTi USEEPS);    //мера параллельности

int __declspec(dllexport) PlaneAndLineCrossed(const TIntVec& A,//точка на плоскости
						const TIntVec& N,//нормаль
						const TIntVec& X,//прямая точка 1
						const TIntVec& Y,//прямая точка 2
						bool xFixed,
						bool yFixed,
						TIntVec& O, //точка пересечения
						MBTi USEEPS);    //мера параллельности

bool __declspec(dllexport) PlanesCollinear(   const TIntVec& X1,//точка на плоскости
						const TIntVec& N1,//нормаль
						const TIntVec& X2,
						const TIntVec& N2,
						MBTi USEEPS  );
#endif

