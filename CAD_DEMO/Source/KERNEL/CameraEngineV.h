//---------------------------------------------------------------------------

#ifndef CameraEngineVH
#define CameraEngineVH
#include "VisCam.hpp"
//#include "MyControls.h"

//---------------------------------------------------------------------------


enum TCameraOperation { coVERTICAL_TRANSLATION = 0,
                        coHORISONTAL_TRANSLATION = 1,
                        coLA_VERTICAL_TRANSLATION = 2,
                        coZ_POSITION_ROTATION = 3,
                        coZ_LOOKAT_ROTATION = 4,
                        coXY_POSITION_ROTATION = 5,
                        coXY_LOOKAT_ROTATION = 6,
                        coLA_DEPTH_TRANSLATION = 7,
                        coLA_DEPTH_TRANSLATION_NO_ORIENT = 8
                        };

class COMMONAL_API TCameraEngine {
private:
    void Vec2RotateZ(TVisVector& A, const TIntVec& B, MBTi Parameter);
    void Vec2RotateXY(TVisVector& A, const TIntVec& B, MBTi Parameter);
public:
    TIntVec A, PlaneN;
    bool UsePlane;
    TCameraEngine();
    ~TCameraEngine();
    void Toggle(TMDI3D* aView);
    void Operation(TMDI3D* aView, TCameraOperation CO, MBTi Parameter);
    void ViewAll(TVisCamera *Camera, bool No_Platforms_And_FirstFloorElem = true);
};

/*class COMMONAL_API TInterFace{
private:

    TShiftState Shift;

    TElement *FElement;
    void SetElement(TElement *El);

    TMetaMyMode* GetMetaMyMode();
    TVisView *GetVisView();
public:
    bool FAdvancedTexturing;
    bool FPrevAdvancedTexturing;
    void SetAdvancedTexturing(bool Value);
    TDriver Driver;
    TCameraEngine CameraEngine;
    __property TMetaMyMode* Mode = {read = GetMetaMyMode};
    void CustomRender();
    void InvalidateView();
    //--------------------------------
    __property bool AdvancedTexturing = {read = FAdvancedTexturing,write = SetAdvancedTexturing};
    __property bool PrevAdvancedTexturing = {read = FPrevAdvancedTexturing};


    __property TVisView *VisView = {read = GetVisView};
    TInterFace();
    virtual ~TInterFace();
    void FirstInit(TMDI3D *_3D,TMainTree *newMT);
    TMainTree *BIF_MT;
    TMDI3D *MDI3D;
};

extern COMMONAL_API TInterFace *BIF;  */


#endif

