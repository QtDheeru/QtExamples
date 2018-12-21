#include "MyWidget.h"
#include <QApplication>

/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 * This illustrates the deletion of child objects
 * when the parent is deleted
 * 97877
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget *w = new MyWidget;

    for(int i=1000;i<1010;i++){
        MyWidget *w1 = new MyWidget(w);
        w1->setObjectName(QString::number(i));
        for(int j=0;j<2;j++){
            MyWidget *w3 = new MyWidget(w1);
            w3->setObjectName(QString("Child-%1").arg(j));
        }
    }
    w->show();
    delete w;

    return a.exec();
}
