//---------------------------------------------------------------------------

#ifndef GeomObjVH
#define GeomObjVH
#include "VisPrimitiveObj.hpp"
#include "TGUnitV.h"
#include "LinearList.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//Drive
extern long int TickCount1;
extern long int TickCount2;
extern long int TickCount3;
extern long int TickCount4;
extern long int TickCount5;
extern long int TickCount6;
extern long int TickCount7;
extern long int TickCount8;

class TGPolygon;
class TGCut;
typedef bool (__closure *TConditionForPass)(TGCut *cut, TGPolygon *p1, TGPolygon *p2);

enum TRenderType
{
    rtCLASSIFY,
	rtMARK,
	rtSMOOTH,
	rtCOLOR,
    rtERROR//not used!!!
};
//Drive
/*
const MBTi PEPS				= 0.0005;						// ������� �������� �����
const MBTi VALID_RADIUS		= 5;
const MBTi CEPS				= PEPS / 2*VALID_RADIUS;		// ������� ��������������
*/

//const MBTi VALID_RADIUS		= 5.0f;

//#define GET_CEPS(EPS)		EPS/(2.0*VALID_RADIUS)

//const MBTi CEPS				= GET_CEPS(PEPS);		// ������� ��������������


//#define CEPS_N 0.00001

enum TTag
{
	tgOTHER	  	= 0,
	tgTHIS		= 3,

	tgPOSITIVE	= 1,
	tgNEGATIVE	= -1,
	tgINTERSECT	= 2,

	tgTRUE		= 1,
	tgFALSE		= 0,
};

enum TConstructFlags
{
	coPOINTS		= 0x0001,
	coCUTS			= 0x0002,
	coPOLYGONS		= 0x0004,
	coNORMALS		= 0x0008,
	coPOLYGONHOLES  = 0x0010,

	coWIRE			= 0x0001 | 0x0002,
	coSOLID			= 0x0004,
	coALL			= 0xFFFF
};


enum TGeomResult {
	grOK	=	0x0001,
	grERROR =	0x0000,
};

enum TGeomFixFlags
{
	gfxPOINTSINCUTS		=	0x0001,
	gfxCUTSCROSS		=	0x0002,
	gfxCLOSEPOINTS		=	0x0004,
	gfxALL				=	0xFFFF
};

enum TStructFixFlags
{
	sfxREMOVE_BRANCHES					= 0x0001,
	sfxREMOVE_REPEATED					= 0x0002,
	sfxREMOVE_BRIDGES_BY_CONTOURIZE     = 0x0004,
	sfxREMOVE_BRIDGES_BY_POLYGONIZE     = 0x0008,
};

enum TFreeUnusedType  {
	fuPoints = 0x0001 ,
	fuCuts = 0x0002,
	fuAll = 0x0003
};

enum TClassifyFlags
{
	flORIGIN		= 0x0001,
	flHOLE			= 0x0002,
	flINTERSECT		= 0x0004,
	flCONTOUR		= 0x0008,
	flMARK			= 0x0010,
	flALREDY		= 0x0020,
	flBELONG		= 0x0040,
	flSAME			= 0x0080,
	flERROR			= 0x0100,
	flCACHED		= 0x0200,
	flNEEDCALC		= 0x0400,
	flBOUNDARY		= 0x0800,
	flALL			= 0xFFFF,
};

enum TGBoolean
{
	gbA_MINUS_B		= 0x01,
	gbB_MINUS_A		= 0x02,

	gbA_AND_B		= 0x03,
	gbINTERSECTION	= 0x03,

	gbA_XOR_B		= 0x04,
	gbUNION			= 0x04,

	gbSPLIT			= 0x05
};

enum TClassify
{
	gfFALSE			= 0x00,
	gfTRUE			= 0x01,

	gfUNDEFINED		= 0x00,

	gfNEGATIVE		= 0x01,
	gfPOSITIVE 		= 0x02,
	gfINTERSECT 	= 0x03,
	gfCOLLINEAR 	= 0x04,

	gfOTHER		 	= 0x00,
	gfTHIS		 	= 0x01,

};

template <class t1, class t2>
struct TMTwinElement
{
	t1 Data;
	t2 Target;
};

struct TGeomFlags
{
	// ����� ������ �������
	unsigned Origin:3;
	unsigned Cached:1;
	unsigned Intersect:1;
	unsigned Solid:1;
	unsigned Alredy:1;

	// ���������� �����
	unsigned Mark:1;
	unsigned Hole:1;
	unsigned Belong:1;
	unsigned Contour:1;
	unsigned Same:1;
	unsigned Error:1;
	unsigned NeedCalc:1;
	unsigned Boundary:1;

	unsigned reserved:19;
};

template <class TreeType>
class TMTreeNode
{
	TMTreeNode *FParent;
public:
	TMTList <TMTreeNode<TreeType> > Children;

	TreeType *Node;

	TMTreeNode()
	{
		FParent = NULL;
		Node = NULL;
	}
	void SetParent(TMTreeNode *parent)
	{
		if (FParent)
			FParent->Children.Remove(this);
		FParent = parent;	
		if (!FParent)
			return;
		FParent->Children.Add(this);
	};
	TMTreeNode *GetParent()
	{
		return FParent;
	}

