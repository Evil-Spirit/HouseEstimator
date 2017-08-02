/*
** Lua binding: z_VisIt
** Generated automatically by tolua++-1.0.3 on 02/21/05 20:22:06.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_z_VisIt_open (lua_State* tolua_S);

#include "Bind.h"
#include <vcl.h>
#include "Usefuls.h"                 
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
#include "VisPrimitiveObj.hpp"
#include "VisClass.hpp"
#include "VisAttr.hpp"
#include "VisMat.hpp"
#include "VisMath.hpp"
#include "VisObj.hpp"
#include "VisView.hpp"
const int LUA_N = 1<<30;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_TVisVector (lua_State* tolua_S)
{
 TVisVector* self = (TVisVector*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisPrimitiveObj (lua_State* tolua_S)
{
 TVisPrimitiveObj* self = (TVisPrimitiveObj*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisTexture (lua_State* tolua_S)
{
 TVisTexture* self = (TVisTexture*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisObject (lua_State* tolua_S)
{
 TVisObject* self = (TVisObject*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisAttributes (lua_State* tolua_S)
{
 TVisAttributes* self = (TVisAttributes*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisTranslation (lua_State* tolua_S)
{
 TVisTranslation* self = (TVisTranslation*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisRotation (lua_State* tolua_S)
{
 TVisRotation* self = (TVisRotation*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisTransformation (lua_State* tolua_S)
{
 TVisTransformation* self = (TVisTransformation*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisMathVector (lua_State* tolua_S)
{
 TVisMathVector* self = (TVisMathVector*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisRender (lua_State* tolua_S)
{
 TVisRender* self = (TVisRender*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisPrimitivePoints (lua_State* tolua_S)
{
 TVisPrimitivePoints* self = (TVisPrimitivePoints*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisView (lua_State* tolua_S)
{
 TVisView* self = (TVisView*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisCustomView (lua_State* tolua_S)
{
 TVisCustomView* self = (TVisCustomView*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisProperty (lua_State* tolua_S)
{
 TVisProperty* self = (TVisProperty*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisMaterial (lua_State* tolua_S)
{
 TVisMaterial* self = (TVisMaterial*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisScale (lua_State* tolua_S)
{
 TVisScale* self = (TVisScale*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisTextureFlags (lua_State* tolua_S)
{
 TVisTextureFlags* self = (TVisTextureFlags*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisPrimitiveArray (lua_State* tolua_S)
{
 TVisPrimitiveArray* self = (TVisPrimitiveArray*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TVisColor (lua_State* tolua_S)
{
 TVisColor* self = (TVisColor*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TVisVector");
 tolua_usertype(tolua_S,"TVisTransform");
 tolua_usertype(tolua_S,"TVisCustomNode");
 tolua_usertype(tolua_S,"TVisPrimitiveObj");
 tolua_usertype(tolua_S,"TVisTexture");
 tolua_usertype(tolua_S,"TVisObject");
 tolua_usertype(tolua_S,"TVisAttributes");
 tolua_usertype(tolua_S,"TVisView");
 tolua_usertype(tolua_S,"TVisCustomView");
 tolua_usertype(tolua_S,"TVisTranslation");
 tolua_usertype(tolua_S,"TVisRotation");
 tolua_usertype(tolua_S,"TVisPrimitiveArray");
 tolua_usertype(tolua_S,"TVisPointItem");
 tolua_usertype(tolua_S,"TObject");
 tolua_usertype(tolua_S,"TVisMathVector");
 tolua_usertype(tolua_S,"TVisTransformed");
 tolua_usertype(tolua_S,"TVisRender");
 tolua_usertype(tolua_S,"TVisPrimitivePoints");
 tolua_usertype(tolua_S,"TVisRotationOrder");
 tolua_usertype(tolua_S,"TComponent");
 tolua_usertype(tolua_S,"TVisTransformation");
 tolua_usertype(tolua_S,"TVisMaterial");
 tolua_usertype(tolua_S,"TVisProperty");
 tolua_usertype(tolua_S,"TPersistent");
 tolua_usertype(tolua_S,"TVisScale");
 tolua_usertype(tolua_S,"TVisTextureFlags");
 tolua_usertype(tolua_S,"Graphics::TBitmap");
 tolua_usertype(tolua_S,"TVisColor");
}

/* get function: GL_POINTS */
static int tolua_get_VisConst_GL_POINTS(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_POINTS);
 return 1;
}

/* get function: GL_LINES */
static int tolua_get_VisConst_GL_LINES(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_LINES);
 return 1;
}

/* get function: GL_LINE_LOOP */
static int tolua_get_VisConst_GL_LINE_LOOP(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_LINE_LOOP);
 return 1;
}

/* get function: GL_LINE_STRIP */
static int tolua_get_VisConst_GL_LINE_STRIP(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_LINE_STRIP);
 return 1;
}

/* get function: GL_TRIANGLES */
static int tolua_get_VisConst_GL_TRIANGLES(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_TRIANGLES);
 return 1;
}

/* get function: GL_TRIANGLE_STRIP */
static int tolua_get_VisConst_GL_TRIANGLE_STRIP(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_TRIANGLE_STRIP);
 return 1;
}

/* get function: GL_TRIANGLE_FAN */
static int tolua_get_VisConst_GL_TRIANGLE_FAN(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_TRIANGLE_FAN);
 return 1;
}

/* get function: GL_QUADS */
static int tolua_get_VisConst_GL_QUADS(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_QUADS);
 return 1;
}

/* get function: GL_QUAD_STRIP */
static int tolua_get_VisConst_GL_QUAD_STRIP(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_QUAD_STRIP);
 return 1;
}

/* get function: GL_POLYGON */
static int tolua_get_VisConst_GL_POLYGON(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)GL_POLYGON);
 return 1;
}

/* method: new of class  TVisMathVector */
static int tolua_z_VisIt_TVisMathVector_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisMathVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisMathVector* tolua_ret = (TVisMathVector*)  new TVisMathVector();

/* getting type */
  char* lua_type = "TVisMathVector";
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

/* method: new_local of class  TVisMathVector */
static int tolua_z_VisIt_TVisMathVector_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisMathVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisMathVector* tolua_ret = (TVisMathVector*)  new TVisMathVector();

/* getting type */
  char* lua_type = "TVisMathVector";
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

