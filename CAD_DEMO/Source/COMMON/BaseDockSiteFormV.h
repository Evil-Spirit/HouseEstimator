// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#ifndef BaseDockSiteFormVH
#define BaseDockSiteFormVH
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
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
    
    void  pnlLeftSideDockOver(TObject *Sender,
          TDragDockObject *Source, int X, int Y, TDragState State,
          bool &Accept);
    void  pnlLeftSideDockDrop(TObject *Sender,
          TDragDockObject *Source, int X, int Y);
    void  pnlRightSideDockDrop(TObject *Sender,
          TDragDockObject *Source, int X, int Y);
    void  pnlBottomSideDockDrop(TObject *Sender,
          TDragDockObject *Source, int X, int Y);
    void  pnlLeftSideUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
    void  pnlRightSideUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
    void  pnlBottomSideUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
private:	// User declarations
    TWndMethod OldLeftDockWndProc;
    TWndMethod OldRightDockWndProc;
    TWndMethod OldBottomDockWndProc;
    void  LeftDockWindowProc(Messages::TMessage &Message);
    void  RightDockWindowProc(Messages::TMessage &Message);
    void  BottomDockWindowProc(Messages::TMessage &Message);
    void  ControlVisibilityChanged(TPanel* DockTarget,TControl* Control,bool Visible);
    int FDockIndex;
    void SetDockIndex(int aDockIndex);
public:		// User declarations
	// __property int DockIndex {read=FDockIndex, write=FDockIndex}; // [manual migration needed]
	 TBaseDockSiteForm(TComponent* Owner);
};
#endif
