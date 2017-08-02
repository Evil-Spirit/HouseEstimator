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
	TMDelTList<TGPoint>		FVertex;									// �������
	TMDelTList<TGCut>		FCuts;										// �������
	TMDelTList<TGPolygon>	FPolygons;									// ��������

	TMTList < TMTList<TGCut> > FUserCuts;								// ���������������� ��������� �� �������

	void UpdateCutPointers(TGCut *o, TMTList <TGCut> n);				// ��������� ���������������� ������ ���������� �� �������
	void UpdateCutPointers(TGCut *o, TGCut *n);							//
	void UpdateCutPointers(TGCut *o);                                   //
	void UpdateCutPointers(TGCut *o, TGCut *n, TGCut *n2);              //

public:
	TGeomObject();

///////////////////////////////////
//	����������
///////////////////////////////////
	MBTi PEPS;															// ������� �������� �����

	bool SnapPointsToNearest;											// �������� ����� ��� ���������� � ���������
	bool SnapPoints;													// �������� ����� ��� ����������
	bool SnapPolygons;													// �������� ���������
	bool SnapCuts;														// �������� ��������

	bool CheckPolygonData;												// �������� ������ ��� ���������� ��������
	bool CheckCutData;													// �������� ������ ��� ���������� ��������

	void RegisterCutPointers(TMTList <TGCut> *user);					// ���������������� ���������������� ������
	void UnRegisterCutPointers(TMTList <TGCut> *user);					// ���������������� ���������������� ������
	void UnRegisterCutPointersAtAll();									// ���������������� ��� ������

	void CachePoints();													// ������������ �����
	void RestorePoints();												// ������������� �����

	void CachePoints(TMTList <TGPoint> &pnt);                           // ������������ �����
	void RestorePoints(TMTList <TGPoint> &pnt);                         // ������������� �����

	void Cache(TMTList <TMyObject> &pnt);         	    	    	          // ������������ �����
	void Restore(TMTList <TMyObject> &pnt);        	    	             // ������������� �����
///////////////////////////////////
//	�����
///////////////////////////////////
	void FillCutsFlags(TClassifyFlags Flag, TClassify State);
	void FillCutsFlags(TMTList <TGCut> &cuts, TClassifyFlags Flag, TClassify State);

	void FillPolygonsFlags(TClassifyFlags Flag, TClassify State);
	void FillPolygonsFlags(TMTList <TGPolygon> &poly, TClassifyFlags Flag, TClassify State);

	void FillPointsFlags(TClassifyFlags Flag, TClassify State);
	void FillPointsFlags(TMTList <TGPoint> &points, TClassifyFlags Flag, TClassify State);
	void FillPointsFlags(TMTList<TMyObject> &what, TClassifyFlags fl, TClassify gf);

	void FillCutsTag(const int ID);												// ��������� ���� ��������
	void FillPointsTag(const int ID);											// ��������� ���� ���������

///////////////////////////////
//	�������� ������
///////////////////////////////

	// ��������� �������������� ������������ �������
	int GetPolygonsCount() const;										// ����������� ���������
	__property int PolygonsCount = {read = GetPolygonsCount};			//

	int GetCutsCount() const;										   	// ����������� ��������
	__property int CutsCount = {read = GetCutsCount};					//

	int GetVertexCount() const;											// ����������� �����
	__property int VertexCount = {read = GetVertexCount};				//

	TGPoint &GetVertex(int index) const;								// �������
	TGPoint &GetVertex(int index);										// �������
	__property TGPoint &Vertex[int] = {read = GetVertex};				// �������
	void GetPoints(TMTList <TGCut> &ret);

	TGCut &GetCut(int index) const;									   	// �������
	TGCut &GetCut(int index);										   	// �������
	__property TGCut &Cuts[int] = {read = GetCut};                      // �������
	void GetCuts(TMTList <TGCut> &ret);

	TGPolygon &GetPolygon(int index) const;								// ��������
	TGPolygon &GetPolygon(int index);									// ��������
	void GetPolygons(TMTList <TGCut> &ret);

	__property TGPolygon &Polygons[int] = {read = GetPolygon};          // ��������

///////////////////////////////
//	�������� �������
///////////////////////////////

	bool GetClosed() const;												// ����������� ��������� �������
	__property bool Closed = {read = GetClosed};						//

	bool GetSolid() const;												// ������ - ������� ����
	__property bool Solid = {read = GetSolid};							//

