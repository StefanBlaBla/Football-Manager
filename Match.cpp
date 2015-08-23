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
    int attackHome, attackAway, defenceHome, defenceAway, numChancesHome, numChancesAway;
    std::vector<Player*> homeDef, homeMidDef, homeMid, homeMidAtt, homeAtt;
    std::vector<Player*> awayDef, awayMidDef, awayMid, awayMidAtt, awayAtt;


    homeDef = homeTeam->getDefenders();
    homeMidDef = homeTeam->getMidDefenders();
    homeMid = homeTeam->getMiddle();
    homeMidAtt = homeTeam->getMidAttackers();
    homeAtt = homeTeam->getAttackers();

    awayDef = awayTeam->getDefenders();
    awayMidDef = awayTeam->getMidDefenders();
    awayMid = awayTeam->getMiddle();
    awayMidAtt = awayTeam->getMidAttackers();
    awayAtt = awayTeam->getAttackers();

    for (int i = 0; i < homeAtt.size(); i++)
    {
        attackHome += homeAtt[i]->getStat("attack");
        defenceHome += homeAtt[i]->getStat("defence") * 0,1;
    }

    for (int i = 0; i < homeMidAtt.size(); i++)
    {
        attackHome += homeMidAtt[i]->getStat("attack") * 0,85;
        defenceHome += homeMidAtt[i]->getStat("defence") * 0,15;
    }

    for (int i = 0; i < homeMid.size(); i++)
    {
        attackHome += homeMid[i]->getStat("attack") * 0,5;
        defenceHome += homeMid[i]->getStat("defence") * 0,5;
    }

    for (int i = 0; i < homeMidDef.size(); i++)
    {
        attackHome += homeMidDef[i]->getStat("attack") * 0,15;
        defenceHome += homeMidDef[i]->getStat("defence") * 0,9;
    }

    for (int i = 0; i < homeDef.size(); i++)
    {
        attackHome += homeDef[i]->getStat("attack") * 0,1;
        defenceHome += homeDef[i]->getStat("defence");
    }

    for (int i = 0; i < awayAtt.size(); i++)
    {
        attackAway += awayAtt[i]->getStat("attack");
        defenceAway += awayAtt[i]->getStat("defence") * 0,1;
    }

    for (int i = 0; i < awayMidAtt.size(); i++)
    {
        attackAway += awayMidAtt[i]->getStat("attack") * 0,85;
        defenceAway += awayMidAtt[i]->getStat("defence") * 0,15;
    }

    for (int i = 0; i < awayMid.size(); i++)
    {
        attackAway += awayMid[i]->getStat("attack") * 0,5;
        defenceAway += awayMid[i]->getStat("defence") * 0,5;
    }

    for (int i = 0; i < awayMidDef.size(); i++)
    {
        attackAway += awayMidDef[i]->getStat("attack") * 0,15;
        defenceAway += awayMidDef[i]->getStat("defence") * 0,9;
    }

    for (int i = 0; i < awayDef.size(); i++)
    {
        attackAway += awayDef[i]->getStat("attack") * 0,1;
        defenceAway += awayDef[i]->getStat("defence");
    }

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
