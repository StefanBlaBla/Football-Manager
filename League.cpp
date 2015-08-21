#include "League.h"

League::League(const std::string& name, Date startingDate)
{
    this->name = name;
    this->startingDate = startingDate;
}


League::~League()
{

}


std::string League::getName() const
{
    return name;
}


void League::printInfo()
{
    std::cout <<"++++++++LEAGUE++++++++\n";
    std::cout <<"Name: " << name << std::endl;
    std::cout <<"Teams: ";

    for (int i = 0; i < teams.size(); i++)
    {
        std::cout << teams[i]->getName() << ", ";
    }

    std::cout << std::endl;
}


void League::addTeam(Team *team)
{
    teams.push_back(team);
}


void League::createSchedule()
{
    Date curDate = startingDate;

    for (int x = 0; x < teams.size(); x++)
    {
        for (int y = 0; y < teams.size(); y++)
        {
            if (x != y)
            {
                matches.push_back(Match(curDate, teams[x], teams[y]));
                curDate.advance(3, 0, 0);
            }
        }
    }
}


void League::onDayAdvanced(Date date)
{
    for (int i = 0; i < matches.size(); i++)
    {
        if (matches[i].getDate() == date)
            matches[i].simulate();
    }
}


void League::printMatches()
{
    for (int i = 0; i < matches.size(); i++)
    {
        matches[i].printInfo();
    }
}
