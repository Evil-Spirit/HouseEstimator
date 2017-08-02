/*
** Lua binding: z_Pointer
** Generated automatically by tolua++-1.0.3 on 12/09/04 19:36:20.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_z_Pointer_open (lua_State* tolua_S);

#include <vcl.h>
#include "Usefuls.h"                 
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
#include "ElementV.h"
/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_TPointer_TElement_ (lua_State* tolua_S)
{
 TPointer<TElement>* self = (TPointer<TElement>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TElement");
 tolua_usertype(tolua_S,"TPointer<TElement>");
 tolua_usertype(tolua_S,"TMyObject");
}

/* method: new of class  TPointer<TElement> */
static int tolua_z_Pointer_TPointer_TElement__new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TPointer<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TPointer<TElement>* tolua_ret = (TPointer<TElement>*)  new TPointer<TElement>();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TPointer<TElement>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TPointer<TElement> */
static int tolua_z_Pointer_TPointer_TElement__new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TPointer<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TPointer<TElement>* tolua_ret = (TPointer<TElement>*)  new TPointer<TElement>();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TPointer<TElement>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TPointer<TElement> */
static int tolua_z_Pointer_TPointer_TElement__delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TPointer<TElement>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TPointer<TElement>* self = (TPointer<TElement>*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: ADR of class  TPointer<TElement> */
static int tolua_get_TPointer_TElement__ADR_ptr(lua_State* tolua_S)
{
  TPointer<TElement>* self = (TPointer<TElement>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ADR'",NULL);
#endif
  tolua_pushusertype(tolua_S,(void*)(self->ADR),(self->ADR) ? self->ADR->DynamicType->Name.c_str() : "TElement");
 return 1;
}

/* set function: ADR of class  TPointer<TElement> */
static int tolua_set_TPointer_TElement__ADR_ptr(lua_State* tolua_S)
{
  TPointer<TElement>* self = (TPointer<TElement>*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ADR'",NULL);
  if (!tolua_isusertype(tolua_S,2,"TElement",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ADR = ((TElement*)  tolua_tousertype(tolua_S,2,0));
 return 0;
}

/* Open function */
TOLUA_API int tolua_z_Pointer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TPointer_TElement_","TPointer<TElement>","TMyObject",tolua_collect_TPointer_TElement_);
#else
 tolua_cclass(tolua_S,"TPointer_TElement_","TPointer<TElement>","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TPointer_TElement_");
 tolua_function(tolua_S,"new",tolua_z_Pointer_TPointer_TElement__new00);
 tolua_function(tolua_S,"new_local",tolua_z_Pointer_TPointer_TElement__new00_local);
 tolua_set_call_event(tolua_S,tolua_z_Pointer_TPointer_TElement__new00_local);
 tolua_function(tolua_S,"delete",tolua_z_Pointer_TPointer_TElement__delete00);
 tolua_variable(tolua_S,"ADR",tolua_get_TPointer_TElement__ADR_ptr,tolua_set_TPointer_TElement__ADR_ptr);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}
