#ifndef COMPETITIONSMANAGER_H
#define COMPETITIONSMANAGER_H

#include <vector>

#include "League.h"

class CompetitionsManager
{
public:

    CompetitionsManager();
    ~CompetitionsManager();

    void registerPlayer(Player &player);
    void registerTeam(Team &team);
    void registerLeague(League &league);

    Team* getTeam(const std::string& name);
    Team* getTeam(int ID);

    void registerTeamsInLeague();
    void addPlayersToTeams();

    void onDayAdvanced(Date date);

    void leagueCreateSchedule();

    void printTeamsInfo();
    void printLeaguesInfo();
    void printMatchesInfo();

private:

    std::vector<League> leagues;
    std::vector<Team> teams;
    std::vector<Player> players;

};

#endif // COMPETITIONSMANAGER_H
