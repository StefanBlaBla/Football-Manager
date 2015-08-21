#include "GameManager.h"

GameManager::GameManager()
: timeManager(), dataManager(this), compManager()
{

}


GameManager::~GameManager()
{

}


void GameManager::onStart()
{
    dataManager.readManifest();
    compManager.leagueCreateSchedule();

    std::string name;
    std::cout <<"Enter the name of the team you want to manage: ";
    getline(std::cin, name);

    std::cout<<"\nYou have chosen " << name;

    std::cin.get();
    // Here should be the code where we create the actual manager, set schedule, fixtures..
}


bool GameManager::update()
{
    system("cls");

    //This "UI" code should probably be move to another class GUIManager, but most probably not..
    int choise;
    std::cout <<"Date: " << timeManager.getDate().getDateFormatted() << std::endl;

    std::cout <<"1. Advance one day" << std::endl;
    std::cout <<"2. Advance to next event" << std::endl;
    std::cout <<"3. My Team " << std::endl;
    std::cout <<"4. Quit " << std::endl;
    std::cin >> choise;

    if (choise == 1)
    {
        timeManager.advanceOneDay();
        compManager.onDayAdvanced(timeManager.getDate());
    }
    else if (choise == 4)
        return false;

    return true;
}


void GameManager::onEnd()
{
    std::cout <<"onEnd\n";
}



void GameManager::registerPlayer(Player &player)
{
    compManager.registerPlayer(player);
}


void GameManager::registerLeague(League &league)
{
    compManager.registerLeague(league);
}


void GameManager::registerTeam(Team &team)
{
    compManager.registerTeam(team);
}


void GameManager::registerTeamsInLeague()
{
    compManager.registerTeamsInLeague();
}


void GameManager::addPlayersToTeams()
{
    compManager.addPlayersToTeams();
}


Team* GameManager::getTeam(const std::string& name)
{
    return compManager.getTeam(name);
}
