//---------------------------------------------------------------------------

#ifndef MyControlsH
#define MyControlsH
#include "ElementV.h"
#include "VisCam.hpp"
//---------------------------------------------------------------------------
TIntVec COMMONAL_API MAPAccord(const TIntVec& Res,const TIntVec& Shift ,TElement *FEL);
void COMMONAL_API Pos_Accord( TIntVec& Position, TMetaLink *ML, TElement *EL0, TElement *EL1, bool Point_1_HI=false );
enum TSelectMode {smSyngle = 0, smMultiple=1};





enum TUserActions  {    uaDown=0,
                        uaUp=1,
                        uaMove=2,
                        uaUpMove=3,
                        uaNew=4};

enum TIFOperations {    ioNone=0,
                        ioMove=1,
                        ioRotate=2,
                        ioScale=3,
                        ioDraw=4,
                        ioConstruct=5,
                        ioMoveAutoAlign = 6,
                        ioWallConstruct=7,
                        ioMoveDraw=8 };

const AnsiString IFOperationsStr[9] = { AnsiString("None"),
                                        AnsiString("Move"),
                                        AnsiString("RotateZ"),
                                        AnsiString("Scale"),
                                        AnsiString("Draw"),
                                        AnsiString("Construct"),
                                        AnsiString("MoveAndAutoAlign"),
                                        AnsiString("MoveAndDraw"),
                                        AnsiString("WallConstruct")
                                          };

enum TScaleType {   stX = 100,
                    stY=10,
                    stZ = 1,
                    stXY = 110,
                    stYZ = 11,
                    stXZ = 101,
                    stXYZ = 111 };
                    
enum TDrawType {    dtSyngle=0, dtMultiple=1    };
enum TMoveType {    mtHorisontal=0, mtVertical=1   };

class COMMONAL_API TSYNGLEACTION
{
    public:
    TSYNGLEACTION(){};
    virtual ~TSYNGLEACTION(){};
    int ImageIndex;
    int EnumIndex;
    AnsiString Description;

};

class COMMONAL_API TACTIONTYPE
{
    public:
    TACTIONTYPE(){Actions = new TMDelTList<TSYNGLEACTION>();};
    virtual ~TACTIONTYPE(){delete Actions;};
    TToolButton *TB;
    int EnumIndex;
    int DefaultEnum;
    int DefaultImageIndex;
    AnsiString Description;
    bool RightButtonTerminate;
    bool MoveFirst;
    TMDelTList<TSYNGLEACTION> *Actions;
};

class COMMONAL_API TAllActions {
public:
    TMDelTList< TACTIONTYPE > *ATS;
    TAllActions(){ATS = new TMDelTList< TACTIONTYPE >();};
    virtual ~TAllActions(){delete ATS;};
    int DefaultEnum;
    TACTIONTYPE* FindByID(TIFOperations OP);
    void FillMenuItem(TMenuItem *MI,TNotifyEvent OnClick1,TNotifyEvent OnClick2);
};

extern COMMONAL_API TAllActions *ALLACTIONS;
void COMMONAL_API InitActions();
void COMMONAL_API FreeActions();



class COMMONAL_API TMyControls {
protected:
    virtual void OnStart(){};
    virtual void OnStop(){};
    virtual TElement* OnReStart(){Stop();return NULL;};
    virtual void OnContinue(){};
    virtual bool OnCustomRender(const TPoint& P){return true; };
    virtual void OnSetMode(int newMode){};
    TIntVec A;
    TIntVec B;
    TIntVec A1;
    TIntVec B1;
    int FMode;
    void SetMode(int newMode){FMode = newMode; OnSetMode(newMode);}
public:
    virtual bool AllowMultiple(){return false;};
    virtual bool CorrectSettings(TSelectMode SM,TShiftState SS){return false;};
    __property int Mode = {read = FMode,write = SetMode};
    virtual bool Object_OK(){return false;};
    TMyControls();
    virtual ~TMyControls(){};
    void Start();
    void Stop();
    void Continue();
    TElement *ReStart();
    virtual void Toggle();
    void CustomRender();
    bool FirstRender;
    bool Active;
    int Render;
    TIntVec OldSize;
    TIntVec OldPos;
    TIntVec OldRot;
    TElement *Head;
    TDynamicLink *STEPLINK;
    TIntVec Pl0;
    TIntVec Normal;
};

