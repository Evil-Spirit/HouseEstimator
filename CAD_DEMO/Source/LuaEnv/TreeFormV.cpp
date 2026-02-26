// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------
#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "LuaModuleV.h"
#include "LuaStationV.h"
#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"
#include "TreeFormV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
//TStackWindow *StackWindow;

//---------------------------------------------------------------------------
 TTreeWindow::TTreeWindow(TComponent* Owner)
    : TMyMDIChild(Owner)
{
}
//---------------------------------------------------------------------------




