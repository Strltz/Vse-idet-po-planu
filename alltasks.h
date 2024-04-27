#ifndef ALLTASKS_H
#define ALLTASKS_H

#include <QDialog>
#include "task.h"

namespace Ui {
class AllTasks;
}

class AllTasks : public QDialog
{
    Q_OBJECT

public:
    explicit AllTasks(QWidget *parent = 0);
    ~AllTasks();
    void setVector(const QVector <Day_Tasks>&);

private:
    Ui::AllTasks *ui;
    QVector <Day_Tasks> week;

};

#endif // ALLTASKS_H
