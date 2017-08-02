//---------------------------------------------------------------------------


#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
      
#include "RegisterKernelV.h"
#include "Label3DV.h"
#include "MultiElementV.h"
#include "OutPutV.h"
#include "MetaToolV.h"
#include "CustomElementV.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
 //---------------------------------------------------------------------------

#include "AddLuaVarV.h"
#include "CatalogUnitV.h"
#include "MyMDIChildV.h"
#include "Driver.h"
#include "GenImageV.h"
#include "IntExplorerV.h"
#include "LinkGeometry.h"
#include "LogicNode.h"
//#include "LOGOV.h"
#include "LuaUniFormV.h"
#include "LuaVarsEditV.h"
#include "MDI3DUserV.h"
#include "MDI3DV.h"
#include "MDIActionsEditV.h"
#include "MDIBMPSetEditV.h"
#include "MDIBMPSetV.h"
#include "MDIBoolVectorEditV.h"
#include "MDICanExistsCheckEditV.h"
#include "MDIColorsV.h"
#include "MDIConnectV.h"
#include "MDIDynamicLinkEditV.h"
#include "MDIElementSelectV.h"
#include "MDIElementV.h"
#include "MDIEpsEditV.h"
#include "MDIHasAngleV.h"
#include "MDIHasSizeV.h"
#include "MDIHasStepV.h"
//#include "MDILuaEditorV.h"
#include "MDIMetaCatalogUnitV.h"
#include "MDIMetaMaterialV.h"
#include "MDIMetaMyModeV.h"
#include "MDIMetaNodeV.h"
#include "MDIMetaTextureV.h"
#include "MDIMetaVisParamV.h"
#include "MDIMyModeSettingListEditV.h"
#include "MDIMyModeSettingsEditV.h"
#include "MDIMyTextureFlagsEditV.h"
#include "MDIMyTextureModesListV.h"
#include "MDIMyTextureModesV.h"
#include "MDIObjectEditV.h"
#include "MDIPointerEditV.h"
#include "MDIPointerListEditV.h"
#include "MDISelectClassV.h"
#include "MDISignVectorEditV.h"
#include "MDITextureV.h"
#include "MDITriggerBlockEditV.h"
#include "MDITVV.h"
#include "MDIVectorEditV.h"
#include "MDIViewSettingsV.h"
#include "TasksQueueV.h"
#include "MetaClasses.h"
#include "MetaNodeCollectionV.h"
#include "MyGL.h"
#include "OutPutV.h"
#include "Poligon.h"
#include "QuckList.h"
#include "Select.h"
#include "SelectBMPV.h"
#include "SimpleEditV.h"
#include "Triangulation.h"
#include "UNDO.h"
#include "World.h"
#include "LuaAttributeV.h"

#include "LuaModuleV.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
bool KernelIsRegistered = false;

void RegisterKernel()
{
    if (KernelIsRegistered)
        return;

    TMyRegObject();
    TFloor();
    THoleClient();
    TRenderParam();
    TFragmentSettings();
    THasStep();
    THasAngle();

    TMetaEps();
    TMyColor();
    TBMPPointer();
    TMyTextureFlags();
    TMyTextureModes();

    TMyTextureModesList();
    TMyActionSettings();
    TCanExistCheck();
    TLuaAttribute();
    TPolygon();
    THoledPolygon();

    TLuaModule();
    TTriggerBlock();
    TMyRegTree();
    TMyModeSettings();

    TMetaNode();
    TMetaLink();
    TDynamicLink();
    TMetaElement();
    TMetaLabel3D();

    TBMPSet();
    TMetaMaterial();
    TMetaTexture();

    TMetaMyMode();
    TMetaVisParam();
    TMetaCatalogUnit();

    TUnit();
    TLink();
    /* TODO : срочно откомментировать *///TElement();
    TLabel3D();
    TMetaMultiElement();
    TMultiElement();
    TCustomElement();
    TMetaTool();

    TMetaNode::StaticType->UniqueNameFlag = true;
    TUnit::StaticType->UniqueNameFlag = true;
    TMetaCatalogUnit::StaticType->UniqueNameFlag = true;

    TMetaNodeCollection::TypesToEdit.Add(TMetaElement::StaticType);
    TMetaElement::StaticType->MnChDescription = "Elements";
    TMetaElement::StaticType->ImageIndex = iiElements;

    TMetaNodeCollection::TypesToEdit.Add(TMetaLink::StaticType);
    TMetaLink::StaticType->MnChDescription = "Links";
    TMetaLink::StaticType->ImageIndex = iiLinks;

    TMetaNodeCollection::TypesToEdit.Add(TBMPSet::StaticType);
    TBMPSet::StaticType->MnChDescription = "Pictures";
    TBMPSet::StaticType->ImageIndex = iiBMPSets;

    TMetaNodeCollection::TypesToEdit.Add(TMetaMaterial::StaticType);
    TMetaMaterial::StaticType->MnChDescription = "Materials";
    TMetaMaterial::StaticType->ImageIndex = iiMaterials;

    TMetaNodeCollection::TypesToEdit.Add(TMetaTexture::StaticType);
    TMetaTexture::StaticType->MnChDescription = "Textures";
    TMetaTexture::StaticType->ImageIndex = iiTextures;

    TMetaNodeCollection::TypesToEdit.Add(TMetaMyMode::StaticType);
    TMetaMyMode::StaticType->MnChDescription = "Modes";
    TMetaMyMode::StaticType->ImageIndex = iiMetaMyModes;

/*    TMetaNodeCollection::TypesToEdit.Add(TMetaActionList::StaticType);
    TMetaActionList::StaticType->MnChDescription = "Modules";
    TMetaActionList::StaticType->ImageIndex = iiMetaLUA;

    TMetaNodeCollection::TypesToEdit.Add(TMetaUI::StaticType);
    TMetaUI::StaticType->MnChDescription = "Interface";
    TMetaUI::StaticType->ImageIndex = iiMetaUI;  */

    TMetaNodeCollection::TypesToEdit.Add(TMetaCatalogUnit::StaticType);
    TMetaCatalogUnit::StaticType->MnChDescription = "Catalog";
    TMetaCatalogUnit::StaticType->ImageIndex = iiMetaCatalogUnit;

    TMetaNodeCollection::TypesToEdit.Add(TMetaTool::StaticType);
    TMetaTool::StaticType->MnChDescription = "Tools";
    TMetaTool::StaticType->ImageIndex = iiMetaTools;
    
    SetStdOut(&MyStdOut);
    KernelIsRegistered = true;

    /*    TCustomMetaElement();
    TMetaCube();
    TMetaPlatform();
    TMetaRoom();
    TMetaMultiElement();
    TNomenclature();
    TRoom();
    TMetaActionList();
    TMetaAction();
    TMetaUI();
    TMetaMenuItem();
    TCube();
    TCustomElement();
    TPlatform();
    TMultiElement();
*/
} 
