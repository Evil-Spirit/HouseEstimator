//---------------------------------------------------------------------------

#ifndef TestTriangulationH
#define TestTriangulationH
#include "Triangulation.h"
class TPolygon;
class THoledPolygon;
//---------------------------------------------------------------------------


class COMMONAL_API TDelone2 {
private:
    TMDelTList< TCloseEdges > CL_EDGE;
    TMDelTList<TDSide> rBld;
    TMDelTList<TDVec> pBld;
    bool FindDelone2Brother(int i1,int i2);
    bool CheckSimpleCrossing(int i, int i1, int i2);
    bool CheckBldCrossing(int i, int i1, int i2);
    bool SimpleIntersection(TDSide& a,TDSide& b);
    void FindBaseRibs(int& i1,int& i2);
    int FindClosePoint(const TDVec& Vec,MBTi EPS);
    TDSide* FindRibByPoints(TDVec* P0,TDVec* P1);
    bool FindDelone2Brother_Ribs(int i1,int i2);
public:
    TDelone2(){EPS = 0.0001;};
    virtual ~TDelone2(){};

    bool Started;
    TMTList<TDVec> pAll;
    TMDelTList<TDSide> rAll;
    MBTi EPS;

    TMDelTList<TIntVec> CashContour;
    TMTList<TIntVec> Triangles;
    TMTList<TIntVec> Contour;
    TMTList< TDSide > Tri_Ribs;

    void Clear();
    void DeleteClosePoints();
    void ProcessCrossList();
    void TriangulateByPoints();
    void TriangulateByRibs();
    void MergePolygon(TPolygon* P);
    void MergeHPolygon(THoledPolygon* HP);

    TMTList<TIntVec>* OPERATION(TPolygon* P0,TPolygon* P1,int oper);
    TMTList<TIntVec>* Triangulate(THoledPolygon* HP);
    TMTList<TIntVec>* Triangulate2(TMTList<THoledPolygon>* HPL,TMyPolOperation pOP);
    TMTList<TIntVec>* Triangulate3(THoledPolygon* HP,TMTList<TIntVec>* LineEdges);
    TMTList<TIntVec>* GetContour(TPolygon* SelfCrossed);

};

COMMONAL_API extern TDelone2* pDeloune2;

COMMONAL_API TDelone2& GetDelone2();
COMMONAL_API TDelone2* GetDeloune2();
//#define TestDelone Test::GetDelone()
//#define TestDeloune Test::GetDeloune()
#define Delone2 GetDelone2()
#define Deloune2 GetDeloune2()
#endif
