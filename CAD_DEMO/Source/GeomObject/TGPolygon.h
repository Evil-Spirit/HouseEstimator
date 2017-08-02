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
	bool FClosed;				//Замкнутый
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

	int Tag;								// Пользовательский тэг
	int Index;
	TMDelTList < TGPolygon > FHoles;		// Дырки полигона

	int GetCount() const;						// Колличество элементов
	__property int Count = {read = GetCount};	// Колличество элементов

	const TGPoint &GetPoint(int index) const;				// Вершины
	TGPoint &GetPoint(int index);			 				// Вершины
	__property TGPoint &Points[int] = {read = GetPoint};	// Вершины

	bool FindBasisPoints(TMTList<TGPoint> &points);
	
	const TGCut &GetCut(int index) const;					// Отрезки
	TGCut &GetCut(int index);								// Отрезки
	__property TGCut &Cuts[int] = {read = GetCut};			// Отрезки

	bool IsHoled() const;							   		// Содержание дырок

	TIntVec GetOrigin() const;
	TIntVec GetNormal();
	TIntVec GetMidOrigin() const;
	
	__property bool Closed = {read = FClosed};		   		// Замкнутость отрезков
	__property bool Holed = {read = IsHoled};		   		//
	__property TGeomFlags Flags = {read = FFlags, write = FFlags};	   		// Флаги
	
	__property TIntVec Normal = {read = GetNormal};			// Нормаль
	__property TIntVec Origin = {read = GetOrigin};			// Точка на плоскости
	__property TIntVec MidOrigin = {read = GetMidOrigin};	// Точка на плоскости
	
/********************************* Композиция полигона **********************************************/

	int AddCut(TGCut *);					// Добавление отрезка
	void DeleteCut(TGCut *cut);				// Удаление отрезка
	void DeleteCut(int index);				// Удаление отрезка

	TGPolygon *AddHole(TMTList<TGCut>& );				// Добавление дырки

	void ClearCuts();									// Очистка отрезков
	void Cache();
	void Restore();

	void PlaceOnPlane (MBTi &AngX, MBTi &AngY,const TIntVec &org = TIntVec(0,0,0));						//Положить на плоскость
	void BackFromPlane(const MBTi &AngX, const MBTi &AngY, const TIntVec &org = TIntVec(0,0,0));		// вернуть с плоскости

	bool CalculatePlane();								// Рассчитать уравнение (Normal, Origin)

/********************************* Вспомагательные функции **********************************************/
	int IndexOf(TGPoint *pnt);											// Индекс точки

	bool Equals(const TGPolygon& other) const;							// Аналогичность полигонов
	bool ConsistsCut(TGCut *cut);									   	// Содержание отрезка
	void Invert(bool JstInvert = false);                                // Инвертирование направления обхода

	int PointInPolygon2d(const TIntVec& Point, MBTi USEEPS);			// Попадание точки в полигон
	int PointInPolygon_UseHoles2d(const TIntVec &Point, MBTi USEEPS);	// Попадание точки в полигон с дырками

	int PolygonInPolygon2d(const TGPolygon &p, MBTi USEEPS);			// Попадание полигона в полигон
	int PolygonInPolygon_UseHoles2d(const TGPolygon &p, MBTi USEEPS);	// Попадание полигона в полигон с дырками

	TClassify ClassifyByPlane(const TIntVec &n, const TIntVec &o, MBTi EPS);	// Классификация

/**/bool DetectSelfHoles();//?????????????

	TGPoint *GetLowestPoint2d();				// Самая нижняя точка
	TGPoint *GetHighestPoint2d();				// Самая верхняя точка
	
/*********************************** Системные ***********************************************************/
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	void Assign(TMyObject* MO);
/*********************************** Системные ***********************************************************/

	virtual ~TGPolygon();
};

extern COMMONAL_API TClassNode* TGPolygon::StaticType;

#endif

