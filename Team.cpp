#include "Team.h"

Team::Team()
{
    name = "";
    transferBudget = 0;
}


Team::Team(int id, std::string& name, int transferBudget)
{
    this->id = id;
    this->name = name;
    this->transferBudget = transferBudget;
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
}


int Team::getDefMidNum()
{

}


int Team::getMidNum()
{

}


int Team::getAttMidNum()
{

}


int Team::getAttNum()
{

}
