// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDISignVectorEditV.h"
//---------------------------------------------------------------------------
#pragma link "MDIObjectEditV"
#pragma link "SimpleEditV"
#pragma resource "*.dfm"
TMDISIGNVECEDIT *MDISIGNVECEDIT;
TIntVec SignIntVec;
//---------------------------------------------------------------------------
 TMDISIGNVECEDIT::TMDISIGNVECEDIT(TComponent* Owner)
    : TMDISimpleEdit(Owner)
{
delete this;
}
//---------------------------------------------------------------------------
 TMDISIGNVECEDIT::TMDISIGNVECEDIT(TComponent* Owner,TControl *_Parent,TMyObject *_Obj,const AnsiString& _Text,void *_Data)
    : TMDISimpleEdit(Owner,_Parent,_Obj,_Text,_Data)
{
}


void TMDISIGNVECEDIT::SETUP()
{
    A[0]=ComboBox1;
    A[1]=ComboBox2;
    A[2]=ComboBox3;

}

//Îñâåæèòü
void TMDISIGNVECEDIT::Refresh()
{
    SignIntVec = *((TIntVec *)(Obj->GetFieldAddress(L->Caption)));
    for (int i=0;i<3;i++)
        A[i]->ItemIndex = SignIntVec.a[i]+1;
}

///çíà÷åíèå
void *TMDISIGNVECEDIT::Value()
{
    for (int i=0;i<3;i++)
        SignIntVec.a[i]=A[i]->ItemIndex-1;
    return(&SignIntVec);
}

