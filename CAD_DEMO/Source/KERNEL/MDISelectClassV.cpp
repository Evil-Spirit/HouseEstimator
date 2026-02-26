// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDISelectClassV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMDISelectClass *MDISelectClass;
//---------------------------------------------------------------------------
 TMDISelectClass::TMDISelectClass(TComponent* Owner,TMTList<TClassNode> *L)
    : TForm(Owner)
{
    ListBox1->Clear();
    for (int i=0;i<L->Count;i++)
        ListBox1->AddItem(L->Items[i]->Name,NULL);
}
//---------------------------------------------------------------------------
void  TMDISelectClass::Button2Click(TObject *Sender)
{
Returned = -1;
Close();    
}
//---------------------------------------------------------------------------
void  TMDISelectClass::Button1Click(TObject *Sender)
{
Returned = ListBox1->ItemIndex;
Close(); 
}
//---------------------------------------------------------------------------
void  TMDISelectClass::FormShow(TObject *Sender)
{
Returned = -1;
}
//---------------------------------------------------------------------------
