#include "CompetitionsManager.h"


CompetitionsManager::CompetitionsManager()
{

}


CompetitionsManager::~CompetitionsManager()
{

}


void CompetitionsManager::registerPlayer(Player &player)
{
    players.push_back(player);
}


void CompetitionsManager::registerLeague(League &league)
{
    leagues.push_back(league);
}


void CompetitionsManager::registerTeam(Team &team)
{
    teams.push_back(team);
}


void CompetitionsManager::registerTeamsInLeague()
{

}


void CompetitionsManager::addPlayersToTeams()
{
    for (int i = 0; i < players.size(); i++)
    {
        int teamID = players[i].getTeamID();
        for (int y = 0; y < teams.size(); y++)
        {
            if (teams[y].getId() == players[i].getTeamID())
            {
                teams[y].addPlayer(&players[i]);
            }
        }
    }
}


void CompetitionsManager::onDayAdvanced(Date date)
{
    for (int i = 0; i < leagues.size(); i++)
    {
        leagues[i].onDayAdvanced(date);
    }
    for (int x = 0; x < teams.size(); x++)
    {
        teams[x].onDayAdvanced(date);
    }
    for (int y = 0; y < players.size(); y++)
    {
        players[y].onDayAdvanced(date);
    }
}


void CompetitionsManager::printTeamsInfo()
{
    for (int i = 0; i < teams.size(); i++)
    {
        teams[i].printInfo();
    }
}


void CompetitionsManager::printLeaguesInfo()
{
    for (int i = 0; i < leagues.size(); i++)
    {
        leagues[i].printInfo();
    }
}


Team* CompetitionsManager::getTeam(const std::string& name)
{
    for(int i = 0; i < teams.size(); i++)
    {
        if (teams[i].getName() == name)
        {
            return &teams[i];
        }
    }

    return NULL;
}


Team* CompetitionsManager::getTeam(int ID)
{
    for (int i = 0; i < teams.size(); i++)
    {
        if (teams[i].getId() == ID)
        {
            return &teams[i];
        }
    }

    return NULL;
}


void CompetitionsManager::leagueCreateSchedule()
{
    for (int i = 0; i < leagues.size(); i++)
    {
        leagues[i].createSchedule();
    }
}


void CompetitionsManager::printMatchesInfo()
{
    for (int i = 0; i < leagues.size(); i++)
    {
        leagues[i].printMatches();
    }
}