class COMMONAL_API TMover : public TMyControls {
private:
    TIntVec StartPoint;
    virtual void OnStart();
    virtual void OnStop();
    virtual void OnContinue();
    virtual bool OnCustomRender(const TPoint& P);
public:
    bool CorrectSettings(TSelectMode SM,TShiftState SS);
    TMover();
    virtual ~TMover(){};
    virtual bool Object_OK(){return true;};
};

class COMMONAL_API TRotater : public TMyControls {
private:
    TPoint StartPoint;
    TIntVec StartAngle;
    virtual void OnStart();
    virtual void OnStop();
    virtual void OnContinue();
    virtual bool OnCustomRender(const TPoint& P){return true;};
public:
    TRotater(){};
    virtual ~TRotater(){};
    virtual bool Object_OK(){return true;};
};

class COMMONAL_API TScaler : public TMyControls {
private:
    virtual void OnStart();
    virtual void OnStop();
    virtual void OnContinue();
    virtual bool OnCustomRender(const TPoint& P);
    virtual void OnSetMode(int newMode);
    TIntVec StartPoint;
    TIntVec Direction;
    TIntVec _Direction;
    TVisMathVector _GetPoint;
public:
    TScaler();
    virtual ~TScaler(){};
    virtual bool Object_OK(){return true;};
};

class COMMONAL_API TDrawer : public TMyControls {
private:
    virtual void OnStart();
    virtual void OnStop();
    virtual void OnContinue();
    virtual TElement* OnReStart();
    virtual bool OnCustomRender(const TPoint& P);
    TVisMathVector _GetPoint;
public:
    TMDelTList<TIntVec> *CPoints;
    bool AllowMultiple();
    bool Restart;
    TDrawer();
    virtual ~TDrawer();
    virtual bool Object_OK(){return true;};
};

class COMMONAL_API TConstructor: public TMyControls {
private:
public:
    virtual void OnStart();
    virtual void OnStop();
    virtual void OnContinue();
    TVisMathVector _GetPoint;
    virtual TElement* OnReStart();
    virtual bool OnCustomRender(const TPoint& P);
    TIntVec CurVec;
public:
    bool AllowMultiple();
    TPolygon POL;
    TMTList<TMetaElement> *MEs;
    TMDelTList<TIntVec> Steps;
    TConstructor();
    virtual ~TConstructor();
    TMTList<TVisPrimitiveObj>* AllArrows;
    TVisPrimitiveObj* CurArrow;
    MBTi StartZ;
    virtual bool Object_OK();
};

class COMMONAL_API TWallConstructor: public TMyControls {
private:
public:
    virtual void OnStart();
    virtual void OnStop();
    virtual void OnContinue();
    TVisMathVector _GetPoint;
    virtual TElement* OnReStart();
    virtual bool OnCustomRender(const TPoint& P);
    TIntVec CurVec;
    bool Restart;
public:
    bool AllowMultiple();
    TMTList<TMetaElement> *MEs;
    TMDelTList<TIntVec> Steps;
    TMDelTList<TIntVec> PNTS;
    TWallConstructor();
    virtual ~TWallConstructor();
    TMTList<TVisPrimitiveObj>* AllArrows;
    TVisPrimitiveObj* CurArrow;
    MBTi StartZ;
    virtual bool Object_OK();
};

class COMMONAL_API TMoverAA : public TMyControls {
private:
    TIntVec StartPoint;
    double CurrentDepth;
    TVisMathVector _GetPoint;
    TVisMathVector _GetWinTo3D;
    TVisMathVector _GetWinFrom3D;
    bool boolGetPoint;
    double ZShift;
    virtual void OnStart();
    virtual void OnStop();
    virtual void OnContinue();
    virtual bool OnCustomRender(const TPoint& P);
public:
    virtual bool Object_OK(){return true;};
    bool CorrectSettings(TSelectMode SM,TShiftState SS);
    TMoverAA();
    virtual ~TMoverAA(){};
};


class COMMONAL_API TCameraEngine: public TMyControls {
private:
    TVisCamera *_Camera;
    TVisPerspectiveCamera *Perspective;
    TVisOrthographicCamera *Orthographic;
    virtual void OnStart(){};
    virtual void OnStop(){};
    virtual void OnContinue(){};
    void Init(  TVisPerspectiveCamera *_Perspective,
                TVisOrthographicCamera *_Orthographic    );
public:
    TCameraEngine(){};
    virtual ~TCameraEngine(){};
    void ViewAll(TVisCamera *Camera);
};

#endif
