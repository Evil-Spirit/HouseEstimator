// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDICubeV.h"
#include "WallV.h"
//---------------------------------------------------------------------------
#pragma link "MDIElementV"
#pragma resource "*.dfm"
TMDICube *MDICube; 
//---------------------------------------------------------------------------
 TMDICube::TMDICube(TComponent* Owner,TMetaCube *MN)
    : TMDIElement(Owner,MN)
{
}

void TMDICube::MNRefresh()
{
    TMDIElement::MNRefresh();
    cbHoleNormal->ItemIndex = ((TMetaCube *)MetaNode)->HoleNormal+1;
}

void TMDICube::MNApply()
{
    TMDIElement::MNApply();
    ((TMetaCube *)MetaNode)->HoleNormal = cbHoleNormal->ItemIndex-1;
}

