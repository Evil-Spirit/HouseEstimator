//---------------------------------------------------------------------------

#ifndef G2DGeomVH
#define G2DGeomVH
//---------------------------------------------------------------------------
const MBTf MBTf_EPS = 0.0000000001; //10^(-10)  дл€ расчетов с чисто MBTf
const MBTf THRESHOLD_EPS = 0.0000001; //10^(-7) точность гранична€ дл€ MBTi и MBTf
const MBTi MBTi_EXACT_EPS = 0.00001; //10^(-5) наиболее низкий EPS дл€ MBTi

const MBTf MBTf_MIN = -MaxSingle;
const MBTf MBTf_MAX = MaxSingle;
const int MaxDivisionCount = 360; // макс число разбиений при поиске области определени€ пол€рной функции
const MBTi Accuracy_Booster = 1/100;

MBTi COMMONAL_API LengthFromPointToLine(const TIntVec& Point,const TIntVec& Line1,const TIntVec& Line2);


bool COMMONAL_API CrossCircleAndLine(
                    const TIntVec& C1,MBTi R1,
                    const TIntVec& P1,const TIntVec& P2,
                    TMDelTList<TIntVec>& CPS,bool Strongly,MBTi USEEPS);

bool COMMONAL_API CrossCircles(
                    const TIntVec& C1,MBTi R1,
                    const TIntVec& C2,MBTi R2,
                    TMDelTList<TIntVec>& CPS,MBTi USEEPS);


bool COMMONAL_API CircleByThreePoints(
                    const TIntVec& P1,
                    const TIntVec& P2,
                    const TIntVec& P3,
                    TIntVec& CP,
                    MBTi& R);

bool COMMONAL_API CircleByTwoPointsAndAngle(
                    const TIntVec& RotSrc,
                    const TIntVec& RotDst,
                    MBTi Angle,
                    TIntVec& CP,
                    MBTi& R);


TIntVec COMMONAL_API GetThirdPoint(
                    const TIntVec& RotSrc,
                    const TIntVec& RotDst,
                    MBTi Angle
                    );

bool COMMONAL_API ConsistsNotStrictly(const TIntVec& P,const TIntVec& A,const TIntVec& B,MBTi USEEPS);
                        
bool COMMONAL_API CrossPointStrictly(
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& B0,
                        const TIntVec& B1,
                        TIntVec& CP,
                        MBTi USEEPS);


bool COMMONAL_API CrossPointNotStrictly(
                        const TIntVec& A0,
                        const TIntVec& A1,
                        const TIntVec& B0,
                        const TIntVec& B1,
                        TIntVec& CP,
                        MBTi USEEPS);

class TGeomObject;
void COMMONAL_API ListToGeomObject(TGeomObject* GO,const TMDelTList<TIntVec>& Pnts,bool Solid);

class COMMONAL_API TMFunction {
private:
public:
    TMFunction(){};
    ~TMFunction(){};
    virtual TIntVec CalcPolarValue(MBTf arg)const {throw EMyException("<TMFunction::CalcPolarValue>: нет реализации.");};
    virtual MBTf CalcValue(MBTf arg) const {throw EMyException("<TMFunction::CalcPolarValue>: нет реализации.");};
    virtual void ToGeomObject(TGeomObject* GO,MBTi a0,MBTi a1,int Count);
};

class COMMONAL_API TPascalLimacon : public TMFunction
{
public:
    TPascalLimacon(){Index=0;};
    ~TPascalLimacon(){};
    mutable MBTf l;
    mutable MBTf a;
    //--------------------
    mutable MBTf y;
    mutable TIntVec OffSet;
    mutable int Index;
    MBTf CalcValue(MBTf arg) const;
    MBTf CalcSignValue(MBTf arg) const;
    TIntVec CalcPolarValue(MBTf arg)const;
    MBTf CalcValueSimple(MBTf arg) const;
    TIntVec CalcPolarValueSimple(MBTf arg) const;
    TIntVec CalcPolarValueSimpleRotated(MBTf arg) const;
    //              .P1
//             /
//           /
//         /
//       / Angle
//    ./---------------.P0
    void Initialize(const TIntVec& P0,const TIntVec& P1,MBTi Angle,const TIntVec& PositionPoint);
    bool CrossingWithLine(const TIntVec& P0,const TIntVec& P1,TMDelTList<TIntVec>& Roots,MBTf USEEPS = MBTi_EXACT_EPS) const;
    bool CrossingWithCircle(const TIntVec& Center,MBTi Radius,TMDelTList<TIntVec>& Roots,MBTf USEEPS = MBTi_EXACT_EPS) const;
    TIntVec FindClosestPoint(const TIntVec& P0) const;
    virtual void ToGeomObject_All(TGeomObject* GO,int Count);
    bool FindDefinitionInterval(MBTf& a0,MBTf& a1,int Count,MBTf EPS);
    MBTf DetectDefinitionEdge(MBTf a0,MBTf a1,MBTf EPS);
    MBTf DetectDefinitionEdgeSign(MBTf a0,MBTf a1,MBTf EPS);
    bool ValidateDefinitionInterval(MBTf& a0,MBTf& a1,MBTf EPS);
    bool CrossingWithLimacon(TPascalLimacon& Lim,TMDelTList<TIntVec>& Roots,MBTf USEEPS = MBTi_EXACT_EPS) const;
};

class COMMONAL_API TPolarLine : public TMFunction {
public:
    TPolarLine(){};
    ~TPolarLine(){};
    MBTf a;
    MBTf b;
    MBTf c;
    MBTf CalcValue(MBTf arg) const;
    TIntVec CalcPolarValue(MBTf arg)const;
    void Initialize(const TIntVec& P1,const TIntVec& P2);
};

class COMMONAL_API TPolarCircle : public TMFunction {
public:
    TPolarCircle(){Index=0;};
    ~TPolarCircle(){};
    int Index;
    MBTf Radius;
    TIntVec Center;
    MBTf CalcValue(MBTf arg) const;
    TIntVec CalcPolarValue(MBTf arg)const;
    MBTf MoveToEdge(MBTf arg) const;
    MBTf CalcSqrDet(MBTf arg) const;
    MBTf CalcSqrDet(const long double& Sin_a,const long double& Cos_a) const;
};

template <class FLOATTYPE>
void AddRoot(TMDelTList<FLOATTYPE>& Roots,FLOATTYPE Root,FLOATTYPE EPS)
{
    for (int i=0;i<Roots.Count;i++)
        if ( Roots[i] == Root )
            return;
    Roots.Add( new FLOATTYPE(Root) );
}

#endif
