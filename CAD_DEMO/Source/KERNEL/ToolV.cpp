// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------


#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "ToolV.h"

//---------------------------------------------------------------------------

TClassNode* TMyTool::StaticType = NULL;

TMyObject* TMyTool::CreateFunction()
{
    return new TMyTool;
}

const AnsiString aBindedTool = AnsiString("BindedTool");
TMyTool::TMyTool()
{
    RegisterNewClass< TMetaNode, TMyTool >(this,false,&CreateFunction);
    RegisterField(&BindedTool,&aBindedTool,mtMyObject);
}

TMyTool::~TMyTool()
{

}

void TMyTool::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    new     
}

