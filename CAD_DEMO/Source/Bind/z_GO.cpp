/*
** Lua binding: z_GO
** Generated automatically by tolua++-1.0.3 on 01/13/05 12:34:02.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_z_GO_open (lua_State* tolua_S);

#include <vcl.h>
#include "Usefuls.h"                 
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
#include "GeomObjV.h"
#define LUA_N = 1<<31;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_TGCut (lua_State* tolua_S)
{
 TGCut* self = (TGCut*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TGPolygon (lua_State* tolua_S)
{
 TGPolygon* self = (TGPolygon*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TGPoint (lua_State* tolua_S)
{
 TGPoint* self = (TGPoint*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TGeomObject (lua_State* tolua_S)
{
 TGeomObject* self = (TGeomObject*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TMTList<int>");
 tolua_usertype(tolua_S,"TGPoint");
 tolua_usertype(tolua_S,"TMyObject");
 tolua_usertype(tolua_S,"TGeomObject");
 tolua_usertype(tolua_S,"TIntVec");
 tolua_usertype(tolua_S,"TFreeUnusedType");
 tolua_usertype(tolua_S,"__int16");
 tolua_usertype(tolua_S,"TGPolygon");
 tolua_usertype(tolua_S,"TMTList<TGCut>");
 tolua_usertype(tolua_S,"TGCut");
}

/* method: new of class  TGPoint */
static int tolua_z_GO_TGPoint_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TGPoint* tolua_ret = (TGPoint*)  new TGPoint();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TGPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TGPoint */
static int tolua_z_GO_TGPoint_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TGPoint* tolua_ret = (TGPoint*)  new TGPoint();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TGPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TGPoint */
static int tolua_z_GO_TGPoint_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGPoint",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TIntVec tolua_var_1 = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
  {
   TGPoint* tolua_ret = (TGPoint*)  new TGPoint(tolua_var_1);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TGPoint");
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_GO_TGPoint_new00(tolua_S);
}

/* method: new_local of class  TGPoint */
static int tolua_z_GO_TGPoint_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGPoint",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TIntVec tolua_var_1 = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
  {
   TGPoint* tolua_ret = (TGPoint*)  new TGPoint(tolua_var_1);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TGPoint");
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_GO_TGPoint_new00_local(tolua_S);
}

