#pragma once

#include <sol/sol.hpp>

#include "ILuaModuleManager.h"
extern ILuaModuleManager10* pModuleManager;

struct ClientSession
{
	static void Init(lua_State* vm);
};
