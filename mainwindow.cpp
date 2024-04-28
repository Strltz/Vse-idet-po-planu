#include "mainwindow.h"
#include "secondwindow.h"
#include "ui_mainwindow.h"
#include "task.h"
#include "entertask.h"
#include "alltasks.h"

MainWindow::MainWindow(QApplication *parent) :
    QMainWindow(),ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle(tr("Ежедневничек"));

    secWin = new SecondWindow();

    week = first_get();

    connect(ui->button_pon, SIGNAL(clicked()), this, SLOT(open_sec()));
    connect(ui->button_vtor, SIGNAL(clicked()), this, SLOT(open_sec()));
    connect(ui->button_sreda, SIGNAL(clicked()), this, SLOT(open_sec()));
    connect(ui->button_chetv, SIGNAL(clicked()), this, SLOT(open_sec()));
    connect(ui->button_pyatn, SIGNAL(clicked()), this, SLOT(open_sec()));
    connect(ui->button_subb, SIGNAL(clicked()), this, SLOT(open_sec()));
    connect(ui->button_vsk, SIGNAL(clicked()), this, SLOT(open_sec()));
    connect(ui->button_week, SIGNAL(clicked()), this, SLOT(open_all()));



    std::ofstream fout("Week.txt");
    for (int i = 0; i < week.size(); ++i)
    {
        fout << "Date_Of_Tasks_x00F" << " " << week[i].day_Today.toStr() << "\n";
        for (int j = 0; j < week[i].tasks.size(); ++j)
        {
            fout << week[i].tasks[j];
        }
    }
    fout.close();

}

MainWindow::~MainWindow() { delete ui; }

