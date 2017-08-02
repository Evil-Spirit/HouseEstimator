//---------------------------------------------------------------------------

#ifndef TriangulationH
#define TriangulationH
#include "math.h"

//---------------------------------------------------------------------------
class TPolygon;
class THoledPolygon;
COMMONAL_API enum TMyPolOperation { mpoAND = 0, mpoOR = 1, mpoXOR = 2 };
const int HoleStartIndex = 12000;


/*class TDVec : public TInt3d{
public:
    TDVec(){};
    TDVec(MBTi _x,MBTi _y){x=_x;y=_y;};
    TDVec(const TDVec& Vec){x = Vec.x;y = Vec.y;};
    virtual ~TDVec(){};
    MBTi Scalar2D(const TDVec& Vec);
    MBTi Equal2D(const TDVec& Vec,MBTi USEEPS);
    MBTi DLength();

    bool operator ==(const TDVec &rhs) const;
    bool operator !=(const TDVec &rhs) const;
    TDVec operator +(const TDVec &rhs) const;
    TDVec operator -(const TDVec &rhs) const;
    TDVec operator *(const TDVec &rhs) const;
    TDVec operator /(const TDVec &rhs) const;
    //------------------------------------------
    TDVec& operator +=(const TDVec &rhs);
    TDVec& operator -=(const TDVec &rhs);
    TDVec& operator *=(const TDVec &rhs);
    TDVec& operator /=(const TDVec &rhs);
    //------------------------------------------
    TDVec operator /(MBTi rhs) const;
    TDVec& operator /=(MBTi rhs);
    TDVec operator *(MBTi rhs) const;
    TDVec& operator *=(MBTi rhs);
};   */

class COMMONAL_API TDVec : public TIntVec{
public:
//    TMyObject* MyObjectParent;
  TDVec (){};
  virtual ~TDVec(){};
/*    __property MBTi x = {read = fx,write = fx};
    __property MBTi y = {read = fy,write = fy};
    __property MBTi z = {read = fz,write = fz}; */
  TDVec (float _x, float _y) { x = _x; y = _y; };

  TDVec (const TIntVec &v) { x = v.x; y = v.y; z = v.z; };

  TDVec operator+ (TDVec& p) { return TDVec(x + p.x, y + p.y); };
  TDVec operator- (TDVec& p) { return TDVec(x - p.x, y - p.y); };
  bool operator== (TDVec& p) { return (x == p.x) && (y == p.y); };
                                                
  float DLength(void) { return (x*x + y*y); }
  float Scalar2D(TDVec& Vec) { return (x*Vec.x + y*Vec.y); };
  bool Equal2D(const TDVec& Vec,MBTi USEEPS) { return (fabs(x-Vec.x)<USEEPS && fabs(y-Vec.y)<USEEPS); };
  //int classify(TNode&, TNode&);

  //TDVec(TInt3d* p){ x = p->x; y = p->y;};
};


class COMMONAL_API TDSide
{
    public:
    TDSide(TDVec *_P0,TDVec *_P1);
    TDSide(){};
    virtual ~TDSide(){};
    TDVec* ORGN;
    TDVec* DEST;
    bool operator ==(const TDSide &rhs) const;

    int Crossed(const TDSide& ELSE,TDVec& CROSS_POINT,MBTi USEEPS);
    int AnalizePoint(const TDVec& Point,MBTi USEEPS);
    bool ConsistsPoint(const TDVec& Point,MBTi USEEPS);
    int Tag;
};

class COMMONAL_API TCloseEdges{
public:
    TCloseEdges(){};
    virtual ~TCloseEdges(){};
    TMTList<TDVec> VECS;
    TMDelTList<int> INDICES;
};

const int opAND = 0;
const int opOR = 1;
const int opMINUS = 2;
const int opXOR = 3;


class COMMONAL_API TDelone {
private:
    TMDelTList< TCloseEdges > CL_EDGE;
    TMDelTList<TDSide> rBld;
    TMDelTList<TDVec> pBld;
    bool FindDeloneBrother(int i1,int i2);
    bool CheckSimpleCrossing(int i, int i1, int i2);
    bool CheckBldCrossing(int i, int i1, int i2);
    bool SimpleIntersection(TDSide& a,TDSide& b);
    void FindBaseRibs(int& i1,int& i2);
    int FindClosePoint(const TDVec& Vec,MBTi EPS);
    TDSide* FindRibByPoints(TDVec* P0,TDVec* P1);
    bool FindDeloneBrother_Ribs(int i1,int i2);
public:
    TDelone(){EPS = 0.0001;};
    virtual ~TDelone(){};

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

COMMONAL_API extern TDelone* pDeloune;

COMMONAL_API TDelone& GetDelone();
#define Delone GetDelone()
COMMONAL_API TDelone* GetDeloune();
#define Deloune GetDeloune()

#endif
