/*
** Lua binding: z_All
** Generated automatically by tolua++-1.0.3 on 02/27/05 20:24:55.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_z_All_open (lua_State* tolua_S);

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
#define LUA_N = 1<<31;
#include "Main.h"
#include "LuaUniFormV.h"
#include "MDICountReportV.h"
#include "Poligon.h"
#include "MyGL.h"
#include "LogicNode.h"
#include "World.h"
#include "UI.h"
#include "LogicNode.h"
#include "DynamicCast.h"
#include "CounterBaseV.h"
#include "Triangulation.h"
#include "Compose.h"
#include "Roof.h"
#include "GeomObjV.h"
#include "RoofEditV.h"
#include "ElementV.h"
#include "PlatformV.h"
#include "MultiElementV.h"
#include "Label3DV.h"
#include "RoomV.h"
#include "NomenclatureV.h"
#include "WallV.h"
#include "ArchitectureSupportV.h"
#include "Driver.h"
#include "BaseToolV.h"
#include "MDI3DV.h"
#include "AUIV.h"
#include "IntExplorerV.h"
#include "Select.h"
#include "CatalogUnitV.h"
#include "LuaAttributeV.h"
#include "IntExplorerV.h"
#include "Driver.h"
#include "MainToolsV.h"
#include "MyDialogEditU.h"
#include "ElementViewerV.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_TLINKPATTERN (lua_State* tolua_S)
{
 TLINKPATTERN* self = (TLINKPATTERN*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TAdvancedUserInterface (lua_State* tolua_S)
{
 TAdvancedUserInterface* self = (TAdvancedUserInterface*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TNomenclature (lua_State* tolua_S)
{
 TNomenclature* self = (TNomenclature*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TBindedBaseTool (lua_State* tolua_S)
{
 TBindedBaseTool* self = (TBindedBaseTool*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TDriver (lua_State* tolua_S)
{
 TDriver* self = (TDriver*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TLinkNodes (lua_State* tolua_S)
{
 TLinkNodes* self = (TLinkNodes*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TPolygon (lua_State* tolua_S)
{
 TPolygon* self = (TPolygon*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TIntVec (lua_State* tolua_S)
{
 TIntVec* self = (TIntVec*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TSelection (lua_State* tolua_S)
{
 TSelection* self = (TSelection*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TElementQueueCollection (lua_State* tolua_S)
{
 TElementQueueCollection* self = (TElementQueueCollection*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TElementQueue (lua_State* tolua_S)
{
 TElementQueue* self = (TElementQueue*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TLabel3D (lua_State* tolua_S)
{
 TLabel3D* self = (TLabel3D*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TCube (lua_State* tolua_S)
{
 TCube* self = (TCube*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaNode (lua_State* tolua_S)
{
 TMetaNode* self = (TMetaNode*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaCatalogUnit (lua_State* tolua_S)
{
 TMetaCatalogUnit* self = (TMetaCatalogUnit*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TFragmentSettings (lua_State* tolua_S)
{
 TFragmentSettings* self = (TFragmentSettings*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TIntExplorer (lua_State* tolua_S)
{
 TIntExplorer* self = (TIntExplorer*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TLinkPair (lua_State* tolua_S)
{
 TLinkPair* self = (TLinkPair*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TBaseTool (lua_State* tolua_S)
{
 TBaseTool* self = (TBaseTool*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TSyngleLink (lua_State* tolua_S)
{
 TSyngleLink* self = (TSyngleLink*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TLink (lua_State* tolua_S)
{
 TLink* self = (TLink*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TDialogBaseTool (lua_State* tolua_S)
{
 TDialogBaseTool* self = (TDialogBaseTool*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TUserInterfaceParam (lua_State* tolua_S)
{
 TUserInterfaceParam* self = (TUserInterfaceParam*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TShiftState (lua_State* tolua_S)
{
 TShiftState* self = (TShiftState*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_THoledPolygon (lua_State* tolua_S)
{
 THoledPolygon* self = (THoledPolygon*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TUnit (lua_State* tolua_S)
{
 TUnit* self = (TUnit*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TLuaUniForm (lua_State* tolua_S)
{
 TLuaUniForm* self = (TLuaUniForm*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
////////////////////////////////////////////////
static int tolua_collect_TElementViewer (lua_State* tolua_S)
{
 TElementViewer* self = (TElementViewer*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
////////////////////////////////////////////////

static int tolua_collect_TDelone (lua_State* tolua_S)
{
 TDelone* self = (TDelone*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TRenderParam (lua_State* tolua_S)
{
 TRenderParam* self = (TRenderParam*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaMenuItem (lua_State* tolua_S)
{
 TMetaMenuItem* self = (TMetaMenuItem*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TCounterBase (lua_State* tolua_S)
{
 TCounterBase* self = (TCounterBase*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TObjectAttributePreSet (lua_State* tolua_S)
{
 TObjectAttributePreSet* self = (TObjectAttributePreSet*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TFloorInfo (lua_State* tolua_S)
{
 TFloorInfo* self = (TFloorInfo*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TRoom (lua_State* tolua_S)
{
 TRoom* self = (TRoom*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaUI (lua_State* tolua_S)
{
 TMetaUI* self = (TMetaUI*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaTexture (lua_State* tolua_S)
{
 TMetaTexture* self = (TMetaTexture*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TUndoStack (lua_State* tolua_S)
{
 TUndoStack* self = (TUndoStack*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TElement (lua_State* tolua_S)
{
 TElement* self = (TElement*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TRouteNode (lua_State* tolua_S)
{
 TRouteNode* self = (TRouteNode*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaLink (lua_State* tolua_S)
{
 TMetaLink* self = (TMetaLink*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TDynamicLink (lua_State* tolua_S)
{
 TDynamicLink* self = (TDynamicLink*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMainTree (lua_State* tolua_S)
{
 TMainTree* self = (TMainTree*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TBrush (lua_State* tolua_S)
{
 TBrush* self = (TBrush*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TPlatform (lua_State* tolua_S)
{
 TPlatform* self = (TPlatform*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaNodeCollection (lua_State* tolua_S)
{
 TMetaNodeCollection* self = (TMetaNodeCollection*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_T3DScope (lua_State* tolua_S)
{
 T3DScope* self = (T3DScope*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TElementPoints (lua_State* tolua_S)
{
 TElementPoints* self = (TElementPoints*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaMaterial (lua_State* tolua_S)
{
 TMetaMaterial* self = (TMetaMaterial*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TFloor (lua_State* tolua_S)
{
 TFloor* self = (TFloor*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaAction (lua_State* tolua_S)
{
 TMetaAction* self = (TMetaAction*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TPen (lua_State* tolua_S)
{
 TPen* self = (TPen*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaElement (lua_State* tolua_S)
{
 TMetaElement* self = (TMetaElement*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMyObject (lua_State* tolua_S)
{
 TMyObject* self = (TMyObject*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TLuaRoofCut (lua_State* tolua_S)
{
 TLuaRoofCut* self = (TLuaRoofCut*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TRoutePoint (lua_State* tolua_S)
{
 TRoutePoint* self = (TRoutePoint*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TRay (lua_State* tolua_S)
{
 TRay* self = (TRay*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDI3D (lua_State* tolua_S)
{
 TMDI3D* self = (TMDI3D*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TLinkInfo (lua_State* tolua_S)
{
 TLinkInfo* self = (TLinkInfo*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TSide (lua_State* tolua_S)
{
 TSide* self = (TSide*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMultiElement (lua_State* tolua_S)
{
 TMultiElement* self = (TMultiElement*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TRect (lua_State* tolua_S)
{
 TRect* self = (TRect*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TLINKPATTERN");
 tolua_usertype(tolua_S,"TMTList<TElement>");
 tolua_usertype(tolua_S,"TNomenclature");
 tolua_usertype(tolua_S,"TMDelTList<TObjectAttributePreSet>");
 tolua_usertype(tolua_S,"TVisPrimitiveObj");
 tolua_usertype(tolua_S,"TVisView");
 tolua_usertype(tolua_S,"TPolygon");
 tolua_usertype(tolua_S,"TIntVec");
 tolua_usertype(tolua_S,"TLuaAttribute");
 tolua_usertype(tolua_S,"TInt3d");
 tolua_usertype(tolua_S,"TCube");
 tolua_usertype(tolua_S,"TMetaNode");
 tolua_usertype(tolua_S,"TElementQueueCollection");
 tolua_usertype(tolua_S,"TLinkPair");
 tolua_usertype(tolua_S,"TSyngleLink");
 tolua_usertype(tolua_S,"TIntExplorer");
 tolua_usertype(tolua_S,"TDialogBaseTool");
 tolua_usertype(tolua_S,"TMDelTList<TPolygon>");
 tolua_usertype(tolua_S,"TMainTree");
 tolua_usertype(tolua_S,"TWinControl");
 tolua_usertype(tolua_S,"TFloorInfo");
 tolua_usertype(tolua_S,"TMDelTList<TSyngleLink>");
 tolua_usertype(tolua_S,"TMetaTexture");
 tolua_usertype(tolua_S,"TMetaLink");
 tolua_usertype(tolua_S,"TBrush");
 tolua_usertype(tolua_S,"TPlatform");
 tolua_usertype(tolua_S,"TMetaAction");
 tolua_usertype(tolua_S,"TPen");
 tolua_usertype(tolua_S,"TMyObject");
 tolua_usertype(tolua_S,"TMDelTList<TRoutePoint>");
 tolua_usertype(tolua_S,"TSelection");
 tolua_usertype(tolua_S,"TLinkInfo");
 tolua_usertype(tolua_S,"TMDelTList<TMDelTList<TPolygon> >");
 tolua_usertype(tolua_S,"TBaseTool");
 tolua_usertype(tolua_S,"TAdvancedUserInterface");
 tolua_usertype(tolua_S,"TMDelTList<TMDelTList<TIntVec> >");
 tolua_usertype(tolua_S,"TBindedBaseTool");
 tolua_usertype(tolua_S,"TMetaMaterial");
 tolua_usertype(tolua_S,"TDriver");
 tolua_usertype(tolua_S,"TFragmentSettings");
 tolua_usertype(tolua_S,"TDelone");
 tolua_usertype(tolua_S,"TRouteNode");
 tolua_usertype(tolua_S,"TMetaCatalogUnit");
 tolua_usertype(tolua_S,"TMetaMyMode");
 tolua_usertype(tolua_S,"TLink");
 tolua_usertype(tolua_S,"WORD");
 tolua_usertype(tolua_S,"TGeomObject");
 tolua_usertype(tolua_S,"TUserInterfaceParam");
 tolua_usertype(tolua_S,"TMultiElement");
 tolua_usertype(tolua_S,"TMTList<TLink>");
 tolua_usertype(tolua_S,"TLuaUniForm");
 ///////////////////
 tolua_usertype(tolua_S,"TElementViewer");
 ///////////////////
 tolua_usertype(tolua_S,"TMetaMenuItem");
 tolua_usertype(tolua_S,"TComponent");
 tolua_usertype(tolua_S,"TRoom");
 tolua_usertype(tolua_S,"TMetaElement");
 tolua_usertype(tolua_S,"TObjectAttributePreSet");
 tolua_usertype(tolua_S,"TMDelTList<TLuaRoofCut>");
 tolua_usertype(tolua_S,"TMTList<TMetaNode>");
 tolua_usertype(tolua_S,"TMTList<TIntVec>");
 tolua_usertype(tolua_S,"TMyRegObject");
 tolua_usertype(tolua_S,"TUndoStack");
 tolua_usertype(tolua_S,"TElement");
 tolua_usertype(tolua_S,"TMetaUI");
 tolua_usertype(tolua_S,"TMTList<TMetaElement>");
 tolua_usertype(tolua_S,"TDynamicLink");
 tolua_usertype(tolua_S,"TRenderParam");
 tolua_usertype(tolua_S,"T3DScope");
 tolua_usertype(tolua_S,"TShiftState");
 tolua_usertype(tolua_S,"TMetaNodeCollection");
 tolua_usertype(tolua_S,"TLabel3D");
 tolua_usertype(tolua_S,"TMDelTList<TMDelTList<int> >");
 tolua_usertype(tolua_S,"TCounterBase");
 tolua_usertype(tolua_S,"TLinkNodes");
 tolua_usertype(tolua_S,"TElementQueue");
 tolua_usertype(tolua_S,"TElementPoints");
 tolua_usertype(tolua_S,"THoledPolygon");
 tolua_usertype(tolua_S,"TUnit");
 tolua_usertype(tolua_S,"TMDelTList<TIntVec>");
 tolua_usertype(tolua_S,"TRoutePoint");
 tolua_usertype(tolua_S,"TRay");
 tolua_usertype(tolua_S,"TMDI3D");
 tolua_usertype(tolua_S,"TLuaRoofCut");
 tolua_usertype(tolua_S,"TSide");
 tolua_usertype(tolua_S,"TFloor");
 tolua_usertype(tolua_S,"TRect");
}

/* get function: opAND */
static int tolua_get_const_opAND(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)opAND);
 return 1;
}

/* get function: opOR */
static int tolua_get_const_opOR(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)opOR);
 return 1;
}

/* get function: opMINUS */
static int tolua_get_const_opMINUS(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)opMINUS);
 return 1;
}

/* get function: opXOR */
static int tolua_get_const_opXOR(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)opXOR);
 return 1;
}

/* get function: lcNONE */
static int tolua_get_const_lcNONE(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)lcNONE);
 return 1;
}

/* get function: lcCROSSING */
static int tolua_get_const_lcCROSSING(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)lcCROSSING);
 return 1;
}

/* get function: lcPARALLEL */
static int tolua_get_const_lcPARALLEL(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)lcPARALLEL);
 return 1;
}

/* get function: lcEQUAL */
static int tolua_get_const_lcEQUAL(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)lcEQUAL);
 return 1;
}

/* get function: lcCOMMONPOINT */
static int tolua_get_const_lcCOMMONPOINT(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)lcCOMMONPOINT);
 return 1;
}

/* get function: lcCOLLINEAR */
static int tolua_get_const_lcCOLLINEAR(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)lcCOLLINEAR);
 return 1;
}

/* get function: etLEFT */
static int tolua_get_const_etLEFT(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)etLEFT);
 return 1;
}

/* get function: etRIGHT */
static int tolua_get_const_etRIGHT(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)etRIGHT);
 return 1;
}

/* get function: etBETWEEN */
static int tolua_get_const_etBETWEEN(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)etBETWEEN);
 return 1;
}

/* get function: etBEHIND */
static int tolua_get_const_etBEHIND(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)etBEHIND);
 return 1;
}

/* get function: etBEYOND */
static int tolua_get_const_etBEYOND(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)etBEYOND);
 return 1;
}

/* get function: etORIGIN */
static int tolua_get_const_etORIGIN(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)etORIGIN);
 return 1;
}

/* get function: etDESTINATION */
static int tolua_get_const_etDESTINATION(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)etDESTINATION);
 return 1;
}

/* get function: ntNULL */
static int tolua_get_const_ntNULL(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ntNULL);
 return 1;
}

/* get function: ntONE */
static int tolua_get_const_ntONE(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ntONE);
 return 1;
}

/* get function: ntTWO */
static int tolua_get_const_ntTWO(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ntTWO);
 return 1;
}

/* get function: ntTHREE */
static int tolua_get_const_ntTHREE(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ntTHREE);
 return 1;
}

/* get function: ntFOUR */
static int tolua_get_const_ntFOUR(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ntFOUR);
 return 1;
}

/* get function: ntFIVE */
static int tolua_get_const_ntFIVE(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ntFIVE);
 return 1;
}

/* get function: pipBOUNDARY */
static int tolua_get_const_pipBOUNDARY(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)pipBOUNDARY);
 return 1;
}

/* get function: pipOUTSIDE */
static int tolua_get_const_pipOUTSIDE(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)pipOUTSIDE);
 return 1;
}

/* get function: pipINSIDE */
static int tolua_get_const_pipINSIDE(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)pipINSIDE);
 return 1;
}

/* get function: clBlack */
static int tolua_get_const_clBlack(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)clBlack);
 return 1;
}

/* get function: clWhite */
static int tolua_get_const_clWhite(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)clWhite);
 return 1;
}

/* get function: PaymentCount */
static int tolua_get_const_PaymentCount(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)PaymentCount);
 return 1;
}

/* get function: WorkCount */
static int tolua_get_const_WorkCount(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)WorkCount);
 return 1;
}

/* get function: SimpleCount */
static int tolua_get_const_SimpleCount(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)SimpleCount);
 return 1;
}

/* get function: cwClockWize */
static int tolua_get_const_cwClockWize(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)cwClockWize);
 return 1;
}

/* get function: cwNotClockWize */
static int tolua_get_const_cwNotClockWize(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)cwNotClockWize);
 return 1;
}

/* get function: cwNotDefined */
static int tolua_get_const_cwNotDefined(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)cwNotDefined);
 return 1;
}

/* get function: mtInt */
static int tolua_get_const_mtInt(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)mtInt);
 return 1;
}

/* get function: mtDouble */
static int tolua_get_const_mtDouble(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)mtDouble);
 return 1;
}

/* get function: mtString */
static int tolua_get_const_mtString(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)mtString);
 return 1;
}

/* get function: mtMyObject */
static int tolua_get_const_mtMyObject(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)mtMyObject);
 return 1;
}

/* get function: ocmNone */
static int tolua_get_const_ocmNone(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ocmNone);
 return 1;
}

/* get function: ocmPosition */
static int tolua_get_const_ocmPosition(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ocmPosition);
 return 1;
}

/* get function: ocmSize */
static int tolua_get_const_ocmSize(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)ocmSize);
 return 1;
}

/* get function: CurElement */
static int tolua_get_My_CurElement_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(CurElement),lua_type);
 return 1;
}

/* get function: CurLink */
static int tolua_get_My_CurLink_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype(tolua_S,(void*)(CurLink),lua_type);
 return 1;
}

/* get function: curLinkInfo */
static int tolua_get_My_curLinkInfo_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TLinkInfo";
   tolua_pushusertype(tolua_S,(void*)(curLinkInfo),lua_type);
 return 1;
}

/* function: RoundTo */
static int tolua_z_All_My_RoundTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  double src = ((double)  tolua_tonumber(tolua_S,1,0));
/*declare*/
  int digit = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   double tolua_ret = (double)  RoundTo(src,digit);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RoundTo'.",&tolua_err);
 return 0;
#endif
}

/* get function: Counter */
static int tolua_get_My_Counter_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TCounterBase";
   tolua_pushusertype(tolua_S,(void*)(Counter),lua_type);
 return 1;
}


/* function: ApplySkinTheme */
static int tolua_get_ApplySkinTheme(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;

 if (
		 !tolua_isusertype(tolua_S,1,"TControl",0,&tolua_err) ||
		 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
	goto tolua_lerror;
 else
#endif
 {
//declare
	TControl* Control = (TControl*)tolua_tousertype(tolua_S,1,0);
	{
	 ApplySkinTheme(Control);
	}
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ApplySkinTheme'.",&tolua_err);
 return 0;
#endif
}
/* End*/




/* function: BindEvents */
static int tolua_get_Bind_Events(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;

 if (
		 !tolua_isusertype(tolua_S,1,"TComponent",0,&tolua_err) ||
		 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
	goto tolua_lerror;
 else
#endif
 {
//declare
	TComponent* Component = (TComponent*)tolua_tousertype(tolua_S,1,0);
	{
//	 VCLEvents.BindEvents(Component);
// getting type
	//char* lua_type = "TNomenclature";
	// tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
	}
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BindEvents'.",&tolua_err);
 return 0;
#endif
}
/* End*/

////////////////////////
/* function: EditRoof */
static int tolua_get_EditRoof(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;

 if (
		 !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
		 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
	goto tolua_lerror;
 else
#endif
 {
//declare
	TElement* Element = (TElement*)tolua_tousertype(tolua_S,1,0);
	{
		EditRoof(Element);
	}
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EditRoof'.",&tolua_err);
 return 0;
#endif
}
/* End*/
//////////////////////////////////////////////////

/* function: FindNomenclatureByID */
static int tolua_z_All_My_FindNomenclatureByID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
		 !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
		 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
	goto tolua_lerror;
 else
#endif
 {
/*declare*/
	int ID = ((int)  tolua_tonumber(tolua_S,1,0));
	{
	 TNomenclature* tolua_ret = (TNomenclature*)  FindNomenclatureByID(ID);

/* getting type */
	char* lua_type = "TNomenclature";
	 tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
	}
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindNomenclatureByID'.",&tolua_err);
 return 0;
#endif
}

/* function: FindNomenclatureByGUID */
static int tolua_z_All_My_FindNomenclatureByGUID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
		 !tolua_isstring(tolua_S,1,0,&tolua_err) ||
		 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
	goto tolua_lerror;
 else
#endif
 {
/*declare*/
	char* GUID = ((char*)  tolua_tostring(tolua_S,1,0));
	{
	 TNomenclature* tolua_ret = (TNomenclature*)  FindNomenclatureByGUID(GUID);

/* getting type */
	char* lua_type = "TNomenclature";
	 tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
	}
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindNomenclatureByGUID'.",&tolua_err);
 return 0;
#endif
}

/* function: FindNomenclatureByName */
static int tolua_z_All_My_FindNomenclatureByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  char* Name = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   TNomenclature* tolua_ret = (TNomenclature*)  FindNomenclatureByName(Name);

/* getting type */
  char* lua_type = "TNomenclature";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindNomenclatureByName'.",&tolua_err);
 return 0;
#endif
}

/* function: FindNomenclatureByStrCode */
static int tolua_z_All_My_FindNomenclatureByStrCode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  char* StrCode = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   TNomenclature* tolua_ret = (TNomenclature*)  FindNomenclatureByStrCode(StrCode);

/* getting type */
  char* lua_type = "TNomenclature";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindNomenclatureByStrCode'.",&tolua_err);
 return 0;
#endif
}

/* get function: MetaNodeCollection */
static int tolua_get_My_MetaNodeCollection_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TMetaNodeCollection";
   tolua_pushusertype(tolua_S,(void*)(MetaNodeCollection),lua_type);
 return 1;
}

/* get function: World */
static int tolua_get_My_World_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TMainTree";
   tolua_pushusertype(tolua_S,(void*)(World),lua_type);
 return 1;
}

/* get function: curAction */
static int tolua_get_My_curAction_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TMetaAction";
   tolua_pushusertype(tolua_S,(void*)(curAction),lua_type);
 return 1;
}

/* get function: curMenuItem */
static int tolua_get_My_curMenuItem_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TMetaMenuItem";
   tolua_pushusertype(tolua_S,(void*)(curMenuItem),lua_type);
 return 1;
}

/* get function: LN */
static int tolua_get_My_LN_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TLinkNodes";
   tolua_pushusertype(tolua_S,(void*)(LN),lua_type);
 return 1;
}

/* get function: TechnologyCheckPass */
static int tolua_get_My_TechnologyCheckPass(lua_State* tolua_S)
{
  tolua_pushboolean(tolua_S,(bool)TechnologyCheckPass);
 return 1;
}

/* set function: TechnologyCheckPass */
static int tolua_set_My_TechnologyCheckPass(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  TechnologyCheckPass = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: TechnologyCheckStr */
static int tolua_get_My_TechnologyCheckStr(lua_State* tolua_S)
{
  tolua_pushstring(tolua_S,(const char*)TechnologyCheckStr);
 return 1;
}

/* set function: TechnologyCheckStr */
static int tolua_set_My_TechnologyCheckStr(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  TechnologyCheckStr = ((char*)  tolua_tostring(tolua_S,2,0));
 return 0;
}

/* get function: LuaUniForm */
static int tolua_get_My_LuaUniForm_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TLuaUniForm";
   tolua_pushusertype(tolua_S,(void*)(LuaUniForm),lua_type);
 return 1;
}

/* get function: CurNomenclature */
static int tolua_get_My_CurNomenclature_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TNomenclature";
   tolua_pushusertype(tolua_S,(void*)(CurNomenclature),lua_type);
 return 1;
}

/* get function: Deloune */
static int tolua_get_My_Deloune_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TDelone";
   tolua_pushusertype(tolua_S,(void*)(Deloune),lua_type);
 return 1;
}

/* get function: CurrentTool */
static int tolua_get_My_CurrentTool_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TBindedBaseTool";
   tolua_pushusertype(tolua_S,(void*)(CurrentTool),lua_type);
 return 1;
}

/* get function: AUI */
static int tolua_get_My_AUI(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TAdvancedUserInterface";
   tolua_pushusertype(tolua_S,(void*)(&(AUI)),lua_type);
 return 1;
}

/* get function: SelectionCollection */
static int tolua_get_My_SelectionCollection(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TElementQueueCollection";
   tolua_pushusertype(tolua_S,(void*)(&(SelectionCollection)),lua_type);
 return 1;
}

/* get function: MySelection */
static int tolua_get_My_MySelection(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TSelection";
   tolua_pushusertype(tolua_S,(void*)(&(MySelection)),lua_type);
 return 1;
}

/* get function: IntExplorer */
static int tolua_get_My_IntExplorer_ptr(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TIntExplorer";
   tolua_pushusertype(tolua_S,(void*)(IntExplorer),lua_type);
 return 1;
}

/* get function: LuaConditionResult */
static int tolua_get_My_LuaConditionResult(lua_State* tolua_S)
{
  tolua_pushboolean(tolua_S,(bool)LuaConditionResult);
 return 1;
}

