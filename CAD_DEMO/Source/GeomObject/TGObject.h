// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
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
	TMDelTList<TGPoint>		FVertex;									// Âåðøèíû
	TMDelTList<TGCut>		FCuts;										// Îòðåçêè
	TMDelTList<TGPolygon>	FPolygons;									// Ïîëèãîíû

	TMTList < TMTList<TGCut> > FUserCuts;								// Ïîëüçîâàòåëüñêèå óêàçàòåëè íà îòðåçêè

	void UpdateCutPointers(TGCut *o, TMTList <TGCut> n);				// Îáíîâòèòü ïîëüçîâàòåëüñêèå ñïèñêè óêàçàòåëåé íà îòðåçêè
	void UpdateCutPointers(TGCut *o, TGCut *n);							//
	void UpdateCutPointers(TGCut *o);                                   //
	void UpdateCutPointers(TGCut *o, TGCut *n, TGCut *n2);              //

public:
	TGeomObject();

///////////////////////////////////
//	Óïðàâëåíèå
///////////////////////////////////
	MBTi PEPS;															// Ýïñèëîí áëèçîñòè òî÷åê

	bool SnapPointsToNearest;											// Ïðèâÿçêà òî÷åê ïðè äîáàâëåíèè ê áëèæàéøåé
	bool SnapPoints;													// Ïðèâÿçêà òî÷åê ïðè äîáàâëåíèè
	bool SnapPolygons;													// Ïðèâÿçêà ïîëèãîíîâ
	bool SnapCuts;														// Ïðèâÿçêà îòðåçêîâ

	bool CheckPolygonData;												// Ïðîâåðêà äàííûõ ïðè äîáàâëåíèè ïîëèãîíà
	bool CheckCutData;													// Ïðîâåðêà äàííûõ ïðè äîáàâëåíèè ïîëèãîíà

	void RegisterCutPointers(TMTList <TGCut> *user);					// çàÐåãåñòðèðîâàòü ïîëüçîâàòåëüñêèé ñïèñîê
	void UnRegisterCutPointers(TMTList <TGCut> *user);					// îòÐåãåñòðèðîâàòü ïîëüçîâàòåëüñêèé ñïèñîê
	void UnRegisterCutPointersAtAll();									// îòÐåãèñòðèðîâàòü âñå ñïèñêè

	void CachePoints();													// Çàêýøèðîâàòü òî÷êè
	void RestorePoints();												// Ðàñêýøèðîâàòü òî÷êè

	void CachePoints(TMTList <TGPoint> &pnt);                           // Çàêýøèðîâàòü òî÷êè
	void RestorePoints(TMTList <TGPoint> &pnt);                         // Ðàñêýøèðîâàòü òî÷êè

	void Cache(TMTList <TMyObject> &pnt);         	    	    	          // Çàêýøèðîâàòü òî÷êè
	void Restore(TMTList <TMyObject> &pnt);        	    	             // Ðàñêýøèðîâàòü òî÷êè
///////////////////////////////////
//	Ôëàãè
///////////////////////////////////
	void FillCutsFlags(TClassifyFlags Flag, TClassify State);
	void FillCutsFlags(TMTList <TGCut> &cuts, TClassifyFlags Flag, TClassify State);

	void FillPolygonsFlags(TClassifyFlags Flag, TClassify State);
	void FillPolygonsFlags(TMTList <TGPolygon> &poly, TClassifyFlags Flag, TClassify State);

	void FillPointsFlags(TClassifyFlags Flag, TClassify State);
	void FillPointsFlags(TMTList <TGPoint> &points, TClassifyFlags Flag, TClassify State);
	void FillPointsFlags(TMTList<TMyObject> &what, TClassifyFlags fl, TClassify gf);

	void FillCutsTag(const int ID);												// Çàïîëíèòü òýãè îòðåçêîâ
	void FillPointsTag(const int ID);											// Çàïîëíèòü òýãè ïîëèãîíîâ