/* method: delete of class  TGPoint */
static int tolua_z_GO_TGPoint_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGPoint* self = (TGPoint*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Point of class  TGPoint */
static int tolua_get_TGPoint_Point(lua_State* tolua_S)
{
  TGPoint* self = (TGPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Point'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)&(self->Point),"TIntVec");
 return 1;
}

/* set function: Point of class  TGPoint */
static int tolua_set_TGPoint_Point(lua_State* tolua_S)
{
  TGPoint* self = (TGPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Point'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TIntVec",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Point = *((TIntVec*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: GetCut of class  TGPoint */
static int tolua_z_GO_TGPoint_GetCut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGPoint",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGPoint* self = (TGPoint*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCut'",NULL);
#endif
  {
   TGCut& tolua_ret = (TGCut&)  self->GetCut(index);
   tolua_pushusertype(tolua_S,(void*)&tolua_ret,"TGCut");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCut'.",&tolua_err);
 return 0;
#endif
}

/* get function: CutsCount of class  TGPoint */
static int tolua_get_TGPoint_CutsCount(lua_State* tolua_S)
{
  TGPoint* self = (TGPoint*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CutsCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CutsCount);
 return 1;
}

/* method: new of class  TGCut */
static int tolua_z_GO_TGCut_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TGCut* tolua_ret = (TGCut*)  new TGCut();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TGCut");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TGCut */
static int tolua_z_GO_TGCut_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TGCut* tolua_ret = (TGCut*)  new TGCut();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TGCut");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TGCut */
static int tolua_z_GO_TGCut_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Tag of class  TGCut */
static int tolua_get_TGCut_Tag(lua_State* tolua_S)
{
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Tag'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Tag);
 return 1;
}

/* set function: Tag of class  TGCut */
static int tolua_set_TGCut_Tag(lua_State* tolua_S)
{
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Tag'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Tag = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Src of class  TGCut */
static int tolua_get_TGCut_Src_ptr(lua_State* tolua_S)
{
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Src'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)(self->Src),"TGPoint");
 return 1;
}

/* set function: Src of class  TGCut */
static int tolua_set_TGCut_Src_ptr(lua_State* tolua_S)
{
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Src'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TGPoint",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Src = ((TGPoint*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Dst of class  TGCut */
static int tolua_get_TGCut_Dst_ptr(lua_State* tolua_S)
{
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Dst'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)(self->Dst),"TGPoint");
 return 1;
}

/* set function: Dst of class  TGCut */
static int tolua_set_TGCut_Dst_ptr(lua_State* tolua_S)
{
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Dst'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TGPoint",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Dst = ((TGPoint*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Left of class  TGCut */
static int tolua_get_TGCut_Left_ptr(lua_State* tolua_S)
{
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Left'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)(self->Left),"TGPolygon");
 return 1;
}

/* get function: Right of class  TGCut */
static int tolua_get_TGCut_Right_ptr(lua_State* tolua_S)
{
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Right'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)(self->Right),"TGPolygon");
 return 1;
}

/* method: CanConnect of class  TGCut */
static int tolua_z_GO_TGCut_CanConnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGCut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
  const TGCut* cut = ((const TGCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CanConnect'",NULL);
#endif
  {
   TGPoint* tolua_ret = (TGPoint*)  self->CanConnect(*cut);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TGPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CanConnect'.",&tolua_err);
 return 0;
#endif
}

/* method: IsOneFreeSide of class  TGCut */
/*static int tolua_z_GO_TGCut_IsOneFreeSide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsOneFreeSide'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsOneFreeSide();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsOneFreeSide'.",&tolua_err);
 return 0;
#endif
} */

/* method: Equal of class  TGCut */
static int tolua_z_GO_TGCut_Equal00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TGCut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TGCut* self = (const TGCut*)  tolua_tousertype(tolua_S,1,0);
  const TGCut* other = ((const TGCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Equal'",NULL);
#endif
  {
	 bool tolua_ret = (bool)  self->Equals(*other);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Equal'.",&tolua_err);
 return 0;
#endif
}

/* method: ConsistsDstAndSrc of class  TGCut */
static int tolua_z_GO_TGCut_ConsistsDstAndSrc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGCut",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TGPoint",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TGPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
  TGPoint* R1 = ((TGPoint*)  tolua_tousertype(tolua_S,2,0));
  TGPoint* R2 = ((TGPoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ConsistsDstAndSrc'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ConsistsDstAndSrc(R1,R2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ConsistsDstAndSrc'.",&tolua_err);
 return 0;
#endif
}

/* method: SameDirection of class  TGCut */
/*
static int tolua_z_GO_TGCut_SameDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
		 !tolua_isusertype(tolua_S,1,"TGCut",0,&tolua_err) ||
		 !tolua_isusertype(tolua_S,2,"const TGCut",0,&tolua_err) ||
		 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
	goto tolua_lerror;
 else
#endif
 {
	TGCut* self = (TGCut*)  tolua_tousertype(tolua_S,1,0);
	const TGCut* cut = ((const TGCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
	if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SameDirection'",NULL);
#endif
	{
	 bool tolua_ret = (bool)  self->SameDirection(*cut);
	 tolua_pushboolean(tolua_S,(bool)tolua_ret);
	}
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SameDirection'.",&tolua_err);
 return 0;
#endif
}
*/

/* method: new of class  TGPolygon */
static int tolua_z_GO_TGPolygon_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TGPolygon* tolua_ret = (TGPolygon*)  new TGPolygon();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TGPolygon");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TGPolygon */
static int tolua_z_GO_TGPolygon_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TGPolygon* tolua_ret = (TGPolygon*)  new TGPolygon();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TGPolygon");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TGPolygon */
static int tolua_z_GO_TGPolygon_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGPolygon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGPolygon* self = (TGPolygon*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Tag of class  TGPolygon */
static int tolua_get_TGPolygon_Tag(lua_State* tolua_S)
{
  TGPolygon* self = (TGPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Tag'",NULL);
#endif
  tolua_pushnumber(tolua_S,self->Tag);
 return 1;
}

/* set function: Tag of class  TGPolygon */
static int tolua_set_TGPolygon_Tag(lua_State* tolua_S)
{
  TGPolygon* self = (TGPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Tag'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Tag = ((__int16)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: GetPoint of class  TGPolygon */
static int tolua_z_GO_TGPolygon_GetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGPolygon* self = (TGPolygon*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPoint'",NULL);
#endif
  {
   TGPoint& tolua_ret = (TGPoint&)  self->GetPoint(index);
   tolua_pushusertype(tolua_S,(void*)&tolua_ret,"TGPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPoint'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCut of class  TGPolygon */
static int tolua_z_GO_TGPolygon_GetCut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGPolygon* self = (TGPolygon*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCut'",NULL);
#endif
  {
   TGCut& tolua_ret = (TGCut&)  self->GetCut(index);
   tolua_pushusertype(tolua_S,(void*)&tolua_ret,"TGCut");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCut'.",&tolua_err);
 return 0;
#endif
}

/* method: AddCut of class  TGPolygon */
static int tolua_z_GO_TGPolygon_AddCut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGPolygon* self = (TGPolygon*)  tolua_tousertype(tolua_S,1,0);
  TGCut* tolua_var_2 = ((TGCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCut'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddCut(tolua_var_2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCut'.",&tolua_err);
 return 0;
#endif
}

/* method: RemoveCut of class  TGPolygon */
static int tolua_z_GO_TGPolygon_RemoveCut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGPolygon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGPolygon* self = (TGPolygon*)  tolua_tousertype(tolua_S,1,0);
  TGCut* cut = ((TGCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveCut'",NULL);
#endif
  {
	 self->DeleteCut(cut);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveCut'.",&tolua_err);
 return 0;
#endif
}

/* method: DeleteCut of class  TGPolygon */
static int tolua_z_GO_TGPolygon_DeleteCut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGPolygon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGPolygon* self = (TGPolygon*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteCut'",NULL);
#endif
  {
   self->DeleteCut(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteCut'.",&tolua_err);
 return 0;
#endif
}

/* get function: Count of class  TGPolygon */
static int tolua_get_TGPolygon_Count(lua_State* tolua_S)
{
  TGPolygon* self = (TGPolygon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* method: new of class  TGeomObject */
static int tolua_z_GO_TGeomObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TGeomObject* tolua_ret = (TGeomObject*)  new TGeomObject();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TGeomObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TGeomObject */
static int tolua_z_GO_TGeomObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TGeomObject* tolua_ret = (TGeomObject*)  new TGeomObject();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TGeomObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TGeomObject */
static int tolua_z_GO_TGeomObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetVertex of class  TGeomObject */
static int tolua_z_GO_TGeomObject_GetVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TGeomObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TGeomObject* self = (const TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVertex'",NULL);
#endif
  {
   TGPoint& tolua_ret = (TGPoint&)  self->GetVertex(index);
   tolua_pushusertype(tolua_S,(void*)&tolua_ret,"TGPoint");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVertex'.",&tolua_err);
 return 0;
#endif
}

/* method: GetCut of class  TGeomObject */
static int tolua_z_GO_TGeomObject_GetCut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TGeomObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TGeomObject* self = (const TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCut'",NULL);
#endif
  {
   TGCut& tolua_ret = (TGCut&)  self->GetCut(index);
   tolua_pushusertype(tolua_S,(void*)&tolua_ret,"TGCut");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCut'.",&tolua_err);
 return 0;
#endif
}

/* method: GetPolygon of class  TGeomObject */
static int tolua_z_GO_TGeomObject_GetPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const TGeomObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const TGeomObject* self = (const TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPolygon'",NULL);
#endif
  {
   TGPolygon& tolua_ret = (TGPolygon&)  self->GetPolygon(index);
   tolua_pushusertype(tolua_S,(void*)&tolua_ret,"TGPolygon");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPolygon'.",&tolua_err);
 return 0;
#endif
}

/* get function: CutsCount of class  TGeomObject */
static int tolua_get_TGeomObject_CutsCount(lua_State* tolua_S)
{
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CutsCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CutsCount);
 return 1;
}

/* get function: PolygonsCount of class  TGeomObject */
static int tolua_get_TGeomObject_PolygonsCount(lua_State* tolua_S)
{
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PolygonsCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PolygonsCount);
 return 1;
}

/* get function: VertexCount of class  TGeomObject */
static int tolua_get_TGeomObject_VertexCount(lua_State* tolua_S)
{
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'VertexCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->VertexCount);
 return 1;
}

/* method: GetCutByPoints of class  TGeomObject */
static int tolua_z_GO_TGeomObject_GetCutByPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TGPoint",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TGPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  TGPoint* P1 = ((TGPoint*)  tolua_tousertype(tolua_S,2,0));
  TGPoint* P2 = ((TGPoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCutByPoints'",NULL);
#endif
  {
   TGCut* tolua_ret = (TGCut*)  self->GetCutByPoints(P1,P2);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TGCut");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCutByPoints'.",&tolua_err);
 return 0;
#endif
}

/* method: AddPoint of class  TGeomObject */
static int tolua_z_GO_TGeomObject_AddPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TIntVec",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  const TIntVec* v = ((const TIntVec*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPoint'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddPoint(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPoint'.",&tolua_err);
 return 0;
#endif
}

/* method: AddPoint of class  TGeomObject */
static int tolua_z_GO_TGeomObject_AddPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TGPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  const TGPoint* p = ((const TGPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPoint'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddPoint(*p);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_GO_TGeomObject_AddPoint00(tolua_S);
}

/* method: AddCut of class  TGeomObject */
static int tolua_z_GO_TGeomObject_AddCut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  const TGCut* c = ((const TGCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCut'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddCut(*c);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCut'.",&tolua_err);
 return 0;
#endif
}

/* method: AddCut of class  TGeomObject */
static int tolua_z_GO_TGeomObject_AddCut01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  int tolua_var_3 = ((int)  tolua_tonumber(tolua_S,2,0));
  int tolua_var_4 = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCut'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddCut(tolua_var_3,tolua_var_4);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_GO_TGeomObject_AddCut00(tolua_S);
}

/* method: AddCut of class  TGeomObject */
static int tolua_z_GO_TGeomObject_AddCut02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TGPoint",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TGPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  TGPoint* tolua_var_5 = ((TGPoint*)  tolua_tousertype(tolua_S,2,0));
  TGPoint* tolua_var_6 = ((TGPoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCut'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddCut(tolua_var_5,tolua_var_6);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_GO_TGeomObject_AddCut01(tolua_S);
}

/* method: AddPolygon of class  TGeomObject */
static int tolua_z_GO_TGeomObject_AddPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMTList<TGCut>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  TMTList<TGCut>* tolua_var_7 = ((TMTList<TGCut>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPolygon'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddPolygon(*tolua_var_7);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPolygon'.",&tolua_err);
 return 0;
#endif
}

/* method: AddPolygon of class  TGeomObject */
static int tolua_z_GO_TGeomObject_AddPolygon01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TMTList<int>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  const TMTList<int>* indices = ((const TMTList<int>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPolygon'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddPolygon(*indices);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_GO_TGeomObject_AddPolygon00(tolua_S);
}

/* method: ExistsCut of class  TGeomObject */
static int tolua_z_GO_TGeomObject_ExistsCut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TGCut",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  const TGCut* tolua_var_8 = ((const TGCut*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ExistsCut'",NULL);
#endif
  {
   int tolua_ret = (int)  self->ExistsCut(*tolua_var_8);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ExistsCut'.",&tolua_err);
 return 0;
#endif
}

/* method: Clear of class  TGeomObject */
static int tolua_z_GO_TGeomObject_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
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

/* method: FreeUnused of class  TGeomObject */
static int tolua_z_GO_TGeomObject_FreeUnused00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
		 !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
		 !tolua_isusertype(tolua_S,2,"TFreeUnusedType",0,&tolua_err) ||
		 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
	goto tolua_lerror;
 else
#endif
 {
	TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
	TGeomPrimitiveType fur = *((TGeomPrimitiveType*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FreeUnused'",NULL);
#endif
  {
	 self->Fix.Unused(fur);
	}
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FreeUnused'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TGeomObject */
static int tolua_z_GO_TGeomObject_Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TGeomObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TMyObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TGeomObject* self = (TGeomObject*)  tolua_tousertype(tolua_S,1,0);
  TMyObject* Object = ((TMyObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(Object);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* Open function */
TOLUA_API int tolua_z_GO_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TGPoint","TGPoint","TMyObject",tolua_collect_TGPoint);
#else
 tolua_cclass(tolua_S,"TGPoint","TGPoint","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TGPoint");
 tolua_function(tolua_S,"new",tolua_z_GO_TGPoint_new00);
 tolua_function(tolua_S,"new_local",tolua_z_GO_TGPoint_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_GO_TGPoint_new00_local);
 tolua_function(tolua_S,"new",tolua_z_GO_TGPoint_new01);
 tolua_function(tolua_S,"new_local",tolua_z_GO_TGPoint_new01_local);
 tolua_set_call_event(tolua_S,tolua_z_GO_TGPoint_new01_local);
 tolua_function(tolua_S,"delete",tolua_z_GO_TGPoint_delete00);
 tolua_variable(tolua_S,"Point",tolua_get_TGPoint_Point,tolua_set_TGPoint_Point);
 tolua_function(tolua_S,"GetCut",tolua_z_GO_TGPoint_GetCut00);
 tolua_variable(tolua_S,"CutsCount",tolua_get_TGPoint_CutsCount,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TGCut","TGCut","TMyObject",tolua_collect_TGCut);
#else
 tolua_cclass(tolua_S,"TGCut","TGCut","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TGCut");
 tolua_function(tolua_S,"new",tolua_z_GO_TGCut_new00);
 tolua_function(tolua_S,"new_local",tolua_z_GO_TGCut_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_GO_TGCut_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_GO_TGCut_delete00);
 tolua_variable(tolua_S,"Tag",tolua_get_TGCut_Tag,tolua_set_TGCut_Tag);
 tolua_variable(tolua_S,"Src",tolua_get_TGCut_Src_ptr,tolua_set_TGCut_Src_ptr);
 tolua_variable(tolua_S,"Dst",tolua_get_TGCut_Dst_ptr,tolua_set_TGCut_Dst_ptr);
 tolua_variable(tolua_S,"Left",tolua_get_TGCut_Left_ptr,NULL);
 tolua_variable(tolua_S,"Right",tolua_get_TGCut_Right_ptr,NULL);
 tolua_function(tolua_S,"CanConnect",tolua_z_GO_TGCut_CanConnect00);
 //tolua_function(tolua_S,"IsOneFreeSide",tolua_z_GO_TGCut_IsOneFreeSide00);
 tolua_function(tolua_S,"Equal",tolua_z_GO_TGCut_Equal00);
 tolua_function(tolua_S,"ConsistsDstAndSrc",tolua_z_GO_TGCut_ConsistsDstAndSrc00);
// tolua_function(tolua_S,"SameDirection",tolua_z_GO_TGCut_SameDirection00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TGPolygon","TGPolygon","TMyObject",tolua_collect_TGPolygon);
#else
 tolua_cclass(tolua_S,"TGPolygon","TGPolygon","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TGPolygon");
 tolua_function(tolua_S,"new",tolua_z_GO_TGPolygon_new00);
 tolua_function(tolua_S,"new_local",tolua_z_GO_TGPolygon_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_GO_TGPolygon_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_GO_TGPolygon_delete00);
 tolua_variable(tolua_S,"Tag",tolua_get_TGPolygon_Tag,tolua_set_TGPolygon_Tag);
 tolua_function(tolua_S,"GetPoint",tolua_z_GO_TGPolygon_GetPoint00);
 tolua_function(tolua_S,"GetCut",tolua_z_GO_TGPolygon_GetCut00);
 tolua_function(tolua_S,"AddCut",tolua_z_GO_TGPolygon_AddCut00);
 tolua_function(tolua_S,"RemoveCut",tolua_z_GO_TGPolygon_RemoveCut00);
 tolua_function(tolua_S,"DeleteCut",tolua_z_GO_TGPolygon_DeleteCut00);
 tolua_variable(tolua_S,"Count",tolua_get_TGPolygon_Count,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TGeomObject","TGeomObject","TMyObject",tolua_collect_TGeomObject);
#else
 tolua_cclass(tolua_S,"TGeomObject","TGeomObject","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TGeomObject");
 tolua_function(tolua_S,"new",tolua_z_GO_TGeomObject_new00);
 tolua_function(tolua_S,"new_local",tolua_z_GO_TGeomObject_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_GO_TGeomObject_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_GO_TGeomObject_delete00);
 tolua_function(tolua_S,"GetVertex",tolua_z_GO_TGeomObject_GetVertex00);
 tolua_function(tolua_S,"GetCut",tolua_z_GO_TGeomObject_GetCut00);
 tolua_function(tolua_S,"GetPolygon",tolua_z_GO_TGeomObject_GetPolygon00);
 tolua_variable(tolua_S,"CutsCount",tolua_get_TGeomObject_CutsCount,NULL);
 tolua_variable(tolua_S,"PolygonsCount",tolua_get_TGeomObject_PolygonsCount,NULL);
 tolua_variable(tolua_S,"VertexCount",tolua_get_TGeomObject_VertexCount,NULL);
 tolua_function(tolua_S,"GetCutByPoints",tolua_z_GO_TGeomObject_GetCutByPoints00);
 tolua_function(tolua_S,"AddPoint",tolua_z_GO_TGeomObject_AddPoint00);
 tolua_function(tolua_S,"AddPoint",tolua_z_GO_TGeomObject_AddPoint01);
 tolua_function(tolua_S,"AddCut",tolua_z_GO_TGeomObject_AddCut00);
 tolua_function(tolua_S,"AddCut",tolua_z_GO_TGeomObject_AddCut01);
 tolua_function(tolua_S,"AddCut",tolua_z_GO_TGeomObject_AddCut02);
 tolua_function(tolua_S,"AddPolygon",tolua_z_GO_TGeomObject_AddPolygon00);
 tolua_function(tolua_S,"AddPolygon",tolua_z_GO_TGeomObject_AddPolygon01);
 tolua_function(tolua_S,"ExistsCut",tolua_z_GO_TGeomObject_ExistsCut00);
 tolua_function(tolua_S,"Clear",tolua_z_GO_TGeomObject_Clear00);
 tolua_function(tolua_S,"FreeUnused",tolua_z_GO_TGeomObject_FreeUnused00);
 tolua_function(tolua_S,"Assign",tolua_z_GO_TGeomObject_Assign00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
