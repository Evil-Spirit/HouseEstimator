//---------------------------------------------------------------------------

#ifndef EditorXDToolVH
#define EditorXDToolVH
#include "BaseToolV.h"
//---------------------------------------------------------------------------

class TEditor2D;

class PACKAGE TEditorXDTool : public TBaseTool{
private:
    TEditor2D* getEditorXD();
    void setEditorXD(TEditor2D* EXD);
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    __property TEditor2D* EditorXD = {read = getEditorXD, write = setEditorXD};
};

extern PACKAGE TClassNode* TEditorXDTool::StaticType;

class PACKAGE TMyEditorControls : public TMyControls{
private:
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    void MouseMove(void* Sender, TShiftState Shift, const TIntVec& CursorPosition);
    void MouseDown(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition);
    void MouseUp(void* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition);
    void KeyDown(void* Sender, WORD &Key, TShiftState Shift);
    void KeyUp(void* Sender, WORD &Key, TShiftState Shift);
};

extern PACKAGE TClassNode* TMyEditorControls::StaticType;

#endif
