
#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "qdynamicbutton.h"
#include "entertask.h"
#include "task.h"
#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    void setVector(const QVector <Day_Tasks>&);
    ~SecondWindow();

private slots:
    void on_add_clicked();
    void on_deleteBut_clicked();
    void slotGetNumber();

private:
    Ui::SecondWindow *ui;
    EnterTask *newTask;
    QVector <Day_Tasks> week;

};

#endif // SECONDWINDOW_H
