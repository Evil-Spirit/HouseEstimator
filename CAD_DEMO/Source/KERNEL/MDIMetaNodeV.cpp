 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaNodeV.h"
#include "LuaVarsEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MyMDIChildV"
#pragma resource "*.dfm"
TMDIMetaNode *MDIMetaNode;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TMDIMetaNode::TMDIMetaNode(TComponent* Owner,TMetaNode *N)
    : TMyMDIChild(Owner)
{
    for (int i=0;i<cbeImageSelect->Images->Count;i++)
    {
        cbeImageSelect->ItemsEx->AddItem("",i,i,i,0,0);
    }
    MetaNode=N;
    EditAttributes(this,Attributes,NULL,((TMetaNode *)MetaNode));
    ((TMetaNode *)MetaNode)->TB->Edit(this,TB,NULL);
    BMPPointer = new TBMPPointer();
    SmallBMPPointer = new TBMPPointer();
    SETUP();
    MNRefresh();
}

void TMDIMetaNode::MNRefresh()
{
    Caption = MetaNode->Name;
    mnName->Text = MetaNode->Name;
    if (MetaNode->Description.IsEmpty())
        MetaNode->Description = MetaNode->Name;
    mnDescription->Text = MetaNode->Description;
    METAID->Text = IntToStr(MetaNode->ID);
    eGUID->Text = MetaNode->GUID;
    cbeImageSelect->ItemIndex = MetaNode->ImageIndex;
    ((TMDIObjectEdit *)Attributes->Controls[0])->Refresh();
    ((TMDIObjectEdit *)TB->Controls[0])->Refresh();
    BMPPointer->Assign(MetaNode->Img1);
    BMPPointer->GetBitmap(Image1->Picture->Bitmap);
    SmallBMPPointer->Assign(MetaNode->SmallImg);
    SmallBMPPointer->GetBitmap(Image2->Picture->Bitmap);
}

void TMDIMetaNode::MNApply()
{
    MetaNode->Description = mnDescription->Text.Trim();
    MetaNode->Name=mnName->Text;
    MetaNode->ImageIndex=cbeImageSelect->ItemIndex;
    ((TMDIObjectEdit *)Attributes->Controls[0])->Apply();
    ((TMDIObjectEdit *)TB->Controls[0])->Apply();
    MetaNode->Img1->Assign(BMPPointer);
    MetaNode->SmallImg->Assign(SmallBMPPointer);
}

bool TMDIMetaNode::MNChecked()
{
    if ( ((TMDIObjectEdit *)Attributes->Controls[0])->Checked()==false)
        return(false);
    if ( ((TMDIObjectEdit *)TB->Controls[0])->Checked()==false)
        return(false);
    if (mnDescription->Text.Trim().IsEmpty())
        return false;
    TClassNode* tNameNode = MetaNode->DynamicType->UniqueNameNode;
    TMyObject* MRO = NULL;
    if (tNameNode)
        MRO = tNameNode->RecurrentFindByName(mnName->Text);
    return (MRO == MetaNode) || (MRO == NULL);
}


void __fastcall TMDIMetaNode::btOKClick(TObject *Sender)
{
    MetaNode->ReadOnly = false;
    if ( MNChecked() )
    {
        MNApply();
        MetaNode->RecurrentCheck();
        Close();
    }
    else
    {
        ShowMessage("Some fields are incorrect");
    }
    MetaNode->ReadOnly = true;
}
//---------------------------------------------------------------------------

void __fastcall TMDIMetaNode::btCancelClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TMDIMetaNode::FormDestroy(TObject *Sender)
{
    delete BMPPointer;
    delete SmallBMPPointer;
    KILL();
}
//---------------------------------------------------------------------------



void __fastcall TMDIMetaNode::Image2Click(TObject *Sender)
{
    BMPPointer->Select();
    BMPPointer->GetBitmap(Image1->Picture->Bitmap);
}
//---------------------------------------------------------------------------

void __fastcall TMDIMetaNode::Image2DblClick(TObject *Sender)
{
    SmallBMPPointer->Select();
    SmallBMPPointer->GetBitmap(Image2->Picture->Bitmap);
}
//---------------------------------------------------------------------------