/* method: delete of class  TVisMathVector */
static int tolua_z_VisIt_TVisMathVector_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisMathVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisMathVector* self = (TVisMathVector*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: x of class  TVisMathVector */
static int tolua_get_TVisMathVector_x(lua_State* tolua_S)
{
  TVisMathVector* self = (TVisMathVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}

/* set function: x of class  TVisMathVector */
static int tolua_set_TVisMathVector_x(lua_State* tolua_S)
{
  TVisMathVector* self = (TVisMathVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: y of class  TVisMathVector */
static int tolua_get_TVisMathVector_y(lua_State* tolua_S)
{
  TVisMathVector* self = (TVisMathVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}

/* set function: y of class  TVisMathVector */
static int tolua_set_TVisMathVector_y(lua_State* tolua_S)
{
  TVisMathVector* self = (TVisMathVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: z of class  TVisMathVector */
static int tolua_get_TVisMathVector_z(lua_State* tolua_S)
{
  TVisMathVector* self = (TVisMathVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}

/* set function: z of class  TVisMathVector */
static int tolua_set_TVisMathVector_z(lua_State* tolua_S)
{
  TVisMathVector* self = (TVisMathVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: a of class  TVisMathVector */
static int tolua_get_z_VisIt_TVisMathVector_a(lua_State* tolua_S)
{
 int tolua_index;
  TVisMathVector* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisMathVector*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=3)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->a[tolua_index]);
 return 1;
}

/* set function: a of class  TVisMathVector */
static int tolua_set_z_VisIt_TVisMathVector_a(lua_State* tolua_S)
{
 int tolua_index;
  TVisMathVector* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisMathVector*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=3)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->a[tolua_index] = ((double)  tolua_tonumber(tolua_S,3,0));
 return 0;
}

/* function: ToVec */
static int tolua_z_VisIt_ToVec00(lua_State* tolua_S)
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
  double x = ((double)  tolua_tonumber(tolua_S,1,0));
/*declare*/
  double y = ((double)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  double z = ((double)  tolua_tonumber(tolua_S,3,0));
  {
   TVisMathVector tolua_ret = (TVisMathVector)  ToVec(x,y,z);
   {
#ifdef __cplusplus
    void* tolua_obj = new TVisMathVector(tolua_ret);

/* getting type */
  char* lua_type = "TVisMathVector";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TVisMathVector));

/* getting type */
  char* lua_type = "TVisMathVector";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToVec'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TVisProperty */
static int tolua_z_VisIt_TVisProperty_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisProperty* tolua_ret = (TVisProperty*)  new TVisProperty();

/* getting type */
  char* lua_type = "TVisProperty";
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

/* method: new_local of class  TVisProperty */
static int tolua_z_VisIt_TVisProperty_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisProperty* tolua_ret = (TVisProperty*)  new TVisProperty();

/* getting type */
  char* lua_type = "TVisProperty";
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

/* method: delete of class  TVisProperty */
static int tolua_z_VisIt_TVisProperty_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisProperty",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisProperty* self = (TVisProperty*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Assign of class  TVisProperty */
static int tolua_z_VisIt_TVisProperty_Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisProperty",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPersistent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisProperty* self = (TVisProperty*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TPersistent* Source = ((TPersistent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(Source);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TVisVector */
static int tolua_z_VisIt_TVisVector_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisVector* tolua_ret = (TVisVector*)  new TVisVector();

/* getting type */
  char* lua_type = "TVisVector";
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

/* method: new_local of class  TVisVector */
static int tolua_z_VisIt_TVisVector_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisVector* tolua_ret = (TVisVector*)  new TVisVector();

/* getting type */
  char* lua_type = "TVisVector";
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

/* method: delete of class  TVisVector */
static int tolua_z_VisIt_TVisVector_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: AsMathVector of class  TVisVector */
static int tolua_get_TVisVector_AsMathVector(lua_State* tolua_S)
{
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AsMathVector'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisMathVector";
   tolua_pushusertype(tolua_S,(void*)(&(self->AsMathVector)),lua_type);
 return 1;
}

/* set function: AsMathVector of class  TVisVector */
static int tolua_set_TVisVector_AsMathVector(lua_State* tolua_S)
{
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AsMathVector'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisMathVector",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AsMathVector = *((TVisMathVector*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: incX of class  TVisVector */
static int tolua_z_VisIt_TVisVector_incX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'incX'",NULL);
#endif
  {
   self->incX(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'incX'.",&tolua_err);
 return 0;
#endif
}

/* method: incY of class  TVisVector */
static int tolua_z_VisIt_TVisVector_incY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'incY'",NULL);
#endif
  {
   self->incY(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'incY'.",&tolua_err);
 return 0;
#endif
}

/* method: incZ of class  TVisVector */
static int tolua_z_VisIt_TVisVector_incZ00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'incZ'",NULL);
#endif
  {
   self->incZ(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'incZ'.",&tolua_err);
 return 0;
#endif
}

/* method: SetValues of class  TVisVector */
static int tolua_z_VisIt_TVisVector_SetValues00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetValues'",NULL);
#endif
  {
   self->SetValues(x,y,z);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetValues'.",&tolua_err);
 return 0;
#endif
}

/* get function: X of class  TVisVector */
static int tolua_get_TVisVector_X(lua_State* tolua_S)
{
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->X);
 return 1;
}

/* set function: X of class  TVisVector */
static int tolua_set_TVisVector_X(lua_State* tolua_S)
{
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->X = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Y of class  TVisVector */
static int tolua_get_TVisVector_Y(lua_State* tolua_S)
{
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Y);
 return 1;
}

/* set function: Y of class  TVisVector */
static int tolua_set_TVisVector_Y(lua_State* tolua_S)
{
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Y = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Z of class  TVisVector */
static int tolua_get_TVisVector_Z(lua_State* tolua_S)
{
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Z);
 return 1;
}

/* set function: Z of class  TVisVector */
static int tolua_set_TVisVector_Z(lua_State* tolua_S)
{
  TVisVector* self = (TVisVector*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Z = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TVisColor */
static int tolua_z_VisIt_TVisColor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisColor* tolua_ret = (TVisColor*)  new TVisColor();

/* getting type */
  char* lua_type = "TVisColor";
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

/* method: new_local of class  TVisColor */
static int tolua_z_VisIt_TVisColor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisColor* tolua_ret = (TVisColor*)  new TVisColor();

/* getting type */
  char* lua_type = "TVisColor";
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

/* method: delete of class  TVisColor */
static int tolua_z_VisIt_TVisColor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisColor* self = (TVisColor*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Color of class  TVisColor */
static int tolua_get_TVisColor_Color(lua_State* tolua_S)
{
  TVisColor* self = (TVisColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Color);
 return 1;
}

/* set function: Color of class  TVisColor */
static int tolua_set_TVisColor_Color(lua_State* tolua_S)
{
  TVisColor* self = (TVisColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Color = ((TColor) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Alpha of class  TVisColor */
static int tolua_get_TVisColor_Alpha(lua_State* tolua_S)
{
  TVisColor* self = (TVisColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Alpha'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Alpha);
 return 1;
}

/* set function: Alpha of class  TVisColor */
static int tolua_set_TVisColor_Alpha(lua_State* tolua_S)
{
  TVisColor* self = (TVisColor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Alpha'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Alpha = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TVisMaterial */
static int tolua_z_VisIt_TVisMaterial_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisMaterial",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisMaterial* tolua_ret = (TVisMaterial*)  new TVisMaterial(aOwner);

/* getting type */
  char* lua_type = "TVisMaterial";
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

/* method: new_local of class  TVisMaterial */
static int tolua_z_VisIt_TVisMaterial_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisMaterial",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisMaterial* tolua_ret = (TVisMaterial*)  new TVisMaterial(aOwner);

/* getting type */
  char* lua_type = "TVisMaterial";
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

/* method: delete of class  TVisMaterial */
static int tolua_z_VisIt_TVisMaterial_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisMaterial",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Face of class  TVisMaterial */
static int tolua_get_TVisMaterial_Face(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Face'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Face);
 return 1;
}

/* set function: Face of class  TVisMaterial */
static int tolua_set_TVisMaterial_Face(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Face'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Face = ((TMaterialFace) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: ColorAmbient of class  TVisMaterial */
static int tolua_get_TVisMaterial_ColorAmbient_ptr(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorAmbient'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisColor";
   tolua_pushusertype(tolua_S,(void*)(self->ColorAmbient),lua_type);
 return 1;
}

/* set function: ColorAmbient of class  TVisMaterial */
static int tolua_set_TVisMaterial_ColorAmbient_ptr(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorAmbient'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisColor",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ColorAmbient = ((TVisColor*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: ColorDiffuse of class  TVisMaterial */
static int tolua_get_TVisMaterial_ColorDiffuse_ptr(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorDiffuse'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisColor";
   tolua_pushusertype(tolua_S,(void*)(self->ColorDiffuse),lua_type);
 return 1;
}

/* set function: ColorDiffuse of class  TVisMaterial */
static int tolua_set_TVisMaterial_ColorDiffuse_ptr(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorDiffuse'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisColor",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ColorDiffuse = ((TVisColor*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: ColorSpecular of class  TVisMaterial */
static int tolua_get_TVisMaterial_ColorSpecular_ptr(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorSpecular'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisColor";
   tolua_pushusertype(tolua_S,(void*)(self->ColorSpecular),lua_type);
 return 1;
}

/* set function: ColorSpecular of class  TVisMaterial */
static int tolua_set_TVisMaterial_ColorSpecular_ptr(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorSpecular'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisColor",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ColorSpecular = ((TVisColor*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: ColorEmission of class  TVisMaterial */
static int tolua_get_TVisMaterial_ColorEmission_ptr(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorEmission'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisColor";
   tolua_pushusertype(tolua_S,(void*)(self->ColorEmission),lua_type);
 return 1;
}

/* set function: ColorEmission of class  TVisMaterial */
static int tolua_set_TVisMaterial_ColorEmission_ptr(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorEmission'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisColor",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ColorEmission = ((TVisColor*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Shininess of class  TVisMaterial */
static int tolua_get_TVisMaterial_Shininess(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Shininess'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Shininess);
 return 1;
}

/* set function: Shininess of class  TVisMaterial */
static int tolua_set_TVisMaterial_Shininess(lua_State* tolua_S)
{
  TVisMaterial* self = (TVisMaterial*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Shininess'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Shininess = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TVisTexture */
static int tolua_z_VisIt_TVisTexture_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisTexture",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisTexture* tolua_ret = (TVisTexture*)  new TVisTexture(aOwner);

/* getting type */
  char* lua_type = "TVisTexture";
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

/* method: new_local of class  TVisTexture */
static int tolua_z_VisIt_TVisTexture_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisTexture",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisTexture* tolua_ret = (TVisTexture*)  new TVisTexture(aOwner);

/* getting type */
  char* lua_type = "TVisTexture";
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

/* method: delete of class  TVisTexture */
static int tolua_z_VisIt_TVisTexture_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetAlphaBitmap of class  TVisTexture */
static int tolua_z_VisIt_TVisTexture_SetAlphaBitmap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTexture",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Graphics::TBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  Graphics::TBitmap* aBitmap = ((Graphics::TBitmap*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlphaBitmap'",NULL);
#endif
  {
   self->SetAlphaBitmap(aBitmap);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlphaBitmap'.",&tolua_err);
 return 0;
#endif
}

/* method: SetMaskAlpha of class  TVisTexture */
static int tolua_z_VisIt_TVisTexture_SetMaskAlpha00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTexture",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  double Alpha = ((double)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  TColor MaskColor = ((TColor) (int)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  double MaskAlpha = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaskAlpha'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetMaskAlpha(Alpha,MaskColor,MaskAlpha);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaskAlpha'.",&tolua_err);
 return 0;
#endif
}

/* method: Invalidate of class  TVisTexture */
static int tolua_z_VisIt_TVisTexture_Invalidate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Invalidate'",NULL);
#endif
  {
   self->Invalidate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Invalidate'.",&tolua_err);
 return 0;
#endif
}

/* method: BitmapChange of class  TVisTexture */
static int tolua_z_VisIt_TVisTexture_BitmapChange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTexture",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TObject* Sender = ((TObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'BitmapChange'",NULL);
#endif
  {
   self->BitmapChange(Sender);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'BitmapChange'.",&tolua_err);
 return 0;
#endif
}

/* method: AddMipMap of class  TVisTexture */
static int tolua_z_VisIt_TVisTexture_AddMipMap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTexture",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Graphics::TBitmap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  Graphics::TBitmap* MipMap = ((Graphics::TBitmap*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMipMap'",NULL);
#endif
  {
   self->AddMipMap(MipMap);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddMipMap'.",&tolua_err);
 return 0;
#endif
}

/* method: ClearMipMaps of class  TVisTexture */
static int tolua_z_VisIt_TVisTexture_ClearMipMaps00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearMipMaps'",NULL);
#endif
  {
   self->ClearMipMaps();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearMipMaps'.",&tolua_err);
 return 0;
#endif
}

/* get function: MinFilter of class  TVisTexture */
static int tolua_get_TVisTexture_MinFilter(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MinFilter'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MinFilter);
 return 1;
}

/* set function: MinFilter of class  TVisTexture */
static int tolua_set_TVisTexture_MinFilter(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MinFilter'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MinFilter = ((TVisTexFilter) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: MagFilter of class  TVisTexture */
static int tolua_get_TVisTexture_MagFilter(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MagFilter'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MagFilter);
 return 1;
}

/* set function: MagFilter of class  TVisTexture */
static int tolua_set_TVisTexture_MagFilter(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MagFilter'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MagFilter = ((TVisTexFilter) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Bitmap of class  TVisTexture */
static int tolua_get_TVisTexture_Bitmap_ptr(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Bitmap'",NULL);
#endif

/* getting type */
  char* lua_type = "Graphics::TBitmap";
   tolua_pushusertype(tolua_S,(void*)(self->Bitmap),lua_type);
 return 1;
}

/* set function: Bitmap of class  TVisTexture */
static int tolua_set_TVisTexture_Bitmap_ptr(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Bitmap'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Graphics::TBitmap",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Bitmap = ((Graphics::TBitmap*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Alpha of class  TVisTexture */
static int tolua_get_TVisTexture_Alpha(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Alpha'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Alpha);
 return 1;
}

/* set function: Alpha of class  TVisTexture */
static int tolua_set_TVisTexture_Alpha(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Alpha'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Alpha = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Mode of class  TVisTexture */
static int tolua_get_TVisTexture_Mode(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Mode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Mode);
 return 1;
}

/* set function: Mode of class  TVisTexture */
static int tolua_set_TVisTexture_Mode(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Mode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Mode = ((TVisTexMode) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: BlendColor of class  TVisTexture */
static int tolua_get_TVisTexture_BlendColor_ptr(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BlendColor'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisColor";
   tolua_pushusertype(tolua_S,(void*)(self->BlendColor),lua_type);
 return 1;
}

/* set function: BlendColor of class  TVisTexture */
static int tolua_set_TVisTexture_BlendColor_ptr(lua_State* tolua_S)
{
  TVisTexture* self = (TVisTexture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BlendColor'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisColor",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->BlendColor = ((TVisColor*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: new of class  TVisTextureFlags */
static int tolua_z_VisIt_TVisTextureFlags_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisTextureFlags",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisTextureFlags* tolua_ret = (TVisTextureFlags*)  new TVisTextureFlags();

/* getting type */
  char* lua_type = "TVisTextureFlags";
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

/* method: new_local of class  TVisTextureFlags */
static int tolua_z_VisIt_TVisTextureFlags_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisTextureFlags",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisTextureFlags* tolua_ret = (TVisTextureFlags*)  new TVisTextureFlags();

/* getting type */
  char* lua_type = "TVisTextureFlags";
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

/* method: delete of class  TVisTextureFlags */
static int tolua_z_VisIt_TVisTextureFlags_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTextureFlags",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Mode of class  TVisTextureFlags */
static int tolua_get_TVisTextureFlags_Mode(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Mode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Mode);
 return 1;
}

/* set function: Mode of class  TVisTextureFlags */
static int tolua_set_TVisTextureFlags_Mode(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Mode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Mode = ((TVisTextureMode) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: ShiftX of class  TVisTextureFlags */
static int tolua_get_TVisTextureFlags_ShiftX(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShiftX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ShiftX);
 return 1;
}

/* set function: ShiftX of class  TVisTextureFlags */
static int tolua_set_TVisTextureFlags_ShiftX(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShiftX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ShiftX = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: ShiftY of class  TVisTextureFlags */
static int tolua_get_TVisTextureFlags_ShiftY(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShiftY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ShiftY);
 return 1;
}

/* set function: ShiftY of class  TVisTextureFlags */
static int tolua_set_TVisTextureFlags_ShiftY(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShiftY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ShiftY = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: ScaleX of class  TVisTextureFlags */
static int tolua_get_TVisTextureFlags_ScaleX(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ScaleX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ScaleX);
 return 1;
}

/* set function: ScaleX of class  TVisTextureFlags */
static int tolua_set_TVisTextureFlags_ScaleX(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ScaleX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ScaleX = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: ScaleY of class  TVisTextureFlags */
static int tolua_get_TVisTextureFlags_ScaleY(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ScaleY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ScaleY);
 return 1;
}

/* set function: ScaleY of class  TVisTextureFlags */
static int tolua_set_TVisTextureFlags_ScaleY(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ScaleY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ScaleY = ((double)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: ParamVector of class  TVisTextureFlags */
static int tolua_get_TVisTextureFlags_ParamVector_ptr(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ParamVector'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisVector";
   tolua_pushusertype(tolua_S,(void*)(self->ParamVector),lua_type);
 return 1;
}

/* set function: ParamVector of class  TVisTextureFlags */
static int tolua_set_TVisTextureFlags_ParamVector_ptr(lua_State* tolua_S)
{
  TVisTextureFlags* self = (TVisTextureFlags*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ParamVector'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisVector",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ParamVector = ((TVisVector*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: new of class  TVisAttributes */
static int tolua_z_VisIt_TVisAttributes_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisAttributes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisAttributes* tolua_ret = (TVisAttributes*)  new TVisAttributes(aOwner);

/* getting type */
  char* lua_type = "TVisAttributes";
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

/* method: new_local of class  TVisAttributes */
static int tolua_z_VisIt_TVisAttributes_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisAttributes",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisAttributes* tolua_ret = (TVisAttributes*)  new TVisAttributes(aOwner);

/* getting type */
  char* lua_type = "TVisAttributes";
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

/* method: delete of class  TVisAttributes */
static int tolua_z_VisIt_TVisAttributes_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: StippleShift of class  TVisAttributes */
static int tolua_get_TVisAttributes_StippleShift(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'StippleShift'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->StippleShift);
 return 1;
}

/* set function: StippleShift of class  TVisAttributes */
static int tolua_set_TVisAttributes_StippleShift(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'StippleShift'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->StippleShift = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: StippleScale of class  TVisAttributes */
static int tolua_get_TVisAttributes_StippleScale(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'StippleScale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->StippleScale);
 return 1;
}

/* set function: StippleScale of class  TVisAttributes */
static int tolua_set_TVisAttributes_StippleScale(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'StippleScale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->StippleScale = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Antialiasing of class  TVisAttributes */
static int tolua_get_TVisAttributes_Antialiasing(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Antialiasing'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Antialiasing);
 return 1;
}

/* set function: Antialiasing of class  TVisAttributes */
static int tolua_set_TVisAttributes_Antialiasing(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Antialiasing'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Antialiasing = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: ColorAmbient of class  TVisAttributes */
static int tolua_get_TVisAttributes_ColorAmbient_ptr(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorAmbient'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisColor";
   tolua_pushusertype(tolua_S,(void*)(self->ColorAmbient),lua_type);
 return 1;
}

/* set function: ColorAmbient of class  TVisAttributes */
static int tolua_set_TVisAttributes_ColorAmbient_ptr(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorAmbient'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisColor",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ColorAmbient = ((TVisColor*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: CullFace of class  TVisAttributes */
static int tolua_get_TVisAttributes_CullFace(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CullFace'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CullFace);
 return 1;
}

/* set function: CullFace of class  TVisAttributes */
static int tolua_set_TVisAttributes_CullFace(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CullFace'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CullFace = ((TVisCullFace) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Dithering of class  TVisAttributes */
static int tolua_get_TVisAttributes_Dithering(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Dithering'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Dithering);
 return 1;
}

/* set function: Dithering of class  TVisAttributes */
static int tolua_set_TVisAttributes_Dithering(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Dithering'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Dithering = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: Lighting of class  TVisAttributes */
static int tolua_get_TVisAttributes_Lighting(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Lighting'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Lighting);
 return 1;
}

/* set function: Lighting of class  TVisAttributes */
static int tolua_set_TVisAttributes_Lighting(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Lighting'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Lighting = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: LightTwoSide of class  TVisAttributes */
static int tolua_get_TVisAttributes_LightTwoSide(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LightTwoSide'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->LightTwoSide);
 return 1;
}

/* set function: LightTwoSide of class  TVisAttributes */
static int tolua_set_TVisAttributes_LightTwoSide(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LightTwoSide'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->LightTwoSide = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: PolygonMode of class  TVisAttributes */
static int tolua_get_TVisAttributes_PolygonMode(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PolygonMode'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PolygonMode);
 return 1;
}

/* set function: PolygonMode of class  TVisAttributes */
static int tolua_set_TVisAttributes_PolygonMode(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PolygonMode'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PolygonMode = ((TVisPolygonMode) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: PerspectiveCorrection of class  TVisAttributes */
static int tolua_get_TVisAttributes_PerspectiveCorrection(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PerspectiveCorrection'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PerspectiveCorrection);
 return 1;
}

/* set function: PerspectiveCorrection of class  TVisAttributes */
static int tolua_set_TVisAttributes_PerspectiveCorrection(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PerspectiveCorrection'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PerspectiveCorrection = ((TVisQuality) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: ShadeModel of class  TVisAttributes */
static int tolua_get_TVisAttributes_ShadeModel(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShadeModel'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ShadeModel);
 return 1;
}

/* set function: ShadeModel of class  TVisAttributes */
static int tolua_set_TVisAttributes_ShadeModel(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShadeModel'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ShadeModel = ((TVisShadeModel) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Transparency of class  TVisAttributes */
static int tolua_get_TVisAttributes_Transparency(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Transparency'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Transparency);
 return 1;
}

/* set function: Transparency of class  TVisAttributes */
static int tolua_set_TVisAttributes_Transparency(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Transparency'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Transparency = ((TVisTransparencyMode) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: LineStipple of class  TVisAttributes */
static int tolua_get_TVisAttributes_LineStipple(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LineStipple'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->LineStipple);
 return 1;
}

/* set function: LineStipple of class  TVisAttributes */
static int tolua_set_TVisAttributes_LineStipple(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LineStipple'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->LineStipple = ((TVisLineStipple) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: PointSize of class  TVisAttributes */
static int tolua_get_TVisAttributes_PointSize(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PointSize'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PointSize);
 return 1;
}

/* set function: PointSize of class  TVisAttributes */
static int tolua_set_TVisAttributes_PointSize(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PointSize'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PointSize = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: LineWidth of class  TVisAttributes */
static int tolua_get_TVisAttributes_LineWidth(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LineWidth'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->LineWidth);
 return 1;
}

/* set function: LineWidth of class  TVisAttributes */
static int tolua_set_TVisAttributes_LineWidth(lua_State* tolua_S)
{
  TVisAttributes* self = (TVisAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LineWidth'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->LineWidth = ((float)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: Execute of class  TVisRotation */
static int tolua_z_VisIt_TVisRotation_Execute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisRotation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisRotation* self = (TVisRotation*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Order of class  TVisRotation */
static int tolua_get_TVisRotation_Order(lua_State* tolua_S)
{
  TVisRotation* self = (TVisRotation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Order'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisRotationOrder";
   tolua_pushusertype(tolua_S,(void*)(&(self->Order)),lua_type);
 return 1;
}

/* set function: Order of class  TVisRotation */
static int tolua_set_TVisRotation_Order(lua_State* tolua_S)
{
  TVisRotation* self = (TVisRotation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Order'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisRotationOrder",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Order = *((TVisRotationOrder*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: new of class  TVisRotation */
static int tolua_z_VisIt_TVisRotation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisRotation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisRotation* tolua_ret = (TVisRotation*)  new TVisRotation();

/* getting type */
  char* lua_type = "TVisRotation";
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

/* method: new_local of class  TVisRotation */
static int tolua_z_VisIt_TVisRotation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisRotation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisRotation* tolua_ret = (TVisRotation*)  new TVisRotation();

/* getting type */
  char* lua_type = "TVisRotation";
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

/* method: delete of class  TVisRotation */
static int tolua_z_VisIt_TVisRotation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisRotation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisRotation* self = (TVisRotation*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  TVisScale */
static int tolua_z_VisIt_TVisScale_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisScale",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisScale* tolua_ret = (TVisScale*)  new TVisScale();

/* getting type */
  char* lua_type = "TVisScale";
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

/* method: new_local of class  TVisScale */
static int tolua_z_VisIt_TVisScale_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisScale",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisScale* tolua_ret = (TVisScale*)  new TVisScale();

/* getting type */
  char* lua_type = "TVisScale";
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

/* method: delete of class  TVisScale */
static int tolua_z_VisIt_TVisScale_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisScale",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisScale* self = (TVisScale*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  TVisTranslation */
static int tolua_z_VisIt_TVisTranslation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisTranslation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisTranslation* tolua_ret = (TVisTranslation*)  new TVisTranslation();

/* getting type */
  char* lua_type = "TVisTranslation";
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

/* method: new_local of class  TVisTranslation */
static int tolua_z_VisIt_TVisTranslation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisTranslation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisTranslation* tolua_ret = (TVisTranslation*)  new TVisTranslation();

/* getting type */
  char* lua_type = "TVisTranslation";
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

/* method: delete of class  TVisTranslation */
static int tolua_z_VisIt_TVisTranslation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTranslation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTranslation* self = (TVisTranslation*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  TVisTransformation */
static int tolua_z_VisIt_TVisTransformation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisTransformation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisTransformation* tolua_ret = (TVisTransformation*)  new TVisTransformation();

/* getting type */
  char* lua_type = "TVisTransformation";
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

/* method: new_local of class  TVisTransformation */
static int tolua_z_VisIt_TVisTransformation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisTransformation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisTransformation* tolua_ret = (TVisTransformation*)  new TVisTransformation();

/* getting type */
  char* lua_type = "TVisTransformation";
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

/* method: delete of class  TVisTransformation */
static int tolua_z_VisIt_TVisTransformation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTransformation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Execute of class  TVisTransformation */
static int tolua_z_VisIt_TVisTransformation_Execute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisTransformation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Empty of class  TVisTransformation */
static int tolua_get_TVisTransformation_Empty(lua_State* tolua_S)
{
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Empty'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Empty);
 return 1;
}

/* get function: Rotation of class  TVisTransformation */
static int tolua_get_TVisTransformation_Rotation_ptr(lua_State* tolua_S)
{
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Rotation'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisRotation";
   tolua_pushusertype(tolua_S,(void*)(self->Rotation),lua_type);
 return 1;
}

/* set function: Rotation of class  TVisTransformation */
static int tolua_set_TVisTransformation_Rotation_ptr(lua_State* tolua_S)
{
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Rotation'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisRotation",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Rotation = ((TVisRotation*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Scale of class  TVisTransformation */
static int tolua_get_TVisTransformation_Scale_ptr(lua_State* tolua_S)
{
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Scale'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisScale";
   tolua_pushusertype(tolua_S,(void*)(self->Scale),lua_type);
 return 1;
}

/* set function: Scale of class  TVisTransformation */
static int tolua_set_TVisTransformation_Scale_ptr(lua_State* tolua_S)
{
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Scale'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisScale",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Scale = ((TVisScale*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Translation of class  TVisTransformation */
static int tolua_get_TVisTransformation_Translation_ptr(lua_State* tolua_S)
{
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Translation'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisTranslation";
   tolua_pushusertype(tolua_S,(void*)(self->Translation),lua_type);
 return 1;
}

/* set function: Translation of class  TVisTransformation */
static int tolua_set_TVisTransformation_Translation_ptr(lua_State* tolua_S)
{
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Translation'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisTranslation",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Translation = ((TVisTranslation*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Order of class  TVisTransformation */
static int tolua_get_TVisTransformation_Order(lua_State* tolua_S)
{
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Order'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Order);
 return 1;
}

/* set function: Order of class  TVisTransformation */
static int tolua_set_TVisTransformation_Order(lua_State* tolua_S)
{
  TVisTransformation* self = (TVisTransformation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Order'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Order = ((TVisTransformationOrder) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: SetNodeDirect of class  TVisRender */
static int tolua_z_VisIt_TVisRender_SetNodeDirect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisRender",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TVisCustomNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisRender* self = (TVisRender*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TVisCustomNode* Value = ((const TVisCustomNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetNodeDirect'",NULL);
#endif
  {
   self->SetNodeDirect(Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetNodeDirect'.",&tolua_err);
 return 0;
#endif
}

/* method: new of class  TVisRender */
static int tolua_z_VisIt_TVisRender_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisRender",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisRender* tolua_ret = (TVisRender*)  new TVisRender(aOwner);

/* getting type */
  char* lua_type = "TVisRender";
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

/* method: new_local of class  TVisRender */
static int tolua_z_VisIt_TVisRender_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisRender",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisRender* tolua_ret = (TVisRender*)  new TVisRender(aOwner);

/* getting type */
  char* lua_type = "TVisRender";
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

/* method: delete of class  TVisRender */
static int tolua_z_VisIt_TVisRender_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisRender",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisRender* self = (TVisRender*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Render of class  TVisRender */
static int tolua_z_VisIt_TVisRender_Render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisRender",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TVisCustomView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisRender* self = (TVisRender*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TVisCustomView* aView = ((TVisCustomView*)  tolua_tousertype(tolua_S,2,0));
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

/* get function: Enabled of class  TVisRender */
static int tolua_get_TVisRender_Enabled(lua_State* tolua_S)
{
  TVisRender* self = (TVisRender*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Enabled);
 return 1;
}

/* set function: Enabled of class  TVisRender */
static int tolua_set_TVisRender_Enabled(lua_State* tolua_S)
{
  TVisRender* self = (TVisRender*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: new of class  TVisObject */
static int tolua_z_VisIt_TVisObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisObject* tolua_ret = (TVisObject*)  new TVisObject(aOwner);

/* getting type */
  char* lua_type = "TVisObject";
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

/* method: new_local of class  TVisObject */
static int tolua_z_VisIt_TVisObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisObject* tolua_ret = (TVisObject*)  new TVisObject(aOwner);

/* getting type */
  char* lua_type = "TVisObject";
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

/* method: delete of class  TVisObject */
static int tolua_z_VisIt_TVisObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisObject* self = (TVisObject*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: ColorAsMaterial of class  TVisObject */
static int tolua_get_TVisObject_ColorAsMaterial(lua_State* tolua_S)
{
  TVisObject* self = (TVisObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorAsMaterial'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ColorAsMaterial);
 return 1;
}

/* set function: ColorAsMaterial of class  TVisObject */
static int tolua_set_TVisObject_ColorAsMaterial(lua_State* tolua_S)
{
  TVisObject* self = (TVisObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorAsMaterial'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ColorAsMaterial = ((TVisColorAsMaterial) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Color of class  TVisObject */
static int tolua_get_TVisObject_Color_ptr(lua_State* tolua_S)
{
  TVisObject* self = (TVisObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisColor";
   tolua_pushusertype(tolua_S,(void*)(self->Color),lua_type);
 return 1;
}

/* set function: Color of class  TVisObject */
static int tolua_set_TVisObject_Color_ptr(lua_State* tolua_S)
{
  TVisObject* self = (TVisObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisColor",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Color = ((TVisColor*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Attributes of class  TVisObject */
static int tolua_get_TVisObject_Attributes_ptr(lua_State* tolua_S)
{
  TVisObject* self = (TVisObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Attributes'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisAttributes";
   tolua_pushusertype(tolua_S,(void*)(self->Attributes),lua_type);
 return 1;
}

/* set function: Attributes of class  TVisObject */
static int tolua_set_TVisObject_Attributes_ptr(lua_State* tolua_S)
{
  TVisObject* self = (TVisObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Attributes'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisAttributes",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Attributes = ((TVisAttributes*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Material of class  TVisObject */
static int tolua_get_TVisObject_Material_ptr(lua_State* tolua_S)
{
  TVisObject* self = (TVisObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Material'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisMaterial";
   tolua_pushusertype(tolua_S,(void*)(self->Material),lua_type);
 return 1;
}

/* set function: Material of class  TVisObject */
static int tolua_set_TVisObject_Material_ptr(lua_State* tolua_S)
{
  TVisObject* self = (TVisObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Material'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisMaterial",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Material = ((TVisMaterial*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* method: operator[] of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints__geti00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int Nr = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator[]'",NULL);
#endif
  {
   TVisMathVector tolua_ret = (TVisMathVector)  self->operator[](Nr);
   {
#ifdef __cplusplus
    void* tolua_obj = new TVisMathVector(tolua_ret);

/* getting type */
  char* lua_type = "TVisMathVector";
   tolua_pushusertype_and_takeownership(tolua_S,(void*)(tolua_obj),lua_type);
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(TVisMathVector));

/* getting type */
  char* lua_type = "TVisMathVector";
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

/* method: new of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisPrimitivePoints* tolua_ret = (TVisPrimitivePoints*)  new TVisPrimitivePoints();

/* getting type */
  char* lua_type = "TVisPrimitivePoints";
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

/* method: new_local of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TVisPrimitivePoints* tolua_ret = (TVisPrimitivePoints*)  new TVisPrimitivePoints();

/* getting type */
  char* lua_type = "TVisPrimitivePoints";
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

/* method: delete of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Add of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  double x = ((double)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  double y = ((double)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  double z = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   int tolua_ret = (int)  self->Add(x,y,z);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Add of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_Add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TVisMathVector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TVisMathVector",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const TVisMathVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TVisMathVector* Vertex = ((const TVisMathVector*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  const TVisMathVector* Normal = ((const TVisMathVector*)  tolua_tousertype(tolua_S,3,0));
/*declare*/
  const TVisMathVector* Texture = ((const TVisMathVector*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   int tolua_ret = (int)  self->Add(*Vertex,*Normal,*Texture);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_VisIt_TVisPrimitivePoints_Add00(tolua_S);
}

/* method: Add of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_Add02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TVisPointItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TVisPointItem* value = ((TVisPointItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   int tolua_ret = (int)  self->Add(value);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_VisIt_TVisPrimitivePoints_Add01(tolua_S);
}

/* method: Add of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_Add03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TVisPrimitivePoints* value = ((TVisPrimitivePoints*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   int tolua_ret = (int)  self->Add(value);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_VisIt_TVisPrimitivePoints_Add02(tolua_S);
}

/* method: Delete of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int Index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int aCount = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(Index,aCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: GetPoint of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_GetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TVisPointItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  TVisPointItem* value = ((TVisPointItem*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPoint'",NULL);
#endif
  {
   self->GetPoint(index,value);

/* getting type */
  char* lua_type = "TVisPointItem";
   tolua_pushusertype(tolua_S,(void*)(value),lua_type);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPoint'.",&tolua_err);
 return 0;
#endif
}

/* method: SetPoint of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_SetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"TVisPointItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  TVisPointItem* value = ((TVisPointItem*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPoint'",NULL);
#endif
  {
   self->SetPoint(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPoint'.",&tolua_err);
 return 0;
#endif
}

/* method: LiftPoint of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_LiftPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  double value = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LiftPoint'",NULL);
#endif
  {
   self->LiftPoint(index,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LiftPoint'.",&tolua_err);
 return 0;
#endif
}

/* method: ScalePoints of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_ScalePoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  double scaleX = ((double)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  double scaleY = ((double)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  double scaleZ = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ScalePoints'",NULL);
#endif
  {
   self->ScalePoints(scaleX,scaleY,scaleZ);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ScalePoints'.",&tolua_err);
 return 0;
#endif
}

/* method: MovePoints of class  TVisPrimitivePoints */
static int tolua_z_VisIt_TVisPrimitivePoints_MovePoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitivePoints",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  double moveX = ((double)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  double moveY = ((double)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  double moveZ = ((double)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MovePoints'",NULL);
#endif
  {
   self->MovePoints(moveX,moveY,moveZ);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MovePoints'.",&tolua_err);
 return 0;
#endif
}

/* get function: Size of class  TVisPrimitivePoints */
static int tolua_get_TVisPrimitivePoints_Size(lua_State* tolua_S)
{
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Size'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Size);
 return 1;
}

/* set function: Size of class  TVisPrimitivePoints */
static int tolua_set_TVisPrimitivePoints_Size(lua_State* tolua_S)
{
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Size'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Size = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Count of class  TVisPrimitivePoints */
static int tolua_get_TVisPrimitivePoints_Count(lua_State* tolua_S)
{
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* set function: Count of class  TVisPrimitivePoints */
static int tolua_set_TVisPrimitivePoints_Count(lua_State* tolua_S)
{
  TVisPrimitivePoints* self = (TVisPrimitivePoints*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Count = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: PointVec of class  TVisPrimitivePoints */
static int tolua_get_z_VisIt_TVisPrimitivePoints_PointVec(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif

/* getting type */
  char* lua_type = "TVisMathVector";
   tolua_pushusertype(tolua_S,(void*)(&(self->PointVec[tolua_index])),lua_type);
 return 1;
}

/* set function: PointVec of class  TVisPrimitivePoints */
static int tolua_set_z_VisIt_TVisPrimitivePoints_PointVec(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->PointVec[tolua_index] = *((TVisMathVector*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}

/* get function: NormalVec of class  TVisPrimitivePoints */
static int tolua_get_z_VisIt_TVisPrimitivePoints_NormalVec(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif

/* getting type */
  char* lua_type = "TVisMathVector";
   tolua_pushusertype(tolua_S,(void*)(&(self->NormalVec[tolua_index])),lua_type);
 return 1;
}

/* set function: NormalVec of class  TVisPrimitivePoints */
static int tolua_set_z_VisIt_TVisPrimitivePoints_NormalVec(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->NormalVec[tolua_index] = *((TVisMathVector*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}

/* get function: TextureVec of class  TVisPrimitivePoints */
static int tolua_get_z_VisIt_TVisPrimitivePoints_TextureVec(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif

/* getting type */
  char* lua_type = "TVisMathVector";
   tolua_pushusertype(tolua_S,(void*)(&(self->TextureVec[tolua_index])),lua_type);
 return 1;
}

/* set function: TextureVec of class  TVisPrimitivePoints */
static int tolua_set_z_VisIt_TVisPrimitivePoints_TextureVec(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->TextureVec[tolua_index] = *((TVisMathVector*)  tolua_tousertype(tolua_S,3,0));
 return 0;
}

/* get function: EdgeFlag of class  TVisPrimitivePoints */
static int tolua_get_z_VisIt_TVisPrimitivePoints_EdgeFlag(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->EdgeFlag[tolua_index]);
 return 1;
}

/* set function: EdgeFlag of class  TVisPrimitivePoints */
static int tolua_set_z_VisIt_TVisPrimitivePoints_EdgeFlag(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->EdgeFlag[tolua_index] = ((int)  tolua_tonumber(tolua_S,3,0));
 return 0;
}

/* get function: ShareLight of class  TVisPrimitivePoints */
static int tolua_get_z_VisIt_TVisPrimitivePoints_ShareLight(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->ShareLight[tolua_index]);
 return 1;
}

/* set function: ShareLight of class  TVisPrimitivePoints */
static int tolua_set_z_VisIt_TVisPrimitivePoints_ShareLight(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->ShareLight[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}

/* get function: SharePosition of class  TVisPrimitivePoints */
static int tolua_get_z_VisIt_TVisPrimitivePoints_SharePosition(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->SharePosition[tolua_index]);
 return 1;
}

/* set function: SharePosition of class  TVisPrimitivePoints */
static int tolua_set_z_VisIt_TVisPrimitivePoints_SharePosition(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->SharePosition[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}

/* get function: CloseFlag of class  TVisPrimitivePoints */
static int tolua_get_z_VisIt_TVisPrimitivePoints_CloseFlag(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->CloseFlag[tolua_index]);
 return 1;
}

/* set function: CloseFlag of class  TVisPrimitivePoints */
static int tolua_set_z_VisIt_TVisPrimitivePoints_CloseFlag(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitivePoints* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitivePoints*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->CloseFlag[tolua_index] = ((bool)  tolua_toboolean(tolua_S,3,0));
 return 0;
}

/* method: new of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  int aType = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   TVisPrimitiveArray* tolua_ret = (TVisPrimitiveArray*)  new TVisPrimitiveArray(aType);

/* getting type */
  char* lua_type = "TVisPrimitiveArray";
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

/* method: new_local of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  int aType = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   TVisPrimitiveArray* tolua_ret = (TVisPrimitiveArray*)  new TVisPrimitiveArray(aType);

/* getting type */
  char* lua_type = "TVisPrimitiveArray";
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

/* method: delete of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
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

/* method: AddIndex of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_AddIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddIndex'",NULL);
#endif
  {
   self->AddIndex(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddIndex'.",&tolua_err);
 return 0;
#endif
}

/* method: Add of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_Add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TVisPrimitiveArray* Value = ((TVisPrimitiveArray*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  int offset = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Add'",NULL);
#endif
  {
   self->Add(Value,offset);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Add'.",&tolua_err);
 return 0;
#endif
}

/* method: Insert of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_Insert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int position = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Insert'",NULL);
#endif
  {
   self->Insert(position,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Insert'.",&tolua_err);
 return 0;
#endif
}

/* method: Delete of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_Delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int aCount = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Delete'",NULL);
#endif
  {
   self->Delete(index,aCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Delete'.",&tolua_err);
 return 0;
#endif
}

/* method: Assign of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_Assign00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TPersistent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TPersistent* Source = ((TPersistent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Assign'",NULL);
#endif
  {
   self->Assign(Source);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Assign'.",&tolua_err);
 return 0;
#endif
}

/* method: Invert of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ProceedDirectRendering of class  TVisPrimitiveArray */
static int tolua_z_VisIt_TVisPrimitiveArray_ProceedDirectRendering00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ProceedDirectRendering'",NULL);
#endif
  {
   self->ProceedDirectRendering();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ProceedDirectRendering'.",&tolua_err);
 return 0;
#endif
}

/* get function: Indices of class  TVisPrimitiveArray */
static int tolua_get_z_VisIt_TVisPrimitiveArray_Indices(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitiveArray* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitiveArray*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->Indices[tolua_index]);
 return 1;
}

/* set function: Indices of class  TVisPrimitiveArray */
static int tolua_set_z_VisIt_TVisPrimitiveArray_Indices(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitiveArray* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitiveArray*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->Indices[tolua_index] = ((int)  tolua_tonumber(tolua_S,3,0));
 return 0;
}

/* get function: Size of class  TVisPrimitiveArray */
static int tolua_get_TVisPrimitiveArray_Size(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Size'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Size);
 return 1;
}

/* set function: Size of class  TVisPrimitiveArray */
static int tolua_set_TVisPrimitiveArray_Size(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Size'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Size = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Count of class  TVisPrimitiveArray */
static int tolua_get_TVisPrimitiveArray_Count(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Count);
 return 1;
}

/* set function: Count of class  TVisPrimitiveArray */
static int tolua_set_TVisPrimitiveArray_Count(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Count'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Count = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Enabled of class  TVisPrimitiveArray */
static int tolua_get_TVisPrimitiveArray_Enabled(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Enabled);
 return 1;
}

/* set function: Enabled of class  TVisPrimitiveArray */
static int tolua_set_TVisPrimitiveArray_Enabled(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Enabled'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: PrimitiveType of class  TVisPrimitiveArray */
static int tolua_get_TVisPrimitiveArray_PrimitiveType(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PrimitiveType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PrimitiveType);
 return 1;
}

/* set function: PrimitiveType of class  TVisPrimitiveArray */
static int tolua_set_TVisPrimitiveArray_PrimitiveType(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PrimitiveType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PrimitiveType = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Texture of class  TVisPrimitiveArray */
static int tolua_get_TVisPrimitiveArray_Texture_ptr(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Texture'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisTexture";
   tolua_pushusertype(tolua_S,(void*)(self->Texture),lua_type);
 return 1;
}

/* set function: Texture of class  TVisPrimitiveArray */
static int tolua_set_TVisPrimitiveArray_Texture_ptr(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Texture'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisTexture",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Texture = ((TVisTexture*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Color of class  TVisPrimitiveArray */
static int tolua_get_TVisPrimitiveArray_Color_ptr(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisColor";
   tolua_pushusertype(tolua_S,(void*)(self->Color),lua_type);
 return 1;
}

/* set function: Color of class  TVisPrimitiveArray */
static int tolua_set_TVisPrimitiveArray_Color_ptr(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Color'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisColor",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Color = ((TVisColor*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: ColorAsMaterial of class  TVisPrimitiveArray */
static int tolua_get_TVisPrimitiveArray_ColorAsMaterial(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorAsMaterial'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ColorAsMaterial);
 return 1;
}

/* set function: ColorAsMaterial of class  TVisPrimitiveArray */
static int tolua_set_TVisPrimitiveArray_ColorAsMaterial(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ColorAsMaterial'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ColorAsMaterial = ((TVisColorAsMaterial) (int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* get function: Material of class  TVisPrimitiveArray */
static int tolua_get_TVisPrimitiveArray_Material_ptr(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Material'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisMaterial";
   tolua_pushusertype(tolua_S,(void*)(self->Material),lua_type);
 return 1;
}

/* set function: Material of class  TVisPrimitiveArray */
static int tolua_set_TVisPrimitiveArray_Material_ptr(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Material'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisMaterial",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Material = ((TVisMaterial*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Textured of class  TVisPrimitiveArray */
static int tolua_get_TVisPrimitiveArray_Textured(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Textured'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Textured);
 return 1;
}

/* set function: Textured of class  TVisPrimitiveArray */
static int tolua_set_TVisPrimitiveArray_Textured(lua_State* tolua_S)
{
  TVisPrimitiveArray* self = (TVisPrimitiveArray*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Textured'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Textured = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* method: new of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisPrimitiveObj* tolua_ret = (TVisPrimitiveObj*)  new TVisPrimitiveObj(aOwner);

/* getting type */
  char* lua_type = "TVisPrimitiveObj";
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

/* method: new_local of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisPrimitiveObj* tolua_ret = (TVisPrimitiveObj*)  new TVisPrimitiveObj(aOwner);

/* getting type */
  char* lua_type = "TVisPrimitiveObj";
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

/* method: delete of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Init of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'",NULL);
#endif
  {
   self->Init();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}

/* method: InitPoints of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_InitPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InitPoints'",NULL);
#endif
  {
   self->InitPoints();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InitPoints'.",&tolua_err);
 return 0;
#endif
}

/* method: InitPrimitives of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_InitPrimitives00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InitPrimitives'",NULL);
#endif
  {
   self->InitPrimitives();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InitPrimitives'.",&tolua_err);
 return 0;
#endif
}

/* method: AddIndex of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_AddIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddIndex'",NULL);
#endif
  {
   self->AddIndex(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddIndex'.",&tolua_err);
 return 0;
#endif
}

/* method: AddIndex of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_AddIndex01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int PrimitiveNum = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddIndex'",NULL);
#endif
  {
   self->AddIndex(index,PrimitiveNum);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_VisIt_TVisPrimitiveObj_AddIndex00(tolua_S);
}

/* method: AddPrimitiveArray of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_AddPrimitiveArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int aType = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPrimitiveArray'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddPrimitiveArray(aType);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPrimitiveArray'.",&tolua_err);
 return 0;
#endif
}

/* method: AddPrimitiveObj of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_AddPrimitiveObj00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  TVisPrimitiveObj* aValue = ((TVisPrimitiveObj*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPrimitiveObj'",NULL);
#endif
  {
   int tolua_ret = (int)  self->AddPrimitiveObj(aValue);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPrimitiveObj'.",&tolua_err);
 return 0;
#endif
}

/* method: DeletePrimitiveArray of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_DeletePrimitiveArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeletePrimitiveArray'",NULL);
#endif
  {
   self->DeletePrimitiveArray(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeletePrimitiveArray'.",&tolua_err);
 return 0;
#endif
}

/* method: DeletePrimitiveArray of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_DeletePrimitiveArray01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int count = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeletePrimitiveArray'",NULL);
#endif
  {
   self->DeletePrimitiveArray(index,count);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_VisIt_TVisPrimitiveObj_DeletePrimitiveArray00(tolua_S);
}

/* method: ClearAll of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_ClearAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearAll'",NULL);
#endif
  {
   self->ClearAll();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearAll'.",&tolua_err);
 return 0;
#endif
}

/* method: ClearPoints of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_ClearPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ClearPrimitives of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_ClearPrimitives00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ClearPrimitives'",NULL);
#endif
  {
   self->ClearPrimitives();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ClearPrimitives'.",&tolua_err);
 return 0;
#endif
}

/* method: getNearPoint of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_getNearPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"const TVisMathVector",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int PrimitiveNum = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  const TVisMathVector* Point = ((const TVisMathVector*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNearPoint'",NULL);
#endif
  {
   int tolua_ret = (int)  self->getNearPoint(PrimitiveNum,*Point);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNearPoint'.",&tolua_err);
 return 0;
#endif
}

/* method: SplitTriangle of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_SplitTriangle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int nr = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SplitTriangle'",NULL);
#endif
  {
   self->SplitTriangle(nr,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SplitTriangle'.",&tolua_err);
 return 0;
#endif
}

/* method: CalcNormals of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_CalcNormals00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CalcNormals'",NULL);
#endif
  {
   self->CalcNormals();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CalcNormals'.",&tolua_err);
 return 0;
#endif
}

/* method: CalcTexture of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_CalcTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CalcTexture'",NULL);
#endif
  {
   self->CalcTexture();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CalcTexture'.",&tolua_err);
 return 0;
#endif
}

/* method: CalcTexturePoint of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_CalcTexturePoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CalcTexturePoint'",NULL);
#endif
  {
   self->CalcTexturePoint(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CalcTexturePoint'.",&tolua_err);
 return 0;
#endif
}

/* method: SetReliefBitmap of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_SetReliefBitmap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Graphics::TBitmap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  Graphics::TBitmap* aBitmap = ((Graphics::TBitmap*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  float Height = ((float)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  float RepX = ((float)  tolua_tonumber(tolua_S,4,0));
/*declare*/
  float RepY = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetReliefBitmap'",NULL);
#endif
  {
   self->SetReliefBitmap(aBitmap,Height,RepX,RepY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetReliefBitmap'.",&tolua_err);
 return 0;
#endif
}

/* method: Extrude of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_Extrude00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  double Value = ((double)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int steps = ((int)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  bool smooth = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Extrude'",NULL);
#endif
  {
   self->Extrude(Value,steps,smooth);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Extrude'.",&tolua_err);
 return 0;
#endif
}

/* method: Extrude of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_Extrude01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TVisTexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  double Value = ((double)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int steps = ((int)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  bool smooth = ((bool)  tolua_toboolean(tolua_S,4,0));
/*declare*/
  TVisTexture* texture = ((TVisTexture*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Extrude'",NULL);
#endif
  {
   self->Extrude(Value,steps,smooth,texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_VisIt_TVisPrimitiveObj_Extrude00(tolua_S);
}

/* method: ExtrudeByVec of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_ExtrudeByVec00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TVisMathVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TVisMathVector* vector = ((const TVisMathVector*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  int steps = ((int)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  bool smooth = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ExtrudeByVec'",NULL);
#endif
  {
   self->ExtrudeByVec(*vector,steps,smooth);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ExtrudeByVec'.",&tolua_err);
 return 0;
#endif
}

/* method: ExtrudeByVec of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_ExtrudeByVec01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const TVisMathVector",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"TVisTexture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  const TVisMathVector* vector = ((const TVisMathVector*)  tolua_tousertype(tolua_S,2,0));
/*declare*/
  int steps = ((int)  tolua_tonumber(tolua_S,3,0));
/*declare*/
  bool smooth = ((bool)  tolua_toboolean(tolua_S,4,0));
/*declare*/
  TVisTexture* texture = ((TVisTexture*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ExtrudeByVec'",NULL);
#endif
  {
   self->ExtrudeByVec(*vector,steps,smooth,texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_z_VisIt_TVisPrimitiveObj_ExtrudeByVec00(tolua_S);
}

/* method: Invert of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_Invert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
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

/* method: FreePoints of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_FreePoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
/*declare*/
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
/*declare*/
  int num = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FreePoints'",NULL);
#endif
  {
   self->FreePoints(index,num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FreePoints'.",&tolua_err);
 return 0;
#endif
}

/* method: FreeUnusedPoints of class  TVisPrimitiveObj */
static int tolua_z_VisIt_TVisPrimitiveObj_FreeUnusedPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisPrimitiveObj",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FreeUnusedPoints'",NULL);
#endif
  {
   self->FreeUnusedPoints();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FreeUnusedPoints'.",&tolua_err);
 return 0;
#endif
}

/* get function: Inited of class  TVisPrimitiveObj */
static int tolua_get_TVisPrimitiveObj_Inited(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Inited'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Inited);
 return 1;
}

/* get function: PrimitiveCount of class  TVisPrimitiveObj */
static int tolua_get_TVisPrimitiveObj_PrimitiveCount(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PrimitiveCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->PrimitiveCount);
 return 1;
}

/* get function: AutoCalcNormals of class  TVisPrimitiveObj */
static int tolua_get_TVisPrimitiveObj_AutoCalcNormals(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AutoCalcNormals'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->AutoCalcNormals);
 return 1;
}

/* set function: AutoCalcNormals of class  TVisPrimitiveObj */
static int tolua_set_TVisPrimitiveObj_AutoCalcNormals(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AutoCalcNormals'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->AutoCalcNormals = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: Textured of class  TVisPrimitiveObj */
static int tolua_get_TVisPrimitiveObj_Textured(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Textured'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Textured);
 return 1;
}

/* set function: Textured of class  TVisPrimitiveObj */
static int tolua_set_TVisPrimitiveObj_Textured(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Textured'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Textured = ((bool)  tolua_toboolean(tolua_S,2,0));
 return 0;
}

/* get function: Texture of class  TVisPrimitiveObj */
static int tolua_get_TVisPrimitiveObj_Texture_ptr(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Texture'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisTexture";
   tolua_pushusertype(tolua_S,(void*)(self->Texture),lua_type);
 return 1;
}

/* set function: Texture of class  TVisPrimitiveObj */
static int tolua_set_TVisPrimitiveObj_Texture_ptr(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Texture'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisTexture",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Texture = ((TVisTexture*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: TextureFlags of class  TVisPrimitiveObj */
static int tolua_get_TVisPrimitiveObj_TextureFlags_ptr(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TextureFlags'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisTextureFlags";
   tolua_pushusertype(tolua_S,(void*)(self->TextureFlags),lua_type);
 return 1;
}

/* set function: TextureFlags of class  TVisPrimitiveObj */
static int tolua_set_TVisPrimitiveObj_TextureFlags_ptr(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'TextureFlags'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TVisTextureFlags",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->TextureFlags = ((TVisTextureFlags*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* get function: Points of class  TVisPrimitiveObj */
static int tolua_get_TVisPrimitiveObj_Points_ptr(lua_State* tolua_S)
{
  TVisPrimitiveObj* self = (TVisPrimitiveObj*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Points'",NULL);
#endif

/* getting type */
  char* lua_type = "TVisPrimitivePoints";
   tolua_pushusertype(tolua_S,(void*)(self->Points),lua_type);
 return 1;
}

/* get function: Primitive of class  TVisPrimitiveObj */
static int tolua_get_z_VisIt_TVisPrimitiveObj_Primitive(lua_State* tolua_S)
{
 int tolua_index;
  TVisPrimitiveObj* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (TVisPrimitiveObj*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=LUA_N)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif

/* getting type */
  char* lua_type = "TVisPrimitiveArray";
   tolua_pushusertype(tolua_S,(void*)(self->Primitive[tolua_index]),lua_type);
 return 1;
}

/* method: new of class  TVisCustomView */
static int tolua_z_VisIt_TVisCustomView_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisCustomView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisCustomView* tolua_ret = (TVisCustomView*)  new TVisCustomView(aOwner);

/* getting type */
  char* lua_type = "TVisCustomView";
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

/* method: new_local of class  TVisCustomView */
static int tolua_z_VisIt_TVisCustomView_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisCustomView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisCustomView* tolua_ret = (TVisCustomView*)  new TVisCustomView(aOwner);

/* getting type */
  char* lua_type = "TVisCustomView";
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

/* method: delete of class  TVisCustomView */
static int tolua_z_VisIt_TVisCustomView_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisCustomView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisCustomView* self = (TVisCustomView*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  TVisView */
static int tolua_z_VisIt_TVisView_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisView* tolua_ret = (TVisView*)  new TVisView(aOwner);

/* getting type */
  char* lua_type = "TVisView";
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

/* method: new_local of class  TVisView */
static int tolua_z_VisIt_TVisView_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TVisView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
/*declare*/
  TComponent* aOwner = ((TComponent*)  tolua_tousertype(tolua_S,2,0));
  {
   TVisView* tolua_ret = (TVisView*)  new TVisView(aOwner);

/* getting type */
  char* lua_type = "TVisView";
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

/* method: delete of class  TVisView */
static int tolua_z_VisIt_TVisView_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TVisView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TVisView* self = (TVisView*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_z_VisIt_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_module(tolua_S,"VisConst",1);
 tolua_beginmodule(tolua_S,"VisConst");
 tolua_constant(tolua_S,"clMin",clMin);
 tolua_constant(tolua_S,"clMax",clMax);
 tolua_constant(tolua_S,"toRotTraSca",toRotTraSca);
 tolua_constant(tolua_S,"toRotScaTra",toRotScaTra);
 tolua_constant(tolua_S,"toTraRotSca",toTraRotSca);
 tolua_constant(tolua_S,"toTraScaRot",toTraScaRot);
 tolua_constant(tolua_S,"toScaRotTra",toScaRotTra);
 tolua_constant(tolua_S,"toScaTraRot",toScaTraRot);
 tolua_constant(tolua_S,"tmModulate",tmModulate);
 tolua_constant(tolua_S,"tmDecal",tmDecal);
 tolua_constant(tolua_S,"tmBlend",tmBlend);
 tolua_constant(tolua_S,"tmReplace",tmReplace);
 tolua_constant(tolua_S,"tfNearest",tfNearest);
 tolua_constant(tolua_S,"tfLinear",tfLinear);
 tolua_constant(tolua_S,"tfNearest_Nearest",tfNearest_Nearest);
 tolua_constant(tolua_S,"tfLinear_Nearest",tfLinear_Nearest);
 tolua_constant(tolua_S,"tfNearest_Linear",tfNearest_Linear);
 tolua_constant(tolua_S,"tfLinear_Linear",tfLinear_Linear);
 tolua_constant(tolua_S,"pmPoint",pmPoint);
 tolua_constant(tolua_S,"pmLine",pmLine);
 tolua_constant(tolua_S,"pmFill",pmFill);
 tolua_constant(tolua_S,"cfNone",cfNone);
 tolua_constant(tolua_S,"cfFront",cfFront);
 tolua_constant(tolua_S,"cfBack",cfBack);
 tolua_constant(tolua_S,"smFlat",smFlat);
 tolua_constant(tolua_S,"smSmooth",smSmooth);
 tolua_constant(tolua_S,"tmNone",tmNone);
 tolua_constant(tolua_S,"tmAlpha",tmAlpha);
 tolua_constant(tolua_S,"tmAddAlpha",tmAddAlpha);
 tolua_constant(tolua_S,"tmAddColor",tmAddColor);
 tolua_constant(tolua_S,"tmSubColor",tmSubColor);
 tolua_constant(tolua_S,"daStandard",daStandard);
 tolua_constant(tolua_S,"daForeground",daForeground);
 tolua_constant(tolua_S,"daBackground",daBackground);
 tolua_constant(tolua_S,"lsClear",lsClear);
 tolua_constant(tolua_S,"lsDash",lsDash);
 tolua_constant(tolua_S,"lsDot",lsDot);
 tolua_constant(tolua_S,"lsDashDot",lsDashDot);
 tolua_constant(tolua_S,"lsDashDotDot",lsDashDotDot);
 tolua_constant(tolua_S,"lsSolid",lsSolid);
 tolua_constant(tolua_S,"quFastest",quFastest);
 tolua_constant(tolua_S,"quNicest",quNicest);
 tolua_constant(tolua_S,"quDontCare",quDontCare);
 tolua_constant(tolua_S,"fmLinear",fmLinear);
 tolua_constant(tolua_S,"fmExp",fmExp);
 tolua_constant(tolua_S,"fmExp2",fmExp2);
 tolua_constant(tolua_S,"txStandard",txStandard);
 tolua_constant(tolua_S,"txLinearX",txLinearX);
 tolua_constant(tolua_S,"txLinearY",txLinearY);
 tolua_constant(tolua_S,"txLinearZ",txLinearZ);
 tolua_constant(tolua_S,"txLinearXY",txLinearXY);
 tolua_constant(tolua_S,"txLinearYZ",txLinearYZ);
 tolua_constant(tolua_S,"txLinearZX",txLinearZX);
 tolua_constant(tolua_S,"txLinearYX",txLinearYX);
 tolua_constant(tolua_S,"txLinearZY",txLinearZY);
 tolua_constant(tolua_S,"txLinearXZ",txLinearXZ);
 tolua_constant(tolua_S,"txSphereZ",txSphereZ);
 tolua_constant(tolua_S,"txByNormal",txByNormal);
 tolua_constant(tolua_S,"cmNone",cmNone);
 tolua_constant(tolua_S,"cmAmbient",cmAmbient);
 tolua_constant(tolua_S,"cmDiffuse",cmDiffuse);
 tolua_constant(tolua_S,"cmSpecular",cmSpecular);
 tolua_constant(tolua_S,"cmEmission",cmEmission);
 tolua_constant(tolua_S,"cmAmbientDiffuse",cmAmbientDiffuse);
 tolua_variable(tolua_S,"GL_POINTS",tolua_get_VisConst_GL_POINTS,NULL);
 tolua_variable(tolua_S,"GL_LINES",tolua_get_VisConst_GL_LINES,NULL);
 tolua_variable(tolua_S,"GL_LINE_LOOP",tolua_get_VisConst_GL_LINE_LOOP,NULL);
 tolua_variable(tolua_S,"GL_LINE_STRIP",tolua_get_VisConst_GL_LINE_STRIP,NULL);
 tolua_variable(tolua_S,"GL_TRIANGLES",tolua_get_VisConst_GL_TRIANGLES,NULL);
 tolua_variable(tolua_S,"GL_TRIANGLE_STRIP",tolua_get_VisConst_GL_TRIANGLE_STRIP,NULL);
 tolua_variable(tolua_S,"GL_TRIANGLE_FAN",tolua_get_VisConst_GL_TRIANGLE_FAN,NULL);
 tolua_variable(tolua_S,"GL_QUADS",tolua_get_VisConst_GL_QUADS,NULL);
 tolua_variable(tolua_S,"GL_QUAD_STRIP",tolua_get_VisConst_GL_QUAD_STRIP,NULL);
 tolua_variable(tolua_S,"GL_POLYGON",tolua_get_VisConst_GL_POLYGON,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisMathVector","TVisMathVector","",tolua_collect_TVisMathVector);
#else
 tolua_cclass(tolua_S,"TVisMathVector","TVisMathVector","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisMathVector");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisMathVector_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisMathVector_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisMathVector_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisMathVector_delete00);
 tolua_variable(tolua_S,"x",tolua_get_TVisMathVector_x,tolua_set_TVisMathVector_x);
 tolua_variable(tolua_S,"y",tolua_get_TVisMathVector_y,tolua_set_TVisMathVector_y);
 tolua_variable(tolua_S,"z",tolua_get_TVisMathVector_z,tolua_set_TVisMathVector_z);
 tolua_array(tolua_S,"a",tolua_get_z_VisIt_TVisMathVector_a,tolua_set_z_VisIt_TVisMathVector_a);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"ToVec",tolua_z_VisIt_ToVec00);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisProperty","TVisProperty","",tolua_collect_TVisProperty);
#else
 tolua_cclass(tolua_S,"TVisProperty","TVisProperty","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisProperty");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisProperty_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisProperty_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisProperty_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisProperty_delete00);
 tolua_function(tolua_S,"Assign",tolua_z_VisIt_TVisProperty_Assign00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisVector","TVisVector","TVisProperty",tolua_collect_TVisVector);
#else
 tolua_cclass(tolua_S,"TVisVector","TVisVector","TVisProperty",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisVector");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisVector_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisVector_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisVector_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisVector_delete00);
 tolua_variable(tolua_S,"AsMathVector",tolua_get_TVisVector_AsMathVector,tolua_set_TVisVector_AsMathVector);
 tolua_function(tolua_S,"incX",tolua_z_VisIt_TVisVector_incX00);
 tolua_function(tolua_S,"incY",tolua_z_VisIt_TVisVector_incY00);
 tolua_function(tolua_S,"incZ",tolua_z_VisIt_TVisVector_incZ00);
 tolua_function(tolua_S,"SetValues",tolua_z_VisIt_TVisVector_SetValues00);
 tolua_variable(tolua_S,"X",tolua_get_TVisVector_X,tolua_set_TVisVector_X);
 tolua_variable(tolua_S,"Y",tolua_get_TVisVector_Y,tolua_set_TVisVector_Y);
 tolua_variable(tolua_S,"Z",tolua_get_TVisVector_Z,tolua_set_TVisVector_Z);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisColor","TVisColor","TVisProperty",tolua_collect_TVisColor);
#else
 tolua_cclass(tolua_S,"TVisColor","TVisColor","TVisProperty",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisColor");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisColor_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisColor_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisColor_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisColor_delete00);
 tolua_variable(tolua_S,"Color",tolua_get_TVisColor_Color,tolua_set_TVisColor_Color);
 tolua_variable(tolua_S,"Alpha",tolua_get_TVisColor_Alpha,tolua_set_TVisColor_Alpha);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"mfFront",mfFront);
 tolua_constant(tolua_S,"mfBack",mfBack);
 tolua_constant(tolua_S,"mfFrontBack",mfFrontBack);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisMaterial","TVisMaterial","TVisRender",tolua_collect_TVisMaterial);
#else
 tolua_cclass(tolua_S,"TVisMaterial","TVisMaterial","TVisRender",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisMaterial");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisMaterial_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisMaterial_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisMaterial_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisMaterial_delete00);
 tolua_variable(tolua_S,"Face",tolua_get_TVisMaterial_Face,tolua_set_TVisMaterial_Face);
 tolua_variable(tolua_S,"ColorAmbient",tolua_get_TVisMaterial_ColorAmbient_ptr,tolua_set_TVisMaterial_ColorAmbient_ptr);
 tolua_variable(tolua_S,"ColorDiffuse",tolua_get_TVisMaterial_ColorDiffuse_ptr,tolua_set_TVisMaterial_ColorDiffuse_ptr);
 tolua_variable(tolua_S,"ColorSpecular",tolua_get_TVisMaterial_ColorSpecular_ptr,tolua_set_TVisMaterial_ColorSpecular_ptr);
 tolua_variable(tolua_S,"ColorEmission",tolua_get_TVisMaterial_ColorEmission_ptr,tolua_set_TVisMaterial_ColorEmission_ptr);
 tolua_variable(tolua_S,"Shininess",tolua_get_TVisMaterial_Shininess,tolua_set_TVisMaterial_Shininess);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisTexture","TVisTexture","TVisRender",tolua_collect_TVisTexture);
#else
 tolua_cclass(tolua_S,"TVisTexture","TVisTexture","TVisRender",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisTexture");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisTexture_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisTexture_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisTexture_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisTexture_delete00);
 tolua_function(tolua_S,"SetAlphaBitmap",tolua_z_VisIt_TVisTexture_SetAlphaBitmap00);
 tolua_function(tolua_S,"SetMaskAlpha",tolua_z_VisIt_TVisTexture_SetMaskAlpha00);
 tolua_function(tolua_S,"Invalidate",tolua_z_VisIt_TVisTexture_Invalidate00);
 tolua_function(tolua_S,"BitmapChange",tolua_z_VisIt_TVisTexture_BitmapChange00);
 tolua_function(tolua_S,"AddMipMap",tolua_z_VisIt_TVisTexture_AddMipMap00);
 tolua_function(tolua_S,"ClearMipMaps",tolua_z_VisIt_TVisTexture_ClearMipMaps00);
 tolua_variable(tolua_S,"MinFilter",tolua_get_TVisTexture_MinFilter,tolua_set_TVisTexture_MinFilter);
 tolua_variable(tolua_S,"MagFilter",tolua_get_TVisTexture_MagFilter,tolua_set_TVisTexture_MagFilter);
 tolua_variable(tolua_S,"Bitmap",tolua_get_TVisTexture_Bitmap_ptr,tolua_set_TVisTexture_Bitmap_ptr);
 tolua_variable(tolua_S,"Alpha",tolua_get_TVisTexture_Alpha,tolua_set_TVisTexture_Alpha);
 tolua_variable(tolua_S,"Mode",tolua_get_TVisTexture_Mode,tolua_set_TVisTexture_Mode);
 tolua_variable(tolua_S,"BlendColor",tolua_get_TVisTexture_BlendColor_ptr,tolua_set_TVisTexture_BlendColor_ptr);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisTextureFlags","TVisTextureFlags","TVisProperty",tolua_collect_TVisTextureFlags);
#else
 tolua_cclass(tolua_S,"TVisTextureFlags","TVisTextureFlags","TVisProperty",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisTextureFlags");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisTextureFlags_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisTextureFlags_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisTextureFlags_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisTextureFlags_delete00);
 tolua_variable(tolua_S,"Mode",tolua_get_TVisTextureFlags_Mode,tolua_set_TVisTextureFlags_Mode);
 tolua_variable(tolua_S,"ShiftX",tolua_get_TVisTextureFlags_ShiftX,tolua_set_TVisTextureFlags_ShiftX);
 tolua_variable(tolua_S,"ShiftY",tolua_get_TVisTextureFlags_ShiftY,tolua_set_TVisTextureFlags_ShiftY);
 tolua_variable(tolua_S,"ScaleX",tolua_get_TVisTextureFlags_ScaleX,tolua_set_TVisTextureFlags_ScaleX);
 tolua_variable(tolua_S,"ScaleY",tolua_get_TVisTextureFlags_ScaleY,tolua_set_TVisTextureFlags_ScaleY);
 tolua_variable(tolua_S,"ParamVector",tolua_get_TVisTextureFlags_ParamVector_ptr,tolua_set_TVisTextureFlags_ParamVector_ptr);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisAttributes","TVisAttributes","TVisRender",tolua_collect_TVisAttributes);
#else
 tolua_cclass(tolua_S,"TVisAttributes","TVisAttributes","TVisRender",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisAttributes");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisAttributes_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisAttributes_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisAttributes_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisAttributes_delete00);
 tolua_variable(tolua_S,"StippleShift",tolua_get_TVisAttributes_StippleShift,tolua_set_TVisAttributes_StippleShift);
 tolua_variable(tolua_S,"StippleScale",tolua_get_TVisAttributes_StippleScale,tolua_set_TVisAttributes_StippleScale);
 tolua_variable(tolua_S,"Antialiasing",tolua_get_TVisAttributes_Antialiasing,tolua_set_TVisAttributes_Antialiasing);
 tolua_variable(tolua_S,"ColorAmbient",tolua_get_TVisAttributes_ColorAmbient_ptr,tolua_set_TVisAttributes_ColorAmbient_ptr);
 tolua_variable(tolua_S,"CullFace",tolua_get_TVisAttributes_CullFace,tolua_set_TVisAttributes_CullFace);
 tolua_variable(tolua_S,"Dithering",tolua_get_TVisAttributes_Dithering,tolua_set_TVisAttributes_Dithering);
 tolua_variable(tolua_S,"Lighting",tolua_get_TVisAttributes_Lighting,tolua_set_TVisAttributes_Lighting);
 tolua_variable(tolua_S,"LightTwoSide",tolua_get_TVisAttributes_LightTwoSide,tolua_set_TVisAttributes_LightTwoSide);
 tolua_variable(tolua_S,"PolygonMode",tolua_get_TVisAttributes_PolygonMode,tolua_set_TVisAttributes_PolygonMode);
 tolua_variable(tolua_S,"PerspectiveCorrection",tolua_get_TVisAttributes_PerspectiveCorrection,tolua_set_TVisAttributes_PerspectiveCorrection);
 tolua_variable(tolua_S,"ShadeModel",tolua_get_TVisAttributes_ShadeModel,tolua_set_TVisAttributes_ShadeModel);
 tolua_variable(tolua_S,"Transparency",tolua_get_TVisAttributes_Transparency,tolua_set_TVisAttributes_Transparency);
 tolua_variable(tolua_S,"LineStipple",tolua_get_TVisAttributes_LineStipple,tolua_set_TVisAttributes_LineStipple);
 tolua_variable(tolua_S,"PointSize",tolua_get_TVisAttributes_PointSize,tolua_set_TVisAttributes_PointSize);
 tolua_variable(tolua_S,"LineWidth",tolua_get_TVisAttributes_LineWidth,tolua_set_TVisAttributes_LineWidth);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisRotation","TVisRotation","TVisTransform",tolua_collect_TVisRotation);
#else
 tolua_cclass(tolua_S,"TVisRotation","TVisRotation","TVisTransform",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisRotation");
 tolua_function(tolua_S,"Execute",tolua_z_VisIt_TVisRotation_Execute00);
 tolua_variable(tolua_S,"Order",tolua_get_TVisRotation_Order,tolua_set_TVisRotation_Order);
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisRotation_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisRotation_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisRotation_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisRotation_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisScale","TVisScale","TVisTransform",tolua_collect_TVisScale);
#else
 tolua_cclass(tolua_S,"TVisScale","TVisScale","TVisTransform",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisScale");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisScale_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisScale_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisScale_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisScale_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisTranslation","TVisTranslation","TVisTransform",tolua_collect_TVisTranslation);
#else
 tolua_cclass(tolua_S,"TVisTranslation","TVisTranslation","TVisTransform",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisTranslation");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisTranslation_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisTranslation_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisTranslation_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisTranslation_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisTransformation","TVisTransformation","TVisProperty",tolua_collect_TVisTransformation);
#else
 tolua_cclass(tolua_S,"TVisTransformation","TVisTransformation","TVisProperty",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisTransformation");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisTransformation_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisTransformation_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisTransformation_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisTransformation_delete00);
 tolua_function(tolua_S,"Execute",tolua_z_VisIt_TVisTransformation_Execute00);
 tolua_variable(tolua_S,"Empty",tolua_get_TVisTransformation_Empty,NULL);
 tolua_variable(tolua_S,"Rotation",tolua_get_TVisTransformation_Rotation_ptr,tolua_set_TVisTransformation_Rotation_ptr);
 tolua_variable(tolua_S,"Scale",tolua_get_TVisTransformation_Scale_ptr,tolua_set_TVisTransformation_Scale_ptr);
 tolua_variable(tolua_S,"Translation",tolua_get_TVisTransformation_Translation_ptr,tolua_set_TVisTransformation_Translation_ptr);
 tolua_variable(tolua_S,"Order",tolua_get_TVisTransformation_Order,tolua_set_TVisTransformation_Order);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisRender","TVisRender","TVisTransformed",tolua_collect_TVisRender);
#else
 tolua_cclass(tolua_S,"TVisRender","TVisRender","TVisTransformed",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisRender");
 tolua_function(tolua_S,"SetNodeDirect",tolua_z_VisIt_TVisRender_SetNodeDirect00);
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisRender_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisRender_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisRender_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisRender_delete00);
 tolua_function(tolua_S,"Render",tolua_z_VisIt_TVisRender_Render00);
 tolua_variable(tolua_S,"Enabled",tolua_get_TVisRender_Enabled,tolua_set_TVisRender_Enabled);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisObject","TVisObject","TVisRender",tolua_collect_TVisObject);
#else
 tolua_cclass(tolua_S,"TVisObject","TVisObject","TVisRender",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisObject");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisObject_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisObject_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisObject_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisObject_delete00);
 tolua_variable(tolua_S,"ColorAsMaterial",tolua_get_TVisObject_ColorAsMaterial,tolua_set_TVisObject_ColorAsMaterial);
 tolua_variable(tolua_S,"Color",tolua_get_TVisObject_Color_ptr,tolua_set_TVisObject_Color_ptr);
 tolua_variable(tolua_S,"Attributes",tolua_get_TVisObject_Attributes_ptr,tolua_set_TVisObject_Attributes_ptr);
 tolua_variable(tolua_S,"Material",tolua_get_TVisObject_Material_ptr,tolua_set_TVisObject_Material_ptr);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisPrimitivePoints","TVisPrimitivePoints","TVisProperty",tolua_collect_TVisPrimitivePoints);
#else
 tolua_cclass(tolua_S,"TVisPrimitivePoints","TVisPrimitivePoints","TVisProperty",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisPrimitivePoints");
 tolua_function(tolua_S,".geti",tolua_z_VisIt_TVisPrimitivePoints__geti00);
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisPrimitivePoints_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisPrimitivePoints_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisPrimitivePoints_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisPrimitivePoints_delete00);
 tolua_function(tolua_S,"Add",tolua_z_VisIt_TVisPrimitivePoints_Add00);
 tolua_function(tolua_S,"Add",tolua_z_VisIt_TVisPrimitivePoints_Add01);
 tolua_function(tolua_S,"Add",tolua_z_VisIt_TVisPrimitivePoints_Add02);
 tolua_function(tolua_S,"Add",tolua_z_VisIt_TVisPrimitivePoints_Add03);
 tolua_function(tolua_S,"Delete",tolua_z_VisIt_TVisPrimitivePoints_Delete00);
 tolua_function(tolua_S,"GetPoint",tolua_z_VisIt_TVisPrimitivePoints_GetPoint00);
 tolua_function(tolua_S,"SetPoint",tolua_z_VisIt_TVisPrimitivePoints_SetPoint00);
 tolua_function(tolua_S,"LiftPoint",tolua_z_VisIt_TVisPrimitivePoints_LiftPoint00);
 tolua_function(tolua_S,"ScalePoints",tolua_z_VisIt_TVisPrimitivePoints_ScalePoints00);
 tolua_function(tolua_S,"MovePoints",tolua_z_VisIt_TVisPrimitivePoints_MovePoints00);
 tolua_variable(tolua_S,"Size",tolua_get_TVisPrimitivePoints_Size,tolua_set_TVisPrimitivePoints_Size);
 tolua_variable(tolua_S,"Count",tolua_get_TVisPrimitivePoints_Count,tolua_set_TVisPrimitivePoints_Count);
 tolua_array(tolua_S,"PointVec",tolua_get_z_VisIt_TVisPrimitivePoints_PointVec,tolua_set_z_VisIt_TVisPrimitivePoints_PointVec);
 tolua_array(tolua_S,"NormalVec",tolua_get_z_VisIt_TVisPrimitivePoints_NormalVec,tolua_set_z_VisIt_TVisPrimitivePoints_NormalVec);
 tolua_array(tolua_S,"TextureVec",tolua_get_z_VisIt_TVisPrimitivePoints_TextureVec,tolua_set_z_VisIt_TVisPrimitivePoints_TextureVec);
 tolua_array(tolua_S,"EdgeFlag",tolua_get_z_VisIt_TVisPrimitivePoints_EdgeFlag,tolua_set_z_VisIt_TVisPrimitivePoints_EdgeFlag);
 tolua_array(tolua_S,"ShareLight",tolua_get_z_VisIt_TVisPrimitivePoints_ShareLight,tolua_set_z_VisIt_TVisPrimitivePoints_ShareLight);
 tolua_array(tolua_S,"SharePosition",tolua_get_z_VisIt_TVisPrimitivePoints_SharePosition,tolua_set_z_VisIt_TVisPrimitivePoints_SharePosition);
 tolua_array(tolua_S,"CloseFlag",tolua_get_z_VisIt_TVisPrimitivePoints_CloseFlag,tolua_set_z_VisIt_TVisPrimitivePoints_CloseFlag);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisPrimitiveArray","TVisPrimitiveArray","TVisProperty",tolua_collect_TVisPrimitiveArray);
#else
 tolua_cclass(tolua_S,"TVisPrimitiveArray","TVisPrimitiveArray","TVisProperty",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisPrimitiveArray");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisPrimitiveArray_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisPrimitiveArray_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisPrimitiveArray_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisPrimitiveArray_delete00);
 tolua_function(tolua_S,"AddIndex",tolua_z_VisIt_TVisPrimitiveArray_AddIndex00);
 tolua_function(tolua_S,"Add",tolua_z_VisIt_TVisPrimitiveArray_Add00);
 tolua_function(tolua_S,"Insert",tolua_z_VisIt_TVisPrimitiveArray_Insert00);
 tolua_function(tolua_S,"Delete",tolua_z_VisIt_TVisPrimitiveArray_Delete00);
 tolua_function(tolua_S,"Assign",tolua_z_VisIt_TVisPrimitiveArray_Assign00);
 tolua_function(tolua_S,"Invert",tolua_z_VisIt_TVisPrimitiveArray_Invert00);
 tolua_function(tolua_S,"ProceedDirectRendering",tolua_z_VisIt_TVisPrimitiveArray_ProceedDirectRendering00);
 tolua_array(tolua_S,"Indices",tolua_get_z_VisIt_TVisPrimitiveArray_Indices,tolua_set_z_VisIt_TVisPrimitiveArray_Indices);
 tolua_variable(tolua_S,"Size",tolua_get_TVisPrimitiveArray_Size,tolua_set_TVisPrimitiveArray_Size);
 tolua_variable(tolua_S,"Count",tolua_get_TVisPrimitiveArray_Count,tolua_set_TVisPrimitiveArray_Count);
 tolua_variable(tolua_S,"Enabled",tolua_get_TVisPrimitiveArray_Enabled,tolua_set_TVisPrimitiveArray_Enabled);
 tolua_variable(tolua_S,"PrimitiveType",tolua_get_TVisPrimitiveArray_PrimitiveType,tolua_set_TVisPrimitiveArray_PrimitiveType);
 tolua_variable(tolua_S,"Texture",tolua_get_TVisPrimitiveArray_Texture_ptr,tolua_set_TVisPrimitiveArray_Texture_ptr);
 tolua_variable(tolua_S,"Color",tolua_get_TVisPrimitiveArray_Color_ptr,tolua_set_TVisPrimitiveArray_Color_ptr);
 tolua_variable(tolua_S,"ColorAsMaterial",tolua_get_TVisPrimitiveArray_ColorAsMaterial,tolua_set_TVisPrimitiveArray_ColorAsMaterial);
 tolua_variable(tolua_S,"Material",tolua_get_TVisPrimitiveArray_Material_ptr,tolua_set_TVisPrimitiveArray_Material_ptr);
 tolua_variable(tolua_S,"Textured",tolua_get_TVisPrimitiveArray_Textured,tolua_set_TVisPrimitiveArray_Textured);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisPrimitiveObj","TVisPrimitiveObj","TVisObject",tolua_collect_TVisPrimitiveObj);
#else
 tolua_cclass(tolua_S,"TVisPrimitiveObj","TVisPrimitiveObj","TVisObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisPrimitiveObj");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisPrimitiveObj_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisPrimitiveObj_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisPrimitiveObj_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisPrimitiveObj_delete00);
 tolua_function(tolua_S,"Init",tolua_z_VisIt_TVisPrimitiveObj_Init00);
 tolua_function(tolua_S,"InitPoints",tolua_z_VisIt_TVisPrimitiveObj_InitPoints00);
 tolua_function(tolua_S,"InitPrimitives",tolua_z_VisIt_TVisPrimitiveObj_InitPrimitives00);
 tolua_function(tolua_S,"AddIndex",tolua_z_VisIt_TVisPrimitiveObj_AddIndex00);
 tolua_function(tolua_S,"AddIndex",tolua_z_VisIt_TVisPrimitiveObj_AddIndex01);
 tolua_function(tolua_S,"AddPrimitiveArray",tolua_z_VisIt_TVisPrimitiveObj_AddPrimitiveArray00);
 tolua_function(tolua_S,"AddPrimitiveObj",tolua_z_VisIt_TVisPrimitiveObj_AddPrimitiveObj00);
 tolua_function(tolua_S,"DeletePrimitiveArray",tolua_z_VisIt_TVisPrimitiveObj_DeletePrimitiveArray00);
 tolua_function(tolua_S,"DeletePrimitiveArray",tolua_z_VisIt_TVisPrimitiveObj_DeletePrimitiveArray01);
 tolua_function(tolua_S,"ClearAll",tolua_z_VisIt_TVisPrimitiveObj_ClearAll00);
 tolua_function(tolua_S,"ClearPoints",tolua_z_VisIt_TVisPrimitiveObj_ClearPoints00);
 tolua_function(tolua_S,"ClearPrimitives",tolua_z_VisIt_TVisPrimitiveObj_ClearPrimitives00);
 tolua_function(tolua_S,"getNearPoint",tolua_z_VisIt_TVisPrimitiveObj_getNearPoint00);
 tolua_function(tolua_S,"SplitTriangle",tolua_z_VisIt_TVisPrimitiveObj_SplitTriangle00);
 tolua_function(tolua_S,"CalcNormals",tolua_z_VisIt_TVisPrimitiveObj_CalcNormals00);
 tolua_function(tolua_S,"CalcTexture",tolua_z_VisIt_TVisPrimitiveObj_CalcTexture00);
 tolua_function(tolua_S,"CalcTexturePoint",tolua_z_VisIt_TVisPrimitiveObj_CalcTexturePoint00);
 tolua_function(tolua_S,"SetReliefBitmap",tolua_z_VisIt_TVisPrimitiveObj_SetReliefBitmap00);
 tolua_function(tolua_S,"Extrude",tolua_z_VisIt_TVisPrimitiveObj_Extrude00);
 tolua_function(tolua_S,"Extrude",tolua_z_VisIt_TVisPrimitiveObj_Extrude01);
 tolua_function(tolua_S,"ExtrudeByVec",tolua_z_VisIt_TVisPrimitiveObj_ExtrudeByVec00);
 tolua_function(tolua_S,"ExtrudeByVec",tolua_z_VisIt_TVisPrimitiveObj_ExtrudeByVec01);
 tolua_function(tolua_S,"Invert",tolua_z_VisIt_TVisPrimitiveObj_Invert00);
 tolua_function(tolua_S,"FreePoints",tolua_z_VisIt_TVisPrimitiveObj_FreePoints00);
 tolua_function(tolua_S,"FreeUnusedPoints",tolua_z_VisIt_TVisPrimitiveObj_FreeUnusedPoints00);
 tolua_variable(tolua_S,"Inited",tolua_get_TVisPrimitiveObj_Inited,NULL);
 tolua_variable(tolua_S,"PrimitiveCount",tolua_get_TVisPrimitiveObj_PrimitiveCount,NULL);
 tolua_variable(tolua_S,"AutoCalcNormals",tolua_get_TVisPrimitiveObj_AutoCalcNormals,tolua_set_TVisPrimitiveObj_AutoCalcNormals);
 tolua_variable(tolua_S,"Textured",tolua_get_TVisPrimitiveObj_Textured,tolua_set_TVisPrimitiveObj_Textured);
 tolua_variable(tolua_S,"Texture",tolua_get_TVisPrimitiveObj_Texture_ptr,tolua_set_TVisPrimitiveObj_Texture_ptr);
 tolua_variable(tolua_S,"TextureFlags",tolua_get_TVisPrimitiveObj_TextureFlags_ptr,tolua_set_TVisPrimitiveObj_TextureFlags_ptr);
 tolua_variable(tolua_S,"Points",tolua_get_TVisPrimitiveObj_Points_ptr,NULL);
 tolua_array(tolua_S,"Primitive",tolua_get_z_VisIt_TVisPrimitiveObj_Primitive,NULL);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisCustomView","TVisCustomView","",tolua_collect_TVisCustomView);
#else
 tolua_cclass(tolua_S,"TVisCustomView","TVisCustomView","",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisCustomView");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisCustomView_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisCustomView_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisCustomView_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisCustomView_delete00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TVisView","TVisView","TVisCustomView",tolua_collect_TVisView);
#else
 tolua_cclass(tolua_S,"TVisView","TVisView","TVisCustomView",NULL);
#endif
 tolua_beginmodule(tolua_S,"TVisView");
 tolua_function(tolua_S,"new",tolua_z_VisIt_TVisView_new00);
 tolua_function(tolua_S,"new_local",tolua_z_VisIt_TVisView_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_VisIt_TVisView_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_VisIt_TVisView_delete00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
