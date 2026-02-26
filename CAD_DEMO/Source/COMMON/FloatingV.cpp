// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
// NOTE: TFloatForm and TMyControlState use VCL docking/floating window
// mechanics (Windows messages, Parent property, Align, Width/Height as
// settable properties, Invalidate(), LRDockWidth, etc.) that have no direct
// Qt equivalent.  All method bodies are stubs.  Actual floating/docking
// should be implemented with QDockWidget if needed.
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "FloatingV.h"
#include "BaseDockSiteFormV.h"

//---------------------------------------------------------------------------
TMyControlState::TMyControlState()
    : Width(-1000), Height(-1000), Align(-1000), Left(-1000), Top(-1000),
      Parent(nullptr)
{}

void TMyControlState::ApplyToControl(TControl* /*Control*/) {}

//---------------------------------------------------------------------------
TFloatForm::TFloatForm(TComponent* Owner)
    : TBaseForm(Owner)
{
    NeedToResize  = true;
    DoRestoreSize = false;
    FFixed        = false;
    FAL           = AlignBottom;
    FDefaultSize  = 130;
    FFixedSize    = 22;
    FDockIndex    = 0;
}

void TFloatForm::SetAL(int aAL)          { FAL = aAL; }
void TFloatForm::SetFixed(bool aFixed)   { FFixed = aFixed; }
void TFloatForm::SetFixedSize(int s)     { FFixedSize = s; }
void TFloatForm::SetDefaultSize(int s)   { FDefaultSize = s; }
void TFloatForm::SetDockIndex(int idx)   { FDockIndex = idx; }

void TFloatForm::FormEndDock(TObject* /*Sender*/, TObject* /*Target*/,
                              int /*X*/, int /*Y*/) {}

int  TFloatForm::GetParentDockIndex(TWinControl* /*aParent*/) { return -1; }
