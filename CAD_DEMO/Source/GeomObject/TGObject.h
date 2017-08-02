//---------------------------------------------------------------------------

#ifndef TGObjectH
#define TGObjectH
//---------------------------------------------------------------------------


#include "types.h"

#include "TGPoint.h"
#include "TGCut.h"
#include "TGPolygon.h"

#include "TGAExtrude.h"
#include "TGAGraph.h"
#include "TGAAnRender.h"
#include "TGATriangulation.h"
#include "TGATransform.h"
#include "TGAFix.h"
#include "TGABoolean.h"
#include "TGASlice.h"
#include "LinearList.h"

class COMMONAL_API TGeomObject : public TMyObject {

friend class TGAExtrude;
friend class TGATransform;
friend class TGABoolean;
friend class TGASlice;
friend class TGAAnRender;
friend class TGATriangulate;
friend class TGAGraph;
friend class TGAAnRender;

protected:
	TMDelTList<TGPoint>		FVertex;									// Вершины
	TMDelTList<TGCut>		FCuts;										// Отрезки
	TMDelTList<TGPolygon>	FPolygons;									// Полигоны

	TMTList < TMTList<TGCut> > FUserCuts;								// Пользовательские указатели на отрезки

	void UpdateCutPointers(TGCut *o, TMTList <TGCut> n);				// Обновтить пользовательские списки указателей на отрезки
	void UpdateCutPointers(TGCut *o, TGCut *n);							//
	void UpdateCutPointers(TGCut *o);                                   //
	void UpdateCutPointers(TGCut *o, TGCut *n, TGCut *n2);              //

public:
	TGeomObject();

///////////////////////////////////
//	Управление
///////////////////////////////////
	MBTi PEPS;															// Эпсилон близости точек

	bool SnapPointsToNearest;											// Привязка точек при добавлении к ближайшей
	bool SnapPoints;													// Привязка точек при добавлении
	bool SnapPolygons;													// Привязка полигонов
	bool SnapCuts;														// Привязка отрезков

	bool CheckPolygonData;												// Проверка данных при добавлении полигона
	bool CheckCutData;													// Проверка данных при добавлении полигона

	void RegisterCutPointers(TMTList <TGCut> *user);					// заРегестрировать пользовательский список
	void UnRegisterCutPointers(TMTList <TGCut> *user);					// отРегестрировать пользовательский список
	void UnRegisterCutPointersAtAll();									// отРегистрировать все списки

	void CachePoints();													// Закэшировать точки
	void RestorePoints();												// Раскэшировать точки

	void CachePoints(TMTList <TGPoint> &pnt);                           // Закэшировать точки
	void RestorePoints(TMTList <TGPoint> &pnt);                         // Раскэшировать точки

	void Cache(TMTList <TMyObject> &pnt);         	    	    	          // Закэшировать точки
	void Restore(TMTList <TMyObject> &pnt);        	    	             // Раскэшировать точки
///////////////////////////////////
//	Флаги
///////////////////////////////////
	void FillCutsFlags(TClassifyFlags Flag, TClassify State);
	void FillCutsFlags(TMTList <TGCut> &cuts, TClassifyFlags Flag, TClassify State);

	void FillPolygonsFlags(TClassifyFlags Flag, TClassify State);
	void FillPolygonsFlags(TMTList <TGPolygon> &poly, TClassifyFlags Flag, TClassify State);

	void FillPointsFlags(TClassifyFlags Flag, TClassify State);
	void FillPointsFlags(TMTList <TGPoint> &points, TClassifyFlags Flag, TClassify State);
	void FillPointsFlags(TMTList<TMyObject> &what, TClassifyFlags fl, TClassify gf);

	void FillCutsTag(const int ID);												// Заполнить тэги отрезков
	void FillPointsTag(const int ID);											// Заполнить тэги полигонов

///////////////////////////////
//	Интефейс данных
///////////////////////////////

	// Интерфейс геометрических составляющих обьекта
	int GetPolygonsCount() const;										// Колличество полигонов
	__property int PolygonsCount = {read = GetPolygonsCount};			//

	int GetCutsCount() const;										   	// Колличество отрезков
	__property int CutsCount = {read = GetCutsCount};					//

