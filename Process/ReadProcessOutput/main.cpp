#include "MyWidget.h"
#include <QApplication>

/*
 * http://www.pthinks.com - dheerendra@pthinks.com
 *
 * Start the process & read the output
 * of the program from standard out
 * inside the qt program. This starts the process
 * waits for ready read signal from the process
 * Tried with ping and get the output
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();

    return a.exec();
}
