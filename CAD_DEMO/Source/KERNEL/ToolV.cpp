//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "ToolV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
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

