// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
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

	
	TMTList <TGPolygon>  FPlane;			// Ïëîñêîñòè

	__property TGPolygon* FLeft = {read = GetPlane, write = SetPlane, index = 0};	// Ëåâàÿ 
	__property TGPolygon* FRight = {read = GetPlane, write = SetPlane, index = 1};	// Ïðàâàÿ

	void SetPlane(int index, TGPolygon* aPlane);		// Óñòàíîâèòü ïëîñêîñòü
	const TGPolygon *GetPlane(int index) const;			// Âçÿòü ïëîñêîñòü

	void AddPlane(TGPolygon *plane);					// Äîáàâèòü ïëîñêîñòü
	int RemovePlane(TGPolygon *plane);					// Óäàëèòü ïëîñêîñòü
	TGeomFlags FFlags;									// Ãåîìåòðè÷åñêèå ôëàãè

	TBBox FBBox;
	const TBBox &GetBBox();

protected:
	void SetPoint(int index, TGPoint* Value);			// Çàäàòü òî÷êó
public:

	__property const TBBox &BBox = {read = GetBBox};
	TGCut();

	bool Smooth;	// Ñãëàæåííîñòü ãðàíè
	int Tag;		// Òýã ïîëüçîâàòåëÿ
	int Index;
	
	bool GetClosed() const;						   	// Çàìêíóòîñòü ñ òî÷êè çðåíèÿ ïðèìûêàþùèõ ïîëèãîíîâ
	// __property bool Closed {read=GetClosed}; // [manual migration needed]
	// __property TGeomFlags Flags {read=FFlags, write=FFlags}; // [manual migration needed]

	__property TGPoint* Src = {read = FPoint[0],write = SetPoint,index = 0};	// Íà÷àëî
	__property TGPoint* Dst = {read = FPoint[1],write = SetPoint,index = 1};	// Êîíåö

	__property TGPolygon* Left = {read = GetPlane,  index = 0};
	__property TGPolygon* Right = {read = GetPlane,  index = 1};
	
/*************************************** Âñïîìàãàòåëüíûå ôóíêöèè ******************************************************/

/**/bool IsOneFreeSide() const;						// Ñâîáîäíàÿ ñòîðîíà ñ òî÷êè çðåíèÿ ïðèìûêàþùèõ ïîëèãîíîâ
	bool Equals(const TGCut& other) const;			// Àíàëîãè÷íîñòü îòðåçêîâ
	
	bool ConsistsDstAndSrc(const TGPoint* R1, const TGPoint* R2) const;	// Ñîäåðæàíèå îáåèõ òî÷åê
	bool ConsistsPoint(const TGPoint* Point) const;						// Ñîäåðæàíèå òî÷êè


	bool Used() const;

	TGPoint *CanConnect(const TGCut &cut) const;			// Âîçìîæíîñòü ñîñòûêîâêè îòðåçêîâ
	TGPoint *GetAnotherPoint(const TGCut &c) const;			// Âçÿòü òî÷êó îòðåçêà, íå ãðàíè÷íóþ ñ äðóãèì îòðåçêîì.
	TGPoint *GetAnotherPoint(const TGPoint* Point) const;	// Âçÿòü äðóãóþ òî÷êó îòðåçêà

	void Cache();			// Êýøèðîâàòü
	void Restore();			// Âçÿòü èç êýøà
	
/************************** Ñèñòåìíîå ******************************************************/
	static TClassNode* StaticType;
	static TMyObject* CreateFunction();
	void Assign(TMyObject* MO);
/*******************************************************************************************/
	virtual ~TGCut();
};


#endif

