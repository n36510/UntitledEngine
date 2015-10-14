#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include <physfs.h>
#include <SFML/Graphics.hpp>
#include <iostream>

extern "C" {

#include <lua5.2/lua.h>
#include <lua5.2/lualib.h>
#include <lua5.2/lauxlib.h>

}
#include "LuaBridge/LuaBridge.h"
using namespace std;

#include "EventManager.h"
#include "physfsManager.h"
#include "luaManager.h"
#include "Animation.h"
#include "AnimatedSprite.h"
#include "Player.h"

#endif // GLOBALS_H_INCLUDED
