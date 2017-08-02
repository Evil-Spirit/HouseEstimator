//---------------------------------------------------------------------------

#ifndef TypesH
#define TypesH

#include "Usefuls.h"
#include "MTL.h"
#include "MyTEmplates.h"
#include "MathV.h"
//---------------------------------------------------------------------------


///typedef bool (__closure *TConditionForPass)(TGCut *cut, TGPolygon *p1, TGPolygon *p2);
class TGPoint;
class TGCut;
class TGeomObject;

enum TRenderType		// Тип отображения
{
	rtCLASSIFY,			// Классификация
	rtMARK,				// Маркировка
	rtSMOOTH,			// Сглаживание
	rtCOLOR,			// Цвета
	rtERROR				// Чертеж
};

enum TTag				// Тип тэг
{
	tgOTHER	  	= 0,
	tgTHIS		= 3,

	tgPOSITIVE	= 1,
	tgNEGATIVE	= -1,
	tgINTERSECT	= 2,

	tgTRUE		= 1,
	tgFALSE		= 0,
};

enum TConstructFlags	// Стиль отображения
{
	coPOINTS		= 0x0001,			// Точки
	coCUTS			= 0x0002,			// Отрезки
	coPOLYGONS		= 0x0004,			// Полигоны
	coNORMALS		= 0x0008,			// Нормали
	coPOLYGONHOLES  = 0x0010,			// Дырки полигонов

	coWIRE			= 0x0001 | 0x0002,	// Каркасное (точки+отрезки)
	coSOLID			= 0x0004,			// Твердое тело (только полигоны)
	coALL			= 0xFFFF			// Все
};

enum TGeomResult	// Результат геометрических функций
{
	grOK	=	0x0001,		// Ок
	grERROR =	0x0000,		// Ошибка
};

enum TGeomFixFlags			// Флаги геометрического восстановления
{
	gfxPOINTSINCUTS		=	0x0001,		// 
	gfxCUTSCROSS		=	0x0002,
	gfxCLOSEPOINTS		=	0x0004,
	gfxALL				=	0xFFFF
};
	
enum TStructFixFlags		// Флаги структурного восстановления
{
	sfxREMOVE_BRANCHES					= 0x0001,	// Удалить ветки
	sfxREMOVE_REPEATED					= 0x0002,	// Удалить повторные 	
	sfxREMOVE_BRIDGES_BY_CONTOURIZE     = 0x0004,	// Удалить мосты контуризацией
	sfxREMOVE_BRIDGES_BY_POLYGONIZE     = 0x0008,	// Удалить мосты полигонизацией
};

enum TGeomPrimitiveType		
{
	gpPOINT		= 0x0001,
	gpPOINTS	= 0x0001,

	gpCUT		= 0x0002,
	gpCUTS		= 0x0002,

	gpPOLYGON	= 0x0003,
	gpPOLYGONS	= 0x0003,

	gpALL		= 0xFFFFFFFF
};

enum TClassifyFlags			// Флаги 
{                       	
	flORIGIN		= 0x0001,	// Положение
	flHOLE			= 0x0002,	// Дырка
	flINTERSECT		= 0x0004,	// Пересечение
	flCONTOUR		= 0x0008,	// Контур
	flMARK			= 0x0010,	// Маркировка
	flALREDY		= 0x0020,	// Уже есть
	flBELONG		= 0x0040,	// Принадлежность
	flSAME			= 0x0080,	// Аналогичность
	flERROR			= 0x0100,	// Ошибка
	flCACHED		= 0x0200,	// Кэшировано
	flNEEDCALCN		= 0x0400,	// Нужно обновить(перестроить)
	flBOUNDARY		= 0x0800,	// Граничный
	flNEEDCALCB		= 0x1000,	// Нужно обновить(перестроить)
	flALL			= 0xFFFF,	// Все
};

enum TGBoolean					// Флаги булевых операций над геометрией
{
	gbA_MINUS_B		= 0x01,		// A - B
	gbB_MINUS_A		= 0x02,     // B - A

	gbA_AND_B		= 0x03,		// пересечеие A и B
	gbINTERSECTION	= 0x03,		//

	gbA_XOR_B		= 0x04,		// объединение A и B
	gbUNION			= 0x04,		//

	gbSPLIT			= 0x05		// только разбиение
};

enum TClassify					// Общий флаг
{
	gfFALSE			= 0x00,		// Истина
	gfTRUE			= 0x01,		// Ложность

	gfUNDEFINED		= 0x00,		// Неопределенность

	gfNEGATIVE		= 0x01,		// Отрицательность
	gfPOSITIVE 		= 0x02,		// Положительность
	gfINTERSECT 	= 0x03,		// Пересечение
	gfCOLLINEAR 	= 0x04,		// Колиинеарность

	gfOTHER		 	= 0x00,		// Чуждость
	gfTHIS		 	= 0x01,		// Причастие

};

template <class t1, class t2>		// Двойной элемент. Данные и указатель(обычно)
struct TMTwinElement
{
	t1 Data;
	t2 Target;
};

struct TGeomFlags					// Главные геометрические флаги
{
	// Флаги работы функций
	unsigned Origin:3;				// Положение при классификации
	unsigned Cached:1;				// Закэшированность 
	unsigned Intersect:1;           // Пересечение
	unsigned Solid:1;				// Замкнутость (непротиворечие концепции твердого тела)
	unsigned Alredy:1;				// Завершенность, Присутствие, Законченность

	// Внутренние флаги
	unsigned Mark:1;				// Маркировка
	unsigned Hole:1;				// Дырка
	unsigned Belong:1;				// Принадлежность
	unsigned Contour:1;				// Контур
	unsigned Same:1;				// Аналогичность
	unsigned Error:1;				// Ошибочность
	unsigned NeedCalcN:1;			// Обновление 
	unsigned NeedCalcB:1;			// Обновление 
	unsigned Boundary:1;			// Граничность

	unsigned reserved:19;			// Резерв
};

class TBBox
{
public:
	TIntVec Min;
	TIntVec Max;

	TBBox(){} 
	TBBox(const TIntVec &min, const TIntVec &max) : Min(min), Max(max){}
	bool Overlaps(const TBBox &other, MBTi EPS = 0.0) const;
	bool Overlaps2d(const TBBox &other, MBTi EPS = 0.0) const;
	void Calculate(const TMTList <TGPoint> &pnts);
	void Calculate(const TMTList <TGCut> &cuts);
	void Calculate(const TGCut &cut);
};

class TGAlgorithm
{
protected:
	TGeomObject &go;
public:	
	TGAlgorithm(TGeomObject &obj) : go(obj) {};
};


#endif
 
