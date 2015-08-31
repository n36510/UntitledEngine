#ifndef LUAMANAGER_H
#define LUAMANAGER_H


class luaManager
{
    public:
        luaManager();
        virtual ~luaManager();
        void runScript(string filename);
    protected:
    private:
    lua_State *L;
};

#endif // LUAMANAGER_H
