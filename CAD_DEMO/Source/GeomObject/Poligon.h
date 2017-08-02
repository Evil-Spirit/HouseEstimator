//---------------------------------------------------------------------------

#ifndef PoligonH
#define PoligonH
//--------------------------------------------------------------------------
const int CommonError=-111;
const int CommonOK=111;

const int pipHOLEBOUNDARY = 3;
const int pipBOUNDARY = 2;
const int pipOUTSIDE = 1;
const int pipINSIDE = 0;

const int p_pOUTSIDE = 2;
const int p_pCROSSING = 1;
const int p_pINSIDE = 0;

class TLCut;

class COMMONAL_API TLPoint : public TMyObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TLPoint();
    virtual ~TLPoint();
    TIntVec Point;
    TMTList<TLCut> Cuts;
};

extern COMMONAL_API TClassNode* TLPoint::StaticType;


class COMMONAL_API TLCut : public TMyObject{
protected:
    TLPoint* FSrc;
    TLPoint* FDst;
    void SetSrc(TLPoint* Value);
    void SetDst(TLPoint* Value);
public:
    static TClassNode* StaticType;
    TLCut();
    virtual ~TLCut();
    TMyObject* CreateFunction();
    int Tag;
    __property TLPoint* Src = {read = FSrc,write = SetSrc};
    __property TLPoint* Dst = {read = FDst,write = SetDst};
    bool ConsistsDstAndSrc(TLPoint* R1,TLPoint* R2);
};

extern COMMONAL_API TClassNode* TLCut::StaticType;


const int pcrlNONE=0;
const int pcrlCROSSING=1;
const int pcrlCOMMONPOINT=2;
const int pcrlEQUAL=3;

//tclockwize
const int cwClockWize = 1;
const int cwNotClockWize = -1;
const int cwNotDefined = 0;

class TRoutePoint;

//CanExtrude;
enum TPolygonStatus { psOK=0,psCollinear=1,psNoPoints=2,psTooCloseEdges=3,psNoCrossPoints=4 };

class COMMONAL_API TPolygon : public TMyObject{
protected:
    TIntVec* GetPoint(int i);
    TIntVec* GetCyclePoint(int i);
    bool NotInstanced;
public:
    __int16 Tag;
    __int16 Tag2;
    __property TIntVec* Points[int index] = {read = GetPoint};
    __property TIntVec* CyclePoints[int index] = {read = GetCyclePoint};
    TPolygon();
    TPolygon(TMDelTList<TIntVec>* PNTS);
    TPolygon(TMTList<TIntVec>* PNTS);
    virtual ~TPolygon();
    //---------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //---------------------------------

    virtual void Invert(){Vertex->Invert();};
    /*TMDelLSTList*/TMDelTList<TIntVec> *Vertex;
    int ConsistsPoint(const TIntVec &Point,MBTi USEEPS);
    int ConsistsPolygon(TPolygon* ElsePol);
    bool CrossedWithPolygon(TPolygon* ElsePol,MBTi USEEPS);
    void Clear();
    TIntVec Center();
    virtual bool ExistsVertex(const TIntVec& V,TIntVec D = TIntVec(1,1,1));
    void PolygonBreak(int x);
    TIntVec MIN();
    TIntVec MAX();
    void Assign(TMyObject* MO);
    TPolygon& operator =(TPolygon& Pol);
    void Insert(int index,TIntVec* Item);
    virtual void Move(const TIntVec& _Move);
    virtual void Rotate(const TIntVec &Angle,const TIntVec &Center);

    TMDelTList<TRoutePoint> *Router;
    
    virtual double CentralArea();
    double TriangleArea();
    virtual void Set(int axes,MBTi Value);
    bool FindSelfCrossing(int& i1,int& i2,MBTi USEEPS);
    void GetCrossPoints(const TIntVec& P1,const TIntVec& P2, TMDelTList<TIntVec>* PointList,bool UseLinePoints,bool Edge,MBTi USEEPS);

    int FindLowRight(MBTi EPS);
    int IsClockWize();

    bool KillCollinear_1(MBTi USEEPS);
    bool KillCloseEdges_0(MBTi USEEPS);
    void KillSelfCrossing_2(TMDelTList<TPolygon>* POLS,MBTi USEEPS);
    virtual bool Valid(MBTi USEEPS);
    int IntrudeRib(int index,MBTi Value,MBTi USEEPS);
    int FindCollinear(MBTi USEEPS);
    void SquareCreate(const TIntVec& Size);
    void ToConvex(MBTi USEEPS);
    bool RibIsConvex(int index,MBTi USEEPS);
    bool IsConvex(MBTi USEEPS);
    bool PointIsConvex(int index,MBTi USEEPS);
    void ToConvexAndExtrude(MBTi USEEPS,MBTi Value);
    TIntVec AnyPoint(MBTi STEP);
    void ExtrudeRib(int index,MBTi Value,MBTi USEEPS);
};
extern COMMONAL_API TClassNode* TPolygon::StaticType;

const AnsiString aHoles = AnsiString("Holes");

class COMMONAL_API THoledPolygon : public TPolygon {
public:
    THoledPolygon(TMTList<TIntVec>* PNTS);
    THoledPolygon();
    virtual ~THoledPolygon();
    //---------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //---------------------------------

    /*TMDelLSTList*/TMDelTList < TPolygon > *Holes;
    void Clear()
    {
        TPolygon::Clear();
        for (int i=0;i<Holes->Count;i++)
            Holes->Items[i]->Clear();
    }
    void AddHole(TPolygon *PnewHole,bool Invert=false);
    void Assign(TMyObject* MO);
    THoledPolygon& operator =(THoledPolygon& HP);
    bool ExistsVertex(const TIntVec &P,TIntVec D = TIntVec(1,1,1));
    void Move(const TIntVec& _Move);
    void Rotate(const TIntVec &Angle,const TIntVec &Center);
    void Set(int axes,MBTi Value);
    double CentralArea();
    void GetCrossPoints_UseHoles(  const TIntVec& P1, const TIntVec& P2, TMDelTList<TIntVec>* PointList, bool UseLinePoints, bool Edge, bool HoleEdge, MBTi USEEPS );
    int ConsistsPoint_UseHoles(const TIntVec &Point,MBTi USEEPS);
    bool Valid(MBTi USEEPS);
};

extern COMMONAL_API TClassNode* THoledPolygon::StaticType;

#endif