///////////////////////////////
//	Èíòåôåéñ äàííûõ
///////////////////////////////

	// Èíòåðôåéñ ãåîìåòðè÷åñêèõ ñîñòàâëÿþùèõ îáüåêòà
	int GetPolygonsCount() const;										// Êîëëè÷åñòâî ïîëèãîíîâ
	// __property int PolygonsCount {read=GetPolygonsCount}; // [manual migration needed]

	int GetCutsCount() const;										   	// Êîëëè÷åñòâî îòðåçêîâ
	// __property int CutsCount {read=GetCutsCount}; // [manual migration needed]

	int GetVertexCount() const;											// Êîëëè÷åñòâî òî÷åê
	// __property int VertexCount {read=GetVertexCount}; // [manual migration needed]

	TGPoint &GetVertex(int index) const;								// Âåðøèíû
	TGPoint &GetVertex(int index);										// Âåðøèíû
// [indexed property - needs manual migration]: 	__property TGPoint &Vertex[int] = {read = GetVertex};				// Âåðøèíû
	void GetPoints(TMTList <TGCut> &ret);

	TGCut &GetCut(int index) const;									   	// Îòðåçêè
	TGCut &GetCut(int index);										   	// Îòðåçêè
// [indexed property - needs manual migration]: 	__property TGCut &Cuts[int] = {read = GetCut};                      // Îòðåçêè
	void GetCuts(TMTList <TGCut> &ret);

	TGPolygon &GetPolygon(int index) const;								// Ïîëèãîíû
	TGPolygon &GetPolygon(int index);									// Ïîëèãîíû
	void GetPolygons(TMTList <TGCut> &ret);

// [indexed property - needs manual migration]: 	__property TGPolygon &Polygons[int] = {read = GetPolygon};          // Ïîëèãîíû

///////////////////////////////
//	Ñâîéñòâà îáúåêòà
///////////////////////////////

	bool GetClosed() const;												// Çàìêíóòîñòü ýëåìåíòîâ îáüåêòà
	// __property bool Closed {read=GetClosed}; // [manual migration needed]

	bool GetSolid() const;												// Îáüåêò - òâåðäîå òåëî
	// __property bool Solid {read=GetSolid}; // [manual migration needed]

///////////////////////////////
//	Ïîèñê
///////////////////////////////

	int IndexOf(TGPoint *point) const;									// Èíäåêñ òî÷êè
	int IndexOf(TGCut *cut) const;										// Èíäåêñ îòðåçêà
	int IndexOf(TGPolygon *polygon) const;								// Èíäåêñ ïîëèãîíà

	TGCut *ExistsCut(const TGCut &);											// Ñîäåðæàíèå îòðåçêà
	TGCut *ExistsCut(TGPoint *p1, TGPoint *p2);

	TGPoint* ExistsPoint(const TIntVec& v);
	TGPoint* ExistsPoint(const TGPoint& v);

	TGPoint* ExistsPointNearest(const TIntVec& v);
	TGPoint* ExistsPointNearest(const TGPoint& v);

	TGPolygon *ExistsPolygon(const TGPolygon &);								// Ñîäåðæàíèå ïîëèãîíà

	TGCut* GetCutByPoints(TGPoint* P1, TGPoint* P2);								// Íàéòè îòðåçîê ïî äâóì òî÷êàì

///////////////////////////////
//	Ãëàâíûå ôóíêöèè èçìåíåíèÿ
///////////////////////////////

// Óäàëåíèå ýëåìåíòîâ
	virtual void DeletePoint(int index);
	virtual void DeleteCut(int index);
	virtual void DeletePolygon(int index);

	virtual void Delete(TGPoint *target);
	virtual void Delete(TGCut *target);
	virtual void Delete(TGPolygon *target);

	virtual void Clear();														// Î÷èñòèòü ãåîìåòðè÷åñêèé îáüåêò

