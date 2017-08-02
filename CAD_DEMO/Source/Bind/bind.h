#ifndef BINDH
#define BINDH

#include "tolua++.h"
#include <vcl.h>

TOLUA_API AnsiString tolua_toansi(lua_State* tolua_S, int narg, const char* def)
{
    return AnsiString( tolua_tostring(tolua_S,narg,def) );
}

TOLUA_API void tolua_pushansi (lua_State* L, const AnsiString& value)
{
    tolua_pushstring(L,value.c_str());
}

TOLUA_API void tolua_pushfieldansi (lua_State* L, int lo, int index, const AnsiString& value)
{
    tolua_pushfieldstring( L, lo, index, value.c_str() );
}

TOLUA_API int tolua_isansi (lua_State* L, int lo, int def, tolua_Error* err)
{
    return tolua_isstring (L, lo, def, err);
}

#endif

 
