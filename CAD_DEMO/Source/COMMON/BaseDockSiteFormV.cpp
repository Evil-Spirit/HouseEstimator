// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "BaseDockSiteFormV.h"
#include "FloatingV.h"
//---------------------------------------------------------------------------
// NOTE: The docking implementation (TDragDockObject, WindowProc message
// routing, VCL panel/splitter positioning) is Windows/VCL-specific and
// has no direct Qt equivalent.  All methods below are stubs that keep the
// code compiling; actual docking behaviour must be re-implemented with
// Qt dock widgets (QDockWidget) if needed.
//---------------------------------------------------------------------------

TBaseDockSiteForm::TBaseDockSiteForm(TComponent* Owner)
    : TBaseForm(Owner)
{
    pnlLeftSide   = nullptr;
    pnlRightSide  = nullptr;
    pnlBottomSide = nullptr;
    StatusBar     = nullptr;
    spltrLeft     = nullptr;
    spltrRight    = nullptr;
    spltrBottom   = nullptr;
    FDockIndex    = 0;
}

void TBaseDockSiteForm::LeftDockWindowProc(Messages::TMessage& /*Message*/) {}
void TBaseDockSiteForm::RightDockWindowProc(Messages::TMessage& /*Message*/) {}
void TBaseDockSiteForm::BottomDockWindowProc(Messages::TMessage& /*Message*/) {}

void TBaseDockSiteForm::ControlVisibilityChanged(TPanel* /*DockTarget*/,
                                                  TControl* /*Control*/,
                                                  bool /*Visible*/) {}

void TBaseDockSiteForm::pnlLeftSideDockOver(TObject* /*Sender*/,
                                             TDragDockObject* /*Source*/,
                                             int /*X*/, int /*Y*/,
                                             TDragState /*State*/,
                                             bool& /*Accept*/) {}

void TBaseDockSiteForm::pnlLeftSideDockDrop(TObject* /*Sender*/,
                                             TDragDockObject* /*Source*/,
                                             int /*X*/, int /*Y*/) {}

void TBaseDockSiteForm::pnlRightSideDockDrop(TObject* /*Sender*/,
                                              TDragDockObject* /*Source*/,
                                              int /*X*/, int /*Y*/) {}

void TBaseDockSiteForm::pnlBottomSideDockDrop(TObject* /*Sender*/,
                                               TDragDockObject* /*Source*/,
                                               int /*X*/, int /*Y*/) {}

void TBaseDockSiteForm::pnlLeftSideUnDock(TObject* /*Sender*/,
                                           TControl* /*Client*/,
                                           TWinControl* /*NewTarget*/,
                                           bool& /*Allow*/) {}

void TBaseDockSiteForm::pnlRightSideUnDock(TObject* /*Sender*/,
                                            TControl* /*Client*/,
                                            TWinControl* /*NewTarget*/,
                                            bool& /*Allow*/) {}

void TBaseDockSiteForm::pnlBottomSideUnDock(TObject* /*Sender*/,
                                             TControl* /*Client*/,
                                             TWinControl* /*NewTarget*/,
                                             bool& /*Allow*/) {}

void TBaseDockSiteForm::SetDockIndex(int aDockIndex)
{
    FDockIndex = aDockIndex;
}

