#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/assets/img/simulation.png"));
    MainWindow w;
    w.show();
    return a.exec();
}
