/*
** Lua binding: z_Attributes
** Generated automatically by tolua++-1.0.3 on 11/25/04 17:51:40.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_z_Attributes_open (lua_State* tolua_S);

#include <vcl.h>
#include "Usefuls.h"                 
#include "MTL.h"
#include "MyTemplates.h"
#pragma hdrstop
#define LUA_N = 1<<31;
#include "LuaAttributeV.h"
#include "LuaEnvV.h"
#include "LuaModuleV.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

/*void PUSH(lua_State* tolua_S,int Type,void* Address)
{
    switch(Type)
    {
        case mtInt:
            tolua_pushnumber(tolua_S, *((int*)Address) );
        break;
        case mtString:
            tolua_pushstring(tolua_S, ((AnsiString*)Address)->c_str() );
        break;
        case mtCharString:
            tolua_pushstring(tolua_S, (char*)Address );
        break;
        case mtMyObject:
            tolua_pushusertype(tolua_S,Address, (Address!= NULL) ? ((TMyObject*)Address)->DynamicType->Name.c_str() : "TMyObject" );
        break;
        case mtFloat:
            tolua_pushnumber(tolua_S, *((float*)Address) );
        break;
        case mtDouble:
            tolua_pushnumber(tolua_S, *((double*)Address) );
        break;
        case mtBool:
            tolua_pushboolean(tolua_S, *((bool*)Address) );
        break;
        default:
            tolua_pushuserdata(tolua_S,Address);
        break;
    }
}

void PUSHATTRIBUTE(lua_State* tolua_S,TLuaAttribute* LA)
{
    PUSH(tolua_S,LA->Type,LA->Value);
}  */

