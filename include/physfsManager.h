#ifndef PHYSFSMANAGER_H
#define PHYSFSMANAGER_H


class physfsManager
{
    public:
        physfsManager();
        bool Run();
        virtual ~physfsManager();
        sf::Uint8* loadFile(string fileName);
        sf::Texture* loadPng(string filename);

    protected:
    private:
};

#endif // PHYSFSMANAGER_H
