#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include "Date.h"

class TimeManager
{

public:

    TimeManager();
    ~TimeManager();

    void advanceOneDay();

    const int getDay() const;
    const int getMonth() const;
    const int getYear() const;

    Date getDate() const;

private:

    Date date;

};

#endif // TIMEMANAGER_H
