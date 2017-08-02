//---------------------------------------------------------------------------

#ifndef TGPolygonH
#define TGPolygonH
//---------------------------------------------------------------------------
#include "TGUnitV.h"

class TGCut;
class COMMONAL_API TGPolygon : public TGUnit
{
friend class TGeomObject;
friend class TGPoint;
friend class TGABoolean;
friend class TGASlice;
friend class TGAFix;
friend class TGAAnRender;
friend class TGATriangulate;

protected:
	TMTList<TGCut> FCuts;
	bool FClosed;				//���������
	TBBox			FBBox;

	TGeomFlags FFlags;


	TIntVec FNormal;
	TGPolygon *FParent;

	void SyncronizeWith(TGCut &Cut);
	void SetNormal(const TIntVec &n);
	TBBox GetBBox();
	
public:
//Drive
	int IndexForSmoothGroups;
//Drive

	__property TBBox BBox = {read = GetBBox};
	
	TGPolygon();
	TGPolygon(TMTList <TGCut> &cuts);

	int Tag;								// ���������������� ���
	int Index;
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
	void DeleteCut(TGCut *cut);				// �������� �������
	void DeleteCut(int index);				// �������� �������

	TGPolygon *AddHole(TMTList<TGCut>& );				// ���������� �����

	void ClearCuts();									// ������� ��������
	void Cache();
	void Restore();

	void PlaceOnPlane (MBTi &AngX, MBTi &AngY,const TIntVec &org = TIntVec(0,0,0));						//�������� �� ���������
	void BackFromPlane(const MBTi &AngX, const MBTi &AngY, const TIntVec &org = TIntVec(0,0,0));		// ������� � ���������

	bool CalculatePlane();								// ���������� ��������� (Normal, Origin)

/********************************* ��������������� ������� **********************************************/
	int IndexOf(TGPoint *pnt);											// ������ �����

	bool Equals(const TGPolygon& other) const;							// ������������� ���������
	bool ConsistsCut(TGCut *cut);									   	// ���������� �������
	void Invert(bool JstInvert = false);                                // �������������� ����������� ������

	int PointInPolygon2d(const TIntVec& Point, MBTi USEEPS);			// ��������� ����� � �������
	int PointInPolygon_UseHoles2d(const TIntVec &Point, MBTi USEEPS);	// ��������� ����� � ������� � �������

	int PolygonInPolygon2d(const TGPolygon &p, MBTi USEEPS);			// ��������� �������� � �������
	int PolygonInPolygon_UseHoles2d(const TGPolygon &p, MBTi USEEPS);	// ��������� �������� � ������� � �������

	TClassify ClassifyByPlane(const TIntVec &n, const TIntVec &o, MBTi EPS);	// �������������

/**/bool DetectSelfHoles();//?????????????

	TGPoint *GetLowestPoint2d();				// ����� ������ �����
	TGPoint *GetHighestPoint2d();				// ����� ������� �����
	
/*********************************** ��������� ***********************************************************/
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	void Assign(TMyObject* MO);
/*********************************** ��������� ***********************************************************/

	virtual ~TGPolygon();
};

extern COMMONAL_API TClassNode* TGPolygon::StaticType;

#endif

