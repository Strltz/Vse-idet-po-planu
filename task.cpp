#include "task.h"

Time::Time(std::string h, std::string m)
{
    this->hours = h;
    this->minutes = m;
}

Time::~Time() {}


Date::Date(std::string d, std::string m, std::string y)
{
    this->day = d;
    this->month = m;
    this->year = y;
}

Date::~Date() {}


Task::Task(std::string descr, Time start, Time end)
{
    this->description = descr;
    this->start = start;
    this->finish = end;
}

Task::~Task() {}
