#ifndef PHYSFSMANAGER_H
#define PHYSFSMANAGER_H


class physfsManager
{
    public:
        physfsManager();
        bool Run();
        virtual ~physfsManager();
        void* loadFile(string fileName);

    protected:
    private:
};

#endif // PHYSFSMANAGER_H
