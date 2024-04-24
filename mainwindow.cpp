#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"

MainWindow::MainWindow(QApplication *parent) :
    QMainWindow(),ui(new Ui::MainWindow) {
    ui->setupUi(this);

    saveAction = new QAction(tr("&Сохранить"), this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    exitAction = new QAction(tr("&Выход"), this);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    fileMenu = this->menuBar()->addMenu(tr("&Файл"));
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    setWindowTitle(tr("Ежедневничек"));

    ui->Month->setText(QDate::currentDate().toString("MM.yyyy"));
    ui->button_Day->setText(QDate::currentDate().toString("dd"));
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
    int month;
    int day;
    int year;
    int min;
    int hour;

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
        std::stringstream str(flow_str);
        std::getline(str, flow_str, '.');
        day = stoi(flow_str);
        std::getline(str, flow_str, '.');
        month = stoi(flow_str);
        std::getline(str, flow_str);
        year = stoi(flow_str);
        Date dat(day, month, year);
        
        std::stringstream str(std::getline(fin, flow_str));
        

    }
    fin.close();
}

MainWindow::~MainWindow() { delete ui; }
