//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDIVisibleSelectFloorV.h"
#include "World.h"          
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMDIVisibleSelectFloor *MDIVisibleSelectFloor;
//---------------------------------------------------------------------------
__fastcall TMDIVisibleSelectFloor::TMDIVisibleSelectFloor(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMDIVisibleSelectFloor::FormCreate(TObject *Sender)
{
    TClient3D* Client = World->ActiveClient;
    LB->Clear();
    for (int i=0;i<World->Floors.Count;i++)
    {
        LB->AddItem(World->Floors[i].Description,NULL);
        if (Client && Client->Visible[i])
            LB->Selected[i] = true;
    }
    if (!Client || Client->VisibleAll)
        rbAll->Checked=true;
    else
    {
        bool SomeVisible = false;
        for (int i=0;i<Client->Visible.Count;i++)
            if (Client->Visible[i])
            {
                SomeVisible = true;
                break;
            }
        if (SomeVisible)
            rbActualAnd->Checked = true;
        else
            rbActual->Checked = true;
    }
    rbActualAndClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TMDIVisibleSelectFloor::rbActualAndClick(TObject *Sender)
{
    LB->Enabled = (rbActualAnd->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TMDIVisibleSelectFloor::btOKClick(TObject *Sender)
{
    TClient3D* Active = World->ActiveClient;
    if (!Active)
        return;
    if (rbAll->Checked)
        Active->VisibleAll=true;
    else
    {
        Active->VisibleAll=false;
        for (int i=0;i<Active->Visible.Count;i++)
            Active->Visible[i] = false;
        if (rbActualAnd->Checked)
            for (int i=0;i<LB->Count;i++)
                Active->Visible[i] = LB->Selected[i];
    }

}
//---------------------------------------------------------------------------

void __fastcall TMDIVisibleSelectFloor::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;    
}
//---------------------------------------------------------------------------

