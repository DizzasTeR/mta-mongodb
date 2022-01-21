#include "ClientSession.h"
#include <lua-mongo/src/common.h>

void ClientSession::Init(lua_State* vm) {
	sol::state_view view(vm);
	view.require("mongo", luaopen_mongo);
}