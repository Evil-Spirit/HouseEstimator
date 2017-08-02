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

	// Отрезки точки
	 const TGCut &GetCut(int index) const;
	 TGCut &GetCut(int index);													
	__property TGCut& Cuts[int] = {read = GetCut};

	// Колличество отрезков точки
	int GetCutsCount() const;															
	__property int CutsCount = {read = GetCutsCount};

	// Замкнутость точки по замкнутости отрезков точки
	bool GetClosed() const;															
	__property bool Closed = {read = GetClosed};

	// Флаги точки
	__property TGeomFlags Flags = {read = FFlags, write = FFlags};

	// Тэг пользователя
	int Tag;
	int Index;

	// Координаты точки
	TChangeVec Point;

	TGCut *GetTurnRightCut(bool MarkedOnly = false) const;				// Отрезок, самый поворачивающий направо относительно OY
	TGCut *GetTurnLeftCut(bool MarkedOnly = false) const;				// Отрезок, самый поворачивающий налево относительно OY

	TGCut *GetTurnRightCut(TGCut *cut,bool MarkedOnly = false) const;	// Отрезок, самый поворачивающий направо относительно дргугого отрезка
	TGCut *GetTurnLeftCut(TGCut *cut,bool MarkedOnly = false) const;	// Отрезок, самый поворачивающий налево относительно дргугого отрезка
	TGCut *GetAnotherCut(const TGCut *cut, bool MarkedOnly);
	bool Equals(const TGPoint &other);

	void Cache();			// Кэшировать
	void Restore();			// Взять из кэша

	bool Used() const;		// Использованность
	
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