	__property TMTreeNode *Parent = {read = GetParent, write = SetParent};
};

template <class TreeType>
class TMTree
{
public:
	TMDelTList< TMTreeNode<TreeType> > Nodes;

	TMTreeNode<TreeType> *AddNode(TreeType *node, TMTreeNode<TreeType> *parent)
	{
		Nodes.Add(new TMTreeNode<TreeType>);
		Nodes.Last()->Parent = parent;
		Nodes.Last()->Node = node;
		return Nodes.Last();
	}

};	

class TGCut;
//////////////////
//	TGPoint		//
//////////////////

class TCachedPoint;
class COMMONAL_API TGPoint : public TGUnit
{
	friend class TGCut;
	friend class TCachedPoint;
	friend class TGeomObject;
	friend class TGPolygon;
	friend class TGTriangulate;
private:	
	TGeomFlags FFlags;
protected:
	TMTList<TGCut> FCuts;
public:

	TGPoint();
	TGPoint(const TIntVec &);

	// ������� �����
	 const TGCut &GetCut(int index) const;
	 TGCut &GetCut(int index);													
	__property TGCut& Cuts[int] = {read = GetCut};

	// ����������� �������� �����
	int GetCutsCount() const;															
	__property int CutsCount = {read = GetCutsCount};

	// ����������� ����� �� ����������� �������� �����
	bool GetClosed() const;															
	__property bool Closed = {read = GetClosed};

	// ����� �����
	__property TGeomFlags Flags = {read = FFlags, write = FFlags};

	// ��� ������������
	int Tag;

	// ���������� �����
	TChangeVec Point;

	TGCut *GetTurnRightCut(bool MarkedOnly = false) const;				// �������, ����� �������������� ������� ������������ OY
	TGCut *GetTurnLeftCut(bool MarkedOnly = false) const;				// �������, ����� �������������� ������ ������������ OY

	TGCut *GetTurnRightCut(TGCut *cut,bool MarkedOnly = false) const;	// �������, ����� �������������� ������� ������������ �������� �������
	TGCut *GetTurnLeftCut(TGCut *cut,bool MarkedOnly = false) const;	// �������, ����� �������������� ������ ������������ �������� �������

//--------------------------------------------------------
	void Changed(void* Field);
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	void Assign(TMyObject* MO);
//--------------------------------------------------------
	virtual ~TGPoint();
};

class TCachedPoint
{
public:	
	TGPoint *Target;
	TIntVec Data;
	TCachedPoint()
	{
		Target = NULL;
	};
	void Cache(TGPoint *t)
	{
		Target = t;
		Data = t->Point;
		Target->FFlags.Cached = gfTRUE;
	}

	void Restore()
	{
		if (Target)
			Target->Point = Data;
		Target->FFlags.Cached = gfFALSE;
	}
		
	TCachedPoint(TGPoint *t)
	{
		if (t)
			Cache(t);
	}
};
class TGPolygon;
class TGeomObject;


extern COMMONAL_API TClassNode* TGPoint::StaticType;

//////////////////
//	TGCut		//
//////////////////

class COMMONAL_API TGCut : public TGUnit
{
	friend class TGPolygon;
	friend class TGPoint;
	friend class TGeomObject;
	friend class TGTriangulate;
private:
	union
	{
		TGPoint* FPoint[2];
		struct
		{
			TGPoint* FSrc;
			TGPoint* FDst;
		};		
	};

	TMTList <TGPolygon>  FPlane;

	__property TGPolygon* FLeft = {read = GetPlane, write = SetPlane, index = 0};
	__property TGPolygon* FRight = {read = GetPlane, write = SetPlane, index = 1};

	void SetPlane(int index, TGPolygon* aPlane);
	const TGPolygon *GetPlane(int index) const;

	void AddPlane(TGPolygon *plane);	
	int RemovePlane(TGPolygon *plane);	
	TGeomFlags FFlags;

protected:
	void SetPoint(int index, TGPoint* Value);
public:
//Drive
    TIntVec BBoxCenter;
    TIntVec BBoxLengthDiv2;
//Drive
	TGCut();

	bool Smooth;	// ������������ �����
	int Tag;		// ��� ������������

	bool GetClosed() const;						   	// ����������� � ����� ������ ����������� ���������
	__property bool Closed = {read = GetClosed};
	__property TGeomFlags Flags = {read = FFlags, write = FFlags}; 	// ����� �������

	__property TGPoint* Src = {read = FPoint[0],write = SetPoint,index = 0};	// ������
	__property TGPoint* Dst = {read = FPoint[1],write = SetPoint,index = 1};	// �����

	__property TGPolygon* Left = {read = GetPlane,  index = 0};
	__property TGPolygon* Right = {read = GetPlane,  index = 1};
	
/*************************************** ��������������� ������� ******************************************************/

	bool IsOneFreeSide() const;						// ��������� ������� � ����� ������ ����������� ���������
	bool Equal(const TGCut& other) const;			// ������������� ��������
	
