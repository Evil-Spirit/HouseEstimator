//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "BaseDockSiteFormV.h"
#include "FloatingV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BaseFormV"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TBaseDockSiteForm::TBaseDockSiteForm(TComponent* Owner)
	: TBaseForm(Owner)
{
    // change wnd procs for the docking panels
    OldLeftDockWndProc = pnlLeftSide->WindowProc;
    OldRightDockWndProc = pnlRightSide->WindowProc;
    OldBottomDockWndProc = pnlBottomSide->WindowProc;

    pnlLeftSide->WindowProc = LeftDockWindowProc;
    pnlRightSide->WindowProc = RightDockWindowProc;
    pnlBottomSide->WindowProc = BottomDockWindowProc;
    FDockIndex = 0;
}

/*      if (&OldLeftDockWndProc != NULL)
        pnlLeftSide->WindowProc = OldLeftDockWndProc;

      if (&OldRightDockWndProc != NULL)
        pnlRightSide->WindowProc = OldRightDockWndProc;

      if (&OldBottomDockWndProc != NULL)
        pnlBottomSide->WindowProc = OldBottomDockWndProc;
*/
//---------------------------------------------------------------------------
void __fastcall TBaseDockSiteForm::LeftDockWindowProc(Messages::TMessage &Message)
{
    OldLeftDockWndProc(Message);
    if (Message.Msg == Controls::CM_DOCKNOTIFICATION)
    {
        TCMDockNotification& cmdn = (TCMDockNotification&)Message;
        if (cmdn.NotifyRec->ClientMsg == CM_VISIBLECHANGED)
          ControlVisibilityChanged(pnlLeftSide, cmdn.Client, bool(cmdn.NotifyRec->MsgWParam));
    }
}

void __fastcall TBaseDockSiteForm::RightDockWindowProc(Messages::TMessage &Message)
{
    OldRightDockWndProc(Message);
    if (Message.Msg == Controls::CM_DOCKNOTIFICATION)
    {
        TCMDockNotification& cmdn = (TCMDockNotification&)Message;
        if (cmdn.NotifyRec->ClientMsg == CM_VISIBLECHANGED)
          ControlVisibilityChanged(pnlRightSide, cmdn.Client, bool(cmdn.NotifyRec->MsgWParam));
    }
}

void __fastcall TBaseDockSiteForm::BottomDockWindowProc(Messages::TMessage &Message)
{
    if (Message.Msg == WM_SIZE)
    {
		if (StatusBar->Visible)
		    StatusBar->Top = pnlBottomSide->Top + pnlBottomSide->Height;
    }
    OldBottomDockWndProc(Message);
    if (Message.Msg == Controls::CM_DOCKNOTIFICATION)
    {
        TCMDockNotification& cmdn = (TCMDockNotification&)Message;
        if (cmdn.NotifyRec->ClientMsg == CM_VISIBLECHANGED)
          ControlVisibilityChanged(pnlBottomSide, cmdn.Client, bool(cmdn.NotifyRec->MsgWParam));
    }
}

void __fastcall TBaseDockSiteForm::ControlVisibilityChanged(TPanel* DockTarget,TControl* Control,bool Visible)
{
    // all removed
    if (DockTarget->VisibleDockClientCount == 0)
    {
        DockTarget->AutoSize = true;
        if (DockTarget == pnlLeftSide)
            spltrLeft->Visible = false;
        else if (DockTarget == pnlRightSide)
            spltrRight->Visible = false;
        else
            spltrBottom->Visible = false;
    }
  // showing the first one
    else if (Visible && (DockTarget->VisibleDockClientCount == 1))
    {
        DockTarget->AutoSize = false;
        if ((DockTarget == pnlLeftSide || DockTarget == pnlRightSide) && (DockTarget->Width == 0) )
            DockTarget->Width = Control->LRDockWidth;
        else if (DockTarget->Height == 0)
            DockTarget->Height = Control->TBDockHeight;
        if (DockTarget == pnlLeftSide)
        {
            spltrLeft->Visible = true;
            pnlLeftSide->Left = 0;
        }else if (DockTarget == pnlRightSide)
        {
            spltrRight->Visible = true;
            pnlRightSide->Left = spltrRight->Left + spltrRight->Width;
        }
        else
        {
            spltrBottom->Visible = true;
            pnlBottomSide->Top = spltrBottom->Top+spltrBottom->Height;
        }
    }
}


