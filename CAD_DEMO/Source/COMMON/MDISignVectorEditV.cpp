 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDISignVectorEditV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MDIObjectEditV"
#pragma link "SimpleEditV"
#pragma resource "*.dfm"
TMDISIGNVECEDIT *MDISIGNVECEDIT;
TIntVec SignIntVec;
//---------------------------------------------------------------------------
__fastcall TMDISIGNVECEDIT::TMDISIGNVECEDIT(TComponent* Owner)
    : TMDISimpleEdit(Owner)
{
delete this;
}
//---------------------------------------------------------------------------
__fastcall TMDISIGNVECEDIT::TMDISIGNVECEDIT(TComponent* Owner,TControl *_Parent,TMyObject *_Obj,const AnsiString& _Text,void *_Data)
    : TMDISimpleEdit(Owner,_Parent,_Obj,_Text,_Data)
{
}


void TMDISIGNVECEDIT::SETUP()
{
    A[0]=ComboBox1;
    A[1]=ComboBox2;
    A[2]=ComboBox3;

}

//Освежить
void TMDISIGNVECEDIT::Refresh()
{
    SignIntVec = *((TIntVec *)(Obj->GetFieldAddress(L->Caption)));
    for (int i=0;i<3;i++)
        A[i]->ItemIndex = SignIntVec.a[i]+1;
}

///значение
void *TMDISIGNVECEDIT::Value()
{
    for (int i=0;i<3;i++)
        SignIntVec.a[i]=A[i]->ItemIndex-1;
    return(&SignIntVec);
}

