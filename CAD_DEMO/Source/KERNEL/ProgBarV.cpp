// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
             
#include "ProgBarV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"

TProgBar *ProgBar=NULL;
//---------------------------------------------------------------------------
 TProgBar::TProgBar(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void  TProgBar::FormCreate(TObject *Sender)
{
    ProgBar = this;
    SetStartProcess(RealStartProcess);
    SetCountProcess(RealCountProcess);
}
//---------------------------------------------------------------------------
void  TProgBar::FormDestroy(TObject *Sender)
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
void  TProgBar::FormHide(TObject *Sender)
{
    Screen->Cursor = crDefault;    
}
//---------------------------------------------------------------------------

