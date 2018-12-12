#include "MyWidget.h"
#include <QApplication>

/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 * This program shows how the threads co-ordinate using
 * the semaphores.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();

    return a.exec();
}
