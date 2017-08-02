 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIBoolVectorEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma link "SimpleEditV"
#pragma resource "*.dfm"
TMDIBOOLVECEDIT *MDIBOOLVECEDIT;
TBoolVec BoolVec;
//---------------------------------------------------------------------------
__fastcall TMDIBOOLVECEDIT::TMDIBOOLVECEDIT(TComponent* Owner)
    : TMDISimpleEdit(Owner)
{
delete this;
}
//---------------------------------------------------------------------------
__fastcall TMDIBOOLVECEDIT::TMDIBOOLVECEDIT(TComponent* Owner,TControl *_Parent,TMyObject *_Obj,const AnsiString& _Text,void *_Data)
    : TMDISimpleEdit(Owner,_Parent,_Obj,_Text,_Data)
{
}

void TMDIBOOLVECEDIT::SETUP()
{
    A[0]=ComboBox1;
    A[1]=ComboBox2;
    A[2]=ComboBox3;
}

//Освежить
void TMDIBOOLVECEDIT::Refresh()
{
    BoolVec = *((TBoolVec *)(Obj->GetFieldAddress(L->Caption)));
    for (int i=0;i<3;i++)
        A[i]->ItemIndex = BoolVec.a[i];
}

void *TMDIBOOLVECEDIT::Value()
{
    for (int i=0;i<3;i++)
        BoolVec.a[i]=(bool)A[i]->ItemIndex;
    return(&BoolVec);
}

