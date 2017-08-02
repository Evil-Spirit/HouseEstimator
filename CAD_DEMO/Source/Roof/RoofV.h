//---------------------------------------------------------------------------

#ifndef RoofV
#define RoofV
//---------------------------------------------------------------------------
#include "TGObject.h"

class TRoof;

class TRoofPlane
{
public:
	MBTi Angle;
	MBTi Height;
	bool Front;
	TRoofPlane() : Angle(45), Height(0), Front(false) {}

	TRoofPlane &operator=(TRoofPlane &o)
	{
		Angle = o.Angle;
		Height = o.Height;
		Front = o.Front;
		return *this;
	}
};

class TRoofSide
{
public:
	TGCut *Cut;
	TMDelTList <TRoofPlane> Planes;
	MBTi Salient;

	TRoofSide& operator =(const TRoofSide &o)
	{
		Cut = o.Cut;

		Planes.Clear();

		for (int i=0;i<o.Planes.Count;i++)
		{
			Planes.Add( new TRoofPlane() );
			Planes[Planes.Count-1].operator=(o.Planes[i]);

		}

		Salient = o.Salient;
		return *this;
	}

	TRoofSide() : Cut(NULL), Salient(0) {};
	TRoofSide(TGCut *c) : Cut(c), Salient(0) {};
};

void GetRoofPlanes(const TMDelTList<TRoofSide> &side, TMDelTList<TMDelTList<TIntVec> > &n,  TMDelTList<TMDelTList<TIntVec> > &o);
void Lathing(const TGeomObject &roof, TGeomObject &lath);

class TPreTriangle : public TMyObject{
public:
	static TClassNode* StaticType;
	TMyObject* CreateFunction()
	{
		return new TPreTriangle();
	}
	TPreTriangle()
	{
		RegisterNewClass<TMyObject,TPreTriangle >(this,false,&CreateFunction);
		CrossPointLeft	= NULL;
		CrossPointRight	= NULL;
		TruePointLeft	= NULL;
		TruePointRight	= NULL;
		Slope			= 0;
		Plane			= 0;
		Length			= 99999;        
		Criteria		= 0;        
		bool iAmNotBad	= false;
		bool yesIAm		= true;
	};
	virtual ~TPreTriangle(){};

	TGPoint* TruePointLeft;				//����� ����� �� ��� ��������
	TGPoint* TruePointRight;				//������ ����� �� ��� ��������
	TGPoint* CrossPointLeft;				//����� ����� �����������
	TGPoint* CrossPointRight;			//������ ����� �����������

	MBTi Length;							//�������� ���� ��� ��������
	MBTi Criteria;							//�������� ���� ��� ��������


	int Plane;								//������� ���������
	TMDelTList<int>	Planes;					//������� ���������
	int Slope;

	bool iAmNotBad;							//� �� ������
	bool yesIAm;                            //� ����!
	bool IAmTriangle;                            //� ����!
	

/**/

	bool IAmBadLeft(TPreTriangle* Left);	//�������� �� ���� �����
	bool IAmBadRight(TPreTriangle* Right);	//�������� �� ���� ������

	void CalcScatProject(TPreTriangle *left, TPreTriangle *right);	//���������� ��������
	void amIEvil();							//

	void Assign(TMyObject* Obj)
	{
		TPreTriangle* PT = ( TPreTriangle*)Obj;

		TruePointLeft = PT->TruePointLeft;
		TruePointRight = PT->TruePointRight;

		CrossPointLeft = PT->CrossPointLeft;
		CrossPointRight = PT->CrossPointRight;

		Length = PT->Length;
		Criteria = PT->Criteria;

		yesIAm = PT->yesIAm;
		iAmNotBad = PT->iAmNotBad;

		Planes.Assign(&PT->Planes);
		Slope = PT->Slope;
		Plane = PT->Plane;
	}        
};

TClassNode* TPreTriangle::StaticType = NULL;

//������� ���� ������������ ����������

class TCollinearEdge{
public:
	TCollinearEdge(){};
	virtual ~TCollinearEdge(){};

