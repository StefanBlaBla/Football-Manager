#include "TimeManager.h"
#include <sstream>

TimeManager::TimeManager()
    : date(1, 1, 2016)
{

}


TimeManager::~TimeManager()
{

}


void TimeManager::advanceOneDay()
{
    date.advance(1, 0 , 0);
}


const int TimeManager::getDay() const
{
    return date.day;
}


const int TimeManager::getMonth() const
{
    return date.month;
}


const int TimeManager::getYear() const
{
    return date.year;
}


Date TimeManager::getDate() const
{
    return date;
}
