#include "globals.h"

int main(){

    sf::RenderWindow win(sf::VideoMode(800,600,32),"Hello World");


        physfsManager* manager = new physfsManager();

        if(manager->Run()) {

            // Test Script - Temporary
            luaManager* lua = new luaManager();

            lua->runScript(
                manager->loadFile("scripts/test.lua"));

        while (win.isOpen()) {

            EventManager event(&win);
            event.Run();

            win.clear();

            win.display();

        }
    } else {
        return 1;
    }
    return 0;
}
