/*
** Lua binding: z_List
** Generated automatically by tolua++-1.0.3 on 02/03/05 18:30:29.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_z_List_open (lua_State* tolua_S);

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

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_TMTList_TElement_ (lua_State* tolua_S)
{
 TMTList<TElement>* self = (TMTList<TElement>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_TMDelTList_TIntVec___ (lua_State* tolua_S)
{
 TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMTList_TIntVec_ (lua_State* tolua_S)
{
 TMTList<TIntVec>* self = (TMTList<TIntVec>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_TObjectAttributePreSet_ (lua_State* tolua_S)
{
 TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_TMTList_THoledPolygon_ (lua_State* tolua_S)
{
 TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*) tolua_tousertype(tolua_S,1,0);
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

static int tolua_collect_THoledPolygon (lua_State* tolua_S)
{
 THoledPolygon* self = (THoledPolygon*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMTList_TLink_ (lua_State* tolua_S)
{
 TMTList<TLink>* self = (TMTList<TLink>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaElement (lua_State* tolua_S)
{
 TMetaElement* self = (TMetaElement*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TObjectAttributePreSet (lua_State* tolua_S)
{
 TObjectAttributePreSet* self = (TObjectAttributePreSet*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TLuaRoofCut (lua_State* tolua_S)
{
 TLuaRoofCut* self = (TLuaRoofCut*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_TSyngleLink_ (lua_State* tolua_S)
{
 TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMTList_TMDelTList_int___ (lua_State* tolua_S)
{
 TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TElement (lua_State* tolua_S)
{
 TElement* self = (TElement*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMTList_TMetaElement_ (lua_State* tolua_S)
{
 TMTList<TMetaElement>* self = (TMTList<TMetaElement>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_T3DScope_ (lua_State* tolua_S)
{
 TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_THoledPolygon_ (lua_State* tolua_S)
{
 TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_TMDelTList_int___ (lua_State* tolua_S)
{
 TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_int_ (lua_State* tolua_S)
{
 TMDelTList<int>* self = (TMDelTList<int>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TRoutePoint (lua_State* tolua_S)
{
 TRoutePoint* self = (TRoutePoint*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMTList_TMetaNode_ (lua_State* tolua_S)
{
 TMTList<TMetaNode>* self = (TMTList<TMetaNode>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_TIntVec_ (lua_State* tolua_S)
{
 TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_TLuaRoofCut_ (lua_State* tolua_S)
{
 TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_T3DScope (lua_State* tolua_S)
{
 T3DScope* self = (T3DScope*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_TRoutePoint_ (lua_State* tolua_S)
{
 TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMetaNode (lua_State* tolua_S)
{
 TMetaNode* self = (TMetaNode*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMTList_TPolygon_ (lua_State* tolua_S)
{
 TMTList<TPolygon>* self = (TMTList<TPolygon>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_TMDelTList_TPolygon___ (lua_State* tolua_S)
{
 TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_TPolygon_ (lua_State* tolua_S)
{
 TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TMTList<TMetaNode>");
 tolua_usertype(tolua_S,"TMDelTList<TMDelTList<TIntVec> >");
 tolua_usertype(tolua_S,"TMTList<TIntVec>");
 tolua_usertype(tolua_S,"TMDelTList<TObjectAttributePreSet>");
 tolua_usertype(tolua_S,"TPolygon");
 tolua_usertype(tolua_S,"TIntVec");
 tolua_usertype(tolua_S,"TMetaNode");
 tolua_usertype(tolua_S,"TSyngleLink");
 tolua_usertype(tolua_S,"TLink");
 tolua_usertype(tolua_S,"THoledPolygon");
 tolua_usertype(tolua_S,"TMTList<TLink>");
 tolua_usertype(tolua_S,"TMetaElement");
 tolua_usertype(tolua_S,"TObjectAttributePreSet");
 tolua_usertype(tolua_S,"TLuaRoofCut");
 tolua_usertype(tolua_S,"TMDelTList<TSyngleLink>");
 tolua_usertype(tolua_S,"TMTList<TMDelTList<int> >");
 tolua_usertype(tolua_S,"TElement");
 tolua_usertype(tolua_S,"TMTList<TMetaElement>");
 tolua_usertype(tolua_S,"T3DScope");
 tolua_usertype(tolua_S,"TMDelTList<THoledPolygon>");
 tolua_usertype(tolua_S,"TMDelTList<TMDelTList<int> >");
 tolua_usertype(tolua_S,"TMDelTList<int>");
 tolua_usertype(tolua_S,"TRoutePoint");
 tolua_usertype(tolua_S,"TMTList<THoledPolygon>");
 tolua_usertype(tolua_S,"TMyObject");
 tolua_usertype(tolua_S,"TMDelTList<TIntVec>");
 tolua_usertype(tolua_S,"TMDelTList<TLuaRoofCut>");
 tolua_usertype(tolua_S,"TMDelTList<T3DScope>");
 tolua_usertype(tolua_S,"TMDelTList<TRoutePoint>");
 tolua_usertype(tolua_S,"TMDelTList<TPolygon>");
 tolua_usertype(tolua_S,"TMTList<TPolygon>");
 tolua_usertype(tolua_S,"TMDelTList<TMDelTList<TPolygon> >");
 tolua_usertype(tolua_S,"TMTList<TElement>");
}

/* method: new of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TIntVec>* tolua_ret = (TMTList<TIntVec>*)  new TMTList<TIntVec>();

/* getting type */
  char* lua_type = "TMTList<TIntVec>";
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

/* method: new_local of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TIntVec>* tolua_ret = (TMTList<TIntVec>*)  new TMTList<TIntVec>();

/* getting type */
  char* lua_type = "TMTList<TIntVec>";
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

