#ifndef DATE_H
#define DATE_H

#include <sstream>
#include <string>

class Date
{
public:

    Date();
    Date(int day, int month, int year);

    ~Date();


    bool operator==(const Date& rhs);

    void advance(int day, int month, int year);

    std::string getDateFormatted() const;

    int getDateNumber() const;


    int day, month, year;

};

#endif // DATE_H
