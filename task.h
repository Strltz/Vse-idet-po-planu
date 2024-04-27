
#ifndef TASK_H
#define TASK_H

#include <string>
#include <QVector>
#include <QString>
#include <QtAlgorithms>

class Time
{
public:
    Time() = default;
    Time(std::string,std::string);
    std::string toStr();
    QString toQStr();
    ~Time();


    std::string hours;
    std::string minutes;
};

class Date
{
public:
    std::string day;
    std::string month;
    std::string year;

    Date() = default;
    Date(std::string, std::string, std::string);
    void setDate(std::string, std::string, std::string);
    std::string toStr();
    QString toQStr();
    ~Date();
    friend std::ostream& operator<<(std::ostream&, Date&);
};

class Task
{
public:
    std::string description;
    Time start;
    Time finish;
    QString toQStr();
    Task() = default;
    Task(std::string, Time, Time);
    ~Task();
    friend std::ostream& operator<<(std::ostream&, Task&);
    bool friend Sort(const Task&, const Task&);
    friend bool operator<(Task, Task);
};


struct Day_Tasks
{
  Date day_Today;
  QVector <Task> tasks;
};

bool operator<(Day_Tasks, Day_Tasks);

#endif // TASK_H
