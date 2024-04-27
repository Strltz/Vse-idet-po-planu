#include "mainwindow.h"
#include "task.h"
#include <QApplication>
#include "entertask.h"
#include "secondwindow.h"
#include "alltasks.h"
#include "qdynamicbutton.h"
#include "task.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