// Äîáàâëåíèå ýëåìåíòîâ
	TGPoint *AddPoint(const TIntVec &v); 				// Äîáàâëåíèå òî÷êè
	TGPoint *AddPoint(const TGPoint &p);				// Äîáàâëåíèå òî÷êè

	TGCut *AddCut(const TGCut &c);					   	// Äîáàâëåíèå îòðåçêà
	TGCut *AddCut(int, int);						   	// Äîáàâëåíèå îòðåçêà
	TGCut *AddCut(TGPoint *, TGPoint *);				// Äîáàâëåíèå îòðåçêà
	TGCut *AddCut(TIntVec v1, TIntVec v2);				// Äîáàâëåíèå îòðåçêà

	TGPolygon *AddPolygon(TMTList<TGCut>&, const TIntVec &nrm = TIntVec(0,0,0));				// Äîáàâëåíèå ïîëèãîíà
	TGPolygon *AddPolygon(const TMTList<int>& indices, const TIntVec &nrm = TIntVec(0,0,0));	// Äîáàâëåíèå ïîëèãîíà

	TGPolygon *CopyPolygonToObject(const TGPolygon &poly);										// Êîïèðîâàíèå ïîëèãîíà
	TGCut *CopyCutToObject(const TGCut &cut);				// Ñêîïèðîâàòü îòðåçîê â îáüåêò
// CopyPointToObj

//////////////////////////
// Ñòðóêòóðíîå èçìåíåíèå
//////////////////////////

	TGCut *CompositeCuts(TGCut *c1, TGCut *c2);							// Ãëàâíàÿ ôóíêöèÿ îáüåäèíåíèÿ
	void CompositePolygons(const TMTList<TGPolygon> &poly, TMDelTList < TMTList <TGCut> > &res);
	void CollapsePoints(TMTList <TGPoint> pnt);

	bool SplitCut(TGCut *c, TGPoint *Pnt);													// Ðàçáèåíèå îòðåçêà òî÷êîé.
	bool SplitCut(TGCut *c, TGPoint *newPnt, TGCut *&Result1, TGCut *&Result2);				// Ðàçáèåíèå îòðåçêà òî÷êîé.
	bool MultiSplitCut(TGCut *c, const TMTList<TGPoint> &newPnt, TMTList<TGCut> &Result);	// Ìíîæåñòâåííîå ðàçáèåíèå îòðåçêà òî÷êîé
	bool MultiSplitCut(TGCut *c, const TMTList<TGPoint> &newPnt);							// Ìíîæåñòâåííîå ðàçáèåíèå îòðåçêà òî÷êîé
	bool SplitPolygon(TGPolygon *p, TMTList<TGCut> &Cut, TMTList<TGPolygon> &result);		// Ðàçáèåíèå ïîëèãîíà îòðåçêàìè

///////////

	void Append(TGeomObject &obj);							// Äîáàâèòü äðóãîé îáüåêò
	void CalculateNormals();								// Ïåðåñ÷èòàòü íîðìàëè

/////////////////////

	void DetectHoles2d(TMTList<TGPolygon> &poly);											// Îïðåäåëåíèå äûðîê
	void DetectHolesCreatePolygons2d(TMTList<TGPolygon> &poly);								// Îïðåäåëåíèå äûðîê ñ ñîçäàíèåì ïîëèãîíîâ
	bool Polygonize2d(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly);				// Îáùàÿ ïîëèãîíèçàöèÿ
	bool Contourize2d(const TMTList<TGCut> &Cuts, TMTList<TGCut> &contour, TGPoint *begin = NULL);	// Îáùàÿ êîíòóðèçàöèÿ
	bool PolygonizeIsolated(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly);

	void SortCutsByConnect(TMTList <TGCut> &cuts) const;
	TGPoint *GetLowestPoint2d(const TMTList<TGCut> &cuts);						// Âçÿòü ñàìóþ íèæíþþ òî÷êó èç îòðåçêîâ
	void SortByLine(const TIntVec &nrm, TMTList <TGPoint> &pnt);

//////////
// Save
//////////

	void CutsToIndices(TMDelTList<int>& indices) const;							// Îòðåçêè â èíäåêñû
	void IndicesToCuts(TMDelTList<int>& indices);								// Èíäåêñû â îòðåçêè

	void PolygonToIndices(TGPolygon* GP,TMDelTList<int>& indices) const; 		// Ïîëèãîí â èíäåêñû
	void IndicesToPolygon(TGPolygon* GP,TMDelTList<int>& indices); 				// Èíäåêñû â ïîëèãîí

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
	static TMyObject* CreateFunction();
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
 
