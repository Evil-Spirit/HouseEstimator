 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIConnectV.h"
#include "MDIHasPositionV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIMetaNodeV"
#pragma resource "*.dfm"
TMDIConnect *MDIConnect;

//---------------------------------------------------------------------------
__fastcall TMDIConnect::TMDIConnect(TComponent* Owner,TMetaLink *N)
    : TMDIMetaNode(Owner,N)
{
}

void TMDIConnect::SETUP()
{
    ((TMetaLink *)MetaNode)->Angle.Edit(this,Angle,NULL);
    ((TMetaLink *)MetaNode)->EPS.Edit(this,EPS,NULL);
    ((TMetaLink *)MetaNode)->STEP.Edit(this,STEP,NULL);
    cblcmX->Items->Clear();
    cblcmY->Items->Clear();
    cblcmZ->Items->Clear();
    for (int i=0;i<5;i++)
    {
        cblcmX->Items->Add(LinkChangeModeStr[i]);
        cblcmY->Items->Add(LinkChangeModeStr[i]);
        cblcmZ->Items->Add(LinkChangeModeStr[i]);
    }
}

void TMDIConnect::MNRefresh()
{
    TMDIMetaNode::MNRefresh();
    ((TMDIObjectEdit *)Angle->Controls[0])->Refresh();
    ((TMDIObjectEdit *)EPS->Controls[0])->Refresh();
    ((TMDIObjectEdit *)STEP->Controls[0])->Refresh();
    cbHoleCreated->Checked = ((TMetaLink *)MetaNode)->HoleCreated;
    cblcmX->ItemIndex = ((TMetaLink *)MetaNode)->LCM.x;
    cblcmY->ItemIndex = ((TMetaLink *)MetaNode)->LCM.y;
    cblcmZ->ItemIndex = ((TMetaLink *)MetaNode)->LCM.z;
    //---------------------------------------------------
    cbNormal0->ItemIndex = ((TMetaLink *)MetaNode)->ClientNormal0;
    cbNormal1->ItemIndex = ((TMetaLink *)MetaNode)->ClientNormal1;
    cbClient->Checked = ((TMetaLink *)MetaNode)->Client;
    ePriority->Text = IntToStr(((TMetaLink *)MetaNode)->Priority);
    cbMetaLinkType->ItemIndex = ((TMetaLink *)MetaNode)->MetaLinkType;
    cbControl->Checked = ((TMetaLink *)MetaNode)->InWeb;
    cbWallLink->Checked = ((TMetaLink *)MetaNode)->WallLink;
    cbRunOnStop->Checked = ((TMetaLink *)MetaNode)->RunOnStop;
    rgTransMode->ItemIndex = ((TMetaLink *)MetaNode)->TransMode;
}

bool TMDIConnect::MNChecked()
{
    if (TMDIMetaNode::MNChecked()==false)
        return(false);
    if ( ((TMDIObjectEdit *)Angle->Controls[0])->Checked()==false)
        return(false);
    if ( ((TMDIObjectEdit *)EPS->Controls[0])->Checked()==false)
        return(false);
    if ( ((TMDIObjectEdit *)STEP->Controls[0])->Checked()==false)
        return(false);
    if (!ISINTEGER(ePriority->Text))
        return(false);
    return(true);
}

void TMDIConnect::MNApply()
{
    TMDIMetaNode::MNApply();
    ((TMDIObjectEdit *)Angle->Controls[0])->Apply();
    ((TMDIObjectEdit *)EPS->Controls[0])->Apply();
    ((TMDIObjectEdit *)STEP->Controls[0])->Apply();
    ((TMetaLink *)MetaNode)->HoleCreated = cbHoleCreated->Checked;
    ((TMetaLink *)MetaNode)->LCM.x = cblcmX->ItemIndex;
    ((TMetaLink *)MetaNode)->LCM.y = cblcmY->ItemIndex;
    ((TMetaLink *)MetaNode)->LCM.z = cblcmZ->ItemIndex;
    //------------------------------------------------------------
    ((TMetaLink *)MetaNode)->ClientNormal0 = cbNormal0->ItemIndex;
    ((TMetaLink *)MetaNode)->ClientNormal1 = cbNormal1->ItemIndex;
    ((TMetaLink *)MetaNode)->Client = cbClient->Checked;
    ((TMetaLink *)MetaNode)->Priority = ePriority->Text.ToInt();
    ((TMetaLink *)MetaNode)->MetaLinkType = cbMetaLinkType->ItemIndex;
    ((TMetaLink *)MetaNode)->InWeb = cbControl->Checked;
    ((TMetaLink *)MetaNode)->WallLink = cbWallLink->Checked;
    ((TMetaLink *)MetaNode)->TransMode = rgTransMode->ItemIndex;
    ((TMetaLink *)MetaNode)->RunOnStop = cbRunOnStop->Checked;
}


