#include "Team.h"

Team::Team()
{
    name = "";
    transferBudget = 0;
}


Team::Team(int id, std::string& name, int transferBudget, short formation)
{
    this->id = id;
    this->name = name;
    this->transferBudget = transferBudget;
    this->formation = formation;
}


Team::~Team()
{

}


int Team::getId() const
{
    return id;
}


std::string Team::getName() const
{
    return name;
}


int Team::getTransferBudget() const
{
    return transferBudget;
}


void Team::setTransferBudget(int num)
{
    transferBudget = num;
}


void Team::modifyTransferBudget(int amount)
{
    transferBudget += amount;

    if (transferBudget < 0)
        transferBudget = 0;
}


Player* Team::getPlayer(Position pos)
{
}


void Team::addPlayer(Player *player)
{
    players.push_back(player);
}


void Team::onDayAdvanced(Date date)
{

}


void Team::printInfo()
{
    std::cout <<"++++++++++TEAM++++++++++\n";
    std::cout <<"Name: " << name <<std::endl;
    std::cout <<"Transfer Budget: " << transferBudget << std::endl;

    for(int i = 0; i < players.size(); i++)
    {
        players[i]->printInfo();
    }
}


int Team::getDefNum()
{
    return formation >> 12;
}


int Team::getDefMidNum()
{
    return (formation >> 9) & 7;
}


int Team::getMidNum()
{
    return (formation >> 6) & 7;
}


int Team::getAttMidNum()
{
    return (formation >> 3) & 7;
}


int Team::getAttNum()
{
    return formation & 7;
}