	bool ConsistsDstAndSrc(const TGPoint* R1, const TGPoint* R2) const;	// ���������� ����� �����
	bool ConsistsPoint(const TGPoint* Point) const;						// ���������� �����
	bool SameDirection(const TGCut &cut) const;							// SameDIrection �������� ��� �������, ��� CanConnect() != NULL
	bool Used() const;

	TGPoint *CanConnect(const TGCut &cut) const;			// ����������� ���������� ��������
	TGPoint *GetAnotherPoint(const TGCut &c) const;			// ����� ����� �������, �� ��������� � ������ ��������.
	TGPoint *GetAnotherPoint(const TGPoint* Point) const;	// ����� ������ ����� �������
	
/************************** ��������� ******************************************************/
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	void Assign(TMyObject* MO);
/*******************************************************************************************/
	virtual ~TGCut();
};
extern COMMONAL_API TClassNode* TGCut::StaticType;

//////////////////
//	TGPolygon	//
//////////////////

class COMMONAL_API TGPolygon : public TGUnit{

friend class TGeomObject;
friend class TGPoint;
friend class TGTriangulate;

protected:
	TMTList<TGCut> FCuts;
	bool FClosed;				//���������

	TGeomFlags FFlags;


	TIntVec FNormal;
	TGPolygon *FParent;

	void SyncronizeWith(TGCut &Cut);
	void SetNormal(const TIntVec &n);
public:
//Drive
	int IndexForSmoothGroups;
	TIntVec BBoxCenter;
	TIntVec BBoxLengthDiv2;
//Drive
	TGPolygon();
	TGPolygon(TMTList <TGCut> &cuts);

	int Tag;								// ���������������� ���
	TMDelTList < TGPolygon > FHoles;		// ����� ��������

	int GetCount() const;						// ����������� ���������
	__property int Count = {read = GetCount};	// ����������� ���������

	const TGPoint &GetPoint(int index) const;				// �������
	TGPoint &GetPoint(int index);			 				// �������
	__property TGPoint &Points[int] = {read = GetPoint};	// �������

	bool FindBasisPoints(TMTList<TGPoint> &points);
	
	const TGCut &GetCut(int index) const;					// �������
	TGCut &GetCut(int index);								// �������
	__property TGCut &Cuts[int] = {read = GetCut};			// �������

	bool IsHoled() const;							   		// ���������� �����
	TIntVec GetOrigin() const;
	TIntVec GetNormal();
	TIntVec GetMidOrigin() const;

	
	__property bool Closed = {read = FClosed};		   		// ����������� ��������
	__property bool Holed = {read = IsHoled};		   		//
	__property TGeomFlags Flags = {read = FFlags, write = FFlags};	   		// �����
	
	__property TIntVec Normal = {read = GetNormal};			// �������
	__property TIntVec Origin = {read = GetOrigin};			// ����� �� ���������
	__property TIntVec MidOrigin = {read = GetMidOrigin};	// ����� �� ���������
	
/********************************* ���������� �������� **********************************************/

	int AddCut(TGCut *);					// ���������� �������
	void RemoveCut(TGCut *cut);				// �������� �������
	void DeleteCut(int index);				// �������� �������

	TGPolygon *AddHole(TMTList<TGCut>& );				// ���������� �����

	void ClearCuts();									// ������� ��������

	void PlaceOnPlane (MBTi &AngX, MBTi &AngY,const TIntVec &org = TIntVec(0,0,0));						//�������� �� ���������
	void BackFromPlane(const MBTi &AngX, const MBTi &AngY, const TIntVec &org = TIntVec(0,0,0));		// ������� � ���������

	bool CalculatePlane();								// ���������� ��������� (Normal, Origin)

/********************************* ��������������� ������� **********************************************/

	bool Equal(const TGPolygon& other) const;							// ������������� ���������
	bool ConsistsCut(TGCut *cut);									   	// ���������� �������
	int IndexOf(TGPoint *pnt);											// ������ �����
	void Invert(bool JstInvert = false);                                // �������������� ����������� ������

	int PointInPolygon2d(const TIntVec& Point, MBTi USEEPS);			// ��������� ����� � �������
	int PointInPolygon_UseHoles2d(const TIntVec &Point, MBTi USEEPS);	// ��������� ����� � ������� � �������

	int PolygonInPolygon2d(const TGPolygon &p, MBTi USEEPS);			// ��������� �������� � �������
	int PolygonInPolygon_UseHoles2d(const TGPolygon &p, MBTi USEEPS);	// ��������� �������� � ������� � �������


	TClassify ClassifyByPlane(const TIntVec &n, const TIntVec &o, MBTi EPS);	// �������������
	bool DetectSelfHoles();//?????????????

	TGPoint *GetLowestPoint2d();
	TGPoint *GetHighestPoint2d();
	
/*********************************** ��������� ***********************************************************/
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	void Assign(TMyObject* MO);

	virtual ~TGPolygon();
};

extern COMMONAL_API TClassNode* TGPolygon::StaticType;
/*TGPolygon*/

///////////////////////
// class TGeomObject //
///////////////////////

class TGIntCut;
class TGIntPoint;

