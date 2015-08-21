#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "rapidjson/document.h"
#include "rapidjson/filestream.h"


#include <stdio.h>
#include <vector>
#include <iostream>

class GameManager;

class DataManager
{
public:

    DataManager();
    DataManager(GameManager* gm);
    ~DataManager();

    void readManifest();

    void readFile(const char* path);

    void readFiles(const std::vector<std::string>& paths);

private:

    GameManager* gm;
};

#endif // DATAMANAGER_H
