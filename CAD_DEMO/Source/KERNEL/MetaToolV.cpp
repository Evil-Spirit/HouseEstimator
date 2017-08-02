//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaToolEditV.h"
#include "IntExplorerV.h"
#include "MetaToolV.h"
#include "AUIV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TClassNode* TMetaTool::StaticType = NULL;

TMyObject* TMetaTool::CreateFunction()
{
    return new TMetaTool;
}

const AnsiString aBindedTool = AnsiString("BindedTool");
TMetaTool::TMetaTool()
    :BindedTool( *(new TBindedBaseTool) )
{
    RegisterNewClass< TMetaNode, TMetaTool >(this,false,&CreateFunction);
    RegisterField(&BindedTool,&aBindedTool,mtMyObject);
    ImageIndex = iiMetaTool;

    if ( IntExplorer && IntExplorer->ControlList.Tools.IndexOf( this ) ==-1 )
        IntExplorer->ControlList.Tools.Add( this );
}

TMetaTool::TMetaTool(TBindedBaseTool& _BindedTool)
    :BindedTool( _BindedTool )
{
    RegisterNewClass< TMetaNode, TMetaTool >(this,false,&CreateFunction);
    RegisterField(&BindedTool,&aBindedTool,mtMyObject);
    ImageIndex = iiMetaTool;

    if ( IntExplorer && IntExplorer->ControlList.Tools.IndexOf( this ) ==-1 )
        IntExplorer->ControlList.Tools.Add( this );
}


TMetaTool::~TMetaTool()
{
    if (IntExplorer)
        ( IntExplorer->ControlList.Tools.Remove( this ));
    delete &(BindedTool);
}

void TMetaTool::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    new TMDIMetaToolEdit(Owner,this);    
}

TToolControlList::TToolControlList()
{
    FActiveIndex = -1;
}

TToolControlList::~TToolControlList()
{
    
}

void TToolControlList::SetActiveIndex(int aValue)
{
    if (ActiveIndex != aValue)
    {
        if ( (ActiveIndex >= 0) && (ActiveIndex < Tools.Count) )
            Tools[FActiveIndex].BindedTool.Exit(AUI.ActiveView);
        FActiveIndex = aValue;
    }
}

void TToolControlList::CustomMouseMove(TMDI3D* Sender, TShiftState Shift, const TIntVec& CursorPosition)
{
    if (Sender == AUI.ActiveView)
        Tools[ActiveIndex].BindedTool.MouseMove(Sender,Shift,CursorPosition);
}

void TToolControlList::CustomMouseDown(TMDI3D* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
    if (Sender == AUI.ActiveView)
        Tools[ActiveIndex].BindedTool.MouseDown(Sender,Button,Shift,CursorPosition);
}

void TToolControlList::CustomMouseUp(TMDI3D* Sender, TMouseButton Button, TShiftState Shift, const TIntVec& CursorPosition)
{
    if (Sender == AUI.ActiveView)
        Tools[ActiveIndex].BindedTool.MouseUp(Sender,Button,Shift,CursorPosition);
}

void TToolControlList::CustomKeyDown(TMDI3D* Sender, WORD &Key, TShiftState Shift)
{
    if (Sender == AUI.ActiveView)
        Tools[ActiveIndex].BindedTool.KeyDown(Sender,Key,Shift);
}

void TToolControlList::CustomKeyUp(TMDI3D* Sender, WORD &Key, TShiftState Shift)
{
    if (Sender == AUI.ActiveView)
        Tools[ActiveIndex].BindedTool.KeyUp(Sender,Key,Shift);
}

void TToolControlList::CustomExit(TMDI3D* Sender)
{
    if (Sender == AUI.ActiveView && IntExplorer)
    {
        IntExplorer->SwitchTool(1);
//        MainToolBar->Buttons[0]->Click();
//        MainToolBar->Buttons[0]->Down = true;
    }
//    Tools[FActiveTool].BindedTool.Exit(Sender);
}

void TToolControlList::CustomRender(TMDI3D* Sender)
{
    if (Sender == AUI.ActiveView)
        Tools[ActiveIndex].BindedTool.Render(Sender);
}

AnsiString TToolControlList::CustomHint(TMDI3D* Sender)
{
    if (Sender == AUI.ActiveView)
        return Tools[ActiveIndex].BindedTool.Hint(Sender);
    return AnsiString();
}

void TToolControlList::Restart()
{
    if ( (ActiveIndex >= 0) && (ActiveIndex < Tools.Count) )
        Tools[ActiveIndex].BindedTool.Exit(AUI.ActiveView);
}

