#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H


class EventManager
{
    public:
        EventManager(sf::RenderWindow *win);
        virtual ~EventManager();

        void Run();
    protected:
    private:
    sf::Event event;
    sf::RenderWindow* window;
};

#endif // EVENTMANAGER_H
