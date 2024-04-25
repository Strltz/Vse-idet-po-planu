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
    void first_get();
    void open_sec();

private:
    Ui::MainWindow *ui;
    SecondWindow *secWin;
    QAction *saveAction;
    QAction *exitAction;
    QMenu *fileMenu;
};

#endif // MAINWINDOW_H
