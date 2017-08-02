//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDICubeV.h"
#include "WallV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIElementV"
#pragma resource "*.dfm"
TMDICube *MDICube; 
//---------------------------------------------------------------------------
__fastcall TMDICube::TMDICube(TComponent* Owner,TMetaCube *MN)
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

