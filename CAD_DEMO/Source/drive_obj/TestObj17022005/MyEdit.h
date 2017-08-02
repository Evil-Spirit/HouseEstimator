//---------------------------------------------------------------------------
#ifndef MyEditH
#define MyEditH
                               
#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
//---------------------------------------------------------------------------
class TMyView;
class TRedCut;
//точка
class PACKAGE TRedPoint : public TMyObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TRedPoint();
    virtual ~TRedPoint(){};
    TChangeVec Point;
    TMTList<TRedCut> Cuts;
};

extern PACKAGE TClassNode* TRedPoint::StaticType;

//отрезок
class PACKAGE TRedCut : public TMyObject{
    TRedPoint* FSrc;
    TRedPoint* FDst;
    void SetSrc(TRedPoint* Value);
    void SetDst(TRedPoint* Value);
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TRedCut();
    virtual ~TRedCut();
    __property TRedPoint* Src = {read = FSrc,write = SetSrc};
    __property TRedPoint* Dst = {read = FDst,write = SetDst};
};

extern PACKAGE TClassNode* TRedCut::StaticType;

class PACKAGE TMyFigure : public TMyObject{
protected:
    TVisPrimitiveObj* VCO;
    virtual void ProcessCreateView();
    bool NeedCreateView;
    virtual long int GetCutsCount() const {return 0;};
    virtual long int GetPointsCount() const {return 0;};
    TColor FColor;
    int FLineWidth;
    void SetColor(TColor AColor);
    void SetLineWidth(int ALineWidth);
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    __property TColor Color = {read = FColor,write = SetColor};
    __property int LineWidth = {read = FLineWidth,write = SetLineWidth};
    TChangeVec RotateCenter;
    void CreateRC();
    void CreateBBox();
    TIntVec BBoxLU, BBoxRD;
    bool Additional;
    bool Fixid;
    TMyFigure();
    virtual ~TMyFigure();

    virtual int FindPoint(const TIntVec& V) const;
    virtual bool Snap(const TIntVec &Point, TIntVec& SnapPoint, int& CutIndex, MBTi CEPS, bool Infinity) const;

    __property int PointsCount = {read = GetPointsCount};
//    __property TRedPoint& Points[int i] = {read = GetPoint};
    __property int CutsCount = {read = GetCutsCount};
//    __property TRedCut& Cuts[int i] = {read = GetCut};

    virtual TRedCut& GetCut(int Index);
    virtual const TRedCut& GetCut(int Index) const;
    virtual TRedPoint& GetPoint(int Index);
    virtual const TRedPoint& GetPoint(int Index) const;

    virtual void Render(TMyView* aView);
    //virtual void CreateView();
    virtual int IndexOfPoint(TRedPoint* Point) const;
    virtual int IndexOfCut(TRedCut* Cut) const;
    virtual void AboutToChange(void* Sender);
};

extern PACKAGE TClassNode* TMyFigure::StaticType;

class PACKAGE TCustomFigure : public TMyFigure{
protected:
    TMDelTList<TRedPoint> PNTS;
    TMDelTList<TRedCut> CUTS;
    void ProcessDelPoint(TRedPoint* P);
    void CutsToIndices(TMDelTList<int>& CutPointIndices) const;
    void IndicesToCuts(TMDelTList<int>& CutPointIndices);
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TCustomFigure();
    virtual ~TCustomFigure(){};

    void AddCut(const TIntVec& P1,const TIntVec& P2);
    int AddPoint(MBTi x, MBTi y, MBTi z);
    int AddPoint(const TIntVec& Vec);
    void DelPoint(int Index);
    void DelCut(int Index);

//    void SetPointCoordinate(int Index, MBTi x, MBTi y, MBTi z);
//    virtual bool Snap(const TIntVec &Point, TIntVec* SnapPoint, int* CutIndex, const MBTi CEPS, bool Infinity);

    virtual long int GetCutsCount() const;
    virtual long int GetPointsCount() const;
    virtual TRedCut& GetCut(int Index);
    virtual TRedPoint& GetPoint(int Index);
    virtual const TRedCut& GetCut(int Index) const;
    virtual const TRedPoint& GetPoint(int Index) const;
    virtual int IndexOfPoint(TRedPoint* Point) const;
    virtual int IndexOfCut(TRedCut* Cut) const;


    //сохранение и загрузка в текстовый файл
    virtual void SaveData(FILE *F) const;
    virtual void LoadData(FILE *F);
    //запись и чтение в поток
    virtual void WriteData(TMemoryStream *MS) const;
    virtual void ReadData(TMemoryStream *MS);
    //присвоение
    virtual void Assign(TMyObject* MO);
};

extern PACKAGE TClassNode* TCustomFigure::StaticType;

class PACKAGE TInfinityLine : public TMyFigure{
private:
    TRedPoint RedPoint[2];
    TRedCut RedCut;
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TInfinityLine();
    virtual ~TInfinityLine(){};
    void Render(TMyView* aView);
    virtual long int GetCutsCount() const {return 1;};
    virtual long int GetPointsCount() const {return 2;};
    virtual TRedCut& GetCut(int Index);
    virtual TRedPoint& GetPoint(int Index);

