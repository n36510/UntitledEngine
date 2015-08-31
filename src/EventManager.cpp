#include "globals.h"

EventManager::EventManager(sf::RenderWindow *win)
{
    this->window = win;
}

EventManager::~EventManager()
{
    //dtor
}

void EventManager::Run() {
    while (window->pollEvent(this->event))
    {
        if (this->event.type = sf::Event::Closed) {
            window->close();
        }
    }
}
