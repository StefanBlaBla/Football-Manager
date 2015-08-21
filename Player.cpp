#include "Player.h"


Player::Player(const std::string& name, int age, int teamID, int positions, const std::map<std::string, int>& stats)
{
    this->name = name;
    this->age = age;
    this->teamID = teamID;
    this->positions = positions;
    this->stats = stats;
}


Player::~Player()
{

}


int Player::getTeamID()
{
    return teamID;
}


void Player::onDayAdvanced(Date date)
{

}


void Player::printInfo()
{
    std::cout <<"+++++++PLAYER+++++++\n";
    std::cout <<"Name: " << name << std::endl;
    std::cout <<"Age: " << age << std::endl;

    //print stats info
}


int Player::stringToPosition(const std::string& str)
{
    std::vector<std::string> tokens = util::splitToString(str, ',');
    int pos;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "gk")
            pos |= GK;
        else if (tokens[i] == "dl")
            pos |= DL;
        else if (tokens[i] == "dcl")
            pos |= DCL;
        else if (tokens[i] == "dcr")
            pos |= DCR;
        else if (tokens[i] == "dr")
            pos |= DR;
        else if (tokens[i] == "dmc")
            pos |= DMC;
        else if (tokens[i] == "ml")
            pos |= ML;
        else if (tokens[i] == "mcl")
            pos |= MCL;
        else if (tokens[i] == "mcr")
            pos |= MCR;
        else if (tokens[i] == "mr")
            pos |= MR;
        else if (tokens[i] == "aml")
            pos |= AML;
        else if (tokens[i] == "amc")
            pos |= AMC;
        else if (tokens[i] == "amr")
            pos |= AMR;
        else if (tokens[i] == "wl")
            pos |= WL;
        else if (tokens[i] == "wr")
            pos |= WR;
        else if (tokens[i] == "st")
            pos |= ST;
        else if (tokens[i] == "dcc")
            pos |= DCC;
        else if (tokens[i] == "str")
            pos |= STR;
        else if (tokens[i] == "stl")
            pos |= STL;
        else if (tokens[i] == "dml")
            pos |= DML;
        else if (tokens[i] == "dmr")
            pos |= DMR;
    }

    return pos;
}