static int tolua_collect_TLuaAttribute (lua_State* tolua_S)
{
 TLuaAttribute* self = (TLuaAttribute*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_TLuaAttributeList (lua_State* tolua_S)
{
 TLuaAttributeList* self = (TLuaAttributeList*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TLuaAttribute");
 tolua_usertype(tolua_S,"TLuaAttributeList");
 tolua_usertype(tolua_S,"TMyObject");
}

/* method: new of class  TLuaAttribute */
static int tolua_z_Attributes_TLuaAttribute_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLuaAttribute",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  new TLuaAttribute();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLuaAttribute");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLuaAttribute */
static int tolua_z_Attributes_TLuaAttribute_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLuaAttribute",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  new TLuaAttribute();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TLuaAttribute");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLuaAttribute */
static int tolua_z_Attributes_TLuaAttribute_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttribute",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttribute* self = (TLuaAttribute*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: Value of class  TLuaAttribute */
static int tolua_get_TLuaAttribute_Value(lua_State* tolua_S)
{
  TLuaAttribute* self = (TLuaAttribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Value'",NULL);
#endif
    PUSHATTRIBUTE(tolua_S,self);
 return 1;
}

/* set function: Value of class  TLuaAttribute */
static int tolua_set_TLuaAttribute_Value(lua_State* tolua_S)
{
  TLuaAttribute* self = (TLuaAttribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Value'",NULL);
  switch (self->Type)
  {
    case mtInt:
    case mtDouble:
    case mtFloat:
    {
        if ( !tolua_isnumber(tolua_S,2,0,&tolua_err) )
            tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
    }
    break;
    case mtString:
    {
        if (!tolua_isstring(tolua_S,2,0,&tolua_err))
            tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
    }
    case mtMyObject:
    {
        if (!tolua_isusertype(tolua_S,2,"TMyObject",0,&tolua_err))
            tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
    }
    break;
  };
#endif
  switch (self->Type)
  {
    case mtInt:
    case mtDouble:
    case mtFloat:
    case mtString:
    {
        self->Value = (void*)tolua_tostring(tolua_S,2,0);
    }
    break;
    case mtMyObject:
    case mtVCLObject:
    case mtAnyThing:
    {
        self->Value = tolua_tousertype(tolua_S,2,0);
    }
    break;
  };

 return 0;
}

/* get function: Type of class  TLuaAttribute */
static int tolua_get_TLuaAttribute_Type(lua_State* tolua_S)
{
  TLuaAttribute* self = (TLuaAttribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Type'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Type);
 return 1;
}

/* set function: Type of class  TLuaAttribute */
static int tolua_set_TLuaAttribute_Type(lua_State* tolua_S)
{
  TLuaAttribute* self = (TLuaAttribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Type'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Type = ((int)  tolua_tonumber(tolua_S,2,0));
 return 0;
}

/* method: new of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLuaAttributeList* tolua_ret = (TLuaAttributeList*)  new TLuaAttributeList();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLuaAttributeList");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: new_local of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TLuaAttributeList* tolua_ret = (TLuaAttributeList*)  new TLuaAttributeList();
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"TLuaAttributeList");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}

/* method: delete of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetAttribute of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_GetAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttribute'",NULL);
#endif
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  self->GetAttribute(Name);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLuaAttribute");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttribute'.",&tolua_err);
 return 0;
#endif
}

/* method: GetAttributeI of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_GetAttributeI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeI'",NULL);
#endif
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  self->GetAttributeI(index);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLuaAttribute");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeI'.",&tolua_err);
 return 0;
#endif
}

/* method: AddAttribute of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_AddAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
  char* Name = ((char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAttribute'",NULL);
#endif
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  self->AddAttribute(type,Name);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLuaAttribute");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddAttribute'.",&tolua_err);
 return 0;
#endif
}

/* method: AddAttribute of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_AddAttribute01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAttribute'",NULL);
#endif
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  self->AddAttribute(Name);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLuaAttribute");
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_Attributes_TLuaAttributeList_AddAttribute00(tolua_S);
}

/* method: AddAttributeI of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_AddAttributeI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  int type = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAttributeI'",NULL);
#endif
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  self->AddAttributeI(type);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLuaAttribute");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddAttributeI'.",&tolua_err);
 return 0;
#endif
}

/* method: AddAttributeI of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_AddAttributeI01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddAttributeI'",NULL);
#endif
  {
   TLuaAttribute* tolua_ret = (TLuaAttribute*)  self->AddAttributeI();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"TLuaAttribute");
  }
 }
 return 1;
tolua_lerror:
 return tolua_z_Attributes_TLuaAttributeList_AddAttributeI00(tolua_S);
}

/* method: GetAttributeValue of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_GetAttributeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeValue'",NULL);
#endif
  {
    TLuaAttribute* LA =  self->GetAttribute(Name);
    if (LA)
        PUSHATTRIBUTE(tolua_S,LA);
    else
        tolua_pushuserdata(tolua_S,(void*)NULL);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeValue'.",&tolua_err);
 return 0;
#endif
}

/* method: GetAttributeIValue of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_GetAttributeIValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeIValue'",NULL);
#endif
  {
    TLuaAttribute* LA =  self->GetAttributeI(index);
    if (LA)
        PUSHATTRIBUTE(tolua_S,LA);
    else
        tolua_pushuserdata(tolua_S,(void*)NULL);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeIValue'.",&tolua_err);
 return 0;
#endif
}

/* method: SetAttributeValue of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_SetAttributeValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
  void* Value = ((void*)  tolua_touserdata(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeValue'",NULL);
#endif
  {
   self->SetAttributeValue(Name,Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeValue'.",&tolua_err);
 return 0;
#endif
}

/* method: SetAttributeIValue of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_SetAttributeIValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  void* Value = ((void*)  tolua_touserdata(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributeIValue'",NULL);
#endif
  {
   self->SetAttributeIValue(index,Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributeIValue'.",&tolua_err);
 return 0;
#endif
}

/* method: DeleteAttributeI of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_DeleteAttributeI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteAttributeI'",NULL);
#endif
  {
   self->DeleteAttributeI(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteAttributeI'.",&tolua_err);
 return 0;
#endif
}

/* method: DeleteAttribute of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_DeleteAttribute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteAttribute'",NULL);
#endif
  {
   self->DeleteAttribute(Name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteAttribute'.",&tolua_err);
 return 0;
#endif
}

/* method: GetAttributeName of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_GetAttributeName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeName'",NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetAttributeName(index);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeName'.",&tolua_err);
 return 0;
#endif
}

/* method: GetAttributeIndex of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_GetAttributeIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
  char* Name = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAttributeIndex'",NULL);
#endif
  {
   int tolua_ret = (int)  self->GetAttributeIndex(Name);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAttributeIndex'.",&tolua_err);
 return 0;
#endif
}

/* method: Clear of class  TLuaAttributeList */
static int tolua_z_Attributes_TLuaAttributeList_Clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TLuaAttributeList",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: AttributeCount of class  TLuaAttributeList */
static int tolua_get_TLuaAttributeList_AttributeCount(lua_State* tolua_S)
{
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AttributeCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->AttributeCount);
 return 1;
}

/* get function: AttributeICount of class  TLuaAttributeList */
static int tolua_get_TLuaAttributeList_AttributeICount(lua_State* tolua_S)
{
  TLuaAttributeList* self = (TLuaAttributeList*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AttributeICount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->AttributeICount);
 return 1;
}

static int tolua_z_All_LuaCreate00(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if ( !tolua_isstring(tolua_S,1,0,&tolua_err) )
        tolua_error(tolua_S,"#ferror in function 'IsLinesCrossedExactly'.",&tolua_err);
    char* ClassName = (char*)  tolua_tostring(tolua_S,1,0);
    TMyObject* tolua_ret = LuaCreate(ClassName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ClassName");
    return 1;
}

static int tolua_z_All_LuaCreateLocal00(lua_State* tolua_S)
{
    tolua_Error tolua_err;
    if ( !tolua_isstring(tolua_S,1,0,&tolua_err) )
        tolua_error(tolua_S,"#ferror in function 'IsLinesCrossedExactly'.",&tolua_err);
    char* ClassName = (char*)  tolua_tostring(tolua_S,1,0);
    TMyObject* tolua_ret = LuaCreate(ClassName);
    tolua_pushusertype_and_takeownership(tolua_S,(void*)tolua_ret,"ClassName");
    return 1;
}

static int tolua_z_Attributes_TLuaAttribute_GetLuaStrType00(lua_State* tolua_S)
{
  TLuaAttribute* self = (TLuaAttribute*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AttributeICount'",NULL);
#endif
  tolua_pushstring(tolua_S,(char*)self->GetLuaStrType());
 return 1;
}

/* Open function */
TOLUA_API int tolua_z_Attributes_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLuaAttribute","TLuaAttribute","TMyObject",tolua_collect_TLuaAttribute);
#else
 tolua_cclass(tolua_S,"TLuaAttribute","TLuaAttribute","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLuaAttribute");
 tolua_function(tolua_S,"new",tolua_z_Attributes_TLuaAttribute_new00);
 tolua_function(tolua_S,"new_local",tolua_z_Attributes_TLuaAttribute_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_Attributes_TLuaAttribute_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_Attributes_TLuaAttribute_delete00);
 tolua_variable(tolua_S,"Value",tolua_get_TLuaAttribute_Value,tolua_set_TLuaAttribute_Value);
 tolua_variable(tolua_S,"Type",tolua_get_TLuaAttribute_Type,tolua_set_TLuaAttribute_Type);
 tolua_function(tolua_S,"GetLuaStrType",tolua_z_Attributes_TLuaAttribute_GetLuaStrType00);
 tolua_endmodule(tolua_S);
#ifdef __cplusplus
 tolua_cclass(tolua_S,"TLuaAttributeList","TLuaAttributeList","TMyObject",tolua_collect_TLuaAttributeList);
#else
 tolua_cclass(tolua_S,"TLuaAttributeList","TLuaAttributeList","TMyObject",NULL);
#endif
 tolua_beginmodule(tolua_S,"TLuaAttributeList");
 tolua_function(tolua_S,"new",tolua_z_Attributes_TLuaAttributeList_new00);
 tolua_function(tolua_S,"new_local",tolua_z_Attributes_TLuaAttributeList_new00_local);
 tolua_set_call_event(tolua_S,tolua_z_Attributes_TLuaAttributeList_new00_local);
 tolua_function(tolua_S,"delete",tolua_z_Attributes_TLuaAttributeList_delete00);
 tolua_function(tolua_S,"GetAttribute",tolua_z_Attributes_TLuaAttributeList_GetAttribute00);
 tolua_function(tolua_S,"GetAttributeI",tolua_z_Attributes_TLuaAttributeList_GetAttributeI00);
 tolua_function(tolua_S,"AddAttribute",tolua_z_Attributes_TLuaAttributeList_AddAttribute00);
 tolua_function(tolua_S,"AddAttribute",tolua_z_Attributes_TLuaAttributeList_AddAttribute01);
 tolua_function(tolua_S,"AddAttributeI",tolua_z_Attributes_TLuaAttributeList_AddAttributeI00);
 tolua_function(tolua_S,"AddAttributeI",tolua_z_Attributes_TLuaAttributeList_AddAttributeI01);
 tolua_function(tolua_S,"GetAttributeValue",tolua_z_Attributes_TLuaAttributeList_GetAttributeValue00);
 tolua_function(tolua_S,"GetAttributeIValue",tolua_z_Attributes_TLuaAttributeList_GetAttributeIValue00);
 tolua_function(tolua_S,"SetAttributeValue",tolua_z_Attributes_TLuaAttributeList_SetAttributeValue00);
 tolua_function(tolua_S,"SetAttributeIValue",tolua_z_Attributes_TLuaAttributeList_SetAttributeIValue00);
 tolua_function(tolua_S,"DeleteAttributeI",tolua_z_Attributes_TLuaAttributeList_DeleteAttributeI00);
 tolua_function(tolua_S,"DeleteAttribute",tolua_z_Attributes_TLuaAttributeList_DeleteAttribute00);
 tolua_function(tolua_S,"GetAttributeName",tolua_z_Attributes_TLuaAttributeList_GetAttributeName00);
 tolua_function(tolua_S,"GetAttributeIndex",tolua_z_Attributes_TLuaAttributeList_GetAttributeIndex00);
 tolua_function(tolua_S,"Clear",tolua_z_Attributes_TLuaAttributeList_Clear00);
 tolua_variable(tolua_S,"AttributeCount",tolua_get_TLuaAttributeList_AttributeCount,NULL);
 tolua_variable(tolua_S,"AttributeICount",tolua_get_TLuaAttributeList_AttributeICount,NULL);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"LuaCreate",tolua_z_All_LuaCreate00);
 tolua_function(tolua_S,"LuaCreateLocal",tolua_z_All_LuaCreateLocal00);
 tolua_endmodule(tolua_S);
 return 1;
}
