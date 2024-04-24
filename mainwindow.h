#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QDate>
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

private:
    Ui::MainWindow *ui;
    QAction *saveAction;
    QAction *exitAction;
    QMenu *fileMenu;
};

#endif // MAINWINDOW_H
