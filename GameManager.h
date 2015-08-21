#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <iostream>
#include <cstdlib>

#include "TimeManager.h"
#include "DataManager.h"
#include "CompetitionsManager.h"

class GameManager
{
public:

    GameManager();
    ~GameManager();

    void onStart();
    bool update(); // returns false when the program should end, otherwise it returns true
    void onEnd();


    void registerPlayer(Player &player);
    void registerTeam(Team &team);
    void registerLeague(League &league);

    void registerTeamsInLeague();

    void addPlayersToTeams();

    Team* getTeam(const std::string& name);

private:

    TimeManager timeManager;
    DataManager dataManager;
    CompetitionsManager compManager;

};

#endif
