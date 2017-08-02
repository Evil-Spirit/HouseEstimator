/*
** Lua binding: z_List_int
** Generated automatically by tolua++-1.0.3 on 10/17/04 18:02:51.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h" 

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_z_List_int_open (lua_State* tolua_S);
#include "Bind.h"

#include <vcl.h>
#include "Usefuls.h"
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop

#define LUA_N = 1<<31;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_TMTList_int_ (lua_State* tolua_S)
{
 TMTList<int>* self = (TMTList<int>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TMDelTList_int_ (lua_State* tolua_S)
{
 TMDelTList<int>* self = (TMDelTList<int>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TMTList<int>");
 tolua_usertype(tolua_S,"TMDelTList<int>");
 tolua_usertype(tolua_S,"TMyObject");
}

/* method: new of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<int>* tolua_ret = (TMTList<int>*)  new TMTList<int>();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TMTList<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMTList<int>* tolua_ret = (TMTList<int>*)  new TMTList<int>();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TMTList<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   int tolua_ret = (int)  *(self->GetItem(i));
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  int tolua_value = ((int)  tolua_tonumber(tolua_S,3,0));
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

/* method: operator[] of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   int tolua_ret = (int)  self->operator[](i);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMTList<int> */
static int tolua_get_TMTList_int__Count(lua_State* tolua_S)
{
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: Delete of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Clear of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Consists of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__Consists00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<int>* L = ((TMTList<int>*)  tolua_tousertype(tolua_S,2,0));
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

/* method: Same of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__Same00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<int>* L = ((TMTList<int>*)  tolua_tousertype(tolua_S,2,0));
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

/* method: Assign of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
  TMTList<int>* L = ((TMTList<int>*)  tolua_tousertype(tolua_S,2,0));
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

/* method: Invert of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMTList<int> */
static int tolua_z_List_int_TMTList_int__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMTList<int>* self = (TMTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<int>* tolua_ret = (TMDelTList<int>*)  new TMDelTList<int>();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TMDelTList<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TMDelTList<int>* tolua_ret = (TMDelTList<int>*)  new TMDelTList<int>();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TMDelTList<int>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetItem of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__GetItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItem'",NULL);
#endif
  {
   int tolua_ret = (int)  *(self->GetItem(i));
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItem'.",&tolua_err);
 return 0;
#endif
}

/* method: operator&[] of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int___seti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
  int tolua_value = ((int)  tolua_tonumber(tolua_S,3,0));
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

/* method: operator[] of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int___geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   int tolua_ret = (int)  self->operator[](i);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.geti'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCycleItem of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__GetCycleItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCycleItem'",NULL);
#endif
  {
   int tolua_ret = (int)  *(self->GetCycleItem(i));
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCycleItem'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TMDelTList<int> */
static int tolua_get_TMDelTList_int__Count(lua_State* tolua_S)
{
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: RemoveOnly of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__RemoveOnly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveOnly'",NULL);
#endif
  {
   self->RemoveOnly(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveOnly'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Clear of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Exchange of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__Exchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Invert of class  TMDelTList<int> */
static int tolua_z_List_int_TMDelTList_int__Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TMDelTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TMDelTList<int>* self = (TMDelTList<int>*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_z_List_int_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMTList_int_","TMTList<int>","TMyObject",tolua_collect_TMTList_int_);
#else
 tolua_cclass(tolua_S,"TMTList_int_","TMTList<int>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMTList_int_");
 tolua_function(tolua_S,"new",tolua_z_List_int_TMTList_int__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_int_TMTList_int__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_int_TMTList_int__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_int_TMTList_int__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_int_TMTList_int__GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_int_TMTList_int___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_int_TMTList_int___geti00);
 tolua_variable(tolua_S,"Count",tolua_get_TMTList_int__Count,NULL);
 tolua_function(tolua_S,"Delete",tolua_z_List_int_TMTList_int__Delete00);
 tolua_function(tolua_S,"Clear",tolua_z_List_int_TMTList_int__Clear00);
 tolua_function(tolua_S,"Consists",tolua_z_List_int_TMTList_int__Consists00);
 tolua_function(tolua_S,"Same",tolua_z_List_int_TMTList_int__Same00);
 tolua_function(tolua_S,"Assign",tolua_z_List_int_TMTList_int__Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_List_int_TMTList_int__Invert00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_int_TMTList_int__Exchange00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TMDelTList_int_","TMDelTList<int>","TMyObject",tolua_collect_TMDelTList_int_);
#else
 tolua_cclass(tolua_S,"TMDelTList_int_","TMDelTList<int>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TMDelTList_int_");
 tolua_function(tolua_S,"new",tolua_z_List_int_TMDelTList_int__new00);
 tolua_function(tolua_S,"new_local",tolua_z_List_int_TMDelTList_int__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_List_int_TMDelTList_int__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_List_int_TMDelTList_int__delete00);
 tolua_function(tolua_S,"GetItem",tolua_z_List_int_TMDelTList_int__GetItem00);
 tolua_function(tolua_S,".seti",tolua_z_List_int_TMDelTList_int___seti00);
 tolua_function(tolua_S,".geti",tolua_z_List_int_TMDelTList_int___geti00);
 tolua_function(tolua_S,"GetCycleItem",tolua_z_List_int_TMDelTList_int__GetCycleItem00);
 tolua_variable(tolua_S,"Count",tolua_get_TMDelTList_int__Count,NULL);
 tolua_function(tolua_S,"RemoveOnly",tolua_z_List_int_TMDelTList_int__RemoveOnly00);
 tolua_function(tolua_S,"Delete",tolua_z_List_int_TMDelTList_int__Delete00);
 tolua_function(tolua_S,"Clear",tolua_z_List_int_TMDelTList_int__Clear00);
 tolua_function(tolua_S,"Exchange",tolua_z_List_int_TMDelTList_int__Exchange00);
 tolua_function(tolua_S,"Invert",tolua_z_List_int_TMDelTList_int__Invert00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