	//����� �� ����� ����������� ���������� ������� �� ������� 
	TMTList<TGPoint> COMMON;
	TMTList<TGPoint> sepPoint;

	TIntVec rayDir[2];
};
/*
class TCollinearEdge{
public:
	TCollinearEdge(){};
	virtual ~TCollinearEdge(){};
	//������ ������� ��� ������  (����� � �������)

	//����� �� ����� ����������� ���������� ������� �� ������� 
	TMTList<TRoofPoint> COMMON;
};
*/

//������ ��������������
//���������� ��������� ������������ ����������
//������ ������� �� ����������
//��������� ���� ���� �� ���� ��������� �� ������������
//�������� ����� �������� ����� �� � ��� ��������� ����� ��������
//������� ����� ����� ��������� � ������ ������ ������������ ����������
class TCollinearGroup{
public:
	TCollinearGroup(){};
	virtual ~TCollinearGroup(){};
	//������ ������ ��������������
	TMDelTList<TCollinearEdge> Edges;
	//������ ������� ����������
	TMDelTList<int> indices;
	//�������� ����� - ����� ���������� ���������� �����
	void InsertPoint(TMDelTList<int> &PntPlane, TGPoint* Pnt,MBTi USEEPS);
	//�������� �� ��� ������������ ��������� ���������
	bool IsNeigh(int i1,int i2);
	//���������������� ������� ������������ ����������
	//���� ������ ���������
	//����� � ������� ���������� �������� � �������� ����������
	void Init(TMTList<TIntVec>& Vert,TMTList<TIntVec>& Norm);
};

class  TRoof : public TGeomObject
{
	friend class TCollinearGroup;
	public:
	TMDelTList< TMDelTList< TMTList<TGPoint> > > PntCube;//��� ����� ����������� ���� ����������
	TMDelTList< TMDelTList<TIntVec> > DirMatrix; //������� ����������� ����� ����������� ��� ������ ���� ����������
	TMDelTList< TMDelTList<TIntVec> > OrgMatrix; //������� ����� �� ������ �����������
	TMDelTList< TMDelTList<int> > PntPlane;

	TMTList<TIntVec> p_Normal;  //������� ��� ������� ����������
	TMTList<TIntVec> p_Origin;  //����� �� ����������

	TMDelTList< TMDelTList<int> > p_Roof;  //������� ��� ������� ����������

	TMTList<int> p_Slope;  //�����
	TMTList<int> p_Plane;  //���������

	TMDelTList<TPreTriangle> PRE_TRI;

	TMDelTList< TMTList<TGCut> > POLY;

	TMDelTList< bool > Convex; //���������� ����� �������

public:

	bool ProcessGeometry(	TMDelTList< TMDelTList<TIntVec> > &p_N,
							TMDelTList< TMDelTList<TIntVec> > &p_O,
							TIntVec& b_N,
							TIntVec& b_O);

	bool Build(	TMDelTList< TMDelTList<TIntVec> > &p_N,
							TMDelTList< TMDelTList<TIntVec> > &p_O,
							TIntVec& b_N,
							TIntVec& b_O);


	bool BuildRoofRecurrent(TMDelTList<TPreTriangle> &PRE_TRI, TMDelTList<TMTList<TGCut> > &RESULT);
	void CalculateStatistics(TMDelTList<TPreTriangle> &PRE_TRI);
	void ProcessPreTriangle(int minindex, TMDelTList<TPreTriangle> &PRE_TRI, TMDelTList<TMTList<TGCut> > &RESULT);
	void DivideTriangle(TMDelTList<TPreTriangle> &PRE_TRI, int index, TMDelTList<TMTList<TGCut> > &RESULT);
	void Clean();


	TRoof(){};
	
	virtual ~TRoof(){};
};


void COMMONAL_API ConstructRoof(
				TMDelTList< TMDelTList<TIntVec> > &p_N,
				TMDelTList< TMDelTList<TIntVec> > &p_O,
				TIntVec& b_N,
				TIntVec& b_O,
				TGeomObject &O
				);

void COMMONAL_API CutsToPlanes(const TMTList <TGCut> &cuts, TRoofSide &side);

#endif

