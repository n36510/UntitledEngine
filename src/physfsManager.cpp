#include "globals.h"

physfsManager::physfsManager()
{
    PHYSFS_init(NULL);
}

physfsManager::~physfsManager()
{
    //dtor
}
string physfsManager::loadFile(string fileName) {
    PHYSFS_File* file = PHYSFS_openRead(fileName.c_str());
    PHYSFS_sint64 file_size = PHYSFS_fileLength(file);
    char* buffer = new char[sizeof(char) * file_size + 1];
    PHYSFS_read(file, buffer, file_size, 1);
    return buffer;
}
bool physfsManager::Run()
{
    bool running = true;
    if (PHYSFS_addToSearchPath("data.pkg",1)) {
    // Check for folders;

        cout << "Loading Sprites: ";

        if (!PHYSFS_exists("sprites")) {
        cout << "Failed" << endl;
        running = false;
        } else {
        cout << "Done!" << endl;
        }

        cout << "Loading Fonts: ";

        if (!PHYSFS_exists("fonts")) {
        cout << "Failed" << endl;
        running = false;
        } else {
        cout << "Done!" << endl;
        }

        cout << "Loading Scripts: ";

        if (!PHYSFS_exists("scripts")) {
            cout << "Failed" << endl;
            running = false;
        } else {

            cout << "Done!" << endl;
        }

    } else {
        std::cout << "Unable to open data.pkg" << std::endl;
        running = false;
    }
    return running;
}
