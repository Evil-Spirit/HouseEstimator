//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "NomenclatureV.h"
#include "MDINomenclatureV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TNomenclature* CurNomenclature = NULL;

//--------------------TNomenclature-----------------------
TMyObject* TNomenclature::CreateFunction()
{
    return new TNomenclature();
}

const AnsiString aStringCode = AnsiString("StringCode");
const AnsiString aMeter = AnsiString("Meter");
const AnsiString aPrice = AnsiString("Price");
const AnsiString aWeight = AnsiString("Weight");
const AnsiString aSize = AnsiString("Size");
const AnsiString aDimensions = AnsiString("Dimensions");
const AnsiString aMemo = AnsiString("Memo");
const AnsiString aPME = AnsiString("PME");


TNomenclature::TNomenclature()
{
    RegisterNewClass< TMetaNode, TNomenclature >(this,false,&CreateFunction);
    RegisterField(&StringCode,&aStringCode,mtString);
    RegisterField(&Meter,&aMeter,mtString);
    RegisterField(&FSavePrice,&aPrice,mtDouble);

    RegisterField(&FSaveWeight,&aWeight,mtDouble);
    RegisterField(&Size,&aSize,mtIntVec);
    RegisterField(&Dimensions,&aDimensions,mtIntVec);
    RegisterField(&Memo,&aMemo,mtString);
    RegisterField(&PME,&aPME,mtMyObject);

    ImageIndex = iiNomenclature;
    ChildType = cNomenclature;
    FSavePrice = 0;
    FSaveWeight=0;
    Price = FSavePrice;
    Weight =FSaveWeight;
}

TNomenclature::TNomenclature(TMetaNode *_Parent,int _ID,const AnsiString& _Name)
{
    RegisterNewClass< TMetaNode, TNomenclature >(this,false,&CreateFunction);

    RegisterField(&StringCode,&aStringCode,mtString);
    RegisterField(&Meter,&aMeter,mtString);
    RegisterField(&FSavePrice,&aPrice,mtDouble);

    RegisterField(&FSaveWeight,&aWeight,mtDouble);
    RegisterField(&Size,&aSize,mtIntVec);
    RegisterField(&Dimensions,&aDimensions,mtIntVec);
    RegisterField(&Memo,&aMemo,mtString);
    RegisterField(&PME,&aPME,mtMyObject);

    ImageIndex = iiNomenclature;
    ChildType = cNomenclature;
    Parent = _Parent;
    FSavePrice = 0;
    FSaveWeight=0;
    Price = FSavePrice;
    Weight =FSaveWeight;

    Name = _Name;
}

void TNomenclature::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
    new TMDINomenclature(Owner,this);
    #endif
}

bool TNomenclature::UsedTrigger(int Trigger)
{
    return (Trigger == trView);
}

TNomenclature* FindNomenclatureByID(int ID)
{
    int total=TNomenclature::StaticType->GetRegInfoCount();
    TNomenclature *NOM = NULL;

    for (int i=0;i<total;i++)
    {
      NOM =((TNomenclature *)TNomenclature::StaticType->GetRegInfo(i)->Object);
      if (NOM->ID==ID)
        return NOM;
    }
    AnsiString STR = AnsiString("Nomenclature object whith ID ")+IntToStr(ID)+AnsiString(" is not found.");
    throw EMyException(STR);
    return NULL;
}



TNomenclature* FindNomenclatureByGUID(char* GUID)
{
    TNomenclature *NOM = (TNomenclature *)TNomenclature::StaticType->RecurrentFindByGUID(GUID);
    if (NOM)
        return NOM;
    else
    {
        AnsiString STR = AnsiString("Nomenclature object whith identifier ")+AnsiString(GUID)+AnsiString(" is not found.");
        throw EMyException(STR);
    }
}

TNomenclature* FindNomenclatureByName(char* _Name)
{
    TNomenclature* NOM = (TNomenclature*)TNomenclature::StaticType->RecurrentFindByName(_Name);
    if (NOM)
        return NOM;
    else
    {
        AnsiString STR = AnsiString("Nomenclature object whith name") + AnsiString(_Name) + AnsiString(" is not found.");
        throw EMyException(STR);
    }
}

TNomenclature* FindNomenclatureByStrCode(char* _StrCode)
{
    throw EMyException("<TNomenclature* TNomenclature::FindNomenclatureByStrCode> - Antiquated function .");
    
/*    AnsiString StringCode = AnsiString(_StrCode).Trim();
    TNomenclature *NOM = (TNomenclature *)MGT->FindByFieldValue(2,AnsiString("StringCode"),&StringCode);
    if (NOM)
        return NOM;
    else
    {
        AnsiString STR = AnsiString(" ") + AnsiString(_StrCode) + AnsiString(" ");
        throw EMyException(STR);
    }  */
}

TMetaElement* TNomenclature::GetAssociated()
{
    return PME.ADR;
}

bool TNomenclature::CheckFields()
{
    if (!TMetaNode::CheckFields())
        return false;
    Price = FSavePrice;
    Weight =FSaveWeight;
    return true;
}

void TNomenclature::SetSavePrice(double newPrice)
{
    FSavePrice = newPrice;
    Price = newPrice;
}

void TNomenclature::SetSaveWeight(double newWeight)
{
    FSaveWeight = newWeight;
    Weight = FSaveWeight;
}
