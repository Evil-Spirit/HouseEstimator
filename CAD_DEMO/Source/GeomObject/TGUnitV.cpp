//---------------------------------------------------------------------------


#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#include <vcl.h>
#pragma hdrstop

#include "TGUnitV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
TClassNode* TGBaseLink::StaticType = NULL;
TClassNode* TGUnit::StaticType = NULL;

AnsiString MBTiToStrF(MBTi Value,int Precision)
{
    return FloatToStrF(Value,ffGeneral,4,Precision);
}

TMyObject* TGBaseLink::CreateFunction()
{
    return new TGBaseLink();
}

const AnsiString aClient0 = AnsiString("Client0");
const AnsiString aClient1 = AnsiString("Client1");
const AnsiString aColor = AnsiString("Color");
const AnsiString aPosition = AnsiString("Position");
const AnsiString aLinkDirection = AnsiString("LinkDirection");
const AnsiString aGUID = AnsiString("GUID");

TGBaseLink::TGBaseLink()
{
    RegisterNewClass<TMyObject,TGBaseLink>(this,false,&CreateFunction);
    RegisterField(&FClients[0],&aClient0,mtMyObject);
    RegisterField(&FClients[1],&aClient1,mtMyObject);
    RegisterField(&Position,&aPosition,mtIntVec);
    RegisterField(&LinkDirection,&aLinkDirection,mtInt);
    RegisterField(&FGUID,&aGUID,mtString);

    Label = new TVisLabel(NULL);
    Label->Transformation->Order = toTraRotSca;
    VCO = new TVisPrimitiveObj(NULL);
    VCO->Transformation->Order = toTraRotSca;
    LinkDirection = ld1To0;
    Visible = true;
}

TGBaseLink::~TGBaseLink()
{
    Client0 = NULL;
    Client1 = NULL;
    delete Label;
    delete VCO;
}

void TGBaseLink::SetClient(int index,TGUnit* Client)
{
    if ( index<0 || index>1 )
        throw EMyException(AnsiString("<TGBaseLink::SetClient>: неверный индекс клиента связки - ") + IntToStr(index) );

    if ( FClients[index].ADR )
        FClients[index].ADR->Remove(this);
    FClients[index].ADR = Client;
    if ( FClients[index].ADR )
        FClients[index].ADR->Add(this);
}

TGUnit* TGBaseLink::GetClient(int index)
{
    if ( index<0 || index>1 )
        throw EMyException(AnsiString("<TGBaseLink::SetClient>: неверный индекс клиента связки - ") + IntToStr(index) );

    return FClients[index].ADR;
}

TMyObject* TGUnit::CreateFunction()
{
    return new TGUnit();
}

bool TGUnit::GetFixed()
{
    return FFixed;
}

void TGUnit::SetFixed(bool Value)
{
    FFixed = Value;
}


int TGUnit::GetLinksCount() const
{
    return FLinks.Count;
}

const AnsiString aLinks = AnsiString("Links");
const AnsiString aFixed = AnsiString("Fixed");

TGUnit::TGUnit()
{
    RegisterNewClass<TMyObject,TGUnit>(this,false,&CreateFunction);
    RegisterField(&FGUID,&aGUID,mtString);
    RegisterField(&FLinks,&aLinks,mtMyObject);
    RegisterField(&FFixed,&aFixed,mtBool);
}

TGUnit::~TGUnit()
{
	for (int i=0;i<FLinks.Count;)
		if (FLinks[i].ADR->Client0 == this)
			FLinks[i].ADR->Client0 = NULL;
		else if (FLinks[i].ADR->Client1 == this)
			FLinks[i].ADR->Client1 = NULL;
		else
			i++;
}

bool TGBaseLink::ConsistsClient(TGUnit* aClient)
{
    return ((aClient == FClients[0].ADR) || (aClient == FClients[1].ADR));
}

TGUnit* TGBaseLink::AnotherClient(TGUnit* aClient)
{
    if ( aClient == FClients[0].ADR )
        return FClients[1].ADR;
    else if ( aClient == FClients[1].ADR )
        return FClients[0].ADR;

    throw EMyException("<TGUnit::AnotherClient>: Клиент не принадлежит связке.");
}

TGBaseLink& TGUnit::GetLink(int index)
{
    return *FLinks[index].ADR;
}


const TGBaseLink& TGUnit::GetLink(int index) const
{
    return *FLinks[index].ADR;
}

int TGUnit::Remove( TGBaseLink* aGLink)
{
    for ( bool OK = FLinks.Start();OK;OK = FLinks.Next() )
        if ( FLinks.GetCurrent()->ADR == aGLink )
        {
            int ret = FLinks.CurrentIndex;
            FLinks.Delete( ret );
            return ret;
        }
    return -1;        
}

int TGUnit::Add( TGBaseLink* aGLink)
{
    return FLinks.Add( new TPointer<TGBaseLink>(aGLink) );
}

