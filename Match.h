#ifndef MATCH_H
#define MATCH_H

#include "Team.h"

class Match
{
public:

    Match(Date date, Team* homeTeam, Team* awayTeam);
    ~Match();

    void simulate();

    bool isPlayed();
    Date getDate();

    void printInfo();

private:

    Date date;
    Team *homeTeam, *awayTeam;
    int homeGoals, awayGoals;
    std::string homeGoalScorers, awayGoalScorers;

    bool played;
};

#endif // MATCH_H
