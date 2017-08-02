 //---------------------------------------------------------------------
#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("main.cpp", Config);
USEFORM("MyMDIChildV.cpp", MyMDIChild);
USEFORM("about.cpp", AboutBox);
USEFORM("MDI3DV.cpp", MDI3D);
USEFORM("MDITVV.cpp", MDITV);
USEFORM("MDI3DUserV.cpp", MDI3DUser);
USEFORM("OutPutV.cpp", OutPut);
USEFORM("MDICountReportV.cpp", MDICountReport);
USEFORM("SelectBMPV.cpp", SelectBMP);
USEFORM("LOGOV.cpp", Logo);
USEFORM("MDI2DV.cpp", MDI2D);
USEFORM("DrawViewV.cpp", DrawView);
USEFORM("MDIVisibleSelectFloorV.cpp", MDIVisibleSelectFloor);
USEFORM("LuaUniFormV.cpp", LuaUniForm);
USEFORM("MDIViewSettingsV.cpp", MDIViewSettings);
USEFORM("PBV.cpp", PB);
USEFORM("IntExplorerV.cpp", IntExplorer);
USEFORM("MDILuaEditorV.cpp", LuaEditor);
USEFORM("ExcelExchangeV.cpp", ExcelExchange);
USEFORM("RegisterModule.cpp", Form1);
//---------------------------------------------------------------------------
#if !defined(INTERNET_VER) && !defined(TRADE_VER)
USEFORM("MDIConfigV.cpp", MDIConfig);
USEFORM("MDIMetaNodeV.cpp", MDIMetaNode);
USEFORM("MDIElementV.cpp", MDIElement);
USEFORM("MDIConnectV.cpp", MDIConnect);
USEFORM("MDIObjectEditV.cpp", MDIObjectEdit);
USEFORM("MDITransformationV.cpp", MDITransformation);
USEFORM("MDIVectorEditV.cpp", MDIVECEDIT);
USEFORM("MDISignVectorEditV.cpp", MDISIGNVECEDIT);
USEFORM("MDIBoolVectorEditV.cpp", MDIBOOLVECEDIT);
USEFORM("MDIHasAngleV.cpp", MDIAngle);
USEFORM("MDIHasSizeV.cpp", MDISize);
USEFORM("MDIDynamicLinkEditV.cpp", MDIDynamicLinkEdit);
USEFORM("IMPORTV.cpp", IMPORT);
USEFORM("MDIColorsV.cpp", MDIColors);
USEFORM("MDISelectClassV.cpp", MDISelectClass);
USEFORM("MDICustomElementV.cpp", MDICustomElement);
USEFORM("MDICubeV.cpp", MDICube);
USEFORM("MDIEpsEditV.cpp", MDIEpsEdit);
USEFORM("Unit1.cpp", Form1);
USEFORM("MDIMetaRoomV.cpp", MDIMetaRoom);
USEFORM("MDIMetaPlatformV.cpp", MDIMetaPlatform);
USEFORM("MDIActionsEditV.cpp", MDIActionsEdit);
USEFORM("MDIMultiElementV.cpp", MDIMultiElement);
USEFORM("MDICheckV.cpp", MDICheck);
USEFORM("MDILuaEditorV.cpp", LuaEditor);
USEFORM("MDIElementSelectV.cpp", MDIElementSelect);
USEFORM("AddLuaVarV.cpp", AddLuaVar);
USEFORM("MDINomenclatureV.cpp", MDINomenclature);
USEFORM("MDIFLOATVECEDITV.cpp", MDIFLOATVECEDIT);
USEFORM("MDIBMPSetEditV.cpp", MDIBMPSetEdit);
USEFORM("MDIBMPSetV.cpp", MDIBMPSet);
USEFORM("MDIMetaMaterialV.cpp", MDIMetaMaterial);
USEFORM("MDIPointerEditV.cpp", MDIPointerEdit);
USEFORM("MDIFloorV.cpp", F);
USEFORM("MDITriggerBlockEditV.cpp", MDITriggerBlockEdit);
USEFORM("MDIMetaMyModeV.cpp", MDIMetaMyMode);
USEFORM("MDIMyModeSettingsEditV.cpp", MDIMyModeSettingsEdit);
USEFORM("MDIMyModeSettingListEditV.cpp", MDIMyModeSettingListEdit);
USEFORM("MDICanExistsCheckEditV.cpp", MDICanExistsCheckEdit);
USEFORM("MDIFloorControlV.cpp", MDIFloorControl);
USEFORM("MDIMetaActionListV.cpp", MDIMetaActionList);
USEFORM("MDIMetaActionV.cpp", MDIMetaAction);
USEFORM("MDIMetaMenuItemV.cpp", MDIMetaMenuItem);
USEFORM("MDIMetaUIV.cpp", MDIMetaUI);
USEFORM("MDIMyTextureModesListV.cpp", MDIMyTextureModesList);
USEFORM("MDIMyTextureModesV.cpp", MDIMyTextureModes);
USEFORM("MDITextureV.cpp", MDITexture);
USEFORM("MDIMetaVisParamV.cpp", MDIMetaVisParam);
USEFORM("MDIPointerListEditV.cpp", MDIPointerListEdit);
USEFORM("PaintFormV.cpp", PaintForm);
USEFORM("FragmentEditorV.cpp", FragmentEditor);
USEFORM("MDIMetaCatalogUnitV.cpp", MDIMetaCatalogUnit);
USEFORM("MDIMetaDataEditV.cpp", MDIMetaDataEdit);
USEFORM("GenImageV.cpp", GenImage);
USEFORM("ExcelExchangeV.cpp", ExcelExchange);
#endif


USEFORM("MDI3DV.cpp", MDI3D);
USEFORM("MDITVV.cpp", MDITV);
USEFORM("MDI3DUserV.cpp", MDI3DUser);
USEFORM("SimpleEditV.cpp", MDISimpleEdit);
USEFORM("OutPutV.cpp", OutPut);
USEFORM("LuaVarsEditV.cpp", LuaVarsEdit);
USEFORM("MDICountReportV.cpp", MDICountReport);
USEFORM("SelectBMPV.cpp", SelectBMP);
USEFORM("LOGOV.cpp", Logo);
USEFORM("MDIMetaTextureV.cpp", MDIMetaTexture);
USEFORM("MDIMyTextureFlagsEditV.cpp", MDIMyTextureFlagsEdit);
USEFORM("MDIHasStepV.cpp", MDIHasStep);
USEFORM("MDI2DV.cpp", MDI2D);
USEFORM("DrawViewV.cpp", DrawView);
USEFORM("MDIVisibleSelectFloorV.cpp", MDIVisibleSelectFloor);
USEFORM("LuaUniFormV.cpp", LuaUniForm);
USEFORM("MDIViewSettingsV.cpp", MDIViewSettings);
USEFORM("PBV.cpp", PB);
USEFORM("IntExplorerV.cpp", IntExplorer);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(TConfig), &Config);
         Application->CreateForm(__classid(TAboutBox), &AboutBox);
         Application->CreateForm(__classid(TPB), &PB);
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->Run();

	return 0;
}
//---------------------------------------------------------------------









