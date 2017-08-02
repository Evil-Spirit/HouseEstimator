//---------------------------------------------------------------------------

#ifndef TGCutH
#define TGCutH
//---------------------------------------------------------------------------
#include "types.h"
#include "TGUnitV.h"

class COMMONAL_API TGCut : public TGUnit
{
	friend class TGPolygon;
	friend class TGPoint;
	friend class TGeomObject;
	friend class TGAFix;
	friend class TGAAnRender;
	
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

	
	TMTList <TGPolygon>  FPlane;			// ���������

	__property TGPolygon* FLeft = {read = GetPlane, write = SetPlane, index = 0};	// ����� 
	__property TGPolygon* FRight = {read = GetPlane, write = SetPlane, index = 1};	// ������

	void SetPlane(int index, TGPolygon* aPlane);		// ���������� ���������
	const TGPolygon *GetPlane(int index) const;			// ����� ���������

	void AddPlane(TGPolygon *plane);					// �������� ���������
	int RemovePlane(TGPolygon *plane);					// ������� ���������
	TGeomFlags FFlags;									// �������������� �����

	TBBox FBBox;
	const TBBox &GetBBox();

protected:
	void SetPoint(int index, TGPoint* Value);			// ������ �����
public:

	__property const TBBox &BBox = {read = GetBBox};
	TGCut();

	bool Smooth;	// ������������ �����
	int Tag;		// ��� ������������
	int Index;
	
	bool GetClosed() const;						   	// ����������� � ����� ������ ����������� ���������
	__property bool Closed = {read = GetClosed};
	__property TGeomFlags Flags = {read = FFlags, write = FFlags}; 	// ����� �������

	__property TGPoint* Src = {read = FPoint[0],write = SetPoint,index = 0};	// ������
	__property TGPoint* Dst = {read = FPoint[1],write = SetPoint,index = 1};	// �����

	__property TGPolygon* Left = {read = GetPlane,  index = 0};
	__property TGPolygon* Right = {read = GetPlane,  index = 1};
	
/*************************************** ��������������� ������� ******************************************************/

/**/bool IsOneFreeSide() const;						// ��������� ������� � ����� ������ ����������� ���������
	bool Equals(const TGCut& other) const;			// ������������� ��������
	
	bool ConsistsDstAndSrc(const TGPoint* R1, const TGPoint* R2) const;	// ���������� ����� �����
	bool ConsistsPoint(const TGPoint* Point) const;						// ���������� �����


	bool Used() const;

	TGPoint *CanConnect(const TGCut &cut) const;			// ����������� ���������� ��������
	TGPoint *GetAnotherPoint(const TGCut &c) const;			// ����� ����� �������, �� ��������� � ������ ��������.
	TGPoint *GetAnotherPoint(const TGPoint* Point) const;	// ����� ������ ����� �������

	void Cache();			// ����������
	void Restore();			// ����� �� ����
	
/************************** ��������� ******************************************************/
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	void Assign(TMyObject* MO);
/*******************************************************************************************/
	virtual ~TGCut();
};

extern COMMONAL_API TClassNode* TGCut::StaticType;

#endif

