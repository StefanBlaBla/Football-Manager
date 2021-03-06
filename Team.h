#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <iostream>

#include "Player.h"

class Team
{
public:

    Team();
    Team(int id, std::string& name, int transferBudget, short formation);
    ~Team();

    int getId() const;
    std::string getName() const;
    int getTransferBudget() const;

    void setTransferBudget(int num);
    void modifyTransferBudget(int amount);

    Player* getPlayer(Position pos);

    std::vector<Player*>& getDefenders();
    std::vector<Player*>& getMidDefenders();
    std::vector<Player*>& getMiddle();
    std::vector<Player*>& getMidAttackers();
    std::vector<Player*>& getAttackers();

    void addPlayer(Player *player);

    void onDayAdvanced(Date date);

    void printInfo();

private:

    int getDefNum();
    int getDefMidNum();
    int getMidNum();
    int getAttMidNum();
    int getAttNum();

    int id;

    std::string name;
    int transferBudget;

    int formation;

    std::vector<Player*> players;

};

#endif // TEAM_H
