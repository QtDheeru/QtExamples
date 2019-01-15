#include "MyWidget.h"
#include <QApplication>

/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 * This program shows the custom model can be written
 * with dynamic update of the model.
 *
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.setWindowTitle("http://www.pthinks.com");
    w.show();
    qWarning() << " Main Thread Id=" << QThread::currentThreadId() << endl;

    return a.exec();
}