QVector <Day_Tasks> MainWindow::first_get()
{
    ui->Month->setText(QDate::currentDate().toString("MM.yyyy"));
    ui->Day->setText(QDate::currentDate().toString("dd"));
    int i = QDate::currentDate().dayOfWeek();
    switch (i)
    {
    case 1:
        ui->button_pon->setText("Пн");
        ui->button_vtor->setText("Вт");
        ui->button_sreda->setText("Ср");
        ui->button_chetv->setText("Чт");
        ui->button_pyatn->setText("Пт");
        ui->button_subb->setText("Сб");
        ui->button_vsk->setText("Вс");
        break;
    case 2:
        ui->button_pon->setText("Вт");
        ui->button_vtor->setText("Ср");
        ui->button_sreda->setText("Чт");
        ui->button_chetv->setText("Пт");
        ui->button_pyatn->setText("Сб");
        ui->button_subb->setText("Вс");
        ui->button_vsk->setText("Пн");
        break;
    case 3:
        ui->button_pon->setText("Ср");
        ui->button_vtor->setText("Чт");
        ui->button_sreda->setText("Пт");
        ui->button_chetv->setText("Сб");
        ui->button_pyatn->setText("Вс");
        ui->button_subb->setText("Пн");
        ui->button_vsk->setText("Вт");
        break;
    case 4:
        ui->button_pon->setText("Чт");
        ui->button_vtor->setText("Пт");
        ui->button_sreda->setText("Сб");
        ui->button_chetv->setText("Вс");
        ui->button_pyatn->setText("Пн");
        ui->button_subb->setText("Вт");
        ui->button_vsk->setText("Ср");
        break;
    case 5:
        ui->button_pon->setText("Пт");
        ui->button_vtor->setText("Сб");
        ui->button_sreda->setText("Вс");
        ui->button_chetv->setText("Пн");
        ui->button_pyatn->setText("Вт");
        ui->button_subb->setText("Ср");
        ui->button_vsk->setText("Чт");
        break;
    case 6:
        ui->button_pon->setText("Сб");
        ui->button_vtor->setText("Вс");
        ui->button_sreda->setText("Пн");
        ui->button_chetv->setText("Вт");
        ui->button_pyatn->setText("Ср");
        ui->button_subb->setText("Чт");
        ui->button_vsk->setText("Пт");
        break;
    case 7:
        ui->button_pon->setText("Вс");
        ui->button_vtor->setText("Пн");
        ui->button_sreda->setText("Вт");
        ui->button_chetv->setText("Ср");
        ui->button_pyatn->setText("Чт");
        ui->button_subb->setText("Пт");
        ui->button_vsk->setText("Сб");
        break;
    default:
        break;
    }

    QVector <Day_Tasks> week;

    std::string flow_str;
    std::string des;
    int j = -1;
    std::string month, day, year;
    std::string min_s, min_e;
    std::string hour_s, hour_e;

    std::ifstream fin_f("Week.txt");
    if (!fin_f.is_open())
    {
        std::ofstream f("Week.txt");
        f.close();
    }
    fin_f.close();
    std::ifstream fin("Week.txt");
    while (std::getline(fin, flow_str))
    {
        std::stringstream str_date(flow_str);
        std::getline(str_date, des, ' ');
        if (des == "Date_Of_Tasks_x00F")
        {
            std::getline(str_date, day, '.');
            std::getline(str_date, month, '.');
            std::getline(str_date, year);
            ++j;
            week.push_back(Day_Tasks());
            week[j].day_Today.setDate(day, month, year);
        } else
        {
            des = flow_str;
            std::getline(fin, flow_str);
            std::stringstream str_time(flow_str);
            std::getline(str_time, hour_s, ':');
            std::getline(str_time, min_s, '-');
            std::getline(str_time, hour_e, ':');
            std::getline(str_time, min_e);
            week[j].tasks.push_back(Task(des, Time(hour_s, min_s), Time(hour_e, min_e)));
        }
    }
    fin.close();

    qSort(week.begin(), week.end());
    int q = 0;

    while (q < week.size())
    {
        if ((QDate::currentDate().toString("dd").toStdString() > week[q].day_Today.day)
                and (QDate::currentDate().toString("MM").toStdString() >= week[q].day_Today.month)
                and (QDate::currentDate().toString("yyyy").toStdString() >= week[q].day_Today.year))
        {
            week.pop_front();
        }
        else
        {
            qSort(week[q].tasks.begin(), week[q].tasks.end());
            if (QDate::currentDate().toString("dd.MM.yyyy").toStdString() == week[q].day_Today.toStr())
            {
                while (week[q].tasks[0].finish.toQStr() < QTime::currentTime().toString("hh:mm"))
                {
                      week[q].tasks.pop_front();
                }
            }
            ++q;
        }
    }

    ui->task_1->setText("Нет задач");
    ui->task_2->setText("Нет задач");
    ui->task_3->setText("Нет задач");
    ui->time_1->setText("-");
    ui->time_2->setText("-");
    ui->time_3->setText("-");

    ui->curr_task->setText("Нет задач");
    ui->time_curr_task->setText("-");
    ui->next_task->setText("Нет задач");
    ui->time_next_task->setText("-");

    if (week.size() > 0)
    {
        if (QDate::currentDate().toString("dd.MM.yyyy").toStdString() == week[0].day_Today.toStr())
        {
            switch (week[0].tasks.size())
            {
            case 0:
                break;
            case 1:
                ui->curr_task->setText(QString::fromStdString(week[0].tasks[0].description));
                ui->time_curr_task->setText(QString::fromStdString(week[0].tasks[0].start.toStr() + "-" + week[0].tasks[0].finish.toStr()));
                break;
            case 2:
                ui->curr_task->setText(QString::fromStdString(week[0].tasks[0].description));
                ui->time_curr_task->setText(QString::fromStdString(week[0].tasks[0].start.toStr() + "-" + week[0].tasks[0].finish.toStr()));
                ui->next_task->setText(QString::fromStdString(week[0].tasks[1].description));
                ui->time_next_task->setText(QString::fromStdString(week[0].tasks[1].start.toStr() + "-" + week[0].tasks[1].finish.toStr()));

                ui->task_1->setText(QString::fromStdString(week[0].tasks[1].description));
                ui->time_1->setText(QString::fromStdString(week[0].tasks[1].start.toStr() + "-" + week[0].tasks[1].finish.toStr()));
                break;
            case 3:
                ui->curr_task->setText(QString::fromStdString(week[0].tasks[0].description));
                ui->time_curr_task->setText(QString::fromStdString(week[0].tasks[0].start.toStr() + "-" + week[0].tasks[0].finish.toStr()));
                ui->next_task->setText(QString::fromStdString(week[0].tasks[1].description));
                ui->time_next_task->setText(QString::fromStdString(week[0].tasks[1].start.toStr() + "-" + week[0].tasks[1].finish.toStr()));

                ui->task_1->setText(QString::fromStdString(week[0].tasks[1].description));
                ui->time_1->setText(QString::fromStdString(week[0].tasks[1].start.toStr() + "-" + week[0].tasks[1].finish.toStr()));
                ui->task_2->setText(QString::fromStdString(week[0].tasks[2].description));
                ui->time_2->setText(QString::fromStdString(week[0].tasks[2].start.toStr() + "-" + week[0].tasks[2].finish.toStr()));
                break;
            default:
                ui->curr_task->setText(QString::fromStdString(week[0].tasks[0].description));
                ui->time_curr_task->setText(QString::fromStdString(week[0].tasks[0].start.toStr() + "-" + week[0].tasks[0].finish.toStr()));
                ui->next_task->setText(QString::fromStdString(week[0].tasks[1].description));
                ui->time_next_task->setText(QString::fromStdString(week[0].tasks[1].start.toStr() + "-" + week[0].tasks[1].finish.toStr()));

                ui->task_1->setText(QString::fromStdString(week[0].tasks[1].description));
                ui->time_1->setText(QString::fromStdString(week[0].tasks[1].start.toStr() + "-" + week[0].tasks[1].finish.toStr()));
                ui->task_2->setText(QString::fromStdString(week[0].tasks[2].description));
                ui->time_2->setText(QString::fromStdString(week[0].tasks[2].start.toStr() + "-" + week[0].tasks[2].finish.toStr()));
                ui->task_3->setText(QString::fromStdString(week[0].tasks[3].description));
                ui->time_3->setText(QString::fromStdString(week[0].tasks[3].start.toStr() + "-" + week[0].tasks[3].finish.toStr()));
            }
        }
    }

    return week;
}


void MainWindow::open_sec()
{
    QPushButton *button = (QPushButton*)sender();
    secWin->setWindowTitle(tr((button->text()).toUtf8()));
    secWin->setVector(week);

    secWin->show();
}

void MainWindow::open_all()
{
    AllTasks *allWin = new AllTasks;
    allWin->setVector(week);
    allWin->setWindowTitle(tr("Все задачечки"));

    allWin->show();
}
