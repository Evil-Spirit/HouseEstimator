//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#include "RegisterArchitectureV.h"
#include "CustomElementV.h"
#include "PlatformV.h"
#include "RoomV.h"
#include "WallV.h"
#include "NomenclatureV.h"
#include "UI.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
bool ArchitectureIsRegistered = false;

void RegisterArchitecture()
{
    if (ArchitectureIsRegistered)
        return;

    TCustomMetaElement();
    TMetaCube();
    TMetaPlatform();
    TMetaRoom();
    TNomenclature();
    TRoom();
    TMetaActionList();
    TMetaAction();
    TMetaUI();
    TMetaMenuItem();
    TCube();
    TCustomElement();
    TPlatform();

    TMetaUI::StaticType->UniqueNameFlag = true;
    TNomenclature::StaticType->UniqueNameFlag = true;

    ArchitectureIsRegistered = true;
}