///////////////////////////////
//	�����
///////////////////////////////

	int IndexOf(TGPoint *point) const;									// ������ �����
	int IndexOf(TGCut *cut) const;										// ������ �������
	int IndexOf(TGPolygon *polygon) const;								// ������ ��������

	TGCut *ExistsCut(const TGCut &);											// ���������� �������
	TGCut *ExistsCut(TGPoint *p1, TGPoint *p2);

	TGPoint* ExistsPoint(const TIntVec& v);
	TGPoint* ExistsPoint(const TGPoint& v);

	TGPoint* ExistsPointNearest(const TIntVec& v);
	TGPoint* ExistsPointNearest(const TGPoint& v);

	TGPolygon *ExistsPolygon(const TGPolygon &);								// ���������� ��������

	TGCut* GetCutByPoints(TGPoint* P1, TGPoint* P2);								// ����� ������� �� ���� ������

///////////////////////////////
//	������� ������� ���������
///////////////////////////////

// �������� ���������
	virtual void DeletePoint(int index);
	virtual void DeleteCut(int index);
	virtual void DeletePolygon(int index);

	virtual void Delete(TGPoint *target);
	virtual void Delete(TGCut *target);
	virtual void Delete(TGPolygon *target);

	virtual void Clear();														// �������� �������������� ������

// ���������� ���������
	TGPoint *AddPoint(const TIntVec &v); 				// ���������� �����
	TGPoint *AddPoint(const TGPoint &p);				// ���������� �����

	TGCut *AddCut(const TGCut &c);					   	// ���������� �������
	TGCut *AddCut(int, int);						   	// ���������� �������
	TGCut *AddCut(TGPoint *, TGPoint *);				// ���������� �������
	TGCut *AddCut(TIntVec v1, TIntVec v2);				// ���������� �������

	TGPolygon *AddPolygon(TMTList<TGCut>&, const TIntVec &nrm = TIntVec(0,0,0));				// ���������� ��������
	TGPolygon *AddPolygon(const TMTList<int>& indices, const TIntVec &nrm = TIntVec(0,0,0));	// ���������� ��������

	TGPolygon *CopyPolygonToObject(const TGPolygon &poly);										// ����������� ��������
	TGCut *CopyCutToObject(const TGCut &cut);				// ����������� ������� � ������
// CopyPointToObj

//////////////////////////
// ����������� ���������
//////////////////////////

	TGCut *CompositeCuts(TGCut *c1, TGCut *c2);							// ������� ������� �����������
	void CompositePolygons(const TMTList<TGPolygon> &poly, TMDelTList < TMTList <TGCut> > &res);
	void CollapsePoints(TMTList <TGPoint> pnt);

	bool SplitCut(TGCut *c, TGPoint *Pnt);													// ��������� ������� ������.
	bool SplitCut(TGCut *c, TGPoint *newPnt, TGCut *&Result1, TGCut *&Result2);				// ��������� ������� ������.
	bool MultiSplitCut(TGCut *c, const TMTList<TGPoint> &newPnt, TMTList<TGCut> &Result);	// ������������� ��������� ������� ������
	bool MultiSplitCut(TGCut *c, const TMTList<TGPoint> &newPnt);							// ������������� ��������� ������� ������
	bool SplitPolygon(TGPolygon *p, TMTList<TGCut> &Cut, TMTList<TGPolygon> &result);		// ��������� �������� ���������

///////////

	void Append(TGeomObject &obj);							// �������� ������ ������
	void CalculateNormals();								// ����������� �������

/////////////////////

	void DetectHoles2d(TMTList<TGPolygon> &poly);											// ����������� �����
	void DetectHolesCreatePolygons2d(TMTList<TGPolygon> &poly);								// ����������� ����� � ��������� ���������
	bool Polygonize2d(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly);				// ����� �������������
	bool Contourize2d(const TMTList<TGCut> &Cuts, TMTList<TGCut> &contour, TGPoint *begin = NULL);	// ����� ������������
	bool PolygonizeIsolated(const TMTList<TGCut> &Cuts, TMDelTList< TMTList<TGCut> > &poly);

	void SortCutsByConnect(TMTList <TGCut> &cuts) const;
	TGPoint *GetLowestPoint2d(const TMTList<TGCut> &cuts);						// ����� ����� ������ ����� �� ��������
	void SortByLine(const TIntVec &nrm, TMTList <TGPoint> &pnt);

//////////
// Save
//////////

	void CutsToIndices(TMDelTList<int>& indices) const;							// ������� � �������
	void IndicesToCuts(TMDelTList<int>& indices);								// ������� � �������

	void PolygonToIndices(TGPolygon* GP,TMDelTList<int>& indices) const; 		// ������� � �������
	void IndicesToPolygon(TGPolygon* GP,TMDelTList<int>& indices); 				// ������� � �������

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
 
