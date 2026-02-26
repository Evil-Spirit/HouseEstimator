// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDIMetaPlatformV.h"
#include "PlatformV.h"
//---------------------------------------------------------------------------
#pragma link "MDIElementV"
#pragma resource "*.dfm"
TMDIMetaPlatform *MDIMetaPlatform;
//---------------------------------------------------------------------------
 TMDIMetaPlatform::TMDIMetaPlatform(TComponent* Owner,TMetaPlatform *M)
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

void  TMDIMetaPlatform::cbFirstClick(TObject *Sender)
{
    cbLand->Checked = false;
}
//---------------------------------------------------------------------------

void  TMDIMetaPlatform::cbLandClick(TObject *Sender)
{
    cbFirst->Checked = false;
}
//---------------------------------------------------------------------------

