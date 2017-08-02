#ifndef TGPointH
#define TGPointH
#include "TGUnitV.h"
#include "Types.h"
//---------------------------------------------------------------------------
#include "TGUnitV.h"


class TGCut;
class COMMONAL_API TGPoint : public TGUnit
{
	friend class TGCut;
	friend class TGeomObject;
	friend class TGPolygon;
	friend class TGATriangulate;
private:	
	TGeomFlags FFlags;
	TIntVec *FCache;
	
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
	int Index;

	// ���������� �����
	TChangeVec Point;

	TGCut *GetTurnRightCut(bool MarkedOnly = false) const;				// �������, ����� �������������� ������� ������������ OY
	TGCut *GetTurnLeftCut(bool MarkedOnly = false) const;				// �������, ����� �������������� ������ ������������ OY

	TGCut *GetTurnRightCut(TGCut *cut,bool MarkedOnly = false) const;	// �������, ����� �������������� ������� ������������ �������� �������
	TGCut *GetTurnLeftCut(TGCut *cut,bool MarkedOnly = false) const;	// �������, ����� �������������� ������ ������������ �������� �������
	TGCut *GetAnotherCut(const TGCut *cut, bool MarkedOnly);
	bool Equals(const TGPoint &other);

	void Cache();			// ����������
	void Restore();			// ����� �� ����

	bool Used() const;		// ����������������
	
//--------------------------------------------------------
	void Changed(void* Field);
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	void Assign(TMyObject* MO);
//--------------------------------------------------------
	virtual ~TGPoint();
};

extern COMMONAL_API TClassNode* TGPoint::StaticType;

#endif

