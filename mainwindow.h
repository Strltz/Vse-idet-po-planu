#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "task.h"
#include "secondwindow.h"
#include <QMainWindow>
#include <QtWidgets>
#include <QDate>
#include <QTime>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QApplication *parent = 0);
    ~MainWindow();

private slots:
    QVector <Day_Tasks> first_get();
    void open_sec();
    void open_all();

private:
    QVector <Day_Tasks> week;
    Ui::MainWindow *ui;
    SecondWindow *secWin;
    QAction *saveAction;
    QAction *exitAction;
    QMenu *fileMenu;
};

#endif // MAINWINDOW_H
