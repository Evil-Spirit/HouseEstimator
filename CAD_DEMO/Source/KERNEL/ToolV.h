// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef ToolVH
#define ToolVH
#include "MetaClasses.h"
//---------------------------------------------------------------------------
class TMyTool : public TMetaNode {
public:
    //----------------------------------
    static TClassNode* StaticType;
    static TMyObject* CreateFunction();
    //----------------------------------
    TBindedBaseTool BindedTool;
    TMyTool();
    virtual ~TMyTool();
    virtual void Edit(TComponent *Owner,TWinControl *Parent,void *Data);
};

#endif
