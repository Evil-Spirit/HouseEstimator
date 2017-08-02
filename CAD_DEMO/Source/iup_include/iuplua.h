/** \file
 * \brief IUP Binding for Lua.
 *
 * See Copyright Notice in iup.h
 * $Id: iuplua.h,v 1.1 2006/07/26 12:40:24 Alex Exp $
 */
 
#ifndef __IUPLUA_H 
#define __IUPLUA_H

#include <iup.h>
#include <lua.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LUA_NOOBJECT  /* Lua 3 */
int iuplua_open (void);
int iupkey_open (void);
int iuplua_dofile (char *filename);
lua_Object iuplua_register (Ihandle* element);
#endif

#ifdef LUA_NOREF  /* Lua 4 or 5 */
void iuplua_open(lua_State *L);
void iupkey_open(lua_State *L);
#endif

#ifdef __cplusplus
}
#endif

#endif
