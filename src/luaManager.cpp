#include "globals.h"

lua_State *L;
sf::RenderWindow* app;


luaManager::luaManager(sf::RenderWindow* win)
{
    app = win;
    L = luaL_newstate();
    luaL_openlibs(L);

}

luaManager::~luaManager()
{
    //dtor
}

void luaManager::runScript(string script) {
    luaL_dostring(L,script.c_str());
}