/* method: delete of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TIntVec* tolua_ret = (TIntVec*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TIntVec tolua_value = *((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->operator[](i);
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
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMTList<TIntVec> */
static int tolua_get_TMTList_TIntVec__Count(lua_State* tolua_S)
{
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  TIntVec* It = ((TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  TIntVec* It = ((TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Exists of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  TIntVec* It = ((TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(It);
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

/* method: Clear of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Consists of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__Consists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TIntVec>* L = ((TMTList<TIntVec>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Consists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Consists(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Consists'.",&tolua_err);
 return 0;
#endif
}

/* method: Same of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__Same00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TIntVec>* L = ((TMTList<TIntVec>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Same'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Same(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Same'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TIntVec>* L = ((TMTList<TIntVec>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(L);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMTList<TIntVec> */
static int tolua_z_List_TMTList_TIntVec__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TIntVec>* self = (TMTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TElement>* tolua_ret = (TMTList<TElement>*)  new TMTList<TElement>();

/* getting type */
  char* lua_type = "TMTList<TElement>";
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

/* method: new_local of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TElement>* tolua_ret = (TMTList<TElement>*)  new TMTList<TElement>();

/* getting type */
  char* lua_type = "TMTList<TElement>";
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

/* method: delete of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TElement* tolua_ret = (TElement*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TElement tolua_value = *((TElement*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TElement tolua_ret = (TElement)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TElement(tolua_ret);

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TElement));

/* getting type */
  char* lua_type = "TElement";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMTList<TElement> */
static int tolua_get_TMTList_TElement__Count(lua_State* tolua_S)
{
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  TElement* It = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  TElement* It = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Exists of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  TElement* It = ((TElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(It);
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

/* method: Clear of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Consists of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__Consists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TElement>* L = ((TMTList<TElement>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Consists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Consists(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Consists'.",&tolua_err);
 return 0;
#endif
}

/* method: Same of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__Same00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TElement>* L = ((TMTList<TElement>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Same'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Same(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Same'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TElement>* L = ((TMTList<TElement>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(L);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMTList<TElement> */
static int tolua_z_List_TMTList_TElement__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TElement>* self = (TMTList<TElement>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TLink>* tolua_ret = (TMTList<TLink>*)  new TMTList<TLink>();

/* getting type */
  char* lua_type = "TMTList<TLink>";
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

/* method: new_local of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TLink>* tolua_ret = (TMTList<TLink>*)  new TMTList<TLink>();

/* getting type */
  char* lua_type = "TMTList<TLink>";
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

/* method: delete of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TLink* tolua_ret = (TLink*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TLink tolua_value = *((TLink*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TLink tolua_ret = (TLink)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TLink(tolua_ret);

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TLink));

/* getting type */
  char* lua_type = "TLink";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMTList<TLink> */
static int tolua_get_TMTList_TLink__Count(lua_State* tolua_S)
{
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  TLink* It = ((TLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  TLink* It = ((TLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Exists of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  TLink* It = ((TLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(It);
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

/* method: Clear of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Consists of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__Consists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TLink>* L = ((TMTList<TLink>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Consists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Consists(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Consists'.",&tolua_err);
 return 0;
#endif
}

/* method: Same of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__Same00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TLink>* L = ((TMTList<TLink>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Same'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Same(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Same'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TLink>* L = ((TMTList<TLink>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(L);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMTList<TLink> */
static int tolua_z_List_TMTList_TLink__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TLink>* self = (TMTList<TLink>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TPolygon>* tolua_ret = (TMTList<TPolygon>*)  new TMTList<TPolygon>();

/* getting type */
  char* lua_type = "TMTList<TPolygon>";
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

/* method: new_local of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TPolygon>* tolua_ret = (TMTList<TPolygon>*)  new TMTList<TPolygon>();

/* getting type */
  char* lua_type = "TMTList<TPolygon>";
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

/* method: delete of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TPolygon* tolua_ret = (TPolygon*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TPolygon tolua_value = *((TPolygon*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TPolygon tolua_ret = (TPolygon)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TPolygon(tolua_ret);

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TPolygon));

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMTList<TPolygon> */
static int tolua_get_TMTList_TPolygon__Count(lua_State* tolua_S)
{
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TPolygon* It = ((TPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TPolygon* It = ((TPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Exists of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TPolygon* It = ((TPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(It);
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

/* method: Clear of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Consists of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__Consists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TPolygon>* L = ((TMTList<TPolygon>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Consists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Consists(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Consists'.",&tolua_err);
 return 0;
#endif
}

/* method: Same of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__Same00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TPolygon>* L = ((TMTList<TPolygon>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Same'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Same(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Same'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TPolygon>* L = ((TMTList<TPolygon>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(L);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMTList<TPolygon> */
static int tolua_z_List_TMTList_TPolygon__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TPolygon>* self = (TMTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<THoledPolygon>* tolua_ret = (TMTList<THoledPolygon>*)  new TMTList<THoledPolygon>();

/* getting type */
  char* lua_type = "TMTList<THoledPolygon>";
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

/* method: new_local of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<THoledPolygon>* tolua_ret = (TMTList<THoledPolygon>*)  new TMTList<THoledPolygon>();

/* getting type */
  char* lua_type = "TMTList<THoledPolygon>";
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

/* method: delete of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   THoledPolygon* tolua_ret = (THoledPolygon*)  self->GetItem(i);

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  THoledPolygon tolua_value = *((THoledPolygon*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   THoledPolygon tolua_ret = (THoledPolygon)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new THoledPolygon(tolua_ret);

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(THoledPolygon));

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMTList<THoledPolygon> */
static int tolua_get_TMTList_THoledPolygon__Count(lua_State* tolua_S)
{
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  THoledPolygon* It = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  THoledPolygon* It = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Exists of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  THoledPolygon* It = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(It);
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

/* method: Clear of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Consists of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__Consists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<THoledPolygon>* L = ((TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Consists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Consists(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Consists'.",&tolua_err);
 return 0;
#endif
}

/* method: Same of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__Same00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<THoledPolygon>* L = ((TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Same'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Same(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Same'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<THoledPolygon>* L = ((TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(L);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMTList<THoledPolygon> */
static int tolua_z_List_TMTList_THoledPolygon__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<THoledPolygon>* self = (TMTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TMetaElement>* tolua_ret = (TMTList<TMetaElement>*)  new TMTList<TMetaElement>();

/* getting type */
  char* lua_type = "TMTList<TMetaElement>";
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

/* method: new_local of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TMetaElement>* tolua_ret = (TMTList<TMetaElement>*)  new TMTList<TMetaElement>();

/* getting type */
  char* lua_type = "TMTList<TMetaElement>";
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

/* method: delete of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TMetaElement* tolua_ret = (TMetaElement*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TMetaElement tolua_value = *((TMetaElement*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TMetaElement tolua_ret = (TMetaElement)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TMetaElement(tolua_ret);

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TMetaElement));

/* getting type */
  char* lua_type = "TMetaElement";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMTList<TMetaElement> */
static int tolua_get_TMTList_TMetaElement__Count(lua_State* tolua_S)
{
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  TMetaElement* It = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  TMetaElement* It = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Exists of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  TMetaElement* It = ((TMetaElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(It);
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

/* method: Clear of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Consists of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__Consists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TMetaElement>* L = ((TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Consists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Consists(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Consists'.",&tolua_err);
 return 0;
#endif
}

/* method: Same of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__Same00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TMetaElement>* L = ((TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Same'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Same(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Same'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TMetaElement>* L = ((TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(L);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMTList<TMetaElement> */
static int tolua_z_List_TMTList_TMetaElement__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaElement>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaElement>* self = (TMTList<TMetaElement>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TMetaNode>* tolua_ret = (TMTList<TMetaNode>*)  new TMTList<TMetaNode>();

/* getting type */
  char* lua_type = "TMTList<TMetaNode>";
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

/* method: new_local of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TMetaNode>* tolua_ret = (TMTList<TMetaNode>*)  new TMTList<TMetaNode>();

/* getting type */
  char* lua_type = "TMTList<TMetaNode>";
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

/* method: delete of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TMetaNode* tolua_ret = (TMetaNode*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMetaNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TMetaNode tolua_value = *((TMetaNode*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TMetaNode tolua_ret = (TMetaNode)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TMetaNode(tolua_ret);

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TMetaNode));

/* getting type */
  char* lua_type = "TMetaNode";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMTList<TMetaNode> */
static int tolua_get_TMTList_TMetaNode__Count(lua_State* tolua_S)
{
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  TMetaNode* It = ((TMetaNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  TMetaNode* It = ((TMetaNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Exists of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMetaNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  TMetaNode* It = ((TMetaNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(It);
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

/* method: Clear of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Consists of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__Consists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TMetaNode>* L = ((TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Consists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Consists(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Consists'.",&tolua_err);
 return 0;
#endif
}

/* method: Same of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__Same00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TMetaNode>* L = ((TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Same'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Same(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Same'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TMetaNode>* L = ((TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(L);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMTList<TMetaNode> */
static int tolua_z_List_TMTList_TMetaNode__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMetaNode>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMetaNode>* self = (TMTList<TMetaNode>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TMDelTList<int> >* tolua_ret = (TMTList<TMDelTList<int> >*)  new TMTList<TMDelTList<int> >();

/* getting type */
  char* lua_type = "TMTList<TMDelTList<int> >";
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

/* method: new_local of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<TMDelTList<int> >* tolua_ret = (TMTList<TMDelTList<int> >*)  new TMTList<TMDelTList<int> >();

/* getting type */
  char* lua_type = "TMTList<TMDelTList<int> >";
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

/* method: delete of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TMDelTList<int>* tolua_ret = (TMDelTList<int>*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TMDelTList<int>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int_____seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TMDelTList<int> tolua_value = *((TMDelTList<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int_____geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TMDelTList<int> tolua_ret = (TMDelTList<int>)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TMDelTList<int>(tolua_ret);

/* getting type */
  char* lua_type = "TMDelTList<int>";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TMDelTList<int>));

/* getting type */
  char* lua_type = "TMDelTList<int>";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMTList<TMDelTList<int> > */
static int tolua_get_TMTList_TMDelTList_int____Count(lua_State* tolua_S)
{
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<int>* It = ((TMDelTList<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<int>* It = ((TMDelTList<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Exists of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____Exists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<int>* It = ((TMDelTList<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Exists(It);
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

/* method: Clear of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Consists of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____Consists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TMDelTList<int> >* L = ((TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Consists'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Consists(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Consists'.",&tolua_err);
 return 0;
#endif
}

/* method: Same of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____Same00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TMDelTList<int> >* L = ((TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Same'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Same(L);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Same'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TMDelTList<int> >* L = ((TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(L);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMTList<TMDelTList<int> > */
static int tolua_z_List_TMTList_TMDelTList_int____Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<TMDelTList<int> >* self = (TMTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TIntVec>* tolua_ret = (TMDelTList<TIntVec>*)  new TMDelTList<TIntVec>();

/* getting type */
  char* lua_type = "TMDelTList<TIntVec>";
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

/* method: new_local of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TIntVec>* tolua_ret = (TMDelTList<TIntVec>*)  new TMDelTList<TIntVec>();

/* getting type */
  char* lua_type = "TMDelTList<TIntVec>";
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

/* method: delete of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TIntVec* tolua_ret = (TIntVec*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   TIntVec* tolua_ret = (TIntVec*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "TIntVec";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TIntVec tolua_value = *((TIntVec*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TIntVec tolua_ret = (TIntVec)  self->operator[](i);
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
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<TIntVec> */
static int tolua_get_TMDelTList_TIntVec__Count(lua_State* tolua_S)
{
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  TIntVec* It = ((TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  TIntVec* it = ((TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_TIntVec__RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  TIntVec* It = ((TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<TIntVec> */
static int tolua_z_List_TMDelTList_TIntVec__Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TIntVec>* self = (TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
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

/* method: new of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TLuaRoofCut>* tolua_ret = (TMDelTList<TLuaRoofCut>*)  new TMDelTList<TLuaRoofCut>();

/* getting type */
  char* lua_type = "TMDelTList<TLuaRoofCut>";
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

/* method: new_local of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TLuaRoofCut>* tolua_ret = (TMDelTList<TLuaRoofCut>*)  new TMDelTList<TLuaRoofCut>();

/* getting type */
  char* lua_type = "TMDelTList<TLuaRoofCut>";
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

/* method: delete of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TLuaRoofCut* tolua_ret = (TLuaRoofCut*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TLuaRoofCut";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   TLuaRoofCut* tolua_ret = (TLuaRoofCut*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "TLuaRoofCut";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TLuaRoofCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TLuaRoofCut tolua_value = *((TLuaRoofCut*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TLuaRoofCut tolua_ret = (TLuaRoofCut)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TLuaRoofCut(tolua_ret);

/* getting type */
  char* lua_type = "TLuaRoofCut";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TLuaRoofCut));

/* getting type */
  char* lua_type = "TLuaRoofCut";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<TLuaRoofCut> */
static int tolua_get_TMDelTList_TLuaRoofCut__Count(lua_State* tolua_S)
{
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLuaRoofCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  TLuaRoofCut* It = ((TLuaRoofCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLuaRoofCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  TLuaRoofCut* it = ((TLuaRoofCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_TLuaRoofCut__RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TLuaRoofCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  TLuaRoofCut* It = ((TLuaRoofCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<TLuaRoofCut> */
static int tolua_z_List_TMDelTList_TLuaRoofCut__Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TLuaRoofCut>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TLuaRoofCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TLuaRoofCut>* self = (TMDelTList<TLuaRoofCut>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  TLuaRoofCut* Item = ((TLuaRoofCut*)  tolua_tousertype(tolua_S,3,0));
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

/* method: new of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TPolygon>* tolua_ret = (TMDelTList<TPolygon>*)  new TMDelTList<TPolygon>();

/* getting type */
  char* lua_type = "TMDelTList<TPolygon>";
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

/* method: new_local of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TPolygon>* tolua_ret = (TMDelTList<TPolygon>*)  new TMDelTList<TPolygon>();

/* getting type */
  char* lua_type = "TMDelTList<TPolygon>";
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

/* method: delete of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TPolygon* tolua_ret = (TPolygon*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   TPolygon* tolua_ret = (TPolygon*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TPolygon tolua_value = *((TPolygon*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TPolygon tolua_ret = (TPolygon)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TPolygon(tolua_ret);

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TPolygon));

/* getting type */
  char* lua_type = "TPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<TPolygon> */
static int tolua_get_TMDelTList_TPolygon__Count(lua_State* tolua_S)
{
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TPolygon* It = ((TPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TPolygon* it = ((TPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_TPolygon__RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  TPolygon* It = ((TPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<TPolygon> */
static int tolua_z_List_TMDelTList_TPolygon__Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TPolygon>* self = (TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  TPolygon* Item = ((TPolygon*)  tolua_tousertype(tolua_S,3,0));
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

/* method: new of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<THoledPolygon>* tolua_ret = (TMDelTList<THoledPolygon>*)  new TMDelTList<THoledPolygon>();

/* getting type */
  char* lua_type = "TMDelTList<THoledPolygon>";
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

/* method: new_local of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<THoledPolygon>* tolua_ret = (TMDelTList<THoledPolygon>*)  new TMDelTList<THoledPolygon>();

/* getting type */
  char* lua_type = "TMDelTList<THoledPolygon>";
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

/* method: delete of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   THoledPolygon* tolua_ret = (THoledPolygon*)  self->GetItem(i);

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   THoledPolygon* tolua_ret = (THoledPolygon*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  THoledPolygon tolua_value = *((THoledPolygon*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   THoledPolygon tolua_ret = (THoledPolygon)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new THoledPolygon(tolua_ret);

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(THoledPolygon));

/* getting type */
  char* lua_type = "THoledPolygon";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<THoledPolygon> */
static int tolua_get_TMDelTList_THoledPolygon__Count(lua_State* tolua_S)
{
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  THoledPolygon* It = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  THoledPolygon* it = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_THoledPolygon__RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  THoledPolygon* It = ((THoledPolygon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<THoledPolygon> */
static int tolua_z_List_TMDelTList_THoledPolygon__Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<THoledPolygon>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"THoledPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<THoledPolygon>* self = (TMDelTList<THoledPolygon>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  THoledPolygon* Item = ((THoledPolygon*)  tolua_tousertype(tolua_S,3,0));
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

/* method: new of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<T3DScope>* tolua_ret = (TMDelTList<T3DScope>*)  new TMDelTList<T3DScope>();

/* getting type */
  char* lua_type = "TMDelTList<T3DScope>";
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

/* method: new_local of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<T3DScope>* tolua_ret = (TMDelTList<T3DScope>*)  new TMDelTList<T3DScope>();

/* getting type */
  char* lua_type = "TMDelTList<T3DScope>";
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

/* method: delete of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   T3DScope* tolua_ret = (T3DScope*)  self->GetItem(i);

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   T3DScope* tolua_ret = (T3DScope*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  T3DScope tolua_value = *((T3DScope*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   T3DScope tolua_ret = (T3DScope)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new T3DScope(tolua_ret);

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(T3DScope));

/* getting type */
  char* lua_type = "T3DScope";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<T3DScope> */
static int tolua_get_TMDelTList_T3DScope__Count(lua_State* tolua_S)
{
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  T3DScope* It = ((T3DScope*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  T3DScope* it = ((T3DScope*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_T3DScope__RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  T3DScope* It = ((T3DScope*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<T3DScope> */
static int tolua_z_List_TMDelTList_T3DScope__Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<T3DScope>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"T3DScope",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<T3DScope>* self = (TMDelTList<T3DScope>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  T3DScope* Item = ((T3DScope*)  tolua_tousertype(tolua_S,3,0));
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

/* method: new of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TRoutePoint>* tolua_ret = (TMDelTList<TRoutePoint>*)  new TMDelTList<TRoutePoint>();

/* getting type */
  char* lua_type = "TMDelTList<TRoutePoint>";
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

/* method: new_local of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TRoutePoint>* tolua_ret = (TMDelTList<TRoutePoint>*)  new TMDelTList<TRoutePoint>();

/* getting type */
  char* lua_type = "TMDelTList<TRoutePoint>";
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

/* method: delete of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TRoutePoint* tolua_ret = (TRoutePoint*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TRoutePoint";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   TRoutePoint* tolua_ret = (TRoutePoint*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "TRoutePoint";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TRoutePoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TRoutePoint tolua_value = *((TRoutePoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TRoutePoint tolua_ret = (TRoutePoint)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TRoutePoint(tolua_ret);

/* getting type */
  char* lua_type = "TRoutePoint";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TRoutePoint));

/* getting type */
  char* lua_type = "TRoutePoint";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<TRoutePoint> */
static int tolua_get_TMDelTList_TRoutePoint__Count(lua_State* tolua_S)
{
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TRoutePoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  TRoutePoint* It = ((TRoutePoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TRoutePoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  TRoutePoint* it = ((TRoutePoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_TRoutePoint__RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TRoutePoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  TRoutePoint* It = ((TRoutePoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<TRoutePoint> */
static int tolua_z_List_TMDelTList_TRoutePoint__Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TRoutePoint>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TRoutePoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TRoutePoint>* self = (TMDelTList<TRoutePoint>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  TRoutePoint* Item = ((TRoutePoint*)  tolua_tousertype(tolua_S,3,0));
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

/* method: new of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TObjectAttributePreSet>* tolua_ret = (TMDelTList<TObjectAttributePreSet>*)  new TMDelTList<TObjectAttributePreSet>();

/* getting type */
  char* lua_type = "TMDelTList<TObjectAttributePreSet>";
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

/* method: new_local of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TObjectAttributePreSet>* tolua_ret = (TMDelTList<TObjectAttributePreSet>*)  new TMDelTList<TObjectAttributePreSet>();

/* getting type */
  char* lua_type = "TMDelTList<TObjectAttributePreSet>";
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

/* method: delete of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TObjectAttributePreSet* tolua_ret = (TObjectAttributePreSet*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TObjectAttributePreSet";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   TObjectAttributePreSet* tolua_ret = (TObjectAttributePreSet*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "TObjectAttributePreSet";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TObjectAttributePreSet tolua_value = *((TObjectAttributePreSet*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TObjectAttributePreSet tolua_ret = (TObjectAttributePreSet)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TObjectAttributePreSet(tolua_ret);

/* getting type */
  char* lua_type = "TObjectAttributePreSet";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TObjectAttributePreSet));

/* getting type */
  char* lua_type = "TObjectAttributePreSet";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_get_TMDelTList_TObjectAttributePreSet__Count(lua_State* tolua_S)
{
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  TObjectAttributePreSet* It = ((TObjectAttributePreSet*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  TObjectAttributePreSet* it = ((TObjectAttributePreSet*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_TObjectAttributePreSet__RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  TObjectAttributePreSet* It = ((TObjectAttributePreSet*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<TObjectAttributePreSet> */
static int tolua_z_List_TMDelTList_TObjectAttributePreSet__Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TObjectAttributePreSet>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TObjectAttributePreSet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TObjectAttributePreSet>* self = (TMDelTList<TObjectAttributePreSet>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  TObjectAttributePreSet* Item = ((TObjectAttributePreSet*)  tolua_tousertype(tolua_S,3,0));
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

/* method: new of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TSyngleLink>* tolua_ret = (TMDelTList<TSyngleLink>*)  new TMDelTList<TSyngleLink>();

/* getting type */
  char* lua_type = "TMDelTList<TSyngleLink>";
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

/* method: new_local of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TSyngleLink>* tolua_ret = (TMDelTList<TSyngleLink>*)  new TMDelTList<TSyngleLink>();

/* getting type */
  char* lua_type = "TMDelTList<TSyngleLink>";
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

/* method: delete of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TSyngleLink* tolua_ret = (TSyngleLink*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TSyngleLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   TSyngleLink* tolua_ret = (TSyngleLink*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "TSyngleLink";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TSyngleLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TSyngleLink tolua_value = *((TSyngleLink*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TSyngleLink tolua_ret = (TSyngleLink)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TSyngleLink(tolua_ret);

/* getting type */
  char* lua_type = "TSyngleLink";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TSyngleLink));

/* getting type */
  char* lua_type = "TSyngleLink";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<TSyngleLink> */
static int tolua_get_TMDelTList_TSyngleLink__Count(lua_State* tolua_S)
{
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TSyngleLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  TSyngleLink* It = ((TSyngleLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TSyngleLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  TSyngleLink* it = ((TSyngleLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_TSyngleLink__RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TSyngleLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  TSyngleLink* It = ((TSyngleLink*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<TSyngleLink> */
static int tolua_z_List_TMDelTList_TSyngleLink__Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TSyngleLink>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TSyngleLink",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TSyngleLink>* self = (TMDelTList<TSyngleLink>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  TSyngleLink* Item = ((TSyngleLink*)  tolua_tousertype(tolua_S,3,0));
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

/* method: new of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TMDelTList<TIntVec> >* tolua_ret = (TMDelTList<TMDelTList<TIntVec> >*)  new TMDelTList<TMDelTList<TIntVec> >();

/* getting type */
  char* lua_type = "TMDelTList<TMDelTList<TIntVec> >";
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

/* method: new_local of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TMDelTList<TIntVec> >* tolua_ret = (TMDelTList<TMDelTList<TIntVec> >*)  new TMDelTList<TMDelTList<TIntVec> >();

/* getting type */
  char* lua_type = "TMDelTList<TMDelTList<TIntVec> >";
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

/* method: delete of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TMDelTList<TIntVec>* tolua_ret = (TMDelTList<TIntVec>*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TMDelTList<TIntVec>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   TMDelTList<TIntVec>* tolua_ret = (TMDelTList<TIntVec>*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "TMDelTList<TIntVec>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec_____seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TMDelTList<TIntVec> tolua_value = *((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec_____geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TMDelTList<TIntVec> tolua_ret = (TMDelTList<TIntVec>)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TMDelTList<TIntVec>(tolua_ret);

/* getting type */
  char* lua_type = "TMDelTList<TIntVec>";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TMDelTList<TIntVec>));

/* getting type */
  char* lua_type = "TMDelTList<TIntVec>";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_get_TMDelTList_TMDelTList_TIntVec____Count(lua_State* tolua_S)
{
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<TIntVec>* It = ((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<TIntVec>* it = ((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_TMDelTList_TIntVec____RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<TIntVec>* It = ((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<TMDelTList<TIntVec> > */
static int tolua_z_List_TMDelTList_TMDelTList_TIntVec____Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TIntVec> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMDelTList<TIntVec>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TIntVec> >* self = (TMDelTList<TMDelTList<TIntVec> >*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  TMDelTList<TIntVec>* Item = ((TMDelTList<TIntVec>*)  tolua_tousertype(tolua_S,3,0));
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

/* method: new of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TMDelTList<TPolygon> >* tolua_ret = (TMDelTList<TMDelTList<TPolygon> >*)  new TMDelTList<TMDelTList<TPolygon> >();

/* getting type */
  char* lua_type = "TMDelTList<TMDelTList<TPolygon> >";
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

/* method: new_local of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TMDelTList<TPolygon> >* tolua_ret = (TMDelTList<TMDelTList<TPolygon> >*)  new TMDelTList<TMDelTList<TPolygon> >();

/* getting type */
  char* lua_type = "TMDelTList<TMDelTList<TPolygon> >";
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

/* method: delete of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TMDelTList<TPolygon>* tolua_ret = (TMDelTList<TPolygon>*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TMDelTList<TPolygon>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   TMDelTList<TPolygon>* tolua_ret = (TMDelTList<TPolygon>*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "TMDelTList<TPolygon>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon_____seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TMDelTList<TPolygon> tolua_value = *((TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon_____geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TMDelTList<TPolygon> tolua_ret = (TMDelTList<TPolygon>)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TMDelTList<TPolygon>(tolua_ret);

/* getting type */
  char* lua_type = "TMDelTList<TPolygon>";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TMDelTList<TPolygon>));

/* getting type */
  char* lua_type = "TMDelTList<TPolygon>";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_get_TMDelTList_TMDelTList_TPolygon____Count(lua_State* tolua_S)
{
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<TPolygon>* It = ((TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<TPolygon>* it = ((TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_TMDelTList_TPolygon____RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<TPolygon>* It = ((TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<TMDelTList<TPolygon> > */
static int tolua_z_List_TMDelTList_TMDelTList_TPolygon____Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<TPolygon> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMDelTList<TPolygon>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<TPolygon> >* self = (TMDelTList<TMDelTList<TPolygon> >*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  TMDelTList<TPolygon>* Item = ((TMDelTList<TPolygon>*)  tolua_tousertype(tolua_S,3,0));
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

/* method: new of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TMDelTList<int> >* tolua_ret = (TMDelTList<TMDelTList<int> >*)  new TMDelTList<TMDelTList<int> >();

/* getting type */
  char* lua_type = "TMDelTList<TMDelTList<int> >";
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

/* method: new_local of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<TMDelTList<int> >* tolua_ret = (TMDelTList<TMDelTList<int> >*)  new TMDelTList<TMDelTList<int> >();

/* getting type */
  char* lua_type = "TMDelTList<TMDelTList<int> >";
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

/* method: delete of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   TMDelTList<int>* tolua_ret = (TMDelTList<int>*)  self->GetItem(i);

/* getting type */
  char* lua_type = "TMDelTList<int>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   TMDelTList<int>* tolua_ret = (TMDelTList<int>*)  self->GetCycleItem(i);

/* getting type */
  char* lua_type = "TMDelTList<int>";
   tolua_pushusertype(tolua_S,(void*)(tolua_ret),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int_____seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  TMDelTList<int> tolua_value = *((TMDelTList<int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator&[]'",NULL);
#endif
  self->operator[](i) =  tolua_value;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.seti'.",&tolua_err);
 return 0;
#endif
}

/* method: operator[] of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int_____geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TMDelTList<int> tolua_ret = (TMDelTList<int>)  self->operator[](i);
   {
#ifdef __cplusplus
    void* tolua_obj = new TMDelTList<int>(tolua_ret);

/* getting type */
  char* lua_type = "TMDelTList<int>";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TMDelTList<int>));

/* getting type */
  char* lua_type = "TMDelTList<int>";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<TMDelTList<int> > */
static int tolua_get_TMDelTList_TMDelTList_int____Count(lua_State* tolua_S)
{
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Add of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<int>* It = ((TMDelTList<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(It);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<int>* it = ((TMDelTList<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(it);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveOnly of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____RemoveOnly01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_List_TMDelTList_TMDelTList_int____RemoveOnly00(tolua_S);
}

/* method: Delete of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: IndexOf of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____IndexOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  TMDelTList<int>* It = ((TMDelTList<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IndexOf'",NULL);
#endif
  {
   int tolua_ret = (int)  self->IndexOf(It);
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

/* method: Clear of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int id1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int id2 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Exchange'",NULL);
#endif
  {
   self->Exchange(id1,id2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Exchange'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Insert of class  TMDelTList<TMDelTList<int> > */
static int tolua_z_List_TMDelTList_TMDelTList_int____Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<TMDelTList<int> >",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<TMDelTList<int> >* self = (TMDelTList<TMDelTList<int> >*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  TMDelTList<int>* Item = ((TMDelTList<int>*)  tolua_tousertype(tolua_S,3,0));
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

/* Open function */
TOLUA_API int tolua_z_List_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMTList_TIntVec_","TMTList<TIntVec>","TMyObject",tolua_collect_TMTList_TIntVec_);
#else
 tolua_cclass(tolua_S,"TMTList_TIntVec_","TMTList<TIntVec>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMTList_TIntVec_");
 tolua_function(tolua_S,"new",tolua_z_List_TMTList_TIntVec__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMTList_TIntVec__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMTList_TIntVec__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMTList_TIntVec__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMTList_TIntVec__GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMTList_TIntVec___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMTList_TIntVec___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMTList_TIntVec__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMTList_TIntVec__Add00);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMTList_TIntVec__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMTList_TIntVec__IndexOf00);
 tolua_function(tolua_S,"Exists",tolua_z_List_TMTList_TIntVec__Exists00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMTList_TIntVec__Clear00);
 tolua_function(tolua_S,"Consists",tolua_z_List_TMTList_TIntVec__Consists00);
 tolua_function(tolua_S,"Same",tolua_z_List_TMTList_TIntVec__Same00);
 tolua_function(tolua_S,"Assign",tolua_z_List_TMTList_TIntVec__Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMTList_TIntVec__Invert00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMTList_TIntVec__Exchange00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMTList_TElement_","TMTList<TElement>","TMyObject",tolua_collect_TMTList_TElement_);
#else
 tolua_cclass(tolua_S,"TMTList_TElement_","TMTList<TElement>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMTList_TElement_");
 tolua_function(tolua_S,"new",tolua_z_List_TMTList_TElement__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMTList_TElement__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMTList_TElement__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMTList_TElement__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMTList_TElement__GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMTList_TElement___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMTList_TElement___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMTList_TElement__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMTList_TElement__Add00);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMTList_TElement__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMTList_TElement__IndexOf00);
 tolua_function(tolua_S,"Exists",tolua_z_List_TMTList_TElement__Exists00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMTList_TElement__Clear00);
 tolua_function(tolua_S,"Consists",tolua_z_List_TMTList_TElement__Consists00);
 tolua_function(tolua_S,"Same",tolua_z_List_TMTList_TElement__Same00);
 tolua_function(tolua_S,"Assign",tolua_z_List_TMTList_TElement__Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMTList_TElement__Invert00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMTList_TElement__Exchange00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMTList_TLink_","TMTList<TLink>","TMyObject",tolua_collect_TMTList_TLink_);
#else
 tolua_cclass(tolua_S,"TMTList_TLink_","TMTList<TLink>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMTList_TLink_");
 tolua_function(tolua_S,"new",tolua_z_List_TMTList_TLink__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMTList_TLink__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMTList_TLink__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMTList_TLink__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMTList_TLink__GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMTList_TLink___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMTList_TLink___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMTList_TLink__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMTList_TLink__Add00);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMTList_TLink__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMTList_TLink__IndexOf00);
 tolua_function(tolua_S,"Exists",tolua_z_List_TMTList_TLink__Exists00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMTList_TLink__Clear00);
 tolua_function(tolua_S,"Consists",tolua_z_List_TMTList_TLink__Consists00);
 tolua_function(tolua_S,"Same",tolua_z_List_TMTList_TLink__Same00);
 tolua_function(tolua_S,"Assign",tolua_z_List_TMTList_TLink__Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMTList_TLink__Invert00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMTList_TLink__Exchange00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMTList_TPolygon_","TMTList<TPolygon>","TMyObject",tolua_collect_TMTList_TPolygon_);
#else
 tolua_cclass(tolua_S,"TMTList_TPolygon_","TMTList<TPolygon>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMTList_TPolygon_");
 tolua_function(tolua_S,"new",tolua_z_List_TMTList_TPolygon__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMTList_TPolygon__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMTList_TPolygon__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMTList_TPolygon__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMTList_TPolygon__GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMTList_TPolygon___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMTList_TPolygon___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMTList_TPolygon__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMTList_TPolygon__Add00);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMTList_TPolygon__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMTList_TPolygon__IndexOf00);
 tolua_function(tolua_S,"Exists",tolua_z_List_TMTList_TPolygon__Exists00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMTList_TPolygon__Clear00);
 tolua_function(tolua_S,"Consists",tolua_z_List_TMTList_TPolygon__Consists00);
 tolua_function(tolua_S,"Same",tolua_z_List_TMTList_TPolygon__Same00);
 tolua_function(tolua_S,"Assign",tolua_z_List_TMTList_TPolygon__Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMTList_TPolygon__Invert00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMTList_TPolygon__Exchange00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMTList_THoledPolygon_","TMTList<THoledPolygon>","TMyObject",tolua_collect_TMTList_THoledPolygon_);
#else
 tolua_cclass(tolua_S,"TMTList_THoledPolygon_","TMTList<THoledPolygon>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMTList_THoledPolygon_");
 tolua_function(tolua_S,"new",tolua_z_List_TMTList_THoledPolygon__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMTList_THoledPolygon__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMTList_THoledPolygon__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMTList_THoledPolygon__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMTList_THoledPolygon__GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMTList_THoledPolygon___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMTList_THoledPolygon___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMTList_THoledPolygon__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMTList_THoledPolygon__Add00);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMTList_THoledPolygon__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMTList_THoledPolygon__IndexOf00);
 tolua_function(tolua_S,"Exists",tolua_z_List_TMTList_THoledPolygon__Exists00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMTList_THoledPolygon__Clear00);
 tolua_function(tolua_S,"Consists",tolua_z_List_TMTList_THoledPolygon__Consists00);
 tolua_function(tolua_S,"Same",tolua_z_List_TMTList_THoledPolygon__Same00);
 tolua_function(tolua_S,"Assign",tolua_z_List_TMTList_THoledPolygon__Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMTList_THoledPolygon__Invert00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMTList_THoledPolygon__Exchange00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMTList_TMetaElement_","TMTList<TMetaElement>","TMyObject",tolua_collect_TMTList_TMetaElement_);
#else
 tolua_cclass(tolua_S,"TMTList_TMetaElement_","TMTList<TMetaElement>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMTList_TMetaElement_");
 tolua_function(tolua_S,"new",tolua_z_List_TMTList_TMetaElement__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMTList_TMetaElement__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMTList_TMetaElement__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMTList_TMetaElement__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMTList_TMetaElement__GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMTList_TMetaElement___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMTList_TMetaElement___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMTList_TMetaElement__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMTList_TMetaElement__Add00);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMTList_TMetaElement__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMTList_TMetaElement__IndexOf00);
 tolua_function(tolua_S,"Exists",tolua_z_List_TMTList_TMetaElement__Exists00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMTList_TMetaElement__Clear00);
 tolua_function(tolua_S,"Consists",tolua_z_List_TMTList_TMetaElement__Consists00);
 tolua_function(tolua_S,"Same",tolua_z_List_TMTList_TMetaElement__Same00);
 tolua_function(tolua_S,"Assign",tolua_z_List_TMTList_TMetaElement__Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMTList_TMetaElement__Invert00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMTList_TMetaElement__Exchange00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMTList_TMetaNode_","TMTList<TMetaNode>","TMyObject",tolua_collect_TMTList_TMetaNode_);
#else
 tolua_cclass(tolua_S,"TMTList_TMetaNode_","TMTList<TMetaNode>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMTList_TMetaNode_");
 tolua_function(tolua_S,"new",tolua_z_List_TMTList_TMetaNode__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMTList_TMetaNode__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMTList_TMetaNode__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMTList_TMetaNode__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMTList_TMetaNode__GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMTList_TMetaNode___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMTList_TMetaNode___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMTList_TMetaNode__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMTList_TMetaNode__Add00);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMTList_TMetaNode__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMTList_TMetaNode__IndexOf00);
 tolua_function(tolua_S,"Exists",tolua_z_List_TMTList_TMetaNode__Exists00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMTList_TMetaNode__Clear00);
 tolua_function(tolua_S,"Consists",tolua_z_List_TMTList_TMetaNode__Consists00);
 tolua_function(tolua_S,"Same",tolua_z_List_TMTList_TMetaNode__Same00);
 tolua_function(tolua_S,"Assign",tolua_z_List_TMTList_TMetaNode__Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMTList_TMetaNode__Invert00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMTList_TMetaNode__Exchange00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMTList_TMDelTList_int___","TMTList<TMDelTList<int> >","TMyObject",tolua_collect_TMTList_TMDelTList_int___);
#else
 tolua_cclass(tolua_S,"TMTList_TMDelTList_int___","TMTList<TMDelTList<int> >","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMTList_TMDelTList_int___");
 tolua_function(tolua_S,"new",tolua_z_List_TMTList_TMDelTList_int____new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMTList_TMDelTList_int____new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMTList_TMDelTList_int____new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMTList_TMDelTList_int____delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMTList_TMDelTList_int____GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMTList_TMDelTList_int_____seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMTList_TMDelTList_int_____geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMTList_TMDelTList_int____Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMTList_TMDelTList_int____Add00);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMTList_TMDelTList_int____Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMTList_TMDelTList_int____IndexOf00);
 tolua_function(tolua_S,"Exists",tolua_z_List_TMTList_TMDelTList_int____Exists00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMTList_TMDelTList_int____Clear00);
 tolua_function(tolua_S,"Consists",tolua_z_List_TMTList_TMDelTList_int____Consists00);
 tolua_function(tolua_S,"Same",tolua_z_List_TMTList_TMDelTList_int____Same00);
 tolua_function(tolua_S,"Assign",tolua_z_List_TMTList_TMDelTList_int____Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMTList_TMDelTList_int____Invert00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMTList_TMDelTList_int____Exchange00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_TIntVec_","TMDelTList<TIntVec>","TMyObject",tolua_collect_TMDelTList_TIntVec_);
#else
 tolua_cclass(tolua_S,"TMDelTList_TIntVec_","TMDelTList<TIntVec>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_TIntVec_");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_TIntVec__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_TIntVec__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_TIntVec__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_TIntVec__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_TIntVec__GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_TIntVec__GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_TIntVec___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_TIntVec___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_TIntVec__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_TIntVec__Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TIntVec__RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TIntVec__RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_TIntVec__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_TIntVec__IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_TIntVec__Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_TIntVec__Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_TIntVec__Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_TIntVec__Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_TLuaRoofCut_","TMDelTList<TLuaRoofCut>","TMyObject",tolua_collect_TMDelTList_TLuaRoofCut_);
#else
 tolua_cclass(tolua_S,"TMDelTList_TLuaRoofCut_","TMDelTList<TLuaRoofCut>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_TLuaRoofCut_");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_TLuaRoofCut__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_TLuaRoofCut__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_TLuaRoofCut__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_TLuaRoofCut__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_TLuaRoofCut__GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_TLuaRoofCut__GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_TLuaRoofCut___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_TLuaRoofCut___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_TLuaRoofCut__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_TLuaRoofCut__Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TLuaRoofCut__RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TLuaRoofCut__RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_TLuaRoofCut__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_TLuaRoofCut__IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_TLuaRoofCut__Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_TLuaRoofCut__Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_TLuaRoofCut__Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_TLuaRoofCut__Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_TPolygon_","TMDelTList<TPolygon>","TMyObject",tolua_collect_TMDelTList_TPolygon_);
#else
 tolua_cclass(tolua_S,"TMDelTList_TPolygon_","TMDelTList<TPolygon>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_TPolygon_");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_TPolygon__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_TPolygon__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_TPolygon__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_TPolygon__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_TPolygon__GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_TPolygon__GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_TPolygon___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_TPolygon___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_TPolygon__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_TPolygon__Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TPolygon__RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TPolygon__RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_TPolygon__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_TPolygon__IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_TPolygon__Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_TPolygon__Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_TPolygon__Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_TPolygon__Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_THoledPolygon_","TMDelTList<THoledPolygon>","TMyObject",tolua_collect_TMDelTList_THoledPolygon_);
#else
 tolua_cclass(tolua_S,"TMDelTList_THoledPolygon_","TMDelTList<THoledPolygon>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_THoledPolygon_");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_THoledPolygon__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_THoledPolygon__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_THoledPolygon__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_THoledPolygon__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_THoledPolygon__GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_THoledPolygon__GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_THoledPolygon___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_THoledPolygon___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_THoledPolygon__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_THoledPolygon__Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_THoledPolygon__RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_THoledPolygon__RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_THoledPolygon__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_THoledPolygon__IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_THoledPolygon__Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_THoledPolygon__Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_THoledPolygon__Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_THoledPolygon__Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_T3DScope_","TMDelTList<T3DScope>","TMyObject",tolua_collect_TMDelTList_T3DScope_);
#else
 tolua_cclass(tolua_S,"TMDelTList_T3DScope_","TMDelTList<T3DScope>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_T3DScope_");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_T3DScope__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_T3DScope__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_T3DScope__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_T3DScope__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_T3DScope__GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_T3DScope__GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_T3DScope___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_T3DScope___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_T3DScope__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_T3DScope__Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_T3DScope__RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_T3DScope__RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_T3DScope__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_T3DScope__IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_T3DScope__Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_T3DScope__Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_T3DScope__Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_T3DScope__Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_TRoutePoint_","TMDelTList<TRoutePoint>","TMyObject",tolua_collect_TMDelTList_TRoutePoint_);
#else
 tolua_cclass(tolua_S,"TMDelTList_TRoutePoint_","TMDelTList<TRoutePoint>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_TRoutePoint_");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_TRoutePoint__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_TRoutePoint__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_TRoutePoint__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_TRoutePoint__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_TRoutePoint__GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_TRoutePoint__GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_TRoutePoint___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_TRoutePoint___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_TRoutePoint__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_TRoutePoint__Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TRoutePoint__RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TRoutePoint__RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_TRoutePoint__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_TRoutePoint__IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_TRoutePoint__Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_TRoutePoint__Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_TRoutePoint__Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_TRoutePoint__Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_TObjectAttributePreSet_","TMDelTList<TObjectAttributePreSet>","TMyObject",tolua_collect_TMDelTList_TObjectAttributePreSet_);
#else
 tolua_cclass(tolua_S,"TMDelTList_TObjectAttributePreSet_","TMDelTList<TObjectAttributePreSet>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_TObjectAttributePreSet_");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_TObjectAttributePreSet__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_TObjectAttributePreSet__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_TObjectAttributePreSet__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_TObjectAttributePreSet__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_TObjectAttributePreSet__GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_TObjectAttributePreSet__GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_TObjectAttributePreSet___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_TObjectAttributePreSet___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_TObjectAttributePreSet__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_TObjectAttributePreSet__Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TObjectAttributePreSet__RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TObjectAttributePreSet__RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_TObjectAttributePreSet__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_TObjectAttributePreSet__IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_TObjectAttributePreSet__Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_TObjectAttributePreSet__Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_TObjectAttributePreSet__Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_TObjectAttributePreSet__Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_TSyngleLink_","TMDelTList<TSyngleLink>","TMyObject",tolua_collect_TMDelTList_TSyngleLink_);
#else
 tolua_cclass(tolua_S,"TMDelTList_TSyngleLink_","TMDelTList<TSyngleLink>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_TSyngleLink_");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_TSyngleLink__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_TSyngleLink__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_TSyngleLink__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_TSyngleLink__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_TSyngleLink__GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_TSyngleLink__GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_TSyngleLink___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_TSyngleLink___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_TSyngleLink__Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_TSyngleLink__Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TSyngleLink__RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TSyngleLink__RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_TSyngleLink__Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_TSyngleLink__IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_TSyngleLink__Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_TSyngleLink__Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_TSyngleLink__Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_TSyngleLink__Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_TMDelTList_TIntVec___","TMDelTList<TMDelTList<TIntVec> >","TMyObject",tolua_collect_TMDelTList_TMDelTList_TIntVec___);
#else
 tolua_cclass(tolua_S,"TMDelTList_TMDelTList_TIntVec___","TMDelTList<TMDelTList<TIntVec> >","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_TMDelTList_TIntVec___");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_TMDelTList_TIntVec____new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_TMDelTList_TIntVec____new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_TMDelTList_TIntVec____new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_TMDelTList_TIntVec____delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_TMDelTList_TIntVec____GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_TMDelTList_TIntVec____GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_TMDelTList_TIntVec_____seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_TMDelTList_TIntVec_____geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_TMDelTList_TIntVec____Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_TMDelTList_TIntVec____Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TMDelTList_TIntVec____RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TMDelTList_TIntVec____RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_TMDelTList_TIntVec____Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_TMDelTList_TIntVec____IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_TMDelTList_TIntVec____Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_TMDelTList_TIntVec____Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_TMDelTList_TIntVec____Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_TMDelTList_TIntVec____Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_TMDelTList_TPolygon___","TMDelTList<TMDelTList<TPolygon> >","TMyObject",tolua_collect_TMDelTList_TMDelTList_TPolygon___);
#else
 tolua_cclass(tolua_S,"TMDelTList_TMDelTList_TPolygon___","TMDelTList<TMDelTList<TPolygon> >","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_TMDelTList_TPolygon___");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_TMDelTList_TPolygon____new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_TMDelTList_TPolygon____new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_TMDelTList_TPolygon____new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_TMDelTList_TPolygon____delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_TMDelTList_TPolygon____GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_TMDelTList_TPolygon____GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_TMDelTList_TPolygon_____seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_TMDelTList_TPolygon_____geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_TMDelTList_TPolygon____Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_TMDelTList_TPolygon____Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TMDelTList_TPolygon____RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TMDelTList_TPolygon____RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_TMDelTList_TPolygon____Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_TMDelTList_TPolygon____IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_TMDelTList_TPolygon____Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_TMDelTList_TPolygon____Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_TMDelTList_TPolygon____Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_TMDelTList_TPolygon____Insert00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_TMDelTList_int___","TMDelTList<TMDelTList<int> >","TMyObject",tolua_collect_TMDelTList_TMDelTList_int___);
#else
 tolua_cclass(tolua_S,"TMDelTList_TMDelTList_int___","TMDelTList<TMDelTList<int> >","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_TMDelTList_int___");
 tolua_function(tolua_S,"new",tolua_z_List_TMDelTList_TMDelTList_int____new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_TMDelTList_TMDelTList_int____new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_TMDelTList_TMDelTList_int____new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_TMDelTList_TMDelTList_int____delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_TMDelTList_TMDelTList_int____GetItem00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_TMDelTList_TMDelTList_int____GetCycleItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_TMDelTList_TMDelTList_int_____seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_TMDelTList_TMDelTList_int_____geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_TMDelTList_int____Count,NULL);
 tolua_function(tolua_S,"Add",tolua_z_List_TMDelTList_TMDelTList_int____Add00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TMDelTList_int____RemoveOnly00);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_TMDelTList_TMDelTList_int____RemoveOnly01);
 tolua_function(tolua_S,"Delete",tolua_z_List_TMDelTList_TMDelTList_int____Delete00);
 tolua_function(tolua_S,"IndexOf",tolua_z_List_TMDelTList_TMDelTList_int____IndexOf00);
 tolua_function(tolua_S,"Clear",tolua_z_List_TMDelTList_TMDelTList_int____Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_TMDelTList_TMDelTList_int____Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_TMDelTList_TMDelTList_int____Invert00);
 tolua_function(tolua_S,"Insert",tolua_z_List_TMDelTList_TMDelTList_int____Insert00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
