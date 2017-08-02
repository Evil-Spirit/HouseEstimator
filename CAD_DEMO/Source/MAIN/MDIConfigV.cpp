 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MetaClasses.h"
#include "MDIConfigV.h"
#include "MDI3DUserV.h"
#include "Main.h"
#include "MetaNodeCollectionV.h"
#include "MDIObjectEditV.h"
#include "ExcelExchangeV.h"
#include "LuaVarsEditV.h"
#include "MySupportV.h"
#include "CustomElementV.h"
#include "World.h"
#include "SkinEngineV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MyMDIChildV"
#pragma link "SUISkinEngine"
#pragma resource "*.dfm"
TMDIConfig *MDIConfig;
//---------------------------------------------------------------------------
__fastcall TMDIConfig::TMDIConfig(TComponent* Owner)
    : TMyMDIChild(Owner)
{
    SkinEngine->AddForm_BCB(this);
    MetaNodeCollection->FillTreeView(tvTechnology);
    MNL = new TMTList<TMetaNode>();
    MetaNodeCollection->KernelSupport->Edit(this,tsMainVariable,NULL);
    ((TMDIObjectEdit*)tsMainVariable->Controls[0])->Refresh();
    //suiSkinEngine1->Active = false;
    //suiSkinEngine1->SkinFile = GetSkinFile();
    //suiSkinEngine1->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TMDIConfig::NewFolExecute(TObject *Sender)
{
    if (!tvTechnology->Selected)
        return;
    if (tvTechnology->Selected->Level==0)
        return;
    TTreeNode *Parent=tvTechnology->Selected;
//    if (Parent->HasChildren)
  //      Parent == Parent->Parent;
    TMetaNode *MN = (TMetaNode *)Parent->Data;

    MN = MetaNodeCollection->AddGroup(MN,0,MN->Name);
    if (MN!=NULL)
        MN->Edit(this,NULL,NULL);
}

//---------------------------------------------------------------------------

void __fastcall TMDIConfig::NewExecute(TObject *Sender)
{
    if (!tvTechnology->Selected)
        return;
    if (tvTechnology->Selected->Level==0)
        return;
/*    if (tvTechnology->Selected->Level==1)
        return;*/
    //under construction

/*  TTreeNode *Parent=tvTechnology->Selected->Parent;
    TMetaNode *MN = (TMetaNode *)Parent->Data;
    if (MN->ChildType==ctNone)
        Parent = tvTechnology->Selected;
    MN =(TMetaNode *)Parent->Data;*/

    TTreeNode *Parent=tvTechnology->Selected;
//    if (Parent->HasChildren)
  //      Parent == Parent->Parent;
    TMetaNode *MN = (TMetaNode *)Parent->Data;

    AnsiString ClassName = MN->ChildType;
    if ( !ClassName.IsEmpty() )
		ClassName = MetaNodeCollection->SelectClassIfNeed(ClassName);
	//if (ClassName == AnsiString("TCustomMetaElement"))
	{
		if (TCustomMetaElement::StaticType->RegInfoCount >= 160)
		{
			return;
		}
	}
	MN = MetaNodeCollection->AddMetaChild(MN,ClassName,-1,MN->Name, false);
	if (MN!=NULL)
        MN->Edit(this,NULL,NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMDIConfig::EditExecute(TObject *Sender)
{
    if (!tvTechnology->Selected)
        return;
    if (!tvTechnology->Selected->Data)
        return;
    TMetaNode * MN = (TMetaNode *)tvTechnology->Selected->Data;
    if (MN->ServiceNode)
        Application->MessageBox("Not allowed to edit","");
    else
        MN->Edit(this,NULL,NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMDIConfig::DelExecute(TObject *Sender)
{
    if (!tvTechnology->Selected)
        return;
    if (tvTechnology->Selected->Level<=1)
        return;
    TTreeNode *Node = tvTechnology->Selected;

    if (Node->HasChildren)
        return;
    TMetaNode *MN = (TMetaNode *)Node->Data;
    TMTList<TMyObject> OBJL;
    MetaNodeCollection->GetLookingTo(NULL,MN,OBJL);
    if (OBJL.Count>0)
    {
        Mes("This object is linked to. Can't delete.");
        return;
    }

    MN->FromTree();
    delete MN;

}
//---------------------------------------------------------------------------


void __fastcall TMDIConfig::tvTechnologyDeletion(TObject *Sender,
      TTreeNode *Node)
{
    if (Node->Data)
        ((TMetaNode *)Node->Data)->TN=NULL;
}
//---------------------------------------------------------------------------


void __fastcall TMDIConfig::tvTechnologyStartDrag(TObject *Sender,
      TDragObject *&DragObject)
{
    MNL->Clear();
    if (tvTechnology->Selected)
    {
        TMetaNode *MN = (TMetaNode *)tvTechnology->Selected->Data;
        if (MN)
            MetaNodeCollection->AllowedParents(MN,MNL);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDIConfig::tvTechnologyDragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
    if (tvTechnology->DropTarget)
    {
        TMetaNode *MN = (TMetaNode *)tvTechnology->DropTarget->Data;
        if (MN&&MNL->IndexOf(MN)!=-1)
            Accept = true;
        else
            Accept = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDIConfig::FormDestroy(TObject *Sender)
{
    delete MNL;
}
//---------------------------------------------------------------------------

void __fastcall TMDIConfig::tvTechnologyDragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
    if (tvTechnology->DropTarget)
    {
        TMetaNode *MN = (TMetaNode *)tvTechnology->DropTarget->Data;
        if (MN&&MNL->IndexOf(MN)!=-1)
        {
            TMetaNode *Child = (TMetaNode *)tvTechnology->Selected->Data;
            Child->FromTree();
            if ( typeid(*Child) == typeid(TDynamicLink) )
            {
                ((TDynamicLink*)Child)->EL1.ADR = (TMetaElement*)MN;
                Child->CheckFields();
            }
            ((TMyRegTree*)MetaNodeCollection)->AddChild(MN,Child);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMDIConfig::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    ((TMDIObjectEdit*)tsMainVariable->Controls[0])->Apply();
    TMyMDIChild::FormCloseQuery(Sender,CanClose);
    if (CanClose)
        switch(Application->MessageBox("Save metadata?","Confirmation",MB_YESNOCANCEL))
        {
            case ID_YES:
                CanClose = MetaNodeCollection->Save();
            break;
            case ID_CANCEL:
                CanClose = false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TMDIConfig::tvTechnologyMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Button == mbRight)
    {
        TTreeNode *TN = tvTechnology->GetNodeAt(X,Y);
        tvTechnology->Select(TN);
        TPoint P = TPoint(X,Y);
        P = tvTechnology->ClientToScreen(P);
        PopupMenu1->Popup(P.x,P.y);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMDIConfig::tvTechnologyDblClick(TObject *Sender)
{
    TTreeNode *TN = (TTreeNode*)Sender;
    if (TN == NULL)
    	return;
    tvTechnology->Select(TN);
	EditExecute(NULL);
}
//---------------------------------------------------------------------------


void __fastcall TMDIConfig::UpActionExecute(TObject *Sender)
{
    if (!tvTechnology->Selected)
        return;
    TMetaNode* MN = (TMetaNode*)(tvTechnology->Selected->Data);
    TMetaNode* Parent = (TMetaNode*)MN->Parent;
    if (MN == MetaNodeCollection->Head)
        return;
    if (Parent == MetaNodeCollection->Head)
        return;
    int index = Parent->ChildList->IndexOf(MN);
    int upindex = (index + Parent->ChildList->Count-1)%Parent->ChildList->Count;
    Parent->ChildList->Move(index,upindex);

    if (upindex == 0)
        MN->TN->MoveTo(tvTechnology->Selected->Parent->Item[upindex],naAddFirst);
    else if (upindex == tvTechnology->Selected->Parent->Count-1)
        MN->TN->MoveTo(tvTechnology->Selected->Parent->Item[upindex],naAdd);
    else
        MN->TN->MoveTo(tvTechnology->Selected->Parent->Item[upindex],naInsert);

/*    TMetaNode* Dest = (TMetaNode*)Parent->ChildList->Items[upindex];
    MN->TN->MoveTo(Dest->TN,naInsert);*/
/*    Parent->ChildList->Move(index,upindex);
    tvTechnology->Selected->Parent->DeleteChildren();
    for (int i=0;i<Parent->ChildList->Count;i++)
        MetaNodeCollection->RecurrentFillTreeView(Parent->ChildList->Items[i],tvTechnology);
    tvTechnology->Selected = MN->TN;        */
}
//---------------------------------------------------------------------------

void __fastcall TMDIConfig::DownActionExecute(TObject *Sender)
{
    if (!tvTechnology->Selected)
        return;
    TMetaNode* MN = (TMetaNode*)(tvTechnology->Selected->Data);
    TMetaNode* Parent = (TMetaNode*)MN->Parent;
    if (MN == MetaNodeCollection->Head)
        return;
    if (Parent == MetaNodeCollection->Head)
        return;
    int index = Parent->ChildList->IndexOf(MN);
    int downindex = (index + 1)%Parent->ChildList->Count;
    Parent->ChildList->Move(index,downindex);
    if (downindex == 0)
        MN->TN->MoveTo(tvTechnology->Selected->Parent->Item[downindex],naAddFirst);
    else if (downindex == tvTechnology->Selected->Parent->Count-1)
        MN->TN->MoveTo(tvTechnology->Selected->Parent->Item[downindex],naAdd);
    else
        MN->TN->MoveTo(tvTechnology->Selected->Parent->Item[downindex+1],naInsert);

}
//---------------------------------------------------------------------------



void __fastcall TMDIConfig::NewCopyExecute(TObject *Sender)
{
    if (!tvTechnology->Selected)
        return;
    if (tvTechnology->Selected->Level<=1)
        return;
    TTreeNode *Node = tvTechnology->Selected;

    TMetaNode *MN = (TMetaNode *)Node->Data;

    TTreeNode *Parent=tvTechnology->Selected->Parent;
    TMetaNode *MNParent = (TMetaNode *)Parent->Data;

    TMetaNode *MNNEW = NULL;
    if ( typeid(*MN) == typeid(TMetaNode) )
        MNNEW = MetaNodeCollection->AddGroup(MNParent,0,MN->Name);
    else
        MNNEW = MetaNodeCollection->AddMetaChild(MNParent,AnsiString(typeid(*MN).name()).Trim(),-1,MN->Name);
    if (MNNEW!=NULL)
    {
        MNNEW->Assign(MN);
        MNNEW->RecurrentCheck();
        MNNEW->Edit(this,NULL,NULL);
    }
}
//---------------------------------------------------------------------------


void __fastcall TMDIConfig::ExportHereExecute(TObject *Sender)
{
    if (!tvTechnology->Selected)
        return;
    if (!tvTechnology->Selected->Data)
        return;
    TMetaNode * MN = (TMetaNode *)tvTechnology->Selected->Data;
    SD->FileName = AnsiString("EXPORT_")+MN->Name+AnsiString(".XLS");
    if (SD->Execute())
        ExcelExport(MN,true,SD->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMDIConfig::ImportHereExecute(TObject *Sender)
{
    if (OD->Execute())
        ExcelImport(OD->FileName);
}
//---------------------------------------------------------------------------




