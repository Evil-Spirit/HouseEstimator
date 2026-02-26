// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef TypesH
#define TypesH

#include "Usefuls.h"
#include "MTL.h"
#include "MyTEmplates.h"
#include "MathV.h"
//---------------------------------------------------------------------------


///typedef bool ( *TConditionForPass)(TGCut *cut, TGPolygon *p1, TGPolygon *p2);
class TGPoint;
class TGCut;
class TGeomObject;

enum TRenderType		// Òèï îòîáðàæåíèÿ
{
	rtCLASSIFY,			// Êëàññèôèêàöèÿ
	rtMARK,				// Ìàðêèðîâêà
	rtSMOOTH,			// Ñãëàæèâàíèå
	rtCOLOR,			// Öâåòà
	rtERROR				// ×åðòåæ
};

enum TTag				// Òèï òýã
{
	tgOTHER	  	= 0,
	tgTHIS		= 3,

	tgPOSITIVE	= 1,
	tgNEGATIVE	= -1,
	tgINTERSECT	= 2,

	tgTRUE		= 1,
	tgFALSE		= 0,
};

enum TConstructFlags	// Ñòèëü îòîáðàæåíèÿ
{
	coPOINTS		= 0x0001,			// Òî÷êè
	coCUTS			= 0x0002,			// Îòðåçêè
	coPOLYGONS		= 0x0004,			// Ïîëèãîíû
	coNORMALS		= 0x0008,			// Íîðìàëè
	coPOLYGONHOLES  = 0x0010,			// Äûðêè ïîëèãîíîâ

	coWIRE			= 0x0001 | 0x0002,	// Êàðêàñíîå (òî÷êè+îòðåçêè)
	coSOLID			= 0x0004,			// Òâåðäîå òåëî (òîëüêî ïîëèãîíû)
	coALL			= 0xFFFF			// Âñå
};

enum TGeomResult	// Ðåçóëüòàò ãåîìåòðè÷åñêèõ ôóíêöèé
{
	grOK	=	0x0001,		// Îê
	grERROR =	0x0000,		// Îøèáêà
};

enum TGeomFixFlags			// Ôëàãè ãåîìåòðè÷åñêîãî âîññòàíîâëåíèÿ
{
	gfxPOINTSINCUTS		=	0x0001,		// 
	gfxCUTSCROSS		=	0x0002,
	gfxCLOSEPOINTS		=	0x0004,
	gfxALL				=	0xFFFF
};
	
enum TStructFixFlags		// Ôëàãè ñòðóêòóðíîãî âîññòàíîâëåíèÿ
{
	sfxREMOVE_BRANCHES					= 0x0001,	// Óäàëèòü âåòêè
	sfxREMOVE_REPEATED					= 0x0002,	// Óäàëèòü ïîâòîðíûå 	
	sfxREMOVE_BRIDGES_BY_CONTOURIZE     = 0x0004,	// Óäàëèòü ìîñòû êîíòóðèçàöèåé
	sfxREMOVE_BRIDGES_BY_POLYGONIZE     = 0x0008,	// Óäàëèòü ìîñòû ïîëèãîíèçàöèåé
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

enum TClassifyFlags			// Ôëàãè 
{                       	
	flORIGIN		= 0x0001,	// Ïîëîæåíèå
	flHOLE			= 0x0002,	// Äûðêà
	flINTERSECT		= 0x0004,	// Ïåðåñå÷åíèå
	flCONTOUR		= 0x0008,	// Êîíòóð
	flMARK			= 0x0010,	// Ìàðêèðîâêà
	flALREDY		= 0x0020,	// Óæå åñòü
	flBELONG		= 0x0040,	// Ïðèíàäëåæíîñòü
	flSAME			= 0x0080,	// Àíàëîãè÷íîñòü
	flERROR			= 0x0100,	// Îøèáêà
	flCACHED		= 0x0200,	// Êýøèðîâàíî
	flNEEDCALCN		= 0x0400,	// Íóæíî îáíîâèòü(ïåðåñòðîèòü)
	flBOUNDARY		= 0x0800,	// Ãðàíè÷íûé
	flNEEDCALCB		= 0x1000,	// Íóæíî îáíîâèòü(ïåðåñòðîèòü)
	flALL			= 0xFFFF,	// Âñå
};

enum TGBoolean					// Ôëàãè áóëåâûõ îïåðàöèé íàä ãåîìåòðèåé
{
	gbA_MINUS_B		= 0x01,		// A - B
	gbB_MINUS_A		= 0x02,     // B - A

	gbA_AND_B		= 0x03,		// ïåðåñå÷åèå A è B
	gbINTERSECTION	= 0x03,		//

	gbA_XOR_B		= 0x04,		// îáúåäèíåíèå A è B
	gbUNION			= 0x04,		//

	gbSPLIT			= 0x05		// òîëüêî ðàçáèåíèå
};

enum TClassify					// Îáùèé ôëàã
{
	gfFALSE			= 0x00,		// Èñòèíà
	gfTRUE			= 0x01,		// Ëîæíîñòü

	gfUNDEFINED		= 0x00,		// Íåîïðåäåëåííîñòü

	gfNEGATIVE		= 0x01,		// Îòðèöàòåëüíîñòü
	gfPOSITIVE 		= 0x02,		// Ïîëîæèòåëüíîñòü
	gfINTERSECT 	= 0x03,		// Ïåðåñå÷åíèå
	gfCOLLINEAR 	= 0x04,		// Êîëèèíåàðíîñòü

	gfOTHER		 	= 0x00,		// ×óæäîñòü
	gfTHIS		 	= 0x01,		// Ïðè÷àñòèå

};

template <class t1, class t2>		// Äâîéíîé ýëåìåíò. Äàííûå è óêàçàòåëü(îáû÷íî)
struct TMTwinElement
{
	t1 Data;
	t2 Target;
};

struct TGeomFlags					// Ãëàâíûå ãåîìåòðè÷åñêèå ôëàãè
{
	// Ôëàãè ðàáîòû ôóíêöèé
	unsigned Origin:3;				// Ïîëîæåíèå ïðè êëàññèôèêàöèè
	unsigned Cached:1;				// Çàêýøèðîâàííîñòü 
	unsigned Intersect:1;           // Ïåðåñå÷åíèå
	unsigned Solid:1;				// Çàìêíóòîñòü (íåïðîòèâîðå÷èå êîíöåïöèè òâåðäîãî òåëà)
	unsigned Alredy:1;				// Çàâåðøåííîñòü, Ïðèñóòñòâèå, Çàêîí÷åííîñòü

	// Âíóòðåííèå ôëàãè
	unsigned Mark:1;				// Ìàðêèðîâêà
	unsigned Hole:1;				// Äûðêà
	unsigned Belong:1;				// Ïðèíàäëåæíîñòü
	unsigned Contour:1;				// Êîíòóð
	unsigned Same:1;				// Àíàëîãè÷íîñòü
	unsigned Error:1;				// Îøèáî÷íîñòü
	unsigned NeedCalcN:1;			// Îáíîâëåíèå 
	unsigned NeedCalcB:1;			// Îáíîâëåíèå 
	unsigned Boundary:1;			// Ãðàíè÷íîñòü

	unsigned reserved:19;			// Ðåçåðâ
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
 
