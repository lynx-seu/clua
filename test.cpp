#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

static void stack_dump(lua_State *L)
{
	int i;
	int top = lua_gettop(L);

	for (i = 1; i <= top; i++) { /* repeat for each level */
		int t = lua_type(L, i);
		switch (t) {
		case LUA_TSTRING: /* strings */
			printf("`%s'", lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN: /* booleans */
			printf(lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TNUMBER: /* numbers */
			printf("%g", lua_tonumber(L, i));
			break;
		default: /* other values */
			printf("%s", lua_typename(L, t));
			break;
		}
		printf(" "); /* put a separator */
	}
	printf("\n"); /* end the listing */	
}

static int test(lua_State *L)
{
	std::vector<int> vi;
	int n=luaL_getn(L, 1), c=0;

	for (int i = 1; i<=n; ++i)
	{
		lua_pushnumber(L, i);
		lua_gettable(L , 1);
		c = luaL_getn(L, -1);
		for (int j=1; j<=c; j++) 
		{
			lua_pushnumber(L, j);
			lua_gettable(L, -2);
			int v = luaL_checknumber(L, -1);
			vi.push_back(v);
			lua_pop(L, 1);
		}
		lua_pop(L, 1);
	}

	lua_newtable(L);

	for (int i=0; i<vi.size(); i++)
	{
		lua_pushnumber(L, i+1);
		lua_pushnumber(L, vi[i]);
		lua_settable(L, -3);
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