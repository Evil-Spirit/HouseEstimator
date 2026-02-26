// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
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
	bool FClosed;				//Çàìêíóòûé
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

	// __property TBBox BBox {read=GetBBox}; // [manual migration needed]
	
	TGPolygon();
	TGPolygon(TMTList <TGCut> &cuts);

	int Tag;								// Ïîëüçîâàòåëüñêèé òýã
	int Index;
	TMDelTList < TGPolygon > FHoles;		// Äûðêè ïîëèãîíà

	int GetCount() const;						// Êîëëè÷åñòâî ýëåìåíòîâ
	// __property int Count {read=GetCount}; // [manual migration needed]

	const TGPoint &GetPoint(int index) const;				// Âåðøèíû
	TGPoint &GetPoint(int index);			 				// Âåðøèíû
// [indexed property - needs manual migration]: 	__property TGPoint &Points[int] = {read = GetPoint};	// Âåðøèíû

	bool FindBasisPoints(TMTList<TGPoint> &points);
	
	const TGCut &GetCut(int index) const;					// Îòðåçêè
	TGCut &GetCut(int index);								// Îòðåçêè
// [indexed property - needs manual migration]: 	__property TGCut &Cuts[int] = {read = GetCut};			// Îòðåçêè

	bool IsHoled() const;							   		// Ñîäåðæàíèå äûðîê

	TIntVec GetOrigin() const;
	TIntVec GetNormal();
	TIntVec GetMidOrigin() const;
	
	// __property bool Closed {read=FClosed}; // [manual migration needed]
	// __property bool Holed {read=IsHoled}; // [manual migration needed]
	// __property TGeomFlags Flags {read=FFlags, write=FFlags}; // [manual migration needed]
	
	// __property TIntVec Normal {read=GetNormal}; // [manual migration needed]
	// __property TIntVec Origin {read=GetOrigin}; // [manual migration needed]
	// __property TIntVec MidOrigin {read=GetMidOrigin}; // [manual migration needed]
	
/********************************* Êîìïîçèöèÿ ïîëèãîíà **********************************************/

	int AddCut(TGCut *);					// Äîáàâëåíèå îòðåçêà
	void DeleteCut(TGCut *cut);				// Óäàëåíèå îòðåçêà
	void DeleteCut(int index);				// Óäàëåíèå îòðåçêà

	TGPolygon *AddHole(TMTList<TGCut>& );				// Äîáàâëåíèå äûðêè

	void ClearCuts();									// Î÷èñòêà îòðåçêîâ
	void Cache();
	void Restore();

	void PlaceOnPlane (MBTi &AngX, MBTi &AngY,const TIntVec &org = TIntVec(0,0,0));						//Ïîëîæèòü íà ïëîñêîñòü
	void BackFromPlane(const MBTi &AngX, const MBTi &AngY, const TIntVec &org = TIntVec(0,0,0));		// âåðíóòü ñ ïëîñêîñòè

	bool CalculatePlane();								// Ðàññ÷èòàòü óðàâíåíèå (Normal, Origin)

/********************************* Âñïîìàãàòåëüíûå ôóíêöèè **********************************************/
	int IndexOf(TGPoint *pnt);											// Èíäåêñ òî÷êè

	bool Equals(const TGPolygon& other) const;							// Àíàëîãè÷íîñòü ïîëèãîíîâ
	bool ConsistsCut(TGCut *cut);									   	// Ñîäåðæàíèå îòðåçêà
	void Invert(bool JstInvert = false);                                // Èíâåðòèðîâàíèå íàïðàâëåíèÿ îáõîäà

	int PointInPolygon2d(const TIntVec& Point, MBTi USEEPS);			// Ïîïàäàíèå òî÷êè â ïîëèãîí
	int PointInPolygon_UseHoles2d(const TIntVec &Point, MBTi USEEPS);	// Ïîïàäàíèå òî÷êè â ïîëèãîí ñ äûðêàìè

	int PolygonInPolygon2d(const TGPolygon &p, MBTi USEEPS);			// Ïîïàäàíèå ïîëèãîíà â ïîëèãîí
	int PolygonInPolygon_UseHoles2d(const TGPolygon &p, MBTi USEEPS);	// Ïîïàäàíèå ïîëèãîíà â ïîëèãîí ñ äûðêàìè

	TClassify ClassifyByPlane(const TIntVec &n, const TIntVec &o, MBTi EPS);	// Êëàññèôèêàöèÿ

/**/bool DetectSelfHoles();//?????????????

	TGPoint *GetLowestPoint2d();				// Ñàìàÿ íèæíÿÿ òî÷êà
	TGPoint *GetHighestPoint2d();				// Ñàìàÿ âåðõíÿÿ òî÷êà
	
/*********************************** Ñèñòåìíûå ***********************************************************/
	static TClassNode* StaticType;
	static TMyObject* CreateFunction();
	void Assign(TMyObject* MO);
/*********************************** Ñèñòåìíûå ***********************************************************/

	virtual ~TGPolygon();
};


#endif

