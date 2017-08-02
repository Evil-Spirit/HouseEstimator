 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIMetaPlatformV.h"
#include "PlatformV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIElementV"
#pragma resource "*.dfm"
TMDIMetaPlatform *MDIMetaPlatform;
//---------------------------------------------------------------------------
__fastcall TMDIMetaPlatform::TMDIMetaPlatform(TComponent* Owner,TMetaPlatform *M)
    : TMDIElement(Owner,M)
{
}
//---------------------------------------------------------------------------
void TMDIMetaPlatform::MNRefresh()
{
    TMDIElement::MNRefresh();
    cbFirst->Checked = ((TMetaPlatform*)MetaNode)->First;
    cbLand->Checked = ((TMetaPlatform*)MetaNode)->Land;
}

void TMDIMetaPlatform::MNApply()
{
    TMDIElement::MNApply();
    ((TMetaPlatform*)MetaNode)->First = cbFirst->Checked;
    ((TMetaPlatform*)MetaNode)->Land = cbLand->Checked;
}

void __fastcall TMDIMetaPlatform::cbFirstClick(TObject *Sender)
{
    cbLand->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TMDIMetaPlatform::cbLandClick(TObject *Sender)
{
    cbFirst->Checked = false;
}
//---------------------------------------------------------------------------

