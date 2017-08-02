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

	TGPoint* TruePointLeft;				//левая точка из уже принятых
	TGPoint* TruePointRight;				//правая точка из уже принятых
	TGPoint* CrossPointLeft;				//левая точка пересечения
	TGPoint* CrossPointRight;			//правая точка пересечения

	MBTi Length;							//значение веса или критерия
	MBTi Criteria;							//значение веса или критерия


	int Plane;								//текущая плоскость
	TMDelTList<int>	Planes;					//текущая плоскость
	int Slope;

	bool iAmNotBad;							//Я не плохой
	bool yesIAm;                            //Я злой!
	bool IAmTriangle;                            //Я злой!
	

/**/

	bool IAmBadLeft(TPreTriangle* Left);	//является ли хуже слева
	bool IAmBadRight(TPreTriangle* Right);	//является ли хуже справа

	void CalcScatProject(TPreTriangle *left, TPreTriangle *right);	//рассчитать критерий
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

//граница двух коллинеарных плоскостей

class TCollinearEdge{
public:
	TCollinearEdge(){};
	virtual ~TCollinearEdge(){};

	//точки из точек пересечения плоскостей лежашие на границе 
	TMTList<TGPoint> COMMON;
	TMTList<TGPoint> sepPoint;

	TIntVec rayDir[2];
};
/*
class TCollinearEdge{
public:
	TCollinearEdge(){};
	virtual ~TCollinearEdge(){};
	//задана граница как прямая  (точка и нормаль)

	//точки из точек пересечения плоскостей лежашие на границе 
	TMTList<TRoofPoint> COMMON;
};
*/

//группа коллинеарности
//объединяет несколько коллинеарных плоскостей
//задает границы их разделения
//поскольку если хотя бы одна плоскость из коллинеарных
//проходит через заданную точку то и все остальные также проходят
//поэтому такие точки разделены в смысле границ коллинеарных плоскостей
class TCollinearGroup{
public:
	TCollinearGroup(){};
	virtual ~TCollinearGroup(){};
	//список границ коллинеарности
	TMDelTList<TCollinearEdge> Edges;
	//список номеров плоскостей
	TMDelTList<int> indices;
	//вставить точку - метод интерфейса разделения точек
	void InsertPoint(TMDelTList<int> &PntPlane, TGPoint* Pnt,MBTi USEEPS);
	//являются ли две коллинеарные плоскости соседними
	bool IsNeigh(int i1,int i2);
	//инициализировать границы коллинеарных плоскостей
	//если заданы плоскости
	//точки и нормали плоскостей переданы в качестве аргументов
	void Init(TMTList<TIntVec>& Vert,TMTList<TIntVec>& Norm);
};

class  TRoof : public TGeomObject
{
	friend class TCollinearGroup;
	public:
	TMDelTList< TMDelTList< TMTList<TGPoint> > > PntCube;//КУБ точек пересечения трех плоскостей
	TMDelTList< TMDelTList<TIntVec> > DirMatrix; //Матрица направлений линий пересечения для каждых двух плоскостей
	TMDelTList< TMDelTList<TIntVec> > OrgMatrix; //Матрица точек на линиях пересечения
	TMDelTList< TMDelTList<int> > PntPlane;

	TMTList<TIntVec> p_Normal;  //нормали для входных плоскостей
	TMTList<TIntVec> p_Origin;  //точки на плоскостях

	TMDelTList< TMDelTList<int> > p_Roof;  //нормали для входных плоскостей

	TMTList<int> p_Slope;  //скаты
	TMTList<int> p_Plane;  //плоскости

	TMDelTList<TPreTriangle> PRE_TRI;

	TMDelTList< TMTList<TGCut> > POLY;

	TMDelTList< bool > Convex; //выпуклость точек контура

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

