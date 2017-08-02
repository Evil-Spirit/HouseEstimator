 //---------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
       
#include "MyMDIChildV.h"
//---------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FloatingV"
#pragma link "BaseFormV"
#pragma resource "*.dfm"
//---------------------------------------------------------------------
TMyMDIChild* MyMDIChild;

__fastcall TMyMDIChild::TMyMDIChild(TComponent *Owner)
	: TBaseForm(Owner)
{
//	DockIndex=100;
}
__fastcall TMyMDIChild::TMyMDIChild(TComponent *Owner,const AnsiString& _Caption,bool load)
	: TBaseForm(Owner)
{
//	DockIndex=100;
    Caption = _Caption;
}

//--------------------------------------------------------------------- 
void __fastcall TMyMDIChild::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------


void __fastcall TMyMDIChild::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    for (int i=0;i<Screen->FormCount;i++)
    {
        TForm *Form = Screen->Forms[i];
        if (Form->Owner == this && Form->Parent == NULL)
            Form->Close();
    }
    Application->ProcessMessages();
    for(int j=0;j<Screen->FormCount;)
    {
        TForm *Form = Screen->Forms[j];
        if (Form->Owner != this || Form->Parent != NULL)
            j++;
        else if (!Form->Visible)
            delete Form;
        else
        {
            CanClose =  false;
            return;
        }
    }
    Application->ProcessMessages();
    for (int i=0;i<Screen->FormCount;i++)
    {
        TForm *Form = Screen->Forms[i];
        if (Form->Owner == this && Form->Parent == NULL)
        {
            CanClose =  false;
            return;
        }
    }
    CanClose = true;
}
//---------------------------------------------------------------------------


