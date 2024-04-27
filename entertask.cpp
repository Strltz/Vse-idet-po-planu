#include "entertask.h"
#include "ui_entertask.h"
#include "secondwindow.h"

EnterTask::EnterTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterTask)
{
    ui->setupUi(this);
}

EnterTask::~EnterTask()
{

    delete ui;

}
