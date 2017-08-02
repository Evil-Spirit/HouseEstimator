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

	
	TMTList <TGPolygon>  FPlane;			// Плоскости

	__property TGPolygon* FLeft = {read = GetPlane, write = SetPlane, index = 0};	// Левая 
	__property TGPolygon* FRight = {read = GetPlane, write = SetPlane, index = 1};	// Правая

	void SetPlane(int index, TGPolygon* aPlane);		// Установить плоскость
	const TGPolygon *GetPlane(int index) const;			// Взять плоскость

	void AddPlane(TGPolygon *plane);					// Добавить плоскость
	int RemovePlane(TGPolygon *plane);					// Удалить плоскость
	TGeomFlags FFlags;									// Геометрические флаги

	TBBox FBBox;
	const TBBox &GetBBox();

protected:
	void SetPoint(int index, TGPoint* Value);			// Задать точку
public:

	__property const TBBox &BBox = {read = GetBBox};
	TGCut();

	bool Smooth;	// Сглаженность грани
	int Tag;		// Тэг пользователя
	int Index;
	
	bool GetClosed() const;						   	// Замкнутость с точки зрения примыкающих полигонов
	__property bool Closed = {read = GetClosed};
	__property TGeomFlags Flags = {read = FFlags, write = FFlags}; 	// Флаги отрезка

	__property TGPoint* Src = {read = FPoint[0],write = SetPoint,index = 0};	// Начало
	__property TGPoint* Dst = {read = FPoint[1],write = SetPoint,index = 1};	// Конец

	__property TGPolygon* Left = {read = GetPlane,  index = 0};
	__property TGPolygon* Right = {read = GetPlane,  index = 1};
	
/*************************************** Вспомагательные функции ******************************************************/

/**/bool IsOneFreeSide() const;						// Свободная сторона с точки зрения примыкающих полигонов
	bool Equals(const TGCut& other) const;			// Аналогичность отрезков
	
	bool ConsistsDstAndSrc(const TGPoint* R1, const TGPoint* R2) const;	// Содержание обеих точек
	bool ConsistsPoint(const TGPoint* Point) const;						// Содержание точки


	bool Used() const;

	TGPoint *CanConnect(const TGCut &cut) const;			// Возможность состыковки отрезков
	TGPoint *GetAnotherPoint(const TGCut &c) const;			// Взять точку отрезка, не граничную с другим отрезком.
	TGPoint *GetAnotherPoint(const TGPoint* Point) const;	// Взять другую точку отрезка

	void Cache();			// Кэшировать
	void Restore();			// Взять из кэша
	
/************************** Системное ******************************************************/
	static TClassNode* StaticType;
	TMyObject* CreateFunction();
	void Assign(TMyObject* MO);
/*******************************************************************************************/
	virtual ~TGCut();
};

extern COMMONAL_API TClassNode* TGCut::StaticType;

#endif

