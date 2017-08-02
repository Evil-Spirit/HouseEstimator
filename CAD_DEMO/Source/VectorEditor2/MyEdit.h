//---------------------------------------------------------------------------
#ifndef MyEditH
#define MyEditH

#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class T2DGObject;
class TEditor2D;

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

class TEditorAttributes : public TMyObject{
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

TClassNode* TEditorAttributes::StaticType = NULL;

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

class TGridAttributes : public TMyObject{
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
};

TClassNode* TGridAttributes::StaticType = NULL;

class TGrid : public TMyObject{
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
    void Create(const TIntVec &a, const TIntVec &b, MBTi DepthLevel);
    void Render(TEditor2D* aView);
};

TClassNode* TGrid::StaticType = NULL;

class TSelected{
public:
    T2DGObject* Figure;
    TMDelTList<int> CutIndices;
    int FindCutIndex(int Index) const;
};

class TSelection{
private:
public:
    TMTList<TSelected> Figures;
    int FindFigure(T2DGObject* MF) const;
    bool FindCutAndFigureIndices(T2DGObject* MF, const int& FigureCutIndex, int& FigureIndex, int& SelectedCutIndex);    bool FindCutAndFigureIndex(T2DGObject* MF, int& FigureIndex, int& CutIndex) const;
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
#endif
