// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
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

	TGPoint* TruePointLeft;				//ëåâàÿ òî÷êà èç óæå ïðèíÿòûõ
	TGPoint* TruePointRight;				//ïðàâàÿ òî÷êà èç óæå ïðèíÿòûõ
	TGPoint* CrossPointLeft;				//ëåâàÿ òî÷êà ïåðåñå÷åíèÿ
	TGPoint* CrossPointRight;			//ïðàâàÿ òî÷êà ïåðåñå÷åíèÿ

	MBTi Length;							//çíà÷åíèå âåñà èëè êðèòåðèÿ
	MBTi Criteria;							//çíà÷åíèå âåñà èëè êðèòåðèÿ


	int Plane;								//òåêóùàÿ ïëîñêîñòü
	TMDelTList<int>	Planes;					//òåêóùàÿ ïëîñêîñòü
	int Slope;

	bool iAmNotBad;							//ß íå ïëîõîé
	bool yesIAm;                            //ß çëîé!
	bool IAmTriangle;                            //ß çëîé!
	

/**/

	bool IAmBadLeft(TPreTriangle* Left);	//ÿâëÿåòñÿ ëè õóæå ñëåâà
	bool IAmBadRight(TPreTriangle* Right);	//ÿâëÿåòñÿ ëè õóæå ñïðàâà

	void CalcScatProject(TPreTriangle *left, TPreTriangle *right);	//ðàññ÷èòàòü êðèòåðèé
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

//ãðàíèöà äâóõ êîëëèíåàðíûõ ïëîñêîñòåé

class TCollinearEdge{
public:
	TCollinearEdge(){};
	virtual ~TCollinearEdge(){};

	//òî÷êè èç òî÷åê ïåðåñå÷åíèÿ ïëîñêîñòåé ëåæàøèå íà ãðàíèöå 
	TMTList<TGPoint> COMMON;
	TMTList<TGPoint> sepPoint;

	TIntVec rayDir[2];
};
/*
class TCollinearEdge{
public:
	TCollinearEdge(){};
	virtual ~TCollinearEdge(){};
	//çàäàíà ãðàíèöà êàê ïðÿìàÿ  (òî÷êà è íîðìàëü)

	//òî÷êè èç òî÷åê ïåðåñå÷åíèÿ ïëîñêîñòåé ëåæàøèå íà ãðàíèöå 
	TMTList<TRoofPoint> COMMON;
};
*/

//ãðóïïà êîëëèíåàðíîñòè
//îáúåäèíÿåò íåñêîëüêî êîëëèíåàðíûõ ïëîñêîñòåé
//çàäàåò ãðàíèöû èõ ðàçäåëåíèÿ
//ïîñêîëüêó åñëè õîòÿ áû îäíà ïëîñêîñòü èç êîëëèíåàðíûõ
//ïðîõîäèò ÷åðåç çàäàííóþ òî÷êó òî è âñå îñòàëüíûå òàêæå ïðîõîäÿò
//ïîýòîìó òàêèå òî÷êè ðàçäåëåíû â ñìûñëå ãðàíèö êîëëèíåàðíûõ ïëîñêîñòåé
class TCollinearGroup{
public:
	TCollinearGroup(){};
	virtual ~TCollinearGroup(){};
	//ñïèñîê ãðàíèö êîëëèíåàðíîñòè
	TMDelTList<TCollinearEdge> Edges;
	//ñïèñîê íîìåðîâ ïëîñêîñòåé
	TMDelTList<int> indices;
	//âñòàâèòü òî÷êó - ìåòîä èíòåðôåéñà ðàçäåëåíèÿ òî÷åê
	void InsertPoint(TMDelTList<int> &PntPlane, TGPoint* Pnt,MBTi USEEPS);
	//ÿâëÿþòñÿ ëè äâå êîëëèíåàðíûå ïëîñêîñòè ñîñåäíèìè
	bool IsNeigh(int i1,int i2);
	//èíèöèàëèçèðîâàòü ãðàíèöû êîëëèíåàðíûõ ïëîñêîñòåé
	//åñëè çàäàíû ïëîñêîñòè
	//òî÷êè è íîðìàëè ïëîñêîñòåé ïåðåäàíû â êà÷åñòâå àðãóìåíòîâ
	void Init(TMTList<TIntVec>& Vert,TMTList<TIntVec>& Norm);
};

class  TRoof : public TGeomObject
{
	friend class TCollinearGroup;
	public:
	TMDelTList< TMDelTList< TMTList<TGPoint> > > PntCube;//ÊÓÁ òî÷åê ïåðåñå÷åíèÿ òðåõ ïëîñêîñòåé
	TMDelTList< TMDelTList<TIntVec> > DirMatrix; //Ìàòðèöà íàïðàâëåíèé ëèíèé ïåðåñå÷åíèÿ äëÿ êàæäûõ äâóõ ïëîñêîñòåé
	TMDelTList< TMDelTList<TIntVec> > OrgMatrix; //Ìàòðèöà òî÷åê íà ëèíèÿõ ïåðåñå÷åíèÿ
	TMDelTList< TMDelTList<int> > PntPlane;

	TMTList<TIntVec> p_Normal;  //íîðìàëè äëÿ âõîäíûõ ïëîñêîñòåé
	TMTList<TIntVec> p_Origin;  //òî÷êè íà ïëîñêîñòÿõ

	TMDelTList< TMDelTList<int> > p_Roof;  //íîðìàëè äëÿ âõîäíûõ ïëîñêîñòåé

	TMTList<int> p_Slope;  //ñêàòû
	TMTList<int> p_Plane;  //ïëîñêîñòè

	TMDelTList<TPreTriangle> PRE_TRI;

	TMDelTList< TMTList<TGCut> > POLY;

	TMDelTList< bool > Convex; //âûïóêëîñòü òî÷åê êîíòóðà

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

