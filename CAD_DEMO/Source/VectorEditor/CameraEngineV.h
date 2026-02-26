// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef CameraEngineVH
#define CameraEngineVH

#include "Poligon.h"
#include "MetaClasses.h"
#include "ElementV.h"
#include "VisShape.hpp"
#include "MDI3DV.h"
#include "VisAttr.hpp"
#include "Driver.h"
//#include "MyControls.h"

//---------------------------------------------------------------------------
//format  Control, ControlMode

class COMMONAL_API TCameraEngine{
private:
    TVisCamera *_Camera;
    TVisPerspectiveCamera *Perspective;
    TVisOrthographicCamera *Orthographic;
    void Init(  TVisPerspectiveCamera *_Perspective,
                TVisOrthographicCamera *_Orthographic    );
public:
    TCameraEngine(){};
    virtual ~TCameraEngine(){};
    void ViewAll(TVisCamera *Camera);
};

class COMMONAL_API TInterFace{
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
    // __property TMetaMyMode* Mode {read=GetMetaMyMode}; // [manual migration needed]
    void CustomRender();
    void InvalidateView();
    //--------------------------------
    // __property bool AdvancedTexturing {read=FAdvancedTexturing, write=SetAdvancedTexturing}; // [manual migration needed]
    // __property bool PrevAdvancedTexturing {read=FPrevAdvancedTexturing}; // [manual migration needed]


    __property TVisView *VisView = {read = GetVisView};
    TInterFace();
    virtual ~TInterFace();
    void FirstInit(TMDI3D *_3D,TMainTree *newMT);
    TMainTree *BIF_MT;
    TMDI3D *MDI3D;
};

extern COMMONAL_API TInterFace *BIF;


#endif

