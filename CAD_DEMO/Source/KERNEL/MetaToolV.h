//---------------------------------------------------------------------------

#ifndef MetaToolVH
#define MetaToolVH
#include "MetaClasses.h"
#include "MainToolsV.h"
//---------------------------------------------------------------------------
class TBindedBaseTool;
const iiMetaTool = 31;
const iiMetaTools = 30;
class COMMONAL_API TMetaTool : public TMetaNode {
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TBindedBaseTool& BindedTool;
    TMetaTool();
    TMetaTool(TBindedBaseTool& aBindedTool);
    virtual ~TMetaTool();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
extern COMMONAL_API TClassNode* TMetaTool::StaticType;

class COMMONAL_API TToolControlList {
    int FActiveIndex;
    void Restart();
    void SetActiveIndex(int aValue);
public:
    TMTList<TMetaTool> Tools;
    __property int ActiveIndex = {read = FActiveIndex,write = SetActiveIndex};
    //----------------------------------
    TToolControlList();
    virtual ~TToolControlList();
    void CustomMouseMove(TMDI3D* Sender, TShiftState Shift, const TIntVec& CursorPosition);
    void CustomMouseDown(TMDI3D* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition);
    void CustomMouseUp(TMDI3D* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition);
    void CustomKeyDown(TMDI3D* Sender, WORD &Key, TShiftState Shift);
    void CustomKeyUp(TMDI3D* Sender, WORD &Key, TShiftState Shift);
    void CustomExit(TMDI3D* Sender);
    void CustomRender(TMDI3D* Sender);
    AnsiString CustomHint(TMDI3D* Sender);
};

#endif
