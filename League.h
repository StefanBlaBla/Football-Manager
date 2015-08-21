#ifndef LEAGUE_H
#define LEAGUE_H

#include <vector>
#include <iostream>

#include "Match.h"

class League
{
public:

    League(const std::string& name, Date startingDate);
    ~League();

    std::string getName() const;

    void addTeam(Team *team);

    void createSchedule();

    void onDayAdvanced(Date date);

    void printInfo();

    void printMatches();

private:

    std::string name;
    Date startingDate;
    std::vector<Team*> teams;
    std::vector<Match> matches;
};

#endif // LEAGUE_H
