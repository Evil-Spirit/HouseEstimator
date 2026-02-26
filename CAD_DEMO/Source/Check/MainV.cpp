// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------

#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "MainV.h"
#include "LuaEditorV.h"
#include "LuaEnvV.h"
#include "LuaModuleV.h"
#include "LuaStationV.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMain *Main;
//---------------------------------------------------------------------------
 TMain::TMain(TComponent* Owner)
    : TForm(Owner)
{
    this->TabStop = true;
}
//---------------------------------------------------------------------------
void  TMain::FormCreate(TObject *Sender)
{
    LuaAllOpen();
    LM = new TLuaModule();
    CreateEditor(this,LM);
    LE = new TLuaEditorInterface(this,LM);
//    LuaStation.UnRegister(LM);
}
//---------------------------------------------------------------------------
void  TMain::FormClose(TObject *Sender, TCloseAction &Action)
{
    delete LE;
    delete LM;
    LuaAllClose();    
}
//---------------------------------------------------------------------------

void  TMain::FormShortCut(TWMKey &Msg, bool &Handled)
{
    LE->FormShortCut(Msg,Handled);    
}
//---------------------------------------------------------------------------

