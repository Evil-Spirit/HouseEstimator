// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "Usefuls.h"
#include "MyTemplates.h"
#include "MTL.h"
#include "compat/vcl_qt.h"

#include "ToolBarU.h"
#include "DialogEditorToolsU.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"

TToolBarForm *ToolBarF = NULL;
//---------------------------------------------------------------------------
 TToolBarForm::TToolBarForm(TComponent* Owner) : TForm(Owner)
{
    Dialog = NULL;
//    ToolBarF = this;
    Hide();
}

//---------------------------------------------------------------------------
void TToolBarForm::SetToolBar()
{
/*    for(int j = cnButton; j <= cnPageControl; j++)
    {
        DialogTools.Matrix.Add(new TMDelTList<TBaseTool>());
        TCreateTool* Tool = new TCreateTool( (TClassId)j );
        Tool->DialogEdit = Dialog;
        DialogTools.Matrix[j-1].Add( Tool );
        DialogTools.ActiveIndices.Add(new int(0));
    }
    DialogTools.Matrix.Add(new TMDelTList<TBaseTool>());
    TSelectTool* sTool = new TSelectTool( (TClassId)cnMouse );
    sTool->DialogEdit = Dialog;
    DialogTools.Matrix[cnMouse-1].Add( sTool );
    DialogTools.ActiveIndices.Add(new int(0));
    DialogTools.ActiveList=(TClassId)cnMouse-1;
    ToolBar->Images = Dialog->ImageList;
    for (int i = 0; i < DialogTools.Matrix.Count; i++)
    {
        TAction* Action = new TAction(Dialog->AL);
        Action->AutoCheck = true;
        Action->ActionList = Dialog->AL;
        Action->Tag = i;
        Action->OnExecute = Dialog->ActionExecute;
        TToolButton* TB = new TToolButton(this);
        TB->ImageIndex = DialogTools.Matrix[i][0].ImageId;
        TB->Style = tbsButton;
        TB->Action = Action;
        TB->Parent = ToolBar;
    }
    SDELAT" ZAOTMyDialogEdit *MyDialogEdit = NULL;POLNENIE KAK V OI   */
    Show();
}

//---------------------------------------------------------------------------
