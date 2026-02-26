// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaNodeV.h"
#include "LuaVarsEditV.h"
//---------------------------------------------------------------------------
#pragma link "MyMDIChildV"
#pragma resource "*.dfm"
TMDIMetaNode *MDIMetaNode;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
 TMDIMetaNode::TMDIMetaNode(TComponent* Owner,TMetaNode *N)
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


void  TMDIMetaNode::btOKClick(TObject *Sender)
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

void  TMDIMetaNode::btCancelClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void  TMDIMetaNode::FormDestroy(TObject *Sender)
{
    delete BMPPointer;
    delete SmallBMPPointer;
    KILL();
}
//---------------------------------------------------------------------------



void  TMDIMetaNode::Image2Click(TObject *Sender)
{
    BMPPointer->Select();
    BMPPointer->GetBitmap(Image1->Picture->Bitmap);
}
//---------------------------------------------------------------------------

void  TMDIMetaNode::Image2DblClick(TObject *Sender)
{
    SmallBMPPointer->Select();
    SmallBMPPointer->GetBitmap(Image2->Picture->Bitmap);
}
//---------------------------------------------------------------------------

