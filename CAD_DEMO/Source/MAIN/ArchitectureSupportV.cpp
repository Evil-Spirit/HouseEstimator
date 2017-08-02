//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "ArchitectureSupportV.h"
#include "World.h"
#include "RoomV.h"
#include "PlatformV.h"
#include "Label3DV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

TMyObject* TArchitectSupport::CreateFunction()
{
    return new TArchitectSupport();
}

const AnsiString aAFirstPlatform = AnsiString("AFirstPlatform");
const AnsiString aADefaultLand = AnsiString("ADefaultLand");
const AnsiString aAPlatform_Land = AnsiString("APlatform_Land");

TArchitectSupport::TArchitectSupport()
{
    RegisterNewClass< TMySupport,TArchitectSupport >(this,false,&CreateFunction);

    RegisterField(&AFirstPlatform,&aAFirstPlatform,mtMyObject);
    RegisterField(&ADefaultLand,&aADefaultLand,mtMyObject);
    RegisterField(&APlatform_Land,&aAPlatform_Land,mtMyObject);
};

TMetaPlatform* TArchitectSupport::GetFirstPlatform()
{
    return AFirstPlatform.ADR;
}

TMetaPlatform* TArchitectSupport::GetDefaultLand()
{
    return ADefaultLand.ADR;
}


TDynamicLink* TArchitectSupport::GetPlatform_Land()
{
    return APlatform_Land.ADR;
}

void TArchitectSupport::Edit(TComponent *Owner,TWinControl *Parent,void *Data)
{
    #if !defined(INTERNET_VER) && !defined(TRADE_VER)
//    new TMDIArchiVarsEdit(Owner,Parent,this,"Basic variables",Data);
    #endif
}

void TArchitectSupport::PreProcessActions()
{
/*    if (!FirstPlatform)
    {
        Application->MessageBox("Standart First TPlatform не найден","Error");
        inited = false;
        return;
    }
    if (!DefaultLand)
    {
        Application->MessageBox("DefaultLand не найден","Error");
        inited = false;
        return;
    }
    if (!MetaLabel3D)
    {
        Application->MessageBox("Standart MetaLabel3D не найден","Error");
        inited = false;
        return;
    }
    if (!MetaLabelLink)
    {
        Application->MessageBox("Standart MetaLabelLink не найден","Error");
        inited = false;
        return;
    }
    if (!Platform_Land)
    {
        Application->MessageBox("Standart Platform_Land_Link не найден","Error");
        inited = false;
        return;
    }
    if (!DEFAULT_SIZE)
    {
        Application->MessageBox("Standart DEFAULT_SIZE не найден","Error");
        inited = false;
        return;
    }
    if (!DEFAULT_MODE)
    {
        Application->MessageBox("Standart DEFAULT_MODE не найден","Error");
        inited = false;
        return;
    }
    if (!_3D_MODE)
    {
        Application->MessageBox("Standart _3D_MODE не найден","Error");
        inited = false;
        return;
    }

    if (FirstPlatform && MetaLabel3D)
        FreeLink(FirstPlatform,MetaLabel3D);
    inited = true;    */
}

void TArchitectSupport::AfterProcessActions()
{
    //do nothing
}

double PACKAGE GetTotalArea(TMainTree* aWorld,int FloorIndex)
{
    double total = 0;
    TMTList<TMyRegObject> LST;
    aWorld->SelectByCT(NULL,TRoom::StaticType,&LST,true,true);
    for (int i=0;i<LST.Count;i++)
    {
        TRoom* Room = (TRoom*)LST.Items[i];
        if (Room->Status==0)
            continue;
        if ( ( FloorIndex == -1 ) ||
             ( FloorIndex >= 0  ) &&
             ( FloorIndex <  aWorld->Floors.Count ) &&
             ( aWorld->Floors[FloorIndex].First.ADR ) &&
             ( Room->In(aWorld->Floors[FloorIndex].First.ADR) )
           )
            total += Room->HP->CentralArea();
    }
    return total;
}