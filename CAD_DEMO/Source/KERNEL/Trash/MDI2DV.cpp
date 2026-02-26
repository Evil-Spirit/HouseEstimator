// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
 //---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MDI2DV.h"
#include "DrawViewV.h"
#include "World.h"
//---------------------------------------------------------------------------
#pragma link "MyMDIChildV"
#pragma resource "*.dfm"
TMDI2D* ConditionDV = NULL;;
TMDI2D *MDI2D;
//---------------------------------------------------------------------------
 TMDI2D::TMDI2D(TComponent* Owner)
    : TMyMDIChild(Owner)
{
}
//---------------------------------------------------------------------------

void  TMDI2D::FormShow(TObject *Sender)
{
    DrawView = new TDrawView(this,this);
    DrawView->Show();
}
//---------------------------------------------------------------------------

void  TMDI2D::AppMessage(TMsg& AMessage, bool& Handled)
{
    if (AMessage.message == WM_KEYDOWN)
    {
        WORD Key = (WORD)AMessage.wParam;
        DrawView->FormKeyDown(this,Key,TShiftState() );
    }
}


void  TMDI2D::FormMouseWheel(TObject *Sender, TShiftState Shift,
      int WheelDelta, TPoint &MousePos, bool &Handled)
{
    if (WheelDelta>0)
      DrawView->TimerAction(taZoomMinus,((double)WheelDelta)/100);
    else
      DrawView->TimerAction(taZoomPlus,-((double)WheelDelta)/100);
}
//---------------------------------------------------------------------------

void  TMDI2D::FormCreate(TObject *Sender)
{
    if (World)
        World->RegisterClient(this);
}
//---------------------------------------------------------------------------

void  TMDI2D::FormDestroy(TObject *Sender)
{
    if (World)
        World->UnRegisterClient(this);

}
//---------------------------------------------------------------------------


