#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <vector>

#include "Date.h"
#include "Utills.h"

enum Position
{
    GK      = 1,
    DR      = 2,
    DCR     = 4,
    DCL     = 8,
    DL      = 16,
    DMC     = 32,
    MR      = 64,
    MCR     = 128,
    MCL     = 256,
    ML      = 512,
    AML     = 1024,
    AMC     = 2048,
    AMR     = 4096,
    WR      = 8192,
    ST      = 16384,
    WL      = 32768,
    DCC     = 65536,
    STR     = 131072,
    STL     = 262144,
    DML     = 524288,
    DMR     = 1048576
};

class Player
{

public:

    Player(const std::string& name, int age, int teamID, int positions, const std::map<std::string, int>& stats); //Ignoring position for now!
    ~Player();

    int getTeamID();

    void onDayAdvanced(Date date);

    void printInfo();

    static int stringToPosition(const std::string& str);

private:

    std::string name;
    int age;
    int positions;
    std::map<std::string, int> stats;

    int teamID;

};

#endif // PLAYER_H
