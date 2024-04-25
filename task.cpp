#include "task.h"

Time::Time(std::string h, std::string m)
{
    this->hours = h;
    this->minutes = m;
}

std::string Time::toStr()
{
    return (this->hours + ":" + this->minutes);
}

Time::~Time() {}


Date::Date(std::string d, std::string m, std::string y)
{
    this->day = d;
    this->month = m;
    this->year = y;
}

void Date::setDate(std::string d, std::string m, std::string y)
{
    this->day = d;
    this->month = m;
    this->year = y;
}

std::ostream& operator<<(std::ostream& ostr, Date& date)
{
    std::string str;
    str = date.day + "." + date.month + "." + date.year + "\n";
    return ostr << str;
}

bool operator<(Day_Tasks obj1, Day_Tasks obj2)
{
    if (obj1.day_Today.year <= obj2.day_Today.year)
    {
        if (obj1.day_Today.month <= obj2.day_Today.month)
        {
            if (obj1.day_Today.day <= obj2.day_Today.day)
            {
                return true;
            } else {return false;}
        } else {return false;}
    }
    return false;
}

std::string Date::toStr()
{
    return this->day + "." + this->month + "." + this->year;
}

Date::~Date() {}


Task::Task(std::string descr, Time start, Time end)
{
    this->description = descr;
    this->start = start;
    this->finish = end;
}

bool operator<(Task obj1, Task obj2)
{
    return (obj1.start.hours <= obj2.start.hours);
}

std::ostream& operator<<(std::ostream& ostr, Task& task)
{
    std::string str;
    str = task.description + "\n" + task.start.hours + ":" + task.start.minutes + "-" +
            task.finish.hours + ":" + task.finish.minutes + "\n";
    return ostr << str;
}

Task::~Task() {}