class COMMONAL_API TGeomObject : public TMyObject {
friend class TGTriangulate;//�������� ��� 

protected:

	TMDelTList< TMDelTList<TCachedPoint> > PointsCache;
	TMDelTList<TGPoint> FVertex;
	TMDelTList<TGCut> FCuts;

/*	void FillCutsFlags(TClassifyFlags Flag, TClassify State);
	void FillCutsFlags(TMTList <TGCut> &cuts, TClassifyFlags Flag, TClassify State);

	void FillPolygonsFlags(TClassifyFlags Flag, TClassify State);
	void FillPolygonsFlags(TMTList <TGPolygon> &poly, TClassifyFlags Flag, TClassify State);

	void FillPointsFlags(TClassifyFlags Flag, TClassify State);
	void FillPointsFlags(TMTList <TGPoint> &points, TClassifyFlags Flag, TClassify State);
*/
	bool ClassifySolidRecursive(TGPolygon *p);

	void CachePoints();
	void RestorePoints();

	TGCut *DeletePointBetweenCollinear(TGPoint *pnt);

	void SynchronizePolygonsWisesRecursive(TGPolygon *p);

	void ClassifyPolygonsByIntersectBorder();
	void ClassifyPolygonsByIntersectBorderRecursive(TGCut *cut);
	void FillPolygonsOriginInBorders(TGPolygon *p, TClassify state);
	void FillPolygonsOriginInIntersectionRecursive(TGPolygon *p, TClassify state);
	
public:
	MBTi PEPS;						// ������� �������� �����
	bool SnapPoints;
	bool SnapPointsToNearest;

	void FillCutsFlags(TClassifyFlags Flag, TClassify State);
	void FillCutsFlags(TMTList <TGCut> &cuts, TClassifyFlags Flag, TClassify State);

	void FillPolygonsFlags(TClassifyFlags Flag, TClassify State);
	void FillPolygonsFlags(TMTList <TGPolygon> &poly, TClassifyFlags Flag, TClassify State);

	void FillPointsFlags(TClassifyFlags Flag, TClassify State);
	void FillPointsFlags(TMTList <TGPoint> &points, TClassifyFlags Flag, TClassify State);

	bool GeometryFix(TMTList<TGCut> &cuts, TGeomFixFlags flags);
	void GeometryFix(TGeomFixFlags flags);

	bool StructureFix(TMTList<TGCut> &cuts, TStructFixFlags flags);
	bool StructureFix(TStructFixFlags flags);
	bool StructureFix(TGPolygon *, TStructFixFlags flags);

	TMDelTList<TGPolygon> FPolygons;		//!!!!!!!!!!!!!!!!!!!!!!!

	TGeomObject();

	void SynchronizePolygonsWises(TGPolygon *p = NULL);

	void ClassifySolid();													// ����������� ��������� ��������
	void ClassifyPolygons(const TIntVec &n, const TIntVec &o, MBTi EPS);	// ������������� ��������� ����������
	

	// ����������� �������
	bool GetClosed() const;												// ����������� ��������� �������
	__property bool Closed = {read = GetClosed};						// 

	bool GetSolid() const;												// ������ - ������� ����
	__property bool Solid = {read = GetSolid};							//

	// ��������� �������������� ������������ �������
	int GetPolygonsCount() const;										// ����������� ���������
	__property int PolygonsCount = {read = GetPolygonsCount};			// 

	int GetCutsCount() const;										   	// ����������� ��������
	__property int CutsCount = {read = GetCutsCount};					//

	int GetVertexCount() const;											// ����������� �����
	__property int VertexCount = {read = GetVertexCount};				//

	////////////////////////////////////////////////////
	TGPoint &GetVertex(int index) const;								// �������
	TGPoint &GetVertex(int index);										// �������
	__property TGPoint &Vertex[int] = {read = GetVertex};

	TGCut &GetCut(int index) const;									   	// �������
	TGCut &GetCut(int index);										   	// �������
	__property TGCut &Cuts[int] = {read = GetCut};

	TGPolygon &GetPolygon(int index) const;								// ��������
	TGPolygon &GetPolygon(int index);									// ��������
	__property TGPolygon &Polygons[int] = {read = GetPolygon};

	////////////////////////////////////////////////////
	int IndexOf(TGPoint *point) const;									// ������ �����
	int IndexOf(TGCut *cut) const;										// ������ �������
	int IndexOf(TGPolygon *polygon) const;								// ������ ��������
	////////////////////////////////////////////////////
	// ���������� �������

	virtual void DeletePoint(int index);
	virtual void DeleteCut(int index);
	virtual void DeletePolygon(int index);

	virtual void Delete(TGPoint *target);
	virtual void Delete(TGCut *target);
	virtual void Delete(TGPolygon *target);

	TGPoint *AddPoint(const TIntVec &v); 				// ���������� �����
	TGPoint *AddPoint(const TGPoint &p);				// ���������� �����

	TGCut *AddCut(const TGCut &c);										// ���������� �������
	TGCut *AddCut(int, int);											// ���������� �������
	TGCut *AddCut(TGPoint *, TGPoint *);                                // ���������� �������
	TGCut *AddCut(TIntVec v1, TIntVec v2);								// ���������� �������

