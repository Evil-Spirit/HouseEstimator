 //---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDISelectClassV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMDISelectClass *MDISelectClass;
//---------------------------------------------------------------------------
__fastcall TMDISelectClass::TMDISelectClass(TComponent* Owner,TMTList<TClassNode> *L)
    : TForm(Owner)
{
    ListBox1->Clear();
    for (int i=0;i<L->Count;i++)
        ListBox1->AddItem(L->Items[i]->Name,NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMDISelectClass::Button2Click(TObject *Sender)
{
Returned = -1;
Close();    
}
//---------------------------------------------------------------------------
void __fastcall TMDISelectClass::Button1Click(TObject *Sender)
{
Returned = ListBox1->ItemIndex;
Close(); 
}
//---------------------------------------------------------------------------
void __fastcall TMDISelectClass::FormShow(TObject *Sender)
{
Returned = -1;
}
//---------------------------------------------------------------------------
