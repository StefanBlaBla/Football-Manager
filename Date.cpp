#include "Date.h"


Date::Date()
{
    day = 1;
    month = 1;
    year = 2015;
}


Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}


Date::~Date()
{

}


bool Date::operator==(const Date& rhs)
{
    if (day == rhs.day && month == rhs.month && year == rhs.year)
        return true;

    return false;
}


void Date::advance(int day, int month, int year)
{
    this->day += day;
    this->month += month;
    this->year += year;

    if (this->day > 28)
    {
        if (this->month == 2)
        {
            //the month is february and it has 28 days
            this->month++;
            this->day = 1;
        }
        else if (this->month%2 != 0)
        {
            //this means if the month has 31
            if (this->day > 31)
            {
                this->month++;
                this->day = 1;
            }
        }
        else
        {
            if (this->day > 30)
            {
                this->month++;
                this->day = 1;
            }
            //here the month has 30
        }

        if (this->month >= 12)
        {
            this->year++;
            this->month = 1;
            this->day = 1;
        }
    }
}


std::string Date::getDateFormatted() const
{
    std::string date;
    std::stringstream out;
    out << day;
    out << "/";
    out << month;
    out << "/";
    out << year;

    //TODO: Fix this
    date = out.str();

    return date;
}


int Date::getDateNumber() const
{
    std::stringstream str;
    str << year << month << day;

    int num;
    str >> num;

    return num;
}