	TGPolygon *AddPolygon(TMTList<TGCut>&, const TIntVec &nrm = TIntVec(0,0,0));			// ���������� ��������
	TGPolygon *AddPolygon(const TMTList<int>& indices, const TIntVec &nrm = TIntVec(0,0,0));// ���������� �������� 
	TGPolygon *CopyPolygonToObject(const TGPolygon &poly);										// ����������� �������� 

	void ClosePolygon(int);					 			// ������� ��������� ��������
	void ClosePolygon(TGPolygon *);                     // ������� ��������� ��������

	// Extrudes
	TGCut *ExtrudeCut(TGCut *c, const TIntVec& d, bool inv = false);  	// ������������ �������
	TGCut *ExtrudeCut(int index, const TIntVec& d, bool inv = false); 	// ������������ �������

	void ExtrudePolygon(TGPolygon *p, const TIntVec& d);			  	// ������������ ��������
	void ExtrudePolygon(int index, const TIntVec& d);				  	// ������������ ��������

	TGPoint *ExtrudePoint(TGPoint *p, const TIntVec& d);			  	// ������������ �����
	TGPoint *ExtrudePoint(int index, const TIntVec& d);				  	// ������������ �����

	void Extrude(const TIntVec& d);										// ����� ������� ������������

	// ����������
	TGPoint *SliceCutByPlane2d(int index, TGCut *&rc1, TGCut *&rc2);	// ���������� ������� ���� OX
	TGPoint *SliceCutByPlane2d(TGCut *cut, TGCut *&rc1, TGCut *&rc2);	// ���������� ������� ���� OX

	void SplitPolygonByPlane(TGPolygon *p, const TIntVec& n, const TIntVec& o, TMTList<TGPolygon> &Result);	// ���������� �������� ����������
	void SplitPolygonByPlane(int index, const TIntVec& n, const TIntVec& o, TMTList<TGPolygon> &Result);	

	void SliceByPlane(const TIntVec &n, const TIntVec &o);						// ��������� ������� ����������
	void SplitByPlane(const TIntVec &n, const TIntVec &o);						// ���������� ������� ����������
	void SliceByPlaneNoSplit(const TIntVec &n, const TIntVec &o);

	void TransformToPlane(const TIntVec& n, MBTi &AngX, MBTi &AngY);			// ������������� ������ � ���������
	void TransformBack(const MBTi &AngX, const MBTi &AngY);						// ������� ������ �������

	void TransformToPolygon(TGPolygon *p, const TIntVec& n, const TIntVec& o, MBTi &AngX, MBTi &AngY, MBTi &AngZ);	// ������������� ������ � ��������
	void TransformBack(const TIntVec& n, const TIntVec& o, const MBTi &AngX, const MBTi &AngY, const MBTi &AngZ);	// ������� �������

	void TransformToPlane(const TIntVec& n, TMTList<TMyObject> &what, MBTi &AngX, MBTi &AngY, const TIntVec &org = TIntVec(0,0,0));
	void TransformBack(TMTList<TMyObject> &what, const MBTi &AngX, const MBTi &AngY, const TIntVec &org = TIntVec(0,0,0));

	void TransformToPlaneAndOX(TMTList<TMyObject> &what, const TIntVec& Normal, const TIntVec& n, MBTi &AngX, MBTi &AngY, MBTi &AngZ, bool chkMark);
	void TransformBack(TMTList<TMyObject> &what, const TIntVec& n, const MBTi &AngX, const MBTi &AngY, const MBTi &AngZ, bool chkMark);

	void TransformMove(TMTList<TMyObject> &what, TIntVec &org, bool chkMark);
	

	void TransformRotate(const TIntVec &angle, const TIntVec &Center);
	void TransformScale(const TIntVec &scale);
	void TransformTranslate(const TIntVec &dir);


	// ����

	void FillCutsTag(const int ID);												// ��������� ���� ��������
	void FillPointsTag(const int ID);											// ��������� ���� ���������

	//����� �������

	void FreeUnused(TFreeUnusedType fur);										// �������� ������������� �����
	virtual void Clear();														// �������� �������������� ������

	// ��������������� �������
	
	bool Polygonize2d(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly);			// ����� �������������
	bool Contourize2d(const TMTList<TGCut> &Cuts, TMTList<TGCut> &contour, TGPoint *begin = NULL);// ����� ������������


	void Triangulate();
	void DetectHolesAtAll(MBTi _PEPS, MBTi _CEPS);
	void CrossCutsAtAll(MBTi _PEPS, MBTi _CEPS);
	void WeldPointsAtAll(MBTi EPS);

	void Optimize(MBTi PEPS, MBTi CEPS, bool det, bool cross);
	void CollapsePoints(TMTList <TGPoint> pnt);

	void ProcessCrossCuts2d(TMTList<TGCut>& Cuts);
	void ProcessCrossCuts2d();
	
	//��������������
	TGCut *ExistsCut(const TGCut &);											// ���������� �������
	TGPoint* ExistsPoint(const TIntVec& v);
	TGPolygon *ExistsPolygon(const TGPolygon &);								// ���������� ��������

