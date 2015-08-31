#include "globals.h"

luaManager::luaManager()
{
    this->L = luaL_newstate();
    luaL_openlibs(this->L);
}

luaManager::~luaManager()
{
    //dtor
}

void luaManager::runScript(string script) {
    luaL_dostring(this->L,script.c_str());
}
