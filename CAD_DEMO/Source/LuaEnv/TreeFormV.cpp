//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LuaModuleV.h"
#include "LuaStationV.h"
#include "LuaEnvV.h"
#include "LuaEditorV.h"
#include "VCLSCILEXERV.h"
#include "TreeFormV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TStackWindow *StackWindow;

//---------------------------------------------------------------------------
__fastcall TTreeWindow::TTreeWindow(TComponent* Owner)
    : TMyMDIChild(Owner)
{
}
//---------------------------------------------------------------------------