/* set function: LuaConditionResult */
static int tolua_set_My_LuaConditionResult(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  LuaConditionResult = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: UndoStack */
static int tolua_get_My_UndoStack(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TUndoStack";
   tolua_pushusertype(tolua_S,(void*)(&(UndoStack)),lua_type);
 return 1;
}

/* get function: Driver */
static int tolua_get_My_Driver(lua_State* tolua_S)
{

/* getting type */
  char* lua_type = "TDriver";
   tolua_pushusertype(tolua_S,(void*)(&(Driver)),lua_type);
 return 1;
}

/* function: RGB */
static int tolua_z_All_My_RGB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  int r = ((int)  tolua_tonumber(tolua_S,1,0));
/*declare*/
  int g = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int b = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   TColor tolua_ret = (TColor)  RGB(r,g,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RGB'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TRect */
static int tolua_z_All_TRect_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRect* tolua_ret = (TRect*)  new TRect();

/* getting type */
  char* lua_type = "TRect";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TRect */
static int tolua_z_All_TRect_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRect* tolua_ret = (TRect*)  new TRect();

/* getting type */
  char* lua_type = "TRect";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TRect */
static int tolua_z_All_TRect_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
		 !tolua_isusertype(tolua_S,1,"TRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Left of class  TRect */
static int tolua_get_TRect_Left(lua_State* tolua_S)
{
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Left'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Left);
 return 1;
}

/* set function: Left of class  TRect */
static int tolua_set_TRect_Left(lua_State* tolua_S)
{
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Left'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Left = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Top of class  TRect */
static int tolua_get_TRect_Top(lua_State* tolua_S)
{
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Top'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Top);
 return 1;
}

/* set function: Top of class  TRect */
static int tolua_set_TRect_Top(lua_State* tolua_S)
{
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Top'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Top = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Right of class  TRect */
static int tolua_get_TRect_Right(lua_State* tolua_S)
{
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Right'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Right);
 return 1;
}

/* set function: Right of class  TRect */
static int tolua_set_TRect_Right(lua_State* tolua_S)
{
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Right'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Right = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Bottom of class  TRect */
static int tolua_get_TRect_Bottom(lua_State* tolua_S)
{
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Bottom'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Bottom);
 return 1;
}

/* set function: Bottom of class  TRect */
static int tolua_set_TRect_Bottom(lua_State* tolua_S)
{
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Bottom'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Bottom = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: Width of class  TRect */
static int tolua_z_All_TRect_Width00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Width'",NULL);
#endif
  {
   int tolua_ret = (int)  self->Width();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Width'.",&tolua_err);
 return 0;
#endif
}

/* method: Height of class  TRect */
static int tolua_z_All_TRect_Height00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRect* self = (TRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Height'",NULL);
#endif
  {
   int tolua_ret = (int)  self->Height();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Height'.",&tolua_err);
 return 0;
#endif
}
//Start of TElementViewer//////////////////////////////////
/* get function: pView of class  TElementViewer */
static int tolua_get_TElementViewer_pView_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pView'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->pView,"TPanel");
 return 1;
}

/* set function: pView of class  TElementViewer */
static int tolua_set_TElementViewer_pView_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pView'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TPanel",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pView = ((TPanel*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: FormActivate of class  TElementViewer */
static int tolua_z_ElementViewer_TElementViewer_FormActivate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementViewer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
  TObject* Sender = ((TObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FormActivate'",NULL);
#endif
  {
   self->FormActivate(Sender);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FormActivate'.",&tolua_err);
 return 0;
#endif
}

/* get function: ShowElement of class  TElementViewer */
static int tolua_get_TElementViewer_ShowElement_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShowElement'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->ShowElement,"TElement");
 return 1;
}

/* set function: ShowElement of class  TElementViewer */
static int tolua_set_TElementViewer_ShowElement_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShowElement'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ShowElement = ((TElement*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: ShowMetaElement of class  TElementViewer */
static int tolua_get_TElementViewer_ShowMetaElement_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShowMetaElement'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->ShowMetaElement,"TMetaElement");
 return 1;
}

/* set function: ShowMetaElement of class  TElementViewer */
static int tolua_set_TElementViewer_ShowMetaElement_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShowMetaElement'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ShowMetaElement = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: MT of class  TElementViewer */
static int tolua_get_TElementViewer_MT_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MT'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->MT,"TMainTree");
 return 1;
}

/* set function: MT of class  TElementViewer */
static int tolua_set_TElementViewer_MT_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MT'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TMainTree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MT = ((TMainTree*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: TV of class  TElementViewer */
static int tolua_get_TElementViewer_TV_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TV'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)self->TV,"TMDITV");
 return 1;
}

/* set function: TV of class  TElementViewer */
static int tolua_set_TElementViewer_TV_ptr(lua_State* tolua_S)
{
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TV'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TMDITV",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TV = ((TMDITV*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: new of class  TElementViewer */
static int tolua_z_ElementViewer_TElementViewer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElementViewer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TComponent* Owner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TElementViewer* tolua_ret = (TElementViewer*)  new TElementViewer(Owner);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TElementViewer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TElementViewer */
static int tolua_z_ElementViewer_TElementViewer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElementViewer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TComponent* Owner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TElementViewer* tolua_ret = (TElementViewer*)  new TElementViewer(Owner);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TElementViewer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TElementViewer */
static int tolua_z_ElementViewer_TElementViewer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementViewer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Start of class  TElementViewer */
static int tolua_z_ElementViewer_TElementViewer_Start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementViewer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementViewer* self = (TElementViewer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Start'",NULL);
#endif
  {
   self->Start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Start'.",&tolua_err);
 return 0;
#endif
}
//End of TElementViewer//////////////////////////////////


/* method: new of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TWinControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TWinControl* WC = ((TWinControl*)  tolua_tousertype(tolua_S,2,0));
  {
   TLuaUniForm* tolua_ret = (TLuaUniForm*)  new TLuaUniForm(WC);

/* getting type */
  char* lua_type = "TLuaUniForm";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TWinControl",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TWinControl* WC = ((TWinControl*)  tolua_tousertype(tolua_S,2,0));
  {
   TLuaUniForm* tolua_ret = (TLuaUniForm*)  new TLuaUniForm(WC);

/* getting type */
  char* lua_type = "TLuaUniForm";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: btOK of class  TLuaUniForm */
static int tolua_get_TLuaUniForm_btOK_ptr(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btOK'",NULL);
#endif

/* getting type */
  char* lua_type = "TWinControl";
   tolua_pushusertype(tolua_S,(void*)(self->btOK),lua_type);
 return 1;
}

/* get function: btCancel of class  TLuaUniForm */
static int tolua_get_TLuaUniForm_btCancel_ptr(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btCancel'",NULL);
#endif

/* getting type */
  char* lua_type = "TWinControl";
   tolua_pushusertype(tolua_S,(void*)(self->btCancel),lua_type);
 return 1;
}

/* get function: btApply of class  TLuaUniForm */
static int tolua_get_TLuaUniForm_btApply_ptr(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'btApply'",NULL);
#endif

/* getting type */
  char* lua_type = "TWinControl";
   tolua_pushusertype(tolua_S,(void*)(self->btApply),lua_type);
 return 1;
}

/* get function: pView of class  TLuaUniForm */
static int tolua_get_TLuaUniForm_pView_ptr(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pView'",NULL);
#endif

/* getting type */
  char* lua_type = "TWinControl";
   tolua_pushusertype(tolua_S,(void*)(self->pView),lua_type);
 return 1;
}

/* method: GetPanel of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_GetPanel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int PanelIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPanel'",NULL);
#endif
  {
   TWinControl* tolua_ret = (TWinControl*)  self->GetPanel(PanelIndex);

/* getting type */
  char* lua_type = "TWinControl";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPanel'.",&tolua_err);
 return 0;
#endif
}

/* method: SetPageCountForPanel of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_SetPageCountForPanel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int PanelIndex = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int PageCount = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPageCountForPanel'",NULL);
#endif
  {
   self->SetPageCountForPanel(PanelIndex,PageCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPageCountForPanel'.",&tolua_err);
 return 0;
#endif
}

/* method: GetPage of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_GetPage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int PanelIndex = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int PageIndex = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPage'",NULL);
#endif
  {
   TWinControl* tolua_ret = (TWinControl*)  self->GetPage(PanelIndex,PageIndex);

/* getting type */
  char* lua_type = "TWinControl";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPage'.",&tolua_err);
 return 0;
#endif
}

/* method: SetCaption of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_SetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* Caption = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaption'",NULL);
#endif
  {
   self->SetCaption(Caption);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaption'.",&tolua_err);
 return 0;
#endif
}

/* method: SetPageCaption of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_SetPageCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int PanelIndex = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int PageIndex = ((int)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  char* Caption = ((char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPageCaption'",NULL);
#endif
  {
   self->SetPageCaption(PanelIndex,PageIndex,Caption);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPageCaption'.",&tolua_err);
 return 0;
#endif
}

/* get function: ShowElement of class  TLuaUniForm */
static int tolua_get_TLuaUniForm_ShowElement_ptr(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShowElement'",NULL);
#endif

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(self->ShowElement),lua_type);
 return 1;
}

/* set function: ShowElement of class  TLuaUniForm */
static int tolua_set_TLuaUniForm_ShowElement_ptr(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShowElement'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ShowElement = ((TElement*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: ShowMetaElement of class  TLuaUniForm */
static int tolua_get_TLuaUniForm_ShowMetaElement_ptr(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShowMetaElement'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype(tolua_S,(void*)(self->ShowMetaElement),lua_type);
 return 1;
}

/* set function: ShowMetaElement of class  TLuaUniForm */
static int tolua_set_TLuaUniForm_ShowMetaElement_ptr(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShowMetaElement'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ShowMetaElement = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: Start of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_Start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Start'",NULL);
#endif
  {
   self->Start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Start'.",&tolua_err);
 return 0;
#endif
}

/* method: Close of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_Close00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Close'",NULL);
#endif
  {
   self->Close();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Close'.",&tolua_err);
 return 0;
#endif
}

/* method: SetDialogParent of class  TLuaUniForm */
static int tolua_z_All_TLuaUniForm_SetDialogParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaUniForm",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TWinControl",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TWinControl* Parent = ((TWinControl*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  char* DialogName = ((char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDialogParent'",NULL);
#endif
  {
   self->SetDialogParent(Parent,DialogName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDialogParent'.",&tolua_err);
 return 0;
#endif
}

/* get function: AutoAlign of class  TLuaUniForm */
static int tolua_get_TLuaUniForm_AutoAlign(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AutoAlign'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->AutoAlign);
 return 1;
}

/* set function: AutoAlign of class  TLuaUniForm */
static int tolua_set_TLuaUniForm_AutoAlign(lua_State* tolua_S)
{
  TLuaUniForm* self = (TLuaUniForm*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AutoAlign'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AutoAlign = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}
///////////////////////////////////Drive////////////////////////////////////////
/* get function: NetActual of class TLinkNodes */
static int tolua_get_TLinkNodes_NetActual(lua_State* tolua_S)
{
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NetActual'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->NetActual);
 return 1;
}

/* set function: NetActual of class  TLinkNodes */
static int tolua_set_TLinkNodes_NetActual(lua_State* tolua_S)
{
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NetActual'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->NetActual = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}
///////////////////////////////////Drive////////////////////////////////////////
/* method: new of class  TBrush */
static int tolua_z_All_TBrush_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TBrush",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TBrush* tolua_ret = (TBrush*)  new TBrush();

/* getting type */
  char* lua_type = "TBrush";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TBrush */
static int tolua_z_All_TBrush_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TBrush",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TBrush* tolua_ret = (TBrush*)  new TBrush();

/* getting type */
  char* lua_type = "TBrush";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TBrush */
static int tolua_z_All_TBrush_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TBrush",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TBrush* self = (TBrush*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Color of class  TBrush */
static int tolua_get_TBrush_Color(lua_State* tolua_S)
{
  TBrush* self = (TBrush*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Color);
 return 1;
}

/* set function: Color of class  TBrush */
static int tolua_set_TBrush_Color(lua_State* tolua_S)
{
  TBrush* self = (TBrush*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Color = ((TColor) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Style of class  TBrush */
static int tolua_get_TBrush_Style(lua_State* tolua_S)
{
  TBrush* self = (TBrush*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Style'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Style);
 return 1;
}

/* set function: Style of class  TBrush */
static int tolua_set_TBrush_Style(lua_State* tolua_S)
{
  TBrush* self = (TBrush*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Style'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Style = ((TBrushStyle) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TPen */
static int tolua_z_All_TPen_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TPen",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TPen* tolua_ret = (TPen*)  new TPen();

/* getting type */
  char* lua_type = "TPen";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TPen */
static int tolua_z_All_TPen_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TPen",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TPen* tolua_ret = (TPen*)  new TPen();

/* getting type */
  char* lua_type = "TPen";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TPen */
static int tolua_z_All_TPen_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPen",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPen* self = (TPen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Color of class  TPen */
static int tolua_get_TPen_Color(lua_State* tolua_S)
{
  TPen* self = (TPen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Color);
 return 1;
}

/* set function: Color of class  TPen */
static int tolua_set_TPen_Color(lua_State* tolua_S)
{
  TPen* self = (TPen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Color = ((TColor) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Style of class  TPen */
static int tolua_get_TPen_Style(lua_State* tolua_S)
{
  TPen* self = (TPen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Style'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Style);
 return 1;
}

/* set function: Style of class  TPen */
static int tolua_set_TPen_Style(lua_State* tolua_S)
{
  TPen* self = (TPen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Style'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Style = ((TPenStyle) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Mode of class  TPen */
static int tolua_get_TPen_Mode(lua_State* tolua_S)
{
  TPen* self = (TPen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Mode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Mode);
 return 1;
}

/* set function: Mode of class  TPen */
static int tolua_set_TPen_Mode(lua_State* tolua_S)
{
  TPen* self = (TPen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Mode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Mode = ((TPenMode) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Width of class  TPen */
static int tolua_get_TPen_Width(lua_State* tolua_S)
{
  TPen* self = (TPen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Width);
 return 1;
}

/* set function: Width of class  TPen */
static int tolua_set_TPen_Width(lua_State* tolua_S)
{
  TPen* self = (TPen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Width = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: x of class  TIntVec */
static int tolua_get_TIntVec_x(lua_State* tolua_S)
{
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}

/* set function: x of class  TIntVec */
static int tolua_set_TIntVec_x(lua_State* tolua_S)
{
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: y of class  TIntVec */
static int tolua_get_TIntVec_y(lua_State* tolua_S)
{
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}

/* set function: y of class  TIntVec */
static int tolua_set_TIntVec_y(lua_State* tolua_S)
{
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: z of class  TIntVec */
static int tolua_get_TIntVec_z(lua_State* tolua_S)
{
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}

/* set function: z of class  TIntVec */
static int tolua_set_TIntVec_z(lua_State* tolua_S)
{
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TIntVec */
static int tolua_z_All_TIntVec_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TIntVec* tolua_ret = (TIntVec*)  new TIntVec();

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TIntVec */
static int tolua_z_All_TIntVec_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TIntVec* tolua_ret = (TIntVec*)  new TIntVec();

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TIntVec */
static int tolua_z_All_TIntVec_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TIntVec */
static int tolua_z_All_TIntVec_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
/*declare*/
  const TIntVec* rhs = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
  {
   TIntVec* tolua_ret = (TIntVec*)  new TIntVec(*rhs);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_TIntVec_new00(tolua_S);
}

/* method: new_local of class  TIntVec */
static int tolua_z_All_TIntVec_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
/*declare*/
  const TIntVec* rhs = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
  {
   TIntVec* tolua_ret = (TIntVec*)  new TIntVec(*rhs);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_TIntVec_new00_local(tolua_S);
}

/* method: new of class  TIntVec */
static int tolua_z_All_TIntVec_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
/*declare*/
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
/*declare*/
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
  {
   TIntVec* tolua_ret = (TIntVec*)  new TIntVec(x,y,z);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_TIntVec_new01(tolua_S);
}

/* method: new_local of class  TIntVec */
static int tolua_z_All_TIntVec_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
/*declare*/
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
/*declare*/
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
  {
   TIntVec* tolua_ret = (TIntVec*)  new TIntVec(x,y,z);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_TIntVec_new01_local(tolua_S);
}

/* method: operator<= of class  TIntVec */
static int tolua_z_All_TIntVec__le00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TIntVec* self = (const TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* rhs = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator<='",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator<=(*rhs);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.le'.",&tolua_err);
 return 0;
#endif
}

/* method: operator== of class  TIntVec */
static int tolua_z_All_TIntVec__eq00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TIntVec* self = (const TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* rhs = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*rhs);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}

/* method: operator+ of class  TIntVec */
static int tolua_z_All_TIntVec__add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TIntVec* self = (const TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* rhs = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->operator+(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}

/* method: operator- of class  TIntVec */
static int tolua_z_All_TIntVec__sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TIntVec* self = (const TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* rhs = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->operator-(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}

/* method: operator* of class  TIntVec */
static int tolua_z_All_TIntVec__mul00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TIntVec* self = (const TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* rhs = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->operator*(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}

/* method: operator/ of class  TIntVec */
static int tolua_z_All_TIntVec__div00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TIntVec* self = (const TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* rhs = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->operator/(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}

/* method: operator/ of class  TIntVec */
static int tolua_z_All_TIntVec__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const TIntVec* self = (const TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  double rhs = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->operator/(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_TIntVec__div00(tolua_S);
}

/* method: operator* of class  TIntVec */
static int tolua_z_All_TIntVec__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const TIntVec* self = (const TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  double rhs = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->operator*(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_TIntVec__mul00(tolua_S);
}

/* method: Length of class  TIntVec */
static int tolua_z_All_TIntVec_Length00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TIntVec* self = (const TIntVec*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Length'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->Length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Length'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TIntVec */
static int tolua_z_All_TIntVec_Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Vec = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   TIntVec& tolua_ret = (TIntVec&)  self->Assign(*Vec);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Equal2D of class  TIntVec */
static int tolua_z_All_TIntVec_Equal2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* P = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equal2D'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Equal2D(*P,USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equal2D'.",&tolua_err);
 return 0;
#endif
}

/* method: Length2D of class  TIntVec */
static int tolua_z_All_TIntVec_Length2D00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TIntVec* self = (TIntVec*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Length2D'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->Length2D();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Length2D'.",&tolua_err);
 return 0;
#endif
}

/* function: VecToStr */
static int tolua_z_All_VecToStr00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* Vec = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
  {
   char* tolua_ret = (char*)  VecToStr(*Vec);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VecToStr'.",&tolua_err);
 return 0;
#endif
}

/* function: StrToVec */
static int tolua_z_All_StrToVec00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  char* str = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   TIntVec tolua_ret = (TIntVec)  StrToVec(str);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StrToVec'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMyObject */
static int tolua_z_All_TMyObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMyObject* tolua_ret = (TMyObject*)  new TMyObject();

/* getting type */
  char* lua_type = "TMyObject";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMyObject */
static int tolua_z_All_TMyObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMyObject* tolua_ret = (TMyObject*)  new TMyObject();

/* getting type */
  char* lua_type = "TMyObject";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMyObject */
static int tolua_z_All_TMyObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMyObject* self = (TMyObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCharName of class  TMyObject */
static int tolua_z_All_TMyObject_GetCharName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMyObject* self = (TMyObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharName'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetCharName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCharName'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCharDescription of class  TMyObject */
static int tolua_z_All_TMyObject_GetCharDescription00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMyObject* self = (TMyObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharDescription'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetCharDescription();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCharDescription'.",&tolua_err);
 return 0;
#endif
}

/* method: SetCharDescription of class  TMyObject */
static int tolua_z_All_TMyObject_SetCharDescription00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMyObject* self = (TMyObject*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* newDescription = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCharDescription'",NULL);
#endif
  {
   self->SetCharDescription(newDescription);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCharDescription'.",&tolua_err);
 return 0;
#endif
}

/* method: LuaCompareAddress of class  TMyObject */
static int tolua_z_All_TMyObject_LuaCompareAddress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMyObject* self = (TMyObject*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LuaCompareAddress'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->LuaCompareAddress(Obj);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LuaCompareAddress'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TMyObject */
static int tolua_z_All_TMyObject_Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMyObject* self = (TMyObject*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(Obj);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TLuaRoofCut */
static int tolua_z_All_TLuaRoofCut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLuaRoofCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLuaRoofCut* tolua_ret = (TLuaRoofCut*)  new TLuaRoofCut();

/* getting type */
  char* lua_type = "TLuaRoofCut";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLuaRoofCut */
static int tolua_z_All_TLuaRoofCut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLuaRoofCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLuaRoofCut* tolua_ret = (TLuaRoofCut*)  new TLuaRoofCut();

/* getting type */
  char* lua_type = "TLuaRoofCut";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLuaRoofCut */
static int tolua_z_All_TLuaRoofCut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaRoofCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaRoofCut* self = (TLuaRoofCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: LOW of class  TLuaRoofCut */
static int tolua_get_TLuaRoofCut_LOW(lua_State* tolua_S)
{
  TLuaRoofCut* self = (TLuaRoofCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LOW'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->LOW)),lua_type);
 return 1;
}

/* get function: HI of class  TLuaRoofCut */
static int tolua_get_TLuaRoofCut_HI(lua_State* tolua_S)
{
  TLuaRoofCut* self = (TLuaRoofCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'HI'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->HI)),lua_type);
 return 1;
}

/* get function: Slope0 of class  TLuaRoofCut */
static int tolua_get_TLuaRoofCut_Slope0(lua_State* tolua_S)
{
  TLuaRoofCut* self = (TLuaRoofCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Slope0'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Slope0);
 return 1;
}

/* set function: Slope0 of class  TLuaRoofCut */
static int tolua_set_TLuaRoofCut_Slope0(lua_State* tolua_S)
{
  TLuaRoofCut* self = (TLuaRoofCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Slope0'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Slope0 = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Slope1 of class  TLuaRoofCut */
static int tolua_get_TLuaRoofCut_Slope1(lua_State* tolua_S)
{
  TLuaRoofCut* self = (TLuaRoofCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Slope1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Slope1);
 return 1;
}

/* set function: Slope1 of class  TLuaRoofCut */
static int tolua_set_TLuaRoofCut_Slope1(lua_State* tolua_S)
{
  TLuaRoofCut* self = (TLuaRoofCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Slope1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Slope1 = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TPolygon */
static int tolua_z_All_TPolygon_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TPolygon* tolua_ret = (TPolygon*)  new TPolygon();

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TPolygon */
static int tolua_z_All_TPolygon_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TPolygon* tolua_ret = (TPolygon*)  new TPolygon();

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TPolygon */
static int tolua_z_All_TPolygon_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TPolygon */
static int tolua_z_All_TPolygon_Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Invert'",NULL);
#endif
  {
   self->Invert();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Invert'.",&tolua_err);
 return 0;
#endif
}

/* get function: Vertex of class  TPolygon */
static int tolua_get_TPolygon_Vertex_ptr(lua_State* tolua_S)
{
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Vertex'",NULL);
#endif

/* getting type */
  char* lua_type = "TMDelTList<TIntVec>";
   tolua_pushusertype(tolua_S,(void*)(self->Vertex),lua_type);
 return 1;
}

/* method: Clear of class  TPolygon */
static int tolua_z_All_TPolygon_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}

/* method: MIN of class  TPolygon */
static int tolua_z_All_TPolygon_MIN00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MIN'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->MIN();
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MIN'.",&tolua_err);
 return 0;
#endif
}

/* method: MAX of class  TPolygon */
static int tolua_z_All_TPolygon_MAX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MAX'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->MAX();
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MAX'.",&tolua_err);
 return 0;
#endif
}

/* method: Insert of class  TPolygon */
static int tolua_z_All_TPolygon_Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  TIntVec* Item = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Insert'",NULL);
#endif
  {
   self->Insert(index,Item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Insert'.",&tolua_err);
 return 0;
#endif
}

/* method: Move of class  TPolygon */
static int tolua_z_All_TPolygon_Move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* _Move = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Move'",NULL);
#endif
  {
   self->Move(*_Move);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Move'.",&tolua_err);
 return 0;
#endif
}

/* method: Rotate of class  TPolygon */
static int tolua_z_All_TPolygon_Rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Angle = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* Center = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rotate'",NULL);
#endif
  {
   self->Rotate(*Angle,*Center);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Rotate'.",&tolua_err);
 return 0;
#endif
}

/* method: ConsistsPoint of class  TPolygon */
static int tolua_z_All_TPolygon_ConsistsPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Point = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ConsistsPoint'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ConsistsPoint(*Point,USEEPS);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConsistsPoint'.",&tolua_err);
 return 0;
#endif
}

/* method: FindSelfCrossing of class  TPolygon */
static int tolua_z_All_TPolygon_FindSelfCrossing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i1 = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int i2 = ((int)  tolua_tonumber(tolua_S,3,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindSelfCrossing'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->FindSelfCrossing(i1,i2,USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)i1);
   tolua_pushnumber(tolua_S,(lua_Number)i2);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindSelfCrossing'.",&tolua_err);
 return 0;
#endif
}

/* method: Center of class  TPolygon */
static int tolua_z_All_TPolygon_Center00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Center'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->Center();
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Center'.",&tolua_err);
 return 0;
#endif
}

/* method: CentralArea of class  TPolygon */
static int tolua_z_All_TPolygon_CentralArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CentralArea'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->CentralArea();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CentralArea'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCrossPoints of class  TPolygon */
static int tolua_z_All_TPolygon_GetCrossPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* P1 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* P2 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TMDelTList<TIntVec>* PointList = ((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  bool UseLinePoints = ((bool)  tolua_toboolean(tolua_S,5,0));
/*declare*/
  bool Edge = ((bool)  tolua_toboolean(tolua_S,6,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCrossPoints'",NULL);
#endif
  {
   self->GetCrossPoints(*P1,*P2,PointList,UseLinePoints,Edge,USEEPS);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCrossPoints'.",&tolua_err);
 return 0;
#endif
}

/* get function: Router of class  TPolygon */
static int tolua_get_TPolygon_Router_ptr(lua_State* tolua_S)
{
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Router'",NULL);
#endif

/* getting type */
  char* lua_type = "TMDelTList<TRoutePoint>";
   tolua_pushusertype(tolua_S,(void*)(self->Router),lua_type);
 return 1;
}

/* method: IsClockWize of class  TPolygon */
static int tolua_z_All_TPolygon_IsClockWize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsClockWize'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IsClockWize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsClockWize'.",&tolua_err);
 return 0;
#endif
}

/* method: KillCollinear_1 of class  TPolygon */
static int tolua_z_All_TPolygon_KillCollinear_100(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'KillCollinear_1'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->KillCollinear_1(USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'KillCollinear_1'.",&tolua_err);
 return 0;
#endif
}

/* method: KillCloseEdges_0 of class  TPolygon */
static int tolua_z_All_TPolygon_KillCloseEdges_000(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'KillCloseEdges_0'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->KillCloseEdges_0(USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'KillCloseEdges_0'.",&tolua_err);
 return 0;
#endif
}

/* method: SquareCreate of class  TPolygon */
static int tolua_z_All_TPolygon_SquareCreate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Size = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SquareCreate'",NULL);
#endif
  {
   self->SquareCreate(*Size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SquareCreate'.",&tolua_err);
 return 0;
#endif
}

/* method: IntrudeRib of class  TPolygon */
static int tolua_z_All_TPolygon_IntrudeRib00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float Value = ((  float)  tolua_tonumber(tolua_S,3,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IntrudeRib'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IntrudeRib(index,Value,USEEPS);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IntrudeRib'.",&tolua_err);
 return 0;
#endif
}

/* method: Valid of class  TPolygon */
static int tolua_z_All_TPolygon_Valid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Valid'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Valid(USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Valid'.",&tolua_err);
 return 0;
#endif
}

/* method: ToConvex of class  TPolygon */
static int tolua_z_All_TPolygon_ToConvex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToConvex'",NULL);
#endif
  {
   self->ToConvex(USEEPS);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToConvex'.",&tolua_err);
 return 0;
#endif
}

/* method: RibIsConvex of class  TPolygon */
static int tolua_z_All_TPolygon_RibIsConvex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RibIsConvex'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RibIsConvex(index,USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RibIsConvex'.",&tolua_err);
 return 0;
#endif
}

/* method: IsConvex of class  TPolygon */
static int tolua_z_All_TPolygon_IsConvex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsConvex'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsConvex(USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsConvex'.",&tolua_err);
 return 0;
#endif
}

/* method: PointIsConvex of class  TPolygon */
static int tolua_z_All_TPolygon_PointIsConvex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PointIsConvex'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->PointIsConvex(index,USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PointIsConvex'.",&tolua_err);
 return 0;
#endif
}

/* method: ToConvexAndExtrude of class  TPolygon */
static int tolua_z_All_TPolygon_ToConvexAndExtrude00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float Value = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToConvexAndExtrude'",NULL);
#endif
  {
   self->ToConvexAndExtrude(USEEPS,Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToConvexAndExtrude'.",&tolua_err);
 return 0;
#endif
}

/* method: CrossedWithPolygon of class  TPolygon */
static int tolua_z_All_TPolygon_CrossedWithPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TPolygon* ElsePol = ((TPolygon*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CrossedWithPolygon'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CrossedWithPolygon(ElsePol,USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CrossedWithPolygon'.",&tolua_err);
 return 0;
#endif
}

/* method: KillSelfCrossing_2 of class  TPolygon */
static int tolua_z_All_TPolygon_KillSelfCrossing_200(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMDelTList<TPolygon>* POLS = ((TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'KillSelfCrossing_2'",NULL);
#endif
  {
   self->KillSelfCrossing_2(POLS,USEEPS);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'KillSelfCrossing_2'.",&tolua_err);
 return 0;
#endif
}

/* method: ExtrudeRib of class  TPolygon */
static int tolua_z_All_TPolygon_ExtrudeRib00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPolygon* self = (TPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float Value = ((  float)  tolua_tonumber(tolua_S,3,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ExtrudeRib'",NULL);
#endif
  {
   self->ExtrudeRib(index,Value,USEEPS);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ExtrudeRib'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   THoledPolygon* tolua_ret = (THoledPolygon*)  new THoledPolygon();

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   THoledPolygon* tolua_ret = (THoledPolygon*)  new THoledPolygon();

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Holes of class  THoledPolygon */
static int tolua_get_THoledPolygon_Holes_ptr(lua_State* tolua_S)
{
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Holes'",NULL);
#endif

/* getting type */
  char* lua_type = "TMDelTList<TPolygon>";
   tolua_pushusertype(tolua_S,(void*)(self->Holes),lua_type);
 return 1;
}

/* method: Clear of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}

/* method: AddHole of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_AddHole00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TPolygon* Polygon = ((TPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddHole'",NULL);
#endif
  {
   self->AddHole(Polygon);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddHole'.",&tolua_err);
 return 0;
#endif
}

/* method: ExistsVertex of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_ExistsVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* P = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec D = *((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ExistsVertex'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ExistsVertex(*P,D);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ExistsVertex'.",&tolua_err);
 return 0;
#endif
}

/* method: Move of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_Move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* _Move = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Move'",NULL);
#endif
  {
   self->Move(*_Move);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Move'.",&tolua_err);
 return 0;
#endif
}

/* method: Rotate of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_Rotate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Angle = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* Center = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Rotate'",NULL);
#endif
  {
   self->Rotate(*Angle,*Center);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Rotate'.",&tolua_err);
 return 0;
#endif
}

/* method: Set of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_Set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int axes = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int Value = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Set'",NULL);
#endif
  {
   self->Set(axes,Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Set'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCrossPoints_UseHoles of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_GetCrossPoints_UseHoles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* P1 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* P2 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TMDelTList<TIntVec>* PointList = ((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  bool UseLinePoints = ((bool)  tolua_toboolean(tolua_S,5,0));
/*declare*/
  bool Edge = ((bool)  tolua_toboolean(tolua_S,6,0));
/*declare*/
  bool HoleEdge = ((bool)  tolua_toboolean(tolua_S,7,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCrossPoints_UseHoles'",NULL);
#endif
  {
   self->GetCrossPoints_UseHoles(*P1,*P2,PointList,UseLinePoints,Edge,HoleEdge,USEEPS);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCrossPoints_UseHoles'.",&tolua_err);
 return 0;
#endif
}

/* method: ConsistsPoint_UseHoles of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_ConsistsPoint_UseHoles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Point = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ConsistsPoint_UseHoles'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ConsistsPoint_UseHoles(*Point,USEEPS);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConsistsPoint_UseHoles'.",&tolua_err);
 return 0;
#endif
}

/* method: Valid of class  THoledPolygon */
static int tolua_z_All_THoledPolygon_Valid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  THoledPolygon* self = (THoledPolygon*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Valid'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Valid(USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Valid'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMetaNode */
static int tolua_z_All_TMetaNode_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaNode* tolua_ret = (TMetaNode*)  new TMetaNode();

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaNode */
static int tolua_z_All_TMetaNode_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaNode* tolua_ret = (TMetaNode*)  new TMetaNode();

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaNode */
static int tolua_z_All_TMetaNode_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaNode* self = (TMetaNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: GetAttributeValue of class  TMetaNode */
static int tolua_z_All_TMetaNode_GetAttributeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaNode",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaNode* self = (TMetaNode*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* _name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeValue'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetAttributeValue(_name);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeValue'.",&tolua_err);
 return 0;
#endif
}

/* method: GetAttribute of class  TMetaNode */
static int tolua_z_All_TMetaNode_GetAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaNode",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaNode* self = (TMetaNode*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* _name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttribute'",NULL);
#endif
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  self->GetAttribute(_name);

/* getting type */
  char* lua_type = "TLuaAttribute";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttribute'.",&tolua_err);
 return 0;
#endif
}

/* method: SetAttributeValue of class  TMetaNode */
static int tolua_z_All_TMetaNode_SetAttributeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaNode",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaNode* self = (TMetaNode*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* _name = ((char*)  tolua_tostring(tolua_S,2,0));
/*declare*/
  char* _value = ((char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeValue'",NULL);
#endif
  {
   self->SetAttributeValue(_name,_value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeValue'.",&tolua_err);
 return 0;
#endif
}

/* get function: Parent of class  TMetaNode */
static int tolua_get_TMetaNode_Parent_ptr(lua_State* tolua_S)
{
  TMetaNode* self = (TMetaNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Parent'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype(tolua_S,(void*)(self->Parent),lua_type);
 return 1;
}

/* method: new of class  TMetaTexture */
static int tolua_z_All_TMetaTexture_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaTexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaTexture* tolua_ret = (TMetaTexture*)  new TMetaTexture();

/* getting type */
  char* lua_type = "TMetaTexture";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaTexture */
static int tolua_z_All_TMetaTexture_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaTexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaTexture* tolua_ret = (TMetaTexture*)  new TMetaTexture();

/* getting type */
  char* lua_type = "TMetaTexture";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaTexture */
static int tolua_z_All_TMetaTexture_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaTexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaTexture* self = (TMetaTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMetaMaterial */
static int tolua_z_All_TMetaMaterial_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaMaterial* tolua_ret = (TMetaMaterial*)  new TMetaMaterial();

/* getting type */
  char* lua_type = "TMetaMaterial";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaMaterial */
static int tolua_z_All_TMetaMaterial_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaMaterial* tolua_ret = (TMetaMaterial*)  new TMetaMaterial();

/* getting type */
  char* lua_type = "TMetaMaterial";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaMaterial */
static int tolua_z_All_TMetaMaterial_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaMaterial* self = (TMetaMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMetaElement */
static int tolua_z_All_TMetaElement_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaElement* tolua_ret = (TMetaElement*)  new TMetaElement();

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaElement */
static int tolua_z_All_TMetaElement_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaElement* tolua_ret = (TMetaElement*)  new TMetaElement();

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaElement */
static int tolua_z_All_TMetaElement_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaElement* self = (TMetaElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: GetDynLink of class  TMetaElement */
static int tolua_z_All_TMetaElement_GetDynLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaElement* self = (TMetaElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDynLink'",NULL);
#endif
  {
   TDynamicLink* tolua_ret = (TDynamicLink*)  self->GetDynLink(index);

/* getting type */
  char* lua_type = "TDynamicLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDynLink'.",&tolua_err);
 return 0;
#endif
}

/* get function: DynLinkCount of class  TMetaElement */
static int tolua_get_TMetaElement_DynLinkCount(lua_State* tolua_S)
{
  TMetaElement* self = (TMetaElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DynLinkCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->DynLinkCount);
 return 1;
}

/* method: SearchNeededLinkFor of class  TMetaElement */
static int tolua_z_All_TMetaElement_SearchNeededLinkFor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaElement* self = (TMetaElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMetaElement* Target = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SearchNeededLinkFor'",NULL);
#endif
  {
   TDynamicLink* tolua_ret = (TDynamicLink*)  self->SearchNeededLinkFor(Target);

/* getting type */
  char* lua_type = "TDynamicLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SearchNeededLinkFor'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMetaLink */
static int tolua_z_All_TMetaLink_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaLink* tolua_ret = (TMetaLink*)  new TMetaLink();

/* getting type */
  char* lua_type = "TMetaLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaLink */
static int tolua_z_All_TMetaLink_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaLink* tolua_ret = (TMetaLink*)  new TMetaLink();

/* getting type */
  char* lua_type = "TMetaLink";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaLink */
static int tolua_z_All_TMetaLink_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaLink* self = (TMetaLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TDynamicLink */
static int tolua_z_All_TDynamicLink_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TDynamicLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TDynamicLink* tolua_ret = (TDynamicLink*)  new TDynamicLink();

/* getting type */
  char* lua_type = "TDynamicLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TDynamicLink */
static int tolua_z_All_TDynamicLink_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TDynamicLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TDynamicLink* tolua_ret = (TDynamicLink*)  new TDynamicLink();

/* getting type */
  char* lua_type = "TDynamicLink";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TDynamicLink */
static int tolua_z_All_TDynamicLink_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDynamicLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDynamicLink* self = (TDynamicLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Link of class  TDynamicLink */
static int tolua_get_TDynamicLink_Link_ptr(lua_State* tolua_S)
{
  TDynamicLink* self = (TDynamicLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Link'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaLink";
   tolua_pushusertype(tolua_S,(void*)(self->Link),lua_type);
 return 1;
}

/* method: NeededFor of class  TDynamicLink */
static int tolua_z_All_TDynamicLink_NeededFor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDynamicLink",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDynamicLink* self = (TDynamicLink*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMetaElement* MEL = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NeededFor'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->NeededFor(MEL);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NeededFor'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TNomenclature */
static int tolua_z_All_TNomenclature_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TNomenclature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TNomenclature* tolua_ret = (TNomenclature*)  new TNomenclature();

/* getting type */
  char* lua_type = "TNomenclature";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TNomenclature */
static int tolua_z_All_TNomenclature_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TNomenclature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TNomenclature* tolua_ret = (TNomenclature*)  new TNomenclature();

/* getting type */
  char* lua_type = "TNomenclature";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TNomenclature */
static int tolua_z_All_TNomenclature_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TNomenclature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: GetMemo of class  TNomenclature */
static int tolua_z_All_TNomenclature_GetMemo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TNomenclature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMemo'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetMemo();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMemo'.",&tolua_err);
 return 0;
#endif
}

/* get function: Price of class  TNomenclature */
static int tolua_get_TNomenclature_Price(lua_State* tolua_S)
{
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Price'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Price);
 return 1;
}

/* set function: Price of class  TNomenclature */
static int tolua_set_TNomenclature_Price(lua_State* tolua_S)
{
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Price'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Price = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Weight of class  TNomenclature */
static int tolua_get_TNomenclature_Weight(lua_State* tolua_S)
{
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Weight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Weight);
 return 1;
}

/* set function: Weight of class  TNomenclature */
static int tolua_set_TNomenclature_Weight(lua_State* tolua_S)
{
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Weight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Weight = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Size of class  TNomenclature */
static int tolua_get_TNomenclature_Size(lua_State* tolua_S)
{
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Size'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->Size)),lua_type);
 return 1;
}

/* get function: Dimensions of class  TNomenclature */
static int tolua_get_TNomenclature_Dimensions(lua_State* tolua_S)
{
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Dimensions'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->Dimensions)),lua_type);
 return 1;
}

/* get function: Associated of class  TNomenclature */
static int tolua_get_TNomenclature_Associated_ptr(lua_State* tolua_S)
{
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Associated'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype(tolua_S,(void*)(self->Associated),lua_type);
 return 1;
}

/* method: GetStrCode of class  TNomenclature */
static int tolua_z_All_TNomenclature_GetStrCode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TNomenclature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TNomenclature* self = (TNomenclature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStrCode'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetStrCode();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStrCode'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TUnit */
static int tolua_z_All_TUnit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TUnit* tolua_ret = (TUnit*)  new TUnit();

/* getting type */
  char* lua_type = "TUnit";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TUnit */
static int tolua_z_All_TUnit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TUnit* tolua_ret = (TUnit*)  new TUnit();

/* getting type */
  char* lua_type = "TUnit";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TUnit */
static int tolua_z_All_TUnit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUnit* self = (TUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Parent of class  TUnit */
static int tolua_get_TUnit_Parent_ptr(lua_State* tolua_S)
{
  TUnit* self = (TUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Parent'",NULL);
#endif

/* getting type */
  char* lua_type = "TUnit";
   tolua_pushusertype(tolua_S,(void*)(self->Parent),lua_type);
 return 1;
}

/* method: GetAttributeValue of class  TUnit */
static int tolua_z_All_TUnit_GetAttributeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUnit",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUnit* self = (TUnit*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* _name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeValue'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetAttributeValue(_name);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeValue'.",&tolua_err);
 return 0;
#endif
}

/* method: GetAttribute of class  TUnit */
static int tolua_z_All_TUnit_GetAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUnit",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUnit* self = (TUnit*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* _name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttribute'",NULL);
#endif
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  self->GetAttribute(_name);

/* getting type */
  char* lua_type = "TLuaAttribute";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttribute'.",&tolua_err);
 return 0;
#endif
}

/* method: SetAttributeValue of class  TUnit */
static int tolua_z_All_TUnit_SetAttributeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUnit",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUnit* self = (TUnit*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* _name = ((char*)  tolua_tostring(tolua_S,2,0));
/*declare*/
  char* _value = ((char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeValue'",NULL);
#endif
  {
   self->SetAttributeValue(_name,_value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeValue'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TLink */
static int tolua_z_All_TLink_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLink* tolua_ret = (TLink*)  new TLink();

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLink */
static int tolua_z_All_TLink_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLink* tolua_ret = (TLink*)  new TLink();

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLink */
static int tolua_z_All_TLink_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Exists of class  TLink */
static int tolua_z_All_TLink_Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* El = ((TElement*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,3,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(El,i);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exists'.",&tolua_err);
 return 0;
#endif
}

/* method: Exists of class  TLink */
static int tolua_z_All_TLink_Exists01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMetaElement* mel = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,3,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(mel,i);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_TLink_Exists00(tolua_S);
}

/* method: NeededFor of class  TLink */
static int tolua_z_All_TLink_NeededFor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* El = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NeededFor'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->NeededFor(El);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NeededFor'.",&tolua_err);
 return 0;
#endif
}

/* get function: Angle of class  TLink */
static int tolua_get_TLink_Angle(lua_State* tolua_S)
{
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Angle'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->Angle)),lua_type);
 return 1;
}

/* method: AbsPositionBy of class  TLink */
static int tolua_z_All_TLink_AbsPositionBy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* El = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AbsPositionBy'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->AbsPositionBy(El);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AbsPositionBy'.",&tolua_err);
 return 0;
#endif
}

/* method: GetPos of class  TLink */
static int tolua_z_All_TLink_GetPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPos'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->GetPos(i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPos'.",&tolua_err);
 return 0;
#endif
}

/* method: GetElement of class  TLink */
static int tolua_z_All_TLink_GetElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetElement'",NULL);
#endif
  {
   TElement* tolua_ret = (TElement*)  self->GetElement(i);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetElement'.",&tolua_err);
 return 0;
#endif
}

/* get function: Counted of class  TLink */
static int tolua_get_TLink_Counted(lua_State* tolua_S)
{
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Counted'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Counted);
 return 1;
}

/* set function: Counted of class  TLink */
static int tolua_set_TLink_Counted(lua_State* tolua_S)
{
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Counted'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Counted = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: MyMeta of class  TLink */
static int tolua_get_TLink_MyMeta_ptr(lua_State* tolua_S)
{
  TLink* self = (TLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MyMeta'",NULL);
#endif

/* getting type */
  char* lua_type = "TDynamicLink";
   tolua_pushusertype(tolua_S,(void*)(self->MyMeta),lua_type);
 return 1;
}

/* method: new of class  TPlatform */
static int tolua_z_All_TPlatform_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TPlatform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TPlatform* tolua_ret = (TPlatform*)  new TPlatform();

/* getting type */
  char* lua_type = "TPlatform";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TPlatform */
static int tolua_z_All_TPlatform_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TPlatform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TPlatform* tolua_ret = (TPlatform*)  new TPlatform();

/* getting type */
  char* lua_type = "TPlatform";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TPlatform */
static int tolua_z_All_TPlatform_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPlatform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPlatform* self = (TPlatform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: CreateClient of class  TPlatform */
static int tolua_z_All_TPlatform_CreateClient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPlatform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPlatform* self = (TPlatform*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* Target = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateClient'",NULL);
#endif
  {
   self->CreateClient(Target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateClient'.",&tolua_err);
 return 0;
#endif
}

/* method: CheckFields of class  TPlatform */
static int tolua_z_All_TPlatform_CheckFields00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPlatform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPlatform* self = (TPlatform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CheckFields'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CheckFields();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CheckFields'.",&tolua_err);
 return 0;
#endif
}

/* method: Init of class  TPlatform */
static int tolua_z_All_TPlatform_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPlatform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPlatform* self = (TPlatform*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}

/* method: FillCompletePolygon of class  TPlatform */
static int tolua_z_All_TPlatform_FillCompletePolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPlatform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPlatform* self = (TPlatform*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  THoledPolygon* CP = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FillCompletePolygon'",NULL);
#endif
  {
   self->FillCompletePolygon(CP);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FillCompletePolygon'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TElement */
static int tolua_z_All_TElement_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TElement* tolua_ret = (TElement*)  new TElement();

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TElement */
static int tolua_z_All_TElement_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TElement* tolua_ret = (TElement*)  new TElement();

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TElement */
static int tolua_z_All_TElement_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: CreateView of class  TElement */
static int tolua_z_All_TElement_CreateView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateView'",NULL);
#endif
  {
   self->ForceCreateView();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateView'.",&tolua_err);
 return 0;
#endif
}

/* method: SetPos of class  TElement */
static int tolua_z_All_TElement_SetPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* newPos = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPos'",NULL);
#endif
  {
   self->SetPos(*newPos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPos'.",&tolua_err);
 return 0;
#endif
}

/* method: SetAngle of class  TElement */
static int tolua_z_All_TElement_SetAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* newAngle = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngle'",NULL);
#endif
  {
   self->SetAngle(*newAngle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngle'.",&tolua_err);
 return 0;
#endif
}

/* method: SetSize of class  TElement */
static int tolua_z_All_TElement_SetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* newSize = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSize'",NULL);
#endif
  {
   self->SetSize(*newSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSize'.",&tolua_err);
 return 0;
#endif
}

/* method: UserChangePosition of class  TElement */
static int tolua_z_All_TElement_UserChangePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Move = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* Rotate = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UserChangePosition'",NULL);
#endif
  {
   self->UserChangePosition(*Move,*Rotate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UserChangePosition'.",&tolua_err);
 return 0;
#endif
}

/* method: ChangeSize of class  TElement */
static int tolua_z_All_TElement_ChangeSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* ChangeVector = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* ChangeDirection = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  bool Try = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChangeSize'",NULL);
#endif
  {
   self->ChangeSize(*ChangeVector,*ChangeDirection,Try);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeSize'.",&tolua_err);
 return 0;
#endif
}

/* method: SetSlope of class  TElement */
static int tolua_z_All_TElement_SetSlope00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* _SlopeMinus = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* _SlopePlus = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  bool Render = ((bool)  tolua_toboolean(tolua_S,4,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSlope'",NULL);
#endif
  {
   self->SetSlope(*_SlopeMinus,*_SlopePlus,Render);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSlope'.",&tolua_err);
 return 0;
#endif
}

/* method: LinkPosition of class  TElement */
static int tolua_z_All_TElement_LinkPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* ElOther = ((TElement*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* Position = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LinkPosition'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->LinkPosition(ElOther,*Position);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LinkPosition'.",&tolua_err);
 return 0;
#endif
}

/* method: CreateClient of class  TElement */
static int tolua_z_All_TElement_CreateClient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* Target = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateClient'",NULL);
#endif
  {
   self->CreateClient(Target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateClient'.",&tolua_err);
 return 0;
#endif
}

/* method: LOW_HI of class  TElement */
static int tolua_z_All_TElement_LOW_HI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TIntVec* LOW = ((TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* HI = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LOW_HI'",NULL);
#endif
  {
   self->LOW_HI(*LOW,*HI);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LOW_HI'.",&tolua_err);
 return 0;
#endif
}

/* get function: CurrentEnabled of class  TElement */
static int tolua_get_TElement_CurrentEnabled(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CurrentEnabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->CurrentEnabled);
 return 1;
}

/* set function: CurrentEnabled of class  TElement */
static int tolua_set_TElement_CurrentEnabled(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CurrentEnabled'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CurrentEnabled = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: CustomEnabled of class  TElement */
static int tolua_get_TElement_CustomEnabled(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CustomEnabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->CustomEnabled);
 return 1;
}

/* get function: ModeEnabled of class  TElement */
static int tolua_get_TElement_ModeEnabled(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ModeEnabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->ModeEnabled);
 return 1;
}

/* get function: TotalEnabled of class  TElement */
static int tolua_get_TElement_TotalEnabled(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TotalEnabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->TotalEnabled);
 return 1;
}

/* get function: AbsSize of class  TElement */
static int tolua_get_TElement_AbsSize(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AbsSize'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->AbsSize)),lua_type);
 return 1;
}

/* set function: AbsSize of class  TElement */
static int tolua_set_TElement_AbsSize(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AbsSize'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AbsSize = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: AbsPos of class  TElement */
static int tolua_get_TElement_AbsPos(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AbsPos'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->AbsPos)),lua_type);
 return 1;
}

/* set function: AbsPos of class  TElement */
static int tolua_set_TElement_AbsPos(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AbsPos'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AbsPos = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: AbsAngle of class  TElement */
static int tolua_get_TElement_AbsAngle(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AbsAngle'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->AbsAngle)),lua_type);
 return 1;
}

/* set function: AbsAngle of class  TElement */
static int tolua_set_TElement_AbsAngle(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AbsAngle'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AbsAngle = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: SlopeMinus of class  TElement */
static int tolua_get_TElement_SlopeMinus(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SlopeMinus'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->SlopeMinus)),lua_type);
 return 1;
}

/* get function: SlopePlus of class  TElement */
static int tolua_get_TElement_SlopePlus(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SlopePlus'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->SlopePlus)),lua_type);
 return 1;
}

/* method: GetLink of class  TElement */
static int tolua_z_All_TElement_GetLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLink'",NULL);
#endif
  {
   TLink* tolua_ret = (TLink*)  self->GetLink(i);

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLink'.",&tolua_err);
 return 0;
#endif
}

/* get function: LinksCount of class  TElement */
static int tolua_get_TElement_LinksCount(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LinksCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->LinksCount);
 return 1;
}

/* method: GetLinkOf of class  TElement */
static int tolua_z_All_TElement_GetLinkOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* El = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinkOf'",NULL);
#endif
  {
   TLink* tolua_ret = (TLink*)  self->GetLinkOf(El);

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinkOf'.",&tolua_err);
 return 0;
#endif
}

/* method: CreateLabel of class  TElement */
static int tolua_z_All_TElement_CreateLabel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  bool Rotateble = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateLabel'",NULL);
#endif
  {
   TLabel3D* tolua_ret = (TLabel3D*)  self->CreateLabel(Rotateble);

/* getting type */
  char* lua_type = "TLabel3D";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateLabel'.",&tolua_err);
 return 0;
#endif
}

/* method: CreateLabel of class  TElement */
static int tolua_z_All_TElement_CreateLabel01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  bool Rotateble = ((bool)  tolua_toboolean(tolua_S,2,0));
/*declare*/
  const TIntVec* Pos = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateLabel'",NULL);
#endif
  {
   TLabel3D* tolua_ret = (TLabel3D*)  self->CreateLabel(Rotateble,*Pos);

/* getting type */
  char* lua_type = "TLabel3D";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_TElement_CreateLabel00(tolua_S);
}

/* method: KillLabel of class  TElement */
static int tolua_z_All_TElement_KillLabel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'KillLabel'",NULL);
#endif
  {
   self->KillLabel();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'KillLabel'.",&tolua_err);
 return 0;
#endif
}

/* method: GetChild of class  TElement */
static int tolua_z_All_TElement_GetChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChild'",NULL);
#endif
  {
   TElement* tolua_ret = (TElement*)  self->GetChild(i);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChild'.",&tolua_err);
 return 0;
#endif
}

/* method: GetChildCount of class  TElement */
static int tolua_z_All_TElement_GetChildCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChildCount'",NULL);
#endif
  {
   int tolua_ret = (int)  self->GetChildCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChildCount'.",&tolua_err);
 return 0;
#endif
}

/* get function: HP of class  TElement */
static int tolua_get_TElement_HP_ptr(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'HP'",NULL);
#endif

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype(tolua_S,(void*)(self->HP),lua_type);
 return 1;
}

/* set function: HP of class  TElement */
static int tolua_set_TElement_HP_ptr(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'HP'",NULL);
  if (!tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->HP = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: ClearPoints of class  TElement */
static int tolua_z_All_TElement_ClearPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearPoints'",NULL);
#endif
  {
   self->ClearPoints();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearPoints'.",&tolua_err);
 return 0;
#endif
}

/* method: AddArrPoint of class  TElement */
static int tolua_z_All_TElement_AddArrPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* _Point = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddArrPoint'",NULL);
#endif
  {
   self->AddArrPoint(*_Point);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddArrPoint'.",&tolua_err);
 return 0;
#endif
}

/* get function: Counted of class  TElement */
static int tolua_get_TElement_Counted(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Counted'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Counted);
 return 1;
}

/* set function: Counted of class  TElement */
static int tolua_set_TElement_Counted(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Counted'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Counted = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: EditStatus of class  TElement */
static int tolua_z_All_TElement_EditStatus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int Operation = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int Type = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'EditStatus'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->EditStatus(Operation,Type);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)Operation);
   tolua_pushnumber(tolua_S,(lua_Number)Type);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'EditStatus'.",&tolua_err);
 return 0;
#endif
}

/* get function: MyMeta of class  TElement */
static int tolua_get_TElement_MyMeta_ptr(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MyMeta'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype(tolua_S,(void*)(self->MyMeta),lua_type);
 return 1;
}

/* get function: SideRender of class  TElement */
static int tolua_get_TElement_SideRender(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SideRender'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->SideRender);
 return 1;
}

/* set function: SideRender of class  TElement */
static int tolua_set_TElement_SideRender(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SideRender'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SideRender = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: Create_SIZER of class  TElement */
static int tolua_z_All_TElement_Create_SIZER00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int ID = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  const TIntVec* P1 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* P2 = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Create_SIZER'",NULL);
#endif
  {
   TElement* tolua_ret = (TElement*)  self->Create_SIZER(ID,*P1,*P2);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Create_SIZER'.",&tolua_err);
 return 0;
#endif
}

/* method: Kill_SIZER of class  TElement */
static int tolua_z_All_TElement_Kill_SIZER00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int ID = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Kill_SIZER'",NULL);
#endif
  {
   self->Kill_SIZER(ID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Kill_SIZER'.",&tolua_err);
 return 0;
#endif
}

/* method: AbsFromLocal of class  TElement */
static int tolua_z_All_TElement_AbsFromLocal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Vector = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* Result = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AbsFromLocal'",NULL);
#endif
  {
   self->AbsFromLocal(*Vector,*Result);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AbsFromLocal'.",&tolua_err);
 return 0;
#endif
}

/* method: LocalFromAbs of class  TElement */
static int tolua_z_All_TElement_LocalFromAbs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Vector = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* Result = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LocalFromAbs'",NULL);
#endif
  {
   self->LocalFromAbs(*Vector,*Result);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LocalFromAbs'.",&tolua_err);
 return 0;
#endif
}

/* method: LocalizePolygon of class  TElement */
static int tolua_z_All_TElement_LocalizePolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LocalizePolygon'",NULL);
#endif
  {
   self->LocalizePolygon();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LocalizePolygon'.",&tolua_err);
 return 0;
#endif
}

/* get function: SideCount of class  TElement */
static int tolua_get_TElement_SideCount(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SideCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->SideCount);
 return 1;
}

/* method: GetSide of class  TElement */
static int tolua_z_All_TElement_GetSide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSide'",NULL);
#endif
  {
   TSide* tolua_ret = (TSide*)  self->GetSide(i);

/* getting type */
  char* lua_type = "TSide";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSide'.",&tolua_err);
 return 0;
#endif
}

/* method: StandartCreateView of class  TElement */
static int tolua_z_All_TElement_StandartCreateView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StandartCreateView'",NULL);
#endif
  {
   self->StandartCreateView();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StandartCreateView'.",&tolua_err);
 return 0;
#endif
}

/* get function: RenderParamCount of class  TElement */
static int tolua_get_TElement_RenderParamCount(lua_State* tolua_S)
{
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'RenderParamCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->RenderParamCount);
 return 1;
}

/* method: GetRenderParam of class  TElement */
static int tolua_z_All_TElement_GetRenderParam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRenderParam'",NULL);
#endif
  {
   TRenderParam* tolua_ret = (TRenderParam*)  self->GetRenderParam(i);

/* getting type */
  char* lua_type = "TRenderParam";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRenderParam'.",&tolua_err);
 return 0;
#endif
}

/* method: RegisterCreateView of class  TElement */
static int tolua_z_All_TElement_RegisterCreateView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterCreateView'",NULL);
#endif
  {
   self->RegisterCreateView();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterCreateView'.",&tolua_err);
 return 0;
#endif
}

/* method: RegisterUpdatePos of class  TElement */
static int tolua_z_All_TElement_RegisterUpdatePos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterUpdatePos'",NULL);
#endif
  {
   self->RegisterUpdatePos();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterUpdatePos'.",&tolua_err);
 return 0;
#endif
}

/* method: RegisterTexturing of class  TElement */
static int tolua_z_All_TElement_RegisterTexturing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterTexturing'",NULL);
#endif
  {
   self->RegisterTexturing();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterTexturing'.",&tolua_err);
 return 0;
#endif
}

/* method: ProcessCreateView of class  TElement */
static int tolua_z_All_TElement_ProcessCreateView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProcessCreateView'",NULL);
#endif
  {
   self->ProcessCreateView();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProcessCreateView'.",&tolua_err);
 return 0;
#endif
}

/* method: ProcessUpdatePos of class  TElement */
static int tolua_z_All_TElement_ProcessUpdatePos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProcessUpdatePos'",NULL);
#endif
  {
   self->ProcessUpdatePos();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProcessUpdatePos'.",&tolua_err);
 return 0;
#endif
}

/* method: ProcessTexturing of class  TElement */
static int tolua_z_All_TElement_ProcessTexturing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProcessTexturing'",NULL);
#endif
  {
   self->ProcessTexturing();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProcessTexturing'.",&tolua_err);
 return 0;
#endif
}

/* method: Render of class  TElement */
static int tolua_z_All_TElement_Render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TVisView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElement* self = (TElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TVisView* aView = ((TVisView*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Render'",NULL);
#endif
  {
   self->Render(aView);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Render'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TLabel3D */
static int tolua_z_All_TLabel3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLabel3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLabel3D* tolua_ret = (TLabel3D*)  new TLabel3D();

/* getting type */
  char* lua_type = "TLabel3D";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLabel3D */
static int tolua_z_All_TLabel3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLabel3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLabel3D* tolua_ret = (TLabel3D*)  new TLabel3D();

/* getting type */
  char* lua_type = "TLabel3D";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLabel3D */
static int tolua_z_All_TLabel3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLabel3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLabel3D* self = (TLabel3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: SetCharText of class  TLabel3D */
static int tolua_z_All_TLabel3D_SetCharText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLabel3D",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLabel3D* self = (TLabel3D*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* _Text = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCharText'",NULL);
#endif
  {
   self->SetCharText(_Text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCharText'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TRoom */
static int tolua_z_All_TRoom_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRoom* tolua_ret = (TRoom*)  new TRoom();

/* getting type */
  char* lua_type = "TRoom";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TRoom */
static int tolua_z_All_TRoom_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRoom* tolua_ret = (TRoom*)  new TRoom();

/* getting type */
  char* lua_type = "TRoom";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TRoom */
static int tolua_z_All_TRoom_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: FloorParam of class  TRoom */
static int tolua_get_TRoom_FloorParam(lua_State* tolua_S)
{
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FloorParam'",NULL);
#endif

/* getting type */
  char* lua_type = "TRenderParam";
   tolua_pushusertype(tolua_S,(void*)(&(self->FloorParam)),lua_type);
 return 1;
}

/* get function: CeilParam of class  TRoom */
static int tolua_get_TRoom_CeilParam(lua_State* tolua_S)
{
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CeilParam'",NULL);
#endif

/* getting type */
  char* lua_type = "TRenderParam";
   tolua_pushusertype(tolua_S,(void*)(&(self->CeilParam)),lua_type);
 return 1;
}

/* method: GetFloorArea of class  TRoom */
static int tolua_z_All_TRoom_GetFloorArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFloorArea'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->GetFloorArea();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFloorArea'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCeilArea of class  TRoom */
static int tolua_z_All_TRoom_GetCeilArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCeilArea'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->GetCeilArea();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCeilArea'.",&tolua_err);
 return 0;
#endif
}

/* get function: CeilServiceZ of class  TRoom */
static int tolua_get_TRoom_CeilServiceZ(lua_State* tolua_S)
{
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CeilServiceZ'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CeilServiceZ);
 return 1;
}

/* set function: CeilServiceZ of class  TRoom */
static int tolua_set_TRoom_CeilServiceZ(lua_State* tolua_S)
{
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CeilServiceZ'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CeilServiceZ = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Status of class  TRoom */
static int tolua_get_TRoom_Status(lua_State* tolua_S)
{
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Status'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Status);
 return 1;
}

/* set function: Status of class  TRoom */
static int tolua_set_TRoom_Status(lua_State* tolua_S)
{
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Status'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Status = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: FloorServiceZ of class  TRoom */
static int tolua_get_TRoom_FloorServiceZ(lua_State* tolua_S)
{
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FloorServiceZ'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FloorServiceZ);
 return 1;
}

/* set function: FloorServiceZ of class  TRoom */
static int tolua_set_TRoom_FloorServiceZ(lua_State* tolua_S)
{
  TRoom* self = (TRoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FloorServiceZ'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FloorServiceZ = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TCube */
static int tolua_z_All_TCube_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TCube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TCube* tolua_ret = (TCube*)  new TCube();

/* getting type */
  char* lua_type = "TCube";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TCube */
static int tolua_z_All_TCube_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TCube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TCube* tolua_ret = (TCube*)  new TCube();

/* getting type */
  char* lua_type = "TCube";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TCube */
static int tolua_z_All_TCube_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCube* self = (TCube*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: VHP of class  TCube */
static int tolua_get_TCube_VHP(lua_State* tolua_S)
{
  TCube* self = (TCube*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'VHP'",NULL);
#endif

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype(tolua_S,(void*)(&(self->VHP)),lua_type);
 return 1;
}

/* get function: FragmentsCount of class  TCube */
static int tolua_get_TCube_FragmentsCount(lua_State* tolua_S)
{
  TCube* self = (TCube*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FragmentsCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FragmentsCount);
 return 1;
}

/* method: GetFragment of class  TCube */
static int tolua_z_All_TCube_GetFragment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCube",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCube* self = (TCube*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFragment'",NULL);
#endif
  {
   TFragmentSettings* tolua_ret = (TFragmentSettings*)  self->GetFragment(i);

/* getting type */
  char* lua_type = "TFragmentSettings";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFragment'.",&tolua_err);
 return 0;
#endif
}

/* method: FragmentArea of class  TCube */
static int tolua_z_All_TCube_FragmentArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCube",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCube* self = (TCube*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int Fragment = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int Param = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FragmentArea'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->FragmentArea(Fragment,Param);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FragmentArea'.",&tolua_err);
 return 0;
#endif
}

/* method: NominateVHP of class  TCube */
static int tolua_z_All_TCube_NominateVHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCube* self = (TCube*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'NominateVHP'",NULL);
#endif
  {
   self->NominateVHP();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NominateVHP'.",&tolua_err);
 return 0;
#endif
}

/* method: FillCompletePolygon of class  TCube */
static int tolua_z_All_TCube_FillCompletePolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCube",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCube* self = (TCube*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  THoledPolygon* CP = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FillCompletePolygon'",NULL);
#endif
  {
   self->FillCompletePolygon(CP);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FillCompletePolygon'.",&tolua_err);
 return 0;
#endif
}

/* get function: VP of class  TCube */
static int tolua_get_TCube_VP_ptr(lua_State* tolua_S)
{
  TCube* self = (TCube*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'VP'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisPrimitiveObj";
   tolua_pushusertype(tolua_S,(void*)(self->VP),lua_type);
 return 1;
}

/* method: new of class  TMultiElement */
static int tolua_z_All_TMultiElement_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMultiElement* tolua_ret = (TMultiElement*)  new TMultiElement();

/* getting type */
  char* lua_type = "TMultiElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMultiElement */
static int tolua_z_All_TMultiElement_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMultiElement* tolua_ret = (TMultiElement*)  new TMultiElement();

/* getting type */
  char* lua_type = "TMultiElement";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMultiElement */
static int tolua_z_All_TMultiElement_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMultiElement* self = (TMultiElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Add of class  TMultiElement */
static int tolua_z_All_TMultiElement_Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMultiElement* self = (TMultiElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   TElement* tolua_ret = (TElement*)  self->Add(index);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: AddOnly of class  TMultiElement */
static int tolua_z_All_TMultiElement_AddOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMultiElement* self = (TMultiElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddOnly'",NULL);
#endif
  {
   TElement* tolua_ret = (TElement*)  self->AddOnly(index);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: DeleteOne of class  TMultiElement */
static int tolua_z_All_TMultiElement_DeleteOne00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMultiElement* self = (TMultiElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* El = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteOne'",NULL);
#endif
  {
   self->DeleteOne(El);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteOne'.",&tolua_err);
 return 0;
#endif
}

/* method: DeleteOne of class  TMultiElement */
static int tolua_z_All_TMultiElement_DeleteOne01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMultiElement* self = (TMultiElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int typeindex = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteOne'",NULL);
#endif
  {
   self->DeleteOne(typeindex,index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_All_TMultiElement_DeleteOne00(tolua_S);
}

/* method: Clear of class  TMultiElement */
static int tolua_z_All_TMultiElement_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMultiElement* self = (TMultiElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}

/* method: GetPart of class  TMultiElement */
static int tolua_z_All_TMultiElement_GetPart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMultiElement* self = (TMultiElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int j = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPart'",NULL);
#endif
  {
   TElement* tolua_ret = (TElement*)  self->GetPart(i,j);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPart'.",&tolua_err);
 return 0;
#endif
}

/* method: CountOf of class  TMultiElement */
static int tolua_z_All_TMultiElement_CountOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMultiElement",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMultiElement* self = (TMultiElement*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CountOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->CountOf(type);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CountOf'.",&tolua_err);
 return 0;
#endif
}

/* get function: MetaPartCount of class  TMultiElement */
static int tolua_get_TMultiElement_MetaPartCount(lua_State* tolua_S)
{
  TMultiElement* self = (TMultiElement*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetaPartCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MetaPartCount);
 return 1;
}

/* function: ToCube */
static int tolua_z_All_ToCube00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TCube* tolua_ret = (TCube*)  ToCube(Obj);

/* getting type */
  char* lua_type = "TCube";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToCube'.",&tolua_err);
 return 0;
#endif
}

/* function: ToRoom */
static int tolua_z_All_ToRoom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TRoom* tolua_ret = (TRoom*)  ToRoom(Obj);

/* getting type */
  char* lua_type = "TRoom";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToRoom'.",&tolua_err);
 return 0;
#endif
}

/* function: ToMultiElement */
static int tolua_z_All_ToMultiElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TMultiElement* tolua_ret = (TMultiElement*)  ToMultiElement(Obj);

/* getting type */
  char* lua_type = "TMultiElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMultiElement'.",&tolua_err);
 return 0;
#endif
}

/* function: ToPlatform */
static int tolua_z_All_ToPlatform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TPlatform* tolua_ret = (TPlatform*)  ToPlatform(Obj);

/* getting type */
  char* lua_type = "TPlatform";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToPlatform'.",&tolua_err);
 return 0;
#endif
}

/* function: ToElement */
static int tolua_z_All_ToElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TElement* tolua_ret = (TElement*)  ToElement(Obj);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToElement'.",&tolua_err);
 return 0;
#endif
}

/* function: ToMetaElement */
static int tolua_z_All_ToMetaElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TMetaElement* tolua_ret = (TMetaElement*)  ToMetaElement(Obj);

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMetaElement'.",&tolua_err);
 return 0;
#endif
}

/* function: ToMetaLink */
static int tolua_z_All_ToMetaLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TMetaLink* tolua_ret = (TMetaLink*)  ToMetaLink(Obj);

/* getting type */
  char* lua_type = "TMetaLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMetaLink'.",&tolua_err);
 return 0;
#endif
}

/* function: ToDynamicLink */
static int tolua_z_All_ToDynamicLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TDynamicLink* tolua_ret = (TDynamicLink*)  ToDynamicLink(Obj);

/* getting type */
  char* lua_type = "TDynamicLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToDynamicLink'.",&tolua_err);
 return 0;
#endif
}

/* function: ToMyRegObject */
static int tolua_z_All_ToMyRegObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TMyRegObject* tolua_ret = (TMyRegObject*)  ToMyRegObject(Obj);

/* getting type */
  char* lua_type = "TMyRegObject";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMyRegObject'.",&tolua_err);
 return 0;
#endif
}

/* function: ToMetaNode */
static int tolua_z_All_ToMetaNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TMetaNode* tolua_ret = (TMetaNode*)  ToMetaNode(Obj);

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMetaNode'.",&tolua_err);
 return 0;
#endif
}

/* function: ToPolygon */
static int tolua_z_All_ToPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TPolygon* tolua_ret = (TPolygon*)  ToPolygon(Obj);

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToPolygon'.",&tolua_err);
 return 0;
#endif
}

/* function: ToMetaTexture */
static int tolua_z_All_ToMetaTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TMetaTexture* tolua_ret = (TMetaTexture*)  ToMetaTexture(Obj);

/* getting type */
  char* lua_type = "TMetaTexture";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMetaTexture'.",&tolua_err);
 return 0;
#endif
}

/* function: ToMetaMaterial */
static int tolua_z_All_ToMetaMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMyObject* Obj = ((TMyObject*)  tolua_tousertype(tolua_S,1,0));
  {
   TMetaMaterial* tolua_ret = (TMetaMaterial*)  ToMetaMaterial(Obj);

/* getting type */
  char* lua_type = "TMetaMaterial";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToMetaMaterial'.",&tolua_err);
 return 0;
#endif
}

/* function: AngleRad */
static int tolua_z_All_AngleRad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* X1 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* X2 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* X3 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
  {
   double tolua_ret = (double)  AngleRad(*X1,*X2,*X3);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AngleRad'.",&tolua_err);
 return 0;
#endif
}

/* function: AngleRadOX */
static int tolua_z_All_AngleRadOX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* X1 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* X2 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
  {
   double tolua_ret = (double)  AngleRadOX(*X1,*X2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AngleRadOX'.",&tolua_err);
 return 0;
#endif
}

/* function: RotateAround */
static int tolua_z_All_RotateAround00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* Point = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* Angle = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec Center = *((TIntVec*)  tolua_tousertype(tolua_S,3,0));
  {
   TIntVec tolua_ret = (TIntVec)  RotateAround(*Point,*Angle,Center);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RotateAround'.",&tolua_err);
 return 0;
#endif
}

/* function: slope_around */
static int tolua_z_All_slope_around00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
   float x = ((  float)  tolua_tonumber(tolua_S,1,0));
/*declare*/
   float y = ((  float)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float y0 = ((  float)  tolua_tonumber(tolua_S,3,0));
/*declare*/
   float angle = ((  float)  tolua_tonumber(tolua_S,4,0));
  {
    float tolua_ret = (  float)  slope_around(x,y,y0,angle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'slope_around'.",&tolua_err);
 return 0;
#endif
}

/* function: slope_delta */
static int tolua_z_All_slope_delta00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
   float y = ((  float)  tolua_tonumber(tolua_S,1,0));
/*declare*/
   float y0 = ((  float)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float angle = ((  float)  tolua_tonumber(tolua_S,3,0));
  {
    float tolua_ret = (  float)  slope_delta(y,y0,angle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'slope_delta'.",&tolua_err);
 return 0;
#endif
}

/* function: SlopeAround */
static int tolua_z_All_SlopeAround00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* Point = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* Slope = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* Param = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* Center = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
  {
   TIntVec tolua_ret = (TIntVec)  SlopeAround(*Point,*Slope,*Param,*Center);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SlopeAround'.",&tolua_err);
 return 0;
#endif
}

/* function: IsLinesCrossedExactly */
static int tolua_z_All_IsLinesCrossedExactly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* _P00 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* _P01 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* _P10 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* _P11 = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TIntVec* CrossPoint = ((TIntVec*)  tolua_tousertype(tolua_S,5,0));
  {
   int tolua_ret = (int)  IsLinesCrossedExactly(*_P00,*_P01,*_P10,*_P11,*CrossPoint);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsLinesCrossedExactly'.",&tolua_err);
 return 0;
#endif
}

/* function: IsLineAndCutCrossedExactly */
static int tolua_z_All_IsLineAndCutCrossedExactly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* LINE0 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* LINE1 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* CUT0 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* CUT1 = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TIntVec* CrossPoint = ((TIntVec*)  tolua_tousertype(tolua_S,5,0));
  {
   int tolua_ret = (int)  IsLineAndCutCrossedExactly(*LINE0,*LINE1,*CUT0,*CUT1,*CrossPoint);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsLineAndCutCrossedExactly'.",&tolua_err);
 return 0;
#endif
}

/* function: IsCutsCrossedExactly */
static int tolua_z_All_IsCutsCrossedExactly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* _P00 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* _P01 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* _P10 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* _P11 = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TIntVec* CrossPoint = ((TIntVec*)  tolua_tousertype(tolua_S,5,0));
  {
   int tolua_ret = (int)  IsCutsCrossedExactly(*_P00,*_P01,*_P10,*_P11,*CrossPoint);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsCutsCrossedExactly'.",&tolua_err);
 return 0;
#endif
}

/* function: Classify */
static int tolua_z_All_Classify00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* P2 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* P0 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* Pl = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
   float EPS = ((  float)  tolua_tonumber(tolua_S,4,0));
  {
   int tolua_ret = (int)  Classify(*P2,*P0,*Pl,EPS);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Classify'.",&tolua_err);
 return 0;
#endif
}

/* function: IsCutsCrossed */
static int tolua_z_All_IsCutsCrossed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* _P00 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* _P01 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* _P10 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* _P11 = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TIntVec* CrossPoint = ((TIntVec*)  tolua_tousertype(tolua_S,5,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,6,0));
  {
   int tolua_ret = (int)  IsCutsCrossed(*_P00,*_P01,*_P10,*_P11,*CrossPoint,USEEPS);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsCutsCrossed'.",&tolua_err);
 return 0;
#endif
}

/* function: IsLinesParallel */
static int tolua_z_All_IsLinesParallel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* _P00 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* _P01 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* _P10 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* _P11 = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  IsLinesParallel(*_P00,*_P01,*_P10,*_P11,USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsLinesParallel'.",&tolua_err);
 return 0;
#endif
}

/* function: IsLinesCollinear */
static int tolua_z_All_IsLinesCollinear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* _P00 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* _P01 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* _P10 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* _P11 = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  IsLinesCollinear(*_P00,*_P01,*_P10,*_P11,USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsLinesCollinear'.",&tolua_err);
 return 0;
#endif
}

/* function: IsCutsCollinearAndCrossing */
static int tolua_z_All_IsCutsCollinearAndCrossing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* _P00 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* _P01 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* _P10 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* _P11 = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,5,0));
  {
   bool tolua_ret = (bool)  IsCutsCollinearAndCrossing(*_P00,*_P01,*_P10,*_P11,USEEPS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsCutsCollinearAndCrossing'.",&tolua_err);
 return 0;
#endif
}

/* function: GetTotalArea */
static int tolua_z_All_GetTotalArea00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMainTree* aWorld = ((TMainTree*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  int FloorIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   double tolua_ret = (double)  GetTotalArea(aWorld,FloorIndex);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTotalArea'.",&tolua_err);
 return 0;
#endif
}

/* function: StrOut */
static int tolua_z_All_StrOut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  char* Text = ((char*)  tolua_tostring(tolua_S,1,0));
/*declare*/
  bool Clear = ((bool)  tolua_toboolean(tolua_S,2,false));
  {
   StrOut(Text,Clear);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StrOut'.",&tolua_err);
 return 0;
#endif
}

/* function: Mes */
static int tolua_z_All_Mes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  char* Text = ((char*)  tolua_tostring(tolua_S,1,0));
/*declare*/
  char* Caption = ((char*)  tolua_tostring(tolua_S,2,NULL));
  {
   int tolua_ret = (int)  Mes(Text,Caption);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Mes'.",&tolua_err);
 return 0;
#endif
}

/* function: VectorP */
static int tolua_z_All_VectorP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* a = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* b = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
  {
   TIntVec tolua_ret = (TIntVec)  VectorP(*a,*b);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'VectorP'.",&tolua_err);
 return 0;
#endif
}

/* function: ScalarP */
static int tolua_z_All_ScalarP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* a = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* b = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
  {
   double tolua_ret = (double)  ScalarP(*a,*b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ScalarP'.",&tolua_err);
 return 0;
#endif
}

/* function: PlaneCrossPoint */
static int tolua_z_All_PlaneCrossPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  const TIntVec* P1 = ((const TIntVec*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  const TIntVec* P2 = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* P3 = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* V1 = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  const TIntVec* V2 = ((const TIntVec*)  tolua_tousertype(tolua_S,5,0));
/*declare*/
  TIntVec* CP = ((TIntVec*)  tolua_tousertype(tolua_S,6,0));
  {
   bool tolua_ret = (bool)  PlaneCrossPoint(*P1,*P2,*P3,*V1,*V2,*CP);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlaneCrossPoint'.",&tolua_err);
 return 0;
#endif
}

/* function: ComposePolygon */
static int tolua_z_All_ComposePolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TPolygon* Pol = ((TPolygon*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  TMDelTList<TPolygon>* Pols = ((TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TMDelTList<TMDelTList<int> >* Indices = ((TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,3,0));
  {
   ComposePolygon(*Pol,*Pols,*Indices);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ComposePolygon'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TCounterBase */
static int tolua_z_All_TCounterBase_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TCounterBase* tolua_ret = (TCounterBase*)  new TCounterBase();

/* getting type */
  char* lua_type = "TCounterBase";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TCounterBase */
static int tolua_z_All_TCounterBase_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TCounterBase* tolua_ret = (TCounterBase*)  new TCounterBase();

/* getting type */
  char* lua_type = "TCounterBase";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TCounterBase */
static int tolua_z_All_TCounterBase_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: DefineField of class  TCounterBase */
static int tolua_z_All_TCounterBase_DefineField00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,7,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,8,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,9,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* FieldName = ((char*)  tolua_tostring(tolua_S,2,0));
/*declare*/
  int Type = ((int)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  char* Meter = ((char*)  tolua_tostring(tolua_S,4,0));
/*declare*/
  int Digit = ((int)  tolua_tonumber(tolua_S,5,0));
/*declare*/
  bool Visible = ((bool)  tolua_toboolean(tolua_S,6,0));
/*declare*/
  bool Accumulate = ((bool)  tolua_toboolean(tolua_S,7,0));
/*declare*/
  bool Total = ((bool)  tolua_toboolean(tolua_S,8,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefineField'",NULL);
#endif
  {
   self->DefineField(FieldName,Type,Meter,Digit,Visible,Accumulate,Total);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DefineField'.",&tolua_err);
 return 0;
#endif
}

/* method: FieldExists of class  TCounterBase */
static int tolua_z_All_TCounterBase_FieldExists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* FieldName = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FieldExists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->FieldExists(FieldName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FieldExists'.",&tolua_err);
 return 0;
#endif
}

/* method: SetData of class  TCounterBase */
static int tolua_z_All_TCounterBase_SetData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMyObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TNomenclature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMyObject* Sender = ((TMyObject*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TNomenclature* Nom = ((TNomenclature*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  char* FieldName = ((char*)  tolua_tostring(tolua_S,4,0));
/*declare*/
  char* Data = ((char*)  tolua_tostring(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetData'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetData(Sender,Nom,FieldName,Data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetData'.",&tolua_err);
 return 0;
#endif
}

/* method: AddData of class  TCounterBase */
static int tolua_z_All_TCounterBase_AddData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMyObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TNomenclature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMyObject* Sender = ((TMyObject*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TNomenclature* Nom = ((TNomenclature*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  char* FieldName = ((char*)  tolua_tostring(tolua_S,4,0));
/*declare*/
  char* Data = ((char*)  tolua_tostring(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddData'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddData(Sender,Nom,FieldName,Data);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddData'.",&tolua_err);
 return 0;
#endif
}

/* method: SetDataByValue of class  TCounterBase */
static int tolua_z_All_TCounterBase_SetDataByValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMyObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TNomenclature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMyObject* Sender = ((TMyObject*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TNomenclature* Nom = ((TNomenclature*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  char* FieldName = ((char*)  tolua_tostring(tolua_S,4,0));
/*declare*/
  char* Data = ((char*)  tolua_tostring(tolua_S,5,0));
/*declare*/
  char* KeyField = ((char*)  tolua_tostring(tolua_S,6,0));
/*declare*/
  char* KeyData = ((char*)  tolua_tostring(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDataByValue'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetDataByValue(Sender,Nom,FieldName,Data,KeyField,KeyData);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDataByValue'.",&tolua_err);
 return 0;
#endif
}

/* method: AddDataByValue of class  TCounterBase */
static int tolua_z_All_TCounterBase_AddDataByValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMyObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TNomenclature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isstring(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMyObject* Sender = ((TMyObject*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TNomenclature* Nom = ((TNomenclature*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  char* FieldName = ((char*)  tolua_tostring(tolua_S,4,0));
/*declare*/
  char* Data = ((char*)  tolua_tostring(tolua_S,5,0));
/*declare*/
  char* KeyField = ((char*)  tolua_tostring(tolua_S,6,0));
/*declare*/
  char* KeyData = ((char*)  tolua_tostring(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddDataByValue'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddDataByValue(Sender,Nom,FieldName,Data,KeyField,KeyData);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddDataByValue'.",&tolua_err);
 return 0;
#endif
}

/* method: GetSum of class  TCounterBase */
static int tolua_z_All_TCounterBase_GetSum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMyObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TNomenclature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMyObject* Sender = ((TMyObject*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TNomenclature* Nom = ((TNomenclature*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  char* FieldName = ((char*)  tolua_tostring(tolua_S,4,0));
/*declare*/
  bool Round = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSum'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetSum(Sender,Nom,FieldName,Round);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSum'.",&tolua_err);
 return 0;
#endif
}

/* method: GetSumByNomFilter of class  TCounterBase */
static int tolua_z_All_TCounterBase_GetSumByNomFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMyRegObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMyObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMyRegObject* Parent = ((TMyRegObject*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TMyObject* Sender = ((TMyObject*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  char* FieldName = ((char*)  tolua_tostring(tolua_S,4,0));
/*declare*/
  bool Round = ((bool)  tolua_toboolean(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSumByNomFilter'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetSumByNomFilter(Parent,Sender,FieldName,Round);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSumByNomFilter'.",&tolua_err);
 return 0;
#endif
}

/* method: Clear of class  TCounterBase */
static int tolua_z_All_TCounterBase_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TCounterBase",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}

/* get function: CountMode of class  TCounterBase */
static int tolua_get_TCounterBase_CountMode(lua_State* tolua_S)
{
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CountMode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CountMode);
 return 1;
}

/* set function: CountMode of class  TCounterBase */
static int tolua_set_TCounterBase_CountMode(lua_State* tolua_S)
{
  TCounterBase* self = (TCounterBase*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CountMode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CountMode = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TFloorInfo */
static int tolua_z_All_TFloorInfo_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TFloorInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TFloorInfo* tolua_ret = (TFloorInfo*)  new TFloorInfo();

/* getting type */
  char* lua_type = "TFloorInfo";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TFloorInfo */
static int tolua_z_All_TFloorInfo_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TFloorInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TFloorInfo* tolua_ret = (TFloorInfo*)  new TFloorInfo();

/* getting type */
  char* lua_type = "TFloorInfo";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TFloorInfo */
static int tolua_z_All_TFloorInfo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TFloorInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Up_Lost of class  TFloorInfo */
static int tolua_get_TFloorInfo_Up_Lost(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Up_Lost'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Up_Lost);
 return 1;
}

/* set function: Up_Lost of class  TFloorInfo */
static int tolua_set_TFloorInfo_Up_Lost(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Up_Lost'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Up_Lost = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Down_Lost of class  TFloorInfo */
static int tolua_get_TFloorInfo_Down_Lost(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Down_Lost'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Down_Lost);
 return 1;
}

/* set function: Down_Lost of class  TFloorInfo */
static int tolua_set_TFloorInfo_Down_Lost(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Down_Lost'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Down_Lost = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: OK_Pressed of class  TFloorInfo */
static int tolua_get_TFloorInfo_OK_Pressed(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OK_Pressed'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->OK_Pressed);
 return 1;
}

/* set function: OK_Pressed of class  TFloorInfo */
static int tolua_set_TFloorInfo_OK_Pressed(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OK_Pressed'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->OK_Pressed = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: FloorName of class  TFloorInfo */
static int tolua_get_TFloorInfo_FloorName(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FloorName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->FloorName);
 return 1;
}

/* set function: FloorName of class  TFloorInfo */
static int tolua_set_TFloorInfo_FloorName(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FloorName'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FloorName = ((char*)  tolua_tostring(tolua_S,2,0));
 return 0;
}

/* get function: Height of class  TFloorInfo */
static int tolua_get_TFloorInfo_Height(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Height);
 return 1;
}

/* set function: Height of class  TFloorInfo */
static int tolua_set_TFloorInfo_Height(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Height = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: FloorFrom of class  TFloorInfo */
static int tolua_get_TFloorInfo_FloorFrom(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FloorFrom'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FloorFrom);
 return 1;
}

/* set function: FloorFrom of class  TFloorInfo */
static int tolua_set_TFloorInfo_FloorFrom(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FloorFrom'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FloorFrom = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: ElToMove of class  TFloorInfo */
static int tolua_get_TFloorInfo_ElToMove_ptr(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ElToMove'",NULL);
#endif

/* getting type */
  char* lua_type = "TMTList<TMetaNode>";
   tolua_pushusertype(tolua_S,(void*)(self->ElToMove),lua_type);
 return 1;
}

/* set function: ElToMove of class  TFloorInfo */
static int tolua_set_TFloorInfo_ElToMove_ptr(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ElToMove'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TMTList<TMetaNode>",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ElToMove = ((TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: AddIndex of class  TFloorInfo */
static int tolua_get_TFloorInfo_AddIndex(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AddIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->AddIndex);
 return 1;
}

/* set function: AddIndex of class  TFloorInfo */
static int tolua_set_TFloorInfo_AddIndex(lua_State* tolua_S)
{
  TFloorInfo* self = (TFloorInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AddIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AddIndex = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TFloor */
static int tolua_z_All_TFloor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TFloor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TFloor* tolua_ret = (TFloor*)  new TFloor();

/* getting type */
  char* lua_type = "TFloor";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TFloor */
static int tolua_z_All_TFloor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TFloor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TFloor* tolua_ret = (TFloor*)  new TFloor();

/* getting type */
  char* lua_type = "TFloor";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TFloor */
static int tolua_z_All_TFloor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TFloor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TFloor* self = (TFloor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: AbsZ of class  TFloor */
static int tolua_get_TFloor_AbsZ(lua_State* tolua_S)
{
  TFloor* self = (TFloor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AbsZ'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->AbsZ);
 return 1;
}

/* get function: FirstElement of class  TFloor */
static int tolua_get_TFloor_FirstElement_ptr(lua_State* tolua_S)
{
  TFloor* self = (TFloor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FirstElement'",NULL);
#endif

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(self->FirstElement),lua_type);
 return 1;
}

/* get function: Height of class  TFloor */
static int tolua_get_TFloor_Height(lua_State* tolua_S)
{
  TFloor* self = (TFloor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Height);
 return 1;
}

/* get function: Up_Lost of class  TFloor */
static int tolua_get_TFloor_Up_Lost(lua_State* tolua_S)
{
  TFloor* self = (TFloor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Up_Lost'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Up_Lost);
 return 1;
}

/* set function: Up_Lost of class  TFloor */
static int tolua_set_TFloor_Up_Lost(lua_State* tolua_S)
{
  TFloor* self = (TFloor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Up_Lost'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Up_Lost = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Down_Lost of class  TFloor */
static int tolua_get_TFloor_Down_Lost(lua_State* tolua_S)
{
  TFloor* self = (TFloor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Down_Lost'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Down_Lost);
 return 1;
}

/* set function: Down_Lost of class  TFloor */
static int tolua_set_TFloor_Down_Lost(lua_State* tolua_S)
{
  TFloor* self = (TFloor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Down_Lost'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Down_Lost = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TMainTree */
static int tolua_z_All_TMainTree_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMainTree* tolua_ret = (TMainTree*)  new TMainTree();

/* getting type */
  char* lua_type = "TMainTree";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMainTree */
static int tolua_z_All_TMainTree_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMainTree* tolua_ret = (TMainTree*)  new TMainTree();

/* getting type */
  char* lua_type = "TMainTree";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMainTree */
static int tolua_z_All_TMainTree_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: FloorOf of class  TMainTree */
static int tolua_z_All_TMainTree_FloorOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* El = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FloorOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->FloorOf(El);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FloorOf'.",&tolua_err);
 return 0;
#endif
}

/* method: FloorOfUseDriver of class  TMainTree */
static int tolua_z_All_TMainTree_FloorOfUseDriver00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* El = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FloorOfUseDriver'",NULL);
#endif
  {
   int tolua_ret = (int)  self->FloorOfUseDriver(El);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FloorOfUseDriver'.",&tolua_err);
 return 0;
#endif
}

/* get function: ActiveFloor of class  TMainTree */
static int tolua_get_TMainTree_ActiveFloor_ptr(lua_State* tolua_S)
{
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ActiveFloor'",NULL);
#endif

/* getting type */
  char* lua_type = "TFloor";
   tolua_pushusertype(tolua_S,(void*)(self->ActiveFloor),lua_type);
 return 1;
}

/* get function: FloorCount of class  TMainTree */
static int tolua_get_TMainTree_FloorCount(lua_State* tolua_S)
{
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FloorCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FloorCount);
 return 1;
}

/* get function: FloorInfo of class  TMainTree */
static int tolua_get_TMainTree_FloorInfo_ptr(lua_State* tolua_S)
{
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FloorInfo'",NULL);
#endif

/* getting type */
  char* lua_type = "TFloorInfo";
   tolua_pushusertype(tolua_S,(void*)(self->FloorInfo),lua_type);
 return 1;
}

/* method: GetFloor of class  TMainTree */
static int tolua_z_All_TMainTree_GetFloor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFloor'",NULL);
#endif
  {
   TFloor* tolua_ret = (TFloor*)  self->GetFloor(i);

/* getting type */
  char* lua_type = "TFloor";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFloor'.",&tolua_err);
 return 0;
#endif
}

/* method: SelectByMetaElement of class  TMainTree */
static int tolua_z_All_TMainTree_SelectByMetaElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMetaElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int Floor = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  TMetaElement* MetaElement = ((TMetaElement*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TMTList<TElement>* LST = ((TMTList<TElement>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SelectByMetaElement'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SelectByMetaElement(Floor,MetaElement,LST);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SelectByMetaElement'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOfFloor of class  TMainTree */
static int tolua_z_All_TMainTree_IndexOfFloor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TFloor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TFloor* Floor = ((TFloor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOfFloor'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOfFloor(Floor);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IndexOfFloor'.",&tolua_err);
 return 0;
#endif
}

/* get function: ModeIndex of class  TMainTree */
static int tolua_get_TMainTree_ModeIndex(lua_State* tolua_S)
{
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ModeIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ModeIndex);
 return 1;
}

/* get function: PrevModeIndex of class  TMainTree */
static int tolua_get_TMainTree_PrevModeIndex(lua_State* tolua_S)
{
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PrevModeIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PrevModeIndex);
 return 1;
}

/* method: AutoConnect of class  TMainTree */
static int tolua_z_All_TMainTree_AutoConnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* Target = ((TElement*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TElement* Source = ((TElement*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AutoConnect'",NULL);
#endif
  {
   self->AutoConnect(Target,Source);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AutoConnect'.",&tolua_err);
 return 0;
#endif
}

///////////////////////////////////Drive////////////////////////////////////////
/* method: AutoConnect of class  TMainTree */
static int tolua_z_All_TMainTree_Process_AddElement(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMainTree* self = (TMainTree*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMetaElement* Mel = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TElement* UseFloorElement = ((TElement*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Process_AddElement'",NULL);
#endif
  {
   self->Process_AddElement(Mel,UseFloorElement);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Process_AddElement'.",&tolua_err);
 return 0;
#endif
}
///////////////////////////////////Drive////////////////////////////////////////

/* method: new of class  TMetaNodeCollection */
static int tolua_z_All_TMetaNodeCollection_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaNodeCollection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaNodeCollection* tolua_ret = (TMetaNodeCollection*)  new TMetaNodeCollection();

/* getting type */
  char* lua_type = "TMetaNodeCollection";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaNodeCollection */
static int tolua_z_All_TMetaNodeCollection_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaNodeCollection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaNodeCollection* tolua_ret = (TMetaNodeCollection*)  new TMetaNodeCollection();

/* getting type */
  char* lua_type = "TMetaNodeCollection";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaNodeCollection */
static int tolua_z_All_TMetaNodeCollection_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaNodeCollection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaNodeCollection* self = (TMetaNodeCollection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: FindMDByName of class  TMetaNodeCollection */
static int tolua_z_All_TMetaNodeCollection_FindMDByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaNodeCollection",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaNodeCollection* self = (TMetaNodeCollection*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindMDByName'",NULL);
#endif
  {
   TMetaNode* tolua_ret = (TMetaNode*)  self->FindMDByName(name);

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindMDByName'.",&tolua_err);
 return 0;
#endif
}

/* method: FindMDByGUID of class  TMetaNodeCollection */
static int tolua_z_All_TMetaNodeCollection_FindMDByGUID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaNodeCollection",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaNodeCollection* self = (TMetaNodeCollection*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* GUID = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindMDByGUID'",NULL);
#endif
  {
   TMetaNode* tolua_ret = (TMetaNode*)  self->FindMDByGUID(GUID);

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindMDByGUID'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  T3DScope */
static int tolua_z_All_T3DScope_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   T3DScope* tolua_ret = (T3DScope*)  new T3DScope();

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  T3DScope */
static int tolua_z_All_T3DScope_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   T3DScope* tolua_ret = (T3DScope*)  new T3DScope();

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  T3DScope */
static int tolua_z_All_T3DScope_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
/*declare*/
  const TIntVec* VecLow = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* VecHi = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
  {
   T3DScope* tolua_ret = (T3DScope*)  new T3DScope(*VecLow,*VecHi);

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_T3DScope_new00(tolua_S);
}

/* method: new_local of class  T3DScope */
static int tolua_z_All_T3DScope_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
/*declare*/
  const TIntVec* VecLow = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* VecHi = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
  {
   T3DScope* tolua_ret = (T3DScope*)  new T3DScope(*VecLow,*VecHi);

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_T3DScope_new00_local(tolua_S);
}

/* method: delete of class  T3DScope */
static int tolua_z_All_T3DScope_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: LOW of class  T3DScope */
static int tolua_get_T3DScope_LOW(lua_State* tolua_S)
{
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LOW'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->LOW)),lua_type);
 return 1;
}

/* set function: LOW of class  T3DScope */
static int tolua_set_T3DScope_LOW(lua_State* tolua_S)
{
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LOW'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->LOW = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: HI of class  T3DScope */
static int tolua_get_T3DScope_HI(lua_State* tolua_S)
{
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'HI'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->HI)),lua_type);
 return 1;
}

/* set function: HI of class  T3DScope */
static int tolua_set_T3DScope_HI(lua_State* tolua_S)
{
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'HI'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->HI = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: CheckFields of class  T3DScope */
static int tolua_z_All_T3DScope_CheckFields00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CheckFields'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CheckFields();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CheckFields'.",&tolua_err);
 return 0;
#endif
}

/* method: Valid of class  T3DScope */
static int tolua_z_All_T3DScope_Valid00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Vec = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Valid'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Valid(*Vec);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Valid'.",&tolua_err);
 return 0;
#endif
}

/* method: CrossedWithStep of class  T3DScope */
static int tolua_z_All_T3DScope_CrossedWithStep00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const T3DScope* OS = ((const T3DScope*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* Step = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CrossedWithStep'",NULL);
#endif
  {
   self->CrossedWithStep(*OS,*Step);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CrossedWithStep'.",&tolua_err);
 return 0;
#endif
}

/* method: Crossed of class  T3DScope */
static int tolua_z_All_T3DScope_Crossed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  T3DScope* OS = ((T3DScope*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Crossed'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Crossed(OS);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Crossed'.",&tolua_err);
 return 0;
#endif
}

/* method: Move of class  T3DScope */
static int tolua_z_All_T3DScope_Move00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Trans = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Move'",NULL);
#endif
  {
   self->Move(*Trans);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Move'.",&tolua_err);
 return 0;
#endif
}

/* method: Scale of class  T3DScope */
static int tolua_z_All_T3DScope_Scale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Scale = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Scale'",NULL);
#endif
  {
   self->Scale(*Scale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Scale'.",&tolua_err);
 return 0;
#endif
}

/* method: PointAbout of class  T3DScope */
static int tolua_z_All_T3DScope_PointAbout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Point = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* Step = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* DiscrStep = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PointAbout'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->PointAbout(*Point,*Step,*DiscrStep);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PointAbout'.",&tolua_err);
 return 0;
#endif
}

/* method: Discrete of class  T3DScope */
static int tolua_z_All_T3DScope_Discrete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"T3DScope",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  T3DScope* self = (T3DScope*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TIntVec* Point = ((TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TIntVec* Step = ((const TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Discrete'",NULL);
#endif
  {
   self->Discrete(*Point,*Step);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Discrete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TObjectAttributePreSet */
static int tolua_z_All_TObjectAttributePreSet_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
/*declare*/
  char* Value = ((char*)  tolua_tostring(tolua_S,3,0));
  {
   TObjectAttributePreSet* tolua_ret = (TObjectAttributePreSet*)  new TObjectAttributePreSet(Name,Value);

/* getting type */
  char* lua_type = "TObjectAttributePreSet";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TObjectAttributePreSet */
static int tolua_z_All_TObjectAttributePreSet_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
/*declare*/
  char* Value = ((char*)  tolua_tostring(tolua_S,3,0));
  {
   TObjectAttributePreSet* tolua_ret = (TObjectAttributePreSet*)  new TObjectAttributePreSet(Name,Value);

/* getting type */
  char* lua_type = "TObjectAttributePreSet";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TObjectAttributePreSet */
static int tolua_z_All_TObjectAttributePreSet_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TObjectAttributePreSet* self = (TObjectAttributePreSet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: SetAttributeName of class  TObjectAttributePreSet */
static int tolua_z_All_TObjectAttributePreSet_SetAttributeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TObjectAttributePreSet* self = (TObjectAttributePreSet*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeName'",NULL);
#endif
  {
   self->SetAttributeName(Name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeName'.",&tolua_err);
 return 0;
#endif
}

/* method: SetAttributeValue of class  TObjectAttributePreSet */
static int tolua_z_All_TObjectAttributePreSet_SetAttributeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TObjectAttributePreSet* self = (TObjectAttributePreSet*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* Value = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeValue'",NULL);
#endif
  {
   self->SetAttributeValue(Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeValue'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TSyngleLink */
static int tolua_z_All_TSyngleLink_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TSyngleLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TSyngleLink* tolua_ret = (TSyngleLink*)  new TSyngleLink();

/* getting type */
  char* lua_type = "TSyngleLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TSyngleLink */
static int tolua_z_All_TSyngleLink_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TSyngleLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TSyngleLink* tolua_ret = (TSyngleLink*)  new TSyngleLink();

/* getting type */
  char* lua_type = "TSyngleLink";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TSyngleLink */
static int tolua_z_All_TSyngleLink_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSyngleLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSyngleLink* self = (TSyngleLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: CrossPoint of class  TSyngleLink */
static int tolua_get_TSyngleLink_CrossPoint(lua_State* tolua_S)
{
  TSyngleLink* self = (TSyngleLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CrossPoint'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->CrossPoint)),lua_type);
 return 1;
}

/* set function: CrossPoint of class  TSyngleLink */
static int tolua_set_TSyngleLink_CrossPoint(lua_State* tolua_S)
{
  TSyngleLink* self = (TSyngleLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CrossPoint'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CrossPoint = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: OAPreSet of class  TSyngleLink */
static int tolua_get_TSyngleLink_OAPreSet(lua_State* tolua_S)
{
  TSyngleLink* self = (TSyngleLink*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OAPreSet'",NULL);
#endif

/* getting type */
  char* lua_type = "TMDelTList<TObjectAttributePreSet>";
   tolua_pushusertype(tolua_S,(void*)(&(self->OAPreSet)),lua_type);
 return 1;
}

/* method: new of class  TLINKPATTERN */
static int tolua_z_All_TLINKPATTERN_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLINKPATTERN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLINKPATTERN* tolua_ret = (TLINKPATTERN*)  new TLINKPATTERN();

/* getting type */
  char* lua_type = "TLINKPATTERN";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLINKPATTERN */
static int tolua_z_All_TLINKPATTERN_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLINKPATTERN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLINKPATTERN* tolua_ret = (TLINKPATTERN*)  new TLINKPATTERN();

/* getting type */
  char* lua_type = "TLINKPATTERN";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLINKPATTERN */
static int tolua_z_All_TLINKPATTERN_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLINKPATTERN",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: DL of class  TLINKPATTERN */
static int tolua_get_TLINKPATTERN_DL_ptr(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DL'",NULL);
#endif

/* getting type */
  char* lua_type = "TDynamicLink";
   tolua_pushusertype(tolua_S,(void*)(self->DL),lua_type);
 return 1;
}

/* set function: DL of class  TLINKPATTERN */
static int tolua_set_TLINKPATTERN_DL_ptr(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'DL'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TDynamicLink",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->DL = ((TDynamicLink*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: TS_Common of class  TLINKPATTERN */
static int tolua_get_TLINKPATTERN_TS_Common(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TS_Common'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->TS_Common)),lua_type);
 return 1;
}

/* set function: TS_Common of class  TLINKPATTERN */
static int tolua_set_TLINKPATTERN_TS_Common(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TS_Common'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TS_Common = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: R_Common of class  TLINKPATTERN */
static int tolua_get_TLINKPATTERN_R_Common(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'R_Common'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->R_Common)),lua_type);
 return 1;
}

/* set function: R_Common of class  TLINKPATTERN */
static int tolua_set_TLINKPATTERN_R_Common(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'R_Common'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->R_Common = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: CrossPoint of class  TLINKPATTERN */
static int tolua_get_TLINKPATTERN_CrossPoint(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CrossPoint'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->CrossPoint)),lua_type);
 return 1;
}

/* set function: CrossPoint of class  TLINKPATTERN */
static int tolua_set_TLINKPATTERN_CrossPoint(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CrossPoint'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CrossPoint = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Direction of class  TLINKPATTERN */
static int tolua_get_TLINKPATTERN_Direction(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Direction'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->Direction)),lua_type);
 return 1;
}

/* set function: Direction of class  TLINKPATTERN */
static int tolua_set_TLINKPATTERN_Direction(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Direction'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Direction = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: RotateCenter of class  TLINKPATTERN */
static int tolua_get_TLINKPATTERN_RotateCenter(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'RotateCenter'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->RotateCenter)),lua_type);
 return 1;
}

/* set function: RotateCenter of class  TLINKPATTERN */
static int tolua_set_TLINKPATTERN_RotateCenter(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'RotateCenter'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->RotateCenter = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: SyngleLinks of class  TLINKPATTERN */
static int tolua_get_TLINKPATTERN_SyngleLinks(lua_State* tolua_S)
{
  TLINKPATTERN* self = (TLINKPATTERN*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SyngleLinks'",NULL);
#endif

/* getting type */
  char* lua_type = "TMDelTList<TSyngleLink>";
   tolua_pushusertype(tolua_S,(void*)(&(self->SyngleLinks)),lua_type);
 return 1;
}

/* method: new of class  TLinkInfo */
static int tolua_z_All_TLinkInfo_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLinkInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLinkInfo* tolua_ret = (TLinkInfo*)  new TLinkInfo();

/* getting type */
  char* lua_type = "TLinkInfo";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLinkInfo */
static int tolua_z_All_TLinkInfo_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLinkInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLinkInfo* tolua_ret = (TLinkInfo*)  new TLinkInfo();

/* getting type */
  char* lua_type = "TLinkInfo";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLinkInfo */
static int tolua_z_All_TLinkInfo_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkInfo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Target of class  TLinkInfo */
static int tolua_get_TLinkInfo_Target_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Target'",NULL);
#endif

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(self->Target),lua_type);
 return 1;
}

/* set function: Target of class  TLinkInfo */
static int tolua_set_TLinkInfo_Target_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Target'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Target = ((TElement*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Source of class  TLinkInfo */
static int tolua_get_TLinkInfo_Source_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Source'",NULL);
#endif

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(self->Source),lua_type);
 return 1;
}

/* set function: Source of class  TLinkInfo */
static int tolua_set_TLinkInfo_Source_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Source'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Source = ((TElement*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: TargetScope of class  TLinkInfo */
static int tolua_get_TLinkInfo_TargetScope_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TargetScope'",NULL);
#endif

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype(tolua_S,(void*)(self->TargetScope),lua_type);
 return 1;
}

/* set function: TargetScope of class  TLinkInfo */
static int tolua_set_TLinkInfo_TargetScope_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TargetScope'",NULL);
  if (!tolua_isusertype(tolua_S,2,"T3DScope",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TargetScope = ((T3DScope*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: SourceScope of class  TLinkInfo */
static int tolua_get_TLinkInfo_SourceScope_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SourceScope'",NULL);
#endif

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype(tolua_S,(void*)(self->SourceScope),lua_type);
 return 1;
}

/* set function: SourceScope of class  TLinkInfo */
static int tolua_set_TLinkInfo_SourceScope_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SourceScope'",NULL);
  if (!tolua_isusertype(tolua_S,2,"T3DScope",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SourceScope = ((T3DScope*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: LINKPATTERN of class  TLinkInfo */
static int tolua_get_TLinkInfo_LINKPATTERN_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LINKPATTERN'",NULL);
#endif

/* getting type */
  char* lua_type = "TLINKPATTERN";
   tolua_pushusertype(tolua_S,(void*)(self->LINKPATTERN),lua_type);
 return 1;
}

/* set function: LINKPATTERN of class  TLinkInfo */
static int tolua_set_TLinkInfo_LINKPATTERN_ptr(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LINKPATTERN'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TLINKPATTERN",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->LINKPATTERN = ((TLINKPATTERN*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: SizeTransform of class  TLinkInfo */
static int tolua_get_TLinkInfo_SizeTransform(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SizeTransform'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->SizeTransform);
 return 1;
}

/* set function: SizeTransform of class  TLinkInfo */
static int tolua_set_TLinkInfo_SizeTransform(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SizeTransform'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SizeTransform = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: OK of class  TLinkInfo */
static int tolua_get_TLinkInfo_OK(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OK'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->OK);
 return 1;
}

/* set function: OK of class  TLinkInfo */
static int tolua_set_TLinkInfo_OK(lua_State* tolua_S)
{
  TLinkInfo* self = (TLinkInfo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OK'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->OK = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: new of class  TSide */
static int tolua_z_All_TSide_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TSide* tolua_ret = (TSide*)  new TSide();

/* getting type */
  char* lua_type = "TSide";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TSide */
static int tolua_z_All_TSide_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TSide* tolua_ret = (TSide*)  new TSide();

/* getting type */
  char* lua_type = "TSide";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TSide */
static int tolua_z_All_TSide_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: SideType of class  TSide */
static int tolua_get_TSide_SideType(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SideType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->SideType);
 return 1;
}

/* set function: SideType of class  TSide */
static int tolua_set_TSide_SideType(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SideType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SideType = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Node0 of class  TSide */
static int tolua_get_TSide_Node0_ptr(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Node0'",NULL);
#endif

/* getting type */
  char* lua_type = "TRouteNode";
   tolua_pushusertype(tolua_S,(void*)(self->Node0),lua_type);
 return 1;
}

/* get function: CenterP0 of class  TSide */
static int tolua_get_TSide_CenterP0_ptr(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CenterP0'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(self->CenterP0),lua_type);
 return 1;
}

/* get function: P0 of class  TSide */
static int tolua_get_TSide_P0_ptr(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'P0'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(self->P0),lua_type);
 return 1;
}

/* get function: Node1 of class  TSide */
static int tolua_get_TSide_Node1_ptr(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Node1'",NULL);
#endif

/* getting type */
  char* lua_type = "TRouteNode";
   tolua_pushusertype(tolua_S,(void*)(self->Node1),lua_type);
 return 1;
}

/* get function: CenterP1 of class  TSide */
static int tolua_get_TSide_CenterP1_ptr(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CenterP1'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(self->CenterP1),lua_type);
 return 1;
}

/* get function: P1 of class  TSide */
static int tolua_get_TSide_P1_ptr(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'P1'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(self->P1),lua_type);
 return 1;
}

/* get function: Premises of class  TSide */
static int tolua_get_TSide_Premises_ptr(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Premises'",NULL);
#endif

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype(tolua_S,(void*)(self->Premises),lua_type);
 return 1;
}

/* get function: Element of class  TSide */
static int tolua_get_TSide_Element_ptr(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Element'",NULL);
#endif

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(self->Element),lua_type);
 return 1;
}

/* method: Crossed of class  TSide */
static int tolua_z_All_TSide_Crossed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TSide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TSide* ELSE = ((const TSide*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* CROSS_POINT = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Crossed'",NULL);
#endif
  {
   int tolua_ret = (int)  self->Crossed(*ELSE,*CROSS_POINT,USEEPS);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Crossed'.",&tolua_err);
 return 0;
#endif
}

/* method: AnalizePoint of class  TSide */
static int tolua_z_All_TSide_AnalizePoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Point = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AnalizePoint'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AnalizePoint(*Point);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AnalizePoint'.",&tolua_err);
 return 0;
#endif
}

/* method: ConsistsPoint of class  TSide */
static int tolua_z_All_TSide_ConsistsPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Point = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ConsistsPoint'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ConsistsPoint(*Point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConsistsPoint'.",&tolua_err);
 return 0;
#endif
}

/* method: SplitMeDestination of class  TSide */
static int tolua_z_All_TSide_SplitMeDestination00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TSide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TRouteNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TSide* New_ = ((TSide*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* Middle = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TIntVec* CenterMiddle = ((TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TRouteNode* RouteMiddle = ((TRouteNode*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SplitMeDestination'",NULL);
#endif
  {
   self->SplitMeDestination(*New_,Middle,CenterMiddle,RouteMiddle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SplitMeDestination'.",&tolua_err);
 return 0;
#endif
}

/* method: SplitMeOrigin of class  TSide */
static int tolua_z_All_TSide_SplitMeOrigin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TSide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TRouteNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TSide* New_ = ((TSide*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* Middle = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TIntVec* CenterMiddle = ((TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TRouteNode* RouteMiddle = ((TRouteNode*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SplitMeOrigin'",NULL);
#endif
  {
   self->SplitMeOrigin(*New_,Middle,CenterMiddle,RouteMiddle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SplitMeOrigin'.",&tolua_err);
 return 0;
#endif
}

/* method: UpdateEdge of class  TSide */
static int tolua_z_All_TSide_UpdateEdge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TRouteNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TIntVec* NewDest = ((TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* NewCenterDest = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  bool DestinationEdge = ((bool)  tolua_toboolean(tolua_S,4,0));
/*declare*/
  TRouteNode* NewNode = ((TRouteNode*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateEdge'",NULL);
#endif
  {
   self->UpdateEdge(NewDest,NewCenterDest,DestinationEdge,NewNode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateEdge'.",&tolua_err);
 return 0;
#endif
}

/* method: IsOutSide of class  TSide */
static int tolua_z_All_TSide_IsOutSide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSide",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsOutSide'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsOutSide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsOutSide'.",&tolua_err);
 return 0;
#endif
}

/* get function: ISWALLEND of class  TSide */
static int tolua_get_TSide_ISWALLEND(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ISWALLEND'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->ISWALLEND);
 return 1;
}

/* get function: ISWALLSTART of class  TSide */
static int tolua_get_TSide_ISWALLSTART(lua_State* tolua_S)
{
  TSide* self = (TSide*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ISWALLSTART'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->ISWALLSTART);
 return 1;
}

/* method: new of class  TLinkPair */
static int tolua_z_All_TLinkPair_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLinkPair",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLinkPair* tolua_ret = (TLinkPair*)  new TLinkPair();

/* getting type */
  char* lua_type = "TLinkPair";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLinkPair */
static int tolua_z_All_TLinkPair_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLinkPair",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLinkPair* tolua_ret = (TLinkPair*)  new TLinkPair();

/* getting type */
  char* lua_type = "TLinkPair";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLinkPair */
static int tolua_z_All_TLinkPair_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkPair",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkPair* self = (TLinkPair*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Pos of class  TLinkPair */
static int tolua_get_TLinkPair_Pos(lua_State* tolua_S)
{
  TLinkPair* self = (TLinkPair*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pos'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->Pos)),lua_type);
 return 1;
}

/* get function: Link of class  TLinkPair */
static int tolua_get_TLinkPair_Link_ptr(lua_State* tolua_S)
{
  TLinkPair* self = (TLinkPair*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Link'",NULL);
#endif

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype(tolua_S,(void*)(self->Link),lua_type);
 return 1;
}

/* method: Satisfy of class  TLinkPair */
static int tolua_z_All_TLinkPair_Satisfy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkPair",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkPair* self = (TLinkPair*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* ElseVec = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Satisfy'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Satisfy(*ElseVec);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Satisfy'.",&tolua_err);
 return 0;
#endif
}

/* method: GetTranslate of class  TLinkPair */
static int tolua_z_All_TLinkPair_GetTranslate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkPair",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkPair* self = (TLinkPair*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* From = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* Translate = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTranslate'",NULL);
#endif
  {
   self->GetTranslate(*From,*Translate);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTranslate'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TRay */
static int tolua_z_All_TRay_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRay* tolua_ret = (TRay*)  new TRay();

/* getting type */
  char* lua_type = "TRay";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TRay */
static int tolua_z_All_TRay_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRay* tolua_ret = (TRay*)  new TRay();

/* getting type */
  char* lua_type = "TRay";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TRay */
static int tolua_z_All_TRay_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRay* self = (TRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: XPlusDirection of class  TRay */
static int tolua_get_TRay_XPlusDirection(lua_State* tolua_S)
{
  TRay* self = (TRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'XPlusDirection'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->XPlusDirection);
 return 1;
}

/* get function: ElementPoints of class  TRay */
static int tolua_get_TRay_ElementPoints_ptr(lua_State* tolua_S)
{
  TRay* self = (TRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ElementPoints'",NULL);
#endif

/* getting type */
  char* lua_type = "TElementPoints";
   tolua_pushusertype(tolua_S,(void*)(self->ElementPoints),lua_type);
 return 1;
}

/* get function: YMinusSide of class  TRay */
static int tolua_get_TRay_YMinusSide_ptr(lua_State* tolua_S)
{
  TRay* self = (TRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'YMinusSide'",NULL);
#endif

/* getting type */
  char* lua_type = "TSide";
   tolua_pushusertype(tolua_S,(void*)(self->YMinusSide),lua_type);
 return 1;
}

/* get function: YPlusSide of class  TRay */
static int tolua_get_TRay_YPlusSide_ptr(lua_State* tolua_S)
{
  TRay* self = (TRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'YPlusSide'",NULL);
#endif

/* getting type */
  char* lua_type = "TSide";
   tolua_pushusertype(tolua_S,(void*)(self->YPlusSide),lua_type);
 return 1;
}

/* get function: Point of class  TRay */
static int tolua_get_TRay_Point_ptr(lua_State* tolua_S)
{
  TRay* self = (TRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Point'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(self->Point),lua_type);
 return 1;
}

/* get function: AngleOX of class  TRay */
static int tolua_get_TRay_AngleOX(lua_State* tolua_S)
{
  TRay* self = (TRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AngleOX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->AngleOX);
 return 1;
}

/* method: new of class  TRoutePoint */
static int tolua_z_All_TRoutePoint_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRoutePoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRoutePoint* tolua_ret = (TRoutePoint*)  new TRoutePoint();

/* getting type */
  char* lua_type = "TRoutePoint";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TRoutePoint */
static int tolua_z_All_TRoutePoint_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRoutePoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRoutePoint* tolua_ret = (TRoutePoint*)  new TRoutePoint();

/* getting type */
  char* lua_type = "TRoutePoint";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TRoutePoint */
static int tolua_z_All_TRoutePoint_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRoutePoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRoutePoint* self = (TRoutePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Pnt of class  TRoutePoint */
static int tolua_get_TRoutePoint_Pnt_ptr(lua_State* tolua_S)
{
  TRoutePoint* self = (TRoutePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Pnt'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(self->Pnt),lua_type);
 return 1;
}

/* get function: InputSide of class  TRoutePoint */
static int tolua_get_TRoutePoint_InputSide_ptr(lua_State* tolua_S)
{
  TRoutePoint* self = (TRoutePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'InputSide'",NULL);
#endif

/* getting type */
  char* lua_type = "TSide";
   tolua_pushusertype(tolua_S,(void*)(self->InputSide),lua_type);
 return 1;
}

/* get function: OutPutSide of class  TRoutePoint */
static int tolua_get_TRoutePoint_OutPutSide_ptr(lua_State* tolua_S)
{
  TRoutePoint* self = (TRoutePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OutPutSide'",NULL);
#endif

/* getting type */
  char* lua_type = "TSide";
   tolua_pushusertype(tolua_S,(void*)(self->OutPutSide),lua_type);
 return 1;
}

/* get function: Next of class  TRoutePoint */
static int tolua_get_TRoutePoint_Next_ptr(lua_State* tolua_S)
{
  TRoutePoint* self = (TRoutePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Next'",NULL);
#endif

/* getting type */
  char* lua_type = "TRoutePoint";
   tolua_pushusertype(tolua_S,(void*)(self->Next),lua_type);
 return 1;
}

/* get function: Prev of class  TRoutePoint */
static int tolua_get_TRoutePoint_Prev_ptr(lua_State* tolua_S)
{
  TRoutePoint* self = (TRoutePoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Prev'",NULL);
#endif

/* getting type */
  char* lua_type = "TRoutePoint";
   tolua_pushusertype(tolua_S,(void*)(self->Prev),lua_type);
 return 1;
}

/* method: new of class  TElementPoints */
static int tolua_z_All_TElementPoints_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElementPoints",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TElementPoints* tolua_ret = (TElementPoints*)  new TElementPoints();

/* getting type */
  char* lua_type = "TElementPoints";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TElementPoints */
static int tolua_z_All_TElementPoints_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElementPoints",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TElementPoints* tolua_ret = (TElementPoints*)  new TElementPoints();

/* getting type */
  char* lua_type = "TElementPoints";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TElementPoints */
static int tolua_z_All_TElementPoints_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementPoints",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementPoints* self = (TElementPoints*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Element of class  TElementPoints */
static int tolua_get_TElementPoints_Element_ptr(lua_State* tolua_S)
{
  TElementPoints* self = (TElementPoints*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Element'",NULL);
#endif

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(self->Element),lua_type);
 return 1;
}

/* method: FindSide of class  TElementPoints */
static int tolua_z_All_TElementPoints_FindSide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementPoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementPoints* self = (TElementPoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int Type = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  TIntVec* Point = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  bool ByDestination = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindSide'",NULL);
#endif
  {
   TSide* tolua_ret = (TSide*)  self->FindSide(Type,Point,ByDestination);

/* getting type */
  char* lua_type = "TSide";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindSide'.",&tolua_err);
 return 0;
#endif
}

/* get function: SideCount of class  TElementPoints */
static int tolua_get_TElementPoints_SideCount(lua_State* tolua_S)
{
  TElementPoints* self = (TElementPoints*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SideCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->SideCount);
 return 1;
}

/* get function: FilteredRouteNodesCount of class  TElementPoints */
static int tolua_get_TElementPoints_FilteredRouteNodesCount(lua_State* tolua_S)
{
  TElementPoints* self = (TElementPoints*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FilteredRouteNodesCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FilteredRouteNodesCount);
 return 1;
}

/* get function: AllRouteNodesCount of class  TElementPoints */
static int tolua_get_TElementPoints_AllRouteNodesCount(lua_State* tolua_S)
{
  TElementPoints* self = (TElementPoints*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AllRouteNodesCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->AllRouteNodesCount);
 return 1;
}

/* method: GetSide of class  TElementPoints */
static int tolua_z_All_TElementPoints_GetSide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementPoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementPoints* self = (TElementPoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSide'",NULL);
#endif
  {
   TSide* tolua_ret = (TSide*)  self->GetSide(i);

/* getting type */
  char* lua_type = "TSide";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSide'.",&tolua_err);
 return 0;
#endif
}

/* method: GetFilteredRouteNode of class  TElementPoints */
static int tolua_z_All_TElementPoints_GetFilteredRouteNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementPoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementPoints* self = (TElementPoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFilteredRouteNode'",NULL);
#endif
  {
   TRouteNode* tolua_ret = (TRouteNode*)  self->GetFilteredRouteNode(i);

/* getting type */
  char* lua_type = "TRouteNode";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFilteredRouteNode'.",&tolua_err);
 return 0;
#endif
}

/* method: GetAllRouteNode of class  TElementPoints */
static int tolua_z_All_TElementPoints_GetAllRouteNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementPoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementPoints* self = (TElementPoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllRouteNode'",NULL);
#endif
  {
   TRouteNode* tolua_ret = (TRouteNode*)  self->GetAllRouteNode(i);

/* getting type */
  char* lua_type = "TRouteNode";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllRouteNode'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TRouteNode */
static int tolua_z_All_TRouteNode_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRouteNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRouteNode* tolua_ret = (TRouteNode*)  new TRouteNode();

/* getting type */
  char* lua_type = "TRouteNode";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TRouteNode */
static int tolua_z_All_TRouteNode_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRouteNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRouteNode* tolua_ret = (TRouteNode*)  new TRouteNode();

/* getting type */
  char* lua_type = "TRouteNode";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TRouteNode */
static int tolua_z_All_TRouteNode_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRouteNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: LinkPoint of class  TRouteNode */
static int tolua_get_TRouteNode_LinkPoint(lua_State* tolua_S)
{
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LinkPoint'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->LinkPoint)),lua_type);
 return 1;
}

/* get function: Element of class  TRouteNode */
static int tolua_get_TRouteNode_Element_ptr(lua_State* tolua_S)
{
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Element'",NULL);
#endif

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(self->Element),lua_type);
 return 1;
}

/* get function: RayCount of class  TRouteNode */
static int tolua_get_TRouteNode_RayCount(lua_State* tolua_S)
{
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'RayCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->RayCount);
 return 1;
}

/* method: GetRay of class  TRouteNode */
static int tolua_z_All_TRouteNode_GetRay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRouteNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRay'",NULL);
#endif
  {
   TRay* tolua_ret = (TRay*)  self->GetRay(i);

/* getting type */
  char* lua_type = "TRay";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRay'.",&tolua_err);
 return 0;
#endif
}

/* get function: LinkPairCount of class  TRouteNode */
static int tolua_get_TRouteNode_LinkPairCount(lua_State* tolua_S)
{
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LinkPairCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->LinkPairCount);
 return 1;
}

/* method: GetLinkPair of class  TRouteNode */
static int tolua_z_All_TRouteNode_GetLinkPair00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRouteNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinkPair'",NULL);
#endif
  {
   TLinkPair* tolua_ret = (TLinkPair*)  self->GetLinkPair(i);

/* getting type */
  char* lua_type = "TLinkPair";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinkPair'.",&tolua_err);
 return 0;
#endif
}

/* get function: RayCrossCount of class  TRouteNode */
static int tolua_get_TRouteNode_RayCrossCount(lua_State* tolua_S)
{
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'RayCrossCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->RayCrossCount);
 return 1;
}

/* method: GetRayCross of class  TRouteNode */
static int tolua_z_All_TRouteNode_GetRayCross00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRouteNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRayCross'",NULL);
#endif
  {
   TIntVec* tolua_ret = (TIntVec*)  self->GetRayCross(i);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRayCross'.",&tolua_err);
 return 0;
#endif
}

/* method: Satisfy of class  TRouteNode */
static int tolua_z_All_TRouteNode_Satisfy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRouteNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLinkPair",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TLinkPair* LinkPair = ((TLinkPair*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Satisfy'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Satisfy(LinkPair);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Satisfy'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TRouteNode */
static int tolua_z_All_TRouteNode_IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRouteNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLinkPair",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRouteNode* self = (TRouteNode*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TLinkPair* LinkPair = ((TLinkPair*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(LinkPair);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IndexOf'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLinkNodes* tolua_ret = (TLinkNodes*)  new TLinkNodes();

/* getting type */
  char* lua_type = "TLinkNodes";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLinkNodes* tolua_ret = (TLinkNodes*)  new TLinkNodes();

/* getting type */
  char* lua_type = "TLinkNodes";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Exists of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TLink* Link = ((TLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   int tolua_ret = (int)  self->Exists(Link);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exists'.",&tolua_err);
 return 0;
#endif
}

/* method: ExistsElem of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_ExistsElem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* Elem = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ExistsElem'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ExistsElem(Elem);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ExistsElem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetLinksForVec of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_GetLinksForVec00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Vec = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TMTList<TLink>* LNKL = ((TMTList<TLink>*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TElement* Parent = ((TElement*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinksForVec'",NULL);
#endif
  {
   self->GetLinksForVec(*Vec,LNKL,Parent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinksForVec'.",&tolua_err);
 return 0;
#endif
}

/* method: GetLinksForLink of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_GetLinksForLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLink",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TLink* Link = ((TLink*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TMTList<TLink>* LNKL = ((TMTList<TLink>*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  bool NeedFalse = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLinksForLink'",NULL);
#endif
  {
   self->GetLinksForLink(Link,LNKL,NeedFalse);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLinksForLink'.",&tolua_err);
 return 0;
#endif
}

/* method: SelectNearestPoint of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_SelectNearestPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Point = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TMTList<TMetaElement>* ELS = ((TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TMDelTList<TIntVec>* Steps = ((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TIntVec* Trans = ((TIntVec*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SelectNearestPoint'",NULL);
#endif
  {
   TElement* tolua_ret = (TElement*)  self->SelectNearestPoint(*Point,ELS,Steps,*Trans);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SelectNearestPoint'.",&tolua_err);
 return 0;
#endif
}

/* method: SelectNearestLink of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_SelectNearestLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TMetaElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Point = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* Trans = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TMetaElement* El0 = ((TMetaElement*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TMetaElement* El1 = ((TMetaElement*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SelectNearestLink'",NULL);
#endif
  {
   TLink* tolua_ret = (TLink*)  self->SelectNearestLink(*Point,*Trans,El0,El1);

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SelectNearestLink'.",&tolua_err);
 return 0;
#endif
}

/* method: DefinePermises_06 of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_DefinePermises_0600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* ParentFilter = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DefinePermises_06'",NULL);
#endif
  {
   self->DefinePermises_06(ParentFilter);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DefinePermises_06'.",&tolua_err);
 return 0;
#endif
}

/* get function: RouteNodeCount of class  TLinkNodes */
static int tolua_get_TLinkNodes_RouteNodeCount(lua_State* tolua_S)
{
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'RouteNodeCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->RouteNodeCount);
 return 1;
}

/* get function: ElementFragmentsCount of class  TLinkNodes */
static int tolua_get_TLinkNodes_ElementFragmentsCount(lua_State* tolua_S)
{
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ElementFragmentsCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ElementFragmentsCount);
 return 1;
}

/* get function: PremisesPolygonCount of class  TLinkNodes */
static int tolua_get_TLinkNodes_PremisesPolygonCount(lua_State* tolua_S)
{
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PremisesPolygonCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PremisesPolygonCount);
 return 1;
}

/* get function: BuildingPolygonCount of class  TLinkNodes */
static int tolua_get_TLinkNodes_BuildingPolygonCount(lua_State* tolua_S)
{
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BuildingPolygonCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->BuildingPolygonCount);
 return 1;
}

/* get function: RouterListsCount of class  TLinkNodes */
static int tolua_get_TLinkNodes_RouterListsCount(lua_State* tolua_S)
{
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'RouterListsCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->RouterListsCount);
 return 1;
}

/* method: GetRouteNode of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_GetRouteNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRouteNode'",NULL);
#endif
  {
   TRouteNode* tolua_ret = (TRouteNode*)  self->GetRouteNode(i);

/* getting type */
  char* lua_type = "TRouteNode";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRouteNode'.",&tolua_err);
 return 0;
#endif
}

/* method: GetElementFragments of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_GetElementFragments00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetElementFragments'",NULL);
#endif
  {
   TElementPoints* tolua_ret = (TElementPoints*)  self->GetElementFragments(i);

/* getting type */
  char* lua_type = "TElementPoints";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetElementFragments'.",&tolua_err);
 return 0;
#endif
}

/* method: GetPremisesPolygon of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_GetPremisesPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPremisesPolygon'",NULL);
#endif
  {
   THoledPolygon* tolua_ret = (THoledPolygon*)  self->GetPremisesPolygon(i);

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPremisesPolygon'.",&tolua_err);
 return 0;
#endif
}

/* method: GetBuildingPolygon of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_GetBuildingPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBuildingPolygon'",NULL);
#endif
  {
   THoledPolygon* tolua_ret = (THoledPolygon*)  self->GetBuildingPolygon(i);

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBuildingPolygon'.",&tolua_err);
 return 0;
#endif
}

/* method: GetRouterCount of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_GetRouterCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRouterCount'",NULL);
#endif
  {
   int tolua_ret = (int)  self->GetRouterCount(i);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRouterCount'.",&tolua_err);
 return 0;
#endif
}

/* method: GetRouter of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_GetRouter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int j = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRouter'",NULL);
#endif
  {
   TRoutePoint* tolua_ret = (TRoutePoint*)  self->GetRouter(i,j);

/* getting type */
  char* lua_type = "TRoutePoint";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRouter'.",&tolua_err);
 return 0;
#endif
}

/* method: ClearMetaFilter of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_ClearMetaFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearMetaFilter'",NULL);
#endif
  {
   self->ClearMetaFilter();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearMetaFilter'.",&tolua_err);
 return 0;
#endif
}

/* method: AddToMetaFilter of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_AddToMetaFilter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMetaElement* MetaElement = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddToMetaFilter'",NULL);
#endif
  {
   self->AddToMetaFilter(MetaElement);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddToMetaFilter'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOfFilterMetaElement of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_IndexOfFilterMetaElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TMetaElement* MetaElement = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOfFilterMetaElement'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOfFilterMetaElement(MetaElement);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IndexOfFilterMetaElement'.",&tolua_err);
 return 0;
#endif
}

/* get function: FilterMetaElementCount of class  TLinkNodes */
static int tolua_get_TLinkNodes_FilterMetaElementCount(lua_State* tolua_S)
{
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FilterMetaElementCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->FilterMetaElementCount);
 return 1;
}

/* method: GetFilterMetaElement of class  TLinkNodes */
static int tolua_z_All_TLinkNodes_GetFilterMetaElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLinkNodes",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLinkNodes* self = (TLinkNodes*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFilterMetaElement'",NULL);
#endif
  {
   TMetaElement* tolua_ret = (TMetaElement*)  self->GetFilterMetaElement(i);

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFilterMetaElement'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMetaUI */
static int tolua_z_All_TMetaUI_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaUI",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaUI* tolua_ret = (TMetaUI*)  new TMetaUI();

/* getting type */
  char* lua_type = "TMetaUI";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaUI */
static int tolua_z_All_TMetaUI_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaUI",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaUI* tolua_ret = (TMetaUI*)  new TMetaUI();

/* getting type */
  char* lua_type = "TMetaUI";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaUI */
static int tolua_z_All_TMetaUI_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaUI",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaUI* self = (TMetaUI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: UImageIndex of class  TMetaUI */
static int tolua_get_TMetaUI_UImageIndex(lua_State* tolua_S)
{
  TMetaUI* self = (TMetaUI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UImageIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->UImageIndex);
 return 1;
}

/* set function: UImageIndex of class  TMetaUI */
static int tolua_set_TMetaUI_UImageIndex(lua_State* tolua_S)
{
  TMetaUI* self = (TMetaUI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UImageIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->UImageIndex = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Enabled of class  TMetaUI */
static int tolua_get_TMetaUI_Enabled(lua_State* tolua_S)
{
  TMetaUI* self = (TMetaUI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Enabled);
 return 1;
}

/* set function: Enabled of class  TMetaUI */
static int tolua_set_TMetaUI_Enabled(lua_State* tolua_S)
{
  TMetaUI* self = (TMetaUI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: Visible of class  TMetaUI */
static int tolua_get_TMetaUI_Visible(lua_State* tolua_S)
{
  TMetaUI* self = (TMetaUI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Visible'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Visible);
 return 1;
}

/* set function: Visible of class  TMetaUI */
static int tolua_set_TMetaUI_Visible(lua_State* tolua_S)
{
  TMetaUI* self = (TMetaUI*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Visible'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Visible = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: new of class  TMetaAction */
static int tolua_z_All_TMetaAction_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaAction* tolua_ret = (TMetaAction*)  new TMetaAction();

/* getting type */
  char* lua_type = "TMetaAction";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaAction */
static int tolua_z_All_TMetaAction_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaAction* tolua_ret = (TMetaAction*)  new TMetaAction();

/* getting type */
  char* lua_type = "TMetaAction";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaAction */
static int tolua_z_All_TMetaAction_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaAction* self = (TMetaAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: UImageIndex of class  TMetaAction */
static int tolua_get_TMetaAction_UImageIndex(lua_State* tolua_S)
{
  TMetaAction* self = (TMetaAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UImageIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->UImageIndex);
 return 1;
}

/* set function: UImageIndex of class  TMetaAction */
static int tolua_set_TMetaAction_UImageIndex(lua_State* tolua_S)
{
  TMetaAction* self = (TMetaAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UImageIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->UImageIndex = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Enabled of class  TMetaAction */
static int tolua_get_TMetaAction_Enabled(lua_State* tolua_S)
{
  TMetaAction* self = (TMetaAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Enabled);
 return 1;
}

/* set function: Enabled of class  TMetaAction */
static int tolua_set_TMetaAction_Enabled(lua_State* tolua_S)
{
  TMetaAction* self = (TMetaAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: Visible of class  TMetaAction */
static int tolua_get_TMetaAction_Visible(lua_State* tolua_S)
{
  TMetaAction* self = (TMetaAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Visible'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Visible);
 return 1;
}

/* set function: Visible of class  TMetaAction */
static int tolua_set_TMetaAction_Visible(lua_State* tolua_S)
{
  TMetaAction* self = (TMetaAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Visible'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Visible = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: Update of class  TMetaAction */
static int tolua_z_All_TMetaAction_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaAction* self = (TMetaAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'",NULL);
#endif
  {
   self->Update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}

/* method: Execute of class  TMetaAction */
static int tolua_z_All_TMetaAction_Execute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaAction* self = (TMetaAction*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Execute'",NULL);
#endif
  {
   self->Execute();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Execute'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMetaMenuItem */
static int tolua_z_All_TMetaMenuItem_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaMenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaMenuItem* tolua_ret = (TMetaMenuItem*)  new TMetaMenuItem();

/* getting type */
  char* lua_type = "TMetaMenuItem";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaMenuItem */
static int tolua_z_All_TMetaMenuItem_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaMenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaMenuItem* tolua_ret = (TMetaMenuItem*)  new TMetaMenuItem();

/* getting type */
  char* lua_type = "TMetaMenuItem";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaMenuItem */
static int tolua_z_All_TMetaMenuItem_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaMenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaMenuItem* self = (TMetaMenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Update of class  TMetaMenuItem */
static int tolua_z_All_TMetaMenuItem_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaMenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaMenuItem* self = (TMetaMenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'",NULL);
#endif
  {
   self->Update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}

/* method: Execute of class  TMetaMenuItem */
static int tolua_z_All_TMetaMenuItem_Execute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaMenuItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaMenuItem* self = (TMetaMenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Execute'",NULL);
#endif
  {
   self->Execute();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Execute'.",&tolua_err);
 return 0;
#endif
}

/* get function: AssociatedAction of class  TMetaMenuItem */
static int tolua_get_TMetaMenuItem_AssociatedAction_ptr(lua_State* tolua_S)
{
  TMetaMenuItem* self = (TMetaMenuItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AssociatedAction'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaAction";
   tolua_pushusertype(tolua_S,(void*)(self->AssociatedAction),lua_type);
 return 1;
}

/* method: new of class  TRenderParam */
static int tolua_z_All_TRenderParam_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRenderParam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRenderParam* tolua_ret = (TRenderParam*)  new TRenderParam();

/* getting type */
  char* lua_type = "TRenderParam";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TRenderParam */
static int tolua_z_All_TRenderParam_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TRenderParam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TRenderParam* tolua_ret = (TRenderParam*)  new TRenderParam();

/* getting type */
  char* lua_type = "TRenderParam";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TRenderParam */
static int tolua_z_All_TRenderParam_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TRenderParam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Area of class  TRenderParam */
static int tolua_get_TRenderParam_Area(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Area'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Area);
 return 1;
}

/* set function: Area of class  TRenderParam */
static int tolua_set_TRenderParam_Area(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Area'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Area = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Texture of class  TRenderParam */
static int tolua_get_TRenderParam_Texture_ptr(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Texture'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaTexture";
   tolua_pushusertype(tolua_S,(void*)(self->Texture),lua_type);
 return 1;
}

/* set function: Texture of class  TRenderParam */
static int tolua_set_TRenderParam_Texture_ptr(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Texture'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TMetaTexture",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Texture = ((TMetaTexture*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Material of class  TRenderParam */
static int tolua_get_TRenderParam_Material_ptr(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Material'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaMaterial";
   tolua_pushusertype(tolua_S,(void*)(self->Material),lua_type);
 return 1;
}

/* set function: Material of class  TRenderParam */
static int tolua_set_TRenderParam_Material_ptr(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Material'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TMetaMaterial",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Material = ((TMetaMaterial*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: TexCenter of class  TRenderParam */
static int tolua_get_TRenderParam_TexCenter(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TexCenter'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->TexCenter)),lua_type);
 return 1;
}

/* set function: TexCenter of class  TRenderParam */
static int tolua_set_TRenderParam_TexCenter(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TexCenter'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TexCenter = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: TexAngle of class  TRenderParam */
static int tolua_get_TRenderParam_TexAngle(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TexAngle'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->TexAngle)),lua_type);
 return 1;
}

/* set function: TexAngle of class  TRenderParam */
static int tolua_set_TRenderParam_TexAngle(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TexAngle'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TexAngle = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Enabled of class  TRenderParam */
static int tolua_get_TRenderParam_Enabled(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Enabled);
 return 1;
}

/* set function: Enabled of class  TRenderParam */
static int tolua_set_TRenderParam_Enabled(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: OverPosMode of class  TRenderParam */
static int tolua_get_TRenderParam_OverPosMode(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OverPosMode'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->OverPosMode);
 return 1;
}

/* set function: OverPosMode of class  TRenderParam */
static int tolua_set_TRenderParam_OverPosMode(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OverPosMode'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->OverPosMode = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: OverPos of class  TRenderParam */
static int tolua_get_TRenderParam_OverPos(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OverPos'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->OverPos)),lua_type);
 return 1;
}

/* set function: OverPos of class  TRenderParam */
static int tolua_set_TRenderParam_OverPos(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OverPos'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->OverPos = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: OverSizeMode of class  TRenderParam */
static int tolua_get_TRenderParam_OverSizeMode(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OverSizeMode'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->OverSizeMode);
 return 1;
}

/* set function: OverSizeMode of class  TRenderParam */
static int tolua_set_TRenderParam_OverSizeMode(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OverSizeMode'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->OverSizeMode = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: OverSize of class  TRenderParam */
static int tolua_get_TRenderParam_OverSize(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OverSize'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->OverSize)),lua_type);
 return 1;
}

/* set function: OverSize of class  TRenderParam */
static int tolua_set_TRenderParam_OverSize(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OverSize'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->OverSize = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: FLAT2D of class  TRenderParam */
static int tolua_get_TRenderParam_FLAT2D(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FLAT2D'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->FLAT2D);
 return 1;
}

/* set function: FLAT2D of class  TRenderParam */
static int tolua_set_TRenderParam_FLAT2D(lua_State* tolua_S)
{
  TRenderParam* self = (TRenderParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'FLAT2D'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->FLAT2D = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: new of class  TFragmentSettings */
static int tolua_z_All_TFragmentSettings_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TFragmentSettings",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TFragmentSettings* tolua_ret = (TFragmentSettings*)  new TFragmentSettings();

/* getting type */
  char* lua_type = "TFragmentSettings";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TFragmentSettings */
static int tolua_z_All_TFragmentSettings_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TFragmentSettings",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TFragmentSettings* tolua_ret = (TFragmentSettings*)  new TFragmentSettings();

/* getting type */
  char* lua_type = "TFragmentSettings";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TFragmentSettings */
static int tolua_z_All_TFragmentSettings_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TFragmentSettings",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: LocalP0 of class  TFragmentSettings */
static int tolua_get_TFragmentSettings_LocalP0(lua_State* tolua_S)
{
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LocalP0'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->LocalP0)),lua_type);
 return 1;
}

/* get function: LocalP1 of class  TFragmentSettings */
static int tolua_get_TFragmentSettings_LocalP1(lua_State* tolua_S)
{
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LocalP1'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->LocalP1)),lua_type);
 return 1;
}

/* get function: IsOutSide of class  TFragmentSettings */
static int tolua_get_TFragmentSettings_IsOutSide(lua_State* tolua_S)
{
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'IsOutSide'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->IsOutSide);
 return 1;
}

/* get function: SideType of class  TFragmentSettings */
static int tolua_get_TFragmentSettings_SideType(lua_State* tolua_S)
{
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SideType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->SideType);
 return 1;
}

/* get function: SideIndex of class  TFragmentSettings */
static int tolua_get_TFragmentSettings_SideIndex(lua_State* tolua_S)
{
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SideIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->SideIndex);
 return 1;
}

/* method: FragmentOfPoint of class  TFragmentSettings */
static int tolua_z_All_TFragmentSettings_FragmentOfPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TFragmentSettings",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* LocPoint = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
   float USEEPS = ((  float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FragmentOfPoint'",NULL);
#endif
  {
   int tolua_ret = (int)  self->FragmentOfPoint(*LocPoint,USEEPS);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FragmentOfPoint'.",&tolua_err);
 return 0;
#endif
}

/* get function: PolygonCount of class  TFragmentSettings */
static int tolua_get_TFragmentSettings_PolygonCount(lua_State* tolua_S)
{
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PolygonCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PolygonCount);
 return 1;
}

/* method: GetRenderParam of class  TFragmentSettings */
static int tolua_z_All_TFragmentSettings_GetRenderParam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TFragmentSettings",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRenderParam'",NULL);
#endif
  {
   TRenderParam* tolua_ret = (TRenderParam*)  self->GetRenderParam(i);

/* getting type */
  char* lua_type = "TRenderParam";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRenderParam'.",&tolua_err);
 return 0;
#endif
}

/* method: GetPolygon of class  TFragmentSettings */
static int tolua_z_All_TFragmentSettings_GetPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TFragmentSettings",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TFragmentSettings* self = (TFragmentSettings*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPolygon'",NULL);
#endif
  {
   THoledPolygon* tolua_ret = (THoledPolygon*)  self->GetPolygon(i);

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPolygon'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TDelone */
static int tolua_z_All_TDelone_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TDelone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TDelone* tolua_ret = (TDelone*)  new TDelone();

/* getting type */
  char* lua_type = "TDelone";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TDelone */
static int tolua_z_All_TDelone_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TDelone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TDelone* tolua_ret = (TDelone*)  new TDelone();

/* getting type */
  char* lua_type = "TDelone";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TDelone */
static int tolua_z_All_TDelone_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDelone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDelone* self = (TDelone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: EPS of class  TDelone */
static int tolua_get_TDelone_EPS(lua_State* tolua_S)
{
  TDelone* self = (TDelone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EPS'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->EPS);
 return 1;
}

/* set function: EPS of class  TDelone */
static int tolua_set_TDelone_EPS(lua_State* tolua_S)
{
  TDelone* self = (TDelone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EPS'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->EPS = ((  float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Triangles of class  TDelone */
static int tolua_get_TDelone_Triangles(lua_State* tolua_S)
{
  TDelone* self = (TDelone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Triangles'",NULL);
#endif

/* getting type */
  char* lua_type = "TMTList<TIntVec>";
   tolua_pushusertype(tolua_S,(void*)(&(self->Triangles)),lua_type);
 return 1;
}

/* get function: Contour of class  TDelone */
static int tolua_get_TDelone_Contour(lua_State* tolua_S)
{
  TDelone* self = (TDelone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Contour'",NULL);
#endif

/* getting type */
  char* lua_type = "TMTList<TIntVec>";
   tolua_pushusertype(tolua_S,(void*)(&(self->Contour)),lua_type);
 return 1;
}

/* method: OPERATION of class  TDelone */
static int tolua_z_All_TDelone_OPERATION00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDelone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDelone* self = (TDelone*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TPolygon* P0 = ((TPolygon*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TPolygon* P1 = ((TPolygon*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  int oper = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OPERATION'",NULL);
#endif
  {
   TMTList<TIntVec>* tolua_ret = (TMTList<TIntVec>*)  self->OPERATION(P0,P1,oper);

/* getting type */
  char* lua_type = "TMTList<TIntVec>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OPERATION'.",&tolua_err);
 return 0;
#endif
}

/* method: Triangulate of class  TDelone */
static int tolua_z_All_TDelone_Triangulate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDelone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDelone* self = (TDelone*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  THoledPolygon* HP = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Triangulate'",NULL);
#endif
  {
   TMTList<TIntVec>* tolua_ret = (TMTList<TIntVec>*)  self->Triangulate(HP);

/* getting type */
  char* lua_type = "TMTList<TIntVec>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Triangulate'.",&tolua_err);
 return 0;
#endif
}

/* method: Triangulate3 of class  TDelone */
static int tolua_z_All_TDelone_Triangulate300(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDelone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDelone* self = (TDelone*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  THoledPolygon* HP = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TMTList<TIntVec>* LineEdges = ((TMTList<TIntVec>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Triangulate3'",NULL);
#endif
  {
   TMTList<TIntVec>* tolua_ret = (TMTList<TIntVec>*)  self->Triangulate3(HP,LineEdges);

/* getting type */
  char* lua_type = "TMTList<TIntVec>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Triangulate3'.",&tolua_err);
 return 0;
#endif
}

/* function: CreateRoofOld */
static int tolua_z_All_CreateRoofOld00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMDelTList<TIntVec>* RoofPolygon = ((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  TMDelTList<TIntVec>* Param = ((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TMDelTList<TPolygon>* RES = ((TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TMDelTList<TLuaRoofCut>* FLEGS = ((TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TMDelTList<TLuaRoofCut>* FSCATES = ((TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,5,0));
  {
   CreateRoofOld(RoofPolygon,Param,RES,FLEGS,FSCATES);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateRoofOld'.",&tolua_err);
 return 0;
#endif
}

/* function: CreateRoof */
static int tolua_z_All_CreateRoof00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,7,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMDelTList<TMDelTList<TIntVec> >* pp_N = ((TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  TMDelTList<TMDelTList<TIntVec> >* pp_O = ((TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* b_N = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TIntVec* b_O = ((TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TMDelTList<TMDelTList<TPolygon> >* RES = ((TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,5,0));
/*declare*/
  TMDelTList<TLuaRoofCut>* FLEGS = ((TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,6,0));
/*declare*/
  TMDelTList<TLuaRoofCut>* FSCATES = ((TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,7,0));
  {
   CreateRoof(*pp_N,*pp_O,*b_N,*b_O,*RES,*FLEGS,*FSCATES);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateRoof'.",&tolua_err);
 return 0;
#endif
}

/* function: ConstructRoof */
static int tolua_z_All_ConstructRoof00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TIntVec",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TGeomObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMDelTList<TMDelTList<TIntVec> >* pp_N = ((TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  TMDelTList<TMDelTList<TIntVec> >* pp_O = ((TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TIntVec* b_N = ((TIntVec*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  TIntVec* b_O = ((TIntVec*)  tolua_tousertype(tolua_S,4,0));
/*declare*/
  TGeomObject* G0 = ((TGeomObject*)  tolua_tousertype(tolua_S,5,0));
  {
   ConstructRoof(*pp_N,*pp_O,*b_N,*b_O,*G0);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConstructRoof'.",&tolua_err);
 return 0;
#endif
}

/* function: CreateLinkFunction */
static int tolua_z_All_CreateLinkFunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TDynamicLink",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TElement* EL0 = ((TElement*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  TElement* EL1 = ((TElement*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TDynamicLink* DynamicLink = ((TDynamicLink*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TIntVec* AbsPoint = ((const TIntVec*)  tolua_tousertype(tolua_S,4,0));
  {
   TLink* tolua_ret = (TLink*)  CreateLinkFunction(EL0,EL1,DynamicLink,*AbsPoint);

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateLinkFunction'.",&tolua_err);
 return 0;
#endif
}

/* function: AllowLink */
static int tolua_z_All_AllowLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLink",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TLink* Link = ((TLink*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  TMTList<TLink>* LNKL = ((TMTList<TLink>*)  tolua_tousertype(tolua_S,2,0));
  {
   int tolua_ret = (int)  AllowLink(Link,LNKL);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AllowLink'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMDI3D */
static int tolua_z_All_TMDI3D_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDI3D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMainTree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* Owner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TMainTree* MT = ((TMainTree*)  tolua_tousertype(tolua_S,3,0));
  {
   TMDI3D* tolua_ret = (TMDI3D*)  new TMDI3D(Owner,MT);

/* getting type */
  char* lua_type = "TMDI3D";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMDI3D */
static int tolua_z_All_TMDI3D_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDI3D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMainTree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* Owner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  TMainTree* MT = ((TMainTree*)  tolua_tousertype(tolua_S,3,0));
  {
   TMDI3D* tolua_ret = (TMDI3D*)  new TMDI3D(Owner,MT);

/* getting type */
  char* lua_type = "TMDI3D";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMDI3D */
static int tolua_z_All_TMDI3D_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDI3D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: A of class  TMDI3D */
static int tolua_get_TMDI3D_A(lua_State* tolua_S)
{
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'A'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->A)),lua_type);
 return 1;
}

/* set function: A of class  TMDI3D */
static int tolua_set_TMDI3D_A(lua_State* tolua_S)
{
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'A'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->A = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: PlaneN of class  TMDI3D */
static int tolua_get_TMDI3D_PlaneN(lua_State* tolua_S)
{
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PlaneN'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->PlaneN)),lua_type);
 return 1;
}

/* set function: PlaneN of class  TMDI3D */
static int tolua_set_TMDI3D_PlaneN(lua_State* tolua_S)
{
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PlaneN'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PlaneN = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: ScreenToProject of class  TMDI3D */
static int tolua_z_All_TMDI3D_ScreenToProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDI3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
   float x = ((  float)  tolua_tonumber(tolua_S,2,0));
/*declare*/
   float y = ((  float)  tolua_tonumber(tolua_S,3,0));
/*declare*/
   float z = ((  float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ScreenToProject'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->ScreenToProject(x,y,z);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ScreenToProject'.",&tolua_err);
 return 0;
#endif
}

/* method: ScreenToProject of class  TMDI3D */
static int tolua_z_All_TMDI3D_ScreenToProject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDI3D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* V = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ScreenToProject'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->ScreenToProject(*V);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_TMDI3D_ScreenToProject00(tolua_S);
}

/* method: ProjectToScreen of class  TMDI3D */
static int tolua_z_All_TMDI3D_ProjectToScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDI3D",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TIntVec* Vv = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProjectToScreen'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->ProjectToScreen(*Vv);
   {
#ifdef __cplusplus
    void* tolua_obj = new TIntVec(tolua_ret);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TIntVec));

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProjectToScreen'.",&tolua_err);
 return 0;
#endif
}

/* method: Factor of class  TMDI3D */
static int tolua_z_All_TMDI3D_Factor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDI3D",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int Pixels = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Factor'",NULL);
#endif
  {
    float tolua_ret = (  float)  self->Factor(Pixels);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Factor'.",&tolua_err);
 return 0;
#endif
}

/* get function: View of class  TMDI3D */
static int tolua_get_TMDI3D_View_ptr(lua_State* tolua_S)
{
  TMDI3D* self = (TMDI3D*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'View'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisView";
   tolua_pushusertype(tolua_S,(void*)(self->View),lua_type);
 return 1;
}

/* method: new of class  TShiftState */
static int tolua_z_All_TShiftState_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TShiftState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TShiftState* tolua_ret = (TShiftState*)  new TShiftState();

/* getting type */
  char* lua_type = "TShiftState";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TShiftState */
static int tolua_z_All_TShiftState_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TShiftState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TShiftState* tolua_ret = (TShiftState*)  new TShiftState();

/* getting type */
  char* lua_type = "TShiftState";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TShiftState */
static int tolua_z_All_TShiftState_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TShiftState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TShiftState* self = (TShiftState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Contains of class  TShiftState */
static int tolua_z_All_TShiftState_Contains00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TShiftState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TShiftState* self = (TShiftState*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  Classes__1 State = ((Classes__1) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Contains'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Contains(State);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Contains'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TUserInterfaceParam */
static int tolua_z_All_TUserInterfaceParam_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TUserInterfaceParam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TUserInterfaceParam* tolua_ret = (TUserInterfaceParam*)  new TUserInterfaceParam();

/* getting type */
  char* lua_type = "TUserInterfaceParam";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TUserInterfaceParam */
static int tolua_z_All_TUserInterfaceParam_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TUserInterfaceParam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TUserInterfaceParam* tolua_ret = (TUserInterfaceParam*)  new TUserInterfaceParam();

/* getting type */
  char* lua_type = "TUserInterfaceParam";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TUserInterfaceParam */
static int tolua_z_All_TUserInterfaceParam_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUserInterfaceParam",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Center of class  TUserInterfaceParam */
static int tolua_get_TUserInterfaceParam_Center(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Center'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->Center)),lua_type);
 return 1;
}

/* set function: Center of class  TUserInterfaceParam */
static int tolua_set_TUserInterfaceParam_Center(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Center'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Center = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: NewCursorPos of class  TUserInterfaceParam */
static int tolua_get_TUserInterfaceParam_NewCursorPos(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NewCursorPos'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->NewCursorPos)),lua_type);
 return 1;
}

/* set function: NewCursorPos of class  TUserInterfaceParam */
static int tolua_set_TUserInterfaceParam_NewCursorPos(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NewCursorPos'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->NewCursorPos = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Sender of class  TUserInterfaceParam */
static int tolua_get_TUserInterfaceParam_Sender_ptr(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Sender'",NULL);
#endif

/* getting type */
  char* lua_type = "TMDI3D";
   tolua_pushusertype(tolua_S,(void*)(self->Sender),lua_type);
 return 1;
}

/* set function: Sender of class  TUserInterfaceParam */
static int tolua_set_TUserInterfaceParam_Sender_ptr(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Sender'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TMDI3D",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Sender = ((TMDI3D*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Key of class  TUserInterfaceParam */
static int tolua_get_TUserInterfaceParam_Key(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Key'",NULL);
#endif

/* getting type */
  char* lua_type = "WORD";
   tolua_pushusertype(tolua_S,(void*)(&(self->Key)),lua_type);
 return 1;
}

/* set function: Key of class  TUserInterfaceParam */
static int tolua_set_TUserInterfaceParam_Key(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Key'",NULL);
  if (!tolua_isusertype(tolua_S,2,"WORD",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Key = *((WORD*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Shift of class  TUserInterfaceParam */
static int tolua_get_TUserInterfaceParam_Shift(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Shift'",NULL);
#endif

/* getting type */
  char* lua_type = "TShiftState";
   tolua_pushusertype(tolua_S,(void*)(&(self->Shift)),lua_type);
 return 1;
}

/* set function: Shift of class  TUserInterfaceParam */
static int tolua_set_TUserInterfaceParam_Shift(lua_State* tolua_S)
{
  TUserInterfaceParam* self = (TUserInterfaceParam*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Shift'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TShiftState",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Shift = *((TShiftState*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: UIP of class  TBaseTool */
static int tolua_get_TBaseTool_UIP(lua_State* tolua_S)
{
  TBaseTool* self = (TBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UIP'",NULL);
#endif

/* getting type */
  char* lua_type = "TUserInterfaceParam";
   tolua_pushusertype(tolua_S,(void*)(&(self->UIP)),lua_type);
 return 1;
}

/* get function: VCO of class  TBaseTool */
static int tolua_get_TBaseTool_VCO_ptr(lua_State* tolua_S)
{
  TBaseTool* self = (TBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'VCO'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisPrimitiveObj";
   tolua_pushusertype(tolua_S,(void*)(self->VCO),lua_type);
 return 1;
}

/* get function: SnapCursor of class  TBaseTool */
static int tolua_get_TBaseTool_SnapCursor_ptr(lua_State* tolua_S)
{
  TBaseTool* self = (TBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SnapCursor'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisPrimitiveObj";
   tolua_pushusertype(tolua_S,(void*)(self->SnapCursor),lua_type);
 return 1;
}

/* method: new of class  TBaseTool */
static int tolua_z_All_TBaseTool_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TBaseTool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TBaseTool* tolua_ret = (TBaseTool*)  new TBaseTool();

/* getting type */
  char* lua_type = "TBaseTool";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TBaseTool */
static int tolua_z_All_TBaseTool_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TBaseTool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TBaseTool* tolua_ret = (TBaseTool*)  new TBaseTool();

/* getting type */
  char* lua_type = "TBaseTool";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TBaseTool */
static int tolua_z_All_TBaseTool_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TBaseTool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TBaseTool* self = (TBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TDialogBaseTool */
static int tolua_z_All_TDialogBaseTool_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TDialogBaseTool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TDialogBaseTool* tolua_ret = (TDialogBaseTool*)  new TDialogBaseTool();

/* getting type */
  char* lua_type = "TDialogBaseTool";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TDialogBaseTool */
static int tolua_z_All_TDialogBaseTool_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TDialogBaseTool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TDialogBaseTool* tolua_ret = (TDialogBaseTool*)  new TDialogBaseTool();

/* getting type */
  char* lua_type = "TDialogBaseTool";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TDialogBaseTool */
static int tolua_z_All_TDialogBaseTool_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDialogBaseTool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDialogBaseTool* self = (TDialogBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Sender of class  TDialogBaseTool */
static int tolua_get_TDialogBaseTool_Sender_ptr(lua_State* tolua_S)
{
  TDialogBaseTool* self = (TDialogBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Sender'",NULL);
#endif

/* getting type */
  char* lua_type = "TMDI3D";
   tolua_pushusertype(tolua_S,(void*)(self->Sender),lua_type);
 return 1;
}

/* get function: A of class  TDialogBaseTool */
static int tolua_get_TDialogBaseTool_A(lua_State* tolua_S)
{
  TDialogBaseTool* self = (TDialogBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'A'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->A)),lua_type);
 return 1;
}

/* set function: A of class  TDialogBaseTool */
static int tolua_set_TDialogBaseTool_A(lua_State* tolua_S)
{
  TDialogBaseTool* self = (TDialogBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'A'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->A = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: PlaneN of class  TDialogBaseTool */
static int tolua_get_TDialogBaseTool_PlaneN(lua_State* tolua_S)
{
  TDialogBaseTool* self = (TDialogBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PlaneN'",NULL);
#endif

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(&(self->PlaneN)),lua_type);
 return 1;
}

/* set function: PlaneN of class  TDialogBaseTool */
static int tolua_set_TDialogBaseTool_PlaneN(lua_State* tolua_S)
{
  TDialogBaseTool* self = (TDialogBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PlaneN'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PlaneN = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: Changed of class  TDialogBaseTool */
static int tolua_z_All_TDialogBaseTool_Changed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDialogBaseTool",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDialogBaseTool* self = (TDialogBaseTool*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  void* Field = ((void*)  tolua_touserdata(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Changed'",NULL);
#endif
  {
   self->Changed(Field);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Changed'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TBindedBaseTool */
static int tolua_z_All_TBindedBaseTool_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TBindedBaseTool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TBindedBaseTool* tolua_ret = (TBindedBaseTool*)  new TBindedBaseTool();

/* getting type */
  char* lua_type = "TBindedBaseTool";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TBindedBaseTool */
static int tolua_z_All_TBindedBaseTool_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TBindedBaseTool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TBindedBaseTool* tolua_ret = (TBindedBaseTool*)  new TBindedBaseTool();

/* getting type */
  char* lua_type = "TBindedBaseTool";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TBindedBaseTool */
static int tolua_z_All_TBindedBaseTool_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TBindedBaseTool",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TBindedBaseTool* self = (TBindedBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: ExecutedName of class  TBindedBaseTool */
static int tolua_get_TBindedBaseTool_ExecutedName(lua_State* tolua_S)
{
  TBindedBaseTool* self = (TBindedBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ExecutedName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->ExecutedName);
 return 1;
}

/* method: KeyToStrChar of class  TBindedBaseTool */
static int tolua_z_All_TBindedBaseTool_KeyToStrChar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TBindedBaseTool",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"WORD",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TBindedBaseTool* self = (TBindedBaseTool*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  WORD Key = *((WORD*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'KeyToStrChar'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->KeyToStrChar(Key);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'KeyToStrChar'.",&tolua_err);
 return 0;
#endif
}

/* get function: Attribute of class  TBindedBaseTool */
static int tolua_get_TBindedBaseTool_Attribute(lua_State* tolua_S)
{
  TBindedBaseTool* self = (TBindedBaseTool*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Attribute'",NULL);
#endif

/* getting type */
  char* lua_type = "TLuaAttribute";
   tolua_pushusertype(tolua_S,(void*)(&(self->Attribute)),lua_type);
 return 1;
}

/* method: new of class  TAdvancedUserInterface */
static int tolua_z_All_TAdvancedUserInterface_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TAdvancedUserInterface",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TAdvancedUserInterface* tolua_ret = (TAdvancedUserInterface*)  new TAdvancedUserInterface();

/* getting type */
  char* lua_type = "TAdvancedUserInterface";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TAdvancedUserInterface */
static int tolua_z_All_TAdvancedUserInterface_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TAdvancedUserInterface",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TAdvancedUserInterface* tolua_ret = (TAdvancedUserInterface*)  new TAdvancedUserInterface();

/* getting type */
  char* lua_type = "TAdvancedUserInterface";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TAdvancedUserInterface */
static int tolua_z_All_TAdvancedUserInterface_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TAdvancedUserInterface",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TAdvancedUserInterface* self = (TAdvancedUserInterface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: CurrentWorldIndex of class  TAdvancedUserInterface */
static int tolua_get_TAdvancedUserInterface_CurrentWorldIndex(lua_State* tolua_S)
{
  TAdvancedUserInterface* self = (TAdvancedUserInterface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CurrentWorldIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CurrentWorldIndex);
 return 1;
}

/* get function: ActiveView of class  TAdvancedUserInterface */
static int tolua_get_TAdvancedUserInterface_ActiveView_ptr(lua_State* tolua_S)
{
  TAdvancedUserInterface* self = (TAdvancedUserInterface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ActiveView'",NULL);
#endif

/* getting type */
  char* lua_type = "TMDI3D";
   tolua_pushusertype(tolua_S,(void*)(self->ActiveView),lua_type);
 return 1;
}

/* get function: ActiveWorld of class  TAdvancedUserInterface */
static int tolua_get_TAdvancedUserInterface_ActiveWorld_ptr(lua_State* tolua_S)
{
  TAdvancedUserInterface* self = (TAdvancedUserInterface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ActiveWorld'",NULL);
#endif

/* getting type */
  char* lua_type = "TMainTree";
   tolua_pushusertype(tolua_S,(void*)(self->ActiveWorld),lua_type);
 return 1;
}

/* method: InvalidateView of class  TAdvancedUserInterface */
static int tolua_z_All_TAdvancedUserInterface_InvalidateView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TAdvancedUserInterface",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TAdvancedUserInterface* self = (TAdvancedUserInterface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InvalidateView'",NULL);
#endif
  {
   self->InvalidateView();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InvalidateView'.",&tolua_err);
 return 0;
#endif
}

/* get function: Mode of class  TAdvancedUserInterface */
static int tolua_get_TAdvancedUserInterface_Mode_ptr(lua_State* tolua_S)
{
  TAdvancedUserInterface* self = (TAdvancedUserInterface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Mode'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaMyMode";
   tolua_pushusertype(tolua_S,(void*)(self->Mode),lua_type);
 return 1;
}

/* get function: AdvancedTexturing of class  TAdvancedUserInterface */
static int tolua_get_TAdvancedUserInterface_AdvancedTexturing(lua_State* tolua_S)
{
  TAdvancedUserInterface* self = (TAdvancedUserInterface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AdvancedTexturing'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->AdvancedTexturing);
 return 1;
}

/* set function: AdvancedTexturing of class  TAdvancedUserInterface */
static int tolua_set_TAdvancedUserInterface_AdvancedTexturing(lua_State* tolua_S)
{
  TAdvancedUserInterface* self = (TAdvancedUserInterface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AdvancedTexturing'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AdvancedTexturing = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: PrevAdvancedTexturing of class  TAdvancedUserInterface */
static int tolua_get_TAdvancedUserInterface_PrevAdvancedTexturing(lua_State* tolua_S)
{
  TAdvancedUserInterface* self = (TAdvancedUserInterface*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PrevAdvancedTexturing'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->PrevAdvancedTexturing);
 return 1;
}

/* method: new of class  TIntExplorer */
static int tolua_z_All_TIntExplorer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TIntExplorer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* Owner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TIntExplorer* tolua_ret = (TIntExplorer*)  new TIntExplorer(Owner);

/* getting type */
  char* lua_type = "TIntExplorer";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TIntExplorer */
static int tolua_z_All_TIntExplorer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TIntExplorer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* Owner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TIntExplorer* tolua_ret = (TIntExplorer*)  new TIntExplorer(Owner);

/* getting type */
  char* lua_type = "TIntExplorer";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TIntExplorer */
static int tolua_z_All_TIntExplorer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TIntExplorer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TIntExplorer* self = (TIntExplorer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: MetaCatalogUnit of class  TIntExplorer */
static int tolua_get_TIntExplorer_MetaCatalogUnit_ptr(lua_State* tolua_S)
{
  TIntExplorer* self = (TIntExplorer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MetaCatalogUnit'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaCatalogUnit";
   tolua_pushusertype(tolua_S,(void*)(self->MetaCatalogUnit),lua_type);
 return 1;
}

/* method: new of class  TMetaCatalogUnit */
static int tolua_z_All_TMetaCatalogUnit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaCatalogUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaCatalogUnit* tolua_ret = (TMetaCatalogUnit*)  new TMetaCatalogUnit();

/* getting type */
  char* lua_type = "TMetaCatalogUnit";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMetaCatalogUnit */
static int tolua_z_All_TMetaCatalogUnit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMetaCatalogUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMetaCatalogUnit* tolua_ret = (TMetaCatalogUnit*)  new TMetaCatalogUnit();

/* getting type */
  char* lua_type = "TMetaCatalogUnit";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMetaCatalogUnit */
static int tolua_z_All_TMetaCatalogUnit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMetaCatalogUnit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMetaCatalogUnit* self = (TMetaCatalogUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Associated of class  TMetaCatalogUnit */
static int tolua_get_TMetaCatalogUnit_Associated_ptr(lua_State* tolua_S)
{
  TMetaCatalogUnit* self = (TMetaCatalogUnit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Associated'",NULL);
#endif

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype(tolua_S,(void*)(self->Associated),lua_type);
 return 1;
}

/* method: new of class  TElementQueue */
static int tolua_z_All_TElementQueue_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElementQueue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TElementQueue* tolua_ret = (TElementQueue*)  new TElementQueue();

/* getting type */
  char* lua_type = "TElementQueue";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TElementQueue */
static int tolua_z_All_TElementQueue_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElementQueue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TElementQueue* tolua_ret = (TElementQueue*)  new TElementQueue();

/* getting type */
  char* lua_type = "TElementQueue";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TElementQueue */
static int tolua_z_All_TElementQueue_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementQueue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementQueue* self = (TElementQueue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Add of class  TElementQueue */
static int tolua_z_All_TElementQueue_Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementQueue",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementQueue* self = (TElementQueue*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* Element = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(Element);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Changed of class  TElementQueue */
static int tolua_z_All_TElementQueue_Changed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementQueue",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementQueue* self = (TElementQueue*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* Element = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Changed'",NULL);
#endif
  {
   self->Changed(Element);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Changed'.",&tolua_err);
 return 0;
#endif
}

/* method: Remove of class  TElementQueue */
static int tolua_z_All_TElementQueue_Remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementQueue",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementQueue* self = (TElementQueue*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* Element = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Remove'",NULL);
#endif
  {
   self->Remove(Element);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Remove'.",&tolua_err);
 return 0;
#endif
}

/* method: Clear of class  TElementQueue */
static int tolua_z_All_TElementQueue_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementQueue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementQueue* self = (TElementQueue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TElementQueue */
static int tolua_get_TElementQueue_Count(lua_State* tolua_S)
{
  TElementQueue* self = (TElementQueue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: GetElement of class  TElementQueue */
static int tolua_z_All_TElementQueue_GetElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementQueue",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementQueue* self = (TElementQueue*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetElement'",NULL);
#endif
  {
   TElement* tolua_ret = (TElement*)  self->GetElement(i);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetElement'.",&tolua_err);
 return 0;
#endif
}

/* get function: Enabled of class  TElementQueue */
static int tolua_get_TElementQueue_Enabled(lua_State* tolua_S)
{
  TElementQueue* self = (TElementQueue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Enabled);
 return 1;
}

/* set function: Enabled of class  TElementQueue */
static int tolua_set_TElementQueue_Enabled(lua_State* tolua_S)
{
  TElementQueue* self = (TElementQueue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: new of class  TElementQueueCollection */
static int tolua_z_All_TElementQueueCollection_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElementQueueCollection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TElementQueueCollection* tolua_ret = (TElementQueueCollection*)  new TElementQueueCollection();

/* getting type */
  char* lua_type = "TElementQueueCollection";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TElementQueueCollection */
static int tolua_z_All_TElementQueueCollection_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TElementQueueCollection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TElementQueueCollection* tolua_ret = (TElementQueueCollection*)  new TElementQueueCollection();

/* getting type */
  char* lua_type = "TElementQueueCollection";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TElementQueueCollection */
static int tolua_z_All_TElementQueueCollection_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementQueueCollection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementQueueCollection* self = (TElementQueueCollection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: Enabled of class  TElementQueueCollection */
static int tolua_get_TElementQueueCollection_Enabled(lua_State* tolua_S)
{
  TElementQueueCollection* self = (TElementQueueCollection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Enabled);
 return 1;
}

/* method: Remove of class  TElementQueueCollection */
static int tolua_z_All_TElementQueueCollection_Remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementQueueCollection",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementQueueCollection* self = (TElementQueueCollection*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* Element = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Remove'",NULL);
#endif
  {
   self->Remove(Element);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Remove'.",&tolua_err);
 return 0;
#endif
}

/* method: Changed of class  TElementQueueCollection */
static int tolua_z_All_TElementQueueCollection_Changed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElementQueueCollection",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TElementQueueCollection* self = (TElementQueueCollection*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* Element = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Changed'",NULL);
#endif
  {
   self->Changed(Element);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Changed'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TSelection */
static int tolua_z_All_TSelection_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TSelection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TSelection* tolua_ret = (TSelection*)  new TSelection();

/* getting type */
  char* lua_type = "TSelection";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TSelection */
static int tolua_z_All_TSelection_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TSelection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TSelection* tolua_ret = (TSelection*)  new TSelection();

/* getting type */
  char* lua_type = "TSelection";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TSelection */
static int tolua_z_All_TSelection_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSelection",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSelection* self = (TSelection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Render of class  TSelection */
static int tolua_z_All_TSelection_Render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TSelection",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TVisView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TSelection* self = (TSelection*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TVisView* aView = ((TVisView*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Render'",NULL);
#endif
  {
   self->Render(aView);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Render'.",&tolua_err);
 return 0;
#endif
}

/* function: CreateElementFunction */
static int tolua_z_All_CreateElementFunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TMainTree* _Tree = ((TMainTree*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  TMetaNode* MetaNode = ((TMetaNode*)  tolua_tousertype(tolua_S,2,0));
  {
   TElement* tolua_ret = (TElement*)  CreateElementFunction(_Tree,MetaNode);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateElementFunction'.",&tolua_err);
 return 0;
#endif
}

/* function: KillElement */
static int tolua_z_All_KillElement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TElement* EL = ((TElement*)  tolua_tousertype(tolua_S,1,0));
  {
   KillElement(EL);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'KillElement'.",&tolua_err);
 return 0;
#endif
}

/* function: CreateElementFunction */
static int tolua_z_All_CreateElementFunction01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMainTree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
/*declare*/
  TMainTree* _Tree = ((TMainTree*)  tolua_tousertype(tolua_S,1,0));
/*declare*/
  int _METAID = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   TElement* tolua_ret = (TElement*)  CreateElementFunction(_Tree,_METAID);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_All_CreateElementFunction00(tolua_S);
}

/* method: new of class  TUndoStack */
static int tolua_z_All_TUndoStack_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TUndoStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TUndoStack* tolua_ret = (TUndoStack*)  new TUndoStack();

/* getting type */
  char* lua_type = "TUndoStack";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TUndoStack */
static int tolua_z_All_TUndoStack_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TUndoStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TUndoStack* tolua_ret = (TUndoStack*)  new TUndoStack();

/* getting type */
  char* lua_type = "TUndoStack";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TUndoStack */
static int tolua_z_All_TUndoStack_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUndoStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUndoStack* self = (TUndoStack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* method: OpenSessionC of class  TUndoStack */
static int tolua_z_All_TUndoStack_OpenSessionC00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUndoStack",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUndoStack* self = (TUndoStack*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OpenSessionC'",NULL);
#endif
  {
   self->OpenSessionC(Name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OpenSessionC'.",&tolua_err);
 return 0;
#endif
}

/* method: CloseSession of class  TUndoStack */
static int tolua_z_All_TUndoStack_CloseSession00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUndoStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUndoStack* self = (TUndoStack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CloseSession'",NULL);
#endif
  {
   self->CloseSession();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloseSession'.",&tolua_err);
 return 0;
#endif
}

/* method: BreakSession of class  TUndoStack */
static int tolua_z_All_TUndoStack_BreakSession00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUndoStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUndoStack* self = (TUndoStack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BreakSession'",NULL);
#endif
  {
   self->BreakSession();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BreakSession'.",&tolua_err);
 return 0;
#endif
}

/* method: Opened of class  TUndoStack */
static int tolua_z_All_TUndoStack_Opened00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TUndoStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TUndoStack* self = (TUndoStack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Opened'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Opened();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Opened'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TDriver */
static int tolua_z_All_TDriver_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TDriver",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TDriver* tolua_ret = (TDriver*)  new TDriver();

/* getting type */
  char* lua_type = "TDriver";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TDriver */
static int tolua_z_All_TDriver_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TDriver",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TDriver* tolua_ret = (TDriver*)  new TDriver();

/* getting type */
  char* lua_type = "TDriver";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TDriver */
static int tolua_z_All_TDriver_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDriver",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}

/* get function: MainMode of class  TDriver */
static int tolua_get_TDriver_MainMode(lua_State* tolua_S)
{
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MainMode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MainMode);
 return 1;
}

/* set function: MainMode of class  TDriver */
static int tolua_set_TDriver_MainMode(lua_State* tolua_S)
{
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MainMode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MainMode = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: CorrectMode of class  TDriver */
static int tolua_get_TDriver_CorrectMode(lua_State* tolua_S)
{
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CorrectMode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CorrectMode);
 return 1;
}

/* set function: CorrectMode of class  TDriver */
static int tolua_set_TDriver_CorrectMode(lua_State* tolua_S)
{
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CorrectMode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CorrectMode = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: Init of class  TDriver */
static int tolua_z_All_TDriver_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDriver",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"TElement",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TElement* _Element = ((TElement*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  bool IgnoreAuto = ((bool)  tolua_toboolean(tolua_S,3,0));
/*declare*/
  TElement* UseFloor = ((TElement*)  tolua_tousertype(tolua_S,4,NULL));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'",NULL);
#endif
  {
   self->Init(_Element,IgnoreAuto,UseFloor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}

/* method: Check of class  TDriver */
static int tolua_z_All_TDriver_Check00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDriver",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Check'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Check();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Check'.",&tolua_err);
 return 0;
#endif
}

/* method: Stop of class  TDriver */
static int tolua_z_All_TDriver_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDriver",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Stop();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}

/* method: Clear of class  TDriver */
static int tolua_z_All_TDriver_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDriver",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Clear'",NULL);
#endif
  {
   self->Clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Clear'.",&tolua_err);
 return 0;
#endif
}

/* get function: PreLinksCount of class  TDriver */
static int tolua_get_TDriver_PreLinksCount(lua_State* tolua_S)
{
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PreLinksCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PreLinksCount);
 return 1;
}

/* method: GetPreLink of class  TDriver */
static int tolua_z_All_TDriver_GetPreLink00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TDriver",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TDriver* self = (TDriver*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPreLink'",NULL);
#endif
  {
   TLinkInfo& tolua_ret = (TLinkInfo&)  self->GetPreLink(index);

/* getting type */
  char* lua_type = "TLinkInfo";
   tolua_pushusertype(tolua_S,(void*)(&tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPreLink'.",&tolua_err);
 return 0;
#endif
}

/* Open function */
TOLUA_API int tolua_z_All_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_module(tolua_S,"const",1);
 tolua_beginmodule(tolua_S,"const");
 tolua_constant(tolua_S,"clMin",clMin);
 tolua_constant(tolua_S,"clMax",clMax);
 tolua_constant(tolua_S,"pmBlack",pmBlack);
 tolua_constant(tolua_S,"pmWhite",pmWhite);
 tolua_constant(tolua_S,"pmNop",pmNop);
 tolua_constant(tolua_S,"pmNot",pmNot);
 tolua_constant(tolua_S,"pmCopy",pmCopy);
 tolua_constant(tolua_S,"pmNotCopy",pmNotCopy);
 tolua_constant(tolua_S,"pmMergePenNot",pmMergePenNot);
 tolua_constant(tolua_S,"pmMaskPenNot",pmMaskPenNot);
 tolua_constant(tolua_S,"pmMergeNotPen",pmMergeNotPen);
 tolua_constant(tolua_S,"pmMaskNotPen",pmMaskNotPen);
 tolua_constant(tolua_S,"pmMerge",pmMerge);
 tolua_constant(tolua_S,"pmNotMerge",pmNotMerge);
 tolua_constant(tolua_S,"pmMask",pmMask);
 tolua_constant(tolua_S,"pmNotMask",pmNotMask);
 tolua_constant(tolua_S,"pmXor",pmXor);
 tolua_constant(tolua_S,"pmNotXor",pmNotXor);
 tolua_constant(tolua_S,"psSolid",psSolid);
 tolua_constant(tolua_S,"psDash",psDash);
 tolua_constant(tolua_S,"psDot",psDot);
 tolua_constant(tolua_S,"psDashDot",psDashDot);
 tolua_constant(tolua_S,"psDashDotDot",psDashDotDot);
 tolua_constant(tolua_S,"psClear",psClear);
 tolua_constant(tolua_S,"psInsideFrame",psInsideFrame);
 tolua_constant(tolua_S,"bsSolid",bsSolid);
 tolua_constant(tolua_S,"bsClear",bsClear);
 tolua_constant(tolua_S,"bsHorizontal",bsHorizontal);
 tolua_constant(tolua_S,"bsVertical",bsVertical);
 tolua_constant(tolua_S,"bsFDiagonal",bsFDiagonal);
 tolua_constant(tolua_S,"bsBDiagonal",bsBDiagonal);
 tolua_constant(tolua_S,"bsCross",bsCross);
 tolua_constant(tolua_S,"bsDiagCross",bsDiagCross);
 tolua_constant(tolua_S,"fsSurface",fsSurface);
 tolua_constant(tolua_S,"fsBorder",fsBorder);
 tolua_variable(tolua_S,"opAND",tolua_get_const_opAND,NULL);
 tolua_variable(tolua_S,"opOR",tolua_get_const_opOR,NULL);
 tolua_variable(tolua_S,"opMINUS",tolua_get_const_opMINUS,NULL);
 tolua_variable(tolua_S,"opXOR",tolua_get_const_opXOR,NULL);
 tolua_variable(tolua_S,"lcNONE",tolua_get_const_lcNONE,NULL);
 tolua_variable(tolua_S,"lcCROSSING",tolua_get_const_lcCROSSING,NULL);
 tolua_variable(tolua_S,"lcPARALLEL",tolua_get_const_lcPARALLEL,NULL);
 tolua_variable(tolua_S,"lcEQUAL",tolua_get_const_lcEQUAL,NULL);
 tolua_variable(tolua_S,"lcCOMMONPOINT",tolua_get_const_lcCOMMONPOINT,NULL);
 tolua_variable(tolua_S,"lcCOLLINEAR",tolua_get_const_lcCOLLINEAR,NULL);
 tolua_variable(tolua_S,"etLEFT",tolua_get_const_etLEFT,NULL);
 tolua_variable(tolua_S,"etRIGHT",tolua_get_const_etRIGHT,NULL);
 tolua_variable(tolua_S,"etBETWEEN",tolua_get_const_etBETWEEN,NULL);
 tolua_variable(tolua_S,"etBEHIND",tolua_get_const_etBEHIND,NULL);
 tolua_variable(tolua_S,"etBEYOND",tolua_get_const_etBEYOND,NULL);
 tolua_variable(tolua_S,"etORIGIN",tolua_get_const_etORIGIN,NULL);
 tolua_variable(tolua_S,"etDESTINATION",tolua_get_const_etDESTINATION,NULL);
 tolua_variable(tolua_S,"ntNULL",tolua_get_const_ntNULL,NULL);
 tolua_variable(tolua_S,"ntONE",tolua_get_const_ntONE,NULL);
 tolua_variable(tolua_S,"ntTWO",tolua_get_const_ntTWO,NULL);
 tolua_variable(tolua_S,"ntTHREE",tolua_get_const_ntTHREE,NULL);
 tolua_variable(tolua_S,"ntFOUR",tolua_get_const_ntFOUR,NULL);
 tolua_variable(tolua_S,"ntFIVE",tolua_get_const_ntFIVE,NULL);
 tolua_variable(tolua_S,"pipBOUNDARY",tolua_get_const_pipBOUNDARY,NULL);
 tolua_variable(tolua_S,"pipOUTSIDE",tolua_get_const_pipOUTSIDE,NULL);
 tolua_variable(tolua_S,"pipINSIDE",tolua_get_const_pipINSIDE,NULL);
 tolua_variable(tolua_S,"clBlack",tolua_get_const_clBlack,NULL);
 tolua_variable(tolua_S,"clWhite",tolua_get_const_clWhite,NULL);
 tolua_variable(tolua_S,"PaymentCount",tolua_get_const_PaymentCount,NULL);
 tolua_variable(tolua_S,"WorkCount",tolua_get_const_WorkCount,NULL);
 tolua_variable(tolua_S,"SimpleCount",tolua_get_const_SimpleCount,NULL);
 tolua_variable(tolua_S,"cwClockWize",tolua_get_const_cwClockWize,NULL);
 tolua_variable(tolua_S,"cwNotClockWize",tolua_get_const_cwNotClockWize,NULL);
 tolua_variable(tolua_S,"cwNotDefined",tolua_get_const_cwNotDefined,NULL);
 tolua_variable(tolua_S,"mtInt",tolua_get_const_mtInt,NULL);
 tolua_variable(tolua_S,"mtDouble",tolua_get_const_mtDouble,NULL);
 tolua_variable(tolua_S,"mtString",tolua_get_const_mtString,NULL);
 tolua_variable(tolua_S,"mtMyObject",tolua_get_const_mtMyObject,NULL);
 tolua_constant(tolua_S,"ssShift",ssShift);
 tolua_constant(tolua_S,"ssAlt",ssAlt);
 tolua_constant(tolua_S,"ssCtrl",ssCtrl);
 tolua_constant(tolua_S,"ssLeft",ssLeft);
 tolua_constant(tolua_S,"ssRight",ssRight);
 tolua_constant(tolua_S,"ssMiddle",ssMiddle);
 tolua_constant(tolua_S,"ssDouble",ssDouble);
// tolua_constant(tolua_S,"fuPoints",fuPoints);
// tolua_constant(tolua_S,"fuCuts",fuCuts);
// tolua_constant(tolua_S,"fuAll",fuAll);
 tolua_variable(tolua_S,"ocmNone",tolua_get_const_ocmNone,NULL);
 tolua_variable(tolua_S,"ocmPosition",tolua_get_const_ocmPosition,NULL);
 tolua_variable(tolua_S,"ocmSize",tolua_get_const_ocmSize,NULL);
 tolua_endmodule(tolua_S);
 tolua_module(tolua_S,"My",1);
 tolua_beginmodule(tolua_S,"My");
 tolua_variable(tolua_S,"CurElement",tolua_get_My_CurElement_ptr,NULL);
 tolua_variable(tolua_S,"CurLink",tolua_get_My_CurLink_ptr,NULL);
 tolua_variable(tolua_S,"curLinkInfo",tolua_get_My_curLinkInfo_ptr,NULL);
 tolua_function(tolua_S,"RoundTo",tolua_z_All_My_RoundTo00);
 tolua_variable(tolua_S,"Counter",tolua_get_My_Counter_ptr,NULL);

 tolua_function(tolua_S,"ApplySkinTheme",tolua_get_ApplySkinTheme);
 tolua_function(tolua_S,"BindEvents",tolua_get_Bind_Events);
 tolua_function(tolua_S,"EditRoof",tolua_get_EditRoof);
 tolua_function(tolua_S,"FindNomenclatureByID",tolua_z_All_My_FindNomenclatureByID00);

 tolua_function(tolua_S,"FindNomenclatureByGUID",tolua_z_All_My_FindNomenclatureByGUID00);
 tolua_function(tolua_S,"FindNomenclatureByName",tolua_z_All_My_FindNomenclatureByName00);
 tolua_function(tolua_S,"FindNomenclatureByStrCode",tolua_z_All_My_FindNomenclatureByStrCode00);
 tolua_variable(tolua_S,"MetaNodeCollection",tolua_get_My_MetaNodeCollection_ptr,NULL);
 tolua_variable(tolua_S,"World",tolua_get_My_World_ptr,NULL);
 tolua_variable(tolua_S,"curAction",tolua_get_My_curAction_ptr,NULL);
 tolua_variable(tolua_S,"curMenuItem",tolua_get_My_curMenuItem_ptr,NULL);
 tolua_variable(tolua_S,"LN",tolua_get_My_LN_ptr,NULL);
 tolua_variable(tolua_S,"TechnologyCheckPass",tolua_get_My_TechnologyCheckPass,tolua_set_My_TechnologyCheckPass);
 tolua_variable(tolua_S,"TechnologyCheckStr",tolua_get_My_TechnologyCheckStr,tolua_set_My_TechnologyCheckStr);
 tolua_variable(tolua_S,"LuaUniForm",tolua_get_My_LuaUniForm_ptr,NULL);
 tolua_variable(tolua_S,"CurNomenclature",tolua_get_My_CurNomenclature_ptr,NULL);
 tolua_variable(tolua_S,"Deloune",tolua_get_My_Deloune_ptr,NULL);
 tolua_variable(tolua_S,"CurrentTool",tolua_get_My_CurrentTool_ptr,NULL);
 tolua_variable(tolua_S,"AUI",tolua_get_My_AUI,NULL);
 tolua_variable(tolua_S,"SelectionCollection",tolua_get_My_SelectionCollection,NULL);
 tolua_variable(tolua_S,"MySelection",tolua_get_My_MySelection,NULL);
 tolua_variable(tolua_S,"IntExplorer",tolua_get_My_IntExplorer_ptr,NULL);
 tolua_variable(tolua_S,"LuaConditionResult",tolua_get_My_LuaConditionResult,tolua_set_My_LuaConditionResult);
 tolua_variable(tolua_S,"UndoStack",tolua_get_My_UndoStack,NULL);
 tolua_variable(tolua_S,"Driver",tolua_get_My_Driver,NULL);
 tolua_function(tolua_S,"RGB",tolua_z_All_My_RGB00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TRect","TRect","",tolua_collect_TRect);
#else
 tolua_cclass(tolua_S,"TRect","TRect","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TRect");
 tolua_function(tolua_S,"new",tolua_z_All_TRect_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TRect_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TRect_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TRect_delete00);
 tolua_variable(tolua_S,"Left",tolua_get_TRect_Left,tolua_set_TRect_Left);
 tolua_variable(tolua_S,"Top",tolua_get_TRect_Top,tolua_set_TRect_Top);
 tolua_variable(tolua_S,"Right",tolua_get_TRect_Right,tolua_set_TRect_Right);
 tolua_variable(tolua_S,"Bottom",tolua_get_TRect_Bottom,tolua_set_TRect_Bottom);
 tolua_function(tolua_S,"Width",tolua_z_All_TRect_Width00);
 tolua_function(tolua_S,"Height",tolua_z_All_TRect_Height00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLuaUniForm","TLuaUniForm","TWinControl",tolua_collect_TLuaUniForm);
#else
 tolua_cclass(tolua_S,"TLuaUniForm","TLuaUniForm","TWinControl",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLuaUniForm");
 tolua_function(tolua_S,"new",tolua_z_All_TLuaUniForm_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TLuaUniForm_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TLuaUniForm_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TLuaUniForm_delete00);
 tolua_variable(tolua_S,"btOK",tolua_get_TLuaUniForm_btOK_ptr,NULL);
 tolua_variable(tolua_S,"btCancel",tolua_get_TLuaUniForm_btCancel_ptr,NULL);
 tolua_variable(tolua_S,"btApply",tolua_get_TLuaUniForm_btApply_ptr,NULL);
 tolua_variable(tolua_S,"pView",tolua_get_TLuaUniForm_pView_ptr,NULL);
 tolua_function(tolua_S,"GetPanel",tolua_z_All_TLuaUniForm_GetPanel00);
 tolua_function(tolua_S,"SetPageCountForPanel",tolua_z_All_TLuaUniForm_SetPageCountForPanel00);
 tolua_function(tolua_S,"GetPage",tolua_z_All_TLuaUniForm_GetPage00);
 tolua_function(tolua_S,"SetCaption",tolua_z_All_TLuaUniForm_SetCaption00);
 tolua_function(tolua_S,"SetPageCaption",tolua_z_All_TLuaUniForm_SetPageCaption00);
 tolua_variable(tolua_S,"ShowElement",tolua_get_TLuaUniForm_ShowElement_ptr,tolua_set_TLuaUniForm_ShowElement_ptr);
 tolua_variable(tolua_S,"ShowMetaElement",tolua_get_TLuaUniForm_ShowMetaElement_ptr,tolua_set_TLuaUniForm_ShowMetaElement_ptr);
 tolua_function(tolua_S,"Start",tolua_z_All_TLuaUniForm_Start00);
 tolua_function(tolua_S,"Close",tolua_z_All_TLuaUniForm_Close00);
 tolua_function(tolua_S,"SetDialogParent",tolua_z_All_TLuaUniForm_SetDialogParent00);
 tolua_variable(tolua_S,"AutoAlign",tolua_get_TLuaUniForm_AutoAlign,tolua_set_TLuaUniForm_AutoAlign);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TBrush","TBrush","",tolua_collect_TBrush);
#else
 tolua_cclass(tolua_S,"TBrush","TBrush","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TBrush");
 tolua_function(tolua_S,"new",tolua_z_All_TBrush_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TBrush_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TBrush_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TBrush_delete00);
 tolua_variable(tolua_S,"Color",tolua_get_TBrush_Color,tolua_set_TBrush_Color);
 tolua_variable(tolua_S,"Style",tolua_get_TBrush_Style,tolua_set_TBrush_Style);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TPen","TPen","",tolua_collect_TPen);
#else
 tolua_cclass(tolua_S,"TPen","TPen","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TPen");
 tolua_function(tolua_S,"new",tolua_z_All_TPen_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TPen_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TPen_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TPen_delete00);
 tolua_variable(tolua_S,"Color",tolua_get_TPen_Color,tolua_set_TPen_Color);
 tolua_variable(tolua_S,"Style",tolua_get_TPen_Style,tolua_set_TPen_Style);
 tolua_variable(tolua_S,"Mode",tolua_get_TPen_Mode,tolua_set_TPen_Mode);
 tolua_variable(tolua_S,"Width",tolua_get_TPen_Width,tolua_set_TPen_Width);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TIntVec","TIntVec","TInt3d",tolua_collect_TIntVec);
#else
 tolua_cclass(tolua_S,"TIntVec","TIntVec","TInt3d",NULL);
#endif
 tolua_beginmodule(tolua_S,"TIntVec");
 tolua_variable(tolua_S,"x",tolua_get_TIntVec_x,tolua_set_TIntVec_x);
 tolua_variable(tolua_S,"y",tolua_get_TIntVec_y,tolua_set_TIntVec_y);
 tolua_variable(tolua_S,"z",tolua_get_TIntVec_z,tolua_set_TIntVec_z);
 tolua_function(tolua_S,"new",tolua_z_All_TIntVec_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TIntVec_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TIntVec_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TIntVec_delete00);
 tolua_function(tolua_S,"new",tolua_z_All_TIntVec_new01);
 tolua_function(tolua_S,"new_local",tolua_z_All_TIntVec_new01_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TIntVec_new01_local);
 tolua_function(tolua_S,"new",tolua_z_All_TIntVec_new02);
 tolua_function(tolua_S,"new_local",tolua_z_All_TIntVec_new02_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TIntVec_new02_local);
 tolua_function(tolua_S,".le",tolua_z_All_TIntVec__le00);
 tolua_function(tolua_S,".eq",tolua_z_All_TIntVec__eq00);
 tolua_function(tolua_S,".add",tolua_z_All_TIntVec__add00);
 tolua_function(tolua_S,".sub",tolua_z_All_TIntVec__sub00);
 tolua_function(tolua_S,".mul",tolua_z_All_TIntVec__mul00);
 tolua_function(tolua_S,".div",tolua_z_All_TIntVec__div00);
 tolua_function(tolua_S,".div",tolua_z_All_TIntVec__div01);
 tolua_function(tolua_S,".mul",tolua_z_All_TIntVec__mul01);
 tolua_function(tolua_S,"Length",tolua_z_All_TIntVec_Length00);
 tolua_function(tolua_S,"Assign",tolua_z_All_TIntVec_Assign00);
 tolua_function(tolua_S,"Equal2D",tolua_z_All_TIntVec_Equal2D00);
 tolua_function(tolua_S,"Length2D",tolua_z_All_TIntVec_Length2D00);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"VecToStr",tolua_z_All_VecToStr00);
 tolua_function(tolua_S,"StrToVec",tolua_z_All_StrToVec00);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMyObject","TMyObject","",tolua_collect_TMyObject);
#else
 tolua_cclass(tolua_S,"TMyObject","TMyObject","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMyObject");
 tolua_function(tolua_S,"new",tolua_z_All_TMyObject_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMyObject_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMyObject_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMyObject_delete00);
 tolua_function(tolua_S,"GetCharName",tolua_z_All_TMyObject_GetCharName00);
 tolua_function(tolua_S,"GetCharDescription",tolua_z_All_TMyObject_GetCharDescription00);
 tolua_function(tolua_S,"SetCharDescription",tolua_z_All_TMyObject_SetCharDescription00);
 tolua_function(tolua_S,"LuaCompareAddress",tolua_z_All_TMyObject_LuaCompareAddress00);
 tolua_function(tolua_S,"Assign",tolua_z_All_TMyObject_Assign00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLuaRoofCut","TLuaRoofCut","",tolua_collect_TLuaRoofCut);
#else
 tolua_cclass(tolua_S,"TLuaRoofCut","TLuaRoofCut","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLuaRoofCut");
 tolua_function(tolua_S,"new",tolua_z_All_TLuaRoofCut_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TLuaRoofCut_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TLuaRoofCut_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TLuaRoofCut_delete00);
 tolua_variable(tolua_S,"LOW",tolua_get_TLuaRoofCut_LOW,NULL);
 tolua_variable(tolua_S,"HI",tolua_get_TLuaRoofCut_HI,NULL);
 tolua_variable(tolua_S,"Slope0",tolua_get_TLuaRoofCut_Slope0,tolua_set_TLuaRoofCut_Slope0);
 tolua_variable(tolua_S,"Slope1",tolua_get_TLuaRoofCut_Slope1,tolua_set_TLuaRoofCut_Slope1);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TPolygon","TPolygon","TMyObject",tolua_collect_TPolygon);
#else
 tolua_cclass(tolua_S,"TPolygon","TPolygon","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TPolygon");
 tolua_function(tolua_S,"new",tolua_z_All_TPolygon_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TPolygon_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TPolygon_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TPolygon_delete00);
 tolua_function(tolua_S,"Invert",tolua_z_All_TPolygon_Invert00);
 tolua_variable(tolua_S,"Vertex",tolua_get_TPolygon_Vertex_ptr,NULL);
 tolua_function(tolua_S,"Clear",tolua_z_All_TPolygon_Clear00);
 tolua_function(tolua_S,"MIN",tolua_z_All_TPolygon_MIN00);
 tolua_function(tolua_S,"MAX",tolua_z_All_TPolygon_MAX00);
 tolua_function(tolua_S,"Insert",tolua_z_All_TPolygon_Insert00);
 tolua_function(tolua_S,"Move",tolua_z_All_TPolygon_Move00);
 tolua_function(tolua_S,"Rotate",tolua_z_All_TPolygon_Rotate00);
 tolua_function(tolua_S,"ConsistsPoint",tolua_z_All_TPolygon_ConsistsPoint00);
 tolua_function(tolua_S,"FindSelfCrossing",tolua_z_All_TPolygon_FindSelfCrossing00);
 tolua_function(tolua_S,"Center",tolua_z_All_TPolygon_Center00);
 tolua_function(tolua_S,"CentralArea",tolua_z_All_TPolygon_CentralArea00);
 tolua_function(tolua_S,"GetCrossPoints",tolua_z_All_TPolygon_GetCrossPoints00);
 tolua_variable(tolua_S,"Router",tolua_get_TPolygon_Router_ptr,NULL);
 tolua_function(tolua_S,"IsClockWize",tolua_z_All_TPolygon_IsClockWize00);
 tolua_function(tolua_S,"KillCollinear_1",tolua_z_All_TPolygon_KillCollinear_100);
 tolua_function(tolua_S,"KillCloseEdges_0",tolua_z_All_TPolygon_KillCloseEdges_000);
 tolua_function(tolua_S,"SquareCreate",tolua_z_All_TPolygon_SquareCreate00);
 tolua_function(tolua_S,"IntrudeRib",tolua_z_All_TPolygon_IntrudeRib00);
 tolua_function(tolua_S,"Valid",tolua_z_All_TPolygon_Valid00);
 tolua_function(tolua_S,"ToConvex",tolua_z_All_TPolygon_ToConvex00);
 tolua_function(tolua_S,"RibIsConvex",tolua_z_All_TPolygon_RibIsConvex00);
 tolua_function(tolua_S,"IsConvex",tolua_z_All_TPolygon_IsConvex00);
 tolua_function(tolua_S,"PointIsConvex",tolua_z_All_TPolygon_PointIsConvex00);
 tolua_function(tolua_S,"ToConvexAndExtrude",tolua_z_All_TPolygon_ToConvexAndExtrude00);
 tolua_function(tolua_S,"CrossedWithPolygon",tolua_z_All_TPolygon_CrossedWithPolygon00);
 tolua_function(tolua_S,"KillSelfCrossing_2",tolua_z_All_TPolygon_KillSelfCrossing_200);
 tolua_function(tolua_S,"ExtrudeRib",tolua_z_All_TPolygon_ExtrudeRib00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"THoledPolygon","THoledPolygon","TPolygon",tolua_collect_THoledPolygon);
#else
 tolua_cclass(tolua_S,"THoledPolygon","THoledPolygon","TPolygon",NULL);
#endif
 tolua_beginmodule(tolua_S,"THoledPolygon");
 tolua_function(tolua_S,"new",tolua_z_All_THoledPolygon_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_THoledPolygon_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_THoledPolygon_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_THoledPolygon_delete00);
 tolua_variable(tolua_S,"Holes",tolua_get_THoledPolygon_Holes_ptr,NULL);
 tolua_function(tolua_S,"Clear",tolua_z_All_THoledPolygon_Clear00);
 tolua_function(tolua_S,"AddHole",tolua_z_All_THoledPolygon_AddHole00);
 tolua_function(tolua_S,"ExistsVertex",tolua_z_All_THoledPolygon_ExistsVertex00);
 tolua_function(tolua_S,"Move",tolua_z_All_THoledPolygon_Move00);
 tolua_function(tolua_S,"Rotate",tolua_z_All_THoledPolygon_Rotate00);
 tolua_function(tolua_S,"Set",tolua_z_All_THoledPolygon_Set00);
 tolua_function(tolua_S,"GetCrossPoints_UseHoles",tolua_z_All_THoledPolygon_GetCrossPoints_UseHoles00);
 tolua_function(tolua_S,"ConsistsPoint_UseHoles",tolua_z_All_THoledPolygon_ConsistsPoint_UseHoles00);
 tolua_function(tolua_S,"Valid",tolua_z_All_THoledPolygon_Valid00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaNode","TMetaNode","TMyObject",tolua_collect_TMetaNode);
#else
 tolua_cclass(tolua_S,"TMetaNode","TMetaNode","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaNode");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaNode_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaNode_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaNode_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaNode_delete00);
 tolua_function(tolua_S,"GetAttributeValue",tolua_z_All_TMetaNode_GetAttributeValue00);
 tolua_function(tolua_S,"GetAttribute",tolua_z_All_TMetaNode_GetAttribute00);
 tolua_function(tolua_S,"SetAttributeValue",tolua_z_All_TMetaNode_SetAttributeValue00);
 tolua_variable(tolua_S,"Parent",tolua_get_TMetaNode_Parent_ptr,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaTexture","TMetaTexture","TMetaNode",tolua_collect_TMetaTexture);
#else
 tolua_cclass(tolua_S,"TMetaTexture","TMetaTexture","TMetaNode",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaTexture");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaTexture_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaTexture_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaTexture_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaTexture_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaMaterial","TMetaMaterial","TMetaNode",tolua_collect_TMetaMaterial);
#else
 tolua_cclass(tolua_S,"TMetaMaterial","TMetaMaterial","TMetaNode",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaMaterial");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaMaterial_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaMaterial_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaMaterial_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaMaterial_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaElement","TMetaElement","TMetaNode",tolua_collect_TMetaElement);
#else
 tolua_cclass(tolua_S,"TMetaElement","TMetaElement","TMetaNode",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaElement");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaElement_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaElement_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaElement_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaElement_delete00);
 tolua_function(tolua_S,"GetDynLink",tolua_z_All_TMetaElement_GetDynLink00);
 tolua_variable(tolua_S,"DynLinkCount",tolua_get_TMetaElement_DynLinkCount,NULL);
 tolua_function(tolua_S,"SearchNeededLinkFor",tolua_z_All_TMetaElement_SearchNeededLinkFor00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaLink","TMetaLink","TMetaNode",tolua_collect_TMetaLink);
#else
 tolua_cclass(tolua_S,"TMetaLink","TMetaLink","TMetaNode",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaLink");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaLink_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaLink_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaLink_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaLink_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TDynamicLink","TDynamicLink","TMetaNode",tolua_collect_TDynamicLink);
#else
 tolua_cclass(tolua_S,"TDynamicLink","TDynamicLink","TMetaNode",NULL);
#endif
 tolua_beginmodule(tolua_S,"TDynamicLink");
 tolua_function(tolua_S,"new",tolua_z_All_TDynamicLink_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TDynamicLink_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TDynamicLink_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TDynamicLink_delete00);
 tolua_variable(tolua_S,"Link",tolua_get_TDynamicLink_Link_ptr,NULL);
 tolua_function(tolua_S,"NeededFor",tolua_z_All_TDynamicLink_NeededFor00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TNomenclature","TNomenclature","TMetaNode",tolua_collect_TNomenclature);
#else
 tolua_cclass(tolua_S,"TNomenclature","TNomenclature","TMetaNode",NULL);
#endif
 tolua_beginmodule(tolua_S,"TNomenclature");
 tolua_function(tolua_S,"new",tolua_z_All_TNomenclature_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TNomenclature_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TNomenclature_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TNomenclature_delete00);
 tolua_function(tolua_S,"GetMemo",tolua_z_All_TNomenclature_GetMemo00);
 tolua_variable(tolua_S,"Price",tolua_get_TNomenclature_Price,tolua_set_TNomenclature_Price);
 tolua_variable(tolua_S,"Weight",tolua_get_TNomenclature_Weight,tolua_set_TNomenclature_Weight);
 tolua_variable(tolua_S,"Size",tolua_get_TNomenclature_Size,NULL);
 tolua_variable(tolua_S,"Dimensions",tolua_get_TNomenclature_Dimensions,NULL);
 tolua_variable(tolua_S,"Associated",tolua_get_TNomenclature_Associated_ptr,NULL);
 tolua_function(tolua_S,"GetStrCode",tolua_z_All_TNomenclature_GetStrCode00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TUnit","TUnit","TMyObject",tolua_collect_TUnit);
#else
 tolua_cclass(tolua_S,"TUnit","TUnit","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TUnit");
 tolua_function(tolua_S,"new",tolua_z_All_TUnit_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TUnit_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TUnit_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TUnit_delete00);
 tolua_variable(tolua_S,"Parent",tolua_get_TUnit_Parent_ptr,NULL);
 tolua_function(tolua_S,"GetAttributeValue",tolua_z_All_TUnit_GetAttributeValue00);
 tolua_function(tolua_S,"GetAttribute",tolua_z_All_TUnit_GetAttribute00);
 tolua_function(tolua_S,"SetAttributeValue",tolua_z_All_TUnit_SetAttributeValue00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLink","TLink","TUnit",tolua_collect_TLink);
#else
 tolua_cclass(tolua_S,"TLink","TLink","TUnit",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLink");
 tolua_function(tolua_S,"new",tolua_z_All_TLink_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TLink_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TLink_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TLink_delete00);
 tolua_function(tolua_S,"Exists",tolua_z_All_TLink_Exists00);
 tolua_function(tolua_S,"Exists",tolua_z_All_TLink_Exists01);
 tolua_function(tolua_S,"NeededFor",tolua_z_All_TLink_NeededFor00);
 tolua_variable(tolua_S,"Angle",tolua_get_TLink_Angle,NULL);
 tolua_function(tolua_S,"AbsPositionBy",tolua_z_All_TLink_AbsPositionBy00);
 tolua_function(tolua_S,"GetPos",tolua_z_All_TLink_GetPos00);
 tolua_function(tolua_S,"GetElement",tolua_z_All_TLink_GetElement00);
 tolua_variable(tolua_S,"Counted",tolua_get_TLink_Counted,tolua_set_TLink_Counted);
 tolua_variable(tolua_S,"MyMeta",tolua_get_TLink_MyMeta_ptr,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TPlatform","TPlatform","TElement",tolua_collect_TPlatform);
#else
 tolua_cclass(tolua_S,"TPlatform","TPlatform","TElement",NULL);
#endif
 tolua_beginmodule(tolua_S,"TPlatform");
 tolua_function(tolua_S,"new",tolua_z_All_TPlatform_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TPlatform_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TPlatform_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TPlatform_delete00);
 tolua_function(tolua_S,"CreateClient",tolua_z_All_TPlatform_CreateClient00);
 tolua_function(tolua_S,"CheckFields",tolua_z_All_TPlatform_CheckFields00);
 tolua_function(tolua_S,"Init",tolua_z_All_TPlatform_Init00);
 tolua_function(tolua_S,"FillCompletePolygon",tolua_z_All_TPlatform_FillCompletePolygon00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TElement","TElement","TUnit",tolua_collect_TElement);
#else
 tolua_cclass(tolua_S,"TElement","TElement","TUnit",NULL);
#endif
 tolua_beginmodule(tolua_S,"TElement");
 tolua_function(tolua_S,"new",tolua_z_All_TElement_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TElement_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TElement_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TElement_delete00);
 tolua_function(tolua_S,"CreateView",tolua_z_All_TElement_CreateView00);
 tolua_function(tolua_S,"SetPos",tolua_z_All_TElement_SetPos00);
 tolua_function(tolua_S,"SetAngle",tolua_z_All_TElement_SetAngle00);
 tolua_function(tolua_S,"SetSize",tolua_z_All_TElement_SetSize00);
 tolua_function(tolua_S,"UserChangePosition",tolua_z_All_TElement_UserChangePosition00);
 tolua_function(tolua_S,"ChangeSize",tolua_z_All_TElement_ChangeSize00);
 tolua_function(tolua_S,"SetSlope",tolua_z_All_TElement_SetSlope00);
 tolua_function(tolua_S,"LinkPosition",tolua_z_All_TElement_LinkPosition00);
 tolua_function(tolua_S,"CreateClient",tolua_z_All_TElement_CreateClient00);
 tolua_function(tolua_S,"LOW_HI",tolua_z_All_TElement_LOW_HI00);
 tolua_variable(tolua_S,"CurrentEnabled",tolua_get_TElement_CurrentEnabled,tolua_set_TElement_CurrentEnabled);
 tolua_variable(tolua_S,"CustomEnabled",tolua_get_TElement_CustomEnabled,NULL);
 tolua_variable(tolua_S,"ModeEnabled",tolua_get_TElement_ModeEnabled,NULL);
 tolua_variable(tolua_S,"TotalEnabled",tolua_get_TElement_TotalEnabled,NULL);
 tolua_variable(tolua_S,"AbsSize",tolua_get_TElement_AbsSize,tolua_set_TElement_AbsSize);
 tolua_variable(tolua_S,"AbsPos",tolua_get_TElement_AbsPos,tolua_set_TElement_AbsPos);
 tolua_variable(tolua_S,"AbsAngle",tolua_get_TElement_AbsAngle,tolua_set_TElement_AbsAngle);
 tolua_variable(tolua_S,"SlopeMinus",tolua_get_TElement_SlopeMinus,NULL);
 tolua_variable(tolua_S,"SlopePlus",tolua_get_TElement_SlopePlus,NULL);
 tolua_function(tolua_S,"GetLink",tolua_z_All_TElement_GetLink00);
 tolua_variable(tolua_S,"LinksCount",tolua_get_TElement_LinksCount,NULL);
 tolua_function(tolua_S,"GetLinkOf",tolua_z_All_TElement_GetLinkOf00);
 tolua_function(tolua_S,"CreateLabel",tolua_z_All_TElement_CreateLabel00);
 tolua_function(tolua_S,"CreateLabel",tolua_z_All_TElement_CreateLabel01);
 tolua_function(tolua_S,"KillLabel",tolua_z_All_TElement_KillLabel00);
 tolua_function(tolua_S,"GetChild",tolua_z_All_TElement_GetChild00);
 tolua_function(tolua_S,"GetChildCount",tolua_z_All_TElement_GetChildCount00);
 tolua_variable(tolua_S,"HP",tolua_get_TElement_HP_ptr,tolua_set_TElement_HP_ptr);
 tolua_function(tolua_S,"ClearPoints",tolua_z_All_TElement_ClearPoints00);
 tolua_function(tolua_S,"AddArrPoint",tolua_z_All_TElement_AddArrPoint00);
 tolua_variable(tolua_S,"Counted",tolua_get_TElement_Counted,tolua_set_TElement_Counted);
 tolua_function(tolua_S,"EditStatus",tolua_z_All_TElement_EditStatus00);
 tolua_variable(tolua_S,"MyMeta",tolua_get_TElement_MyMeta_ptr,NULL);
 tolua_variable(tolua_S,"SideRender",tolua_get_TElement_SideRender,tolua_set_TElement_SideRender);
 tolua_function(tolua_S,"Create_SIZER",tolua_z_All_TElement_Create_SIZER00);
 tolua_function(tolua_S,"Kill_SIZER",tolua_z_All_TElement_Kill_SIZER00);
 tolua_function(tolua_S,"AbsFromLocal",tolua_z_All_TElement_AbsFromLocal00);
 tolua_function(tolua_S,"LocalFromAbs",tolua_z_All_TElement_LocalFromAbs00);
 tolua_function(tolua_S,"LocalizePolygon",tolua_z_All_TElement_LocalizePolygon00);
 tolua_variable(tolua_S,"SideCount",tolua_get_TElement_SideCount,NULL);
 tolua_function(tolua_S,"GetSide",tolua_z_All_TElement_GetSide00);
 tolua_function(tolua_S,"StandartCreateView",tolua_z_All_TElement_StandartCreateView00);
 tolua_variable(tolua_S,"RenderParamCount",tolua_get_TElement_RenderParamCount,NULL);
 tolua_function(tolua_S,"GetRenderParam",tolua_z_All_TElement_GetRenderParam00);
 tolua_function(tolua_S,"RegisterCreateView",tolua_z_All_TElement_RegisterCreateView00);
 tolua_function(tolua_S,"RegisterUpdatePos",tolua_z_All_TElement_RegisterUpdatePos00);
 tolua_function(tolua_S,"RegisterTexturing",tolua_z_All_TElement_RegisterTexturing00);
 tolua_function(tolua_S,"ProcessCreateView",tolua_z_All_TElement_ProcessCreateView00);
 tolua_function(tolua_S,"ProcessUpdatePos",tolua_z_All_TElement_ProcessUpdatePos00);
 tolua_function(tolua_S,"ProcessTexturing",tolua_z_All_TElement_ProcessTexturing00);
 tolua_function(tolua_S,"Render",tolua_z_All_TElement_Render00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLabel3D","TLabel3D","TElement",tolua_collect_TLabel3D);
#else
 tolua_cclass(tolua_S,"TLabel3D","TLabel3D","TElement",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLabel3D");
 tolua_function(tolua_S,"new",tolua_z_All_TLabel3D_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TLabel3D_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TLabel3D_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TLabel3D_delete00);
 tolua_function(tolua_S,"SetCharText",tolua_z_All_TLabel3D_SetCharText00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TRoom","TRoom","TElement",tolua_collect_TRoom);
#else
 tolua_cclass(tolua_S,"TRoom","TRoom","TElement",NULL);
#endif
 tolua_beginmodule(tolua_S,"TRoom");
 tolua_function(tolua_S,"new",tolua_z_All_TRoom_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TRoom_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TRoom_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TRoom_delete00);
 tolua_variable(tolua_S,"FloorParam",tolua_get_TRoom_FloorParam,NULL);
 tolua_variable(tolua_S,"CeilParam",tolua_get_TRoom_CeilParam,NULL);
 tolua_function(tolua_S,"GetFloorArea",tolua_z_All_TRoom_GetFloorArea00);
 tolua_function(tolua_S,"GetCeilArea",tolua_z_All_TRoom_GetCeilArea00);
 tolua_variable(tolua_S,"CeilServiceZ",tolua_get_TRoom_CeilServiceZ,tolua_set_TRoom_CeilServiceZ);
 tolua_variable(tolua_S,"Status",tolua_get_TRoom_Status,tolua_set_TRoom_Status);
 tolua_variable(tolua_S,"FloorServiceZ",tolua_get_TRoom_FloorServiceZ,tolua_set_TRoom_FloorServiceZ);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TCube","TCube","TElement",tolua_collect_TCube);
#else
 tolua_cclass(tolua_S,"TCube","TCube","TElement",NULL);
#endif
 tolua_beginmodule(tolua_S,"TCube");
 tolua_function(tolua_S,"new",tolua_z_All_TCube_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TCube_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TCube_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TCube_delete00);
 tolua_variable(tolua_S,"VHP",tolua_get_TCube_VHP,NULL);
 tolua_variable(tolua_S,"FragmentsCount",tolua_get_TCube_FragmentsCount,NULL);
 tolua_function(tolua_S,"GetFragment",tolua_z_All_TCube_GetFragment00);
 tolua_function(tolua_S,"FragmentArea",tolua_z_All_TCube_FragmentArea00);
 tolua_function(tolua_S,"NominateVHP",tolua_z_All_TCube_NominateVHP00);
 tolua_function(tolua_S,"FillCompletePolygon",tolua_z_All_TCube_FillCompletePolygon00);
 tolua_variable(tolua_S,"VP",tolua_get_TCube_VP_ptr,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMultiElement","TMultiElement","TElement",tolua_collect_TMultiElement);
#else
 tolua_cclass(tolua_S,"TMultiElement","TMultiElement","TElement",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMultiElement");
 tolua_function(tolua_S,"new",tolua_z_All_TMultiElement_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMultiElement_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMultiElement_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMultiElement_delete00);
 tolua_function(tolua_S,"Add",tolua_z_All_TMultiElement_Add00);
 tolua_function(tolua_S,"AddOnly",tolua_z_All_TMultiElement_AddOnly00);
 tolua_function(tolua_S,"DeleteOne",tolua_z_All_TMultiElement_DeleteOne00);
 tolua_function(tolua_S,"DeleteOne",tolua_z_All_TMultiElement_DeleteOne01);
 tolua_function(tolua_S,"Clear",tolua_z_All_TMultiElement_Clear00);
 tolua_function(tolua_S,"GetPart",tolua_z_All_TMultiElement_GetPart00);
 tolua_function(tolua_S,"CountOf",tolua_z_All_TMultiElement_CountOf00);
 tolua_variable(tolua_S,"MetaPartCount",tolua_get_TMultiElement_MetaPartCount,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"ToCube",tolua_z_All_ToCube00);
 tolua_function(tolua_S,"ToRoom",tolua_z_All_ToRoom00);
 tolua_function(tolua_S,"ToMultiElement",tolua_z_All_ToMultiElement00);
 tolua_function(tolua_S,"ToPlatform",tolua_z_All_ToPlatform00);
 tolua_function(tolua_S,"ToElement",tolua_z_All_ToElement00);
 tolua_function(tolua_S,"ToMetaElement",tolua_z_All_ToMetaElement00);
 tolua_function(tolua_S,"ToMetaLink",tolua_z_All_ToMetaLink00);
 tolua_function(tolua_S,"ToDynamicLink",tolua_z_All_ToDynamicLink00);
 tolua_function(tolua_S,"ToMyRegObject",tolua_z_All_ToMyRegObject00);
 tolua_function(tolua_S,"ToMetaNode",tolua_z_All_ToMetaNode00);
 tolua_function(tolua_S,"ToPolygon",tolua_z_All_ToPolygon00);
 tolua_function(tolua_S,"ToMetaTexture",tolua_z_All_ToMetaTexture00);
 tolua_function(tolua_S,"ToMetaMaterial",tolua_z_All_ToMetaMaterial00);
 tolua_function(tolua_S,"AngleRad",tolua_z_All_AngleRad00);
 tolua_function(tolua_S,"AngleRadOX",tolua_z_All_AngleRadOX00);
 tolua_function(tolua_S,"RotateAround",tolua_z_All_RotateAround00);
 tolua_function(tolua_S,"slope_around",tolua_z_All_slope_around00);
 tolua_function(tolua_S,"slope_delta",tolua_z_All_slope_delta00);
 tolua_function(tolua_S,"SlopeAround",tolua_z_All_SlopeAround00);
 tolua_function(tolua_S,"IsLinesCrossedExactly",tolua_z_All_IsLinesCrossedExactly00);
 tolua_function(tolua_S,"IsLineAndCutCrossedExactly",tolua_z_All_IsLineAndCutCrossedExactly00);
 tolua_function(tolua_S,"IsCutsCrossedExactly",tolua_z_All_IsCutsCrossedExactly00);
 tolua_function(tolua_S,"Classify",tolua_z_All_Classify00);
 tolua_function(tolua_S,"IsCutsCrossed",tolua_z_All_IsCutsCrossed00);
 tolua_function(tolua_S,"IsLinesParallel",tolua_z_All_IsLinesParallel00);
 tolua_function(tolua_S,"IsLinesCollinear",tolua_z_All_IsLinesCollinear00);
 tolua_function(tolua_S,"IsCutsCollinearAndCrossing",tolua_z_All_IsCutsCollinearAndCrossing00);
 tolua_function(tolua_S,"GetTotalArea",tolua_z_All_GetTotalArea00);
 tolua_function(tolua_S,"StrOut",tolua_z_All_StrOut00);
 tolua_function(tolua_S,"Mes",tolua_z_All_Mes00);
 tolua_function(tolua_S,"VectorP",tolua_z_All_VectorP00);
 tolua_function(tolua_S,"ScalarP",tolua_z_All_ScalarP00);
 tolua_function(tolua_S,"PlaneCrossPoint",tolua_z_All_PlaneCrossPoint00);
 tolua_function(tolua_S,"ComposePolygon",tolua_z_All_ComposePolygon00);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TCounterBase","TCounterBase","",tolua_collect_TCounterBase);
#else
 tolua_cclass(tolua_S,"TCounterBase","TCounterBase","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TCounterBase");
 tolua_function(tolua_S,"new",tolua_z_All_TCounterBase_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TCounterBase_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TCounterBase_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TCounterBase_delete00);
 tolua_function(tolua_S,"DefineField",tolua_z_All_TCounterBase_DefineField00);
 tolua_function(tolua_S,"FieldExists",tolua_z_All_TCounterBase_FieldExists00);
 tolua_function(tolua_S,"SetData",tolua_z_All_TCounterBase_SetData00);
 tolua_function(tolua_S,"AddData",tolua_z_All_TCounterBase_AddData00);
 tolua_function(tolua_S,"SetDataByValue",tolua_z_All_TCounterBase_SetDataByValue00);
 tolua_function(tolua_S,"AddDataByValue",tolua_z_All_TCounterBase_AddDataByValue00);
 tolua_function(tolua_S,"GetSum",tolua_z_All_TCounterBase_GetSum00);
 tolua_function(tolua_S,"GetSumByNomFilter",tolua_z_All_TCounterBase_GetSumByNomFilter00);
 tolua_function(tolua_S,"Clear",tolua_z_All_TCounterBase_Clear00);
 tolua_variable(tolua_S,"CountMode",tolua_get_TCounterBase_CountMode,tolua_set_TCounterBase_CountMode);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TFloorInfo","TFloorInfo","",tolua_collect_TFloorInfo);
#else
 tolua_cclass(tolua_S,"TFloorInfo","TFloorInfo","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TFloorInfo");
 tolua_function(tolua_S,"new",tolua_z_All_TFloorInfo_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TFloorInfo_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TFloorInfo_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TFloorInfo_delete00);
 tolua_variable(tolua_S,"Up_Lost",tolua_get_TFloorInfo_Up_Lost,tolua_set_TFloorInfo_Up_Lost);
 tolua_variable(tolua_S,"Down_Lost",tolua_get_TFloorInfo_Down_Lost,tolua_set_TFloorInfo_Down_Lost);
 tolua_variable(tolua_S,"OK_Pressed",tolua_get_TFloorInfo_OK_Pressed,tolua_set_TFloorInfo_OK_Pressed);
 tolua_variable(tolua_S,"FloorName",tolua_get_TFloorInfo_FloorName,tolua_set_TFloorInfo_FloorName);
 tolua_variable(tolua_S,"Height",tolua_get_TFloorInfo_Height,tolua_set_TFloorInfo_Height);
 tolua_variable(tolua_S,"FloorFrom",tolua_get_TFloorInfo_FloorFrom,tolua_set_TFloorInfo_FloorFrom);
 tolua_variable(tolua_S,"ElToMove",tolua_get_TFloorInfo_ElToMove_ptr,tolua_set_TFloorInfo_ElToMove_ptr);
 tolua_variable(tolua_S,"AddIndex",tolua_get_TFloorInfo_AddIndex,tolua_set_TFloorInfo_AddIndex);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TFloor","TFloor","TMyObject",tolua_collect_TFloor);
#else
 tolua_cclass(tolua_S,"TFloor","TFloor","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TFloor");
 tolua_function(tolua_S,"new",tolua_z_All_TFloor_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TFloor_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TFloor_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TFloor_delete00);
 tolua_variable(tolua_S,"AbsZ",tolua_get_TFloor_AbsZ,NULL);
 tolua_variable(tolua_S,"FirstElement",tolua_get_TFloor_FirstElement_ptr,NULL);
 tolua_variable(tolua_S,"Height",tolua_get_TFloor_Height,NULL);
 tolua_variable(tolua_S,"Up_Lost",tolua_get_TFloor_Up_Lost,tolua_set_TFloor_Up_Lost);
 tolua_variable(tolua_S,"Down_Lost",tolua_get_TFloor_Down_Lost,tolua_set_TFloor_Down_Lost);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMainTree","TMainTree","",tolua_collect_TMainTree);
#else
 tolua_cclass(tolua_S,"TMainTree","TMainTree","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMainTree");
 tolua_function(tolua_S,"new",tolua_z_All_TMainTree_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMainTree_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMainTree_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMainTree_delete00);
 tolua_function(tolua_S,"FloorOf",tolua_z_All_TMainTree_FloorOf00);
 tolua_function(tolua_S,"FloorOfUseDriver",tolua_z_All_TMainTree_FloorOfUseDriver00);
 tolua_variable(tolua_S,"ActiveFloor",tolua_get_TMainTree_ActiveFloor_ptr,NULL);
 tolua_variable(tolua_S,"FloorCount",tolua_get_TMainTree_FloorCount,NULL);
 tolua_variable(tolua_S,"FloorInfo",tolua_get_TMainTree_FloorInfo_ptr,NULL);
 tolua_function(tolua_S,"GetFloor",tolua_z_All_TMainTree_GetFloor00);
 tolua_function(tolua_S,"SelectByMetaElement",tolua_z_All_TMainTree_SelectByMetaElement00);
 tolua_function(tolua_S,"IndexOfFloor",tolua_z_All_TMainTree_IndexOfFloor00);
 tolua_variable(tolua_S,"ModeIndex",tolua_get_TMainTree_ModeIndex,NULL);
 tolua_variable(tolua_S,"PrevModeIndex",tolua_get_TMainTree_PrevModeIndex,NULL);
 tolua_function(tolua_S,"AutoConnect",tolua_z_All_TMainTree_AutoConnect00);
///////////////////////////////////Drive////////////////////////////////////////
 tolua_function(tolua_S,"Process_AddElement",tolua_z_All_TMainTree_Process_AddElement);
///////////////////////////////////Drive////////////////////////////////////////
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaNodeCollection","TMetaNodeCollection","",tolua_collect_TMetaNodeCollection);
#else
 tolua_cclass(tolua_S,"TMetaNodeCollection","TMetaNodeCollection","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaNodeCollection");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaNodeCollection_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaNodeCollection_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaNodeCollection_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaNodeCollection_delete00);
 tolua_function(tolua_S,"FindMDByName",tolua_z_All_TMetaNodeCollection_FindMDByName00);
 tolua_function(tolua_S,"FindMDByGUID",tolua_z_All_TMetaNodeCollection_FindMDByGUID00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"T3DScope","T3DScope","",tolua_collect_T3DScope);
#else
 tolua_cclass(tolua_S,"T3DScope","T3DScope","",NULL);
#endif
 tolua_beginmodule(tolua_S,"T3DScope");
 tolua_function(tolua_S,"new",tolua_z_All_T3DScope_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_T3DScope_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_T3DScope_new00_local);
 tolua_function(tolua_S,"new",tolua_z_All_T3DScope_new01);
 tolua_function(tolua_S,"new_local",tolua_z_All_T3DScope_new01_local);
 tolua_set_call_event(tolua_S,tolua_z_All_T3DScope_new01_local);
 tolua_function(tolua_S,"delete",tolua_z_All_T3DScope_delete00);
 tolua_variable(tolua_S,"LOW",tolua_get_T3DScope_LOW,tolua_set_T3DScope_LOW);
 tolua_variable(tolua_S,"HI",tolua_get_T3DScope_HI,tolua_set_T3DScope_HI);
 tolua_function(tolua_S,"CheckFields",tolua_z_All_T3DScope_CheckFields00);
 tolua_function(tolua_S,"Valid",tolua_z_All_T3DScope_Valid00);
 tolua_function(tolua_S,"CrossedWithStep",tolua_z_All_T3DScope_CrossedWithStep00);
 tolua_function(tolua_S,"Crossed",tolua_z_All_T3DScope_Crossed00);
 tolua_function(tolua_S,"Move",tolua_z_All_T3DScope_Move00);
 tolua_function(tolua_S,"Scale",tolua_z_All_T3DScope_Scale00);
 tolua_function(tolua_S,"PointAbout",tolua_z_All_T3DScope_PointAbout00);
 tolua_function(tolua_S,"Discrete",tolua_z_All_T3DScope_Discrete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TObjectAttributePreSet","TObjectAttributePreSet","",tolua_collect_TObjectAttributePreSet);
#else
 tolua_cclass(tolua_S,"TObjectAttributePreSet","TObjectAttributePreSet","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TObjectAttributePreSet");
 tolua_function(tolua_S,"new",tolua_z_All_TObjectAttributePreSet_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TObjectAttributePreSet_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TObjectAttributePreSet_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TObjectAttributePreSet_delete00);
 tolua_function(tolua_S,"SetAttributeName",tolua_z_All_TObjectAttributePreSet_SetAttributeName00);
 tolua_function(tolua_S,"SetAttributeValue",tolua_z_All_TObjectAttributePreSet_SetAttributeValue00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TSyngleLink","TSyngleLink","",tolua_collect_TSyngleLink);
#else
 tolua_cclass(tolua_S,"TSyngleLink","TSyngleLink","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TSyngleLink");
 tolua_function(tolua_S,"new",tolua_z_All_TSyngleLink_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TSyngleLink_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TSyngleLink_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TSyngleLink_delete00);
 tolua_variable(tolua_S,"CrossPoint",tolua_get_TSyngleLink_CrossPoint,tolua_set_TSyngleLink_CrossPoint);
 tolua_variable(tolua_S,"OAPreSet",tolua_get_TSyngleLink_OAPreSet,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLINKPATTERN","TLINKPATTERN","",tolua_collect_TLINKPATTERN);
#else
 tolua_cclass(tolua_S,"TLINKPATTERN","TLINKPATTERN","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLINKPATTERN");
 tolua_function(tolua_S,"new",tolua_z_All_TLINKPATTERN_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TLINKPATTERN_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TLINKPATTERN_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TLINKPATTERN_delete00);
 tolua_variable(tolua_S,"DL",tolua_get_TLINKPATTERN_DL_ptr,tolua_set_TLINKPATTERN_DL_ptr);
 tolua_variable(tolua_S,"TS_Common",tolua_get_TLINKPATTERN_TS_Common,tolua_set_TLINKPATTERN_TS_Common);
 tolua_variable(tolua_S,"R_Common",tolua_get_TLINKPATTERN_R_Common,tolua_set_TLINKPATTERN_R_Common);
 tolua_variable(tolua_S,"CrossPoint",tolua_get_TLINKPATTERN_CrossPoint,tolua_set_TLINKPATTERN_CrossPoint);
 tolua_variable(tolua_S,"Direction",tolua_get_TLINKPATTERN_Direction,tolua_set_TLINKPATTERN_Direction);
 tolua_variable(tolua_S,"RotateCenter",tolua_get_TLINKPATTERN_RotateCenter,tolua_set_TLINKPATTERN_RotateCenter);
 tolua_variable(tolua_S,"SyngleLinks",tolua_get_TLINKPATTERN_SyngleLinks,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLinkInfo","TLinkInfo","",tolua_collect_TLinkInfo);
#else
 tolua_cclass(tolua_S,"TLinkInfo","TLinkInfo","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLinkInfo");
 tolua_function(tolua_S,"new",tolua_z_All_TLinkInfo_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TLinkInfo_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TLinkInfo_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TLinkInfo_delete00);
 tolua_variable(tolua_S,"Target",tolua_get_TLinkInfo_Target_ptr,tolua_set_TLinkInfo_Target_ptr);
 tolua_variable(tolua_S,"Source",tolua_get_TLinkInfo_Source_ptr,tolua_set_TLinkInfo_Source_ptr);
 tolua_variable(tolua_S,"TargetScope",tolua_get_TLinkInfo_TargetScope_ptr,tolua_set_TLinkInfo_TargetScope_ptr);
 tolua_variable(tolua_S,"SourceScope",tolua_get_TLinkInfo_SourceScope_ptr,tolua_set_TLinkInfo_SourceScope_ptr);
 tolua_variable(tolua_S,"LINKPATTERN",tolua_get_TLinkInfo_LINKPATTERN_ptr,tolua_set_TLinkInfo_LINKPATTERN_ptr);
 tolua_variable(tolua_S,"SizeTransform",tolua_get_TLinkInfo_SizeTransform,tolua_set_TLinkInfo_SizeTransform);
 tolua_variable(tolua_S,"OK",tolua_get_TLinkInfo_OK,tolua_set_TLinkInfo_OK);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TSide","TSide","",tolua_collect_TSide);
#else
 tolua_cclass(tolua_S,"TSide","TSide","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TSide");
 tolua_function(tolua_S,"new",tolua_z_All_TSide_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TSide_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TSide_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TSide_delete00);
 tolua_variable(tolua_S,"SideType",tolua_get_TSide_SideType,tolua_set_TSide_SideType);
 tolua_variable(tolua_S,"Node0",tolua_get_TSide_Node0_ptr,NULL);
 tolua_variable(tolua_S,"CenterP0",tolua_get_TSide_CenterP0_ptr,NULL);
 tolua_variable(tolua_S,"P0",tolua_get_TSide_P0_ptr,NULL);
 tolua_variable(tolua_S,"Node1",tolua_get_TSide_Node1_ptr,NULL);
 tolua_variable(tolua_S,"CenterP1",tolua_get_TSide_CenterP1_ptr,NULL);
 tolua_variable(tolua_S,"P1",tolua_get_TSide_P1_ptr,NULL);
 tolua_variable(tolua_S,"Premises",tolua_get_TSide_Premises_ptr,NULL);
 tolua_variable(tolua_S,"Element",tolua_get_TSide_Element_ptr,NULL);
 tolua_function(tolua_S,"Crossed",tolua_z_All_TSide_Crossed00);
 tolua_function(tolua_S,"AnalizePoint",tolua_z_All_TSide_AnalizePoint00);
 tolua_function(tolua_S,"ConsistsPoint",tolua_z_All_TSide_ConsistsPoint00);
 tolua_function(tolua_S,"SplitMeDestination",tolua_z_All_TSide_SplitMeDestination00);
 tolua_function(tolua_S,"SplitMeOrigin",tolua_z_All_TSide_SplitMeOrigin00);
 tolua_function(tolua_S,"UpdateEdge",tolua_z_All_TSide_UpdateEdge00);
 tolua_function(tolua_S,"IsOutSide",tolua_z_All_TSide_IsOutSide00);
 tolua_variable(tolua_S,"ISWALLEND",tolua_get_TSide_ISWALLEND,NULL);
 tolua_variable(tolua_S,"ISWALLSTART",tolua_get_TSide_ISWALLSTART,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLinkPair","TLinkPair","",tolua_collect_TLinkPair);
#else
 tolua_cclass(tolua_S,"TLinkPair","TLinkPair","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLinkPair");
 tolua_function(tolua_S,"new",tolua_z_All_TLinkPair_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TLinkPair_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TLinkPair_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TLinkPair_delete00);
 tolua_variable(tolua_S,"Pos",tolua_get_TLinkPair_Pos,NULL);
 tolua_variable(tolua_S,"Link",tolua_get_TLinkPair_Link_ptr,NULL);
 tolua_function(tolua_S,"Satisfy",tolua_z_All_TLinkPair_Satisfy00);
 tolua_function(tolua_S,"GetTranslate",tolua_z_All_TLinkPair_GetTranslate00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TRay","TRay","",tolua_collect_TRay);
#else
 tolua_cclass(tolua_S,"TRay","TRay","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TRay");
 tolua_function(tolua_S,"new",tolua_z_All_TRay_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TRay_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TRay_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TRay_delete00);
 tolua_variable(tolua_S,"XPlusDirection",tolua_get_TRay_XPlusDirection,NULL);
 tolua_variable(tolua_S,"ElementPoints",tolua_get_TRay_ElementPoints_ptr,NULL);
 tolua_variable(tolua_S,"YMinusSide",tolua_get_TRay_YMinusSide_ptr,NULL);
 tolua_variable(tolua_S,"YPlusSide",tolua_get_TRay_YPlusSide_ptr,NULL);
 tolua_variable(tolua_S,"Point",tolua_get_TRay_Point_ptr,NULL);
 tolua_variable(tolua_S,"AngleOX",tolua_get_TRay_AngleOX,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TRoutePoint","TRoutePoint","",tolua_collect_TRoutePoint);
#else
 tolua_cclass(tolua_S,"TRoutePoint","TRoutePoint","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TRoutePoint");
 tolua_function(tolua_S,"new",tolua_z_All_TRoutePoint_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TRoutePoint_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TRoutePoint_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TRoutePoint_delete00);
 tolua_variable(tolua_S,"Pnt",tolua_get_TRoutePoint_Pnt_ptr,NULL);
 tolua_variable(tolua_S,"InputSide",tolua_get_TRoutePoint_InputSide_ptr,NULL);
 tolua_variable(tolua_S,"OutPutSide",tolua_get_TRoutePoint_OutPutSide_ptr,NULL);
 tolua_variable(tolua_S,"Next",tolua_get_TRoutePoint_Next_ptr,NULL);
 tolua_variable(tolua_S,"Prev",tolua_get_TRoutePoint_Prev_ptr,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TElementPoints","TElementPoints","",tolua_collect_TElementPoints);
#else
 tolua_cclass(tolua_S,"TElementPoints","TElementPoints","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TElementPoints");
 tolua_function(tolua_S,"new",tolua_z_All_TElementPoints_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TElementPoints_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TElementPoints_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TElementPoints_delete00);
 tolua_variable(tolua_S,"Element",tolua_get_TElementPoints_Element_ptr,NULL);
 tolua_function(tolua_S,"FindSide",tolua_z_All_TElementPoints_FindSide00);
 tolua_variable(tolua_S,"SideCount",tolua_get_TElementPoints_SideCount,NULL);
 tolua_variable(tolua_S,"FilteredRouteNodesCount",tolua_get_TElementPoints_FilteredRouteNodesCount,NULL);
 tolua_variable(tolua_S,"AllRouteNodesCount",tolua_get_TElementPoints_AllRouteNodesCount,NULL);
 tolua_function(tolua_S,"GetSide",tolua_z_All_TElementPoints_GetSide00);
 tolua_function(tolua_S,"GetFilteredRouteNode",tolua_z_All_TElementPoints_GetFilteredRouteNode00);
 tolua_function(tolua_S,"GetAllRouteNode",tolua_z_All_TElementPoints_GetAllRouteNode00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TRouteNode","TRouteNode","",tolua_collect_TRouteNode);
#else
 tolua_cclass(tolua_S,"TRouteNode","TRouteNode","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TRouteNode");
 tolua_function(tolua_S,"new",tolua_z_All_TRouteNode_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TRouteNode_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TRouteNode_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TRouteNode_delete00);
 tolua_variable(tolua_S,"LinkPoint",tolua_get_TRouteNode_LinkPoint,NULL);
 tolua_variable(tolua_S,"Element",tolua_get_TRouteNode_Element_ptr,NULL);
 tolua_variable(tolua_S,"RayCount",tolua_get_TRouteNode_RayCount,NULL);
 tolua_function(tolua_S,"GetRay",tolua_z_All_TRouteNode_GetRay00);
 tolua_variable(tolua_S,"LinkPairCount",tolua_get_TRouteNode_LinkPairCount,NULL);
 tolua_function(tolua_S,"GetLinkPair",tolua_z_All_TRouteNode_GetLinkPair00);
 tolua_variable(tolua_S,"RayCrossCount",tolua_get_TRouteNode_RayCrossCount,NULL);
 tolua_function(tolua_S,"GetRayCross",tolua_z_All_TRouteNode_GetRayCross00);
 tolua_function(tolua_S,"Satisfy",tolua_z_All_TRouteNode_Satisfy00);
 tolua_function(tolua_S,"IndexOf",tolua_z_All_TRouteNode_IndexOf00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLinkNodes","TLinkNodes","",tolua_collect_TLinkNodes);
#else
 tolua_cclass(tolua_S,"TLinkNodes","TLinkNodes","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLinkNodes");
 tolua_function(tolua_S,"new",tolua_z_All_TLinkNodes_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TLinkNodes_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TLinkNodes_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TLinkNodes_delete00);
 tolua_function(tolua_S,"Exists",tolua_z_All_TLinkNodes_Exists00);
 tolua_function(tolua_S,"ExistsElem",tolua_z_All_TLinkNodes_ExistsElem00);
 tolua_function(tolua_S,"GetLinksForVec",tolua_z_All_TLinkNodes_GetLinksForVec00);
 tolua_function(tolua_S,"GetLinksForLink",tolua_z_All_TLinkNodes_GetLinksForLink00);
 tolua_function(tolua_S,"SelectNearestPoint",tolua_z_All_TLinkNodes_SelectNearestPoint00);
 tolua_function(tolua_S,"SelectNearestLink",tolua_z_All_TLinkNodes_SelectNearestLink00);
 tolua_function(tolua_S,"DefinePermises_06",tolua_z_All_TLinkNodes_DefinePermises_0600);
 tolua_variable(tolua_S,"RouteNodeCount",tolua_get_TLinkNodes_RouteNodeCount,NULL);
 tolua_variable(tolua_S,"ElementFragmentsCount",tolua_get_TLinkNodes_ElementFragmentsCount,NULL);
 tolua_variable(tolua_S,"PremisesPolygonCount",tolua_get_TLinkNodes_PremisesPolygonCount,NULL);
 tolua_variable(tolua_S,"BuildingPolygonCount",tolua_get_TLinkNodes_BuildingPolygonCount,NULL);
 tolua_variable(tolua_S,"RouterListsCount",tolua_get_TLinkNodes_RouterListsCount,NULL);
 tolua_function(tolua_S,"GetRouteNode",tolua_z_All_TLinkNodes_GetRouteNode00);
 tolua_function(tolua_S,"GetElementFragments",tolua_z_All_TLinkNodes_GetElementFragments00);
 tolua_function(tolua_S,"GetPremisesPolygon",tolua_z_All_TLinkNodes_GetPremisesPolygon00);
 tolua_function(tolua_S,"GetBuildingPolygon",tolua_z_All_TLinkNodes_GetBuildingPolygon00);
 tolua_function(tolua_S,"GetRouterCount",tolua_z_All_TLinkNodes_GetRouterCount00);
 tolua_function(tolua_S,"GetRouter",tolua_z_All_TLinkNodes_GetRouter00);
 tolua_function(tolua_S,"ClearMetaFilter",tolua_z_All_TLinkNodes_ClearMetaFilter00);
 tolua_function(tolua_S,"AddToMetaFilter",tolua_z_All_TLinkNodes_AddToMetaFilter00);
 tolua_function(tolua_S,"IndexOfFilterMetaElement",tolua_z_All_TLinkNodes_IndexOfFilterMetaElement00);
 tolua_variable(tolua_S,"FilterMetaElementCount",tolua_get_TLinkNodes_FilterMetaElementCount,NULL);
 tolua_function(tolua_S,"GetFilterMetaElement",tolua_z_All_TLinkNodes_GetFilterMetaElement00);
///////////////////////////////////Drive////////////////////////////////////////
 tolua_variable(tolua_S,"NetActual",tolua_get_TLinkNodes_NetActual,tolua_set_TLinkNodes_NetActual);
///////////////////////////////////Drive////////////////////////////////////////

 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaUI","TMetaUI","TMetaNode",tolua_collect_TMetaUI);
#else
 tolua_cclass(tolua_S,"TMetaUI","TMetaUI","TMetaNode",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaUI");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaUI_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaUI_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaUI_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaUI_delete00);
 tolua_variable(tolua_S,"UImageIndex",tolua_get_TMetaUI_UImageIndex,tolua_set_TMetaUI_UImageIndex);
 tolua_variable(tolua_S,"Enabled",tolua_get_TMetaUI_Enabled,tolua_set_TMetaUI_Enabled);
 tolua_variable(tolua_S,"Visible",tolua_get_TMetaUI_Visible,tolua_set_TMetaUI_Visible);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaAction","TMetaAction","TMetaNode",tolua_collect_TMetaAction);
#else
 tolua_cclass(tolua_S,"TMetaAction","TMetaAction","TMetaNode",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaAction");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaAction_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaAction_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaAction_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaAction_delete00);
 tolua_variable(tolua_S,"UImageIndex",tolua_get_TMetaAction_UImageIndex,tolua_set_TMetaAction_UImageIndex);
 tolua_variable(tolua_S,"Enabled",tolua_get_TMetaAction_Enabled,tolua_set_TMetaAction_Enabled);
 tolua_variable(tolua_S,"Visible",tolua_get_TMetaAction_Visible,tolua_set_TMetaAction_Visible);
 tolua_function(tolua_S,"Update",tolua_z_All_TMetaAction_Update00);
 tolua_function(tolua_S,"Execute",tolua_z_All_TMetaAction_Execute00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaMenuItem","TMetaMenuItem","TMetaUI",tolua_collect_TMetaMenuItem);
#else
 tolua_cclass(tolua_S,"TMetaMenuItem","TMetaMenuItem","TMetaUI",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaMenuItem");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaMenuItem_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaMenuItem_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaMenuItem_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaMenuItem_delete00);
 tolua_function(tolua_S,"Update",tolua_z_All_TMetaMenuItem_Update00);
 tolua_function(tolua_S,"Execute",tolua_z_All_TMetaMenuItem_Execute00);
 tolua_variable(tolua_S,"AssociatedAction",tolua_get_TMetaMenuItem_AssociatedAction_ptr,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TRenderParam","TRenderParam","TMyObject",tolua_collect_TRenderParam);
#else
 tolua_cclass(tolua_S,"TRenderParam","TRenderParam","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TRenderParam");
 tolua_function(tolua_S,"new",tolua_z_All_TRenderParam_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TRenderParam_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TRenderParam_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TRenderParam_delete00);
 tolua_variable(tolua_S,"Area",tolua_get_TRenderParam_Area,tolua_set_TRenderParam_Area);
 tolua_variable(tolua_S,"Texture",tolua_get_TRenderParam_Texture_ptr,tolua_set_TRenderParam_Texture_ptr);
 tolua_variable(tolua_S,"Material",tolua_get_TRenderParam_Material_ptr,tolua_set_TRenderParam_Material_ptr);
 tolua_variable(tolua_S,"TexCenter",tolua_get_TRenderParam_TexCenter,tolua_set_TRenderParam_TexCenter);
 tolua_variable(tolua_S,"TexAngle",tolua_get_TRenderParam_TexAngle,tolua_set_TRenderParam_TexAngle);
 tolua_variable(tolua_S,"Enabled",tolua_get_TRenderParam_Enabled,tolua_set_TRenderParam_Enabled);
 tolua_variable(tolua_S,"OverPosMode",tolua_get_TRenderParam_OverPosMode,tolua_set_TRenderParam_OverPosMode);
 tolua_variable(tolua_S,"OverPos",tolua_get_TRenderParam_OverPos,tolua_set_TRenderParam_OverPos);
 tolua_variable(tolua_S,"OverSizeMode",tolua_get_TRenderParam_OverSizeMode,tolua_set_TRenderParam_OverSizeMode);
 tolua_variable(tolua_S,"OverSize",tolua_get_TRenderParam_OverSize,tolua_set_TRenderParam_OverSize);
 tolua_variable(tolua_S,"FLAT2D",tolua_get_TRenderParam_FLAT2D,tolua_set_TRenderParam_FLAT2D);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TFragmentSettings","TFragmentSettings","TMyObject",tolua_collect_TFragmentSettings);
#else
 tolua_cclass(tolua_S,"TFragmentSettings","TFragmentSettings","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TFragmentSettings");
 tolua_function(tolua_S,"new",tolua_z_All_TFragmentSettings_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TFragmentSettings_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TFragmentSettings_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TFragmentSettings_delete00);
 tolua_variable(tolua_S,"LocalP0",tolua_get_TFragmentSettings_LocalP0,NULL);
 tolua_variable(tolua_S,"LocalP1",tolua_get_TFragmentSettings_LocalP1,NULL);
 tolua_variable(tolua_S,"IsOutSide",tolua_get_TFragmentSettings_IsOutSide,NULL);
 tolua_variable(tolua_S,"SideType",tolua_get_TFragmentSettings_SideType,NULL);
 tolua_variable(tolua_S,"SideIndex",tolua_get_TFragmentSettings_SideIndex,NULL);
 tolua_function(tolua_S,"FragmentOfPoint",tolua_z_All_TFragmentSettings_FragmentOfPoint00);
 tolua_variable(tolua_S,"PolygonCount",tolua_get_TFragmentSettings_PolygonCount,NULL);
 tolua_function(tolua_S,"GetRenderParam",tolua_z_All_TFragmentSettings_GetRenderParam00);
 tolua_function(tolua_S,"GetPolygon",tolua_z_All_TFragmentSettings_GetPolygon00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TDelone","TDelone","",tolua_collect_TDelone);
#else
 tolua_cclass(tolua_S,"TDelone","TDelone","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TDelone");
 tolua_function(tolua_S,"new",tolua_z_All_TDelone_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TDelone_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TDelone_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TDelone_delete00);
 tolua_variable(tolua_S,"EPS",tolua_get_TDelone_EPS,tolua_set_TDelone_EPS);
 tolua_variable(tolua_S,"Triangles",tolua_get_TDelone_Triangles,NULL);
 tolua_variable(tolua_S,"Contour",tolua_get_TDelone_Contour,NULL);
 tolua_function(tolua_S,"OPERATION",tolua_z_All_TDelone_OPERATION00);
 tolua_function(tolua_S,"Triangulate",tolua_z_All_TDelone_Triangulate00);
 tolua_function(tolua_S,"Triangulate3",tolua_z_All_TDelone_Triangulate300);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"CreateRoofOld",tolua_z_All_CreateRoofOld00);
 tolua_function(tolua_S,"CreateRoof",tolua_z_All_CreateRoof00);
 tolua_function(tolua_S,"ConstructRoof",tolua_z_All_ConstructRoof00);
 tolua_function(tolua_S,"CreateLinkFunction",tolua_z_All_CreateLinkFunction00);
 tolua_function(tolua_S,"AllowLink",tolua_z_All_AllowLink00);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDI3D","TMDI3D","",tolua_collect_TMDI3D);
#else
 tolua_cclass(tolua_S,"TMDI3D","TMDI3D","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDI3D");
 tolua_function(tolua_S,"new",tolua_z_All_TMDI3D_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMDI3D_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMDI3D_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMDI3D_delete00);
 tolua_variable(tolua_S,"A",tolua_get_TMDI3D_A,tolua_set_TMDI3D_A);
 tolua_variable(tolua_S,"PlaneN",tolua_get_TMDI3D_PlaneN,tolua_set_TMDI3D_PlaneN);
 tolua_function(tolua_S,"ScreenToProject",tolua_z_All_TMDI3D_ScreenToProject00);
 tolua_function(tolua_S,"ScreenToProject",tolua_z_All_TMDI3D_ScreenToProject01);
 tolua_function(tolua_S,"ProjectToScreen",tolua_z_All_TMDI3D_ProjectToScreen00);
 tolua_function(tolua_S,"Factor",tolua_z_All_TMDI3D_Factor00);
 tolua_variable(tolua_S,"View",tolua_get_TMDI3D_View_ptr,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TShiftState","TShiftState","",tolua_collect_TShiftState);
#else
 tolua_cclass(tolua_S,"TShiftState","TShiftState","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TShiftState");
 tolua_function(tolua_S,"new",tolua_z_All_TShiftState_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TShiftState_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TShiftState_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TShiftState_delete00);
 tolua_function(tolua_S,"Contains",tolua_z_All_TShiftState_Contains00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TUserInterfaceParam","TUserInterfaceParam","",tolua_collect_TUserInterfaceParam);
#else
 tolua_cclass(tolua_S,"TUserInterfaceParam","TUserInterfaceParam","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TUserInterfaceParam");
 tolua_function(tolua_S,"new",tolua_z_All_TUserInterfaceParam_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TUserInterfaceParam_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TUserInterfaceParam_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TUserInterfaceParam_delete00);
 tolua_variable(tolua_S,"Center",tolua_get_TUserInterfaceParam_Center,tolua_set_TUserInterfaceParam_Center);
 tolua_variable(tolua_S,"NewCursorPos",tolua_get_TUserInterfaceParam_NewCursorPos,tolua_set_TUserInterfaceParam_NewCursorPos);
 tolua_variable(tolua_S,"Sender",tolua_get_TUserInterfaceParam_Sender_ptr,tolua_set_TUserInterfaceParam_Sender_ptr);
 tolua_variable(tolua_S,"Key",tolua_get_TUserInterfaceParam_Key,tolua_set_TUserInterfaceParam_Key);
 tolua_variable(tolua_S,"Shift",tolua_get_TUserInterfaceParam_Shift,tolua_set_TUserInterfaceParam_Shift);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TBaseTool","TBaseTool","TMyObject",tolua_collect_TBaseTool);
#else
 tolua_cclass(tolua_S,"TBaseTool","TBaseTool","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TBaseTool");
 tolua_variable(tolua_S,"UIP",tolua_get_TBaseTool_UIP,NULL);
 tolua_variable(tolua_S,"VCO",tolua_get_TBaseTool_VCO_ptr,NULL);
 tolua_variable(tolua_S,"SnapCursor",tolua_get_TBaseTool_SnapCursor_ptr,NULL);
 tolua_function(tolua_S,"new",tolua_z_All_TBaseTool_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TBaseTool_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TBaseTool_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TBaseTool_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TDialogBaseTool","TDialogBaseTool","TBaseTool",tolua_collect_TDialogBaseTool);
#else
 tolua_cclass(tolua_S,"TDialogBaseTool","TDialogBaseTool","TBaseTool",NULL);
#endif
 tolua_beginmodule(tolua_S,"TDialogBaseTool");
 tolua_function(tolua_S,"new",tolua_z_All_TDialogBaseTool_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TDialogBaseTool_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TDialogBaseTool_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TDialogBaseTool_delete00);
 tolua_variable(tolua_S,"Sender",tolua_get_TDialogBaseTool_Sender_ptr,NULL);
 tolua_variable(tolua_S,"A",tolua_get_TDialogBaseTool_A,tolua_set_TDialogBaseTool_A);
 tolua_variable(tolua_S,"PlaneN",tolua_get_TDialogBaseTool_PlaneN,tolua_set_TDialogBaseTool_PlaneN);
 tolua_function(tolua_S,"Changed",tolua_z_All_TDialogBaseTool_Changed00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TBindedBaseTool","TBindedBaseTool","TDialogBaseTool",tolua_collect_TBindedBaseTool);
#else
 tolua_cclass(tolua_S,"TBindedBaseTool","TBindedBaseTool","TDialogBaseTool",NULL);
#endif
 tolua_beginmodule(tolua_S,"TBindedBaseTool");
 tolua_function(tolua_S,"new",tolua_z_All_TBindedBaseTool_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TBindedBaseTool_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TBindedBaseTool_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TBindedBaseTool_delete00);
 tolua_variable(tolua_S,"ExecutedName",tolua_get_TBindedBaseTool_ExecutedName,NULL);
 tolua_function(tolua_S,"KeyToStrChar",tolua_z_All_TBindedBaseTool_KeyToStrChar00);
 tolua_variable(tolua_S,"Attribute",tolua_get_TBindedBaseTool_Attribute,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TAdvancedUserInterface","TAdvancedUserInterface","",tolua_collect_TAdvancedUserInterface);
#else
 tolua_cclass(tolua_S,"TAdvancedUserInterface","TAdvancedUserInterface","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TAdvancedUserInterface");
 tolua_function(tolua_S,"new",tolua_z_All_TAdvancedUserInterface_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TAdvancedUserInterface_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TAdvancedUserInterface_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TAdvancedUserInterface_delete00);
 tolua_variable(tolua_S,"CurrentWorldIndex",tolua_get_TAdvancedUserInterface_CurrentWorldIndex,NULL);
 tolua_variable(tolua_S,"ActiveView",tolua_get_TAdvancedUserInterface_ActiveView_ptr,NULL);
 tolua_variable(tolua_S,"ActiveWorld",tolua_get_TAdvancedUserInterface_ActiveWorld_ptr,NULL);
 tolua_function(tolua_S,"InvalidateView",tolua_z_All_TAdvancedUserInterface_InvalidateView00);
 tolua_variable(tolua_S,"Mode",tolua_get_TAdvancedUserInterface_Mode_ptr,NULL);
 tolua_variable(tolua_S,"AdvancedTexturing",tolua_get_TAdvancedUserInterface_AdvancedTexturing,tolua_set_TAdvancedUserInterface_AdvancedTexturing);
 tolua_variable(tolua_S,"PrevAdvancedTexturing",tolua_get_TAdvancedUserInterface_PrevAdvancedTexturing,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TIntExplorer","TIntExplorer","",tolua_collect_TIntExplorer);
#else
 tolua_cclass(tolua_S,"TIntExplorer","TIntExplorer","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TIntExplorer");
 tolua_function(tolua_S,"new",tolua_z_All_TIntExplorer_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TIntExplorer_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TIntExplorer_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TIntExplorer_delete00);
 tolua_variable(tolua_S,"MetaCatalogUnit",tolua_get_TIntExplorer_MetaCatalogUnit_ptr,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMetaCatalogUnit","TMetaCatalogUnit","TMetaNode",tolua_collect_TMetaCatalogUnit);
#else
 tolua_cclass(tolua_S,"TMetaCatalogUnit","TMetaCatalogUnit","TMetaNode",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMetaCatalogUnit");
 tolua_function(tolua_S,"new",tolua_z_All_TMetaCatalogUnit_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TMetaCatalogUnit_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TMetaCatalogUnit_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TMetaCatalogUnit_delete00);
 tolua_variable(tolua_S,"Associated",tolua_get_TMetaCatalogUnit_Associated_ptr,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TElementQueue","TElementQueue","",tolua_collect_TElementQueue);
#else
 tolua_cclass(tolua_S,"TElementQueue","TElementQueue","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TElementQueue");
 tolua_function(tolua_S,"new",tolua_z_All_TElementQueue_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TElementQueue_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TElementQueue_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TElementQueue_delete00);
 tolua_function(tolua_S,"Add",tolua_z_All_TElementQueue_Add00);
 tolua_function(tolua_S,"Changed",tolua_z_All_TElementQueue_Changed00);
 tolua_function(tolua_S,"Remove",tolua_z_All_TElementQueue_Remove00);
 tolua_function(tolua_S,"Clear",tolua_z_All_TElementQueue_Clear00);
 tolua_variable(tolua_S,"Count",tolua_get_TElementQueue_Count,NULL);
 tolua_function(tolua_S,"GetElement",tolua_z_All_TElementQueue_GetElement00);
 tolua_variable(tolua_S,"Enabled",tolua_get_TElementQueue_Enabled,tolua_set_TElementQueue_Enabled);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TElementQueueCollection","TElementQueueCollection","",tolua_collect_TElementQueueCollection);
#else
 tolua_cclass(tolua_S,"TElementQueueCollection","TElementQueueCollection","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TElementQueueCollection");
 tolua_function(tolua_S,"new",tolua_z_All_TElementQueueCollection_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TElementQueueCollection_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TElementQueueCollection_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TElementQueueCollection_delete00);
 tolua_variable(tolua_S,"Enabled",tolua_get_TElementQueueCollection_Enabled,NULL);
 tolua_function(tolua_S,"Remove",tolua_z_All_TElementQueueCollection_Remove00);
 tolua_function(tolua_S,"Changed",tolua_z_All_TElementQueueCollection_Changed00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TSelection","TSelection","TElementQueue",tolua_collect_TSelection);
#else
 tolua_cclass(tolua_S,"TSelection","TSelection","TElementQueue",NULL);
#endif
 tolua_beginmodule(tolua_S,"TSelection");
 tolua_function(tolua_S,"new",tolua_z_All_TSelection_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TSelection_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TSelection_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TSelection_delete00);
 tolua_function(tolua_S,"Render",tolua_z_All_TSelection_Render00);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"CreateElementFunction",tolua_z_All_CreateElementFunction00);
 tolua_function(tolua_S,"KillElement",tolua_z_All_KillElement00);
 tolua_function(tolua_S,"CreateElementFunction",tolua_z_All_CreateElementFunction01);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TUndoStack","TUndoStack","",tolua_collect_TUndoStack);
#else
 tolua_cclass(tolua_S,"TUndoStack","TUndoStack","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TUndoStack");
 tolua_function(tolua_S,"new",tolua_z_All_TUndoStack_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TUndoStack_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TUndoStack_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TUndoStack_delete00);
 tolua_function(tolua_S,"OpenSessionC",tolua_z_All_TUndoStack_OpenSessionC00);
 tolua_function(tolua_S,"CloseSession",tolua_z_All_TUndoStack_CloseSession00);
 tolua_function(tolua_S,"BreakSession",tolua_z_All_TUndoStack_BreakSession00);
 tolua_function(tolua_S,"Opened",tolua_z_All_TUndoStack_Opened00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TDriver","TDriver","",tolua_collect_TDriver);
#else
 tolua_cclass(tolua_S,"TDriver","TDriver","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TDriver");
 tolua_function(tolua_S,"new",tolua_z_All_TDriver_new00);
 tolua_function(tolua_S,"new_local",tolua_z_All_TDriver_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_All_TDriver_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_All_TDriver_delete00);
 tolua_variable(tolua_S,"MainMode",tolua_get_TDriver_MainMode,tolua_set_TDriver_MainMode);
 tolua_variable(tolua_S,"CorrectMode",tolua_get_TDriver_CorrectMode,tolua_set_TDriver_CorrectMode);
 tolua_function(tolua_S,"Init",tolua_z_All_TDriver_Init00);
 tolua_function(tolua_S,"Check",tolua_z_All_TDriver_Check00);
 tolua_function(tolua_S,"Stop",tolua_z_All_TDriver_Stop00);
 tolua_function(tolua_S,"Clear",tolua_z_All_TDriver_Clear00);
 tolua_variable(tolua_S,"PreLinksCount",tolua_get_TDriver_PreLinksCount,NULL);
 tolua_function(tolua_S,"GetPreLink",tolua_z_All_TDriver_GetPreLink00);
 tolua_endmodule(tolua_S);
 ////////////////////////////////////
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"TElementViewer","TElementViewer","TForm",tolua_collect_TElementViewer);
#else
 tolua_cclass(tolua_S,"TElementViewer","TElementViewer","TForm",NULL);
#endif
 tolua_beginmodule(tolua_S,"TElementViewer");
 tolua_variable(tolua_S,"pView",tolua_get_TElementViewer_pView_ptr,tolua_set_TElementViewer_pView_ptr);
 tolua_function(tolua_S,"FormActivate",tolua_z_ElementViewer_TElementViewer_FormActivate00);
 tolua_variable(tolua_S,"ShowElement",tolua_get_TElementViewer_ShowElement_ptr,tolua_set_TElementViewer_ShowElement_ptr);
 tolua_variable(tolua_S,"ShowMetaElement",tolua_get_TElementViewer_ShowMetaElement_ptr,tolua_set_TElementViewer_ShowMetaElement_ptr);
 tolua_variable(tolua_S,"MT",tolua_get_TElementViewer_MT_ptr,tolua_set_TElementViewer_MT_ptr);
 tolua_variable(tolua_S,"TV",tolua_get_TElementViewer_TV_ptr,tolua_set_TElementViewer_TV_ptr);
 tolua_function(tolua_S,"new",tolua_z_ElementViewer_TElementViewer_new00);
 tolua_function(tolua_S,"new_local",tolua_z_ElementViewer_TElementViewer_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_ElementViewer_TElementViewer_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_ElementViewer_TElementViewer_delete00);
 tolua_function(tolua_S,"Start",tolua_z_ElementViewer_TElementViewer_Start00);
 tolua_endmodule(tolua_S);
 ////////////////////////////////////
 tolua_endmodule(tolua_S);
 return 1;
}
