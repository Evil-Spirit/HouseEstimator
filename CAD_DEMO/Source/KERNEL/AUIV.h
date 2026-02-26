// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef AUIVH
#define AUIVH
//---------------------------------------------------------------------------
#include "CameraEngineV.h"

class TMainTree;
class TMDI3D;
class TMDI3DUser;
class TMetaMyMode;
class TWorldAndViews;

typedef void (* TCurrentViewIndexChanged)(TWorldAndViews* WAV);

class COMMONAL_API TWorldAndViews {
private:
    TCurrentViewIndexChanged CurrentViewIndexChanged;
    void SetCurrentViewIndex(int aCurrentViewIndex);
    int FCurrentViewIndex;
public:
    TWorldAndViews( TCurrentViewIndexChanged aCurrentViewIndexChanged );
    TWorldAndViews(){};
    ~TWorldAndViews(){};
    TMainTree* World;
    TMTList<TMDI3D> Views;
    // __property int CurrentViewIndex {read=FCurrentViewIndex, write=SetCurrentViewIndex}; // [manual migration needed]
};

class COMMONAL_API TAdvancedUserInterface {
private:
    TMDelTList<TWorldAndViews>  WAVs;
    int FCurrentWorldIndex;
    void SetCurrentWorldIndex(int aCurrentWorldIndex);
    int FindWorld(TMainTree* aMainTree);
    int FindWorld(TMDI3D* aMDI3D);
    bool UnRegisterInProcess;
    void PreProcessView();
    void AfterProcessView();
    bool ProcessSaveProject(TMainTree* aWorld);
    TMainTree* FActiveWorld;
    TMDI3D* FActiveView;
    void SimpleUnRegister(TMDI3D* aMDI3D);
    void SimpleUnRegister(TMainTree* aMainTree);
    //-----------------------------------
    bool FAdvancedTexturing;
    bool FPrevAdvancedTexturing;
    TMetaMyMode* GetMetaMyMode();
    void SetAdvancedTexturing(bool Value);
    void Changed();
public:
    TAdvancedUserInterface();
    virtual ~TAdvancedUserInterface(){};
    void CurrentViewIndexChanged(TWorldAndViews* WAV);
    //--------------------------------------------------------------------------
    // __property int CurrentWorldIndex {read=FCurrentWorldIndex, write=SetCurrentWorldIndex}; // [manual migration needed]
    // __property TMDI3D* ActiveView {read=FActiveView}; // [manual migration needed]
    // __property TMainTree* ActiveWorld {read=FActiveWorld}; // [manual migration needed]

    void Register(TMainTree* aMainTree);
    void ActivateWorld(TMainTree* aMainTree);
    bool UnRegister(TMainTree* aMainTree);

    void Register(TMainTree* aMainTree,TMDI3D* aMDI3D);
    void ActivateView(TMDI3D* aMDI3D);
    bool UnRegister(TMDI3D* aMDI3D);

    //-----------------------------------
    TCameraEngine CameraEngine;
    void CustomRender();
    void InvalidateView();
    // __property TMetaMyMode* Mode {read=GetMetaMyMode}; // [manual migration needed]
    // __property bool AdvancedTexturing {read=FAdvancedTexturing, write=SetAdvancedTexturing}; // [manual migration needed]
    // __property bool PrevAdvancedTexturing {read=FPrevAdvancedTexturing}; // [manual migration needed]
    //--------------------------------
    bool CheckExplorerVisible();
};

extern COMMONAL_API TAdvancedUserInterface AUI;
#endif
