#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
// }

static int test(lua_State *L)
{
	int n = luaL_getn(L, 1);

	for (int i = 1; i<=n; ++i)
	{
		lua_pushnumber(L, i);
	}

	return 1;
}


static const struct luaL_reg arraylib [] = {
	{"test", test},
	{NULL, NULL}
};

extern "C" int luaopen_t(lua_State *L)
{
	luaL_register(L, "t", arraylib);
	return 1;
}