	TGCut* GetCutByPoints(TGPoint* P1,TGPoint* P2);								// ����� ������� �� ���� ������

	void CutsToIndices(TMDelTList<int>& indices) const;							// ������� � �������
	void IndicesToCuts(TMDelTList<int>& indices);								// ������� � �������

	void PolygonToIndices(TGPolygon* GP,TMDelTList<int>& indices) const; 		// ������� � �������
	void IndicesToPolygon(TGPolygon* GP,TMDelTList<int>& indices); 				// ������� � �������

	TGPoint *GetLowestPoint2d(const TMTList<TGCut> &cuts);						// ����� ����� ������ ����� �� ��������


	TGPoint *CutOX_Cross2D(TGCut &cut, MBTi EPS);
	// ���������

	bool SplitCut(TGCut *c, TGPoint *Pnt);										// ��������� ������� ������.
	bool SplitCut(TGCut *c, TGPoint *newPnt, TGCut *&Result1, TGCut *&Result2);
	
	bool SplitPolygon(TGPolygon *p, TMTList<TGCut> &Cut, TMTList<TGPolygon> &result);	// ��������� �������� ���������

	void DetectHoles2d(TMTList<TGPolygon> &poly);
	void DetectHolesCreatePolygons2d(TMTList<TGPolygon> &poly);
	void TransfixPolygon2d(TGPolygon *p, TMTList<TGPoint> &cps);

//	bool IntersectPolygons(TGPolygon *p1, TGPolygon *p2, TMTList <TGCut> &r1, TMTList <TGCut> &r2/*, TGeomObject &intersect*/);
	bool IntersectPolygons(TGPolygon *p1, TGPolygon *p2, TMDelTList <TGIntCut> &r1, TMDelTList <TGIntCut> &r2, TMDelTList <TGIntPoint> &);
	bool PlanePolygonIntersect(TGPolygon *plane, TGPolygon *p, TMDelTList <TGIntPoint> &cps);

	TGCut *CopyCutToObject(const TGCut &cut);

	void CopyCutsToObject(const TGeomObject &obj);
	void CopyPolygonsToObject(const TGeomObject &obj);

	void Append(TGeomObject &obj);
/**/

	void SolidObjectsBoolean(TGBoolean operation, TGeomObject &obj, TGeomObject &result);

	void CalculateNormals();

	bool SolidCheck();
	void SolidFix();

	void ToPrimitiveObj(TVisPrimitiveObj *VCO, TConstructFlags flags = coSOLID);
	void ToPrimitiveObj2(TVisPrimitiveObj *VCO);
	void FromPrimitiveObj(TVisPrimitiveObj *VCO);
	
	void SavePolygonAsFigure(int ind, const AnsiString &name);
	void SaveCutsAsFigure(const TMTList <TGCut> &cuts, const  AnsiString &name);
	void SaveObjectAsFigure(int ind, const TMemoryStream *f);

	void SavePolygon(TGPolygon *poly, FILE *F) const;
	void LoadPolygon(TGPolygon *poly, FILE *F);
	void WritePolygon(TGPolygon *poly, TMemoryStream *MS) const;
	void ReadPolygon(TGPolygon *poly, TMemoryStream *MS);
/**/

// Drive: AnalyticalRender
    void PolygonTriangulate(TGPolygon* p, TMTList<TGPolygon>& poly);//����������� � ���������
    void evlProcessCrossCuts2D(TMTList<TGCut>& Cuts);
    TGPoint& drGetPoint(int index, TMTList<TGCut>& cuts);
    TIntVec PointInPolygon(TGPolygon* p);
    TIntVec GetPointInPolygon2d(TGPolygon* p);
    TIntVec GetPointInPolygon2d(TMTList<TGCut>& cuts);
    TIntVec GetPointInPolygonUseHoles(TGPolygon* p);
    TIntVec GetPointInPolygonUseHoles2d(TGPolygon* p);
    int  drPointInPolygon_UseHoles2d( TGPolygon* p, const TIntVec &Point, MBTi USEEPS, TGPolygon*& Hole);
    void ConstructPolygonsFromHoles( TGPolygon& p, TMTList<TGPolygon>& poly);
    bool ConditionForTag(TGCut *cut, TGPolygon *p1, TGPolygon *p2);
    bool ConditionForTagAndHole(TGCut *cut, TGPolygon *p1, TGPolygon *p2);
    bool ConditionForSmooth(TGCut *cut, TGPolygon *p1, TGPolygon *p2);
    void PassByObject(TGPolygon *p, TConditionForPass& ConditionForPass);
    void GetBBox2D(TGPolygon *p, TMDelTList<TIntVec>& BBox);
    void GetBBox(TGPolygon *p);
    void GetBBox(TGCut *cut);
    void CalculateBBoxes();
	bool CompareBBox2D(TGPolygon *p1, TGPolygon *p2);
	bool CompareBBox2D(TGCut *p1, TGCut *p2);
	int  FindCeilForPolygon(TGPolygon *p, TMDelTList< TMTList<TGPolygon> >& Ceils);
    void ProjectToXY(TGeomObject &obj, TStatusBar* SB);
    bool IntersectPolygons2DPoly2( TGPolygon* p1, TGPolygon* p2, TMDelTList< TMTList<TGCut> > &Onlyp1, TMDelTList< TMTList<TGCut> > &Split, TMDelTList< TMTList<TGCut> > &Onlyp2);
    bool IntersectPolygonsUseHoles( TGPolygon* p1, TGPolygon* p2, TMTList<TGPolygon> &POnlyp1, TMTList<TGPolygon> &PSplit, TMTList<TGPolygon> &POnlyp2);
    bool SplitCutForCrossedCuts(TMTList<TGCut>& aCuts, TGCut *&c, TGPoint *&Pnt, TMTList<TGCut>& CutsConveyor);
    void AnalyticalRenderConveyor(TGeomObject& obj, TStatusBar* SB);

