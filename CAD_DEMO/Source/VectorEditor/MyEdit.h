//---------------------------------------------------------------------------
#ifndef MyEditH
#define MyEditH

#include "VisPrimitiveObj.hpp"
#include "VisView.hpp"
#include "BaseToolV.h"
//---------------------------------------------------------------------------
class TMyView;
class T2DGObject;

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

class TG2DLink;
class TGPoint;
class TGCut;
class TSelected{
public:
    T2DGObject* Figure;
    TMTList< TGCut > SCuts;     
    TMTList< TGPoint > SPoints;
    TMTList< TG2DLink > SLinks;     
    int FindCutIndex(TGCut* Cut) const;
};

class TSelection{
private:
public:
    TMTList<TSelected> Figures;
    int FindFigure(T2DGObject* MF) const;
    bool FindCutAndFigureIndices(T2DGObject* MF, TGCut* Cut, int& FigureIndex, int& SelectedCutIndex);    bool FindCutAndFigureIndex(T2DGObject* MF, int& FigureIndex, int& CutIndex) const;
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
