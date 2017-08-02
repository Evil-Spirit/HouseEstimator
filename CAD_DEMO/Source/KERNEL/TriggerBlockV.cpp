//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
           

#include "MDITriggerBlockEditV.h"
//#include "Main.h"
//#include "InterFace.h"
//nclude "QuckList.h"
//nclude "LuaUniFormV.h"

#include "TriggerBlockV.h"
#include "LuaModuleV.h"
#include "AUIV.h"
#include "MDI3DV.h"
#include "LuaUniFormV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
TClassNode* TTriggerBlock::StaticType = NULL;

void TTriggerBlock::SetName(const AnsiString &vName)
{
    TMyObject::SetName(vName);
    for (int i=0;i<According->Count;i++)
        Modules->Items[According->Items[i]->intX()]->Name = Name + AnsiString(" ") + TriggerTypeStr[According->Items[i]->intY()];
}

const AnsiString aName = AnsiString("Name");
const AnsiString aModules = AnsiString("Modules");
const AnsiString aAccording = AnsiString("According");

TMyObject* TTriggerBlock::CreateFunction()
{
    return new TTriggerBlock();
}

TTriggerBlock::TTriggerBlock()
{
    RegisterNewClass< TMyObject, TTriggerBlock >(this,false,&CreateFunction);
    Modules = new /*TMDelLSTList*/TMDelTList<TLuaModule>();
    According = new /*TMDelLSTList*/TMDelTList<TIntVec>();
    FastRunList = new TMTList<TLuaModule>;
    RegisterField(&Name,&aName,mtString);
    RegisterField(Modules,&aModules,mtMyObject);
    RegisterField(According,&aAccording,mtMyObject);
}

TTriggerBlock::~TTriggerBlock()
{
    delete Modules;
    delete According;
    delete FastRunList;
}

void TTriggerBlock::AddTrigger(int TriggerType)
{
    for (int i=0;i<According->Count;i++)
        if (According->Items[i]->intY() == TriggerType)
            return;
    Modules->Add ( new TLuaModule() );
    Modules->Items[Modules->Count-1]->Name = Name+AnsiString(" ")+TriggerTypeStr[TriggerType];
    According->Add ( new TIntVec(Modules->Count-1, TriggerType, 0) );
    CheckFields();
}

void TTriggerBlock::DeleteTrigger(int TriggerType)
{
    for (int i=0;i<According->Count;i++)
        if (According->Items[i]->y == TriggerType)
        {
            for (int j=0;j<According->Count;j++)
                if (According->Items[j]->intX()>According->Items[i]->intX())
                    According->Items[j]->x = According->Items[j]->intX()-1;
            Modules->Delete(According->Items[i]->intX());
            According->Delete(i);
            break;
        }
    CheckFields();
}

bool RunForm(TLuaModule* LM)
{
    if (LM->HasForm)
    {
        TComponent* _Owner = AUI.ActiveView;
        if (!_Owner)
            _Owner = ComponentExists(__classid(TMDI3D));
        if (!_Owner)
            _Owner = Application->MainForm;
        if (!_Owner)
            _Owner = Application;
        bool result;
        TLuaUniForm *LF = new TLuaUniForm(_Owner,LM);
        result = LM->Run();
        delete LF;
        return result;
    }
    else
        return LM->Run();
}

TLuaModule *TEMP_LM;
bool TTriggerBlock::Run(int TriggerType)
{
    if (TriggerType>=FastRunList->Count)
        return false;
    TEMP_LM = FastRunList->Items[TriggerType];
    if (!TEMP_LM)
        return false;
    return RunForm(TEMP_LM);
}

TLuaModule *TTriggerBlock::GetModule(int TriggerType)
{
    if (TriggerType>=FastRunList->Count)
        return NULL;
    return FastRunList->Items[TriggerType];
}

bool TTriggerBlock::Exists(int TriggerType)
{
    return GetModule(TriggerType) != NULL;
}


void TTriggerBlock::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDITriggerBlockEdit(Owner,Parent,this,"Triggers",Data);
    #endif
}

bool TTriggerBlock::CheckFields()
{
    FastRunList->Clear();
    for (int i=0;i<According->Count;i++)
    {
        while (According->Items[i]->intY() >= FastRunList->Count)
            FastRunList->Add(NULL);
        FastRunList->Items[According->Items[i]->intY()] = Modules->Items[According->Items[i]->intX()];
    }
    return true;
}

