// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef EditorXDToolVH
#define EditorXDToolVH
#include "BaseToolV.h"
//---------------------------------------------------------------------------

class TEditor2D;

class  TEditorXDTool : public TBaseTool{
private:
    TEditor2D* getEditorXD();
    void setEditorXD(TEditor2D* EXD);
public:
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    // __property TEditor2D* EditorXD {read=getEditorXD, write=setEditorXD}; // [manual migration needed]
};

extern  TClassNode* TEditorXDTool::StaticType;

class  TMyEditorControls : public TMyControls{
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

extern  TClassNode* TMyEditorControls::StaticType;

#endif
