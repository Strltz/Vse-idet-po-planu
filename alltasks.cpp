#include "alltasks.h"
#include "ui_alltasks.h"
#include <QVBoxLayout>
#include <QLabel>

AllTasks::AllTasks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllTasks)
{
    ui->setupUi(this);
    for (int i = 0;i < week.size(); ++i)
    {
        QVBoxLayout *layout = new QVBoxLayout;
        ui->verticalLayout->addWidget(layout);
        QLabel *label = new QLabel;
        label->setText(week[i].day_Today.toQStr());
        ui->verticalLayout->layout()->addWidget(label);
        for (int j = 0; j < week[i].tasks.size(); ++j)
        {
            ui->verticalLayout->layout()->addWidget(label->setText(week[i].tasks[j].toQStr()));
        }
    }

}

AllTasks::~AllTasks()
{
    for(int i = 0; i < ui->verticalLayout->count(); ++i)
    {
        for (int j = 0; j < ui->verticalLayout->layout()->count(); ++j)
        {

        }
    }

    delete ui;
}


void AllTasks::setVector(const QVector <Day_Tasks>& week)
{
    this->week = week;
}
