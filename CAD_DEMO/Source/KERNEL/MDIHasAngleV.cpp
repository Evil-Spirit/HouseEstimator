 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIHasAngleV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDIAngle *MDIAngle;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

__fastcall TMDIAngle::TMDIAngle(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
void TMDIAngle::SETUP()
{
P[0] = Mirrored;
P[1] = LOW;
P[2] = HI;
Count=3;
}

