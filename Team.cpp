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


std::vector<Player*>& Team::getDefenders()
{
    std::vector<Player*> p;
    int defNum = getDefNum();

    if (defNum == 4)
    {
        p.push_back(players[1]);
        p.push_back(players[2]);
        p.push_back(players[3]);
        p.push_back(players[4]);
    }
    else if (defNum = 3)
    {
        p.push_back(players[1]);
        p.push_back(players[2]);
        p.push_back(players[3]);
    }

    return p;
}


std::vector<Player*>& Team::getMidDefenders()
{
    std::vector<Player*> p;
    int defNum = getDefNum();
    int midDefNum = getDefMidNum();

    if (midDefNum == 3)
    {
        p.push_back(players[1 + defNum]);
        p.push_back(players[2 + defNum]);
        p.push_back(players[3 + defNum]);
        p.push_back(players[4 + defNum]);
    }
    else if (midDefNum = 2)
    {
        p.push_back(players[1 + defNum]);
        p.push_back(players[2 + defNum]);
    }
    else if (midDefNum = 1)
    {
        p.push_back(players[1 + defNum]);
    }

    return p;
}


std::vector<Player*>& Team::getMiddle()
{
    std::vector<Player*> p;
    int defNum = getDefNum();
    int midDefNum = getDefMidNum();
    int middleNum = getMidNum();

    if (middleNum == 4)
    {
        p.push_back(players[1 + defNum + midDefNum]);
        p.push_back(players[2 + defNum + midDefNum]);
        p.push_back(players[3 + defNum + midDefNum]);
        p.push_back(players[4 + defNum + midDefNum]);
    }
    else if (middleNum = 3)
    {
        p.push_back(players[1 + defNum + midDefNum]);
        p.push_back(players[2 + defNum + midDefNum]);
        p.push_back(players[3 + defNum + midDefNum]);
    }
    else if (middleNum = 2)
    {
        p.push_back(players[1 + defNum + midDefNum]);
        p.push_back(players[2 + defNum + midDefNum]);
    }
    else if (middleNum = 1)
    {
        p.push_back(players[1 + defNum + midDefNum]);
    }

    return p;
}


std::vector<Player*>& Team::getMidAttackers()
{
    std::vector<Player*> p;
    int defNum = getDefNum();
    int midDefNum = getDefMidNum();
    int middleNum = getMidNum();
    int midAttNum = getAttMidNum();

    if (midAttNum = 3)
    {
        p.push_back(players[1 + defNum + midDefNum + middleNum]);
        p.push_back(players[2 + defNum + midDefNum + middleNum]);
        p.push_back(players[3 + defNum + midDefNum + middleNum]);
    }
    else if (midAttNum = 2)
    {
        p.push_back(players[1 + defNum + midDefNum + middleNum]);
        p.push_back(players[2 + defNum + midDefNum + middleNum]);
    }
    else if (midAttNum = 1)
    {
        p.push_back(players[1 + defNum + midDefNum + middleNum]);
    }

    return p;
}


std::vector<Player*>& Team::getAttackers()
{
    std::vector<Player*> p;
    int defNum = getDefNum();
    int midDefNum = getDefMidNum();
    int middleNum = getMidNum();
    int midAttNum = getAttMidNum();
    int attNum = getAttNum();

    if (attNum = 4)
    {
        p.push_back(players[1 + defNum + midDefNum + middleNum + midAttNum]);
        p.push_back(players[2 + defNum + midDefNum + middleNum + midAttNum]);
        p.push_back(players[3 + defNum + midDefNum + middleNum + midAttNum]);
        p.push_back(players[1 + defNum + midDefNum + middleNum + midAttNum]);
    }
    else if (attNum = 3)
    {
        p.push_back(players[1 + defNum + midDefNum + middleNum + midAttNum]);
        p.push_back(players[2 + defNum + midDefNum + middleNum + midAttNum]);
        p.push_back(players[1 + defNum + midDefNum + middleNum + midAttNum]);
    }
    else if (attNum = 2)
    {
        p.push_back(players[1 + defNum + midDefNum + middleNum + midAttNum]);
        p.push_back(players[1 + defNum + midDefNum + middleNum + midAttNum]);
    }
    else if (attNum = 1)
    {
        p.push_back(players[1 + defNum + midDefNum + middleNum + midAttNum]);
    }

    return p;
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
