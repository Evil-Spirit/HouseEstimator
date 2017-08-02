 //---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MDI2DV.h"
#include "DrawViewV.h"
#include "World.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MyMDIChildV"
#pragma resource "*.dfm"
TMDI2D* ConditionDV = NULL;;
TMDI2D *MDI2D;
//---------------------------------------------------------------------------
__fastcall TMDI2D::TMDI2D(TComponent* Owner)
    : TMyMDIChild(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMDI2D::FormShow(TObject *Sender)
{
    DrawView = new TDrawView(this,this);
    DrawView->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMDI2D::AppMessage(TMsg& AMessage, bool& Handled)
{
    if (AMessage.message == WM_KEYDOWN)
    {
        WORD Key = (WORD)AMessage.wParam;
        DrawView->FormKeyDown(this,Key,TShiftState() );
    }
}


void __fastcall TMDI2D::FormMouseWheel(TObject *Sender, TShiftState Shift,
      int WheelDelta, TPoint &MousePos, bool &Handled)
{
    if (WheelDelta>0)
      DrawView->TimerAction(taZoomMinus,((double)WheelDelta)/100);
    else
      DrawView->TimerAction(taZoomPlus,-((double)WheelDelta)/100);
}
//---------------------------------------------------------------------------

void __fastcall TMDI2D::FormCreate(TObject *Sender)
{
    if (World)
        World->RegisterClient(this);
}
//---------------------------------------------------------------------------

void __fastcall TMDI2D::FormDestroy(TObject *Sender)
{
    if (World)
        World->UnRegisterClient(this);

}
//---------------------------------------------------------------------------