	int GetVertexCount() const;											// Колличество точек
	__property int VertexCount = {read = GetVertexCount};				//

	TGPoint &GetVertex(int index) const;								// Вершины
	TGPoint &GetVertex(int index);										// Вершины
	__property TGPoint &Vertex[int] = {read = GetVertex};				// Вершины
	void GetPoints(TMTList <TGCut> &ret);

	TGCut &GetCut(int index) const;									   	// Отрезки
	TGCut &GetCut(int index);										   	// Отрезки
	__property TGCut &Cuts[int] = {read = GetCut};                      // Отрезки
	void GetCuts(TMTList <TGCut> &ret);

	TGPolygon &GetPolygon(int index) const;								// Полигоны
	TGPolygon &GetPolygon(int index);									// Полигоны
	void GetPolygons(TMTList <TGCut> &ret);

	__property TGPolygon &Polygons[int] = {read = GetPolygon};          // Полигоны

///////////////////////////////
//	Свойства объекта
///////////////////////////////

	bool GetClosed() const;												// Замкнутость элементов обьекта
	__property bool Closed = {read = GetClosed};						//

	bool GetSolid() const;												// Обьект - твердое тело
	__property bool Solid = {read = GetSolid};							//

///////////////////////////////
//	Поиск
///////////////////////////////

	int IndexOf(TGPoint *point) const;									// Индекс точки
	int IndexOf(TGCut *cut) const;										// Индекс отрезка
	int IndexOf(TGPolygon *polygon) const;								// Индекс полигона

	TGCut *ExistsCut(const TGCut &);											// Содержание отрезка
	TGCut *ExistsCut(TGPoint *p1, TGPoint *p2);

	TGPoint* ExistsPoint(const TIntVec& v);
	TGPoint* ExistsPoint(const TGPoint& v);

	TGPoint* ExistsPointNearest(const TIntVec& v);
	TGPoint* ExistsPointNearest(const TGPoint& v);

	TGPolygon *ExistsPolygon(const TGPolygon &);								// Содержание полигона

	TGCut* GetCutByPoints(TGPoint* P1, TGPoint* P2);								// Найти отрезок по двум точкам

///////////////////////////////
//	Главные функции изменения
///////////////////////////////

// Удаление элементов
	virtual void DeletePoint(int index);
	virtual void DeleteCut(int index);
	virtual void DeletePolygon(int index);

	virtual void Delete(TGPoint *target);
	virtual void Delete(TGCut *target);
	virtual void Delete(TGPolygon *target);

	virtual void Clear();														// Очистить геометрический обьект

// Добавление элементов
	TGPoint *AddPoint(const TIntVec &v); 				// Добавление точки
	TGPoint *AddPoint(const TGPoint &p);				// Добавление точки

	TGCut *AddCut(const TGCut &c);					   	// Добавление отрезка
	TGCut *AddCut(int, int);						   	// Добавление отрезка
	TGCut *AddCut(TGPoint *, TGPoint *);				// Добавление отрезка
	TGCut *AddCut(TIntVec v1, TIntVec v2);				// Добавление отрезка

	TGPolygon *AddPolygon(TMTList<TGCut>&, const TIntVec &nrm = TIntVec(0,0,0));				// Добавление полигона
	TGPolygon *AddPolygon(const TMTList<int>& indices, const TIntVec &nrm = TIntVec(0,0,0));	// Добавление полигона

	TGPolygon *CopyPolygonToObject(const TGPolygon &poly);										// Копирование полигона
	TGCut *CopyCutToObject(const TGCut &cut);				// Скопировать отрезок в обьект
// CopyPointToObj

//////////////////////////
// Структурное изменение
//////////////////////////

	TGCut *CompositeCuts(TGCut *c1, TGCut *c2);							// Главная функция обьединения
	void CompositePolygons(const TMTList<TGPolygon> &poly, TMDelTList < TMTList <TGCut> > &res);
	void CollapsePoints(TMTList <TGPoint> pnt);

