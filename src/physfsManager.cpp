#include "globals.h"

physfsManager::physfsManager()
{
    PHYSFS_init(NULL);
}

physfsManager::~physfsManager()
{
    //dtor
}
sf::Uint8* physfsManager::loadFile(string fileName) {
    PHYSFS_File* file = PHYSFS_openRead(fileName.c_str());
    PHYSFS_sint64 file_size = PHYSFS_fileLength(file);
    sf::Uint8* buffer = new sf::Uint8[file_size];
    PHYSFS_read(file, buffer, 1, file_size);
    return buffer;
}

// Code below written by Phillip Stephens for Sakura, Reused for my own purposes.

sf::Texture* physfsManager::loadPng(string m_filename) {


    PHYSFS_file* file = PHYSFS_openRead(m_filename.c_str());
    if (file)
    {
        sf::Uint8* data = new sf::Uint8[PHYSFS_fileLength(file)];
        sf::Uint32 readLen = PHYSFS_read(file, data, 1, PHYSFS_fileLength(file));

        if (readLen == PHYSFS_fileLength(file))
        {
            sf::Texture* m_data = new sf::Texture;
            if (m_data->loadFromMemory(data, PHYSFS_fileLength(file)))
            {
                return m_data;
            }
        }

        delete[] data;
        data = NULL;
        PHYSFS_close(file);
    }
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
