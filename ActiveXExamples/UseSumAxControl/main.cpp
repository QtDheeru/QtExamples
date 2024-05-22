#include "MainWindow.h"

#include <QApplication>
#include <QAxWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QAxWidget* ax = new QAxWidget(&w);

    ax->setControl("{7E7250E5-F595-43f0-8FFA-967B07A858A5}");
    QVariant sum = ax->dynamicCall("sum(int,int)",10,20);
    qDebug() << " Sum Value =" << sum;
    return a.exec();
}
