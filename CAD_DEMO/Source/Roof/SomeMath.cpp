//---------------------------------------------------------------------------

#pragma hdrstop

#include "SomeMath.h"
//---------------------------------------------------------------------------

bool PlanesParallel(const TIntVec& N1,const TIntVec& N2,MBTi USEEPS)
{
	return ( ((N1-N2).Length()<USEEPS) || ((N1+N2).Length()<USEEPS) );
}
int PlaneCrossPoint2(   const TIntVec& A,//����� �� ���������
						const TIntVec& N,//�������
						const TIntVec& X,//������ ����� 1
						const TIntVec& Y,//������ ����� 2
						TIntVec& O, //����� �����������
						MBTi USEEPS)    //���� ��������������
{
	TIntVec V = A - X ;
	// ���������� �� ��������� �� �������
	MBTi d = ScalarP ( N, V );
	TIntVec W = Y - X;
	// ����������� � ��������� �� ������� ��� ����������� �������
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
//����� ����������� ���� � ���������
//1 - ���� �����
//2 - ������ ����������� ���������
//0 - ������ � ��������� �����������
//3 - ����� ���������� �� ����� �� ����
int PlaneAndLineCrossed(const TIntVec& A,//����� �� ���������
						const TIntVec& N,//�������
						const TIntVec& X,//������ ����� 1
						const TIntVec& Y,//������ ����� 2
						bool xFixed,
						bool yFixed,
						TIntVec& O, //����� �����������
						MBTi USEEPS)    //���� ��������������
{
	TIntVec V = A - X;
	// ���������� �� ��������� �� �������
	MBTi d = ScalarP ( N, V );
	TIntVec W = Y - X;
	// ����������� � ��������� �� ������� ��� ����������� �������
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

//�������� �������������� ���� ����������
bool PlanesCollinear(   const TIntVec& X1,//����� �� ���������
						const TIntVec& N1,//�������
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

