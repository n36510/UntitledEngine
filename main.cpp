#include "globals.h"

int main(){

    sf::RenderWindow win(sf::VideoMode(800 , 600, 32),"Hello World");


        physfsManager* manager = new physfsManager();

        if(manager->Run()) {
        // manager->loadFile(filename);
        Player* player = new Player(manager,&win);
        sf::Clock* dt = new sf::Clock();
        while (win.isOpen()) {

            sf::Time deltaTime = dt->restart();


            EventManager event(&win);
            event.Run();

            player->Update(deltaTime);

            win.clear();
            player->draw();
            win.display();

        }
    } else {
        return 1;
    }
    return 0;
}
