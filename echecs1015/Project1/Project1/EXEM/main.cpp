#include "mainwindow.h"
#include <QApplication>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     a.setApplicationDisplayName("INF1015 Chess");
    MainWindow w;
    w.show();
    return a.exec();
}
