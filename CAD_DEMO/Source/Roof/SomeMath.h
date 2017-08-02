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

int __declspec(dllexport) PlaneCrossPoint2(   const TIntVec& A,//����� �� ���������
						const TIntVec& N,//�������
						const TIntVec& X,//������ ����� 1
						const TIntVec& Y,//������ ����� 2
						TIntVec& O, //����� �����������
						MBTi USEEPS);    //���� ��������������

int __declspec(dllexport) PlaneAndLineCrossed(const TIntVec& A,//����� �� ���������
						const TIntVec& N,//�������
						const TIntVec& X,//������ ����� 1
						const TIntVec& Y,//������ ����� 2
						bool xFixed,
						bool yFixed,
						TIntVec& O, //����� �����������
						MBTi USEEPS);    //���� ��������������

bool __declspec(dllexport) PlanesCollinear(   const TIntVec& X1,//����� �� ���������
						const TIntVec& N1,//�������
						const TIntVec& X2,
						const TIntVec& N2,
						MBTi USEEPS  );
#endif

