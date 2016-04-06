#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
// }

static int l_sin(lua_State *L)
{
	double d = luaL_checknumber(L, 1);
	lua_pushnumber(L, sin(d));
	return 1;
}

static const struct luaL_reg mylib [] = {
	{"sin", l_sin},
	{NULL, NULL}
};

extern "C" int luaopen_mylib(lua_State *L)
{
	luaL_register(L, "mylib", mylib);
	return 1;
}