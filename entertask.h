#ifndef ENTERTASK_H
#define ENTERTASK_H

#include <QDialog>

namespace Ui {
class EnterTask;
}

class EnterTask : public QDialog
{
    Q_OBJECT

public:
    explicit EnterTask(QWidget *parent = 0);
    ~EnterTask();

private:
    Ui::EnterTask *ui;
};

#endif // ENTERTASK_H
