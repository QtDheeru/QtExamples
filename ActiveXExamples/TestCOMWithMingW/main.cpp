#include "MyWidget.h"

#include <QApplication>
#include <QAxWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    QAxWidget* ax = new QAxWidget(&w);

    ax->setControl("{787719DC-8D8E-46bb-8FFE-FB9C58412B32}");
    ax->dynamicCall("setValue(int)",20);

    w.setWindowTitle("MingWWidget");
    w.resize(400,400);
    w.show();
    return a.exec();
}
