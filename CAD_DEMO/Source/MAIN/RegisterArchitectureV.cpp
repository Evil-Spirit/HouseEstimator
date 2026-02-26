// [migrated-to-qt]
#ifndef __BORLANDC__
#include "compat/borland.h"
#endif
//---------------------------------------------------------------------------


#include "compat/vcl_qt.h"
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"

#include "RegisterArchitectureV.h"
#include "CustomElementV.h"
#include "PlatformV.h"
#include "RoomV.h"
#include "WallV.h"
#include "NomenclatureV.h"
#include "UI.h"

//---------------------------------------------------------------------------

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


