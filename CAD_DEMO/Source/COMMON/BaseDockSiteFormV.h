//---------------------------------------------------------------------------

#ifndef BaseDockSiteFormVH
#define BaseDockSiteFormVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include "BaseFormV.h"
//---------------------------------------------------------------------------
class COMMONAL_API TBaseDockSiteForm : public TBaseForm
{
__published:	// IDE-managed Components
	TPanel *pnlRightSide;
	TPanel *pnlBottomSide;
	TPanel *pnlLeftSide;
	TStatusBar *StatusBar;
	TSplitter *spltrRight;
	TSplitter *spltrBottom;
	TSplitter *spltrLeft;
    
    void __fastcall pnlLeftSideDockOver(TObject *Sender,
          TDragDockObject *Source, int X, int Y, TDragState State,
          bool &Accept);
    void __fastcall pnlLeftSideDockDrop(TObject *Sender,
          TDragDockObject *Source, int X, int Y);
    void __fastcall pnlRightSideDockDrop(TObject *Sender,
          TDragDockObject *Source, int X, int Y);
    void __fastcall pnlBottomSideDockDrop(TObject *Sender,
          TDragDockObject *Source, int X, int Y);
    void __fastcall pnlLeftSideUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
    void __fastcall pnlRightSideUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
    void __fastcall pnlBottomSideUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
private:	// User declarations
    TWndMethod OldLeftDockWndProc;
    TWndMethod OldRightDockWndProc;
    TWndMethod OldBottomDockWndProc;
    void __fastcall LeftDockWindowProc(Messages::TMessage &Message);
    void __fastcall RightDockWindowProc(Messages::TMessage &Message);
    void __fastcall BottomDockWindowProc(Messages::TMessage &Message);
    void __fastcall ControlVisibilityChanged(TPanel* DockTarget,TControl* Control,bool Visible);
    int FDockIndex;
    void SetDockIndex(int aDockIndex);
public:		// User declarations
	__property int DockIndex = {read = FDockIndex,write = FDockIndex};
	__fastcall TBaseDockSiteForm(TComponent* Owner);
};
#endif
