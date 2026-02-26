// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
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

	// Îòðåçêè òî÷êè
	 const TGCut &GetCut(int index) const;
	 TGCut &GetCut(int index);													
// [indexed property - needs manual migration]: 	__property TGCut& Cuts[int] = {read = GetCut};

	// Êîëëè÷åñòâî îòðåçêîâ òî÷êè
	int GetCutsCount() const;															
	// __property int CutsCount {read=GetCutsCount}; // [manual migration needed]

	// Çàìêíóòîñòü òî÷êè ïî çàìêíóòîñòè îòðåçêîâ òî÷êè
	bool GetClosed() const;															
	// __property bool Closed {read=GetClosed}; // [manual migration needed]

	// Ôëàãè òî÷êè
	// __property TGeomFlags Flags {read=FFlags, write=FFlags}; // [manual migration needed]

	// Òýã ïîëüçîâàòåëÿ
	int Tag;
	int Index;

	// Êîîðäèíàòû òî÷êè
	TChangeVec Point;

	TGCut *GetTurnRightCut(bool MarkedOnly = false) const;				// Îòðåçîê, ñàìûé ïîâîðà÷èâàþùèé íàïðàâî îòíîñèòåëüíî OY
	TGCut *GetTurnLeftCut(bool MarkedOnly = false) const;				// Îòðåçîê, ñàìûé ïîâîðà÷èâàþùèé íàëåâî îòíîñèòåëüíî OY

	TGCut *GetTurnRightCut(TGCut *cut,bool MarkedOnly = false) const;	// Îòðåçîê, ñàìûé ïîâîðà÷èâàþùèé íàïðàâî îòíîñèòåëüíî äðãóãîãî îòðåçêà
	TGCut *GetTurnLeftCut(TGCut *cut,bool MarkedOnly = false) const;	// Îòðåçîê, ñàìûé ïîâîðà÷èâàþùèé íàëåâî îòíîñèòåëüíî äðãóãîãî îòðåçêà
	TGCut *GetAnotherCut(const TGCut *cut, bool MarkedOnly);
	bool Equals(const TGPoint &other);

	void Cache();			// Êýøèðîâàòü
	void Restore();			// Âçÿòü èç êýøà

	bool Used() const;		// Èñïîëüçîâàííîñòü
	
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

