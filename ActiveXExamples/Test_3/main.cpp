#include "MainWindow.h"

#include <QApplication>
#include <QAxWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QAxWidget* ax = new QAxWidget(&w);

    ax->setControl("{B54F3741-5B07-11cf-A4B0-00AA004A55E8}");

    ax->setGeometry(10, 10, 380, 280);
    w.show();
    return a.exec();
}
