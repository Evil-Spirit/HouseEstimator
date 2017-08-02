//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "LuaStationV.h"
#include "LuaModuleV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TLuaStation LuaStation;

void RegisterLuaEnv()
{
    
}

#pragma startup RegisterLuaEnv 66

TLuaStation::TLuaStation()
{
  LMS = new TMTList<TLuaModule>();
}

TLuaStation::~TLuaStation()
{
  delete LMS;
}

AnsiString TLuaStation::Register(TLuaModule *Module)
{
  for (int i=0;i<LMS->Count;i++)
    if (LMS->Items[i] == Module)
      return MODULE_+IntToStr(i);
  LMS->Add(Module);
  return MODULE_+IntToStr(LMS->Count-1);
}

void TLuaStation::UnRegister(TLuaModule *Module)
{
  for (int i=0;i<LMS->Count;i++)
    if (LMS->Items[i] == Module)
    {
      LMS->Items[i] = NULL;
      return;
    }
}

bool CheckWholeWord(const AnsiString& Text,int index,int Length)
{
    //check left
    bool left_ok = true;
    if (index!=1)
    {
        left_ok = left_ok && _ABC_.Pos(Text[index-1])==0;
        left_ok = left_ok && RUS_ABC_.Pos(Text[index-1])==0;
        left_ok = left_ok && Text[index-1] != '_';
    }
    bool right_ok = true;
    if (index+Length != Text.Length())
    {
        right_ok = right_ok && _ABC_.Pos(Text[index+Length])==0;
        right_ok = right_ok && RUS_ABC_.Pos(Text[index+Length])==0;
        right_ok = right_ok && Text[index+Length] != '_';
    }
    return right_ok && left_ok;
}

void TLuaStation::FindInAllModules(const AnsiString& Text, TFindOptions FO)
{
    AnsiString FindText = Text;
    int Length = FindText.Length();
    AnsiString TextToFind;
    if (!FO.Contains(frMatchCase))
        FindText = FindText.LowerCase();
    StdOut("Поиск во всех модулях",true);
    AnsiString TEXT_;
    for (int i=0;i<LMS->Count;i++)
    {
        if (LMS->Items[i] == NULL)
            continue;
        TextToFind = LMS->Items[i]->CODE;
        if (!FO.Contains(frMatchCase))
            TextToFind = TextToFind.LowerCase();
        int index = TextToFind.Pos(FindText);
        TEXT_ = LMS->Items[i]->Name + AnsiString(" ") + LMS->Items[i]->Description
            + AnsiString(" ") + LMS->Items[i]->_ModuleName;
        while (index!=0 )
        {
            StdOut(TEXT_,false);
            //if ( !FO.Contains(frWholeWord) || CheckWholeWord(TextToFind,index,Length) )
                //LinkStdOut(TEXT_,false,LMS->Items[i],index,index+Length);
            TextToFind.Delete(index,Length);
            TextToFind.Insert(AnsiString().StringOfChar(' ',Length),index);
            index = TextToFind.Pos(FindText);
        }
    }
}

TLuaModule* TLuaStation::FindByName(const AnsiString& aName)
{
    for (int i=0;i<LMS->Count;i++)
        if ( LMS->Items[i] && LMS->Items[i]->_ModuleName == aName )
            return LMS->Items[i];
    return NULL;
}

void TLuaStation::SaveData(FILE *f)
{
    LMS->SaveData(f);
}

void TLuaStation::LoadData(FILE *f)
{
    LMS->LoadData(f);
}


