//---------------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "SkinEngineV.h"
#pragma link "SUISkinEngine"
TsuiSkinEngine* fSkinEngine = NULL;

TsuiSkinEngine *GetSkinEngine()
{
  if (fSkinEngine==NULL)
  {
    TForm *HiddenForm  = new TForm(Application);
    HiddenForm->Visible = false;
    fSkinEngine = new TsuiSkinEngine(HiddenForm);
    fSkinEngine->SkinFile = GetSkinFile();
    fSkinEngine->Active = true;
  }
  return fSkinEngine;
}

void WorldInit()
{
  GetSkinEngine();
}
#pragma startup WorldInit

AnsiString GetSkinFile()
{
  return AnsiString(MainDir+"\\Longhorn.sui");
}
//////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------

#pragma package(smart_init)
