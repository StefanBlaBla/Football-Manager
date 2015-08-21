#include "Match.h"


Match::Match(Date date, Team* homeTeam, Team* awayTeam)
{
    this->date = date;

    this->homeTeam = homeTeam;
    this->awayTeam = awayTeam;
}


Match::~Match()
{

}


void Match::simulate()
{
    std::cout <<"match simulate!";
}


bool Match::isPlayed()
{
    return played;
}


Date Match::getDate()
{
    return date;
}


void Match::printInfo()
{
    std::cout << date.getDateFormatted() << " | " << homeTeam->getName() << " - " << awayTeam->getName() << std::endl;
}
