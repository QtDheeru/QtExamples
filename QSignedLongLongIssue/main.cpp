#include "MyWidget.h"
#include <QApplication>
#include <QPushButton>
#include <QThread>
#include "DataHandler.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();

    qRegisterMetaType<signed long long>("signed long long");
    QThread thr;
    DataHandler dh;
    QObject::connect(&w,&MyWidget::sendLong,&dh,&DataHandler::handleData);
    dh.moveToThread(&thr);
    thr.start();

    QPushButton b1("SendMe");
    QObject::connect(&w,&MyWidget::sendLong,&w,&MyWidget::handleData);

    return a.exec();
}
