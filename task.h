#ifndef TASK_H
#define TASK_H

#include <string>
#include <QVector>

class Time
{
public:
    Time() = default;
    Time(std::string,std::string);
    ~Time();

private:
    std::string hours;
    std::string minutes;
};

class Date
{
private:
    std::string day;
    std::string month;
    std::string year;
public:
    Date() = default;
    Date(std::string, std::string, std::string);
    ~Date();
};

class Task
{
private:
    std::string description;
    Time start;
    Time finish;

public:
    Task() = default;
    Task(std::string, Time, Time);
    ~Task();
};


struct Day_Tasks
{
  Date day_Today;
  QVector <Task> tasks;
};

#endif // TASK_H