void __fastcall TBaseDockSiteForm::pnlLeftSideDockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
	if ( !IS(Source->Control,__classid(TFloatForm)) || ((TFloatForm*)Source->Control)->DockIndex != DockIndex )
    {
    	Accept = false;
        return;
    }

    TRect aRect;
    if ( (((TPanel*)Sender)->Width == 0) || (((TPanel*)Sender)->Height == 0) )
    {
        aRect = Source->DockRect;
        if (Sender == pnlRightSide)
            aRect.Left = Source->DockRect.Left - Source->Control->LRDockWidth;
        else if (Sender == pnlLeftSide)
            aRect.Right = Source->DockRect.Left + Source->Control->LRDockWidth;
        else if (Sender == pnlBottomSide)
            aRect.Top = Source->DockRect.Top - Source->Control->TBDockHeight;
        Source->DockRect = aRect;
    }
}
//---------------------------------------------------------------------------

void __fastcall TBaseDockSiteForm::pnlLeftSideDockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
    spltrLeft->Visible = true;
    pnlLeftSide->Left = 0;
    pnlLeftSide->AutoSize = false;
//    if (IS(Source->Control,__classid(TIntExplorer)))
//        ((TIntExplorer*)Source->Control)->DroppedOn(pnlLeftSide);
//    pnlLeftSide->Width = Source->Control->LRDockWidth;
}
//---------------------------------------------------------------------------

void __fastcall TBaseDockSiteForm::pnlRightSideDockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
  spltrRight->Visible = true;
//  pnlRightSide->Width = Source->Control->LRDockWidth;
  pnlRightSide->Left = spltrRight->Left + spltrRight->Width;
  pnlRightSide->AutoSize = false;
//    if (IS(Source->Control,__classid(TIntExplorer)))
//        ((TIntExplorer*)Source->Control)->DroppedOn(pnlRightSide);
}
//---------------------------------------------------------------------------

void __fastcall TBaseDockSiteForm::pnlBottomSideDockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
    spltrBottom->Visible = true;
//    pnlRightSide->Height = Source->Control->TBDockHeight;
    pnlBottomSide->Top = spltrBottom->Top+spltrBottom->Height;
    pnlBottomSide->AutoSize = false;
//    if (IS(Source->Control,__classid(TIntExplorer)))
//        ((TIntExplorer*)Source->Control)->DroppedOn(pnlBottomSide);
}
//---------------------------------------------------------------------------

void __fastcall TBaseDockSiteForm::pnlLeftSideUnDock(TObject *Sender,
      TControl *Client, TWinControl *NewTarget, bool &Allow)
{
    if (pnlLeftSide->VisibleDockClientCount == 1)
    {
        spltrLeft->Visible = false;
        pnlLeftSide->AutoSize = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TBaseDockSiteForm::pnlRightSideUnDock(TObject *Sender,
      TControl *Client, TWinControl *NewTarget, bool &Allow)
{
    if (pnlRightSide->VisibleDockClientCount == 1)
    {
        spltrRight->Visible = false;
        pnlRightSide->AutoSize = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TBaseDockSiteForm::pnlBottomSideUnDock(TObject *Sender,
      TControl *Client, TWinControl *NewTarget, bool &Allow)
{
    if (pnlBottomSide->VisibleDockClientCount == 1)
    {
        spltrBottom->Visible = false;
        pnlBottomSide->AutoSize = true;
    }
}
//---------------------------------------------------------------------------

