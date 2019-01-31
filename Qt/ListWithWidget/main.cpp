#include "MyWidget.h"
#include <QApplication>
/*
 * QListWidgetItem which contains a widget.
 * How to get a QListWidgetItem from Widget
 * at QListWidget
 * http://www.pthinks.com
 * dheerendra@pthinks.com
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();

    return a.exec();
}
