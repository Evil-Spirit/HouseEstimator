//---------------------------------------------------------------------------

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "MainV.h"
#include "LuaEditorV.h"
#include "LuaEnvV.h"
#include "LuaModuleV.h"
#include "LuaStationV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain *Main;
//---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner)
    : TForm(Owner)
{
    this->TabStop = true;
}
//---------------------------------------------------------------------------
void __fastcall TMain::FormCreate(TObject *Sender)
{
    LuaAllOpen();
    LM = new TLuaModule();
    CreateEditor(this,LM);
    LE = new TLuaEditorInterface(this,LM);
//    LuaStation.UnRegister(LM);
}
//---------------------------------------------------------------------------
void __fastcall TMain::FormClose(TObject *Sender, TCloseAction &Action)
{
    delete LE;
    delete LM;
    LuaAllClose();    
}
//---------------------------------------------------------------------------

void __fastcall TMain::FormShortCut(TWMKey &Msg, bool &Handled)
{
    LE->FormShortCut(Msg,Handled);    
}
//---------------------------------------------------------------------------