    void GetCeilsGroup(TGPolygon& p, TMTList<TGPolygon>& Poly);
    void GetSmoothGroupForAnRen(TGPolygon& p, TMTList<TGPolygon>& Poly);
    void AddPolygonToCeils(TGPolygon* p, TGeomObject& obj, TMTList<TGPolygon>& Conveyor, TMTList<TGPolygon>& Ceils);
    void AddPolygonToCeilsUseHoles(TGPolygon* p, TGeomObject& obj, TMTList<TGPolygon>& Conveyor, TMTList<TGPolygon>& Ceils);
    bool ExistsPolygonInPolygon(TMTList<TGCut>& cuts, const TGPolygon& Polygon);
    bool ExistsPolygonInPolygonUseHoles(TMTList<TGCut>& cuts, TGPolygon& PolygonUseHole, bool DifferentHoles);
    bool ExistsPolygonInPolygonUseHoles2(TMTList<TGCut>& cuts, TGPolygon& PolygonUseHole, bool UseHoles);
	void DeleteBackFace();
    bool drPolygonize(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly);
    void DeleteBranches(TMTList<TGCut> &cuts);
    void drProcessCrossCuts2d(TStatusBar* SB);
	bool drProcessCrossCuts2d(TMTList<TGCut>& aCuts, TStatusBar* SB);
	bool drConsistsPoint(const TGPoint& Point, const TGCut& Cut) const;					// ���������� �����
	bool drSplitCut(TGCut *c, TGPoint *&newPnt, TGCut *&Result1, TGCut *&Result2);


	void Triangulate2();
    void ShiftVecCompToXY(TIntVec& Vec, int CompNum);
    void ShiftVecCompFromXY(TIntVec& Vec, int CompNum, MBTi VecComp);
	void Triangulate3(TGeomObject& obj);
    void ConstructVCO(TVisPrimitiveObj* VCO, TConstructFlags co, TRenderType render, TGeomObject& obj);
	void GetSmoothGroup(TGPoint* Pnt, int CutIndex, TMTList<TGPolygon>& Poly);
	void GetSmoothGroup2(TGPoint* Pnt, int CutIndex, int CurGroupInd, TMTList<TGPolygon>& Poly, TLList< TLList<int> >& FastPointDetect);
/*    void Find2BasePoints(TGPoint *pnt1, TGPoint *pnt2);
    bool FindDeloneBrother(TGPoint* pnt1, TGPoint* pnt2);
    bool SimpleIntersection(TGPoint& aSrc, TGPoint& aDst, TGPoint& bSrc, TGPoint& bDst);
    bool CheckSimpleCrossing(TGPoint& a, TGPoint& b, TGPoint& c);
    bool CheckBldCrossing(TGPoint& a, TGPoint& b, TGPoint& c);
    void TriangulateByPoints();
    TMTList<TGPoint>* Triangulate(TGPolygon *p);*/
	void ScaleTo(MBTi maxSize);
	TGCut *ExistsCutFast( TGPoint& p1, TGPoint& p2 );
	TGCut *AddCutFast(TGPoint *p1, TGPoint *p2);
	TGCut *AddCutFast(TIntVec p1, TIntVec p2);
	TGCut *AddCutFast(const TGCut &c);
    TGPolygon *AddPolygonForTriangulate(TMTList<TGCut> &cuts, const TIntVec &nrm);
	void ToPrimitiveObj2(TVisPrimitiveObj *VCO, TConstructFlags co, TRenderType render);
	void SaveTwoPolygonAsFigure(int ind1, int ind2, AnsiString &name);
// Drive: AnalyticalRender

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	static TClassNode* StaticType;
	void Assign(TMyObject* MO);
	TMyObject* CreateFunction();
	void SaveData(FILE *F) const;
	void LoadData(FILE *F);
	void WriteData(TMemoryStream *MS) const;
	void ReadData(TMemoryStream *MS);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	virtual ~TGeomObject(){};
	/*system*/
	TCreateFunction CreateCutFunction;
	TCreateFunction CreatePointFunction;
	TCreateFunction CreatePolygonFunction;
};
extern COMMONAL_API TClassNode* TGeomObject::StaticType;

