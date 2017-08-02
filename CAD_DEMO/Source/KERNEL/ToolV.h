//---------------------------------------------------------------------------

#ifndef ToolVH
#define ToolVH
#include "MetaClasses.h"
//---------------------------------------------------------------------------
class TMyTool : public TMetaNode {
public:
    //----------------------------------
    static TClassNode* StaticType;
    TMyObject* CreateFunction();
    //----------------------------------
    TBindedBaseTool BindedTool;
    TMyTool();
    virtual ~TMyTool();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};
extern COMMONAL_API TClassNode* TMyTool::StaticType;

#endif
