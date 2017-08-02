//---------------------------------------------------------------------------

#include <basepch.h>
#pragma hdrstop
USEFORM("GenImageV.cpp", GenImage);
USEFORM("ElementViewerV.cpp", ElementViewer);
USEFORM("LuaVarsEditV.cpp", LuaVarsEdit);
USEFORM("MDI3DV.cpp", MDI3D);
USEFORM("MDIColorsV.cpp", MDIColors);
USEFORM("MDIElementSelectV.cpp", MDIElementSelect);
USEFORM("MDIMetaNodeV.cpp", MDIMetaNode);
USEFORM("MDIMetaTextureV.cpp", MDIMetaTexture);
USEFORM("MDIMetaVisParamV.cpp", MDIMetaVisParam);
USEFORM("MDIPointerEditV.cpp", MDIPointerEdit);
USEFORM("MDIPointerListEditV.cpp", MDIPointerListEdit);
USEFORM("MDITextureV.cpp", MDITexture);
USEFORM("MDITriggerBlockEditV.cpp", MDITriggerBlockEdit);
USEFORM("MDITVV.cpp", MDITV);
USEFORM("MDIViewSettingsV.cpp", MDIViewSettings);
USEFORM("ProgBarV.cpp", ProgBar);
USEFORM("SelectBMPV.cpp", SelectBMP);
USEFORM("IntExplorerV.cpp", IntExplorer);
USEFORM("MDIMetaCatalogUnitV.cpp", MDIMetaCatalogUnit);
USEFORM("MDIMetaMyModeV.cpp", MDIMetaMyMode);
USEFORM("MDIKernelSupportEditV.cpp", MDIKernelSupportEdit);
USEFORM("MDISelectClassV.cpp", MDISelectClass);
USEFORM("AddLuaVarV.cpp", AddLuaVar);
USEFORM("MDIMetaToolEditV.cpp", MDIMetaToolEdit);
USEFORM("ToolFormV.cpp", ToolForm);
USEFORM("BindedBaseToolEditV.cpp", BindedBaseToolEdit);
USEFORM("BindedBlockEditV.cpp", BindedBlockEdit);
USEFORM("BindedGoEditV.cpp", BindedGoEdit);
USEFORM("LuaUniFormV.cpp", LuaUniForm);
USEFORM("Wizard3DSImport.cpp", frmWizard3DSImport);
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
//---------------------------------------------------------------------------
 