	bool SplitCut(TGCut *c, TGPoint *Pnt);													// Разбиение отрезка точкой.
	bool SplitCut(TGCut *c, TGPoint *newPnt, TGCut *&Result1, TGCut *&Result2);				// Разбиение отрезка точкой.
	bool MultiSplitCut(TGCut *c, const TMTList<TGPoint> &newPnt, TMTList<TGCut> &Result);	// Множественное разбиение отрезка точкой
	bool MultiSplitCut(TGCut *c, const TMTList<TGPoint> &newPnt);							// Множественное разбиение отрезка точкой
	bool SplitPolygon(TGPolygon *p, TMTList<TGCut> &Cut, TMTList<TGPolygon> &result);		// Разбиение полигона отрезками

///////////

	void Append(TGeomObject &obj);							// Добавить другой обьект
	void CalculateNormals();								// Пересчитать нормали

/////////////////////

	void DetectHoles2d(TMTList<TGPolygon> &poly);											// Определение дырок
	void DetectHolesCreatePolygons2d(TMTList<TGPolygon> &poly);								// Определение дырок с созданием полигонов
	bool Polygonize2d(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly);				// Общая полигонизация
	bool Contourize2d(const TMTList<TGCut> &Cuts, TMTList<TGCut> &contour, TGPoint *begin = NULL);	// Общая контуризация
	bool PolygonizeIsolated(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly);

	void SortCutsByConnect(TMTList <TGCut> &cuts) const;
	TGPoint *GetLowestPoint2d(const TMTList<TGCut> &cuts);						// Взять самую нижнюю точку из отрезков
	void SortByLine(const TIntVec &nrm, TMTList <TGPoint> &pnt);

//////////
// Save
//////////

	void CutsToIndices(TMDelTList<int>& indices) const;							// Отрезки в индексы
	void IndicesToCuts(TMDelTList<int>& indices);								// Индексы в отрезки

	void PolygonToIndices(TGPolygon* GP,TMDelTList<int>& indices) const; 		// Полигон в индексы
	void IndicesToPolygon(TGPolygon* GP,TMDelTList<int>& indices); 				// Индексы в полигон

	void SavePolygonAsFigure(int ind, const AnsiString &name);
	void SaveCutsAsFigure(const TMTList <TGCut> &cuts, const  AnsiString &name);
	void SaveObjectAsFigure(int ind, const TMemoryStream *f);

	void SaveObjCutsAsFigure(const  AnsiString &name);

	void SavePolygon(TGPolygon *poly, FILE *F) const;
	void LoadPolygon(TGPolygon *poly, FILE *F);
	void WritePolygon(TGPolygon *poly, TMemoryStream *MS) const;
	void ReadPolygon(TGPolygon *poly, TMemoryStream *MS);

////////////////
// Algorithms //
////////////////
	void ToPrimitiveObj2(TVisPrimitiveObj* VCO, TConstructFlags co, TRenderType render);
	void ConstructVCO(TVisPrimitiveObj* VCO, TConstructFlags co, TRenderType render, TGeomObject& obj);
	void GetSmoothGroup2(TGPoint* Pnt, int CutIndex, int CurGroupInd, TMTList<TGPolygon>& Poly, TLList< TLList<int> >& FastPointDetect);
	void PolygonTriangulate(TGPolygon* p, TMTList<TGPolygon>& poly);

	TGAExtrude		Extrude;
	TGATriangulate	Triangulate;
	TGATransform	Transform;
	TGAFix			Fix;
	TGABoolean		Boolean;
	TGASlice		Slice;
	TGAGraph		Graph;
	TGAAnRender		AnRender;

////////////
// System
////////////

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	TMyObject* CreateFunction();
	static TClassNode* StaticType;

	void Assign(TMyObject* MO);
	void SaveData(FILE *F) const;
	void LoadData(FILE *F);
	void WriteData(TMemoryStream *MS) const;
	void ReadData(TMemoryStream *MS);
	virtual ~TGeomObject(){};

	TCreateFunction CreateCutFunction;
	TCreateFunction CreatePointFunction;
	TCreateFunction CreatePolygonFunction;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
};

void TGeomObject::GetPoints(TMTList <TGCut> &ret)
{
	ret.Assign(&FVertex);
}

void TGeomObject::GetCuts(TMTList <TGCut> &ret)
{
	ret.Assign(&FCuts);
}

void TGeomObject::GetPolygons(TMTList <TGCut> &ret)
{
	ret.Assign(&FPolygons);
}

/*
typedef TGeomObject TGObject;

#include "TGPrimitive.h"
*/

#endif
 