class COMMONAL_API TGTriangulate {
private:
public:
	MBTi EPS;
	TGeomObject& GObj;
//    TGTriangulate(){EPS = 0.0001;};
	TGTriangulate(TGeomObject& _GObj):GObj(_GObj){EPS = 0.0000001;};
	virtual ~TGTriangulate(){};
	TMTList<TGCut> CutsBuild;
	TMTList<TGPoint> FVertex;
	TMTList<TGCut> FCuts;

	TMTList<TGCut> Triangles;

	TGCut* ExistsCutIn_CutsBuild( TGPoint* p1,  TGPoint* p2 );
	TGCut* ExistsCutIn_FCuts( TGPoint* p1,  TGPoint* p2 );
	TGCut* ExistsCutIn_GObjFCuts( TGCut* cut );
	TGCut* AddCut(TGPoint* p1, TGPoint* p2);
	TGCut* NewCut(TGPoint* p1, TGPoint* p2);

	void MergePolygon(TGPolygon* P);
	int classify(TIntVec& p2,TIntVec &p0, TIntVec &p1);
	void Find2BasePoints(TGPoint*& pnt1, TGPoint*& pnt2);
	bool FindDeloneBrother(TGPoint* pnt1, TGPoint* pnt2);
	bool SimpleIntersection(TIntVec& aSrc, TIntVec& aDst, TIntVec& bSrc, TIntVec& bDst);
/*	bool SimpleIntersection2(TIntVec& aSrc, TIntVec& aDst, TGCut& b);
	bool SimpleIntersection3(TGCut& a, TGCut& b);*/
	bool CheckSimpleCrossing(TGPoint& a, TGPoint& b, TGPoint& c);
	bool CheckBldCrossing(TGPoint& a, TGPoint& b, TGPoint& c);
	void TriangulateByPoints();
	TMTList<TGCut>* Triangulate(TGPolygon *p);
};

COMMONAL_API void PrimitiveSquare(TGeomObject *obj, MBTi sx, MBTi sy);
COMMONAL_API void PrimitiveCircle(TGeomObject *obj, MBTi Rad, int partCount);
COMMONAL_API void PrimitiveRing(TGeomObject *obj, MBTi Rad1, MBTi Rad2, int partCount);
COMMONAL_API void PrimitiveHoledRing(TGeomObject *obj, MBTi Rad1, MBTi Rad2, int partCount);
COMMONAL_API void PrimitiveXRing(TGeomObject *obj, MBTi Rad1, MBTi Rad2, int partCount);
COMMONAL_API void PrimitivePyramid(TGeomObject *obj, MBTi sx, MBTi sy, MBTi sz);
COMMONAL_API void PrimitivePlane(TGeomObject *obj, MBTi sx, MBTi sy, const TIntVec &n, const TIntVec &o, TConstructFlags co);
COMMONAL_API void PrimitiveLineUnit(TGeomObject *obj, MBTi sx, MBTi sy, const TIntVec &a, const TIntVec &b);

class THoledPolygon;

void GPolygonToHPolygon(TGPolygon& GHP,THoledPolygon& HP);

void COMMONAL_API Triangulate_(TGPolygon* GHP, TMDelTList <TIntVec> &tris);
//void GetToPlaneTransformation(const TIntVec &n, MBTi &AngX, MBTi &AngY);

//TIntVec TransformTo(const TIntVec &v, MBTi &AngX, MBTi &AngY);
//TIntVec TransformFrom(const TIntVec &v, MBTi &AngX, MBTi &AngY);



extern TMDelTList< TMTList<TGCut> > fuckin00;
extern TMDelTList < TMTwinElement < TMTList < TGCut >, TGPolygon *> > fuckin01;
extern TMTwinElement < TMTList < TGCut >, TGPolygon *> fuckin02;


template <class T>

void TMDelTListAdd(TMTList<T> &src, TMTList<T> &dst)
{
	for (int i=0;i<dst.Count;i++)
	{
		src.Add(new T);
		*src.Last() = dst[i];
	}	
}

template <class T>
void TMTListAdd(TMTList<T> &src, TMTList<T> &dst)
{
	for (int i=0;i<dst.Count;i++)
		src.Add(dst.Items[i]);
}

template <class T>
void TMTListSub(TMTList<T> &src, TMTList<T> &dst)
{
	for (int i=0;i<dst.Count;i++)
		src.Remove(dst.Items[i]);
}

template <class T>
void TMTListUnite(TMTList<T> &src, TMTList<T> &dst)
{
	for (int i=0;i<dst.Count;i++)
		if (dst.Items[i])
		{	
			int n=-1;
			if ((n = src.IndexOf(NULL)) != -1)
				src.Items[n] = dst.Items[i];
			else if (src.IndexOf(dst.Items[i]) == -1)
				src.Add(dst.Items[i]);
		}		
}

TGeomFlags FlagUnite(TGeomFlags &a, TGeomFlags &b);
COMMONAL_API void GetBasePoints(const TMTList<TGCut> &cuts, TMTList<TGPoint> &points);

extern int TimeForTransform;
extern int TimeForIntersect;
extern int TimeForDetect;
extern int TimeForSplit;
extern int TimeForPolygonize;
extern int TimeTotal;
extern int TimeTotalIntersect;
extern int TimeTotalSplit;
#endif