    virtual const TRedCut& GetCut(int Index) const;
    virtual const TRedPoint& GetPoint(int Index) const;

    virtual void LoadData(FILE *F);
    virtual void ReadData(TMemoryStream *MS);
    virtual void Assign(TMyObject* MO);
//    virtual void ProcessCreateView();
};

extern PACKAGE TClassNode* TInfinityLine::StaticType;

struct TEditorColors {
    TColor Additional;
    TColor MyFigures;
    TColor Selected;
    TColor Fixid;
    TColor BackGround;
};

struct TEditorLineWidth{
    int Additional;
    int MyFigures;
    int Selected;
    int Fixid;
};

class PACKAGE TEditorAttributes : public TMyObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TEditorAttributes();
    virtual ~TEditorAttributes(){};
    bool Snap;
    MBTi SnapValue;
    int SnapValuePix;//pixels
    bool AdditionalFiguresSnap;
    bool SnapMyFigures;
//&&&    bool SnapCrossPoint;
    TEditorColors Colors;
    TEditorLineWidth LinesWidth;
};

extern PACKAGE TClassNode* TEditorAttributes::StaticType;

struct TGridColors{
    TColor OSI;
    TColor MIN;
    TColor MAX;
};

struct TGridLineWidth{
    int OSI;
    int MIN;
    int MAX;
};

class PACKAGE TGridAttributes : public TMyObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TGridAttributes();
    virtual ~TGridAttributes(){};
    bool Snap;
    MBTi Step;
    MBTi ZoomStep;
    int SwitchEpsilon;
    int Multiplier;
    int SnapStep;
    int ZoomLimit;
    TGridColors Colors;
    TGridLineWidth LinesWidth;
    bool Visible;
    bool ChangeMinToMax, ChangeMaxToMin;
    bool ReBuild;
    bool Minimal;
};

extern PACKAGE TClassNode* TGridAttributes::StaticType;

class PACKAGE TGrid : public TMyObject{
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    TGrid();
    virtual ~TGrid();
    int Precision;
    TVisPrimitiveObj* VCO_MIN;
    TVisPrimitiveObj* VCO_MAX;
    TVisPrimitiveObj* VCO_OSI;
    TGridAttributes Attr;
    TIntVec Snap(const TIntVec &Point) const;
    void Create(const TIntVec &a, const TIntVec &b, MBTi dist, MBTi DepthLevel);
    void Render(TMyView* aView);
};

extern PACKAGE TClassNode* TGrid::StaticType;

class TSelected{
public:
    TMyFigure* Figure;
    TMDelTList<int> CutIndices;
    int FindCutIndex(int Index) const;
};

class TSelection{
private:
public:
    TMTList<TSelected> Figures;
    int FindFigure(TMyFigure* MF) const;
    bool FindCutAndFigureIndices(TMyFigure* MF, const int& FigureCutIndex, int& FigureIndex, int& SelectedCutIndex);    bool FindCutAndFigureIndex(TMyFigure* MF, int& FigureIndex, int& CutIndex) const;
};

/*class TLinesAndCuts{
public:
    TLinesAndCuts(TIntVec P1, TIntVec P2, bool Inf, bool _Additional)
    {
        Point1 = P1;
        Point2 = P2;
        Infinity = Inf;
        Additional = _Additional;
    };
    ~TLinesAndCuts(){};
    TIntVec Point1;
    TIntVec Point2;
    bool Infinity;
    bool Additional;
};*/

class TDepthLevels{
public:
    TDepthLevels();
    TDepthLevels(MBTi _Grid, MBTi _Fixid, MBTi _Additional, MBTi _Figures, MBTi _Selected);
    ~TDepthLevels(){};
    MBTi Grid;
    MBTi Fixid;
    MBTi Additional;
    MBTi Figures;
    MBTi Selected;
};

enum TCameraOperation { coVERTICAL_TRANSLATION = 0,
                        coHORISONTAL_TRANSLATION = 1,
                        coLA_VERTICAL_TRANSLATION = 2,
                        coZ_POSITION_ROTATION = 3,
                        coZ_LOOKAT_ROTATION = 4,
                        coXY_POSITION_ROTATION = 5,
                        coXY_LOOKAT_ROTATION = 6,
                        coLA_DEPTH_TRANSLATION = 7
                        };

class TCameraEngine {
private:
    void Vec2RotateZ(TVisVector& A, const TIntVec& B, MBTi Parameter);
    void Vec2RotateXY(TVisVector& A, const TIntVec& B, MBTi Parameter);
public:
    TIntVec A, PlaneN;
    bool UsePlane;
    TCameraEngine();
    ~TCameraEngine();
    void Toggle(TMyView* aView);
    void Operation(TMyView* aView, TCameraOperation CO, const TIntVec& MouseObject, MBTi Parameter);
};
#endif
