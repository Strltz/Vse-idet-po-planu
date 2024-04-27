#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "task.h"
#include "entertask.h"
#include <QFrame>

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setEchoMode(QLineEdit::NoEcho);

    newTask = new EnterTask();

}

SecondWindow::~SecondWindow()
{


    delete ui;
}


void SecondWindow::setVector(const QVector <Day_Tasks>& week)
{
    this->week = week;
}

void SecondWindow::on_add_clicked()
{
    newTask->setWindowTitle(tr("Задачечка"));
    newTask->show();
    QDynamicButton *button = new QDynamicButton(this);

    button->setText("Кнопочка");

    ui->verticalLayout->addWidget(button);

    connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
}

void SecondWindow::on_deleteBut_clicked()
{
    for(int i = 0; i < ui->verticalLayout->count(); ++i)
    {
        QDynamicButton *button = qobject_cast<QDynamicButton*>(ui->verticalLayout->itemAt(i)->widget());

        if(button->getID() == ui->lineEdit->text().toInt())
        {
            button->hide();
            delete button;
        }
    }
}

void SecondWindow::slotGetNumber()
{

    QDynamicButton *button = (QDynamicButton*) sender();
    ui->lineEdit->setText(QString::number(button->getID()));
}
