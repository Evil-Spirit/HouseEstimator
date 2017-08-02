//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
             
#include "Math.hpp"
#include "ProgBarV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TProgBar *ProgBar=NULL;
//---------------------------------------------------------------------------
__fastcall TProgBar::TProgBar(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TProgBar::FormCreate(TObject *Sender)
{
    ProgBar = this;
    SetStartProcess(RealStartProcess);
    SetCountProcess(RealCountProcess);
}
//---------------------------------------------------------------------------
void __fastcall TProgBar::FormDestroy(TObject *Sender)
{
    ProgBar = NULL;
    SetStartProcess(NULL);
    SetCountProcess(NULL);
}
//---------------------------------------------------------------------------
void RealStartProcess(const AnsiString& ProcessName,int Count)
{
    if (ProgBar)
    {
        ProgBar->Left = 20;
        ProgBar->Top = Application->MainForm->Height - ProgBar->Height - 20;
        ProgBar->Main->Caption = ProcessName;
        ProgBar->Detail->Caption = "";
        ProgBar->Progress->Max = Count;
        ProgBar->Progress->Position = 0;
        ProgBar->ProcessName = ProcessName;
        if ( Count > 10 )
        {
            Screen->Cursor = crHourGlass;
            ProgBar->Visible = true;
            Application->ProcessMessages();
        }
    }
}

void RealCountProcess(const AnsiString& ObjectName,int Count)
{
    if (ProgBar)
    {
        ProgBar->Progress->StepBy(Count);
        ProgBar->Detail->Caption = ObjectName;
        ProgBar->lProcessName->Caption = ProgBar->ProcessName + AnsiString(" ") + IntToStr(int(RoundTo(double(ProgBar->Progress->Position*100)/double(ProgBar->Progress->Max),0))) + AnsiString(" %");
        if (ProgBar->Visible)
            Application->ProcessMessages();
    }
}
void __fastcall TProgBar::FormHide(TObject *Sender)
{
    Screen->Cursor = crDefault;    
}
//---------------------------------------------------------------------------

