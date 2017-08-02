 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIHasSizeV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma resource "*.dfm"
TMDISize *MDISize;
//---------------------------------------------------------------------------
__fastcall TMDISize::TMDISize(TComponent* Owner,TControl *_Parent, TMyObject *_Obj,const AnsiString& Text,void *Data)
    : TMDIObjectEdit(Owner,_Parent,_Obj,Text,Data)
{
}
//---------------------------------------------------------------------------
void TMDISize::SETUP()
{
P[0] = DEFAULT;
P[1] = LOW;
P[2] = HI;
P[3] = STEP;
Count=4;
}
