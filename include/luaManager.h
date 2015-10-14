#ifndef LUAMANAGER_H
#define LUAMANAGER_H


class luaManager
{
    public:
        luaManager(sf::RenderWindow* win);
        virtual ~luaManager();
        void runScript(string filename);
    protected:
    private:

};

#endif // LUAMANAGER_H
